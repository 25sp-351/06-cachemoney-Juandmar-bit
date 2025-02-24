This program accept an integer as a dollar value and convert to a  textual representation. 
In this program the user should be aware that the input has to be contain cents in the value. If the user want to input $133.34 the user has to type 13334 a whole. The max value with textual representation has to be less and equal 150000.
1. First case: Positive value. Whole numbers no cents.

    Input = 150000
    Output = one thousand five hundred

2. Second case: Positive value. Dollars and cents.

    Input: 3244
    Output: 3244 = thirty two dollars and forty four cents

3. Third case: Only cents.
        
    Input: 34
    Output: 34 = thirty four cents

4. Fourth case: Integers with character
    
    Input: 23dwd
    Output: The value is not an integer.

5. Fifth case: Value is greater than the value allowed.
    
    Input: 433443
    Output: The value is greater than one thousand five hundred dollars.

6. Sixth case: Value contains only characters.
    
    Input: dice
    Output: The value is not an integer.

7. Seventh case: Non-positive values.

    Input: -32
    Output: The value contains non-positive integers.

8. Eigth case: Value contains hundred with cents.

    Input: 32433
    Output: three hundred twenty four dollars and thirty three cents

9. Ninth case: Positive value. Dollars and cents saved in memoization.

    Input: 3244
    Output: 3244 = thirty two dollars and forty four cents

    Other Cases: 
    Input: 1 
    Output: one cent
    16 -> 'sixteen cents'
    55 -> 'fifty-five cents'
    94 -> 'ninety-four cents'
    97 -> 'ninety-seven cents'
    228 -> 'two dollars twenty-eight cents'
    264 -> 'two dollars sixty-four cents'
    368 -> 'three dollars sixty-eight cents'    
    381 -> 'three dollars eighty-one cents'
    418 -> 'four dollars eighteen cents'