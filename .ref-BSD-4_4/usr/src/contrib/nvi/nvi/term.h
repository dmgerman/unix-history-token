begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)term.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/* Special character lookup values. */
end_comment

begin_define
define|#
directive|define
name|K_CARAT
value|1
end_define

begin_define
define|#
directive|define
name|K_CNTRLD
value|2
end_define

begin_define
define|#
directive|define
name|K_CNTRLR
value|3
end_define

begin_define
define|#
directive|define
name|K_CNTRLT
value|4
end_define

begin_define
define|#
directive|define
name|K_CNTRLZ
value|5
end_define

begin_define
define|#
directive|define
name|K_COLON
value|6
end_define

begin_define
define|#
directive|define
name|K_CR
value|7
end_define

begin_define
define|#
directive|define
name|K_ESCAPE
value|8
end_define

begin_define
define|#
directive|define
name|K_FORMFEED
value|9
end_define

begin_define
define|#
directive|define
name|K_NL
value|10
end_define

begin_define
define|#
directive|define
name|K_RIGHTBRACE
value|11
end_define

begin_define
define|#
directive|define
name|K_RIGHTPAREN
value|12
end_define

begin_define
define|#
directive|define
name|K_TAB
value|13
end_define

begin_define
define|#
directive|define
name|K_VERASE
value|14
end_define

begin_define
define|#
directive|define
name|K_VKILL
value|15
end_define

begin_define
define|#
directive|define
name|K_VLNEXT
value|16
end_define

begin_define
define|#
directive|define
name|K_VWERASE
value|17
end_define

begin_define
define|#
directive|define
name|K_ZERO
value|18
end_define

begin_comment
comment|/* The mark at the end of a range. */
end_comment

begin_define
define|#
directive|define
name|END_CH
value|'$'
end_define

begin_comment
comment|/* Flags describing how input is handled. */
end_comment

begin_define
define|#
directive|define
name|TXT_AICHARS
value|0x000001
end_define

begin_comment
comment|/* Leading autoindent chars. */
end_comment

begin_define
define|#
directive|define
name|TXT_APPENDEOL
value|0x000002
end_define

begin_comment
comment|/* Appending after EOL. */
end_comment

begin_define
define|#
directive|define
name|TXT_AUTOINDENT
value|0x000004
end_define

begin_comment
comment|/* Autoindent set this line. */
end_comment

begin_define
define|#
directive|define
name|TXT_BEAUTIFY
value|0x000008
end_define

begin_comment
comment|/* Only printable characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_BS
value|0x000010
end_define

begin_comment
comment|/* Backspace returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_CNTRLT
value|0x000020
end_define

begin_comment
comment|/* Control-T is an indent special. */
end_comment

begin_define
define|#
directive|define
name|TXT_CR
value|0x000040
end_define

begin_comment
comment|/* CR returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_EMARK
value|0x000080
end_define

begin_comment
comment|/* End of replacement mark. */
end_comment

begin_define
define|#
directive|define
name|TXT_ESCAPE
value|0x000100
end_define

begin_comment
comment|/* Escape returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPCOMMAND
value|0x000200
end_define

begin_comment
comment|/* Apply the command map. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPINPUT
value|0x000400
end_define

begin_comment
comment|/* Apply the input map. */
end_comment

begin_define
define|#
directive|define
name|TXT_NLECHO
value|0x000800
end_define

begin_comment
comment|/* Echo the newline. */
end_comment

begin_define
define|#
directive|define
name|TXT_OVERWRITE
value|0x001000
end_define

begin_comment
comment|/* Overwrite characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_PROMPT
value|0x002000
end_define

begin_comment
comment|/* Display a prompt. */
end_comment

begin_define
define|#
directive|define
name|TXT_RECORD
value|0x004000
end_define

begin_comment
comment|/* Record for replay. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLACE
value|0x008000
end_define

begin_comment
comment|/* Replace; don't delete overwrite. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLAY
value|0x010000
end_define

begin_comment
comment|/* Replay the last input. */
end_comment

begin_define
define|#
directive|define
name|TXT_RESOLVE
value|0x020000
end_define

begin_comment
comment|/* Resolve the text into the file. */
end_comment

begin_define
define|#
directive|define
name|TXT_SHOWMATCH
value|0x040000
end_define

begin_comment
comment|/* Showmatch flag is set. */
end_comment

begin_define
define|#
directive|define
name|TXT_VALID_VI
define|\
value|(TXT_APPENDEOL | TXT_AUTOINDENT | TXT_BEAUTIFY | TXT_CNTRLT |	\ 	 TXT_CR | TXT_EMARK | TXT_ESCAPE | TXT_MAPCOMMAND |		\ 	 TXT_OVERWRITE | TXT_PROMPT | TXT_RECORD | TXT_REPLACE |	\ 	 TXT_REPLAY | TXT_RESOLVE)
end_define

begin_define
define|#
directive|define
name|TXT_VALID_EX
define|\
value|(TXT_BEAUTIFY | TXT_CR | TXT_NLECHO | TXT_PROMPT)
end_define

begin_define
define|#
directive|define
name|TXT_GETKEY_MASK
define|\
value|(TXT_BEAUTIFY | TXT_MAPCOMMAND)
end_define

begin_comment
comment|/* Support keyboard routines. */
end_comment

begin_decl_stmt
name|void
name|term_flush_pseudo
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_key
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_more_pseudo
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_waiting
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

