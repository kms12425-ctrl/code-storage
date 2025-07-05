var ourstr = "fsa";
ourstr += ourstr;
ourstr[0] = "j";
console.log(ourstr);
var result = abc(ourstr, ourstr)
console.log(result)


function abc(abv, diu)
{
    var result = abv + diu
    return result;
}