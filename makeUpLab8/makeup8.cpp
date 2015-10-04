/*
Alex Roeum	
Makeup Lab 8-10
Sect. 003

Program to use a structure for an array cylinder with properties (attributes)
of height, radius, volume, and surface area.  Use will enter the
hieght and radius, the volume and surface area will be calculated for each.

input:  height and radius of each cylinder
output: height, radius, volume and surface area for each of the cylinders
processing:  volume = pir^2h, surface area = 2pir + 2prir^2

*/

# include <iostream>
# include <string>

using namespace std;

struct cylinder
{
	double height;
	double radius;
	double volume;
	double surf;
};

cylinder inputcylinder();
void outputcylinder(cylinder B);
double CheckDim(double val, string what);
int storeCylinder(cylinder clyinders[]);
void outputArray(cylinder cylinders[], int iterations);

const double PI = 3.14159;
int main()
{
	cylinder cylinderArray[75];
	int iteration;
	iteration = storeCylinder(cylinderArray);
	outputArray(cylinderArray, iteration);

	return 0;
}

/*  Function to input the attributes of a cylinder variable
The user will be prompted to enter theheight and
radius the the volume and surface area will be
calculated.  A variable of cylinder data type will
be returned;
input:  nothing will be passed to the function but
the user will be prompted to enter the height
and radius.
output:  a variable of cylinder data type will be
returned to the function call.
processing:  volume = pir^2h,
surface area = 2pir + 2prir^2
*/

cylinder inputcylinder()
{
	cylinder A;
	cout << "Enter the radius for a cylinder. ";
	cin >> A.radius;

	//call function to check
	CheckDim(A.radius, "radius");

	cout << "Enter the height for a cylinder. ";
	cin >> A.height;
	//call function to check
	CheckDim(A.height, "height");
	cout << endl;

	A.volume = PI * A.radius*A.radius*A.height;
	A.surf = 2 * PI * A.radius*A.radius
		+ 2 * PI * A.radius * A.height;
	return A;
}
/*  Function to output all the properties of a cylinder
variable.
input :  accept a variable of cylinder data type
output:  nothing is sent back to the function call
the properties are output
processing:  cout.

*/
void outputcylinder(cylinder B)
{
	cout << "A cylinder with a height of " << B.height
		<< " and radius of " << B.radius
		<< "\nhas a volume of " << B.volume
		<< " a surface area of " << B.surf << ".\n";
}


/*  Function to robustly check the entered value is greater than zero.
input:  the value and what it stands for is passed to the function by value
output: a value greater than 0 is returned to the function call
processing:  a while loop

*/
double CheckDim(double val, string what)
{
	while (val <= 0)
	{
		cout << "The " << what << " must be greater than zero!\nPlease enter a new value for "
			<< what << ". ";
		cin >> val;
	}
	return val;
}

/*
	Function to input the values for each values in a cylinder array. It will prompt the user if he/she wants
	to add another it will end when the user enters no.
	input: the values for each cylinder and if the user wants to continue
	output: the number of iterations of cylinders made
	processing: the values set for each cylinder
*/
int storeCylinder(cylinder clyinders[])
{
	int iterations = 0;
	bool cont = true;
	char input;
	do{

		clyinders[iterations] = inputcylinder();
		iterations++;
		cout << "Do you want to enter another Cylinder? (y/n)";
		cin >> input;
		cout << endl;

		if (input == 'y' || input == 'Y')
			cont = true;
		else if (input == 'n' || input == 'N')
			cont = false;

	} while (cont == true || (iterations > 75));
	
	return iterations;
}

/*
	function to output each cylinder with cylinder number
	input: the cylinder array and number of iterations
	ouput: each cylinder with its dimentions and number of cylinders
	processing: loop to output each cylinder
*/
void outputArray(cylinder cylinders[], int iterations)
{

	for (int i = 0; i < iterations; i++)
	{
		cout << "Cylinder " << i+1<<endl;
		outputcylinder(cylinders[i]);
		cout << endl;
	}
	cout << "There are "<<iterations<<" cylinders inputted."<<endl;
}
