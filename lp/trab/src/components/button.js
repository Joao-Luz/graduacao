import 'phaser'

class Button extends Phaser.GameObjects.Image {
    constructor(scene, x, y, texture, config){
        super(scene, x, y, texture, config.frame);
        this.callback = config.callback;
        this.callback.bind(config.callbackScope);

        // caso nao sejam definidos os sprites para pointerover, pointerdown ou pointerup
        let frame = config.frame != undefined ? config.frame : 0;
        let over = config.over != undefined ? config.over : 1;
        let down = config.down != undefined ? config.down : 2;
        this.setInteractive({cursor: 'pointer'});
        this.on('pointerover', () => this.setFrame(over))
            .on('pointerout', () => this.setFrame(frame))
            .on('pointerdown', () => {
                this.setFrame(down);
                this.y += 1;
            })
            .on('pointerup', () => {
                this.y -= 1;
                this.setFrame(frame);
                this.callback();
            });
    }
}

// adicionando o objeto no manager do Phaser 3 para facilitar sua criacao
export default class ButtonPlugin extends Phaser.Plugins.BasePlugin {
    constructor(pluginManager){
        super(pluginManager);
        pluginManager.registerGameObject('button', this.createButton);
    }

    createButton(x, y, texture, config){
        return this.displayList.add(new Button(this.scene, x, y, texture, config));
    }
}