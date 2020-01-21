export const DECTO = {
  BIN: function(decimal){
    return DecToBinary( decimal );
  },
  OCT: function(decimal){
    return DecToOctal( decimal );

  },
  HEX: function(decimal){
    return DecToHex( decimal );
  }
};

export const BINTO = {
  DEC: function(bin){
    return BinToBaseX(bin, 0);
  },
  OCT: function(bin){
    return BinToBaseX(bin, 8);
  },
  HEX: function(bin){
    return BinToBaseX(bin, 16);
  }
};

export const HEXTO = {
  DEC: function(hex){
  },
  BIN: function(hex){
  },
  OCT: function(hex){
  }
};

export const OCTTO = {
  DEC: function(oct){
  },
  BIN: function(oct){
  },
  HEX: function(oct){
  }
};

// Decimal conversions

export function DecToBinary(decimal){
  if(decimal==0) return 0;

  return decimal % 2 + 10 * DecToBinary(Math.floor(decimal / 2));
}
export function DecToOctal(decimal){
  if(decimal==0) return 0;

  return decimal % 8 + 10 * DecToOctal(Math.floor(decimal / 8));
}

export function DecToHex(decimal){
  let store = '';

  while(decimal!=0){
    let hex = decimal%16;

    if(hex>9){
      console.log('moreThan9')
      store+= String.fromCharCode(55+hex);
    }else{
      console.log('lessThan9')
      store+=hex;
    }
    decimal = Math.floor(decimal/16);
  }
  
  return store;
}

// Binary conversions

function BinToBaseX(bin, base){
  let binStringGrp = [];
  let output = "";
  switch (base) {
    case 8:
      // OCT
      binStringGrp = chunkString(reverseString(bin), 3)
      break;
    case 16:
      // HEX
      binStringGrp = chunkString(reverseString(bin), 4)
      break;
    default:
      binStringGrp.push(reverseString(bin));
      break;
  }

  console.log('binStringGrp');
  console.log(binStringGrp);

  let convertedArr = convertBinGrp(binStringGrp);
  
  convertedArr.forEach(elem=>{
    if(base==16 && parseInt(elem)>9){
      output+= String.fromCharCode(55+ parseInt(elem));
    }else{
      output+=elem;
    }
    
  });
  output = reverseString(output);

  console.log(`Result ${output}`)
  return output;
  function chunkString(str, length) {
    if(!str || !length){
      return null;
    }
    // Source : https://stackoverflow.com/questions/7033639/split-large-string-in-n-size-chunks-in-javascript
    let grouped = str.match(new RegExp('.{1,' + length + '}', 'g'));

    return grouped;
  };

  function reverseString(str){
    let binArr = str.split('');
    let reversedArr = binArr.reverse();
    let joinedStr = reversedArr.join('')

    return joinedStr;
  }

  function convertBinGrp(binGroup){
    let output = [];
    for (let index = 0; index < binGroup.length; index++) {
      const binGrp = binGroup[index];
      
      output.push(0);
      
      binGrp.split('').forEach((bin,idx)=>{
        console.log(bin, idx, Math.pow(2, idx))

        let lastItem = output[output.length-1];
        lastItem += bin==1?Math.pow(2, idx):0;
        output[output.length-1] = lastItem;
      });
      
    }

    console.log('output');
    console.log(output);
    return output;
  }
}