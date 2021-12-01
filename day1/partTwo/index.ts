var fs = require("fs");
fs.readFile("input.txt", "utf8", function (err, data) {
  if (err) throw err;
  const depths = data.split("\n");

  const groupedDepths = [];
  let x = 0;
  while (x < depths.length - 2) {
    groupedDepths[x] = (
      parseInt(depths[x]) +
      parseInt(depths[x + 1]) +
      parseInt(depths[x + 2])
    ).toString();
    x++;
  }

  let lastDepth: string;
  let increments = 1;
  groupedDepths.forEach(function (depth) {
    if (depth > lastDepth) {
      increments++;
    }
    lastDepth = depth;
  });
  console.log(increments);
});
