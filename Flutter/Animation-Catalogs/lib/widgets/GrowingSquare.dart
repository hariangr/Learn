import 'package:flutter/material.dart';

class GrowingSquare extends StatefulWidget {
  final double width;
  final double height;

  GrowingSquare({this.width, this.height});

  @override
  _GrowingSquareState createState() => _GrowingSquareState();
}

class _GrowingSquareState extends State<GrowingSquare>
    with SingleTickerProviderStateMixin {
  AnimationController controller;
  Animation growingAnimation;

  double size;

  @override
  void initState() {
    super.initState();

    controller =
        new AnimationController(vsync: this, duration: Duration(seconds: 2));

    growingAnimation =
        new Tween<double>(begin: 0.0, end: 100.0).animate(controller);

    controller.addListener(() {
      setState(() {
        size = growingAnimation.value;
      });
    });

    controller.repeat();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
        width: widget.width,
        height: widget.height,
        child: Center(
          child: Container(
            width: size,
            height: size,
            color: Colors.red,
          ),
        ));
  }
}
