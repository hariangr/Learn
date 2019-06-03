import 'package:flutter/material.dart';
import 'package:flutter_animations_catalog/services/Database.dart';
import 'package:flutter_animations_catalog/data/AnimationWidgetItem.dart';
import 'package:flutter_animations_catalog/screens/PresenterScreen.dart';

class AnimationListScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Flutter Animations Catalog"),
        centerTitle: true,
      ),
      body: new ListView.builder(
        itemCount: Database.animations.length,
        itemBuilder: (context, i) => AnimListItem(
              animWidget: Database.animations[i],
              onTap: () {
                MaterialPageRoute route = new MaterialPageRoute(
                  builder: (_) =>
                      PresenterScreen(animWidget: Database.animations[i]),
                );

                Navigator.push(context, route);
              },
            ),
      ),
    );
  }
}

class AnimListItem extends StatelessWidget {
  final AnimationWidgetItem animWidget;
  final GestureTapCallback onTap;

  AnimListItem({this.animWidget, this.onTap});

  @override
  Widget build(BuildContext context) {
    return Card(
      child: ListTile(
        title: Text(animWidget.title),
        subtitle: Text(animWidget.description),
        onTap: this.onTap,
      ),
    );
  }
}
