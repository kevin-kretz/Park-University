function addGame(form) {
  const GAMES_TABLE = document.getElementById("games-table");  // set a constant variable to be the location of the games table
  GAMES_TABLE.insertRow(GAMES_TABLE.rows.length);  // inserts row at bottom of table
  var row = GAMES_TABLE.rows.item(GAMES_TABLE.rows.length - 1);  // set row variable to the row index that was just created

  var avg = form.elements["H"].value / form.elements["AB"].value;  // calculates the average
  var obp = (form.elements["H"].value + form.elements["BB"].value) / (form.elements["AB"].value+ form.elements["BB"].value)  // calculates the on base percentage

  row.insertCell(0).innerHTML = GAMES_TABLE.rows.length;  // insert the game number
  row.insertCell(1).innerHTML = form.elements["POS"].value;  // inserts selected position
  row.insertCell(2).innerHTML = form.elements["AB"].value;  // inserts numbe of at bats
  row.insertCell(3).innerHTML = form.elements["H"].value;  // inserts number of hits
  row.insertCell(4).innerHTML = form.elements["HR"].value;  // inserts number of homeruns
  row.insertCell(5).innerHTML = form.elements["BB"].value;  // inserts number of walks
  row.insertCell(6).innerHTML = avg.toPrecision(3);  // inserts average; decimal places limited to 3
  row.insertCell(7).innerHTML = obp.toPrecision(3);  // inserts onbase percentage; limits decimal places to 3

  alert("Your game was added!");  // alerts user game was added to the table
}
