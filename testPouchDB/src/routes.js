import { configuredPouch, app } from './';

app.get('/', (req, res) => res.send('ROOT'));

app.use('/pouchdb', expressPouch( configuredPouch ) );

app.use('/api', api_v1 );