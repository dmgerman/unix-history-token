begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa.h	5.7 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_error
error|#
directive|error
error|isa.h is included from PC-9801 source
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_ISA_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_ISA_H_
end_define

begin_comment
comment|/* BEWARE:  Included in both assembler and C code */
end_comment

begin_comment
comment|/*  * ISA Bus conventions  */
end_comment

begin_comment
comment|/*  * Input / Output Port Assignments  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_ISABEGIN
end_ifndef

begin_define
define|#
directive|define
name|IO_ISABEGIN
value|0x000
end_define

begin_comment
comment|/* 0x000 - Beginning of I/O Registers */
end_comment

begin_comment
comment|/* CPU Board */
end_comment

begin_define
define|#
directive|define
name|IO_DMA1
value|0x000
end_define

begin_comment
comment|/* 8237A DMA Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_ICU1
value|0x020
end_define

begin_comment
comment|/* 8259A Interrupt Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_PMP1
value|0x026
end_define

begin_comment
comment|/* 82347 Power Management Peripheral */
end_comment

begin_define
define|#
directive|define
name|IO_TIMER1
value|0x040
end_define

begin_comment
comment|/* 8253 Timer #1 */
end_comment

begin_define
define|#
directive|define
name|IO_TIMER2
value|0x048
end_define

begin_comment
comment|/* 8253 Timer #2 */
end_comment

begin_define
define|#
directive|define
name|IO_KBD
value|0x060
end_define

begin_comment
comment|/* 8042 Keyboard */
end_comment

begin_define
define|#
directive|define
name|IO_PPI
value|0x061
end_define

begin_comment
comment|/* Programmable Peripheral Interface */
end_comment

begin_define
define|#
directive|define
name|IO_RTC
value|0x070
end_define

begin_comment
comment|/* RTC */
end_comment

begin_define
define|#
directive|define
name|IO_NMI
value|IO_RTC
end_define

begin_comment
comment|/* NMI Control */
end_comment

begin_define
define|#
directive|define
name|IO_DMAPG
value|0x080
end_define

begin_comment
comment|/* DMA Page Registers */
end_comment

begin_define
define|#
directive|define
name|IO_ICU2
value|0x0A0
end_define

begin_comment
comment|/* 8259A Interrupt Controller #2 */
end_comment

begin_define
define|#
directive|define
name|IO_DMA2
value|0x0C0
end_define

begin_comment
comment|/* 8237A DMA Controller #2 */
end_comment

begin_define
define|#
directive|define
name|IO_NPX
value|0x0F0
end_define

begin_comment
comment|/* Numeric Coprocessor */
end_comment

begin_comment
comment|/* Cards */
end_comment

begin_comment
comment|/* 0x100 - 0x16F Open */
end_comment

begin_define
define|#
directive|define
name|IO_WD2
value|0x170
end_define

begin_comment
comment|/* Secondary Fixed Disk Controller */
end_comment

begin_define
define|#
directive|define
name|IO_PMP2
value|0x178
end_define

begin_comment
comment|/* 82347 Power Management Peripheral */
end_comment

begin_comment
comment|/* 0x17A - 0x1EF Open */
end_comment

begin_define
define|#
directive|define
name|IO_WD1
value|0x1F0
end_define

begin_comment
comment|/* Primary Fixed Disk Controller */
end_comment

begin_define
define|#
directive|define
name|IO_GAME
value|0x201
end_define

begin_comment
comment|/* Game Controller */
end_comment

begin_comment
comment|/* 0x202 - 0x22A Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC2
value|0x22B
end_define

begin_comment
comment|/* AmiScan addr.grp. 2 */
end_comment

begin_comment
comment|/* 0x230 - 0x26A Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC3
value|0x26B
end_define

begin_comment
comment|/* AmiScan addr.grp. 3 */
end_comment

begin_define
define|#
directive|define
name|IO_GSC1
value|0x270
end_define

begin_comment
comment|/* -- 0x27B! GeniScan GS-4500 addr.grp. 1 */
end_comment

begin_define
define|#
directive|define
name|IO_LPT2
value|0x278
end_define

begin_comment
comment|/* Parallel Port #2 */
end_comment

begin_comment
comment|/* 0x280 - 0x2AA Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC4
value|0x2AB
end_define

begin_comment
comment|/* AmiScan addr.grp. 4 */
end_comment

begin_comment
comment|/* 0x2B0 - 0x2DF Open */
end_comment

begin_define
define|#
directive|define
name|IO_GSC2
value|0x2E0
end_define

begin_comment
comment|/* GeniScan GS-4500 addr.grp. 2 */
end_comment

begin_define
define|#
directive|define
name|IO_COM4
value|0x2E8
end_define

begin_comment
comment|/* COM4 i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_ASC5
value|0x2EB
end_define

begin_comment
comment|/* AmiScan addr.grp. 5 */
end_comment

begin_comment
comment|/* 0x2F0 - 0x2F7 Open */
end_comment

begin_define
define|#
directive|define
name|IO_COM2
value|0x2F8
end_define

begin_comment
comment|/* COM2 i/o address */
end_comment

begin_comment
comment|/* 0x300 - 0x32A Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC6
value|0x32B
end_define

begin_comment
comment|/* AmiScan addr.grp. 6 */
end_comment

begin_define
define|#
directive|define
name|IO_AHA0
value|0x330
end_define

begin_comment
comment|/* adaptec 1542 default addr. */
end_comment

begin_define
define|#
directive|define
name|IO_BT0
value|0x330
end_define

begin_comment
comment|/* bustek 742a default addr. */
end_comment

begin_define
define|#
directive|define
name|IO_UHA0
value|0x330
end_define

begin_comment
comment|/* ultrastore 14f default addr. */
end_comment

begin_define
define|#
directive|define
name|IO_AHA1
value|0x334
end_define

begin_comment
comment|/* adaptec 1542 default addr. */
end_comment

begin_define
define|#
directive|define
name|IO_BT1
value|0x334
end_define

begin_comment
comment|/* bustek 742a default addr. */
end_comment

begin_comment
comment|/* 0x340 - 0x36A Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC7
value|0x36B
end_define

begin_comment
comment|/* AmiScan addr.grp. 7 */
end_comment

begin_define
define|#
directive|define
name|IO_GSC3
value|0x370
end_define

begin_comment
comment|/* GeniScan GS-4500 addr.grp. 3 */
end_comment

begin_define
define|#
directive|define
name|IO_FD2
value|0x370
end_define

begin_comment
comment|/* secondary base i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_LPT1
value|0x378
end_define

begin_comment
comment|/* Parallel Port #1 */
end_comment

begin_comment
comment|/* 0x380 - 0x3AA Open */
end_comment

begin_define
define|#
directive|define
name|IO_ASC8
value|0x3AB
end_define

begin_comment
comment|/* AmiScan addr.grp. 8 */
end_comment

begin_define
define|#
directive|define
name|IO_MDA
value|0x3B0
end_define

begin_comment
comment|/* Monochome Adapter */
end_comment

begin_define
define|#
directive|define
name|IO_LPT3
value|0x3BC
end_define

begin_comment
comment|/* Monochome Adapter Printer Port */
end_comment

begin_define
define|#
directive|define
name|IO_VGA
value|0x3C0
end_define

begin_comment
comment|/* E/VGA Ports */
end_comment

begin_define
define|#
directive|define
name|IO_CGA
value|0x3D0
end_define

begin_comment
comment|/* CGA Ports */
end_comment

begin_define
define|#
directive|define
name|IO_GSC4
value|0x3E0
end_define

begin_comment
comment|/* GeniScan GS-4500 addr.grp. 4 */
end_comment

begin_define
define|#
directive|define
name|IO_COM3
value|0x3E8
end_define

begin_comment
comment|/* COM3 i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_ASC1
value|0x3EB
end_define

begin_comment
comment|/* AmiScan addr.grp. 1 */
end_comment

begin_define
define|#
directive|define
name|IO_FD1
value|0x3F0
end_define

begin_comment
comment|/* primary base i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_COM1
value|0x3F8
end_define

begin_comment
comment|/* COM1 i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_ISAEND
value|0x3FF
end_define

begin_comment
comment|/* End (actually Max) of I/O Regs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISABEGIN */
end_comment

begin_comment
comment|/*  * Input / Output Port Sizes - these are from several sources, and tend  * to be the larger of what was found.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_ISASIZES
end_ifndef

begin_define
define|#
directive|define
name|IO_ISASIZES
end_define

begin_define
define|#
directive|define
name|IO_ASCSIZE
value|5
end_define

begin_comment
comment|/* AmiScan GI1904-based hand scanner */
end_comment

begin_define
define|#
directive|define
name|IO_CGASIZE
value|12
end_define

begin_comment
comment|/* CGA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_COMSIZE
value|8
end_define

begin_comment
comment|/* 8250, 16x50 com controllers */
end_comment

begin_define
define|#
directive|define
name|IO_DMASIZE
value|16
end_define

begin_comment
comment|/* 8237 DMA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_DPGSIZE
value|32
end_define

begin_comment
comment|/* 74LS612 DMA page registers */
end_comment

begin_define
define|#
directive|define
name|IO_EISASIZE
value|256
end_define

begin_comment
comment|/* EISA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_FDCSIZE
value|8
end_define

begin_comment
comment|/* Nec765 floppy controllers */
end_comment

begin_define
define|#
directive|define
name|IO_GAMSIZE
value|16
end_define

begin_comment
comment|/* AT compatible game controllers */
end_comment

begin_define
define|#
directive|define
name|IO_GSCSIZE
value|8
end_define

begin_comment
comment|/* GeniScan GS-4500G hand scanner */
end_comment

begin_define
define|#
directive|define
name|IO_ICUSIZE
value|16
end_define

begin_comment
comment|/* 8259A interrupt controllers */
end_comment

begin_define
define|#
directive|define
name|IO_KBDSIZE
value|16
end_define

begin_comment
comment|/* 8042 Keyboard controllers */
end_comment

begin_define
define|#
directive|define
name|IO_LPTSIZE
value|8
end_define

begin_comment
comment|/* LPT controllers, some use only 4 */
end_comment

begin_define
define|#
directive|define
name|IO_MDASIZE
value|12
end_define

begin_comment
comment|/* Monochrome display controllers */
end_comment

begin_define
define|#
directive|define
name|IO_NPXSIZE
value|16
end_define

begin_comment
comment|/* 80387/80487 NPX registers */
end_comment

begin_define
define|#
directive|define
name|IO_PMPSIZE
value|2
end_define

begin_comment
comment|/* 82347 power management peripheral */
end_comment

begin_define
define|#
directive|define
name|IO_PSMSIZE
value|5
end_define

begin_comment
comment|/* 8042 Keyboard controllers */
end_comment

begin_define
define|#
directive|define
name|IO_RTCSIZE
value|16
end_define

begin_comment
comment|/* CMOS real time clock, NMI control */
end_comment

begin_define
define|#
directive|define
name|IO_TMRSIZE
value|16
end_define

begin_comment
comment|/* 8253 programmable timers */
end_comment

begin_define
define|#
directive|define
name|IO_VGASIZE
value|16
end_define

begin_comment
comment|/* VGA controllers */
end_comment

begin_define
define|#
directive|define
name|IO_WDCSIZE
value|8
end_define

begin_comment
comment|/* WD compatible disk controllers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISASIZES */
end_comment

begin_comment
comment|/*  * Input / Output Memory Physical Addresses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IOM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|IOM_BEGIN
value|0x0A0000
end_define

begin_comment
comment|/* Start of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_END
value|0x100000
end_define

begin_comment
comment|/* End of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_SIZE
value|(IOM_END - IOM_BEGIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IOM_BEGIN */
end_comment

begin_comment
comment|/*  * RAM Physical Address Space (ignoring the above mentioned "hole")  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RAM_BEGIN
end_ifndef

begin_define
define|#
directive|define
name|RAM_BEGIN
value|0x0000000
end_define

begin_comment
comment|/* Start of RAM Memory */
end_comment

begin_define
define|#
directive|define
name|RAM_END
value|0x1000000
end_define

begin_comment
comment|/* End of RAM Memory */
end_comment

begin_define
define|#
directive|define
name|RAM_SIZE
value|(RAM_END - RAM_BEGIN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !RAM_BEGIN */
end_comment

begin_comment
comment|/*  * Oddball Physical Memory Addresses  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAQ_RAMRELOC
end_ifndef

begin_define
define|#
directive|define
name|COMPAQ_RAMRELOC
value|0x80C00000
end_define

begin_comment
comment|/* Compaq RAM relocation/diag */
end_comment

begin_define
define|#
directive|define
name|COMPAQ_RAMSETUP
value|0x80C00002
end_define

begin_comment
comment|/* Compaq RAM setup */
end_comment

begin_define
define|#
directive|define
name|WEITEK_FPU
value|0xC0000000
end_define

begin_comment
comment|/* WTL 2167 */
end_comment

begin_define
define|#
directive|define
name|CYRIX_EMC
value|0xC0000000
end_define

begin_comment
comment|/* Cyrix EMC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !COMPAQ_RAMRELOC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ISA_H_ */
end_comment

end_unit

