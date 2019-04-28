class ListBinding{
    constructor(element){
        this.listElement = element;
        this.textList = [];
    }
    static createListItem(someText){
        let item = document.createElement("li");
        let itemText = document.createTextNode(someText);
        item.appendChild(itemText);
        return item;
    }
    update(){
        while(this.listElement.firstChild){
            this.listElement.removeChild(this.listElement.firstChild);
        }
        for(text in textList){
            this.listElement.appendChild(ListBinding.createListItem(text));
        }
    }
    add(someText){
        this.textList.push(someText);
        this.update();
    }
    remove(index){
        this.textList.splice(index,1);
        this.update();
    }
}