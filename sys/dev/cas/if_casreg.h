begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Eduardo Horvath.  * Copyright (c) 2008 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: gemreg.h,v 1.8 2005/12/11 12:21:26 christos Exp  *	from: FreeBSD: if_gemreg.h 174987 2007-12-30 01:32:03Z marius  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CASREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CASREG_H
end_define

begin_comment
comment|/*  * register definitions for Sun Cassini/Cassini+ and National Semiconductor  * DP83065 Saturn Gigabit Ethernet controllers  */
end_comment

begin_comment
comment|/* global resources */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW
value|0x0004
end_define

begin_comment
comment|/* core arbitration weight */
end_comment

begin_define
define|#
directive|define
name|CAS_INF_BURST
value|0x0008
end_define

begin_comment
comment|/* infinite burst enable */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS
value|0x000c
end_define

begin_comment
comment|/* interrupt status */
end_comment

begin_define
define|#
directive|define
name|CAS_INTMASK
value|0x0010
end_define

begin_comment
comment|/* interrupt mask */
end_comment

begin_define
define|#
directive|define
name|CAS_CLEAR_ALIAS
value|0x0014
end_define

begin_comment
comment|/* clear mask alias */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_ALIAS
value|0x001c
end_define

begin_comment
comment|/* interrupt status alias */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_STATUS
value|0x1000
end_define

begin_comment
comment|/* PCI error status */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_MASK
value|0x1004
end_define

begin_comment
comment|/* PCI error mask */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF
value|0x1008
end_define

begin_comment
comment|/* BIM configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_DIAG
value|0x100c
end_define

begin_comment
comment|/* BIM diagnostic */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET
value|0x1010
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN
value|0x1020
end_define

begin_comment
comment|/* BIM local device output enable */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_BUF_ADDR
value|0x1024
end_define

begin_comment
comment|/* BIM buffer address */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_BUF_DATA_LO
value|0x1028
end_define

begin_comment
comment|/* BIM buffer data low */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_BUF_DATA_HI
value|0x102c
end_define

begin_comment
comment|/* BIM buffer data high */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_RAM_BIST
value|0x1030
end_define

begin_comment
comment|/* BIM RAM BIST control/status */
end_comment

begin_define
define|#
directive|define
name|CAS_PROBE_MUX_SELECT
value|0x1034
end_define

begin_comment
comment|/* PROBE MUX SELECT */
end_comment

begin_define
define|#
directive|define
name|CAS_INTMASK2
value|0x1038
end_define

begin_comment
comment|/* interrupt mask 2 for INTB */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS2
value|0x103c
end_define

begin_comment
comment|/* interrupt status 2 for INTB */
end_comment

begin_define
define|#
directive|define
name|CAS_CLEAR_ALIAS2
value|0x1040
end_define

begin_comment
comment|/* clear mask alias 2 for INTB */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_ALIAS2
value|0x1044
end_define

begin_comment
comment|/* interrupt status alias 2 for INTB */
end_comment

begin_define
define|#
directive|define
name|CAS_INTMASK3
value|0x1048
end_define

begin_comment
comment|/* interrupt mask 3 for INTC */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS3
value|0x104c
end_define

begin_comment
comment|/* interrupt status 3 for INTC */
end_comment

begin_define
define|#
directive|define
name|CAS_CLEAR_ALIAS3
value|0x1050
end_define

begin_comment
comment|/* clear mask alias 3 for INTC */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_ALIAS3
value|0x1054
end_define

begin_comment
comment|/* interrupt status alias 3 for INTC */
end_comment

begin_define
define|#
directive|define
name|CAS_INTMASK4
value|0x1058
end_define

begin_comment
comment|/* interrupt mask 4 for INTD */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS4
value|0x105c
end_define

begin_comment
comment|/* interrupt status 4 for INTD */
end_comment

begin_define
define|#
directive|define
name|CAS_CLEAR_ALIAS4
value|0x1060
end_define

begin_comment
comment|/* clear mask alias 4 for INTD */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_ALIAS4
value|0x1064
end_define

begin_comment
comment|/* interrupt status alias 4 for INTD */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW_RX_WGHT_MASK
value|0x00000003
end_define

begin_comment
comment|/* RX DMA factor for... */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW_RX_WGHT_SHFT
value|0
end_define

begin_comment
comment|/* ...weighted round robin */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW_TX_WGHT_MASK
value|0x0000000c
end_define

begin_comment
comment|/* RX DMA factor for... */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW_TX_WGHT_SHFT
value|2
end_define

begin_comment
comment|/* ...weighted round robin */
end_comment

begin_define
define|#
directive|define
name|CAS_CAW_RR_DIS
value|0x00000010
end_define

begin_comment
comment|/* weighted round robin dis. */
end_comment

begin_define
define|#
directive|define
name|CAS_INF_BURST_EN
value|0x00000001
end_define

begin_comment
comment|/* Allow bursts> cachline. */
end_comment

begin_comment
comment|/*  * shared interrupt bits for CAS_STATUS, CAS_INTMASK, CAS_CLEAR_ALIAS and  * CAS_STATUS_ALIAS  * Bits 0-9 of CAS_STATUS auto-clear when read.  CAS_CLEAR_ALIAS specifies  * which of bits 0-9 auto-clear when reading CAS_STATUS_ALIAS.  */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_TX_INT_ME
value|0x00000001
end_define

begin_comment
comment|/* Frame w/ INT_ME set sent. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_TX_ALL
value|0x00000002
end_define

begin_comment
comment|/* TX frames trans. to FIFO. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_TX_DONE
value|0x00000004
end_define

begin_comment
comment|/* Any TX frame transferred. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_TX_TAG_ERR
value|0x00000008
end_define

begin_comment
comment|/* TX FIFO tag corrupted. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_DONE
value|0x00000010
end_define

begin_comment
comment|/*>=1 RX frames transferred. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_BUF_NA
value|0x00000020
end_define

begin_comment
comment|/* RX buffer not available */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_TAG_ERR
value|0x00000040
end_define

begin_comment
comment|/* RX FIFO tag corrupted. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_COMP_FULL
value|0x00000080
end_define

begin_comment
comment|/* RX completion ring full */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_BUF_AEMPTY
value|0x00000100
end_define

begin_comment
comment|/* RX desc. ring almost empty */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_COMP_AFULL
value|0x00000200
end_define

begin_comment
comment|/* RX cmpl. ring almost full */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_LEN_MMATCH
value|0x00000400
end_define

begin_comment
comment|/* length field mismatch */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_SUMMARY
value|0x00001000
end_define

begin_comment
comment|/* summary interrupt bit */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_PCS_INT
value|0x00002000
end_define

begin_comment
comment|/* PCS interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_TX_MAC_INT
value|0x00004000
end_define

begin_comment
comment|/* TX MAC interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_RX_MAC_INT
value|0x00008000
end_define

begin_comment
comment|/* RX MAC interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_MAC_CTRL_INT
value|0x00010000
end_define

begin_comment
comment|/* MAC control interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_MIF
value|0x00020000
end_define

begin_comment
comment|/* MIF interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_INTR_PCI_ERROR_INT
value|0x00040000
end_define

begin_comment
comment|/* PCI error interrupt */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_TX_COMP3_MASK
value|0xfff80000
end_define

begin_comment
comment|/* TX completion 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_STATUS_TX_COMP3_SHFT
value|19
end_define

begin_comment
comment|/* CAS_ERROR_STATUS and CAS_ERROR_MASK PCI error bits */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_DTRTO
value|0x00000002
end_define

begin_comment
comment|/* delayed trans. timeout */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_OTHER
value|0x00000004
end_define

begin_comment
comment|/* errors (see PCIR_STATUS) */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_DMAW_ZERO
value|0x00000008
end_define

begin_comment
comment|/* zero count DMA write */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_DMAR_ZERO
value|0x00000010
end_define

begin_comment
comment|/* zero count DMA read */
end_comment

begin_define
define|#
directive|define
name|CAS_ERROR_RTRTO
value|0x00000020
end_define

begin_comment
comment|/* 255 retries exceeded */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_BD64_DIS
value|0x00000004
end_define

begin_comment
comment|/* 64-bit mode disable */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_M66EN
value|0x00000008
end_define

begin_comment
comment|/* PCI clock is 66MHz (ro). */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_BUS32_WIDE
value|0x00000010
end_define

begin_comment
comment|/* PCI bus is 32-bit (ro). */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_DPAR_EN
value|0x00000020
end_define

begin_comment
comment|/* parity error intr. enable */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_RMA_EN
value|0x00000040
end_define

begin_comment
comment|/* master abort intr. enable */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_RTA_EN
value|0x00000080
end_define

begin_comment
comment|/* target abort intr. enable */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_DIS_BIM
value|0x00000200
end_define

begin_comment
comment|/* Stop PCI DMA transactions. */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_BIM_DIS
value|0x00000400
end_define

begin_comment
comment|/* BIM was stopped (ro). */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_CONF_BLOCK_PERR
value|0x00000800
end_define

begin_comment
comment|/* Block PERR# to PCI bus. */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_DIAG_BRST_SM
value|0x0000007f
end_define

begin_comment
comment|/* burst ctrl. state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_DIAG_MSTR_SM
value|0x3fffff00
end_define

begin_define
define|#
directive|define
name|CAS_RESET_TX
value|0x00000001
end_define

begin_comment
comment|/* Reset TX DMA engine. */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_RX
value|0x00000002
end_define

begin_comment
comment|/* Reset RX DMA engine. */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_RSTOUT
value|0x00000004
end_define

begin_comment
comment|/* Force PCI RSTOUT#. */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_PCS_DIS
value|0x00000008
end_define

begin_comment
comment|/* PCS reset disable */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_BREQ_SM
value|0x00007f00
end_define

begin_comment
comment|/* breq state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_PCIARB
value|0x00070000
end_define

begin_comment
comment|/* PCI arbitration state */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_RDPCI
value|0x00300000
end_define

begin_comment
comment|/* read PCI state */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_RDARB
value|0x00c00000
end_define

begin_comment
comment|/* read arbitration state */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_WRPCI
value|0x06000000
end_define

begin_comment
comment|/* write PCI state */
end_comment

begin_define
define|#
directive|define
name|CAS_RESET_WRARB
value|0x38000000
end_define

begin_comment
comment|/* write arbitration state */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_PAD
value|0x00000001
end_define

begin_comment
comment|/* addr. bus, RW and OE */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_PROM
value|0x00000002
end_define

begin_comment
comment|/* PROM chip select */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_EXT
value|0x00000004
end_define

begin_comment
comment|/* secondary local bus device */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_SOFT_0
value|0x00000008
end_define

begin_comment
comment|/* soft. progr. ctrl. bit 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_SOFT_1
value|0x00000010
end_define

begin_comment
comment|/* soft. progr. ctrl. bit 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_LDEV_OEN_HWRST
value|0x00000020
end_define

begin_comment
comment|/* hw. reset (Cassini+ only) */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_BUF_ADDR_INDEX
value|0x0000003f
end_define

begin_comment
comment|/* buffer entry index */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_BUF_ADDR_RDWR
value|0x00000040
end_define

begin_comment
comment|/* 0: read, 1: write access */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_RAM_BIST_START
value|0x00000001
end_define

begin_comment
comment|/* Start BIST on read buffer. */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_RAM_BIST_SUM
value|0x00000004
end_define

begin_comment
comment|/* read buffer pass summary */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_RAM_BIST_LO
value|0x00000010
end_define

begin_comment
comment|/* read buf. low bank passes */
end_comment

begin_define
define|#
directive|define
name|CAS_BIM_RAM_BIST_HI
value|0x00000020
end_define

begin_comment
comment|/* read buf. high bank passes */
end_comment

begin_define
define|#
directive|define
name|CAS_PROBE_MUX_SELECT_LO
value|0x0000000f
end_define

begin_comment
comment|/* P_A[7:0] */
end_comment

begin_define
define|#
directive|define
name|CAS_PROBE_MUX_SELECT_HI
value|0x000000f0
end_define

begin_comment
comment|/* P_A[15:8] */
end_comment

begin_define
define|#
directive|define
name|CAS_PROBE_MUX_SELECT_SB
value|0x000000f0
end_define

begin_comment
comment|/* txdma_wr address and size */
end_comment

begin_define
define|#
directive|define
name|CAS_PROBE_MUX_SELECT_EN
value|0xf0000000
end_define

begin_comment
comment|/* enable probe on P_A[15:0] */
end_comment

begin_comment
comment|/*  * interrupt bits for CAS_INTMASK[2-4], CAS_STATUS[2-4], CAS_CLEAR_ALIAS[2-4]  * and CAS_STATUS_ALIAS[2-4].  * CAS_STATUS[2-4] auto-clear when read.  CAS_CLEAR_ALIAS[2-4] specifies which  * of bits 0-9 auto-clear when reading the corresponding CAS_STATUS_ALIAS[2-4].  */
end_comment

begin_define
define|#
directive|define
name|CAS_INTRN_RX_DONE
value|0x00000001
end_define

begin_comment
comment|/*>=1 RX frames transferred. */
end_comment

begin_define
define|#
directive|define
name|CAS_INTRN_RX_COMP_FULL
value|0x00000002
end_define

begin_comment
comment|/* RX completion ring full */
end_comment

begin_define
define|#
directive|define
name|CAS_INTRN_RX_COMP_AFULL
value|0x00000004
end_define

begin_comment
comment|/* RX cmpl. ring almost full */
end_comment

begin_define
define|#
directive|define
name|CAS_INTRN_RX_BUF_NA
value|0x00000008
end_define

begin_comment
comment|/* RX buffer not available */
end_comment

begin_define
define|#
directive|define
name|CAS_INTRN_RX_BUF_AEMPTY
value|0x00000010
end_define

begin_comment
comment|/* RX desc. ring almost empty */
end_comment

begin_comment
comment|/* INTn enable bit for CAS_INTMASK[2-4] */
end_comment

begin_define
define|#
directive|define
name|CAS_INTMASKN_EN
value|0x00000080
end_define

begin_comment
comment|/* INT[B-D] enable */
end_comment

begin_comment
comment|/* TX DMA registers */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF
value|0x2004
end_define

begin_comment
comment|/* TX configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_WR
value|0x2014
end_define

begin_comment
comment|/* FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_SDWR
value|0x2018
end_define

begin_comment
comment|/* FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_RD
value|0x201c
end_define

begin_comment
comment|/* FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_SDRD
value|0x2020
end_define

begin_comment
comment|/* FIFO shadow read pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_PKT_CNT
value|0x2024
end_define

begin_comment
comment|/* FIFO packet counter */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1
value|0x2028
end_define

begin_comment
comment|/* TX state machine 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM2
value|0x202c
end_define

begin_comment
comment|/* TX state machine 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DATA_PTR_LO
value|0x2030
end_define

begin_comment
comment|/* TX data pointer low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DATA_PTR_HI
value|0x2034
end_define

begin_comment
comment|/* TX data pointer high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_KICK1
value|0x2038
end_define

begin_comment
comment|/* TX kick 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_KICK2
value|0x203c
end_define

begin_comment
comment|/* TX kick 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_KICK3
value|0x2040
end_define

begin_comment
comment|/* TX kick 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_KICK4
value|0x2044
end_define

begin_comment
comment|/* TX kick 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMP1
value|0x2048
end_define

begin_comment
comment|/* TX completion 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMP2
value|0x204c
end_define

begin_comment
comment|/* TX completion 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMP3
value|0x2050
end_define

begin_comment
comment|/* TX completion 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMP4
value|0x2054
end_define

begin_comment
comment|/* TX completion 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMPWB_BASE_LO
value|0x2058
end_define

begin_comment
comment|/* TX completion writeback base low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_COMPWB_BASE_HI
value|0x205c
end_define

begin_comment
comment|/* TX completion writeback base high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC1_BASE_LO
value|0x2060
end_define

begin_comment
comment|/* TX descriptor ring 1 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC1_BASE_HI
value|0x2064
end_define

begin_comment
comment|/* TX descriptor ring 1 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC2_BASE_LO
value|0x2068
end_define

begin_comment
comment|/* TX descriptor ring 2 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC2_BASE_HI
value|0x206c
end_define

begin_comment
comment|/* TX descriptor ring 2 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC3_BASE_LO
value|0x2070
end_define

begin_comment
comment|/* TX descriptor ring 2 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC3_BASE_HI
value|0x2074
end_define

begin_comment
comment|/* TX descriptor ring 2 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC4_BASE_LO
value|0x2078
end_define

begin_comment
comment|/* TX descriptor ring 2 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC4_BASE_HI
value|0x207c
end_define

begin_comment
comment|/* TX descriptor ring 2 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_MAXBURST1
value|0x2080
end_define

begin_comment
comment|/* TX MaxBurst 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_MAXBURST2
value|0x2084
end_define

begin_comment
comment|/* TX MaxBurst 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_MAXBURST3
value|0x2088
end_define

begin_comment
comment|/* TX MaxBurst 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_MAXBURST4
value|0x208c
end_define

begin_comment
comment|/* TX MaxBurst 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_ADDR
value|0x2104
end_define

begin_comment
comment|/* TX FIFO address */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_TAG
value|0x2108
end_define

begin_comment
comment|/* TX FIFO tag */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_DATA_LO
value|0x210c
end_define

begin_comment
comment|/* TX FIFO data low */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_DATA_HI_T1
value|0x2110
end_define

begin_comment
comment|/* TX FIFO data highT1 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_DATA_HI_T0
value|0x2114
end_define

begin_comment
comment|/* TX FIFO data highT0 */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_FIFO_SIZE
value|0x2118
end_define

begin_comment
comment|/* TX FIFO size in 64 byte multiples */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST
value|0x211c
end_define

begin_comment
comment|/* TX RAM BIST control/status */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_TXDMA_EN
value|0x00000001
end_define

begin_comment
comment|/* TX DMA enable */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_FIFO_PIO
value|0x00000002
end_define

begin_comment
comment|/* Allow TX FIFO PIO access. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC1_MASK
value|0x0000003c
end_define

begin_comment
comment|/* TX descriptor ring 1 size */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC1_SHFT
value|2
end_define

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC2_MASK
value|0x000003c0
end_define

begin_comment
comment|/* TX descriptor ring 2 size */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC2_SHFT
value|6
end_define

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC3_MASK
value|0x00003c00
end_define

begin_comment
comment|/* TX descriptor ring 3 size */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC3_SHFT
value|10
end_define

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC4_MASK
value|0x0003c000
end_define

begin_comment
comment|/* TX descriptor ring 4 size */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_DESC4_SHFT
value|14
end_define

begin_define
define|#
directive|define
name|CAS_TX_CONF_PACED
value|0x00100000
end_define

begin_comment
comment|/* ALL intr. on FIFO empty */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_RDPP_DIS
value|0x01000000
end_define

begin_comment
comment|/* Should always be set. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_COMPWB_Q1
value|0x02000000
end_define

begin_comment
comment|/* Completion writeback... */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_COMPWB_Q2
value|0x04000000
end_define

begin_comment
comment|/* ...happens at the end... */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_COMPWB_Q3
value|0x08000000
end_define

begin_comment
comment|/* ...of every packet in... */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_COMPWB_Q4
value|0x10000000
end_define

begin_comment
comment|/* ...queue n. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_PICWB_DIS
value|0x20000000
end_define

begin_comment
comment|/* pre-intr. compl. W/B dis. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_CTX_MASK
value|0xc0000000
end_define

begin_comment
comment|/* test port selection */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_CONF_CTX_SHFT
value|30
end_define

begin_define
define|#
directive|define
name|CAS_TX_COMPWB_ALIGN
value|2048
end_define

begin_comment
comment|/* TX compl. W/B alignment */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_DESC_ALIGN
value|2048
end_define

begin_comment
comment|/* TX descriptor alignment */
end_comment

begin_comment
comment|/* descriptor ring size bits for both CAS_TX_CONF and CAS_RX_CONF */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_32
value|0x0
end_define

begin_comment
comment|/* 32 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_64
value|0x1
end_define

begin_comment
comment|/* 64 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_128
value|0x2
end_define

begin_comment
comment|/* 128 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_256
value|0x3
end_define

begin_comment
comment|/* 256 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_512
value|0x4
end_define

begin_comment
comment|/* 512 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_1K
value|0x5
end_define

begin_comment
comment|/* 1k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_2K
value|0x6
end_define

begin_comment
comment|/* 2k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_4K
value|0x7
end_define

begin_comment
comment|/* 4k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_DESC_8K
value|0x8
end_define

begin_comment
comment|/* 8k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_CHAIN
value|0x000003ff
end_define

begin_comment
comment|/* chaining state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_CKSUM
value|0x00000c00
end_define

begin_comment
comment|/* checksum state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_TX_FIFO_LOAD
value|0x0003f000
end_define

begin_comment
comment|/* TX FIFO load state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_TX_FIFO_UNLD
value|0x003c0000
end_define

begin_comment
comment|/* TX FIFO unload state mach. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_CACHE_CTRL
value|0x03c00000
end_define

begin_comment
comment|/* cache control state mach. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM1_CBQARB
value|0x03c00000
end_define

begin_comment
comment|/* CBQ arbiter state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM2_COMPWB
value|0x00000007
end_define

begin_comment
comment|/* compl. WB state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM2_SUB_LOAD
value|0x00000038
end_define

begin_comment
comment|/* sub load state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_SM2_KICK
value|0x000000c0
end_define

begin_comment
comment|/* kick state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_START
value|0x00000001
end_define

begin_comment
comment|/* Start RAM BIST process. */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_SUMMARY
value|0x00000002
end_define

begin_comment
comment|/* All RAM okay */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_RAM32B
value|0x00000004
end_define

begin_comment
comment|/* RAM32B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_RAM33B
value|0x00000008
end_define

begin_comment
comment|/* RAM33B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_RAM32A
value|0x00000010
end_define

begin_comment
comment|/* RAM32A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_RAM33A
value|0x00000020
end_define

begin_comment
comment|/* RAM33A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_TX_RAM_BIST_SM
value|0x000001c0
end_define

begin_comment
comment|/* RAM BIST state machine */
end_comment

begin_comment
comment|/* RX DMA registers */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF
value|0x4000
end_define

begin_comment
comment|/* RX configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ
value|0x4004
end_define

begin_comment
comment|/* RX page size */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_WR
value|0x4008
end_define

begin_comment
comment|/* RX FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_RD
value|0x400c
end_define

begin_comment
comment|/* RX FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_WR
value|0x4010
end_define

begin_comment
comment|/* RX IPP FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_SDWR
value|0x4014
end_define

begin_comment
comment|/* RX IPP FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_RD
value|0x4018
end_define

begin_comment
comment|/* RX IPP FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DEBUG
value|0x401c
end_define

begin_comment
comment|/* RX debug */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PTHRS
value|0x4020
end_define

begin_comment
comment|/* RX PAUSE threshold */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_KICK
value|0x4024
end_define

begin_comment
comment|/* RX kick */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DESC_BASE_LO
value|0x4028
end_define

begin_comment
comment|/* RX descriptor ring base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DESC_BASE_HI
value|0x402c
end_define

begin_comment
comment|/* RX descriptor ring base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_BASE_LO
value|0x4030
end_define

begin_comment
comment|/* RX completion ring base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_BASE_HI
value|0x4034
end_define

begin_comment
comment|/* RX completion ring base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP
value|0x4038
end_define

begin_comment
comment|/* RX completion */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_HEAD
value|0x403c
end_define

begin_comment
comment|/* RX completion head */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_TAIL
value|0x4040
end_define

begin_comment
comment|/* RX completion tail */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BLANK
value|0x4044
end_define

begin_comment
comment|/* RX blanking for ISR read */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_THRS
value|0x4048
end_define

begin_comment
comment|/* RX almost empty threshold */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED
value|0x4048
end_define

begin_comment
comment|/* RX random early detection enable */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FF
value|0x4050
end_define

begin_comment
comment|/* RX FIFO fullness */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_PKT_CNT
value|0x4054
end_define

begin_comment
comment|/* RX IPP packet counter */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_WORKING_DMA_LO
value|0x4058
end_define

begin_comment
comment|/* RX working DMA pointer low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_WORKING_DMA_HI
value|0x405c
end_define

begin_comment
comment|/* RX working DMA pointer high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST
value|0x4060
end_define

begin_comment
comment|/* RX BIST */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO_WR
value|0x4064
end_define

begin_comment
comment|/* RX control FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO_RD
value|0x4068
end_define

begin_comment
comment|/* RX control FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BLANK_ALIAS
value|0x406c
end_define

begin_comment
comment|/* RX blanking for ISR read alias */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_ADDR
value|0x4080
end_define

begin_comment
comment|/* RX FIFO address */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_TAG
value|0x4084
end_define

begin_comment
comment|/* RX FIFO tag */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_DATA_LO
value|0x4088
end_define

begin_comment
comment|/* RX FIFO data low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_DATA_HI_T0
value|0x408c
end_define

begin_comment
comment|/* RX FIFO data highT0 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_DATA_HI_T1
value|0x4090
end_define

begin_comment
comment|/* RX FIFO data highT1 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO
value|0x4094
end_define

begin_comment
comment|/* RX control FIFO and batching FIFO */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO_LO
value|0x4098
end_define

begin_comment
comment|/* RX control FIFO data low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO_MD
value|0x409c
end_define

begin_comment
comment|/* RX control FIFO data mid */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CTRL_FIFO_HI
value|0x4100
end_define

begin_comment
comment|/* RX control FIFO data high, flowID */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_ADDR
value|0x4104
end_define

begin_comment
comment|/* RX IPP FIFO address */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_TAG
value|0x4108
end_define

begin_comment
comment|/* RX IPP FIFO tag */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_DATA_LO
value|0x410c
end_define

begin_comment
comment|/* RX IPP FIFO data low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_DATA_HI_T0
value|0x4110
end_define

begin_comment
comment|/* RX IPP FIFO data highT0 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_IPP_DATA_HI_T1
value|0x4114
end_define

begin_comment
comment|/* RX IPP FIFO data highT1 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_HDR_PAGE_LO
value|0x4118
end_define

begin_comment
comment|/* RX header page pointer low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_HDR_PAGE_HIGH
value|0x411c
end_define

begin_comment
comment|/* RX header page pointer high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_MTU_PAGE_LO
value|0x4120
end_define

begin_comment
comment|/* RX MTU page pointer low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_MTU_PAGE_HIGH
value|0x4124
end_define

begin_comment
comment|/* RX MTU page pointer high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_REAS_DMA_ADDR
value|0x4128
end_define

begin_comment
comment|/* RX reassembly DMA table address */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_REAS_DMA_DATA_LO
value|0x412c
end_define

begin_comment
comment|/* RX reassembly DMA table data low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_REAS_DMA_DATA_MD
value|0x4130
end_define

begin_comment
comment|/* RX reassembly DMA table data mid */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_REAS_DMA_DATA_HI
value|0x4134
end_define

begin_comment
comment|/* RX reassembly DMA table data high */
end_comment

begin_comment
comment|/* The rest of the RX DMA registers are Cassini+/Saturn only. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DESC2_BASE_LO
value|0x4200
end_define

begin_comment
comment|/* RX descriptor ring 2 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DESC2_BASE_HI
value|0x4204
end_define

begin_comment
comment|/* RX descriptor ring 2 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP2_BASE_LO
value|0x4208
end_define

begin_comment
comment|/* RX completion ring 2 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP2_BASE_HI
value|0x420c
end_define

begin_comment
comment|/* RX completion ring 2 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP3_BASE_LO
value|0x4210
end_define

begin_comment
comment|/* RX completion ring 3 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP3_BASE_HI
value|0x4214
end_define

begin_comment
comment|/* RX completion ring 3 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP4_BASE_LO
value|0x4218
end_define

begin_comment
comment|/* RX completion ring 4 base low */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP4_BASE_HI
value|0x421c
end_define

begin_comment
comment|/* RX completion ring 4 base high */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_KICK2
value|0x4220
end_define

begin_comment
comment|/* RX kick 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP2
value|0x4224
end_define

begin_comment
comment|/* RX completion 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_HEAD2
value|0x4228
end_define

begin_comment
comment|/* RX completion head 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_TAIL2
value|0x422c
end_define

begin_comment
comment|/* RX completion tail 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_HEAD3
value|0x4230
end_define

begin_comment
comment|/* RX completion head 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_TAIL3
value|0x4234
end_define

begin_comment
comment|/* RX completion tail 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_HEAD4
value|0x4238
end_define

begin_comment
comment|/* RX completion head 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_TAIL4
value|0x423c
end_define

begin_comment
comment|/* RX completion tail 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_THRS2
value|0x4048
end_define

begin_comment
comment|/* RX almost empty threshold 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_RXDMA_EN
value|0x00000001
end_define

begin_comment
comment|/* RX DMA enable */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_DESC_MASK
value|0x0000001e
end_define

begin_comment
comment|/* RX descriptor ring size */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_DESC_SHFT
value|1
end_define

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_MASK
value|0x000001e0
end_define

begin_comment
comment|/* RX complition ring size */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_SHFT
value|5
end_define

begin_define
define|#
directive|define
name|CAS_RX_CONF_BATCH_DIS
value|0x00000200
end_define

begin_comment
comment|/* descriptor batching dis. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_SOFF_MASK
value|0x00001c00
end_define

begin_comment
comment|/* swivel offset */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_SOFF_SHFT
value|10
end_define

begin_comment
comment|/* The RX descriptor ring 2 is Cassini+/Saturn only. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_DESC2_MASK
value|0x000f0000
end_define

begin_comment
comment|/* RX descriptor ring 2 size */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_DESC2_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_128
value|0x0
end_define

begin_comment
comment|/* 128 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_256
value|0x1
end_define

begin_comment
comment|/* 256 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_512
value|0x2
end_define

begin_comment
comment|/* 512 descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_1K
value|0x3
end_define

begin_comment
comment|/* 1k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_2K
value|0x4
end_define

begin_comment
comment|/* 2k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_4K
value|0x5
end_define

begin_comment
comment|/* 4k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_8K
value|0x6
end_define

begin_comment
comment|/* 8k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_16K
value|0x7
end_define

begin_comment
comment|/* 16k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_CONF_COMP_32K
value|0x8
end_define

begin_comment
comment|/* 32k descriptors */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MASK
value|0x00000003
end_define

begin_comment
comment|/* RX page size */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_CNT_MASK
value|0x00007800
end_define

begin_comment
comment|/* number of MTU buffers */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_CNT_SHFT
value|11
end_define

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_MASK
value|0x18000000
end_define

begin_comment
comment|/* MTU buffer stride */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_SHFT
value|27
end_define

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_MASK
value|0xc0000000
end_define

begin_comment
comment|/* MTU buffer offset */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_SHFT
value|30
end_define

begin_define
define|#
directive|define
name|CAS_RX_PSZ_2K
value|0x0
end_define

begin_comment
comment|/* page size 2Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_4K
value|0x1
end_define

begin_comment
comment|/* page size 4Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_8K
value|0x2
end_define

begin_comment
comment|/* page size 8Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_16K
value|0x3
end_define

begin_comment
comment|/* page size 16Kbyte*/
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_1K
value|0x0
end_define

begin_comment
comment|/* MTU buffer stride 1Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_2K
value|0x1
end_define

begin_comment
comment|/* MTU buffer stride 2Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_4K
value|0x2
end_define

begin_comment
comment|/* MTU buffer stride 4Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_STRD_8K
value|0x3
end_define

begin_comment
comment|/* MTU buffer stride 8Kbyte */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_0
value|0x0
end_define

begin_comment
comment|/* MTU buf. offset 0 bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_64
value|0x1
end_define

begin_comment
comment|/* MTU buf. offset 64 bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_96
value|0x2
end_define

begin_comment
comment|/* MTU buf. offset 96 bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PSZ_MB_OFF_128
value|0x3
end_define

begin_comment
comment|/* MTU buf. offset 128 bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_DESC_ALIGN
value|8192
end_define

begin_comment
comment|/* RX descriptor alignment */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_COMP_ALIGN
value|8192
end_define

begin_comment
comment|/* RX complition alignment */
end_comment

begin_comment
comment|/* The RX PAUSE thresholds are specified in multiples of 64 bytes. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PTHRS_XOFF_MASK
value|0x000001ff
end_define

begin_comment
comment|/* XOFF PAUSE */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PTHRS_XOFF_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_PTHRS_XON_MASK
value|0x001ff000
end_define

begin_comment
comment|/* XON PAUSE */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_PTHRS_XON_SHFT
value|12
end_define

begin_comment
comment|/*  * CAS_RX_BLANK and CAS_RX_BLANK_ALIAS bits  * CAS_RX_BLANK is loaded each time CAS_STATUS is read and CAS_RX_BLANK_ALIAS  * is read each time CAS_STATUS_ALIAS is read.  The blanking time is specified  * in multiples of 512 core ticks (which runs at 125MHz).  */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BLANK_PKTS_MASK
value|0x000001ff
end_define

begin_comment
comment|/* RX blanking packets */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BLANK_PKTS_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_BLANK_TIME_MASK
value|0x3ffff000
end_define

begin_comment
comment|/* RX blanking time */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BLANK_TIME_SHFT
value|12
end_define

begin_comment
comment|/* CAS_RX_AEMPTY_THRS and CAS_RX_AEMPTY_THRS2 bits */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_THRS_MASK
value|0x00001fff
end_define

begin_comment
comment|/* RX_BUF_AEMPTY threshold */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_THRS_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_COMP_MASK
value|0x0fffe000
end_define

begin_comment
comment|/* RX_COMP_AFULL threshold */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_AEMPTY_COMP_SHFT
value|13
end_define

begin_comment
comment|/* The RX random early detection probability is in 12.5% granularity. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED_4K_6K_MASK
value|0x000000ff
end_define

begin_comment
comment|/* 4K< FIFO threshold< 6K */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED_4K_6K_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_RED_6K_8K_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* 6K< FIFO threshold< 8K */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED_6K_8K_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|CAS_RX_RED_8K_10K_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* 8K< FIFO threshold< 10K */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED_8K_10K_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_RX_RED_10K_12K_MASK
value|0xff000000
end_define

begin_comment
comment|/* 10K< FIFO threshold< 12K */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_RED_10K_12K_SHFT
value|24
end_define

begin_comment
comment|/* CAS_RX_FF_IPP_MASK and CAS_RX_FF_FIFO_MASK are in 8 bytes granularity. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FF_PKT_MASK
value|0x000000ff
end_define

begin_comment
comment|/* # of packets in RX FIFO */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FF_PKT_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RX_FF_IPP_MASK
value|0x0007ff00
end_define

begin_comment
comment|/* IPP FIFO level */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FF_IPP_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|CAS_RX_FF_FIFO_MASK
value|0x3ff80000
end_define

begin_comment
comment|/* RX FIFO level */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FF_FIFO_SHFT
value|19
end_define

begin_define
define|#
directive|define
name|CAS_RX_BIST_START
value|0x00000001
end_define

begin_comment
comment|/* Start BIST process. */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_SUMMARY
value|0x00000002
end_define

begin_comment
comment|/* All okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_SM
value|0x00007800
end_define

begin_comment
comment|/* BIST state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_REAS_27
value|0x00008000
end_define

begin_comment
comment|/* Reas 27 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_REAS_26B
value|0x00010000
end_define

begin_comment
comment|/* Reas 26B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_REAS_26A
value|0x00020000
end_define

begin_comment
comment|/* Reas 26A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_CTRL_33
value|0x00040000
end_define

begin_comment
comment|/* Control FIFO 33 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_CTRL_32
value|0x00080000
end_define

begin_comment
comment|/* Control FIFO 32 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_33C
value|0x00100000
end_define

begin_comment
comment|/* IPP 33C okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_32C
value|0x00200000
end_define

begin_comment
comment|/* IPP 32C okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_33B
value|0x00400000
end_define

begin_comment
comment|/* IPP 33B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_32B
value|0x00800000
end_define

begin_comment
comment|/* IPP 32B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_33A
value|0x01000000
end_define

begin_comment
comment|/* IPP 33A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_IPP_32A
value|0x02000000
end_define

begin_comment
comment|/* IPP 32A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_33C
value|0x04000000
end_define

begin_comment
comment|/* 33C okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_32C
value|0x08000000
end_define

begin_comment
comment|/* 32C okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_33B
value|0x10000000
end_define

begin_comment
comment|/* 33B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_32B
value|0x20000000
end_define

begin_comment
comment|/* 32B okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_33A
value|0x40000000
end_define

begin_comment
comment|/* 33A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_BIST_32A
value|0x80000000
end_define

begin_comment
comment|/* 32A okay */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_REAS_DMA_ADDR_LC
value|0x0000003f
end_define

begin_comment
comment|/* reas. table location sel. */
end_comment

begin_comment
comment|/* header parser registers */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF
value|0x4140
end_define

begin_comment
comment|/* HP configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_IR_ADDR
value|0x4144
end_define

begin_comment
comment|/* HP instruction RAM address */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_IR_DATA_LO
value|0x4148
end_define

begin_comment
comment|/* HP instruction RAM data low */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_IR_DATA_MD
value|0x414c
end_define

begin_comment
comment|/* HP instruction RAM data mid */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_IR_DATA_HI
value|0x4150
end_define

begin_comment
comment|/* HP instruction RAM data high */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_DR_FDB
value|0x4154
end_define

begin_comment
comment|/* HP data RAM and flow DB address */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_DR_DATA
value|0x4158
end_define

begin_comment
comment|/* HP data RAM data */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB1
value|0x415c
end_define

begin_comment
comment|/* HP flow database 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB2
value|0x4160
end_define

begin_comment
comment|/* HP flow database 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB3
value|0x4164
end_define

begin_comment
comment|/* HP flow database 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB4
value|0x4168
end_define

begin_comment
comment|/* HP flow database 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB5
value|0x416c
end_define

begin_comment
comment|/* HP flow database 5 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB6
value|0x4170
end_define

begin_comment
comment|/* HP flow database 6 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB7
value|0x4174
end_define

begin_comment
comment|/* HP flow database 7 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB8
value|0x4178
end_define

begin_comment
comment|/* HP flow database 8 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB9
value|0x417c
end_define

begin_comment
comment|/* HP flow database 9 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB10
value|0x4180
end_define

begin_comment
comment|/* HP flow database 10 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB11
value|0x4184
end_define

begin_comment
comment|/* HP flow database 11 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_FLOW_DB12
value|0x4188
end_define

begin_comment
comment|/* HP flow database 12 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_SM
value|0x418c
end_define

begin_comment
comment|/* HP state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS1
value|0x4190
end_define

begin_comment
comment|/* HP status 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS2
value|0x4194
end_define

begin_comment
comment|/* HP status 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3
value|0x4198
end_define

begin_comment
comment|/* HP status 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST
value|0x419c
end_define

begin_comment
comment|/* HP RAM BIST */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF_PARSE_EN
value|0x00000001
end_define

begin_comment
comment|/* header parsing enable */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF_NCPU_MASK
value|0x000000fc
end_define

begin_comment
comment|/* #CPUs (0x0: 64) */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF_NCPU_SHFT
value|2
end_define

begin_define
define|#
directive|define
name|CAS_HP_CONF_SINC_DIS
value|0x00000100
end_define

begin_comment
comment|/* SYN inc. seq. number dis. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF_TPT_MASK
value|0x000ffe00
end_define

begin_comment
comment|/* TCP payload threshold */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_CONF_TPT_SHFT
value|9
end_define

begin_define
define|#
directive|define
name|CAS_HP_DR_FDB_DR_MASK
value|0x0000001f
end_define

begin_comment
comment|/* data RAM location sel. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_DR_FDB_DR_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_HP_DR_FDB_FDB_MASK
value|0x00003f00
end_define

begin_comment
comment|/* flow DB location sel. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_DR_FDB_FDB_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_OP_MASK
value|0x00000007
end_define

begin_comment
comment|/* HRP opcode */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_OP_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_LB_MASK
value|0x000001f8
end_define

begin_comment
comment|/* load balancing CPU number */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_LB_SHFT
value|3
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_L3O_MASK
value|0x0000fe00
end_define

begin_comment
comment|/* layer 3 offset */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_L3O_SHFT
value|9
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_SAP_MASK
value|0xffff0000
end_define

begin_comment
comment|/* ethertype */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS1_SAP_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_TSZ_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* TCP payload size */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_TSZ_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_TO_MASK
value|0x007f0000
end_define

begin_comment
comment|/* TCP payload offset */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_TO_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_FID_MASK
value|0x1f800000
end_define

begin_comment
comment|/* flow ID */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_FID_SHFT
value|23
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_AR2_MASK
value|0xe0000000
end_define

begin_comment
comment|/* accu_R2[6:4] */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS2_AR2_SHFT
value|29
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_TCP_NCHK
value|0x00000001
end_define

begin_comment
comment|/* TCP no payload check */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_TCP_CHK
value|0x00000002
end_define

begin_comment
comment|/* TCP payload check */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_SYN_FLAG
value|0x00000004
end_define

begin_comment
comment|/* SYN flag */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_TCP_FLAG
value|0x00000008
end_define

begin_comment
comment|/* TCP flag check */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_CTRL_PF
value|0x00000010
end_define

begin_comment
comment|/* control packet flag */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_NASSIST
value|0x00000020
end_define

begin_comment
comment|/* no assist */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_MASK_PT
value|0x00000040
end_define

begin_comment
comment|/* Mask payload threshold. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_FRC_TPC
value|0x00000080
end_define

begin_comment
comment|/* Force TCP payload check. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_MASK_DLZ
value|0x00000100
end_define

begin_comment
comment|/* Mask data length equal 0. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_FRC_TNPC
value|0x00000200
end_define

begin_comment
comment|/* Force TCP no payload chk. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_JMBHS_EN
value|0x00000400
end_define

begin_comment
comment|/* jumbo header split enable */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_BWO_REAS
value|0x00000800
end_define

begin_comment
comment|/* batching w/o reassembly */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_FRC_DROP
value|0x00001000
end_define

begin_comment
comment|/* force drop */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_AR1_MASK
value|0x000fe000
end_define

begin_comment
comment|/* accu_R1 */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_AR1_SHFT
value|13
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_CSO_MASK
value|0x07f00000
end_define

begin_comment
comment|/* checksum start offset */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_CSO_SHFT
value|19
end_define

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_AR2_MASK
value|0xf0000000
end_define

begin_comment
comment|/* accu_R2[3:0] */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_STATUS3_AR2_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_START
value|0x00000001
end_define

begin_comment
comment|/* Start RAM BIST process. */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_SUMMARY
value|0x00000002
end_define

begin_comment
comment|/* all RAM okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_TCPSEQ
value|0x00020000
end_define

begin_comment
comment|/* TCP seqeunce RAM okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID31
value|0x00040000
end_define

begin_comment
comment|/* flow ID RAM3 bank 1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID21
value|0x00080000
end_define

begin_comment
comment|/* flow ID RAM2 bank 1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID11
value|0x00100000
end_define

begin_comment
comment|/* flow ID RAM1 bank 1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID01
value|0x00200000
end_define

begin_comment
comment|/* flow ID RAM0 bank 1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID30
value|0x00400000
end_define

begin_comment
comment|/* flow ID RAM3 bank 0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID20
value|0x00800000
end_define

begin_comment
comment|/* flow ID RAM2 bank 0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID10
value|0x01000000
end_define

begin_comment
comment|/* flow ID RAM1 bank 0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_FID00
value|0x02000000
end_define

begin_comment
comment|/* flow ID RAM0 bank 0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_AGE1
value|0x04000000
end_define

begin_comment
comment|/* aging RAM1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_AGE0
value|0x08000000
end_define

begin_comment
comment|/* aging RAM0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_IR2
value|0x10000000
end_define

begin_comment
comment|/* instruction RAM2 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_IR1
value|0x20000000
end_define

begin_comment
comment|/* instruction RAM1 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_IR0
value|0x40000000
end_define

begin_comment
comment|/* instruction RAM0 okay */
end_comment

begin_define
define|#
directive|define
name|CAS_HP_RAM_BIST_DR
value|0x80000000
end_define

begin_comment
comment|/* data RAM okay */
end_comment

begin_comment
comment|/* MAC registers */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TXRESET
value|0x6000
end_define

begin_comment
comment|/* TX MAC software reset command */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RXRESET
value|0x6004
end_define

begin_comment
comment|/* RX MAC software reset command */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SPC
value|0x6008
end_define

begin_comment
comment|/* send PAUSE command */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_STATUS
value|0x6010
end_define

begin_comment
comment|/* TX MAC status */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_STATUS
value|0x6014
end_define

begin_comment
comment|/* RX MAC status */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_STATUS
value|0x6018
end_define

begin_comment
comment|/* MAC control status */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_MASK
value|0x6020
end_define

begin_comment
comment|/* TX MAC mask */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_MASK
value|0x6024
end_define

begin_comment
comment|/* RX MAC mask */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_MASK
value|0x6028
end_define

begin_comment
comment|/* MAC control mask */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF
value|0x6030
end_define

begin_comment
comment|/* TX MAC configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF
value|0x6034
end_define

begin_comment
comment|/* RX MAC configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_CONF
value|0x6038
end_define

begin_comment
comment|/* MAC control configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF
value|0x603c
end_define

begin_comment
comment|/* XIF configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_IPG0
value|0x6040
end_define

begin_comment
comment|/* inter packet gap 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_IPG1
value|0x6044
end_define

begin_comment
comment|/* inter packet gap 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_IPG2
value|0x6048
end_define

begin_comment
comment|/* inter packet gap 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SLOT_TIME
value|0x604c
end_define

begin_comment
comment|/* slot time */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MIN_FRAME
value|0x6050
end_define

begin_comment
comment|/* minimum frame size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MAX_BF
value|0x6054
end_define

begin_comment
comment|/* maximum bust and frame size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_PREAMBLE_LEN
value|0x6058
end_define

begin_comment
comment|/* PA size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_JAM_SIZE
value|0x605c
end_define

begin_comment
comment|/* jam size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ATTEMPT_LIMIT
value|0x6060
end_define

begin_comment
comment|/* attempt limit */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_TYPE
value|0x6064
end_define

begin_comment
comment|/* MAC control type */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR0
value|0x6080
end_define

begin_comment
comment|/* MAC address 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR1
value|0x6084
end_define

begin_comment
comment|/* MAC address 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR2
value|0x6088
end_define

begin_comment
comment|/* MAC address 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR3
value|0x608c
end_define

begin_comment
comment|/* MAC address 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR4
value|0x6090
end_define

begin_comment
comment|/* MAC address 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR5
value|0x6094
end_define

begin_comment
comment|/* MAC address 5 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR6
value|0x6098
end_define

begin_comment
comment|/* MAC address 6 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR7
value|0x609c
end_define

begin_comment
comment|/* MAC address 7 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR8
value|0x60a0
end_define

begin_comment
comment|/* MAC address 8 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR9
value|0x60a4
end_define

begin_comment
comment|/* MAC address 9 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR10
value|0x60a8
end_define

begin_comment
comment|/* MAC address 10 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR11
value|0x60ac
end_define

begin_comment
comment|/* MAC address 11 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR12
value|0x60b0
end_define

begin_comment
comment|/* MAC address 12 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR13
value|0x60b4
end_define

begin_comment
comment|/* MAC address 13 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR14
value|0x60b8
end_define

begin_comment
comment|/* MAC address 14 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR15
value|0x60bc
end_define

begin_comment
comment|/* MAC address 15 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR16
value|0x60c0
end_define

begin_comment
comment|/* MAC address 16 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR17
value|0x60c4
end_define

begin_comment
comment|/* MAC address 17 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR18
value|0x60c8
end_define

begin_comment
comment|/* MAC address 18 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR19
value|0x60cc
end_define

begin_comment
comment|/* MAC address 19 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR20
value|0x60d0
end_define

begin_comment
comment|/* MAC address 20 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR21
value|0x60d4
end_define

begin_comment
comment|/* MAC address 21 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR22
value|0x60d8
end_define

begin_comment
comment|/* MAC address 22 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR23
value|0x60dc
end_define

begin_comment
comment|/* MAC address 23 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR24
value|0x60e0
end_define

begin_comment
comment|/* MAC address 24 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR25
value|0x60e4
end_define

begin_comment
comment|/* MAC address 25 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR26
value|0x60e8
end_define

begin_comment
comment|/* MAC address 26 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR27
value|0x60ec
end_define

begin_comment
comment|/* MAC address 27 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR28
value|0x60f0
end_define

begin_comment
comment|/* MAC address 28 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR29
value|0x60f4
end_define

begin_comment
comment|/* MAC address 29 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR30
value|0x60f8
end_define

begin_comment
comment|/* MAC address 30 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR31
value|0x60fc
end_define

begin_comment
comment|/* MAC address 31 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR32
value|0x6100
end_define

begin_comment
comment|/* MAC address 32 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR33
value|0x6104
end_define

begin_comment
comment|/* MAC address 33 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR34
value|0x6108
end_define

begin_comment
comment|/* MAC address 34 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR35
value|0x610c
end_define

begin_comment
comment|/* MAC address 35 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR36
value|0x6110
end_define

begin_comment
comment|/* MAC address 36 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR37
value|0x6114
end_define

begin_comment
comment|/* MAC address 37 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR38
value|0x6118
end_define

begin_comment
comment|/* MAC address 38 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR39
value|0x611c
end_define

begin_comment
comment|/* MAC address 39 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR40
value|0x6120
end_define

begin_comment
comment|/* MAC address 40 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR41
value|0x6124
end_define

begin_comment
comment|/* MAC address 41 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR42
value|0x6128
end_define

begin_comment
comment|/* MAC address 42 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR43
value|0x612c
end_define

begin_comment
comment|/* MAC address 43 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_ADDR44
value|0x6130
end_define

begin_comment
comment|/* MAC address 44 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_AFILTER0
value|0x614c
end_define

begin_comment
comment|/* address filter 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_AFILTER1
value|0x6150
end_define

begin_comment
comment|/* address filter 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_AFILTER2
value|0x6154
end_define

begin_comment
comment|/* address filter 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_AFILTER_MASK1_2
value|0x6158
end_define

begin_comment
comment|/* address filter 2& 1 mask*/
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_AFILTER_MASK0
value|0x615c
end_define

begin_comment
comment|/* address filter 0 mask */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH0
value|0x6160
end_define

begin_comment
comment|/* hash table 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH1
value|0x6164
end_define

begin_comment
comment|/* hash table 1 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH2
value|0x6168
end_define

begin_comment
comment|/* hash table 2 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH3
value|0x616c
end_define

begin_comment
comment|/* hash table 3 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH4
value|0x6170
end_define

begin_comment
comment|/* hash table 4 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH5
value|0x6174
end_define

begin_comment
comment|/* hash table 5 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH6
value|0x6178
end_define

begin_comment
comment|/* hash table 6 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH7
value|0x617c
end_define

begin_comment
comment|/* hash table 7 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH8
value|0x6180
end_define

begin_comment
comment|/* hash table 8 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH9
value|0x6184
end_define

begin_comment
comment|/* hash table 9 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH10
value|0x6188
end_define

begin_comment
comment|/* hash table 10 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH11
value|0x618c
end_define

begin_comment
comment|/* hash table 11 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH12
value|0x6190
end_define

begin_comment
comment|/* hash table 12 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH13
value|0x6194
end_define

begin_comment
comment|/* hash table 13 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH14
value|0x6198
end_define

begin_comment
comment|/* hash table 14 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_HASH15
value|0x619c
end_define

begin_comment
comment|/* hash table 15 */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_NORM_COLL_CNT
value|0x61a0
end_define

begin_comment
comment|/* normal collision counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_FIRST_COLL_CNT
value|0x61a4
end_define

begin_comment
comment|/* 1st attempt suc. collision counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_EXCESS_COLL_CNT
value|0x61a8
end_define

begin_comment
comment|/* excess collision counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_LATE_COLL_CNT
value|0x61ac
end_define

begin_comment
comment|/* late collision counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_DEFER_TMR_CNT
value|0x61b0
end_define

begin_comment
comment|/* defer timer */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_PEAK_ATTEMPTS
value|0x61b4
end_define

begin_comment
comment|/* peak attempts */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_FRAME_COUNT
value|0x61b8
end_define

begin_comment
comment|/* receive frame counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_LEN_ERR_CNT
value|0x61bc
end_define

begin_comment
comment|/* length error counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_ALIGN_ERR
value|0x61c0
end_define

begin_comment
comment|/* alignment error counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CRC_ERR_CNT
value|0x61c4
end_define

begin_comment
comment|/* FCS error counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CODE_VIOL
value|0x61c8
end_define

begin_comment
comment|/* RX code violation error counter */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RANDOM_SEED
value|0x61cc
end_define

begin_comment
comment|/* random number seed */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MAC_STATE
value|0x61d0
end_define

begin_comment
comment|/* MAC state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SPC_TIME_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* PAUSE time value */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SPC_TIME_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_MAC_SPC_SEND
value|0x00010000
end_define

begin_comment
comment|/* Send PAUSE frame. */
end_comment

begin_comment
comment|/* CAS_MAC_TX_STATUS and CAS_MAC_TX_MASK register bits */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_FRAME_XMTD
value|0x00000001
end_define

begin_comment
comment|/* Frame transmitted. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_UNDERRUN
value|0x00000002
end_define

begin_comment
comment|/* TX data starvation */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_MAX_PKT_ERR
value|0x00000004
end_define

begin_comment
comment|/* frame> CAS_MAC_MAX_FRAME */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_NCC_EXP
value|0x00000008
end_define

begin_comment
comment|/* normal coll. counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_ECC_EXP
value|0x00000010
end_define

begin_comment
comment|/* excess coll. counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_LCC_EXP
value|0x00000020
end_define

begin_comment
comment|/* late coll. counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_FCC_EXP
value|0x00000040
end_define

begin_comment
comment|/* 1st coll. counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_DEFER_EXP
value|0x00000080
end_define

begin_comment
comment|/* defer timer wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_PEAK_EXP
value|0x00000100
end_define

begin_comment
comment|/* peak attempts counter wrap */
end_comment

begin_comment
comment|/* CAS_MAC_RX_STATUS and CAS_MAC_RX_MASK register bits */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_FRAME_RCVD
value|0x00000001
end_define

begin_comment
comment|/* Frame received. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_OVERFLOW
value|0x00000002
end_define

begin_comment
comment|/* RX FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_FRAME_EXP
value|0x00000004
end_define

begin_comment
comment|/* RX frame counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_ALIGN_EXP
value|0x00000008
end_define

begin_comment
comment|/* alignment error cntr. wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CRC_EXP
value|0x00000010
end_define

begin_comment
comment|/* CRC error counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_LEN_EXP
value|0x00000020
end_define

begin_comment
comment|/* length error counter wrap */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_VIOL_EXP
value|0x00000040
end_define

begin_comment
comment|/* code violation cntr. wrap */
end_comment

begin_comment
comment|/* CAS_MAC_CTRL_STATUS and CAS_MAC_CTRL_MASK register bits */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_PAUSE_RCVD
value|0x00000001
end_define

begin_comment
comment|/* PAUSE received. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_PAUSE
value|0x00000002
end_define

begin_comment
comment|/* PAUSE state entered. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_NON_PAUSE
value|0x00000004
end_define

begin_comment
comment|/* PAUSE state left. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_STATUS_PT_MASK
value|0xffff0000
end_define

begin_comment
comment|/* PAUSE time */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_STATUS_PT_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_EN
value|0x00000001
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_ICARR
value|0x00000002
end_define

begin_comment
comment|/* Ignore carrier sense. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_ICOLLIS
value|0x00000004
end_define

begin_comment
comment|/* Ignore collisions. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_EN_IPG0
value|0x00000008
end_define

begin_comment
comment|/* extend RX-to-TX IPG */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_NGU
value|0x00000010
end_define

begin_comment
comment|/* Never give up. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_NGUL
value|0x00000020
end_define

begin_comment
comment|/* never give up limit */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_NBOFF
value|0x00000040
end_define

begin_comment
comment|/* Disable backoff algorithm. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_SDOWN
value|0x00000080
end_define

begin_comment
comment|/* CSMA/CD slow down */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_NO_FCS
value|0x00000100
end_define

begin_comment
comment|/* Don't generate FCS. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_TX_CONF_CARR
value|0x00000200
end_define

begin_comment
comment|/* carrier extension enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_EN
value|0x00000001
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_STRPPAD
value|0x00000002
end_define

begin_comment
comment|/* Must not be set. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_STRPFCS
value|0x00000004
end_define

begin_comment
comment|/* Strip FCS bytes. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_PROMISC
value|0x00000008
end_define

begin_comment
comment|/* promiscuous mode enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_PGRP
value|0x00000010
end_define

begin_comment
comment|/* promiscuous group mode en. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_HFILTER
value|0x00000020
end_define

begin_comment
comment|/* hash filter enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_AFILTER
value|0x00000040
end_define

begin_comment
comment|/* address filter enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_DIS_DOE
value|0x00000080
end_define

begin_comment
comment|/* disable discard on error */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_RX_CONF_CARR
value|0x00000100
end_define

begin_comment
comment|/* carrier extension enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_CONF_TXP
value|0x00000001
end_define

begin_comment
comment|/* send PAUSE enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_CONF_RXP
value|0x00000002
end_define

begin_comment
comment|/* receive PAUSE enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_CTRL_CONF_PASSP
value|0x00000004
end_define

begin_comment
comment|/* Pass PAUSE up to RX DMA. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_TX_OE
value|0x00000001
end_define

begin_comment
comment|/* MII TX output drivers en. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_ILBK
value|0x00000002
end_define

begin_comment
comment|/* MII internal loopback en. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_NOECHO
value|0x00000004
end_define

begin_comment
comment|/* Disable echo. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_GMII
value|0x00000008
end_define

begin_comment
comment|/* GMII (vs. MII) mode enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_BUF_OE
value|0x00000010
end_define

begin_comment
comment|/* MII_BUF_OE enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_LNKLED
value|0x00000020
end_define

begin_comment
comment|/* Force LINKLED# active. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_XIF_CONF_FDXLED
value|0x00000040
end_define

begin_comment
comment|/* Force FDPLXLED# active. */
end_comment

begin_comment
comment|/*  * The value of CAS_MAC_SLOT_TIME specifies the PAUSE time unit and depends  * on whether carrier extension is enabled.  */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SLOT_TIME_CARR
value|0x200
end_define

begin_comment
comment|/* slot time for carr. ext. */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_SLOT_TIME_NORM
value|0x40
end_define

begin_comment
comment|/* slot time otherwise */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MAX_BF_FRM_MASK
value|0x00007fff
end_define

begin_comment
comment|/* maximum frame size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MAX_BF_FRM_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_MAC_MAX_BF_BST_MASK
value|0x3fff0000
end_define

begin_comment
comment|/* maximum burst size */
end_comment

begin_define
define|#
directive|define
name|CAS_MAC_MAX_BF_BST_SHFT
value|16
end_define

begin_comment
comment|/*  * MIF registers  * The bit-bang registers use the low bit only.  */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_BB_CLOCK
value|0x6200
end_define

begin_comment
comment|/* MIF bit-bang clock */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_BB_DATA
value|0x6204
end_define

begin_comment
comment|/* MIF bit-bang data */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_BB_OUTPUT_EN
value|0x6208
end_define

begin_comment
comment|/* MIF bit-bang output enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME
value|0x620c
end_define

begin_comment
comment|/* MIF frame/output */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF
value|0x6210
end_define

begin_comment
comment|/* MIF configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_MASK
value|0x6214
end_define

begin_comment
comment|/* MIF mask */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_STATUS
value|0x6218
end_define

begin_comment
comment|/* MIF status */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_SM
value|0x621c
end_define

begin_comment
comment|/* MIF state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_DATA
value|0x0000ffff
end_define

begin_comment
comment|/* instruction payload */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_TA_LSB
value|0x00010000
end_define

begin_comment
comment|/* turn around LSB */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_TA_MSB
value|0x00020000
end_define

begin_comment
comment|/* turn around MSB */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_REG_MASK
value|0x007c0000
end_define

begin_comment
comment|/* register address */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_REG_SHFT
value|18
end_define

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_PHY_MASK
value|0x0f800000
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_PHY_SHFT
value|23
end_define

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_OP_WRITE
value|0x10000000
end_define

begin_comment
comment|/* write opcode */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_OP_READ
value|0x20000000
end_define

begin_comment
comment|/* read opcode */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_OP_MASK
define|\
value|(CAS_MIF_FRAME_OP_WRITE | CAS_MIF_FRAME_OP_READ)
end_define

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_ST
value|0x40000000
end_define

begin_comment
comment|/* start of frame */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_ST_MASK
value|0xc0000000
end_define

begin_comment
comment|/* start of frame */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_READ
define|\
value|(CAS_MIF_FRAME_TA_MSB | CAS_MIF_FRAME_OP_READ | CAS_MIF_FRAME_ST)
end_define

begin_define
define|#
directive|define
name|CAS_MIF_FRAME_WRITE
define|\
value|(CAS_MIF_FRAME_TA_MSB | CAS_MIF_FRAME_OP_WRITE | CAS_MIF_FRAME_ST)
end_define

begin_define
define|#
directive|define
name|CAS_MIF_CONF_PHY_SELECT
value|0x00000001
end_define

begin_comment
comment|/* PHY select, 0: MDIO_0 */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_POLL_EN
value|0x00000002
end_define

begin_comment
comment|/* polling mechanism enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_BB_MODE
value|0x00000004
end_define

begin_comment
comment|/* bit-bang mode enable */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_PREG_MASK
value|0x000000f8
end_define

begin_comment
comment|/* polled register */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_PREG_SHFT
value|3
end_define

begin_define
define|#
directive|define
name|CAS_MIF_CONF_MDI0
value|0x00000100
end_define

begin_comment
comment|/* MDIO_0 data/attached */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_MDI1
value|0x00000200
end_define

begin_comment
comment|/* MDIO_1 data/attached */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_PPHY_MASK
value|0x00007c00
end_define

begin_comment
comment|/* polled PHY */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_CONF_PPHY_SHFT
value|10
end_define

begin_comment
comment|/* CAS_MIF_MASK and CAS_MIF_STATUS bits */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_POLL_STATUS_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* polling status */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_POLL_STATUS_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_MIF_POLL_DATA_MASK
value|0xffff0000
end_define

begin_comment
comment|/* polling data */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_POLL_DATA_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|CAS_MIF_SM_CTRL_MASK
value|0x00000007
end_define

begin_comment
comment|/* ctrl. state machine state */
end_comment

begin_define
define|#
directive|define
name|CAS_MIF_SM_CTRL_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_MIF_SM_EXEC_MASK
value|0x00000060
end_define

begin_comment
comment|/* exec. state machine state */
end_comment

begin_comment
comment|/* PCS/Serialink registers */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL
value|0x9000
end_define

begin_comment
comment|/* PCS MII control (PCS "BMCR") */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS
value|0x9004
end_define

begin_comment
comment|/* PCS MII status (PCS "BMSR") */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANAR
value|0x9008
end_define

begin_comment
comment|/* PCS MII advertisement */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANLPAR
value|0x900c
end_define

begin_comment
comment|/* PCS MII link partner ability */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF
value|0x9010
end_define

begin_comment
comment|/* PCS configuration */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM
value|0x9014
end_define

begin_comment
comment|/* PCS state machine */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_INTR_STATUS
value|0x9018
end_define

begin_comment
comment|/* PCS interrupt status */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_DATAPATH
value|0x9050
end_define

begin_comment
comment|/* datapath mode */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_CTRL
value|0x9054
end_define

begin_comment
comment|/* SERDES control */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_OUTPUT_SELECT
value|0x9058
end_define

begin_comment
comment|/* shared output select */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_STATUS
value|0x905c
end_define

begin_comment
comment|/* SERDES state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_PKT_CNT
value|0x9060
end_define

begin_comment
comment|/* PCS packet counter */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_1000M
value|0x00000040
end_define

begin_comment
comment|/* 1000Mbps speed select */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_COLL_TEST
value|0x00000080
end_define

begin_comment
comment|/* collision test */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_FDX
value|0x00000100
end_define

begin_comment
comment|/* full-duplex, always 0 */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_RANEG
value|0x00000200
end_define

begin_comment
comment|/* restart auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_ISOLATE
value|0x00000400
end_define

begin_comment
comment|/* isolate PHY from MII */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_POWERDOWN
value|0x00000800
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_ANEG_EN
value|0x00001000
end_define

begin_comment
comment|/* auto-negotiation enable */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_10_100M
value|0x00002000
end_define

begin_comment
comment|/* 10/100Mbps speed select */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CTRL_RESET
value|0x00008000
end_define

begin_comment
comment|/* Reset PCS. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_EXTCAP
value|0x00000001
end_define

begin_comment
comment|/* extended capability */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_JABBER
value|0x00000002
end_define

begin_comment
comment|/* jabber condition detected */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_LINK
value|0x00000004
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_ANEG_ABL
value|0x00000008
end_define

begin_comment
comment|/* auto-negotiation ability */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_REM_FLT
value|0x00000010
end_define

begin_comment
comment|/* remote fault detected */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_ANEG_CPT
value|0x00000020
end_define

begin_comment
comment|/* auto-negotiate complete */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_STATUS_EXTENDED
value|0x00000100
end_define

begin_comment
comment|/* extended status */
end_comment

begin_comment
comment|/* CAS_PCS_ANAR and CAS_PCS_ANLPAR register bits */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_FDX
value|0x00000020
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_HDX
value|0x00000040
end_define

begin_comment
comment|/* half-duplex */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_PAUSE
value|0x00000080
end_define

begin_comment
comment|/* symmetric PAUSE */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_ASM_DIR
value|0x00000100
end_define

begin_comment
comment|/* asymmetric PAUSE */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_RFLT_FAIL
value|0x00001000
end_define

begin_comment
comment|/* remote fault - fail */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_RFLT_OFF
value|0x00002000
end_define

begin_comment
comment|/* remote fault - off-line */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_RFLT_MASK
define|\
value|(CAS_PCS_ANEG_RFLT_FAIL | CAS_PCS_ANEG_RFLT_OFF)
end_define

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_ACK
value|0x00004000
end_define

begin_comment
comment|/* acknowledge */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_ANEG_NEXT_PAGE
value|0x00008000
end_define

begin_comment
comment|/* next page */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_EN
value|0x00000001
end_define

begin_comment
comment|/* Enable PCS. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_SDO
value|0x00000002
end_define

begin_comment
comment|/* signal detect override */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_SDL
value|0x00000004
end_define

begin_comment
comment|/* signal detect active-low */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_JS_NORM
value|0x00000000
end_define

begin_comment
comment|/* jitter study - normal op. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_JS_HF
value|0x00000008
end_define

begin_comment
comment|/* jitter study - HF test */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_JS_LF
value|0x00000010
end_define

begin_comment
comment|/* jitter study - LF test */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_CONF_JS_MASK
value|(CAS_PCS_CONF_JS_HF | CAS_PCS_CONF_JS_LF)
end_define

begin_define
define|#
directive|define
name|CAS_PCS_CONF_ANEG_TO
value|0x00000020
end_define

begin_comment
comment|/* auto-neg. timer override */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_TX_CTRL_MASK
value|0x0000000f
end_define

begin_comment
comment|/* TX control state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_TX_CTRL_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_RX_CTRL_MASK
value|0x000000f0
end_define

begin_comment
comment|/* RX control state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_RX_CTRL_SHFT
value|4
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_WSYNC_MASK
value|0x00000700
end_define

begin_comment
comment|/* word sync. state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_WSYNC_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_SEQ_MASK
value|0x00001800
end_define

begin_comment
comment|/* sequence detection state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_SEQ_SHFT
value|11
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_LINK_UP
value|0x00016000
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_LINK_MASK
value|0x0001e000
end_define

begin_comment
comment|/* link configuration state */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_LINK_SHFT
value|13
end_define

begin_define
define|#
directive|define
name|CAS_PCS_SM_LOSS_C
value|0x00100000
end_define

begin_comment
comment|/* link-loss due to C codes */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_LOSS_SYNC
value|0x00200000
end_define

begin_comment
comment|/* link-loss due to sync-loss */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_LOS
value|0x00400000
end_define

begin_comment
comment|/* loss of signal */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_BREAK
value|0x01000000
end_define

begin_comment
comment|/* no link due to breaklink */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_SERDES
value|0x02000000
end_define

begin_comment
comment|/* no link due to SERDES */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_C
value|0x04000000
end_define

begin_comment
comment|/* no link due to bad C codes */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_SYNC
value|0x08000000
end_define

begin_comment
comment|/* no link due to word sync. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_WAIT_C
value|0x10000000
end_define

begin_comment
comment|/* no link, waiting for ack. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SM_NLINK_NIDLE
value|0x20000000
end_define

begin_comment
comment|/* no link due to no idle */
end_comment

begin_comment
comment|/*  * CAS_PCS_INTR_STATUS has no corresponding mask register.  It can only  * be masked with CAS_INTR_PCS_INT.  */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_INTR_LINK
value|0x00000004
end_define

begin_comment
comment|/* link status change */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_DATAPATH_MII
value|0x00000001
end_define

begin_comment
comment|/* GMII/MII and MAC loopback */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_DATAPATH_SERDES
value|0x00000002
end_define

begin_comment
comment|/* SERDES via 10-bit */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_CTRL_LBK
value|0x00000001
end_define

begin_comment
comment|/* loopback at 10-bit enable */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_CTRL_ESD
value|0x00000002
end_define

begin_comment
comment|/* En. sync char. detection. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_CTRL_LR
value|0x00000004
end_define

begin_comment
comment|/* Lock to reference clock. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_STATUS_T
value|0x00000000
end_define

begin_comment
comment|/* Undergoing test. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_STATUS_L
value|0x00000001
end_define

begin_comment
comment|/* Waiting 500us w/ lockrefn. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_STATUS_C
value|0x00000002
end_define

begin_comment
comment|/* Waiting for comma detect. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_SERDES_STATUS_S
value|0x00000003
end_define

begin_comment
comment|/* Receive data is sync. */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_PKT_CNT_TX_MASK
value|0x000007ff
end_define

begin_comment
comment|/* TX packets */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_PKT_CNT_TX_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_PCS_PKT_CNT_RX_MASK
value|0x07ff0000
end_define

begin_comment
comment|/* RX packets */
end_comment

begin_define
define|#
directive|define
name|CAS_PCS_PKT_CNT_RX_SHFT
value|16
end_define

begin_comment
comment|/*  * PCI expansion ROM runtime access  * Cassinis and Saturn map a 1MB space for the PCI expansion ROM as the  * second half of the first register bank, although they only support up  * to 64KB ROMs.  */
end_comment

begin_define
define|#
directive|define
name|CAS_PCI_ROM_OFFSET
value|0x100000
end_define

begin_define
define|#
directive|define
name|CAS_PCI_ROM_SIZE
value|0x10000
end_define

begin_comment
comment|/* secondary local bus device */
end_comment

begin_define
define|#
directive|define
name|CAS_SEC_LBDEV_OFFSET
value|0x180000
end_define

begin_define
define|#
directive|define
name|CAS_SEC_LBDE_SIZE
value|0x7ffff
end_define

begin_comment
comment|/* wired PHY addresses */
end_comment

begin_define
define|#
directive|define
name|CAS_PHYAD_INTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|CAS_PHYAD_EXTERNAL
value|0
end_define

begin_comment
comment|/* wired RX FIFO size in bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RX_FIFO_SIZE
value|16 * 1024
end_define

begin_comment
comment|/*  * descriptor ring structures  */
end_comment

begin_struct
struct|struct
name|cas_desc
block|{
name|uint64_t
name|cd_flags
decl_stmt|;
name|uint64_t
name|cd_buf_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * transmit flags  * CAS_TD_CKSUM_START_MASK, CAS_TD_CKSUM_STUFF_MASK, CAS_TD_CKSUM_EN and  * CAS_TD_INT_ME only need to be set in 1st descriptor of a frame.  */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_BUF_LEN_MASK
value|0x0000000000003fffULL
end_define

begin_comment
comment|/* buffer length */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_BUF_LEN_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_TD_CKSUM_START_MASK
value|0x00000000001f8000ULL
end_define

begin_comment
comment|/* checksum start... */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_CKSUM_START_SHFT
value|15
end_define

begin_comment
comment|/* ...offset */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_CKSUM_STUFF_MASK
value|0x000000001fe00000ULL
end_define

begin_comment
comment|/* checksum stuff... */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_CKSUM_STUFF_SHFT
value|21
end_define

begin_comment
comment|/* ...offset */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_CKSUM_EN
value|0x0000000020000000ULL
end_define

begin_comment
comment|/* checksum enable */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_END_OF_FRAME
value|0x0000000040000000ULL
end_define

begin_comment
comment|/* last desc. of pkt. */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_START_OF_FRAME
value|0x0000000080000000ULL
end_define

begin_comment
comment|/* 1st desc. of pkt. */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_INT_ME
value|0x0000000100000000ULL
end_define

begin_comment
comment|/* intr. when in FIFO */
end_comment

begin_define
define|#
directive|define
name|CAS_TD_NO_CRC
value|0x0000000200000000ULL
end_define

begin_comment
comment|/* Don't insert CRC. */
end_comment

begin_comment
comment|/* receive flags */
end_comment

begin_define
define|#
directive|define
name|CAS_RD_BUF_INDEX_MASK
value|0x0000000000003fffULL
end_define

begin_comment
comment|/* data buffer index */
end_comment

begin_define
define|#
directive|define
name|CAS_RD_BUF_INDEX_SHFT
value|0
end_define

begin_comment
comment|/*  * receive completion ring structure  */
end_comment

begin_struct
struct|struct
name|cas_rx_comp
block|{
name|uint64_t
name|crc_word1
decl_stmt|;
name|uint64_t
name|crc_word2
decl_stmt|;
name|uint64_t
name|crc_word3
decl_stmt|;
name|uint64_t
name|crc_word4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAS_RC1_DATA_SIZE_MASK
value|0x0000000007ffe000ULL
end_define

begin_comment
comment|/* pkt. data length */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_DATA_SIZE_SHFT
value|13
end_define

begin_define
define|#
directive|define
name|CAS_RC1_DATA_OFF_MASK
value|0x000001fff8000000ULL
end_define

begin_comment
comment|/* data buffer offset */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_DATA_OFF_SHFT
value|27
end_define

begin_define
define|#
directive|define
name|CAS_RC1_DATA_INDEX_MASK
value|0x007ffe0000000000ULL
end_define

begin_comment
comment|/* data buffer index */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_DATA_INDEX_SHFT
value|41
end_define

begin_define
define|#
directive|define
name|CAS_RC1_SKIP_MASK
value|0x0180000000000000ULL
end_define

begin_comment
comment|/* entries to skip */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_SKIP_SHFT
value|55
end_define

begin_define
define|#
directive|define
name|CAS_RC1_RELEASE_NEXT
value|0x0200000000000000ULL
end_define

begin_comment
comment|/* last in reas. buf. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_SPLIT_PKT
value|0x0400000000000000ULL
end_define

begin_comment
comment|/* used 2 reas. buf. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_RELEASE_FLOW
value|0x0800000000000000ULL
end_define

begin_comment
comment|/* last pkt. of flow */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_RELEASE_DATA
value|0x1000000000000000ULL
end_define

begin_comment
comment|/* reas. buf. full */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_RELEASE_HDR
value|0x2000000000000000ULL
end_define

begin_comment
comment|/* header buf. full */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_HW
value|0x0000000000000000ULL
end_define

begin_comment
comment|/* owned by hardware */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_RSFB
value|0x4000000000000000ULL
end_define

begin_comment
comment|/* stale flow buf... */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_RNRP
value|0x8000000000000000ULL
end_define

begin_comment
comment|/* non-reas. pkt... */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_RFP
value|0xc000000000000000ULL
end_define

begin_comment
comment|/* flow packet... */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_MASK
value|CAS_RC1_TYPE_RFP
end_define

begin_comment
comment|/* ...release */
end_comment

begin_define
define|#
directive|define
name|CAS_RC1_TYPE_SHFT
value|62
end_define

begin_define
define|#
directive|define
name|CAS_RC2_NEXT_INDEX_MASK
value|0x00000007ffe00000ULL
end_define

begin_comment
comment|/* next buf. of pkt. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC2_NEXT_INDEX_SHFT
value|21
end_define

begin_define
define|#
directive|define
name|CAS_RC2_HDR_SIZE_MASK
value|0x00000ff800000000ULL
end_define

begin_comment
comment|/* header length */
end_comment

begin_define
define|#
directive|define
name|CAS_RC2_HDR_SIZE_SHFT
value|35
end_define

begin_define
define|#
directive|define
name|CAS_RC2_HDR_OFF_MASK
value|0x0003f00000000000ULL
end_define

begin_comment
comment|/* header buf. offset */
end_comment

begin_define
define|#
directive|define
name|CAS_RC2_HDR_OFF_SHFT
value|44
end_define

begin_define
define|#
directive|define
name|CAS_RC2_HDR_INDEX_MASK
value|0xfffc000000000000ULL
end_define

begin_comment
comment|/* header buf. index */
end_comment

begin_define
define|#
directive|define
name|CAS_RC2_HDR_INDEX_SHFT
value|50
end_define

begin_define
define|#
directive|define
name|CAS_RC3_SMALL_PKT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* pkt.<= 256 - SOFF */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_JUMBO_PKT
value|0x0000000000000002ULL
end_define

begin_comment
comment|/* pkt.> 1522 bytes */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_JMBHS_EN
value|0x0000000000000004ULL
end_define

begin_comment
comment|/* jmb. hdr. spl. en. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_CSO_MASK
value|0x000000000007f000ULL
end_define

begin_comment
comment|/* checksum start... */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_CSO_SHFT
value|12
end_define

begin_comment
comment|/* ...offset */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_FLOWID_MASK
value|0x0000000001f80000ULL
end_define

begin_comment
comment|/* flow ID of pkt. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_FLOWID_SHFT
value|19
end_define

begin_define
define|#
directive|define
name|CAS_RC3_OP_MASK
value|0x000000000e000000ULL
end_define

begin_comment
comment|/* opcode */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_OP_SHFT
value|25
end_define

begin_define
define|#
directive|define
name|CAS_RC3_FRC_FLAG
value|0x0000000010000000ULL
end_define

begin_comment
comment|/* op. 2 batch. lkhd. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_NASSIST
value|0x0000000020000000ULL
end_define

begin_comment
comment|/* no assist */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_LB_MASK
value|0x000001f800000000ULL
end_define

begin_comment
comment|/* load balancing key */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_LB_SHFT
value|35
end_define

begin_define
define|#
directive|define
name|CAS_RC3_L3HO_MASK
value|0x0000fe0000000000ULL
end_define

begin_comment
comment|/* layer 3 hdr. off. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_L3HO_SHFT
value|41
end_define

begin_define
define|#
directive|define
name|CAS_RC3_PLUS_ENC_PKT
value|0x0000020000000000ULL
end_define

begin_comment
comment|/* IPsec AH/ESP pkt. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_PLUS_L3HO_MASK
value|0x0000fc0000000000ULL
end_define

begin_comment
comment|/* layer 3 hdr. off. */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_PLUS_L3HO_SHFT
value|42
end_define

begin_define
define|#
directive|define
name|CAS_RC3_SAP_MASK
value|0xffff000000000000ULL
end_define

begin_comment
comment|/* ethertype */
end_comment

begin_define
define|#
directive|define
name|CAS_RC3_SAP_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|CAS_RC4_TCP_CSUM_MASK
value|0x000000000000ffffULL
end_define

begin_comment
comment|/* TCP checksum */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_TCP_CSUM_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|CAS_RC4_PKT_LEN_MASK
value|0x000000003fff0000ULL
end_define

begin_comment
comment|/* entire pkt. length */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_PKT_LEN_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|CAS_RC4_PAM_MASK
value|0x00000003c0000000ULL
end_define

begin_comment
comment|/* mcast. addr. match */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_PAM_SHFT
value|30
end_define

begin_define
define|#
directive|define
name|CAS_RC4_ZERO
value|0x0000080000000000ULL
end_define

begin_comment
comment|/* owned by software */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_HASH_VAL_MASK
value|0x0ffff00000000000ULL
end_define

begin_comment
comment|/* mcast. addr. hash */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_HASH_VAL_SHFT
value|44
end_define

begin_define
define|#
directive|define
name|CAS_RC4_HASH_PASS
value|0x1000000000000000ULL
end_define

begin_comment
comment|/* passed hash filter */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_BAD
value|0x4000000000000000ULL
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|CAS_RC4_LEN_MMATCH
value|0x8000000000000000ULL
end_define

begin_comment
comment|/* length field mism. */
end_comment

begin_define
define|#
directive|define
name|CAS_GET
parameter_list|(
name|reg
parameter_list|,
name|bits
parameter_list|)
value|(((reg)& (bits ## _MASK))>> (bits ## _SHFT))
end_define

begin_define
define|#
directive|define
name|CAS_SET
parameter_list|(
name|val
parameter_list|,
name|bits
parameter_list|)
value|(((val)<< (bits ## _SHFT))& (bits ## _MASK))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

