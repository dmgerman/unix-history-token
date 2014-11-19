begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_DMA_ATTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_DMA_ATTR_H_
end_define

begin_enum
enum|enum
name|dma_attr
block|{
name|DMA_ATTR_WRITE_BARRIER
block|,
name|DMA_ATTR_WEAK_ORDERING
block|,
name|DMA_ATTR_MAX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|__DMA_ATTRS_LONGS
value|BITS_TO_LONGS(DMA_ATTR_MAX)
end_define

begin_struct
struct|struct
name|dma_attrs
block|{
name|unsigned
name|long
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFINE_DMA_ATTRS
parameter_list|(
name|x
parameter_list|)
value|struct dma_attrs x = { }
end_define

begin_function
specifier|static
specifier|inline
name|void
name|init_dma_attrs
parameter_list|(
name|struct
name|dma_attrs
modifier|*
name|attrs
parameter_list|)
block|{
name|attrs
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_DMA_ATTR_H_ */
end_comment

end_unit

