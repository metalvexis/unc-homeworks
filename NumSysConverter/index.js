import { DECTO } from './lib.js';
let decimalInput = document.querySelector('#decimal');

decimalInput.addEventListener('keyup', function(e){
  let decimal = e.target.value;

  if(!isNaN(parseInt(decimal))){
    console.log(`decimal: `+decimal);
    decimal = parseInt(decimal);

    let bin = DECTO.BIN(decimal);
    document.querySelector('#toBinary').innerHTML = bin;

    let oct = DECTO.OCT(decimal);
    document.querySelector('#toOctal').innerHTML = oct;

    let hex = DECTO.HEX(decimal);
    document.querySelector('#toHex').innerHTML = hex;
  }else{
    console.error('Invalid Input');
  }
})