#include <cstdlib>

#include <ctime>

#include <iostream>

class Random

{

private:

    int a = 0;

public:

    int RandomNumber();

};

int Random::RandomNumber()

{

    a = rand() % (9 - 0 + 1) + 0;


    return a;

}

class Input

{

private:

    int b = 0;

public:

    int InputNumber();

};

int Input::InputNumber()

{

    std::cin >> b;

    return b;

}

class Judgement

{

private:

    int c = 0;

    int d = 0;

    int preOutputNumber[4] = {};

    int preInputNumber[4] = {};

    int HitCount = 0;

    int BroCount = 0;

public:

    int JudgementNumber(const int InputNumber[], const int outputNumber[]);

};

int Judgement::JudgementNumber(const int InputNumber[], const int outputNumber[])

{

    for (int i = 0; i < 4; i++)

    {

        c = InputNumber[i];

        preInputNumber[i] = c;

        std::cout << c << std::endl;

    }

    for (int i = 0; i < 4; i++)

    {

        d = outputNumber[i];

        preOutputNumber[i] = d;

        std::cout << d << std::endl;

    }

    for (int i = 0; i < 4; i++)

    {

        if (preOutputNumber[i] == preInputNumber[i])

        {

            HitCount++;

        }

        if (preOutputNumber[0] == preInputNumber[i])

        {

            BroCount++;

        }

        if (preOutputNumber[1] == preInputNumber[i])

        {

            BroCount++;

        }

        if (preOutputNumber[2] == preInputNumber[i])

        {

            BroCount++;

        }

        if (preOutputNumber[3] == preInputNumber[i])

        {

            BroCount++;

        }

        if (preInputNumber[0] == preOutputNumber[i])

        {

            BroCount++;

        }

        if (preInputNumber[1] == preOutputNumber[i])

        {

            BroCount++;

        }

        if (preInputNumber[2] == preOutputNumber[i])

        {

            BroCount++;

        }

        if (preInputNumber[3] == preOutputNumber[i])

        {

            BroCount++;

        }

        std::cout << "ヒット" << HitCount << std::endl;

        return HitCount, BroCount;

    }

}

int main(int argc, char const* argv[]) {

    int RoopCount = 0;

    std::srand(time(NULL));

    int outputNumber[4] = {};

    Random random;

    for (int i = 0; i < 4; i++)

    {

        int a = random.RandomNumber();

        std::cout << a << std::endl;

        outputNumber[i] = a;

    }

    while (true)

    {

        Input input;

        Judgement judgement;

        int InputNumber[4] = {};

        int size = 4;

        int HitCount = 0;

        int BroCount = 0;


        for (int i = 1; i < 5; i++)

        {

            std::cout << i << "番目の数字を入力してください" << std::endl;

            int b = input.InputNumber();

            InputNumber[i - 1] = b;

        }

        HitCount, BroCount = judgement.JudgementNumber(InputNumber, outputNumber);

        if (HitCount == 4)

        {

            std::cout << "正解！" << std::endl;

            std::cout << "繰り返した数は：" << RoopCount << std::endl;

            return 0;

        }

        else

        {

            std::cout << "ヒット回数は：" << HitCount << std::endl;

            std::cout << "ブロー回数は：" << BroCount << std::endl;

            RoopCount++;

        }

    }

}
