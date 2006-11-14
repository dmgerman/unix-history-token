begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1990 William F. Jolitz  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)segments.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SEGMENTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SEGMENTS_H_
end_define

begin_comment
comment|/*  * 386 Segmentation Data Structures and definitions  *	William F. Jolitz (william@ernie.berkeley.edu) 6/20/1989  */
end_comment

begin_comment
comment|/*  * Selectors  */
end_comment

begin_define
define|#
directive|define
name|ISPL
parameter_list|(
name|s
parameter_list|)
value|((s)&3)
end_define

begin_comment
comment|/* what is the priority level of a selector */
end_comment

begin_define
define|#
directive|define
name|SEL_KPL
value|0
end_define

begin_comment
comment|/* kernel priority level */
end_comment

begin_define
define|#
directive|define
name|SEL_UPL
value|3
end_define

begin_comment
comment|/* user priority level */
end_comment

begin_define
define|#
directive|define
name|ISLDT
parameter_list|(
name|s
parameter_list|)
value|((s)&SEL_LDT)
end_define

begin_comment
comment|/* is it local or global */
end_comment

begin_define
define|#
directive|define
name|SEL_LDT
value|4
end_define

begin_comment
comment|/* local descriptor table */
end_comment

begin_define
define|#
directive|define
name|IDXSEL
parameter_list|(
name|s
parameter_list|)
value|(((s)>>3)& 0x1fff)
end_define

begin_comment
comment|/* index of selector */
end_comment

begin_define
define|#
directive|define
name|LSEL
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|(((s)<<3) | SEL_LDT | r)
end_define

begin_comment
comment|/* a local selector */
end_comment

begin_define
define|#
directive|define
name|GSEL
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|(((s)<<3) | r)
end_define

begin_comment
comment|/* a global selector */
end_comment

begin_comment
comment|/*  * Memory and System segment descriptors  */
end_comment

begin_struct
struct|struct
name|segment_descriptor
block|{
name|unsigned
name|sd_lolimit
range|:
literal|16
decl_stmt|;
comment|/* segment extent (lsb) */
name|unsigned
name|sd_lobase
range|:
literal|24
name|__packed
decl_stmt|;
comment|/* segment base address (lsb) */
name|unsigned
name|sd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|sd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|sd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|sd_hilimit
range|:
literal|4
decl_stmt|;
comment|/* segment extent (msb) */
name|unsigned
name|sd_xx
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|unsigned
name|sd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|sd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
name|unsigned
name|sd_hibase
range|:
literal|8
decl_stmt|;
comment|/* segment base address  (msb) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Gate descriptors (e.g. indirect descriptors)  */
end_comment

begin_struct
struct|struct
name|gate_descriptor
block|{
name|unsigned
name|gd_looffset
range|:
literal|16
decl_stmt|;
comment|/* gate offset (lsb) */
name|unsigned
name|gd_selector
range|:
literal|16
decl_stmt|;
comment|/* gate segment selector */
name|unsigned
name|gd_stkcpy
range|:
literal|5
decl_stmt|;
comment|/* number of stack wds to cpy */
name|unsigned
name|gd_xx
range|:
literal|3
decl_stmt|;
comment|/* unused */
name|unsigned
name|gd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|gd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|gd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|gd_hioffset
range|:
literal|16
decl_stmt|;
comment|/* gate offset (msb) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic descriptor  */
end_comment

begin_union
union|union
name|descriptor
block|{
name|struct
name|segment_descriptor
name|sd
decl_stmt|;
name|struct
name|gate_descriptor
name|gd
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* system segments and gate types */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL
value|0
end_define

begin_comment
comment|/* system null */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286TSS
value|1
end_define

begin_comment
comment|/* system 286 TSS available */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSLDT
value|2
end_define

begin_comment
comment|/* system local descriptor table */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286BSY
value|3
end_define

begin_comment
comment|/* system 286 TSS busy */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286CGT
value|4
end_define

begin_comment
comment|/* system 286 call gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSTASKGT
value|5
end_define

begin_comment
comment|/* system task gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286IGT
value|6
end_define

begin_comment
comment|/* system 286 interrupt gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286TGT
value|7
end_define

begin_comment
comment|/* system 286 trap gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL2
value|8
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386TSS
value|9
end_define

begin_comment
comment|/* system 386 TSS available */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL3
value|10
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386BSY
value|11
end_define

begin_comment
comment|/* system 386 TSS busy */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386CGT
value|12
end_define

begin_comment
comment|/* system 386 call gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL4
value|13
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386IGT
value|14
end_define

begin_comment
comment|/* system 386 interrupt gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386TGT
value|15
end_define

begin_comment
comment|/* system 386 trap gate */
end_comment

begin_comment
comment|/* memory segment types */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRO
value|16
end_define

begin_comment
comment|/* memory read only */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMROA
value|17
end_define

begin_comment
comment|/* memory read only accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRW
value|18
end_define

begin_comment
comment|/* memory read write */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWA
value|19
end_define

begin_comment
comment|/* memory read write accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMROD
value|20
end_define

begin_comment
comment|/* memory read only expand dwn limit */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRODA
value|21
end_define

begin_comment
comment|/* memory read only expand dwn limit accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWD
value|22
end_define

begin_comment
comment|/* memory read write expand dwn limit */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWDA
value|23
end_define

begin_comment
comment|/* memory read write expand dwn limit accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEME
value|24
end_define

begin_comment
comment|/* memory execute only */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEA
value|25
end_define

begin_comment
comment|/* memory execute only accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMER
value|26
end_define

begin_comment
comment|/* memory execute read */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERA
value|27
end_define

begin_comment
comment|/* memory execute read accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEC
value|28
end_define

begin_comment
comment|/* memory execute only conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEAC
value|29
end_define

begin_comment
comment|/* memory execute only accessed conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERC
value|30
end_define

begin_comment
comment|/* memory execute read conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERAC
value|31
end_define

begin_comment
comment|/* memory execute read accessed conforming */
end_comment

begin_comment
comment|/*  * Software definitions are in this convenient format,  * which are translated into inconvenient segment descriptors  * when needed to be used by the 386 hardware  */
end_comment

begin_struct
struct|struct
name|soft_segment_descriptor
block|{
name|unsigned
name|ssd_base
decl_stmt|;
comment|/* segment base address  */
name|unsigned
name|ssd_limit
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|ssd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|ssd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|ssd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|ssd_xx
range|:
literal|4
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_xx1
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|ssd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * region descriptors, used to load gdt/idt tables before segments yet exist.  */
end_comment

begin_struct
struct|struct
name|region_descriptor
block|{
name|unsigned
name|rd_limit
range|:
literal|16
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|rd_base
range|:
literal|32
name|__packed
decl_stmt|;
comment|/* base address  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Segment Protection Exception code bits  */
end_comment

begin_define
define|#
directive|define
name|SEGEX_EXT
value|0x01
end_define

begin_comment
comment|/* recursive or externally induced */
end_comment

begin_define
define|#
directive|define
name|SEGEX_IDT
value|0x02
end_define

begin_comment
comment|/* interrupt descriptor table */
end_comment

begin_define
define|#
directive|define
name|SEGEX_TI
value|0x04
end_define

begin_comment
comment|/* local descriptor table */
end_comment

begin_comment
comment|/* other bits are affected descriptor index */
end_comment

begin_define
define|#
directive|define
name|SEGEX_IDX
parameter_list|(
name|s
parameter_list|)
value|(((s)>>3)&0x1fff)
end_define

begin_comment
comment|/*  * Size of IDT table  */
end_comment

begin_define
define|#
directive|define
name|NIDT
value|256
end_define

begin_comment
comment|/* 32 reserved, 0x80 syscall, most are h/w */
end_comment

begin_define
define|#
directive|define
name|NRSVIDT
value|32
end_define

begin_comment
comment|/* reserved entries for cpu exceptions */
end_comment

begin_comment
comment|/*  * Entries in the Interrupt Descriptor Table (IDT)  */
end_comment

begin_define
define|#
directive|define
name|IDT_DE
value|0
end_define

begin_comment
comment|/* #DE: Divide Error */
end_comment

begin_define
define|#
directive|define
name|IDT_DB
value|1
end_define

begin_comment
comment|/* #DB: Debug */
end_comment

begin_define
define|#
directive|define
name|IDT_NMI
value|2
end_define

begin_comment
comment|/* Nonmaskable External Interrupt */
end_comment

begin_define
define|#
directive|define
name|IDT_BP
value|3
end_define

begin_comment
comment|/* #BP: Breakpoint */
end_comment

begin_define
define|#
directive|define
name|IDT_OF
value|4
end_define

begin_comment
comment|/* #OF: Overflow */
end_comment

begin_define
define|#
directive|define
name|IDT_BR
value|5
end_define

begin_comment
comment|/* #BR: Bound Range Exceeded */
end_comment

begin_define
define|#
directive|define
name|IDT_UD
value|6
end_define

begin_comment
comment|/* #UD: Undefined/Invalid Opcode */
end_comment

begin_define
define|#
directive|define
name|IDT_NM
value|7
end_define

begin_comment
comment|/* #NM: No Math Coprocessor */
end_comment

begin_define
define|#
directive|define
name|IDT_DF
value|8
end_define

begin_comment
comment|/* #DF: Double Fault */
end_comment

begin_define
define|#
directive|define
name|IDT_FPUGP
value|9
end_define

begin_comment
comment|/* Coprocessor Segment Overrun */
end_comment

begin_define
define|#
directive|define
name|IDT_TS
value|10
end_define

begin_comment
comment|/* #TS: Invalid TSS */
end_comment

begin_define
define|#
directive|define
name|IDT_NP
value|11
end_define

begin_comment
comment|/* #NP: Segment Not Present */
end_comment

begin_define
define|#
directive|define
name|IDT_SS
value|12
end_define

begin_comment
comment|/* #SS: Stack Segment Fault */
end_comment

begin_define
define|#
directive|define
name|IDT_GP
value|13
end_define

begin_comment
comment|/* #GP: General Protection Fault */
end_comment

begin_define
define|#
directive|define
name|IDT_PF
value|14
end_define

begin_comment
comment|/* #PF: Page Fault */
end_comment

begin_define
define|#
directive|define
name|IDT_MF
value|16
end_define

begin_comment
comment|/* #MF: FPU Floating-Point Error */
end_comment

begin_define
define|#
directive|define
name|IDT_AC
value|17
end_define

begin_comment
comment|/* #AC: Alignment Check */
end_comment

begin_define
define|#
directive|define
name|IDT_MC
value|18
end_define

begin_comment
comment|/* #MC: Machine Check */
end_comment

begin_define
define|#
directive|define
name|IDT_XF
value|19
end_define

begin_comment
comment|/* #XF: SIMD Floating-Point Exception */
end_comment

begin_define
define|#
directive|define
name|IDT_IO_INTS
value|NRSVIDT
end_define

begin_comment
comment|/* Base of IDT entries for I/O interrupts. */
end_comment

begin_define
define|#
directive|define
name|IDT_SYSCALL
value|0x80
end_define

begin_comment
comment|/* System Call Interrupt Vector */
end_comment

begin_comment
comment|/*  * Entries in the Global Descriptor Table (GDT)  * Note that each 4 entries share a single 32 byte L1 cache line.  * Some of the fast syscall instructions require a specific order here.  */
end_comment

begin_define
define|#
directive|define
name|GNULL_SEL
value|0
end_define

begin_comment
comment|/* Null Descriptor */
end_comment

begin_define
define|#
directive|define
name|GPRIV_SEL
value|1
end_define

begin_comment
comment|/* SMP Per-Processor Private Data */
end_comment

begin_define
define|#
directive|define
name|GUFS_SEL
value|2
end_define

begin_comment
comment|/* User %fs Descriptor (order critical: 1) */
end_comment

begin_define
define|#
directive|define
name|GUGS_SEL
value|3
end_define

begin_comment
comment|/* User %gs Descriptor (order critical: 2) */
end_comment

begin_define
define|#
directive|define
name|GCODE_SEL
value|4
end_define

begin_comment
comment|/* Kernel Code Descriptor (order critical: 1) */
end_comment

begin_define
define|#
directive|define
name|GDATA_SEL
value|5
end_define

begin_comment
comment|/* Kernel Data Descriptor (order critical: 2) */
end_comment

begin_define
define|#
directive|define
name|GUCODE_SEL
value|6
end_define

begin_comment
comment|/* User Code Descriptor (order critical: 3) */
end_comment

begin_define
define|#
directive|define
name|GUDATA_SEL
value|7
end_define

begin_comment
comment|/* User Data Descriptor (order critical: 4) */
end_comment

begin_define
define|#
directive|define
name|GBIOSLOWMEM_SEL
value|8
end_define

begin_comment
comment|/* BIOS low memory access (must be entry 8) */
end_comment

begin_define
define|#
directive|define
name|GPROC0_SEL
value|9
end_define

begin_comment
comment|/* Task state process slot zero and up */
end_comment

begin_define
define|#
directive|define
name|GLDT_SEL
value|10
end_define

begin_comment
comment|/* Default User LDT */
end_comment

begin_define
define|#
directive|define
name|GUSERLDT_SEL
value|11
end_define

begin_comment
comment|/* User LDT */
end_comment

begin_define
define|#
directive|define
name|GPANIC_SEL
value|12
end_define

begin_comment
comment|/* Task state to consider panic from */
end_comment

begin_define
define|#
directive|define
name|GBIOSCODE32_SEL
value|13
end_define

begin_comment
comment|/* BIOS interface (32bit Code) */
end_comment

begin_define
define|#
directive|define
name|GBIOSCODE16_SEL
value|14
end_define

begin_comment
comment|/* BIOS interface (16bit Code) */
end_comment

begin_define
define|#
directive|define
name|GBIOSDATA_SEL
value|15
end_define

begin_comment
comment|/* BIOS interface (Data) */
end_comment

begin_define
define|#
directive|define
name|GBIOSUTIL_SEL
value|16
end_define

begin_comment
comment|/* BIOS interface (Utility) */
end_comment

begin_define
define|#
directive|define
name|GBIOSARGS_SEL
value|17
end_define

begin_comment
comment|/* BIOS interface (Arguments) */
end_comment

begin_define
define|#
directive|define
name|GNDIS_SEL
value|18
end_define

begin_comment
comment|/* For the NDIS layer */
end_comment

begin_define
define|#
directive|define
name|NGDT
value|19
end_define

begin_comment
comment|/*  * Entries in the Local Descriptor Table (LDT)  */
end_comment

begin_define
define|#
directive|define
name|LSYS5CALLS_SEL
value|0
end_define

begin_comment
comment|/* forced by intel BCS */
end_comment

begin_define
define|#
directive|define
name|LSYS5SIGR_SEL
value|1
end_define

begin_define
define|#
directive|define
name|L43BSDCALLS_SEL
value|2
end_define

begin_comment
comment|/* notyet */
end_comment

begin_define
define|#
directive|define
name|LUCODE_SEL
value|3
end_define

begin_define
define|#
directive|define
name|LSOL26CALLS_SEL
value|4
end_define

begin_comment
comment|/* Solaris>= 2.6 system call gate */
end_comment

begin_define
define|#
directive|define
name|LUDATA_SEL
value|5
end_define

begin_comment
comment|/* separate stack, es,fs,gs sels ? */
end_comment

begin_comment
comment|/* #define	LPOSIXCALLS_SEL	5*/
end_comment

begin_comment
comment|/* notyet */
end_comment

begin_define
define|#
directive|define
name|LBSDICALLS_SEL
value|16
end_define

begin_comment
comment|/* BSDI system call gate */
end_comment

begin_define
define|#
directive|define
name|NLDT
value|(LBSDICALLS_SEL + 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|_default_ldt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|descriptor
name|gdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|soft_segment_descriptor
name|gdt_segs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gate_descriptor
modifier|*
name|idt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|descriptor
name|ldt
index|[
name|NLDT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|region_descriptor
name|r_gdt
decl_stmt|,
name|r_idt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lgdt
parameter_list|(
name|struct
name|region_descriptor
modifier|*
name|rdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdtossd
parameter_list|(
name|struct
name|segment_descriptor
modifier|*
name|sdp
parameter_list|,
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssdtosd
parameter_list|(
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|,
name|struct
name|segment_descriptor
modifier|*
name|sdp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SEGMENTS_H_ */
end_comment

end_unit

