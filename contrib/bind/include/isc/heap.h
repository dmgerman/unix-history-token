begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|heap_higher_priority_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heap_index_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|heap_for_each_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|heap_context
block|{
name|int
name|array_size
decl_stmt|;
name|int
name|array_size_increment
decl_stmt|;
name|int
name|heap_size
decl_stmt|;
name|void
modifier|*
modifier|*
name|heap
decl_stmt|;
name|heap_higher_priority_func
name|higher_priority
decl_stmt|;
name|heap_index_func
name|index
decl_stmt|;
block|}
typedef|*
name|heap_context
typedef|;
end_typedef

begin_define
define|#
directive|define
name|heap_new
value|__heap_new
end_define

begin_define
define|#
directive|define
name|heap_free
value|__heap_free
end_define

begin_define
define|#
directive|define
name|heap_insert
value|__heap_insert
end_define

begin_define
define|#
directive|define
name|heap_delete
value|__heap_delete
end_define

begin_define
define|#
directive|define
name|heap_increased
value|__heap_increased
end_define

begin_define
define|#
directive|define
name|heap_decreased
value|__heap_decreased
end_define

begin_define
define|#
directive|define
name|heap_element
value|__heap_element
end_define

begin_define
define|#
directive|define
name|heap_for_each
value|__heap_for_each
end_define

begin_function_decl
name|heap_context
name|heap_new
parameter_list|(
name|heap_higher_priority_func
parameter_list|,
name|heap_index_func
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_free
parameter_list|(
name|heap_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_insert
parameter_list|(
name|heap_context
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_delete
parameter_list|(
name|heap_context
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_increased
parameter_list|(
name|heap_context
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_decreased
parameter_list|(
name|heap_context
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|heap_element
parameter_list|(
name|heap_context
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heap_for_each
parameter_list|(
name|heap_context
parameter_list|,
name|heap_for_each_func
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

