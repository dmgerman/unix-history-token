begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_H_
end_define

begin_comment
comment|/*  * 64-bit MIPS types.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|typedef unsigned long	register_t;
comment|/* 64-bit MIPS register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|paddr_t
typedef|;
end_typedef

begin_comment
comment|/* Physical address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|vaddr_t
typedef|;
end_typedef

begin_comment
comment|/* Virtual address */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef unsigned char	uint8_t; typedef unsigned short	uint16_t; typedef unsigned int	uint32_t; typedef unsigned long	uint64_t;
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MIPS address space layout.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_XKPHYS_UNCACHED_BASE
value|0x9000000000000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_CACHED_NC_BASE
value|0x9800000000000000
end_define

begin_function
specifier|static
specifier|inline
name|vaddr_t
name|mips_phys_to_cached
parameter_list|(
name|paddr_t
name|phys
parameter_list|)
block|{
return|return
operator|(
name|phys
operator||
name|MIPS_XKPHYS_CACHED_NC_BASE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|vaddr_t
name|mips_phys_to_uncached
parameter_list|(
name|paddr_t
name|phys
parameter_list|)
block|{
return|return
operator|(
name|phys
operator||
name|MIPS_XKPHYS_UNCACHED_BASE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Endian conversion routines for use in I/O -- most Altera devices are little  * endian, but our processor is big endian.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|byteswap16
parameter_list|(
name|uint16_t
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator||
operator|(
name|v
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|byteswap32
parameter_list|(
name|uint32_t
name|v
parameter_list|)
block|{
return|return
operator|(
operator|(
name|v
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
operator||
operator|(
name|v
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|8
operator||
operator|(
name|v
operator|&
literal|0x0000ff00
operator|)
operator|<<
literal|8
operator||
operator|(
name|v
operator|&
literal|0x000000ff
operator|)
operator|<<
literal|24
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * MIPS simple I/O routines -- arguments are virtual addresses so that the  * caller can determine required caching properties.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|mips_ioread_uint8
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|)
block|{
name|uint8_t
name|v
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("lb %0, 0(%1)" : "=r" (v) : "r" (vaddr));
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mips_iowrite_uint8
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|,
name|uint8_t
name|v
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("sb %0, 0(%1)" : : "r" (v), "r" (vaddr));
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|mips_ioread_uint32
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|)
block|{
name|uint32_t
name|v
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("lw %0, 0(%1)" : "=r" (v) : "r" (vaddr));
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mips_iowrite_uint32
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("sw %0, 0(%1)" : : "r" (v), "r" (vaddr));
block|}
end_function

begin_comment
comment|/*  * Little-endian versions of 32-bit I/O routines.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|mips_ioread_uint32le
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|)
block|{
return|return
operator|(
name|byteswap32
argument_list|(
name|mips_ioread_uint32
argument_list|(
name|vaddr
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mips_iowrite_uint32le
parameter_list|(
name|vaddr_t
name|vaddr
parameter_list|,
name|uint32_t
name|v
parameter_list|)
block|{
name|mips_iowrite_uint32
argument_list|(
name|vaddr
argument_list|,
name|byteswap32
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Coprocessor 0 interfaces.  */
end_comment

begin_function
specifier|static
specifier|inline
name|register_t
name|cp0_count_get
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|count
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("dmfc0 %0, $9" : "=r" (count));
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

