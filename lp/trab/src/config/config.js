import TimerPlugin from '../components/timer';
import EndCardPlugin from '../components/endCard';
import WordsPlugin from '../components/words'
import ButtonPlugin from '../components/button'
import game from '../scenes/game'
import loading from '../scenes/loading'
import menu from '../scenes/menu'

// a configuracao do jogo, passado para dentro do objeto Game no inicio da execucao
export default {
    type: Phaser.AUTO,
    parent: "typeracer-lp",
    width: 400,
    height: 300,
    render: {
      pixelArt: true,

    },
    scene: [loading, game],
    plugins: {
        global: [
            { key: 'Timer', plugin: TimerPlugin, start: true },
            { key: 'EndCard', plugin: EndCardPlugin, start: true },
            { key: 'Words', plugin: WordsPlugin, start: true },
            { key: 'Button', plugin: ButtonPlugin, start: true }
        ]
    },
    
    doom: {
      createContainer: true
    },
    scene: [loading, game, menu],
    scale: {
        zoom: 2
    }
  };