let _inputLines;
let _lineNumber = 0;
let inputReader = _inputReader();

function _main() {
	_inputLines = _inputData
		.trim()
		.split("\n")
		.map((string) => {
			return string.trim();
		});
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
}

var _inputData = "";
function cacheInput(data) {
	_inputData += data;
}

process.stdin.resume();
process.stdin.setEncoding("utf8");
process.stdin.on("data", cacheInput).on("end", _main);

function _inputReader() {
	function readNumber() {
		return Number(_inputLines[_lineNumber++]);
	}

	function readLine() {
		return _inputLines[_lineNumber++];
	}

	return {
		readNumber,
		readLine,
	};
}
