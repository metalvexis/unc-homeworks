export default {

	getInfo(){
		return global.localPouch.info();
	},

	getAllDocs(){
		return global.localPouch.allDocs();
	}

};