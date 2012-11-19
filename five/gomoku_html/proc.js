var BLACK = 1;
var BLANK = 0;
var WHITE = 2;
var _isEnabled = true;
var _whosTurn = BLACK;
var bdmap = new Array(225);
var history_vector = [];

var history_current_step = undefined;

function nameChanged(v, index){
    var label;
    if(index == 1)
        label = document.getElementById("p1_name");
    else
        label = document.getElementById("p2_name");
    label.innerHTML = v;
}

function history_load(){
		
}

function history_save(){
	if(_isEnabled){
		alert("Not ended!");
		return;
	}
	localStorage.setItem("History", history_vector);
}


function history_back(){
	if(history_current_step == undefined || history_current_step == 0)
		return;
	
}

function history_forward(){
	if(history_current_step == undefined)
		return;
	
}

function hasFive(loc, patt){
    var loc_i,loc_j;
    var i,j,count;
    i = loc_i = Math.floor(loc / 15);
    j = loc_j = loc % 15;
    //up down 5
    while(i >= 0 && bdmap[i*15 + j] == patt)
        --i;
    ++i; count = 0;
    while(i < 15 && bdmap[i*15 + j] == patt){
        ++count; ++i;
    }
    if(count >= 5)
        return true;
    // left right 5
    i = loc_i; j = loc_j;
    while(j >= 0 && bdmap[i*15 + j] == patt)
        --j;
    ++j; count = 0;
    while(j < 15 && bdmap[i*15 + j] == patt){
        ++count; ++j;
    }
    if(count >= 5)
        return true;
    //up left - down right 5
    i = loc_i; j = loc_j;
    while(i >= 0 && j >= 0 && bdmap[i*15 + j] == patt){
        --i; --j;
    }
    ++i; ++j; count = 0;
    while(i < 15 && j < 15 && bdmap[i*15 + j] == patt){
        ++count; ++i; ++j;
    }
    if(count >= 5)
        return true;
    //up right - down left 5
    i = loc_i; j = loc_j;
    while(i >= 0 && j < 15 && bdmap[i*15 + j] == patt){
        --i; ++j;
    }
    ++i; --j; count = 0;
    while(i < 15 && j >= 0 && bdmap[i*15 + j] == patt){
        ++count; ++i; --j;
    }
    if(count >= 5)
        return true;
    //no five
    return false;
}

function setPiece(id){
    if(_isEnabled == false || bdmap[parseInt(id)] != BLANK)
        return;
    var loc = document.getElementById(id);
    var pic = document.createElement("img");
    if(_whosTurn == BLACK)
        pic.src = "./res/blackp.png";
    else
        pic.src = "./res/whitep.png";
    loc.appendChild(pic);
    bdmap[parseInt(id)] = _whosTurn;
    if(hasFive(id, _whosTurn)){
        _isEnabled = false;
        document.getElementById("notice").
            innerHTML = "Winner is :";
       document.getElementById("notice").innerHTML += _whosTurn == BLACK ? 
            document.getElementById("p1_name").innerHTML : 
            document.getElementById("p2_name").innerHTML;
            return;
    }
	history_vector.push([id,_whosTurn]);
    _whosTurn = 3 - _whosTurn;
}

function mouseOver(id){
    if(_isEnabled)
        document.getElementById(id).setAttribute("active", "");
}

function mouseOut(id){
    if(_isEnabled)
        document.getElementById(id).removeAttribute("active");
}

window.onload = function(){
    var board = document.getElementById("board");
    var pre_x = 23;
    var pre_y = 18;
    var dv = document.createElement("div");
    dv.setAttribute("class", "piece");
    dv.setAttribute("onClick", "setPiece(this.id)");
    dv.setAttribute("onmouseover", "mouseOver(this.id)");
    dv.setAttribute("onmouseout", "mouseOut(this.id)");
    dv.id = "0";
    board.appendChild(dv);
    for(var i = 1; i < 225; ++i){
        if(i % 15 == 0){
            var t = document.createElement("div");
            t.setAttribute("class", "piece");
            board.appendChild(t);
        }
        dv = document.createElement("div");
        dv.setAttribute("class", "piece");
        dv.setAttribute("onClick", "setPiece(this.id)");
        dv.setAttribute("onmouseover", "mouseOver(this.id)");
        dv.setAttribute("onmouseout", "mouseOut(this.id)");
        dv.id = i.toString();
        board.appendChild(dv);
        bdmap[i] = BLANK;
    }
}
