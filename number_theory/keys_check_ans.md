For this answer, I went with floor(sqrt(N))-1. The rationale for this from that once a number has crossed the point of a sqrt, then the value has already been checked. For instance, with the example of 77, if 7 * 11 is checked, then this is the same as 11 * 7. Next, the floor is taken. Once this sqrt value is found, then all that is needed is to round down from this. With 77, sqrt(77) is about 8.77. 8 is the last possible value that can divide 77, without going above the threshold value. At 9, we are repeating computations already done. Finally, the -1 is added because we do not need to check if 1 is a factor of N. 


floor(sqrt(519920566100540349463))-1 = 22801766730
