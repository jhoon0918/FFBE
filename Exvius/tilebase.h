#pragma once
#define TILESIZE 32

#define TILEX 30	//���� Ÿ�� ����
#define TILEY 30	//���� Ÿ�� ����


#define TILESIZEX TILESIZE * TILEX	//640 32 * 20
#define TILESIZEY TILESIZE * TILEY	//640 32 * 20

//Ÿ�ϼ� ����
#define SAMPLETILEX 16
#define SAMPLETILEY 16


//����Ÿ�� ����
#define TILEMAX 18

//����
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2,
	OBJ_NONE
};

//������
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//Ÿ�� ���� ���� ����ü
struct tagTile
{
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			tilenumber;
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX;
	int			objFrameY;
};

//Ÿ�ϼ� ���� ���� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int tilenumber;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ÿ�� �޾ƿ� ����ü
struct tagCurrentTile
{
	int tilenumber;
	int x;
	int y;
};

enum CTRL
{
	CTRL_SAVE,			//���̺�		��ư
	CTRL_LOAD,			//�ε�		��ư
	CTRL_TERRAINDRAW,	//����		��ư
	CTRL_OBJDRAW,		//������Ʈ	��ư
	CTRL_ERASER,		//���찳		��ư
	CTRL_END
};