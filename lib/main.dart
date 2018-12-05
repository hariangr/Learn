import 'package:flutter/material.dart';
import 'package:flutter_animations_catalog/screens/SplashScreen.dart';
import 'package:flutter_animations_catalog/screens/AnimationsListScreen.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: SplashScreen(),
      routes: <String, WidgetBuilder>{
        "/splash": (BuildContext context) => SplashScreen(),
        "/animationList": (BuildContext context) => AnimationListScreen(),
      },
    );
  }
}
