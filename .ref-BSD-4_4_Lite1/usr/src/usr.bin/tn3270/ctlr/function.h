begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)function.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * The following are the various functions which the keyboard can ask  * the controller to perform.  *  * Note that this file (the following entries) are scanned by mkhit.c,  * and that the format must remain more-or-less consistent  * [ \t]*TOKEN  */
end_comment

begin_enum
enum|enum
name|ctlrfcn
block|{
name|undefined
init|=
literal|0
block|,
comment|/* Not yet touched */
name|FCN_NULL
block|,
comment|/* Illegal sequence */
name|FCN_RESET
block|,
comment|/* unlock keyboard */
name|FCN_MAKE_SHIFT_LOCK
block|,
name|FCN_BREAK_SHIFT_LOCK
block|,
name|FCN_MAKE_SHIFT
block|,
comment|/* shift key pressed DOWN */
name|FCN_BREAK_SHIFT
block|,
comment|/* shift key released */
name|FCN_MAKE_ALT
block|,
comment|/* alt key pressed DOWN */
name|FCN_BREAK_ALT
block|,
comment|/* alt key released */
name|FCN_MAKE_CTRL
block|,
name|FCN_CAPS_LOCK
block|,
name|FCN_MONOCASE
block|,
comment|/* DISPLAY in upper case */
name|FCN_DVCNL
block|,
name|FCN_CHARACTER
block|,
comment|/* Not one of the following, but ... */
name|FCN_VERTICAL_BAR
block|,
comment|/* EBCDIC solid vertical bar */
name|FCN_CENTSIGN
block|,
comment|/* EBCDIC cent sign */
name|FCN_SPACE
block|,
comment|/* EBCDIC space */
name|FCN_DP
block|,
comment|/* EBCDIC dup character */
name|FCN_FM
block|,
comment|/* EBCDIC field mark */
name|FCN_AID
block|,
comment|/* Some AID key */
name|FCN_ATTN
block|,
name|FCN_CURSEL
block|,
comment|/* Cursor select function (and aid) */
name|FCN_TEST
block|,
comment|/* Test function */
name|FCN_EINP
block|,
comment|/* erase input (dangerous) */
name|FCN_EEOF
block|,
name|FCN_DELETE
block|,
name|FCN_INSRT
block|,
name|FCN_TAB
block|,
name|FCN_BTAB
block|,
name|FCN_NL
block|,
name|FCN_HOME
block|,
name|FCN_UP
block|,
name|FCN_DOWN
block|,
name|FCN_RIGHT
block|,
name|FCN_LEFT
block|,
name|FCN_LEFT2
block|,
name|FCN_RIGHT2
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PURE3274
argument_list|)
comment|/* 	 * Local editing functions 	 */
name|FCN_SETTAB
block|,
comment|/* set a column tab */
name|FCN_DELTAB
block|,
name|FCN_COLTAB
block|,
name|FCN_COLBAK
block|,
name|FCN_INDENT
block|,
comment|/* more margin over one col tab */
name|FCN_UNDENT
block|,
name|FCN_SETMRG
block|,
name|FCN_SETHOM
block|,
name|FCN_CLRTAB
block|,
name|FCN_ERASE
block|,
comment|/* erase last character */
name|FCN_WERASE
block|,
name|FCN_FERASE
block|,
name|FCN_WORDTAB
block|,
comment|/* tab to start of next word */
name|FCN_WORDBACKTAB
block|,
name|FCN_WORDEND
block|,
comment|/* find next end of word */
name|FCN_FIELDEND
block|,
comment|/* find next end of field */
comment|/* 	 * APL functions 	 */
name|FCN_APLON
block|,
comment|/* start using apl character set */
name|FCN_APLOFF
block|,
name|FCN_APLEND
block|,
name|FCN_PCON
block|,
name|FCN_PCOFF
block|,
name|FCN_INIT
block|,
comment|/* re-init screen */
name|FCN_SYNCH
block|,
comment|/* synch up after line/control error */
name|FCN_FLINP
block|,
comment|/* flush input buffer */
name|FCN_RESHOW
block|,
comment|/* redraw screen */
name|FCN_MASTER_RESET
block|,
comment|/* FLINP, RESET, RESHOW, + more */
name|FCN_DISC
block|,
comment|/* suspend application */
name|FCN_ESCAPE
block|,
comment|/* enter command mode */
name|FCN_ALTK
block|,
comment|/* Dvorak keyboard */
name|FCN_XOFF
block|,
comment|/* suspend output to screen */
name|FCN_XON
block|,
comment|/* resume output to screen */
name|FCN_LPRT
comment|/* print screen on printer */
endif|#
directive|endif
comment|/* !defined(PURE3274) */
block|}
enum|;
end_enum

begin_comment
comment|/*  * The following is the structure which defines what a 3270 keystroke  * can do.  */
end_comment

begin_struct
struct|struct
name|hits
block|{
name|unsigned
name|char
name|keynumber
decl_stmt|;
struct|struct
name|hit
block|{
name|enum
name|ctlrfcn
name|ctlrfcn
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
comment|/* AID value or 3270 display code */
block|}
name|hit
index|[
literal|4
index|]
struct|;
comment|/* plain, shifted, alted, shiftalted */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hits
name|hits
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Definitions of the shift state (and the left/right shift key position).  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_RIGHT
value|0x20
end_define

begin_comment
comment|/* Right shift key is down */
end_comment

begin_define
define|#
directive|define
name|SHIFT_LEFT
value|0x10
end_define

begin_comment
comment|/* Left shift key is down */
end_comment

begin_define
define|#
directive|define
name|SHIFT_CONTROL
value|0x08
end_define

begin_comment
comment|/* Control shift state (unused) */
end_comment

begin_define
define|#
directive|define
name|SHIFT_ALT
value|0x04
end_define

begin_comment
comment|/* ALT shift state */
end_comment

begin_define
define|#
directive|define
name|SHIFT_CAPS
value|0x02
end_define

begin_comment
comment|/* Caps lock state */
end_comment

begin_define
define|#
directive|define
name|SHIFT_UPSHIFT
value|0x01
end_define

begin_comment
comment|/* Upshift state */
end_comment

end_unit

