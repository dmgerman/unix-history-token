begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)isa.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * ISA Bus conventions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
name|unsigned
name|char
name|inb
argument_list|()
decl_stmt|,
name|rtcin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|outb
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Input / Output Port Assignments  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_BEGIN
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
name|IO_TIMER1
value|0x040
end_define

begin_comment
comment|/* 8252 Timer #1 */
end_comment

begin_define
define|#
directive|define
name|IO_TIMER2
value|0x048
end_define

begin_comment
comment|/* 8252 Timer #2 */
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

begin_comment
comment|/* 0x178 - 0x1EF Open */
end_comment

begin_define
define|#
directive|define
name|IO_WD1
value|0x1f0
end_define

begin_comment
comment|/* Primary Fixed Disk Controller */
end_comment

begin_define
define|#
directive|define
name|IO_GAME
value|0x200
end_define

begin_comment
comment|/* Game Controller */
end_comment

begin_comment
comment|/* 0x208 - 0x277 Open */
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
comment|/* 0x280 - 0x2F7 Open */
end_comment

begin_define
define|#
directive|define
name|IO_COM2
value|0x2f8
end_define

begin_comment
comment|/* COM2 i/o address */
end_comment

begin_comment
comment|/* 0x300 - 0x36F Open */
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
comment|/* 0x380 - 0x3AF Open */
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

begin_comment
comment|/* 0x3E0 - 0x3EF Open */
end_comment

begin_define
define|#
directive|define
name|IO_FD1
value|0x3f0
end_define

begin_comment
comment|/* primary base i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_COM1
value|0x3f8
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
comment|/* - 0x3FF End of I/O Registers */
end_comment

begin_endif
endif|#
directive|endif
endif|IO_ISABEGIN
end_endif

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
value|0xa0000
end_define

begin_comment
comment|/* Start of I/O Memory "hole" */
end_comment

begin_define
define|#
directive|define
name|IOM_END
value|0xFFFFF
end_define

begin_comment
comment|/* End of I/O Memory "hole" */
end_comment

begin_endif
endif|#
directive|endif
endif|IOM_BEGIN
end_endif

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
value|0x000000
end_define

begin_comment
comment|/* Start of RAM Memory */
end_comment

begin_define
define|#
directive|define
name|RAM_END
value|0xFFFFFF
end_define

begin_comment
comment|/* End of RAM Memory */
end_comment

begin_endif
endif|#
directive|endif
endif|IOM_BEGIN
end_endif

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
value|0x80c00000
end_define

begin_comment
comment|/* Compaq RAM relocation/diag */
end_comment

begin_define
define|#
directive|define
name|COMPAQ_RAMSETUP
value|0x80c00002
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
endif|COMPAQ_RAMRELOC
end_endif

end_unit

