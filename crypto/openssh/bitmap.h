begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BITMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_BITMAP_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Simple bit vector routines */
end_comment

begin_struct_decl
struct_decl|struct
name|bitmap
struct_decl|;
end_struct_decl

begin_comment
comment|/* Allocate a new bitmap. Returns NULL on allocation failure. */
end_comment

begin_function_decl
name|struct
name|bitmap
modifier|*
name|bitmap_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a bitmap */
end_comment

begin_function_decl
name|void
name|bitmap_free
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Zero an existing bitmap */
end_comment

begin_function_decl
name|void
name|bitmap_zero
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Test whether a bit is set in a bitmap. */
end_comment

begin_function_decl
name|int
name|bitmap_test_bit
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|,
name|u_int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a bit in a bitmap. Returns 0 on success or -1 on error */
end_comment

begin_function_decl
name|int
name|bitmap_set_bit
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|,
name|u_int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clear a bit in a bitmap */
end_comment

begin_function_decl
name|void
name|bitmap_clear_bit
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|,
name|u_int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of bits in a bitmap (i.e. the position of the MSB) */
end_comment

begin_function_decl
name|size_t
name|bitmap_nbits
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of bytes needed to represent a bitmap */
end_comment

begin_function_decl
name|size_t
name|bitmap_nbytes
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a bitmap to a big endian byte string */
end_comment

begin_function_decl
name|int
name|bitmap_to_string
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a big endian byte string to a bitmap */
end_comment

begin_function_decl
name|int
name|bitmap_from_string
parameter_list|(
name|struct
name|bitmap
modifier|*
name|b
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BITMAP_H */
end_comment

end_unit

