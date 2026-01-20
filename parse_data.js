async function parse_data(url, type) {
  if ((url && type) && (['html', 'json', 'text'].includes(type))) {
    if (type === 'html') {
      return new DOMParser().parseFromString(await fetch(url).then(res => res.text()), 'text/html');
    }
    else if (type === 'json') {
      return await fetch(url).then(res => res.json());
    }
    else if (type === 'text') {
      return await fetch(url).then(res => res.text());
    }
  }
  else {
    return false;
  }
}
