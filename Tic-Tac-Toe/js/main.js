import Game from "./Game.js";

let game = new Game();

console.log(game.turn);
game.makeMove(0);
console.log(game.board);
console.log(game.turn);
game.makeMove(6);
console.log(game.board);
