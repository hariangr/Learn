import 'package:flutter_animations_catalog/data/AnimationWidgetItem.dart';
import 'package:flutter_animations_catalog/widgets/GrowingSquare.dart';

class Database {
  static final animations = <AnimationWidgetItem>[
    AnimationWidgetItem(
        title: "Growing Square",
        widget: GrowingSquare(height: 100.0, width: 100.0),
        description: "Simple growing square"),
  ];
}
