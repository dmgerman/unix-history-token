begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Sun Microsystems, Inc. All rights reserved.  * Copyright (c) 2005 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX4_DOORBELL_H
end_ifndef

begin_define
define|#
directive|define
name|MLX4_DOORBELL_H
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

begin_define
define|#
directive|define
name|MLX4_SEND_DOORBELL
value|0x14
end_define

begin_define
define|#
directive|define
name|MLX4_CQ_DOORBELL
value|0x20
end_define

begin_if
if|#
directive|if
name|BITS_PER_LONG
operator|==
literal|64
end_if

begin_comment
comment|/*  * Assume that we can just write a 64-bit doorbell atomically.  s390  * actually doesn't have writeq() but S/390 systems don't even have  * PCI so we won't worry about it.  */
end_comment

begin_define
define|#
directive|define
name|MLX4_DECLARE_DOORBELL_LOCK
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MLX4_INIT_DOORBELL_LOCK
parameter_list|(
name|ptr
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|MLX4_GET_DOORBELL_LOCK
parameter_list|(
name|ptr
parameter_list|)
value|(NULL)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|mlx4_write64
parameter_list|(
name|__be32
name|val
index|[
literal|2
index|]
parameter_list|,
name|void
name|__iomem
modifier|*
name|dest
parameter_list|,
name|spinlock_t
modifier|*
name|doorbell_lock
parameter_list|)
block|{
name|__raw_writeq
argument_list|(
operator|*
operator|(
name|u64
operator|*
operator|)
name|val
argument_list|,
name|dest
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Just fall back to a spinlock to protect the doorbell if  * BITS_PER_LONG is 32 -- there's no portable way to do atomic 64-bit  * MMIO writes.  */
end_comment

begin_define
define|#
directive|define
name|MLX4_DECLARE_DOORBELL_LOCK
parameter_list|(
name|name
parameter_list|)
value|spinlock_t name;
end_define

begin_define
define|#
directive|define
name|MLX4_INIT_DOORBELL_LOCK
parameter_list|(
name|ptr
parameter_list|)
value|spin_lock_init(ptr)
end_define

begin_define
define|#
directive|define
name|MLX4_GET_DOORBELL_LOCK
parameter_list|(
name|ptr
parameter_list|)
value|(ptr)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|mlx4_write64
parameter_list|(
name|__be32
name|val
index|[
literal|2
index|]
parameter_list|,
name|void
name|__iomem
modifier|*
name|dest
parameter_list|,
name|spinlock_t
modifier|*
name|doorbell_lock
parameter_list|)
block|{
name|unsigned
name|long
name|flags
decl_stmt|;
name|spin_lock_irqsave
argument_list|(
name|doorbell_lock
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|__raw_writel
argument_list|(
operator|(
name|__force
name|u32
operator|)
name|val
index|[
literal|0
index|]
argument_list|,
name|dest
argument_list|)
expr_stmt|;
name|__raw_writel
argument_list|(
operator|(
name|__force
name|u32
operator|)
name|val
index|[
literal|1
index|]
argument_list|,
name|dest
operator|+
literal|4
argument_list|)
expr_stmt|;
name|spin_unlock_irqrestore
argument_list|(
name|doorbell_lock
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX4_DOORBELL_H */
end_comment

end_unit

