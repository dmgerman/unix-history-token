begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)dc7085cons.h	7.2 (Berkeley) %G%  *  * dc7085.h --  *  *     	Definitions for the dc7085 chip.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: $Header: /sprite/src/kernel/dev/ds3100.md/RCS/dc7085.h,  *	v 1.4 89/08/15 19:52:46 rab Exp $ SPRITE (DECWRL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DC7085
end_ifndef

begin_define
define|#
directive|define
name|_DC7085
end_define

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
name|dc7085regs
block|{
name|u_short
name|dc_csr
decl_stmt|;
comment|/* control and status (R/W) */
name|u_short
name|pad0
index|[
literal|3
index|]
decl_stmt|;
name|short
name|dc_rbuf_lpr
decl_stmt|;
comment|/* receiver data (R), line params (W) */
name|u_short
name|pad1
index|[
literal|3
index|]
decl_stmt|;
name|u_short
name|dc_tcr
decl_stmt|;
comment|/* transmitter control (R/W) */
name|u_short
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|u_short
name|dc_msr_tdr
decl_stmt|;
comment|/* modem status (R), transmit data (W) */
block|}
name|dcregs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dc_rbuf
value|dc_rbuf_lpr
end_define

begin_define
define|#
directive|define
name|dc_lpr
value|dc_rbuf_lpr
end_define

begin_define
define|#
directive|define
name|dc_msr
value|dc_msr_tdr
end_define

begin_define
define|#
directive|define
name|dc_tdr
value|dc_msr_tdr
end_define

begin_comment
comment|/*  * Control status register bits.  */
end_comment

begin_define
define|#
directive|define
name|CSR_TRDY
value|0x8000
end_define

begin_define
define|#
directive|define
name|CSR_TIE
value|0x4000
end_define

begin_define
define|#
directive|define
name|CSR_TX_LINE_NUM
value|0x0300
end_define

begin_define
define|#
directive|define
name|CSR_RDONE
value|0x0080
end_define

begin_define
define|#
directive|define
name|CSR_RIE
value|0x0040
end_define

begin_define
define|#
directive|define
name|CSR_MSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|CSR_CLR
value|0x0010
end_define

begin_define
define|#
directive|define
name|CSR_MAINT
value|0x0008
end_define

begin_comment
comment|/*  * Receiver buffer register bits.  */
end_comment

begin_define
define|#
directive|define
name|RBUF_DVAL
value|0x8000
end_define

begin_define
define|#
directive|define
name|RBUF_OERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|RBUF_FERR
value|0x2000
end_define

begin_define
define|#
directive|define
name|RBUF_PERR
value|0x1000
end_define

begin_define
define|#
directive|define
name|RBUF_LINE_NUM
value|0x0300
end_define

begin_define
define|#
directive|define
name|RBUF_LINE_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RBUF_CHAR
value|0x00FF
end_define

begin_comment
comment|/*  * Transmit control register values.  */
end_comment

begin_define
define|#
directive|define
name|TCR_DTR2
value|0x400
end_define

begin_define
define|#
directive|define
name|TCR_EN3
value|0x008
end_define

begin_define
define|#
directive|define
name|TCR_EN2
value|0x004
end_define

begin_define
define|#
directive|define
name|TCR_EN1
value|0x002
end_define

begin_define
define|#
directive|define
name|TCR_EN0
value|0x001
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DS5000
end_ifdef

begin_define
define|#
directive|define
name|TCR_RTS2
value|0x800
end_define

begin_define
define|#
directive|define
name|TCR_RTS3
value|0x200
end_define

begin_define
define|#
directive|define
name|TCR_DTR3
value|0x100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Line parameter register bits.  */
end_comment

begin_define
define|#
directive|define
name|LPR_RXENAB
value|0x1000
end_define

begin_define
define|#
directive|define
name|LPR_B50
value|0x0000
end_define

begin_define
define|#
directive|define
name|LPR_B75
value|0x0100
end_define

begin_define
define|#
directive|define
name|LPR_B110
value|0x0200
end_define

begin_define
define|#
directive|define
name|LPR_B134
value|0x0300
end_define

begin_define
define|#
directive|define
name|LPR_B150
value|0x0400
end_define

begin_define
define|#
directive|define
name|LPR_B300
value|0x0500
end_define

begin_define
define|#
directive|define
name|LPR_B600
value|0x0600
end_define

begin_define
define|#
directive|define
name|LPR_B1200
value|0x0700
end_define

begin_define
define|#
directive|define
name|LPR_B1800
value|0x0800
end_define

begin_define
define|#
directive|define
name|LPR_B2000
value|0x0900
end_define

begin_define
define|#
directive|define
name|LPR_B2400
value|0x0A00
end_define

begin_define
define|#
directive|define
name|LPR_B3600
value|0x0B00
end_define

begin_define
define|#
directive|define
name|LPR_B4800
value|0x0C00
end_define

begin_define
define|#
directive|define
name|LPR_B7200
value|0x0D00
end_define

begin_define
define|#
directive|define
name|LPR_B9600
value|0x0E00
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DS3100
end_ifdef

begin_define
define|#
directive|define
name|LPR_B19800
value|0x0F00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DS5000
end_ifdef

begin_define
define|#
directive|define
name|LPR_B19200
value|0x0F00
end_define

begin_define
define|#
directive|define
name|LPR_B38400
value|0x0F00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LPR_OPAR
value|0x0080
end_define

begin_define
define|#
directive|define
name|LPR_PARENB
value|0x0040
end_define

begin_define
define|#
directive|define
name|LPR_2_STOP
value|0x0020
end_define

begin_define
define|#
directive|define
name|LPR_8_BIT_CHAR
value|0x0018
end_define

begin_define
define|#
directive|define
name|LPR_7_BIT_CHAR
value|0x0010
end_define

begin_define
define|#
directive|define
name|LPR_6_BIT_CHAR
value|0x0008
end_define

begin_define
define|#
directive|define
name|LPR_5_BIT_CHAR
value|0x0000
end_define

begin_comment
comment|/*  * Modem status register bits.  */
end_comment

begin_define
define|#
directive|define
name|MSR_DSR2
value|0x0200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DS5000
end_ifdef

begin_define
define|#
directive|define
name|MSR_RI2
value|0x0800
end_define

begin_define
define|#
directive|define
name|MSR_CD2
value|0x0400
end_define

begin_define
define|#
directive|define
name|MSR_CTS2
value|0x0100
end_define

begin_define
define|#
directive|define
name|MSR_RI3
value|0x0008
end_define

begin_define
define|#
directive|define
name|MSR_CD3
value|0x0004
end_define

begin_define
define|#
directive|define
name|MSR_DSR3
value|0x0002
end_define

begin_define
define|#
directive|define
name|MSR_CTS3
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The four serial ports.  */
end_comment

begin_define
define|#
directive|define
name|KBD_PORT
value|0
end_define

begin_define
define|#
directive|define
name|MOUSE_PORT
value|1
end_define

begin_define
define|#
directive|define
name|MODEM_PORT
value|2
end_define

begin_define
define|#
directive|define
name|PRINTER_PORT
value|3
end_define

begin_comment
comment|/*  * Special key values.  */
end_comment

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
comment|/* bits in dm lsr, copied from dmreg.h */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DC7085 */
end_comment

end_unit

