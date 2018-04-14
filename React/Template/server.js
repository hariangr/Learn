const express = require('express');
const path = require('path');

const app = new express();

const userApi = require('./api/user');

app.use('/api/user', userApi);

app.use(express.static(path.join(__dirname, 'client', 'build')));

app.get('/*', (req, res) => {
  res.sendFile(path.join(__dirname, 'client', 'build', 'index.html'));
})

const port = process.env.PORT || 3003;
app.listen(port, () => {
  console.log(`Listening on port ${port}`);
})
