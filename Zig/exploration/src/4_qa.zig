const std = @import("std");

pub fn main() !void {
    const writer = std.io.getStdOut().writer();
    const reader = std.io.getStdIn().reader();

    try writer.print("Masukkan nama? ", .{});
    var buf: [255]u8 = undefined;

    const name = try reader.readUntilDelimiter(buf[0..], '\n');

    try writer.print("Namamu adalah '{s}'\n", .{name});
}
