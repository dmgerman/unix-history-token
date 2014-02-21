begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$						*/
end_comment

begin_comment
comment|/*	$OpenBSD: extern.h,v 1.3 2006/01/16 08:09:25 otto Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2003, Otto Moerbeek<otto@drijf.net>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|"bcode.h"
end_include

begin_comment
comment|/* inout.c */
end_comment

begin_function_decl
name|void
name|src_setstream
parameter_list|(
name|struct
name|source
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|src_setstring
parameter_list|(
name|struct
name|source
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|number
modifier|*
name|readnumber
parameter_list|(
name|struct
name|source
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printnumber
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|number
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|read_string
parameter_list|(
name|struct
name|source
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_value
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|value
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ascii
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|number
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mem.c */
end_comment

begin_function_decl
name|struct
name|number
modifier|*
name|new_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_number
parameter_list|(
name|struct
name|number
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|number
modifier|*
name|dup_number
parameter_list|(
specifier|const
name|struct
name|number
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|brealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bn_check
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bn_checkp
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stack.c */
end_comment

begin_function_decl
name|void
name|stack_init
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_free_value
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|value
modifier|*
name|stack_dup_value
parameter_list|(
specifier|const
name|struct
name|value
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_swap
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|stack_size
parameter_list|(
specifier|const
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_dup
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_pushnumber
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|struct
name|number
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_pushstring
parameter_list|(
name|struct
name|stack
modifier|*
name|stack
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_push
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_set_tos
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|value
modifier|*
name|stack_tos
parameter_list|(
specifier|const
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|value
modifier|*
name|stack_pop
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|number
modifier|*
name|stack_popnumber
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stack_popstring
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_clear
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stack_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|stack
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frame_assign
parameter_list|(
name|struct
name|stack
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|value
modifier|*
name|frame_retrieve
parameter_list|(
specifier|const
name|struct
name|stack
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void		 frame_free(struct stack *); */
end_comment

end_unit

