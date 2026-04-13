# Compiler

A simple project demonstrating the operation of a compiler with lexical, semantic and syntactic analysers and generators. It transforms simple code from input.txt into C++ language.

Compile the program: 
`$ make` 

Create an input.txt file (an example follows) and run the program:
`$ ./compiler`

The file output.cc will be created, containing C++ code.

The tokens accepted by the compiler grammar are:
<pre>
token	 =	 &lt;car&gt; ::= [0-9]+
		     &lt;tree&gt; ::= [0-9]+ ou [0-9]+.[0-9]+
		     &lt;banana&gt; ::= "[^"]*"	
		     [A-Za-z]+ ::= [0-9]+ ou  [0-9]+.[0-9]+ ou "[^"]*"
		     &lt;se&gt; (expr) {token}
		     &lt;se&gt; (expr) &lt;senao> {token}
		     &lt;whilst&gt; (expr) {token}
		     &lt;para&gt; (exprPara) {token}
		     ø
expr	=	variable == [0-9]+ or "[^"]*"
		    variable != [0-9]+ or "[^"]*"
		    variable >= [0-9]+ or "[^"]*"
		    variable =< [0-9]+ or "[^"]*"
		    variable > [0-9]+ or "[^"]*"
		    variable < [0-9]+ or "[^"]*"
exprPara = 	&lt;car&gt; variable, variable < [0-9]+, variable++ 	
variable  =	[A-Za-z0-9]
</pre>

**Car:**
Represents a positive 16-bit integer value. Accepts numbers up to 4,294,967,295. Can be declared alone or declared and initialised.

Declaration:
<pre>
car x;
</pre>

Declaration and initialisation: 
<pre>
car x = 99; 
</pre>

The token must be written correctly, and there must be a space between the token and the variable (in this example, we use the variable x). Additionally, it must end with a semicolon (;).

**Tree:**
It represents a positive integer or float (decimal, i.e., floating-point) value up to 3.4×10^38. It can be declared alone or declared and initialised.

Declaration: 
<pre>
tree y; 
</pre>

Declaration and initialisation (with floating point):
<pre>
tree y = 9.9; 
</pre>

Declaration and initialisation (without floating point):
<pre>
tree y = 9; 
</pre>

The token must be written correctly, and there must be a space between the token and the variable (in this example, we use the variable y). Additionally, it must end with a semicolon (;).

**Banana:**
It represents a string. It can be declared alone or declared and initialised.

Declaration:
<pre>
banana z; 
</pre>

Declaration and initialisation:
<pre>
banana z = “c123”;
</pre>

The token must be written correctly, and there must be a space between the token and the variable (in this example, we use the variable z). Additionally, it must end with a semicolon (;).

**Grape:**

<pre>
grape(var); 
</pre>

Input. Equivalent to std::cin

**Avocado:**

<pre>
avocado(var); 
</pre>

Output. Equivalent to std::cout

**Se e se senao:**

Se e senão mean if and else in Portuguese.

**Whilst:**

Equivalent to a while loop.

**Para:**

It means for in Portuguese.

**Initializing already declared variables:**

You can initialise already declared variables. Considering x, y and z, respectively, integer, floating-point and banana:

<pre>
x = 1;
y = 1.2;
z = "Hello world"; 
</pre>
