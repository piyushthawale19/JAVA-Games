
import java.util.Scanner;
import java.util.Random;
  class main
{
    public static void main(String[] args)
    {
        Scanner reader= new Scanner(System.in);
        String play ="yes";


        //while loop to dteremine if we are going to play again
         while(play.equals("yes"))
         {
           Random rand = new Random();
           int randNum = rand.nextInt(100);
           int guess = -1;  
           int tries=0;


             // while loop to check if the game is over
            while( guess != randNum)
            {
                System.out.print("Guess a number between 1 to 100: ");
                guess = reader.nextInt();
                tries++;
                 


                if(guess==randNum)
                {
                    System.out.println("Awesome! you guessed are Correct");
                    System.out.println("It only took you " + tries + " guesses!");
                    System.out.println("would you like  to play again? Yes or No ");
                    play = reader.next().toLowerCase();
                }
                else if (guess > randNum) 
                {
                 System.out.println("Your guess is very high,try again."); 

                }
                else
                {
                    System.out.println("Your guess is very low,try again."); 
  
                }
            }

         }
         reader.close();
    }
}

