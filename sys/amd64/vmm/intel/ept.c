begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|"vmx_cpufunc.h"
end_include

begin_include
include|#
directive|include
file|"vmm_ipi.h"
end_include

begin_include
include|#
directive|include
file|"ept.h"
end_include

begin_define
define|#
directive|define
name|EPT_SUPPORTS_EXEC_ONLY
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 0))
end_define

begin_define
define|#
directive|define
name|EPT_PWL4
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 6))
end_define

begin_define
define|#
directive|define
name|EPT_MEMORY_TYPE_WB
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 14))
end_define

begin_define
define|#
directive|define
name|EPT_PDE_SUPERPAGE
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 16))
end_define

begin_comment
comment|/* 2MB pages */
end_comment

begin_define
define|#
directive|define
name|EPT_PDPTE_SUPERPAGE
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 17))
end_define

begin_comment
comment|/* 1GB pages */
end_comment

begin_define
define|#
directive|define
name|INVEPT_SUPPORTED
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 20))
end_define

begin_define
define|#
directive|define
name|AD_BITS_SUPPORTED
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 21))
end_define

begin_define
define|#
directive|define
name|INVVPID_SUPPORTED
parameter_list|(
name|cap
parameter_list|)
value|((cap)& (1UL<< 32))
end_define

begin_define
define|#
directive|define
name|INVVPID_ALL_TYPES_MASK
value|0xF0000000000UL
end_define

begin_define
define|#
directive|define
name|INVVPID_ALL_TYPES_SUPPORTED
parameter_list|(
name|cap
parameter_list|)
define|\
value|(((cap)& INVVPID_ALL_TYPES_MASK) == INVVPID_ALL_TYPES_MASK)
end_define

begin_define
define|#
directive|define
name|INVEPT_ALL_TYPES_MASK
value|0x6000000UL
end_define

begin_define
define|#
directive|define
name|INVEPT_ALL_TYPES_SUPPORTED
parameter_list|(
name|cap
parameter_list|)
define|\
value|(((cap)& INVEPT_ALL_TYPES_MASK) == INVEPT_ALL_TYPES_MASK)
end_define

begin_define
define|#
directive|define
name|EPT_PWLEVELS
value|4
end_define

begin_comment
comment|/* page walk levels */
end_comment

begin_define
define|#
directive|define
name|EPT_ENABLE_AD_BITS
value|(1<< 6)
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_vmm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw_vmm
argument_list|,
name|OID_AUTO
argument_list|,
name|ept
argument_list|,
name|CTLFLAG_RW
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|ept_enable_ad_bits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ept_pmap_flags
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_ept
argument_list|,
name|OID_AUTO
argument_list|,
name|pmap_flags
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|ept_pmap_flags
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|ept_init
parameter_list|(
name|int
name|ipinum
parameter_list|)
block|{
name|int
name|use_hw_ad_bits
decl_stmt|,
name|use_superpages
decl_stmt|,
name|use_exec_only
decl_stmt|;
name|uint64_t
name|cap
decl_stmt|;
name|cap
operator|=
name|rdmsr
argument_list|(
name|MSR_VMX_EPT_VPID_CAP
argument_list|)
expr_stmt|;
comment|/* 	 * Verify that: 	 * - page walk length is 4 steps 	 * - extended page tables can be laid out in write-back memory 	 * - invvpid instruction with all possible types is supported 	 * - invept instruction with all possible types is supported 	 */
if|if
condition|(
operator|!
name|EPT_PWL4
argument_list|(
name|cap
argument_list|)
operator|||
operator|!
name|EPT_MEMORY_TYPE_WB
argument_list|(
name|cap
argument_list|)
operator|||
operator|!
name|INVVPID_SUPPORTED
argument_list|(
name|cap
argument_list|)
operator|||
operator|!
name|INVVPID_ALL_TYPES_SUPPORTED
argument_list|(
name|cap
argument_list|)
operator|||
operator|!
name|INVEPT_SUPPORTED
argument_list|(
name|cap
argument_list|)
operator|||
operator|!
name|INVEPT_ALL_TYPES_SUPPORTED
argument_list|(
name|cap
argument_list|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
name|ept_pmap_flags
operator|=
name|ipinum
operator|&
name|PMAP_NESTED_IPIMASK
expr_stmt|;
name|use_superpages
operator|=
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.vmm.ept.use_superpages"
argument_list|,
operator|&
name|use_superpages
argument_list|)
expr_stmt|;
if|if
condition|(
name|use_superpages
operator|&&
name|EPT_PDE_SUPERPAGE
argument_list|(
name|cap
argument_list|)
condition|)
name|ept_pmap_flags
operator||=
name|PMAP_PDE_SUPERPAGE
expr_stmt|;
comment|/* 2MB superpage */
name|use_hw_ad_bits
operator|=
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.vmm.ept.use_hw_ad_bits"
argument_list|,
operator|&
name|use_hw_ad_bits
argument_list|)
expr_stmt|;
if|if
condition|(
name|use_hw_ad_bits
operator|&&
name|AD_BITS_SUPPORTED
argument_list|(
name|cap
argument_list|)
condition|)
name|ept_enable_ad_bits
operator|=
literal|1
expr_stmt|;
else|else
name|ept_pmap_flags
operator||=
name|PMAP_EMULATE_AD_BITS
expr_stmt|;
name|use_exec_only
operator|=
literal|1
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.vmm.ept.use_exec_only"
argument_list|,
operator|&
name|use_exec_only
argument_list|)
expr_stmt|;
if|if
condition|(
name|use_exec_only
operator|&&
name|EPT_SUPPORTS_EXEC_ONLY
argument_list|(
name|cap
argument_list|)
condition|)
name|ept_pmap_flags
operator||=
name|PMAP_SUPPORTS_EXEC_ONLY
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static void ept_dump(uint64_t *ptp, int nlevels) { 	int i, t, tabs; 	uint64_t *ptpnext, ptpval;  	if (--nlevels< 0) 		return;  	tabs = 3 - nlevels; 	for (t = 0; t< tabs; t++) 		printf("\t"); 	printf("PTP = %p\n", ptp);  	for (i = 0; i< 512; i++) { 		ptpval = ptp[i];  		if (ptpval == 0) 			continue; 		 		for (t = 0; t< tabs; t++) 			printf("\t"); 		printf("%3d 0x%016lx\n", i, ptpval);  		if (nlevels != 0&& (ptpval& EPT_PG_SUPERPAGE) == 0) { 			ptpnext = (uint64_t *) 				  PHYS_TO_DMAP(ptpval& EPT_ADDR_MASK); 			ept_dump(ptpnext, nlevels); 		} 	} }
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|invept_single_context
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|invept_desc
name|desc
init|=
operator|*
operator|(
expr|struct
name|invept_desc
operator|*
operator|)
name|arg
decl_stmt|;
name|invept
argument_list|(
name|INVEPT_TYPE_SINGLE_CONTEXT
argument_list|,
name|desc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ept_invalidate_mappings
parameter_list|(
name|u_long
name|eptp
parameter_list|)
block|{
name|struct
name|invept_desc
name|invept_desc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|invept_desc
operator|.
name|eptp
operator|=
name|eptp
expr_stmt|;
name|smp_rendezvous
argument_list|(
name|NULL
argument_list|,
name|invept_single_context
argument_list|,
name|NULL
argument_list|,
operator|&
name|invept_desc
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|ept_pinit
parameter_list|(
name|pmap_t
name|pmap
parameter_list|)
block|{
return|return
operator|(
name|pmap_pinit_type
argument_list|(
name|pmap
argument_list|,
name|PT_EPT
argument_list|,
name|ept_pmap_flags
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|vmspace
modifier|*
name|ept_vmspace_alloc
parameter_list|(
name|vm_offset_t
name|min
parameter_list|,
name|vm_offset_t
name|max
parameter_list|)
block|{
return|return
operator|(
name|vmspace_alloc
argument_list|(
name|min
argument_list|,
name|max
argument_list|,
name|ept_pinit
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ept_vmspace_free
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
block|{
name|vmspace_free
argument_list|(
name|vmspace
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|uint64_t
name|eptp
parameter_list|(
name|uint64_t
name|pml4
parameter_list|)
block|{
name|uint64_t
name|eptp_val
decl_stmt|;
name|eptp_val
operator|=
name|pml4
operator||
operator|(
name|EPT_PWLEVELS
operator|-
literal|1
operator|)
operator|<<
literal|3
operator||
name|PAT_WRITE_BACK
expr_stmt|;
if|if
condition|(
name|ept_enable_ad_bits
condition|)
name|eptp_val
operator||=
name|EPT_ENABLE_AD_BITS
expr_stmt|;
return|return
operator|(
name|eptp_val
operator|)
return|;
block|}
end_function

end_unit

