function updateWebsite(form) {
  var sectionHeader = document.getElementById("custom-header");  // set var to section header location
  sectionHeader.innerHTML = updateSectionHeader(form);  // update section header

  updateServicesTable(form);  // update the services table
  showConfirmation();  // alerts user with appointment confirmation
}

function updateSectionHeader(form) {
  var petsName = form.elements["pet-name"].value;  // get pets name from form
  if (petsName[petsName.length - 1] == "s") {  // if pet's name ends in s
    return(petsName + "' appointment:");  // return appropriate header
  }
  else {  // otherwise
    return(petsName + "'s appointment:");  // return appropriate header
  }
}

function updateServicesTable(form) {
  var totalCell = document.getElementById("total-cell");  // set var to the "total" cell
  var checkUp = form.elements["check-up"].checked;  // set variable to see if "check up" is checked
  var shots = form.elements["shots"].checked;  // set variable to see if "shots" is checked
  var emergency = form.elements["emergency"].checked;  // set variable to see if "emergency" is checked
  var other = form.elements["other"].checked;  // set variable to see if "other" is checked
  var total = 0;  // create variable for total cost; initialize to 0;

  if (checkUp) {  // if "check up" is checked
    addService("Check up", "$50.00");  // add service to services table
    total += 50;  // add to toal price
  }
  if (shots) {  // if "shots" is checked
    addService("Shots", "$100.00");  // add service to services table
    total += 100;  // add to toal price
  }
  if (emergency) {  // if "ermergancy" is checked
    addService("Emergency", "$150.00");  // add service to services table
    total += 150;  // add to toal price
  }
  if (other) {  // if "other" is checked
    addService("Other", "$100.00");  // add service to services table
    total += 100;  // add to toal price
  }

  totalCell.innerHTML = "$" + total + ".00";  // update total cell with total cost
}

function addService(service, price) {
  var servicesTable = document.getElementById("services-table");  // set variable for table location
  servicesTable.insertRow(servicesTable.rows.length);  // insert a row at the bottom of the table
  row = servicesTable.rows.item(servicesTable.rows.length - 1);  // create var row; initalize to the row that was just created
  row.insertCell(0).innerHTML = service; // insert a cell for the service provided
  row.insertCell(1).innerHTML = price;  // insert a cell for the price of the service
}

function preventFormReset(event) {
  event.returnValue = false;  // prevents form from reseting, when you click submit.
}

function showConfirmation(date) {
  alert("Thank you! Your appointment has been scheduled!");  // prints confirmation in alert box
}
