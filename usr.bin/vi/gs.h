begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gs.h	8.26 (Berkeley) 1/9/94  */
end_comment

begin_struct
struct|struct
name|_gs
block|{
name|CIRCLEQ_HEAD
argument_list|(
argument|_dqh
argument_list|,
argument|_scr
argument_list|)
name|dq
expr_stmt|;
comment|/* Displayed screens. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_hqh
argument_list|,
argument|_scr
argument_list|)
name|hq
expr_stmt|;
comment|/* Hidden screens. */
name|mode_t
name|origmode
decl_stmt|;
comment|/* Original terminal mode. */
name|struct
name|termios
name|original_termios
decl_stmt|;
comment|/* Original terminal values. */
name|struct
name|termios
name|s5_curses_botch
decl_stmt|;
comment|/* System V curses workaround. */
name|MSGH
name|msgq
decl_stmt|;
comment|/* User message list. */
name|char
modifier|*
name|tmp_bp
decl_stmt|;
comment|/* Temporary buffer. */
name|size_t
name|tmp_blen
decl_stmt|;
comment|/* Size of temporary buffer. */
ifdef|#
directive|ifdef
name|DEBUG
name|FILE
modifier|*
name|tracefp
decl_stmt|;
comment|/* Trace file pointer. */
endif|#
directive|endif
comment|/* INFORMATION SHARED BY ALL SCREENS. */
name|IBUF
modifier|*
name|tty
decl_stmt|;
comment|/* Key input buffer. */
name|CB
modifier|*
name|dcbp
decl_stmt|;
comment|/* Default cut buffer pointer. */
name|CB
modifier|*
name|dcb_store
decl_stmt|;
comment|/* Default cut buffer storage. */
name|LIST_HEAD
argument_list|(
argument|_cuth
argument_list|,
argument|_cb
argument_list|)
name|cutq
expr_stmt|;
comment|/* Linked list of cut buffers. */
define|#
directive|define
name|MAX_BIT_SEQ
value|128
comment|/* Max + 1 fast check character. */
name|LIST_HEAD
argument_list|(
argument|_seqh
argument_list|,
argument|_seq
argument_list|)
name|seqq
expr_stmt|;
comment|/* Linked list of maps, abbrevs. */
name|bitstr_t
name|bit_decl
parameter_list|(
name|seqb
parameter_list|,
name|MAX_BIT_SEQ
parameter_list|)
function_decl|;
define|#
directive|define
name|term_key_val
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|((ch)<= MAX_FAST_KEY ? sp->gp->special_key[ch] :		\ 	    (ch)> sp->gp->max_special ? 0 : __term_key_val(sp, ch))
define|#
directive|define
name|MAX_FAST_KEY
value|255
comment|/* Max + 1 fast check character.*/
name|CHAR_T
name|max_special
decl_stmt|;
comment|/* Max special character. */
name|u_char
modifier|*
name|special_key
decl_stmt|;
comment|/* Fast lookup table. */
name|CHNAME
specifier|const
modifier|*
name|cname
decl_stmt|;
comment|/* Display names of ASCII characters. */
define|#
directive|define
name|G_ABBREV
value|0x00001
comment|/* If have abbreviations. */
define|#
directive|define
name|G_BELLSCHED
value|0x00002
comment|/* Bell scheduled. */
define|#
directive|define
name|G_CURSES_INIT
value|0x00004
comment|/* Curses: initialized. */
define|#
directive|define
name|G_CURSES_S5CB
value|0x00008
comment|/* Curses: s5_curses_botch set. */
define|#
directive|define
name|G_ISFROMTTY
value|0x00010
comment|/* Reading from a tty. */
define|#
directive|define
name|G_RECOVER_SET
value|0x00020
comment|/* Recover system initialized. */
define|#
directive|define
name|G_SETMODE
value|0x00040
comment|/* Tty mode changed. */
define|#
directive|define
name|G_SIGALRM
value|0x00080
comment|/* SIGALRM arrived. */
define|#
directive|define
name|G_SIGHUP
value|0x00100
comment|/* SIGHUP arrived. */
define|#
directive|define
name|G_SIGTERM
value|0x00200
comment|/* SIGTERM arrived. */
define|#
directive|define
name|G_SIGWINCH
value|0x00400
comment|/* SIGWINCH arrived. */
define|#
directive|define
name|G_SLEEPING
value|0x00800
comment|/* Asleep (die on signal). */
define|#
directive|define
name|G_SNAPSHOT
value|0x01000
comment|/* Always snapshot files. */
define|#
directive|define
name|G_TMP_INUSE
value|0x02000
comment|/* Temporary buffer in use. */
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|GS
modifier|*
name|__global_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of screens. */
end_comment

end_unit

