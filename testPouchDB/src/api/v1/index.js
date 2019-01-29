import express from 'express';
import localdb from '../../pouchdb';

const router = express.Router();

router.get('/', function (req, res) {
  res.send({status: 'OK'});
});

router.get('/get_info', function (req, res) {

	localdb.getInfo().then((info)=>{
		res.json(info);
	})
  
});

router.get('/get_all_docs', function (req, res) {

	localdb.getAllDocs().then((docs)=>{
		res.json(docs);
	})
  
});

export default router;