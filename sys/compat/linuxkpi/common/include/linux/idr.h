begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_IDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_IDR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_define
define|#
directive|define
name|IDR_BITS
value|5
end_define

begin_define
define|#
directive|define
name|IDR_SIZE
value|(1<< IDR_BITS)
end_define

begin_define
define|#
directive|define
name|IDR_MASK
value|(IDR_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|MAX_ID_SHIFT
value|((sizeof(int) * NBBY) - 1)
end_define

begin_define
define|#
directive|define
name|MAX_ID_BIT
value|(1U<< MAX_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|MAX_ID_MASK
value|(MAX_ID_BIT - 1)
end_define

begin_define
define|#
directive|define
name|MAX_LEVEL
value|(MAX_ID_SHIFT + IDR_BITS - 1) / IDR_BITS
end_define

begin_define
define|#
directive|define
name|MAX_IDR_SHIFT
value|(sizeof(int)*8 - 1)
end_define

begin_define
define|#
directive|define
name|MAX_IDR_BIT
value|(1U<< MAX_IDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|MAX_IDR_MASK
value|(MAX_IDR_BIT - 1)
end_define

begin_struct
struct|struct
name|idr_layer
block|{
name|unsigned
name|long
name|bitmap
decl_stmt|;
name|struct
name|idr_layer
modifier|*
name|ary
index|[
name|IDR_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|idr
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|idr_layer
modifier|*
name|top
decl_stmt|;
name|struct
name|idr_layer
modifier|*
name|free
decl_stmt|;
name|int
name|layers
decl_stmt|;
name|int
name|next_cyclic_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* NOTE: It is the applications responsibility to destroy the IDR */
end_comment

begin_define
define|#
directive|define
name|DEFINE_IDR
parameter_list|(
name|name
parameter_list|)
define|\
value|struct idr name;						\ 	SYSINIT(name##_idr_sysinit, SI_SUB_DRIVERS, SI_ORDER_FIRST,	\ 	    idr_init,&(name))
end_define

begin_comment
comment|/* NOTE: It is the applications responsibility to destroy the IDA */
end_comment

begin_define
define|#
directive|define
name|DEFINE_IDA
parameter_list|(
name|name
parameter_list|)
define|\
value|struct ida name;						\ 	SYSINIT(name##_ida_sysinit, SI_SUB_DRIVERS, SI_ORDER_FIRST,	\ 	    ida_init,&(name))
end_define

begin_function_decl
name|void
name|idr_preload
parameter_list|(
name|gfp_t
name|gfp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idr_preload_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|idr_find
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|idr_get_next
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|int
modifier|*
name|nextid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_pre_get
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_get_new
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_get_new_above
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|starting_id
parameter_list|,
name|int
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|idr_replace
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idr_remove
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idr_remove_all
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idr_destroy
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idr_init
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_alloc
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
name|gfp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_alloc_cyclic
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|,
name|gfp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idr_for_each
parameter_list|(
name|struct
name|idr
modifier|*
name|idp
parameter_list|,
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|idr_for_each_entry
parameter_list|(
name|idp
parameter_list|,
name|entry
parameter_list|,
name|id
parameter_list|)
define|\
value|for ((id) = 0; ((entry) = idr_get_next(idp,&(id))) != NULL; ++(id))
end_define

begin_define
define|#
directive|define
name|IDA_CHUNK_SIZE
value|128
end_define

begin_comment
comment|/* 128 bytes per chunk */
end_comment

begin_define
define|#
directive|define
name|IDA_BITMAP_LONGS
value|(IDA_CHUNK_SIZE / sizeof(long) - 1)
end_define

begin_define
define|#
directive|define
name|IDA_BITMAP_BITS
value|(IDA_BITMAP_LONGS * sizeof(long) * 8)
end_define

begin_struct
struct|struct
name|ida_bitmap
block|{
name|long
name|nr_busy
decl_stmt|;
name|unsigned
name|long
name|bitmap
index|[
name|IDA_BITMAP_LONGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ida
block|{
name|struct
name|idr
name|idr
decl_stmt|;
name|struct
name|ida_bitmap
modifier|*
name|free_bitmap
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ida_pre_get
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ida_get_new_above
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|int
name|starting_id
parameter_list|,
name|int
modifier|*
name|p_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ida_remove
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ida_destroy
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ida_init
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ida_simple_get
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|unsigned
name|int
name|start
parameter_list|,
name|unsigned
name|int
name|end
parameter_list|,
name|gfp_t
name|gfp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ida_simple_remove
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|unsigned
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|ida_get_new
parameter_list|(
name|struct
name|ida
modifier|*
name|ida
parameter_list|,
name|int
modifier|*
name|p_id
parameter_list|)
block|{
return|return
operator|(
name|ida_get_new_above
argument_list|(
name|ida
argument_list|,
literal|0
argument_list|,
name|p_id
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_IDR_H_ */
end_comment

end_unit

