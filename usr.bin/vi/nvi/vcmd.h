begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vcmd.h	8.23 (Berkeley) 1/8/94  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_vikeys
name|VIKEYS
typedef|;
end_typedef

begin_comment
comment|/* Structure passed around to functions implementing vi commands. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vicmdarg
block|{
define|#
directive|define
name|vp_startzero
value|buffer
comment|/* START ZERO OUT. */
name|CHAR_T
name|buffer
decl_stmt|;
comment|/* Buffer. */
name|CHAR_T
name|character
decl_stmt|;
comment|/* Character. */
name|u_long
name|count
decl_stmt|;
comment|/* Count. */
name|u_long
name|count2
decl_stmt|;
comment|/* Second count (only used by z). */
name|int
name|key
decl_stmt|;
comment|/* Command key. */
name|VIKEYS
specifier|const
modifier|*
name|kp
decl_stmt|;
comment|/* VIKEYS key. */
name|VIKEYS
specifier|const
modifier|*
name|mkp
decl_stmt|;
comment|/* VIKEYS motion key. */
name|size_t
name|klen
decl_stmt|;
comment|/* Keyword length. */
comment|/*  * Historic vi allowed "dl" when the cursor was on the last column, deleting  * the last character, and similarly allowed "dw" when the cursor was on the  * last column of the file.  It didn't allow "dh" when the cursor was on  * column 1, although these cases are not strictly analogous.  The point is  * that some movements would succeed if they were associated with a motion  * command, and fail otherwise.  This is part of the off-by-1 schizophrenia  * that plagued vi.  Other examples are that "dfb" deleted everything up to  * and including the next 'b' character, but "d/b" only deleted everything  * up to the next 'b' character.  While this implementation regularizes the  * interface to the extent possible, there are many special cases that can't  * be fixed.  This is implemented by setting special flags per command so that  * the motion routines know what's really going on.  *  * Note, the VC_COMMASK flags are set in the vikeys array, and therefore  * must have values not used in the set of flags declared in the VIKEYS  * structure below.  */
define|#
directive|define
name|VC_C
value|0x0001
comment|/* The 'c' command. */
define|#
directive|define
name|VC_D
value|0x0002
comment|/* The 'd' command. */
define|#
directive|define
name|VC_SH
value|0x0004
comment|/* The '>' command. */
define|#
directive|define
name|VC_Y
value|0x0008
comment|/* The 'y' command. */
define|#
directive|define
name|VC_COMMASK
value|0x000f
comment|/* Mask for special flags. */
define|#
directive|define
name|VC_BUFFER
value|0x0010
comment|/* Buffer set. */
define|#
directive|define
name|VC_C1SET
value|0x0020
comment|/* Count 1 set. */
define|#
directive|define
name|VC_C1RESET
value|0x0040
comment|/* Reset the C1SET flag for dot commands. */
define|#
directive|define
name|VC_C2SET
value|0x0080
comment|/* Count 2 set. */
define|#
directive|define
name|VC_LMODE
value|0x0100
comment|/* Motion is line oriented. */
define|#
directive|define
name|VC_ISDOT
value|0x0200
comment|/* Command was the dot command. */
define|#
directive|define
name|VC_REVMOVE
value|0x0400
comment|/* Movement was before the cursor. */
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|vp_endzero
value|keyword
comment|/* END ZERO OUT. */
name|char
modifier|*
name|keyword
decl_stmt|;
comment|/* Keyword. */
name|size_t
name|kbuflen
decl_stmt|;
comment|/* Keyword buffer length. */
block|}
name|VICMDARG
typedef|;
end_typedef

begin_comment
comment|/* Vi command structure. */
end_comment

begin_struct
struct|struct
name|_vikeys
block|{
comment|/* Underlying function. */
name|int
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VICMDARG
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|V_DONTUSE1
value|0x000001
comment|/* VC_C */
define|#
directive|define
name|V_DONTUSE2
value|0x000002
comment|/* VC_D */
define|#
directive|define
name|V_DONTUSE3
value|0x000004
comment|/* VC_SH */
define|#
directive|define
name|V_DONTUSE4
value|0x000008
comment|/* VC_Y */
define|#
directive|define
name|V_ABS
value|0x000010
comment|/* Absolute movement, set '' mark. */
define|#
directive|define
name|V_CHAR
value|0x000020
comment|/* Character (required, trailing). */
define|#
directive|define
name|V_CNT
value|0x000040
comment|/* Count (optional, leading). */
define|#
directive|define
name|V_DOT
value|0x000080
comment|/* On success, sets dot command. */
define|#
directive|define
name|V_KEYNUM
value|0x000100
comment|/* Cursor referenced number. */
define|#
directive|define
name|V_KEYW
value|0x000200
comment|/* Cursor referenced word. */
define|#
directive|define
name|V_LMODE
value|0x000400
comment|/* Motion is line oriented. */
define|#
directive|define
name|V_MOTION
value|0x000800
comment|/* Motion (required, trailing). */
define|#
directive|define
name|V_MOVE
value|0x001000
comment|/* Command defines movement. */
define|#
directive|define
name|V_OBUF
value|0x002000
comment|/* Buffer (optional, leading). */
define|#
directive|define
name|V_RBUF
value|0x004000
comment|/* Buffer (required, trailing). */
define|#
directive|define
name|V_RCM
value|0x008000
comment|/* Use relative cursor movment (RCM). */
define|#
directive|define
name|V_RCM_SET
value|0x010000
comment|/* RCM: set to current position. */
define|#
directive|define
name|V_RCM_SETFNB
value|0x020000
comment|/* RCM: set to first non-blank (FNB). */
define|#
directive|define
name|V_RCM_SETLAST
value|0x040000
comment|/* RCM: set to last character. */
define|#
directive|define
name|V_RCM_SETLFNB
value|0x080000
comment|/* RCM: set to FNB if line moved. */
define|#
directive|define
name|V_RCM_SETNNB
value|0x100000
comment|/* RCM: set to next non-blank. */
name|u_long
name|flags
decl_stmt|;
name|char
modifier|*
name|usage
decl_stmt|;
comment|/* Usage line. */
name|char
modifier|*
name|help
decl_stmt|;
comment|/* Help line. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXVIKEY
value|126
end_define

begin_comment
comment|/* List of vi commands. */
end_comment

begin_decl_stmt
specifier|extern
name|VIKEYS
specifier|const
name|vikeys
index|[
name|MAXVIKEY
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Definition of a "word". */
end_comment

begin_define
define|#
directive|define
name|inword
parameter_list|(
name|ch
parameter_list|)
value|(isalnum(ch) || (ch) == '_')
end_define

begin_comment
comment|/* Character stream structure, prototypes. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vcs
block|{
name|recno_t
name|cs_lno
decl_stmt|;
comment|/* Line. */
name|size_t
name|cs_cno
decl_stmt|;
comment|/* Column. */
name|char
modifier|*
name|cs_bp
decl_stmt|;
comment|/* Buffer. */
name|size_t
name|cs_len
decl_stmt|;
comment|/* Length. */
name|int
name|cs_ch
decl_stmt|;
comment|/* Character. */
define|#
directive|define
name|CS_EMP
value|1
comment|/* Empty line. */
define|#
directive|define
name|CS_EOF
value|2
comment|/* End-of-file. */
define|#
directive|define
name|CS_EOL
value|3
comment|/* End-of-line. */
define|#
directive|define
name|CS_SOF
value|4
comment|/* Start-of-file. */
name|int
name|cs_flags
decl_stmt|;
comment|/* Return flags. */
block|}
name|VCS
typedef|;
end_typedef

begin_decl_stmt
name|int
name|cs_bblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_fblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_fspace
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_next
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_prev
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vi private, per-screen memory. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vi_private
block|{
name|VICMDARG
name|sdot
decl_stmt|;
comment|/* Saved dot, motion command. */
name|VICMDARG
name|sdotmotion
decl_stmt|;
name|CHAR_T
name|rlast
decl_stmt|;
comment|/* Last 'r' command character. */
name|char
modifier|*
name|rep
decl_stmt|;
comment|/* Input replay buffer. */
name|size_t
name|rep_len
decl_stmt|;
comment|/* Input replay buffer length. */
name|size_t
name|rep_cnt
decl_stmt|;
comment|/* Input replay buffer characters. */
name|CHAR_T
name|inc_lastch
decl_stmt|;
comment|/* Last increment character. */
name|long
name|inc_lastval
decl_stmt|;
comment|/* Last increment value. */
name|char
modifier|*
name|paragraph
decl_stmt|;
comment|/* Paragraph search list. */
name|size_t
name|paragraph_len
decl_stmt|;
comment|/* Paragraph search list length. */
name|u_long
name|u_ccnt
decl_stmt|;
comment|/* Undo command count. */
block|}
name|VI_PRIVATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIP
parameter_list|(
name|sp
parameter_list|)
value|((VI_PRIVATE *)((sp)->vi_private))
end_define

begin_comment
comment|/* Vi function prototypes. */
end_comment

begin_decl_stmt
name|int
name|txt_auto
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|TEXT
operator|*
operator|,
name|size_t
operator|,
name|TEXT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_buildparagraph
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
name|v_end
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
name|void
name|v_eof
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|v_eol
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_exwrite
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_isempty
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_msgflush
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
name|v_ntext
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|TEXTH
operator|*
operator|,
name|MARK
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|size_t
operator|,
name|MARK
operator|*
operator|,
name|int
operator|,
name|recno_t
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_optchange
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v_screen_end
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
name|void
name|v_sof
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vi
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VIPROTO
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|type name __P((SCR *, EXF *,	VICMDARG *, MARK *, MARK *, MARK *))
end_define

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_again
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_at
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_bottom
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_cfirst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Change
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_change
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_chF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_chf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_chrepeat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_chrrepeat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_chT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_cht
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_cr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Delete
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_delete
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_dollar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_down
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_ex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_exmode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_filter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_first
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_gomark
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_home
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_hpagedown
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_hpageup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_iA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_ia
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_iI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_ii
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_increment
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_iO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_io
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_join
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_left
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_lgoto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_linedown
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_lineup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_mark
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_match
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_middle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_ncol
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_pagedown
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_pageup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_paragraphb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_paragraphf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Put
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_put
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_redraw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Replace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_replace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_right
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_screen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_searchb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_searchf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_searchN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_searchn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_searchw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_sectionb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_sectionf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_sentenceb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_sentencef
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_shiftl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_shiftr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_status
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_stop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Subst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_subst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_switch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_tagpop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_tagpush
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_ulcase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Undo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_undo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_up
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_wordB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_wordb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_wordE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_worde
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_wordW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_wordw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Xchar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_xchar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_Yank
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_yank
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_z
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VIPROTO
argument_list|(
name|int
argument_list|,
name|v_zero
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

