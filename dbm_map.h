begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: dbm_map.h,v 1.1 2016/07/19 21:31:55 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2016 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Private interface for low-level routines for the map-based version   * of the mandoc database, for read-only access.  * To be used by dbm*.c only.  */
end_comment

begin_struct_decl
struct_decl|struct
name|dbm_match
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|dbm_map
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbm_unmap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dbm_get
parameter_list|(
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
modifier|*
name|dbm_getint
parameter_list|(
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|dbm_addr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_match
parameter_list|(
specifier|const
name|struct
name|dbm_match
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

