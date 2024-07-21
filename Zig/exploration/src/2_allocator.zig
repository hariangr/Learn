const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    var allocator = gpa.allocator();

    const str = try allocator.alloc(u8, 255);
    for (0..60) |i| {
        str[i] = @intCast(i + 48);
    }

    std.debug.print("Contoh string {s}", .{str});
}
