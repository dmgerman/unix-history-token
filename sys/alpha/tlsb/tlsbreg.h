begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: tlsbreg.h,v 1.5 2000/01/27 22:27:50 mjacob Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Based in part upon a prototype version by Jason Thorpe  * Copyright (c) 1996 by Jason Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Definitions for the TurboLaser System Bus found on  * AlphaServer 8200/8400 systems.  */
end_comment

begin_comment
comment|/*  * There are 9 TurboLaser nodes, 0 though 8.  Their uses are defined as  * follows:  *  *	Node	Module  *	----    ------  *	0	CPU, Memory  *	1	CPU, Memory  *	2	CPU, Memory  *	3	CPU, Memory  *	4	CPU, Memory, I/O  *	5	CPU, Memory, I/O  *	6	CPU, Memory, I/O  *	7	CPU, Memory, I/O  *	8	I/O  *  * A node occurs every 0x00400000 bytes.  *  * Note, the AlphaServer 8200 only has nodes 4 though 8.  */
end_comment

begin_define
define|#
directive|define
name|TLSB_NODE_BASE
value|0x000000ff88000000
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TLSB_NODE_SIZE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|TLSB_NODE_MAX
value|8
end_define

begin_comment
comment|/* inclusive */
end_comment

begin_comment
comment|/* Translate a node number to an address. */
end_comment

begin_define
define|#
directive|define
name|TLSB_NODE_ADDR
parameter_list|(
name|_node
parameter_list|)
define|\
value|(long)(TLSB_NODE_BASE + ((_node) * TLSB_NODE_SIZE))
end_define

begin_define
define|#
directive|define
name|TLSB_NODE_REG_ADDR
parameter_list|(
name|_node
parameter_list|,
name|_reg
parameter_list|)
define|\
value|KV((long)TLSB_NODE_ADDR((_node)) + (_reg))
end_define

begin_comment
comment|/* Access the specified register on the specified node. */
end_comment

begin_define
define|#
directive|define
name|TLSB_GET_NODEREG
parameter_list|(
name|_node
parameter_list|,
name|_reg
parameter_list|)
define|\
value|*(volatile u_int32_t *)(TLSB_NODE_REG_ADDR((_node), (_reg)))
end_define

begin_define
define|#
directive|define
name|TLSB_PUT_NODEREG
parameter_list|(
name|_node
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|*(volatile u_int32_t *)(TLSB_NODE_REG_ADDR((_node), (_reg))) = (_val)
end_define

begin_comment
comment|/*  * Some registers are shared by all TurboLaser nodes, and appear in  * the TurboLaser Broadcast space.  */
end_comment

begin_define
define|#
directive|define
name|TLSB_BCAST_BASE
value|0x000000ff8e000000
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TLSB_BCAST_REG_ADDR
parameter_list|(
name|_reg
parameter_list|)
value|KV((long)(TLSB_BCASE_BASE + (_reg)))
end_define

begin_comment
comment|/* Access the specified register in the broadcast space. */
end_comment

begin_define
define|#
directive|define
name|TLSB_GET_BCASTREG
parameter_list|(
name|_reg
parameter_list|)
define|\
value|*(volatile u_int32_t *)(TLSB_BCAST_REG_ADDR + (_reg))
end_define

begin_define
define|#
directive|define
name|TLSB_PUT_BCASTREG
parameter_list|(
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|*(volatile u_int32_t *)(TLSB_BCAST_REG_ADDR + (_reg)) = (_val)
end_define

begin_comment
comment|/*  * Location of the Gbus, the per-CPU bus containing the clock and  * console hardware.  */
end_comment

begin_define
define|#
directive|define
name|TLSB_GBUS_BASE
value|0x000000ff90000000
end_define

begin_comment
comment|/* Dense */
end_comment

begin_comment
comment|/*  * Note that not every module type supports each TurboLaser register.  * The following defines the keys used to denote module support for  * a given register:  *  *	C	Supported by CPU module  *	M	Supported by Memory module  *	I	Supported by I/O module  */
end_comment

begin_comment
comment|/*  * Per-node TurboLaser System Bus registers, offsets from the  * base of the node.  */
end_comment

begin_define
define|#
directive|define
name|TLDEV
value|0x0000
end_define

begin_comment
comment|/* CMI: Device Register */
end_comment

begin_define
define|#
directive|define
name|TLBER
value|0x0040
end_define

begin_comment
comment|/* CMI: Bus Error Register */
end_comment

begin_define
define|#
directive|define
name|TLCNR
value|0x0080
end_define

begin_comment
comment|/* CMI: Congfiguration Register */
end_comment

begin_define
define|#
directive|define
name|TLVID
value|0x00c0
end_define

begin_comment
comment|/* CM: Virtual ID Register */
end_comment

begin_define
define|#
directive|define
name|TLMMR0
value|0x0200
end_define

begin_comment
comment|/* CM: Memory Mapping Register 0 */
end_comment

begin_define
define|#
directive|define
name|TLMMR1
value|0x0240
end_define

begin_comment
comment|/* CM: Memory Mapping Register 1 */
end_comment

begin_define
define|#
directive|define
name|TLMMR2
value|0x0280
end_define

begin_comment
comment|/* CM: Memory Mapping Register 2 */
end_comment

begin_define
define|#
directive|define
name|TLMMR3
value|0x02c0
end_define

begin_comment
comment|/* CM: Memory Mapping Register 3 */
end_comment

begin_define
define|#
directive|define
name|TLMMR4
value|0x0300
end_define

begin_comment
comment|/* CM: Memory Mapping Register 4 */
end_comment

begin_define
define|#
directive|define
name|TLMMR5
value|0x0340
end_define

begin_comment
comment|/* CM: Memory Mapping Register 5 */
end_comment

begin_define
define|#
directive|define
name|TLMMR6
value|0x0380
end_define

begin_comment
comment|/* CM: Memory Mapping Register 6 */
end_comment

begin_define
define|#
directive|define
name|TLMMR7
value|0x03c0
end_define

begin_comment
comment|/* CM: Memory Mapping Register 7 */
end_comment

begin_define
define|#
directive|define
name|TLFADR0
value|0x0600
end_define

begin_comment
comment|/* MI: Failing Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|TLFADR1
value|0x0640
end_define

begin_comment
comment|/* MI: Failing Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|TLESR0
value|0x0680
end_define

begin_comment
comment|/* CMI: Error Syndrome Register 0 */
end_comment

begin_define
define|#
directive|define
name|TLESR1
value|0x06c0
end_define

begin_comment
comment|/* CMI: Error Syndrome Register 1 */
end_comment

begin_define
define|#
directive|define
name|TLESR2
value|0x0700
end_define

begin_comment
comment|/* CMI: Error Syndrome Register 2 */
end_comment

begin_define
define|#
directive|define
name|TLESR3
value|0x0740
end_define

begin_comment
comment|/* CMI: Error Syndrome Register 3 */
end_comment

begin_define
define|#
directive|define
name|TLILID0
value|0x0a00
end_define

begin_comment
comment|/* I: Int. Level 0 IDENT Register */
end_comment

begin_define
define|#
directive|define
name|TLILID1
value|0x0a40
end_define

begin_comment
comment|/* I: Int. Level 1 IDENT Register */
end_comment

begin_define
define|#
directive|define
name|TLILID2
value|0x0a80
end_define

begin_comment
comment|/* I: Int. Level 2 IDENT Register */
end_comment

begin_define
define|#
directive|define
name|TLILID3
value|0x0ac0
end_define

begin_comment
comment|/* I: Int. Level 3 IDENT Register */
end_comment

begin_define
define|#
directive|define
name|TLCPUMASK
value|0x0b00
end_define

begin_comment
comment|/* I: CPU Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|TLMBPTR
value|0x0c00
end_define

begin_comment
comment|/* I: Mailbox Pointer Register */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK0
value|0x1100
end_define

begin_comment
comment|/* C: Interrupt Mask Register CPU 0 */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK1
value|0x1140
end_define

begin_comment
comment|/* C: Interrupt Mask Register CPU 1 */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM0
value|0x1180
end_define

begin_comment
comment|/* C: Interrupt Sum Register CPU 0 */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM1
value|0x11C0
end_define

begin_comment
comment|/* C: Interrupt Sum Register CPU 1 */
end_comment

begin_define
define|#
directive|define
name|TLEPAERR
value|0x1500
end_define

begin_comment
comment|/* C: ADG error register */
end_comment

begin_define
define|#
directive|define
name|TLEPDERR
value|0x1540
end_define

begin_comment
comment|/* C: DIGA error register */
end_comment

begin_define
define|#
directive|define
name|TLEPMERR
value|0x1580
end_define

begin_comment
comment|/* C: MMG error register */
end_comment

begin_define
define|#
directive|define
name|TLDMCMD
value|0x1600
end_define

begin_comment
comment|/* C: Data Mover Command */
end_comment

begin_define
define|#
directive|define
name|TLDMADRA
value|0x1680
end_define

begin_comment
comment|/* C: Data Mover Source */
end_comment

begin_define
define|#
directive|define
name|TLDMADRB
value|0x16C0
end_define

begin_comment
comment|/* C: Data Mover Destination */
end_comment

begin_comment
comment|/*  * Registers shared between TurboLaser nodes, offsets from the  * TurboLaser Broadcast Base.  */
end_comment

begin_define
define|#
directive|define
name|TLPRIVATE
value|0x0000
end_define

begin_comment
comment|/* CMI: private "global" space */
end_comment

begin_define
define|#
directive|define
name|TLIPINTR
value|0x0040
end_define

begin_comment
comment|/* C: Interprocessor Int. Register */
end_comment

begin_define
define|#
directive|define
name|TLIOINTR4
value|0x0100
end_define

begin_comment
comment|/* C: I/O Interrupt Register 4 */
end_comment

begin_define
define|#
directive|define
name|TLIOINTR5
value|0x0140
end_define

begin_comment
comment|/* C: I/O Interrupt Register 5 */
end_comment

begin_define
define|#
directive|define
name|TLIOINTR6
value|0x0180
end_define

begin_comment
comment|/* C: I/O Interrupt Register 6 */
end_comment

begin_define
define|#
directive|define
name|TLIOINTR7
value|0x01c0
end_define

begin_comment
comment|/* C: I/O Interrupt Register 7 */
end_comment

begin_define
define|#
directive|define
name|TLIOINTR8
value|0x0200
end_define

begin_comment
comment|/* C: I/O Interrupt Register 8 */
end_comment

begin_define
define|#
directive|define
name|TLWSDQR4
value|0x0400
end_define

begin_comment
comment|/* C: Win Spc Dcr Que Ctr Reg 4 */
end_comment

begin_define
define|#
directive|define
name|TLWSDQR5
value|0x0440
end_define

begin_comment
comment|/* C: Win Spc Dcr Que Ctr Reg 5 */
end_comment

begin_define
define|#
directive|define
name|TLWSDQR6
value|0x0480
end_define

begin_comment
comment|/* C: Win Spc Dcr Que Ctr Reg 6 */
end_comment

begin_define
define|#
directive|define
name|TLWSDQR7
value|0x04c0
end_define

begin_comment
comment|/* C: Win Spc Dcr Que Ctr Reg 7 */
end_comment

begin_define
define|#
directive|define
name|TLWSDQR8
value|0x0500
end_define

begin_comment
comment|/* C: Win Spc Dcr Que Ctr Reg 8 */
end_comment

begin_define
define|#
directive|define
name|TLRMDQRX
value|0x0600
end_define

begin_comment
comment|/* C: Mem Chan Dcr Que Ctr Reg X */
end_comment

begin_define
define|#
directive|define
name|TLRMDQR8
value|0x0640
end_define

begin_comment
comment|/* C: Mem Chan Dcr Que Ctr Reg 8 */
end_comment

begin_define
define|#
directive|define
name|TLRDRD
value|0x0800
end_define

begin_comment
comment|/* C: CSR Read Data Rtn Data Reg */
end_comment

begin_define
define|#
directive|define
name|TLRDRE
value|0x0840
end_define

begin_comment
comment|/* C: CSR Read Data Rtn Error Reg */
end_comment

begin_define
define|#
directive|define
name|TLMCR
value|0x1880
end_define

begin_comment
comment|/* M: Memory Control Register */
end_comment

begin_comment
comment|/*  * TLDEV - Device Register  *  * Access: R/W  *  * Notes:  *	Register is loaded during initialization with information  *	that identifies a node.  A zero value indicates a non-initialized  *	(slot empty) node.  *  *	Bits 0-15 contain the hardware device type, bits 16-23  *	the board's software revision, and bits 24-31 the board's  *	hardware revision.  *  *	The device type portion is laid out as follows:  *  *		Bit 15: identifies a CPU  *		Bit 14: identifies a memory board  *		Bit 13: identifies an I/O board  *		Bits 0-7: specify the ID of a node type  */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|TLDEV_DTYPE_KFTHA
value|0x2000
end_define

begin_comment
comment|/* KFTHA board, I/O */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_KFTIA
value|0x2020
end_define

begin_comment
comment|/* KFTIA board, I/O */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_MS7CC
value|0x5000
end_define

begin_comment
comment|/* Memory board */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_SCPU4
value|0x8011
end_define

begin_comment
comment|/* 1 CPU, 4mb cache */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_SCPU16
value|0x8012
end_define

begin_comment
comment|/* 1 CPU, 16mb cache */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_DCPU4
value|0x8014
end_define

begin_comment
comment|/* 2 CPU, 4mb cache */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE_DCPU16
value|0x8015
end_define

begin_comment
comment|/* 2 CPU, 16mb cache */
end_comment

begin_define
define|#
directive|define
name|TLDEV_DTYPE
parameter_list|(
name|_val
parameter_list|)
value|((_val)& TLDEV_DTYPE_MASK)
end_define

begin_define
define|#
directive|define
name|TLDEV_ISCPU
parameter_list|(
name|_val
parameter_list|)
value|(TLDEV_DTYPE(_val)& 0x8000)
end_define

begin_define
define|#
directive|define
name|TLDEV_ISMEM
parameter_list|(
name|_val
parameter_list|)
value|(TLDEV_DTYPE(_val)& 0x4000)
end_define

begin_define
define|#
directive|define
name|TLDEV_ISIOPORT
parameter_list|(
name|_val
parameter_list|)
value|(TLDEV_DTYPE(_val)& 0x2000)
end_define

begin_define
define|#
directive|define
name|TLDEV_SWREV
parameter_list|(
name|_val
parameter_list|)
value|(((_val)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|TLDEV_HWREV
parameter_list|(
name|_val
parameter_list|)
value|(((_val)>> 24)& 0xff)
end_define

begin_comment
comment|/*  * TLBER - Bus Error Register  *  * Access: R/W  *  * Notes:  *	This register contains information about TLSB errors detected by  *	nodes on the TLSB.  The register will become locked when:  *  *		* Any error occurs and the "lock on first error"  *		  bit of the Configuration Register is set.  *  *		* Any bit other than 20-23 (DS0-DS3) becomes set.  *  *	and will remain locked until either:  *  *		* All bits in the TLBER are cleared.  *  *		* The "lock on first error" bit is cleared.  *  *	TLBER locking is intended for diagnosic purposes only, and  *	not for general use.  */
end_comment

begin_define
define|#
directive|define
name|TLBER_ATCE
value|0x00000001
end_define

begin_comment
comment|/* Addr Transmit Ck Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_APE
value|0x00000002
end_define

begin_comment
comment|/* Addr Parity Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_BAE
value|0x00000004
end_define

begin_comment
comment|/* Bank Avail Violation Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_LKTO
value|0x00000008
end_define

begin_comment
comment|/* Bank Lock Timeout */
end_comment

begin_define
define|#
directive|define
name|TLBER_NAE
value|0x00000010
end_define

begin_comment
comment|/* No Ack Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_RTCE
value|0x00000020
end_define

begin_comment
comment|/* Read Transmit Ck Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_ACKTCE
value|0x00000040
end_define

begin_comment
comment|/* Ack Transmit Ck Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_MMRE
value|0x00000080
end_define

begin_comment
comment|/* Mem Mapping Register Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_FNAE
value|0x00000100
end_define

begin_comment
comment|/* Fatal No Ack Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_REQDE
value|0x00000200
end_define

begin_comment
comment|/* Request Deassertion Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_ATDE
value|0x00000400
end_define

begin_comment
comment|/* Addredd Transmitter During Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_UDE
value|0x00010000
end_define

begin_comment
comment|/* Uncorrectable Data Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_CWDE
value|0x00020000
end_define

begin_comment
comment|/* Correctable Write Data Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_CRDE
value|0x00040000
end_define

begin_comment
comment|/* Correctable Read Data Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_CRDE2
value|0x00080000
end_define

begin_comment
comment|/* ...ditto... */
end_comment

begin_define
define|#
directive|define
name|TLBER_DS0
value|0x00100000
end_define

begin_comment
comment|/* Data Synd 0 */
end_comment

begin_define
define|#
directive|define
name|TLBER_DS1
value|0x00200000
end_define

begin_comment
comment|/* Data Synd 1 */
end_comment

begin_define
define|#
directive|define
name|TLBER_DS2
value|0x00400000
end_define

begin_comment
comment|/* Data Synd 2 */
end_comment

begin_define
define|#
directive|define
name|TLBER_DS3
value|0x00800000
end_define

begin_comment
comment|/* Data Synd 3 */
end_comment

begin_define
define|#
directive|define
name|TLBER_DTDE
value|0x01000000
end_define

begin_comment
comment|/* Data Transmitter During Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_FDTCE
value|0x02000000
end_define

begin_comment
comment|/* Fatal Data Transmit Ck Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_UACKE
value|0x04000000
end_define

begin_comment
comment|/* Unexpected Ack Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_ABTCE
value|0x08000000
end_define

begin_comment
comment|/* Addr Bus Transmit Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_DCTCE
value|0x10000000
end_define

begin_comment
comment|/* Data Control Transmit Ck Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_SEQE
value|0x20000000
end_define

begin_comment
comment|/* Sequence Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_DSE
value|0x40000000
end_define

begin_comment
comment|/* Data Status Error */
end_comment

begin_define
define|#
directive|define
name|TLBER_DTO
value|0x80000000
end_define

begin_comment
comment|/* Data Timeout Error */
end_comment

begin_comment
comment|/*  * TLCNR - Configuration Register  *  * Access: R/W  */
end_comment

begin_define
define|#
directive|define
name|TLCNR_CWDD
value|0x00000001
end_define

begin_comment
comment|/* Corr Write Data Err INTR Dis */
end_comment

begin_define
define|#
directive|define
name|TLCNR_CRDD
value|0x00000002
end_define

begin_comment
comment|/* Corr Read Data Err INTR Dis */
end_comment

begin_define
define|#
directive|define
name|TLCNR_LKTOD
value|0x00000004
end_define

begin_comment
comment|/* Bank Lock Timeout Disable */
end_comment

begin_define
define|#
directive|define
name|TLCNR_DTOD
value|0x00000008
end_define

begin_comment
comment|/* Data Timeout Disable */
end_comment

begin_define
define|#
directive|define
name|TLCNR_STF_A
value|0x00001000
end_define

begin_comment
comment|/* Self-Test Fail A */
end_comment

begin_define
define|#
directive|define
name|TLCNR_STF_B
value|0x00002000
end_define

begin_comment
comment|/* Self-Test Fail B */
end_comment

begin_define
define|#
directive|define
name|TLCNR_HALT_A
value|0x00100000
end_define

begin_comment
comment|/* Halt A */
end_comment

begin_define
define|#
directive|define
name|TLCNR_HALT_B
value|0x00200000
end_define

begin_comment
comment|/* Halt B */
end_comment

begin_define
define|#
directive|define
name|TLCNR_RSTSTAT
value|0x10000000
end_define

begin_comment
comment|/* Reset Status */
end_comment

begin_define
define|#
directive|define
name|TLCNR_NRST
value|0x40000000
end_define

begin_comment
comment|/* Node Reset */
end_comment

begin_define
define|#
directive|define
name|TLCNR_LOFE
value|0x80000000
end_define

begin_comment
comment|/* Lock On First Error */
end_comment

begin_define
define|#
directive|define
name|TLCNR_NODE_MASK
value|0x000000f0
end_define

begin_comment
comment|/* Node ID mask */
end_comment

begin_define
define|#
directive|define
name|TLCNR_NODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TLCNR_VCNT_MASK
value|0x00000f00
end_define

begin_comment
comment|/* VCNT mask */
end_comment

begin_define
define|#
directive|define
name|TLCNR_VCNT_SHIFT
value|8
end_define

begin_comment
comment|/*  * TLVID - Virtual ID Register  *  * Access: R/W  *  * Notes:  *	Virtual units can be CPUs or Memory boards.  The units are  *	are addressed using virtual IDs.  These virtual IDs are assigned  *	by writing to the TLVID register.  The upper 24 bits of this  *	register are reserved and must be written as `0'.  */
end_comment

begin_define
define|#
directive|define
name|TLVID_VIDA_MASK
value|0x0000000f
end_define

begin_comment
comment|/* Virtual ID for unit 0 */
end_comment

begin_define
define|#
directive|define
name|TLVID_VIDA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TLVID_VIDB_MASK
value|0x000000f0
end_define

begin_comment
comment|/* Virtual ID for unit 1 */
end_comment

begin_define
define|#
directive|define
name|TLVID_VIDB_SHIFT
value|4
end_define

begin_comment
comment|/*  * TLMMRn - Memory Mapping Registers  *  * Access: W  *  * Notes:  *	Contains mapping information for doing a bank-decode.  */
end_comment

begin_define
define|#
directive|define
name|TLMMR_INTMASK
value|0x00000003
end_define

begin_comment
comment|/* Valid bits in Interleave */
end_comment

begin_define
define|#
directive|define
name|TLMMR_ADRMASK
value|0x000000f0
end_define

begin_comment
comment|/* Valid bits in Address */
end_comment

begin_define
define|#
directive|define
name|TLMMR_SBANK
value|0x00000800
end_define

begin_comment
comment|/* Single-bank indicator */
end_comment

begin_define
define|#
directive|define
name|TLMMR_VALID
value|0x80000000
end_define

begin_comment
comment|/* Indicated mapping is valid */
end_comment

begin_define
define|#
directive|define
name|TLMMR_INTLV_MASK
value|0x00000700
end_define

begin_comment
comment|/* Mask for interleave value */
end_comment

begin_define
define|#
directive|define
name|TLMMR_INTLV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TLMMR_ADDRESS_MASK
value|0x03fff000
end_define

begin_comment
comment|/* Mask for address value */
end_comment

begin_define
define|#
directive|define
name|TLMMR_ADDRESS_SHIFT
value|12
end_define

begin_comment
comment|/*  * TLFADRn - Failing Address Registers  *  * Access: R/W  *  * Notes:  *	These registers contain status information for a failed address.  *	Not all nodes preserve this information.  The validation bits  *	indicate the validity of a given field.  */
end_comment

begin_comment
comment|/*  * CPU Interrupt Mask Register  *  * The PAL code reads this register for each CPU on a TLSB CPU board  * to see what is or isn't enabled.  */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_CONHALT
value|0x100
end_define

begin_comment
comment|/* Enable ^P Halt */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_HALT
value|0x080
end_define

begin_comment
comment|/* Enable Halt */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_CLOCK
value|0x040
end_define

begin_comment
comment|/* Enable Clock Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_XCALL
value|0x020
end_define

begin_comment
comment|/* Enable Interprocessor Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_IPL17
value|0x010
end_define

begin_comment
comment|/* Enable IPL 17 Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_IPL16
value|0x008
end_define

begin_comment
comment|/* Enable IPL 16 Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_IPL15
value|0x004
end_define

begin_comment
comment|/* Enable IPL 15 Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_IPL14
value|0x002
end_define

begin_comment
comment|/* Enable IPL 14 Interrupts */
end_comment

begin_define
define|#
directive|define
name|TLINTRMASK_DUART
value|0x001
end_define

begin_comment
comment|/* Enable GBUS Duart0 Interrupts */
end_comment

begin_comment
comment|/*  * CPU Interrupt Summary Register  *  * The PAL code reads this register at interrupt time to figure out  * which interrupt line to assert to the CPU. Note that when the  * interrupt is actually vectored through the PAL code, it arrives  * here already presorted as to type (clock, halt, iointr).  */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_HALT
value|(1<< 28)
end_define

begin_comment
comment|/* Halted via TLCNR register */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_CONHALT
value|(1<< 27)
end_define

begin_comment
comment|/* Halted via ^P (W1C) */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_CLOCK
value|(1<< 6)
end_define

begin_comment
comment|/* Clock Interrupt (W1C) */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_XCALL
value|(1<< 5)
end_define

begin_comment
comment|/* Interprocessor Int (W1C) */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_IPL17
value|(1<< 4)
end_define

begin_comment
comment|/* IPL 17 Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_IPL16
value|(1<< 3)
end_define

begin_comment
comment|/* IPL 16 Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_IPL15
value|(1<< 2)
end_define

begin_comment
comment|/* IPL 15 Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_IPL14
value|(1<< 1)
end_define

begin_comment
comment|/* IPL 14 Interrupt Summary */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_DUART
value|(1<< 0)
end_define

begin_comment
comment|/* Duart Int (W1C) */
end_comment

begin_comment
comment|/* after checking the summaries, you can get the source node for each level */
end_comment

begin_define
define|#
directive|define
name|TLINTRSUM_IPL17_SOURCE
parameter_list|(
name|x
parameter_list|)
value|((x>> 22)& 0x1f)
end_define

begin_define
define|#
directive|define
name|TLINTRSUM_IPL16_SOURCE
parameter_list|(
name|x
parameter_list|)
value|((x>> 17)& 0x1f)
end_define

begin_define
define|#
directive|define
name|TLINTRSUM_IPL15_SOURCE
parameter_list|(
name|x
parameter_list|)
value|((x>> 12)& 0x1f)
end_define

begin_define
define|#
directive|define
name|TLINTRSUM_IPL14_SOURCE
parameter_list|(
name|x
parameter_list|)
value|((x>> 7)& 0x1f)
end_define

begin_comment
comment|/*  * (some of) TurboLaser CPU ADG error register defines.  */
end_comment

begin_define
define|#
directive|define
name|TLEPAERR_IBOX_TMO
value|0x1800
end_define

begin_comment
comment|/* window space read failed */
end_comment

begin_define
define|#
directive|define
name|TLEPAERR_WSPC_RD
value|0x0600
end_define

begin_comment
comment|/* window space read failed */
end_comment

begin_comment
comment|/*  * (some of) TurboLaser CPU DIGA error register defines.  */
end_comment

begin_define
define|#
directive|define
name|TLEPDERR_GBTMO
value|0x4
end_define

begin_comment
comment|/* GBus timeout */
end_comment

end_unit

