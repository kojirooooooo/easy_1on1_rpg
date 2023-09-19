#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * ��12. �Ȉ�RPG ��l���ƓG��1��1�̃^�[�����o�g���B�ǂ��炩��HP��0�ȉ��ɂȂ�����I���B
 * **/

typedef char String[1024];

//�e�L�����N�^�[�̃X�e�[�^�X
typedef struct
{
    String name;
    int hp;
    String skill;
} Character;

//��l���̍U��
int attack(int skillFlag, String enemyName);

//�G�̍U��
int enemyAttack(int skillFlag, String enemyName);

int main(void)
{

    printf("�悤�����A�����͈ꝺ�����_�����m���W�����Z��ł��B\n");
    printf("���Ȃ��́A��l�̌��m�Ƃ��ċ��G�Ƃ̐킢�ɒ��݂܂��B\n");

    printf("����ł́A�撣���Ă��������B\n");

    Character player1 = {"��l��", 2000, "�W�����v�a��"};
    Character firstEnemy = {"�`���s��1", 2000, "�P���J�L�b�N"};

    printf("%s�������ꂽ!\n", firstEnemy.name);

    int skillFlag = 0;
    int hpDown = 0;

    while (player1.hp > 0 && firstEnemy.hp > 0)
    {
        printf("�ǂ�����H(1-3)  %s: HP%d %s: HP%d\n", player1.name, player1.hp, firstEnemy.name, firstEnemy.hp);
        printf("1.�U�� 2.�X�L��:%s 3.�h��\n", player1.skill);

        scanf("%d", &skillFlag);
        hpDown = attack(skillFlag, firstEnemy.name);

        firstEnemy.hp -= hpDown;

        hpDown = enemyAttack(skillFlag, firstEnemy.name);

        player1.hp -= hpDown;
    }

    if (player1.hp <= 0)
    {
        printf("%s�͓|�ꂽ!\n", player1.name);
        printf("�c�O�Ȃ��炠�Ȃ��̕����ł��B�o�����Ă��܂��傤�B\n");
    }
    else if (firstEnemy.hp <= 0)
    {
        printf("%s�͓|�ꂽ!\n", firstEnemy.name);
        printf("���߂łƂ��������܂��A���Ȃ��̏����ł��B\n");
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
        printf("��l���̍U��!!\n");
        attackValue = 100;
        printf("%s��%d�̃_���[�W!!\n", enemyName, attackValue);
        break;

    case 2:
        printf("��l���̃W�����v�a��!!\n");
        if (randNum % 2 == 0)
        {
            attackValue = (randNum + 1) * 150;
        }
        else
        {
            attackValue = 70;
        }
        printf("%s��%d�̃_���[�W!!\n", enemyName, attackValue);
        break;

    case 3:
        printf("��l���͎��̑̐��ɓ�����!!\n");
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
        printf("%s�̍U��!!\n", enemyName);
        attackValue = 100;
    }
    else
    {
        printf("%s�̃P���J�L�b�N!!\n", enemyName);
        attackValue = (randNum + 1) * 100;
    }

    attackValue = attackValue * protectValue;
    printf("��l����%d�̃_���[�W!!\n", attackValue);
    return (int)attackValue;
}