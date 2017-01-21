begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: dba_array.h,v 1.1 2016/07/19 21:31:55 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2016 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Public interface for allocation-based arrays  * for the mandoc database, for read-write access.  * To be used by dba*.c and by makewhatis(8).  */
end_comment

begin_struct_decl
struct_decl|struct
name|dba_array
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|DBA_STR
value|0x01
end_define

begin_comment
comment|/* Map contains strings, not pointers. */
end_comment

begin_define
define|#
directive|define
name|DBA_GROW
value|0x02
end_define

begin_comment
comment|/* Allow the array to grow. */
end_comment

begin_define
define|#
directive|define
name|dba_array_FOREACH
parameter_list|(
name|a
parameter_list|,
name|e
parameter_list|)
define|\
value|dba_array_start(a); \ 	while (((e) = dba_array_next(a)) != NULL)
end_define

begin_typedef
typedef|typedef
name|int
name|dba_compare_func
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|dba_array
modifier|*
name|dba_array_new
parameter_list|(
name|int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_free
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_set
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_add
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dba_array_get
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_start
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dba_array_next
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_del
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_undel
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_setpos
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|dba_array_getpos
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_sort
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|dba_compare_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|dba_array_writelen
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_writepos
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dba_array_writelst
parameter_list|(
name|struct
name|dba_array
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

