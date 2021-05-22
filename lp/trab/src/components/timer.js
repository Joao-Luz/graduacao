import "phaser"

class Timer extends Phaser.GameObjects.Text {
    constructor(scene, x, y, config, style){
        super(scene, x, y, config.time.toFixed(1), style);
        this.config = config;
        this.time = config.time;
        this.originalTime = config.time;
    }

    reset(){
        this.time = this.originalTime;
        this.setText(this.time.toFixed(1));
        this.setColor('white');
        if(this.timeEvent){
            this.timeEvent.remove();
            this.timeEvent.destroy();
        }
    }

    start(){
        // caso o relogio ja esteja rodando, reiniciar
        this.reset();
        this.setColor('white');
        this.time = this.originalTime;
        const callback = this.config.callback;
        const callbackScope = this.config.callbackScope;
        callback.bind(callbackScope);
        // atualizar o relogio a cada 0.1 segundos
        this.timeEvent = this.scene.time.addEvent({
            delay: 100,
            loop: true,
            callback: () => {
                this.time -= 0.1;
                // em 10 segundos o relogio fica vermelho
                if(this.time <= 10) this.setColor('red');
                // no final chama o callback definido e finaliza o evento de tempo
                if(this.time <= 0){
                    this.time = 0;
                    
                    this.setText('0.0');
                    this.timeEvent.remove();
                    this.timeEvent.destroy();
                }
                else this.setText(this.time.toFixed(1));
                callback(this.time);
            }
        });
    }

}

// adicionando o objeto no manager do Phaser 3 para facilitar sua criacao
export default class TimerPlugin extends Phaser.Plugins.BasePlugin {
    constructor(pluginManager){
        super(pluginManager);
        pluginManager.registerGameObject('timer', this.createTimer);
    }

    createTimer(x, y, config){
        return this.displayList.add(new Timer(this.scene, x, y, config, {fontSize: 40, fontFamily: 'upheave'},));
    }
}