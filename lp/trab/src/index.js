import Phaser from "phaser";
import config from "./config/config"

class Game extends Phaser.Game{
  constructor(){
    super(config);
  }
}

// o inicio da execucao do jogo, carrega um novo jogo com as configuracoes de config.js
window.onload = function(){
  window.game = new Game();
}