begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Doug Rabson& Andrew Gallatin   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
value|(*(volatile int32_t *)				\ 				ALPHA_PHYS_TO_K0SEG(r + t2_csr_base))
end_define

begin_define
define|#
directive|define
name|REGVAL64
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int64_t *)				\ 				ALPHA_PHYS_TO_K0SEG(r + t2_csr_base))
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

end_unit

