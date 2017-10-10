// 2017.10.08
// Assignment 4 Question 1
     // Dynamic Programming to break a paragraph into lines. 
     // This problem is about choosing line breaks to format a paragraph nicely. 
     // Suppose that the paragraph has n words of lengths l1, l2, . . . , ln in that order. 
     // Each pair of consecutive words in a line must be separated by a blank, and a blank has length 1. 
     // Suppose that the maximum line length is L.

     // For example, here are three different formatting choices:
     // Example 1:
     //      I propose to consider the
     //      question, ‘Can machines think?’
     //      This should begin with definitions of
     //      the meaning
     //      of the terms ‘machine’ and ‘think’.
     
     // Example 2:
     //      I propose to consider the question,
     //      ‘Can machines think?’ This should
     //      begin with definitions of the meaning
     //      of the terms ‘machine’ and ‘think’.
     
     // Example 3:
     //      I  propose to consider  the question,
     //      ‘Can  machines  think?’  This  should
     //      begin with definitions of the meaning
     //      of  the  terms ‘machine’ and ‘think’.

     // The second example chooses the line breaks to make the lines roughly equal in length.
     // The third example adds extra blanks between words to right-justify (so all lines have the same length).
     // Give a dynamic programming algorithm to choose line breaks and add extra blanks 
     // so that all lines have the same length L. A line cannot start or end with a blank. This means that a line cannot 
     // have just one word unless that word has exactly L characters, so there are inputs that
      
     // have no solution. Let m be the maximum number of blanks in a row that you add between words. Your goal is to find a solution that minimizes m.
     // Note: If words i,i+1,...,j go on a line then the number of characters in the line is at least ci,j = j − i +  jk=i lk. 
     // To get line length L, the number of extra blanks you must add is L − ci,j , and you will distribute these blanks 
     // as equally as possible in the j − i spaces between the words.
     // Give a dynamic programming algorithm to find the minimum value m. 
     // The run-time should be O(n2). Clearly indicate what your subproblems are, and the order in which you solve them. 
     // Justify correctness of your algorithm, and analyze its running time.


