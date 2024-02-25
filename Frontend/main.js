async function testSetup(url) {
  try { 
    const response = await fetch(url);   // we are sending the url(which contains the necessary data to python, it returns a response
    document.getElementById('result').innerText = `Result`;
    const data = await response.json();  // the response is turned into a json format
    console.log(data);
  } catch (error) {           
    console.log('Error1');
  }
}

document.querySelector('#option-selection').addEventListener('submit', function (evt) {
  evt.preventDefault();
  document.getElementById('result').innerText = ``;
  const datatype = parseInt(document.querySelector('input[name="datatype"]:checked').value);
  const array_size = parseInt(document.getElementById('getArraySize').value);
  const index = parseInt(document.getElementById('getIndex').value);

  // Create JSON data
  if (array_size >= 1 && array_size <= 10000 && index >= 0 && index < array_size) {
        const jsonData = {
            "dataType": datatype,
            "arraySize": array_size,
            "searchIndex": index
        };
  console.log(JSON.stringify(jsonData));

  // Create url with JSON data
  let url = 'http://127.0.0.1:8008/cgi-bin/index.py/?';
  for (const key in jsonData) {
  	if (jsonData.hasOwnProperty(key)) {
		url += `${key}=${jsonData[key]}&`;
	  }
  }
  url = url.slice(0, -1);   // Remove the trailing '&' character
  console.log("Formatted URL:", url); // Example: http://127.0.0.1:5000/test_setup?dataType=2&arraySize=450&searchIndex=25
  testSetup(url);

  } else {
    	console.error("Invalid input values.");
  }
});
