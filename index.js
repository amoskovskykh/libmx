function foo() {
    let a = 15;
    return function() {
        return a++;
    }
}

let f = foo();

alert(f());
alert(f());