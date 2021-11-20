class NotesStore {
  //add your code here
  constructor() {
    this.active = [];
    this.completed = [];
    this.others = [];
  }

  addNote(state, name) {
    if (name.length == 0) throw "Name cannot be empty";
    else {
      if (state !== "completed" && state !== "active" && state !== "others")
        throw `Invalid state ${state}`;
      else {
        if (state === "active") this.active.push(name);
        else if (state === "completed") this.completed.push(name);
        else if (state === "others") this.others.push(name);
      }
    }
  }
  getNotes(state) {
    if (state !== "completed" && state !== "active" && state !== "others")
      throw `Invalid state ${state}`;
    if (state === "active") return this.active;
    else if (state === "completed") return this.completed;
    else if (state === "others") return this.others;
  }
}
let a  = new NotesStore();

a.addNote ('active', 'DrinkTea');
// a.addNote active DrinkCoffee
// addNote completed Study
// getNotes active 
// getNotes completed
// getNotes foo
console.log(a.getNotes('foo'));