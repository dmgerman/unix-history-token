begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)gs.h	8.39 (Berkeley) 7/23/94  */
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
name|sigset_t
name|blockset
decl_stmt|;
comment|/* Signal mask. */
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
name|MAX_FAST_KEY
value|254
comment|/* Max fast check character.*/
define|#
directive|define
name|KEY_LEN
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|((ch)<= MAX_FAST_KEY ?						\ 	    sp->gp->cname[ch].len : __key_len(sp, ch))
define|#
directive|define
name|KEY_NAME
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|((ch)<= MAX_FAST_KEY ?						\ 	    sp->gp->cname[ch].name : __key_name(sp, ch))
struct|struct
block|{
name|CHAR_T
name|name
index|[
name|MAX_CHARACTER_COLUMNS
operator|+
literal|1
index|]
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
block|}
name|cname
index|[
name|MAX_FAST_KEY
operator|+
literal|1
index|]
struct|;
comment|/* Fast lookup table. */
define|#
directive|define
name|KEY_VAL
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|((ch)<= MAX_FAST_KEY ? sp->gp->special_key[ch] :		\ 	    (ch)> sp->gp->max_special ? 0 : __key_val(sp, ch))
name|CHAR_T
name|max_special
decl_stmt|;
comment|/* Max special character. */
name|u_char
comment|/* Fast lookup table. */
name|special_key
index|[
name|MAX_FAST_KEY
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Interrupt macros. */
define|#
directive|define
name|INTERRUPTED
parameter_list|(
name|sp
parameter_list|)
define|\
value|(F_ISSET((sp), S_INTERRUPTED) || F_ISSET((sp)->gp, G_SIGINT))
define|#
directive|define
name|CLR_INTERRUPT
parameter_list|(
name|sp
parameter_list|)
value|{						\ 	F_CLR((sp), S_INTERRUPTED | S_INTERRUPTIBLE);			\ 	F_CLR((sp)->gp, G_SIGINT);					\ }
define|#
directive|define
name|G_ABBREV
value|0x0001
comment|/* If have abbreviations. */
define|#
directive|define
name|G_BELLSCHED
value|0x0002
comment|/* Bell scheduled. */
define|#
directive|define
name|G_RECOVER_SET
value|0x0004
comment|/* Recover system initialized. */
define|#
directive|define
name|G_SETMODE
value|0x0008
comment|/* Tty mode changed. */
define|#
directive|define
name|G_SIGALRM
value|0x0010
comment|/* SIGALRM arrived. */
define|#
directive|define
name|G_SIGINT
value|0x0020
comment|/* SIGINT arrived. */
define|#
directive|define
name|G_SIGWINCH
value|0x0040
comment|/* SIGWINCH arrived. */
define|#
directive|define
name|G_SNAPSHOT
value|0x0080
comment|/* Always snapshot files. */
define|#
directive|define
name|G_STDIN_TTY
value|0x0100
comment|/* Standard input is a tty. */
define|#
directive|define
name|G_TERMIOS_SET
value|0x0200
comment|/* Termios structure is valid. */
define|#
directive|define
name|G_TMP_INUSE
value|0x0400
comment|/* Temporary buffer in use. */
name|u_int16_t
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

