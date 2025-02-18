function openPresent(event) {
    const image = event.currentTarget;
    image.src = 'https://media.giphy.com/media/27ppQUOxe7KlG/giphy.gif';
   
   image.removeEventListener('click', openPresent); 
   image.addEventListener('click', closePresent);
    
  }
  
  function closePresent(event) {
    const image = event.currentTarget;
    image.src = 'https://s3-us-west-2.amazonaws.com/s.cdpn.io/1083533/gift-icon.png';
      image.removeEventListener('click', closePresent);
      image.addEventListener('click', openPresent);
    
  }
  
  const image = document.querySelector('img');
  image.addEventListener('click', openPresent);