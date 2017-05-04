begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016, Anish Gupta (anish@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
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
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<machine/pci_cfgreg.h>
end_include

begin_include
include|#
directive|include
file|"pcib_if.h"
end_include

begin_include
include|#
directive|include
file|"io/iommu.h"
end_include

begin_include
include|#
directive|include
file|"amdvi_priv.h"
end_include

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
name|amdvi
argument_list|,
name|CTLFLAG_RW
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MOD_INC
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|m
parameter_list|)
value|(((a) + (s)) % ((m) * (s)))
end_define

begin_define
define|#
directive|define
name|MOD_DEC
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|m
parameter_list|)
value|(((a) - (s)) % ((m) * (s)))
end_define

begin_comment
comment|/* Print RID or device ID in PCI string format. */
end_comment

begin_define
define|#
directive|define
name|RID2PCI_STR
parameter_list|(
name|d
parameter_list|)
value|PCI_RID2BUS(d), PCI_RID2SLOT(d), PCI_RID2FUNC(d)
end_define

begin_function_decl
specifier|static
name|void
name|amdvi_dump_cmds
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|amdvi_print_dev_cap
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_AMDVI
argument_list|,
literal|"amdvi"
argument_list|,
literal|"amdvi"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|device_t
modifier|*
name|ivhd_devs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ivhd_count
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|count
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|ivhd_count
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|amdvi_enable_user
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|enable
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|amdvi_enable_user
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.vmm.amdvi_enable"
argument_list|,
operator|&
name|amdvi_enable_user
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AMDVI_ATS_ENABLE
end_ifdef

begin_comment
comment|/* XXX: ATS is not tested. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amdvi_enable_iotlb
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|iotlb_enabled
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|amdvi_enable_iotlb
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.vmm.enable_iotlb"
argument_list|,
operator|&
name|amdvi_enable_iotlb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|amdvi_host_ptp
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use page tables for host. */
end_comment

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|host_ptp
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|amdvi_host_ptp
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.vmm.amdvi.host_ptp"
argument_list|,
operator|&
name|amdvi_host_ptp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Page table level used<= supported by h/w[v1=7]. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amdvi_ptp_level
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|ptp_level
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|amdvi_ptp_level
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.vmm.amdvi.ptp_level"
argument_list|,
operator|&
name|amdvi_ptp_level
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Disable fault event reporting. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amdvi_disable_io_fault
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|disable_io_fault
argument_list|,
name|CTLFLAG_RDTUN
argument_list|,
operator|&
name|amdvi_disable_io_fault
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"hw.vmm.amdvi.disable_io_fault"
argument_list|,
operator|&
name|amdvi_disable_io_fault
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|amdvi_dom_id
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 is reserved for host. */
end_comment

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_hw_vmm_amdvi
argument_list|,
name|OID_AUTO
argument_list|,
name|domain_id
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|amdvi_dom_id
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Device table entry.  * Bus(256) x Dev(32) x Fun(8) x DTE(256 bits or 32 bytes).  *	= 256 * 2 * PAGE_SIZE.  */
end_comment

begin_function_decl
specifier|static
name|struct
name|amdvi_dte
name|amdvi_dte
index|[
name|PCI_NUM_DEV_MAX
index|]
name|__aligned
parameter_list|(
name|PAGE_SIZE
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|CTASSERT
argument_list|(
name|PCI_NUM_DEV_MAX
operator|==
literal|0x10000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|amdvi_dte
argument_list|)
operator|==
literal|0x200000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|amdvi_domain
argument_list|)
name|dom_head
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|void
name|amdvi_pci_write
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|int
name|off
parameter_list|,
name|uint32_t
name|data
parameter_list|)
block|{
name|pci_cfgregwrite
argument_list|(
name|PCI_RID2BUS
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|PCI_RID2SLOT
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|PCI_RID2FUNC
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|off
argument_list|,
name|data
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|amdvi_pci_read
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|int
name|off
parameter_list|)
block|{
return|return
operator|(
name|pci_cfgregread
argument_list|(
name|PCI_RID2BUS
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|PCI_RID2SLOT
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|PCI_RID2FUNC
argument_list|(
name|softc
operator|->
name|pci_rid
argument_list|)
argument_list|,
name|off
argument_list|,
literal|4
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|amdvi_find_pci_cap
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint8_t
name|capability
parameter_list|,
name|int
modifier|*
name|off
parameter_list|)
block|{
name|uint32_t
name|read
decl_stmt|;
name|uint8_t
name|ptr
decl_stmt|;
name|read
operator|=
name|amdvi_pci_read
argument_list|(
name|softc
argument_list|,
name|PCIR_COMMAND
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|read
operator|>>
literal|16
operator|)
operator|&
name|PCIM_STATUS_CAPPRESENT
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* Read the starting of capability pointer. */
name|read
operator|=
name|amdvi_pci_read
argument_list|(
name|softc
argument_list|,
name|PCIR_CAP_PTR
argument_list|)
expr_stmt|;
name|ptr
operator|=
name|read
operator|&
literal|0xFF
expr_stmt|;
while|while
condition|(
name|ptr
operator|!=
literal|0
condition|)
block|{
name|read
operator|=
name|amdvi_pci_read
argument_list|(
name|softc
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|read
operator|&
literal|0xFF
operator|)
operator|==
name|capability
condition|)
block|{
operator|*
name|off
operator|=
name|ptr
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|ptr
operator|=
operator|(
name|read
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
expr_stmt|;
block|}
return|return
operator|(
name|ENOENT
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|AMDVI_ATS_ENABLE
end_ifdef

begin_comment
comment|/* XXX: Should be in pci.c */
end_comment

begin_comment
comment|/*  * Check if device has ATS capability and its enabled.  * If ATS is absent or disabled, return (-1), otherwise ATS  * queue length.  */
end_comment

begin_function
specifier|static
name|int
name|amdvi_find_ats_qlen
parameter_list|(
name|uint16_t
name|devid
parameter_list|)
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|off
decl_stmt|,
name|cap
decl_stmt|;
name|int
name|qlen
init|=
operator|-
literal|1
decl_stmt|;
name|dev
operator|=
name|pci_find_bsf
argument_list|(
name|PCI_RID2BUS
argument_list|(
name|devid
argument_list|)
argument_list|,
name|PCI_RID2SLOT
argument_list|(
name|devid
argument_list|)
argument_list|,
name|PCI_RID2FUNC
argument_list|(
name|devid
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
define|#
directive|define
name|PCIM_ATS_EN
value|BIT(31)
if|if
condition|(
name|pci_find_extcap
argument_list|(
name|dev
argument_list|,
name|PCIZ_ATS
argument_list|,
operator|&
name|off
argument_list|)
operator|==
literal|0
condition|)
block|{
name|cap
operator|=
name|pci_read_config
argument_list|(
name|dev
argument_list|,
name|off
operator|+
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|qlen
operator|=
operator|(
name|cap
operator|&
literal|0x1F
operator|)
expr_stmt|;
name|qlen
operator|=
name|qlen
condition|?
name|qlen
else|:
literal|32
expr_stmt|;
name|printf
argument_list|(
literal|"AMD-Vi: PCI device %d.%d.%d ATS %s qlen=%d\n"
argument_list|,
name|RID2PCI_STR
argument_list|(
name|devid
argument_list|)
argument_list|,
operator|(
name|cap
operator|&
name|PCIM_ATS_EN
operator|)
condition|?
literal|"enabled"
else|:
literal|"Disabled"
argument_list|,
name|qlen
argument_list|)
expr_stmt|;
name|qlen
operator|=
operator|(
name|cap
operator|&
name|PCIM_ATS_EN
operator|)
condition|?
name|qlen
else|:
operator|-
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|qlen
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Check if an endpoint device support device IOTLB or ATS.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|amdvi_dev_support_iotlb
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
block|{
name|struct
name|ivhd_dev_cfg
modifier|*
name|cfg
decl_stmt|;
name|int
name|qlen
decl_stmt|,
name|i
decl_stmt|;
name|bool
name|pci_ats
decl_stmt|,
name|ivhd_ats
decl_stmt|;
name|qlen
operator|=
name|amdvi_find_ats_qlen
argument_list|(
name|devid
argument_list|)
expr_stmt|;
if|if
condition|(
name|qlen
operator|<
literal|0
condition|)
return|return
operator|(
name|false
operator|)
return|;
name|KASSERT
argument_list|(
name|softc
argument_list|,
operator|(
literal|"softc is NULL"
operator|)
argument_list|)
expr_stmt|;
name|cfg
operator|=
name|softc
operator|->
name|dev_cfg
expr_stmt|;
name|ivhd_ats
operator|=
name|false
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|softc
operator|->
name|dev_cfg_cnt
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|cfg
operator|->
name|start_id
operator|<=
name|devid
operator|)
operator|&&
operator|(
name|cfg
operator|->
name|end_id
operator|>=
name|devid
operator|)
condition|)
block|{
name|ivhd_ats
operator|=
name|cfg
operator|->
name|enable_ats
expr_stmt|;
break|break;
block|}
name|cfg
operator|++
expr_stmt|;
block|}
name|pci_ats
operator|=
operator|(
name|qlen
operator|<
literal|0
operator|)
condition|?
name|false
else|:
name|true
expr_stmt|;
if|if
condition|(
name|pci_ats
operator|!=
name|ivhd_ats
condition|)
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"BIOS bug: mismatch in ATS setting for %d.%d.%d,"
literal|"ATS inv qlen = %d\n"
argument_list|,
name|RID2PCI_STR
argument_list|(
name|devid
argument_list|)
argument_list|,
name|qlen
argument_list|)
expr_stmt|;
comment|/* Ignore IVRS setting and respect PCI setting. */
return|return
operator|(
name|pci_ats
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable IOTLB support for IOMMU if its supported. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|amdvi_hw_enable_iotlb
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|AMDVI_ATS_ENABLE
name|softc
operator|->
name|iotlb
operator|=
name|false
expr_stmt|;
else|#
directive|else
name|bool
name|supported
decl_stmt|;
name|supported
operator|=
operator|(
name|softc
operator|->
name|ivhd_flag
operator|&
name|IVHD_FLAG_IOTLB
operator|)
condition|?
name|true
else|:
name|false
expr_stmt|;
if|if
condition|(
name|softc
operator|->
name|pci_cap
operator|&
name|AMDVI_PCI_CAP_IOTLB
condition|)
block|{
if|if
condition|(
operator|!
name|supported
condition|)
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"IOTLB disabled by BIOS.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|supported
operator|&&
operator|!
name|amdvi_enable_iotlb
condition|)
block|{
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"IOTLB disabled by user.\n"
argument_list|)
expr_stmt|;
name|supported
operator|=
name|false
expr_stmt|;
block|}
block|}
else|else
name|supported
operator|=
name|false
expr_stmt|;
name|softc
operator|->
name|iotlb
operator|=
name|supported
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|int
name|amdvi_init_cmd
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
block|{
name|struct
name|amdvi_ctrl
modifier|*
name|ctrl
init|=
name|softc
operator|->
name|ctrl
decl_stmt|;
name|ctrl
operator|->
name|cmd
operator|.
name|len
operator|=
literal|8
expr_stmt|;
comment|/* Use 256 command buffer entries. */
name|softc
operator|->
name|cmd_max
operator|=
literal|1
operator|<<
name|ctrl
operator|->
name|cmd
operator|.
name|len
expr_stmt|;
name|softc
operator|->
name|cmd
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|amdvi_cmd
argument_list|)
operator|*
name|softc
operator|->
name|cmd_max
argument_list|,
name|M_AMDVI
argument_list|,
name|M_WAITOK
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|uintptr_t
operator|)
name|softc
operator|->
name|cmd
operator|&
name|PAGE_MASK
condition|)
name|panic
argument_list|(
literal|"AMDVi: Command buffer not aligned on page boundary."
argument_list|)
expr_stmt|;
name|ctrl
operator|->
name|cmd
operator|.
name|base
operator|=
name|vtophys
argument_list|(
name|softc
operator|->
name|cmd
argument_list|)
operator|/
name|PAGE_SIZE
expr_stmt|;
comment|/* 	 * XXX: Reset the h/w pointers in case IOMMU is restarting, 	 * h/w doesn't clear these pointers based on empirical data. 	 */
name|ctrl
operator|->
name|cmd_tail
operator|=
literal|0
expr_stmt|;
name|ctrl
operator|->
name|cmd_head
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Note: Update tail pointer after we have written the command since tail  * pointer update cause h/w to execute new commands, see section 3.3  * of AMD IOMMU spec ver 2.0.  */
end_comment

begin_comment
comment|/* Get the command tail pointer w/o updating it. */
end_comment

begin_function
specifier|static
name|struct
name|amdvi_cmd
modifier|*
name|amdvi_get_cmd_tail
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
block|{
name|struct
name|amdvi_ctrl
modifier|*
name|ctrl
decl_stmt|;
name|struct
name|amdvi_cmd
modifier|*
name|tail
decl_stmt|;
name|KASSERT
argument_list|(
name|softc
argument_list|,
operator|(
literal|"softc is NULL"
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|softc
operator|->
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|ctrl
operator|=
name|softc
operator|->
name|ctrl
expr_stmt|;
name|KASSERT
argument_list|(
name|ctrl
operator|!=
name|NULL
argument_list|,
operator|(
literal|"ctrl is NULL"
operator|)
argument_list|)
expr_stmt|;
name|tail
operator|=
operator|(
expr|struct
name|amdvi_cmd
operator|*
operator|)
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|softc
operator|->
name|cmd
operator|+
name|ctrl
operator|->
name|cmd_tail
operator|)
expr_stmt|;
return|return
operator|(
name|tail
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Update the command tail pointer which will start command execution.  */
end_comment

begin_function
specifier|static
name|void
name|amdvi_update_cmd_tail
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
block|{
name|struct
name|amdvi_ctrl
modifier|*
name|ctrl
decl_stmt|;
name|int
name|size
decl_stmt|;
name|size
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|amdvi_cmd
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|softc
operator|->
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|ctrl
operator|=
name|softc
operator|->
name|ctrl
expr_stmt|;
name|KASSERT
argument_list|(
name|ctrl
operator|!=
name|NULL
argument_list|,
operator|(
literal|"ctrl is NULL"
operator|)
argument_list|)
expr_stmt|;
name|ctrl
operator|->
name|cmd_tail
operator|=
name|MOD_INC
argument_list|(
name|ctrl
operator|->
name|cmd_tail
argument_list|,
name|size
argument_list|,
name|softc
operator|->
name|cmd_max
argument_list|)
expr_stmt|;
name|softc
operator|->
name|total_cmd
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"cmd_tail: %s Tail:0x%x, Head:0x%x.\n"
argument_list|,
name|ctrl
operator|->
name|cmd_tail
argument_list|,
name|ctrl
operator|->
name|cmd_head
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Various commands supported by IOMMU.  */
end_comment

begin_comment
comment|/* Completion wait command. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_cmd_cmp
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
specifier|const
name|uint64_t
name|data
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|uint64_t
name|pa
decl_stmt|;
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|pa
operator|=
name|vtophys
argument_list|(
operator|&
name|softc
operator|->
name|cmp_data
argument_list|)
expr_stmt|;
name|cmd
operator|->
name|opcode
operator|=
name|AMDVI_CMP_WAIT_OPCODE
expr_stmt|;
name|cmd
operator|->
name|word0
operator|=
operator|(
name|pa
operator|&
literal|0xFFFFFFF8
operator|)
operator||
operator|(
name|AMDVI_CMP_WAIT_STORE
operator|)
expr_stmt|;
comment|//(AMDVI_CMP_WAIT_FLUSH | AMDVI_CMP_WAIT_STORE);
name|cmd
operator|->
name|word1
operator|=
operator|(
name|pa
operator|>>
literal|32
operator|)
operator|&
literal|0xFFFFF
expr_stmt|;
name|cmd
operator|->
name|addr
operator|=
name|data
expr_stmt|;
name|amdvi_update_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Invalidate device table entry. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_cmd_inv_dte
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|cmd
operator|->
name|opcode
operator|=
name|AMDVI_INVD_DTE_OPCODE
expr_stmt|;
name|cmd
operator|->
name|word0
operator|=
name|devid
expr_stmt|;
name|amdvi_update_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"Invalidated DTE:0x%x\n"
argument_list|,
name|devid
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* Invalidate IOMMU page, use for invalidation of domain. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_cmd_inv_iommu_pages
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|domain_id
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|bool
name|guest_nested
parameter_list|,
name|bool
name|pde
parameter_list|,
name|bool
name|page
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|cmd
operator|->
name|opcode
operator|=
name|AMDVI_INVD_PAGE_OPCODE
expr_stmt|;
name|cmd
operator|->
name|word1
operator|=
name|domain_id
expr_stmt|;
comment|/* 	 * Invalidate all addresses for this domain. 	 */
name|cmd
operator|->
name|addr
operator|=
name|addr
expr_stmt|;
name|cmd
operator|->
name|addr
operator||=
name|pde
condition|?
name|AMDVI_INVD_PAGE_PDE
else|:
literal|0
expr_stmt|;
name|cmd
operator|->
name|addr
operator||=
name|page
condition|?
name|AMDVI_INVD_PAGE_S
else|:
literal|0
expr_stmt|;
name|amdvi_update_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|AMDVI_ATS_ENABLE
end_ifdef

begin_comment
comment|/* Invalidate device IOTLB. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_cmd_inv_iotlb
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|int
name|qlen
decl_stmt|;
if|if
condition|(
operator|!
name|softc
operator|->
name|iotlb
condition|)
return|return;
name|qlen
operator|=
name|amdvi_find_ats_qlen
argument_list|(
name|devid
argument_list|)
expr_stmt|;
if|if
condition|(
name|qlen
operator|<
literal|0
condition|)
block|{
name|panic
argument_list|(
literal|"AMDVI: Invalid ATS qlen(%d) for device %d.%d.%d\n"
argument_list|,
name|qlen
argument_list|,
name|RID2PCI_STR
argument_list|(
name|devid
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"Invalidate IOTLB devID 0x%x"
literal|" Qlen:%d\n"
argument_list|,
name|devid
argument_list|,
name|qlen
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|cmd
operator|->
name|opcode
operator|=
name|AMDVI_INVD_IOTLB_OPCODE
expr_stmt|;
name|cmd
operator|->
name|word0
operator|=
name|devid
expr_stmt|;
name|cmd
operator|->
name|word1
operator|=
name|qlen
expr_stmt|;
name|cmd
operator|->
name|addr
operator|=
name|AMDVI_INVD_IOTLB_ALL_ADDR
operator||
name|AMDVI_INVD_IOTLB_S
expr_stmt|;
name|amdvi_update_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* For Interrupt Remap. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_cmd_inv_intr_map
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|devid
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
name|cmd
operator|->
name|opcode
operator|=
name|AMDVI_INVD_INTR_OPCODE
expr_stmt|;
name|cmd
operator|->
name|word0
operator|=
name|devid
expr_stmt|;
name|amdvi_update_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"Invalidate INTR map of devID 0x%x\n"
argument_list|,
name|devid
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Invalidate domain using INVALIDATE_IOMMU_PAGES command. */
end_comment

begin_function
specifier|static
name|void
name|amdvi_inv_domain
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|,
name|uint16_t
name|domain_id
parameter_list|)
block|{
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
name|cmd
operator|=
name|amdvi_get_cmd_tail
argument_list|(
name|softc
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|cmd
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Cmd is NULL"
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * See section 3.3.3 of IOMMU spec rev 2.0, software note 	 * for invalidating domain. 	 */
name|amdvi_cmd_inv_iommu_pages
argument_list|(
name|softc
argument_list|,
name|domain_id
argument_list|,
name|AMDVI_INVD_PAGE_ALL_ADDR
argument_list|,
name|false
argument_list|,
name|true
argument_list|,
name|true
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
name|device_printf
argument_list|(
name|softc
operator|->
name|dev
argument_list|,
literal|"Invalidate domain:0x%x\n"
argument_list|,
name|domain_id
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|bool
name|amdvi_cmp_wait
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
block|{
name|struct
name|amdvi_ctrl
modifier|*
name|ctrl
decl_stmt|;
specifier|const
name|uint64_t
name|VERIFY
init|=
literal|0xA5A5
decl_stmt|;
specifier|volatile
name|uint64_t
modifier|*
name|read
decl_stmt|;
name|int
name|i
decl_stmt|;
name|bool
name|status
decl_stmt|;
name|ctrl
operator|=
name|softc
operator|->
name|ctrl
expr_stmt|;
name|read
operator|=
operator|&
name|softc
operator|->
name|cmp_data
expr_stmt|;
operator|*
name|read
operator|=
literal|0
expr_stmt|;
name|amdvi_cmd_cmp
argument_list|(
name|softc
argument_list|,
name|VERIFY
argument_list|)
expr_stmt|;
comment|/* Wait for h/w to update completion data. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
operator|&&
operator|(
operator|*
name|read
operator|!=
name|VERIFY
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* 1 ms */
block|}
name|status
operator|=
operator|(
name|VERIFY
operator|==
name|softc
operator|->
name|cmp_data
operator|)
condition|?
name|true
else|:
name|false
expr_stmt|;
ifdef|#
directive|ifdef
name|AMDVI_DEBUG_CMD
if|if
condition|(
name|status
condition|)
name|device_printf
argument_list|(
argument|softc->dev
argument_list|,
literal|"CMD completion DONE Tail:0x%x, 			      "
argument|Head:
literal|0x
argument|%x
argument_list|,
argument|loop:%d.\n
literal|", ctrl->cmd_tail, 			      ctrl->cmd_head, loop); #endif 	return (status); }  static void amdvi_wait(struct amdvi_softc *softc) { 	struct amdvi_ctrl *ctrl; 	int i;  	KASSERT(softc, ("
argument|softc is NULL
literal|"));  	ctrl = softc->ctrl; 	KASSERT(ctrl != NULL, ("
argument|ctrl is NULL
literal|")); 	/* Don't wait if h/w is not enabled. */ 	if ((ctrl->control& AMDVI_CTRL_EN) == 0) 		return;  	for (i = 0; i< 10; i++) { 		if (amdvi_cmp_wait(softc)) 			return; 	}  	device_printf(softc->dev, "
argument|Error: completion failed
literal|" 		      "
argument|tail:
literal|0x
argument|%x
argument_list|,
argument|head:
literal|0x
argument|%x.\n
literal|", 		      ctrl->cmd_tail, ctrl->cmd_head); 	amdvi_dump_cmds(softc); }  static void amdvi_dump_cmds(struct amdvi_softc *softc) { 	struct amdvi_ctrl *ctrl; 	struct amdvi_cmd *cmd; 	int off, i;  	ctrl = softc->ctrl; 	device_printf(softc->dev, "
argument|Dump all the commands:\n
literal|"); 	/* 	 * If h/w is stuck in completion, it is the previous command, 	 * start dumping from previous command onward. 	 */ 	off = MOD_DEC(ctrl->cmd_head, sizeof(struct amdvi_cmd), 	    softc->cmd_max); 	for (i = 0; off != ctrl->cmd_tail&& 	    i< softc->cmd_max; i++) { 		cmd = (struct amdvi_cmd *)((uint8_t *)softc->cmd + off); 		printf("
argument|[CMD%d
argument_list|,
argument|off:
literal|0x
argument|%x] opcode=
literal|0x
argument|%x
literal|0x
argument|%x
literal|" 		    "
literal|0x
argument|%x
literal|0x
argument|%lx\n
literal|", i, off, cmd->opcode, 		    cmd->word0, cmd->word1, cmd->addr); 		off = (off + sizeof(struct amdvi_cmd)) % 		    (softc->cmd_max * sizeof(struct amdvi_cmd)); 	} }  static int amdvi_init_event(struct amdvi_softc *softc) { 	struct amdvi_ctrl *ctrl;  	ctrl = softc->ctrl; 	ctrl->event.len = 8; 	softc->event_max = 1<< ctrl->event.len; 	softc->event = malloc(sizeof(struct amdvi_event) * 	    softc->event_max, M_AMDVI, M_WAITOK | M_ZERO); 	if ((uintptr_t)softc->event& PAGE_MASK) { 		device_printf(softc->dev, "
argument|Event buffer not aligned on page.
literal|"); 		return (false); 	} 	ctrl->event.base = vtophys(softc->event) / PAGE_SIZE;  	/* Reset the pointers. */ 	ctrl->evt_head = 0; 	ctrl->evt_tail = 0;  	return (0); }  static inline void amdvi_decode_evt_flag(uint16_t flag) {  	flag&= AMDVI_EVENT_FLAG_MASK; 	printf("
literal|0x
argument|%b]\n
literal|", flag, 		"
argument|\
literal|020
literal|" 		"
argument|\
literal|001GN
literal|" 		"
argument|\
literal|002NX
literal|" 		"
argument|\
literal|003US
literal|" 		"
argument|\
literal|004I
literal|" 		"
argument|\
literal|005PR
literal|" 		"
argument|\
literal|006RW
literal|" 		"
argument|\
literal|007PE
literal|" 		"
argument|\
literal|010RZ
literal|" 		"
argument|\
literal|011TR
literal|" 		); }  /* See section 2.5.4 of AMD IOMMU spec ver 2.62.*/ static inline void amdvi_decode_evt_flag_type(uint8_t type) {  	switch (AMDVI_EVENT_FLAG_TYPE(type)) { 	case 0: 		printf("
argument|RSVD\n
literal|"); 		break; 	case 1: 		printf("
argument|Master Abort\n
literal|"); 		break; 	case 2: 		printf("
argument|Target Abort\n
literal|"); 		break; 	case 3: 		printf("
argument|Data Err\n
literal|"); 		break; 	default: 		break; 	} }  static void amdvi_decode_inv_dte_evt(uint16_t devid, uint16_t domid, uint64_t addr,     uint16_t flag) {  	printf("
argument|\t[IO_PAGE_FAULT EVT: devId:
literal|0x
argument|%x DomId:
literal|0x
argument|%x
literal|" 	    "
argument|Addr:
literal|0x
argument|%lx
literal|", 	    devid, domid, addr); 	amdvi_decode_evt_flag(flag); }  static void amdvi_decode_pf_evt(uint16_t devid, uint16_t domid, uint64_t addr,     uint16_t flag) {  	printf("
argument|\t[IO_PAGE_FAULT EVT: devId:
literal|0x
argument|%x DomId:
literal|0x
argument|%x
literal|" 	    "
argument|Addr:
literal|0x
argument|%lx
literal|", 	    devid, domid, addr); 	amdvi_decode_evt_flag(flag); }  static void amdvi_decode_dte_hwerr_evt(uint16_t devid, uint16_t domid,     uint64_t addr, uint16_t flag) {  	printf("
argument|\t[DEV_TAB_HW_ERR EVT: devId:
literal|0x
argument|%x DomId:
literal|0x
argument|%x
literal|" 	    "
argument|Addr:
literal|0x
argument|%lx
literal|", devid, domid, addr); 	amdvi_decode_evt_flag(flag); 	amdvi_decode_evt_flag_type(flag); }  static void amdvi_decode_page_hwerr_evt(uint16_t devid, uint16_t domid, uint64_t addr,     uint16_t flag) {  	printf("
argument|\t[PAGE_TAB_HW_ERR EVT: devId:
literal|0x
argument|%x DomId:
literal|0x
argument|%x
literal|" 	    "
argument|Addr:
literal|0x
argument|%lx
literal|", devid, domid, addr); 	amdvi_decode_evt_flag(flag); 	amdvi_decode_evt_flag_type(AMDVI_EVENT_FLAG_TYPE(flag)); }  static void amdvi_decode_evt(struct amdvi_event *evt) { 	struct amdvi_cmd *cmd;  	switch (evt->opcode) { 	case AMDVI_EVENT_INVALID_DTE: 		amdvi_decode_inv_dte_evt(evt->devid, evt->pasid_domid, 		    evt->addr, evt->flag); 		break;  	case AMDVI_EVENT_PFAULT: 		amdvi_decode_pf_evt(evt->devid, evt->pasid_domid, 		    evt->addr, evt->flag); 		break;  	case AMDVI_EVENT_DTE_HW_ERROR: 		amdvi_decode_dte_hwerr_evt(evt->devid, evt->pasid_domid, 		    evt->addr, evt->flag); 		break;  	case AMDVI_EVENT_PAGE_HW_ERROR: 		amdvi_decode_page_hwerr_evt(evt->devid, evt->pasid_domid, 		    evt->addr, evt->flag); 		break;  	case AMDVI_EVENT_ILLEGAL_CMD: 		/* FALL THROUGH */ 	case AMDVI_EVENT_CMD_HW_ERROR: 		printf("
argument|\t[%s EVT]
literal|", (evt->opcode == AMDVI_EVENT_ILLEGAL_CMD) ? 		    "
argument|ILLEGAL CMD
literal|" : "
argument|CMD HW ERR
literal|"); 		cmd = (struct amdvi_cmd *)PHYS_TO_DMAP(evt->addr); 		printf("
argument|\tCMD opcode=
literal|0x
argument|%x
literal|0x
argument|%x
literal|0x
argument|%x
literal|0x
argument|%lx\n
literal|", 		    cmd->opcode, cmd->word0, cmd->word1, cmd->addr); 		break;  	case AMDVI_EVENT_IOTLB_TIMEOUT: 		printf("
argument|\t[IOTLB_INV_TIMEOUT devid:
literal|0x
argument|%x addr:
literal|0x
argument|%lx
literal|", 		    evt->devid, evt->addr); 		break;  	case AMDVI_EVENT_INVALID_DTE_REQ: 		printf("
argument|\t[INV_DTE devid:
literal|0x
argument|%x addr:
literal|0x
argument|%lx
literal|", 		    evt->devid, evt->addr); 		break;  	case AMDVI_EVENT_INVALID_PPR_REQ: 	case AMDVI_EVENT_COUNTER_ZERO: 		printf("
argument|AMD-Vi: v2 events.\n
literal|"); 		break;  	default: 		printf("
argument|Unsupported AMD-Vi event:%d
literal|", evt->opcode); 	} }  static void amdvi_print_events(struct amdvi_softc *softc) { 	struct amdvi_ctrl *ctrl; 	struct amdvi_event *event; 	int i, size;  	ctrl = softc->ctrl; 	size = sizeof(struct amdvi_event); 	for (i = 0; i< softc->event_max; i++) { 		event =&softc->event[ctrl->evt_head / size]; 		if (!event->opcode) 			break; 		device_printf(softc->dev, "
argument|\t[Event%d: Head:
literal|0x
argument|%x Tail:
literal|0x
argument|%x]\n
literal|", 		    i, ctrl->evt_head, ctrl->evt_tail); 		amdvi_decode_evt(event); 		ctrl->evt_head = MOD_INC(ctrl->evt_head, size, 		    softc->event_max); 	} }  static int amdvi_init_dte(struct amdvi_softc *softc) { 	struct amdvi_ctrl *ctrl;  	ctrl = softc->ctrl; 	ctrl->dte.base = vtophys(amdvi_dte) / PAGE_SIZE; 	ctrl->dte.size = 0x1FF;		/* 2MB device table. */  	return (0); }  /*  * Not all capabilities of IOMMU are available in ACPI IVHD flag  * or EFR entry, read directly from device.  */ static int amdvi_print_pci_cap(device_t dev) { 	struct amdvi_softc *softc; 	uint32_t off, cap;   	softc = device_get_softc(dev); 	off = softc->cap_off;  	/* 	 * Section 3.7.1 of IOMMU sepc rev 2.0. 	 * Read capability from device. 	 */ 	cap = amdvi_pci_read(softc, off);  	/* Make sure capability type[18:16] is 3. */ 	KASSERT((((cap>> 16)& 0x7) == 0x3), 	    ("
argument|Not a IOMMU capability
literal|0x
argument|%x@
literal|0x
argument|%x
literal|", cap, off));  	softc->pci_cap = cap>> 24; 	device_printf(softc->dev, "
argument|PCI cap
literal|0x
argument|%x@
literal|0x
argument|%x feature:%b\n
literal|", 	    cap, off, softc->pci_cap, 	    "
argument|\
literal|020
argument|\
literal|001IOTLB
argument|\
literal|002HT
argument|\
literal|003NPCache
argument|\
literal|004EFR
literal|");  	/* IOMMU spec Rev 2.0, section 3.7.2.1 */ 	softc->pci_efr = softc->ctrl->ex_feature; 	if (softc->pci_efr) { 		device_printf(softc->dev, "
argument|PCI extended Feature:%b\n
literal|", 		    (int)softc->pci_efr, 		    "
argument|\
literal|020
argument|\
literal|001PreFSup
argument|\
literal|002PPRSup
argument|\
literal|003XTSup
argument|\
literal|004NXSup
argument|\
literal|006IASup
literal|" 		    "
argument|\
literal|007GASup
argument|\
literal|008HESup
argument|\
literal|009PCSup
literal|"); 		device_printf(softc->dev, 		    "
argument|PCI HATS = %d GATS = %d GLXSup = %d
argument_list|,
argument|max PASID:
literal|0x
argument|%x
literal|", 		    (int)((softc->pci_efr>> 10)& 0x3), 		    (int)((softc->pci_efr>> 12)& 0x3), 		    (int)((softc->pci_efr>> 14)& 0x3), 		    (int)((softc->pci_efr>> 32)& 0x1F) + 1); 	}  	return (0); }  static void amdvi_event_intr(void *arg) { 	struct amdvi_softc *softc; 	struct amdvi_ctrl *ctrl;  	softc = (struct amdvi_softc *)arg; 	ctrl = softc->ctrl; 	device_printf(softc->dev, "
argument|EVT INTR %ld Status:
literal|0x
argument|%x
literal|" 	    "
argument|EVT Head:
literal|0x
argument|%x Tail:
literal|0x
argument|%x]\n
literal|", softc->event_intr_cnt++, 	    ctrl->status, ctrl->evt_head, ctrl->evt_tail); 	printf("
argument|[CMD Total
literal|0x
argument|%lx] Tail:
literal|0x
argument|%x
argument_list|,
argument|Head:
literal|0x
argument|%x.\n
literal|", 	    softc->total_cmd, ctrl->cmd_tail, ctrl->cmd_head);  	amdvi_print_events(softc); }  static void amdvi_free_evt_intr_res(device_t dev) {  	struct amdvi_softc *softc;  	softc = device_get_softc(dev); 	if (softc->event_tag != NULL) { 		bus_teardown_intr(dev, softc->event_res, softc->event_tag); 	} 	if (softc->event_res != NULL) { 		bus_release_resource(dev, SYS_RES_IRQ, softc->event_rid, 		    softc->event_res); 	} 	bus_delete_resource(dev, SYS_RES_IRQ, softc->event_rid); 	PCIB_RELEASE_MSI(device_get_parent(device_get_parent(dev)), 	    dev, 1,&softc->event_irq); }  static	bool amdvi_alloc_intr_resources(struct amdvi_softc *softc) { 	device_t dev, pcib; 	uint64_t msi_addr; 	uint32_t msi_data, temp; 	int err, msi_off;  	dev = softc->dev; 	pcib = device_get_parent(device_get_parent(dev)); 	softc->event_irq = -1; 	softc->event_rid = 0; 	/* 	 * Section 3.7.1 of IOMMU rev 2.0. With MSI, there is only one 	 * interrupt. XXX: Enable MSI/X support. 	 */  	err = PCIB_ALLOC_MSI(pcib, dev, 1, 1,&softc->event_irq); 	if (err) { 		device_printf(dev, 		    "
argument|Couldn
literal|'t find event MSI IRQ resource.\n"); 		return (ENOENT); 	} 	err = bus_set_resource(dev, SYS_RES_IRQ, softc->event_rid, 	    softc->event_irq, 1); 	if (err) { 		device_printf(dev, "Couldn'
argument|t set event MSI resource.\n
literal|"); 		return (ENXIO); 	} 	softc->event_res = bus_alloc_resource_any(dev, SYS_RES_IRQ,&softc->event_rid, RF_ACTIVE); 	if (!softc->event_res) { 		device_printf(dev, 		    "
argument|Unable to allocate event INTR resource.\n
literal|"); 		return (ENOMEM); 	}  	if (bus_setup_intr(dev, softc->event_res, 	    INTR_TYPE_MISC | INTR_MPSAFE, NULL, amdvi_event_intr, 	    softc,&softc->event_tag)) { 		device_printf(dev, "
argument|Fail to setup event intr\n
literal|"); 		bus_release_resource(softc->dev, SYS_RES_IRQ, 		    softc->event_rid, softc->event_res); 		softc->event_res = NULL; 		return (ENXIO); 	}  	bus_describe_intr(dev, softc->event_res, softc->event_tag, 	    "
argument|fault
literal|");  	err = amdvi_find_pci_cap(softc, PCIY_MSI,&msi_off); 	if (err) { 		device_printf(dev, "
argument|Couldn
literal|'t find MSI capability, err = %d.\n", 			      err); 		return (err); 	}  	err = PCIB_MAP_MSI(pcib, dev, softc->event_irq,&msi_addr,&msi_data); 	if (err) { 		device_printf(dev, 		    "Event interrupt config failed, err=%d.\n", 		    err); 		amdvi_free_evt_intr_res(softc->dev); 		return (err); 	}  	/* Configure MSI */ 	amdvi_pci_write(softc, msi_off + PCIR_MSI_ADDR, msi_addr); 	amdvi_pci_write(softc, msi_off + PCIR_MSI_ADDR_HIGH, 	    msi_addr>> 32); 	amdvi_pci_write(softc, msi_off + PCIR_MSI_DATA_64BIT, msi_data);  	/* Now enable MSI interrupt. */ 	temp = amdvi_pci_read(softc, msi_off); 	temp |= (PCIM_MSICTRL_MSI_ENABLE<< 16);	/* MSI enable. */ 	amdvi_pci_write(softc, msi_off, temp);  	return (0); }   static void amdvi_print_dev_cap(struct amdvi_softc *softc) { 	struct ivhd_dev_cfg *cfg; 	int i;  	cfg = softc->dev_cfg; 	for (i = 0; i< softc->dev_cfg_cnt; i++) { 		device_printf(softc->dev, "device [0x%x - 0x%x]" 		    "config:%b%s\n", cfg->start_id, cfg->end_id, 		    cfg->data, 		    "\020\001INIT\002ExtInt\003NMI" 		    "\007LINT0\008LINT1", 		    cfg->enable_ats ? "ATS enabled" : ""); 		cfg++; 	} }  static int amdvi_handle_sysctl(SYSCTL_HANDLER_ARGS) { 	struct amdvi_softc *softc; 	int result, type, error = 0;  	softc = (struct amdvi_softc *)arg1; 	type = arg2;  	switch (type) { 	case 0: 		result = softc->ctrl->cmd_head; 		error = sysctl_handle_int(oidp,&result, 0, 		    req); 		break; 	case 1: 		result = softc->ctrl->cmd_tail; 		error = sysctl_handle_int(oidp,&result, 0, 		    req); 		break; 	case 2: 		result = softc->ctrl->evt_head; 		error = sysctl_handle_int(oidp,&result, 0, 		    req); 		break; 	case 3: 		result = softc->ctrl->evt_tail; 		error = sysctl_handle_int(oidp,&result, 0, 		    req); 		break;  	default: 		device_printf(softc->dev, "Unknown sysctl:%d\n", type); 	}  	return (error); }  static void amdvi_add_sysctl(struct amdvi_softc *softc) { 	struct sysctl_oid_list *child; 	struct sysctl_ctx_list *ctx; 	device_t dev;  	dev = softc->dev; 	ctx = device_get_sysctl_ctx(dev); 	child = SYSCTL_CHILDREN(device_get_sysctl_tree(dev));  	SYSCTL_ADD_ULONG(ctx, child, OID_AUTO, "event_intr_count", CTLFLAG_RD,&softc->event_intr_cnt, "Event interrupt count"); 	SYSCTL_ADD_ULONG(ctx, child, OID_AUTO, "command_count", CTLFLAG_RD,&softc->total_cmd, "Command submitted count"); 	SYSCTL_ADD_UINT(ctx, child, OID_AUTO, "pci_rid", CTLFLAG_RD, 	    (int *)&softc->pci_rid, 0, 	    "IOMMU RID"); 	SYSCTL_ADD_UINT(ctx, child, OID_AUTO, "start_dev_rid", CTLFLAG_RD, 	    (int *)&softc->start_dev_rid, 0, 	    "Start of device under this IOMMU"); 	SYSCTL_ADD_UINT(ctx, child, OID_AUTO, "end_dev_rid", CTLFLAG_RD, 	    (int *)&softc->end_dev_rid, 0, 	    "End of device under this IOMMU"); 	SYSCTL_ADD_PROC(ctx, child, OID_AUTO, "command_head", 	    CTLTYPE_UINT | CTLFLAG_RD, softc, 0, 	    amdvi_handle_sysctl, "IU", "Command head"); 	SYSCTL_ADD_PROC(ctx, child, OID_AUTO, "command_tail", 	    CTLTYPE_UINT | CTLFLAG_RD, softc, 1, 	    amdvi_handle_sysctl, "IU", "Command tail"); 	SYSCTL_ADD_PROC(ctx, child, OID_AUTO, "event_head", 	    CTLTYPE_UINT | CTLFLAG_RD, softc, 2, 	    amdvi_handle_sysctl, "IU", "Command head"); 	SYSCTL_ADD_PROC(ctx, child, OID_AUTO, "event_tail", 	    CTLTYPE_UINT | CTLFLAG_RD, softc, 3, 	    amdvi_handle_sysctl, "IU", "Command tail"); }  int amdvi_setup_hw(struct amdvi_softc *softc) { 	device_t dev; 	int status;  	dev = softc->dev;  	amdvi_hw_enable_iotlb(softc);  	amdvi_print_dev_cap(softc);  	if ((status = amdvi_print_pci_cap(dev)) != 0) { 		device_printf(dev, "PCI capability.\n"); 		return (status); 	} 	if ((status = amdvi_init_cmd(softc)) != 0) { 		device_printf(dev, "Couldn'
argument|t configure command buffer.\n
literal|"); 		return (status); 	} 	if ((status = amdvi_init_event(softc)) != 0) { 		device_printf(dev, "
argument|Couldn
literal|'t configure event buffer.\n"); 		return (status); 	} 	if ((status = amdvi_init_dte(softc)) != 0) { 		device_printf(dev, "Couldn'
argument|t configure device table.\n
literal|"); 		return (status); 	} 	if ((status = amdvi_alloc_intr_resources(softc)) != 0) { 		return (status); 	} 	amdvi_add_sysctl(softc); 	return (0); }  int amdvi_teardown_hw(struct amdvi_softc *softc) { 	device_t dev;  	dev = softc->dev;  	/*  	 * Called after disable, h/w is stopped by now, free all the resources.  	 */ 	amdvi_free_evt_intr_res(dev);  	if (softc->cmd) 		free(softc->cmd, M_AMDVI);  	if (softc->event) 		free(softc->event, M_AMDVI);  	return (0); }  /*********** bhyve interfaces *********************/ static int amdvi_init(void) { 	if (!ivhd_count) { 		return (EIO); 	} 	if (!amdvi_enable_user&& ivhd_count) { 		printf("
argument|bhyve: Found %d AMD-Vi/IOMMU device(s)
argument_list|,
literal|" 		    	"
argument|use hw.vmm.amdvi_enable=
literal|1
argument|to enable pass-through.\n
literal|", 		    ivhd_count); 		return (EINVAL); 	} 	return (0); }  static void amdvi_cleanup(void) { 	/* Nothing. */ }  static uint16_t amdvi_domainId(void) {  	/* 	 * If we hit maximum domain limit, rollover leaving host 	 * domain(0). 	 * XXX: make sure that this domain is not used. 	 */ 	if (amdvi_dom_id == AMDVI_MAX_DOMAIN) 		amdvi_dom_id = 1;  	return ((uint16_t)amdvi_dom_id++); }  static void amdvi_do_inv_domain(uint16_t domain_id, bool create) { 	struct amdvi_softc *softc; 	int i;  	for (i = 0; i< ivhd_count; i++) { 		softc = device_get_softc(ivhd_devs[i]); 		KASSERT(softc, ("
argument|softc is NULL
literal|")); 		/* 		 * If not present pages are cached, invalidate page after 		 * creating domain. 		 */ #if 0 		if (create&& ((softc->pci_cap& AMDVI_PCI_CAP_NPCACHE) == 0)) 			continue; #endif 		amdvi_inv_domain(softc, domain_id); 		amdvi_wait(softc); 	} }  static void * amdvi_create_domain(vm_paddr_t maxaddr) { 	struct amdvi_domain *dom;  	dom = malloc(sizeof(struct amdvi_domain), M_AMDVI, M_ZERO | M_WAITOK); 	dom->id = amdvi_domainId(); 	//dom->maxaddr = maxaddr; #ifdef AMDVI_DEBUG_CMD 	printf("
argument|Created domain #%d\n
literal|", dom->id); #endif 	/* 	 * Host domain(#0) don't create translation table. 	 */ 	if (dom->id || amdvi_host_ptp) 		dom->ptp = malloc(PAGE_SIZE, M_AMDVI, M_WAITOK | M_ZERO);  	dom->ptp_level = amdvi_ptp_level;  	amdvi_do_inv_domain(dom->id, true); 	SLIST_INSERT_HEAD(&dom_head, dom, next);  	return (dom); }  static void amdvi_free_ptp(uint64_t *ptp, int level) { 	int i;  	if (level< 1) 		return;  	for (i = 0; i< NPTEPG ; i++) { 		if ((ptp[i]& AMDVI_PT_PRESENT) == 0) 			continue; 		/* XXX: Add super-page or PTE mapping> 4KB. */ #ifdef notyet 		/* Super-page mapping. */ 		if (AMDVI_PD_SUPER(ptp[i])) 			continue; #endif  		amdvi_free_ptp((uint64_t *)PHYS_TO_DMAP(ptp[i]& AMDVI_PT_MASK), level - 1);  	}  	free(ptp, M_AMDVI); }  static void amdvi_destroy_domain(void *arg) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg; 	KASSERT(domain, ("
argument|domain is NULL
literal|")); #ifdef AMDVI_DEBUG_CMD 	printf("
argument|Destroying domain %d\n
literal|", domain->id); #endif 	if (domain->ptp) 		amdvi_free_ptp(domain->ptp, domain->ptp_level);  	amdvi_do_inv_domain(domain->id, false); 	SLIST_REMOVE(&dom_head, domain, amdvi_domain, next); 	free(domain, M_AMDVI); }  static uint64_t amdvi_set_pt(uint64_t *pt, int level, vm_paddr_t gpa,     vm_paddr_t hpa, uint64_t pg_size, bool create) { 	uint64_t *page, pa; 	int shift, index; 	const int PT_SHIFT = 9; 	const int PT_INDEX_MASK = (1<< PT_SHIFT) - 1;	/* Based on PT_SHIFT */  	if (!pg_size) 		return (0);  	if (hpa& (pg_size - 1)) { 		printf("
argument|HPA is not size aligned.\n
literal|"); 		return (0); 	} 	if (gpa& (pg_size - 1)) { 		printf("
argument|HPA is not size aligned.\n
literal|"); 		return (0); 	} 	shift = PML4SHIFT; 	while ((shift> PAGE_SHIFT)&& (pg_size< (1UL<< shift))) { 		index = (gpa>> shift)& PT_INDEX_MASK;  		if ((pt[index] == 0)&& create) { 			page = malloc(PAGE_SIZE, M_AMDVI, M_WAITOK | M_ZERO); 			pa = vtophys(page); 			pt[index] = pa | AMDVI_PT_PRESENT | AMDVI_PT_RW | 			    ((level - 1)<< AMDVI_PD_LEVEL_SHIFT); 		} #ifdef AMDVI_DEBUG_PTE 		if ((gpa % 0x1000000) == 0) 			printf("
argument|[level%d
argument_list|,
argument|shift = %d]PTE:
literal|0x
argument|%lx\n
literal|", 			    level, shift, pt[index]); #endif #define PTE2PA(x)	((uint64_t)(x)& AMDVI_PT_MASK) 		pa = PTE2PA(pt[index]); 		pt = (uint64_t *)PHYS_TO_DMAP(pa); 		shift -= PT_SHIFT; 		level--; 	}  	/* Leaf entry. */ 	index = (gpa>> shift)& PT_INDEX_MASK;  	if (create) { 		pt[index] = hpa | AMDVI_PT_RW | AMDVI_PT_PRESENT; 	} else 		pt[index] = 0;  #ifdef AMDVI_DEBUG_PTE 	if ((gpa % 0x1000000) == 0) 		printf("
argument|[Last level%d
argument_list|,
argument|shift = %d]PTE:
literal|0x
argument|%lx\n
literal|", 		    level, shift, pt[index]); #endif 	return (1ULL<< shift); }  static uint64_t amdvi_update_mapping(struct amdvi_domain *domain, vm_paddr_t gpa,     vm_paddr_t hpa, uint64_t size, bool create) { 	uint64_t mapped, *ptp, len; 	int level;  	KASSERT(domain, ("
argument|domain is NULL
literal|")); 	level = domain->ptp_level; 	KASSERT(level, ("
argument|Page table level is
literal|0
literal|"));  	ptp = domain->ptp; 	KASSERT(ptp, ("
argument|PTP is NULL
literal|")); 	mapped = 0; 	while (mapped< size) { 		len = amdvi_set_pt(ptp, level, gpa + mapped, hpa + mapped, 		    PAGE_SIZE, create); 		if (!len) { 			printf("
argument|Error: Couldn
literal|'t map HPA:0x%lx GPA:0x%lx\n", 			    hpa, gpa); 			return (0); 		} 		mapped += len; 	}  	return (mapped); }  static uint64_t amdvi_create_mapping(void *arg, vm_paddr_t gpa, vm_paddr_t hpa,     uint64_t len) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg;  	if (domain->id&& !domain->ptp) { 		printf("ptp is NULL"); 		return (-1); 	}  	/* 	 * If host domain is created w/o page table, skip IOMMU page 	 * table set-up. 	 */ 	if (domain->ptp) 		return (amdvi_update_mapping(domain, gpa, hpa, len, true)); 	else 		return (len); }  static uint64_t amdvi_destroy_mapping(void *arg, vm_paddr_t gpa, uint64_t len) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg; 	/* 	 * If host domain is created w/o page table, skip IOMMU page 	 * table set-up. 	 */ 	if (domain->ptp) 		return (amdvi_update_mapping(domain, gpa, 0, len, false)); 	return 	    (len); }  static struct amdvi_softc * amdvi_find_iommu(uint16_t devid) { 	struct amdvi_softc *softc; 	int i;  	for (i = 0; i< ivhd_count; i++) { 		softc = device_get_softc(ivhd_devs[i]); 		if ((devid>= softc->start_dev_rid)&& 		    (devid<= softc->end_dev_rid)) 			return (softc); 	}  	/* 	 * XXX: BIOS bug, device not in IVRS table, assume its from first IOMMU. 	 */ 	printf("BIOS bug device(%d.%d.%d) doesn'
argument|t have IVHD entry.\n
literal|", 	    RID2PCI_STR(devid));  	return (device_get_softc(ivhd_devs[0])); }  /*  * Set-up device table entry.  * IOMMU spec Rev 2.0, section 3.2.2.2, some of the fields must  * be set concurrently, e.g. read and write bits.  */ static void amdvi_set_dte(struct amdvi_domain *domain, uint16_t devid, bool enable) { 	struct amdvi_softc *softc; 	struct amdvi_dte temp;  	softc = amdvi_find_iommu(devid); 	KASSERT(softc, ("
argument|softc is NULL for pci_rid:
literal|0x
argument|%x\n
literal|", devid));  	memset(&temp, 0, sizeof(struct amdvi_dte));  #ifdef AMDVI_ATS_ENABLE 	/* If IOMMU and device support IOTLB, enable it. */ 	if (amdvi_dev_support_iotlb(softc, devid)&& softc->iotlb) 		temp.iotlb_enable = 1; #endif  	/* Avoid duplicate I/O faults. */ 	temp.sup_second_io_fault = 1; 	temp.sup_all_io_fault = amdvi_disable_io_fault;  	temp.dt_valid = 1; 	temp.domain_id = domain->id;  	if (enable) { 		if (domain->ptp) { 			temp.pt_base = vtophys(domain->ptp)>> 12; 			temp.pt_level = amdvi_ptp_level; 		} 		/* 		 * XXX: Page table valid[TV] bit must be set even if host domain 		 * page tables are not enabled. 		 */ 		temp.pt_valid = 1; 		temp.read_allow = 1; 		temp.write_allow = 1; 	} 	amdvi_dte[devid] = temp; }  static void amdvi_inv_device(uint16_t devid) { 	struct amdvi_softc *softc;  	softc = amdvi_find_iommu(devid); 	KASSERT(softc, ("
argument|softc is NULL
literal|"));  	amdvi_cmd_inv_dte(softc, devid); #ifdef AMDVI_ATS_ENABLE 	if (amdvi_dev_support_iotlb(softc, devid)) 		amdvi_cmd_inv_iotlb(softc, devid); #endif 	amdvi_wait(softc); }  static void amdvi_add_device(void *arg, uint16_t devid) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg; 	KASSERT(domain != NULL, ("
argument|domain is NULL
literal|")); #ifdef AMDVI_DEBUG_CMD 	printf("
argument|Assigning device(%d.%d.%d) to domain:%d\n
literal|", 	    RID2PCI_STR(devid), domain->id); #endif 	amdvi_set_dte(domain, devid, true); 	amdvi_inv_device(devid); }  static void amdvi_remove_device(void *arg, uint16_t devid) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg; #ifdef AMDVI_DEBUG_CMD 	printf("
argument|Remove device(
literal|0x
argument|%x) from domain:%d\n
literal|", 	       devid, domain->id); #endif 	amdvi_set_dte(domain, devid, false); 	amdvi_inv_device(devid); }  static void amdvi_enable(void) { 	struct amdvi_ctrl *ctrl; 	struct amdvi_softc *softc; 	uint64_t val; 	int i;  	for (i = 0; i< ivhd_count; i++) { 		softc = device_get_softc(ivhd_devs[i]); 		KASSERT(softc, ("
argument|softc is NULL\n
literal|")); 		ctrl = softc->ctrl; 		KASSERT(ctrl, ("
argument|ctrl is NULL\n
literal|"));  		val = (	AMDVI_CTRL_EN 		| 			AMDVI_CTRL_CMD 		| 		    	AMDVI_CTRL_ELOG 	| 		    	AMDVI_CTRL_ELOGINT 	| 		    	AMDVI_CTRL_INV_TO_1S);  		if (softc->ivhd_flag& IVHD_FLAG_COH) 			val |= AMDVI_CTRL_COH; 		if (softc->ivhd_flag& IVHD_FLAG_HTT) 			val |= AMDVI_CTRL_HTT; 		if (softc->ivhd_flag& IVHD_FLAG_RPPW) 			val |= AMDVI_CTRL_RPPW; 		if (softc->ivhd_flag& IVHD_FLAG_PPW) 			val |= AMDVI_CTRL_PPW; 		if (softc->ivhd_flag& IVHD_FLAG_ISOC) 			val |= AMDVI_CTRL_ISOC;  		ctrl->control = val; 	} }  static void amdvi_disable(void) { 	struct amdvi_ctrl *ctrl; 	struct amdvi_softc *softc; 	int i;  	for (i = 0; i< ivhd_count; i++) { 		softc = device_get_softc(ivhd_devs[i]); 		KASSERT(softc, ("
argument|softc is NULL\n
literal|")); 		ctrl = softc->ctrl; 		KASSERT(ctrl, ("
argument|ctrl is NULL\n
literal|"));  		ctrl->control = 0; 	} }  static void amdvi_inv_tlb(void *arg) { 	struct amdvi_domain *domain;  	domain = (struct amdvi_domain *)arg; 	KASSERT(domain, ("
argument|domain is NULL
literal|"
end_function

unit|)); 	amdvi_do_inv_domain(domain->id, false); }  struct iommu_ops iommu_ops_amd = { 	amdvi_init, 	amdvi_cleanup, 	amdvi_enable, 	amdvi_disable, 	amdvi_create_domain, 	amdvi_destroy_domain, 	amdvi_create_mapping, 	amdvi_destroy_mapping, 	amdvi_add_device, 	amdvi_remove_device, 	amdvi_inv_tlb };
end_unit

