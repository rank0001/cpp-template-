const { inputReader } = require("competitive-programming-js");
let n = inputReader.readNumber();
let str = inputReader.readLine();
let sf = 0,
  fs = 0;
for (let i = 1; i < str.length; i++) {
  if (str[i] === "F" && str[i - 1] === "S") sf++;
  else if (str[i] === "S" && str[i - 1] === "F") fs++;
}
if (sf - fs > 0) {
  console.log("YES");
} else {
  console.log("NO");
}
