begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: hifn7751reg.h,v 1.35 2002/04/08 17:49:42 jason Exp $	*/
end_comment

begin_comment
comment|/*-  * Invertex AEON / Hifn 7751 driver  * Copyright (c) 1999 Invertex Inc. All rights reserved.  * Copyright (c) 1999 Theo de Raadt  * Copyright (c) 2000-2001 Network Security Technologies, Inc.  *			http://www.netsec.net  *  * Please send any comments, feedback, bug-fixes, or feature requests to  * software@invertex.com.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HIFN_H__
end_ifndef

begin_define
define|#
directive|define
name|__HIFN_H__
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_comment
comment|/*  * Some PCI configuration space offset defines.  The names were made  * identical to the names used by the Linux kernel.  */
end_comment

begin_define
define|#
directive|define
name|HIFN_BAR0
value|PCIR_BAR(0)
end_define

begin_comment
comment|/* PUC register map */
end_comment

begin_define
define|#
directive|define
name|HIFN_BAR1
value|PCIR_BAR(1)
end_define

begin_comment
comment|/* DMA register map */
end_comment

begin_define
define|#
directive|define
name|HIFN_TRDY_TIMEOUT
value|0x40
end_define

begin_define
define|#
directive|define
name|HIFN_RETRY_TIMEOUT
value|0x41
end_define

begin_comment
comment|/*  * PCI vendor and device identifiers  * (the names are preserved from their OpenBSD source).  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_HIFN
value|0x13a3
end_define

begin_comment
comment|/* Hifn */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_7751
value|0x0005
end_define

begin_comment
comment|/* 7751 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_6500
value|0x0006
end_define

begin_comment
comment|/* 6500 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_7811
value|0x0007
end_define

begin_comment
comment|/* 7811 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_7951
value|0x0012
end_define

begin_comment
comment|/* 7951 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_7955
value|0x0020
end_define

begin_comment
comment|/* 7954/7955 */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_HIFN_7956
value|0x001d
end_define

begin_comment
comment|/* 7956 */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_INVERTEX
value|0x14e1
end_define

begin_comment
comment|/* Invertex */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_INVERTEX_AEON
value|0x0005
end_define

begin_comment
comment|/* AEON */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_NETSEC
value|0x1660
end_define

begin_comment
comment|/* NetSec */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_NETSEC_7751
value|0x7751
end_define

begin_comment
comment|/* 7751 */
end_comment

begin_comment
comment|/*  * The values below should multiple of 4 -- and be large enough to handle  * any command the driver implements.  *  * MAX_COMMAND = base command + mac command + encrypt command +  *			mac-key + rc4-key  * MAX_RESULT  = base result + mac result + mac + encrypt result  *			  *  */
end_comment

begin_define
define|#
directive|define
name|HIFN_MAX_COMMAND
value|(8 + 8 + 8 + 64 + 260)
end_define

begin_define
define|#
directive|define
name|HIFN_MAX_RESULT
value|(8 + 4 + 20 + 4)
end_define

begin_comment
comment|/*  * hifn_desc_t  *  * Holds an individual descriptor for any of the rings.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hifn_desc
block|{
specifier|volatile
name|u_int32_t
name|l
decl_stmt|;
comment|/* length and status bits */
specifier|volatile
name|u_int32_t
name|p
decl_stmt|;
block|}
name|hifn_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Masks for the "length" field of struct hifn_desc.  */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_LENGTH
value|0x0000ffff
end_define

begin_comment
comment|/* length bit mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_MASKDONEIRQ
value|0x02000000
end_define

begin_comment
comment|/* mask the done interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_DESTOVER
value|0x04000000
end_define

begin_comment
comment|/* destination overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_OVER
value|0x08000000
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_LAST
value|0x20000000
end_define

begin_comment
comment|/* last descriptor in chain */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_JUMP
value|0x40000000
end_define

begin_comment
comment|/* jump descriptor */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_VALID
value|0x80000000
end_define

begin_comment
comment|/* valid bit */
end_comment

begin_comment
comment|/*  * Processing Unit Registers (offset from BASEREG0)  */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUDATA
value|0x00
end_define

begin_comment
comment|/* Processing Unit Data */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUCTRL
value|0x04
end_define

begin_comment
comment|/* Processing Unit Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUISR
value|0x08
end_define

begin_comment
comment|/* Processing Unit Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUCNFG
value|0x0c
end_define

begin_comment
comment|/* Processing Unit Configuration */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUIER
value|0x10
end_define

begin_comment
comment|/* Processing Unit Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUSTAT
value|0x14
end_define

begin_comment
comment|/* Processing Unit Status/Chip ID */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_FIFOSTAT
value|0x18
end_define

begin_comment
comment|/* FIFO Status */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_FIFOCNFG
value|0x1c
end_define

begin_comment
comment|/* FIFO Configuration */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_PUCTRL2
value|0x28
end_define

begin_comment
comment|/* Processing Unit Control (2nd map) */
end_comment

begin_define
define|#
directive|define
name|HIFN_0_MUTE1
value|0x80
end_define

begin_define
define|#
directive|define
name|HIFN_0_MUTE2
value|0x90
end_define

begin_define
define|#
directive|define
name|HIFN_0_SPACESIZE
value|0x100
end_define

begin_comment
comment|/* Register space size */
end_comment

begin_comment
comment|/* Processing Unit Control Register (HIFN_0_PUCTRL) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCTRL_CLRSRCFIFO
value|0x0010
end_define

begin_comment
comment|/* clear source fifo */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCTRL_STOP
value|0x0008
end_define

begin_comment
comment|/* stop pu */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCTRL_LOCKRAM
value|0x0004
end_define

begin_comment
comment|/* lock ram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCTRL_DMAENA
value|0x0002
end_define

begin_comment
comment|/* enable dma */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCTRL_RESET
value|0x0001
end_define

begin_comment
comment|/* Reset processing unit */
end_comment

begin_comment
comment|/* Processing Unit Interrupt Status Register (HIFN_0_PUISR) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_CMDINVAL
value|0x8000
end_define

begin_comment
comment|/* Invalid command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_DATAERR
value|0x4000
end_define

begin_comment
comment|/* Data error interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_SRCFIFO
value|0x2000
end_define

begin_comment
comment|/* Source FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_DSTFIFO
value|0x1000
end_define

begin_comment
comment|/* Destination FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_DSTOVER
value|0x0200
end_define

begin_comment
comment|/* Destination overrun interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_SRCCMD
value|0x0080
end_define

begin_comment
comment|/* Source command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_SRCCTX
value|0x0040
end_define

begin_comment
comment|/* Source context interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_SRCDATA
value|0x0020
end_define

begin_comment
comment|/* Source data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_DSTDATA
value|0x0010
end_define

begin_comment
comment|/* Destination data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUISR_DSTRESULT
value|0x0004
end_define

begin_comment
comment|/* Destination result interrupt */
end_comment

begin_comment
comment|/* Processing Unit Configuration Register (HIFN_0_PUCNFG) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRAMMASK
value|0xe000
end_define

begin_comment
comment|/* DRAM size mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_256K
value|0x0000
end_define

begin_comment
comment|/* 256k dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_512K
value|0x2000
end_define

begin_comment
comment|/* 512k dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_1M
value|0x4000
end_define

begin_comment
comment|/* 1m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_2M
value|0x6000
end_define

begin_comment
comment|/* 2m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_4M
value|0x8000
end_define

begin_comment
comment|/* 4m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_8M
value|0xa000
end_define

begin_comment
comment|/* 8m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUNCFG_DSZ_16M
value|0xc000
end_define

begin_comment
comment|/* 16m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DSZ_32M
value|0xe000
end_define

begin_comment
comment|/* 32m dram */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRAMREFRESH
value|0x1800
end_define

begin_comment
comment|/* DRAM refresh rate mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRFR_512
value|0x0000
end_define

begin_comment
comment|/* 512 divisor of ECLK */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRFR_256
value|0x0800
end_define

begin_comment
comment|/* 256 divisor of ECLK */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRFR_128
value|0x1000
end_define

begin_comment
comment|/* 128 divisor of ECLK */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_TCALLPHASES
value|0x0200
end_define

begin_comment
comment|/* your guess is as good as mine... */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_TCDRVTOTEM
value|0x0100
end_define

begin_comment
comment|/* your guess is as good as mine... */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_BIGENDIAN
value|0x0080
end_define

begin_comment
comment|/* DMA big endian mode */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_BUS32
value|0x0040
end_define

begin_comment
comment|/* Bus width 32bits */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_BUS16
value|0x0000
end_define

begin_comment
comment|/* Bus width 16 bits */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_CHIPID
value|0x0020
end_define

begin_comment
comment|/* Allow chipid from PUSTAT */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_DRAM
value|0x0010
end_define

begin_comment
comment|/* Context RAM is DRAM */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_SRAM
value|0x0000
end_define

begin_comment
comment|/* Context RAM is SRAM */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_COMPSING
value|0x0004
end_define

begin_comment
comment|/* Enable single compression context */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUCNFG_ENCCNFG
value|0x0002
end_define

begin_comment
comment|/* Encryption configuration */
end_comment

begin_comment
comment|/* Processing Unit Interrupt Enable Register (HIFN_0_PUIER) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_CMDINVAL
value|0x8000
end_define

begin_comment
comment|/* Invalid command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_DATAERR
value|0x4000
end_define

begin_comment
comment|/* Data error interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_SRCFIFO
value|0x2000
end_define

begin_comment
comment|/* Source FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_DSTFIFO
value|0x1000
end_define

begin_comment
comment|/* Destination FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_DSTOVER
value|0x0200
end_define

begin_comment
comment|/* Destination overrun interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_SRCCMD
value|0x0080
end_define

begin_comment
comment|/* Source command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_SRCCTX
value|0x0040
end_define

begin_comment
comment|/* Source context interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_SRCDATA
value|0x0020
end_define

begin_comment
comment|/* Source data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_DSTDATA
value|0x0010
end_define

begin_comment
comment|/* Destination data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUIER_DSTRESULT
value|0x0004
end_define

begin_comment
comment|/* Destination result interrupt */
end_comment

begin_comment
comment|/* Processing Unit Status Register/Chip ID (HIFN_0_PUSTAT) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_CMDINVAL
value|0x8000
end_define

begin_comment
comment|/* Invalid command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_DATAERR
value|0x4000
end_define

begin_comment
comment|/* Data error interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_SRCFIFO
value|0x2000
end_define

begin_comment
comment|/* Source FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_DSTFIFO
value|0x1000
end_define

begin_comment
comment|/* Destination FIFO ready interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_DSTOVER
value|0x0200
end_define

begin_comment
comment|/* Destination overrun interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_SRCCMD
value|0x0080
end_define

begin_comment
comment|/* Source command interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_SRCCTX
value|0x0040
end_define

begin_comment
comment|/* Source context interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_SRCDATA
value|0x0020
end_define

begin_comment
comment|/* Source data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_DSTDATA
value|0x0010
end_define

begin_comment
comment|/* Destination data interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_DSTRESULT
value|0x0004
end_define

begin_comment
comment|/* Destination result interrupt */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_CHIPREV
value|0x00ff
end_define

begin_comment
comment|/* Chip revision mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_CHIPENA
value|0xff00
end_define

begin_comment
comment|/* Chip enabled mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_ENA_2
value|0x1100
end_define

begin_comment
comment|/* Level 2 enabled */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_ENA_1
value|0x1000
end_define

begin_comment
comment|/* Level 1 enabled */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_ENA_0
value|0x3000
end_define

begin_comment
comment|/* Level 0 enabled */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_REV_2
value|0x0020
end_define

begin_comment
comment|/* 7751 PT6/2 */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUSTAT_REV_3
value|0x0030
end_define

begin_comment
comment|/* 7751 PT6/3 */
end_comment

begin_comment
comment|/* FIFO Status Register (HIFN_0_FIFOSTAT) */
end_comment

begin_define
define|#
directive|define
name|HIFN_FIFOSTAT_SRC
value|0x7f00
end_define

begin_comment
comment|/* Source FIFO available */
end_comment

begin_define
define|#
directive|define
name|HIFN_FIFOSTAT_DST
value|0x007f
end_define

begin_comment
comment|/* Destination FIFO available */
end_comment

begin_comment
comment|/* FIFO Configuration Register (HIFN_0_FIFOCNFG) */
end_comment

begin_define
define|#
directive|define
name|HIFN_FIFOCNFG_THRESHOLD
value|0x0400
end_define

begin_comment
comment|/* must be written as this value */
end_comment

begin_comment
comment|/*  * DMA Interface Registers (offset from BASEREG1)  */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_CRAR
value|0x0c
end_define

begin_comment
comment|/* DMA Command Ring Address */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_SRAR
value|0x1c
end_define

begin_comment
comment|/* DMA Source Ring Address */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_RRAR
value|0x2c
end_define

begin_comment
comment|/* DMA Result Ring Address */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_DRAR
value|0x3c
end_define

begin_comment
comment|/* DMA Destination Ring Address */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_CSR
value|0x40
end_define

begin_comment
comment|/* DMA Status and Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_IER
value|0x44
end_define

begin_comment
comment|/* DMA Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_CNFG
value|0x48
end_define

begin_comment
comment|/* DMA Configuration */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PLL
value|0x4c
end_define

begin_comment
comment|/* 7955/7956: PLL config */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_7811_RNGENA
value|0x60
end_define

begin_comment
comment|/* 7811: rng enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_7811_RNGCFG
value|0x64
end_define

begin_comment
comment|/* 7811: rng config */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_7811_RNGDAT
value|0x68
end_define

begin_comment
comment|/* 7811: rng data */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_7811_RNGSTS
value|0x6c
end_define

begin_comment
comment|/* 7811: rng status */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_DMA_CNFG2
value|0x6c
end_define

begin_comment
comment|/* 7955/7956: dma config #2 */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_7811_MIPSRST
value|0x94
end_define

begin_comment
comment|/* 7811: MIPS reset */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_REVID
value|0x98
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_RESET
value|0x204
end_define

begin_comment
comment|/* Public/RNG Reset */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_BASE
value|0x300
end_define

begin_comment
comment|/* Public Base Address */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_OPLEN
value|0x304
end_define

begin_comment
comment|/* 7951-compat Public Operand Length */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_OP
value|0x308
end_define

begin_comment
comment|/* 7951-compat Public Operand */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_STATUS
value|0x30c
end_define

begin_comment
comment|/* 7951-compat Public Status */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_IEN
value|0x310
end_define

begin_comment
comment|/* Public Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_RNG_CONFIG
value|0x314
end_define

begin_comment
comment|/* RNG config */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_RNG_DATA
value|0x318
end_define

begin_comment
comment|/* RNG data */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_MODE
value|0x320
end_define

begin_comment
comment|/* PK mode */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_FIFO_OPLEN
value|0x380
end_define

begin_comment
comment|/* first element of oplen fifo */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_FIFO_OP
value|0x384
end_define

begin_comment
comment|/* first element of op fifo */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_MEM
value|0x400
end_define

begin_comment
comment|/* start of Public key memory */
end_comment

begin_define
define|#
directive|define
name|HIFN_1_PUB_MEMEND
value|0xbff
end_define

begin_comment
comment|/* end of Public key memory */
end_comment

begin_comment
comment|/* DMA Status and Control Register (HIFN_1_DMA_CSR) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_CTRLMASK
value|0xc0000000
end_define

begin_comment
comment|/* Destinition Ring Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_CTRL_NOP
value|0x00000000
end_define

begin_comment
comment|/* Dest. Control: no-op */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_CTRL_DIS
value|0x40000000
end_define

begin_comment
comment|/* Dest. Control: disable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_CTRL_ENA
value|0x80000000
end_define

begin_comment
comment|/* Dest. Control: enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_ABORT
value|0x20000000
end_define

begin_comment
comment|/* Destinition Ring PCIAbort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_DONE
value|0x10000000
end_define

begin_comment
comment|/* Destinition Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_LAST
value|0x08000000
end_define

begin_comment
comment|/* Destinition Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_WAIT
value|0x04000000
end_define

begin_comment
comment|/* Destinition Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_D_OVER
value|0x02000000
end_define

begin_comment
comment|/* Destinition Ring Overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_CTRL
value|0x00c00000
end_define

begin_comment
comment|/* Result Ring Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_CTRL_NOP
value|0x00000000
end_define

begin_comment
comment|/* Result Control: no-op */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_CTRL_DIS
value|0x00400000
end_define

begin_comment
comment|/* Result Control: disable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_CTRL_ENA
value|0x00800000
end_define

begin_comment
comment|/* Result Control: enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_ABORT
value|0x00200000
end_define

begin_comment
comment|/* Result Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_DONE
value|0x00100000
end_define

begin_comment
comment|/* Result Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_LAST
value|0x00080000
end_define

begin_comment
comment|/* Result Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_WAIT
value|0x00040000
end_define

begin_comment
comment|/* Result Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_R_OVER
value|0x00020000
end_define

begin_comment
comment|/* Result Ring Overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_CTRL
value|0x0000c000
end_define

begin_comment
comment|/* Source Ring Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_CTRL_NOP
value|0x00000000
end_define

begin_comment
comment|/* Source Control: no-op */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_CTRL_DIS
value|0x00004000
end_define

begin_comment
comment|/* Source Control: disable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_CTRL_ENA
value|0x00008000
end_define

begin_comment
comment|/* Source Control: enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_ABORT
value|0x00002000
end_define

begin_comment
comment|/* Source Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_DONE
value|0x00001000
end_define

begin_comment
comment|/* Source Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_LAST
value|0x00000800
end_define

begin_comment
comment|/* Source Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_S_WAIT
value|0x00000400
end_define

begin_comment
comment|/* Source Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_ILLW
value|0x00000200
end_define

begin_comment
comment|/* Illegal write (7811 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_ILLR
value|0x00000100
end_define

begin_comment
comment|/* Illegal read (7811 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_CTRL
value|0x000000c0
end_define

begin_comment
comment|/* Command Ring Control */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_CTRL_NOP
value|0x00000000
end_define

begin_comment
comment|/* Command Control: no-op */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_CTRL_DIS
value|0x00000040
end_define

begin_comment
comment|/* Command Control: disable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_CTRL_ENA
value|0x00000080
end_define

begin_comment
comment|/* Command Control: enable */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_ABORT
value|0x00000020
end_define

begin_comment
comment|/* Command Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_DONE
value|0x00000010
end_define

begin_comment
comment|/* Command Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_LAST
value|0x00000008
end_define

begin_comment
comment|/* Command Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_C_WAIT
value|0x00000004
end_define

begin_comment
comment|/* Command Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_PUBDONE
value|0x00000002
end_define

begin_comment
comment|/* Public op done (7951 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACSR_ENGINE
value|0x00000001
end_define

begin_comment
comment|/* Command Ring Engine IRQ */
end_comment

begin_comment
comment|/* DMA Interrupt Enable Register (HIFN_1_DMA_IER) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_D_ABORT
value|0x20000000
end_define

begin_comment
comment|/* Destination Ring PCIAbort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_D_DONE
value|0x10000000
end_define

begin_comment
comment|/* Destination Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_D_LAST
value|0x08000000
end_define

begin_comment
comment|/* Destination Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_D_WAIT
value|0x04000000
end_define

begin_comment
comment|/* Destination Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_D_OVER
value|0x02000000
end_define

begin_comment
comment|/* Destination Ring Overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_R_ABORT
value|0x00200000
end_define

begin_comment
comment|/* Result Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_R_DONE
value|0x00100000
end_define

begin_comment
comment|/* Result Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_R_LAST
value|0x00080000
end_define

begin_comment
comment|/* Result Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_R_WAIT
value|0x00040000
end_define

begin_comment
comment|/* Result Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_R_OVER
value|0x00020000
end_define

begin_comment
comment|/* Result Ring Overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_S_ABORT
value|0x00002000
end_define

begin_comment
comment|/* Source Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_S_DONE
value|0x00001000
end_define

begin_comment
comment|/* Source Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_S_LAST
value|0x00000800
end_define

begin_comment
comment|/* Source Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_S_WAIT
value|0x00000400
end_define

begin_comment
comment|/* Source Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_ILLW
value|0x00000200
end_define

begin_comment
comment|/* Illegal write (7811 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_ILLR
value|0x00000100
end_define

begin_comment
comment|/* Illegal read (7811 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_C_ABORT
value|0x00000020
end_define

begin_comment
comment|/* Command Ring PCI Abort */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_C_DONE
value|0x00000010
end_define

begin_comment
comment|/* Command Ring Done */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_C_LAST
value|0x00000008
end_define

begin_comment
comment|/* Command Ring Last */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_C_WAIT
value|0x00000004
end_define

begin_comment
comment|/* Command Ring Waiting */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_PUBDONE
value|0x00000002
end_define

begin_comment
comment|/* public op done (7951 only) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMAIER_ENGINE
value|0x00000001
end_define

begin_comment
comment|/* Engine IRQ */
end_comment

begin_comment
comment|/* DMA Configuration Register (HIFN_1_DMA_CNFG) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_BIGENDIAN
value|0x10000000
end_define

begin_comment
comment|/* big endian mode */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_POLLFREQ
value|0x00ff0000
end_define

begin_comment
comment|/* Poll frequency mask */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_UNLOCK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HIFN_DMACNFG_POLLINVAL
value|0x00000700
end_define

begin_comment
comment|/* Invalid Poll Scalar */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_LAST
value|0x00000010
end_define

begin_comment
comment|/* Host control LAST bit */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_MODE
value|0x00000004
end_define

begin_comment
comment|/* DMA mode */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_DMARESET
value|0x00000002
end_define

begin_comment
comment|/* DMA Reset # */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG_MSTRESET
value|0x00000001
end_define

begin_comment
comment|/* Master Reset # */
end_comment

begin_comment
comment|/* DMA Configuration Register (HIFN_1_DMA_CNFG2) */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_PKSWAP32
value|(1<< 19)
end_define

begin_comment
comment|/* swap the OPLEN/OP reg */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_PKSWAP8
value|(1<< 18)
end_define

begin_comment
comment|/* swap the bits of OPLEN/OP */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_BAR0_SWAP32
value|(1<<17)
end_define

begin_comment
comment|/* swap the bytes of BAR0 */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_BAR1_SWAP8
value|(1<<16)
end_define

begin_comment
comment|/* swap the bits  of BAR0 */
end_comment

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_INIT_WRITE_BURST_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_INIT_READ_BURST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_TGT_WRITE_BURST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HIFN_DMACNFG2_TGT_READ_BURST_SHIFT
value|0
end_define

begin_comment
comment|/* 7811 RNG Enable Register (HIFN_1_7811_RNGENA) */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGENA_ENA
value|0x00000001
end_define

begin_comment
comment|/* enable RNG */
end_comment

begin_comment
comment|/* 7811 RNG Config Register (HIFN_1_7811_RNGCFG) */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGCFG_PRE1
value|0x00000f00
end_define

begin_comment
comment|/* first prescalar */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGCFG_OPRE
value|0x00000080
end_define

begin_comment
comment|/* output prescalar */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGCFG_DEFL
value|0x00000f80
end_define

begin_comment
comment|/* 2 words/ 1/100 sec */
end_comment

begin_comment
comment|/* 7811 RNG Status Register (HIFN_1_7811_RNGSTS) */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGSTS_RDY
value|0x00004000
end_define

begin_comment
comment|/* two numbers in FIFO */
end_comment

begin_define
define|#
directive|define
name|HIFN_7811_RNGSTS_UFL
value|0x00001000
end_define

begin_comment
comment|/* rng underflow */
end_comment

begin_comment
comment|/* 7811 MIPS Reset Register (HIFN_1_7811_MIPSRST) */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_BAR2SIZE
value|0xffff0000
end_define

begin_comment
comment|/* sdram size */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_GPRAMINIT
value|0x00008000
end_define

begin_comment
comment|/* gpram can be accessed */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_CRAMINIT
value|0x00004000
end_define

begin_comment
comment|/* ctxram can be accessed */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_LED2
value|0x00000400
end_define

begin_comment
comment|/* external LED2 */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_LED1
value|0x00000200
end_define

begin_comment
comment|/* external LED1 */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_LED0
value|0x00000100
end_define

begin_comment
comment|/* external LED0 */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_MIPSDIS
value|0x00000004
end_define

begin_comment
comment|/* disable MIPS */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_MIPSRST
value|0x00000002
end_define

begin_comment
comment|/* warm reset MIPS */
end_comment

begin_define
define|#
directive|define
name|HIFN_MIPSRST_MIPSCOLD
value|0x00000001
end_define

begin_comment
comment|/* cold reset MIPS */
end_comment

begin_comment
comment|/* Public key reset register (HIFN_1_PUB_RESET) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBRST_RESET
value|0x00000001
end_define

begin_comment
comment|/* reset public/rng unit */
end_comment

begin_comment
comment|/* Public operation register (HIFN_1_PUB_OP) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_AOFFSET
value|0x0000003e
end_define

begin_comment
comment|/* A offset */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_BOFFSET
value|0x00000fc0
end_define

begin_comment
comment|/* B offset */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_MOFFSET
value|0x0003f000
end_define

begin_comment
comment|/* M offset */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MASK
value|0x003c0000
end_define

begin_comment
comment|/* Opcode: */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_NOP
value|0x00000000
end_define

begin_comment
comment|/*  NOP */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_ADD
value|0x00040000
end_define

begin_comment
comment|/*  ADD */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_ADDC
value|0x00080000
end_define

begin_comment
comment|/*  ADD w/carry */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_SUB
value|0x000c0000
end_define

begin_comment
comment|/*  SUB */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_SUBC
value|0x00100000
end_define

begin_comment
comment|/*  SUB w/carry */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MODADD
value|0x00140000
end_define

begin_comment
comment|/*  Modular ADD */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MODSUB
value|0x00180000
end_define

begin_comment
comment|/*  Modular SUB */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_INCA
value|0x001c0000
end_define

begin_comment
comment|/*  INC A */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_DECA
value|0x00200000
end_define

begin_comment
comment|/*  DEC A */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MULT
value|0x00240000
end_define

begin_comment
comment|/*  MULT */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MODMULT
value|0x00280000
end_define

begin_comment
comment|/*  Modular MULT */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MODRED
value|0x002c0000
end_define

begin_comment
comment|/*  Modular Red */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOP_OP_MODEXP
value|0x00300000
end_define

begin_comment
comment|/*  Modular Exp */
end_comment

begin_comment
comment|/* Public operand length register (HIFN_1_PUB_OPLEN) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBOPLEN_MODLEN
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HIFN_PUBOPLEN_EXPLEN
value|0x0003ff80
end_define

begin_define
define|#
directive|define
name|HIFN_PUBOPLEN_REDLEN
value|0x003c0000
end_define

begin_comment
comment|/* Public status register (HIFN_1_PUB_STATUS) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_DONE
value|0x00000001
end_define

begin_comment
comment|/* operation done */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_CARRY
value|0x00000002
end_define

begin_comment
comment|/* carry */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_FIFO_EMPTY
value|0x00000100
end_define

begin_comment
comment|/* fifo empty */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_FIFO_FULL
value|0x00000200
end_define

begin_comment
comment|/* fifo full */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_FIFO_OVFL
value|0x00000400
end_define

begin_comment
comment|/* fifo overflow */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_FIFO_WRITE
value|0x000f0000
end_define

begin_comment
comment|/* fifo write */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBSTS_FIFO_READ
value|0x0f000000
end_define

begin_comment
comment|/* fifo read */
end_comment

begin_comment
comment|/* Public interrupt enable register (HIFN_1_PUB_IEN) */
end_comment

begin_define
define|#
directive|define
name|HIFN_PUBIEN_DONE
value|0x00000001
end_define

begin_comment
comment|/* operation done interrupt */
end_comment

begin_comment
comment|/* Random number generator config register (HIFN_1_RNG_CONFIG) */
end_comment

begin_define
define|#
directive|define
name|HIFN_RNGCFG_ENA
value|0x00000001
end_define

begin_comment
comment|/* enable rng */
end_comment

begin_comment
comment|/*  * Register offsets in register set 1  */
end_comment

begin_define
define|#
directive|define
name|HIFN_UNLOCK_SECRET1
value|0xf4
end_define

begin_define
define|#
directive|define
name|HIFN_UNLOCK_SECRET2
value|0xfc
end_define

begin_comment
comment|/*  * PLL config register  *  * This register is present only on 7954/7955/7956 parts. It must be  * programmed according to the bus interface method used by the h/w.  * Note that the parts require a stable clock.  Since the PCI clock  * may vary the reference clock must usually be used.  To avoid  * overclocking the core logic, setup must be done carefully, refer  * to the driver for details.  The exact multiplier required varies  * by part and system configuration; refer to the Hifn documentation.  */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_REF_SEL
value|0x00000001
end_define

begin_comment
comment|/* REF/HBI clk selection */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_BP
value|0x00000002
end_define

begin_comment
comment|/* bypass (used during setup) */
end_comment

begin_comment
comment|/* bit 2 reserved */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_PK_CLK_SEL
value|0x00000008
end_define

begin_comment
comment|/* public key clk select */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_PE_CLK_SEL
value|0x00000010
end_define

begin_comment
comment|/* packet engine clk select */
end_comment

begin_comment
comment|/* bits 5-9 reserved */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_MBSET
value|0x00000400
end_define

begin_comment
comment|/* must be set to 1 */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND
value|0x00003800
end_define

begin_comment
comment|/* Fpll_ref multiplier select */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|HIFN_PLL_ND_2
value|0x00000000
end_define

begin_comment
comment|/* 2x */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_4
value|0x00000800
end_define

begin_comment
comment|/* 4x */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_6
value|0x00001000
end_define

begin_comment
comment|/* 6x */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_8
value|0x00001800
end_define

begin_comment
comment|/* 8x */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_10
value|0x00002000
end_define

begin_comment
comment|/* 10x */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_ND_12
value|0x00002800
end_define

begin_comment
comment|/* 12x */
end_comment

begin_comment
comment|/* bits 14-15 reserved */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_IS
value|0x00010000
end_define

begin_comment
comment|/* charge pump current select */
end_comment

begin_comment
comment|/* bits 17-31 reserved */
end_comment

begin_comment
comment|/*  * Board configuration specifies only these bits.  */
end_comment

begin_define
define|#
directive|define
name|HIFN_PLL_CONFIG
value|(HIFN_PLL_IS|HIFN_PLL_ND|HIFN_PLL_REF_SEL)
end_define

begin_comment
comment|/*  * Public Key Engine Mode Register  */
end_comment

begin_define
define|#
directive|define
name|HIFN_PKMODE_HOSTINVERT
value|(1<< 0)
end_define

begin_comment
comment|/* HOST INVERT */
end_comment

begin_define
define|#
directive|define
name|HIFN_PKMODE_ENHANCED
value|(1<< 1)
end_define

begin_comment
comment|/* Enable enhanced mode */
end_comment

begin_comment
comment|/*********************************************************************  * Structs for board commands   *  *********************************************************************/
end_comment

begin_comment
comment|/*  * Structure to help build up the command data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hifn_base_command
block|{
specifier|volatile
name|u_int16_t
name|masks
decl_stmt|;
specifier|volatile
name|u_int16_t
name|session_num
decl_stmt|;
specifier|volatile
name|u_int16_t
name|total_source_count
decl_stmt|;
specifier|volatile
name|u_int16_t
name|total_dest_count
decl_stmt|;
block|}
name|hifn_base_command_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_MAC
value|0x0400
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_CRYPT
value|0x0800
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_DECODE
value|0x2000
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_SRCLEN_M
value|0xc000
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_SRCLEN_S
value|14
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_DSTLEN_M
value|0x3000
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_DSTLEN_S
value|12
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_LENMASK_HI
value|0x30000
end_define

begin_define
define|#
directive|define
name|HIFN_BASE_CMD_LENMASK_LO
value|0x0ffff
end_define

begin_comment
comment|/*  * Structure to help build up the command data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hifn_crypt_command
block|{
specifier|volatile
name|u_int16_t
name|masks
decl_stmt|;
specifier|volatile
name|u_int16_t
name|header_skip
decl_stmt|;
specifier|volatile
name|u_int16_t
name|source_count
decl_stmt|;
specifier|volatile
name|u_int16_t
name|reserved
decl_stmt|;
block|}
name|hifn_crypt_command_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_ALG_MASK
value|0x0003
end_define

begin_comment
comment|/* algorithm: */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_ALG_DES
value|0x0000
end_define

begin_comment
comment|/*   DES */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_ALG_3DES
value|0x0001
end_define

begin_comment
comment|/*   3DES */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_ALG_RC4
value|0x0002
end_define

begin_comment
comment|/*   RC4 */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_ALG_AES
value|0x0003
end_define

begin_comment
comment|/*   AES */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_MODE_MASK
value|0x0018
end_define

begin_comment
comment|/* Encrypt mode: */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_MODE_ECB
value|0x0000
end_define

begin_comment
comment|/*   ECB */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_MODE_CBC
value|0x0008
end_define

begin_comment
comment|/*   CBC */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_MODE_CFB
value|0x0010
end_define

begin_comment
comment|/*   CFB */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_MODE_OFB
value|0x0018
end_define

begin_comment
comment|/*   OFB */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_CLR_CTX
value|0x0040
end_define

begin_comment
comment|/* clear context */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_NEW_KEY
value|0x0800
end_define

begin_comment
comment|/* expect new key */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_NEW_IV
value|0x1000
end_define

begin_comment
comment|/* expect new iv */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_SRCLEN_M
value|0xc000
end_define

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_SRCLEN_S
value|14
end_define

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_KSZ_MASK
value|0x0600
end_define

begin_comment
comment|/* AES key size: */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_KSZ_128
value|0x0000
end_define

begin_comment
comment|/*   128 bit */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_KSZ_192
value|0x0200
end_define

begin_comment
comment|/*   192 bit */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPT_CMD_KSZ_256
value|0x0400
end_define

begin_comment
comment|/*   256 bit */
end_comment

begin_comment
comment|/*  * Structure to help build up the command data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hifn_mac_command
block|{
specifier|volatile
name|u_int16_t
name|masks
decl_stmt|;
specifier|volatile
name|u_int16_t
name|header_skip
decl_stmt|;
specifier|volatile
name|u_int16_t
name|source_count
decl_stmt|;
specifier|volatile
name|u_int16_t
name|reserved
decl_stmt|;
block|}
name|hifn_mac_command_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_ALG_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_ALG_SHA1
value|0x0000
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_ALG_MD5
value|0x0001
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_MODE_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_MODE_HMAC
value|0x0000
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_MODE_SSL_MAC
value|0x0004
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_MODE_HASH
value|0x0008
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_MODE_FULL
value|0x0004
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_TRUNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_RESULT
value|0x0020
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_APPEND
value|0x0040
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_SRCLEN_M
value|0xc000
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_SRCLEN_S
value|14
end_define

begin_comment
comment|/*  * MAC POS IPsec initiates authentication after encryption on encodes  * and before decryption on decodes.  */
end_comment

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_POS_IPSEC
value|0x0200
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_CMD_NEW_KEY
value|0x0800
end_define

begin_comment
comment|/*  * The poll frequency and poll scalar defines are unshifted values used  * to set fields in the DMA Configuration Register.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HIFN_POLL_FREQUENCY
end_ifndef

begin_define
define|#
directive|define
name|HIFN_POLL_FREQUENCY
value|0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HIFN_POLL_SCALAR
end_ifndef

begin_define
define|#
directive|define
name|HIFN_POLL_SCALAR
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HIFN_MAX_SEGLEN
value|0xffff
end_define

begin_comment
comment|/* maximum dma segment len */
end_comment

begin_define
define|#
directive|define
name|HIFN_MAX_DMALEN
value|0x3ffff
end_define

begin_comment
comment|/* maximum dma length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HIFN_H__ */
end_comment

end_unit

