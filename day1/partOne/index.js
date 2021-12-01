var fs = require("fs");
fs.readFile("input.txt", "utf8", function (err, data) {
    if (err)
        throw err;
    var depths = data.split("\n");
    var lastDepth;
    var increments = 1;
    depths.forEach(function (depth) {
        if (depth > lastDepth) {
            increments++;
        }
        lastDepth = depth;
    });
    console.log(increments);
});
