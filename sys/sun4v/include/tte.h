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
value|(4)
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
name|TD_PA_CH_BITS
value|(30)
end_define

begin_define
define|#
directive|define
name|TD_PA_SF_BITS
value|(28)
end_define

begin_define
define|#
directive|define
name|TD_PA_BITS
value|(42)
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
name|TD_PA_CH_MASK
value|((1UL<< TD_PA_CH_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|TD_PA_SF_MASK
value|((1UL<< TD_PA_SF_BITS) - 1)
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
name|TTE8K
value|(0UL)
end_define

begin_define
define|#
directive|define
name|TTE64K
value|(1UL)
end_define

begin_define
define|#
directive|define
name|TTE512K
value|(2UL)
end_define

begin_define
define|#
directive|define
name|TTE4M
value|(3UL)
end_define

begin_define
define|#
directive|define
name|TTE32M
value|(4UL)
end_define

begin_define
define|#
directive|define
name|TTE256M
value|(5UL)
end_define

begin_define
define|#
directive|define
name|TTE2G
value|(6UL)
end_define

begin_define
define|#
directive|define
name|TTE16G
value|(7UL)
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
name|tte_data
parameter_list|)
define|\
value|(tte_data& (TD_PA_MASK<< TD_PA_SHIFT))
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

begin_define
define|#
directive|define
name|PTE_SHIFT
value|(3)
end_define

begin_define
define|#
directive|define
name|PT_SHIFT
value|(PAGE_SHIFT - PTE_SHIFT)
end_define

begin_define
define|#
directive|define
name|VTD_SOFT_SHIFT
value|(56)
end_define

begin_define
define|#
directive|define
name|VTD_V
value|(1UL<< 63)
end_define

begin_define
define|#
directive|define
name|VTD_NFO
value|(1UL<< 62)
end_define

begin_define
define|#
directive|define
name|VTD_PA
parameter_list|(
name|pa
parameter_list|)
value|((pa)& (TD_PA_MASK<< TD_PA_SHIFT))
end_define

begin_define
define|#
directive|define
name|VTD_IE
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|VTD_E
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|VTD_CP
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|VTD_CV
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|VTD_P
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|VTD_X
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|VTD_W
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|VTD_REF
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|VTD_SW_W
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|VTD_MANAGED
value|(1UL<< 58)
end_define

begin_define
define|#
directive|define
name|VTD_WIRED
value|(1UL<< 57)
end_define

begin_define
define|#
directive|define
name|VTD_LOCK
value|(1UL<< 56)
end_define

begin_define
define|#
directive|define
name|VTD_8K
value|TTE8K
end_define

begin_define
define|#
directive|define
name|VTD_64K
value|TTE64K
end_define

begin_define
define|#
directive|define
name|VTD_512K
value|TTE512K
end_define

begin_define
define|#
directive|define
name|VTD_4M
value|TTE4M
end_define

begin_define
define|#
directive|define
name|VTD_32M
value|TTE32M
end_define

begin_define
define|#
directive|define
name|VTD_256M
value|TTE256M
end_define

begin_comment
comment|/*  * sparc64 compatibility for the loader  */
end_comment

begin_define
define|#
directive|define
name|TD_SIZE_SHIFT
value|(61)
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
name|TD_V
value|(1UL<< 63)
end_define

begin_define
define|#
directive|define
name|TD_4M
value|(TS_4M<< TD_SIZE_SHIFT)
end_define

begin_comment
comment|/*  * default flags for kernel pages  */
end_comment

begin_define
define|#
directive|define
name|TTE_KERNEL
value|VTD_V | VTD_CP | VTD_CV | VTD_P | VTD_X | VTD_W | VTD_SW_W | VTD_REF | VTD_WIRED
end_define

begin_define
define|#
directive|define
name|TTE_KERNEL_MINFLAGS
value|VTD_P
end_define

begin_define
define|#
directive|define
name|TTE_MINFLAGS
value|VTD_V | VTD_CP | VTD_CV
end_define

begin_define
define|#
directive|define
name|VTD_SIZE_BITS
value|(4)
end_define

begin_define
define|#
directive|define
name|VTD_SIZE_MASK
value|((1<< VTD_SIZE_BITS) - 1)
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
name|tte_data
parameter_list|)
define|\
value|(tte_data& VTD_SIZE_MASK)
end_define

begin_define
define|#
directive|define
name|TTE_GET_PAGE_SHIFT
parameter_list|(
name|tte_data
parameter_list|)
define|\
value|TTE_PAGE_SHIFT(TTE_GET_SIZE(tte_data))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
name|tte
block|{
name|unsigned
name|int
name|v
range|:
literal|1
decl_stmt|;
comment|/*<63> valid */
name|unsigned
name|int
name|nfo
range|:
literal|1
decl_stmt|;
comment|/*<62> non-fault only */
name|unsigned
name|int
name|sw
range|:
literal|3
decl_stmt|;
comment|/*<61:59> sw */
name|unsigned
name|int
name|managed
range|:
literal|1
decl_stmt|;
comment|/*<58> managed */
name|unsigned
name|int
name|wired
range|:
literal|1
decl_stmt|;
comment|/*<57> wired */
name|unsigned
name|int
name|lock
range|:
literal|1
decl_stmt|;
comment|/*<56> sw - locked */
name|unsigned
name|long
name|pa
range|:
literal|43
decl_stmt|;
comment|/*<55:13> pa */
name|unsigned
name|int
name|ie
range|:
literal|1
decl_stmt|;
comment|/*<12> 1=invert endianness */
name|unsigned
name|int
name|e
range|:
literal|1
decl_stmt|;
comment|/*<11> side effect */
name|unsigned
name|int
name|cp
range|:
literal|1
decl_stmt|;
comment|/*<10> physically cache */
name|unsigned
name|int
name|cv
range|:
literal|1
decl_stmt|;
comment|/*<9> virtually cache */
name|unsigned
name|int
name|p
range|:
literal|1
decl_stmt|;
comment|/*<8> privilege required */
name|unsigned
name|int
name|x
range|:
literal|1
decl_stmt|;
comment|/*<7> execute perm */
name|unsigned
name|int
name|w
range|:
literal|1
decl_stmt|;
comment|/*<6> write perm */
name|unsigned
name|int
name|ref
range|:
literal|1
decl_stmt|;
comment|/*<5> sw - ref */
name|unsigned
name|int
name|wr_perm
range|:
literal|1
decl_stmt|;
comment|/*<4> sw - write perm */
name|unsigned
name|int
name|rsvd
range|:
literal|1
decl_stmt|;
comment|/*<3> reserved */
name|unsigned
name|int
name|sz
range|:
literal|3
decl_stmt|;
comment|/*<2:0> pagesize */
block|}
name|tte_bit
struct|;
name|uint64_t
name|ll
decl_stmt|;
block|}
name|tte_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tte_val
value|tte_bit.v
end_define

begin_comment
comment|/* use< 0 check in asm */
end_comment

begin_define
define|#
directive|define
name|tte_size
value|tte_bit.sz
end_define

begin_define
define|#
directive|define
name|tte_nfo
value|tte_bit.nfo
end_define

begin_define
define|#
directive|define
name|tte_ie
value|tte_bit.ie
end_define

begin_define
define|#
directive|define
name|tte_wired
value|tte_bit.wired
end_define

begin_define
define|#
directive|define
name|tte_pa
value|tte_bit.pa
end_define

begin_define
define|#
directive|define
name|tte_ref
value|tte_bit.ref
end_define

begin_define
define|#
directive|define
name|tte_wr_perm
value|tte_bit.wr_perm
end_define

begin_define
define|#
directive|define
name|tte_exec_perm
value|tte_bit.x
end_define

begin_define
define|#
directive|define
name|tte_lock
value|tte_bit.lock
end_define

begin_define
define|#
directive|define
name|tte_cp
value|tte_bit.cp
end_define

begin_define
define|#
directive|define
name|tte_cv
value|tte_bit.cv
end_define

begin_define
define|#
directive|define
name|tte_se
value|tte_bit.e
end_define

begin_define
define|#
directive|define
name|tte_priv
value|tte_bit.p
end_define

begin_define
define|#
directive|define
name|tte_hwwr
value|tte_bit.w
end_define

begin_define
define|#
directive|define
name|TTE_IS_VALID
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_inthi< 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_INVALID
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_val = 0)
end_define

begin_define
define|#
directive|define
name|TTE_IS_8K
parameter_list|(
name|ttep
parameter_list|)
value|(TTE_CSZ(ttep) == TTE8K)
end_define

begin_define
define|#
directive|define
name|TTE_IS_WIRED
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_wired)
end_define

begin_define
define|#
directive|define
name|TTE_IS_WRITABLE
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_wr_perm)
end_define

begin_define
define|#
directive|define
name|TTE_IS_EXECUTABLE
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_exec_perm)
end_define

begin_define
define|#
directive|define
name|TTE_IS_PRIVILEGED
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_priv)
end_define

begin_define
define|#
directive|define
name|TTE_IS_NOSYNC
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_no_sync)
end_define

begin_define
define|#
directive|define
name|TTE_IS_LOCKED
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_lock)
end_define

begin_define
define|#
directive|define
name|TTE_IS_SIDEFFECT
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_se)
end_define

begin_define
define|#
directive|define
name|TTE_IS_NFO
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_nfo)
end_define

begin_define
define|#
directive|define
name|TTE_IS_REF
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_ref)
end_define

begin_define
define|#
directive|define
name|TTE_IS_MOD
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_hwwr)
end_define

begin_define
define|#
directive|define
name|TTE_IS_IE
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_ie)
end_define

begin_define
define|#
directive|define
name|TTE_SET_SUSPEND
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_suspend = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_SUSPEND
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_suspend = 0)
end_define

begin_define
define|#
directive|define
name|TTE_IS_SUSPEND
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_suspend)
end_define

begin_define
define|#
directive|define
name|TTE_SET_REF
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_ref = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_REF
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_ref = 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_LOCKED
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_lock = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_LOCKED
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_lock = 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_MOD
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_hwwr = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_MOD
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_hwwr = 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_RM
parameter_list|(
name|ttep
parameter_list|)
define|\
value|(((ttep)->tte_intlo) =						\ 	(ttep)->tte_intlo | TTE_HWWR_INT | TTE_REF_INT)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_RM
parameter_list|(
name|ttep
parameter_list|)
define|\
value|(((ttep)->tte_intlo) =						\ 	(ttep)->tte_intlo& ~(TTE_HWWR_INT | TTE_REF_INT))
end_define

begin_define
define|#
directive|define
name|TTE_SET_WRT
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_wr_perm = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_WRT
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_wr_perm = 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_EXEC
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_exec_perm = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_EXEC
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_exec_perm = 0)
end_define

begin_define
define|#
directive|define
name|TTE_SET_PRIV
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_priv = 1)
end_define

begin_define
define|#
directive|define
name|TTE_CLR_PRIV
parameter_list|(
name|ttep
parameter_list|)
value|((ttep)->tte_priv = 0)
end_define

begin_define
define|#
directive|define
name|TTE_BSZS_SHIFT
parameter_list|(
name|sz
parameter_list|)
value|((sz) * 3)
end_define

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|tte_clear_phys_bit
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_set_phys_bit
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|tte_get_phys_bit
parameter_list|(
name|vm_page_t
name|m
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_clear_virt_bit
parameter_list|(
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tte_set_virt_bit
parameter_list|(
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|tte_get_virt_bit
parameter_list|(
name|struct
name|pmap
modifier|*
name|pmap
parameter_list|,
name|vm_offset_t
name|va
parameter_list|,
name|uint64_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TTE_H_ */
end_comment

end_unit

