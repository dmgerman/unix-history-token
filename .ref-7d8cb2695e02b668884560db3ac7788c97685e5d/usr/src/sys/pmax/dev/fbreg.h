begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)fbreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Data for fb.c generic frame buffer routines that are called by the  * various frame buffer drivers.  */
end_comment

begin_struct
struct|struct
name|fbuaccess
block|{
name|PM_Info
name|scrInfo
decl_stmt|;
name|pmEvent
name|events
index|[
name|PM_MAXEVQ
index|]
decl_stmt|;
name|pmTimeCoord
name|tcs
index|[
name|MOTION_BUFFER_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmax_fb
block|{
name|int
name|GraphicsOpen
decl_stmt|;
comment|/* Open yet? */
name|int
name|initialized
decl_stmt|;
comment|/* Set up yet? */
name|int
name|isMono
decl_stmt|;
comment|/* Monochrome fb? */
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* Screen pos for glass tty */
name|struct
name|fbuaccess
modifier|*
name|fbu
decl_stmt|;
comment|/* X event stuff */
name|char
modifier|*
name|fr_addr
decl_stmt|;
comment|/* Frame buffer address */
name|size_t
name|fr_size
decl_stmt|;
comment|/* Frame buffer size */
name|char
modifier|*
name|fr_chipaddr
decl_stmt|;
comment|/* Base address for chips */
name|void
function_decl|(
modifier|*
name|posCursor
function_decl|)
parameter_list|()
function_decl|;
comment|/* Position cursor func */
name|void
function_decl|(
modifier|*
name|KBDPutc
function_decl|)
parameter_list|()
function_decl|;
comment|/* Send char to keyboard func */
name|dev_t
name|kbddev
decl_stmt|;
comment|/* Device for KBDPutc */
name|struct
name|selinfo
name|selp
decl_stmt|;
comment|/* Select structure */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for the Keyboard and mouse.  */
end_comment

begin_comment
comment|/*  * Special key values.  */
end_comment

begin_define
define|#
directive|define
name|KEY_R_SHIFT
value|0xab
end_define

begin_define
define|#
directive|define
name|KEY_SHIFT
value|0xae
end_define

begin_define
define|#
directive|define
name|KEY_CONTROL
value|0xaf
end_define

begin_define
define|#
directive|define
name|KEY_R_ALT
value|0xb2
end_define

begin_define
define|#
directive|define
name|KEY_UP
value|0xb3
end_define

begin_define
define|#
directive|define
name|KEY_REPEAT
value|0xb4
end_define

begin_define
define|#
directive|define
name|KEY_F1
value|0x56
end_define

begin_define
define|#
directive|define
name|KEY_COMMAND
value|KEY_F1
end_define

begin_comment
comment|/*  * Lk201/301 keyboard  */
end_comment

begin_define
define|#
directive|define
name|LK_UPDOWN
value|0x86
end_define

begin_comment
comment|/* bits for setting lk201 modes */
end_comment

begin_define
define|#
directive|define
name|LK_AUTODOWN
value|0x82
end_define

begin_define
define|#
directive|define
name|LK_DOWN
value|0x80
end_define

begin_define
define|#
directive|define
name|LK_DEFAULTS
value|0xd3
end_define

begin_comment
comment|/* reset mode settings          */
end_comment

begin_define
define|#
directive|define
name|LK_AR_ENABLE
value|0xe3
end_define

begin_comment
comment|/* global auto repeat enable	*/
end_comment

begin_define
define|#
directive|define
name|LK_CL_ENABLE
value|0x1b
end_define

begin_comment
comment|/* keyclick enable		*/
end_comment

begin_define
define|#
directive|define
name|LK_KBD_ENABLE
value|0x8b
end_define

begin_comment
comment|/* keyboard enable		*/
end_comment

begin_define
define|#
directive|define
name|LK_BELL_ENABLE
value|0x23
end_define

begin_comment
comment|/* the bell			*/
end_comment

begin_define
define|#
directive|define
name|LK_LED_ENABLE
value|0x13
end_define

begin_comment
comment|/* light led			*/
end_comment

begin_define
define|#
directive|define
name|LK_LED_DISABLE
value|0x11
end_define

begin_comment
comment|/* turn off led			*/
end_comment

begin_define
define|#
directive|define
name|LK_RING_BELL
value|0xa7
end_define

begin_comment
comment|/* ring keyboard bell		*/
end_comment

begin_define
define|#
directive|define
name|LED_1
value|0x81
end_define

begin_comment
comment|/* led bits			*/
end_comment

begin_define
define|#
directive|define
name|LED_2
value|0x82
end_define

begin_define
define|#
directive|define
name|LED_3
value|0x84
end_define

begin_define
define|#
directive|define
name|LED_4
value|0x88
end_define

begin_define
define|#
directive|define
name|LED_ALL
value|0x8f
end_define

begin_define
define|#
directive|define
name|LK_HELP
value|0x7c
end_define

begin_comment
comment|/* help key			*/
end_comment

begin_define
define|#
directive|define
name|LK_DO
value|0x7d
end_define

begin_comment
comment|/* do key			*/
end_comment

begin_define
define|#
directive|define
name|LK_KDOWN_ERROR
value|0x3d
end_define

begin_comment
comment|/* key down on powerup error	*/
end_comment

begin_define
define|#
directive|define
name|LK_POWER_ERROR
value|0x3e
end_define

begin_comment
comment|/* keyboard failure on pwrup tst*/
end_comment

begin_define
define|#
directive|define
name|LK_OUTPUT_ERROR
value|0xb5
end_define

begin_comment
comment|/* keystrokes lost during inhbt */
end_comment

begin_define
define|#
directive|define
name|LK_INPUT_ERROR
value|0xb6
end_define

begin_comment
comment|/* garbage command to keyboard	*/
end_comment

begin_define
define|#
directive|define
name|LK_LOWEST
value|0x56
end_define

begin_comment
comment|/* lowest significant keycode	*/
end_comment

begin_comment
comment|/* max volume is 0, lowest is 0x7 */
end_comment

begin_define
define|#
directive|define
name|LK_PARAM_VOLUME
parameter_list|(
name|v
parameter_list|)
value|(0x80|((v)&0x7))
end_define

begin_comment
comment|/* mode command details */
end_comment

begin_define
define|#
directive|define
name|LK_CMD_MODE
parameter_list|(
name|m
parameter_list|,
name|div
parameter_list|)
value|((m)|((div)<<3))
end_define

begin_comment
comment|/*  * Command characters for the mouse.  */
end_comment

begin_define
define|#
directive|define
name|MOUSE_SELF_TEST
value|'T'
end_define

begin_define
define|#
directive|define
name|MOUSE_INCREMENTAL
value|'R'
end_define

begin_comment
comment|/*  * Mouse output bits.  *  *     	MOUSE_START_FRAME	Start of report frame bit.  *	MOUSE_X_SIGN		Sign bit for X.  *	MOUSE_Y_SIGN		Sign bit for Y.  *	MOUSE_X_OFFSET		X offset to start cursor at.  *	MOUSE_Y_OFFSET		Y offset to start cursor at.  */
end_comment

begin_define
define|#
directive|define
name|MOUSE_START_FRAME
value|0x80
end_define

begin_define
define|#
directive|define
name|MOUSE_X_SIGN
value|0x10
end_define

begin_define
define|#
directive|define
name|MOUSE_Y_SIGN
value|0x08
end_define

begin_comment
comment|/*  * Definitions for mouse buttons  */
end_comment

begin_define
define|#
directive|define
name|EVENT_LEFT_BUTTON
value|0x01
end_define

begin_define
define|#
directive|define
name|EVENT_MIDDLE_BUTTON
value|0x02
end_define

begin_define
define|#
directive|define
name|EVENT_RIGHT_BUTTON
value|0x03
end_define

begin_define
define|#
directive|define
name|RIGHT_BUTTON
value|0x01
end_define

begin_define
define|#
directive|define
name|MIDDLE_BUTTON
value|0x02
end_define

begin_define
define|#
directive|define
name|LEFT_BUTTON
value|0x04
end_define

begin_comment
comment|/*  * Mouse report structure definition  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|state
decl_stmt|;
comment|/* buttons and sign bits	*/
name|short
name|dx
decl_stmt|;
comment|/* delta X since last change	*/
name|short
name|dy
decl_stmt|;
comment|/* delta Y since last change	*/
name|char
name|byteCount
decl_stmt|;
comment|/* mouse report byte count	*/
block|}
name|MouseReport
typedef|;
end_typedef

begin_comment
comment|/*  * Macro to translate from a time struct to milliseconds.  */
end_comment

begin_define
define|#
directive|define
name|TO_MS
parameter_list|(
name|tv
parameter_list|)
value|((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
end_define

begin_decl_stmt
specifier|extern
name|void
name|fbKbdEvent
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbMouseEvent
name|__P
argument_list|(
operator|(
name|MouseReport
operator|*
operator|,
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbMouseButtons
name|__P
argument_list|(
operator|(
name|MouseReport
operator|*
operator|,
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbScroll
name|__P
argument_list|(
operator|(
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbPutc
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbBlitc
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fbBlitc
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kbdMapChar
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|KBDReset
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|dev_t
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MouseInit
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|dev_t
argument_list|,
name|int
argument_list|)
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|dev_t
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|KBDGetc
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tb_kbdmouseconfig
name|__P
argument_list|(
operator|(
expr|struct
name|pmax_fb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fbmmap
name|__P
argument_list|(
operator|(
expr|struct
name|pmax_fb
operator|*
operator|,
name|dev_t
operator|,
name|caddr_t
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

