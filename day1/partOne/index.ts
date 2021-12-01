var fs = require("fs");

fs.readFile("input.txt", "utf8", (err, data) => {
  if (err) throw err;
  const depths = data.split("\n");
  let lastDepth: string;
  let increments = 1;
  depths.forEach((depth: string) => {
    if (depth > lastDepth) {
      increments++;
    }

    lastDepth = depth;
  });

  console.log(increments);
});
