begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2001 Doug Rabson& Andrew Gallatin   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Portions of this file were obtained from Compaq intellectual  * property which was made available under the following copyright:  *  * *****************************************************************  * *                                                               *  * *    Copyright Compaq Computer Corporation, 2000                *  * *                                                               *  * *   Permission to use, copy, modify, distribute, and sell       *  * *   this software and its documentation for any purpose is      *  * *   hereby granted without fee, provided that the above         *  * *   copyright notice appear in all copies and that both         *  * *   that copyright notice and this permission notice appear     *  * *   in supporting documentation, and that the name of           *  * *   Compaq Computer Corporation not be used in advertising      *  * *   or publicity pertaining to distribution of the software     *  * *   without specific, written prior permission.  Compaq         *  * *   makes no representations about the suitability of this      *  * *   software for any purpose.  It is provided "AS IS"           *  * *   without express or implied warranty.                        *  * *                                                               *  * *****************************************************************  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Registers in the T2 CBUS-to-PCI bridge as used in the SABLE  * systems.  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)				\ 				ALPHA_PHYS_TO_K0SEG(r + sable_lynx_base))
end_define

begin_define
define|#
directive|define
name|REGVAL64
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int64_t *)				\ 				ALPHA_PHYS_TO_K0SEG(r + sable_lynx_base))
end_define

begin_define
define|#
directive|define
name|SABLE_BASE
value|0x0UL
end_define

begin_comment
comment|/* offset of SABLE CSRs */
end_comment

begin_define
define|#
directive|define
name|LYNX_BASE
value|0x8000000000UL
end_define

begin_comment
comment|/* offset of LYNX CSRs */
end_comment

begin_define
define|#
directive|define
name|PCI0_BASE
value|0x38e000000UL
end_define

begin_define
define|#
directive|define
name|PCI1_BASE
value|0x38f000000UL
end_define

begin_define
define|#
directive|define
name|CBUS_BASE
value|0x380000000
end_define

begin_comment
comment|/* CBUS CSRs */
end_comment

begin_define
define|#
directive|define
name|T2_PCI_SIO
value|0x3a0000000
end_define

begin_comment
comment|/* PCI sparse I/O space */
end_comment

begin_define
define|#
directive|define
name|T2_PCI_CONF
value|0x390000000
end_define

begin_comment
comment|/* PCI configuration space */
end_comment

begin_define
define|#
directive|define
name|T2_PCI_SPARSE
value|0x200000000
end_define

begin_comment
comment|/* PCI sparse memory space */
end_comment

begin_define
define|#
directive|define
name|T2_PCI_DENSE
value|0x3c0000000
end_define

begin_comment
comment|/* PCI dense memory space */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSR
value|(CBUS_BASE + 0xe000000)
end_define

begin_comment
comment|/* Low word */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_EL
value|0x00000002UL
end_define

begin_comment
comment|/* loopback enable */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ESMV
value|0x00000004UL
end_define

begin_comment
comment|/* enable state machine visibility */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PDBP
value|0x00000008UL
end_define

begin_comment
comment|/* PCI drive bad parity */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_SLOT0
value|0x00000030UL
end_define

begin_comment
comment|/* PCI slot 0 present bits */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PINT
value|0x00000040UL
end_define

begin_comment
comment|/* PCI interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ENTLBEC
value|0x00000080UL
end_define

begin_comment
comment|/* enable TLB error check */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ENCCDMA
value|0x00000100UL
end_define

begin_comment
comment|/* enable CXACK for DMA */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ENXXCHG
value|0x00000400UL
end_define

begin_comment
comment|/* enable exclusive exchange for EV5 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_CAWWP0
value|0x00001000UL
end_define

begin_comment
comment|/* CBUS command/address write wrong parity 0 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_CAWWP2
value|0x00002000UL
end_define

begin_comment
comment|/* CBUS command/address write wrong parity 2 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_CDWWPE
value|0x00004000UL
end_define

begin_comment
comment|/* CBUS data write wrong parity even */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_SLOT2
value|0x00008000UL
end_define

begin_comment
comment|/* PCI slot 2 present bit */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PSERR
value|0x00010000UL
end_define

begin_comment
comment|/* power supply error */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_MBA7
value|0x00020000UL
end_define

begin_comment
comment|/* MBA7 asserted */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_SLOT1
value|0x000c0000UL
end_define

begin_comment
comment|/* PCI slot 1 present bits */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PDWWP1
value|0x00100000UL
end_define

begin_comment
comment|/* PCI DMA write wrong parity HW1 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PDWWP0
value|0x00200000UL
end_define

begin_comment
comment|/* PCI DMA write wrong parity HW0 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PBR
value|0x00400000UL
end_define

begin_comment
comment|/* PCI bus reset */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_PIR
value|0x00800000UL
end_define

begin_comment
comment|/* PCI interface reset */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ENCOI
value|0x01000000UL
end_define

begin_comment
comment|/* enable NOACK, CUCERR and out-of-sync int */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_EPMS
value|0x02000000UL
end_define

begin_comment
comment|/* enable PCI memory space */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ETLB
value|0x04000000UL
end_define

begin_comment
comment|/* enable TLB */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_EACC
value|0x08000000UL
end_define

begin_comment
comment|/* enable atomic CBUS cycles */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ITLB
value|0x10000000UL
end_define

begin_comment
comment|/* flush TLB */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_ECPC
value|0x20000000UL
end_define

begin_comment
comment|/* enable CBUS parity check */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_CIR
value|0x40000000UL
end_define

begin_comment
comment|/* CBUS interface reset */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRL_EPL
value|0x80000000UL
end_define

begin_comment
comment|/* enable PCI lock */
end_comment

begin_comment
comment|/* High word */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_CBBCE
value|0x00000001UL
end_define

begin_comment
comment|/* CBUS back-to-back cycle enable */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_TM
value|0x0000000eUL
end_define

begin_comment
comment|/* T2 revision number */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_SMVL
value|0x00000070UL
end_define

begin_comment
comment|/* state machine visibility select */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_SLOT2
value|0x00000080UL
end_define

begin_comment
comment|/* PCI slot 2 present bit */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EPR
value|0x00000100UL
end_define

begin_comment
comment|/* enable passive release */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_CAWWP1
value|0x00001000UL
end_define

begin_comment
comment|/* cbus command/address write wrong parity 1 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_CAWWP3
value|0x00002000UL
end_define

begin_comment
comment|/* cbus command/address write wrong parity 3 */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_DWWPO
value|0x00004000UL
end_define

begin_comment
comment|/* CBUS data write wrong parity odd */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_PRM
value|0x00100000UL
end_define

begin_comment
comment|/* PCI read multiple */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_PWM
value|0x00200000UL
end_define

begin_comment
comment|/* PCI write multiple */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_FPRDPED
value|0x00400000UL
end_define

begin_comment
comment|/* force PCI RDPE detect */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_PFAPED
value|0x00800000UL
end_define

begin_comment
comment|/* force PCI APE detect */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_FPWDPED
value|0x01000000UL
end_define

begin_comment
comment|/* force PCI WDPE detect */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EPNMI
value|0x02000000UL
end_define

begin_comment
comment|/* enable PCI NMI */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EPDTI
value|0x04000000UL
end_define

begin_comment
comment|/* enable PCI DTI */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EPSEI
value|0x08000000UL
end_define

begin_comment
comment|/* enable PCI SERR interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EPPEI
value|0x10000000UL
end_define

begin_comment
comment|/* enable PCI PERR interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_ERDPC
value|0x20000000UL
end_define

begin_comment
comment|/* enable PCI RDP interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EADPC
value|0x40000000UL
end_define

begin_comment
comment|/* enable PCI AP interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_IOCSRH_EWDPC
value|0x80000000UL
end_define

begin_comment
comment|/* enable PCI WDP interrupt */
end_comment

begin_define
define|#
directive|define
name|T2_CERR1
value|(CBUS_BASE + 0xe000020)
end_define

begin_define
define|#
directive|define
name|T2_CERR2
value|(CBUS_BASE + 0xe000040)
end_define

begin_define
define|#
directive|define
name|T2_CERR3
value|(CBUS_BASE + 0xe000060)
end_define

begin_define
define|#
directive|define
name|T2_PERR1
value|(CBUS_BASE + 0xe000080)
end_define

begin_define
define|#
directive|define
name|T2_PERR1_PWDPE
value|0x00000001
end_define

begin_comment
comment|/* PCI write data parity error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_PAPE
value|0x00000002
end_define

begin_comment
comment|/* PCI address parity error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_PRDPE
value|0x00000004
end_define

begin_comment
comment|/* PCI read data parity error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_PPE
value|0x00000008
end_define

begin_comment
comment|/* PCI parity error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_PSE
value|0x00000010
end_define

begin_comment
comment|/* PCI system error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_PDTE
value|0x00000020
end_define

begin_comment
comment|/* PCI device timeout error */
end_comment

begin_define
define|#
directive|define
name|T2_PERR1_NMI
value|0x00000040
end_define

begin_comment
comment|/* PCI NMI */
end_comment

begin_define
define|#
directive|define
name|T2_PERR2
value|(CBUS_BASE + 0xe0000a0)
end_define

begin_define
define|#
directive|define
name|T2_PSCR
value|(CBUS_BASE + 0xe0000c0)
end_define

begin_define
define|#
directive|define
name|T2_HAE0_1
value|(CBUS_BASE + 0xe0000e0)
end_define

begin_define
define|#
directive|define
name|T2_HAE0_2
value|(CBUS_BASE + 0xe000100)
end_define

begin_define
define|#
directive|define
name|T2_HBASE
value|(CBUS_BASE + 0xe000120)
end_define

begin_define
define|#
directive|define
name|T2_WBASE1
value|(CBUS_BASE + 0xe000140)
end_define

begin_define
define|#
directive|define
name|T2_WMASK1
value|(CBUS_BASE + 0xe000160)
end_define

begin_define
define|#
directive|define
name|T2_TBASE1
value|(CBUS_BASE + 0xe000180)
end_define

begin_define
define|#
directive|define
name|T2_WBASE2
value|(CBUS_BASE + 0xe0001a0)
end_define

begin_define
define|#
directive|define
name|T2_WMASK2
value|(CBUS_BASE + 0xe0001c0)
end_define

begin_define
define|#
directive|define
name|T2_TBASE2
value|(CBUS_BASE + 0xe0001e0)
end_define

begin_define
define|#
directive|define
name|T2_TLBBR
value|(CBUS_BASE + 0xe000200)
end_define

begin_define
define|#
directive|define
name|T2_HAE0_3
value|(CBUS_BASE + 0xe000240)
end_define

begin_define
define|#
directive|define
name|T2_HAE0_4
value|(CBUS_BASE + 0xe000280)
end_define

begin_comment
comment|/*  * DMA window constants, section 5.2.1.1.1 of the   * Sable I/O Specification  */
end_comment

begin_define
define|#
directive|define
name|T2_WINDOW_ENABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|T2_WINDOW_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|T2_WINDOW_SG
value|0x00040000
end_define

begin_define
define|#
directive|define
name|T2_WINDOW_DIRECT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_2G
value|0x7ff00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_1G
value|0x3ff00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_512M
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_256M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_128M
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_64M
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_32M
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_16M
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_8M
value|0x00700000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_4M
value|0x00300000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_2M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|T2_WMASK_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_2G
value|0x80000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_1G
value|0x40000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_512M
value|0x20000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_256M
value|0x10000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_128M
value|0x08000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_64M
value|0x04000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_32M
value|0x02000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_16M
value|0x01000000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_8M
value|0x00800000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_4M
value|0x00400000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_2M
value|0x00200000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_1M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|T2_WSIZE_0M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|T2_TBASE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MASTER_ICU
value|0x535
end_define

begin_define
define|#
directive|define
name|SLAVE0_ICU
value|0x537
end_define

begin_define
define|#
directive|define
name|SLAVE1_ICU
value|0x53b
end_define

begin_define
define|#
directive|define
name|SLAVE2_ICU
value|0x53d
end_define

begin_define
define|#
directive|define
name|SLAVE3_ICU
value|0x53f
end_define

begin_define
define|#
directive|define
name|T2_EISA_IRQ_TO_STDIO_IRQ
parameter_list|(
name|x
parameter_list|)
value|((x) + 7)
end_define

begin_define
define|#
directive|define
name|T2_STDIO_IRQ_TO_EISA_IRQ
parameter_list|(
name|x
parameter_list|)
value|((x) - 7)
end_define

begin_define
define|#
directive|define
name|STDIO_PCI0_IRQ_TO_SCB_VECTOR
parameter_list|(
name|x
parameter_list|)
value|(( ( x ) * 0x10) + 0x800)
end_define

begin_define
define|#
directive|define
name|STDIO_PCI1_IRQ_TO_SCB_VECTOR
parameter_list|(
name|x
parameter_list|)
value|(( ( x ) * 0x10) + 0xC00)
end_define

begin_comment
comment|/*  * T4  Control and Status Registers  *  * All CBUS CSRs in the Cbus2 IO subsystems are in the T4 gate array.  The  * CBUS CSRs in the T4 are all aligned on hexaword boundaries and have   * quadword length.  Note, this structure also works for T2 as the T2  * registers are a proper subset of the T3/T4's.  Just make sure  * that T2 code does not reference T3/T4-only registers.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|iocsr
decl_stmt|;
name|u_long
name|fill_00
index|[
literal|3
index|]
decl_stmt|;
comment|/* I/O Control/Status */
name|u_long
name|cerr1
decl_stmt|;
name|u_long
name|fill_01
index|[
literal|3
index|]
decl_stmt|;
comment|/* Cbus Error Register 1 */
name|u_long
name|cerr2
decl_stmt|;
name|u_long
name|fill_02
index|[
literal|3
index|]
decl_stmt|;
comment|/* Cbus Error Register 2 */
name|u_long
name|cerr3
decl_stmt|;
name|u_long
name|fill_03
index|[
literal|3
index|]
decl_stmt|;
comment|/* Cbus Error Register 3 */
name|u_long
name|pcierr1
decl_stmt|;
name|u_long
name|fill_04
index|[
literal|3
index|]
decl_stmt|;
comment|/* PCI Error Register 1 */
name|u_long
name|pcierr2
decl_stmt|;
name|u_long
name|fill_05
index|[
literal|3
index|]
decl_stmt|;
comment|/* PCI Error Register 2 */
name|u_long
name|pciscr
decl_stmt|;
name|u_long
name|fill_06
index|[
literal|3
index|]
decl_stmt|;
comment|/* PCI Special Cycle  */
name|u_long
name|hae0_1
decl_stmt|;
name|u_long
name|fill_07
index|[
literal|3
index|]
decl_stmt|;
comment|/* High Address Extension 1 */
name|u_long
name|hae0_2
decl_stmt|;
name|u_long
name|fill_08
index|[
literal|3
index|]
decl_stmt|;
comment|/* High Address Extension 2 */
name|u_long
name|hbase
decl_stmt|;
name|u_long
name|fill_09
index|[
literal|3
index|]
decl_stmt|;
comment|/* PCI Hole Base */
name|u_long
name|wbase1
decl_stmt|;
name|u_long
name|fill_0a
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Base 1 */
name|u_long
name|wmask1
decl_stmt|;
name|u_long
name|fill_0b
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Mask 1 */
name|u_long
name|tbase1
decl_stmt|;
name|u_long
name|fill_0c
index|[
literal|3
index|]
decl_stmt|;
comment|/* Translated Base 1 */
name|u_long
name|wbase2
decl_stmt|;
name|u_long
name|fill_0d
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Base 2 */
name|u_long
name|wmask2
decl_stmt|;
name|u_long
name|fill_0e
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Mask 2 */
name|u_long
name|tbase2
decl_stmt|;
name|u_long
name|fill_0f
index|[
literal|3
index|]
decl_stmt|;
comment|/* Translated Base 2 */
name|u_long
name|tlbbr
decl_stmt|;
name|u_long
name|fill_10
index|[
literal|3
index|]
decl_stmt|;
comment|/* TLB by-pass */
name|u_long
name|ivr
decl_stmt|;
name|u_long
name|fill_11
index|[
literal|3
index|]
decl_stmt|;
comment|/* IVR Passive Rels/Intr Addr  (reserved on T3/T4) */
name|u_long
name|hae0_3
decl_stmt|;
name|u_long
name|fill_12
index|[
literal|3
index|]
decl_stmt|;
comment|/* High Address Extension 3 */
name|u_long
name|hae0_4
decl_stmt|;
name|u_long
name|fill_13
index|[
literal|3
index|]
decl_stmt|;
comment|/* High Address Extension 4 */
name|u_long
name|wbase3
decl_stmt|;
name|u_long
name|fill_14
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Base 3 */
name|u_long
name|wmask3
decl_stmt|;
name|u_long
name|fill_15
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Mask 3 */
name|u_long
name|tbase3
decl_stmt|;
name|u_long
name|fill_16
index|[
literal|3
index|]
decl_stmt|;
comment|/* Translated Base 3 */
name|u_long
name|rsvd1
decl_stmt|;
name|u_long
name|fill_16a
index|[
literal|3
index|]
decl_stmt|;
comment|/* unused location */
name|u_long
name|tdr0
decl_stmt|;
name|u_long
name|fill_17
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 0 */
name|u_long
name|tdr1
decl_stmt|;
name|u_long
name|fill_18
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 1 */
name|u_long
name|tdr2
decl_stmt|;
name|u_long
name|fill_19
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 2 */
name|u_long
name|tdr3
decl_stmt|;
name|u_long
name|fill_1a
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 3 */
name|u_long
name|tdr4
decl_stmt|;
name|u_long
name|fill_1b
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 4 */
name|u_long
name|tdr5
decl_stmt|;
name|u_long
name|fill_1c
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 5 */
name|u_long
name|tdr6
decl_stmt|;
name|u_long
name|fill_1d
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 6 */
name|u_long
name|tdr7
decl_stmt|;
name|u_long
name|fill_1e
index|[
literal|3
index|]
decl_stmt|;
comment|/* tlb data register 7 */
name|u_long
name|wbase4
decl_stmt|;
name|u_long
name|fill_1f
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Base 4 */
name|u_long
name|wmask4
decl_stmt|;
name|u_long
name|fill_20
index|[
literal|3
index|]
decl_stmt|;
comment|/* Window Mask 4 */
name|u_long
name|tbase4
decl_stmt|;
name|u_long
name|fill_21
index|[
literal|3
index|]
decl_stmt|;
comment|/* Translated Base 4 */
comment|/*  * The following 4 registers are used to get to the ICIC chip  */
name|u_long
name|air
decl_stmt|;
name|u_long
name|fill_22
index|[
literal|3
index|]
decl_stmt|;
comment|/* Address Indirection register */
name|u_long
name|var
decl_stmt|;
name|u_long
name|fill_23
index|[
literal|3
index|]
decl_stmt|;
comment|/* Vector access register */
name|u_long
name|dir
decl_stmt|;
name|u_long
name|fill_24
index|[
literal|3
index|]
decl_stmt|;
comment|/* Data Indirection register */
name|u_long
name|ice
decl_stmt|;
name|u_long
name|fill_25
index|[
literal|3
index|]
decl_stmt|;
comment|/* IC enable register Indirection register */
block|}
name|t2_csr_t
typedef|;
end_typedef

end_unit

