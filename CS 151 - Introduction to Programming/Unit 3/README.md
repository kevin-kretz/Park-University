# Project

Implement a program that processes people as they arrive at a concert. Your program should prompt the user for their role. It then prompts for their credentials. Here are the four types of people (their roles) and the credentials they need to enter the concert venue:

- regular fan – ticket
- VIP fan – ticket and backstage pass
- roadie – backstage pass
- venue employee – employee ID

After prompting the user for their role and whether they have the proper credentials to enter, your program should print instructions, telling the user where to go. The sample sessions show the messages your program should display when the user is properly credentialed. If the user is not properly credentialed, your program should display “Sorry, you need to leave.”

For the user’s role question (which asks for 1, 2, 3, or 4), you may assume the user enters an integer.

For the credentials questions, you may assume the user enters “y” or “Y” for yes or “n” or “N” for no.

As always, you must mimic the sample session precisely. In particular, note the colons, blank spaces, blank lines, and so on.

### Sample Session - Regular Fan (Pass)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 1
Do you have a ticket? (y/n): Y

Proceed to the standard seating area.
```

### Sample Session - Roadie (Pass)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 3
Do you have a backstage pass? (y/n): y

Find the band and do what they need.
```

### Sample Session - Venue Employee (Pass)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 4
Do you have an employee ID? (y/n): y

Go to your work area.
```

### Sample Session - VIP Fan (Pass)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 2
Do you have a ticket? (y/n): Y
Do you have a backstage pass? (y/n): y

Proceed to the VIP seating area.
```

### Sample Session - VIP Fan (Fail)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 2
Do you have a ticket? (y/n): n
Do you have a backstage pass? (y/n): y

Sorry, you need to leave.
```

### Sample Session - Invalid Input (Fail)

```
Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?
Enter 1, 2, 3, or 4: 6

Sorry, invalid input. You need to leave.
```
