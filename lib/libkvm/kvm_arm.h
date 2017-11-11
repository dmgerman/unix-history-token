begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_ARM_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_ARM_H__
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|arm_physaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|arm_pd_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|arm_pt_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ARM_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ARM_PAGE_SIZE
value|(1<< ARM_PAGE_SHIFT)
end_define

begin_comment
comment|/* Page size */
end_comment

begin_define
define|#
directive|define
name|ARM_PAGE_MASK
value|(ARM_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ARM_L1_TABLE_SIZE
value|0x4000
end_define

begin_comment
comment|/* 16K */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_S_SIZE
value|0x00100000
end_define

begin_comment
comment|/* 1M */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_S_OFFSET
value|(ARM_L1_S_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ARM_L1_S_FRAME
value|(~ARM_L1_S_OFFSET)
end_define

begin_define
define|#
directive|define
name|ARM_L1_S_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ARM_L2_L_SIZE
value|0x00010000
end_define

begin_comment
comment|/* 64K */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_L_OFFSET
value|(ARM_L2_L_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ARM_L2_L_FRAME
value|(~ARM_L2_L_OFFSET)
end_define

begin_define
define|#
directive|define
name|ARM_L2_L_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ARM_L2_S_SIZE
value|0x00001000
end_define

begin_comment
comment|/* 4K */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_S_OFFSET
value|(ARM_L2_S_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ARM_L2_S_FRAME
value|(~ARM_L2_S_OFFSET)
end_define

begin_define
define|#
directive|define
name|ARM_L2_S_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ARM_L2_TEX1
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ARM_PTE2_RO
value|ARM_L2_TEX1
end_define

begin_define
define|#
directive|define
name|ARM_L2_NX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ARM_PTE2_NX
value|ARM_L2_NX
end_define

begin_comment
comment|/*  * Note: L2_S_PROT_W differs depending on whether the system is generic or  *       xscale.  This isn't easily accessible in this context, so use an  *       approximation of 'xscale' which is a subset of 'generic'.  */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_AP0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|ARM_AP_W
value|0x01
end_define

begin_define
define|#
directive|define
name|ARM_L2_S_PROT_W
value|(ARM_L2_AP0(ARM_AP_W))
end_define

begin_define
define|#
directive|define
name|ARM_L1_TYPE_INV
value|0x00
end_define

begin_comment
comment|/* Invalid (fault) */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_TYPE_C
value|0x01
end_define

begin_comment
comment|/* Coarse L2 */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_TYPE_S
value|0x02
end_define

begin_comment
comment|/* Section */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_TYPE_MASK
value|0x03
end_define

begin_comment
comment|/* Mask	of type	bits */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_S_ADDR_MASK
value|0xfff00000
end_define

begin_comment
comment|/* phys	address	of section */
end_comment

begin_define
define|#
directive|define
name|ARM_L1_C_ADDR_MASK
value|0xfffffc00
end_define

begin_comment
comment|/* phys	address	of L2 Table */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_TYPE_INV
value|0x00
end_define

begin_comment
comment|/* Invalid (fault) */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_TYPE_L
value|0x01
end_define

begin_comment
comment|/* Large Page - 64k */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_TYPE_S
value|0x02
end_define

begin_comment
comment|/* Small Page -  4k */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_TYPE_T
value|0x03
end_define

begin_comment
comment|/* Tiny Page  -  1k - not used */
end_comment

begin_define
define|#
directive|define
name|ARM_L2_TYPE_MASK
value|0x03
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_include
include|#
directive|include
file|<machine/acle-compat.h>
end_include

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|<machine/pte-v6.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/pte-v4.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|ARM_PAGE_SHIFT
argument_list|,
literal|"PAGE_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SIZE
operator|==
name|ARM_PAGE_SIZE
argument_list|,
literal|"PAGE_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_MASK
operator|==
name|ARM_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_TABLE_SIZE
operator|==
name|ARM_L1_TABLE_SIZE
argument_list|,
literal|"L1_TABLE_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_S_SIZE
operator|==
name|ARM_L1_S_SIZE
argument_list|,
literal|"L1_S_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_S_OFFSET
operator|==
name|ARM_L1_S_OFFSET
argument_list|,
literal|"L1_S_OFFSET mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_S_FRAME
operator|==
name|ARM_L1_S_FRAME
argument_list|,
literal|"L1_S_FRAME mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_S_SHIFT
operator|==
name|ARM_L1_S_SHIFT
argument_list|,
literal|"L1_S_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_L_SIZE
operator|==
name|ARM_L2_L_SIZE
argument_list|,
literal|"L2_L_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_L_OFFSET
operator|==
name|ARM_L2_L_OFFSET
argument_list|,
literal|"L2_L_OFFSET mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_L_FRAME
operator|==
name|ARM_L2_L_FRAME
argument_list|,
literal|"L2_L_FRAME mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_L_SHIFT
operator|==
name|ARM_L2_L_SHIFT
argument_list|,
literal|"L2_L_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_S_SIZE
operator|==
name|ARM_L2_S_SIZE
argument_list|,
literal|"L2_S_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_S_OFFSET
operator|==
name|ARM_L2_S_OFFSET
argument_list|,
literal|"L2_S_OFFSET mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_S_FRAME
operator|==
name|ARM_L2_S_FRAME
argument_list|,
literal|"L2_S_FRAME mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_S_SHIFT
operator|==
name|ARM_L2_S_SHIFT
argument_list|,
literal|"L2_S_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_TYPE_INV
operator|==
name|ARM_L1_TYPE_INV
argument_list|,
literal|"L1_TYPE_INV mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_TYPE_C
operator|==
name|ARM_L1_TYPE_C
argument_list|,
literal|"L1_TYPE_C mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_TYPE_S
operator|==
name|ARM_L1_TYPE_S
argument_list|,
literal|"L1_TYPE_S mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_TYPE_MASK
operator|==
name|ARM_L1_TYPE_MASK
argument_list|,
literal|"L1_TYPE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_S_ADDR_MASK
operator|==
name|ARM_L1_S_ADDR_MASK
argument_list|,
literal|"L1_S_ADDR_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L1_C_ADDR_MASK
operator|==
name|ARM_L1_C_ADDR_MASK
argument_list|,
literal|"L1_C_ADDR_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_TYPE_INV
operator|==
name|ARM_L2_TYPE_INV
argument_list|,
literal|"L2_TYPE_INV mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_TYPE_L
operator|==
name|ARM_L2_TYPE_L
argument_list|,
literal|"L2_TYPE_L mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L2_TYPE_S
operator|==
name|ARM_L2_TYPE_S
argument_list|,
literal|"L2_TYPE_S mismatch"
argument_list|)
assert|;
end_assert

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_assert
assert|_Static_assert
argument_list|(
name|L2_TYPE_T
operator|==
name|ARM_L2_TYPE_T
argument_list|,
literal|"L2_TYPE_T mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
name|L2_TYPE_MASK
operator|==
name|ARM_L2_TYPE_MASK
argument_list|,
literal|"L2_TYPE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|_arm_native
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__KVM_ARM_H__ */
end_comment

end_unit

