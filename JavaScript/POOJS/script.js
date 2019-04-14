/*
Create a object called stopwatch, that have three methods:
- start : Start the stopwatch, if already started we have to complain
- stop : Stops the stopwatch, if already stopped we have to complain
- duration : show the duration on seconds between the start and stop seconds, if doesnt reset, we added
- reset: Resets the count of the stopwatch
*/
function StopWatch(){
    let started = false;
    let duration = 0;
    let ti = 0;
    this.start = () =>{
        if(started){
            return Error('Already Started');
        }
        ti = Date.now();
        started = true;
    }
    this.stop = ()=>{
        if(!started){
            return Error('Not started');
        }
        duration += Date.now() - ti;
        ti = Date.now();
        started = false;
    }
    this.reset = () =>{
        duration = 0;
        ti = 0;
        started = false;
    }
    Object.defineProperty(this,'duration',{
        get: ()=>{
            return duration;
        }
    });
}