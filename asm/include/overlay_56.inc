#include <nitro/fs/overlay.h>
#pragma once
.public TextFlags_SetCanABSpeedUpPrint
.public FontID_String_GetWidth
.public PaletteData_Init
.public PaletteData_Free
.public PaletteData_AllocBuffers
.public PaletteData_FreeBuffers
.public PaletteData_LoadPalette
.public PaletteData_LoadNarc
.public sub_02003370
.public sub_0200398C
.public sub_02003B44
.public sub_02003B50
.public sub_02003E5C
.public PlaySE
.public OverlayManager_CreateAndGetData
.public OverlayManager_GetData
.public OverlayManager_FreeData
.public OverlayManager_GetArgs
.public NARC_New
.public NARC_Delete
.public NARC_ReadWholeMember
.public NARC_GetMemberSize
.public sub_0200B2E0
.public NewMsgDataFromNarc
.public DestroyMsgData
.public ReadMsgDataIntoString
.public SpriteRenderer_Create
.public SpriteRenderer_CreateGfxHandler
.public sub_0200CF70
.public sub_0200CFF4
.public sub_0200D020
.public thunk_OamManager_ApplyAndResetBuffers
.public SpriteRenderer_Delete
.public SpriteRenderer_Init2DGfxResManagersFromCountsArray
.public SpriteRenderer_LoadPlttResObjFromNarcId
.public SpriteRenderer_LoadCellResObjFromNarcId
.public SpriteRenderer_LoadAnimResObjFromNarcId
.public SpriteRenderer_LoadResourcesAndCreateSprite
.public SpriteRenderer_UnloadResourcesAndRemoveGfxHandler
.public sub_0200D9DC
.public UnkImageStruct_SetSpriteVisibleFlag
.public sub_0200E128
.public CreateSysTask
.public DestroySysTask
.public LoadUserFrameGfx1
.public LoadUserFrameGfx2
.public DrawFrameAndWindow2
.public ClearFrameAndWindow2
.public sub_0200FBDC
.public SetMasterBrightnessNeutral
.public sub_0200FBF4
.public MailMsg_GetExpandedString
.public MailMsg_IsInit
.public sub_0201660C
.public sub_02016624
.public sub_02016704
.public sub_020168F4
.public sub_020169C0
.public sub_020169CC
.public sub_020183F0
.public sub_02018410
.public Main_SetVBlankIntrCB
.public HBlankInterruptDisable
.public CreateHeap
.public DestroyHeap
.public AllocFromHeap
.public AllocFromHeapAtEnd
.public FreeToHeap
.public BgConfig_Alloc
.public SetBothScreensModesAndDisable
.public InitBgFromTemplate
.public FreeBgTilemapBuffer
.public BG_LoadCharTilesData
.public BG_ClearCharDataRange
.public BG_LoadPlttData
.public CopyToBgTilemapRect
.public FillBgTilemapRect
.public BgClearTilemapBufferAndCommit
.public AddWindowParameterized
.public RemoveWindow
.public CopyWindowToVram
.public ClearWindowTilemapAndCopyToVram
.public FillWindowPixelBuffer
.public DoScheduledBgGpuUpdates
.public ScheduleBgTilemapBufferTransfer
.public DoesPixelAtScreenXYMatchPtrVal
.public TextPrinterCheckActive
.public AddTextPrinterParameterizedWithColor
.public GF_CreateVramTransferManager
.public GF_DestroyVramTransferManager
.public GfGfx_SetBanks
.public GfGfx_DisableEngineAPlanes
.public GfGfx_EngineATogglePlanes
.public GfGfx_DisableEngineBPlanes
.public sub_02025224
.public System_GetTouchHeld
.public System_GetTouchNew
.public String_New
.public String_Delete
.public String_SetEmpty
.public Options_GetTextFrameDelay
.public Options_GetFrame
.public sub_0203A964
.public sub_02074490
.public sub_02074494
.public sub_020744A0
.public NNS_GfdDoVramTransfer
.public NNS_G2dGetUnpackedCharacterData
.public NNS_G2dGetUnpackedPaletteData
.public NNS_G2dGetUnpackedScreenData
.public G2x_SetBlendAlpha_
.public MI_CpuFill8
.public memset
.public gSystem
.public ov56_021E5C20
.public ov56_021E5C9C
.public ov56_021E5CB4
