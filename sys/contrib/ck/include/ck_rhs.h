begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2012-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_RHS_H
end_ifndef

begin_define
define|#
directive|define
name|CK_RHS_H
end_define

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_malloc.h>
end_include

begin_include
include|#
directive|include
file|<ck_md.h>
end_include

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_include
include|#
directive|include
file|<ck_stdint.h>
end_include

begin_include
include|#
directive|include
file|<ck_stdbool.h>
end_include

begin_include
include|#
directive|include
file|<ck_stddef.h>
end_include

begin_comment
comment|/*  * Indicates a single-writer many-reader workload. Mutually  * exclusive with CK_RHS_MODE_MPMC  */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_MODE_SPMC
value|1
end_define

begin_comment
comment|/*  * Indicates that values to be stored are not pointers but  * values. Allows for full precision. Mutually exclusive  * with CK_RHS_MODE_OBJECT.  */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_MODE_DIRECT
value|2
end_define

begin_comment
comment|/*  * Indicates that the values to be stored are pointers.  * Allows for space optimizations in the presence of pointer  * packing. Mutually exclusive with CK_RHS_MODE_DIRECT.  */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_MODE_OBJECT
value|8
end_define

begin_comment
comment|/*  * Indicated that the load is read-mostly, so get should be optimized  * over put and delete  */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_MODE_READ_MOSTLY
value|16
end_define

begin_comment
comment|/* Currently unsupported. */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_MODE_MPMC
value|(void)
end_define

begin_comment
comment|/*  * Hash callback function.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ck_rhs_hash_cb_t
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Returns pointer to object if objects are equivalent.  */
end_comment

begin_typedef
typedef|typedef
name|bool
name|ck_rhs_compare_cb_t
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CK_MD_POINTER_PACK_ENABLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CK_MD_VMA_BITS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CK_RHS_PP
end_define

begin_define
define|#
directive|define
name|CK_RHS_KEY_MASK
value|((1U<< ((sizeof(void *) * 8) - CK_MD_VMA_BITS)) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ck_rhs_map
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ck_rhs
block|{
name|struct
name|ck_malloc
modifier|*
name|m
decl_stmt|;
name|struct
name|ck_rhs_map
modifier|*
name|map
decl_stmt|;
name|unsigned
name|int
name|mode
decl_stmt|;
name|unsigned
name|int
name|load_factor
decl_stmt|;
name|unsigned
name|long
name|seed
decl_stmt|;
name|ck_rhs_hash_cb_t
modifier|*
name|hf
decl_stmt|;
name|ck_rhs_compare_cb_t
modifier|*
name|compare
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_rhs
name|ck_rhs_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ck_rhs_stat
block|{
name|unsigned
name|long
name|n_entries
decl_stmt|;
name|unsigned
name|int
name|probe_maximum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ck_rhs_iterator
block|{
name|void
modifier|*
modifier|*
name|cursor
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_rhs_iterator
name|ck_rhs_iterator_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CK_RHS_ITERATOR_INITIALIZER
value|{ NULL, 0 }
end_define

begin_comment
comment|/* Convenience wrapper to table hash function. */
end_comment

begin_define
define|#
directive|define
name|CK_RHS_HASH
parameter_list|(
name|T
parameter_list|,
name|F
parameter_list|,
name|K
parameter_list|)
value|F((K), (T)->seed)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|ck_rhs_apply_fn_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|bool
name|ck_rhs_apply
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|ck_rhs_apply_fn_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ck_rhs_iterator_init
parameter_list|(
name|ck_rhs_iterator_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_next
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|ck_rhs_iterator_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_move
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|ck_rhs_t
modifier|*
parameter_list|,
name|ck_rhs_hash_cb_t
modifier|*
parameter_list|,
name|ck_rhs_compare_cb_t
modifier|*
parameter_list|,
name|struct
name|ck_malloc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_init
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|ck_rhs_hash_cb_t
modifier|*
parameter_list|,
name|ck_rhs_compare_cb_t
modifier|*
parameter_list|,
name|struct
name|ck_malloc
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ck_rhs_destroy
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ck_rhs_get
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_put
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_put_unique
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_set
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_fas
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ck_rhs_remove
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_grow
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_rebuild
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_gc
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|ck_rhs_count
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_reset
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_reset_size
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ck_rhs_stat
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|struct
name|ck_rhs_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ck_rhs_set_load_factor
parameter_list|(
name|ck_rhs_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_RHS_H */
end_comment

end_unit

