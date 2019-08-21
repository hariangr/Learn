import 'package:flutter/material.dart';
import 'package:english_words/english_words.dart';

void main() => runApp(new MyApp());

class MyApp extends StatelessWidget {
  Widget build(BuildContext context) {
    return new MaterialApp(
      title: 'Welcome to Flutter',
      home: new RandomWords(),
      theme: new ThemeData(
        primaryColor: Colors.indigo,
      )
    );
  }
}

class RandomWords extends StatefulWidget {
  @override
    State<StatefulWidget> createState() {
      // TODO: implement createState
      return new RandomWordsState();
    }
}

class RandomWordsState extends State<RandomWords> {
  final _suggestion = <WordPair>[];
  final _biggerFont = const TextStyle(fontSize: 18.0);
  final _saved = new Set<WordPair>();

  void _pushSaved() {
    print('Pushed');
    Navigator.of(context).push(
      new MaterialPageRoute(
        builder: (context) {


          final tiles = _saved.map((pair) {
            return new ListTile(
              title: new Text(pair.asPascalCase),
            );
          });

          final divided = ListTile.divideTiles(
            context: context,
            tiles: tiles,
          ).toList();

          return new Scaffold(
            appBar: new AppBar(
              title: new Text('S'),
            ),
            body: new ListView(
              children: divided,
            ),
          );
        },
      )
    );    
  }
  
  Widget _buildSuggestions() {
    return new ListView.builder(
      padding: const EdgeInsets.all(16.0),
      itemBuilder: (context, i) {
        if(i >= _suggestion.length){
          _suggestion.addAll(generateWordPairs().take(10));
        }

        final index = i ~/ 2;
        if(i.isOdd){
          return new Divider();
        } else {
          return _buildRow(_suggestion[index]);
        }
      },
    );
  }

  Widget _buildRow(WordPair pair) {
    final alreadySaved = _saved.contains(pair);

    return new ListTile(
      title: new Text(
        pair.asPascalCase,
        style: _biggerFont,
      ),
      trailing: new Icon(
        alreadySaved ? Icons.favorite : Icons.favorite_border,
        color: alreadySaved ? Colors.red : null,
      ),
      onTap: () {
        setState(() {
          if(alreadySaved) {
            _saved.remove(pair);
          } else {
            _saved.add(pair);
          }
        });
      },
    ); 
  }

  @override
    Widget build(BuildContext context) {
      // TODO: implement build

      return new Scaffold(
        appBar: new AppBar(
          title: new Text('Sesuatu yang tak kumengerti'),
          actions: <Widget>[
            new IconButton(icon: new Icon(Icons.list), onPressed: _pushSaved),
          ],
        ),
        body: _buildSuggestions(),
      );
    }
}