begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: dwlpxreg.h,v 1.9 1998/03/21 22:02:42 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Taken from combinations of:  *  *	``DWLPA and DWLPB PCI Adapter Technical Manual,  *	  Order Number: EK-DWLPX-TM.A01''  *  *  and  *  *	``AlphaServer 8200/8400 System Technical Manual,  *	  Order Number EK-T8030-TM. A01''  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_comment
comment|/*  * There are (potentially) 4 I/O hoses, and there are three  * (electrically distinct) PCI busses per DWLPX (which appear  * as one logical PCI bus).  *  * A CPU to PCI Address Mapping looks (roughly) like this:  *  *  39 38........36 35.34 33.....32 31....................5 4.........3 2...0  *  --------------------------------------------------------------------------  *  |1| I/O NodeID |Hose#|PCI Space|Byte Aligned I/O<26:0>|Byte Length|0 0 0|  *  --------------------------------------------------------------------------  *  * I/O Node is the TLSB Node ID minus 4. Don't ask.  */
end_comment

begin_define
define|#
directive|define
name|NHPC
value|3
end_define

begin_comment
comment|/*  * Address Space Cookies  *  * (lacking I/O Node ID and Hose Numbers)  */
end_comment

begin_define
define|#
directive|define
name|DWLPX_PCI_DENSE
value|0x000000000LL
end_define

begin_define
define|#
directive|define
name|DWLPX_PCI_SPARSE
value|0x100000000LL
end_define

begin_define
define|#
directive|define
name|DWLPX_PCI_IOSPACE
value|0x200000000LL
end_define

begin_define
define|#
directive|define
name|DWLPX_PCI_CONF
value|0x300000000LL
end_define

begin_comment
comment|/*  * PCIA Interface Adapter Register Addresses (Offsets from Node Address)  *  *  * Addresses are for Hose #0, PCI bus #0. Macros below will offset  * per bus. I/O Hose and TLSB Node I/D offsets must be added separately.  */
end_comment

begin_define
define|#
directive|define
name|_PCIA_CTL
value|0x380000000LL
end_define

begin_comment
comment|/* PCI 0 Bus Control */
end_comment

begin_define
define|#
directive|define
name|_PCIA_MRETRY
value|0x380000080LL
end_define

begin_comment
comment|/* PCI 0 Master Retry Limit */
end_comment

begin_define
define|#
directive|define
name|_PCIA_GPR
value|0x380000100LL
end_define

begin_comment
comment|/* PCI 0 General Purpose */
end_comment

begin_define
define|#
directive|define
name|_PCIA_ERR
value|0x380000180LL
end_define

begin_comment
comment|/* PCI 0 Error Summary */
end_comment

begin_define
define|#
directive|define
name|_PCIA_FADR
value|0x380000200LL
end_define

begin_comment
comment|/* PCI 0 Failing Address */
end_comment

begin_define
define|#
directive|define
name|_PCIA_IMASK
value|0x380000280LL
end_define

begin_comment
comment|/* PCI 0 Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|_PCIA_DIAG
value|0x380000300LL
end_define

begin_comment
comment|/* PCI 0 Diagnostic  */
end_comment

begin_define
define|#
directive|define
name|_PCIA_IPEND
value|0x380000380LL
end_define

begin_comment
comment|/* PCI 0 Interrupt Pending */
end_comment

begin_define
define|#
directive|define
name|_PCIA_IPROG
value|0x380000400LL
end_define

begin_comment
comment|/* PCI 0 Interrupt in Progress */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WMASK_A
value|0x380000480LL
end_define

begin_comment
comment|/* PCI 0 Window Mask A */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WBASE_A
value|0x380000500LL
end_define

begin_comment
comment|/* PCI 0 Window Base A */
end_comment

begin_define
define|#
directive|define
name|_PCIA_TBASE_A
value|0x380000580LL
end_define

begin_comment
comment|/* PCI 0 Window Translated Base A */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WMASK_B
value|0x380000600LL
end_define

begin_comment
comment|/* PCI 0 Window Mask B */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WBASE_B
value|0x380000680LL
end_define

begin_comment
comment|/* PCI 0 Window Base B */
end_comment

begin_define
define|#
directive|define
name|_PCIA_TBASE_B
value|0x380000700LL
end_define

begin_comment
comment|/* PCI 0 Window Translated Base B */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WMASK_C
value|0x380000780LL
end_define

begin_comment
comment|/* PCI 0 Window Mask C */
end_comment

begin_define
define|#
directive|define
name|_PCIA_WBASE_C
value|0x380000800LL
end_define

begin_comment
comment|/* PCI 0 Window Base C */
end_comment

begin_define
define|#
directive|define
name|_PCIA_TBASE_C
value|0x380000880LL
end_define

begin_comment
comment|/* PCI 0 Window Translated Base C */
end_comment

begin_define
define|#
directive|define
name|_PCIA_ERRVEC
value|0x380000900LL
end_define

begin_comment
comment|/* PCI 0 Error Interrupt Vector */
end_comment

begin_define
define|#
directive|define
name|_PCIA_DEVVEC
value|0x380001000LL
end_define

begin_comment
comment|/* PCI 0 Device Interrupt Vector */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_CTL	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_MRETRY
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_MRETRY	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_GPR
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_GPR	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_ERR
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_ERR	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_FADR
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_FADR	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_IMASK
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_IMASK	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_DIAG
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_DIAG	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_IPEND
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_IPEND	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_IPROG
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_IPROG	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_A
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WMASK_A	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WBASE_A
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WBASE_A	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_TBASE_A
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_TBASE_A	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_B
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WMASK_B	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WBASE_B
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WBASE_B	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_TBASE_B
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_TBASE_B	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_C
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WMASK_C	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_WBASE_C
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_WBASE_C	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_TBASE_C
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_TBASE_C	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_ERRVEC
parameter_list|(
name|hpc
parameter_list|)
value|(_PCIA_ERRVEC	+ (0x200000 * (hpc)))
end_define

begin_define
define|#
directive|define
name|PCIA_DEVVEC
parameter_list|(
name|hpc
parameter_list|,
name|subslot
parameter_list|,
name|ipin
parameter_list|)
define|\
value|(_PCIA_DEVVEC + (0x200000 * (hpc)) + ((subslot) * 0x200) + ((ipin-1) * 0x80))
end_define

begin_define
define|#
directive|define
name|PCIA_SCYCLE
value|0x380002000LL
end_define

begin_comment
comment|/* PCI Special Cycle */
end_comment

begin_define
define|#
directive|define
name|PCIA_IACK
value|0x380002080LL
end_define

begin_comment
comment|/* PCI Interrupt Acknowledge */
end_comment

begin_define
define|#
directive|define
name|PCIA_PRESENT
value|0x380800000LL
end_define

begin_comment
comment|/* PCI Slot Present */
end_comment

begin_define
define|#
directive|define
name|PCIA_TBIT
value|0x380A00000LL
end_define

begin_comment
comment|/* PCI TBIT */
end_comment

begin_define
define|#
directive|define
name|PCIA_MCTL
value|0x380C00000LL
end_define

begin_comment
comment|/* PCI Module Control */
end_comment

begin_define
define|#
directive|define
name|PCIA_IBR
value|0x380E00000LL
end_define

begin_comment
comment|/* PCI Information Base Repair */
end_comment

begin_comment
comment|/*  * Bits in PCIA_CTL register  */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_SG32K
value|(0<<25)
end_define

begin_comment
comment|/* 32K SGMAP entries */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_SG64K
value|(1<<25)
end_define

begin_comment
comment|/* 64K SGMAP entries */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_SG128K
value|(3<<25)
end_define

begin_comment
comment|/* 128K SGMAP entries */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_SG0K
value|(2<<25)
end_define

begin_comment
comment|/* disable SGMAP in HPC */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_4UP
value|(0<<23)
end_define

begin_comment
comment|/* 4 Up Hose buffers */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_1UP
value|(1<<23)
end_define

begin_comment
comment|/* 1 "" */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_2UP
value|(2<<23)
end_define

begin_comment
comment|/* 2 "" */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_3UP
value|(3<<23)
end_define

begin_comment
comment|/* 3 "" (normal) */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_RMM4X
value|(1<<22)
end_define

begin_comment
comment|/* Read Multiple 2X -> 4X */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_RMMENA
value|(1<<21)
end_define

begin_comment
comment|/* Read Multiple Enable */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_RMMARB
value|(1<<20)
end_define

begin_comment
comment|/* RMM Multiple Arb */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_HAEDIS
value|(1<<19)
end_define

begin_comment
comment|/* Hardware Address Ext. Disable */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_MHAE
parameter_list|(
name|x
parameter_list|)
value|((x&0x1f)<<14)
end_define

begin_comment
comment|/* Memory Hardware Address Extension */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_IHAE
parameter_list|(
name|x
parameter_list|)
value|((x&0x1f)<<9)
end_define

begin_comment
comment|/* I/O Hardware Address Extension */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_CUTENA
value|(1<<8)
end_define

begin_comment
comment|/* PCI Cut Through */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_CUT
parameter_list|(
name|x
parameter_list|)
value|((x&0x7)<<4)
end_define

begin_comment
comment|/* PCI Cut Through Size */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_PRESET
value|(1<<3)
end_define

begin_comment
comment|/* PCI Reset */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_DTHROT
value|(1<<2)
end_define

begin_comment
comment|/* DMA downthrottle */
end_comment

begin_define
define|#
directive|define
name|PCIA_CTL_T1CYC
value|(1<<0)
end_define

begin_comment
comment|/* Type 1 Configuration Cycle */
end_comment

begin_comment
comment|/*  * Bits in PCIA_ERR. All are "Write 1 to clear".  */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_SERR_L
value|(1<<18)
end_define

begin_comment
comment|/* PCI device asserted SERR_L */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_ILAT
value|(1<<17)
end_define

begin_comment
comment|/* Incremental Latency Exceeded */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_SGPRTY
value|(1<<16)
end_define

begin_comment
comment|/* CPU access of SG RAM Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_ILLCSR
value|(1<<15)
end_define

begin_comment
comment|/* Illegal CSR Address Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_PCINXM
value|(1<<14)
end_define

begin_comment
comment|/* Nonexistent PCI Address Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_DSCERR
value|(1<<13)
end_define

begin_comment
comment|/* PCI Target Disconnect Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_ABRT
value|(1<<12)
end_define

begin_comment
comment|/* PCI Target Abort Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_WPRTY
value|(1<<11)
end_define

begin_comment
comment|/* PCI Write Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_DPERR
value|(1<<10)
end_define

begin_comment
comment|/* PCI Data Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_APERR
value|(1<<9)
end_define

begin_comment
comment|/* PCI Address Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_DFLT
value|(1<<8)
end_define

begin_comment
comment|/* SG Map RAM Invalid Entry Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_DPRTY
value|(1<<7)
end_define

begin_comment
comment|/* DMA access of SG RAM Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_DRPERR
value|(1<<6)
end_define

begin_comment
comment|/* DMA Read Return Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_MABRT
value|(1<<5)
end_define

begin_comment
comment|/* PCI Master Abort Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_CPRTY
value|(1<<4)
end_define

begin_comment
comment|/* CSR Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_COVR
value|(1<<3)
end_define

begin_comment
comment|/* CSR Overrun Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_MBPERR
value|(1<<2)
end_define

begin_comment
comment|/* Mailbox Parity Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_MBILI
value|(1<<1)
end_define

begin_comment
comment|/* Mailbox Illegal Length Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_ERROR
value|(1<<0)
end_define

begin_comment
comment|/* Summary Error */
end_comment

begin_define
define|#
directive|define
name|PCIA_ERR_ALLERR
value|((1<<19) - 1)
end_define

begin_comment
comment|/*  * Bits in PCIA_PRESENT.  */
end_comment

begin_define
define|#
directive|define
name|PCIA_PRESENT_REVSHIFT
value|25
end_define

begin_comment
comment|/* shift by this to get revision */
end_comment

begin_define
define|#
directive|define
name|PCIA_PRESENT_REVMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_STDIO
value|0x01000000
end_define

begin_comment
comment|/* STD I/O bridge present */
end_comment

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOTSHIFT
parameter_list|(
name|hpc
parameter_list|,
name|slot
parameter_list|)
define|\
value|(((hpc)<< 3) + ((slot)<< 1))
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOT_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOT_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOT_25W
value|0x1
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOT_15W
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIA_PRESENT_SLOW_7W
value|0x3
end_define

begin_comment
comment|/*  * Location of the DWLPx SGMAP page table SRAM.  */
end_comment

begin_define
define|#
directive|define
name|PCIA_SGMAP_PT
value|0x381000000UL
end_define

begin_comment
comment|/*  * Values for PCIA_WMASK_x  */
end_comment

begin_define
define|#
directive|define
name|PCIA_WMASK_MASK
value|0xffff0000
end_define

begin_comment
comment|/* mask of valid bits */
end_comment

begin_define
define|#
directive|define
name|PCIA_WMASK_64K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_128K
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_256K
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_512K
value|0x00070000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_1M
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_2M
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_4M
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_8M
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_16M
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_32M
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_64M
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_128M
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_256M
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_512M
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_1G
value|0x3fff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_2G
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|PCIA_WMASK_4G
value|0xffff0000
end_define

begin_comment
comment|/*  * Values for PCIA_WBASE_x  */
end_comment

begin_define
define|#
directive|define
name|PCIA_WBASE_MASK
value|0xffff0000
end_define

begin_comment
comment|/* mask of valid bits in address */
end_comment

begin_define
define|#
directive|define
name|PCIA_WBASE_W_EN
value|0x00000002
end_define

begin_comment
comment|/* window enable */
end_comment

begin_define
define|#
directive|define
name|PCIA_WBASE_SG_EN
value|0x00000001
end_define

begin_comment
comment|/* SGMAP enable */
end_comment

begin_comment
comment|/*  * Values for PCIA_TBASE_x  *  * NOTE: Translated Base is only used on direct-mapped DMA on the DWLPx!!  */
end_comment

begin_define
define|#
directive|define
name|PCIA_TBASE_MASK
value|0x00fffffe
end_define

begin_define
define|#
directive|define
name|PCIA_TBASE_SHIFT
value|15
end_define

end_unit

