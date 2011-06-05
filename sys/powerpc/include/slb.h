begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2009 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SLB_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SLB_H_
end_define

begin_comment
comment|/*  * Bit definitions for segment lookaside buffer entries.  *  * PowerPC Microprocessor Family: The Programming Environments for 64-bit  * Microprocessors, section 7.4.2.1  *  * Note that these bitmasks are relative to the values for one of the two  * values for slbmte, slbmfee, and slbmfev, not the internal SLB  * representation.  */
end_comment

begin_define
define|#
directive|define
name|SLBV_KS
value|0x0000000000000800UL
end_define

begin_comment
comment|/* Supervisor-state prot key */
end_comment

begin_define
define|#
directive|define
name|SLBV_KP
value|0x0000000000000400UL
end_define

begin_comment
comment|/* User-state prot key */
end_comment

begin_define
define|#
directive|define
name|SLBV_N
value|0x0000000000000200UL
end_define

begin_comment
comment|/* No-execute protection */
end_comment

begin_define
define|#
directive|define
name|SLBV_L
value|0x0000000000000100UL
end_define

begin_comment
comment|/* Large page selector */
end_comment

begin_define
define|#
directive|define
name|SLBV_CLASS
value|0x0000000000000080UL
end_define

begin_comment
comment|/* Class selector */
end_comment

begin_define
define|#
directive|define
name|SLBV_VSID_MASK
value|0xfffffffffffff000UL
end_define

begin_comment
comment|/* Virtual segment ID mask */
end_comment

begin_define
define|#
directive|define
name|SLBV_VSID_SHIFT
value|12
end_define

begin_comment
comment|/*  * Make a predictable 1:1 map from ESIDs to VSIDs for the kernel. Hash table  * coverage is increased by swizzling the ESID and multiplying by a prime  * number (0x13bb).  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_VSID_BIT
value|0x0000001000000000UL
end_define

begin_comment
comment|/* Bit set in all kernel VSIDs */
end_comment

begin_define
define|#
directive|define
name|KERNEL_VSID
parameter_list|(
name|esid
parameter_list|)
value|((((((uint64_t)esid<< 8) | ((uint64_t)esid>> 28)) \ 				* 0x13bbUL)& (KERNEL_VSID_BIT - 1)) | \ 				KERNEL_VSID_BIT)
end_define

begin_define
define|#
directive|define
name|SLBE_VALID
value|0x0000000008000000UL
end_define

begin_comment
comment|/* SLB entry valid */
end_comment

begin_define
define|#
directive|define
name|SLBE_INDEX_MASK
value|0x0000000000000fffUL
end_define

begin_comment
comment|/* SLB index mask*/
end_comment

begin_define
define|#
directive|define
name|SLBE_ESID_MASK
value|0xfffffffff0000000UL
end_define

begin_comment
comment|/* Effective segment ID mask */
end_comment

begin_define
define|#
directive|define
name|SLBE_ESID_SHIFT
value|28
end_define

begin_comment
comment|/*  * User segment for copyin/out  */
end_comment

begin_define
define|#
directive|define
name|USER_SLB_SLOT
value|0
end_define

begin_define
define|#
directive|define
name|USER_SLB_SLBE
value|(((USER_ADDR>> ADDR_SR_SHFT)<< SLBE_ESID_SHIFT) | \ 			SLBE_VALID | USER_SLB_SLOT)
end_define

begin_struct
struct|struct
name|slb
block|{
name|uint64_t
name|slbv
decl_stmt|;
name|uint64_t
name|slbe
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SLB_H_ */
end_comment

end_unit

