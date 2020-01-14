export const DECTO = {
  BIN: function(decimal){
    return toBinary( decimal );
  },
  OCT: function(decimal){
    return toOctal( decimal );

  },
  HEX: function(decimal){
    return toHex( decimal );
  },
  Hello: "World"
};


export function toBinary(decimal){
  if(decimal==0) return 0;

  return decimal % 2 + 10 * toBinary(Math.floor(decimal / 2));
}
export function toOctal(decimal){
  if(decimal==0) return 0;

  return decimal % 8 + 10 * toOctal(Math.floor(decimal / 8));
}

export function toHex(decimal){
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