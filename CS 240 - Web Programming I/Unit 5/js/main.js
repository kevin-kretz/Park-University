function showResults() {
  var name = document.getElementById("name").value;  // gets name from form and stores it in a variable
  var email = document.getElementById("email").value;  // gets email address for later use
  var dob = document.getElementById("dob").value;  // gets email address for later use

  alert("Thanks for submitting your form, " + name + ".\n" + 
  "Your email was submitted as: " + email + "\n" +
  "Your date of birth was submitted as: " + dob);

  return false;
}
