begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCI_BHND_PCI_HOSTBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCI_BHND_PCI_HOSTBVAR_H_
end_define

begin_comment
comment|/*  * PCI/PCIe-Gen1 Host Bridge definitions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pcivar.h"
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_pci_hostb_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * PCI/PCIe-Gen1 endpoint-mode device quirks  */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|BHND_PCI_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * SBTOPCI_PREF and SBTOPCI_BURST must be set on the 	 * SSB_PCICORE_SBTOPCI2 register. 	 */
name|BHND_PCI_QUIRK_SBTOPCI2_PREF_BURST
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * SBTOPCI_RC_READMULTI must be set on the SSB_PCICORE_SBTOPCI2 	 * register. 	 */
name|BHND_PCI_QUIRK_SBTOPCI2_READMULTI
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/** 	 * PCI CLKRUN# should be disabled on attach (via CLKRUN_DSBL). 	 *  	 * The purpose of this work-around is unclear; there is some 	 * documentation regarding earlier Broadcom drivers supporting 	 * a "force CLKRUN#" *enable* registry key for use on mobile 	 * hardware. 	 */
name|BHND_PCI_QUIRK_CLKRUN_DSBL
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/** 	 * On PCI-attached BCM4321CB* boards, the PCI latency timer must be set 	 * to 960ns on initial attach. 	 */
name|BHND_PCI_QUIRK_960NS_LATTIM_OVR
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
comment|/** 	 * TLP workaround for unmatched address handling is required. 	 *  	 * This TLP workaround will enable setting of the PCIe UR status bit 	 * on memory access to an unmatched address. 	 */
name|BHND_PCIE_QUIRK_UR_STATUS_FIX
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
comment|/** 	 * PCI-PM power management must be explicitly enabled via 	 * the data link control register. 	 */
name|BHND_PCIE_QUIRK_PCIPM_REQEN
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/** 	 * Fix L0s to L0 exit transition on SerDes<= rev9 devices. 	 *  	 * On these devices, PCIe/SerDes symbol lock can be lost if the 	 * reference clock has not fully stabilized during the L0s to L0 	 * exit transition, triggering an internal reset of the chip. 	 *  	 * The SerDes RX CDR phase lock timers and proportional/integral 	 * filters must be tweaked to ensure the CDR has fully stabilized 	 * before asserting receive sequencer completion. 	 */
name|BHND_PCIE_QUIRK_SDR9_L0s_HANG
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|/** 	 * The idle time for entering L1 low-power state must be 	 * explicitly set (to 114ns) to fix slow L1->L0 transition issues. 	 */
name|BHND_PCIE_QUIRK_L1_IDLE_THRESH
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
comment|/** 	 * The ASPM L1 entry timer should be extended for better performance, 	 * and restored for better power savings. 	 */
name|BHND_PCIE_QUIRK_L1_TIMER_PERF
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
comment|/** 	 * ASPM and ECPM settings must be overridden manually. 	 * Applies to 4311B0/4321B1 chipset revisions. 	 *  	 * The override behavior is controlled by the BHND_BFL2_PCIEWAR_OVR 	 * flag; if set, ASPM and CLKREQ should be explicitly disabled. If not 	 * set, they should be explicitly enabled. 	 *  	 * Attach/Resume: 	 *   - Update SRSH_ASPM_ENB flag in the SPROM ASPM register. 	 *   - Update SRSH_CLKREQ_ENB flag in the SPROM CLKREQ_REV5 	 *     register. 	 *   - Update ASPM L0S/L1 flags in PCIER_LINK_CTL register. 	 *   - Clear CLKREQ (ECPM) flag in PCIER_LINK_CTL register. 	 *  	 * Suspend: 	 *   - Clear ASPM L1 flag in the PCIER_LINK_CTL register. 	 *   - Set CLKREQ (ECPM) flag in the PCIER_LINK_CTL register. 	 *  	 * Detach: 	 *   - Set CLKREQ (ECPM) flag in the PCIER_LINK_CTL register. 	 */
name|BHND_PCIE_QUIRK_ASPM_OVR
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
comment|/** 	 * A subset of Apple devices did not set the BHND_BFL2_PCIEWAR_OVR 	 * flag in SPROM; on these devices, the BHND_BFL2_PCIEWAR_OVR flag 	 * should always be treated as if set. 	 */
name|BHND_PCIE_QUIRK_BFL2_PCIEWAR_EN
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
comment|/** 	 * Fix SerDes polarity on SerDes<= rev9 devices. 	 * 	 * The SerDes polarity must be saved at device attachment, and 	 * restored on suspend/resume. 	 */
name|BHND_PCIE_QUIRK_SDR9_POLARITY
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
comment|/** 	 * SerDes PLL down flag must be manually disabled (by ChipCommon) on 	 * resume. 	 */
name|BHND_PCIE_QUIRK_SERDES_NOPLLDOWN
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
comment|/** 	 * On attach and resume, consult the SPROM to determine whether 	 * the L2/L3-Ready w/o PCI RESET work-around must be applied. 	 * 	 * If L23READY_EXIT_NOPRST is not already set in the SPROM, set it 	 */
name|BHND_PCIE_QUIRK_SPROM_L23_PCI_RESET
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
comment|/** 	 * The PCIe SerDes PLL must be configured to not retry the startup 	 * sequence upon frequency detection failure on SerDes<= rev9 devices 	 *  	 * The issue this workaround resolves is unknown. 	 */
name|BHND_PCIE_QUIRK_SDR9_NO_FREQRETRY
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
comment|/** 	 * Common flag for quirks that require PCIe SerDes TX 	 * drive strength adjustment. 	 *  	 * Only applies to PCIe>= rev10 devices. 	 */
name|BHND_PCIE_QUIRK_SERDES_TXDRV_ADJUST
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
comment|/** 	 * On Apple BCM94322X9 devices, the PCIe SerDes TX drive strength 	 * should be set to 700mV. 	 * 	 * The exact issue is unknown, but presumably this workaround 	 * resolves signal integrity issues with these devices. 	 *  	 * Only applies to PCIe>= rev10 devices. 	 */
name|BHND_PCIE_QUIRK_SERDES_TXDRV_700MV
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
operator||
name|BHND_PCIE_QUIRK_SERDES_TXDRV_ADJUST
block|,
comment|/** 	 * On some Apple BCM4331-based devices, the PCIe SerDes TX drive 	 * strength should be set to its maximum. 	 * 	 * The exact issue is unknown, but presumably this workaround 	 * resolves signal integrity issues with these devices. 	 */
name|BHND_PCIE_QUIRK_SERDES_TXDRV_MAX
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
operator||
name|BHND_PCIE_QUIRK_SERDES_TXDRV_ADJUST
block|,
comment|/** 	 * PCIe cores prior to rev18 do not support an MRRS larger than 	 * 128 bytes. 	 */
name|BHND_PCIE_QUIRK_MAX_MRRS_128
init|=
operator|(
literal|1
operator|<<
literal|19
operator|)
block|,
comment|/** 	 * The PCIe core should be configured with an MRRS of 512 bytes. 	 */
name|BHND_PCIE_QUIRK_DEFAULT_MRRS_512
init|=
operator|(
literal|1
operator|<<
literal|20
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * bhnd_pci_hostb driver instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_pcihb_softc
block|{
name|struct
name|bhnd_pci_softc
name|common
decl_stmt|;
comment|/**< common bhnd_pci state */
name|device_t
name|dev
decl_stmt|;
name|device_t
name|pci_dev
decl_stmt|;
comment|/**< host PCI device */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< hostb device quirks */
comment|/** BHND_PCIE_QUIRK_ASPM_OVR state. */
struct|struct
block|{
comment|/** 		 * ASPM/CLKREQ override setting. 		 *  		 * If true, ASPM/CLKREQ should be overridden as enabled. 		 * If false, ASPM/CLKREQ should be overridden as disabled. 		 */
name|bool
name|aspm_en
decl_stmt|;
block|}
name|aspm_quirk_override
struct|;
comment|/** BHND_PCIE_QUIRK_SDR9_POLARITY state. */
struct|struct
block|{
comment|/**  		 * PCIe SerDes RX polarity. 		 * 		 * Initialized to the PCIe link's RX polarity 		 * at attach time. This is used to restore the 		 * correct polarity on resume */
name|bool
name|inv
decl_stmt|;
block|}
name|sdr9_quirk_polarity
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_BHND_PCI_HOSTBVAR_H_ */
end_comment

end_unit

