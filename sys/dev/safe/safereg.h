begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Sam Leffler, Errno Consulting  * Copyright (c) 2003 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAFE_SAFEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAFE_SAFEREG_H_
end_define

begin_comment
comment|/*  * Register definitions for SafeNet SafeXcel-1141 crypto device.  * Definitions from revision 1.3 (Nov 6 2002) of the User's Manual.  */
end_comment

begin_define
define|#
directive|define
name|BS_BAR
value|0x10
end_define

begin_comment
comment|/* DMA base address register */
end_comment

begin_define
define|#
directive|define
name|BS_TRDY_TIMEOUT
value|0x40
end_define

begin_comment
comment|/* TRDY timeout */
end_comment

begin_define
define|#
directive|define
name|BS_RETRY_TIMEOUT
value|0x41
end_define

begin_comment
comment|/* DMA retry timeout */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_SAFENET
value|0x16ae
end_define

begin_comment
comment|/* SafeNet, Inc. */
end_comment

begin_comment
comment|/* SafeNet */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_SAFEXCEL
value|0x1141
end_define

begin_comment
comment|/* 1141 */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR
value|0x0000
end_define

begin_comment
comment|/* Packet Enginge Ctrl/Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_SRC
value|0x0004
end_define

begin_comment
comment|/* Packet Engine Source */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DST
value|0x0008
end_define

begin_comment
comment|/* Packet Engine Destination */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_SA
value|0x000c
end_define

begin_comment
comment|/* Packet Engine SA */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_LEN
value|0x0010
end_define

begin_comment
comment|/* Packet Engine Length */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG
value|0x0040
end_define

begin_comment
comment|/* Packet Engine DMA Configuration */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT
value|0x0044
end_define

begin_comment
comment|/* Packet Engine DMA Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PDRBASE
value|0x0048
end_define

begin_comment
comment|/* Packet Engine Descriptor Ring Base */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RDRBASE
value|0x004c
end_define

begin_comment
comment|/* Packet Engine Result Ring Base */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGCFG
value|0x0050
end_define

begin_comment
comment|/* Packet Engine Ring Configuration */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGPOLL
value|0x0054
end_define

begin_comment
comment|/* Packet Engine Ring Poll */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_IRNGSTAT
value|0x0058
end_define

begin_comment
comment|/* Packet Engine Internal Ring Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_ERNGSTAT
value|0x005c
end_define

begin_comment
comment|/* Packet Engine External Ring Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_IOTHRESH
value|0x0060
end_define

begin_comment
comment|/* Packet Engine I/O Threshold */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_GRNGBASE
value|0x0064
end_define

begin_comment
comment|/* Packet Engine Gather Ring Base */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_SRNGBASE
value|0x0068
end_define

begin_comment
comment|/* Packet Engine Scatter Ring Base */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTSIZE
value|0x006c
end_define

begin_comment
comment|/* Packet Engine Particlar Ring Size */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG
value|0x0070
end_define

begin_comment
comment|/* Packet Engine Particle Ring Config */
end_comment

begin_define
define|#
directive|define
name|SAFE_CRYPTO_CTRL
value|0x0080
end_define

begin_comment
comment|/* Crypto Control */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVID
value|0x0084
end_define

begin_comment
comment|/* Device ID */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO
value|0x0088
end_define

begin_comment
comment|/* Device Info */
end_comment

begin_define
define|#
directive|define
name|SAFE_HU_STAT
value|0x00a0
end_define

begin_comment
comment|/* Host Unmasked Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_HM_STAT
value|0x00a4
end_define

begin_comment
comment|/* Host Masked Status (read-only) */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_CLR
value|0x00a4
end_define

begin_comment
comment|/* Host Clear Interrupt (write-only) */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_MASK
value|0x00a8
end_define

begin_comment
comment|/* Host Mask Control */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_CFG
value|0x00ac
end_define

begin_comment
comment|/* Interrupt Configuration */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_RD_DESCR
value|0x00b4
end_define

begin_comment
comment|/* Force Descriptor Read */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_DESC_CNT
value|0x00b8
end_define

begin_comment
comment|/* Host Descriptor Done Count */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_ENDIAN
value|0x00c0
end_define

begin_comment
comment|/* Master Endian Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_SRCADDR
value|0x00c4
end_define

begin_comment
comment|/* DMA Source Address Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_DSTADDR
value|0x00c8
end_define

begin_comment
comment|/* DMA Destination Address Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_STAT
value|0x00cc
end_define

begin_comment
comment|/* DMA Current Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_CFG
value|0x00d4
end_define

begin_comment
comment|/* DMA Configuration/Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_ENDIAN
value|0x00e0
end_define

begin_comment
comment|/* Endian Configuration */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_A_ADDR
value|0x0800
end_define

begin_comment
comment|/* Public Key A Address */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_B_ADDR
value|0x0804
end_define

begin_comment
comment|/* Public Key B Address */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_C_ADDR
value|0x0808
end_define

begin_comment
comment|/* Public Key C Address */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_D_ADDR
value|0x080c
end_define

begin_comment
comment|/* Public Key D Address */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_A_LEN
value|0x0810
end_define

begin_comment
comment|/* Public Key A Length */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_B_LEN
value|0x0814
end_define

begin_comment
comment|/* Public Key B Length */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_SHIFT
value|0x0818
end_define

begin_comment
comment|/* Public Key Shift */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC
value|0x081c
end_define

begin_comment
comment|/* Public Key Function */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_OUT
value|0x0100
end_define

begin_comment
comment|/* RNG Output */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_STAT
value|0x0104
end_define

begin_comment
comment|/* RNG Status */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL
value|0x0108
end_define

begin_comment
comment|/* RNG Control */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_A
value|0x010c
end_define

begin_comment
comment|/* RNG A */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_B
value|0x0110
end_define

begin_comment
comment|/* RNG B */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_X_LO
value|0x0114
end_define

begin_comment
comment|/* RNG X [31:0] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_X_MID
value|0x0118
end_define

begin_comment
comment|/* RNG X [63:32] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_X_HI
value|0x011c
end_define

begin_comment
comment|/* RNG X [80:64] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_X_CNTR
value|0x0120
end_define

begin_comment
comment|/* RNG Counter */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_ALM_CNT
value|0x0124
end_define

begin_comment
comment|/* RNG Alarm Count */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CNFG
value|0x0128
end_define

begin_comment
comment|/* RNG Configuration */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_LFSR1_LO
value|0x012c
end_define

begin_comment
comment|/* RNG LFSR1 [31:0] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_LFSR1_HI
value|0x0130
end_define

begin_comment
comment|/* RNG LFSR1 [47:32] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_LFSR2_LO
value|0x0134
end_define

begin_comment
comment|/* RNG LFSR1 [31:0] */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_LFSR2_HI
value|0x0138
end_define

begin_comment
comment|/* RNG LFSR1 [47:32] */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_READY
value|0x00000001
end_define

begin_comment
comment|/* ready for processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_DONE
value|0x00000002
end_define

begin_comment
comment|/* h/w completed processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_LOADSA
value|0x00000004
end_define

begin_comment
comment|/* load SA digests */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_HASHFINAL
value|0x00000010
end_define

begin_comment
comment|/* do hash pad& write result */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_SABUSID
value|0x000000c0
end_define

begin_comment
comment|/* bus id for SA */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_SAPCI
value|0x00000040
end_define

begin_comment
comment|/* PCI bus id for SA */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_NXTHDR
value|0x0000ff00
end_define

begin_comment
comment|/* next hdr value for IPsec */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_FPAD
value|0x0000ff00
end_define

begin_comment
comment|/* fixed pad for basic ops */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_STATUS
value|0x00ff0000
end_define

begin_comment
comment|/* operation result status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_AUTH_FAIL
value|0x00010000
end_define

begin_comment
comment|/* ICV mismatch (inbound) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_FAIL
value|0x00020000
end_define

begin_comment
comment|/* pad verify fail (inbound) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_SEQ_FAIL
value|0x00040000
end_define

begin_comment
comment|/* sequence number (inbound) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XERROR
value|0x00080000
end_define

begin_comment
comment|/* extended error follows */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE
value|0x00f00000
end_define

begin_comment
comment|/* extended error code */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_S
value|20
end_define

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_BADCMD
value|0
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_BADALG
value|1
end_define

begin_comment
comment|/* invalid algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_ALGDIS
value|2
end_define

begin_comment
comment|/* algorithm disabled */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_ZEROLEN
value|3
end_define

begin_comment
comment|/* zero packet length */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_DMAERR
value|4
end_define

begin_comment
comment|/* bus DMA error */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_PIPEABORT
value|5
end_define

begin_comment
comment|/* secondary bus DMA error */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_BADSPI
value|6
end_define

begin_comment
comment|/* IPsec SPI mismatch */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_XECODE_TIMEOUT
value|10
end_define

begin_comment
comment|/* failsafe timeout */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD
value|0xff000000
end_define

begin_comment
comment|/* ESP padding control/status */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_MIN
value|0x00000000
end_define

begin_comment
comment|/* minimum IPsec padding */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_16
value|0x08000000
end_define

begin_comment
comment|/* pad to 16-byte boundary */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_32
value|0x10000000
end_define

begin_comment
comment|/* pad to 32-byte boundary */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_64
value|0x20000000
end_define

begin_comment
comment|/* pad to 64-byte boundary */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_128
value|0x40000000
end_define

begin_comment
comment|/* pad to 128-byte boundary */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_PAD_256
value|0x80000000
end_define

begin_comment
comment|/* pad to 256-byte boundary */
end_comment

begin_comment
comment|/*  * Check the CSR to see if the PE has returned ownership to  * the host.  Note that before processing a descriptor this  * must be done followed by a check of the SAFE_PE_LEN register  * status bits to avoid premature processing of a descriptor  * on its way back to the host.  */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_CSR_IS_DONE
parameter_list|(
name|_csr
parameter_list|)
define|\
value|(((_csr)& (SAFE_PE_CSR_READY | SAFE_PE_CSR_DONE)) == SAFE_PE_CSR_DONE)
end_define

begin_define
define|#
directive|define
name|SAFE_PE_LEN_LENGTH
value|0x000fffff
end_define

begin_comment
comment|/* total length (bytes) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_LEN_READY
value|0x00400000
end_define

begin_comment
comment|/* ready for processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_LEN_DONE
value|0x00800000
end_define

begin_comment
comment|/* h/w completed processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_LEN_BYPASS
value|0xff000000
end_define

begin_comment
comment|/* bypass offset (bytes) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_LEN_BYPASS_S
value|24
end_define

begin_define
define|#
directive|define
name|SAFE_PE_LEN_IS_DONE
parameter_list|(
name|_len
parameter_list|)
define|\
value|(((_len)& (SAFE_PE_LEN_READY | SAFE_PE_LEN_DONE)) == SAFE_PE_LEN_DONE)
end_define

begin_comment
comment|/* NB: these apply to HU_STAT, HM_STAT, HI_CLR, and HI_MASK */
end_comment

begin_define
define|#
directive|define
name|SAFE_INT_PE_CDONE
value|0x00000002
end_define

begin_comment
comment|/* PE context done */
end_comment

begin_define
define|#
directive|define
name|SAFE_INT_PE_DDONE
value|0x00000008
end_define

begin_comment
comment|/* PE descriptor done */
end_comment

begin_define
define|#
directive|define
name|SAFE_INT_PE_ERROR
value|0x00000010
end_define

begin_comment
comment|/* PE error */
end_comment

begin_define
define|#
directive|define
name|SAFE_INT_PE_ODONE
value|0x00000020
end_define

begin_comment
comment|/* PE operation done */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_CFG_PULSE
value|0x00000001
end_define

begin_comment
comment|/* use pulse interrupt */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_CFG_LEVEL
value|0x00000000
end_define

begin_comment
comment|/* use level interrupt */
end_comment

begin_define
define|#
directive|define
name|SAFE_HI_CFG_AUTOCLR
value|0x00000002
end_define

begin_comment
comment|/* auto-clear pulse interrupt */
end_comment

begin_define
define|#
directive|define
name|SAFE_ENDIAN_PASS
value|0x000000e4
end_define

begin_comment
comment|/* straight pass-thru */
end_comment

begin_define
define|#
directive|define
name|SAFE_ENDIAN_SWAB
value|0x0000001b
end_define

begin_comment
comment|/* swap bytes in 32-bit word */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_PERESET
value|0x00000001
end_define

begin_comment
comment|/* reset packet engine */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_PDRRESET
value|0x00000002
end_define

begin_comment
comment|/* reset PDR counters/ptrs */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_SGRESET
value|0x00000004
end_define

begin_comment
comment|/* reset scatter/gather cache */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_FSENA
value|0x00000008
end_define

begin_comment
comment|/* enable failsafe reset */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_PEMODE
value|0x00000100
end_define

begin_comment
comment|/* packet engine mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_SAPREC
value|0x00000200
end_define

begin_comment
comment|/* SA precedes packet */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_PKFOLL
value|0x00000400
end_define

begin_comment
comment|/* packet follows descriptor */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_GPRBID
value|0x00003000
end_define

begin_comment
comment|/* gather particle ring busid */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_GPRPCI
value|0x00001000
end_define

begin_comment
comment|/* PCI gather particle ring */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_SPRBID
value|0x0000c000
end_define

begin_comment
comment|/* scatter part. ring busid */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_SPRPCI
value|0x00004000
end_define

begin_comment
comment|/* PCI scatter part. ring */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_ESDESC
value|0x00010000
end_define

begin_comment
comment|/* endian swap descriptors */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_ESSA
value|0x00020000
end_define

begin_comment
comment|/* endian swap SA data */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_ESPACKET
value|0x00040000
end_define

begin_comment
comment|/* endian swap packet data */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_ESPDESC
value|0x00080000
end_define

begin_comment
comment|/* endian swap particle desc. */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMACFG_NOPDRUP
value|0x00100000
end_define

begin_comment
comment|/* supp. PDR ownership update */
end_comment

begin_define
define|#
directive|define
name|SAFE_PD_EDMACFG_PCIMODE
value|0x01000000
end_define

begin_comment
comment|/* PCI target mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_PEIDONE
value|0x00000001
end_define

begin_comment
comment|/* PE core input done */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_PEODONE
value|0x00000002
end_define

begin_comment
comment|/* PE core output done */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_ENCDONE
value|0x00000004
end_define

begin_comment
comment|/* encryption done */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_IHDONE
value|0x00000008
end_define

begin_comment
comment|/* inner hash done */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_OHDONE
value|0x00000010
end_define

begin_comment
comment|/* outer hash (HMAC) done */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_PADFLT
value|0x00000020
end_define

begin_comment
comment|/* crypto pad fault */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_ICVFLT
value|0x00000040
end_define

begin_comment
comment|/* ICV fault */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_SPIMIS
value|0x00000080
end_define

begin_comment
comment|/* SPI mismatch */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_CRYPTO
value|0x00000100
end_define

begin_comment
comment|/* crypto engine timeout */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_CQACT
value|0x00000200
end_define

begin_comment
comment|/* command queue active */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_IRACT
value|0x00000400
end_define

begin_comment
comment|/* input request active */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_ORACT
value|0x00000800
end_define

begin_comment
comment|/* output request active */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_PEISIZE
value|0x003ff000
end_define

begin_comment
comment|/* PE input size:32-bit words */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_DMASTAT_PEOSIZE
value|0xffc00000
end_define

begin_comment
comment|/* PE out. size:32-bit words */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGCFG_SIZE
value|0x000003ff
end_define

begin_comment
comment|/* ring size (descriptors) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGCFG_OFFSET
value|0xffff0000
end_define

begin_comment
comment|/* offset btw desc's (dwords) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGCFG_OFFSET_S
value|16
end_define

begin_define
define|#
directive|define
name|SAFE_PE_RINGPOLL_POLL
value|0x00000fff
end_define

begin_comment
comment|/* polling frequency/divisor */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGPOLL_RETRY
value|0x03ff0000
end_define

begin_comment
comment|/* polling frequency/divisor */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_RINGPOLL_CONT
value|0x80000000
end_define

begin_comment
comment|/* continuously poll */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_IRNGSTAT_CQAVAIL
value|0x00000001
end_define

begin_comment
comment|/* command queue available */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_ERNGSTAT_NEXT
value|0x03ff0000
end_define

begin_comment
comment|/* index of next packet desc. */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_ERNGSTAT_NEXT_S
value|16
end_define

begin_define
define|#
directive|define
name|SAFE_PE_IOTHRESH_INPUT
value|0x000003ff
end_define

begin_comment
comment|/* input threshold (dwords) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_IOTHRESH_OUTPUT
value|0x03ff0000
end_define

begin_comment
comment|/* output threshold (dwords) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SIZE
value|0x0000ffff
end_define

begin_comment
comment|/* scatter particle size */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_GBURST
value|0x00030000
end_define

begin_comment
comment|/* gather particle burst */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_GBURST_2
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_GBURST_4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_GBURST_8
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_GBURST_16
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SBURST
value|0x000c0000
end_define

begin_comment
comment|/* scatter particle burst */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SBURST_2
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SBURST_4
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SBURST_8
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTCFG_SBURST_16
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|SAFE_PE_PARTSIZE_SCAT
value|0xffff0000
end_define

begin_comment
comment|/* scatter particle ring size */
end_comment

begin_define
define|#
directive|define
name|SAFE_PE_PARTSIZE_GATH
value|0x0000ffff
end_define

begin_comment
comment|/* gather particle ring size */
end_comment

begin_define
define|#
directive|define
name|SAFE_CRYPTO_CTRL_3DES
value|0x00000001
end_define

begin_comment
comment|/* enable 3DES support */
end_comment

begin_define
define|#
directive|define
name|SAFE_CRYPTO_CTRL_PKEY
value|0x00010000
end_define

begin_comment
comment|/* enable public key support */
end_comment

begin_define
define|#
directive|define
name|SAFE_CRYPTO_CTRL_RNG
value|0x00020000
end_define

begin_comment
comment|/* enable RNG support */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_REV_MIN
value|0x0000000f
end_define

begin_comment
comment|/* minor rev for chip */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_REV_MAJ
value|0x000000f0
end_define

begin_comment
comment|/* major rev for chip */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_REV_MAJ_S
value|4
end_define

begin_define
define|#
directive|define
name|SAFE_DEVINFO_DES
value|0x00000100
end_define

begin_comment
comment|/* DES/3DES support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_ARC4
value|0x00000200
end_define

begin_comment
comment|/* ARC4 support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_AES
value|0x00000400
end_define

begin_comment
comment|/* AES support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_MD5
value|0x00001000
end_define

begin_comment
comment|/* MD5 support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_SHA1
value|0x00002000
end_define

begin_comment
comment|/* SHA-1 support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_RIPEMD
value|0x00004000
end_define

begin_comment
comment|/* RIPEMD support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_DEFLATE
value|0x00010000
end_define

begin_comment
comment|/* Deflate support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_SARAM
value|0x00100000
end_define

begin_comment
comment|/* on-chip SA RAM present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_EMIBUS
value|0x00200000
end_define

begin_comment
comment|/* EMI bus present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_PKEY
value|0x00400000
end_define

begin_comment
comment|/* public key support present */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEVINFO_RNG
value|0x00800000
end_define

begin_comment
comment|/* RNG present */
end_comment

begin_define
define|#
directive|define
name|SAFE_REV
parameter_list|(
name|_maj
parameter_list|,
name|_min
parameter_list|)
value|(((_maj)<< SAFE_DEVINFO_REV_MAJ_S) | (_min))
end_define

begin_define
define|#
directive|define
name|SAFE_REV_MAJ
parameter_list|(
name|_chiprev
parameter_list|)
define|\
value|(((_chiprev)& SAFE_DEVINFO_REV_MAJ)>> SAFE_DEVINFO_REV_MAJ_S)
end_define

begin_define
define|#
directive|define
name|SAFE_REV_MIN
parameter_list|(
name|_chiprev
parameter_list|)
value|((_chiprev)& SAFE_DEVINFO_REV_MIN)
end_define

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_MULT
value|0x00000001
end_define

begin_comment
comment|/* Multiply function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_SQUARE
value|0x00000004
end_define

begin_comment
comment|/* Square function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_ADD
value|0x00000010
end_define

begin_comment
comment|/* Add function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_SUB
value|0x00000020
end_define

begin_comment
comment|/* Subtract function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_LSHIFT
value|0x00000040
end_define

begin_comment
comment|/* Left-shift function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_RSHIFT
value|0x00000080
end_define

begin_comment
comment|/* Right-shift function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_DIV
value|0x00000100
end_define

begin_comment
comment|/* Divide function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_CMP
value|0x00000400
end_define

begin_comment
comment|/* Compare function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_COPY
value|0x00000800
end_define

begin_comment
comment|/* Copy function */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_EXP16
value|0x00002000
end_define

begin_comment
comment|/* Exponentiate (4-bit ACT) */
end_comment

begin_define
define|#
directive|define
name|SAFE_PK_FUNC_EXP4
value|0x00004000
end_define

begin_comment
comment|/* Exponentiate (2-bit ACT) */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_STAT_BUSY
value|0x00000001
end_define

begin_comment
comment|/* busy, data not valid */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_PRE_LFSR
value|0x00000001
end_define

begin_comment
comment|/* enable output pre-LFSR */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_TST_MODE
value|0x00000002
end_define

begin_comment
comment|/* enable test mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_TST_RUN
value|0x00000004
end_define

begin_comment
comment|/* start test state machine */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_ENA_RING1
value|0x00000008
end_define

begin_comment
comment|/* test entropy oscillator #1 */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_ENA_RING2
value|0x00000010
end_define

begin_comment
comment|/* test entropy oscillator #2 */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_DIS_ALARM
value|0x00000020
end_define

begin_comment
comment|/* disable RNG alarm reports */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_TST_CLOCK
value|0x00000040
end_define

begin_comment
comment|/* enable test clock */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_SHORTEN
value|0x00000080
end_define

begin_comment
comment|/* shorten state timers */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_TST_ALARM
value|0x00000100
end_define

begin_comment
comment|/* simulate alarm state */
end_comment

begin_define
define|#
directive|define
name|SAFE_RNG_CTRL_RST_LFSR
value|0x00000200
end_define

begin_comment
comment|/* reset LFSR */
end_comment

begin_comment
comment|/*  * Packet engine descriptor.  Note that d_csr is a copy of the  * SAFE_PE_CSR register and all definitions apply, and d_len  * is a copy of the SAFE_PE_LEN register and all definitions apply.  * d_src and d_len may point directly to contiguous data or to a  * list of ``particle descriptors'' when using scatter/gather i/o.  */
end_comment

begin_struct
struct|struct
name|safe_desc
block|{
name|u_int32_t
name|d_csr
decl_stmt|;
comment|/* per-packet control/status */
name|u_int32_t
name|d_src
decl_stmt|;
comment|/* source address */
name|u_int32_t
name|d_dst
decl_stmt|;
comment|/* destination address */
name|u_int32_t
name|d_sa
decl_stmt|;
comment|/* SA address */
name|u_int32_t
name|d_len
decl_stmt|;
comment|/* length, bypass, status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scatter/Gather particle descriptor.  *  * NB: scatter descriptors do not specify a size; this is fixed  *     by the setting of the SAFE_PE_PARTCFG register.  */
end_comment

begin_struct
struct|struct
name|safe_pdesc
block|{
name|u_int32_t
name|pd_addr
decl_stmt|;
comment|/* particle address */
name|u_int16_t
name|pd_flags
decl_stmt|;
comment|/* control word */
name|u_int16_t
name|pd_size
decl_stmt|;
comment|/* particle size (bytes) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SAFE_PD_READY
value|0x0001
end_define

begin_comment
comment|/* ready for processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_PD_DONE
value|0x0002
end_define

begin_comment
comment|/* h/w completed processing */
end_comment

begin_comment
comment|/*  * Security Association (SA) Record (Rev 1).  One of these is  * required for each operation processed by the packet engine.  */
end_comment

begin_struct
struct|struct
name|safe_sarec
block|{
name|u_int32_t
name|sa_cmd0
decl_stmt|;
name|u_int32_t
name|sa_cmd1
decl_stmt|;
name|u_int32_t
name|sa_resv0
decl_stmt|;
name|u_int32_t
name|sa_resv1
decl_stmt|;
name|u_int32_t
name|sa_key
index|[
literal|8
index|]
decl_stmt|;
comment|/* DES/3DES/AES key */
name|u_int32_t
name|sa_indigest
index|[
literal|5
index|]
decl_stmt|;
comment|/* inner digest */
name|u_int32_t
name|sa_outdigest
index|[
literal|5
index|]
decl_stmt|;
comment|/* outer digest */
name|u_int32_t
name|sa_spi
decl_stmt|;
comment|/* SPI */
name|u_int32_t
name|sa_seqnum
decl_stmt|;
comment|/* sequence number */
name|u_int32_t
name|sa_seqmask
index|[
literal|2
index|]
decl_stmt|;
comment|/* sequence number mask */
name|u_int32_t
name|sa_resv2
decl_stmt|;
name|u_int32_t
name|sa_staterec
decl_stmt|;
comment|/* address of state record */
name|u_int32_t
name|sa_resv3
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|sa_samgmt0
decl_stmt|;
comment|/* SA management field 0 */
name|u_int32_t
name|sa_samgmt1
decl_stmt|;
comment|/* SA management field 0 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP
value|0x00000007
end_define

begin_comment
comment|/* operation code */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP_CRYPT
value|0x00000000
end_define

begin_comment
comment|/* encrypt/decrypt (basic) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP_BOTH
value|0x00000001
end_define

begin_comment
comment|/* encrypt-hash/hash-decrypto */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP_HASH
value|0x00000003
end_define

begin_comment
comment|/* hash (outbound-only) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP_ESP
value|0x00000000
end_define

begin_comment
comment|/* ESP in/out (proto) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OP_AH
value|0x00000001
end_define

begin_comment
comment|/* AH in/out (proto) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_INBOUND
value|0x00000008
end_define

begin_comment
comment|/* inbound operation */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OUTBOUND
value|0x00000000
end_define

begin_comment
comment|/* outbound operation */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_GROUP
value|0x00000030
end_define

begin_comment
comment|/* operation group */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_BASIC
value|0x00000000
end_define

begin_comment
comment|/* basic operation */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PROTO
value|0x00000010
end_define

begin_comment
comment|/* protocol/packet operation */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_BUNDLE
value|0x00000020
end_define

begin_comment
comment|/* bundled operation (resvd) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PAD
value|0x000000c0
end_define

begin_comment
comment|/* crypto pad method */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PAD_IPSEC
value|0x00000000
end_define

begin_comment
comment|/* IPsec padding */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PAD_PKCS7
value|0x00000040
end_define

begin_comment
comment|/* PKCS#7 padding */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PAD_CONS
value|0x00000080
end_define

begin_comment
comment|/* constant padding */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_PAD_ZERO
value|0x000000c0
end_define

begin_comment
comment|/* zero padding */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_CRYPT_ALG
value|0x00000f00
end_define

begin_comment
comment|/* symmetric crypto algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_DES
value|0x00000000
end_define

begin_comment
comment|/* DES crypto algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_3DES
value|0x00000100
end_define

begin_comment
comment|/* 3DES crypto algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_AES
value|0x00000300
end_define

begin_comment
comment|/* AES crypto algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_CRYPT_NULL
value|0x00000f00
end_define

begin_comment
comment|/* null crypto algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HASH_ALG
value|0x0000f000
end_define

begin_comment
comment|/* hash algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_MD5
value|0x00000000
end_define

begin_comment
comment|/* MD5 hash algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_SHA1
value|0x00001000
end_define

begin_comment
comment|/* SHA-1 hash algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HASH_NULL
value|0x0000f000
end_define

begin_comment
comment|/* null hash algorithm */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HDR_PROC
value|0x00080000
end_define

begin_comment
comment|/* header processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IBUSID
value|0x00300000
end_define

begin_comment
comment|/* input bus id */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IPCI
value|0x00100000
end_define

begin_comment
comment|/* PCI input bus id */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OBUSID
value|0x00c00000
end_define

begin_comment
comment|/* output bus id */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OPCI
value|0x00400000
end_define

begin_comment
comment|/* PCI output bus id */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IVLD
value|0x03000000
end_define

begin_comment
comment|/* IV loading */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IVLD_NONE
value|0x00000000
end_define

begin_comment
comment|/* IV no load (reuse) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IVLD_IBUF
value|0x01000000
end_define

begin_comment
comment|/* IV load from input buffer */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IVLD_STATE
value|0x02000000
end_define

begin_comment
comment|/* IV load from state */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HSLD
value|0x0c000000
end_define

begin_comment
comment|/* hash state loading */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HSLD_SA
value|0x00000000
end_define

begin_comment
comment|/* hash state load from SA */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HSLD_STATE
value|0x08000000
end_define

begin_comment
comment|/* hash state load from state */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_HSLD_NONE
value|0x0c000000
end_define

begin_comment
comment|/* hash state no load */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_SAVEIV
value|0x10000000
end_define

begin_comment
comment|/* save IV */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_SAVEHASH
value|0x20000000
end_define

begin_comment
comment|/* save hash state */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_IGATHER
value|0x40000000
end_define

begin_comment
comment|/* input gather */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD0_OSCATTER
value|0x80000000
end_define

begin_comment
comment|/* output scatter */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_HDRCOPY
value|0x00000002
end_define

begin_comment
comment|/* copy header to output */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_PAYCOPY
value|0x00000004
end_define

begin_comment
comment|/* copy payload to output */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_PADCOPY
value|0x00000008
end_define

begin_comment
comment|/* copy pad to output */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_IPV4
value|0x00000000
end_define

begin_comment
comment|/* IPv4 protocol */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_IPV6
value|0x00000010
end_define

begin_comment
comment|/* IPv6 protocol */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_MUTABLE
value|0x00000020
end_define

begin_comment
comment|/* mutable bit processing */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_SRBUSID
value|0x000000c0
end_define

begin_comment
comment|/* state record bus id */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_SRPCI
value|0x00000040
end_define

begin_comment
comment|/* state record from PCI */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_CRMODE
value|0x00000300
end_define

begin_comment
comment|/* crypto mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_ECB
value|0x00000000
end_define

begin_comment
comment|/* ECB crypto mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_CBC
value|0x00000100
end_define

begin_comment
comment|/* CBC crypto mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_OFB
value|0x00000200
end_define

begin_comment
comment|/* OFB crypto mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_CFB
value|0x00000300
end_define

begin_comment
comment|/* CFB crypto mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_CRFEEDBACK
value|0x00000c00
end_define

begin_comment
comment|/* crypto feedback mode */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_64BIT
value|0x00000000
end_define

begin_comment
comment|/* 64-bit crypto feedback */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_8BIT
value|0x00000400
end_define

begin_comment
comment|/* 8-bit crypto feedback */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_1BIT
value|0x00000800
end_define

begin_comment
comment|/* 1-bit crypto feedback */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_128BIT
value|0x00000c00
end_define

begin_comment
comment|/* 128-bit crypto feedback */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_OPTIONS
value|0x00001000
end_define

begin_comment
comment|/* HMAC/options mutable bit */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_HMAC
value|SAFE_SA_CMD1_OPTIONS
end_define

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_SAREV1
value|0x00008000
end_define

begin_comment
comment|/* SA Revision 1 */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_OFFSET
value|0x00ff0000
end_define

begin_comment
comment|/* hash/crypto offset(dwords) */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_OFFSET_S
value|16
end_define

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_AESKEYLEN
value|0x0f000000
end_define

begin_comment
comment|/* AES key length */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_AES128
value|0x02000000
end_define

begin_comment
comment|/* 128-bit AES key */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_AES192
value|0x03000000
end_define

begin_comment
comment|/* 192-bit AES key */
end_comment

begin_define
define|#
directive|define
name|SAFE_SA_CMD1_AES256
value|0x04000000
end_define

begin_comment
comment|/* 256-bit AES key */
end_comment

begin_comment
comment|/*   * Security Associate State Record (Rev 1).  */
end_comment

begin_struct
struct|struct
name|safe_sastate
block|{
name|u_int32_t
name|sa_saved_iv
index|[
literal|4
index|]
decl_stmt|;
comment|/* saved IV (DES/3DES/AES) */
name|u_int32_t
name|sa_saved_hashbc
decl_stmt|;
comment|/* saved hash byte count */
name|u_int32_t
name|sa_saved_indigest
index|[
literal|5
index|]
decl_stmt|;
comment|/* saved inner digest */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SAFE_SAFEREG_H_ */
end_comment

end_unit

