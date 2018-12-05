import 'package:flutter/material.dart';
import 'package:flutter_animations_catalog/widgets/JumpingBall.dart';
import 'package:flutter_animations_catalog/widgets/GrowingSquare.dart';

class AnimationListScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: new Center(
        child: GrowingSquare(),
      ),
    );
  }
}