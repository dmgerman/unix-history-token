begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)term.h	8.1 (Berkeley) 6/4/93  *	$NetBSD: term.h,v 1.17 2006/03/06 21:11:56 christos Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * el.term.h: Termcap header  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_term
end_ifndef

begin_define
define|#
directive|define
name|_h_el_term
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Symbolic function key bindings	*/
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the key			*/
name|int
name|key
decl_stmt|;
comment|/* Index in termcap table		*/
name|key_value_t
name|fun
decl_stmt|;
comment|/* Function bound to it			*/
name|int
name|type
decl_stmt|;
comment|/* Type of function			*/
block|}
name|fkey_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|t_name
decl_stmt|;
comment|/* the terminal name	*/
name|coord_t
name|t_size
decl_stmt|;
comment|/* # lines and cols	*/
name|int
name|t_flags
decl_stmt|;
define|#
directive|define
name|TERM_CAN_INSERT
value|0x001
comment|/* Has insert cap	*/
define|#
directive|define
name|TERM_CAN_DELETE
value|0x002
comment|/* Has delete cap	*/
define|#
directive|define
name|TERM_CAN_CEOL
value|0x004
comment|/* Has CEOL cap		*/
define|#
directive|define
name|TERM_CAN_TAB
value|0x008
comment|/* Can use tabs		*/
define|#
directive|define
name|TERM_CAN_ME
value|0x010
comment|/* Can turn all attrs.	*/
define|#
directive|define
name|TERM_CAN_UP
value|0x020
comment|/* Can move up		*/
define|#
directive|define
name|TERM_HAS_META
value|0x040
comment|/* Has a meta key	*/
define|#
directive|define
name|TERM_HAS_AUTO_MARGINS
value|0x080
comment|/* Has auto margins	*/
define|#
directive|define
name|TERM_HAS_MAGIC_MARGINS
value|0x100
comment|/* Has magic margins	*/
name|char
modifier|*
name|t_buf
decl_stmt|;
comment|/* Termcap buffer	*/
name|int
name|t_loc
decl_stmt|;
comment|/* location used	*/
name|char
modifier|*
modifier|*
name|t_str
decl_stmt|;
comment|/* termcap strings	*/
name|int
modifier|*
name|t_val
decl_stmt|;
comment|/* termcap values	*/
name|char
modifier|*
name|t_cap
decl_stmt|;
comment|/* Termcap buffer	*/
name|fkey_t
modifier|*
name|t_fkey
decl_stmt|;
comment|/* Array of keys	*/
block|}
name|el_term_t
typedef|;
end_typedef

begin_comment
comment|/*  * fKey indexes  */
end_comment

begin_define
define|#
directive|define
name|A_K_DN
value|0
end_define

begin_define
define|#
directive|define
name|A_K_UP
value|1
end_define

begin_define
define|#
directive|define
name|A_K_LT
value|2
end_define

begin_define
define|#
directive|define
name|A_K_RT
value|3
end_define

begin_define
define|#
directive|define
name|A_K_HO
value|4
end_define

begin_define
define|#
directive|define
name|A_K_EN
value|5
end_define

begin_define
define|#
directive|define
name|A_K_NKEYS
value|6
end_define

begin_function_decl
name|protected
name|void
name|term_move_to_line
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_move_to_char
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_clear_EOL
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_overwrite
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_insertwrite
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_deletechars
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_clear_screen
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_beep
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_change_size
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_get_size
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_init
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_bind_arrow
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_print_arrow
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_clear_arrow
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_set_arrow
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|key_value_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_end
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_get
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_set
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_settc
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_telltc
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term_echotc
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term_writec
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|term__putc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|term__flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Easy access macros  */
end_comment

begin_define
define|#
directive|define
name|EL_FLAGS
value|(el)->el_term.t_flags
end_define

begin_define
define|#
directive|define
name|EL_CAN_INSERT
value|(EL_FLAGS& TERM_CAN_INSERT)
end_define

begin_define
define|#
directive|define
name|EL_CAN_DELETE
value|(EL_FLAGS& TERM_CAN_DELETE)
end_define

begin_define
define|#
directive|define
name|EL_CAN_CEOL
value|(EL_FLAGS& TERM_CAN_CEOL)
end_define

begin_define
define|#
directive|define
name|EL_CAN_TAB
value|(EL_FLAGS& TERM_CAN_TAB)
end_define

begin_define
define|#
directive|define
name|EL_CAN_ME
value|(EL_FLAGS& TERM_CAN_ME)
end_define

begin_define
define|#
directive|define
name|EL_CAN_UP
value|(EL_FLAGS& TERM_CAN_UP)
end_define

begin_define
define|#
directive|define
name|EL_HAS_META
value|(EL_FLAGS& TERM_HAS_META)
end_define

begin_define
define|#
directive|define
name|EL_HAS_AUTO_MARGINS
value|(EL_FLAGS& TERM_HAS_AUTO_MARGINS)
end_define

begin_define
define|#
directive|define
name|EL_HAS_MAGIC_MARGINS
value|(EL_FLAGS& TERM_HAS_MAGIC_MARGINS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_term */
end_comment

end_unit

