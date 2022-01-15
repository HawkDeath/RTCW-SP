#include "vk_local.h"
#include <vulkan/vulkan.h>
#include <volk.h>
#include <stdio.h>
#include <Windows.h>
#if !defined(__PRETTY_FUNCTION__)
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#define LOG(...) MessageBoxA(NULL, __VA_ARGS__, "", MB_OK);

glconfig_t glConfig; // dummy

void AddCoronaToScene(const vec3_t org, float r, float g, float b,
  float scale, int id, int flags) {
  LOG(__PRETTY_FUNCTION__)
}

void AddLightToScene(const vec3_t org, float intensity, float r, float g,
  float b, int overdraw) {
  LOG(__PRETTY_FUNCTION__)
}

void AddPolysToScene(qhandle_t hShader, int numVerts,
  const polyVert_t* verts, int numPolys) {
  LOG(__PRETTY_FUNCTION__)
}

void Shutdown(qboolean destroyWindow) {
  LOG(__PRETTY_FUNCTION__)
}

void BeginRegistration(glconfig_t* config) { LOG(__PRETTY_FUNCTION__) }

qhandle_t RegisterModel(const char* name) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}
qhandle_t RegisterSkin(const char* name) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

qhandle_t RegisterShader(const char* name) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

qhandle_t RegisterShaderNoMip(const char* name) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

void LoadWorld(const char* name) {
  LOG(__PRETTY_FUNCTION__)
}

qboolean GetSkinModel(qhandle_t skinid, const char* type,
  char* name) {
  LOG(__PRETTY_FUNCTION__)
  return qtrue;
}

qhandle_t GetShaderFromModel(qhandle_t modelid, int surfnum,
  int withlightmap) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

void SetWorldVisData(const byte* vis) {
  LOG(__PRETTY_FUNCTION__)
}

void EndRegistration(void) {
  LOG(__PRETTY_FUNCTION__)
}  

void ClearScene(void) { LOG(__PRETTY_FUNCTION__) }

void AddRefEntityToScene(const refEntity_t* re) { LOG(__PRETTY_FUNCTION__) }

int LightForPoint(vec3_t point, vec3_t ambientLight, vec3_t directedLight,
  vec3_t lightDir) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

void AddPolyToScene(qhandle_t hShader, int numVerts,
  const polyVert_t* verts) {
  LOG(__PRETTY_FUNCTION__)
}

void SetFog(int fogvar, int var1, int var2, float r, float g, float b,
  float density) {
  LOG(__PRETTY_FUNCTION__)
}

void RenderScene(const refdef_t* fd) { LOG(__PRETTY_FUNCTION__) }

void SetColor(const float* rgba) { LOG(__PRETTY_FUNCTION__) } // NULL = 1,1,1,1

void DrawStretchPic(float x, float y, float w, float h, float s1, float t1,
  float s2, float t2, qhandle_t hShader) {
  LOG(__PRETTY_FUNCTION__)
} // 0 = white

void DrawStretchPicGradient(float x, float y, float w, float h, float s1,
  float t1, float s2, float t2,
  qhandle_t hShader, const float* gradientColor,
  int gradientType) {
  LOG(__PRETTY_FUNCTION__)
}

void DrawStretchRaw(int x, int y, int w, int h, int cols, int rows,
  const byte* data, int client, qboolean dirty) {
  LOG(__PRETTY_FUNCTION__)
}

void UploadCinematic(int w, int h, int cols, int rows, const byte* data,
  int client, qboolean dirty) {
  LOG(__PRETTY_FUNCTION__)
}

void BeginFrame(stereoFrame_t stereoFrame) { LOG(__PRETTY_FUNCTION__) }

void EndFrame(int* frontEndMsec, int* backEndMsec) { LOG(__PRETTY_FUNCTION__) }

int MarkFragments(int numPoints, const vec3_t* points,
  const vec3_t projection, int maxPoints,
  vec3_t pointBuffer, int maxFragments,
  markFragment_t* fragmentBuffer) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}

int LerpTag(orientation_t* tag, const refEntity_t* refent,
  const char* tagName, int startIndex) {
  LOG(__PRETTY_FUNCTION__)
  return 0;
}
void ModelBounds(qhandle_t model, vec3_t mins, vec3_t maxs) { LOG(__PRETTY_FUNCTION__) }

void RegisterFont(const char* fontName, int pointSize, fontInfo_t* font) { LOG(__PRETTY_FUNCTION__) }

void RemapShader(const char* oldShader, const char* newShader,
  const char* offsetTime) {
  LOG(__PRETTY_FUNCTION__)
}

qboolean GetEntityToken(char* buffer, int size) { LOG(__PRETTY_FUNCTION__) return qtrue; }

refexport_t* GetRefAPI(int apiVersion, refimport_t* rimp) {
  static refexport_t re;
  //    ri = *rimp;
  VkInstance instance;
  volkInitialize();
  memset(&re, 0, sizeof(re));
  re.AddCoronaToScene = AddCoronaToScene;
  re.AddLightToScene = AddLightToScene;
  re.AddPolysToScene = AddPolysToScene;
  re.AddPolyToScene = AddPolyToScene;
  re.AddRefEntityToScene = AddRefEntityToScene;
  re.BeginFrame = BeginFrame;
  re.BeginRegistration = BeginRegistration;
  re.ClearScene = ClearScene;
  re.DrawStretchPic = DrawStretchPic;
  re.DrawStretchPicGradient = DrawStretchPicGradient;
  re.DrawStretchRaw = DrawStretchRaw;
  re.EndFrame = EndFrame;
  re.EndRegistration = EndRegistration;
  re.GetEntityToken = GetEntityToken;
  re.GetShaderFromModel = GetShaderFromModel;
  re.GetSkinModel = GetSkinModel;
  re.LerpTag = LerpTag;
  re.LightForPoint = LightForPoint;
  re.LoadWorld = LoadWorld;
  re.MarkFragments = MarkFragments;
  re.ModelBounds = ModelBounds;
  re.RegisterFont = RegisterFont;
  re.RegisterModel = RegisterModel;
  re.RegisterShader = RegisterShader;
  re.RegisterShaderNoMip = RegisterShaderNoMip;
  re.RegisterSkin = RegisterSkin;
  re.RemapShader = RemapShader;
  re.RenderScene = RenderScene;
  re.SetColor = SetColor;
  re.SetFog = SetFog;
  re.SetWorldVisData = SetWorldVisData;
  re.Shutdown = Shutdown;
  re.UploadCinematic = UploadCinematic;

  return &re;
}
