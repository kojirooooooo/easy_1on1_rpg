#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 問12. 簡易RPG 主人公と敵で1対1のターン制バトル。どちらかのHPが0以下になったら終了。
 * **/

typedef char String[1024];

//各キャラクターのステータス
typedef struct
{
    String name;
    int hp;
    String skill;
} Character;

//主人公の攻撃
int attack(int skillFlag, String enemyName);

//敵の攻撃
int enemyAttack(int skillFlag, String enemyName);

int main(void)
{

    printf("ようこそ、ここは一攫千金を狙う剣士が集う闘技場です。\n");
    printf("あなたは、一人の剣士として強敵との戦いに挑みます。\n");

    printf("それでは、頑張ってください。\n");

    Character player1 = {"主人公", 2000, "ジャンプ斬り"};
    Character firstEnemy = {"チンピラ1", 2000, "ケンカキック"};

    printf("%sがあらわれた!\n", firstEnemy.name);

    int skillFlag = 0;
    int hpDown = 0;

    while (player1.hp > 0 && firstEnemy.hp > 0)
    {
        printf("どうする？(1-3)  %s: HP%d %s: HP%d\n", player1.name, player1.hp, firstEnemy.name, firstEnemy.hp);
        printf("1.攻撃 2.スキル:%s 3.防御\n", player1.skill);

        scanf("%d", &skillFlag);
        hpDown = attack(skillFlag, firstEnemy.name);

        firstEnemy.hp -= hpDown;

        hpDown = enemyAttack(skillFlag, firstEnemy.name);

        player1.hp -= hpDown;
    }

    if (player1.hp <= 0)
    {
        printf("%sは倒れた!\n", player1.name);
        printf("残念ながらあなたの負けです。出直してきましょう。\n");
    }
    else if (firstEnemy.hp <= 0)
    {
        printf("%sは倒れた!\n", firstEnemy.name);
        printf("おめでとうございます、あなたの勝利です。\n");
    }

    return 0;
}

int attack(int skillFlag, String enemyName)
{
    srand((unsigned)time(NULL));
    int randNum = rand() % 10;

    int attackValue = 0;

    switch (skillFlag)
    {
    case 1:
        printf("主人公の攻撃!!\n");
        attackValue = 100;
        printf("%sに%dのダメージ!!\n", enemyName, attackValue);
        break;

    case 2:
        printf("主人公のジャンプ斬り!!\n");
        if (randNum % 2 == 0)
        {
            attackValue = (randNum + 1) * 150;
        }
        else
        {
            attackValue = 70;
        }
        printf("%sに%dのダメージ!!\n", enemyName, attackValue);
        break;

    case 3:
        printf("主人公は守りの体制に入った!!\n");
        break;

    default:
        break;
    }

    return attackValue;
}

int enemyAttack(int skillFlag, String enemyName)
{
    srand((unsigned)time(NULL));
    int randNum = rand() % 10;

    int attackValue = 0;
    double protectValue = 1;

    if (skillFlag = 3)
    {
        protectValue = 0.8;
    }

    if (randNum % 2 == 0)
    {
        printf("%sの攻撃!!\n", enemyName);
        attackValue = 100;
    }
    else
    {
        printf("%sのケンカキック!!\n", enemyName);
        attackValue = (randNum + 1) * 100;
    }

    attackValue = attackValue * protectValue;
    printf("主人公に%dのダメージ!!\n", attackValue);
    return (int)attackValue;
}