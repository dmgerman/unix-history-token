begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sparse Arrays for Objective C dispatch tables    Copyright (C) 1993, 1995, 1996 Free Software Foundation, Inc.    Contributed by Kresten Krab Thorup.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__sarray_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__sarray_INCLUDE_GNU
end_define

begin_define
define|#
directive|define
name|OBJC_SPARSE2
end_define

begin_comment
comment|/* 2-level sparse array */
end_comment

begin_comment
comment|/* #define OBJC_SPARSE3 */
end_comment

begin_comment
comment|/* 3-level sparse array */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJC_SPARSE2
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__objc_sparse2_id
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__objc_sparse3_id
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"objc/thr.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|nbuckets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for stats */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nindices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|narrays
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|idxsize
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/* An unsigned integer of same size as a pointer */
end_comment

begin_define
define|#
directive|define
name|SIZET_BITS
value|(sizeof(size_t)*8)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJC_SPARSE2
argument_list|)
end_if

begin_define
define|#
directive|define
name|PRECOMPUTE_SELECTORS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
end_ifdef

begin_comment
comment|/* Buckets are 8 words each */
end_comment

begin_define
define|#
directive|define
name|BUCKET_BITS
value|3
end_define

begin_define
define|#
directive|define
name|BUCKET_SIZE
value|(1<<BUCKET_BITS)
end_define

begin_define
define|#
directive|define
name|BUCKET_MASK
value|(BUCKET_SIZE-1)
end_define

begin_comment
comment|/* Indices are 16 words each */
end_comment

begin_define
define|#
directive|define
name|INDEX_BITS
value|4
end_define

begin_define
define|#
directive|define
name|INDEX_SIZE
value|(1<<INDEX_BITS)
end_define

begin_define
define|#
directive|define
name|INDEX_MASK
value|(INDEX_SIZE-1)
end_define

begin_define
define|#
directive|define
name|INDEX_CAPACITY
value|(BUCKET_SIZE*INDEX_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJC_SPARSE2 */
end_comment

begin_comment
comment|/* Buckets are 32 words each */
end_comment

begin_define
define|#
directive|define
name|BUCKET_BITS
value|5
end_define

begin_define
define|#
directive|define
name|BUCKET_SIZE
value|(1<<BUCKET_BITS)
end_define

begin_define
define|#
directive|define
name|BUCKET_MASK
value|(BUCKET_SIZE-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJC_SPARSE2 */
end_comment

begin_typedef
typedef|typedef
name|size_t
name|sidx
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PRECOMPUTE_SELECTORS
end_ifdef

begin_struct
struct|struct
name|soffset
block|{
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
name|unsigned
name|int
name|unused
range|:
name|SIZET_BITS
operator|/
literal|4
decl_stmt|;
name|unsigned
name|int
name|eoffset
range|:
name|SIZET_BITS
operator|/
literal|4
decl_stmt|;
name|unsigned
name|int
name|boffset
range|:
name|SIZET_BITS
operator|/
literal|4
decl_stmt|;
name|unsigned
name|int
name|ioffset
range|:
name|SIZET_BITS
operator|/
literal|4
decl_stmt|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
ifdef|#
directive|ifdef
name|__sparc__
name|unsigned
name|long
name|boffset
range|:
operator|(
name|SIZET_BITS
operator|-
literal|2
operator|)
operator|-
name|BUCKET_BITS
decl_stmt|;
name|unsigned
name|int
name|eoffset
range|:
name|BUCKET_BITS
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|2
decl_stmt|;
else|#
directive|else
name|unsigned
name|int
name|boffset
range|:
name|SIZET_BITS
operator|/
literal|2
decl_stmt|;
name|unsigned
name|int
name|eoffset
range|:
name|SIZET_BITS
operator|/
literal|2
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* OBJC_SPARSE2 */
block|}
struct|;
end_struct

begin_union
union|union
name|sofftype
block|{
name|struct
name|soffset
name|off
decl_stmt|;
name|sidx
name|idx
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not PRECOMPUTE_SELECTORS */
end_comment

begin_union
union|union
name|sversion
block|{
name|int
name|version
decl_stmt|;
name|void
modifier|*
name|next_free
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|sbucket
block|{
name|void
modifier|*
name|elems
index|[
name|BUCKET_SIZE
index|]
decl_stmt|;
comment|/* elements stored in array */
name|union
name|sversion
name|version
decl_stmt|;
comment|/* used for copy-on-write */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
end_ifdef

begin_struct
struct|struct
name|sindex
block|{
name|struct
name|sbucket
modifier|*
name|buckets
index|[
name|INDEX_SIZE
index|]
decl_stmt|;
name|union
name|sversion
name|version
decl_stmt|;
comment|/* used for copy-on-write */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJC_SPARSE3 */
end_comment

begin_struct
struct|struct
name|sarray
block|{
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
name|struct
name|sindex
modifier|*
modifier|*
name|indices
decl_stmt|;
name|struct
name|sindex
modifier|*
name|empty_index
decl_stmt|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
name|struct
name|sbucket
modifier|*
modifier|*
name|buckets
decl_stmt|;
endif|#
directive|endif
comment|/* OBJC_SPARSE2 */
name|struct
name|sbucket
modifier|*
name|empty_bucket
decl_stmt|;
name|union
name|sversion
name|version
decl_stmt|;
comment|/* used for copy-on-write */
name|short
name|ref_count
decl_stmt|;
name|struct
name|sarray
modifier|*
name|is_copy_of
decl_stmt|;
name|size_t
name|capacity
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|sarray
modifier|*
name|sarray_new
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
name|default_element
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sarray_free
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sarray
modifier|*
name|sarray_lazy_copy
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sarray_realloc
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|,
name|int
name|new_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sarray_at_put
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|,
name|sidx
name|index
parameter_list|,
name|void
modifier|*
name|elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sarray_at_put_safe
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|,
name|sidx
name|index
parameter_list|,
name|void
modifier|*
name|elem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sarray
modifier|*
name|sarray_hard_copy
parameter_list|(
name|struct
name|sarray
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ... like the name? */
end_comment

begin_function_decl
name|void
name|sarray_remove_garbage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|PRECOMPUTE_SELECTORS
end_ifdef

begin_comment
comment|/* Transform soffset values to ints and vica verca */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|soffset_decode
parameter_list|(
name|sidx
name|index
parameter_list|)
block|{
name|union
name|sofftype
name|x
decl_stmt|;
name|x
operator|.
name|idx
operator|=
name|index
expr_stmt|;
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
return|return
name|x
operator|.
name|off
operator|.
name|eoffset
operator|+
operator|(
name|x
operator|.
name|off
operator|.
name|boffset
operator|*
name|BUCKET_SIZE
operator|)
operator|+
operator|(
name|x
operator|.
name|off
operator|.
name|ioffset
operator|*
name|INDEX_CAPACITY
operator|)
return|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
return|return
name|x
operator|.
name|off
operator|.
name|eoffset
operator|+
operator|(
name|x
operator|.
name|off
operator|.
name|boffset
operator|*
name|BUCKET_SIZE
operator|)
return|;
endif|#
directive|endif
comment|/* OBJC_SPARSE2 */
block|}
end_function

begin_function
specifier|static
specifier|inline
name|sidx
name|soffset_encode
parameter_list|(
name|size_t
name|offset
parameter_list|)
block|{
name|union
name|sofftype
name|x
decl_stmt|;
name|x
operator|.
name|off
operator|.
name|eoffset
operator|=
name|offset
operator|%
name|BUCKET_SIZE
expr_stmt|;
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
name|x
operator|.
name|off
operator|.
name|boffset
operator|=
operator|(
name|offset
operator|/
name|BUCKET_SIZE
operator|)
operator|%
name|INDEX_SIZE
expr_stmt|;
name|x
operator|.
name|off
operator|.
name|ioffset
operator|=
name|offset
operator|/
name|INDEX_CAPACITY
expr_stmt|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
name|x
operator|.
name|off
operator|.
name|boffset
operator|=
name|offset
operator|/
name|BUCKET_SIZE
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|sidx
operator|)
name|x
operator|.
name|idx
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not PRECOMPUTE_SELECTORS */
end_comment

begin_function
specifier|static
specifier|inline
name|size_t
name|soffset_decode
parameter_list|(
name|sidx
name|index
parameter_list|)
block|{
return|return
name|index
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|sidx
name|soffset_encode
parameter_list|(
name|size_t
name|offset
parameter_list|)
block|{
return|return
name|offset
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not PRECOMPUTE_SELECTORS */
end_comment

begin_comment
comment|/* Get element from the Sparse array `array' at offset `index' */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|sarray_get
parameter_list|(
name|struct
name|sarray
modifier|*
name|array
parameter_list|,
name|sidx
name|index
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PRECOMPUTE_SELECTORS
name|union
name|sofftype
name|x
decl_stmt|;
name|x
operator|.
name|idx
operator|=
name|index
expr_stmt|;
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
return|return
name|array
operator|->
name|indices
index|[
name|x
operator|.
name|off
operator|.
name|ioffset
index|]
operator|->
name|buckets
index|[
name|x
operator|.
name|off
operator|.
name|boffset
index|]
operator|->
name|elems
index|[
name|x
operator|.
name|off
operator|.
name|eoffset
index|]
return|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
return|return
name|array
operator|->
name|buckets
index|[
name|x
operator|.
name|off
operator|.
name|boffset
index|]
operator|->
name|elems
index|[
name|x
operator|.
name|off
operator|.
name|eoffset
index|]
return|;
endif|#
directive|endif
comment|/* OBJC_SPARSE2 */
else|#
directive|else
comment|/* not PRECOMPUTE_SELECTORS */
ifdef|#
directive|ifdef
name|OBJC_SPARSE3
return|return
name|array
operator|->
name|indices
index|[
name|index
operator|/
name|INDEX_CAPACITY
index|]
operator|->
name|buckets
index|[
operator|(
name|index
operator|/
name|BUCKET_SIZE
operator|)
operator|%
name|INDEX_SIZE
index|]
operator|->
name|elems
index|[
name|index
operator|%
name|BUCKET_SIZE
index|]
return|;
else|#
directive|else
comment|/* OBJC_SPARSE2 */
return|return
name|array
operator|->
name|buckets
index|[
name|index
operator|/
name|BUCKET_SIZE
index|]
operator|->
name|elems
index|[
name|index
operator|%
name|BUCKET_SIZE
index|]
return|;
endif|#
directive|endif
comment|/* not OBJC_SPARSE3 */
endif|#
directive|endif
comment|/* not PRECOMPUTE_SELECTORS */
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|sarray_get_safe
parameter_list|(
name|struct
name|sarray
modifier|*
name|array
parameter_list|,
name|sidx
name|index
parameter_list|)
block|{
if|if
condition|(
name|soffset_decode
argument_list|(
name|index
argument_list|)
operator|<
name|array
operator|->
name|capacity
condition|)
return|return
name|sarray_get
argument_list|(
name|array
argument_list|,
name|index
argument_list|)
return|;
else|else
return|return
operator|(
name|array
operator|->
name|empty_bucket
operator|->
name|elems
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sarray_INCLUDE_GNU */
end_comment

end_unit

