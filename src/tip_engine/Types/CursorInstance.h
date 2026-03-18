#include "CommonTypes.h"
#include "ReqTypes.h"
#include "ModelFormat.h"
#include "VivaClassTypes.h"

struct sceneLookAt_s;
struct cursorTargetList_s;
struct cursorMainWorkspace_s;
struct cursorControls_s;
struct cursorCamera_s;
struct cursorTarget_s;
struct cursorMarker_s;
struct cursorSurfaceMonitorInst_s;
struct cursorCookieCutterInst_s;

/* 1012 */
enum cursorMode_e : __int32
{
  cursorMode_Idle = 0x0,
  cursorMode_Tool_Using = 0x1,
  cursorMode_Tool_Opening = 0x2,
  cursorMode_Actor_MindMeld = 0x3,
  cursorMode_Actor_Headcam = 0x4,
  cursorMode_Garden_BirdsEyeView = 0x5,
  cursorMode_Garden_Boundary_Crossing = 0x6,
  cursorMode_Garden_Boundary_Crossed = 0x7,
  cursorMode_Garden_Boundary_Crossed_BirdsEyeView = 0x8,
  cursorMode_MAX = 0x9,
};

/* 12403 */
struct cursorNetSyncInst_s
{
  mlVec originalPos;
  mlVec wantedPos;
  mlVec overshootPos;
};

/* 12428 */
struct cursorArea_s
{
  mlVec vertices[50];
  unsigned int numVertices;
};

/* 1013 */
enum cursorLock_e : __int32
{
  cursorLock_None = 0x0,
  cursorLock_Position = 0x1,
  cursorLock_DontSuck = 0x2,
  cursorLock_ForceSuck = 0x4,
  cursorLock_Camera_All = 0x10,
  cursorLock_Camera_Yaw = 0x20,
  cursorLock_Camera_Pitch = 0x40,
  cursorLock_Camera_Zoom = 0x80,
  cursorLock_Camera_Position = 0x100,
  cursorLock_BirdsEye = 0x200,
  cursorLock_StartMenu = 0x400,
  cursorLock_MAX = 0xFFFF,
};

/* 11889 */
struct assetDbPackageManagerLoadUnit_s_unnamed_tag
{
  unsigned int acksRemaining;
  float timer;
  char initiatingPlayer;
  unsigned int addressOnInitiator;
  int notifiedInitiatorOfLoadComplete;
};

/* 12442 */
struct cursorInst_s_unnamed_tag
{
  int states[13];
};

/* 11716 */
struct objTagDb_s
{
  char text[64];
};

/* 11892 */
struct gameIdParams_s
{
  int useParams;
  int createdLocally;
  gameIdComplete_s id;
};

/* 11893 */
struct objNetSyncPropertiesAsset_s
{
  unsigned int properties;
};

/* 11894 */
struct objNetSyncDirtyFlagAsset_s
{
  unsigned int dirtyFlags;
};

/* 11895 */
struct objNetSyncDOPropertiesAsset_s
{
  unsigned int properties;
};

/* 11896 */
struct objNetSyncParams_s
{
  objNetSyncPropertiesAsset_s properties;
  objNetSyncDirtyFlagAsset_s dirtyFlags;
  objNetSyncDOPropertiesAsset_s doproperties;
  float updateDelayTimerDefault;
  float updateForcedTimerDefault;
};

/* 11897 */
struct objParams_s
{
  unsigned __int16 size;
  objTagDb_s tag;
  char classId[64];
  sceneMainWorkspace_s *scene;
  assetId_s objParamsAid;
  gameIdParams_s idParams;
  objNetSyncParams_s netSyncParams;
};

/* 12443 */
struct sceneControlNetSyncParams_s
{
  int type;
};

/* 12444 */
struct sceneControlObjParams_s
{
  objParams_s __objParameters;
  sceneControlNetSyncParams_s netSyncParams;
  int disablePause;
  int disableNoControllerTest;
  int disableScreenSaver;
  int disableSerialisation;
};

/* 990 */
enum cursorControlsType_e : __int32
{
  cursorControlsType_Advanced = 0x0,
  cursorControlsType_Basic = 0x1,
  cursorControlsType_MAX = 0x2,
};

/* 12445 */
struct cursorParams_s_unnamed_tag
{
  float clamp;
  float sector;
  float snapDistance;
};

/* 12446 */
struct __declspec(align(4)) cursorParams_s
{
  sceneControlObjParams_s __sceneControlObjParameters;
  cursorControlsType_e controls;
  assetId_s cameraAid;
  assetId_s targetAid;
  assetId_s markerAid;
  cursorParams_s_unnamed_tag suck;
  unsigned char move[4];
  unsigned char turbo[8];
  unsigned char tool[64];
  unsigned char pushout[8];
  unsigned char frontend[8];
  int couchSocial;
  char couchSocialPlayerIndex;
};

/* 12400 */
struct __declspec(align(4)) cursorInst_s
{
  sceneControlObjInst_s __sceneControlObjInstance;
  cursorMainWorkspace_s *workspace;
  cursorMode_e mode;
  char owner;
  cursorNetSyncInst_s netsync;
  cursorControls_s *controls;
  cursorCamera_s *camera;
  cursorTarget_s *target;
  cursorMarker_s *marker;
  cursorArea_s area;
  cursorSurfaceMonitorInst_s *surfaceMonitor;
  cursorCookieCutterInst_s *cookieCutter;
  cursorLock_e locks;
  dsList2_s lockStack;
  cursorTargetList_s *avatarList;
  float timer;
  avatarInst_s *attachedTo;
  avatarInst_s *lastTarget;
  sceneLookAt_s *lookAt;
  unsigned int hijackRefCount;
  int _firstTickBodge;
  int hasPushedPad;
  int couchSocial;
  assetDbPackageManagerLoadUnit_s asyncToolLoadUnit[4];
  cursorInst_s_unnamed_tag deflect;
  unsigned char position[24];
  unsigned char rotation[24];
  unsigned char suck[12];
  unsigned char move[20];
  unsigned char turbo[12];
  unsigned char tool[104];
  unsigned char action[16];
  unsigned char frontend[4];
  cursorParams_s _params;
  netDeadReckoningInst_s deadReckoning;
};

