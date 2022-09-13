
//1

Console.WriteLine($"It's easy to win forgiveness for being wrong; \n\t\tbeing right is what gets you into real trouble.\n\t\t\t\tBjarne Stroustrup");


//2
double number;
double persent;
double result;
Console.WriteLine("Please write the number: ");
number = Convert.ToDouble(Console.ReadLine());
Console.WriteLine("Please write the percent: ");
persent = Convert.ToDouble(Console.ReadLine());
result = (number * persent) / 100;
Console.WriteLine(persent+" persents of "+number+" = "+ result);


//3
int number1;
int number2;
int number3;
int number4;

Console.WriteLine("Please write first number: ");
number1 = Convert.ToInt32(Console.ReadLine());
Console.WriteLine("Please write second number: ");
number2 = Convert.ToInt32(Console.ReadLine());
Console.WriteLine("Please write third number: ");
number3 = Convert.ToInt32(Console.ReadLine());
Console.WriteLine("Please write fourth number: ");
number4 = Convert.ToInt32(Console.ReadLine());

int CreatedNumber = number1 * 1000 + number2 * 100 + number3 * 10 + number4;
Console.WriteLine("Your number: "+CreatedNumber);