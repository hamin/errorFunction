# errorFunction

errorFunction is a command line tool/program that I wrote for my Scientific Computing course at Wabash College. This was written when I was a junior in college in 2007 ... yeah its been a while :) .

The program evaluates an approximation of the [error function][errorFunction] over an interval given by the user. It also uses [Simpson's rule/method for numerical integration][simpson] for approximating the integral in the error function. The results are then printed on a text file labeled "results.dat" which is compatible with [gnuplot][gnuplot].

In order to compile the program just run make like so:

	make
	
This will create the executable program **_errorFunction_** which you can run like so:

	./errorFunction

You'll then be prompted to enter the startpoint, endpoint, and size of the integration steps used by the Simpson's method to evaluate the error function over that interval.

Once you've run the program, the approximate values of the error function over the interval are written the file **_results.dat_**. The file is GNUplot compatible. In order to plot it using gnuplot enter gnuplot like so:

	gnuplot

Once inside the gnuplot prompt, you can plot the results of the file like so:

	plot 'results.dat'

Hope someone finds this useful, enjoy :) !

  [errorFunction]: http://en.wikipedia.org/wiki/Error_function
  [simpson]: http://en.wikipedia.org/wiki/Simpson's_rule
  [gnuplot]: http://www.gnuplot.info/