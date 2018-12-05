import 'package:flutter/material.dart';

class PresenterScreen extends StatelessWidget {
  Widget widget;

  PresenterScreen({this.widget});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Row(
        children: <Widget>[
          widget
        ],
      ),
    );
  }
}