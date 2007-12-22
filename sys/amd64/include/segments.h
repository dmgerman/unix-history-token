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
comment|/*  * AMD64 Segmentation Data Structures and definitions  */
end_comment

begin_comment
comment|/*  * Selectors  */
end_comment

begin_define
define|#
directive|define
name|SEL_RPL_MASK
value|3
end_define

begin_comment
comment|/* requester priv level */
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
comment|/*  * User segment descriptors (%cs, %ds etc for compatability apps. 64 bit wide)  * For long-mode apps, %cs only has the conforming bit in sd_type, the sd_dpl,  * sd_p, sd_l and sd_def32 which must be zero).  %ds only has sd_p.  */
end_comment

begin_struct
struct|struct
name|user_segment_descriptor
block|{
name|u_int64_t
name|sd_lolimit
range|:
literal|16
decl_stmt|;
comment|/* segment extent (lsb) */
name|u_int64_t
name|sd_lobase
range|:
literal|24
decl_stmt|;
comment|/* segment base address (lsb) */
name|u_int64_t
name|sd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|u_int64_t
name|sd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|u_int64_t
name|sd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|u_int64_t
name|sd_hilimit
range|:
literal|4
decl_stmt|;
comment|/* segment extent (msb) */
name|u_int64_t
name|sd_xx
range|:
literal|1
decl_stmt|;
comment|/* unused */
name|u_int64_t
name|sd_long
range|:
literal|1
decl_stmt|;
comment|/* long mode (cs only) */
name|u_int64_t
name|sd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|u_int64_t
name|sd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
name|u_int64_t
name|sd_hibase
range|:
literal|8
decl_stmt|;
comment|/* segment base address  (msb) */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * System segment descriptors (128 bit wide)  */
end_comment

begin_struct
struct|struct
name|system_segment_descriptor
block|{
name|u_int64_t
name|sd_lolimit
range|:
literal|16
decl_stmt|;
comment|/* segment extent (lsb) */
name|u_int64_t
name|sd_lobase
range|:
literal|24
decl_stmt|;
comment|/* segment base address (lsb) */
name|u_int64_t
name|sd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|u_int64_t
name|sd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|u_int64_t
name|sd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|u_int64_t
name|sd_hilimit
range|:
literal|4
decl_stmt|;
comment|/* segment extent (msb) */
name|u_int64_t
name|sd_xx0
range|:
literal|3
decl_stmt|;
comment|/* unused */
name|u_int64_t
name|sd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
name|u_int64_t
name|sd_hibase
range|:
literal|40
name|__packed
decl_stmt|;
comment|/* segment base address  (msb) */
name|u_int64_t
name|sd_xx1
range|:
literal|8
decl_stmt|;
name|u_int64_t
name|sd_mbz
range|:
literal|5
decl_stmt|;
comment|/* MUST be zero */
name|u_int64_t
name|sd_xx2
range|:
literal|19
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Gate descriptors (e.g. indirect descriptors, trap, interrupt etc. 128 bit)  * Only interrupt and trap gates have gd_ist.  */
end_comment

begin_struct
struct|struct
name|gate_descriptor
block|{
name|u_int64_t
name|gd_looffset
range|:
literal|16
decl_stmt|;
comment|/* gate offset (lsb) */
name|u_int64_t
name|gd_selector
range|:
literal|16
decl_stmt|;
comment|/* gate segment selector */
name|u_int64_t
name|gd_ist
range|:
literal|3
decl_stmt|;
comment|/* IST table index */
name|u_int64_t
name|gd_xx
range|:
literal|5
decl_stmt|;
comment|/* unused */
name|u_int64_t
name|gd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|u_int64_t
name|gd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|u_int64_t
name|gd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|u_int64_t
name|gd_hioffset
range|:
literal|48
name|__packed
decl_stmt|;
comment|/* gate offset (msb) */
name|u_int64_t
name|sd_xx1
range|:
literal|32
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

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
name|SDT_SYSLDT
value|2
end_define

begin_comment
comment|/* system 64 bit local descriptor table */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSTSS
value|9
end_define

begin_comment
comment|/* system available 64 bit TSS */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSBSY
value|11
end_define

begin_comment
comment|/* system busy 64 bit TSS */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSCGT
value|12
end_define

begin_comment
comment|/* system 64 bit call gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSIGT
value|14
end_define

begin_comment
comment|/* system 64 bit interrupt gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSTGT
value|15
end_define

begin_comment
comment|/* system 64 bit trap gate */
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
name|long
name|ssd_base
decl_stmt|;
comment|/* segment base address  */
name|unsigned
name|long
name|ssd_limit
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|long
name|ssd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|long
name|ssd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|long
name|ssd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|long
name|ssd_long
range|:
literal|1
decl_stmt|;
comment|/* long mode (for %cs) */
name|unsigned
name|long
name|ssd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|long
name|ssd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
block|}
name|__packed
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
name|long
name|rd_limit
range|:
literal|16
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|long
name|rd_base
range|:
literal|64
name|__packed
decl_stmt|;
comment|/* base address  */
block|}
name|__packed
struct|;
end_struct

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
comment|/* 32 reserved, 16 h/w, 0 s/w, linux's 0x80 */
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
comment|/*  * Entries in the Global Descriptor Table (GDT)  */
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
name|GCODE_SEL
value|1
end_define

begin_comment
comment|/* Kernel Code Descriptor */
end_comment

begin_define
define|#
directive|define
name|GDATA_SEL
value|2
end_define

begin_comment
comment|/* Kernel Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|GUCODE32_SEL
value|3
end_define

begin_comment
comment|/* User 32 bit code Descriptor */
end_comment

begin_define
define|#
directive|define
name|GUDATA_SEL
value|4
end_define

begin_comment
comment|/* User 32/64 bit Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|GUCODE_SEL
value|5
end_define

begin_comment
comment|/* User 64 bit Code Descriptor */
end_comment

begin_define
define|#
directive|define
name|GPROC0_SEL
value|6
end_define

begin_comment
comment|/* TSS for entering kernel etc */
end_comment

begin_comment
comment|/* slot 6 is second half of GPROC0_SEL */
end_comment

begin_define
define|#
directive|define
name|GUGS32_SEL
value|8
end_define

begin_comment
comment|/* User 32 bit GS Descriptor */
end_comment

begin_define
define|#
directive|define
name|NGDT
value|9
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|user_segment_descriptor
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
name|user_segment_descriptor
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
name|user_segment_descriptor
modifier|*
name|sdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssdtosyssd
parameter_list|(
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|,
name|struct
name|system_segment_descriptor
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

