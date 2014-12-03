begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Texas A&M University  * All rights reserved.  *  * Developer: Wm. Daryl Hawkins  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ICHWD_H_
end_ifndef

begin_define
define|#
directive|define
name|_ICHWD_H_
end_define

begin_struct
struct|struct
name|ichwd_device
block|{
name|uint16_t
name|device
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
name|unsigned
name|int
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ichwd_softc
block|{
name|device_t
name|device
decl_stmt|;
name|device_t
name|ich
decl_stmt|;
name|int
name|ich_version
decl_stmt|;
name|int
name|active
decl_stmt|;
name|unsigned
name|int
name|timeout
decl_stmt|;
name|int
name|smi_enabled
decl_stmt|;
name|int
name|smi_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|smi_res
decl_stmt|;
name|int
name|tco_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|tco_res
decl_stmt|;
name|int
name|gcs_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|gcs_res
decl_stmt|;
name|eventhandler_tag
name|ev_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VENDORID_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT0
value|0x1c40
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT1
value|0x1c41
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT2
value|0x1c42
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT3
value|0x1c43
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT4
value|0x1c44
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT5
value|0x1c45
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT6
value|0x1c46
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT7
value|0x1c47
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT8
value|0x1c48
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT9
value|0x1c49
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT10
value|0x1c4a
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT11
value|0x1c4b
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT12
value|0x1c4c
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT13
value|0x1c4d
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT14
value|0x1c4e
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT15
value|0x1c4f
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT16
value|0x1c50
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT17
value|0x1c51
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT18
value|0x1c52
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT19
value|0x1c53
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT20
value|0x1c54
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT21
value|0x1c55
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT22
value|0x1c56
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT23
value|0x1c57
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT24
value|0x1c58
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT25
value|0x1c59
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT26
value|0x1c5a
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT27
value|0x1c5b
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT28
value|0x1c5c
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT29
value|0x1c5d
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT30
value|0x1c5e
end_define

begin_define
define|#
directive|define
name|DEVICEID_CPT31
value|0x1c5f
end_define

begin_define
define|#
directive|define
name|DEVICEID_PATSBURG_LPC1
value|0x1d40
end_define

begin_define
define|#
directive|define
name|DEVICEID_PATSBURG_LPC2
value|0x1d41
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT0
value|0x1e40
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT1
value|0x1e41
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT2
value|0x1e42
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT3
value|0x1e43
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT4
value|0x1e44
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT5
value|0x1e45
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT6
value|0x1e46
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT7
value|0x1e47
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT8
value|0x1e48
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT9
value|0x1e49
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT10
value|0x1e4a
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT11
value|0x1e4b
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT12
value|0x1e4c
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT13
value|0x1e4d
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT14
value|0x1e4e
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT15
value|0x1e4f
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT16
value|0x1e50
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT17
value|0x1e51
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT18
value|0x1e52
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT19
value|0x1e53
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT20
value|0x1e54
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT21
value|0x1e55
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT22
value|0x1e56
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT23
value|0x1e57
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT24
value|0x1e58
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT25
value|0x1e59
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT26
value|0x1e5a
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT27
value|0x1e5b
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT28
value|0x1e5c
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT29
value|0x1e5d
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT30
value|0x1e5e
end_define

begin_define
define|#
directive|define
name|DEVICEID_PPT31
value|0x1e5f
end_define

begin_define
define|#
directive|define
name|DEVICEID_DH89XXCC_LPC
value|0x2310
end_define

begin_define
define|#
directive|define
name|DEVICEID_COLETOCRK_LPC
value|0x2390
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801AA
value|0x2410
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801AB
value|0x2420
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801BA
value|0x2440
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801BAM
value|0x244c
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801CA
value|0x2480
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801CAM
value|0x248c
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801DB
value|0x24c0
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801DBM
value|0x24cc
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801E
value|0x2450
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801EB
value|0x24dc
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801EBR
value|0x24d0
end_define

begin_define
define|#
directive|define
name|DEVICEID_6300ESB
value|0x25a1
end_define

begin_define
define|#
directive|define
name|DEVICEID_82801FBR
value|0x2640
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH6M
value|0x2641
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH6W
value|0x2642
end_define

begin_define
define|#
directive|define
name|DEVICEID_63XXESB
value|0x2670
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH7
value|0x27b8
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH7DH
value|0x27b0
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH7M
value|0x27b9
end_define

begin_define
define|#
directive|define
name|DEVICEID_NM10
value|0x27bc
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH7MDH
value|0x27bd
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH8
value|0x2810
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH8DH
value|0x2812
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH8DO
value|0x2814
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH8M
value|0x2815
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH8ME
value|0x2811
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9
value|0x2918
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9DH
value|0x2912
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9DO
value|0x2914
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9M
value|0x2919
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9ME
value|0x2917
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH9R
value|0x2916
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH10
value|0x3a18
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH10D
value|0x3a1a
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH10DO
value|0x3a14
end_define

begin_define
define|#
directive|define
name|DEVICEID_ICH10R
value|0x3a16
end_define

begin_define
define|#
directive|define
name|DEVICEID_PCH
value|0x3b00
end_define

begin_define
define|#
directive|define
name|DEVICEID_PCHM
value|0x3b01
end_define

begin_define
define|#
directive|define
name|DEVICEID_P55
value|0x3b02
end_define

begin_define
define|#
directive|define
name|DEVICEID_PM55
value|0x3b03
end_define

begin_define
define|#
directive|define
name|DEVICEID_H55
value|0x3b06
end_define

begin_define
define|#
directive|define
name|DEVICEID_QM57
value|0x3b07
end_define

begin_define
define|#
directive|define
name|DEVICEID_H57
value|0x3b08
end_define

begin_define
define|#
directive|define
name|DEVICEID_HM55
value|0x3b09
end_define

begin_define
define|#
directive|define
name|DEVICEID_Q57
value|0x3b0a
end_define

begin_define
define|#
directive|define
name|DEVICEID_HM57
value|0x3b0b
end_define

begin_define
define|#
directive|define
name|DEVICEID_PCHMSFF
value|0x3b0d
end_define

begin_define
define|#
directive|define
name|DEVICEID_QS57
value|0x3b0f
end_define

begin_define
define|#
directive|define
name|DEVICEID_3400
value|0x3b12
end_define

begin_define
define|#
directive|define
name|DEVICEID_3420
value|0x3b14
end_define

begin_define
define|#
directive|define
name|DEVICEID_3450
value|0x3b16
end_define

begin_define
define|#
directive|define
name|DEVICEID_WCPT2
value|0x8cc2
end_define

begin_define
define|#
directive|define
name|DEVICEID_WCPT4
value|0x8cc4
end_define

begin_define
define|#
directive|define
name|DEVICEID_WCPT6
value|0x8cc6
end_define

begin_comment
comment|/* ICH LPC Interface Bridge Registers (ICH5 and older) */
end_comment

begin_define
define|#
directive|define
name|ICH_GEN_STA
value|0xd4
end_define

begin_define
define|#
directive|define
name|ICH_GEN_STA_NO_REBOOT
value|0x02
end_define

begin_define
define|#
directive|define
name|ICH_PMBASE
value|0x40
end_define

begin_comment
comment|/* ACPI base address register */
end_comment

begin_define
define|#
directive|define
name|ICH_PMBASE_MASK
value|0x7f80
end_define

begin_comment
comment|/* bits 7-15 */
end_comment

begin_comment
comment|/* ICH Chipset Configuration Registers (ICH6 and newer) */
end_comment

begin_define
define|#
directive|define
name|ICH_RCBA
value|0xf0
end_define

begin_define
define|#
directive|define
name|ICH_GCS_OFFSET
value|0x3410
end_define

begin_define
define|#
directive|define
name|ICH_GCS_SIZE
value|0x4
end_define

begin_define
define|#
directive|define
name|ICH_GCS_NO_REBOOT
value|0x20
end_define

begin_comment
comment|/* register names and locations (relative to PMBASE) */
end_comment

begin_define
define|#
directive|define
name|SMI_BASE
value|0x30
end_define

begin_comment
comment|/* base address for SMI registers */
end_comment

begin_define
define|#
directive|define
name|SMI_LEN
value|0x08
end_define

begin_define
define|#
directive|define
name|SMI_EN
value|0x00
end_define

begin_comment
comment|/* SMI Control and Enable Register */
end_comment

begin_define
define|#
directive|define
name|SMI_STS
value|0x04
end_define

begin_comment
comment|/* SMI Status Register */
end_comment

begin_define
define|#
directive|define
name|TCO_BASE
value|0x60
end_define

begin_comment
comment|/* base address for TCO registers */
end_comment

begin_define
define|#
directive|define
name|TCO_LEN
value|0x20
end_define

begin_define
define|#
directive|define
name|TCO_RLD
value|0x00
end_define

begin_comment
comment|/* TCO Reload and Current Value */
end_comment

begin_define
define|#
directive|define
name|TCO_TMR1
value|0x01
end_define

begin_comment
comment|/* TCO Timer Initial Value 					(ICH5 and older, 8 bits) */
end_comment

begin_define
define|#
directive|define
name|TCO_TMR2
value|0x12
end_define

begin_comment
comment|/* TCO Timer Initial Value 					(ICH6 and newer, 16 bits) */
end_comment

begin_define
define|#
directive|define
name|TCO_DAT_IN
value|0x02
end_define

begin_comment
comment|/* TCO Data In (DO NOT USE) */
end_comment

begin_define
define|#
directive|define
name|TCO_DAT_OUT
value|0x03
end_define

begin_comment
comment|/* TCO Data Out (DO NOT USE) */
end_comment

begin_define
define|#
directive|define
name|TCO1_STS
value|0x04
end_define

begin_comment
comment|/* TCO Status 1 */
end_comment

begin_define
define|#
directive|define
name|TCO2_STS
value|0x06
end_define

begin_comment
comment|/* TCO Status 2 */
end_comment

begin_define
define|#
directive|define
name|TCO1_CNT
value|0x08
end_define

begin_comment
comment|/* TCO Control 1 */
end_comment

begin_define
define|#
directive|define
name|TCO2_CNT
value|0x08
end_define

begin_comment
comment|/* TCO Control 2 */
end_comment

begin_define
define|#
directive|define
name|TCO_MESSAGE1
value|0x0c
end_define

begin_comment
comment|/* TCO Message 1 */
end_comment

begin_define
define|#
directive|define
name|TCO_MESSAGE2
value|0x0d
end_define

begin_comment
comment|/* TCO Message 2 */
end_comment

begin_comment
comment|/* bit definitions for SMI_EN and SMI_STS */
end_comment

begin_define
define|#
directive|define
name|SMI_TCO_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|SMI_TCO_STS
value|0x2000
end_define

begin_define
define|#
directive|define
name|SMI_GBL_EN
value|0x0001
end_define

begin_comment
comment|/* timer value mask for TCO_RLD and TCO_TMR */
end_comment

begin_define
define|#
directive|define
name|TCO_TIMER_MASK
value|0x1f
end_define

begin_comment
comment|/* status bits for TCO1_STS */
end_comment

begin_define
define|#
directive|define
name|TCO_NEWCENTURY
value|0x80
end_define

begin_comment
comment|/* set for RTC year roll over (99 to 00) */
end_comment

begin_define
define|#
directive|define
name|TCO_TIMEOUT
value|0x08
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|TCO_INT_STS
value|0x04
end_define

begin_comment
comment|/* data out (DO NOT USE) */
end_comment

begin_define
define|#
directive|define
name|TCO_SMI_STS
value|0x02
end_define

begin_comment
comment|/* data in (DO NOT USE) */
end_comment

begin_comment
comment|/* status bits for TCO2_STS */
end_comment

begin_define
define|#
directive|define
name|TCO_BOOT_STS
value|0x04
end_define

begin_comment
comment|/* failed to come out of reset */
end_comment

begin_define
define|#
directive|define
name|TCO_SECOND_TO_STS
value|0x02
end_define

begin_comment
comment|/* ran down twice */
end_comment

begin_comment
comment|/* control bits for TCO1_CNT */
end_comment

begin_define
define|#
directive|define
name|TCO_TMR_HALT
value|0x0800
end_define

begin_comment
comment|/* clear to enable WDT */
end_comment

begin_define
define|#
directive|define
name|TCO_NMI2SMI_EN
value|0x0200
end_define

begin_comment
comment|/* convert NMIs to SMIs */
end_comment

begin_define
define|#
directive|define
name|TCO_CNT_PRESERVE
value|TCO_NMI2SMI_EN
end_define

begin_comment
comment|/* preserve these bits */
end_comment

begin_define
define|#
directive|define
name|TCO_NMI_NOW
value|0x0100
end_define

begin_comment
comment|/* trigger an NMI */
end_comment

begin_comment
comment|/*  * Masks for the TCO timer value field in TCO_RLD.  * If the datasheets are to be believed, the minimum value actually varies  * from chipset to chipset - 4 for ICH5 and 2 for all other chipsets.  * I suspect this is a bug in the ICH5 datasheet and that the minimum is  * uniformly 2, but I'd rather err on the side of caution.  */
end_comment

begin_define
define|#
directive|define
name|TCO_RLD_TMR_MIN
value|0x0004
end_define

begin_define
define|#
directive|define
name|TCO_RLD1_TMR_MAX
value|0x003f
end_define

begin_define
define|#
directive|define
name|TCO_RLD2_TMR_MAX
value|0x03ff
end_define

begin_comment
comment|/* approximate length in nanoseconds of one WDT tick (about 0.6 sec) */
end_comment

begin_define
define|#
directive|define
name|ICHWD_TICK
value|600000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

