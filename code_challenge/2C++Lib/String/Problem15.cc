// Question 15
	// 657. Judge Route Circle
	// 	Initially, there is a Robot at position (0, 0). Given a sequence of its moves, 
	// judge if this robot makes a circle, which means it moves back to the original place.
	//  The move sequence is represented by a string. And each move is represent by a character. 
	// The valid robot moves are R (Right), L (Left), U (Up) and D (down). 
	// The output should be true or false representing whether the robot makes a circle.

// Example
	// Input: "UD"
	// Output: true

	// Input: "LL"
	// Output: false

// Implementation
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    var num = [0,0]
    var res = moves.split("");
    for (i = 0; i < res.length; i++){
        var s = res[i];
        if (s == "U"){
            num[1] += 1;
        } else if (s == "D"){
            num[1] -= 1;
        } else if (s == "L"){
            num[0] -= 1;
        } else if (s == "R"){
            num[0] += 1;
        } 
    }
    if (num[0] == 0 && num[1] == 0)
        return true;
    else 
        return false;
};