import 'package:flutter/material.dart';
import 'package:flutter_animations_catalog/data/AnimationWidgetItem.dart';

class PresenterScreen extends StatelessWidget {
  final AnimationWidgetItem animWidget;

  PresenterScreen({this.animWidget});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(animWidget.title),
      ),
      body: Column(
        children: <Widget>[
          animWidget.widget,
          // Expanded(
          //   child: animWidget.widget,
          // ),
          ListTile(
            title: Text(animWidget.title),
            subtitle: Text(animWidget.description),
          )
        ],
      ),
    );
  }
}
