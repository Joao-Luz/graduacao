import 'phaser'
import config from '../config/config'
import {shuffle} from '../utils/utils'

export default class Game extends Phaser.Scene{
    constructor(){
        super('game');
    }

    preload(){
        // carrega as palavras na memoria
        this.wordsSource = require('../assets/words.json');
    }

    startStats(){
        // inicializa estatísticas e atualiza os respectivos textos
        this.maxCharacters = 0;
        this.score = 0;
        this.scoreText.setText('0');
        this.multiplier = 1.0;
        this.multiplierText.setText('1.0');
        this.multiplierLevel.setFrame(0);
        this.sequence = 0;
        this.sequenceText.setText('000');
        this.maxWords = 0;
        this.maxSequence = 0;
        this.totalWords = 0;
    }

    restart(){
        // inicializa o jogo com as devidas configuracoes
        this.gameMusic.setVolume(.1);

        this.endCard.setY(config.height+200);
        this.timer.reset();
        this.words.restart(shuffle(this.wordsSource));
        this.startStats();
        this.startCounter.setVisible(true).setAlpha(1);
        // o timer antes de comecar a rodada
        let counter = 2;
        if(this.startCounterEvent){
            this.startCounterEvent.remove();
            this.startCounterEvent.destroy();
        }
        this.startCounter.setVisible(true).setText('3');
        // a cada segundo decrescer 1 no timer
        this.startCounterEvent = this.time.addEvent({
            delay: 1000,
            repeat: 2,
            callback: () => {
                if(counter == 0){
                    // quando chegar em zero, começar o jogo, diminui a opacidade e aumenta o volume da musica
                    this.gameMusic.setVolume(.2);
                    this.startCounter.setText('Vai!');
                    this.tweens.add({
                        targets: this.startCounter,
                        onStart: () => {
                            this.timeOut = false;
                            this.timer.start();
                            this.words.newWord(100);
                        },
                        onStartScope: this,
                        onComplete: () => this.startCounter.setVisible(false),
                        onCompleteScope: this,
                        alpha: 0
                    })
                }
                else this.startCounter.setText(`${counter--}`);
            },
            callbackScope: this,
        })
    }

    updateGameMusic(){
        this.gameMusic.setVolume(this.multiplier/16+.2);
    }

    create(){
        // criando os objetos de jogo necessários
        this.add.image(0, 0, 'background').setOrigin(0, 0);
        
        this.gameMusic = this.sound.add('game_music', {loop: true, volume: 0.01});
        this.gameMusic.play();
        
        const style = {fontSize: 20, fontFamily: 'upheave'};
        // timer de um minuto
        this.timer = this.add.timer(config.width-10, 30, {
            time: 60,
            callback: (time) => { // callback para quando o relógio chegar em diferentes tempos
                if(time <= 0){
                    this.timeOut = true;
                    this.gameMusic.setVolume(.1).setDetune(0);
                    const precision = this.totalWords != 0 ? this.maxWords/this.totalWords : 0;
                    this.endCard.start({
                        score: this.score,
                        maxCharacters: this.maxCharacters,
                        maxWords: this.maxWords,
                        maxSequence: this.maxSequence,
                        precision: precision
                    })
                }
                else if(time <= 5) this.gameMusic.setDetune(300);
                else if(time <= 10) this.gameMusic.setDetune(200);
                else if(time <= 30) this.gameMusic.setDetune(100);
            },
            callbackScope: this
        }).setOrigin(1, 0);
        // pontuacao
        this.scoreText = this.add.text(config.width-10, 10, '0', style).setOrigin(1, 0);

        // multiplicador e contador de palavras em sequencia
        this.add.image(40, config.height-20, 'counter').setOrigin(.5, .5);
        this.sequenceText = this.add.text(23, config.height-21, `000`, style).setOrigin(0, .5);
        this.multiplierLevel = this.add.image(40, config.height-55, 'mult', 0).setOrigin(.5, .5);
        this.multiplierText = this.add.text(40, config.height-55, `1.0`, style).setOrigin(.5, .5);
        
        // contador antes do inicio de cada partida
        this.startCounter = this.add.text(config.width/2, config.height/2, '3', {fontFamily: 'upheave', fontSize: 80}).setOrigin(.5,.5).setVisible(false);
        // card do final da partida
        this.endCard = this.add.endcard(config.width/2, 0);
        // palavras (tanto para difitar quanto as digitadas)
        this.words = this.add.words(50, config.height/2 + 20, shuffle(this.wordsSource));

        // botoes de reiniciar
        this.add.button(config.width-20, config.height-20, 'icons', {
            callback: () => {
                this.restart();
            },
            callbackScope: this,
            frame: 0,
            over: 0,
            down: 1
        });
        // e de voltar para o menu
        this.add.button(config.width-50, config.height-20, 'icons', {
            callback: () => this.exit(),
            callbackScope: this,
            frame: 2,
            over: 2,
            down: 3
        });

        // inicar o jogo equivalente a reiniciar
        this.restart();

        // mapeando teclas para letras
        this.input.keyboard.on('keydown', e => this.buttonCallback(e.keyCode), this);
    }

    buttonCallback(key){
        // o callback decide o que fazer quando uma tecla for pressionada se o teclado estiver ativo e se a tecla for uma letra
        if(this.keyboardEnable && !this.timeOut && (key >= 65 && key <= 90)){
            const res = this.words.checkCurrentCharacter(key); // res = 1 (uma tecla correta), 0 (tecla errada), >1 (palavra completa)

            this.maxCharacters += res > 0 ? 1 : 0;
            this.maxWords += res > 1 ? 1 : 0;
            if(res != 1) this.totalWords += 1;

            // contando palavras seguidas
            if(res > 1) this.sequence += 1;
            else if(res == 0) this.sequence = 0;
            this.maxSequence = Math.max(this.sequence, this.maxSequence);
            this.sequenceText.setText(`${this.sequence.toString().padStart(3, '0')}`);
            
            // atualizando multiplicador
            this.multiplier = Math.floor(this.sequence/3);
            this.multiplierText.setText(`${(this.multiplier * 0.5 + 1).toFixed(1)}`);
            this.updateGameMusic();
            // atualizando a roda do multiplicador
            this.multiplier < 9 && this.multiplierLevel.setFrame(this.multiplier);
            
            // atualizando pontuacao
            this.score += (this.multiplier * 0.5 + 1) * 10 * res;
            this.scoreText.setText(`${this.score}`);
        }
    
    }

    exit(){
        this.gameMusic.stop();
        this.scene.start('menu');
    }
}