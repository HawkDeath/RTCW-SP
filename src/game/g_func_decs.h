extern void Info_SetValueForKey_Big(char *s, const char *key,
                                    const char *value);
extern void Info_SetValueForKey(char *s, const char *key, const char *value);
extern qboolean Info_Validate(const char *s);
extern void Info_RemoveKey_Big(char *s, const char *key);
extern void Info_RemoveKey(char *s, const char *key);
extern void Info_NextPair(const char **head, char *key, char *value);
extern char *Info_ValueForKey(const char *s, const char *key);
extern float *tv(float x, float y, float z);
extern char *QDECL va(char *format, ...);
extern int Q_strcasecmp(char *s1, char *s2);
extern int Q_strncasecmp(char *s1, char *s2, int n);
extern void QDECL Com_sprintf(char *dest, int size, const char *fmt, ...);
extern char *Q_CleanStr(char *string);
extern int Q_PrintStrlen(const char *string);
extern void Q_strcat(char *dest, int size, const char *src);
extern char *Q_strupr(char *s1);
extern char *Q_strlwr(char *s1);
extern int Q_stricmp(const char *s1, const char *s2);
extern int Q_strncmp(const char *s1, const char *s2, int n);
extern int Q_stricmpn(const char *s1, const char *s2, int n);
extern void Q_strncpyz(char *dest, const char *src, int destsize);
extern char *Q_strrchr(const char *string, int c);
extern int Q_isforfilename(int c);
extern int Q_isalphanumeric(int c);
extern int Q_isnumeric(int c);
extern int Q_isalpha(int c);
extern int Q_isupper(int c);
extern int Q_islower(int c);
extern int Q_isprint(int c);
extern void Parse3DMatrix(char **buf_p, int z, int y, int x, float *m);
extern void Parse2DMatrix(char **buf_p, int y, int x, float *m);
extern void Parse1DMatrix(char **buf_p, int x, float *m);
extern void SkipRestOfLine(char **data);
extern void SkipBracedSection(char **program);
extern void COM_MatchToken(char **buf_p, char *match);
extern char *COM_ParseExt(char **data_p, qboolean allowLineBreaks);
extern int COM_Compress(char *data_p);
extern char *SkipWhitespace(char *data, qboolean *hasNewLines);
extern void COM_ParseWarning(char *format, ...);
extern void COM_ParseError(char *format, ...);
extern char *COM_Parse(char **data_p);
extern int COM_GetCurrentParseLine(void);
extern void COM_SetCurrentParseLine(int line);
extern void COM_RestoreParseSession(char **data_p);
extern void COM_BeginParseSession(const char *name);
extern void Swap_Init(void);
extern float FloatNoSwap(float f);
extern float FloatSwap(float f);
extern qint64 Long64NoSwap(qint64 ll);
extern qint64 Long64Swap(qint64 ll);
extern int LongNoSwap(int l);
extern int LongSwap(int l);
extern short ShortNoSwap(short l);
extern short ShortSwap(short l);
extern float LittleFloat(float l);
extern float BigFloat(float l);
extern qint64 LittleLong64(qint64 l);
extern qint64 BigLong64(qint64 l);
extern int LittleLong(int l);
extern int BigLong(int l);
extern short LittleShort(short l);
extern short BigShort(short l);
extern void COM_BitClear(int array[], int bitNum);
extern void COM_BitSet(int array[], int bitNum);
extern qboolean COM_BitCheck(const int array[], int bitNum);
extern void COM_DefaultExtension(char *path, int maxSize,
                                 const char *extension);
extern void COM_StripFilename(char *in, char *out);
extern void COM_StripExtension(const char *in, char *out);
extern char *COM_SkipPath(char *pathname);
extern float Com_Clamp(float min, float max, float value);
extern float VectorDistance(vec3_t v1, vec3_t v2);
extern void AxisToAngles(vec3_t axis[3], vec3_t angles);
extern float vectoyaw(const vec3_t vec);
extern void ProjectPointOntoVector(vec3_t point, vec3_t vStart, vec3_t vEnd,
                                   vec3_t vProj);
extern void GetPerpendicularViewVector(const vec3_t point, const vec3_t p1,
                                       const vec3_t p2, vec3_t up);
extern void PerpendicularVector(vec3_t dst, const vec3_t src);
extern void AngleVectors(const vec3_t angles, vec3_t forward, vec3_t right,
                         vec3_t up);
extern void MatrixMultiply(float in1[3][3], float in2[3][3], float out[3][3]);
extern int Q_log2(int val);
extern void Vector4Scale(const vec4_t in, vec_t scale, vec4_t out);
extern void VectorInverse(vec3_t v);
extern vec_t DistanceSquared(const vec3_t p1, const vec3_t p2);
extern vec_t Distance(const vec3_t p1, const vec3_t p2);
extern vec_t VectorLengthSquared(const vec3_t v);
extern vec_t VectorLength(const vec3_t v);
extern void CrossProduct(const vec3_t v1, const vec3_t v2, vec3_t cross);
extern void _VectorScale(const vec3_t in, vec_t scale, vec3_t out);
extern void _VectorCopy(const vec3_t in, vec3_t out);
extern void _VectorAdd(const vec3_t veca, const vec3_t vecb, vec3_t out);
extern void _VectorSubtract(const vec3_t veca, const vec3_t vecb, vec3_t out);
extern vec_t _DotProduct(const vec3_t v1, const vec3_t v2);
extern void _VectorMA(const vec3_t veca, float scale, const vec3_t vecb,
                      vec3_t vecc);
extern vec_t VectorNormalize2(const vec3_t v, vec3_t out);
extern void VectorNormalizeFast(vec3_t v);
extern vec_t VectorNormalize(vec3_t v);
extern int VectorCompare(const vec3_t v1, const vec3_t v2);
extern void AddPointToBounds(const vec3_t v, vec3_t mins, vec3_t maxs);
extern void ClearBounds(vec3_t mins, vec3_t maxs);
extern float RadiusFromBounds(const vec3_t mins, const vec3_t maxs);
extern int BoxOnPlaneSide(vec3_t emins, vec3_t emaxs, struct cplane_s *p);
extern void SetPlaneSignbits(cplane_t *out);
extern float AngleDelta(float angle1, float angle2);
extern float AngleNormalize180(float angle);
extern float AngleNormalize360(float angle);
extern float AngleMod(float a);
extern void AnglesSubtract(vec3_t v1, vec3_t v2, vec3_t v3);
extern float AngleSubtract(float a1, float a2);
extern float LerpAngle(float from, float to, float frac);
extern float Q_fabs(float f);
extern float Q_rsqrt(float number);
extern void VectorRotate(vec3_t in, vec3_t matrix[3], vec3_t out);
extern void MakeNormalVectors(const vec3_t forward, vec3_t right, vec3_t up);
extern void ProjectPointOnPlane(vec3_t dst, const vec3_t p,
                                const vec3_t normal);
extern void AxisCopy(vec3_t in[3], vec3_t out[3]);
extern void AxisClear(vec3_t axis[3]);
extern void AnglesToAxis(const vec3_t angles, vec3_t axis[3]);
extern void vectoangles(const vec3_t value1, vec3_t angles);
extern void RotateAroundDirection(vec3_t axis[3], float yaw);
extern void RotatePointAroundVector(vec3_t dst, const vec3_t dir,
                                    const vec3_t point, float degrees);
extern qboolean PlaneFromPoints(vec4_t plane, const vec3_t a, const vec3_t b,
                                const vec3_t c);
extern float NormalizeColor(const vec3_t in, vec3_t out);
extern unsigned ColorBytes4(float r, float g, float b, float a);
extern unsigned ColorBytes3(float r, float g, float b);
extern void ByteToDir(int b, vec3_t dir);
extern int DirToByte(vec3_t dir);
extern signed short ClampShort(int i);
extern signed char ClampChar(int i);
extern float Q_crandom(int *seed);
extern float Q_random(int *seed);
extern int Q_rand(int *seed);
extern void FireWeapon(gentity_t *ent);
extern void CalcMuzzlePoints(gentity_t *ent, int weapon);
extern void CalcMuzzlePointForActivate(gentity_t *ent, vec3_t forward,
                                       vec3_t right, vec3_t up,
                                       vec3_t muzzlePoint);
extern void CalcMuzzlePoint(gentity_t *ent, int weapon, vec3_t forward,
                            vec3_t right, vec3_t up, vec3_t muzzlePoint);
extern qboolean LogAccuracyHit(gentity_t *target, gentity_t *attacker);
extern void AddLean(gentity_t *ent, vec3_t point);
extern void Weapon_LightningFire(gentity_t *ent);
extern void Weapon_RocketLauncher_Fire(gentity_t *ent, float aimSpreadScale);
extern void weapon_venom_fire(gentity_t *ent, qboolean fullmode,
                              float aimSpreadScale);
extern void VenomPattern(vec3_t origin, vec3_t origin2, int seed,
                         gentity_t *ent);
extern qboolean VenomPellet(vec3_t start, vec3_t end, gentity_t *ent);
extern void weapon_zombiespirit(gentity_t *ent, gentity_t *missile);
extern void weapon_zombiespit(gentity_t *ent);
extern gentity_t *weapon_grenadelauncher_fire(gentity_t *ent, int grenType);
extern gentity_t *weapon_crowbar_throw(gentity_t *ent);
extern void Bullet_Fire_Extended(gentity_t *source, gentity_t *attacker,
                                 vec3_t start, vec3_t end, float spread,
                                 int damage, int recursion);
extern void Bullet_Fire(gentity_t *ent, float spread, int damage);
extern void Bullet_Endpos(gentity_t *ent, float spread, vec3_t *end);
extern void SniperSoundEFX(vec3_t pos);
extern void EmitterCheck(gentity_t *ent, gentity_t *attacker, trace_t *tr);
extern void RubbleFlagCheck(gentity_t *ent, trace_t tr);
extern void Tesla_Fire(gentity_t *ent);
extern void Cross_Fire(gentity_t *ent);
extern float G_GetWeaponSpread(int weapon);
extern int G_GetWeaponDamage(int weapon);
extern void SnapVectorTowards(vec3_t v, vec3_t to);
extern trace_t *CheckMeleeAttack(gentity_t *ent, float dist, qboolean isTest);
extern void Weapon_Gauntlet(gentity_t *ent);
extern void Weapon_Class_Special(gentity_t *ent);
extern void weapon_callAirStrike(gentity_t *ent);
extern void Weapon_Engineer(gentity_t *ent);
extern void Weapon_Medic(gentity_t *ent);
extern void Weapon_Knife(gentity_t *ent);
extern int DebugLine(vec3_t start, vec3_t end, int color);
extern void G_ProcessTagConnect(gentity_t *ent, qboolean clearAngles);
extern qboolean infront(gentity_t *self, gentity_t *other);
extern void G_SetAngle(gentity_t *ent, vec3_t angle);
extern void G_SetOrigin(gentity_t *ent, vec3_t origin);
extern void G_AnimScriptSound(int soundIndex, vec3_t org, int client);
extern void G_Sound(gentity_t *ent, int soundIndex);
extern void G_AddEvent(gentity_t *ent, int event, int eventParm);
extern void G_AddPredictableEvent(gentity_t *ent, int event, int eventParm);
extern void G_KillBox(gentity_t *ent);
extern gentity_t *G_TempEntity(vec3_t origin, int event);
extern void G_FreeEntity(gentity_t *ed);
extern qboolean G_EntitiesFree(void);
extern gentity_t *G_Spawn(void);
extern void G_InitGentity(gentity_t *e);
extern void G_SetMovedir(vec3_t angles, vec3_t movedir);
extern char *vtosf(const vec3_t v);
extern char *vtos(const vec3_t v);
extern void G_UseTargets(gentity_t *ent, gentity_t *activator);
extern gentity_t *G_PickTarget(char *targetname);
extern gentity_t *G_Find(gentity_t *from, int fieldofs, const char *match);
extern void G_TeamCommand(team_t team, char *cmd);
extern int G_SoundIndex(const char *name);
extern int G_ModelIndex(char *name);
extern int G_FindConfigstringIndex(const char *name, int start, int max,
                                   qboolean create);
extern const char *BuildShaderStateConfig();
extern void AddRemap(const char *oldShader, const char *newShader,
                     float timeOffset);
extern void SP_trigger_objective_info(gentity_t *ent);
extern void Touch_objective_info(gentity_t *ent, gentity_t *other,
                                 trace_t *trace);
extern void SP_trigger_flagonly(gentity_t *ent);
extern void Touch_flagonly(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void SP_gas(gentity_t *self);
extern void gas_think(gentity_t *ent);
extern void gas_touch(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void SP_trigger_aidoor(gentity_t *ent);
extern void trigger_aidoor_stayopen(gentity_t *ent, gentity_t *other,
                                    trace_t *trace);
extern void SP_trigger_deathCheck(gentity_t *ent);
extern void SP_trigger_once(gentity_t *ent);
extern void SP_func_timer(gentity_t *self);
extern void func_timer_use(gentity_t *self, gentity_t *other,
                           gentity_t *activator);
extern void func_timer_think(gentity_t *self);
extern void SP_trigger_hurt(gentity_t *self);
extern void hurt_use(gentity_t *self, gentity_t *other, gentity_t *activator);
extern void hurt_think(gentity_t *ent);
extern void hurt_touch(gentity_t *self, gentity_t *other, trace_t *trace);
extern void SP_trigger_teleport(gentity_t *self);
extern void trigger_teleporter_touch(gentity_t *self, gentity_t *other,
                                     trace_t *trace);
extern void SP_target_push(gentity_t *self);
extern void Use_target_push(gentity_t *self, gentity_t *other,
                            gentity_t *activator);
extern void SP_trigger_push(gentity_t *self);
extern void trigger_push_use(gentity_t *self, gentity_t *other,
                             gentity_t *activator);
extern void AimAtTarget(gentity_t *self);
extern void trigger_push_touch(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void SP_trigger_always(gentity_t *ent);
extern void trigger_always_think(gentity_t *ent);
extern void SP_trigger_multiple(gentity_t *ent);
extern void Enable_Trigger_Touch(gentity_t *ent);
extern void Touch_Multi(gentity_t *self, gentity_t *other, trace_t *trace);
extern void Use_Multi(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void multi_trigger(gentity_t *ent, gentity_t *activator);
extern void multi_wait(gentity_t *ent);
extern void InitTrigger(gentity_t *self);
extern void SP_camera_reset_player(gentity_t *ent);
extern void reset_players_pos(gentity_t *ent, gentity_t *other,
                              gentity_t *activator);
extern void mark_players_pos(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void SP_screen_fade(gentity_t *ent);
extern void screen_fade_use(gentity_t *ent, gentity_t *other,
                            gentity_t *activator);
extern void SP_camera_cam(gentity_t *ent);
extern void camera_cam_firstthink(gentity_t *ent);
extern void camera_cam_use(gentity_t *ent, gentity_t *other,
                           gentity_t *activator);
extern void camera_cam_think(gentity_t *ent);
extern void Init_Camera(gentity_t *ent);
extern void delayOnthink(gentity_t *ent);
extern void SP_truck_cam(gentity_t *self);
extern void truck_cam_think(gentity_t *ent);
extern void truck_cam_touch(gentity_t *self, gentity_t *other, trace_t *trace);
extern void SP_props_me109(gentity_t *ent);
extern void InitPlaneSpeaker(gentity_t *ent);
extern void PlaneUse(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void Think_SetupAirplaneWaypoints(gentity_t *ent);
extern void props_me109_think(gentity_t *self);
extern void Plane_Attack(gentity_t *self, qboolean in_PVS);
extern void Plane_Fire_Lead(gentity_t *self);
extern void props_me109_pain(gentity_t *self, gentity_t *attacker, int damage,
                             vec3_t point);
extern void props_me109_die(gentity_t *self, gentity_t *inflictor,
                            gentity_t *attacker, int damage, int mod);
extern void ExplodePlaneSndFx(gentity_t *self);
extern void SP_plane_waypoint(gentity_t *self);
extern void plane_AIScript_AlertEntity(gentity_t *ent);
extern void SP_func_tramcar(gentity_t *self);
extern void Blocked_Tramcar(gentity_t *ent, gentity_t *other);
extern void TramCarUse(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void Tramcar_die(gentity_t *self, gentity_t *inflictor,
                        gentity_t *attacker, int damage, int mod);
extern void Reached_Tramcar(gentity_t *ent);
extern void GetNextTrack(gentity_t *ent);
extern void Calc_Roll(gentity_t *ent);
extern void InitTramcar(gentity_t *ent);
extern void SP_team_WOLF_checkpoint(gentity_t *ent);
extern void checkpoint_spawntouch(gentity_t *self, gentity_t *other,
                                  trace_t *trace);
extern void checkpoint_touch(gentity_t *self, gentity_t *other, trace_t *trace);
extern void checkpoint_think(gentity_t *self);
extern void checkpoint_use(gentity_t *ent, gentity_t *other,
                           gentity_t *activator);
extern void SP_team_WOLF_objective(gentity_t *ent);
extern void SP_team_CTF_bluespawn(gentity_t *ent);
extern void SP_team_CTF_redspawn(gentity_t *ent);
extern void SP_team_CTF_blueplayer(gentity_t *ent);
extern void SP_team_CTF_redplayer(gentity_t *ent);
extern void CheckTeamStatus(void);
extern void TeamplayInfoMessage(gentity_t *ent);
extern gentity_t *SelectCTFSpawnPoint(team_t team, int teamstate, vec3_t origin,
                                      vec3_t angles);
extern gentity_t *SelectRandomTeamSpawnPoint(int teamstate, team_t team);
extern int FindFarthestObjectiveIndex(vec3_t source);
extern qboolean Team_GetLocationMsg(gentity_t *ent, char *loc, int loclen);
extern gentity_t *Team_GetLocation(gentity_t *ent);
extern int Pickup_Team(gentity_t *ent, gentity_t *other);
extern int Team_TouchEnemyFlag(gentity_t *ent, gentity_t *other, int team);
extern int Team_TouchOurFlag(gentity_t *ent, gentity_t *other, int team);
extern void Team_DroppedFlagThink(gentity_t *ent);
extern void Team_FreeEntity(gentity_t *ent);
extern void Team_ReturnFlag(int team);
extern void Team_ReturnFlagSound(gentity_t *ent, int team);
extern void Team_ResetFlags(void);
extern gentity_t *Team_ResetFlag(int team);
extern void Team_CheckHurtCarrier(gentity_t *targ, gentity_t *attacker);
extern void Team_FragBonuses(gentity_t *targ, gentity_t *inflictor,
                             gentity_t *attacker);
extern qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2);
extern void QDECL PrintMsg(gentity_t *ent, const char *fmt, ...);
extern const char *TeamColorString(int team);
extern const char *OtherTeamName(int team);
extern const char *TeamName(int team);
extern int OtherTeam(int team);
extern void Team_InitGame(void);
extern void SP_target_rumble(gentity_t *self);
extern void target_rumble_use(gentity_t *ent, gentity_t *other,
                              gentity_t *activator);
extern void target_rumble_think(gentity_t *ent);
extern void SP_target_script_trigger(gentity_t *ent);
extern void target_script_trigger_use(gentity_t *ent, gentity_t *other,
                                      gentity_t *activator);
extern void SP_target_smoke(gentity_t *ent);
extern void smoke_init(gentity_t *ent);
extern void smoke_toggle(gentity_t *ent, gentity_t *self, gentity_t *activator);
extern void smoke_think(gentity_t *ent);
extern void SP_target_alarm(gentity_t *ent);
extern void Use_Target_Alarm(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void SP_target_lock(gentity_t *ent);
extern void Use_Target_Lock(gentity_t *ent, gentity_t *other,
                            gentity_t *activator);
extern void SP_target_autosave(gentity_t *ent);
extern void SP_target_counter(gentity_t *ent);
extern void SP_target_fog(gentity_t *ent);
extern void Use_target_fog(gentity_t *ent, gentity_t *other,
                           gentity_t *activator);
extern void Use_Target_Counter(gentity_t *ent, gentity_t *other,
                               gentity_t *activator);
extern void Use_Target_Autosave(gentity_t *ent, gentity_t *other,
                                gentity_t *activator);
extern void SP_target_location(gentity_t *self);
extern void target_location_linkup(gentity_t *ent);
extern void SP_target_position(gentity_t *self);
extern void SP_target_kill(gentity_t *self);
extern void target_kill_use(gentity_t *self, gentity_t *other,
                            gentity_t *activator);
extern void SP_target_relay(gentity_t *self);
extern void relay_AIScript_AlertEntity(gentity_t *self);
extern void target_relay_use(gentity_t *self, gentity_t *other,
                             gentity_t *activator);
extern void SP_target_teleporter(gentity_t *self);
extern void target_teleporter_use(gentity_t *self, gentity_t *other,
                                  gentity_t *activator);
extern void SP_target_laser(gentity_t *self);
extern void target_laser_start(gentity_t *self);
extern void target_laser_use(gentity_t *self, gentity_t *other,
                             gentity_t *activator);
extern void target_laser_off(gentity_t *self);
extern void target_laser_on(gentity_t *self);
extern void target_laser_think(gentity_t *self);
extern void SP_target_speaker(gentity_t *ent);
extern void target_speaker_multiple(gentity_t *ent);
extern void Use_Target_Speaker(gentity_t *ent, gentity_t *other,
                               gentity_t *activator);
extern void SP_target_print(gentity_t *ent);
extern void Use_Target_Print(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void SP_target_score(gentity_t *ent);
extern void Use_Target_Score(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void SP_target_delay(gentity_t *ent);
extern void Use_Target_Delay(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void Think_Target_Delay(gentity_t *ent);
extern void SP_target_remove_powerups(gentity_t *ent);
extern void Use_target_remove_powerups(gentity_t *ent, gentity_t *other,
                                       gentity_t *activator);
extern void SP_target_give(gentity_t *ent);
extern void Use_Target_Give(gentity_t *ent, gentity_t *other,
                            gentity_t *activator);
extern int trap_GeneticParentsAndChildSelection(int numranks, float *ranks,
                                                int *parent1, int *parent2,
                                                int *child);
extern void trap_BotResetWeaponState(int weaponstate);
extern void trap_BotFreeWeaponState(int weaponstate);
extern int trap_BotAllocWeaponState(void);
extern int trap_BotLoadWeaponWeights(int weaponstate, char *filename);
extern void trap_BotGetWeaponInfo(int weaponstate, int weapon,
                                  void *weaponinfo);
extern int trap_BotChooseBestFightWeapon(int weaponstate, int *inventory);
extern void trap_BotInitAvoidReach(int handle);
extern void trap_BotInitMoveState(int handle, void *initmove);
extern void trap_BotFreeMoveState(int handle);
extern int trap_BotAllocMoveState(void);
extern int trap_BotPredictVisiblePosition(vec3_t origin, int areanum,
                                          void *goal, int travelflags,
                                          vec3_t target);
extern int trap_BotMovementViewTarget(int movestate, void *goal,
                                      int travelflags, float lookahead,
                                      vec3_t target);
extern int trap_BotReachabilityArea(vec3_t origin, int testground);
extern void trap_BotResetLastAvoidReach(int movestate);
extern void trap_BotResetAvoidReach(int movestate);
extern int trap_BotMoveInDirection(int movestate, vec3_t dir, float speed,
                                   int type);
extern void trap_BotMoveToGoal(void *result, int movestate, void *goal,
                               int travelflags);
extern void trap_BotResetMoveState(int movestate);
extern void trap_BotFreeGoalState(int handle);
extern int trap_BotAllocGoalState(int state);
extern void trap_BotMutateGoalFuzzyLogic(int goalstate, float range);
extern void trap_BotSaveGoalFuzzyLogic(int goalstate, char *filename);
extern void trap_BotInterbreedGoalFuzzyLogic(int parent1, int parent2,
                                             int child);
extern void trap_BotFreeItemWeights(int goalstate);
extern int trap_BotLoadItemWeights(int goalstate, char *filename);
extern void trap_BotUpdateEntityItems(void);
extern void trap_BotInitLevelItems(void);
extern float trap_BotAvoidGoalTime(int goalstate, int number);
extern int trap_BotGetMapLocationGoal(char *name, void *goal);
extern int trap_BotGetNextCampSpotGoal(int num, void *goal);
extern int trap_BotGetLevelItemGoal(int index, char *classname, void *goal);
extern int trap_BotItemGoalInVisButNotVisible(int viewer, vec3_t eye,
                                              vec3_t viewangles, void *goal);
extern int trap_BotTouchingGoal(vec3_t origin, void *goal);
extern int trap_BotChooseNBGItem(int goalstate, vec3_t origin, int *inventory,
                                 int travelflags, void *ltg, float maxtime);
extern int trap_BotChooseLTGItem(int goalstate, vec3_t origin, int *inventory,
                                 int travelflags);
extern int trap_BotGetSecondGoal(int goalstate, void *goal);
extern int trap_BotGetTopGoal(int goalstate, void *goal);
extern void trap_BotGoalName(int number, char *name, int size);
extern void trap_BotDumpGoalStack(int goalstate);
extern void trap_BotDumpAvoidGoals(int goalstate);
extern void trap_BotEmptyGoalStack(int goalstate);
extern void trap_BotPopGoal(int goalstate);
extern void trap_BotPushGoal(int goalstate, void *goal);
extern void trap_BotRemoveFromAvoidGoals(int goalstate, int number);
extern void trap_BotResetAvoidGoals(int goalstate);
extern void trap_BotResetGoalState(int goalstate);
extern void trap_BotSetChatName(int chatstate, char *name);
extern void trap_BotSetChatGender(int chatstate, int gender);
extern int trap_BotLoadChatFile(int chatstate, char *chatfile, char *chatname);
extern void trap_BotReplaceSynonyms(char *string, unsigned long int context);
extern void trap_UnifyWhiteSpaces(char *string);
extern void trap_BotMatchVariable(void *match, int variable, char *buf,
                                  int size);
extern int trap_BotFindMatch(char *str, void *match, unsigned long int context);
extern int trap_StringContains(char *str1, char *str2, int casesensitive);
extern void trap_BotGetChatMessage(int chatstate, char *buf, int size);
extern void trap_BotEnterChat(int chatstate, int client, int sendto);
extern int trap_BotChatLength(int chatstate);
extern int trap_BotReplyChat(int chatstate, char *message, int mcontext,
                             int vcontext, char *var0, char *var1, char *var2,
                             char *var3, char *var4, char *var5, char *var6,
                             char *var7);
extern int trap_BotNumInitialChats(int chatstate, char *type);
extern void trap_BotInitialChat(int chatstate, char *type, int mcontext,
                                char *var0, char *var1, char *var2, char *var3,
                                char *var4, char *var5, char *var6, char *var7);
extern int trap_BotNumConsoleMessages(int chatstate);
extern int trap_BotNextConsoleMessage(int chatstate, void *cm);
extern void trap_BotRemoveConsoleMessage(int chatstate, int handle);
extern void trap_BotQueueConsoleMessage(int chatstate, int type, char *message);
extern void trap_BotFreeChatState(int handle);
extern int trap_BotAllocChatState(void);
extern void trap_Characteristic_String(int character, int index, char *buf,
                                       int size);
extern int trap_Characteristic_BInteger(int character, int index, int min,
                                        int max);
extern int trap_Characteristic_Integer(int character, int index);
extern float trap_Characteristic_BFloat(int character, int index, float min,
                                        float max);
extern float trap_Characteristic_Float(int character, int index);
extern void trap_BotFreeCharacter(int character);
extern int trap_BotLoadCharacter(char *charfile, int skill);
extern void trap_EA_ResetInput(int client, void *init);
extern void trap_EA_GetInput(int client, float thinktime, void *input);
extern void trap_EA_EndRegular(int client, float thinktime);
extern void trap_EA_View(int client, vec3_t viewangles);
extern void trap_EA_Move(int client, vec3_t dir, float speed);
extern void trap_EA_MoveRight(int client);
extern void trap_EA_MoveLeft(int client);
extern void trap_EA_MoveBack(int client);
extern void trap_EA_MoveForward(int client);
extern void trap_EA_MoveDown(int client);
extern void trap_EA_MoveUp(int client);
extern void trap_EA_Crouch(int client);
extern void trap_EA_DelayedJump(int client);
extern void trap_EA_Jump(int client);
extern void trap_EA_Respawn(int client);
extern void trap_EA_Use(int client);
extern void trap_EA_Reload(int client);
extern void trap_EA_Attack(int client);
extern void trap_EA_Talk(int client);
extern void trap_EA_SelectWeapon(int client, int weapon);
extern void trap_EA_Command(int client, char *command);
extern void trap_EA_Gesture(int client);
extern void trap_EA_DropInv(int client, char *inv);
extern void trap_EA_UseInv(int client, char *inv);
extern void trap_EA_DropItem(int client, char *it);
extern void trap_EA_UseItem(int client, char *it);
extern void trap_EA_SayTeam(int client, char *str);
extern void trap_EA_Say(int client, char *str);
extern void trap_AAS_SetAASBlockingEntity(vec3_t absmin, vec3_t absmax,
                                          qboolean blocking);
extern qboolean trap_AAS_GetRouteFirstVisPos(vec3_t srcpos, vec3_t destpos,
                                             int travelflags, vec3_t retpos);
extern int trap_AAS_FindAttackSpotWithinRange(int srcnum, int rangenum,
                                              int enemynum, float rangedist,
                                              int travelflags, float *outpos);
extern qboolean trap_AAS_RT_GetHidePos(vec3_t srcpos, int srcnum, int srcarea,
                                       vec3_t destpos, int destnum,
                                       int destarea, vec3_t returnPos);
extern void trap_AAS_RT_ShowRoute(vec3_t srcpos, int srcnum, int destnum);
extern int trap_AAS_PredictClientMovement(void *move, int entnum, vec3_t origin,
                                          int presencetype, int onground,
                                          vec3_t velocity, vec3_t cmdmove,
                                          int cmdframes, int maxframes,
                                          float frametime, int stopevent,
                                          int stopareanum, int visualize);
extern int trap_AAS_Swimming(vec3_t origin);
extern int trap_AAS_AreaTravelTimeToGoalArea(int areanum, vec3_t origin,
                                             int goalareanum, int travelflags);
extern int trap_AAS_AreaReachability(int areanum);
extern int trap_AAS_IntForBSPEpairKey(int ent, char *key, int *value);
extern int trap_AAS_FloatForBSPEpairKey(int ent, char *key, float *value);
extern int trap_AAS_VectorForBSPEpairKey(int ent, char *key, vec3_t v);
extern int trap_AAS_ValueForBSPEpairKey(int ent, char *key, char *value,
                                        int size);
extern int trap_AAS_NextBSPEntity(int ent);
extern int trap_AAS_PointContents(vec3_t point);
extern int trap_AAS_TraceAreas(vec3_t start, vec3_t end, int *areas,
                               vec3_t *points, int maxareas);
extern int trap_AAS_PointAreaNum(vec3_t point);
extern void trap_AAS_SetCurrentWorld(int index);
extern float trap_AAS_Time(void);
extern void trap_AAS_PresenceTypeBoundingBox(int presencetype, vec3_t mins,
                                             vec3_t maxs);
extern int trap_AAS_Initialized(void);
extern void trap_AAS_EntityInfo(int entnum, void *info);
extern void trap_BotUserCommand(int clientNum, usercmd_t *ucmd);
extern int trap_BotGetServerCommand(int clientNum, char *message, int size);
extern int trap_BotGetSnapshotEntity(int clientNum, int sequence);
extern int trap_BotLibTest(int parm0, char *parm1, vec3_t parm2, vec3_t parm3);
extern int trap_BotLibUpdateEntity(int ent, void *bue);
extern int trap_BotLibLoadMap(const char *mapname);
extern int trap_BotLibStartFrame(float time);
extern int trap_BotLibDefine(char *string);
extern int trap_BotLibVarGet(char *var_name, char *value, int size);
extern int trap_BotLibVarSet(char *var_name, char *value);
extern int trap_BotLibShutdown(void);
extern int trap_BotLibSetup(void);
extern qboolean trap_GetTag(int clientNum, char *tagName, orientation_t * or);
extern void trap_SnapVector(float *v);
extern int trap_RealTime(qtime_t *qtime);
extern void trap_DebugPolygonDelete(int id);
extern int trap_DebugPolygonCreate(int color, int numPoints, vec3_t *points);
extern qboolean trap_GetEntityToken(char *buffer, int bufferSize);
extern void trap_GetUsercmd(int clientNum, usercmd_t *cmd);
extern void trap_BotFreeClient(int clientNum);
extern int trap_BotAllocateClient(void);
extern qboolean trap_EntityContactCapsule(const vec3_t mins, const vec3_t maxs,
                                          const gentity_t *ent);
extern qboolean trap_EntityContact(const vec3_t mins, const vec3_t maxs,
                                   const gentity_t *ent);
extern int trap_EntitiesInBox(const vec3_t mins, const vec3_t maxs, int *list,
                              int maxcount);
extern void trap_UnlinkEntity(gentity_t *ent);
extern void trap_LinkEntity(gentity_t *ent);
extern qboolean trap_AreasConnected(int area1, int area2);
extern void trap_AdjustAreaPortalState(gentity_t *ent, qboolean open);
extern qboolean trap_InPVSIgnorePortals(const vec3_t p1, const vec3_t p2);
extern qboolean trap_InPVS(const vec3_t p1, const vec3_t p2);
extern int trap_PointContents(const vec3_t point, int passEntityNum);
extern void trap_TraceCapsule(trace_t *results, const vec3_t start,
                              const vec3_t mins, const vec3_t maxs,
                              const vec3_t end, int passEntityNum,
                              int contentmask);
extern void trap_Trace(trace_t *results, const vec3_t start, const vec3_t mins,
                       const vec3_t maxs, const vec3_t end, int passEntityNum,
                       int contentmask);
extern void trap_SetBrushModel(gentity_t *ent, const char *name);
extern void trap_GetServerinfo(char *buffer, int bufferSize);
extern void trap_SetUserinfo(int num, const char *buffer);
extern void trap_GetUserinfo(int num, char *buffer, int bufferSize);
extern void trap_GetConfigstring(int num, char *buffer, int bufferSize);
extern void trap_SetConfigstring(int num, const char *string);
extern void trap_SendServerCommand(int clientNum, const char *text);
extern void trap_DropClient(int clientNum, const char *reason);
extern void trap_LocateGameData(gentity_t *gEnts, int numGEntities,
                                int sizeofGEntity_t, playerState_t *clients,
                                int sizeofGClient);
extern void trap_Cvar_VariableStringBuffer(const char *var_name, char *buffer,
                                           int bufsize);
extern int trap_Cvar_VariableIntegerValue(const char *var_name);
extern void trap_Cvar_Set(const char *var_name, const char *value);
extern void trap_Cvar_Update(vmCvar_t *cvar);
extern void trap_Cvar_Register(vmCvar_t *cvar, const char *var_name,
                               const char *value, int flags);
extern void trap_SendConsoleCommand(int exec_when, const char *text);
extern int trap_FS_GetFileList(const char *path, const char *extension,
                               char *listbuf, int bufsize);
extern void trap_FS_CopyFile(char *from, char *to);
extern void trap_FS_FCloseFile(fileHandle_t f);
extern int trap_FS_Rename(const char *from, const char *to);
extern int trap_FS_Write(const void *buffer, int len, fileHandle_t f);
extern void trap_FS_Read(void *buffer, int len, fileHandle_t f);
extern int trap_FS_FOpenFile(const char *qpath, fileHandle_t *f, fsMode_t mode);
extern void trap_Argv(int n, char *buffer, int bufferLength);
extern int trap_Argc(void);
extern int trap_Milliseconds(void);
extern void trap_Endgame(void);
extern void trap_Error(const char *fmt);
extern void trap_Printf(const char *fmt);
extern int PASSFLOAT(float x);
extern void dllEntry(int(QDECL *syscallptr)(int arg, ...));
extern qboolean ConsoleCommand(void);
extern void Svcmd_ForceTeam_f(void);
extern gclient_t *ClientForString(const char *s);
extern void Svcmd_EntityList_f(void);
extern void Svcmd_RemoveIP_f(void);
extern void Svcmd_AddIP_f(void);
extern void G_ProcessIPBans(void);
extern qboolean G_FilterPacket(char *from);
extern void G_SpawnEntitiesFromString(void);
extern void SP_worldspawn(void);
extern qboolean G_ParseSpawnVars(void);
extern char *G_AddSpawnVarToken(const char *string);
extern void G_SpawnGEntityFromSpawnVars(void);
extern void G_ParseField(const char *key, const char *value, gentity_t *ent);
extern char *G_NewString(const char *string);
extern qboolean G_CallSpawn(gentity_t *ent);
extern qboolean G_SpawnVector(const char *key, const char *defaultString,
                              float *out);
extern qboolean G_SpawnInt(const char *key, const char *defaultString,
                           int *out);
extern qboolean G_SpawnFloat(const char *key, const char *defaultString,
                             float *out);
extern qboolean G_SpawnString(const char *key, const char *defaultString,
                              char **out);
extern void G_WriteSessionData(void);
extern void G_InitWorldSession(void);
extern void G_InitSessionData(gclient_t *client, char *userinfo);
extern void G_ReadSessionData(gclient_t *client);
extern void G_WriteClientSessionData(gclient_t *client);
extern qboolean G_ScriptAction_SetHealth(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_RestoreScript(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_BackupScript(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_SetRoundTimelimit(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_EndRound(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Announce(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_SetObjectiveStatus(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_SetWinner(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_ObjectiveAlliedDesc(gentity_t *ent,
                                                   char *params);
extern qboolean G_ScriptAction_ObjectiveAxisDesc(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_NumberofObjectives(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_AlliedRespawntime(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_AxisRespawntime(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MapDescription(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_AIScriptName(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_EntityScriptName(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_StartCam(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_StopSound(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Halt(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_TagConnect(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_ResetScript(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_FaceAngles(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Print(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MissionSuccess(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MissionFailed(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Accum(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_AlertEntity(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_PlayAnim(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MusicQueue(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MusicFade(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MusicStop(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MusicPlay(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_MusicStart(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_PlaySound(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Trigger(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_Wait(gentity_t *ent, char *params);
extern qboolean G_ScriptAction_GotoMarker(gentity_t *ent, char *params);
extern void SP_script_multiplayer(gentity_t *ent);
extern void SP_script_camera(gentity_t *ent);
extern void SP_script_model_med(gentity_t *ent);
extern void script_model_med_use(gentity_t *ent, gentity_t *other,
                                 gentity_t *activator);
extern void script_model_med_spawn(gentity_t *ent);
extern void SP_script_mover(gentity_t *ent);
extern void script_mover_blocked(gentity_t *ent, gentity_t *other);
extern void script_mover_use(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void script_mover_spawn(gentity_t *ent);
extern void script_mover_pain(gentity_t *self, gentity_t *attacker, int damage,
                              vec3_t point);
extern void script_mover_die(gentity_t *self, gentity_t *inflictor,
                             gentity_t *attacker, int damage, int mod);
extern void script_linkentity(gentity_t *ent);
extern qboolean G_Script_ScriptRun(gentity_t *ent);
extern void G_Script_ScriptEvent(gentity_t *ent, char *eventStr, char *params);
extern void G_Script_ScriptChange(gentity_t *ent, int newScriptNum);
extern void G_Script_ScriptParse(gentity_t *ent);
extern void G_Script_ScriptLoad(void);
extern g_script_stack_action_t *G_Script_ActionForString(char *string);
extern int G_Script_EventForString(char *string);
extern qboolean G_Script_EventMatch_IntInRange(g_script_event_t *event,
                                               char *eventParm);
extern qboolean G_Script_EventMatch_StringEqual(g_script_event_t *event,
                                                char *eventParm);
extern void G_LoadPersistant(void);
extern qboolean G_SavePersistant(char *nextmap);
extern void PersReadCastState(fileHandle_t f, cast_state_t *cs);
extern void PersWriteCastState(fileHandle_t f, cast_state_t *cs);
extern void PersReadEntity(fileHandle_t f, gentity_t *cl);
extern void PersWriteEntity(fileHandle_t f, gentity_t *ent);
extern void PersReadClient(fileHandle_t f, gclient_t *cl);
extern void PersWriteClient(fileHandle_t f, gclient_t *cl);
extern void G_LoadGame(char *filename);
extern qboolean G_SaveGame(char *username);
extern char *G_Save_DateStr(void);
extern char *G_Save_TimeStr(void);
extern void ReadTime(fileHandle_t f, qtime_t *tm);
extern void WriteTime(fileHandle_t f);
extern void ReadCastState(fileHandle_t f, cast_state_t *cs, int size);
extern void WriteCastState(fileHandle_t f, cast_state_t *cs);
extern void ReadEntity(fileHandle_t f, gentity_t *ent, int size);
extern void WriteEntity(fileHandle_t f, gentity_t *ent);
extern void ReadClient(fileHandle_t f, gclient_t *client, int size);
extern void WriteClient(fileHandle_t f, gclient_t *cl);
extern void G_Save_Decode(byte *in, int insize, byte *out, int outsize);
extern int G_Save_Encode(byte *raw, byte *out, int rawsize, int outsize);
extern void ReadField(fileHandle_t f, saveField_t *field, byte *base);
extern void WriteField2(fileHandle_t f, saveField_t *field, byte *base);
extern void WriteField1(saveField_t *field, byte *base);
extern byte *G_FindFuncByName(char *name);
extern funcList_t *G_FindFuncAtAddress(byte *adr);
extern int G_SaveWrite(const void *buffer, int len, fileHandle_t f);
extern void G_SaveWriteError(void);
extern void SP_props_flamethrower(gentity_t *ent);
extern void props_flamethrower_init(gentity_t *ent);
extern void props_flamethrower_use(gentity_t *ent, gentity_t *other,
                                   gentity_t *activator);
extern void props_flamethrower_think(gentity_t *ent);
extern void SP_props_footlocker(gentity_t *self);
extern void props_locker_death(gentity_t *ent, gentity_t *inflictor,
                               gentity_t *attacker, int damage, int mod);
extern void props_locker_mass(gentity_t *ent);
extern void props_locker_spawn_item(gentity_t *ent);
extern void init_locker(gentity_t *ent);
extern void props_locker_pain(gentity_t *ent, gentity_t *attacker, int damage,
                              vec3_t point);
extern void props_locker_use(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void props_locker_endrattle(gentity_t *ent);
extern void Spawn_Junk(gentity_t *ent);
extern void SP_props_statueBRUSH(gentity_t *self);
extern void SP_props_statue(gentity_t *ent);
extern void props_statue_touch(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void props_statue_death(gentity_t *ent, gentity_t *inflictor,
                               gentity_t *attacker, int damage, int mod);
extern void props_statue_animate(gentity_t *ent);
extern void props_statue_blocked(gentity_t *ent);
extern void SP_skyportal(gentity_t *ent);
extern void SP_props_decor_Scale(gentity_t *ent);
extern void SP_props_decorBRUSH(gentity_t *self);
extern void SP_props_decoration(gentity_t *ent);
extern void props_touch(gentity_t *self, gentity_t *other, trace_t *trace);
extern void Use_props_decoration(gentity_t *ent, gentity_t *self,
                                 gentity_t *activator);
extern void props_decoration_death(gentity_t *ent, gentity_t *inflictor,
                                   gentity_t *attacker, int damage, int mod);
extern void props_decoration_animate(gentity_t *ent);
extern void SP_props_ExploPart(gentity_t *ent);
extern void props_ExploPartInit(gentity_t *ent);
extern void props_ExploPartUse(gentity_t *ent, gentity_t *other,
                               gentity_t *activator);
extern void SP_propsFireColumn(gentity_t *ent);
extern void propsFireColumnInit(gentity_t *ent);
extern void propsFireColumnUse(gentity_t *ent, gentity_t *other,
                               gentity_t *activator);
extern void SP_props_snowGenerator(gentity_t *ent);
extern void props_snowGenerator_use(gentity_t *ent, gentity_t *other,
                                    gentity_t *activator);
extern void props_snowGenerator_think(gentity_t *ent);
extern void SP_props_castlebed(gentity_t *ent);
extern void props_castlebed_die(gentity_t *ent, gentity_t *inflictor,
                                gentity_t *attacker, int damage, int mod);
extern void props_castlebed_animate(gentity_t *ent);
extern void props_castlebed_touch(gentity_t *ent, gentity_t *other,
                                  trace_t *trace);
extern void SP_Props_58x112tablew(gentity_t *ent);
extern void props_58x112tablew_die(gentity_t *ent, gentity_t *inflictor,
                                   gentity_t *attacker, int damage, int mod);
extern void props_58x112tablew_think(gentity_t *ent);
extern void SP_Props_Flipping_Table(gentity_t *ent);
extern void props_flippy_blocked(gentity_t *ent, gentity_t *other);
extern void props_flippy_table_die(gentity_t *ent, gentity_t *inflictor,
                                   gentity_t *attacker, int damage, int mod);
extern void flippy_table_animate(gentity_t *ent);
extern void flippy_table_use(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void SP_Props_Crate32x64(gentity_t *ent);
extern void props_crate32x64_die(gentity_t *ent, gentity_t *inflictor,
                                 gentity_t *attacker, int damage, int mod);
extern void props_crate32x64_think(gentity_t *ent);
extern void SP_crate_32(gentity_t *self);
extern void SP_crate_64(gentity_t *self);
extern void crate_die(gentity_t *ent, gentity_t *inflictor, gentity_t *attacker,
                      int damage, int mod);
extern void crate_animate(gentity_t *ent);
extern void touch_crate_64(gentity_t *self, gentity_t *other, trace_t *trace);
extern void SP_Props_Flamebarrel(gentity_t *ent);
extern void Props_Barrel_Think(gentity_t *self);
extern void Props_OilSlickSlippery(gentity_t *ent);
extern void Props_Barrel_Die(gentity_t *ent, gentity_t *inflictor,
                             gentity_t *attacker, int damage, int mod);
extern void OilSlick_remove(gentity_t *ent);
extern void OilSlick_remove_think(gentity_t *ent);
extern void Props_Barrel_Pain(gentity_t *ent, gentity_t *attacker, int damage,
                              vec3_t point);
extern void SP_OilParticles(gentity_t *ent);
extern qboolean validOilSlickSpawnPoint(vec3_t point, gentity_t *ent);
extern void Delayed_Leak_Think(gentity_t *ent);
extern void OilParticles_think(gentity_t *ent);
extern void SP_OilSlick(gentity_t *ent);
extern void smoker_think(gentity_t *ent);
extern void barrel_smoke(gentity_t *ent);
extern void Props_Barrel_Animate(gentity_t *ent);
extern void Props_Barrel_Touch(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void SP_Props_Desklamp(gentity_t *ent);
extern void SP_props_shard_generator(gentity_t *ent);
extern void Use_Props_Shard_Generator(gentity_t *ent, gentity_t *other,
                                      gentity_t *activator);
extern void SP_Props_DamageInflictor(gentity_t *ent);
extern void Use_DamageInflictor(gentity_t *ent, gentity_t *other,
                                gentity_t *activator);
extern void SP_Props_ChairHiback(gentity_t *ent);
extern void SP_Props_ChairSide(gentity_t *ent);
extern void SP_Props_ChairChatArm(gentity_t *ent);
extern void SP_Props_ChairChat(gentity_t *ent);
extern void SP_Props_GenericChair(gentity_t *ent);
extern void SP_Props_Chair(gentity_t *ent);
extern void Props_Chair_Skyboxtouch(gentity_t *ent);
extern void Props_Chair_Die(gentity_t *ent, gentity_t *inflictor,
                            gentity_t *attacker, int damage, int mod);
extern void Prop_Break_Sound(gentity_t *ent);
extern void Spawn_Shard(gentity_t *ent, gentity_t *inflictor, int quantity,
                        int type);
extern void Props_Chair_Animate(gentity_t *ent);
extern void Props_Chair_Touch(gentity_t *self, gentity_t *other,
                              trace_t *trace);
extern void Prop_Check_Ground(gentity_t *self);
extern qboolean Prop_Touch(gentity_t *self, gentity_t *other, vec3_t v);
extern void Props_Chair_Think(gentity_t *self);
extern void Props_Activated(gentity_t *self);
extern void Props_TurnLightsOff(gentity_t *self);
extern void Just_Got_Thrown(gentity_t *self);
extern void SP_Props_Locker_Tall(gentity_t *ent);
extern void props_locker_tall_die(gentity_t *ent, gentity_t *inflictor,
                                  gentity_t *attacker, int damage, int mod);
extern void locker_tall_think(gentity_t *ent);
extern void SP_Props_RadioSEVEN(gentity_t *ent);
extern void props_radio_dieSEVEN(gentity_t *ent, gentity_t *inflictor,
                                 gentity_t *attacker, int damage, int mod);
extern void SP_Props_Radio(gentity_t *ent);
extern void props_radio_die(gentity_t *ent, gentity_t *inflictor,
                            gentity_t *attacker, int damage, int mod);
extern void SP_Props_Bench(gentity_t *ent);
extern void props_bench_die(gentity_t *ent, gentity_t *inflictor,
                            gentity_t *attacker, int damage, int mod);
extern void props_bench_think(gentity_t *ent);
extern void InitProp(gentity_t *ent);
extern void propExplosion(gentity_t *ent);
extern void propExplosionLarge(gentity_t *ent);
extern void SP_Dust(gentity_t *ent);
extern void dust_angles_think(gentity_t *ent);
extern void dust_use(gentity_t *ent, gentity_t *self, gentity_t *activator);
extern void SP_SmokeDust(gentity_t *ent);
extern void smokedust_use(gentity_t *ent, gentity_t *self,
                          gentity_t *activator);
extern void SP_props_gunsparks(gentity_t *ent);
extern void SP_props_sparks(gentity_t *ent);
extern void sparks_angles_think(gentity_t *ent);
extern void Psparks_think(gentity_t *ent);
extern void PGUNsparks_use(gentity_t *ent, gentity_t *self,
                           gentity_t *activator);
extern void prop_smoke(gentity_t *ent);
extern void Psmoke_think(gentity_t *ent);
extern void SP_props_box_64(gentity_t *self);
extern void touch_props_box_64(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void SP_props_box_48(gentity_t *self);
extern void touch_props_box_48(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void SP_props_box_32(gentity_t *self);
extern void touch_props_box_32(gentity_t *self, gentity_t *other,
                               trace_t *trace);
extern void moveit(gentity_t *ent, float yaw, float dist);
extern void DropToFloor(gentity_t *ent);
extern void DropToFloorG(gentity_t *ent);
extern void G_Activate(gentity_t *ent, gentity_t *activator);
extern void func_invisible_user(gentity_t *ent);
extern void use_invisible_user(gentity_t *ent, gentity_t *other,
                               gentity_t *activator);
extern void SP_func_explosive(gentity_t *ent);
extern void InitExplosive(gentity_t *ent);
extern void func_explosive_spawn(gentity_t *self, gentity_t *other,
                                 gentity_t *activator);
extern void func_explosive_alert(gentity_t *self);
extern void func_explosive_use(gentity_t *self, gentity_t *other,
                               gentity_t *activator);
extern void func_explosive_touch(gentity_t *self, gentity_t *other,
                                 trace_t *trace);
extern void func_explosive_explode(gentity_t *self, gentity_t *inflictor,
                                   gentity_t *attacker, int damage, int mod);
extern void ClearExplosive(gentity_t *self);
extern void ThrowDebris(gentity_t *self, char *modelname, float speed,
                        vec3_t origin);
extern void SP_target_effect(gentity_t *ent);
extern void use_target_effect(gentity_t *self, gentity_t *other,
                              gentity_t *activator);
extern void SP_func_door_rotating(gentity_t *ent);
extern void SP_func_pendulum(gentity_t *ent);
extern void SP_func_bobbing(gentity_t *ent);
extern void SP_func_rotating(gentity_t *ent);
extern void Use_Func_Rotate(gentity_t *ent, gentity_t *other,
                            gentity_t *activator);
extern void SP_func_static(gentity_t *ent);
extern void SP_func_leaky(gentity_t *ent);
extern void G_BlockThink(gentity_t *ent);
extern void Static_Pain(gentity_t *ent, gentity_t *attacker, int damage,
                        vec3_t point);
extern void Use_Static(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void SP_func_train_rotating(gentity_t *self);
extern void Think_SetupTrainTargets_rotating(gentity_t *ent);
extern void Reached_Train_rotating(gentity_t *ent);
extern void Think_BeginMoving_rotating(gentity_t *ent);
extern void SP_func_bats(gentity_t *self);
extern void FuncEndSpiritsThink(gentity_t *self);
extern void FuncBatsActivate(gentity_t *self, gentity_t *other,
                             gentity_t *activator);
extern void BatDie(gentity_t *self, gentity_t *inflictor, gentity_t *attacker,
                   int damage, int meansOfDeath);
extern void BatMoveThink(gentity_t *bat);
extern void FuncBatsReached(gentity_t *self);
extern void SP_func_train_particles(gentity_t *self);
extern void Func_train_particles_reached(gentity_t *self);
extern void SP_func_train(gentity_t *self);
extern void SP_path_corner(gentity_t *self);
extern void Think_SetupTrainTargets(gentity_t *ent);
extern void Reached_Train(gentity_t *ent);
extern void Think_BeginMoving(gentity_t *ent);
extern void SP_func_button(gentity_t *ent);
extern void Touch_Button(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void SP_func_plat(gentity_t *ent);
extern void SpawnPlatTrigger(gentity_t *ent);
extern void Touch_PlatCenterTrigger(gentity_t *ent, gentity_t *other,
                                    trace_t *trace);
extern void Touch_Plat(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void SP_func_secret(gentity_t *ent);
extern void SP_func_door(gentity_t *ent);
extern void G_TryDoor(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void DoorSetSounds(gentity_t *ent, int doortype, qboolean isRotating);
extern void Door_reverse_sounds(gentity_t *ent);
extern void finishSpawningKeyedMover(gentity_t *ent);
extern qboolean findNonAIBrushTargeter(gentity_t *ent);
extern void Think_MatchTeam(gentity_t *ent);
extern void Think_SpawnNewDoorTrigger(gentity_t *ent);
extern void Touch_DoorTrigger(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void Blocked_DoorRotate(gentity_t *ent, gentity_t *other);
extern void Blocked_Door(gentity_t *ent, gentity_t *other);
extern void InitMoverRotate(gentity_t *ent);
extern void InitMover(gentity_t *ent);
extern void Use_BinaryMover(gentity_t *ent, gentity_t *other,
                            gentity_t *activator);
extern void Use_TrinaryMover(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void Reached_TrinaryMover(gentity_t *ent);
extern qboolean IsBinaryMoverBlocked(gentity_t *ent, gentity_t *other,
                                     gentity_t *activator);
extern void Reached_BinaryMover(gentity_t *ent);
extern void ReturnToPos1Rotate(gentity_t *ent);
extern void GotoPos3(gentity_t *ent);
extern void ReturnToPos2(gentity_t *ent);
extern void ReturnToPos1(gentity_t *ent);
extern void MatchTeamReverseAngleOnSlaves(gentity_t *teamLeader, int moverState,
                                          int time);
extern void MatchTeam(gentity_t *teamLeader, int moverState, int time);
extern void SetMoverState(gentity_t *ent, moverState_t moverState, int time);
extern void G_RunMover(gentity_t *ent);
extern void G_MoverTeam(gentity_t *ent);
extern qboolean G_MoverPush(gentity_t *pusher, vec3_t move, vec3_t amove,
                            gentity_t **obstacle);
extern qboolean G_TryPushingEntity(gentity_t *check, gentity_t *pusher,
                                   vec3_t move, vec3_t amove);
extern void G_RotatePoint(vec3_t point, vec3_t matrix[3]);
extern void G_TransposeMatrix(vec3_t matrix[3], vec3_t transpose[3]);
extern void G_CreateRotationMatrix(const vec3_t angles, vec3_t matrix[3]);
extern void G_TestEntityMoveTowardsPos(gentity_t *ent, vec3_t pos);
extern void G_TestEntityDropToFloor(gentity_t *ent, float maxdrop);
extern gentity_t *G_TestEntityPosition(gentity_t *ent);
extern gentity_t *fire_mortar(gentity_t *self, vec3_t start, vec3_t dir);
extern qboolean visible(gentity_t *self, gentity_t *other);
extern void fire_lead(gentity_t *self, vec3_t start, vec3_t dir, int damage);
extern gentity_t *fire_flamebarrel(gentity_t *self, vec3_t start, vec3_t dir);
extern gentity_t *fire_crowbar(gentity_t *self, vec3_t start, vec3_t dir);
extern gentity_t *fire_zombiespirit(gentity_t *self, gentity_t *bolt,
                                    vec3_t start, vec3_t dir);
extern gentity_t *fire_zombiespit(gentity_t *self, vec3_t start, vec3_t dir);
extern gentity_t *fire_rocket(gentity_t *self, vec3_t start, vec3_t dir);
extern gentity_t *fire_grenade(gentity_t *self, vec3_t start, vec3_t dir,
                               int grenadeWPID);
extern void G_RunCrowbar(gentity_t *ent);
extern void G_RunSpit(gentity_t *ent);
extern int G_PredictMissile(gentity_t *ent, int duration, vec3_t endPos,
                            qboolean allowBounce);
extern void G_PredictBounceMissile(gentity_t *ent, trajectory_t *pos,
                                   trace_t *trace, int time);
extern void G_RunMissile(gentity_t *ent);
extern void G_ExplodeMissilePoisonGas(gentity_t *ent);
extern void G_MissileDie(gentity_t *self, gentity_t *inflictor,
                         gentity_t *attacker, int damage, int mod);
extern void G_ExplodeMissile(gentity_t *ent);
extern void M_think(gentity_t *ent);
extern void Concussive_fx(vec3_t origin);
extern void Concussive_think(gentity_t *ent);
extern void G_MissileImpact(gentity_t *ent, trace_t *trace, int impactDamage,
                            vec3_t dir);
extern qboolean G_BounceMissile(gentity_t *ent, trace_t *trace);
extern void SP_misc_firetrails(gentity_t *ent);
extern void misc_firetrails_finishspawning(gentity_t *ent);
extern void SP_misc_tagemitter(gentity_t *ent);
extern void misc_tagemitter_finishspawning(gentity_t *ent);
extern void tagemitter_use(gentity_t *ent, gentity_t *other,
                           gentity_t *activator);
extern void tagemitter_die(gentity_t *ent);
extern void firetrail_use(gentity_t *ent, gentity_t *other,
                          gentity_t *activator);
extern void firetrail_die(gentity_t *ent);
extern void SP_misc_spawner(gentity_t *ent);
extern void misc_spawner_use(gentity_t *ent, gentity_t *other,
                             gentity_t *activator);
extern void misc_spawner_think(gentity_t *ent);
extern void SP_misc_flak(gentity_t *self);
extern void flak_spawn(gentity_t *ent);
extern void SP_mg42(gentity_t *self);
extern void mg42_spawn(gentity_t *ent);
extern void mg42_use(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void mg42_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker,
                     int damage, int mod);
extern void mg42_think(gentity_t *self);
extern void Flak_Animate(gentity_t *ent);
extern void mg42_track(gentity_t *self, gentity_t *other);
extern void mg42_touch(gentity_t *self, gentity_t *other, trace_t *trace);
extern void clamp_playerbehindgun(gentity_t *self, gentity_t *other,
                                  vec3_t dang);
extern void clamp_hweapontofirearc(gentity_t *self, gentity_t *other,
                                   vec3_t dang);
extern void Fire_Lead(gentity_t *ent, gentity_t *activator, float spread,
                      int damage);
extern void mg42_muzzleflash(gentity_t *ent, vec3_t muzzlepos);
extern void flakPuff(vec3_t origin, qboolean sky);
extern void SP_Bubbles(gentity_t *ent);
extern void SP_Snow(gentity_t *ent);
extern void snow_think(gentity_t *ent);
extern void snowInPVS(gentity_t *ent);
extern void SP_dlight(gentity_t *ent);
extern void use_dlight(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void shutoff_dlight(gentity_t *ent);
extern void dlight_finish_spawning(gentity_t *ent);
extern void SP_corona(gentity_t *ent);
extern void use_corona(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void SP_sniper_brush(gentity_t *ent);
extern void sniper_brush_init(gentity_t *ent);
extern void brush_activate_sniper(gentity_t *ent, gentity_t *other,
                                  trace_t *trace);
extern void SP_shooter_sniper(gentity_t *ent);
extern void SP_shooter_grenade(gentity_t *ent);
extern void SP_shooter_tesla(gentity_t *ent);
extern void shooter_tesla_finish_spawning(gentity_t *ent);
extern void use_shooter_tesla(gentity_t *ent, gentity_t *other,
                              gentity_t *activator);
extern void SP_shooter_zombiespit(gentity_t *ent);
extern void SP_shooter_rocket(gentity_t *ent);
extern void SP_shooter_mortar(gentity_t *ent);
extern void InitShooter(gentity_t *ent, int weapon);
extern void Use_Shooter(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void SP_misc_portal_camera(gentity_t *ent);
extern void SP_misc_portal_surface(gentity_t *ent);
extern void locateCamera(gentity_t *ent);
extern void SP_misc_light_surface(gentity_t *ent);
extern void SP_misc_vis_dummy_multiple(gentity_t *ent);
extern void SP_misc_vis_dummy(gentity_t *ent);
extern void locateMaster(gentity_t *ent);
extern void SP_misc_gamemodel(gentity_t *ent);
extern void SP_misc_model(gentity_t *ent);
extern void SP_misc_spotlight(gentity_t *ent);
extern void spotlight_finish_spawning(gentity_t *ent);
extern void spotlight_die(gentity_t *self, gentity_t *inflictor,
                          gentity_t *attacker, int damage, int mod);
extern void use_spotlight(gentity_t *ent, gentity_t *other,
                          gentity_t *activator);
extern void SP_misc_grabber_trap(gentity_t *ent);
extern void grabber_wake_touch(gentity_t *ent, gentity_t *other,
                               trace_t *trace);
extern void grabber_use(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern void grabber_wake(gentity_t *ent);
extern void grabber_pain(gentity_t *ent, gentity_t *attacker, int damage,
                         vec3_t point);
extern void grabber_close(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void grabber_attack(gentity_t *ent);
extern void grabber_die(gentity_t *ent, gentity_t *inflictor,
                        gentity_t *attacker, int damage, int mod);
extern void grabber_think_hit(gentity_t *ent);
extern void grabber_think_idle(gentity_t *ent);
extern void SP_misc_teleporter_dest(gentity_t *ent);
extern void TeleportPlayer(gentity_t *player, vec3_t origin, vec3_t angles);
extern void SP_lightJunior(gentity_t *self);
extern void SP_light(gentity_t *self);
extern void SP_info_notnull_big(gentity_t *self);
extern void SP_info_notnull(gentity_t *self);
extern void SP_info_null(gentity_t *self);
extern void SP_info_camp(gentity_t *self);
extern void Svcmd_GameMem_f(void);
extern void G_InitMemory(void);
extern void *G_Alloc(int size);
extern void G_RunFrame(int levelTime);
extern void G_RunThink(gentity_t *ent);
extern void CheckCvars(void);
extern void CheckReloadStatus(void);
extern void CheckVote(void);
extern void CheckTournement(void);
extern void CheckExitRules(void);
extern qboolean ScoreIsTied(void);
extern void CheckIntermissionExit(void);
extern void LogExit(const char *string);
extern void QDECL G_LogPrintf(const char *fmt, ...);
extern void ExitLevel(void);
extern void BeginIntermission(void);
extern void FindIntermissionPoint(void);
extern void MoveClientToIntermission(gentity_t *ent);
extern void SendScoreboardMessageToAllClients(void);
extern void CalculateRanks(void);
extern int QDECL SortRanks(const void *a, const void *b);
extern void AdjustTournamentScores(void);
extern void RemoveTournamentLoser(void);
extern void AddTournamentPlayer(void);
extern void QDECL Com_Printf(const char *msg, ...);
extern void QDECL Com_Error(int level, const char *error, ...);
extern void G_ShutdownGame(int restart);
extern void G_InitGame(int levelTime, int randomSeed, int restart);
extern int G_SendMissionStats();
extern void G_SpawnScriptCamera(void);
extern void G_UpdateCvars(void);
extern void G_RegisterCvars(void);
extern void G_RemapTeamShaders();
extern void G_FindTeams(void);
extern void G_CheckForCursorHints(gentity_t *ent);
extern void G_EndGame(void);
extern qboolean G_canStealthStab(int aiChar);
extern void QDECL G_Error(const char *fmt, ...);
extern void QDECL G_DPrintf(const char *fmt, ...);
extern void QDECL G_Printf(const char *fmt, ...);
extern void G_RunItem(gentity_t *ent);
extern void G_RunItemProp(gentity_t *ent, vec3_t origin);
extern void G_BounceItem(gentity_t *ent, trace_t *trace);
extern void G_SpawnItem(gentity_t *ent, gitem_t *item);
extern void SaveRegisteredItems(void);
extern void RegisterItem(gitem_t *item);
extern void ClearRegisteredItems(void);
extern void G_CheckTeamItems(void);
extern void FinishSpawningItem(gentity_t *ent);
extern void Use_Item(gentity_t *ent, gentity_t *other, gentity_t *activator);
extern gentity_t *Drop_Item(gentity_t *ent, gitem_t *item, float angle,
                            qboolean novelocity);
extern gentity_t *LaunchItem(gitem_t *item, vec3_t origin, vec3_t velocity);
extern void Touch_Item(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void Touch_Item_Auto(gentity_t *ent, gentity_t *other, trace_t *trace);
extern void RespawnItem(gentity_t *ent);
extern int Pickup_Armor(gentity_t *ent, gentity_t *other);
extern int Pickup_Health(gentity_t *ent, gentity_t *other);
extern int Pickup_Weapon(gentity_t *ent, gentity_t *other);
extern int Pickup_Ammo(gentity_t *ent, gentity_t *other);
extern void Add_Ammo(gentity_t *ent, int weapon, int count, qboolean fillClip);
extern void Fill_Clip(playerState_t *ps, int weapon);
extern int Pickup_Holdable(gentity_t *ent, gentity_t *other);
extern void UseHoldableItem(gentity_t *ent, int item);
extern int Pickup_Treasure(gentity_t *ent, gentity_t *other);
extern int Pickup_Clipboard(gentity_t *ent, gentity_t *other);
extern int Pickup_Key(gentity_t *ent, gentity_t *other);
extern int Pickup_Powerup(gentity_t *ent, gentity_t *other);
extern qboolean G_RadiusDamage(vec3_t origin, gentity_t *attacker, float damage,
                               float radius, gentity_t *ignore, int mod);
extern qboolean CanDamage(gentity_t *targ, vec3_t origin);
extern void G_Damage(gentity_t *targ, gentity_t *inflictor, gentity_t *attacker,
                     vec3_t dir, vec3_t point, int damage, int dflags, int mod);
extern void G_ArmorDamage(gentity_t *targ);
extern qboolean IsHeadShot(gentity_t *targ, gentity_t *attacker, vec3_t dir,
                           vec3_t point, int mod);
extern qboolean IsHeadShotWeapon(int mod, gentity_t *targ, gentity_t *attacker);
extern int CheckArmor(gentity_t *ent, int damage, int dflags);
extern void player_die(gentity_t *self, gentity_t *inflictor,
                       gentity_t *attacker, int damage, int meansOfDeath);
extern void body_die(gentity_t *self, gentity_t *inflictor, gentity_t *attacker,
                     int damage, int meansOfDeath);
extern void GibEntity(gentity_t *self, int killer);
extern void GibHead(gentity_t *self, int killer);
extern void LookAtKiller(gentity_t *self, gentity_t *inflictor,
                         gentity_t *attacker);
extern void TossClientItems(gentity_t *self);
extern void AddScore(gentity_t *ent, int score);
extern void ClientCommand(int clientNum);
extern void Cmd_SetSpawnPoint_f(gentity_t *clent);
extern void Cmd_EntityCount_f(gentity_t *ent);
extern void Cmd_ClientDamage_f(gentity_t *clent);
extern void ClientDamage(gentity_t *clent, int entnum, int enemynum, int id);
extern int Cmd_WolfKick_f(gentity_t *ent);
extern void Cmd_Activate_f(gentity_t *ent);
extern qboolean G_ThrowChair(gentity_t *ent, vec3_t dir, qboolean force);
extern void Cmd_InterruptCamera_f(gentity_t *ent);
extern void Cmd_SetCameraOrigin_f(gentity_t *ent);
extern void Cmd_StopCamera_f(gentity_t *ent);
extern void Cmd_StartCamera_f(gentity_t *ent);
extern void Cmd_SetViewpos_f(gentity_t *ent);
extern qboolean G_canPickupMelee(gentity_t *ent);
extern void Cmd_Vote_f(gentity_t *ent);
extern void Cmd_CallVote_f(gentity_t *ent);
extern void Cmd_Where_f(gentity_t *ent);
extern void Cmd_GameCommand_f(gentity_t *ent);
extern void G_Say(gentity_t *ent, gentity_t *target, int mode,
                  const char *chatText);
extern void G_SayTo(gentity_t *ent, gentity_t *other, int mode, int color,
                    const char *name, const char *message);
extern void Cmd_FollowCycle_f(gentity_t *ent, int dir);
extern void Cmd_Follow_f(gentity_t *ent);
extern void Cmd_Team_f(gentity_t *ent);
extern void StopFollowing(gentity_t *ent);
extern void SetWolfData(gentity_t *ent, char *ptype, char *weap, char *pistol,
                        char *grenade, char *skinnum);
extern void SetTeam(gentity_t *ent, char *s);
extern void Cmd_Kill_f(gentity_t *ent);
extern void Cmd_LevelShot_f(gentity_t *ent);
extern void Cmd_Noclip_f(gentity_t *ent);
extern void Cmd_Notarget_f(gentity_t *ent);
extern void Cmd_Nofatigue_f(gentity_t *ent);
extern void Cmd_God_f(gentity_t *ent);
extern void Cmd_Give_f(gentity_t *ent);
extern void Cmd_Fogswitch_f(void);
extern void G_setfog(char *fogstring);
extern int ClientNumberFromString(gentity_t *to, char *s);
extern void SanitizeString(char *in, char *out);
extern char *ConcatArgs(int start);
extern qboolean CheatsOk(gentity_t *ent);
extern void Cmd_Score_f(gentity_t *ent);
extern void DeathmatchScoreboardMessage(gentity_t *ent);
extern void G_RetrieveMoveSpeedsFromClient(int entnum, char *text);
extern void ClientDisconnect(int clientNum);
extern void ClientSpawn(gentity_t *ent);
extern void ClientBegin(int clientNum);
extern char *ClientConnect(int clientNum, qboolean firstTime, qboolean isBot);
extern void ClientUserinfoChanged(int clientNum);
extern qboolean G_ParseAnimationFiles(char *modelname, gclient_t *cl);
extern qboolean G_GetModelInfo(int clientNum, char *modelName,
                               animModelInfo_t **modelInfo);
extern qboolean G_CheckForExistingModelInfo(gclient_t *cl, char *modelName,
                                            animModelInfo_t **modelInfo);
extern void SetWolfSpawnWeapons(gclient_t *client);
extern void SetWolfSkin(gclient_t *client, char *model);
extern void ForceClientSkin(gclient_t *client, char *model, const char *skin);
extern team_t PickTeam(int ignoreClientNum);
extern void respawn(gentity_t *ent);
extern void reinforce(gentity_t *ent);
extern void limbo(gentity_t *ent);
extern void SetClientViewAngle(gentity_t *ent, vec3_t angle);
extern void CopyToBodyQue(gentity_t *ent);
extern void BodySink(gentity_t *ent);
extern void InitBodyQue(void);
extern gentity_t *SelectSpectatorSpawnPoint(vec3_t origin, vec3_t angles);
extern gentity_t *SelectInitialSpawnPoint(vec3_t origin, vec3_t angles);
extern gentity_t *SelectSpawnPoint(vec3_t avoidPoint, vec3_t origin,
                                   vec3_t angles);
extern gentity_t *SelectRandomDeathmatchSpawnPoint(void);
extern gentity_t *SelectNearestDeathmatchSpawnPoint(vec3_t from);
extern qboolean SpotWouldTelefrag(gentity_t *spot);
extern void SP_info_player_intermission(gentity_t *ent);
extern void SP_info_player_start(gentity_t *ent);
extern void SP_info_player_deathmatch(gentity_t *ent);
extern char *G_GetBotInfoByName(const char *name);
extern char *G_GetBotInfoByNumber(int num);
extern void Svcmd_AddBot_f(void);
extern qboolean G_BotConnect(int clientNum, qboolean restart);
extern void G_QueueBotBegin(int clientNum);
extern void G_CheckBotSpawn(void);
extern void G_CheckMinimumPlayers(void);
extern int G_CountBotPlayers(int team);
extern int G_CountHumanPlayers(int team);
extern int G_RemoveRandomBot(int team);
extern void G_AddRandomBot(int team);
extern const char *G_GetArenaInfoByMap(const char *map);
extern void SP_alarm_box(gentity_t *ent);
extern void alarmbox_finishspawning(gentity_t *ent);
extern void alarmbox_die(gentity_t *ent, gentity_t *inflictor,
                         gentity_t *attacker, int damage, int mod);
extern void alarmbox_use(gentity_t *ent, gentity_t *other, gentity_t *foo);
extern void alarmbox_updateparts(gentity_t *ent, qboolean matestoo);
extern void alarmExplosion(gentity_t *ent);
extern void ClientEndFrame(gentity_t *ent);
extern void SpectatorClientEndFrame(gentity_t *ent);
extern void G_RunClient(gentity_t *ent);
extern void ClientThink(int clientNum);
extern void ClientThink_real(gentity_t *ent);
extern void SendPendingPredictableEvents(playerState_t *ps);
extern void ClientEvents(gentity_t *ent, int oldEventSequence);
extern void ClientIntermissionThink(gclient_t *client);
extern void ClientTimerActions(gentity_t *ent, int msec);
extern qboolean ClientInactivityTimer(gclient_t *client);
extern void SpectatorThink(gentity_t *ent, usercmd_t *ucmd);
extern void G_TouchTriggers(gentity_t *ent);
extern void ClientImpacts(gentity_t *ent, pmove_t *pm);
extern void G_SetClientSound(gentity_t *ent);
extern void P_WorldEffects(gentity_t *ent);
extern void P_DamageFeedback(gentity_t *player);
extern void PM_StepSlideMove(qboolean gravity);
extern qboolean PM_SlideMove(qboolean gravity);
extern void PM_AdjustAimSpreadScale(void);
extern void PM_CoolWeapons(void);
extern int PM_WeaponClipEmpty(int wp);
extern int PM_WeaponAmmoAvailable(int wp);
extern void PM_WeaponUseAmmo(int wp, int amount);
extern void PM_CheckForReload(int weapon);
extern void PM_AddFallEvent(int landing, int surfaceparms);
extern void PM_ClipVelocity(vec3_t in, vec3_t normal, vec3_t out,
                            float overbounce);
extern void PM_AddTouchEnt(int entityNum);
extern void PM_AddEvent(int newEvent);
extern float Com_GetFlamethrowerRange(void);
extern void BG_PlayerStateToEntityStateExtraPolate(playerState_t *ps,
                                                   entityState_t *s, int time,
                                                   qboolean snap);
extern void BG_PlayerStateToEntityState(playerState_t *ps, entityState_t *s,
                                        qboolean snap);
extern void BG_AddPredictableEventToPlayerstate(int newEvent, int eventParm,
                                                playerState_t *ps);
extern void BG_GetMarkDir(const vec3_t dir, const vec3_t normal, vec3_t out);
extern void BG_EvaluateTrajectoryDelta(const trajectory_t *tr, int atTime,
                                       vec3_t result);
extern void BG_EvaluateTrajectory(const trajectory_t *tr, int atTime,
                                  vec3_t result);
extern qboolean BG_CanItemBeGrabbed(const entityState_t *ent,
                                    const playerState_t *ps);
extern qboolean isClipOnly(int weap);
extern qboolean BG_PlayerTouchesItem(playerState_t *ps, entityState_t *item,
                                     int atTime);
extern gitem_t *BG_FindItem2(const char *name);
extern gitem_t *BG_FindItem(const char *pickupName);
extern gitem_t *BG_FindItemForAmmo(int ammo);
extern gitem_t *BG_FindItemForKey(wkey_t k, int *indexreturn);
extern qboolean BG_AkimboFireSequence(int weapon, int akimboClip, int coltClip);
extern weapon_t BG_FindAmmoForWeapon(weapon_t weapon);
extern weapon_t BG_FindClipForWeapon(weapon_t weapon);
extern gitem_t *BG_FindItemForWeapon(weapon_t weapon);
extern gitem_t *BG_FindItemForHoldable(holdable_t pw);
extern gitem_t *BG_FindItemForPowerup(powerup_t pw);
extern float BG_AnimGetFootstepGap(playerState_t *ps, float xyspeed);
extern void BG_AnimUpdatePlayerStateConditions(pmove_t *pmove);
extern animation_t *BG_GetAnimationForIndex(int client, int index);
extern int BG_GetAnimScriptEvent(playerState_t *ps,
                                 scriptAnimEventTypes_t event);
extern int BG_GetAnimScriptAnimation(int client, aistateEnum_t estate,
                                     scriptAnimMoveTypes_t movetype);
extern int BG_GetConditionValue(int client, int condition,
                                qboolean checkConversion);
extern void BG_UpdateConditionValueStrings(int client, char *conditionStr,
                                           char *valueStr);
extern void BG_UpdateConditionValue(int client, int condition, int value,
                                    qboolean checkConversion);
extern char *BG_GetAnimString(int client, int anim);
extern qboolean BG_ValidAnimScript(int clientNum);
extern int BG_AnimScriptEvent(playerState_t *ps, scriptAnimEventTypes_t event,
                              qboolean isContinue, qboolean force);
extern int BG_AnimScriptStateChange(playerState_t *ps, aistateEnum_t newState,
                                    aistateEnum_t oldState);
extern int BG_AnimScriptCannedAnimation(playerState_t *ps, aistateEnum_t state);
extern int BG_AnimScriptAnimation(playerState_t *ps, aistateEnum_t estate,
                                  scriptAnimMoveTypes_t movetype,
                                  qboolean isContinue);
extern int BG_ExecuteCommand(playerState_t *ps,
                             animScriptCommand_t *scriptCommand,
                             qboolean setTimer, qboolean isContinue,
                             qboolean force);
extern int BG_PlayAnimName(playerState_t *ps, char *animName,
                           animBodyPart_t bodyPart, qboolean setTimer,
                           qboolean isContinue, qboolean force);
extern int BG_PlayAnim(playerState_t *ps, int animNum, animBodyPart_t bodyPart,
                       int forceDuration, qboolean setTimer,
                       qboolean isContinue, qboolean force);
extern animScriptItem_t *BG_FirstValidItem(int client, animScript_t *script);
extern qboolean BG_EvaluateConditions(int client, animScriptItem_t *scriptItem);
extern void BG_AnimParseAnimScript(animModelInfo_t *modelInfo,
                                   animScriptData_t *scriptData, int client,
                                   char *filename, char *input);
extern void BG_ParseCommands(char **input, animScriptItem_t *scriptItem,
                             animModelInfo_t *modelInfo,
                             animScriptData_t *scriptData);
extern qboolean BG_ParseConditions(char **text_pp,
                                   animScriptItem_t *scriptItem);
extern void BG_ParseConditionBits(char **text_pp, animStringItem_t *stringTable,
                                  int condIndex, int result[2]);
extern qboolean BG_AnimParseAnimConfig(animModelInfo_t *animModelInfo,
                                       const char *filename, const char *input);
extern void BG_InitWeaponStrings(void);
extern char *BG_CopyStringIntoBuffer(char *string, char *buffer, int bufSize,
                                     int *offset);
extern int BG_IndexForString(char *token, animStringItem_t *strings,
                             qboolean allowFail);
extern animation_t *BG_AnimationForString(char *string,
                                          animModelInfo_t *modelInfo);
extern int BG_AnimationIndexForString(char *string, int client);
extern animModelInfo_t *BG_ModelInfoForModelname(char *modelname);
extern animModelInfo_t *BG_ModelInfoForClient(int client);
extern void QDECL BG_AnimParseError(const char *msg, ...);
extern void AICast_IdleReload(cast_state_t *cs);
extern void AICast_DeadClipWalls(cast_state_t *cs);
extern void AICast_QueryThink(cast_state_t *cs);
extern qboolean AICast_RequestCrouchAttack(cast_state_t *cs, vec3_t org,
                                           float time);
extern void AICast_EvaluatePmove(int clientnum, pmove_t *pm);
extern void AICast_Blocked(cast_state_t *cs, bot_moveresult_t *moveresult,
                           int activate, bot_goal_t *goal);
extern qboolean AICast_GetAvoid(cast_state_t *cs, bot_goal_t *goal,
                                vec3_t outpos, qboolean reverse, int blockEnt);
extern void AICast_PredictMovement(cast_state_t *cs, int numframes,
                                   float frametime, aicast_predictmove_t *move,
                                   usercmd_t *ucmd, int checkHitEnt);
extern void AICast_StartServerFrame(int time);
extern void AICast_StartFrame(int time);
extern void AICast_Think(int client, float thinktime);
extern void AICast_UpdateInput(cast_state_t *cs, int time);
extern void AICast_InputToUserCommand(cast_state_t *cs, bot_input_t *bi,
                                      usercmd_t *ucmd, int delta_angles[3]);
extern void AICast_ChangeViewAngles(cast_state_t *cs, float thinktime);
extern void AICast_ProcessAIFunctions(cast_state_t *cs, float thinktime);
extern void AICast_SightUpdate(int numchecks);
extern void AICast_UpdateNonVisibility(gentity_t *srcent, gentity_t *destent,
                                       qboolean directview);
extern void AICast_UpdateVisibility(gentity_t *srcent, gentity_t *destent,
                                    qboolean shareVis, qboolean directview);
extern qboolean AICast_CheckVisibility(gentity_t *srcent, gentity_t *destent);
extern qboolean AICast_VisibleFromPos(vec3_t srcpos, int srcnum, vec3_t destpos,
                                      int destnum, qboolean updateVisPos);
extern qboolean AICast_InFieldOfVision(vec3_t viewangles, float fov,
                                       vec3_t angles);
extern void SP_ai_trigger(gentity_t *ent);
extern void ai_trigger_use(gentity_t *self, gentity_t *other,
                           gentity_t *activator);
extern void ai_trigger_activate(gentity_t *self);
extern void AICast_Touch_Trigger(gentity_t *self, gentity_t *other,
                                 trace_t *trace);
extern void AICast_trigger_trigger(gentity_t *ent, gentity_t *activator);
extern void AICast_trigger_wait(gentity_t *ent);
extern void SP_ai_effect(gentity_t *ent);
extern void ai_effect_think(gentity_t *ent);
extern void SP_ai_marker(gentity_t *ent);
extern qboolean AICast_ScriptAction_CatchFire(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_PushAway(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_AnimCondition(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_LockPlayer(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_ExplicitRouting(cast_state_t *cs,
                                                    char *params);
extern qboolean AICast_ScriptAction_MusicQueue(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_MusicFade(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_MusicStop(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_MusicPlay(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_MusicStart(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Cvar(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_NoTarget(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_SetHealth(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_AIScriptName(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_EntityScriptName(cast_state_t *cs,
                                                     char *params);
extern qboolean AICast_ScriptAction_Parachute(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Cigarette(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_StopCam(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_StopCamBlack(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_StartCamBlack(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_StartCam(cast_state_t *cs, char *params);
extern qboolean ScriptStartCam(cast_state_t *cs, char *params, qboolean black);
extern qboolean AICast_ScriptAction_Zoom(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_KnockBack(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_StateType(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_RestoreScript(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_BackupScript(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_Headlook(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_LightningDamage(cast_state_t *cs,
                                                    char *params);
extern qboolean AICast_ScriptAction_DenyAction(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Attrib(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Avoid(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_NoAvoid(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Sight(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_NoSight(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_FoundSecret(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_ChangeLevel(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_EndGame(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Teleport(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_SavePersistant(cast_state_t *cs,
                                                   char *params);
extern qboolean AICast_ScriptAction_Unmount(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Mount(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_ResetScript(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_FaceTargetAngles(cast_state_t *cs,
                                                     char *params);
extern qboolean AICast_ScriptAction_Print(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_NoAIDamage(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_ObjectiveMet(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_ObjectivesNeeded(cast_state_t *cs,
                                                     char *params);
extern qboolean AICast_ScriptAction_MissionFailed(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_SpawnCast(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Accum(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_GodMode(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_FireAtTarget(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_SaveGame(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_AlertEntity(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Movetype(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_GiveInventory(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_TakeWeapon(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_GiveWeapon(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_GiveArmor(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_SetArmor(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_SelectWeapon(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_SuggestWeapon(cast_state_t *cs,
                                                  char *params);
extern qboolean AICast_ScriptAction_SetClip(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_SetAmmo(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_ClearAnim(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_PlayAnim(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Attack(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_NoAttack(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_PlaySound(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_FollowCast(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Trigger(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_Wait(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_AbortIfLoadgame(cast_state_t *cs,
                                                    char *params);
extern qboolean AICast_ScriptAction_CrouchToCast(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_WalkToCast(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_GotoCast(cast_state_t *cs, char *params);
extern qboolean AICast_ScriptAction_CrouchToMarker(cast_state_t *cs,
                                                   char *params);
extern qboolean AICast_ScriptAction_WalkToMarker(cast_state_t *cs,
                                                 char *params);
extern qboolean AICast_ScriptAction_GotoMarker(cast_state_t *cs, char *params);
extern void AICast_NoAttackIfNotHurtSinceLastScriptAction(cast_state_t *cs);
extern qboolean AICast_ScriptRun(cast_state_t *cs, qboolean force);
extern void AICast_ForceScriptEvent(struct cast_state_s *cs, char *eventStr,
                                    char *params);
extern void AICast_ScriptEvent(struct cast_state_s *cs, char *eventStr,
                               char *params);
extern void AICast_ScriptChange(cast_state_t *cs, int newScriptNum);
extern void AICast_ScriptParse(cast_state_t *cs);
extern void AICast_ScriptLoad(void);
extern cast_script_stack_action_t *AICast_ActionForString(cast_state_t *cs,
                                                          char *string);
extern int AICast_EventForString(char *string);
extern qboolean AICast_EventMatch_IntInRange(cast_script_event_t *event,
                                             char *eventParm);
extern qboolean AICast_EventMatch_StringEqual(cast_script_event_t *event,
                                              char *eventParm);
extern char *AIFunc_Heinrich_SpawnSpiritsStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_RaiseDeadStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_RaiseDead(cast_state_t *cs);
extern char *AIFunc_Heinrich_MeleeStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_Earthquake(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordSideSlashStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordSideSlash(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordKnockbackStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordKnockback(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordLungeStart(cast_state_t *cs);
extern char *AIFunc_Heinrich_SwordLunge(cast_state_t *cs);
extern void AICast_Heinrich_Taunt(cast_state_t *cs);
extern void AICast_Heinrich_SoundPrecache(void);
extern char *AIFunc_FlameZombie_PortalStart(cast_state_t *cs);
extern char *AIFunc_FlameZombie_Portal(cast_state_t *cs);
extern char *AIFunc_Helga_MeleeStart(cast_state_t *cs);
extern char *AIFunc_Helga_Melee(cast_state_t *cs);
extern char *AIFunc_Helga_SpiritAttack_Start(cast_state_t *cs);
extern char *AIFunc_Helga_SpiritAttack(cast_state_t *cs);
extern char *AIFunc_WarriorZombieDefenseStart(cast_state_t *cs);
extern char *AIFunc_WarriorZombieDefense(cast_state_t *cs);
extern char *AIFunc_WarriorZombieSightStart(cast_state_t *cs);
extern char *AIFunc_WarriorZombieSight(cast_state_t *cs);
extern char *AIFunc_WarriorZombieMeleeStart(cast_state_t *cs);
extern char *AIFunc_WarriorZombieMelee(cast_state_t *cs);
extern char *AIFunc_RejectAttack1Start(cast_state_t *cs);
extern char *AIFunc_RejectAttack1(cast_state_t *cs);
extern char *AIFunc_BlackGuardAttack1Start(cast_state_t *cs);
extern char *AIFunc_BlackGuardAttack1(cast_state_t *cs);
extern char *AIFunc_StimSoldierAttack2Start(cast_state_t *cs);
extern char *AIFunc_StimSoldierAttack2(cast_state_t *cs);
extern char *AIFunc_StimSoldierAttack1Start(cast_state_t *cs);
extern char *AIFunc_StimSoldierAttack1(cast_state_t *cs);
extern char *AIFunc_LoperAttack3Start(cast_state_t *cs);
extern char *AIFunc_LoperAttack3(cast_state_t *cs);
extern char *AIFunc_LoperAttack2Start(cast_state_t *cs);
extern char *AIFunc_LoperAttack2(cast_state_t *cs);
extern char *AIFunc_LoperAttack1Start(cast_state_t *cs);
extern char *AIFunc_LoperAttack1(cast_state_t *cs);
extern char *AIFunc_ZombieMeleeStart(cast_state_t *cs);
extern char *AIFunc_ZombieMelee(cast_state_t *cs);
extern char *AIFunc_ZombieAttack2Start(cast_state_t *cs);
extern char *AIFunc_ZombieAttack2(cast_state_t *cs);
extern char *AIFunc_ZombieFlameAttackStart(cast_state_t *cs);
extern char *AIFunc_ZombieFlameAttack(cast_state_t *cs);
extern char *AIFunc_DefaultStart(cast_state_t *cs);
extern char *AIFunc_BattleStart(cast_state_t *cs);
extern char *AIFunc_Battle(cast_state_t *cs);
extern char *AIFunc_GrenadeKickStart(cast_state_t *cs);
extern char *AIFunc_GrenadeKick(cast_state_t *cs);
extern char *AIFunc_InspectBodyStart(cast_state_t *cs);
extern char *AIFunc_InspectBody(cast_state_t *cs);
extern char *AIFunc_BattleMG42Start(cast_state_t *cs);
extern char *AIFunc_BattleMG42(cast_state_t *cs);
extern char *AIFunc_GrenadeFlushStart(cast_state_t *cs);
extern char *AIFunc_GrenadeFlush(cast_state_t *cs);
extern char *AIFunc_BattleTakeCoverStart(cast_state_t *cs);
extern char *AIFunc_BattleTakeCover(cast_state_t *cs);
extern char *AIFunc_AvoidDangerStart(cast_state_t *cs);
extern char *AIFunc_AvoidDanger(cast_state_t *cs);
extern char *AIFunc_BattleChaseStart(cast_state_t *cs);
extern char *AIFunc_BattleChase(cast_state_t *cs);
extern char *AIFunc_BattleAmbushStart(cast_state_t *cs);
extern char *AIFunc_BattleAmbush(cast_state_t *cs);
extern char *AIFunc_BattleHuntStart(cast_state_t *cs);
extern char *AIFunc_BattleHunt(cast_state_t *cs);
extern char *AIFunc_FlipMoveStart(cast_state_t *cs, vec3_t vec);
extern char *AIFunc_FlipMove(cast_state_t *cs);
extern char *AIFunc_BattleDiveStart(cast_state_t *cs, vec3_t vec);
extern char *AIFunc_BattleRollStart(cast_state_t *cs, vec3_t vec);
extern char *AIFunc_BattleRoll(cast_state_t *cs);
extern char *AIFunc_DoorMarkerStart(cast_state_t *cs, int doornum,
                                    int markernum);
extern char *AIFunc_DoorMarker(cast_state_t *cs);
extern char *AIFunc_ChaseGoalStart(cast_state_t *cs, int entitynum,
                                   float reachdist, qboolean slowApproach);
extern char *AIFunc_ChaseGoal(cast_state_t *cs);
extern char *AIFunc_ChaseGoalIdleStart(cast_state_t *cs, int entitynum,
                                       float reachdist);
extern char *AIFunc_ChaseGoalIdle(cast_state_t *cs);
extern char *AIFunc_InspectAudibleEventStart(cast_state_t *cs, int entnum);
extern char *AIFunc_InspectAudibleEvent(cast_state_t *cs);
extern char *AIFunc_InspectBulletImpactStart(cast_state_t *cs);
extern char *AIFunc_InspectBulletImpact(cast_state_t *cs);
extern char *AIFunc_InspectFriendlyStart(cast_state_t *cs, int entnum);
extern char *AIFunc_InspectFriendly(cast_state_t *cs);
extern char *AIFunc_IdleStart(cast_state_t *cs);
extern char *AIFunc_Idle(cast_state_t *cs);
extern void AICast_SpecialFunc(cast_state_t *cs);
extern float AICast_SpeedScaleForDistance(cast_state_t *cs, float startdist,
                                          float idealDist);
extern bot_moveresult_t *AICast_MoveToPos(cast_state_t *cs, vec3_t pos,
                                          int entnum);
extern float AICast_GetRandomViewAngle(cast_state_t *cs, float tracedist);
extern char *AIFunc_Restore(cast_state_t *cs);
extern void AICast_AudibleEvent(int srcnum, vec3_t pos, float range);
extern void AICast_ProcessBullet(gentity_t *attacker, vec3_t start, vec3_t end);
extern qboolean AICast_AllowFlameDamage(int entNum);
extern qboolean AICast_HasFiredWeapon(int entNum, int weapon);
extern void AICast_CheckDangerousEntity(gentity_t *ent, int dangerFlags,
                                        float dangerDist, float tacticalLevel,
                                        float aggressionLevel,
                                        qboolean hurtFriendly);
extern int AICast_SafeMissileFire(gentity_t *ent, int duration, int enemyNum,
                                  vec3_t enemyPos, int selfNum, vec3_t endPos);
extern qboolean AICast_WantToRetreat(cast_state_t *cs);
extern float AICast_GetAccuracy(int entnum);
extern qboolean AICast_StopAndAttack(cast_state_t *cs);
extern float AICast_GetWeaponSoundRange(int weapon);
extern void AICast_RecordWeaponFire(gentity_t *ent);
extern qboolean AICast_AIDamageOK(cast_state_t *cs, cast_state_t *ocs);
extern qboolean AICast_GetTakeCoverPos(cast_state_t *cs, int enemyNum,
                                       vec3_t enemyPos, vec3_t returnPos);
extern void AICast_ProcessAttack(cast_state_t *cs);
extern qboolean AICast_RandomTriggerRelease(cast_state_t *cs);
extern qboolean AICast_CanMoveWhileFiringWeapon(int weaponnum);
extern qboolean AICast_AimAtEnemy(cast_state_t *cs);
extern void AICast_WeaponSway(cast_state_t *cs, vec3_t ofs);
extern bot_moveresult_t AICast_CombatMove(cast_state_t *cs, int tfl);
extern int AICast_WantsToTakeCover(cast_state_t *cs, qboolean attacking);
extern int AICast_WantsToChase(cast_state_t *cs);
extern float AICast_Aggression(cast_state_t *cs);
extern void AICast_ChooseWeapon(cast_state_t *cs, qboolean battleFunc);
extern qboolean AICast_WeaponUsable(cast_state_t *cs, int weaponNum);
extern qboolean AICast_GotEnoughAmmoForWeapon(cast_state_t *cs, int weapon);
extern float AICast_WeaponWantScale(cast_state_t *cs, int weapon);
extern void AICast_UpdateBattleInventory(cast_state_t *cs, int enemy);
extern qboolean AICast_CheckAttack(cast_state_t *cs, int enemy,
                                   qboolean allowHitWorld);
extern qboolean AICast_CheckAttackAtPos(int entnum, int enemy, vec3_t pos,
                                        qboolean ducking,
                                        qboolean allowHitWorld);
extern qboolean AICast_CheckAttack_real(cast_state_t *cs, int enemy,
                                        qboolean allowHitWorld);
extern float AICast_WeaponRange(cast_state_t *cs, int weaponnum);
extern qboolean AICast_SameTeam(cast_state_t *cs, int enemynum);
extern qboolean AICast_QueryEnemy(cast_state_t *cs, int enemynum);
extern qboolean AICast_HostileEnemy(cast_state_t *cs, int enemynum);
extern qboolean AICast_EntityVisible(cast_state_t *cs, int enemynum,
                                     qboolean directview);
extern int AICast_ScanForEnemies(cast_state_t *cs, int *enemies);
extern qboolean AICast_StateChange(cast_state_t *cs, aistateEnum_t newaistate);
extern void AICast_RecordScriptSound(int client);
extern void AICast_ProcessActivate(int entNum, int activatorNum);
extern void AICast_AIDoor_Touch(gentity_t *ent, gentity_t *aidoor_trigger,
                                gentity_t *door);
extern void AICast_EndChase(cast_state_t *cs);
extern void AICast_Die(gentity_t *self, gentity_t *inflictor,
                       gentity_t *attacker, int damage, int meansOfDeath);
extern void AICast_Pain(gentity_t *targ, gentity_t *attacker, int damage,
                        vec3_t point);
extern void AICast_Sight(gentity_t *ent, gentity_t *other, int lastSight);
extern void AICast_DBG_Cmd_f(int clientNum);
extern void AICast_DBG_Spawn_f(gclient_t *client, char *cmd);
extern void AICast_DBG_RouteTable_f(vec3_t org, char *param);
extern void AICast_DebugFrame(cast_state_t *cs);
extern void AICast_DBG_ListAIFuncs(cast_state_t *cs, int numprint);
extern void AICast_DBG_AddAIFunc(cast_state_t *cs, char *funcname);
extern void AICast_DBG_InitAIFuncs(void);
extern void SP_ai_blackguard(gentity_t *ent);
extern void SP_ai_protosoldier(gentity_t *ent);
extern void SP_ai_supersoldier(gentity_t *ent);
extern void SP_ai_stimsoldier_tesla(gentity_t *ent);
extern void SP_ai_stimsoldier_rocket(gentity_t *ent);
extern void SP_ai_stimsoldier_dual(gentity_t *ent);
extern void SP_ai_frogman(gentity_t *ent);
extern void SP_ai_eliteguard(gentity_t *ent);
extern void SP_ai_civilian(gentity_t *ent);
extern void SP_ai_partisan(gentity_t *ent);
extern void SP_ai_boss_heinrich(gentity_t *ent);
extern void SP_ai_boss_helga(gentity_t *ent);
extern void SP_ai_loper(gentity_t *ent);
extern void SP_ai_venom(gentity_t *ent);
extern void SP_ai_warzombie(gentity_t *ent);
extern void SP_ai_zombie(gentity_t *ent);
extern void SP_ai_american(gentity_t *ent);
extern void SP_ai_soldier(gentity_t *ent);
extern void AIChar_spawn(gentity_t *ent);
extern void AIChar_AttackSound(cast_state_t *cs);
extern void AIChar_Sight(gentity_t *ent, gentity_t *other, int lastSight);
extern void AIChar_Pain(gentity_t *ent, gentity_t *attacker, int damage,
                        vec3_t point);
extern int AIChar_GetPainLocation(gentity_t *ent, vec3_t point);
extern void AIChar_Death(gentity_t *ent, gentity_t *attacker, int damage,
                         int mod);
extern void AIChar_SetBBox(gentity_t *ent, cast_state_t *cs,
                           qboolean useHeadTag);
extern void AICast_RegisterPain(int entnum);
extern int AICast_NumAttempts(int entnum);
extern int AICast_PlayTime(int entnum);
extern int AICast_NoReload(int entnum);
extern void AICast_AgePlayTime(int entnum);
extern void AICast_AdjustIdealYawForMover(int entnum, float yaw);
extern void G_SetAASBlockingEntity(gentity_t *ent, qboolean blocking);
extern void AICast_SetFlameDamage(int entNum, qboolean status);
extern qboolean AICast_NoFlameDamage(int entNum);
extern void AICast_Activate(int activatorNum, int entNum);
extern qboolean AICast_SolidsInBBox(vec3_t pos, vec3_t mins, vec3_t maxs,
                                    int entnum, int mask);
extern void AICast_CheckLoadGame(void);
extern void AICast_EnableRenderingThink(gentity_t *ent);
extern void AICast_CastScriptThink(void);
extern void AICast_DelayedSpawnCast(gentity_t *ent, int castType);
extern void AIChar_AIScript_AlertEntity(gentity_t *ent);
extern gentity_t *AICast_TravEntityForName(gentity_t *startent, char *name);
extern gentity_t *AICast_FindEntityForName(char *name);
extern void AICast_Init(void);
extern gentity_t *AICast_CreateCharacter(gentity_t *ent, float *attributes,
                                         cast_weapon_info_t *weaponInfo,
                                         char *castname, char *model,
                                         char *head, char *sex, char *color,
                                         char *handicap);
extern void AICast_SetAASIndex(cast_state_t *cs);
extern void AICast_CheckLevelAttributes(cast_state_t *cs, gentity_t *ent,
                                        char **ppStr);
extern gentity_t *AICast_AddCastToGame(gentity_t *ent, char *castname,
                                       char *model, char *head, char *sex,
                                       char *color, char *handicap);
extern int AICast_ShutdownClient(int client);
extern int AICast_SetupClient(int client);
extern cast_state_t *AICast_GetCastState(int entitynum);
extern void AICast_Printf(int type, const char *fmt, ...);
