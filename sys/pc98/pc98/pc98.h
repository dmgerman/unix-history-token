begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)isa.h	5.7 (Berkeley) 5/9/91  *	$Id: pc98.h,v 1.4 1996/09/12 11:09:54 asami Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_PC98_PC98_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_PC98_PC98_H_
end_define

begin_comment
comment|/* BEWARE:  Included in both assembler and C code */
end_comment

begin_comment
comment|/*  * PC98 Bus conventions  */
end_comment

begin_comment
comment|/*  * PC98 Bus conventions  * modified for PC9801 by A.Kojima F.Ukai M.Ishii   *			Kyoto University Microcomputer Club (KMC)  */
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
comment|/* PC98 IO address ... very dirty (^_^; */
end_comment

begin_define
define|#
directive|define
name|IO_ICU1
value|0x000
end_define

begin_comment
comment|/* 8259A Interrupt Controller #1 */
end_comment

begin_define
define|#
directive|define
name|IO_DMA
value|0x001
end_define

begin_comment
comment|/* 8237A DMA Controller */
end_comment

begin_define
define|#
directive|define
name|IO_ICU2
value|0x008
end_define

begin_comment
comment|/* 8259A Interrupt Controller #2 */
end_comment

begin_define
define|#
directive|define
name|IO_RTC
value|0x020
end_define

begin_comment
comment|/* 4990A RTC */
end_comment

begin_define
define|#
directive|define
name|IO_DMAPG
value|0x021
end_define

begin_comment
comment|/* DMA Page Registers */
end_comment

begin_define
define|#
directive|define
name|IO_COM1
value|0x030
end_define

begin_comment
comment|/* 8251A RS232C serial I/O (int) */
end_comment

begin_define
define|#
directive|define
name|IO_SYSPORT
value|0x031
end_define

begin_comment
comment|/* 8255A System Port */
end_comment

begin_define
define|#
directive|define
name|IO_PPI
value|0x035
end_define

begin_comment
comment|/* Programmable Peripheral Interface */
end_comment

begin_define
define|#
directive|define
name|IO_LPT
value|0x040
end_define

begin_comment
comment|/* 8255A Printer Port */
end_comment

begin_define
define|#
directive|define
name|IO_KBD
value|0x041
end_define

begin_comment
comment|/* 8251A Keyboard */
end_comment

begin_define
define|#
directive|define
name|IO_NMI
value|0x050
end_define

begin_comment
comment|/* NMI Control */
end_comment

begin_define
define|#
directive|define
name|IO_WAIT
value|0x05F
end_define

begin_comment
comment|/* WAIT 0.6 us */
end_comment

begin_define
define|#
directive|define
name|IO_GDC1
value|0x060
end_define

begin_comment
comment|/* 7220 GDC Text Control */
end_comment

begin_define
define|#
directive|define
name|IO_TIMER
value|0x071
end_define

begin_comment
comment|/* 8253C Timer */
end_comment

begin_define
define|#
directive|define
name|IO_SASI
value|0x080
end_define

begin_comment
comment|/* SASI Hard Disk Controller */
end_comment

begin_define
define|#
directive|define
name|IO_FD1
value|0x090
end_define

begin_comment
comment|/* 765A 1MB FDC */
end_comment

begin_define
define|#
directive|define
name|IO_GDC2
value|0x0a0
end_define

begin_comment
comment|/* 7220 GDC Graphic Control */
end_comment

begin_define
define|#
directive|define
name|IO_CGROM
value|0x0a1
end_define

begin_comment
comment|/* Character ROM */
end_comment

begin_define
define|#
directive|define
name|IO_COM2
value|0x0b1
end_define

begin_comment
comment|/* 8251A RS232C serial I/O (ext) */
end_comment

begin_define
define|#
directive|define
name|IO_COM3
value|0x0b9
end_define

begin_comment
comment|/* 8251A RS232C serial I/O (ext) */
end_comment

begin_define
define|#
directive|define
name|IO_FDPORT
value|0x0be
end_define

begin_comment
comment|/* FD I/F port (1M<->640K,EMTON) */
end_comment

begin_define
define|#
directive|define
name|IO_FD2
value|0x0c8
end_define

begin_comment
comment|/* 765A 640KB FDC */
end_comment

begin_define
define|#
directive|define
name|IO_SIO1
value|0x0d0
end_define

begin_comment
comment|/* MC16550II ext RS232C */
end_comment

begin_define
define|#
directive|define
name|IO_REEST
value|0x0F0
end_define

begin_comment
comment|/* CPU FPU reset */
end_comment

begin_define
define|#
directive|define
name|IO_A2OEN
value|0x0F2
end_define

begin_comment
comment|/* A20 enable */
end_comment

begin_define
define|#
directive|define
name|IO_A20CT
value|0x0F6
end_define

begin_comment
comment|/* A20 control enable/disable */
end_comment

begin_define
define|#
directive|define
name|IO_NPX
value|0x0F8
end_define

begin_comment
comment|/* Numeric Coprocessor */
end_comment

begin_define
define|#
directive|define
name|IO_SOUND
value|0x188
end_define

begin_comment
comment|/* YM2203 FM sound board */
end_comment

begin_define
define|#
directive|define
name|IO_EGC
value|0x4a0
end_define

begin_comment
comment|/* 7220 GDC Graphic Control */
end_comment

begin_define
define|#
directive|define
name|IO_SCSI
value|0xcc0
end_define

begin_comment
comment|/* SCSI Controller */
end_comment

begin_define
define|#
directive|define
name|IO_SIO2
value|0x8d0
end_define

begin_comment
comment|/* MC16550II ext RS232C */
end_comment

begin_define
define|#
directive|define
name|IO_BEEPF
value|0x3fdb
end_define

begin_comment
comment|/* beep frequency */
end_comment

begin_define
define|#
directive|define
name|IO_MOUSE
value|0x7fd9
end_define

begin_comment
comment|/* mouse */
end_comment

begin_define
define|#
directive|define
name|IO_BMS
value|0x7fd9
end_define

begin_comment
comment|/* Bus Mouse */
end_comment

begin_define
define|#
directive|define
name|IO_MSE
value|0x7fd9
end_define

begin_comment
comment|/* Bus Mouse */
end_comment

begin_define
define|#
directive|define
name|IO_MOUSETM
value|0xdfbd
end_define

begin_comment
comment|/* mouse timer */
end_comment

begin_define
define|#
directive|define
name|IO_WD1_NEC
value|0x640
end_define

begin_comment
comment|/* 98note IDE Hard disk controller */
end_comment

begin_define
define|#
directive|define
name|IO_WD1_EPSON
value|0x80
end_define

begin_comment
comment|/* 386note Hard disk controller */
end_comment

begin_define
define|#
directive|define
name|IO_WD1
value|IO_WD1_NEC
end_define

begin_comment
comment|/* IDE Hard disk controller */
end_comment

begin_define
define|#
directive|define
name|IO_ISAEND
value|0xFFFF
end_define

begin_comment
comment|/* - 0x3FF End of I/O Registers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IO_ISABEGIN */
end_comment

begin_comment
comment|/*  * Input / Output Port Sizes - these are from several sources, and tend  * to be the larger of what was found, ie COM ports can be 4, but some  * boards do not fully decode the address, thus 8 ports are used.  */
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
name|IO_COMSIZE
value|8
end_define

begin_comment
comment|/* 8250, 16X50 com controllers (4?) */
end_comment

begin_define
define|#
directive|define
name|IO_CGASIZE
value|16
end_define

begin_comment
comment|/* CGA controllers */
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
name|IO_FDCSIZE
value|8
end_define

begin_comment
comment|/* Nec765 floppy controllers */
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
value|16
end_define

begin_comment
comment|/* Monochrome display controllers */
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
name|IO_NPXSIZE
value|16
end_define

begin_comment
comment|/* 80387/80487 NPX registers */
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
name|IO_EISASIZE
value|4096
end_define

begin_comment
comment|/* EISA controllers */
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
value|0x0a0000
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
comment|/* !RAM_BEGIN */
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

begin_ifdef
ifdef|#
directive|ifdef
name|EPSON_BOUNCEDMA
end_ifdef

begin_define
define|#
directive|define
name|RAM_END
value|0x0f00000
end_define

begin_comment
comment|/* End of EPSON GR?? RAM Memory */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RAM_END
value|0x1000000
end_define

begin_comment
comment|/* End of RAM Memory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|PC98
end_ifndef

begin_comment
comment|/* IBM-PC */
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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PC98_VECTOR_SIZE
value|(0x400)
end_define

begin_define
define|#
directive|define
name|PC98_SYSTEM_PARAMETER_SIZE
value|(0x230)
end_define

begin_define
define|#
directive|define
name|PC98_SAVE_AREA
parameter_list|(
name|highreso_flag
parameter_list|)
value|(0xa1000)
end_define

begin_define
define|#
directive|define
name|PC98_SAVE_AREA_ADDRESS
value|(0x10)
end_define

begin_define
define|#
directive|define
name|OFS_BOOT_boothowto
value|0x210
end_define

begin_define
define|#
directive|define
name|OFS_BOOT_bootdev
value|0x214
end_define

begin_define
define|#
directive|define
name|OFS_BOOT_cyloffset
value|0x218
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_SECSIZE
parameter_list|(
name|i
parameter_list|)
value|(0x200+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_NCYL
parameter_list|(
name|i
parameter_list|)
value|(0x202+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_HEAD
parameter_list|(
name|i
parameter_list|)
value|(0x205+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_SEC
parameter_list|(
name|i
parameter_list|)
value|(0x204+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_pc98_machine_type
value|0x220
end_define

begin_define
define|#
directive|define
name|OFS_epson_machine_id
value|0x224
end_define

begin_define
define|#
directive|define
name|OFS_epson_bios_id
value|0x225
end_define

begin_define
define|#
directive|define
name|OFS_epson_system_type
value|0x226
end_define

begin_define
define|#
directive|define
name|M_NEC_PC98
value|0x0001
end_define

begin_define
define|#
directive|define
name|M_EPSON_PC98
value|0x0002
end_define

begin_define
define|#
directive|define
name|M_NOT_H98
value|0x0010
end_define

begin_define
define|#
directive|define
name|M_H98
value|0x0020
end_define

begin_define
define|#
directive|define
name|M_NOTE
value|0x0040
end_define

begin_define
define|#
directive|define
name|M_NORMAL
value|0x1000
end_define

begin_define
define|#
directive|define
name|M_HIGHRESO
value|0x2000
end_define

begin_define
define|#
directive|define
name|M_8M
value|0x8000
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_comment
comment|/* BIOS parameter block */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|pc98_system_parameter
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in locore.c */
end_comment

begin_define
define|#
directive|define
name|PC98_SYSTEM_PARAMETER
parameter_list|(
name|x
parameter_list|)
value|pc98_system_parameter[(x)-0x400]
end_define

begin_define
define|#
directive|define
name|BOOT_boothowto
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_boothowto]))
end_define

begin_define
define|#
directive|define
name|BOOT_bootdev
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_bootdev]))
end_define

begin_define
define|#
directive|define
name|BOOT_cyloffset
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_cyloffset]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_SECSIZE
parameter_list|(
name|i
parameter_list|)
value|(*(unsigned short*)(&pc98_system_parameter[OFS_WD_BIOS_SECSIZE(i)]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_NCYL
parameter_list|(
name|i
parameter_list|)
value|(*(unsigned short*)(&pc98_system_parameter[OFS_WD_BIOS_NCYL(i)]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_HEAD
parameter_list|(
name|i
parameter_list|)
value|(pc98_system_parameter[OFS_WD_BIOS_HEAD(i)])
end_define

begin_define
define|#
directive|define
name|WD_BIOS_SEC
parameter_list|(
name|i
parameter_list|)
value|(pc98_system_parameter[OFS_WD_BIOS_SEC(i)])
end_define

begin_define
define|#
directive|define
name|pc98_machine_type
value|(*(unsigned long*)&pc98_system_parameter[OFS_pc98_machine_type])
end_define

begin_define
define|#
directive|define
name|epson_machine_id
value|(pc98_system_parameter[OFS_epson_machine_id])
end_define

begin_define
define|#
directive|define
name|epson_bios_id
value|(pc98_system_parameter[OFS_epson_bios_id])
end_define

begin_define
define|#
directive|define
name|epson_system_type
value|(pc98_system_parameter[OFS_epson_system_type])
end_define

begin_define
define|#
directive|define
name|PC98_TYPE_CHECK
parameter_list|(
name|x
parameter_list|)
value|((pc98_machine_type& (x)) == (x))
end_define

begin_include
include|#
directive|include
file|<machine/spl.h>
end_include

begin_function
specifier|static
specifier|inline
name|u_char
name|epson_inb
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_char
name|data
decl_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x42
argument_list|)
expr_stmt|;
name|data
operator|=
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x40
argument_list|)
expr_stmt|;
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|epson_outb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_char
name|data
parameter_list|)
block|{
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x42
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x40
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|epson_insw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x42
argument_list|)
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|insw
argument_list|(
operator|(
name|u_int
operator|)
name|port
argument_list|,
operator|(
name|void
operator|*
operator|)
name|addr
argument_list|,
operator|(
name|size_t
operator|)
name|cnt
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x40
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|epson_outsw
parameter_list|(
name|u_int
name|port
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|cnt
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x42
argument_list|)
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|outsw
argument_list|(
operator|(
name|u_int
operator|)
name|port
argument_list|,
operator|(
name|void
operator|*
operator|)
name|addr
argument_list|,
operator|(
name|size_t
operator|)
name|cnt
argument_list|)
expr_stmt|;
name|outb
argument_list|(
literal|0x43f
argument_list|,
literal|0x40
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * Obtained from NetBSD/pc98  */
end_comment

begin_define
define|#
directive|define
name|MADDRUNK
value|-1
end_define

begin_define
define|#
directive|define
name|IRQUNK
value|0
end_define

begin_define
define|#
directive|define
name|DRQUNK
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC98_PC98_PC98_H_ */
end_comment

end_unit

