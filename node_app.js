const http = require('http');
const process = require('process');
const os = require('os');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');

  //var used_mem = os.totalmem() - os.freemem();
  var free_mem_gb = (os.freemem() / 1024 / 1024 / 1024).toFixed(2);
  //var used_mem_gb = (used_mem / 1024 / 1024 / 1024).toFixed(2);
  var total_mem_gb = (os.totalmem() / 1024 / 1024 / 1024).toFixed(2);

  res.write(`Node.js version: ${process.versions['node']}\n`);
  res.write(`V8 version: ${process.versions['v8']}\n`);
  res.write(`zlib version: ${process.versions['zlib']}\n`);
  res.write(`OpenSSL version: ${process.versions['openssl']}\n`);
  res.write(`Unicode version: ${process.versions['unicode']}\n`);
  res.write('=====\n');
  res.write(`Platform: ${os.platform()}\n`);
  res.write(`OS name: ${os.type()}\n`);
  res.write(`OS release: ${os.release()}\n`);
  res.write(`Arch: ${os.arch()}\n`);
  res.write(`Uptime: ${Math.floor(os.uptime())} seconds\n`);
  res.write(`CPUs: ${os.cpus().length}\n`);
  res.write(`CPU model: ${os.cpus()[0]['model']}\n`);
  res.write(`CPU frequency: ${os.cpus()[0]['speed']} MHz\n`);
  res.write(`Free memory: ${free_mem_gb} GB\n`);
  //res.write(`Used memory: ${used_mem_gb} GB\n`);
  res.write(`Total memory: ${total_mem_gb} GB\n`);
  res.write(`Home directory: ${os.homedir()}\n`);
  res.write(`Directory for temporary files: ${os.tmpdir()}\n`);
  res.write(`Hostname: ${os.hostname()}\n`);
  res.write(`Username: ${os.userInfo()['username']}\n`);
  res.write(`UID: ${os.userInfo()['uid']}\n`);
  res.write(`User shell: ${os.userInfo()['shell']}\n`);

  res.end();
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
