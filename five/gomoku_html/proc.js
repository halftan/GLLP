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
    clear_board(true);
	if(typeof(Storage) !== "undefined"){
        history_vector = JSON.parse(localStorage.getItem("History"));
        _whosTurn = BLACK;
        _isEnabled = false;
        history_current_step = 0;
        alert("History Loaded.");
    }
}

function clear_board(isreplay){
    var t;
    while(t = history_vector.shift()){
        bdmap[parseInt(t[0])] = BLANK;
        t = document.getElementById(t[0]);
        t.innerHTML = "";
    }
    if(!isreplay){
        _whosTurn = BLACK;
        _isEnabled = true;
    }
    t = document.getElementById("notice");
    t.innerHTML = "";
}

function history_save(){
	if(_isEnabled){
		alert("Not ended!");
		return;
	}
    localStorage.setItem("History", JSON.stringify(history_vector));
}


function history_back(){
	if(history_current_step <= 1)
		return;
    if(history_current_step == undefined){
        // one turn backward
      var l_one = history_vector.pop()[0];
      var l_two = history_vector.pop()[0];
      var loc_one = document.getElementById(l_one);
      var loc_two = document.getElementById(l_two);
      loc_one.innerHTML = "";
      loc_two.innerHTML = "";
      bdmap[parseInt(l_one)] = BLANK;
      bdmap[parseInt(l_two)] = BLANK;
    }
    else{
        var loc_bac = document.getElementById(history_vector.pop()[0]);
        loc_bac.innerHTML = "";
        _whosTurn = 3 - _whosTurn;
    }	
}

function history_forward(){
	if(history_current_step == undefined){
        alert("History not loaded!");
        return;
    }
    var his_t = history_vector.shift();
    if(!his_t){
        alert("Replay ended!");
        return;
    }
    setPiece_by_his(his_t[0]);
    if(_whosTurn != 3 - his_t[1]){
        alert("Error occured in history_set_piece");
        _whosTurn = 3 - _whosTurn;
    }
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

function setPiece_by_his(id){
    var loc = document.getElementById(id);
    var pic = document.createElement("img");
    if(_whosTurn == BLACK)
        pic.src = "./res/blackp.png";
    else
        pic.src = "./res/whitep.png";
    loc.appendChild(pic);
    _whosTurn = 3 - _whosTurn;
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
    history_vector.push([id,_whosTurn]);
    if(hasFive(id, _whosTurn)){
        _isEnabled = false;
        document.getElementById("notice").
            innerHTML = "Winner is :";
        document.getElementById("notice").innerHTML += _whosTurn == BLACK ? 
        document.getElementById("p1_name").innerHTML : 
        document.getElementById("p2_name").innerHTML;
            return;
    }
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
    bdmap[0] = BLANK;
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
