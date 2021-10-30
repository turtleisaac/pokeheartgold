#include "global.h"
#include "sound.h"
#include "sound_chatot.h"
#include "options.h"
#include "main.h"

#define ASM_EXTERN extern

struct SND_WORK {
    /* 0x00000 */ NNSSndArc arc;
    /* 0x00094 */ NNSSndHeapHandle heap;
    /* 0x00098 */ u8 heap_buf[SND_HEAP_SIZE];
    /* 0xBEB78 */ NNSSndHandle unk_BEB78[SND_PLAYER_COUNT];
    /* 0xBEB9C */ u32 unk_BEB9C;
    /* 0xBEBA0 */ u32 unk_BEBA0;
    /* 0xBEBA4 */ u32 unk_BEBA4;
    /* 0xBEBA8 */ u8 unk_BEBA8[0x18];
    /* 0xBEBC0 */ u8 unk_BEBC0[16];
    /* 0xBEBD0 */ u8 unk_BEBD0[28];
    /* 0xBEBEC */ u16 unk_BEBEC;
    /* 0xBEBEE */ u8 unk_BEBEE;
    /* 0xBEBEF */ u8 unk_BEBEF;
    /* 0xBEBF0 */ s32 unk_BEBF0;
    /* 0xBEBF4 */ u8 unk_BEBF4[4];
    /* 0xBEBF8 */ u32 unk_BEBF8;
    /* 0xBEBFC */ u8 unk_BEBFC[2];
    /* 0xBEBFE */ u16 unk_BEBFE;
    /* 0xBEC00 */ u8 unk_BEC00;
    /* 0xBEBC1 */ u8 unk_BEC01;
    /* 0xBEC02 */ u16 unk_BEC02;
    /* 0xBEC04 */ u8 unk_BEC04;
    /* 0xBEC05 */ u8 unk_BEC05;
    /* 0xBEC06 */ u8 unk_BEC06;
    /* 0xBEC07 */ u8 unk_BEC07;
    /* 0xBEC08 */ u8 unk_BEC08;
    /* 0xBEC09 */ u8 unk_BEC09;
    /* 0xBEC0A */ u8 unk_BEC0A;
    /* 0xBEC0B */ u8 unk_BEC0B;
    /* 0xBEC0C */ u32 unk_BEC0C;
    /* 0xBEC10 */ u32 unk_BEC10;
    /* 0xBEC14 */ u32 unk_BEC14;
    /* 0xBEC18 */ u32 unk_BEC18;
    /* 0xBEC1C */ u32 unk_BEC1C;
    /* 0xBEC20 */ u32 unk_BEC20;
    /* 0xBEC24 */ u32 unk_BEC24;
    /* 0xBEC28 */ u8 unk_BEC28;
    /* 0xBEC29 */ u8 unk_BEC29;
    /* 0xBEC2A */ u16 unk_BEC2A;
    /* 0xBEC2C */ u32 unk_BEC2C;
    /* 0xBEC30 */ u8 unk_BEC30[8];
    /* 0xBEC38 */ u32 unk_BEC38;
    /* 0xBEC3C */ SOUND_CHATOT *chatot;
    /* 0xBEC40 */ u32 unk_BEC40;
    /* 0xBEC44 */ u32 unk_BEC44;
    /* 0xBEC48 */ u32 unk_BEC48;
    /* 0xBEC4C */ u32 unk_BEC4C;
    /* 0xBEC50 */ u32 unk_BEC50[2];
    /* 0xBEC58 */ u32 unk_BEC58[2];
    /* 0xBEC60 */ u32 unk_BEC60[2];
    /* 0xBEC68 */ u32 unk_BEC68[2];
    /* 0xBEC70 */ u16 unk_BEC70[2];
    /* 0xBEC74 */ u8 unk_BEC74[2];
    /* 0xBEC76 */ u8 unk_BEC76;
    /* 0xBEC77 */ u8 unk_BEC77;
    /* 0xBEC78 */ u8 unk_BEC78;
    /* 0xBEC79 */ u8 unk_BEC79;
    /* 0xBEC7A */ u16 unk_BEC7A;
    /* 0xBEC7C */ u32 unk_BEC7C;
    /* 0xBEC80 */ u32 unk_BEC80_00:1;
    /* 0xBEC80 */ u32 unk_BEC80_01:31;
    /* 0xBEC84 */ u8 padding_BEC84[4];
}; // size: 0xBEC88

SND_WORK sSoundWork;
u32 _0211194C;
u32 _02111950;
u32 sSndHeapFreeSize;

void GF_SoundDataInit(SND_WORK *work);
void GF_InitMic(SND_WORK *work);
void sub_0200498C(NNSSndHeapHandle *heap_p);
void GF_SndHandleInitAll(SND_WORK *work);
void sub_02004898(struct SND_WORK *work);
void sub_02004300(void);
BOOL sub_020043CC(void);
BOOL sub_02004924(void);

void InitSoundData(SOUND_CHATOT *chatot, OPTIONS *options) {
    SND_WORK *work = GetSoundDataPointer();
    NNS_SndInit();
    GF_SoundDataInit(work);
    GF_InitMic(work);
    work->heap = NNS_SndHeapCreate(work->heap_buf, sizeof(work->heap_buf));
    NNS_SndArcInit(&work->arc, "data/sound/gs_sound_data.sdat", work->heap, FALSE);
    NNS_SndArcPlayerSetup(work->heap);
    sub_0200498C(&work->heap);
    GF_SndHandleInitAll(work);
    sSndHeapFreeSize = NNS_SndHeapGetSize(work->heap);
    GF_SndHeapGetFreeSize();
    sub_02004898(work);
    _02111950 = 0;
    work->chatot = chatot;
    GF_SndSetMonoFlag(options->soundMethod);
}

void DoSoundUpdateFrame(void) {
    SND_WORK *work;
    int i;
    SNDChannelInfo sp24;
    SNDTrackInfo sp8;
    void *stripped_0;
    void *stripped_1;

    work = GetSoundDataPointer();
    stripped_0 = GF_SdatGetAttrPtr(18);
    stripped_1 = GF_SdatGetAttrPtr(32);
    if (!sub_020043CC()) {
        if (work->unk_BEBF0 > 0) {
            work->unk_BEBF0--;
        }
        sub_02004300();
    }
    NNS_SndUpdateDriverInfo();
    if (gMain.newKeys & PAD_BUTTON_DEBUG) {
        for (i = 0; i < 16; i++) {
            NNS_SndPlayerReadDriverTrackInfo(&work->unk_BEB78[7], i, &sp8);
            NNS_SndReadDriverChannelInfo(i, &sp24);
        }
    }
    ChatotSoundMain();
    for (i = 0; i < 2; i++) {
        if (work->unk_BEC74[i] != 0) {
            work->unk_BEC74[i]--;
            if (work->unk_BEC74[i] == 0) {
                sub_020063A4(work->unk_BEC50[i], work->unk_BEC70[i], work->unk_BEC58[i], work->unk_BEC60[i], work->unk_BEC68[i], 0);
            }
        }
    }
    if (work->unk_BEC80_00 && !sub_02004924()) {
        work->unk_BEC80_01++;
    }
    NNS_SndMain();
}

void sub_02004300(void) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    switch (_0211194C) {
    case 1:
        sub_020043B0(2);
        break;
    case 3:
        if (!sub_02005F88()) {
            sub_020043B0(2);
        }
        break;
    case 4:
        if (!sub_02005F88()) {
            sub_020043B0(2);
        }
        break;
    case 5:
        if (!sub_02005F88() && !sub_020059B0()) {
            sub_020048F0();
            if (work->unk_BEBFE != 0) {
                PlayBGM(work->unk_BEBFE);
            }
        }
        break;
    case 6:
        if (!sub_02005F88() && !sub_020059B0()) {
            sub_020048F0();
            if (work->unk_BEBFE != 0) {
                PlayBGM(work->unk_BEBFE);
            }
            sub_02005F10(0x7F, work->unk_BEBF8, 0);
        }
        break;
    }
}

void sub_020043B0(u32 state) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    work->unk_BEBEC = 0;
    _0211194C = state;
}

BOOL sub_020043CC(void) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    if (GF_SndPlayerCountPlayingSeqByPlayerNo(2) != 0) {
        return TRUE;
    }
    if (work->unk_BEC02 != 0) {
        return TRUE;
    }
    return FALSE;
}

SND_WORK *GetSoundDataPointer(void) {
    return &sSoundWork;
}

void *GF_SdatGetAttrPtr(u32 attr) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    switch (attr) {
    case 5:
        return &work->unk_BEBEE;
    case 6:
        return &work->unk_BEBEF;
    case 0:
        return &work->unk_BEB9C;
    case 1:
        return &work->unk_BEBA0;
    case 2:
        return &work->unk_BEBA4;
    case 3:
        return &work->unk_BEBC0;
    case 4:
        return &work->unk_BEBD0;
    case 7:
        return &work->unk_BEBF0;
    case 8:
        return &work->unk_BEBF4;
    case 9:
        return &work->unk_BEBF8;
    case 10:
        return &work->unk_BEBFC;
    case 11:
        return &work->unk_BEBFE;
    case 12:
        return &work->unk_BEC00;
    case 13:
        return &work->unk_BEC01;
    case 14:
        return &work->unk_BEC02;
    case 15:
        return &work->unk_BEC04;
    case 16:
        return &work->unk_BEC05;
    case 17:
        return &work->unk_BEC06;
    case 18:
        return &work->unk_BEC07;
    case 19:
        return &work->unk_BEC08;
    case 20:
        return &work->unk_BEC09;
    case 21:
        return &work->unk_BEC0A;
    case 22:
        return &work->unk_BEC0B;
    case 23:
        return &work->unk_BEC0C;
    case 24:
        return &work->unk_BEC10;
    case 25:
        return &work->unk_BEC14;
    case 26:
        return &work->unk_BEC18;
    case 27:
        return &work->unk_BEC1C;
    case 28:
        return &work->unk_BEC20;
    case 29:
        return &work->unk_BEC24;
    case 30:
        return &work->unk_BEC28;
    case 31:
        return &work->unk_BEC29;
    case 32:
        return &work->unk_BEC2A;
    case 33:
        return &work->unk_BEC2C;
    case 34:
        return &work->unk_BEC30;
    case 35:
        return &work->unk_BEC38;
    case 36:
        return &work->chatot;
    case 37:
        return &work->unk_BEC40;
    case 38:
        return &work->unk_BEC44;
    case 39:
        return &work->unk_BEC48;
    case 40:
        return &work->unk_BEC4C;
    case 41:
        return &work->unk_BEC50[0];
    case 42:
        return &work->unk_BEC58[0];
    case 43:
        return &work->unk_BEC60[0];
    case 44:
        return &work->unk_BEC68[0];
    case 45:
        return &work->unk_BEC70[0];
    case 46:
        return &work->unk_BEC74[0];
    case 47:
        return &work->unk_BEC50[1];
    case 48:
        return &work->unk_BEC58[1];
    case 49:
        return &work->unk_BEC60[1];
    case 50:
        return &work->unk_BEC68[1];
    case 51:
        return &work->unk_BEC70[1];
    case 52:
        return &work->unk_BEC74[1];
    case 53:
        return &work->unk_BEC76;
    case 54:
        return &work->unk_BEC77;
    case 55:
        return &work->unk_BEC78;
    case 56:
        return &work->unk_BEC79;
    case 57:
        return &work->unk_BEC7A;
    case 58:
        return &work->unk_BEC7C;
    }
    GF_ASSERT(0);
    return NULL;
}

int GF_Snd_SaveState(int *level_p) {
    SND_WORK *work;
    int level;

    work = GetSoundDataPointer();
    level = NNS_SndHeapSaveState(work->heap);
    GF_ASSERT(level != -1);
    if (level_p != NULL) {
        *level_p = level;
    }
    GF_SndHeapGetFreeSize();
    return level;
}

void GF_Snd_LoadState(int level) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    NNS_SndHeapLoadState(work->heap, level);
    GF_SndHeapGetFreeSize();
}

void GF_SndHeapGetFreeSize(void) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    sSndHeapFreeSize = NNS_SndHeapGetFreeSize(work->heap);
}

BOOL GF_Snd_LoadGroup(int groupNo) {
    BOOL ret;
    SND_WORK *work;

    work = GetSoundDataPointer();
    ret = NNS_SndArcLoadGroup(groupNo, work->heap);
    GF_SndHeapGetFreeSize();
    return ret;
}

BOOL GF_Snd_LoadSeq(int seqNo) {
    BOOL ret;
    SND_WORK *work;

    work = GetSoundDataPointer();
    ret = NNS_SndArcLoadSeq(seqNo, work->heap);
    GF_SndHeapGetFreeSize();
    return ret;
}

BOOL GF_Snd_LoadSeqEx(int seqNo, u32 loadFlag) {
    BOOL ret;
    SND_WORK *work;

    work = GetSoundDataPointer();
    ret = NNS_SndArcLoadSeqEx(seqNo, loadFlag, work->heap);
    GF_SndHeapGetFreeSize();
    return ret;
}

BOOL GF_Snd_LoadWaveArc(int waveArcNo) {
    BOOL ret;
    SND_WORK *work;

    work = GetSoundDataPointer();
    ret = NNS_SndArcLoadWaveArc(waveArcNo, work->heap);
    GF_SndHeapGetFreeSize();
    return ret;
}

BOOL GF_Snd_LoadBank(int bankNo) {
    BOOL ret;
    SND_WORK *work;

    work = GetSoundDataPointer();
    ret = NNS_SndArcLoadBank(bankNo, work->heap);
    GF_SndHeapGetFreeSize();
    return ret;
}

NNSSndHandle *GetSoundPlayer(int playerNo) {
    SND_WORK *work;

    work = GetSoundDataPointer();
    if (playerNo >= SND_PLAYER_COUNT) {
        GF_ASSERT(0);
        playerNo = 0;
    }
    return &work->unk_BEB78[playerNo];
}
