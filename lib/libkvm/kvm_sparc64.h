begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_SPARC64_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_SPARC64_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_include
include|#
directive|include
file|<machine/tte.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPARC64_PAGE_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|SPARC64_PAGE_SIZE
value|(1<< SPARC64_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPARC64_PAGE_MASK
value|(SPARC64_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|SPARC64_MIN_DIRECT_ADDRESS
value|(0xfffff80000000000)
end_define

begin_define
define|#
directive|define
name|SPARC64_DIRECT_ADDRESS_BITS
value|(43)
end_define

begin_define
define|#
directive|define
name|SPARC64_DIRECT_ADDRESS_MASK
define|\
value|(((uint64_t)1<< SPARC64_DIRECT_ADDRESS_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|SPARC64_DIRECT_TO_PHYS
parameter_list|(
name|va
parameter_list|)
value|((va)& SPARC64_DIRECT_ADDRESS_MASK)
end_define

begin_define
define|#
directive|define
name|SPARC64_TTE_SHIFT
value|(5)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_SIZE_SHIFT
value|(61)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_PA_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_SIZE_BITS
value|(2)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_PA_CH_BITS
value|(30)
end_define

begin_comment
comment|/* US-III{,i,+}, US-IV{,+}, SPARC64 V */
end_comment

begin_define
define|#
directive|define
name|SPARC64_TD_PA_BITS
value|SPARC64_TD_PA_CH_BITS
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_SIZE_MASK
value|(((uint64_t)1<< SPARC64_TD_SIZE_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_PA_MASK
value|(((uint64_t)1<< SPARC64_TD_PA_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|SPARC64_TD_V
value|((uint64_t)1<< 63)
end_define

begin_define
define|#
directive|define
name|SPARC64_TV_SIZE_BITS
value|(SPARC64_TD_SIZE_BITS)
end_define

begin_define
define|#
directive|define
name|SPARC64_TV_VPN
parameter_list|(
name|va
parameter_list|,
name|sz
parameter_list|)
define|\
value|((((va)>> SPARC64_TTE_PAGE_SHIFT(sz))<< SPARC64_TV_SIZE_BITS) | sz)
end_define

begin_define
define|#
directive|define
name|SPARC64_TTE_SIZE_SPREAD
value|(3)
end_define

begin_define
define|#
directive|define
name|SPARC64_TTE_PAGE_SHIFT
parameter_list|(
name|sz
parameter_list|)
define|\
value|(SPARC64_PAGE_SHIFT + ((sz) * SPARC64_TTE_SIZE_SPREAD))
end_define

begin_define
define|#
directive|define
name|SPARC64_TTE_GET_SIZE
parameter_list|(
name|tp
parameter_list|)
define|\
value|(((tp)->tte_data>> SPARC64_TD_SIZE_SHIFT)& SPARC64_TD_SIZE_MASK)
end_define

begin_define
define|#
directive|define
name|SPARC64_TTE_GET_PA
parameter_list|(
name|tp
parameter_list|)
define|\
value|((tp)->tte_data& (SPARC64_TD_PA_MASK<< SPARC64_TD_PA_SHIFT))
end_define

begin_struct
struct|struct
name|sparc64_tte
block|{
name|uint64_t
name|tte_vpn
decl_stmt|;
name|uint64_t
name|tte_data
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|sparc64_tte_match
parameter_list|(
name|struct
name|sparc64_tte
modifier|*
name|tp
parameter_list|,
name|kvaddr_t
name|va
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|tp
operator|->
name|tte_data
operator|&
name|SPARC64_TD_V
operator|)
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|tp
operator|->
name|tte_vpn
operator|==
name|SPARC64_TV_VPN
argument_list|(
name|va
argument_list|,
name|SPARC64_TTE_GET_SIZE
argument_list|(
name|tp
argument_list|)
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|SPARC64_PAGE_SHIFT
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
name|SPARC64_PAGE_SIZE
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
name|SPARC64_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|VM_MIN_DIRECT_ADDRESS
operator|==
name|SPARC64_MIN_DIRECT_ADDRESS
argument_list|,
literal|"VM_MIN_DIRECT_ADDRESS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TLB_DIRECT_ADDRESS_BITS
operator|==
name|SPARC64_DIRECT_ADDRESS_BITS
argument_list|,
literal|"TLB_DIRECT_ADDRESS_BITS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TLB_DIRECT_ADDRESS_MASK
operator|==
name|SPARC64_DIRECT_ADDRESS_MASK
argument_list|,
literal|"TLB_DIRECT_ADDRESS_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TTE_SHIFT
operator|==
name|SPARC64_TTE_SHIFT
argument_list|,
literal|"TTE_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_SIZE_SHIFT
operator|==
name|SPARC64_TD_SIZE_SHIFT
argument_list|,
literal|"TD_SIZE_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_PA_SHIFT
operator|==
name|SPARC64_TD_PA_SHIFT
argument_list|,
literal|"TD_PA_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_SIZE_BITS
operator|==
name|SPARC64_TD_SIZE_BITS
argument_list|,
literal|"TD_SIZE_BITS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_PA_BITS
operator|==
name|SPARC64_TD_PA_BITS
argument_list|,
literal|"TD_PA_BITS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_SIZE_MASK
operator|==
name|SPARC64_TD_SIZE_MASK
argument_list|,
literal|"TD_SIZE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_PA_MASK
operator|==
name|SPARC64_TD_PA_MASK
argument_list|,
literal|"TD_PA_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TD_V
operator|==
name|SPARC64_TD_V
argument_list|,
literal|"TD_V mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TV_SIZE_BITS
operator|==
name|SPARC64_TV_SIZE_BITS
argument_list|,
literal|"TV_SIZE_BITS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|TTE_SIZE_SPREAD
operator|==
name|SPARC64_TTE_SIZE_SPREAD
argument_list|,
literal|"TTE_SIZE_SPREAD mismatch"
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
comment|/* !__KVM_SPARC64_H__ */
end_comment

end_unit

