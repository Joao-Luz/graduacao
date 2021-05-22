import "phaser"
import config from '../config/config'

class EndCard extends Phaser.GameObjects.Container {
    constructor(scene, x, y){
        super(scene, x, y);

        // montando o cartao que mostra as estatisticas
        const style = {color: 'black', fontSize: 20, fontFamily: 'upheave', align: 'center', color: '#3f3f74'};
        const card = scene.add.image(0, 20, 'card').setOrigin(0.5, 0);
        this.score = scene.add.text(-120, 30, ``, style).setFontSize(30).setResolution(2).setOrigin(0, 0);
        this.wpm = scene.add.text(-120, 70, ``, style).setOrigin(0, 0);
        this.cpm = scene.add.text(-120, 90, ``, style).setOrigin(0, 0);
        this.sequence = scene.add.text(-120, 110, ``, style).setOrigin(0, 0);
        this.precision = scene.add.text(-120, 130, ``, style).setOrigin(0, 0);
        // botao para reiniciar o jogo
        const restartButton = scene.add.button(50, 155, 'restart_btn', {
            callback: () => {
                this.scene.restart();
                this.setY(config.height+200);
            },
            callbackScope: this
        }).setOrigin(.5, 0);
        // botao de retornar para o menu
        const menuButton = scene.add.button(-50, 155, 'menu_btn', {
            callback: () => {
                this.scene.exit();
            },
            callbackScope: this
        }).setOrigin(.5, 0);
        this.trophy = scene.add.image(120, 30, 'trophy', 0).setOrigin(1, 0)
        this.add([card, this.score, this.wpm, this.cpm, this.sequence, restartButton, menuButton, this.trophy, this.precision]);
        this.setY(config.height+200);
        this.setDepth(1); // colocando o menu na frente da tela

    }

    start(stats){
        this.score.setText(`${stats.score} pontos!`);
        this.wpm.setText(`${stats.maxWords} palavras`);
        this.cpm.setText(`${stats.maxCharacters} cpm`);
        this.sequence.setText(`${stats.maxSequence} seguidas`);
        this.precision.setText(`${(stats.precision * 100).toFixed(0)}% de precisão`);
        if(stats.score > 20000) this.trophy.setFrame(0);
        else if(stats.score > 10000) this.trophy.setFrame(1);
        else if(stats.score > 5000) this.trophy.setFrame(2);
        else this.trophy.setFrame(3);

        // animando o menu para aparecer por debaixo da tela
        this.scene.tweens.add({
            duration: 200,
            targets: this,
            y: 40,
        });
    }
}

// adicionando o objeto no manager do Phaser 3 para facilitar sua criacao
export default class EndCardPlugin extends Phaser.Plugins.BasePlugin {
    constructor(pluginManager){
        super(pluginManager);
        pluginManager.registerGameObject('endcard', this.createEndCard);
    }

    createEndCard(x, y, stats){
        return this.displayList.add(new EndCard(this.scene, x, y, stats));
    }
}