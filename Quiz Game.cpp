#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

struct stQuestion
{
    string Question;
    string Choices;
    short RightAnswer;
    short TakenAnswer;
};

struct stQuiz
{
    stQuestion QuestionsList[30];
    short NumberOfQuestions = 0;
    short RightAnswers = 0;
    bool IsPass = false;
};
void GenerateQuestionsList(stQuiz& Quiz)
{
    Quiz.QuestionsList[0].Question = "What river was the lifeblood of Ancient Egypt, providing fertile soil and facilitating trade?";
    Quiz.QuestionsList[0].Choices = "1) Tigris River ,2) Euphrates River ,3) Nile River ,4) Indus River";
    Quiz.QuestionsList[0].RightAnswer = 3;

    Quiz.QuestionsList[1].Question = "Who was the ruler of Ancient Egypt known as the “pharaoh”?";
    Quiz.QuestionsList[1].Choices = "1) Emperor, 2) King, 3) Caesar, 4) Pharaoh";
    Quiz.QuestionsList[1].RightAnswer = 4;

    Quiz.QuestionsList[2].Question = "What is the name of the Egyptian god of the afterlife and the underworld?";
    Quiz.QuestionsList[2].Choices = "1) Ra, 2) Anubis, 3) Osiris, 4) Horus";
    Quiz.QuestionsList[2].RightAnswer = 3;

    Quiz.QuestionsList[3].Question = "What has keys but can’t open locks?";
    Quiz.QuestionsList[3].Choices = "1) Piano , 2) Guitar , 3) Car , 4) Abu Trika";
    Quiz.QuestionsList[3].RightAnswer = 1;

    Quiz.QuestionsList[4].Question = "Which 1994 film features a character named Simba?";
    Quiz.QuestionsList[4].Choices = "1) Fish World , 2) Sandrilla , 3) The Lion King , 4) Raponzil";
    Quiz.QuestionsList[4].RightAnswer = 3;

    Quiz.QuestionsList[5].Question = "Which of the following is a measure used for distance?";
    Quiz.QuestionsList[5].Choices = "1) Hectare , 2) Meter , 3) Liter , 4) Kilogram";
    Quiz.QuestionsList[5].RightAnswer = 2;

    Quiz.QuestionsList[6].Question = "If a cup of lemonade costs $0.25, how many must you sell to earn $3.50?";
    Quiz.QuestionsList[6].Choices = "1) 12 , 2) 16 , 3) 10 , 4) 14";
    Quiz.QuestionsList[6].RightAnswer = 4;

    Quiz.QuestionsList[7].Question = "Allah is the Muslim title used for what?";
    Quiz.QuestionsList[7].Choices = "1) Mohammed Prophet , 2) God , 3) Gabriel , 4) Abu Bakr el Seddiek";
    Quiz.QuestionsList[7].RightAnswer = 2;

    Quiz.QuestionsList[8].Question = "Who was the last Prophet in Islam?";
    Quiz.QuestionsList[8].Choices = "1) Mohammed Prophet , 2) Essa , 3) Moussa , 4) Abu Bakr el Seddiek";
    Quiz.QuestionsList[8].RightAnswer = 1;

    Quiz.QuestionsList[9].Question = "Who was the first prophet in Islam?";
    Quiz.QuestionsList[9].Choices = "1) Adam , 2) Essa , 3) Moussa , 4) Abu Bakr el Seddiek";
    Quiz.QuestionsList[9].RightAnswer = 1;

    Quiz.QuestionsList[10].Question = "Prayer is the __________ pillar of Islam";
    Quiz.QuestionsList[10].Choices = "1) 2nd , 2) 3rd , 3) 4th , 4) 5th";
    Quiz.QuestionsList[10].RightAnswer = 1;

    Quiz.QuestionsList[11].Question = "How many times does a Muslim pray in a day?";
    Quiz.QuestionsList[11].Choices = "1) 4 , 2) 5 , 3) 6 , 4) 7";
    Quiz.QuestionsList[11].RightAnswer = 2;

    Quiz.QuestionsList[12].Question = "What is the Holy Book of Islam?";
    Quiz.QuestionsList[12].Choices = "1) Quraan , 2) The Holy Bible , 3) Hebrew Bible , 4) Old Testament";
    Quiz.QuestionsList[12].RightAnswer = 1;

    Quiz.QuestionsList[13].Question = "What does the word (Dajjal) mean in English?";
    Quiz.QuestionsList[13].Choices = "1) The Deceiver , 2) The God , 3) Lucifer , 4) Adam";
    Quiz.QuestionsList[13].RightAnswer = 1;

    Quiz.QuestionsList[14].Question = "Who was the last of the four righteous caliphs?";
    Quiz.QuestionsList[14].Choices = "1) Ebrahiem , 2) Essa , 3) Ali , 4) Adam";
    Quiz.QuestionsList[14].RightAnswer = 3;

    Quiz.QuestionsList[15].Question = "The Declaration of Faith is one of the pillars of Islam. Which one?";
    Quiz.QuestionsList[15].Choices = "1) 1st , 2) 2nd , 3) 3rd , 4) 4th";
    Quiz.QuestionsList[15].RightAnswer = 1;
}

void ShowHeader()
{
    cout << "-------- Welcome To Quiz Game --------\n";
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void ShowRulesScreen()
{
    ShowHeader();
    cout << "------ Please Follow The Instructions ------\n";
    cout << "Step 1:Quiz contains total 10 questions\n";
    cout << "Step 2:You will be given 1 mark for each right answer\n";
    cout << "Step 3:There will be no negative marks\n";
    cout << "Step 4:Please Press (s) to start the game\n";
    cout << "Step 5:Please Select option a,b,c,d\n";
    cout << "Step 6:If you scores 5 or more marks you will pass\n";
    //press any key
    system("pause>0");
}

short PrintQuestionAndGetAnswer(int Number, stQuestion QuestionsList)
{
    short TakenAnswer;
    cout << "\nQuestion [" << Number << "]:\n";
    cout << QuestionsList.Question << endl;
    cout << QuestionsList.Choices << endl;
    cin >> TakenAnswer;
    return TakenAnswer;
}

void DoQuiz(stQuiz& Quiz)
{
    for (int i = 1; i <= 15; i++)
    {     
        Quiz.QuestionsList[i].TakenAnswer = PrintQuestionAndGetAnswer(i + 1, Quiz.QuestionsList[i]);
        if (Quiz.QuestionsList[i].TakenAnswer == Quiz.QuestionsList[i].RightAnswer)
        {
            Quiz.RightAnswers++;
            system("color 2F");
        }
        else
        {
            system("color 4F");
            cout << "\a";
        }
    }
}

bool IsPassed(stQuiz Quiz)
{
    return (Quiz.RightAnswers >= 5);
}

void SetScreenColor(stQuiz Quiz)
{
    if (Quiz.IsPass)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

void GetFinalResults(stQuiz& Quiz)
{
    cout << "\n------------ Quiz Results ------------\n";
    Quiz.IsPass = IsPassed(Quiz);
    if (Quiz.IsPass)
    {
        cout << "------------ You Passed ------------\n";
    }
    else
    {
        cout << "------------ You Failed ------------\n";
    }
    cout << "Number of right answers: " << Quiz.RightAnswers << endl;
    cout << "Number of wrong answers: " << 10 - Quiz.RightAnswers << endl;
    SetScreenColor(Quiz);
}

void StartGame()
{
    stQuiz Quiz;
    char WantAgain = 'y';
    do
    {
        ResetScreen();
        GenerateQuestionsList(Quiz);
        ShowRulesScreen();
        DoQuiz(Quiz);
        GetFinalResults(Quiz);
        cout << endl;
        cout << "Do you want to play again? y or n\n";
        cin >> WantAgain;
        Quiz.RightAnswers = 0; // Reset the score for the next round
    } while (WantAgain == 'y' || WantAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}