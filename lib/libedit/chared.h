begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)chared.h	8.1 (Berkeley) 6/4/93  */
end_comment

begin_comment
comment|/*  * el.chared.h: Character editor interface  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_chared
end_ifndef

begin_define
define|#
directive|define
name|_h_el_chared
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_define
define|#
directive|define
name|EL_MAXMACRO
value|10
end_define

begin_comment
comment|/*  * This is a issue of basic "vi" look-and-feel. Defining VI_MOVE works  * like real vi: i.e. the transition from command<->insert modes moves  * the cursor.  *  * On the other hand we really don't want to move the cursor, because   * all the editing commands don't include the character under the cursor.  * Probably the best fix is to make all the editing commands aware of  * this fact.  */
end_comment

begin_define
define|#
directive|define
name|VI_MOVE
end_define

begin_typedef
typedef|typedef
struct|struct
name|c_macro_t
block|{
name|int
name|level
decl_stmt|;
name|char
modifier|*
modifier|*
name|macro
decl_stmt|;
name|char
modifier|*
name|nline
decl_stmt|;
block|}
name|c_macro_t
typedef|;
end_typedef

begin_comment
comment|/*   * Undo information for both vi and emacs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|c_undo_t
block|{
name|int
name|action
decl_stmt|;
name|int
name|isize
decl_stmt|;
name|int
name|dsize
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
name|c_undo_t
typedef|;
end_typedef

begin_comment
comment|/*  * Current action information for vi  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|c_vcmd_t
block|{
name|int
name|action
decl_stmt|;
name|char
modifier|*
name|pos
decl_stmt|;
name|char
modifier|*
name|ins
decl_stmt|;
block|}
name|c_vcmd_t
typedef|;
end_typedef

begin_comment
comment|/*  * Kill buffer for emacs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|c_kill_t
block|{
name|char
modifier|*
name|buf
decl_stmt|;
name|char
modifier|*
name|last
decl_stmt|;
name|char
modifier|*
name|mark
decl_stmt|;
block|}
name|c_kill_t
typedef|;
end_typedef

begin_comment
comment|/*  * Note that we use both data structures because the user can bind  * commands from both editors!  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|el_chared_t
block|{
name|c_undo_t
name|c_undo
decl_stmt|;
name|c_kill_t
name|c_kill
decl_stmt|;
name|c_vcmd_t
name|c_vcmd
decl_stmt|;
name|c_macro_t
name|c_macro
decl_stmt|;
block|}
name|el_chared_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|STReof
value|"^D\b\b"
end_define

begin_define
define|#
directive|define
name|STRQQ
value|"\"\""
end_define

begin_define
define|#
directive|define
name|isglob
parameter_list|(
name|a
parameter_list|)
value|(strchr("*[]?", (a)) != NULL)
end_define

begin_define
define|#
directive|define
name|isword
parameter_list|(
name|a
parameter_list|)
value|(isprint(a))
end_define

begin_define
define|#
directive|define
name|NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|DELETE
value|0x01
end_define

begin_define
define|#
directive|define
name|INSERT
value|0x02
end_define

begin_define
define|#
directive|define
name|CHANGE
value|0x04
end_define

begin_define
define|#
directive|define
name|CHAR_FWD
value|0
end_define

begin_define
define|#
directive|define
name|CHAR_BACK
value|1
end_define

begin_define
define|#
directive|define
name|MODE_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|MODE_REPLACE
value|1
end_define

begin_define
define|#
directive|define
name|MODE_REPLACE_1
value|2
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"emacs.h"
end_include

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_include
include|#
directive|include
file|"fcns.h"
end_include

begin_decl_stmt
name|protected
name|int
name|cv__isword
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|cv_delfini
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|cv__endword
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|ce__isword
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|cv_undo
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|cv_next_word
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|cv_prev_word
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|c__next_word
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|c__prev_word
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|c_insert
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|c_delbefore
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|c_delafter
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|c_gets
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|c_hpos
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|ch_init
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|ch_reset
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|ch_end
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_chared */
end_comment

end_unit

