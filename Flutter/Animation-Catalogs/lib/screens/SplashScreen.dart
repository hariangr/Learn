import 'package:flutter/material.dart';
import 'dart:async';

class SplashScreen extends StatefulWidget {
  @override
  _SplashScreenState createState() => _SplashScreenState();
}

class _SplashScreenState extends State<SplashScreen> {
  @override
  void initState() {
    super.initState();

    startTimer();
  }

  startTimer() async {
    return Timer(Duration(seconds: 3), () {
      Navigator.of(context).pushReplacementNamed("/animationList");
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: new Center(
        child: Text("Hari Anugrah"),
      ),
    );
  }
}
