const std = @import("std");

pub fn main() !void {
    const stdin = std.io.getStdIn();

    const reader = stdin.reader();
    var buf: [255]u8 = undefined;

    const input = try reader.readUntilDelimiter(buf[0..], '\n');
    std.debug.print("Isinya! {s}\n", .{input});
}
