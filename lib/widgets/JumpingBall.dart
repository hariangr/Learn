import 'package:flutter/material.dart';

class JumpingBall extends StatefulWidget {
  @override
  _JumpingBallState createState() => _JumpingBallState();
}

class _JumpingBallState extends State<JumpingBall>
    with SingleTickerProviderStateMixin {
  AnimationController controller;
  Animation jumpingAnim1;
  Animation jumpingAnim2;

  double yPos;

  @override
  void initState() {
    super.initState();

    controller =
        new AnimationController(vsync: this, duration: Duration(seconds: 1));

    jumpingAnim1 =
        new Tween<double>(begin: -100.0, end: 100.0).animate(controller);
    // jumpingAnim2 =
    //     new Tween<double>(begin: 100.0, end: -100.0).animate(controller);

    controller.addListener(() {
      setState(() {
        yPos = jumpingAnim1.value;
        print(yPos);
      });
    });

    controller.repeat();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 200.0,
      width: 200.0,
      color: Colors.black,
      child: new Center(
        child: new Stack(
          children: <Widget>[
            Transform.translate(
              offset: Offset(0.0, yPos),
              child: Dot(),
            )
          ],
        ),
      ),
    );
  }
}

class Dot extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 20.0,
      width: 20.0,
      decoration: BoxDecoration(
        shape: BoxShape.circle,
        color: Colors.red,
      ),
    );
  }
}
