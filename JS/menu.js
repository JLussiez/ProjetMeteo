


let menuToggle = document.getElementById('toggle');
let navigation = document.getElementById('navigation');
menuToggle.addEventListener('click', function(){
    menuToggle.classList.toggle('active');
    navigation.classList.toggle('active');
});

//activation du fond blanc pour la page séléctionner
let list = document.querySelectorAll('.list');
for (let i = 0; i<list.length; i++){
list[i].onclick = function(){
    let j = 0;
    while(j < list.length){
        list[j++].className = 'list';
    }
    list[i].className = 'list active';
}
}