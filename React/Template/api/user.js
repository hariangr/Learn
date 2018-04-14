const express = require('express');

const router = express.Router();

// /api/user
router.get('/', (req, res) => {
  // PLACEHOLDER
  res.json({
    code: 0,
    msg: 'Hello, this is a placeholder'
  })
});

module.exports = router;
