begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  solKbd.h --  *  *	remade by A.Fujita, DEC-20-1992  */
end_comment

begin_include
include|#
directive|include
file|<luna68k/dev/kbio.h>
end_include

begin_define
define|#
directive|define
name|XK_KATAKANA
end_define

begin_include
include|#
directive|include
file|"keysym.h"
end_include

begin_define
define|#
directive|define
name|KS_KANA
value|0x1
end_define

begin_define
define|#
directive|define
name|KS_CTRL_L
value|0x2
end_define

begin_define
define|#
directive|define
name|KS_CTRL_R
value|0x4
end_define

begin_define
define|#
directive|define
name|KS_META_L
value|0x8
end_define

begin_define
define|#
directive|define
name|KS_META_R
value|0x10
end_define

begin_define
define|#
directive|define
name|KS_ALT_L
value|0x20
end_define

begin_define
define|#
directive|define
name|KS_ALT_R
value|0x40
end_define

begin_define
define|#
directive|define
name|KS_SUPER_L
value|0x80
end_define

begin_define
define|#
directive|define
name|KS_SUPER_R
value|0x100
end_define

begin_define
define|#
directive|define
name|KS_HYPER_L
value|0x200
end_define

begin_define
define|#
directive|define
name|KS_HYPER_R
value|0x400
end_define

begin_define
define|#
directive|define
name|KANA_KEY
value|11
end_define

begin_define
define|#
directive|define
name|CAPSLOCK_KEY
value|14
end_define

begin_define
define|#
directive|define
name|AREPBUFSZ
value|32
end_define

begin_function_decl
specifier|extern
name|int
name|solKbdProc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|solMouseProc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAXEVENTS
value|1024
end_define

begin_define
define|#
directive|define
name|KEYCODE_TB_SIZE
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|_solDevPrvRec
block|{
comment|/* device control */
name|int
name|fd
decl_stmt|;
name|int
name|kbd_type
decl_stmt|;
name|int
name|key_state
decl_stmt|;
comment|/* kana key status */
name|int
name|flags
decl_stmt|;
name|int
name|num
decl_stmt|;
comment|/* ascii control */
name|int
name|offset
decl_stmt|;
name|KeybdCtrl
name|keybdCtrl
decl_stmt|;
name|char
name|semiEncodeDef
index|[
name|KEYCODE_TB_SIZE
index|]
decl_stmt|;
name|char
name|semiEncode
index|[
name|KEYCODE_TB_SIZE
index|]
decl_stmt|;
name|KeyCode
name|minkey
decl_stmt|,
name|maxkey
decl_stmt|;
comment|/* mouse control */
name|int
name|mouse_state
decl_stmt|;
block|}
name|solDevPrv
operator|,
typedef|*
name|solDevPrvPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_solDevEvtRec
block|{
name|u_int
name|type
decl_stmt|;
union|union
block|{
name|u_int
name|p
decl_stmt|;
name|u_char
name|key
decl_stmt|;
struct|struct
block|{
name|u_char
name|state
decl_stmt|;
name|char
name|x_delta
decl_stmt|;
name|char
name|y_delta
decl_stmt|;
block|}
name|ms
struct|;
block|}
name|u
union|;
block|}
name|solDevEvt
operator|,
typedef|*
name|solDevEvtPtr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|key_code
value|u.key
end_define

begin_define
define|#
directive|define
name|ms_state
value|u.ms.state
end_define

begin_define
define|#
directive|define
name|ms_x_delta
value|u.ms.x_delta
end_define

begin_define
define|#
directive|define
name|ms_y_delta
value|u.ms.y_delta
end_define

begin_define
define|#
directive|define
name|EvtKey
value|1
end_define

begin_define
define|#
directive|define
name|EvtMouse
value|2
end_define

begin_define
define|#
directive|define
name|BUTTON_L
value|4
end_define

begin_define
define|#
directive|define
name|BUTTON_M
value|2
end_define

begin_define
define|#
directive|define
name|BUTTON_R
value|1
end_define

end_unit

