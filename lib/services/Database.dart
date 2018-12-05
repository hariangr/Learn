import 'package:flutter_animations_catalog/data/AnimationWidgetItem.dart';
import 'package:flutter_animations_catalog/widgets/GrowingSquare.dart';

class Database {
  static final animations = <AnimationWidgetItem>[
    AnimationWidgetItem(widget: GrowingSquare(), description: "Simple growing square"),
  ];
}