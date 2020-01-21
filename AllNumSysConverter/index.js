import { DECTO, BINTO, HEXTO, OCTTO } from './lib.js';
let inputBaseElem = document.querySelector('#inputBase');
let outputBaseElem = document.querySelector('#outputBase');
let inputValElem = document.querySelector('#inputVal');

const task = {
  fromBase: 'DEC',
  toBase: 'BIN',
  inputValue: '0',
  outputValue: '0',
  operator: null
};

inputBaseElem.addEventListener('input', function(e){
  setBase();
  setOperator();
  executeOperation();
  showResult();
  console.log(task);
});

outputBaseElem.addEventListener('input', function(e){
  setBase();
  setOperator();
  executeOperation();
  showResult();
  console.log(task);
});

inputValElem.addEventListener('keyup', function(e){
  let value = e.target.value;

  if(value && value!==''){
    setInputValue(value);
    setOperator();
    executeOperation();
    showResult();

    console.log(task);
  }else{
    console.error('Invalid Input');
  }
})

function setInputValue(value) {
  task.inputValue = value+''; // force to string
}

function setBase(){
  let selectedInputBase = document.querySelector('#inputBase :checked');
  let selectedOutputBase = document.querySelector('#outputBase :checked');

  task.fromBase = selectedInputBase.value;
  task.toBase = selectedOutputBase.value;
}

function setOperator(){
  const opMap = {
    DEC: DECTO,
    BIN: BINTO,
    HEX: HEXTO,
    OCT: OCTTO
  };
  let operator = opMap[task.fromBase][task.toBase];
  task.operator = !!operator ? operator : null; 
}


function executeOperation(){
  if(task.operator)
    task.outputValue = task.operator(task.inputValue);
}

function showResult(){
  
  document.querySelector('#toConverted').innerHTML = task.outputValue;
}