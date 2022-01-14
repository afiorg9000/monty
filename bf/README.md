#1000-school.bf
/** Using different cells to store different numeric values
* Cell 1 = 80; Cell 2 = 100;
* These base values can then be incremented or decremented
* to store ASCII values of the characters we need to print */
++++++++++ //Cell 1 = 10(To run the loop 10 times)
+++++ +++++
[
>++++++++ // Cell 1 = 8*10
>++++++++++ // Cell 2 = 10*10
<<- // Setting the pointer back to cell 0 & decrement
] // end of loop
	> +
	> +++++ +++
	> +++++ +++++
	<<< -
]
/**Final numeric values in each cell
*Cell 0 = 0; Cell 1 = 80; Cell 2 = 100;*/

// Moving from Cell 0 to Cell 1
>+++. // Printing "S"(ASCII 83)
// Moving from Cell 1 to Cell 2
>-.+++++.+++++++..---. // Printing "chool"(ASCII 99, 104, 111, 111, 108)
>> +++ .
> - . +++++ . +++++ ++ . . --- .
<< .
