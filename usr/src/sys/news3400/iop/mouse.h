begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: mouse.h,v 4.300 91/06/09 06:42:56 root Rel41 $ SONY  *  *	@(#)mouse.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MOUSE__
end_ifndef

begin_define
define|#
directive|define
name|__MOUSE__
value|1
end_define

begin_comment
comment|/*  * mouse register structure definition.  */
end_comment

begin_comment
comment|/*  * mouse data (mouse X, Y coordinates and its button status)  */
end_comment

begin_struct
struct|struct
name|ms_data
block|{
name|int
name|md_sw
decl_stmt|;
comment|/* mouse button */
define|#
directive|define
name|MS_BUTNL
value|0x04
define|#
directive|define
name|MS_BUTNM
value|0x02
define|#
directive|define
name|MS_BUTNR
value|0x01
name|int
name|md_x
decl_stmt|;
comment|/* x coordinate */
name|int
name|md_y
decl_stmt|;
comment|/* y coordinate */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ms_coord
block|{
name|int
name|mc_x
decl_stmt|;
comment|/* x coordinate */
name|int
name|mc_y
decl_stmt|;
comment|/* y coordinate */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ms_range
block|{
name|struct
name|ms_coord
name|mr_min
decl_stmt|;
comment|/* upper left */
name|struct
name|ms_coord
name|mr_max
decl_stmt|;
comment|/* lower right */
block|}
struct|;
end_struct

begin_comment
comment|/*  * mouse event report  *	event report is queued when mouse is put in event mode  *	by using MIOC SETEM ioctl()  */
end_comment

begin_struct
struct|struct
name|ms_event
block|{
name|struct
name|ms_data
name|mse_data
decl_stmt|;
comment|/* mouse X, Y and button status */
name|char
name|mse_trig
decl_stmt|;
comment|/* trigger that caused this event */
define|#
directive|define
name|MSE_MOTION
value|0
comment|/* mouse movement */
define|#
directive|define
name|MSE_BUTTON
value|1
comment|/* mouse buttons */
define|#
directive|define
name|MSE_KEY
value|2
comment|/* keyboard keys */
name|char
name|mse_dir
decl_stmt|;
comment|/* key or button direction */
define|#
directive|define
name|MSE_DOWN
value|0
comment|/* down */
define|#
directive|define
name|MSE_UP
value|1
comment|/* up */
define|#
directive|define
name|MSE_UNKOWN
value|2
comment|/* unkown */
name|char
name|mse_code
decl_stmt|;
comment|/* key or button code */
define|#
directive|define
name|MSE_BUTNR
value|0
comment|/* right button */
define|#
directive|define
name|MSE_BUTNM
value|1
comment|/* middle button */
define|#
directive|define
name|MSE_BUTNL
value|2
comment|/* left button */
name|char
name|mse_inval
decl_stmt|;
comment|/* for key code, see below */
name|struct
name|timeval
name|mse_time
decl_stmt|;
comment|/* time when this event occurred */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ms_queue
block|{
name|int
name|mq_head
decl_stmt|;
name|int
name|mq_tail
decl_stmt|;
define|#
directive|define
name|MS_MAXREPORT
value|170
name|struct
name|ms_event
name|mq_queue
index|[
name|MS_MAXREPORT
index|]
decl_stmt|;
name|int
name|dummy
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* strct ms_param:  *	when mouse is moved more than mp_delta, amount that exceeds  *	the mp_delta is maginified by mp_mag(>0)  */
end_comment

begin_struct
struct|struct
name|ms_param
block|{
name|int
name|mp_delta
decl_stmt|;
comment|/* threshold for maginification */
name|int
name|mp_mag
decl_stmt|;
comment|/* magifying factor */
block|}
struct|;
end_struct

begin_comment
comment|/* meaning of ms_eventmask */
end_comment

begin_define
define|#
directive|define
name|MS_EMEVENT
value|0x80
end_define

begin_comment
comment|/* 1 -> event mode */
end_comment

begin_define
define|#
directive|define
name|MS_EMKEY
value|0x40
end_define

begin_comment
comment|/* keyboard key changes -> event */
end_comment

begin_comment
comment|/* WARNING: use of MS_EMCORD[XY] is no recomended 		 *	MS_EMCORD[XY] will disappear shortly 		 */
end_comment

begin_define
define|#
directive|define
name|MS_EMCORDY
value|0x20
end_define

begin_comment
comment|/* coordinate y changes -> event */
end_comment

begin_define
define|#
directive|define
name|MS_EMCORDX
value|0x10
end_define

begin_comment
comment|/* coordinate x changes -> event */
end_comment

begin_define
define|#
directive|define
name|MS_EMMOTION
value|0x10
end_define

begin_comment
comment|/* coordinates changes -> event */
end_comment

begin_define
define|#
directive|define
name|MS_EMBUTNL
value|0x04
end_define

begin_comment
comment|/* left button changes -> event */
end_comment

begin_define
define|#
directive|define
name|MS_EMBUTNM
value|0x02
end_define

begin_comment
comment|/* mid button changes -> event */
end_comment

begin_define
define|#
directive|define
name|MS_EMBUTNR
value|0x01
end_define

begin_comment
comment|/* right button changes -> event */
end_comment

begin_comment
comment|/*  * Key Code  */
end_comment

begin_define
define|#
directive|define
name|KEY_A
value|41
end_define

begin_define
define|#
directive|define
name|KEY_B
value|59
end_define

begin_define
define|#
directive|define
name|KEY_C
value|57
end_define

begin_define
define|#
directive|define
name|KEY_D
value|43
end_define

begin_define
define|#
directive|define
name|KEY_E
value|29
end_define

begin_define
define|#
directive|define
name|KEY_F
value|44
end_define

begin_define
define|#
directive|define
name|KEY_G
value|45
end_define

begin_define
define|#
directive|define
name|KEY_H
value|46
end_define

begin_define
define|#
directive|define
name|KEY_I
value|34
end_define

begin_define
define|#
directive|define
name|KEY_J
value|47
end_define

begin_define
define|#
directive|define
name|KEY_K
value|48
end_define

begin_define
define|#
directive|define
name|KEY_L
value|49
end_define

begin_define
define|#
directive|define
name|KEY_M
value|61
end_define

begin_define
define|#
directive|define
name|KEY_N
value|60
end_define

begin_define
define|#
directive|define
name|KEY_O
value|35
end_define

begin_define
define|#
directive|define
name|KEY_P
value|36
end_define

begin_define
define|#
directive|define
name|KEY_Q
value|27
end_define

begin_define
define|#
directive|define
name|KEY_R
value|30
end_define

begin_define
define|#
directive|define
name|KEY_S
value|42
end_define

begin_define
define|#
directive|define
name|KEY_T
value|31
end_define

begin_define
define|#
directive|define
name|KEY_U
value|33
end_define

begin_define
define|#
directive|define
name|KEY_V
value|58
end_define

begin_define
define|#
directive|define
name|KEY_W
value|28
end_define

begin_define
define|#
directive|define
name|KEY_X
value|56
end_define

begin_define
define|#
directive|define
name|KEY_Y
value|32
end_define

begin_define
define|#
directive|define
name|KEY_Z
value|55
end_define

begin_define
define|#
directive|define
name|KEY_0
value|21
end_define

begin_define
define|#
directive|define
name|KEY_1
value|12
end_define

begin_define
define|#
directive|define
name|KEY_2
value|13
end_define

begin_define
define|#
directive|define
name|KEY_3
value|14
end_define

begin_define
define|#
directive|define
name|KEY_4
value|15
end_define

begin_define
define|#
directive|define
name|KEY_5
value|16
end_define

begin_define
define|#
directive|define
name|KEY_6
value|17
end_define

begin_define
define|#
directive|define
name|KEY_7
value|18
end_define

begin_define
define|#
directive|define
name|KEY_8
value|19
end_define

begin_define
define|#
directive|define
name|KEY_9
value|20
end_define

begin_define
define|#
directive|define
name|KEY_MINUS
value|22
end_define

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|KEY_EQUAL
value|23
end_define

begin_comment
comment|/* = */
end_comment

begin_define
define|#
directive|define
name|KEY_YEN
value|24
end_define

begin_comment
comment|/* \ */
end_comment

begin_define
define|#
directive|define
name|KEY_BRA
value|37
end_define

begin_comment
comment|/* [ */
end_comment

begin_define
define|#
directive|define
name|KEY_KET
value|38
end_define

begin_comment
comment|/* ] */
end_comment

begin_define
define|#
directive|define
name|KEY_SEMICOL
value|50
end_define

begin_comment
comment|/* ; */
end_comment

begin_define
define|#
directive|define
name|KEY_SQUOTE
value|51
end_define

begin_comment
comment|/* ' */
end_comment

begin_define
define|#
directive|define
name|KEY_BQUOTE
value|52
end_define

begin_comment
comment|/* ` */
end_comment

begin_define
define|#
directive|define
name|KEY_COMMA
value|62
end_define

begin_comment
comment|/* , */
end_comment

begin_define
define|#
directive|define
name|KEY_PERIOD
value|63
end_define

begin_comment
comment|/* . */
end_comment

begin_define
define|#
directive|define
name|KEY_SLASH
value|64
end_define

begin_comment
comment|/* / */
end_comment

begin_define
define|#
directive|define
name|KEY_RO
value|65
end_define

begin_comment
comment|/* 'RO' (katakana) */
end_comment

begin_define
define|#
directive|define
name|KEY_ESC
value|11
end_define

begin_define
define|#
directive|define
name|KEY_TAB
value|26
end_define

begin_define
define|#
directive|define
name|KEY_BS
value|25
end_define

begin_define
define|#
directive|define
name|KEY_DEL
value|39
end_define

begin_define
define|#
directive|define
name|KEY_CR
value|53
end_define

begin_comment
comment|/* carrige return */
end_comment

begin_define
define|#
directive|define
name|KEY_SP
value|70
end_define

begin_comment
comment|/* space */
end_comment

begin_define
define|#
directive|define
name|KEY_CTRL
value|40
end_define

begin_define
define|#
directive|define
name|KEY_SHIFTL
value|54
end_define

begin_comment
comment|/* left shift key */
end_comment

begin_define
define|#
directive|define
name|KEY_SHIFTR
value|66
end_define

begin_comment
comment|/* right shift key */
end_comment

begin_define
define|#
directive|define
name|KEY_ALT
value|67
end_define

begin_define
define|#
directive|define
name|KEY_CAPS
value|68
end_define

begin_define
define|#
directive|define
name|KEY_MUHENKAN
value|69
end_define

begin_define
define|#
directive|define
name|KEY_HENKAN
value|71
end_define

begin_define
define|#
directive|define
name|KEY_EISUU
value|72
end_define

begin_define
define|#
directive|define
name|KEY_KANA
value|73
end_define

begin_define
define|#
directive|define
name|KEY_JIKKOU
value|74
end_define

begin_comment
comment|/* function key */
end_comment

begin_define
define|#
directive|define
name|KEY_F1
value|1
end_define

begin_define
define|#
directive|define
name|KEY_F2
value|2
end_define

begin_define
define|#
directive|define
name|KEY_F3
value|3
end_define

begin_define
define|#
directive|define
name|KEY_F4
value|4
end_define

begin_define
define|#
directive|define
name|KEY_F5
value|5
end_define

begin_define
define|#
directive|define
name|KEY_F6
value|6
end_define

begin_define
define|#
directive|define
name|KEY_F7
value|7
end_define

begin_define
define|#
directive|define
name|KEY_F8
value|8
end_define

begin_define
define|#
directive|define
name|KEY_F9
value|9
end_define

begin_define
define|#
directive|define
name|KEY_F10
value|10
end_define

begin_comment
comment|/* numeric keypad */
end_comment

begin_define
define|#
directive|define
name|NKEY_0
value|87
end_define

begin_define
define|#
directive|define
name|NKEY_1
value|83
end_define

begin_define
define|#
directive|define
name|NKEY_2
value|84
end_define

begin_define
define|#
directive|define
name|NKEY_3
value|85
end_define

begin_define
define|#
directive|define
name|NKEY_4
value|79
end_define

begin_define
define|#
directive|define
name|NKEY_5
value|80
end_define

begin_define
define|#
directive|define
name|NKEY_6
value|81
end_define

begin_define
define|#
directive|define
name|NKEY_7
value|75
end_define

begin_define
define|#
directive|define
name|NKEY_8
value|76
end_define

begin_define
define|#
directive|define
name|NKEY_9
value|77
end_define

begin_define
define|#
directive|define
name|NKEY_PERIOD
value|89
end_define

begin_define
define|#
directive|define
name|NKEY_MINUS
value|78
end_define

begin_define
define|#
directive|define
name|NKEY_PLUS
value|82
end_define

begin_define
define|#
directive|define
name|NKEY_COMMA
value|86
end_define

begin_define
define|#
directive|define
name|NKEY_CR
value|90
end_define

begin_define
define|#
directive|define
name|NKEY_LEFT
value|91
end_define

begin_comment
comment|/* arrow key */
end_comment

begin_define
define|#
directive|define
name|NKEY_RIGHT
value|93
end_define

begin_define
define|#
directive|define
name|NKEY_UP
value|88
end_define

begin_define
define|#
directive|define
name|NKEY_DOWN
value|92
end_define

begin_define
define|#
directive|define
name|OKEY_SPACE
value|94
end_define

begin_define
define|#
directive|define
name|OKEY_EISUU
value|95
end_define

begin_define
define|#
directive|define
name|OKEY_SHIFTL
value|96
end_define

begin_define
define|#
directive|define
name|OKEY_SHIFTR
value|97
end_define

begin_define
define|#
directive|define
name|OKEY_KANA
value|98
end_define

begin_define
define|#
directive|define
name|OKEY_EQUAL
value|99
end_define

begin_define
define|#
directive|define
name|OKEY_ASTERISK
value|100
end_define

begin_define
define|#
directive|define
name|OKEY_SLASH
value|101
end_define

begin_define
define|#
directive|define
name|OKEY_TAB
value|102
end_define

begin_comment
comment|/*  * Mouse I/O contol commands  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|MSIOCGETEM
value|_IOR('M', 0, int)
end_define

begin_comment
comment|/* get current event mask */
end_comment

begin_define
define|#
directive|define
name|MSIOCSETEM
value|_IOW('M', 1, int)
end_define

begin_comment
comment|/* set event mask */
end_comment

begin_define
define|#
directive|define
name|MSIOCSETXY
value|_IOW('M', 2, struct ms_coord)
end_define

begin_comment
comment|/* set current x, y */
end_comment

begin_define
define|#
directive|define
name|MSIOCFLUSH
value|_IO('M', 3)
end_define

begin_comment
comment|/* flush event queue */
end_comment

begin_define
define|#
directive|define
name|MSIOCSETPARAM
value|_IOW('M', 4, struct ms_param)
end_define

begin_comment
comment|/* set mouse parameter */
end_comment

begin_define
define|#
directive|define
name|MSIOCSETRANGE
value|_IOW('M', 5, struct ms_range)
end_define

begin_comment
comment|/* set mouse coordinate range */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MOUSE__ */
end_comment

end_unit

