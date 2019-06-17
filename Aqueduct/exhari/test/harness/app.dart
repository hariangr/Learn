import 'package:exhari/exhari.dart';
import 'package:aqueduct_test/aqueduct_test.dart';

export 'package:exhari/exhari.dart';
export 'package:aqueduct_test/aqueduct_test.dart';
export 'package:test/test.dart';
export 'package:aqueduct/aqueduct.dart';

/// A testing harness for exhari.
///
/// A harness for testing an aqueduct application. Example test file:
///
///         void main() {
///           Harness harness = Harness()..install();
///
///           test("GET /path returns 200", () async {
///             final response = await harness.agent.get("/path");
///             expectResponse(response, 200);
///           });
///         }
///
class Harness extends TestHarness<ExhariChannel> {
  @override
  Future onSetUp() async {

  }

  @override
  Future onTearDown() async {

  }
}
