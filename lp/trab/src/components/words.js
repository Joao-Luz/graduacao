import "phaser"

class Words extends Phaser.GameObjects.Container {
    constructor(scene, x, y, wordStack){
        super(scene);
        // inicializar o objeto das palavras e criar os sons que sao utilizados
        this.thudSound = scene.sound.add('thud', {rate: 1});
        this.wrongSound = scene.sound.add('wrong');
        this.x = x;
        this.y = y;
        this.wordStack = wordStack;
        this.currentText = scene.add.text(x, y, '', {fontSize: 20, fontFamily: 'upheave'});
        this.texts = [];
    }

    restart(wordStack){
        this.wordStack = wordStack;
        // reiniciar as palavras destruindo as palavras ja digitadas
        this.texts.forEach(text => {
            text.destroy();
        });
        this.currentText.setText('');
    }

    newWord(delay){
        // se nao estiver visivel, remover os textos anteriores
        this.texts.forEach(text => {
            text.y -= 30;
            if(text.y < -10) text.destroy();
        });
        // tirar uma palavra da stack
        this.currentWord = this.wordStack.pop();
        this.currentText.setText(this.currentWord).setAlpha(.5).setX(-30);
        this.writtenText = this.scene.add.text(this.x, this.y, '', {fontSize: 20, fontFamily: 'upheave', color: 'lime'});
        this.texts.push(this.writtenText);
        
        // animando as palavras para aparecerem do canto da tela
        this.scene.keyboardEnable = false;
        this.scene.tweens.add({
            duration: delay,
            targets: this.currentText,
            x: this.x,
            alpha: 1,
            onComplete: () => this.scene.keyboardEnable = true,
            onCompleteScope: this
        })

        this.wordIndex = 0;
    }

    checkCurrentCharacter(ccode){
        // checando um caractere digitado
        const wordLength = this.currentWord.length;
        // caractere correto
        if(ccode == this.currentWord.charCodeAt(this.wordIndex)){
            this.thudSound.play();
            this.writtenText.setText(this.writtenText.text + String.fromCharCode(ccode));
            this.wordIndex++;
            if(this.wordIndex == wordLength){
                this.newWord(100);
                return wordLength;
            }
            return 1;
        }
        // caractere incorreto
        else{
            this.wrongSound.play();
            this.writtenText.setText(this.currentWord).setColor('red');
            this.newWord(500); // nova palavra com mais delay para que nao erre a seguinte
            return 0;
        }
    }
}

// adicionando o objeto no manager do Phaser 3 para facilitar sua criacao
export default class WordsPlugin extends Phaser.Plugins.BasePlugin {
    constructor(pluginManager){
        super(pluginManager);
        pluginManager.registerGameObject('words', this.createWords);
    }

    createWords(x, y, wordStack, config){
        return this.displayList.add(new Words(this.scene, x, y, wordStack));
    }
}