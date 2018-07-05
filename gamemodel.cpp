#include <utility>
#include <stdlib.h>
#include <time.h>
#include "GameModel.h"

GameModel::GameModel(){}

void GameModel::startGame(GameType type)
{
    gameType = type;
    // 初始棋盘
    gameMapVec.clear();
    for (int i = 0; i < kBoardSizeNum; i++)
    {
        std::vector<int> lineBoard;
        for (int j = 0; j < kBoardSizeNum; j++)
            lineBoard.push_back(0);
        gameMapVec.push_back(lineBoard);
    }

    // AI模式，需要初始化评分数组
    scoreMapVec.clear();
    for (int i = 0; i < kBoardSizeNum; i++)
    {
        std::vector<int> lineScores;
        for (int j = 0; j < kBoardSizeNum; j++)
            lineScores.push_back(0);
        scoreMapVec.push_back(lineScores);
    }
    // 己方下为true,对方下位false
    playerFlag = true;


}

void GameModel::updateGameMap(int row, int col)
{
    if (playerFlag)
        gameMapVec[row][col] = 1;
    else
        gameMapVec[row][col] = -1;

    // 换手
    playerFlag = !playerFlag;
}

void GameModel::actionByPerson(int row, int col)
{
    updateGameMap(row, col);
}

void GameModel::actionByAI(int &clickRow, int &clickCol)
{
    // 计算评分
    calculateScore();

    // 从评分中找出最大分数的位置
    int maxScore = 0;
    std::vector<std::pair<int, int>> maxPoints;

    for (int row = 1; row < kBoardSizeNum; row++)
        for (int col = 1; col < kBoardSizeNum; col++)
        {
            // 前提是这个坐标是空的
            if (gameMapVec[row][col] == 0)
            {
                if (scoreMapVec[row][col] > maxScore)          // 找最大的数和坐标
                {
                    maxPoints.clear();
                    maxScore = scoreMapVec[row][col];
                    maxPoints.push_back(std::make_pair(row, col));
                }
                else if (scoreMapVec[row][col] == maxScore)     // 如果有多个最大的数，都存起来
                    maxPoints.push_back(std::make_pair(row, col));
            }
        }

    // 随机落子，如果有多个点的话
    srand((unsigned)time(0));
    int index = rand() % maxPoints.size();

    std::pair<int, int> pointPair = maxPoints.at(index);
    clickRow = pointPair.first; // 记录落子点
    clickCol = pointPair.second;
    updateGameMap(clickRow, clickCol);
}

// 最关键的计算评分函数
void GameModel::calculateScore()
{
    // 统计玩家或者电脑连成的子
    int personNum = 0; // 玩家连成子的个数
    int botNum = 0; // AI连成子的个数
    int emptyNum = 0; // 各方向空白位的个数

    // 清空评分数组
    scoreMapVec.clear();
    for (int i = 0; i < kBoardSizeNum; i++)
    {
        std::vector<int> lineScores;
        for (int j = 0; j < kBoardSizeNum; j++)
            lineScores.push_back(0);
        scoreMapVec.push_back(lineScores);
    }
    for (int row = 0; row < kBoardSizeNum; row++)
    {
        for (int col = 0; col < kBoardSizeNum; col++)
        {
            // 空白点就算
            if (row > 0 && col > 0 &&
                gameMapVec[row][col] == 0)
            {
                //对玩家（白子）评分
                for(int j=1,flag=0;j<4;j++)//判断该空位所处的行 是否有两子连成
                {
                    if(gameMapVec[row][j] == 1)  flag++;
                    if(flag==2)   scoreMapVec[row][col] += 100;
                    if(flag==1)   scoreMapVec[row][col] += 15;
                }
                for(int j=1,flag=0;j<4;j++)//判断该空位所处的列 是否有两子连成
                {
                    if(gameMapVec[j][col] == 1)  flag++;
                    if(flag==2)   scoreMapVec[row][col] += 100;
                    if(flag==1)   scoreMapVec[row][col] += 15;
                }
                if(row == col && row == 2)
                {
                    for(int i=1,flag = 0;i<4;i++)//判断该空位所处的右斜方 是否有两子连成
                    {
                        if(gameMapVec[i][i] == 1)  flag++;
                        if(flag==2)   scoreMapVec[row][col] += 100;
                        if(flag==1)   scoreMapVec[row][col] += 15;
                    }
                }
                if(row-col == 2 || col-row == 2)
                {
                    for(int i=3,j=1,flag = 0;j<4;j++,i--)//判断该空位所处的左斜方 是否有两子连成
                    {
                        if(gameMapVec[i][j] == 1)  flag++;
                        if(flag==2)   scoreMapVec[row][col] += 100;
                        if(flag==1)   scoreMapVec[row][col] += 15;
                    }
                }
                //对AI黑子评分
                for(int j=1,flag=0;j<4;j++)//判断该空位所处的行 是否有两子连成
                {
                    if(gameMapVec[row][j] == -1)  flag++;
                    if(flag==2)   scoreMapVec[row][col] += 120;
                    if(flag==1)   scoreMapVec[row][col] += 20;
                }
                for(int j=1,flag=0;j<4;j++)//判断该空位所处的列 是否有两子连成
                {
                    if(gameMapVec[j][col] == 1)  flag++;
                    if(flag==2)   scoreMapVec[row][col] += 120;
                    if(flag==1)   scoreMapVec[row][col] += 20;
                }
                if(row == col)
                {
                    for(int i=1,flag = 0;i<4;i++)//判断该空位所处的右斜方 是否有两子连成
                    {
                        if(gameMapVec[i][i] == 1)  flag++;
                        if(flag==2)   scoreMapVec[row][col] += 120;
                        if(flag==1)   scoreMapVec[row][col] += 20;
                    }
                }
                if(row-col == 2 || col-row == 2)
                {
                    for(int i=3,j=1,flag = 0;j<4;j++,i--)//判断该空位所处的左斜方 是否有两子连成
                    {
                        if(gameMapVec[i][j] == 1)  flag++;
                        if(flag==2)   scoreMapVec[row][col] += 120;
                        if(flag==1)   scoreMapVec[row][col] += 20;
                    }
                }
             }
         }
    }
}

bool GameModel::isWin(int row, int col)
{
    // 横竖斜四种大情况,符合就算赢
    // 水平方向
    if (
        gameMapVec[row][col] == gameMapVec[row][1] &&
        gameMapVec[row][col] == gameMapVec[row][2] &&
        gameMapVec[row][col] == gameMapVec[row][3]   )
        return true;

    // 竖直方向
    if (
        gameMapVec[row][col] == gameMapVec[1][col] &&
        gameMapVec[row][col] == gameMapVec[2][col] &&
        gameMapVec[row][col] == gameMapVec[3][col])
        return true;

    // 左斜方向
    if (
        gameMapVec[1][1] == gameMapVec[2][2] &&
        gameMapVec[1][1] == gameMapVec[3][3] )
    {
        if(gameMapVec[row][col] == gameMapVec[2][2]) return true;
    }

    // 右斜方向
    if (
        gameMapVec[3][1] == gameMapVec[2][2] &&
        gameMapVec[1][3] == gameMapVec[2][2] )
    {
        if(gameMapVec[row][col] == gameMapVec[2][2]) return true;
    }
    if(gameMapVec[row][col] == -1)
    {
        int flag1 = 0,flag2;
        for(int i = 1; i < kBoardSizeNum; i++){
            for(int  j = 1;j < kBoardSizeNum; j++){
                if(gameMapVec[i][j] !=0) flag1++;
                if(gameMapVec[i][j] == 0) flag2=isWin(i,j);
            }
        }
        if(flag1 == 8 && flag2 == 0) return true;
    }
    return false;
}

bool GameModel::isDeadGame()
{
    // 所有空格全部填满
    /*for(int i = 1; i < kBoardSizeNum; i++){
        for(int  j = 1;j < kBoardSizeNum; j++){
            if(gameMapVec[i][j] == 0) return false;
        }
    }
    return true;*/
    for (int i = 1; i < kBoardSizeNum; i++)
    {
        for (int j = 1; j < kBoardSizeNum; j++)
        {
            if (!(gameMapVec[i][j] == 1 || gameMapVec[i][j] == -1))
                return false;
        }
    }
    return true;
}

