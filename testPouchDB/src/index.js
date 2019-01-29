import express from 'express';
import api_v1 from './api/v1';
import PouchDB from 'pouchdb';
import expressPouch from 'express-pouchdb';

const app = express();
const port = 3000;
const configuredPouch = PouchDB.defaults({prefix:'./pouch/'});

global.localPouch = new configuredPouch('localdb');

app.get('/', (req, res) => res.send('CATALYST SERVER RUNNING'));

app.use('/pouchdb', expressPouch( configuredPouch ) );

app.use('/api', api_v1 );

app.listen(port, () => console.log(`Listening on port: ${port}`));