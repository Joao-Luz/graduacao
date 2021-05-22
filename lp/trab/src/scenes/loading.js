import 'phaser'

export default class Loading extends Phaser.Scene {

    constructor(){
        super('loading');
    }

    preload(){
        // carregando imagens e sons que serao usados no jogo
        this.load.image('background', require('../assets/images/background.png'));
        this.load.image('card', require('../assets/images/card.png'));
        this.load.image('background_menu', require('../assets/images/background_menu.png'));
        this.load.image('counter', require('../assets/images/counter.png'))
        this.load.spritesheet('mult', require('../assets/images/mult.png'), {
            frameWidth: 55,
            frameHeight: 55
        });
        this.load.spritesheet('restart_btn', require('../assets/images/restart_btn.png'), {
            frameWidth: 96,
            frameHeight: 23
        });
        this.load.spritesheet('menu_btn', require('../assets/images/menu_btn.png'), {
            frameWidth: 96,
            frameHeight: 23
        });
        this.load.spritesheet('trophy', require('../assets/images/trophy.png'), {
            frameWidth: 21,
            frameHeight: 26
        });
        this.load.spritesheet('play_btn', require('../assets/images/play_btn.png'), {
            frameWidth: 112,
            frameHeight: 23
        });
        this.load.spritesheet('title', require('../assets/images/title.png'), {
            frameWidth: 318,
            frameHeight: 25
        });
        this.load.spritesheet('icons', require('../assets/images/icons.png'), {
            frameWidth: 22,
            frameHeight: 21
        });

        this.load.audio('thud', require('../assets/sounds/thud.ogg'));
        this.load.audio('wrong', require('../assets/sounds/wrong.ogg'));
        this.load.audio('game_music', require('../assets/sounds/game_music.ogg'));
        this.load.audio('menu_music', require('../assets/sounds/menu_music.ogg'));
        this.load.audio('keyboard', require('../assets/sounds/keyboard.ogg'));
    }

    create(){
        // gerando as animacoes que serao usadas no jogo
        this.anims.create({
            key: 'title_writing',
            frames: this.anims.generateFrameNumbers('title', {
                start: 0,
                end: 9
            }),
            delay: 700,
            frameRate: 15,
            repeat: 0
        });
        this.anims.create({
            key: 'title_blinking',
            frames: this.anims.generateFrameNumbers('title', {
                start: 10,
                end: 9
            }),
            frameRate: 1.2,
            repeat: -1,
        });
        this.scene.start('menu');
    }
}