/*
Supported links:
- https://t.me/socks?server=AAA&port=BBB
- https://t.me/socks?server=AAA&port=BBB&user=CCC&pass=DDD
- https://t.me/proxy?server=AAA&port=BBB&secret=CCC
- tg://socks?server=AAA&port=BBB
- tg://socks?server=AAA&port=BBB&user=CCC&pass=DDD
- tg://proxy?server=AAA&port=BBB&secret=CCC
*/

const proxy_link = prompt('Proxy link');

if (!URL.canParse(proxy_link)) {
  console.error('Invalid link');
}
else {
  const proxy_url = new URL(proxy_link);

  if (['https:', 'tg:'].includes(proxy_url.protocol) && proxy_url.search) {
    const params = Object.fromEntries(proxy_url.searchParams.entries());

    if (['/socks', '/proxy'].includes(proxy_url.pathname) || ['socks', 'proxy'].includes(proxy_url.host)) {
      console.log(`Hostname: ${params.server}`);
      console.log(`Port: ${params.port}`);
      if (params.user) console.log(`Username: ${params.user}`);
      if (params.pass) console.log(`Password: ${params.pass}`);
      if (params.secret) console.log(`Secret: ${params.secret}`);
    }
  }
}
