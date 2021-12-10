# COMP-3270-Introduction-to-Algorithms
# AUBURN CS/SE STUDENTS - DO NOT LOOK AT THIS. This Repo is for my personal storage and showcase. You learn nothing from cheating and it will only hurt you in the long run.

Empirical analysis of algorithms involves implementing, running and then analyzing the run-time data collected against theoretical predictions. This homework asks you to implement, and theoretically and empirically compute the complexities of algorithms with different orders of complexity to solve the problem of Maximum Sum Contiguous Subvector defined as follows:

Maximum Sum Contiguous Subvector (MSCS) Problem: Compute the sum of the subsequence of numbers (a subsequence is a consecutive set of one or more numbers) in an array of numbers (for this HW, we will use integers) that sum to the largest value possible; but if this value is negative, MSCS is defined to be zero. E.g., in an array of all positive (or all negative) numbers, the Maximum Contiguous Subvector consists of all numbers in the array (or zero). There may be multiple Maximum Subsequences in an array, all of which sum to the same largest sum. E.g., in an array of all zeroes, MSCS =0 and any 0 in the array is a Maximum Subsequence. Remember that the input array may contain zeroes, negative and/or positive integers. For example, if the input is [1,2,-4,3,-5,2,0] then MSCS =3 and there are two Maximum Subsequences that sum to the same MSCS: A[1]+A[2]=1+2=3 or A[4]=3.

1. Implement the provided four algorithms of different complexity orders to solve this problem.
2. Calculate T(n) and the order of complexity of each algorithm in the big-Oh or Theta notation using any of the methods discussed in class.
3. Use C, Java, or C++
4. Write a program that carries out the following tasks:
5. First, the main program should read from a file named “phw_input.txt” containing 10 comma-delimited 
integers in the first line, create an array containing these 10 integers, and run each of the algorithms on that 
input array, and print out the answer produced by each on the console as follows: "algorithm-1: <answer>; 
algorithm-2:<answer>; algorithm-3:<answer>; algorithm-4:<answer>  where <answer> is the MSCS as 
determined by each of the algorithms.
6. Next, create 19 integer sequences of length 10,15,20,25,......90,95,100, containing randomly generated 
negative, zero and positive integers, and store these in 19 arrays of size 10,15,...,95,100: A1-A19.
7. Then use the system clock to measure time t1, run one of the four algorithms on array Ai (starting with i=1) 
N times (where N is at least 100, but if your system clock does not have a good resolution you may need N 
to be larger, like 500 or 1000 in order to get meaningful running times), then measure time t2, and compute 
average time needed by that algorithm to solve the problem with input size = size of Ai. Do this for each of 
the algorithms executing on each of the 19 input arrays to fill the first four columns of a 19X8 matrix of 
integers with average execution times.  Each row of this matrix corresponds to one input size, from 10-100. 
8. Fill the last four columns of this matrix with values ceiling(T1(n)), ceiling(T2(n)), ceiling(T3(n)), and 
ceiling(T4(n)) where n = each input size and T(n) are the polynomials representing the theoretically 
calculated complexity of the three algorithms that you determined in step 2 part (b). So, column 1 will have 
measured running times of your first algorithm and column 5 will have the calculated complexity for the 
same algorithm; similarly for columns 2 & 6, 3 & 7, and 4 & 8. You may need to scale the complexity 
values (or use an appropriate time unit such as nano/micro/milli seconds for the measured running times) in 
order to bring all data into similar ranges.
9. Your main program should write one text line of algorithm and complexity order titles separated by 
commas (e.g., "algorithm-1,algorithm-2,algorithm-3,algorithm-4,T1(n),T2(n),T3(n), T4(n)"), followed by the 
above matrix also in comma-delimited format (19 lines of 8 integers separated by commas) to a file called 
"yourname_phw_output.txt".
10. Open yourname_phw_output.txt with a spreadsheet and produce a labeled graph with 10-100 on the x-
axis and 8 curves showing the actual time taken and predicted time (the complexity order) for each 
algorithm. Label the curves appropriately.
  
Grade: 97/100
