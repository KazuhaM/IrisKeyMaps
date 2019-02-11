#include "action_layer.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//define layer
enum {
    MDVORAK = 0,
    SMDVORAK,
    MSKYTOUCH,
    SMSKYTOUCH,
    MARKE,
    MARKJ,
    NMALE, //
    NMALJ,
    FUNCE,
    SFUNCE,
    FUNCJ,
    SFUNCJ
};

//define macro
enum custom_keycodes {
    //diphthong codes for JP
    DI_UU= SAFE_RANGE,
    DI_AI,
    DI_OU,
    DI_EI,
    DI_UI,
    DI_AU,
    DI_OI,
    DI_IU,
    DI_AA,
    DI_AE,
    DI_OO,
    DI_OA,
    DI_II,
    DI_IA,
    DI_EA,
    DI_IO,

    //-n codes for JP
    DN_UNN,
    DN_ANN,
    DN_ONN,
    DN_INN,
    DN_ENN,

    //DN_WO, TSU
    DN_WO,
    DN_TSU,
    DN_NN,
    
    //mark codes
    DM_BRCT,
    DM_BRCTL,
    DM_BRCTM,
    DM_SSTT,

    //function code
    DF_RNMSH,
    
    //layer change codes
    D_ETOJ,
    D_JTOE
};


//keycode shorthands
#define KC____  KC_TRNS // three underscores "NO" for transparent

//layer shorthands
#define _MDVORAK 0
#define _SMDVORAK 1
#define _MARKE 2
#define _NMALE 3
#define _FUNCE 4
#define _SFUNCE 5

#define _MSKYTOUCH 6
#define _SMSKYTOUCH 7
#define _MARKJ 8
#define _NMALJ 9
#define _FUNCJ 10
#define _SFUNCJ 11

//layer change
#define KC_TOE TO(0)
#define KC_SEN LT(1,KC_SPC)
#define KC_MRKE TT(2)
#define KC_NUME TT(3)
#define KC_FNCE TT(4)
#define KC_SFE MO(5)

#define KC_TOJ TO(6)
#define KC_SJP LT(7,KC_SPC)
#define KC_MRKJ TT(8)
#define KC_NUMJ TT(9)
#define KC_FNCJ TT(10)
#define KC_SFJ MO(11)

//IME change
#define KC_JTOE D_JTOE
#define KC_ETOJ D_ETOJ
#define KC_CHIME LALT(KC_GRAVE)

//diphthong
#define KC_DUU DI_UU
#define KC_DAI DI_AI
#define KC_DOU DI_OU
#define KC_DEI DI_EI
#define KC_DUI DI_UI
#define KC_DAU DI_AU
#define KC_DOI DI_OI
#define KC_DIU DI_IU
#define KC_DAA DI_AA
#define KC_DAE DI_AE
#define KC_DOO DI_OO
#define KC_DOA DI_OA
#define KC_DII DI_II
#define KC_DIA DI_IA
#define KC_DEA DI_EA
#define KC_DIO DI_IO

//-n
#define KC_DUNN DN_UNN
#define KC_DANN DN_ANN
#define KC_DONN DN_ONN
#define KC_DINN DN_INN
#define KC_DENN DN_ENN

//DN_WO
#define KC_DWO DN_WO
#define KC_DTSU DN_TSU
#define KC_DNN DN_NN

//special extension
#define KC_SKK SE_KK
#define KC_SKT SE_KT
#define KC_SKN SE_KN
#define KC_SKS SE_KS
#define KC_SKM SE_KM
#define KC_SKR SE_KR
#define KC_SKB SE_KB
#define KC_SSK SE_SK
#define KC_SST SE_ST
#define KC_SSN SE_SN
#define KC_SSS SE_SS
#define KC_SSM SE_SM
#define KC_SSR SE_SR
#define KC_SSB SE_SB
#define KC_STK SE_TK
#define KC_STT SE_TT
#define KC_STN SE_TN
#define KC_STS SE_TS
#define KC_STM SE_TM
#define KC_STR SE_TR
#define KC_STB SE_TB
#define KC_SHK SE_HK
#define KC_SHT SE_HT
#define KC_SHN SE_HN
#define KC_SHS SE_HS
#define KC_HMS SE_HM
#define KC_SHR SE_HR
#define KC_SHB SE_HB
#define KC_SMK SE_MK
#define KC_SMT SE_MT
#define KC_SMN SE_MN
#define KC_SMS SE_MS
#define KC_SMM SE_MM
#define KC_SMR SE_MR
#define KC_SMB SE_MB
#define KC_SNK SE_NK
#define KC_SNT SE_NT
#define KC_SNN SE_NN
#define KC_SNS SE_NS
#define KC_SNM SE_NM
#define KC_SNR SE_NR
#define KC_SNB SE_NB
#define KC_SYK SE_YK
#define KC_SYT SE_YT
#define KC_SYS SE_YS
#define KC_SYR SE_YR
#define KC_SYB SE_YB

//mark
#define KC_DBRCT DM_BRCT
#define KC_DBRCTL DM_BRCTL
#define KC_DBRCTM DM_BRCTM
#define KC_SSTT DM_SSTT

//function
#define KC_DRNSH DF_RNMSH

//macros for numpad
#define KC_NP0 M(0)
#define KC_NP1 M(1)
#define KC_NP2 M(2)
#define KC_NP3 M(3)
#define KC_NP4 M(4)
#define KC_NP5 M(5)
#define KC_NP6 M(6)
#define KC_NP7 M(7)
#define KC_NP8 M(8)
#define KC_NP9 M(9)
#define KC_NPDOT M(10)
#define KC_NPEQL M(11)
#define KC_NPPLS M(12)
#define KC_NPMNS M(13)
#define KC_NPAST M(14)
#define KC_NPSLS M(15)

//keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //English base keymap based on dvorak
	[_MDVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,COMM, M  , R  , P  , Y                 , F  , G  , C  , DOT, L  ,RSFT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , O  , E  , U  , I                 , J  , H  , T  , N  , S  , D  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI, B  ,QUOT, X  , K  , DEL, NO      ,ETOJ,BSPC, V  , Z  , Q  ,W   ,ENT ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,FNCE, SEN         ,ENT ,MRKE ,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  //shifted English keymap
    [_SMDVORAK] = LAYOUT(
  //,-------+--------+--------+--------+--------+--------.                      ,---------+---------+---------+---------+---------+--------.
     KC____ , KC____ , KC____ , KC____ , KC____ , KC____                        , KC____  , KC____  , KC____  , KC____  , KC____  , KC____ ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC____ , KC_SCLN, S(KC_M), S(KC_R), S(KC_P), S(KC_Y)                       , S(KC_F) , S(KC_G) , S(KC_C) , KC_COLN , S(KC_L) , KC____ ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC____ , S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I)                       , S(KC_J) , S(KC_H) , S(KC_T) , S(KC_N) , S(KC_S) , S(KC_D),
  //|-------+--------+--------+--------+--------+--------+--------.    ,--------|---------+---------+---------+---------+---------+--------|
     KC____ , S(KC_B), KC_DQT , S(KC_X), S(KC_K), KC____ ,KC_CHIME     ,KC_CHIME, KC____  , S(KC_V) , S(KC_Z) , S(KC_Q) , S(KC_W) , KC____ ,
  //`-------+--------+--------+--------+--------+--------+--------/    \--------+---------+---------+---------+---------+---------+--------'
                                         KC____ , KC_FNCE, KC_SEN      , KC____ , KC_NUME , KC____
  //                                    `-------+--------+--------'    `--------+---------+--------'
  ),
  

  //mark (symbol) keymap for english (IME: off)
    [_MARKE] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC_COLN   , KC_SCLN   , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_QUOT   , KC_LCBR   , KC_LBRC   , KC_LPRN   , KC_AMPR                               , KC_EQL    , KC_EXLM   , KC_BSLS   , KC_CIRC   , KC_MINS   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_DQT	  , KC_DBRCTM , KC_DBRCTL , KC_DBRCT  , KC_LT                                 , KC_SSTT   , KC_QUES   , KC_AT     , KC_TILD   , KC_UNDS   , KC_PIPE   ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC_LCBR   , KC_RBRC   , KC_RPRN   , KC_GT	    , KC_TOE         , KC_ETOJ  , KC_GRV    , KC_DLR    , KC_HASH   , KC_PERC   , KC_SLSH   , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  KC____    , KC_FNCE    , KC_NO          , KC____   , KC_TOE    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //number and allows keymap for english (IME: off)
    [_NMALE] = LAYOUT_kc(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     ___    , ___       , ___       , SCLN      , COLN      , ___                                   , BSLS      , CIRC      , NPSLS     , NPAST     , COMM      , NLCK      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , DLR       , HOME      , UP        , END       , AMPR                                  , EQL       , NP7       , NP8       , NP9       , NPMNS     , ___       ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , LPRN  	  , LEFT      , DOWN      , RGHT      , RPRN                                  , NP0       , NP4       , NP5       , NP6       , NPPLS     , CALC      ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , ___       , PGUP      , SPC       , PGDN      , DEL	      , TOE            , ETOJ     , BSPC      , NP1       , NP2       , NP3       , NPDOT     , ___       ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  ___       , FNCE      , TOE            , NP0      , MRKE      , ___
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //function keymap for english (IME: off)
    [_FUNCE] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC_F1     , KC____    , KC_INS    , KC_PSCR   , KC_NLCK                               , KC_MUTE   , KC_VOLD   , KC_VOLU   , A(KC_G)   , A(KC_S)   , LCA(KC_DEL),
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Y)   , G(KC_R)   , KC_D      , C(KC_F)   , KC_DRNSH                              , A(KC_M)   , KC_HOME   , KC_UP     , KC_END    , C(KC_P)   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_A)   , C(KC_S)   , C(KC_D)   , A(KC_A)   , A(KC_H)                               , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO     ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Z)   , C(KC_X)   , C(KC_C)   , C(KC_V)   , KC_SPC	  , KC_TOE         , KC_ETOJ  , KC____    , KC_PGUP   , KC_NO     , KC_PGDN   , KC_NO     , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  KC____    , KC_TOE    , KC_NO          , KC_ENT   , KC_SFE    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //shifted function keymap for english (IME: off)
    [_SFUNCE] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(S(KC_Z)), KC____    , KC____    , C(KC_H)   , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____	  , KC_TOE         , KC_ETOJ  , KC____    , KC____    , KC____    , KC____   , KC____    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  KC____    , KC_TOE    , KC_NO          , KC____   , KC_SFE    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Japanese base keymap based on sky touch
    [_MSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,COMM, H  , R  , M  , W                 , DUU, DAI, DOU, DOT, DEI,RSFT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, Y  , S  , T  , K  , N                 , U  , A  , O  , I  , E  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI, B  , L  , DNN,DWO, DEL,JTOE     , NO ,BSPC, DAU, DOI, DII, DEA,ENT ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,FNCJ, SJP         ,ENT ,MRKJ,LALT
  //                  `----+----+----'        `----+----+----'
  ),
  
  //shifted Japanese keymap
    [_SMSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ___ , ___, ___, ___, ___, ___               , ___, ___, ___, ___, ___, ___,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ ,SCLN, V  , J  , F  , Q                 , DUI, DAA, DOO,COLN, DIU,___ ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ , B  , Z  , D  , G  , P                 ,DUNN,DANN,DONN,DINN,DENN,SLSH,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ___ ,___ , C  ,DTSU, ___, ___,CHIME    ,CHIME,___, DAE, DOA, DIA, DIO,___ ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       ___ ,FNCJ, SJP         ,___ ,NUMJ,___
  //                  `----+----+----'        `----+----+----'
  ),

  //mark (symbol) keymap for Japanese (IME: on)
    [_MARKJ] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC_COLN   , KC_SCLN   , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_QUOT   , KC_LCBR   , KC_LBRC   , KC_LPRN   , KC_AMPR                               , KC_EQL    , KC_EXLM   , KC_BSLS   , KC_CIRC   , KC_MINS   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_DQT 	  , KC_DBRCTM , KC_DBRCTL , KC_DBRCT  , KC_LT                                 , KC_SSTT   , KC_QUES   , KC_AT     , KC_TILD   , KC_UNDS   , KC_PIPE   ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC_LCBR   , KC_RBRC   , KC_RPRN   , KC_GT	    , KC_JTOE        ,KC_TOJ    , KC_GRV    , KC_DLR    , KC_HASH   , KC_PERC   , KC_SLSH   , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                   KC____   , KC_FNCJ   , KC_NO          ,KC____    , KC_TOJ    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //number and allows keymap for Japanese (IME: on)
    [_NMALJ] = LAYOUT_kc(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     ___    , ___       , ___       , SCLN      , COLN      , ___                                   , BSLS      , CIRC      , NPSLS     , NPAST     , COMM      , NLCK      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , DLR       , HOME      , UP        , END       , AMPR                                  , EQL       , NP7       , NP8       , NP9       , NPMNS     , ___       ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , LPRN  	  , LEFT      , DOWN      , RGHT      , RPRN                                  , NP0       , NP4       , NP5       , NP6       , NPPLS     , CALC      ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , ___       , PGUP      , SPC       , PGDN      , DEL	      , JTOE           , TOJ      , BSPC      , NP1       , NP2       , NP3       , NPDOT     , ___       ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  ___       , FNCJ      , TOJ            , NP0      , MRKJ       , ___
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //function keymap for Japanese (IME: on)
    [_FUNCJ] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC_F1     , KC_NO     , KC_INS    , KC_PSCR   , KC_NLCK                               , KC_MUTE   , KC_VOLD   , KC_VOLU   , A(KC_G)   , A(KC_S)   , LCA(KC_DEL),
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Y)   , G(KC_R)   , KC_D      , C(KC_F)   , KC_DRNSH                              , A(KC_M)   , KC_HOME   , KC_UP     , KC_END    , C(KC_P)   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_A)   , C(KC_S)   , C(KC_D)   , A(KC_A)   , A(KC_H)                               , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO     ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Z)   , C(KC_X)   , C(KC_C)   , C(KC_V)   , KC_SPC	  , KC_JTOE        , KC_TOJ   , KC____    , KC_PGUP   , KC_NO     , KC_PGDN   , KC_NO     , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  KC____    , KC_TOJ    , KC_NO          , KC_ENT   , KC_SFJ    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //shifted function keymap for Japanese (IME: on)
    [_SFUNCJ] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(S(KC_Z)), KC____    , KC____    , C(KC_H)   , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____	  , KC_JTOE        , KC_TOJ   , KC____    , KC____    , KC____    , KC____   , KC____    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
                                                  KC____    , KC_TOJ    , KC_NO          , KC____   , KC_SFJ    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

};

//macro
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  //macros for diphthong
    case DI_UU:
      if (record->event.pressed) {
        // when keycode DI_UU is pressed
        SEND_STRING("uu");
      }
      return false;
      break;
    case DI_AI:
      if (record->event.pressed) {
        // when keycode DI_AI is pressed
        SEND_STRING("ai");
      }
      return false;
      break;
    case DI_OU:
      if (record->event.pressed) {
        // when keycode DI_OU is pressed
        SEND_STRING("ou");
      }
      return false;
      break;
    case DI_EI:
      if (record->event.pressed) {
        // when keycode DI_EI is pressed
        SEND_STRING("ei");
      }
      return false;
      break;
    case DI_UI:
      if (record->event.pressed) {
        // when keycode DI_UI is pressed
        SEND_STRING("ui");
      }
      return false;
      break;
    case DI_AU:
      if (record->event.pressed) {
        // when keycode DI_AU is pressed
        SEND_STRING("au");
      }
      return false;
      break;
    case DI_OI:
      if (record->event.pressed) {
        // when keycode DI_OI is pressed
        SEND_STRING("oi");
      }
      return false;
      break;
    case DI_IU:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("iu");
      }
      return false;
    case DI_AE:
      if (record->event.pressed) {
        // when keycode DI_AE is pressed
        SEND_STRING("ae");
      }
      return false;
      break;
    case DI_AA:
      if (record->event.pressed) {
        // when keycode DI_AA is pressed
        SEND_STRING("aa");
      }
      return false;
      break;
    case DI_OA:
      if (record->event.pressed) {
        // when keycode DI_OA is pressed
        SEND_STRING("oa");
      }
      return false;
      break;
    case DI_OO:
      if (record->event.pressed) {
        // when keycode DI_OO is pressed
        SEND_STRING("oo");
      }
      return false;
      break;
    case DI_IA:
      if (record->event.pressed) {
        // when keycode DI_IA is pressed
        SEND_STRING("ia");
      }
      return false;
      break;
    case DI_II:
      if (record->event.pressed) {
        // when keycode DI_II is pressed
        SEND_STRING("ii");
      }
      return false;
      break;
    case DI_EA:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("ea");
      }
      return false;
      break;
    case DI_IO:
      if (record->event.pressed) {
        // when keycode DI_IO is pressed
        SEND_STRING("io");
      }
      return false;
      break;
  //macros for -n
    case DN_UNN:
      if (record->event.pressed) {
        // when keycode DI_UNN is pressed
        SEND_STRING("unn");
      }
      return false;
      break;
    case DN_ANN:
      if (record->event.pressed) {
        // when keycode DI_ANN is pressed
        SEND_STRING("ann");
      }
      return false;
      break;
    case DN_ONN:
      if (record->event.pressed) {
        // when keycode DI_ONN is pressed
        SEND_STRING("onn");
      }
      return false;
      break;
    case DN_INN:
      if (record->event.pressed) {
        // when keycode DI_INN is pressed
        SEND_STRING("inn");
      }
      return false;
      break;
    case DN_ENN:
      if (record->event.pressed) {
        // when keycode DI_ENN is pressed
        SEND_STRING("enn");
      }
      return false;
      break;
    case DN_WO:
      if (record->event.pressed) {
        // when keycode DI_WO is pressed
        SEND_STRING("wo");
      }
      return false;
      break;
    case DN_TSU:
      if (record->event.pressed) {
        // when keycode DI_TSU is pressed
        SEND_STRING("ltsu");
      }
      return false;
      break;
    case DN_NN:
      if (record->event.pressed) {
        // when keycode DN_NN is pressed
        SEND_STRING("nn");
      }
      return false;
      break;
    //macros for marks
    case DM_BRCT:
      if (record->event.pressed) {
        // when keycode DM_BRCT is pressed
        SEND_STRING("()"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case DM_BRCTL:
      if (record->event.pressed) {
        // when keycode DM_BRCTL is pressed
        SEND_STRING("[]"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case DM_BRCTM:
      if (record->event.pressed) {
        // when keycode DM_BRCTM is pressed
        SEND_STRING("{}"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case DM_SSTT:
      if (record->event.pressed) {
        // when keycode DM_SSTT is pressed
        SEND_STRING("<-");
      }
      return false;
      break;
  //macros for function
    case DF_RNMSH:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        SEND_STRING(SS_LALT("ohr"));
      }
      return false;
      break;
  //macros for layer change
    case D_JTOE:
      if (record->event.pressed) {
        // when keycode D_JTOE is pressed
        SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)));
        layer_clear();
        layer_on(0);
      }
      return false;
      break;
    case D_ETOJ:
      if (record->event.pressed) {
        // when keycode D_ETOJ is pressed
        SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)));
        layer_clear();
        layer_on(6);
      }
      return false;
      break;
  }
  return true;
};

//macros for numpad
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 0:
                return MACRO(T(NLCK), T(P0), T(NLCK), END);
            case 1:
                return MACRO(T(NLCK), T(P1), T(NLCK), END);
            case 2:
                return MACRO(T(NLCK), T(P2), T(NLCK), END);
            case 3:
                return MACRO(T(NLCK), T(P3), T(NLCK), END);
            case 4:
                return MACRO(T(NLCK), T(P4), T(NLCK), END);
            case 5:
                return MACRO(T(NLCK), T(P5), T(NLCK), END);
            case 6:
                return MACRO(T(NLCK), T(P6), T(NLCK), END);
            case 7:
                return MACRO(T(NLCK), T(P7), T(NLCK), END);
            case 8:
                return MACRO(T(NLCK), T(P8), T(NLCK), END);
            case 9:
                return MACRO(T(NLCK), T(P9), T(NLCK), END);
            case 10:
                return MACRO(T(NLCK), T(PDOT), T(NLCK), END);
            case 11:
                return MACRO(T(NLCK), T(PEQL), T(NLCK), END);
            case 12:
                return MACRO(T(NLCK), T(PPLS), T(NLCK), END);
            case 13:
                return MACRO(T(NLCK), T(PMNS), T(NLCK), END);
            case 14:
                return MACRO(T(NLCK), T(PAST), T(NLCK), END);
            case 15:
                return MACRO(T(NLCK), T(PSLS), T(NLCK), END);
        }
    }
    return MACRO_NONE;
};