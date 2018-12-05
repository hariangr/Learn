import 'package:flutter/material.dart';
import 'package:flutter_animations_catalog/services/Database.dart';
import 'package:flutter_animations_catalog/data/AnimationWidgetItem.dart';

class AnimationListScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: new ListView.builder(
        itemCount: Database.animations.length,
        itemBuilder: (context, i) =>
            AnimListItem(animWidget: Database.animations[i]),
      ),
    );
  }
}

class AnimListItem extends StatelessWidget {
  final AnimationWidgetItem animWidget;

  AnimListItem({this.animWidget});

  @override
  Widget build(BuildContext context) {
    return ListTile(
      title: animWidget.widget,
      subtitle: Text(animWidget.description),
    );
  }
}
