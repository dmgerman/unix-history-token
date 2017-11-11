begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_MIPS_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_MIPS_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint64_t
name|mips_physaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|mips32_pte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|mips64_pte_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIPS_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MIPS_PAGE_SIZE
value|(1<< MIPS_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|MIPS_PAGE_MASK
value|(MIPS_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|MIPS32_KSEG0_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS32_KSEG0_END
value|0x9fffffff
end_define

begin_define
define|#
directive|define
name|MIPS32_KSEG1_START
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MIPS32_KSEG1_END
value|0xbfffffff
end_define

begin_define
define|#
directive|define
name|MIPS64_KSEG0_START
value|0xffffffff80000000
end_define

begin_define
define|#
directive|define
name|MIPS64_KSEG0_END
value|0xffffffff9fffffff
end_define

begin_define
define|#
directive|define
name|MIPS64_KSEG1_START
value|0xffffffffa0000000
end_define

begin_define
define|#
directive|define
name|MIPS64_KSEG1_END
value|0xffffffffbfffffff
end_define

begin_define
define|#
directive|define
name|MIPS32_PFN_MASK
value|(0x1FFFFFC0)
end_define

begin_define
define|#
directive|define
name|MIPS64_PFN_MASK
value|0x3FFFFFFC0
end_define

begin_define
define|#
directive|define
name|MIPS_PFN_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|MIPS_PFN_TO_PA
parameter_list|(
name|pfn
parameter_list|)
value|(((pfn)>> MIPS_PFN_SHIFT)<< MIPS_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|MIPS32_PTE_TO_PFN
parameter_list|(
name|pte
parameter_list|)
value|((pte)& MIPS32_PFN_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS32_PTE_TO_PA
parameter_list|(
name|pte
parameter_list|)
value|(MIPS_PFN_TO_PA(MIPS32_PTE_TO_PFN((pte))))
end_define

begin_define
define|#
directive|define
name|MIPS64_PTE_TO_PFN
parameter_list|(
name|pte
parameter_list|)
value|((pte)& MIPS64_PFN_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS64_PTE_TO_PA
parameter_list|(
name|pte
parameter_list|)
value|(MIPS_PFN_TO_PA(MIPS64_PTE_TO_PFN((pte))))
end_define

begin_define
define|#
directive|define
name|MIPS32_SWBITS_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|MIPS64_SWBITS_SHIFT
value|55
end_define

begin_define
define|#
directive|define
name|MIPS_PTE_V
value|0x02
end_define

begin_define
define|#
directive|define
name|MIPS32_PTE_RO
value|((mips32_pte_t)0x01<< MIPS32_SWBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MIPS64_PTE_RO
value|((mips64_pte_t)0x01<< MIPS64_SWBITS_SHIFT)
end_define

begin_function
specifier|static
specifier|inline
name|mips32_pte_t
name|_mips32_pte_get
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|u_long
name|pteindex
parameter_list|)
block|{
name|mips32_pte_t
modifier|*
name|pte
init|=
name|_kvm_pmap_get
argument_list|(
name|kd
argument_list|,
name|pteindex
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pte
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_kvm32toh
argument_list|(
name|kd
argument_list|,
operator|*
name|pte
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|mips64_pte_t
name|_mips64_pte_get
parameter_list|(
name|kvm_t
modifier|*
name|kd
parameter_list|,
name|u_long
name|pteindex
parameter_list|)
block|{
name|mips64_pte_t
modifier|*
name|pte
init|=
name|_kvm_pmap_get
argument_list|(
name|kd
argument_list|,
name|pteindex
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pte
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_kvm64toh
argument_list|(
name|kd
argument_list|,
operator|*
name|pte
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|MIPS_PAGE_SHIFT
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
name|MIPS_PAGE_SIZE
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
name|MIPS_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint64_t
operator|)
name|MIPS_KSEG0_START
operator|==
name|MIPS64_KSEG0_START
argument_list|,
literal|"MIPS_KSEG0_START mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint64_t
operator|)
name|MIPS_KSEG0_END
operator|==
name|MIPS64_KSEG0_END
argument_list|,
literal|"MIPS_KSEG0_END mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint64_t
operator|)
name|MIPS_KSEG1_START
operator|==
name|MIPS64_KSEG1_START
argument_list|,
literal|"MIPS_KSEG1_START mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint64_t
operator|)
name|MIPS_KSEG1_END
operator|==
name|MIPS64_KSEG1_END
argument_list|,
literal|"MIPS_KSEG1_END mismatch"
argument_list|)
assert|;
end_assert

begin_else
else|#
directive|else
end_else

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint32_t
operator|)
name|MIPS_KSEG0_START
operator|==
name|MIPS32_KSEG0_START
argument_list|,
literal|"MIPS_KSEG0_START mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint32_t
operator|)
name|MIPS_KSEG0_END
operator|==
name|MIPS32_KSEG0_END
argument_list|,
literal|"MIPS_KSEG0_END mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint32_t
operator|)
name|MIPS_KSEG1_START
operator|==
name|MIPS32_KSEG1_START
argument_list|,
literal|"MIPS_KSEG1_START mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|uint32_t
operator|)
name|MIPS_KSEG1_END
operator|==
name|MIPS32_KSEG1_END
argument_list|,
literal|"MIPS_KSEG1_END mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_assert
assert|_Static_assert
argument_list|(
name|TLBLO_PFN_MASK
operator|==
name|MIPS64_PFN_MASK
argument_list|,
literal|"TLBLO_PFN_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_else
else|#
directive|else
end_else

begin_assert
assert|_Static_assert
argument_list|(
name|TLBLO_PFN_MASK
operator|==
name|MIPS32_PFN_MASK
argument_list|,
literal|"TLBLO_PFN_MASK mismatch"
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
name|TLBLO_PFN_SHIFT
operator|==
name|MIPS_PFN_SHIFT
argument_list|,
literal|"TLBLO_PFN_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TLB_PAGE_SHIFT
operator|==
name|MIPS_PAGE_SHIFT
argument_list|,
literal|"TLB_PAGE_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__KVM_MIPS_H__ */
end_comment

end_unit

