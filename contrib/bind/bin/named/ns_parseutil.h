begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NS_PARSEUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_NS_PARSEUTIL_H
end_define

begin_comment
comment|/*  * Symbol Table  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_FREE_KEY
value|0x01
end_define

begin_define
define|#
directive|define
name|SYMBOL_FREE_VALUE
value|0x02
end_define

begin_typedef
typedef|typedef
union|union
name|symbol_value
block|{
name|void
modifier|*
name|pointer
decl_stmt|;
name|int
name|integer
decl_stmt|;
block|}
name|symbol_value
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|free_function
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|symbol_entry
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|int
name|type
decl_stmt|;
name|symbol_value
name|value
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|struct
name|symbol_entry
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|symbol_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|symbol_table
block|{
name|int
name|size
decl_stmt|;
name|symbol_entry
modifier|*
name|table
decl_stmt|;
name|free_function
name|free_value
decl_stmt|;
block|}
typedef|*
name|symbol_table
typedef|;
end_typedef

begin_function_decl
name|symbol_table
name|new_symbol_table
parameter_list|(
name|int
parameter_list|,
name|free_function
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_symbol
parameter_list|(
name|symbol_table
parameter_list|,
name|symbol_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_symbol_table
parameter_list|(
name|symbol_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprint_symbol_table
parameter_list|(
name|int
parameter_list|,
name|symbol_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup_symbol
parameter_list|(
name|symbol_table
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|symbol_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|define_symbol
parameter_list|(
name|symbol_table
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|symbol_value
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|undefine_symbol
parameter_list|(
name|symbol_table
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Conversion Routines  */
end_comment

begin_function_decl
name|int
name|unit_to_ulong
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NS_PARSEUTIL_H */
end_comment

end_unit

