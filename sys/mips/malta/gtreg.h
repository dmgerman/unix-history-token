begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: gtreg.h,v 1.2 2005/12/24 20:07:03 perry Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|GT_REGVAL
parameter_list|(
name|x
parameter_list|)
value|*((volatile u_int32_t *) \ 			    (MIPS_PHYS_TO_KSEG1(MALTA_CORECTRL_BASE + (x))))
end_define

begin_comment
comment|/* CPU Configuration Register Map */
end_comment

begin_define
define|#
directive|define
name|GT_CPU_INT
value|0x000
end_define

begin_define
define|#
directive|define
name|GT_MULTIGT
value|0x120
end_define

begin_comment
comment|/* CPU Address Decode Register Map */
end_comment

begin_comment
comment|/* CPU Error Report Register Map */
end_comment

begin_comment
comment|/* CPU Sync Barrier Register Map */
end_comment

begin_comment
comment|/* SDRAM and Device Address Decode Register Map */
end_comment

begin_comment
comment|/* SDRAM Configuration Register Map */
end_comment

begin_comment
comment|/* SDRAM Parameters Register Map */
end_comment

begin_comment
comment|/* ECC Register Map */
end_comment

begin_comment
comment|/* Device Parameters Register Map */
end_comment

begin_comment
comment|/* DMA Record Register Map */
end_comment

begin_comment
comment|/* DMA Arbiter Register Map */
end_comment

begin_comment
comment|/* Timer/Counter Register Map */
end_comment

begin_comment
comment|//#define	GT_TC_0		0x850
end_comment

begin_comment
comment|//#define	GT_TC_1		0x854
end_comment

begin_comment
comment|//#define	GT_TC_2		0x858
end_comment

begin_comment
comment|//#define	GT_TC_3		0x85c
end_comment

begin_comment
comment|//#define	GT_TC_CONTROL	0x864
end_comment

begin_comment
comment|/* PCI Internal Register Map */
end_comment

begin_define
define|#
directive|define
name|GT_PCI0_CFG_ADDR
value|0xcf8
end_define

begin_define
define|#
directive|define
name|GT_PCI0_CFG_DATA
value|0xcfc
end_define

begin_define
define|#
directive|define
name|GT_PCI0_INTR_ACK
value|0xc34
end_define

begin_comment
comment|/* Interrupts Register Map */
end_comment

begin_define
define|#
directive|define
name|GT_INTR_CAUSE
value|0xc18
end_define

begin_define
define|#
directive|define
name|GTIC_INTSUM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GTIC_MEMOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GTIC_DMAOUT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GTIC_CPUOUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GTIC_DMA0COMP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GTIC_DMA1COMP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GTIC_DMA2COMP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GTIC_DMA3COMP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GTIC_T0EXP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GTIC_T1EXP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GTIC_T2EXP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GTIC_T3EXP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GTIC_MASRDERR0
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GTIC_SLVWRERR0
value|0x00002000
end_define

begin_define
define|#
directive|define
name|GTIC_MASWRERR0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|GTIC_SLVRDERR0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|GTIC_ADDRERR0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GTIC_MEMERR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GTIC_MASABORT0
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GTIC_TARABORT0
value|0x00080000
end_define

begin_define
define|#
directive|define
name|GTIC_RETRYCNT0
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GTIC_PMCINT_0
value|0x00200000
end_define

begin_define
define|#
directive|define
name|GTIC_CPUINT
value|0x0c300000
end_define

begin_define
define|#
directive|define
name|GTIC_PCINT
value|0xc3000000
end_define

begin_define
define|#
directive|define
name|GTIC_CPUINTSUM
value|0x40000000
end_define

begin_define
define|#
directive|define
name|GTIC_PCIINTSUM
value|0x80000000
end_define

begin_comment
comment|/* PCI Configuration Register Map */
end_comment

begin_comment
comment|//#define	GT_PCICONFIGBASE	0
end_comment

begin_comment
comment|//#define	GT_PCIDID		BONITO(GT_PCICONFIGBASE + 0x00)
end_comment

begin_comment
comment|//#define	GT_PCICMD		BONITO(GT_PCICONFIGBASE + 0x04)
end_comment

begin_comment
comment|//#define	GT_PCICLASS		BONITO(GT_PCICONFIGBASE + 0x08)
end_comment

begin_comment
comment|//#define	GT_PCILTIMER		BONITO(GT_PCICONFIGBASE + 0x0c)
end_comment

begin_comment
comment|//#define	GT_PCIBASE0		BONITO(GT_PCICONFIGBASE + 0x10)
end_comment

begin_comment
comment|//#define	GT_PCIBASE1		BONITO(GT_PCICONFIGBASE + 0x14)
end_comment

begin_comment
comment|//#define	GT_PCIBASE2		BONITO(GT_PCICONFIGBASE + 0x18)
end_comment

begin_comment
comment|//#define	GT_PCIEXPRBASE		BONITO(GT_PCICONFIGBASE + 0x30)
end_comment

begin_comment
comment|//#define	GT_PCIINT		BONITO(GT_PCICONFIGBASE + 0x3c)
end_comment

begin_comment
comment|/* PCI Configuration, Function 1, Register Map */
end_comment

begin_comment
comment|/* I2O Support Register Map */
end_comment

end_unit

