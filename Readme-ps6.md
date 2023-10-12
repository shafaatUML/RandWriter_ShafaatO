# PS6: RandWriter

## Contact
Name: Shafaat Osmani
Section: 201
Time to Complete: 8 HRS


## Description
Explain what the project does.
The project rearranges given text by randomizing a given chunk of text. 

### Features
Describe what your major decisions were and why you did things that way.
I decided to use a multimap and a map to keep trap of all the data. The multimap stores the kgrams as well as the next char and the next char frequency. I then realized I needed a way to store the kgram frequency so I made another map and stored the kgram into both of them. 

### Testing
What tests did you write?  What exceptions did you use?  Does your code pass the tests?
I wrote tests to ensure each member function works properly. Many of these tests simply test to see if arguments are valid. All tests pass. 

### Lambda
What does your lambda expression do?  What function did you pass it to?

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
I had trouble with iterating through the multimap. I ended up using many iterators and nested for loops to do tedious tasks. 

### Extra Credit
Anything special you did.  This is required to earn bonus points.
Did you make a new instrument?  What is the instrument and how did you make it?  How does the user choose between the guitar or the new instrument?

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
https://www.geeksforgeeks.org/traverse-values-given-key-multimap/
