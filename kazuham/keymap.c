//#include "iris.h"
//#include "action_layer.h"
//#include "eeconfig.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//keycode shorthands
#define KC____  KC_TRNS // three underscores "___" for transparent

#define KC_SEN  MO(1)
#define KC_SJP  MO(3)
//#define KC_MARK TT(4)
//#define KC_NMAL TO(5)

//layer shorthands
#define _MDVORAK 0
#define _SMDVORAK 1
#define _MSKYTOUCH 2
#define _SMSKYTOUCH 3
//#define _MARK 4
//#define _NMAL 5

enum {
//	SFT_LCK //tapdance declarations
    MDVORAK = 0,
    SMDVORAK,
    MSKYTOUCH,
    SMSKYTOUCH,
//    MARK, //
 //   NMAL, //

 //   JTOE,
 //   ETOJ,

    DI_UU,
    DI_AI,
    DI_OU,
    DI_EI,
    DI_UI,
    DI_AU,
    DI_OI,
    DI_IU,

    DN_UNN,
    DN_ANN,
    DN_ONN,
    DN_INN,
    DN_ENN,

    DM_BRCT,
    DM_BRCTL,

    D_MID
};

//diphthong
#define KC_JTOE LT(0,KC_MHEN)
#define KC_ETOJ LT(2,KC_HENK)
//#define KC_ETOJ KC_HENK | DF(2)

#define KC_DUU DI_UU
#define KC_DAI DI_AI
#define KC_DOU DI_OU
#define KC_DEI DI_EI
#define KC_DUI DI_UI
#define KC_DAU DI_AU
#define KC_DOI DI_OI
#define KC_DIU DI_IU

#define KC_DUNN DN_UNN
#define KC_DANN DN_ANN
#define KC_DONN DN_ONN
#define KC_DINN DN_INN
#define KC_DENN DN_ENN

#define KC_DBRCT DM_BRCT
#define KC_DBRCTL DM_BRCTL

#define KC_DMID D_MID

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_MDVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,COMM, M  , R  , P  , Y                 , F  , G  , C  , DOT, L  ,HOME,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , O  , E  , U  , I                 , J  , H  , T  , N  , S  , D  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,LGUI, B  , X  , K  , DEL,JTOE     ,ETOJ,BSPC, V  , Z  , Q  ,W   ,END ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL, SPC, SEN         ,___, ENT, ___ 
  //                  `----+----+----'        `----+----+----'
  ),

    [_SMDVORAK] = LAYOUT(
  //,-------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
     KC_ESC , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6                        , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //|-------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_TAB , KC_SCLN, S(KC_M), S(KC_R), S(KC_P), S(KC_Y)                      , S(KC_F), S(KC_G), S(KC_C), KC_COLN, S(KC_L), KC_HOME,
  //|-------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_LSFT, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I)                      , S(KC_J), S(KC_H), S(KC_T), S(KC_N), S(KC_S), S(KC_D),
  //|-------+--------+--------+--------+--------+--------+--------.    ,-------|--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, S(KC_B), S(KC_X), S(KC_K), KC_DEL , KC_JTOE     ,KC_ETOJ, KC_BSPC, S(KC_V), S(KC_Z), S(KC_Q), S(KC_W), KC_END ,
  //`-------+--------+--------+--------+--------+--------+--------/    \-------+--------+--------+--------+--------+--------+--------'
                                         KC_LCTL, KC_SPC , KC_SEN      ,KC____ , KC_ENT ,KC____
  //                                    `-------+--------+--------'    `-------+--------+--------'
  ),
   
    [_MSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,COMM, H  , R  , M  , W                 , DUU, DAI, DOU, DOT, DEI,HOME,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, Y  , S  , T  , K  , N                 , U  , A  , O  , I  , E  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,LGUI, B  , W  , X  , DEL,JTOE     ,ETOJ,BSPC,DANN,DONN,DINN,DENN,END ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL, SPC, SJP         ,___, ENT, ___ 
  //                  `----+----+----'        `----+----+----'
  ),
    
    [_SMSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,SCLN, V  , J  , F  , Q                 , DUI, DAU, DOI,COLN, DIU,HOME,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, B  , Z  , D  , G  , P                 ,DUNN,DANN,DONN,DINN,DENN,DMID,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,LGUI, B  , W  , X  , DEL,JTOE     ,ETOJ,BSPC,DANN,DONN,DINN,DENN,END ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL, SPC, SJP         ,___, ENT, ___ 
  //                  `----+----+----'        `----+----+----'
  ),
   
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
//    case JTOE:
//      if (record->event.pressed) {
//        // when keycode JTOE is pressed
//        DF(0);
//        SEND_STRING(SS_TAP(X_MHEN));
//      } else {
//        // when keycode JTOE is released
//      }
//      return true;
//      break;
        case DI_UU:
      if (record->event.pressed) {
        // when keycode DI_AI is pressed
        SEND_STRING("uu");
      } else {
        // when keycode DI_AI is released
      }
      return true;
      break;
    case DI_AI:
      if (record->event.pressed) {
        // when keycode DI_AI is pressed
        SEND_STRING("ai");
      } else {
        // when keycode DI_AI is released
      }
      return true;
      break;
    case DI_OU:
      if (record->event.pressed) {
        // when keycode DI_OU is pressed
        SEND_STRING("ou");
      } else {
        // when keycode DI_OU is released
      }
      return true;
      break;
    case DI_EI:
      if (record->event.pressed) {
        // when keycode DI_EI is pressed
        SEND_STRING("ei");
      } else {
        // when keycode DI_EI is released
      }
      return true;
      break;
    case DI_UI:
      if (record->event.pressed) {
        // when keycode DI_UI is pressed
        SEND_STRING("ui");
      } else {
        // when keycode DI_UI is released
      }
      return true;
      break;
    case DI_AU:
      if (record->event.pressed) {
        // when keycode DI_AU is pressed
        SEND_STRING("au");
      } else {
        // when keycode DI_AU is released
      }
      return true;
      break;
    case DI_OI:
      if (record->event.pressed) {
        // when keycode DI_OI is pressed
        SEND_STRING("oi");
      } else {
        // when keycode DI_OI is released
      }
      return true;
      break;
    case DI_IU:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("iu");
      } else {
        // when keycode DI_IU is released
      }
      return true;
      break;
    case DN_UNN:
      if (record->event.pressed) {
        // when keycode DI_UNN is pressed
        SEND_STRING("unn");
      } else {
        // when keycode DI_UNN is released
      }
      return true;
      break;
    case DN_ANN:
      if (record->event.pressed) {
        // when keycode DI_ANN is pressed
        SEND_STRING("ann");
      } else {
        // when keycode DI_ANN is released
      }
      return true;
      break;
    case DN_ONN:
      if (record->event.pressed) {
        // when keycode DI_ONN is pressed
        SEND_STRING("onn");
      } else {
        // when keycode DI_ONN is released
      }
      return true;
      break;
    case DN_INN:
      if (record->event.pressed) {
        // when keycode DI_INN is pressed
        SEND_STRING("inn");
      } else {
        // when keycode DI_INN is released
      }
      return true;
      break;
    case DN_ENN:
      if (record->event.pressed) {
        // when keycode DI_ENN is pressed
        SEND_STRING("enn");
      } else {
        // when keycode DI_ENN is released
      }
      return true;
      break;
    case DM_BRCT:
      if (record->event.pressed) {
        // when keycode DM_BRCT is pressed
        SEND_STRING("()"SS_TAP(X_LEFT));
      } else {
        // when keycode DM_BRCT is released
      }
      return true;
      break;
    case DM_BRCTL:
      if (record->event.pressed) {
        // when keycode DM_BRCTL is pressed
        SEND_STRING("[]"SS_TAP(X_LEFT));
      } else {
        // when keycode DM_BRCTL is released
      }
      return true;
      break;
    case D_MID:
      if (record->event.pressed) {
        // when keycode D_MID is pressed
        SEND_STRING("・");
      } else {
        // when keycode D_MID is released
      }
      return true;
      break;
  }
  return true;
}