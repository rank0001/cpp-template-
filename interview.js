function rangeOfNumbers(startNum, endNum) {
  if (endNum === startNum) {
    return [startNum];
  } else {
    const arr = rangeOfNumbers(startNum, endNum - 1);
    arr.push(endNum);
    return arr;
  }
}
console.log(rangeOfNumbers(6, 9));
