begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: BSDI: pmap.v9.h,v 1.10.2.6 1999/08/23 22:18:44 cp Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TTE_H_
end_define

begin_define
define|#
directive|define
name|TTE_SHIFT
value|(5)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_SHIFT
value|(61)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_SHIFT
value|(50)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_SHIFT
value|(41)
end_define

begin_define
define|#
directive|define
name|TD_PA_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_SHIFT
value|(7)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_BITS
value|(2)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_BITS
value|(9)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_BITS
value|(9)
end_define

begin_define
define|#
directive|define
name|TD_PA_BITS
value|(28)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_BITS
value|(6)
end_define

begin_define
define|#
directive|define
name|TD_SIZE_MASK
value|((1UL<< TD_SIZE_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TD_SOFT2_MASK
value|((1UL<< TD_SOFT2_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TD_DIAG_MASK
value|((1UL<< TD_DIAG_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TD_PA_MASK
value|((1UL<< TD_PA_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TD_SOFT_MASK
value|((1UL<< TD_SOFT_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TS_8K
value|(0UL)
end_define

begin_define
define|#
directive|define
name|TS_64K
value|(1UL)
end_define

begin_define
define|#
directive|define
name|TS_512K
value|(2UL)
end_define

begin_define
define|#
directive|define
name|TS_4M
value|(3UL)
end_define

begin_define
define|#
directive|define
name|TS_MIN
value|TS_8K
end_define

begin_define
define|#
directive|define
name|TS_MAX
value|TS_4M
end_define

begin_define
define|#
directive|define
name|TD_V
value|(1UL<< 63)
end_define

begin_define
define|#
directive|define
name|TD_8K
value|(TS_8K<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_64K
value|(TS_64K<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_512K
value|(TS_512K<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_4M
value|(TS_4M<< TD_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_NFO
value|(1UL<< 60)
end_define

begin_define
define|#
directive|define
name|TD_IE
value|(1UL<< 59)
end_define

begin_define
define|#
directive|define
name|TD_PA
parameter_list|(
name|pa
parameter_list|)
value|((pa)& (TD_PA_MASK<< TD_PA_SHIFT))
end_define

begin_comment
comment|/* NOTE: bit 6 of TD_SOFT will be sign-extended if used as an immediate. */
end_comment

begin_define
define|#
directive|define
name|TD_FAKE
value|((1UL<< 5)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_EXEC
value|((1UL<< 4)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_REF
value|((1UL<< 3)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_PV
value|((1UL<< 2)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_SW
value|((1UL<< 1)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_WIRED
value|((1UL<< 0)<< TD_SOFT_SHIFT)
end_define

begin_define
define|#
directive|define
name|TD_L
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TD_CP
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TD_CV
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|TD_E
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TD_P
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TD_W
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TD_G
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TV_SIZE_BITS
value|(TD_SIZE_BITS)
end_define

begin_define
define|#
directive|define
name|TV_VPN
parameter_list|(
name|va
parameter_list|,
name|sz
parameter_list|)
value|((((va)>> TTE_PAGE_SHIFT(sz))<< TV_SIZE_BITS) | sz)
end_define

begin_define
define|#
directive|define
name|TTE_SIZE_SPREAD
value|(3)
end_define

begin_define
define|#
directive|define
name|TTE_PAGE_SHIFT
parameter_list|(
name|sz
parameter_list|)
define|\
value|(PAGE_SHIFT + ((sz) * TTE_SIZE_SPREAD))
end_define

begin_define
define|#
directive|define
name|TTE_GET_SIZE
parameter_list|(
name|tp
parameter_list|)
define|\
value|(((tp)->tte_data>> TD_SIZE_SHIFT)& TD_SIZE_MASK)
end_define

begin_define
define|#
directive|define
name|TTE_GET_PAGE_SHIFT
parameter_list|(
name|tp
parameter_list|)
define|\
value|TTE_PAGE_SHIFT(TTE_GET_SIZE(tp))
end_define

begin_define
define|#
directive|define
name|TTE_GET_PAGE_SIZE
parameter_list|(
name|tp
parameter_list|)
define|\
value|(1<< TTE_GET_PAGE_SHIFT(tp))
end_define

begin_define
define|#
directive|define
name|TTE_GET_PAGE_MASK
parameter_list|(
name|tp
parameter_list|)
define|\
value|(TTE_GET_PAGE_SIZE(tp) - 1)
end_define

begin_define
define|#
directive|define
name|TTE_GET_PA
parameter_list|(
name|tp
parameter_list|)
define|\
value|((tp)->tte_data& (TD_PA_MASK<< TD_PA_SHIFT))
end_define

begin_define
define|#
directive|define
name|TTE_GET_VPN
parameter_list|(
name|tp
parameter_list|)
define|\
value|((tp)->tte_vpn>> TV_SIZE_BITS)
end_define

begin_define
define|#
directive|define
name|TTE_GET_VA
parameter_list|(
name|tp
parameter_list|)
define|\
value|(TTE_GET_VPN(tp)<< TTE_GET_PAGE_SHIFT(tp))
end_define

begin_define
define|#
directive|define
name|TTE_GET_PMAP
parameter_list|(
name|tp
parameter_list|)
define|\
value|(((tp)->tte_data& TD_P) != 0 ? \ 	 (kernel_pmap) : \ 	 (PHYS_TO_VM_PAGE(pmap_kextract((vm_offset_t)(tp)))->md.pmap))
end_define

begin_define
define|#
directive|define
name|TTE_ZERO
parameter_list|(
name|tp
parameter_list|)
define|\
value|memset(tp, 0, sizeof(*tp))
end_define

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|tte
block|{
name|u_long
name|tte_vpn
decl_stmt|;
name|u_long
name|tte_data
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|tte
argument_list|)
name|tte_link
expr_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|tte_match
parameter_list|(
name|struct
name|tte
modifier|*
name|tp
parameter_list|,
name|vm_offset_t
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
name|TD_V
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
name|TV_VPN
argument_list|(
name|va
argument_list|,
name|TTE_GET_SIZE
argument_list|(
name|tp
argument_list|)
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TTE_H_ */
end_comment

end_unit

