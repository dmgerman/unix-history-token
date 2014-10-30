begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_IO_MAPPING_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_IO_MAPPING_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/io.h>
end_include

begin_struct_decl
struct_decl|struct
name|io_mapping
struct_decl|;
end_struct_decl

begin_function
specifier|static
specifier|inline
name|struct
name|io_mapping
modifier|*
name|io_mapping_create_wc
parameter_list|(
name|resource_size_t
name|base
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
block|{
return|return
name|ioremap_wc
argument_list|(
name|base
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|io_mapping_free
parameter_list|(
name|struct
name|io_mapping
modifier|*
name|mapping
parameter_list|)
block|{
name|iounmap
argument_list|(
name|mapping
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|io_mapping_map_atomic_wc
parameter_list|(
name|struct
name|io_mapping
modifier|*
name|mapping
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|mapping
operator|)
operator|+
name|offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|io_mapping_unmap_atomic
parameter_list|(
name|void
modifier|*
name|vaddr
parameter_list|)
block|{  }
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|io_mapping_map_wc
parameter_list|(
name|struct
name|io_mapping
modifier|*
name|mapping
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|mapping
operator|)
operator|+
name|offset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|io_mapping_unmap
parameter_list|(
name|void
modifier|*
name|vaddr
parameter_list|)
block|{  }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_IO_MAPPING_H_ */
end_comment

end_unit

