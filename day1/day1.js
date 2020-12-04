function inputInts() {
    var array = [];
    var xmlhttp;
    xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            var text = xmlhttp.responseText;
            array = text.split(/\n|\r/g);
            findMatch(2020, array);
        }
    }
    xmlhttp.open("GET", "http://localhost:8080/input.txt", true);
    xmlhttp.send();
};

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function randInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1) ) + min;
}

async function findMatch(goal, ints){
    var completed = document.getElementById("completeInner");
    var iBox = document.getElementById("iBox");
    var jBox = document.getElementById("jBox");
    for(var i = 0; i < ints.length - 1; i++) {
        completed.innerHTML = completed.innerHTML + "<p>" + ints[j] + "</p>";
    }
    for(var i = 0; i < ints.length - 1; i++) {
        for (var j = 0; j < ints.length - 1; j++) {
            var sum = parseInt(ints[i], 10) + parseInt(ints[j], 10);
            if(sum == goal) {
                document.getElementById("matching").innerHTML = "<p class='sucess'>Match!</p>"
                    + "<p>a: " + ints[i] + "</p><p>b: " + ints[j] + "</p><p>Total: " + ints[i] * ints[j];
                console.log("a: " + ints[i]);
                console.log("b: " + ints[j]);
                console.log("total " + ints[i]*ints[j]);

                return ints[i]*ints[j];
            };
            await sleep(randInt(10,200));
            jBox.innerHTML = "<p>" + ints[j] + "</p>";
        };
        await sleep(randInt(10,200));
        iBox.innerHTML = "<p>" + ints[i] + "</p>";
    };
    console.log("no match");
    document.getElementById("matching").innerHTML = "<p class='fail'>No Match</p>";
};