#pragma once
#define TILESIZE 32

#define TILEX 30	//가로 타일 갯수
#define TILEY 30	//세로 타일 갯수


#define TILESIZEX TILESIZE * TILEX	//640 32 * 20
#define TILESIZEY TILESIZE * TILEY	//640 32 * 20

//타일셋 정의
#define SAMPLETILEX 16
#define SAMPLETILEY 16


//샘플타일 숫자
#define TILEMAX 18

//지형
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2,
	OBJ_NONE
};

//포지션
enum POS
{
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//타일 정보 담은 구조체
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

//타일셋 정보 담을 구조체
struct tagSampleTile
{
	RECT rcTile;
	int tilenumber;
	int terrainFrameX;
	int terrainFrameY;
};

//현재 타일 받아올 구조체
struct tagCurrentTile
{
	int tilenumber;
	int x;
	int y;
};

enum CTRL
{
	CTRL_SAVE,			//세이브		버튼
	CTRL_LOAD,			//로드		버튼
	CTRL_TERRAINDRAW,	//지형		버튼
	CTRL_OBJDRAW,		//오브젝트	버튼
	CTRL_ERASER,		//지우개		버튼
	CTRL_END
};