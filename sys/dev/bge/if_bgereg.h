begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Wind River Systems  * Copyright (c) 1997, 1998, 1999, 2001  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * BCM570x memory map. The internal memory layout varies somewhat  * depending on whether or not we have external SSRAM attached.  * The BCM5700 can have up to 16MB of external memory. The BCM5701  * is apparently not designed to use external SSRAM. The mappings  * up to the first 4 send rings are the same for both internal and  * external memory configurations. Note that mini RX ring space is  * only available with external SSRAM configurations, which means  * the mini RX ring is not supported on the BCM5701.  *  * The NIC's memory can be accessed by the host in one of 3 ways:  *  * 1) Indirect register access. The MEMWIN_BASEADDR and MEMWIN_DATA  *    registers in PCI config space can be used to read any 32-bit  *    address within the NIC's memory.  *  * 2) Memory window access. The MEMWIN_BASEADDR register in PCI config  *    space can be used in conjunction with the memory window in the  *    device register space at offset 0x8000 to read any 32K chunk  *    of NIC memory.  *  * 3) Flat mode. If the 'flat mode' bit in the PCI state register is  *    set, the device I/O mapping consumes 32MB of host address space,  *    allowing all of the registers and internal NIC memory to be  *    accessed directly. NIC memory addresses are offset by 0x01000000.  *    Flat mode consumes so much host address space that it is not  *    recommended.  */
end_comment

begin_define
define|#
directive|define
name|BGE_PAGE_ZERO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_PAGE_ZERO_END
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_RCB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_RCB_END
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|BGE_RX_RETURN_RING_RCB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_RX_RETURN_RING_RCB_END
value|0x000002FF
end_define

begin_define
define|#
directive|define
name|BGE_STATS_BLOCK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|BGE_STATS_BLOCK_END
value|0x00000AFF
end_define

begin_define
define|#
directive|define
name|BGE_STATUS_BLOCK
value|0x00000B00
end_define

begin_define
define|#
directive|define
name|BGE_STATUS_BLOCK_END
value|0x00000B4F
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENCOMM
value|0x00000B50
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENCOMM_SIG
value|0x00000B54
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENCOMM_NICCFG
value|0x00000B58
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENCOMM_FW
value|0x00000B78
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENNCOMM_FW_LEN
value|0x00000B7C
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENNCOMM_FW_DATA
value|0x00000B80
end_define

begin_define
define|#
directive|define
name|BGE_SOFTWARE_GENCOMM_END
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|BGE_UNMAPPED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_UNMAPPED_END
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|BGE_DMA_DESCRIPTORS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_DMA_DESCRIPTORS_END
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_1_TO_4
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_1_TO_4_END
value|0x00005FFF
end_define

begin_comment
comment|/* Firmware interface */
end_comment

begin_define
define|#
directive|define
name|BGE_FW_DRV_ALIVE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_FW_PAUSE
value|0x00000002
end_define

begin_comment
comment|/* Mappings for internal memory configuration */
end_comment

begin_define
define|#
directive|define
name|BGE_STD_RX_RINGS
value|0x00006000
end_define

begin_define
define|#
directive|define
name|BGE_STD_RX_RINGS_END
value|0x00006FFF
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_RX_RINGS
value|0x00007000
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_RX_RINGS_END
value|0x00007FFF
end_define

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_1
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_1_END
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_2
value|0x00010000
end_define

begin_comment
comment|/* or expansion ROM */
end_comment

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_2_END
value|0x00017FFF
end_define

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_3
value|0x00018000
end_define

begin_comment
comment|/* or expansion ROM */
end_comment

begin_define
define|#
directive|define
name|BGE_BUFFPOOL_3_END
value|0x0001FFFF
end_define

begin_comment
comment|/* Mappings for external SSRAM configurations */
end_comment

begin_define
define|#
directive|define
name|BGE_SEND_RING_5_TO_6
value|0x00006000
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_5_TO_6_END
value|0x00006FFF
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_7_TO_8
value|0x00007000
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_7_TO_8_END
value|0x00007FFF
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_9_TO_16
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_SEND_RING_9_TO_16_END
value|0x0000BFFF
end_define

begin_define
define|#
directive|define
name|BGE_EXT_STD_RX_RINGS
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|BGE_EXT_STD_RX_RINGS_END
value|0x0000CFFF
end_define

begin_define
define|#
directive|define
name|BGE_EXT_JUMBO_RX_RINGS
value|0x0000D000
end_define

begin_define
define|#
directive|define
name|BGE_EXT_JUMBO_RX_RINGS_END
value|0x0000DFFF
end_define

begin_define
define|#
directive|define
name|BGE_MINI_RX_RINGS
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|BGE_MINI_RX_RINGS_END
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BGE_AVAIL_REGION1
value|0x00010000
end_define

begin_comment
comment|/* or expansion ROM */
end_comment

begin_define
define|#
directive|define
name|BGE_AVAIL_REGION1_END
value|0x00017FFF
end_define

begin_define
define|#
directive|define
name|BGE_AVAIL_REGION2
value|0x00018000
end_define

begin_comment
comment|/* or expansion ROM */
end_comment

begin_define
define|#
directive|define
name|BGE_AVAIL_REGION2_END
value|0x0001FFFF
end_define

begin_define
define|#
directive|define
name|BGE_EXT_SSRAM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_EXT_SSRAM_END
value|0x000FFFFF
end_define

begin_comment
comment|/*  * BCM570x register offsets. These are memory mapped registers  * which can be accessed with the CSR_READ_4()/CSR_WRITE_4() macros.  * Each register must be accessed using 32 bit operations.  *  * All registers are accessed through a 32K shared memory block.  * The first group of registers are actually copies of the PCI  * configuration space registers.  */
end_comment

begin_comment
comment|/*  * PCI registers defined in the PCI 2.2 spec.  */
end_comment

begin_define
define|#
directive|define
name|BGE_PCI_VID
value|0x00
end_define

begin_define
define|#
directive|define
name|BGE_PCI_DID
value|0x02
end_define

begin_define
define|#
directive|define
name|BGE_PCI_CMD
value|0x04
end_define

begin_define
define|#
directive|define
name|BGE_PCI_STS
value|0x06
end_define

begin_define
define|#
directive|define
name|BGE_PCI_REV
value|0x08
end_define

begin_define
define|#
directive|define
name|BGE_PCI_CLASS
value|0x09
end_define

begin_define
define|#
directive|define
name|BGE_PCI_CACHESZ
value|0x0C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_LATTIMER
value|0x0D
end_define

begin_define
define|#
directive|define
name|BGE_PCI_HDRTYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|BGE_PCI_BIST
value|0x0F
end_define

begin_define
define|#
directive|define
name|BGE_PCI_BAR0
value|0x10
end_define

begin_define
define|#
directive|define
name|BGE_PCI_BAR1
value|0x14
end_define

begin_define
define|#
directive|define
name|BGE_PCI_SUBSYS
value|0x2C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_SUBVID
value|0x2E
end_define

begin_define
define|#
directive|define
name|BGE_PCI_ROMBASE
value|0x30
end_define

begin_define
define|#
directive|define
name|BGE_PCI_CAPPTR
value|0x34
end_define

begin_define
define|#
directive|define
name|BGE_PCI_INTLINE
value|0x3C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_INTPIN
value|0x3D
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MINGNT
value|0x3E
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MAXLAT
value|0x3F
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PCIXCAP
value|0x40
end_define

begin_define
define|#
directive|define
name|BGE_PCI_NEXTPTR_PM
value|0x41
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PCIX_CMD
value|0x42
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PCIX_STS
value|0x44
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PWRMGMT_CAPID
value|0x48
end_define

begin_define
define|#
directive|define
name|BGE_PCI_NEXTPTR_VPD
value|0x49
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PWRMGMT_CAPS
value|0x4A
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PWRMGMT_CMD
value|0x4C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PWRMGMT_STS
value|0x4D
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PWRMGMT_DATA
value|0x4F
end_define

begin_define
define|#
directive|define
name|BGE_PCI_VPD_CAPID
value|0x50
end_define

begin_define
define|#
directive|define
name|BGE_PCI_NEXTPTR_MSI
value|0x51
end_define

begin_define
define|#
directive|define
name|BGE_PCI_VPD_ADDR
value|0x52
end_define

begin_define
define|#
directive|define
name|BGE_PCI_VPD_DATA
value|0x54
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MSI_CAPID
value|0x58
end_define

begin_define
define|#
directive|define
name|BGE_PCI_NEXTPTR_NONE
value|0x59
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MSI_CTL
value|0x5A
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MSI_ADDR_HI
value|0x5C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MSI_ADDR_LO
value|0x60
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MSI_DATA
value|0x64
end_define

begin_comment
comment|/* PCI MSI. ??? */
end_comment

begin_define
define|#
directive|define
name|BGE_PCIE_CAPID_REG
value|0xD0
end_define

begin_define
define|#
directive|define
name|BGE_PCIE_CAPID
value|0x10
end_define

begin_comment
comment|/*  * PCI registers specific to the BCM570x family.  */
end_comment

begin_define
define|#
directive|define
name|BGE_PCI_MISC_CTL
value|0x68
end_define

begin_define
define|#
directive|define
name|BGE_PCI_DMA_RW_CTL
value|0x6C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_PCISTATE
value|0x70
end_define

begin_define
define|#
directive|define
name|BGE_PCI_CLKCTL
value|0x74
end_define

begin_define
define|#
directive|define
name|BGE_PCI_REG_BASEADDR
value|0x78
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MEMWIN_BASEADDR
value|0x7C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_REG_DATA
value|0x80
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MEMWIN_DATA
value|0x84
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MODECTL
value|0x88
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MISC_CFG
value|0x8C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_MISC_LOCALCTL
value|0x90
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_RX_STD_PRODIDX_HI
value|0x98
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_RX_STD_PRODIDX_LO
value|0x9C
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_RX_RTN_CONSIDX_HI
value|0xA0
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_RX_RTN_CONSIDX_LO
value|0xA4
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_TX_BD_PRODIDX_HI
value|0xA8
end_define

begin_define
define|#
directive|define
name|BGE_PCI_UNDI_TX_BD_PRODIDX_LO
value|0xAC
end_define

begin_define
define|#
directive|define
name|BGE_PCI_ISR_MBX_HI
value|0xB0
end_define

begin_define
define|#
directive|define
name|BGE_PCI_ISR_MBX_LO
value|0xB4
end_define

begin_comment
comment|/* PCI Misc. Host control register */
end_comment

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_CLEAR_INTA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_MASK_PCI_INTR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_ENDIAN_BYTESWAP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_ENDIAN_WORDSWAP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_PCISTATE_RW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_CLOCKCTL_RW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_REG_WORDSWAP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_INDIRECT_ACCESS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_PCIMISCCTL_ASICREV
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|BGE_HIF_SWAP_OPTIONS
value|(BGE_PCIMISCCTL_ENDIAN_WORDSWAP)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|BGE_DMA_SWAP_OPTIONS
define|\
value|BGE_MODECTL_WORDSWAP_NONFRAME| \ 	BGE_MODECTL_BYTESWAP_DATA|BGE_MODECTL_WORDSWAP_DATA
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BGE_DMA_SWAP_OPTIONS
define|\
value|BGE_MODECTL_WORDSWAP_NONFRAME|BGE_MODECTL_BYTESWAP_NONFRAME| \ 	BGE_MODECTL_BYTESWAP_DATA|BGE_MODECTL_WORDSWAP_DATA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BGE_INIT
define|\
value|(BGE_HIF_SWAP_OPTIONS|BGE_PCIMISCCTL_CLEAR_INTA| \ 	 BGE_PCIMISCCTL_MASK_PCI_INTR|BGE_PCIMISCCTL_INDIRECT_ACCESS)
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_TIGON_I
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_TIGON_II
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_A0
value|0x70000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_A1
value|0x70010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_B0
value|0x71000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_B1
value|0x71010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_B2
value|0x71020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_B3
value|0x71030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_ALTIMA
value|0x71040000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5700_C0
value|0x72000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5701_A0
value|0x00000000
end_define

begin_comment
comment|/* grrrr */
end_comment

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5701_B0
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5701_B2
value|0x01020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5701_B5
value|0x01050000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5703_A0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5703_A1
value|0x10010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5703_A2
value|0x10020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5703_A3
value|0x10030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5703_B0
value|0x11000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5704_A0
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5704_A1
value|0x20010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5704_A2
value|0x20020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5704_A3
value|0x20030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5704_B0
value|0x21000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5705_A0
value|0x30000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5705_A1
value|0x30010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5705_A2
value|0x30020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5705_A3
value|0x30030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_A0
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_A1
value|0x40010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_A3
value|0x40030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_B0
value|0x41000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_B1
value|0x41010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_C0
value|0x42000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_C1
value|0x42010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5750_C2
value|0x42020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5714_A0
value|0x50000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5752_A0
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5752_A1
value|0x60010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5752_A2
value|0x60020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5714_B0
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5714_B3
value|0x80030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5715_A0
value|0x90000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5715_A1
value|0x90010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5715_A3
value|0x90030000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5755_A0
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5755_A1
value|0xa0010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5755_A2
value|0xa0020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5754_A0
value|0xb0000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5754_A1
value|0xb0010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5754_A2
value|0xb0020000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5787_A0
value|0xb0000000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5787_A1
value|0xb0010000
end_define

begin_define
define|#
directive|define
name|BGE_CHIPID_BCM5787_A2
value|0xb0020000
end_define

begin_comment
comment|/* shorthand one */
end_comment

begin_define
define|#
directive|define
name|BGE_ASICREV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5701
value|0x00
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5703
value|0x01
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5704
value|0x02
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5705
value|0x03
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5750
value|0x04
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5714_A0
value|0x05
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5752
value|0x06
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5700
value|0x07
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5780
value|0x08
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5714
value|0x09
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5755
value|0x0a
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5754
value|0x0b
end_define

begin_define
define|#
directive|define
name|BGE_ASICREV_BCM5787
value|0x0b
end_define

begin_comment
comment|/* chip revisions */
end_comment

begin_define
define|#
directive|define
name|BGE_CHIPREV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 24)
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5700_AX
value|0x70
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5700_BX
value|0x71
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5700_CX
value|0x72
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5701_AX
value|0x00
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5703_AX
value|0x10
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5704_AX
value|0x20
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5704_BX
value|0x21
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5750_AX
value|0x40
end_define

begin_define
define|#
directive|define
name|BGE_CHIPREV_5750_BX
value|0x41
end_define

begin_comment
comment|/* PCI DMA Read/Write Control register */
end_comment

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_MINDMA
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_RDADRR_BNDRY
value|0x00000700
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_WRADDR_BNDRY
value|0x00003800
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_ONEDMA_ATONCE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_RD_WAT
value|0x00070000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_WR_WAT
value|0x00380000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_USE_MRM
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_ASRT_ALL_BE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_DFLT_PCI_RD_CMD
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_DFLT_PCI_WR_CMD
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_RD_WAT_SHIFT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_WR_WAT_SHIFT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 19)
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_RD_CMD_SHIFT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|BGE_PCIDMARWCTL_WR_CMD_SHIFT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_16BYTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_32BYTES
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_64BYTES
value|0x00000300
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_128BYTES
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_256BYTES
value|0x00000500
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_512BYTES
value|0x00000600
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_BNDRY_1024BYTES
value|0x00000700
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_16BYTES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_32BYTES
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_64BYTES
value|0x00001800
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_128BYTES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_256BYTES
value|0x00002800
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_512BYTES
value|0x00003000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_BNDRY_1024BYTES
value|0x00003800
end_define

begin_comment
comment|/*  * PCI state register -- note, this register is read only  * unless the PCISTATE_WR bit of the PCI Misc. Host Control  * register is set.  */
end_comment

begin_define
define|#
directive|define
name|BGE_PCISTATE_FORCE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_PCISTATE_INTR_STATE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_PCISTATE_PCI_BUSMODE
value|0x00000004
end_define

begin_comment
comment|/* 1 = PCI, 0 = PCI-X */
end_comment

begin_define
define|#
directive|define
name|BGE_PCISTATE_PCI_BUSSPEED
value|0x00000008
end_define

begin_comment
comment|/* 1 = 66/133, 0 = 33/66 */
end_comment

begin_define
define|#
directive|define
name|BGE_PCISTATE_32BIT_BUS
value|0x00000010
end_define

begin_comment
comment|/* 1 = 32bit, 0 = 64bit */
end_comment

begin_define
define|#
directive|define
name|BGE_PCISTATE_WANT_EXPROM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_PCISTATE_EXPROM_RETRY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_PCISTATE_FLATVIEW_MODE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_PCISTATE_PCI_TGT_RETRY_MAX
value|0x00000E00
end_define

begin_comment
comment|/*  * PCI Clock Control register -- note, this register is read only  * unless the CLOCKCTL_RW bit of the PCI Misc. Host Control  * register is set.  */
end_comment

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_DETECTED_SPEED
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_M66EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_LOWPWR_CLKMODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_RXCPU_CLK_DIS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_TXCPU_CLK_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_ALTCLK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_ALTCLK_SRC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_PCIPLL_DISABLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_SYSPLL_DISABLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_PCICLOCKCTL_BIST_ENABLE
value|0x00010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PCIM_CMD_MWIEN
end_ifndef

begin_define
define|#
directive|define
name|PCIM_CMD_MWIEN
value|0x0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * High priority mailbox registers  * Each mailbox is 64-bits wide, though we only use the  * lower 32 bits. To write a 64-bit value, write the upper 32 bits  * first. The NIC will load the mailbox after the lower 32 bit word  * has been updated.  */
end_comment

begin_define
define|#
directive|define
name|BGE_MBX_IRQ0_HI
value|0x0200
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ0_LO
value|0x0204
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ1_HI
value|0x0208
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ1_LO
value|0x020C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ2_HI
value|0x0210
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ2_LO
value|0x0214
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ3_HI
value|0x0218
end_define

begin_define
define|#
directive|define
name|BGE_MBX_IRQ3_LO
value|0x021C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN0_HI
value|0x0220
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN0_LO
value|0x0224
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN1_HI
value|0x0228
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN1_LO
value|0x022C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN2_HI
value|0x0230
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN2_LO
value|0x0234
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN3_HI
value|0x0228
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN3_LO
value|0x022C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN4_HI
value|0x0240
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN4_LO
value|0x0244
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN5_HI
value|0x0248
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN5_LO
value|0x024C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN6_HI
value|0x0250
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN6_LO
value|0x0254
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN7_HI
value|0x0258
end_define

begin_define
define|#
directive|define
name|BGE_MBX_GEN7_LO
value|0x025C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RELOAD_STATS_HI
value|0x0260
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RELOAD_STATS_LO
value|0x0264
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_STD_PROD_HI
value|0x0268
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_STD_PROD_LO
value|0x026C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_JUMBO_PROD_HI
value|0x0270
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_JUMBO_PROD_LO
value|0x0274
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_MINI_PROD_HI
value|0x0278
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_MINI_PROD_LO
value|0x027C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS0_HI
value|0x0280
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS0_LO
value|0x0284
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS1_HI
value|0x0288
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS1_LO
value|0x028C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS2_HI
value|0x0290
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS2_LO
value|0x0294
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS3_HI
value|0x0298
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS3_LO
value|0x029C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS4_HI
value|0x02A0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS4_LO
value|0x02A4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS5_HI
value|0x02A8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS5_LO
value|0x02AC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS6_HI
value|0x02B0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS6_LO
value|0x02B4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS7_HI
value|0x02B8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS7_LO
value|0x02BC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS8_HI
value|0x02C0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS8_LO
value|0x02C4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS9_HI
value|0x02C8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS9_LO
value|0x02CC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS10_HI
value|0x02D0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS10_LO
value|0x02D4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS11_HI
value|0x02D8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS11_LO
value|0x02DC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS12_HI
value|0x02E0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS12_LO
value|0x02E4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS13_HI
value|0x02E8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS13_LO
value|0x02EC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS14_HI
value|0x02F0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS14_LO
value|0x02F4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS15_HI
value|0x02F8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_RX_CONS15_LO
value|0x02FC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD0_HI
value|0x0300
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD0_LO
value|0x0304
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD1_HI
value|0x0308
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD1_LO
value|0x030C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD2_HI
value|0x0310
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD2_LO
value|0x0314
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD3_HI
value|0x0318
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD3_LO
value|0x031C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD4_HI
value|0x0320
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD4_LO
value|0x0324
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD5_HI
value|0x0328
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD5_LO
value|0x032C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD6_HI
value|0x0330
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD6_LO
value|0x0334
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD7_HI
value|0x0338
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD7_LO
value|0x033C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD8_HI
value|0x0340
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD8_LO
value|0x0344
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD9_HI
value|0x0348
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD9_LO
value|0x034C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD10_HI
value|0x0350
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD10_LO
value|0x0354
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD11_HI
value|0x0358
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD11_LO
value|0x035C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD12_HI
value|0x0360
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD12_LO
value|0x0364
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD13_HI
value|0x0368
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD13_LO
value|0x036C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD14_HI
value|0x0370
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD14_LO
value|0x0374
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD15_HI
value|0x0378
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_HOST_PROD15_LO
value|0x037C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD0_HI
value|0x0380
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD0_LO
value|0x0384
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD1_HI
value|0x0388
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD1_LO
value|0x038C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD2_HI
value|0x0390
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD2_LO
value|0x0394
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD3_HI
value|0x0398
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD3_LO
value|0x039C
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD4_HI
value|0x03A0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD4_LO
value|0x03A4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD5_HI
value|0x03A8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD5_LO
value|0x03AC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD6_HI
value|0x03B0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD6_LO
value|0x03B4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD7_HI
value|0x03B8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD7_LO
value|0x03BC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD8_HI
value|0x03C0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD8_LO
value|0x03C4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD9_HI
value|0x03C8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD9_LO
value|0x03CC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD10_HI
value|0x03D0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD10_LO
value|0x03D4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD11_HI
value|0x03D8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD11_LO
value|0x03DC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD12_HI
value|0x03E0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD12_LO
value|0x03E4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD13_HI
value|0x03E8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD13_LO
value|0x03EC
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD14_HI
value|0x03F0
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD14_LO
value|0x03F4
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD15_HI
value|0x03F8
end_define

begin_define
define|#
directive|define
name|BGE_MBX_TX_NIC_PROD15_LO
value|0x03FC
end_define

begin_define
define|#
directive|define
name|BGE_TX_RINGS_MAX
value|4
end_define

begin_define
define|#
directive|define
name|BGE_TX_RINGS_EXTSSRAM_MAX
value|16
end_define

begin_define
define|#
directive|define
name|BGE_RX_RINGS_MAX
value|16
end_define

begin_comment
comment|/* Ethernet MAC control registers */
end_comment

begin_define
define|#
directive|define
name|BGE_MAC_MODE
value|0x0400
end_define

begin_define
define|#
directive|define
name|BGE_MAC_STS
value|0x0404
end_define

begin_define
define|#
directive|define
name|BGE_MAC_EVT_ENB
value|0x0408
end_define

begin_define
define|#
directive|define
name|BGE_MAC_LED_CTL
value|0x040C
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR1_LO
value|0x0410
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR1_HI
value|0x0414
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR2_LO
value|0x0418
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR2_HI
value|0x041C
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR3_LO
value|0x0420
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR3_HI
value|0x0424
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR4_LO
value|0x0428
end_define

begin_define
define|#
directive|define
name|BGE_MAC_ADDR4_HI
value|0x042C
end_define

begin_define
define|#
directive|define
name|BGE_WOL_PATPTR
value|0x0430
end_define

begin_define
define|#
directive|define
name|BGE_WOL_PATCFG
value|0x0434
end_define

begin_define
define|#
directive|define
name|BGE_TX_RANDOM_BACKOFF
value|0x0438
end_define

begin_define
define|#
directive|define
name|BGE_RX_MTU
value|0x043C
end_define

begin_define
define|#
directive|define
name|BGE_GBIT_PCS_TEST
value|0x0440
end_define

begin_define
define|#
directive|define
name|BGE_TX_TBI_AUTONEG
value|0x0444
end_define

begin_define
define|#
directive|define
name|BGE_RX_TBI_AUTONEG
value|0x0448
end_define

begin_define
define|#
directive|define
name|BGE_MI_COMM
value|0x044C
end_define

begin_define
define|#
directive|define
name|BGE_MI_STS
value|0x0450
end_define

begin_define
define|#
directive|define
name|BGE_MI_MODE
value|0x0454
end_define

begin_define
define|#
directive|define
name|BGE_AUTOPOLL_STS
value|0x0458
end_define

begin_define
define|#
directive|define
name|BGE_TX_MODE
value|0x045C
end_define

begin_define
define|#
directive|define
name|BGE_TX_STS
value|0x0460
end_define

begin_define
define|#
directive|define
name|BGE_TX_LENGTHS
value|0x0464
end_define

begin_define
define|#
directive|define
name|BGE_RX_MODE
value|0x0468
end_define

begin_define
define|#
directive|define
name|BGE_RX_STS
value|0x046C
end_define

begin_define
define|#
directive|define
name|BGE_MAR0
value|0x0470
end_define

begin_define
define|#
directive|define
name|BGE_MAR1
value|0x0474
end_define

begin_define
define|#
directive|define
name|BGE_MAR2
value|0x0478
end_define

begin_define
define|#
directive|define
name|BGE_MAR3
value|0x047C
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL0
value|0x0480
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL0
value|0x0484
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL1
value|0x0488
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL1
value|0x048C
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL2
value|0x0490
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL2
value|0x0494
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL3
value|0x0498
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL3
value|0x049C
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL4
value|0x04A0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL4
value|0x04A4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL5
value|0x04A8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL5
value|0x04AC
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL6
value|0x04B0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL6
value|0x04B4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL7
value|0x04B8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL7
value|0x04BC
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL8
value|0x04C0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL8
value|0x04C4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL9
value|0x04C8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL9
value|0x04CC
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL10
value|0x04D0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL10
value|0x04D4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL11
value|0x04D8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL11
value|0x04DC
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL12
value|0x04E0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL12
value|0x04E4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL13
value|0x04E8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL13
value|0x04EC
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL14
value|0x04F0
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL14
value|0x04F4
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_CTL15
value|0x04F8
end_define

begin_define
define|#
directive|define
name|BGE_RX_BD_RULES_MASKVAL15
value|0x04FC
end_define

begin_define
define|#
directive|define
name|BGE_RX_RULES_CFG
value|0x0500
end_define

begin_define
define|#
directive|define
name|BGE_SERDES_CFG
value|0x0590
end_define

begin_define
define|#
directive|define
name|BGE_SERDES_STS
value|0x0594
end_define

begin_define
define|#
directive|define
name|BGE_SGDIG_CFG
value|0x05B0
end_define

begin_define
define|#
directive|define
name|BGE_SGDIG_STS
value|0x05B4
end_define

begin_define
define|#
directive|define
name|BGE_MAC_STATS
value|0x0800
end_define

begin_comment
comment|/* Ethernet MAC Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_MACMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_HALF_DUPLEX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_PORTMODE
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_LOOPBACK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_RX_TAGGEDPKT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TX_BURST_ENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_MAX_DEFER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_LINK_POLARITY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_RX_STATS_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_RX_STATS_CLEAR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_RX_STATS_FLUSH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TX_STATS_ENB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TX_STATS_CLEAR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TX_STATS_FLUSH
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TBI_SEND_CFGS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_MAGIC_PKT_ENB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_ACPI_PWRON_ENB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_MIP_ENB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_TXDMA_ENB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_RXDMA_ENB
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_MACMODE_FRMHDR_DMA_ENB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_PORTMODE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_PORTMODE_MII
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_PORTMODE_GMII
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_PORTMODE_TBI
value|0x0000000C
end_define

begin_comment
comment|/* MAC Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_MACSTAT_TBI_PCS_SYNCHED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_TBI_SIGNAL_DETECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_RX_CFG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_CFG_CHANGED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_SYNC_CHANGED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_PORT_DECODE_ERROR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_LINK_CHANGED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_MI_COMPLETE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_MI_INTERRUPT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_AUTOPOLL_ERROR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_ODI_ERROR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_RXSTAT_OFLOW
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BGE_MACSTAT_TXSTAT_OFLOW
value|0x08000000
end_define

begin_comment
comment|/* MAC Event Enable Register */
end_comment

begin_define
define|#
directive|define
name|BGE_EVTENB_PORT_DECODE_ERROR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_LINK_CHANGED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_MI_COMPLETE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_MI_INTERRUPT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_AUTOPOLL_ERROR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_ODI_ERROR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_RXSTAT_OFLOW
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BGE_EVTENB_TXSTAT_OFLOW
value|0x08000000
end_define

begin_comment
comment|/* LED Control Register */
end_comment

begin_define
define|#
directive|define
name|BGE_LEDCTL_LINKLED_OVERRIDE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_1000MBPS_LED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_100MBPS_LED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_10MBPS_LED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_TRAFLED_OVERRIDE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_TRAFLED_BLINK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_TREFLED_BLINK_2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_1000MBPS_STS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_100MBPS_STS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_10MBPS_STS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_TRADLED_STS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_BLINKPERIOD
value|0x7FF80000
end_define

begin_define
define|#
directive|define
name|BGE_LEDCTL_BLINKPERIOD_OVERRIDE
value|0x80000000
end_define

begin_comment
comment|/* TX backoff seed register */
end_comment

begin_define
define|#
directive|define
name|BGE_TX_BACKOFF_SEED_MASK
value|0x3F
end_define

begin_comment
comment|/* Autopoll status register */
end_comment

begin_define
define|#
directive|define
name|BGE_AUTOPOLLSTS_ERROR
value|0x00000001
end_define

begin_comment
comment|/* Transmit MAC mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_TXMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_TXMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_TXMODE_FLOWCTL_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_TXMODE_BIGBACKOFF_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_TXMODE_LONGPAUSE_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* Transmit MAC status register */
end_comment

begin_define
define|#
directive|define
name|BGE_TXSTAT_RX_XOFFED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_TXSTAT_SENT_XOFF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_TXSTAT_SENT_XON
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_TXSTAT_LINK_UP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_TXSTAT_ODI_UFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_TXSTAT_ODI_OFLOW
value|0x00000020
end_define

begin_comment
comment|/* Transmit MAC lengths register */
end_comment

begin_define
define|#
directive|define
name|BGE_TXLEN_SLOTTIME
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BGE_TXLEN_IPG
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|BGE_TXLEN_CRS
value|0x00003000
end_define

begin_comment
comment|/* Receive MAC mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_FLOWCTL_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_RX_GIANTS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_RX_RUNTS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_8022_LENCHECK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_RX_PROMISC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_RX_NO_CRC_CHECK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_RXMODE_RX_KEEP_VLAN_DIAG
value|0x00000400
end_define

begin_comment
comment|/* Receive MAC status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXSTAT_REMOTE_XOFFED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXSTAT_RCVD_XOFF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXSTAT_RCVD_XON
value|0x00000004
end_define

begin_comment
comment|/* Receive Rules Control register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXRULECTL_OFFSET
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_CLASS
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_HDRTYPE
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_COMPARE_OP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_MAP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_DISCARD
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_MASK
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_ACTIVATE_PROC3
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_ACTIVATE_PROC2
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_ACTIVATE_PROC1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_RXRULECTL_ANDWITHNEXT
value|0x40000000
end_define

begin_comment
comment|/* Receive Rules Mask register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXRULEMASK_VALUE
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BGE_RXRULEMASK_MASKVAL
value|0xFFFF0000
end_define

begin_comment
comment|/* SERDES configuration register */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_RXR
value|0x00000007
end_define

begin_comment
comment|/* phase interpolator */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_RXG
value|0x00000018
end_define

begin_comment
comment|/* rx gain setting */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_RXEDGESEL
value|0x00000040
end_define

begin_comment
comment|/* rising/falling egde */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_TX_BIAS
value|0x00000380
end_define

begin_comment
comment|/* TXDAC bias setting */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_IBMAX
value|0x00000400
end_define

begin_comment
comment|/* bias current +25% */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_IBMIN
value|0x00000800
end_define

begin_comment
comment|/* bias current -25% */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_TXMODE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_SERDESCFG_TXEDGESEL
value|0x00002000
end_define

begin_comment
comment|/* rising/falling edge */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_MODE
value|0x00004000
end_define

begin_comment
comment|/* TXCP/TXCN disabled */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_PLLTEST
value|0x00008000
end_define

begin_comment
comment|/* PLL test mode */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_CDET
value|0x00010000
end_define

begin_comment
comment|/* comma detect enable */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_TBILOOP
value|0x00020000
end_define

begin_comment
comment|/* local loopback */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_REMLOOP
value|0x00040000
end_define

begin_comment
comment|/* remote loopback */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_INVPHASE
value|0x00080000
end_define

begin_comment
comment|/* Reverse 125Mhz clock */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_12REGCTL
value|0x00300000
end_define

begin_comment
comment|/* 1.2v regulator ctl */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESCFG_REGCTL
value|0x00C00000
end_define

begin_comment
comment|/* regulator ctl (2.5v) */
end_comment

begin_comment
comment|/* SERDES status register */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESSTS_RXSTAT
value|0x0000000F
end_define

begin_comment
comment|/* receive status bits */
end_comment

begin_define
define|#
directive|define
name|BGE_SERDESSTS_CDET
value|0x00000010
end_define

begin_comment
comment|/* comma code detected */
end_comment

begin_comment
comment|/* SGDIG config (not documented) */
end_comment

begin_define
define|#
directive|define
name|BGE_SGDIGCFG_PAUSE_CAP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_SGDIGCFG_ASYM_PAUSE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_SGDIGCFG_SEND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_SGDIGCFG_AUTO
value|0x80000000
end_define

begin_comment
comment|/* SGDIG status (not documented) */
end_comment

begin_define
define|#
directive|define
name|BGE_SGDIGSTS_PAUSE_CAP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_SGDIGSTS_ASYM_PAUSE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_SGDIGSTS_DONE
value|0x00000002
end_define

begin_comment
comment|/* MI communication register */
end_comment

begin_define
define|#
directive|define
name|BGE_MICOMM_DATA
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BGE_MICOMM_REG
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|BGE_MICOMM_PHY
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|BGE_MICOMM_CMD
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|BGE_MICOMM_READFAIL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_MICOMM_BUSY
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_MIREG
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1F)<< 16)
end_define

begin_define
define|#
directive|define
name|BGE_MIPHY
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1F)<< 21)
end_define

begin_define
define|#
directive|define
name|BGE_MICMD_WRITE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BGE_MICMD_READ
value|0x08000000
end_define

begin_comment
comment|/* MI status register */
end_comment

begin_define
define|#
directive|define
name|BGE_MISTS_LINK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MISTS_10MBPS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MIMODE_SHORTPREAMBLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MIMODE_AUTOPOLL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MIMODE_CLKCNT
value|0x001F0000
end_define

begin_comment
comment|/*  * Send data initiator control registers.  */
end_comment

begin_define
define|#
directive|define
name|BGE_SDI_MODE
value|0x0C00
end_define

begin_define
define|#
directive|define
name|BGE_SDI_STATUS
value|0x0C04
end_define

begin_define
define|#
directive|define
name|BGE_SDI_STATS_CTL
value|0x0C08
end_define

begin_define
define|#
directive|define
name|BGE_SDI_STATS_ENABLE_MASK
value|0x0C0C
end_define

begin_define
define|#
directive|define
name|BGE_SDI_STATS_INCREMENT_MASK
value|0x0C10
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS0
value|0x0C80
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS1
value|0x0C84
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS2
value|0x0C88
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS3
value|0x0C8C
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS4
value|0x0C90
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS5
value|0x0C84
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS6
value|0x0C98
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS7
value|0x0C9C
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS8
value|0x0CA0
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS9
value|0x0CA4
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS10
value|0x0CA8
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS11
value|0x0CAC
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS12
value|0x0CB0
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS13
value|0x0CB4
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS14
value|0x0CB8
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_COS15
value|0x0CBC
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_DMA_RQ_FULL
value|0x0CC0
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_DMA_HIPRIO_RQ_FULL
value|0x0CC4
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_SDC_QUEUE_FULL
value|0x0CC8
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_NIC_SENDPROD_SET
value|0x0CCC
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_STATS_UPDATED
value|0x0CD0
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_IRQS
value|0x0CD4
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_AVOIDED_IRQS
value|0x0CD8
end_define

begin_define
define|#
directive|define
name|BGE_LOCSTATS_TX_THRESH_HIT
value|0x0CDC
end_define

begin_comment
comment|/* Send Data Initiator mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_SDIMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SDIMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SDIMODE_STATS_OFLOW_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send Data Initiator stats register */
end_comment

begin_define
define|#
directive|define
name|BGE_SDISTAT_STATS_OFLOW_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send Data Initiator stats control register */
end_comment

begin_define
define|#
directive|define
name|BGE_SDISTATSCTL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SDISTATSCTL_FASTER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SDISTATSCTL_CLEAR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_SDISTATSCTL_FORCEFLUSH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_SDISTATSCTL_FORCEZERO
value|0x00000010
end_define

begin_comment
comment|/*  * Send Data Completion Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_SDC_MODE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BGE_SDC_STATUS
value|0x1004
end_define

begin_comment
comment|/* Send Data completion mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_SDCMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SDCMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SDCMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send Data completion status register */
end_comment

begin_define
define|#
directive|define
name|BGE_SDCSTAT_ATTN
value|0x00000004
end_define

begin_comment
comment|/*  * Send BD Ring Selector Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_SRS_MODE
value|0x1400
end_define

begin_define
define|#
directive|define
name|BGE_SRS_STATUS
value|0x1404
end_define

begin_define
define|#
directive|define
name|BGE_SRS_HWDIAG
value|0x1408
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS0
value|0x1440
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS1
value|0x1444
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS2
value|0x1448
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS3
value|0x144C
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS4
value|0x1450
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS5
value|0x1454
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS6
value|0x1458
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS7
value|0x145C
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS8
value|0x1460
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS9
value|0x1464
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS10
value|0x1468
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS11
value|0x146C
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS12
value|0x1470
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS13
value|0x1474
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS14
value|0x1478
end_define

begin_define
define|#
directive|define
name|BGE_SRS_LOC_NIC_CONS15
value|0x147C
end_define

begin_comment
comment|/* Send BD Ring Selector Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_SRSMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SRSMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SRSMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send BD Ring Selector Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_SRSSTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/* Send BD Ring Selector HW Diagnostics register */
end_comment

begin_define
define|#
directive|define
name|BGE_SRSHWDIAG_STATE
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|BGE_SRSHWDIAG_CURRINGNUM
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|BGE_SRSHWDIAG_STAGEDRINGNUM
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|BGE_SRSHWDIAG_RINGNUM_IN_MBX
value|0x0000F000
end_define

begin_comment
comment|/*  * Send BD Initiator Selector Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDI_MODE
value|0x1800
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_STATUS
value|0x1804
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD0
value|0x1808
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD1
value|0x180C
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD2
value|0x1810
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD3
value|0x1814
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD4
value|0x1818
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD5
value|0x181C
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD6
value|0x1820
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD7
value|0x1824
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD8
value|0x1828
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD9
value|0x182C
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD10
value|0x1830
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD11
value|0x1834
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD12
value|0x1838
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD13
value|0x183C
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD14
value|0x1840
end_define

begin_define
define|#
directive|define
name|BGE_SBDI_LOC_NIC_PROD15
value|0x1844
end_define

begin_comment
comment|/* Send BD Initiator Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDIMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SBDIMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SBDIMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send BD Initiator Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDISTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * Send BD Completion Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDC_MODE
value|0x1C00
end_define

begin_define
define|#
directive|define
name|BGE_SBDC_STATUS
value|0x1C04
end_define

begin_comment
comment|/* Send BD Completion Control Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDCMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_SBDCMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_SBDCMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Send BD Completion Control Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_SBDCSTAT_ATTN
value|0x00000004
end_define

begin_comment
comment|/*  * Receive List Placement Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLP_MODE
value|0x2000
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_STATUS
value|0x2004
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_SEL_LIST_LOCK
value|0x2008
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_SEL_NON_EMPTY_BITS
value|0x200C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_CFG
value|0x2010
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_STATS_CTL
value|0x2014
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_STATS_ENABLE_MASK
value|0x2018
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_STATS_INCREMENT_MASK
value|0x201C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD0
value|0x2100
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL0
value|0x2104
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT0
value|0x2108
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD1
value|0x2110
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL1
value|0x2114
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT1
value|0x2118
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD2
value|0x2120
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL2
value|0x2124
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT2
value|0x2128
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD3
value|0x2130
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL3
value|0x2134
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT3
value|0x2138
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD4
value|0x2140
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL4
value|0x2144
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT4
value|0x2148
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD5
value|0x2150
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL5
value|0x2154
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT5
value|0x2158
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD6
value|0x2160
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL6
value|0x2164
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT6
value|0x2168
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD7
value|0x2170
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL7
value|0x2174
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT7
value|0x2178
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD8
value|0x2180
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL8
value|0x2184
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT8
value|0x2188
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD9
value|0x2190
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL9
value|0x2194
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT9
value|0x2198
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD10
value|0x21A0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL10
value|0x21A4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT10
value|0x21A8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD11
value|0x21B0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL11
value|0x21B4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT11
value|0x21B8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD12
value|0x21C0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL12
value|0x21C4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT12
value|0x21C8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD13
value|0x21D0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL13
value|0x21D4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT13
value|0x21D8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD14
value|0x21E0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL14
value|0x21E4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT14
value|0x21E8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_HEAD15
value|0x21F0
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_TAIL15
value|0x21F4
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_COUNT15
value|0x21F8
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS0
value|0x2200
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS1
value|0x2204
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS2
value|0x2208
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS3
value|0x220C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS4
value|0x2210
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS5
value|0x2214
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS6
value|0x2218
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS7
value|0x221C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS8
value|0x2220
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS9
value|0x2224
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS10
value|0x2228
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS11
value|0x222C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS12
value|0x2230
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS13
value|0x2234
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS14
value|0x2238
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_COS15
value|0x223C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_FILTDROP
value|0x2240
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_DMA_WRQ_FULL
value|0x2244
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_DMA_HPWRQ_FULL
value|0x2248
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_OUT_OF_BDS
value|0x224C
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_IFIN_DROPS
value|0x2250
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_IFIN_ERRORS
value|0x2254
end_define

begin_define
define|#
directive|define
name|BGE_RXLP_LOCSTAT_RXTHRESH_HIT
value|0x2258
end_define

begin_comment
comment|/* Receive List Placement mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLPMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXLPMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXLPMODE_CLASS0_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RXLPMODE_MAPOUTRANGE_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RXLPMODE_STATSOFLOW_ATTN
value|0x00000010
end_define

begin_comment
comment|/* Receive List Placement Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLPSTAT_CLASS0_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RXLPSTAT_MAPOUTRANGE_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RXLPSTAT_STATSOFLOW_ATTN
value|0x00000010
end_define

begin_comment
comment|/*  * Receive Data and Receive BD Initiator Control Registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RDBDI_MODE
value|0x2400
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_STATUS
value|0x2404
end_define

begin_define
define|#
directive|define
name|BGE_RX_JUMBO_RCB_HADDR_HI
value|0x2440
end_define

begin_define
define|#
directive|define
name|BGE_RX_JUMBO_RCB_HADDR_LO
value|0x2444
end_define

begin_define
define|#
directive|define
name|BGE_RX_JUMBO_RCB_MAXLEN_FLAGS
value|0x2448
end_define

begin_define
define|#
directive|define
name|BGE_RX_JUMBO_RCB_NICADDR
value|0x244C
end_define

begin_define
define|#
directive|define
name|BGE_RX_STD_RCB_HADDR_HI
value|0x2450
end_define

begin_define
define|#
directive|define
name|BGE_RX_STD_RCB_HADDR_LO
value|0x2454
end_define

begin_define
define|#
directive|define
name|BGE_RX_STD_RCB_MAXLEN_FLAGS
value|0x2458
end_define

begin_define
define|#
directive|define
name|BGE_RX_STD_RCB_NICADDR
value|0x245C
end_define

begin_define
define|#
directive|define
name|BGE_RX_MINI_RCB_HADDR_HI
value|0x2460
end_define

begin_define
define|#
directive|define
name|BGE_RX_MINI_RCB_HADDR_LO
value|0x2464
end_define

begin_define
define|#
directive|define
name|BGE_RX_MINI_RCB_MAXLEN_FLAGS
value|0x2468
end_define

begin_define
define|#
directive|define
name|BGE_RX_MINI_RCB_NICADDR
value|0x246C
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_JUMBO_RX_CONS
value|0x2470
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_STD_RX_CONS
value|0x2474
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_MINI_RX_CONS
value|0x2478
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD0
value|0x2480
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD1
value|0x2484
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD2
value|0x2488
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD3
value|0x248C
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD4
value|0x2490
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD5
value|0x2494
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD6
value|0x2498
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD7
value|0x249C
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD8
value|0x24A0
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD9
value|0x24A4
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD10
value|0x24A8
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD11
value|0x24AC
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD12
value|0x24B0
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD13
value|0x24B4
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD14
value|0x24B8
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_RETURN_PROD15
value|0x24BC
end_define

begin_define
define|#
directive|define
name|BGE_RDBDI_HWDIAG
value|0x24C0
end_define

begin_comment
comment|/* Receive Data and Receive BD Initiator Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RDBDIMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RDBDIMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RDBDIMODE_JUMBO_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RDBDIMODE_GIANT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RDBDIMODE_BADRINGSZ_ATTN
value|0x00000010
end_define

begin_comment
comment|/* Receive Data and Receive BD Initiator Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RDBDISTAT_JUMBO_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RDBDISTAT_GIANT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RDBDISTAT_BADRINGSZ_ATTN
value|0x00000010
end_define

begin_comment
comment|/*  * Receive Data Completion Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RDC_MODE
value|0x2800
end_define

begin_comment
comment|/* Receive Data Completion Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RDCMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RDCMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RDCMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/*  * Receive BD Initiator Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDI_MODE
value|0x2C00
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_STATUS
value|0x2C04
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_NIC_JUMBO_BD_PROD
value|0x2C08
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_NIC_STD_BD_PROD
value|0x2C0C
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_NIC_MINI_BD_PROD
value|0x2C10
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_MINI_REPL_THRESH
value|0x2C14
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_STD_REPL_THRESH
value|0x2C18
end_define

begin_define
define|#
directive|define
name|BGE_RBDI_JUMBO_REPL_THRESH
value|0x2C1C
end_define

begin_comment
comment|/* Receive BD Initiator Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDIMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RBDIMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RBDIMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Receive BD Initiator Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDISTAT_ATTN
value|0x00000004
end_define

begin_comment
comment|/*  * Receive BD Completion Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDC_MODE
value|0x3000
end_define

begin_define
define|#
directive|define
name|BGE_RBDC_STATUS
value|0x3004
end_define

begin_define
define|#
directive|define
name|BGE_RBDC_JUMBO_BD_PROD
value|0x3008
end_define

begin_define
define|#
directive|define
name|BGE_RBDC_STD_BD_PROD
value|0x300C
end_define

begin_define
define|#
directive|define
name|BGE_RBDC_MINI_BD_PROD
value|0x3010
end_define

begin_comment
comment|/* Receive BD completion mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDCMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RBDCMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RBDCMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Receive BD completion status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RBDCSTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * Receive List Selector Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLS_MODE
value|0x3400
end_define

begin_define
define|#
directive|define
name|BGE_RXLS_STATUS
value|0x3404
end_define

begin_comment
comment|/* Receive List Selector Mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLSMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXLSMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXLSMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Receive List Selector Status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXLSSTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * Mbuf Cluster Free registers (has nothing to do with BSD mbufs)  */
end_comment

begin_define
define|#
directive|define
name|BGE_MBCF_MODE
value|0x3800
end_define

begin_define
define|#
directive|define
name|BGE_MBCF_STATUS
value|0x3804
end_define

begin_comment
comment|/* Mbuf Cluster Free mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_MBCFMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MBCFMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MBCFMODE_ATTN
value|0x00000004
end_define

begin_comment
comment|/* Mbuf Cluster Free status register */
end_comment

begin_define
define|#
directive|define
name|BGE_MBCFSTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * Host Coalescing Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_MODE
value|0x3C00
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATUS
value|0x3C04
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_COAL_TICKS
value|0x3C08
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_COAL_TICKS
value|0x3C0C
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_MAX_COAL_BDS
value|0x3C10
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_MAX_COAL_BDS
value|0x3C14
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_COAL_TICKS_INT
value|0x3C18
end_define

begin_comment
comment|/* ticks during interrupt */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_TX_COAL_TICKS_INT
value|0x3C1C
end_define

begin_comment
comment|/* ticks during interrupt */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_RX_MAX_COAL_BDS_INT
value|0x3C20
end_define

begin_comment
comment|/* BDs during interrupt */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_TX_MAX_COAL_BDS_INT
value|0x3C24
end_define

begin_comment
comment|/* BDs during interrupt */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_STATS_TICKS
value|0x3C28
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATS_ADDR_HI
value|0x3C30
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATS_ADDR_LO
value|0x3C34
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATUSBLK_ADDR_HI
value|0x3C38
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATUSBLK_ADDR_LO
value|0x3C3C
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STATS_BASEADDR
value|0x3C40
end_define

begin_comment
comment|/* address in NIC memory */
end_comment

begin_define
define|#
directive|define
name|BGE_HCC_STATUSBLK_BASEADDR
value|0x3C44
end_define

begin_comment
comment|/* address in NIC memory */
end_comment

begin_define
define|#
directive|define
name|BGE_FLOW_ATTN
value|0x3C48
end_define

begin_define
define|#
directive|define
name|BGE_HCC_JUMBO_BD_CONS
value|0x3C50
end_define

begin_define
define|#
directive|define
name|BGE_HCC_STD_BD_CONS
value|0x3C54
end_define

begin_define
define|#
directive|define
name|BGE_HCC_MINI_BD_CONS
value|0x3C58
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD0
value|0x3C80
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD1
value|0x3C84
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD2
value|0x3C88
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD3
value|0x3C8C
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD4
value|0x3C90
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD5
value|0x3C94
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD6
value|0x3C98
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD7
value|0x3C9C
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD8
value|0x3CA0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD9
value|0x3CA4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD10
value|0x3CA8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD11
value|0x3CAC
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD12
value|0x3CB0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD13
value|0x3CB4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD14
value|0x3CB8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_RX_RETURN_PROD15
value|0x3CBC
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS0
value|0x3CC0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS1
value|0x3CC4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS2
value|0x3CC8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS3
value|0x3CCC
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS4
value|0x3CD0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS5
value|0x3CD4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS6
value|0x3CD8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS7
value|0x3CDC
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS8
value|0x3CE0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS9
value|0x3CE4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS10
value|0x3CE8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS11
value|0x3CEC
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS12
value|0x3CF0
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS13
value|0x3CF4
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS14
value|0x3CF8
end_define

begin_define
define|#
directive|define
name|BGE_HCC_TX_BD_CONS15
value|0x3CFC
end_define

begin_comment
comment|/* Host coalescing mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_HCCMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_HCCMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_HCCMODE_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_HCCMODE_COAL_NOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_HCCMODE_MSI_BITS
value|0x00000070
end_define

begin_define
define|#
directive|define
name|BGE_HCCMODE_STATBLK_SIZE
value|0x00000180
end_define

begin_define
define|#
directive|define
name|BGE_STATBLKSZ_FULL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_STATBLKSZ_64BYTE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_STATBLKSZ_32BYTE
value|0x00000100
end_define

begin_comment
comment|/* Host coalescing status register */
end_comment

begin_define
define|#
directive|define
name|BGE_HCCSTAT_ERROR
value|0x00000004
end_define

begin_comment
comment|/* Flow attention register */
end_comment

begin_define
define|#
directive|define
name|BGE_FLOWATTN_MB_LOWAT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_MEMARB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_HOSTCOAL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_DMADONE_DISCARD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RCB_INVAL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RXDATA_CORRUPT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RDBDI
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RXLS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RXLP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RBDC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_RBDI
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_SDC
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_SDI
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_SRS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_SBDC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_FLOWATTN_SBDI
value|0x80000000
end_define

begin_comment
comment|/*  * Memory arbiter registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_MARB_MODE
value|0x4000
end_define

begin_define
define|#
directive|define
name|BGE_MARB_STATUS
value|0x4004
end_define

begin_define
define|#
directive|define
name|BGE_MARB_TRAPADDR_HI
value|0x4008
end_define

begin_define
define|#
directive|define
name|BGE_MARB_TRAPADDR_LO
value|0x400C
end_define

begin_comment
comment|/* Memory arbiter mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_MARBMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_TX_ADDR_TRAP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_RX_ADDR_TRAP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_DMAW1_TRAP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_DMAR1_TRAP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_RXRISC_TRAP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_TXRISC_TRAP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_PCI_TRAP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_DMAR2_TRAP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_RXQ_TRAP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_RXDI1_TRAP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_RXDI2_TRAP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_DC_GRPMEM_TRAP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_HCOAL_TRAP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_MBUF_TRAP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_TXDI_TRAP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_SDC_DMAC_TRAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_TXBD_TRAP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_BUFFMAN_TRAP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_DMAW2_TRAP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_XTSSRAM_ROFLO_TRAP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_XTSSRAM_RUFLO_TRAP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_XTSSRAM_WOFLO_TRAP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_XTSSRAM_WUFLO_TRAP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_MARBMODE_XTSSRAM_PERR_TRAP
value|0x02000000
end_define

begin_comment
comment|/* Memory arbiter status register */
end_comment

begin_define
define|#
directive|define
name|BGE_MARBSTAT_TX_ADDR_TRAP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_RX_ADDR_TRAP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_DMAW1_TRAP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_DMAR1_TRAP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_RXRISC_TRAP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_TXRISC_TRAP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_PCI_TRAP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_DMAR2_TRAP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_RXQ_TRAP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_RXDI1_TRAP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_RXDI2_TRAP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_DC_GRPMEM_TRAP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_HCOAL_TRAP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_MBUF_TRAP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_TXDI_TRAP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_SDC_DMAC_TRAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_TXBD_TRAP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_BUFFMAN_TRAP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_DMAW2_TRAP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_XTSSRAM_ROFLO_TRAP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_XTSSRAM_RUFLO_TRAP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_XTSSRAM_WOFLO_TRAP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_XTSSRAM_WUFLO_TRAP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_MARBSTAT_XTSSRAM_PERR_TRAP
value|0x02000000
end_define

begin_comment
comment|/*  * Buffer manager control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_BMAN_MODE
value|0x4400
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_STATUS
value|0x4404
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_MBUFPOOL_BASEADDR
value|0x4408
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_MBUFPOOL_LEN
value|0x440C
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_MBUFPOOL_READDMA_LOWAT
value|0x4410
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_MBUFPOOL_MACRX_LOWAT
value|0x4414
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_MBUFPOOL_HIWAT
value|0x4418
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_RXCPU_MBALLOC_REQ
value|0x441C
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_RXCPU_MBALLOC_RESP
value|0x4420
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_TXCPU_MBALLOC_REQ
value|0x4424
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_TXCPU_MBALLOC_RESP
value|0x4428
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_DMA_DESCPOOL_BASEADDR
value|0x442C
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_DMA_DESCPOOL_LEN
value|0x4430
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_DMA_DESCPOOL_LOWAT
value|0x4434
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_DMA_DESCPOOL_HIWAT
value|0x4438
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_RXCPU_DMAALLOC_REQ
value|0x443C
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_RXCPU_DMAALLOC_RESP
value|0x4440
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_TXCPU_DMAALLOC_REQ
value|0x4444
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_TXCPU_DMALLLOC_RESP
value|0x4448
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_HWDIAG_1
value|0x444C
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_HWDIAG_2
value|0x4450
end_define

begin_define
define|#
directive|define
name|BGE_BMAN_HWDIAG_3
value|0x4454
end_define

begin_comment
comment|/* Buffer manager mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_BMANMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_BMANMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_BMANMODE_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_BMANMODE_TESTMODE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_BMANMODE_LOMBUF_ATTN
value|0x00000010
end_define

begin_comment
comment|/* Buffer manager status register */
end_comment

begin_define
define|#
directive|define
name|BGE_BMANSTAT_ERRO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_BMANSTAT_LOWMBUF_ERROR
value|0x00000010
end_define

begin_comment
comment|/*  * Read DMA Control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RDMA_MODE
value|0x4800
end_define

begin_define
define|#
directive|define
name|BGE_RDMA_STATUS
value|0x4804
end_define

begin_comment
comment|/* Read DMA mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RDMAMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_ADDROFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_FIFOUFLOW_ATTN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_PCI_FIFOOREAD_ATTN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_LOCWRITE_TOOBIG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_RDMAMODE_ALL_ATTNS
value|0x000003FC
end_define

begin_comment
comment|/* Read DMA status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_ADDROFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_FIFOUFLOW_ATTN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_PCI_FIFOOREAD_ATTN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_RDMASTAT_LOCWRITE_TOOBIG
value|0x00000200
end_define

begin_comment
comment|/*  * Write DMA control registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_WDMA_MODE
value|0x4C00
end_define

begin_define
define|#
directive|define
name|BGE_WDMA_STATUS
value|0x4C04
end_define

begin_comment
comment|/* Write DMA mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_WDMAMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_ADDROFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_FIFOUFLOW_ATTN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_PCI_FIFOOREAD_ATTN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_LOCREAD_TOOBIG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_WDMAMODE_ALL_ATTNS
value|0x000003FC
end_define

begin_comment
comment|/* Write DMA status register */
end_comment

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_ADDROFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_FIFOUFLOW_ATTN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_PCI_FIFOOREAD_ATTN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_WDMASTAT_LOCREAD_TOOBIG
value|0x00000200
end_define

begin_comment
comment|/*  * RX CPU registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_RXCPU_MODE
value|0x5000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPU_STATUS
value|0x5004
end_define

begin_define
define|#
directive|define
name|BGE_RXCPU_PC
value|0x501C
end_define

begin_comment
comment|/* RX CPU mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_SINGLESTEP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_P0_DATAHLT_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_P0_INSTRHLT_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_WR_POSTBUF_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_DATACACHE_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_ROMFAIL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_WATCHDOG_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_INSTRCACHE_PRF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_INSTRCACHE_FLUSH
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_HALTCPU
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_INVDATAHLT_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_MADDRTRAPHLT_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUMODE_RADDRTRAPHLT_ENB
value|0x00002000
end_define

begin_comment
comment|/* RX CPU status register */
end_comment

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_HW_BREAKPOINT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_HLTINSTR_EXECUTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_INVALID_INSTR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_P0_DATAREF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_P0_INSTRREF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_INVALID_DATAACC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_INVALID_INSTRFTCH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_BAD_MEMALIGN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_MADDR_TRAP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_REGADDR_TRAP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_DATAACC_STALL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_INSTRFETCH_STALL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_MA_WR_FIFOOFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_MA_RD_FIFOOFLOW
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_MA_DATAMASK_OFLOW
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_MA_REQ_FIFOOFLOW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_RXCPUSTAT_BLOCKING_READ
value|0x80000000
end_define

begin_comment
comment|/*  * TX CPU registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_TXCPU_MODE
value|0x5400
end_define

begin_define
define|#
directive|define
name|BGE_TXCPU_STATUS
value|0x5404
end_define

begin_define
define|#
directive|define
name|BGE_TXCPU_PC
value|0x541C
end_define

begin_comment
comment|/* TX CPU mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_SINGLESTEP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_P0_DATAHLT_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_P0_INSTRHLT_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_WR_POSTBUF_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_DATACACHE_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_ROMFAIL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_WATCHDOG_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_INSTRCACHE_PRF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_INSTRCACHE_FLUSH
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_HALTCPU
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_INVDATAHLT_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUMODE_MADDRTRAPHLT_ENB
value|0x00001000
end_define

begin_comment
comment|/* TX CPU status register */
end_comment

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_HW_BREAKPOINT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_HLTINSTR_EXECUTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_INVALID_INSTR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_P0_DATAREF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_P0_INSTRREF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_INVALID_DATAACC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_INVALID_INSTRFTCH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_BAD_MEMALIGN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_MADDR_TRAP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_REGADDR_TRAP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_DATAACC_STALL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_INSTRFETCH_STALL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_MA_WR_FIFOOFLOW
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_MA_RD_FIFOOFLOW
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_MA_DATAMASK_OFLOW
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_MA_REQ_FIFOOFLOW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_TXCPUSTAT_BLOCKING_READ
value|0x80000000
end_define

begin_comment
comment|/*  * Low priority mailbox registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ0_HI
value|0x5800
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ0_LO
value|0x5804
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ1_HI
value|0x5808
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ1_LO
value|0x580C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ2_HI
value|0x5810
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ2_LO
value|0x5814
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ3_HI
value|0x5818
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_IRQ3_LO
value|0x581C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN0_HI
value|0x5820
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN0_LO
value|0x5824
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN1_HI
value|0x5828
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN1_LO
value|0x582C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN2_HI
value|0x5830
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN2_LO
value|0x5834
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN3_HI
value|0x5828
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN3_LO
value|0x582C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN4_HI
value|0x5840
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN4_LO
value|0x5844
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN5_HI
value|0x5848
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN5_LO
value|0x584C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN6_HI
value|0x5850
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN6_LO
value|0x5854
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN7_HI
value|0x5858
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_GEN7_LO
value|0x585C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RELOAD_STATS_HI
value|0x5860
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RELOAD_STATS_LO
value|0x5864
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_STD_PROD_HI
value|0x5868
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_STD_PROD_LO
value|0x586C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_JUMBO_PROD_HI
value|0x5870
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_JUMBO_PROD_LO
value|0x5874
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_MINI_PROD_HI
value|0x5878
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_MINI_PROD_LO
value|0x587C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS0_HI
value|0x5880
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS0_LO
value|0x5884
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS1_HI
value|0x5888
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS1_LO
value|0x588C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS2_HI
value|0x5890
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS2_LO
value|0x5894
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS3_HI
value|0x5898
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS3_LO
value|0x589C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS4_HI
value|0x58A0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS4_LO
value|0x58A4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS5_HI
value|0x58A8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS5_LO
value|0x58AC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS6_HI
value|0x58B0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS6_LO
value|0x58B4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS7_HI
value|0x58B8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS7_LO
value|0x58BC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS8_HI
value|0x58C0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS8_LO
value|0x58C4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS9_HI
value|0x58C8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS9_LO
value|0x58CC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS10_HI
value|0x58D0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS10_LO
value|0x58D4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS11_HI
value|0x58D8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS11_LO
value|0x58DC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS12_HI
value|0x58E0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS12_LO
value|0x58E4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS13_HI
value|0x58E8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS13_LO
value|0x58EC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS14_HI
value|0x58F0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS14_LO
value|0x58F4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS15_HI
value|0x58F8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_RX_CONS15_LO
value|0x58FC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD0_HI
value|0x5900
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD0_LO
value|0x5904
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD1_HI
value|0x5908
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD1_LO
value|0x590C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD2_HI
value|0x5910
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD2_LO
value|0x5914
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD3_HI
value|0x5918
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD3_LO
value|0x591C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD4_HI
value|0x5920
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD4_LO
value|0x5924
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD5_HI
value|0x5928
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD5_LO
value|0x592C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD6_HI
value|0x5930
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD6_LO
value|0x5934
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD7_HI
value|0x5938
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD7_LO
value|0x593C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD8_HI
value|0x5940
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD8_LO
value|0x5944
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD9_HI
value|0x5948
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD9_LO
value|0x594C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD10_HI
value|0x5950
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD10_LO
value|0x5954
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD11_HI
value|0x5958
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD11_LO
value|0x595C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD12_HI
value|0x5960
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD12_LO
value|0x5964
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD13_HI
value|0x5968
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD13_LO
value|0x596C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD14_HI
value|0x5970
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD14_LO
value|0x5974
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD15_HI
value|0x5978
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_HOST_PROD15_LO
value|0x597C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD0_HI
value|0x5980
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD0_LO
value|0x5984
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD1_HI
value|0x5988
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD1_LO
value|0x598C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD2_HI
value|0x5990
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD2_LO
value|0x5994
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD3_HI
value|0x5998
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD3_LO
value|0x599C
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD4_HI
value|0x59A0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD4_LO
value|0x59A4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD5_HI
value|0x59A8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD5_LO
value|0x59AC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD6_HI
value|0x59B0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD6_LO
value|0x59B4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD7_HI
value|0x59B8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD7_LO
value|0x59BC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD8_HI
value|0x59C0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD8_LO
value|0x59C4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD9_HI
value|0x59C8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD9_LO
value|0x59CC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD10_HI
value|0x59D0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD10_LO
value|0x59D4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD11_HI
value|0x59D8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD11_LO
value|0x59DC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD12_HI
value|0x59E0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD12_LO
value|0x59E4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD13_HI
value|0x59E8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD13_LO
value|0x59EC
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD14_HI
value|0x59F0
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD14_LO
value|0x59F4
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD15_HI
value|0x59F8
end_define

begin_define
define|#
directive|define
name|BGE_LPMBX_TX_NIC_PROD15_LO
value|0x59FC
end_define

begin_comment
comment|/*  * Flow throw Queue reset register  */
end_comment

begin_define
define|#
directive|define
name|BGE_FTQ_RESET
value|0x5C00
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_DMAREAD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_DMAHIPRIO_RD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_DMADONE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_SBDC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_SDI
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_WDMA
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_DMAHIPRIO_WR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_TYPE1_SOFTWARE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_SDC
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_HCC
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_TXFIFO
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_MBC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_RBDC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_RXLP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_RDBDI
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_RDC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_FTQRESET_TYPE2_SOFTWARE
value|0x00040000
end_define

begin_comment
comment|/*  * Message Signaled Interrupt registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_MSI_MODE
value|0x6000
end_define

begin_define
define|#
directive|define
name|BGE_MSI_STATUS
value|0x6004
end_define

begin_define
define|#
directive|define
name|BGE_MSI_FIFOACCESS
value|0x6008
end_define

begin_comment
comment|/* MSI mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_MSIMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_MSI_FIFOUFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_MSIMODE_MSI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_comment
comment|/* MSI status register */
end_comment

begin_define
define|#
directive|define
name|BGE_MSISTAT_PCI_TGT_ABRT_ATTN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MSISTAT_PCI_MSTR_ABRT_ATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MSISTAT_PCI_PERR_ATTN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MSISTAT_MSI_FIFOUFLOW_ATTN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_MSISTAT_MSI_FIFOOFLOW_ATTN
value|0x00000040
end_define

begin_comment
comment|/*  * DMA Completion registers  */
end_comment

begin_define
define|#
directive|define
name|BGE_DMAC_MODE
value|0x6400
end_define

begin_comment
comment|/* DMA Completion mode register */
end_comment

begin_define
define|#
directive|define
name|BGE_DMACMODE_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_DMACMODE_ENABLE
value|0x00000002
end_define

begin_comment
comment|/*  * General control registers.  */
end_comment

begin_define
define|#
directive|define
name|BGE_MODE_CTL
value|0x6800
end_define

begin_define
define|#
directive|define
name|BGE_MISC_CFG
value|0x6804
end_define

begin_define
define|#
directive|define
name|BGE_MISC_LOCAL_CTL
value|0x6808
end_define

begin_define
define|#
directive|define
name|BGE_CPU_EVENT
value|0x6810
end_define

begin_define
define|#
directive|define
name|BGE_EE_ADDR
value|0x6838
end_define

begin_define
define|#
directive|define
name|BGE_EE_DATA
value|0x683C
end_define

begin_define
define|#
directive|define
name|BGE_EE_CTL
value|0x6840
end_define

begin_define
define|#
directive|define
name|BGE_MDI_CTL
value|0x6844
end_define

begin_define
define|#
directive|define
name|BGE_EE_DELAY
value|0x6848
end_define

begin_define
define|#
directive|define
name|BGE_FASTBOOT_PC
value|0x6894
end_define

begin_comment
comment|/* Mode control register */
end_comment

begin_define
define|#
directive|define
name|BGE_MODECTL_INT_SNDCOAL_ONLY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_BYTESWAP_NONFRAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_WORDSWAP_NONFRAME
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_BYTESWAP_DATA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_WORDSWAP_DATA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_NO_FRAME_CRACKING
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_NO_RX_CRC
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_RX_BADFRAMES
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_NO_TX_INTR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_NO_RX_INTR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_FORCE_PCI32
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_STACKUP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_HOST_SEND_BDS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_TX_NO_PHDR_CSUM
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_RX_NO_PHDR_CSUM
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_TX_ATTN_INTR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_RX_ATTN_INTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_MAC_ATTN_INTR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_DMA_ATTN_INTR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_FLOWCTL_ATTN_INTR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_4X_SENDRING_SZ
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_MODECTL_FW_PROCESS_MCASTS
value|0x40000000
end_define

begin_comment
comment|/* Misc. config register */
end_comment

begin_define
define|#
directive|define
name|BGE_MISCCFG_RESET_CORE_CLOCKS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MISCCFG_TIMER_PRESCALER
value|0x000000FE
end_define

begin_define
define|#
directive|define
name|BGE_32BITTIME_66MHZ
value|(0x41<< 1)
end_define

begin_comment
comment|/* Misc. Local Control */
end_comment

begin_define
define|#
directive|define
name|BGE_MLC_INTR_STATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MLC_INTR_CLR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MLC_INTR_SET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MLC_INTR_ONATTN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_IN0
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_IN1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_IN2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUTEN0
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUTEN1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUTEN2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUT0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUT1
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_MISCIO_OUT2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_EXTRAM_ENB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_SRAM_SIZE
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_BANK_SEL
value|0x00200000
end_define

begin_comment
comment|/* 0 = 2 banks, 1 == 1 */
end_comment

begin_define
define|#
directive|define
name|BGE_MLC_SSRAM_TYPE
value|0x00400000
end_define

begin_comment
comment|/* 1 = ZBT, 0 = standard */
end_comment

begin_define
define|#
directive|define
name|BGE_MLC_SSRAM_CYC_DESEL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BGE_MLC_AUTO_EEPROM
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_256KB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_512KB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_1MB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_2MB
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_4MB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_8MB
value|0x00140000
end_define

begin_define
define|#
directive|define
name|BGE_SSRAMSIZE_16M
value|0x00180000
end_define

begin_comment
comment|/* EEPROM address register */
end_comment

begin_define
define|#
directive|define
name|BGE_EEADDR_ADDRESS
value|0x0000FFFC
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_HALFCLK
value|0x01FF0000
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_START
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_DEVID
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_DONE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BGE_EEADDR_RW
value|0x80000000
end_define

begin_comment
comment|/* 1 = rd, 0 = wr */
end_comment

begin_define
define|#
directive|define
name|BGE_EEDEVID
parameter_list|(
name|x
parameter_list|)
value|((x& 7)<< 26)
end_define

begin_define
define|#
directive|define
name|BGE_EEHALFCLK
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1FF)<< 16)
end_define

begin_define
define|#
directive|define
name|BGE_HALFCLK_384SCL
value|0x60
end_define

begin_define
define|#
directive|define
name|BGE_EE_READCMD
define|\
value|(BGE_EEHALFCLK(BGE_HALFCLK_384SCL)|BGE_EEDEVID(0)|	\ 	BGE_EEADDR_START|BGE_EEADDR_RW|BGE_EEADDR_DONE)
end_define

begin_define
define|#
directive|define
name|BGE_EE_WRCMD
define|\
value|(BGE_EEHALFCLK(BGE_HALFCLK_384SCL)|BGE_EEDEVID(0)|	\ 	BGE_EEADDR_START|BGE_EEADDR_DONE)
end_define

begin_comment
comment|/* EEPROM Control register */
end_comment

begin_define
define|#
directive|define
name|BGE_EECTL_CLKOUT_TRISTATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_EECTL_CLKOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_EECTL_CLKIN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_EECTL_DATAOUT_TRISTATE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_EECTL_DATAOUT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_EECTL_DATAIN
value|0x00000020
end_define

begin_comment
comment|/* MDI (MII/GMII) access register */
end_comment

begin_define
define|#
directive|define
name|BGE_MDI_DATA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_MDI_DIR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_MDI_SEL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_MDI_CLK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MEMWIN_START
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BGE_MEMWIN_END
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|BGE_MEMWIN_READ
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		pci_write_config(sc->bge_dev, BGE_PCI_MEMWIN_BASEADDR,	\ 		    (0xFFFF0000& x), 4);				\ 		val = CSR_READ_4(sc, BGE_MEMWIN_START + (x& 0xFFFF));	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|BGE_MEMWIN_WRITE
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		pci_write_config(sc->bge_dev, BGE_PCI_MEMWIN_BASEADDR,	\ 		    (0xFFFF0000& x), 4);				\ 		CSR_WRITE_4(sc, BGE_MEMWIN_START + (x& 0xFFFF), val);	\ 	} while(0)
end_define

begin_comment
comment|/*  * This magic number is written to the firmware mailbox at 0xb50  * before a software reset is issued.  After the internal firmware  * has completed its initialization it will write the opposite of   * this value, ~BGE_MAGIC_NUMBER, to the same location, allowing the  * driver to synchronize with the firmware.  */
end_comment

begin_define
define|#
directive|define
name|BGE_MAGIC_NUMBER
value|0x4B657654
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|bge_addr_hi
decl_stmt|;
name|uint32_t
name|bge_addr_lo
decl_stmt|;
block|}
name|bge_hostaddr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BGE_HOSTADDR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|do {								\ 		(x).bge_addr_lo = ((uint64_t) (y)& 0xffffffff);	\ 		(x).bge_addr_hi = ((uint64_t) (y)>> 32);		\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|BGE_ADDR_LO
parameter_list|(
name|y
parameter_list|)
define|\
value|((uint64_t) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|BGE_ADDR_HI
parameter_list|(
name|y
parameter_list|)
define|\
value|((uint64_t) (y)>> 32)
end_define

begin_comment
comment|/* Ring control block structure */
end_comment

begin_struct
struct|struct
name|bge_rcb
block|{
name|bge_hostaddr
name|bge_hostaddr
decl_stmt|;
name|uint32_t
name|bge_maxlen_flags
decl_stmt|;
name|uint32_t
name|bge_nicaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RCB_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|rcb
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bge_btag, sc->bge_bhandle, \ 			  rcb + offsetof(struct bge_rcb, offset), val)
end_define

begin_define
define|#
directive|define
name|BGE_RCB_MAXLEN_FLAGS
parameter_list|(
name|maxlen
parameter_list|,
name|flags
parameter_list|)
value|((maxlen)<< 16 | (flags))
end_define

begin_define
define|#
directive|define
name|BGE_RCB_FLAG_USE_EXT_RX_BD
value|0x0001
end_define

begin_define
define|#
directive|define
name|BGE_RCB_FLAG_RING_DISABLED
value|0x0002
end_define

begin_struct
struct|struct
name|bge_tx_bd
block|{
name|bge_hostaddr
name|bge_addr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_len
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
name|uint16_t
name|bge_rsvd
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_len
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_rsvd
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_TCP_UDP_CSUM
value|0x0001
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_IP_CSUM
value|0x0002
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_END
value|0x0004
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_IP_FRAG
value|0x0008
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_IP_FRAG_END
value|0x0010
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_VLAN_TAG
value|0x0040
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_COAL_NOW
value|0x0080
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_CPU_PRE_DMA
value|0x0100
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_CPU_POST_DMA
value|0x0200
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_INSERT_SRC_ADDR
value|0x1000
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_CHOOSE_SRC_ADDR
value|0x6000
end_define

begin_define
define|#
directive|define
name|BGE_TXBDFLAG_NO_CRC
value|0x8000
end_define

begin_define
define|#
directive|define
name|BGE_NIC_TXRING_ADDR
parameter_list|(
name|ringno
parameter_list|,
name|size
parameter_list|)
define|\
value|BGE_SEND_RING_1_TO_4 +			\ 	((ringno * sizeof(struct bge_tx_bd) * size) / 4)
end_define

begin_struct
struct|struct
name|bge_rx_bd
block|{
name|bge_hostaddr
name|bge_addr
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_len
decl_stmt|;
name|uint16_t
name|bge_idx
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_type
decl_stmt|;
name|uint16_t
name|bge_tcp_udp_csum
decl_stmt|;
name|uint16_t
name|bge_ip_csum
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
name|uint16_t
name|bge_error_flag
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_idx
decl_stmt|;
name|uint16_t
name|bge_len
decl_stmt|;
name|uint16_t
name|bge_type
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_ip_csum
decl_stmt|;
name|uint16_t
name|bge_tcp_udp_csum
decl_stmt|;
name|uint16_t
name|bge_error_flag
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|bge_rsvd
decl_stmt|;
name|uint32_t
name|bge_opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bge_extrx_bd
block|{
name|bge_hostaddr
name|bge_addr1
decl_stmt|;
name|bge_hostaddr
name|bge_addr2
decl_stmt|;
name|bge_hostaddr
name|bge_addr3
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_len2
decl_stmt|;
name|uint16_t
name|bge_len1
decl_stmt|;
name|uint16_t
name|bge_rsvd1
decl_stmt|;
name|uint16_t
name|bge_len3
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_len1
decl_stmt|;
name|uint16_t
name|bge_len2
decl_stmt|;
name|uint16_t
name|bge_len3
decl_stmt|;
name|uint16_t
name|bge_rsvd1
decl_stmt|;
endif|#
directive|endif
name|bge_hostaddr
name|bge_addr0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_len0
decl_stmt|;
name|uint16_t
name|bge_idx
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_type
decl_stmt|;
name|uint16_t
name|bge_tcp_udp_csum
decl_stmt|;
name|uint16_t
name|bge_ip_csum
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
name|uint16_t
name|bge_error_flag
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_idx
decl_stmt|;
name|uint16_t
name|bge_len0
decl_stmt|;
name|uint16_t
name|bge_type
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|uint16_t
name|bge_ip_csum
decl_stmt|;
name|uint16_t
name|bge_tcp_udp_csum
decl_stmt|;
name|uint16_t
name|bge_error_flag
decl_stmt|;
name|uint16_t
name|bge_vlan_tag
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|bge_rsvd0
decl_stmt|;
name|uint32_t
name|bge_opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_END
value|0x0004
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_JUMBO_RING
value|0x0020
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_VLAN_TAG
value|0x0040
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_MINI_RING
value|0x0800
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_IP_CSUM
value|0x1000
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_TCP_UDP_CSUM
value|0x2000
end_define

begin_define
define|#
directive|define
name|BGE_RXBDFLAG_TCP_UDP_IS_TCP
value|0x4000
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_BAD_CRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_COLL_DETECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_LINK_LOST
value|0x0004
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_PHY_DECODE_ERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_MAC_ABORT
value|0x0010
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_RUNT
value|0x0020
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_TRUNC_NO_RSRCS
value|0x0040
end_define

begin_define
define|#
directive|define
name|BGE_RXERRFLAG_GIANT
value|0x0080
end_define

begin_struct
struct|struct
name|bge_sts_idx
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_rx_prod_idx
decl_stmt|;
name|uint16_t
name|bge_tx_cons_idx
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_tx_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rx_prod_idx
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bge_status_block
block|{
name|uint32_t
name|bge_status
decl_stmt|;
name|uint32_t
name|bge_rsvd0
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|uint16_t
name|bge_rx_jumbo_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rx_std_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rx_mini_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rsvd1
decl_stmt|;
else|#
directive|else
name|uint16_t
name|bge_rx_std_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rx_jumbo_cons_idx
decl_stmt|;
name|uint16_t
name|bge_rsvd1
decl_stmt|;
name|uint16_t
name|bge_rx_mini_cons_idx
decl_stmt|;
endif|#
directive|endif
name|struct
name|bge_sts_idx
name|bge_idx
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_TX_CONSIDX
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|x->bge_idx[i].bge_tx_considx
end_define

begin_define
define|#
directive|define
name|BGE_RX_PRODIDX
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
value|x->bge_idx[i].bge_rx_prodidx
end_define

begin_define
define|#
directive|define
name|BGE_STATFLAG_UPDATED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_STATFLAG_LINKSTATE_CHANGED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BGE_STATFLAG_ERROR
value|0x00000004
end_define

begin_comment
comment|/*  * Broadcom Vendor ID  * (Note: the BCM570x still defaults to the Alteon PCI vendor ID  * even though they're now manufactured by Broadcom)  */
end_comment

begin_define
define|#
directive|define
name|BCOM_VENDORID
value|0x14E4
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5700
value|0x1644
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5701
value|0x1645
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5702
value|0x1646
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5702X
value|0x16A6
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5702_ALT
value|0x16C6
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5703
value|0x1647
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5703X
value|0x16A7
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5703_ALT
value|0x16C7
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5704C
value|0x1648
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5704S
value|0x16A8
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5704S_ALT
value|0x1649
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5705
value|0x1653
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5705K
value|0x1654
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5705F
value|0x166E
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5705M
value|0x165D
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5705M_ALT
value|0x165E
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5714C
value|0x1668
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5714S
value|0x1669
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5715
value|0x1678
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5715S
value|0x1679
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5720
value|0x1658
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5721
value|0x1659
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5750
value|0x1676
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5750M
value|0x167C
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5751
value|0x1677
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5751F
value|0x167E
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5751M
value|0x167D
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5752
value|0x1600
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5752M
value|0x1601
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5753
value|0x16F7
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5753F
value|0x16FE
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5753M
value|0x16FD
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5754
value|0x167A
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5754M
value|0x1672
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5755
value|0x167B
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5755M
value|0x1673
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5780
value|0x166A
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5780S
value|0x166B
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5781
value|0x16DD
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5782
value|0x1696
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5786
value|0x169A
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5787
value|0x169B
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5787M
value|0x1693
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5788
value|0x169C
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5789
value|0x169D
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5901
value|0x170D
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5901A2
value|0x170E
end_define

begin_define
define|#
directive|define
name|BCOM_DEVICEID_BCM5903M
value|0x16FF
end_define

begin_comment
comment|/*  * Alteon AceNIC PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|ALTEON_VENDORID
value|0x12AE
end_define

begin_define
define|#
directive|define
name|ALTEON_DEVICEID_ACENIC
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALTEON_DEVICEID_ACENIC_COPPER
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALTEON_DEVICEID_BCM5700
value|0x0003
end_define

begin_define
define|#
directive|define
name|ALTEON_DEVICEID_BCM5701
value|0x0004
end_define

begin_comment
comment|/*  * 3Com 3c996 PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|TC_VENDORID
value|0x10B7
end_define

begin_define
define|#
directive|define
name|TC_DEVICEID_3C996
value|0x0003
end_define

begin_comment
comment|/*  * SysKonnect PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|SK_VENDORID
value|0x1148
end_define

begin_define
define|#
directive|define
name|SK_DEVICEID_ALTIMA
value|0x4400
end_define

begin_define
define|#
directive|define
name|SK_SUBSYSID_9D21
value|0x4421
end_define

begin_define
define|#
directive|define
name|SK_SUBSYSID_9D41
value|0x4441
end_define

begin_comment
comment|/*  * Altima PCI vendor/device ID.  */
end_comment

begin_define
define|#
directive|define
name|ALTIMA_VENDORID
value|0x173b
end_define

begin_define
define|#
directive|define
name|ALTIMA_DEVICE_AC1000
value|0x03e8
end_define

begin_define
define|#
directive|define
name|ALTIMA_DEVICE_AC1002
value|0x03e9
end_define

begin_define
define|#
directive|define
name|ALTIMA_DEVICE_AC9100
value|0x03ea
end_define

begin_comment
comment|/*  * Dell PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|DELL_VENDORID
value|0x1028
end_define

begin_comment
comment|/*  * Apple PCI vendor ID.  */
end_comment

begin_define
define|#
directive|define
name|APPLE_VENDORID
value|0x106b
end_define

begin_define
define|#
directive|define
name|APPLE_DEVICE_BCM5701
value|0x1645
end_define

begin_comment
comment|/*  * Offset of MAC address inside EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|BGE_EE_MAC_OFFSET
value|0x7C
end_define

begin_define
define|#
directive|define
name|BGE_EE_HWCFG_OFFSET
value|0xC8
end_define

begin_define
define|#
directive|define
name|BGE_HWCFG_VOLTAGE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BGE_HWCFG_PHYLED_MODE
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|BGE_HWCFG_MEDIA
value|0x00000030
end_define

begin_define
define|#
directive|define
name|BGE_HWCFG_ASF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BGE_VOLTAGE_1POINT3
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_VOLTAGE_1POINT8
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BGE_PHYLEDMODE_UNSPEC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_PHYLEDMODE_TRIPLELED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BGE_PHYLEDMODE_SINGLELED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BGE_MEDIA_UNSPEC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BGE_MEDIA_COPPER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BGE_MEDIA_FIBER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BGE_PCI_READ_CMD
value|0x06000000
end_define

begin_define
define|#
directive|define
name|BGE_PCI_WRITE_CMD
value|0x70000000
end_define

begin_define
define|#
directive|define
name|BGE_TICKS_PER_SEC
value|1000000
end_define

begin_comment
comment|/*  * Ring size constants.  */
end_comment

begin_define
define|#
directive|define
name|BGE_EVENT_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|BGE_CMD_RING_CNT
value|64
end_define

begin_define
define|#
directive|define
name|BGE_STD_RX_RING_CNT
value|512
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|BGE_MINI_RX_RING_CNT
value|1024
end_define

begin_define
define|#
directive|define
name|BGE_RETURN_RING_CNT
value|1024
end_define

begin_comment
comment|/* 5705 has smaller return ring size */
end_comment

begin_define
define|#
directive|define
name|BGE_RETURN_RING_CNT_5705
value|512
end_define

begin_comment
comment|/*  * Possible TX ring sizes.  */
end_comment

begin_define
define|#
directive|define
name|BGE_TX_RING_CNT_128
value|128
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_BASE_128
value|0x3800
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_CNT_256
value|256
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_BASE_256
value|0x3000
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_CNT_512
value|512
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_BASE_512
value|0x2000
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_CNT
value|BGE_TX_RING_CNT_512
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_BASE
value|BGE_TX_RING_BASE_512
end_define

begin_comment
comment|/*  * Tigon III statistics counters.  */
end_comment

begin_comment
comment|/* Statistics maintained MAC Receive block. */
end_comment

begin_struct
struct|struct
name|bge_rx_mac_stats
block|{
name|bge_hostaddr
name|ifHCInOctets
decl_stmt|;
name|bge_hostaddr
name|Reserved1
decl_stmt|;
name|bge_hostaddr
name|etherStatsFragments
decl_stmt|;
name|bge_hostaddr
name|ifHCInUcastPkts
decl_stmt|;
name|bge_hostaddr
name|ifHCInMulticastPkts
decl_stmt|;
name|bge_hostaddr
name|ifHCInBroadcastPkts
decl_stmt|;
name|bge_hostaddr
name|dot3StatsFCSErrors
decl_stmt|;
name|bge_hostaddr
name|dot3StatsAlignmentErrors
decl_stmt|;
name|bge_hostaddr
name|xonPauseFramesReceived
decl_stmt|;
name|bge_hostaddr
name|xoffPauseFramesReceived
decl_stmt|;
name|bge_hostaddr
name|macControlFramesReceived
decl_stmt|;
name|bge_hostaddr
name|xoffStateEntered
decl_stmt|;
name|bge_hostaddr
name|dot3StatsFramesTooLong
decl_stmt|;
name|bge_hostaddr
name|etherStatsJabbers
decl_stmt|;
name|bge_hostaddr
name|etherStatsUndersizePkts
decl_stmt|;
name|bge_hostaddr
name|inRangeLengthError
decl_stmt|;
name|bge_hostaddr
name|outRangeLengthError
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts64Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts65Octetsto127Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts128Octetsto255Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts256Octetsto511Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts512Octetsto1023Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts1024Octetsto1522Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts1523Octetsto2047Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts2048Octetsto4095Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts4096Octetsto8191Octets
decl_stmt|;
name|bge_hostaddr
name|etherStatsPkts8192Octetsto9022Octets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics maintained MAC Transmit block. */
end_comment

begin_struct
struct|struct
name|bge_tx_mac_stats
block|{
name|bge_hostaddr
name|ifHCOutOctets
decl_stmt|;
name|bge_hostaddr
name|Reserved2
decl_stmt|;
name|bge_hostaddr
name|etherStatsCollisions
decl_stmt|;
name|bge_hostaddr
name|outXonSent
decl_stmt|;
name|bge_hostaddr
name|outXoffSent
decl_stmt|;
name|bge_hostaddr
name|flowControlDone
decl_stmt|;
name|bge_hostaddr
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
name|bge_hostaddr
name|dot3StatsSingleCollisionFrames
decl_stmt|;
name|bge_hostaddr
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
name|bge_hostaddr
name|dot3StatsDeferredTransmissions
decl_stmt|;
name|bge_hostaddr
name|Reserved3
decl_stmt|;
name|bge_hostaddr
name|dot3StatsExcessiveCollisions
decl_stmt|;
name|bge_hostaddr
name|dot3StatsLateCollisions
decl_stmt|;
name|bge_hostaddr
name|dot3Collided2Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided3Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided4Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided5Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided6Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided7Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided8Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided9Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided10Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided11Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided12Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided13Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided14Times
decl_stmt|;
name|bge_hostaddr
name|dot3Collided15Times
decl_stmt|;
name|bge_hostaddr
name|ifHCOutUcastPkts
decl_stmt|;
name|bge_hostaddr
name|ifHCOutMulticastPkts
decl_stmt|;
name|bge_hostaddr
name|ifHCOutBroadcastPkts
decl_stmt|;
name|bge_hostaddr
name|dot3StatsCarrierSenseErrors
decl_stmt|;
name|bge_hostaddr
name|ifOutDiscards
decl_stmt|;
name|bge_hostaddr
name|ifOutErrors
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stats counters access through registers */
end_comment

begin_struct
struct|struct
name|bge_mac_stats_regs
block|{
name|uint32_t
name|ifHCOutOctets
decl_stmt|;
name|uint32_t
name|Reserved0
decl_stmt|;
name|uint32_t
name|etherStatsCollisions
decl_stmt|;
name|uint32_t
name|outXonSent
decl_stmt|;
name|uint32_t
name|outXoffSent
decl_stmt|;
name|uint32_t
name|Reserved1
decl_stmt|;
name|uint32_t
name|dot3StatsInternalMacTransmitErrors
decl_stmt|;
name|uint32_t
name|dot3StatsSingleCollisionFrames
decl_stmt|;
name|uint32_t
name|dot3StatsMultipleCollisionFrames
decl_stmt|;
name|uint32_t
name|dot3StatsDeferredTransmissions
decl_stmt|;
name|uint32_t
name|Reserved2
decl_stmt|;
name|uint32_t
name|dot3StatsExcessiveCollisions
decl_stmt|;
name|uint32_t
name|dot3StatsLateCollisions
decl_stmt|;
name|uint32_t
name|Reserved3
index|[
literal|14
index|]
decl_stmt|;
name|uint32_t
name|ifHCOutUcastPkts
decl_stmt|;
name|uint32_t
name|ifHCOutMulticastPkts
decl_stmt|;
name|uint32_t
name|ifHCOutBroadcastPkts
decl_stmt|;
name|uint32_t
name|Reserved4
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ifHCInOctets
decl_stmt|;
name|uint32_t
name|Reserved5
decl_stmt|;
name|uint32_t
name|etherStatsFragments
decl_stmt|;
name|uint32_t
name|ifHCInUcastPkts
decl_stmt|;
name|uint32_t
name|ifHCInMulticastPkts
decl_stmt|;
name|uint32_t
name|ifHCInBroadcastPkts
decl_stmt|;
name|uint32_t
name|dot3StatsFCSErrors
decl_stmt|;
name|uint32_t
name|dot3StatsAlignmentErrors
decl_stmt|;
name|uint32_t
name|xonPauseFramesReceived
decl_stmt|;
name|uint32_t
name|xoffPauseFramesReceived
decl_stmt|;
name|uint32_t
name|macControlFramesReceived
decl_stmt|;
name|uint32_t
name|xoffStateEntered
decl_stmt|;
name|uint32_t
name|dot3StatsFramesTooLong
decl_stmt|;
name|uint32_t
name|etherStatsJabbers
decl_stmt|;
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bge_stats
block|{
name|uint8_t
name|Reserved0
index|[
literal|256
index|]
decl_stmt|;
comment|/* Statistics maintained by Receive MAC. */
name|struct
name|bge_rx_mac_stats
name|rxstats
decl_stmt|;
name|bge_hostaddr
name|Unused1
index|[
literal|37
index|]
decl_stmt|;
comment|/* Statistics maintained by Transmit MAC. */
name|struct
name|bge_tx_mac_stats
name|txstats
decl_stmt|;
name|bge_hostaddr
name|Unused2
index|[
literal|31
index|]
decl_stmt|;
comment|/* Statistics maintained by Receive List Placement. */
name|bge_hostaddr
name|COSIfHCInPkts
index|[
literal|16
index|]
decl_stmt|;
name|bge_hostaddr
name|COSFramesDroppedDueToFilters
decl_stmt|;
name|bge_hostaddr
name|nicDmaWriteQueueFull
decl_stmt|;
name|bge_hostaddr
name|nicDmaWriteHighPriQueueFull
decl_stmt|;
name|bge_hostaddr
name|nicNoMoreRxBDs
decl_stmt|;
name|bge_hostaddr
name|ifInDiscards
decl_stmt|;
name|bge_hostaddr
name|ifInErrors
decl_stmt|;
name|bge_hostaddr
name|nicRecvThresholdHit
decl_stmt|;
name|bge_hostaddr
name|Unused3
index|[
literal|9
index|]
decl_stmt|;
comment|/* Statistics maintained by Send Data Initiator. */
name|bge_hostaddr
name|COSIfHCOutPkts
index|[
literal|16
index|]
decl_stmt|;
name|bge_hostaddr
name|nicDmaReadQueueFull
decl_stmt|;
name|bge_hostaddr
name|nicDmaReadHighPriQueueFull
decl_stmt|;
name|bge_hostaddr
name|nicSendDataCompQueueFull
decl_stmt|;
comment|/* Statistics maintained by Host Coalescing. */
name|bge_hostaddr
name|nicRingSetSendProdIndex
decl_stmt|;
name|bge_hostaddr
name|nicRingStatusUpdate
decl_stmt|;
name|bge_hostaddr
name|nicInterrupts
decl_stmt|;
name|bge_hostaddr
name|nicAvoidedInterrupts
decl_stmt|;
name|bge_hostaddr
name|nicSendThresholdHit
decl_stmt|;
name|uint8_t
name|Reserved4
index|[
literal|320
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tigon general information block. This resides in host memory  * and contains the status counters, ring control blocks and  * producer pointers.  */
end_comment

begin_struct
struct|struct
name|bge_gib
block|{
name|struct
name|bge_stats
name|bge_stats
decl_stmt|;
name|struct
name|bge_rcb
name|bge_tx_rcb
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|bge_rcb
name|bge_std_rx_rcb
decl_stmt|;
name|struct
name|bge_rcb
name|bge_jumbo_rx_rcb
decl_stmt|;
name|struct
name|bge_rcb
name|bge_mini_rx_rcb
decl_stmt|;
name|struct
name|bge_rcb
name|bge_return_rcb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_FRAMELEN
value|1518
end_define

begin_define
define|#
directive|define
name|BGE_MAX_FRAMELEN
value|1536
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_FRAMELEN
value|9018
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_MTU
value|(BGE_JUMBO_FRAMELEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|BGE_MIN_FRAMELEN
value|60
end_define

begin_comment
comment|/*  * Other utility macros.  */
end_comment

begin_define
define|#
directive|define
name|BGE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_comment
comment|/*  * Register access macros. The Tigon always uses memory mapped register  * accesses and all registers must be accessed with 32 bit operations.  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->bge_btag, sc->bge_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->bge_btag, sc->bge_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|BGE_SETBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, (CSR_READ_4(sc, reg) | (x)))
end_define

begin_define
define|#
directive|define
name|BGE_CLRBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, (CSR_READ_4(sc, reg)& ~(x)))
end_define

begin_define
define|#
directive|define
name|PCI_SETBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s) | (x)), s)
end_define

begin_define
define|#
directive|define
name|PCI_CLRBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s)& ~(x)), s)
end_define

begin_comment
comment|/*  * Memory management stuff. Note: the SSLOTS, MSLOTS and JSLOTS  * values are tuneable. They control the actual amount of buffers  * allocated for the standard, mini and jumbo receive rings.  */
end_comment

begin_define
define|#
directive|define
name|BGE_SSLOTS
value|256
end_define

begin_define
define|#
directive|define
name|BGE_MSLOTS
value|256
end_define

begin_define
define|#
directive|define
name|BGE_JSLOTS
value|384
end_define

begin_define
define|#
directive|define
name|BGE_JRAWLEN
value|(BGE_JUMBO_FRAMELEN + ETHER_ALIGN)
end_define

begin_define
define|#
directive|define
name|BGE_JLEN
value|(BGE_JRAWLEN + (sizeof(uint64_t) - \ 	(BGE_JRAWLEN % sizeof(uint64_t))))
end_define

begin_define
define|#
directive|define
name|BGE_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BGE_RESID
value|(BGE_JPAGESZ - (BGE_JLEN * BGE_JSLOTS) % BGE_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|BGE_JMEM
value|((BGE_JLEN * BGE_JSLOTS) + BGE_RESID)
end_define

begin_define
define|#
directive|define
name|BGE_NSEG_JUMBO
value|4
end_define

begin_define
define|#
directive|define
name|BGE_NSEG_NEW
value|32
end_define

begin_comment
comment|/*  * Ring structures. Most of these reside in host memory and we tell  * the NIC where they are via the ring control blocks. The exceptions  * are the tx and command rings, which live in NIC memory and which  * we access via the shared memory window.  */
end_comment

begin_struct
struct|struct
name|bge_ring_data
block|{
name|struct
name|bge_rx_bd
modifier|*
name|bge_rx_std_ring
decl_stmt|;
name|bus_addr_t
name|bge_rx_std_ring_paddr
decl_stmt|;
name|struct
name|bge_extrx_bd
modifier|*
name|bge_rx_jumbo_ring
decl_stmt|;
name|bus_addr_t
name|bge_rx_jumbo_ring_paddr
decl_stmt|;
name|struct
name|bge_rx_bd
modifier|*
name|bge_rx_return_ring
decl_stmt|;
name|bus_addr_t
name|bge_rx_return_ring_paddr
decl_stmt|;
name|struct
name|bge_tx_bd
modifier|*
name|bge_tx_ring
decl_stmt|;
name|bus_addr_t
name|bge_tx_ring_paddr
decl_stmt|;
name|struct
name|bge_status_block
modifier|*
name|bge_status_block
decl_stmt|;
name|bus_addr_t
name|bge_status_block_paddr
decl_stmt|;
name|struct
name|bge_stats
modifier|*
name|bge_stats
decl_stmt|;
name|bus_addr_t
name|bge_stats_paddr
decl_stmt|;
name|struct
name|bge_gib
name|bge_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_STD_RX_RING_SZ
define|\
value|(sizeof(struct bge_rx_bd) * BGE_STD_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|BGE_JUMBO_RX_RING_SZ
define|\
value|(sizeof(struct bge_extrx_bd) * BGE_JUMBO_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|BGE_TX_RING_SZ
define|\
value|(sizeof(struct bge_tx_bd) * BGE_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|BGE_RX_RTN_RING_SZ
parameter_list|(
name|x
parameter_list|)
define|\
value|(sizeof(struct bge_rx_bd) * x->bge_return_ring_cnt)
end_define

begin_define
define|#
directive|define
name|BGE_STATUS_BLK_SZ
value|sizeof (struct bge_status_block)
end_define

begin_define
define|#
directive|define
name|BGE_STATS_SZ
value|sizeof (struct bge_stats)
end_define

begin_comment
comment|/*  * Mbuf pointers. We need these to keep track of the virtual addresses  * of our mbuf chains since we can only convert from physical to virtual,  * not the other way around.  */
end_comment

begin_struct
struct|struct
name|bge_chain_data
block|{
name|bus_dma_tag_t
name|bge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_rx_std_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_rx_jumbo_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_rx_return_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_status_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_stats_tag
decl_stmt|;
name|bus_dma_tag_t
name|bge_mtag
decl_stmt|;
comment|/* mbuf mapping tag */
name|bus_dma_tag_t
name|bge_mtag_jumbo
decl_stmt|;
comment|/* mbuf mapping tag */
name|bus_dmamap_t
name|bge_tx_dmamap
index|[
name|BGE_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|bge_rx_std_dmamap
index|[
name|BGE_STD_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|bge_rx_jumbo_dmamap
index|[
name|BGE_JUMBO_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|bge_rx_std_ring_map
decl_stmt|;
name|bus_dmamap_t
name|bge_rx_jumbo_ring_map
decl_stmt|;
name|bus_dmamap_t
name|bge_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|bge_rx_return_ring_map
decl_stmt|;
name|bus_dmamap_t
name|bge_status_map
decl_stmt|;
name|bus_dmamap_t
name|bge_stats_map
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|bge_tx_chain
index|[
name|BGE_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|bge_rx_std_chain
index|[
name|BGE_STD_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|bge_rx_jumbo_chain
index|[
name|BGE_JUMBO_RX_RING_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bge_dmamap_arg
block|{
name|struct
name|bge_softc
modifier|*
name|sc
decl_stmt|;
name|bus_addr_t
name|bge_busaddr
decl_stmt|;
name|uint16_t
name|bge_flags
decl_stmt|;
name|int
name|bge_idx
decl_stmt|;
name|int
name|bge_maxsegs
decl_stmt|;
name|struct
name|bge_tx_bd
modifier|*
name|bge_ring
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_HWREV_TIGON
value|0x01
end_define

begin_define
define|#
directive|define
name|BGE_HWREV_TIGON_II
value|0x02
end_define

begin_define
define|#
directive|define
name|BGE_TIMEOUT
value|100000
end_define

begin_define
define|#
directive|define
name|BGE_TXCONS_UNSET
value|0xFFFF
end_define

begin_comment
comment|/* impossible value */
end_comment

begin_struct
struct|struct
name|bge_bcom_hack
block|{
name|int
name|reg
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ASF_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|ASF_NEW_HANDSHAKE
value|2
end_define

begin_define
define|#
directive|define
name|ASF_STACKUP
value|4
end_define

begin_struct
struct|struct
name|bge_softc
block|{
name|struct
name|ifnet
modifier|*
name|bge_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|bge_dev
decl_stmt|;
name|struct
name|mtx
name|bge_mtx
decl_stmt|;
name|device_t
name|bge_miibus
decl_stmt|;
name|bus_space_handle_t
name|bge_bhandle
decl_stmt|;
name|bus_space_tag_t
name|bge_btag
decl_stmt|;
name|void
modifier|*
name|bge_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|bge_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|bge_res
decl_stmt|;
name|struct
name|ifmedia
name|bge_ifmedia
decl_stmt|;
comment|/* TBI media info */
name|uint32_t
name|bge_flags
decl_stmt|;
define|#
directive|define
name|BGE_FLAG_TBI
value|0x00000001
define|#
directive|define
name|BGE_FLAG_JUMBO
value|0x00000002
define|#
directive|define
name|BGE_FLAG_MSI
value|0x00000100
define|#
directive|define
name|BGE_FLAG_PCIX
value|0x00000200
define|#
directive|define
name|BGE_FLAG_PCIE
value|0x00000400
define|#
directive|define
name|BGE_FLAG_5700_FAMILY
value|0x00001000
define|#
directive|define
name|BGE_FLAG_5705_PLUS
value|0x00002000
define|#
directive|define
name|BGE_FLAG_5714_FAMILY
value|0x00004000
define|#
directive|define
name|BGE_FLAG_575X_PLUS
value|0x00008000
define|#
directive|define
name|BGE_FLAG_RX_ALIGNBUG
value|0x00100000
define|#
directive|define
name|BGE_FLAG_NO_3LED
value|0x00200000
define|#
directive|define
name|BGE_FLAG_ADC_BUG
value|0x00400000
define|#
directive|define
name|BGE_FLAG_5704_A0_BUG
value|0x00800000
define|#
directive|define
name|BGE_FLAG_JITTER_BUG
value|0x01000000
define|#
directive|define
name|BGE_FLAG_BER_BUG
value|0x02000000
define|#
directive|define
name|BGE_FLAG_ADJUST_TRIM
value|0x04000000
define|#
directive|define
name|BGE_FLAG_CRC_BUG
value|0x08000000
name|uint32_t
name|bge_chipid
decl_stmt|;
name|uint8_t
name|bge_asicrev
decl_stmt|;
name|uint8_t
name|bge_chiprev
decl_stmt|;
name|uint8_t
name|bge_asf_mode
decl_stmt|;
name|uint8_t
name|bge_asf_count
decl_stmt|;
name|struct
name|bge_ring_data
name|bge_ldata
decl_stmt|;
comment|/* rings */
name|struct
name|bge_chain_data
name|bge_cdata
decl_stmt|;
comment|/* mbufs */
name|uint16_t
name|bge_tx_saved_considx
decl_stmt|;
name|uint16_t
name|bge_rx_saved_considx
decl_stmt|;
name|uint16_t
name|bge_ev_saved_considx
decl_stmt|;
name|uint16_t
name|bge_return_ring_cnt
decl_stmt|;
name|uint16_t
name|bge_std
decl_stmt|;
comment|/* current std ring head */
name|uint16_t
name|bge_jumbo
decl_stmt|;
comment|/* current jumo ring head */
name|uint32_t
name|bge_stat_ticks
decl_stmt|;
name|uint32_t
name|bge_rx_coal_ticks
decl_stmt|;
name|uint32_t
name|bge_tx_coal_ticks
decl_stmt|;
name|uint32_t
name|bge_tx_prodidx
decl_stmt|;
name|uint32_t
name|bge_rx_max_coal_bds
decl_stmt|;
name|uint32_t
name|bge_tx_max_coal_bds
decl_stmt|;
name|uint32_t
name|bge_tx_buf_ratio
decl_stmt|;
name|int
name|bge_if_flags
decl_stmt|;
name|int
name|bge_txcnt
decl_stmt|;
name|int
name|bge_link
decl_stmt|;
comment|/* link state */
name|int
name|bge_link_evt
decl_stmt|;
comment|/* pending link event */
name|int
name|bge_timer
decl_stmt|;
name|struct
name|callout
name|bge_stat_ch
decl_stmt|;
name|uint32_t
name|bge_rx_discards
decl_stmt|;
name|uint32_t
name|bge_tx_discards
decl_stmt|;
name|uint32_t
name|bge_tx_collisions
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
comment|/* DEVICE_POLLING */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BGE_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->bge_mtx, _name, MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->bge_mtx)
end_define

begin_define
define|#
directive|define
name|BGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->bge_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->bge_mtx)
end_define

begin_define
define|#
directive|define
name|BGE_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->bge_mtx)
end_define

end_unit

