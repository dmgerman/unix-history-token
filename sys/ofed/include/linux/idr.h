begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFINE_IDR
parameter_list|(
name|name
parameter_list|)
define|\
value|struct idr name;						\ 	SYSINIT(name##_idr_sysinit, SI_SUB_DRIVERS, SI_ORDER_FIRST,	\ 	    idr_init,&(name));
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_IDR_H_ */
end_comment

end_unit

