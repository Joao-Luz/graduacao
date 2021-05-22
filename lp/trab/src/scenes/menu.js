import 'phaser'
import config from '../config/config'

export default class Menu extends Phaser.Scene {
    constructor() {
        super('menu');
    }

    create() {
        // inicializando a cena com a devida imagem de fundo, titulo e musica
        this.menuMusic = this.sound.add('menu_music', {volume: .3, loop: true});
        this.menuMusic.play();
        this.keyboardSound = this.sound.add('keyboard', {volume: .5});
        this.keyboardSound.addMarker({name: 'default', duration: .8});
        this.keyboardSound.play('default', {delay: .7});
        this.add.image(0, 0, 'background_menu').setOrigin(0, 0);
        // o titulo do jogo, que deve ser animado
        this.add.sprite(config.width/2, 100, 'title', 0)
            .setOrigin(.5, .5)
            .play('title_writing')
            .chain('title_blinking');
        // o botao de jogar
        this.add.button(config.width/2, 200, 'play_btn', {
            callback: () => this.toGame(),
            callbackScope: this
        });
    }

    toGame(){
        // trocando a cena para a cena do jogo
        this.menuMusic.stop();
        this.keyboardSound.stop();
        this.scene.start('game');
    }
}

