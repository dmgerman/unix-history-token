begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * 		@(#)qvreg.h	1.3  Berkeley  6/3/88  *  *	derived from: @(#)qvreg.h	1.3 (ULTRIX) 8/21/85   */
end_comment

begin_comment
comment|/*  * QVSS definitions.  */
end_comment

begin_struct
struct|struct
name|qvdevice
block|{
name|unsigned
name|short
name|qv_csr
decl_stmt|;
comment|/* csr				*/
name|unsigned
name|short
name|qv_xcur
decl_stmt|;
comment|/* cursor x-position		*/
name|unsigned
name|short
name|qv_mouse
decl_stmt|;
comment|/* mouse position		*/
name|unsigned
name|short
name|qv_spare1
decl_stmt|;
name|unsigned
name|short
name|qv_crtaddr
decl_stmt|;
comment|/* crt controller address reg	*/
name|unsigned
name|short
name|qv_crtdata
decl_stmt|;
comment|/* crt controller data register	*/
name|unsigned
name|short
name|qv_intdata
decl_stmt|;
comment|/* int controller data register	*/
name|unsigned
name|short
name|qv_intcsr
decl_stmt|;
comment|/* int controller command/status*/
name|unsigned
name|short
name|qv_dummy
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|short
name|qv_uartmode
decl_stmt|;
comment|/* uart mode			*/
name|unsigned
name|short
name|qv_uartstatus
decl_stmt|;
comment|/* uart status			*/
name|unsigned
name|short
name|qv_uartcmd
decl_stmt|;
comment|/* uart command			*/
name|unsigned
name|short
name|qv_uartdata
decl_stmt|;
comment|/* uart data			*/
name|unsigned
name|short
name|qv_spare2
decl_stmt|;
name|unsigned
name|short
name|qv_uartintstatus
decl_stmt|;
comment|/* uart interrupt status	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * csr bit definations  */
end_comment

begin_define
define|#
directive|define
name|QV_19INCH
value|0x1
end_define

begin_define
define|#
directive|define
name|QV_VIDEO_ENA
value|0x4
end_define

begin_define
define|#
directive|define
name|QV_CUR_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|QV_VIDEO_LP
value|0x10
end_define

begin_define
define|#
directive|define
name|QV_TEST_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|QV_INT_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|QV_CURSOR_ON
value|0x80
end_define

begin_define
define|#
directive|define
name|QV_MOUSE_ANY
value|0x700
end_define

begin_define
define|#
directive|define
name|QV_MOUSE_A
value|0x100
end_define

begin_define
define|#
directive|define
name|QV_MOUSE_B
value|0x200
end_define

begin_define
define|#
directive|define
name|QV_MOUSE_C
value|0x400
end_define

begin_define
define|#
directive|define
name|QV_MEM_BANK
value|0x7800
end_define

begin_comment
comment|/*  * Lk201 keyboard   */
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
comment|/* reset (some) default settings */
end_comment

begin_define
define|#
directive|define
name|LK_AR_ENABLE
value|0xe3
end_define

begin_comment
comment|/* global auto repeat enable */
end_comment

begin_define
define|#
directive|define
name|LK_CL_ENABLE
value|0x1b
end_define

begin_comment
comment|/* keyclick enable */
end_comment

begin_define
define|#
directive|define
name|LK_KBD_ENABLE
value|0x8b
end_define

begin_comment
comment|/* keyboard enable */
end_comment

begin_define
define|#
directive|define
name|LK_BELL_ENABLE
value|0x23
end_define

begin_comment
comment|/* the bell */
end_comment

begin_define
define|#
directive|define
name|LK_LED_ENABLE
value|0x13
end_define

begin_comment
comment|/* light led */
end_comment

begin_define
define|#
directive|define
name|LK_LED_DISABLE
value|0x11
end_define

begin_comment
comment|/* turn off led */
end_comment

begin_define
define|#
directive|define
name|LK_RING_BELL
value|0xa7
end_define

begin_comment
comment|/* ring keyboard bell */
end_comment

begin_define
define|#
directive|define
name|LED_1
value|0x81
end_define

begin_comment
comment|/* led bits */
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
name|LK_KDOWN_ERROR
value|0x3d
end_define

begin_comment
comment|/* key down on powerup error */
end_comment

begin_define
define|#
directive|define
name|LK_POWER_ERROR
value|0x3e
end_define

begin_comment
comment|/* keyboard failure on powerup test */
end_comment

begin_define
define|#
directive|define
name|LK_OUTPUT_ERROR
value|0xb5
end_define

begin_comment
comment|/* keystrokes lost during inhibit */
end_comment

begin_define
define|#
directive|define
name|LK_INPUT_ERROR
value|0xb6
end_define

begin_comment
comment|/* garbage command to keyboard */
end_comment

begin_define
define|#
directive|define
name|LK_LOWEST
value|0x56
end_define

begin_comment
comment|/* lowest significant keycode */
end_comment

begin_define
define|#
directive|define
name|LK_DIV6_START
value|0xad
end_define

begin_comment
comment|/* start of div 6 */
end_comment

begin_define
define|#
directive|define
name|LK_DIV5_END
value|0xb2
end_define

begin_comment
comment|/* end of div 5 */
end_comment

begin_comment
comment|/*  * Keycodes for special keys and functions  */
end_comment

begin_define
define|#
directive|define
name|SHIFT
value|0xae
end_define

begin_define
define|#
directive|define
name|LOCK
value|0xb0
end_define

begin_define
define|#
directive|define
name|REPEAT
value|0xb4
end_define

begin_define
define|#
directive|define
name|CNTRL
value|0xaf
end_define

begin_define
define|#
directive|define
name|ALLUP
value|0xb3
end_define

end_unit

