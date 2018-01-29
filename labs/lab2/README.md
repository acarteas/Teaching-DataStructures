# CS 211 Lab #2
It turns out that the conspiracy theorists were right this whole time, you can actually embed secret messages into images!  In this lab, you will decode secret messages that I've embedded into PPM files.  Here's how I've done it:

The first pixel's RED value contains the first character of the hidden text.  The GREEN and BLUE values represent the location of the next hidden character.  The GREEN value represents the Y coordinate and the BLUE value represents the X coordinate.  You will know that you're done decoding when BOTH the GREEN and BLUE values are equal to zero.  Once you have decoded the message, output the result back to the screen.  

To complete this assignment, I would highly recommend using the ppmDocumentFromFile and ppmDocumentToFile functions found in the PA #1 starter code. 

To receive credit on this assignment, you must demo your completed work to Adam by the end of next lab.  

## EXTRA CREDIT
* Extra credit will be awarded to students who figure out how to encode their own messages into PPM documents.  
* Even more extra credit will be awarded to students who can embed secret messages into existing images