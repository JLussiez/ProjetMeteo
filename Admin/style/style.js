document.getElementById("confirm").hidden = true;
document.getElementById("Cancel").hidden = true;


var suppr = document.getElementById("truncate");
suppr.addEventListener("click",function(){
    document.getElementById('truncate').hidden = true;
    document.getElementById('confirm').hidden = false;
    document.getElementById('Cancel').hidden = false;
});

var cancel = document.getElementById("Cancel");
cancel.addEventListener("click", function(){
    document.getElementById('truncate').hidden = false;
    document.getElementById('confirm').hidden = true;
    document.getElementById('Cancel').hidden = true;
});