#include "../Mybasic/mybasic.h"

//      Huawei: 设计音乐播放器

//      设计一个音乐播放器MusicPlayer，完成音乐播放的基本功能:
//      创建一个 音乐播放器：输入参数为 歌曲数量
//      int AddMusic(int musicId): 加入一首歌曲: 输入参数为 musicId,
//          规则如下：如果已经存在该 musicId, 返回-1, 否则如下：
//              如果音乐播放器容量未满, 将 musicId 加入播放器中，返回0；
//              如果音乐播放器容量已满, 则删除播放次数最少的一首歌曲，
//              再将 musicId 加入播放器中, 返回删除的 musicId;
//              删除规则如下：
//                  如果最少播放次数为 0, 则删除加入时间最早的歌曲；
//                  如果最少播放次数不为 0, 则删除首次播放时间最早的歌曲；
//      bool PlayMusic(int musicId): 播放一首歌曲: 输入参数为 musicId,
//          如果播放器中不存在 musicId，返回 false, 否则返回 true
//      bool DeleteMusic(int musicId): 删除一首歌曲; 输入参数为 musicId,
//         如果播放器中不存在 musicId，返回 false, 否则删除该歌曲返回 true

typedef struct
{

} MusicPlayer;

MusicPlayer *MusicPlayerCreate(int num)
{
    MusicPlayer *obj = NULL;
    return obj;
}

int MusicPlayerFindMusic(MusicPlayer *obj, int musicId)
{
}

int MusicPlayerAddMusic(MusicPlayer **obj, int musicId)
{
}

bool MusicPlayerPlayMusic(MusicPlayer *obj, int musicId)
{
}

bool MusicPlayerDeleteMusic(MusicPlayer **obj, int musicId)
{
}

void MusicPlayerDeleteMusic(MusicPlayer **obj)
{
}

int main()
{
    int c1 = 3;
    MusicPlayer *musicPlayer = MusicPlayerCreate(c1);
    int a1 = MusicPlayerAddMusic(&musicPlayer, 20);
    printf("添加结果为：%d\n", a1); // 0
    int a2 = MusicPlayerAddMusic(&musicPlayer, 30);
    printf("添加结果为：%d\n", a2); // 0
    bool a3 = MusicPlayerPlayMusic(musicPlayer, 30);
    printf("播放结果为：\n");
    printBool(a3); // true
    int a4 = MusicPlayerAddMusic(&musicPlayer, 10);
    printf("添加结果为：%d\n", a4); // 0
    int a5 = MusicPlayerAddMusic(&musicPlayer, 50);
    printf("添加结果为：%d\n", a5); // 20
    bool a6 = MusicPlayerDeleteMusic(&musicPlayer, 30);
    printf("删除结果为：\n");
    PrintBool(a6); // true
    bool a7 = MusicPlayerPlayMusic(musicPlayer, 30);
    printf("播放结果为：\n");
    PrintBool(a7); // false
    int a8 = MusicPlayerAddMusic(&musicPlayer, 60);
    printf("添加结果为：%d\n", a8); // 0
    MusicPlayerFree(&musicPlayer);
}