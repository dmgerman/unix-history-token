begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Peter Wemm and Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_APIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_APIC_H_
end_define

begin_comment
comment|/*  * Local&& I/O APIC definitions.  */
end_comment

begin_comment
comment|/*  * Pentium P54C+ Build-in APIC  * (Advanced programmable Interrupt Controller)  *   * Base Address of Build-in APIC in memory location  * is 0xfee00000.  *   * Map of APIC REgisters:  *   * Offset (hex)    Description                     Read/Write state  * 000             Reserved  * 010             Reserved  * 020 ID          Local APIC ID                   R/W  * 030 VER         Local APIC Version              R  * 040             Reserved  * 050             Reserved  * 060             Reserved  * 070             Reserved  * 080             Task Priority Register          R/W  * 090             Arbitration Priority Register   R  * 0A0             Processor Priority Register     R  * 0B0             EOI Register                    W  * 0C0 RRR         Remote read                     R  * 0D0             Logical Destination             R/W  * 0E0             Destination Format Register     0..27 R;  28..31 R/W  * 0F0 SVR         Spurious Interrupt Vector Reg.  0..3  R;  4..9   R/W  * 100             ISR  000-031                    R  * 110             ISR  032-063                    R  * 120             ISR  064-095                    R  * 130             ISR  095-128                    R  * 140             ISR  128-159                    R  * 150             ISR  160-191                    R  * 160             ISR  192-223                    R  * 170             ISR  224-255                    R  * 180             TMR  000-031                    R  * 190             TMR  032-063                    R  * 1A0             TMR  064-095                    R  * 1B0             TMR  095-128                    R  * 1C0             TMR  128-159                    R  * 1D0             TMR  160-191                    R  * 1E0             TMR  192-223                    R  * 1F0             TMR  224-255                    R  * 200             IRR  000-031                    R  * 210             IRR  032-063                    R  * 220             IRR  064-095                    R  * 230             IRR  095-128                    R  * 240             IRR  128-159                    R  * 250             IRR  160-191                    R  * 260             IRR  192-223                    R  * 270             IRR  224-255                    R  * 280             Error Status Register           R  * 290             Reserved  * 2A0             Reserved  * 2B0             Reserved  * 2C0             Reserved  * 2D0             Reserved  * 2E0             Reserved  * 2F0             Reserved  * 300 ICR_LOW     Interrupt Command Reg. (0-31)   R/W  * 310 ICR_HI      Interrupt Command Reg. (32-63)  R/W  * 320             Local Vector Table (Timer)      R/W  * 330             Reserved  * 340             Reserved  * 350 LVT1        Local Vector Table (LINT0)      R/W  * 360 LVT2        Local Vector Table (LINT1)      R/W  * 370 LVT3        Local Vector Table (ERROR)      R/W  * 380             Initial Count Reg. for Timer    R/W  * 390             Current Count of Timer          R  * 3A0             Reserved  * 3B0             Reserved  * 3C0             Reserved  * 3D0             Reserved  * 3E0             Timer Divide Configuration Reg. R/W  * 3F0             Reserved  */
end_comment

begin_comment
comment|/******************************************************************************  * global defines, etc.  */
end_comment

begin_comment
comment|/******************************************************************************  * LOCAL APIC structure  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|PAD3
value|int : 32; int : 32; int : 32
end_define

begin_define
define|#
directive|define
name|PAD4
value|int : 32; int : 32; int : 32; int : 32
end_define

begin_struct
struct|struct
name|LAPIC
block|{
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|id
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|version
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|tpr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|apr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|ppr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|eoi
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|ldr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|dfr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|svr
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr0
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr1
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr2
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr3
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr4
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr5
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr6
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|isr7
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr0
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr1
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr2
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr3
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr4
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr5
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr6
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|tmr7
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr0
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr1
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr2
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr3
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr4
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr5
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr6
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|irr7
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|esr
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|icr_lo
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|icr_hi
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|lvt_timer
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|lvt_pcint
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|lvt_lint0
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|lvt_lint1
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|lvt_error
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|icr_timer
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|ccr_timer
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
name|u_int32_t
name|dcr_timer
decl_stmt|;
name|PAD3
expr_stmt|;
comment|/* reserved */
name|PAD4
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LAPIC
name|lapic_t
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  * I/O APIC structure  */
end_comment

begin_struct
struct|struct
name|IOAPIC
block|{
name|u_int32_t
name|ioregsel
decl_stmt|;
name|PAD3
expr_stmt|;
name|u_int32_t
name|iowin
decl_stmt|;
name|PAD3
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|IOAPIC
name|ioapic_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|PAD4
end_undef

begin_undef
undef|#
directive|undef
name|PAD3
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_comment
comment|/******************************************************************************  * various code 'logical' values  */
end_comment

begin_comment
comment|/* default level for TPR */
end_comment

begin_define
define|#
directive|define
name|LOPRIO_LEVEL
value|0x00000010
end_define

begin_comment
comment|/* TPR of CPU accepting INTs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GRAB_LOPRIO
end_ifdef

begin_define
define|#
directive|define
name|ALLHWI_LEVEL
value|0x00000000
end_define

begin_comment
comment|/* TPR of CPU grabbing INTs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** GRAB_LOPRIO */
end_comment

begin_comment
comment|/* XXX these 2 don't really belong here... */
end_comment

begin_define
define|#
directive|define
name|COUNT_FIELD
value|0x00ffffff
end_define

begin_comment
comment|/* count portion of the lock */
end_comment

begin_define
define|#
directive|define
name|CPU_FIELD
value|0xff000000
end_define

begin_comment
comment|/* cpu portion of the lock */
end_comment

begin_define
define|#
directive|define
name|FREE_LOCK
value|0xffffffff
end_define

begin_comment
comment|/* value of lock when free */
end_comment

begin_comment
comment|/*  * XXX This code assummes that the reserved field of the  *      local APIC TPR can be written with all 0s.  *     This saves quite a few memory accesses.  *     If the silicon ever changes then things will break!  *     It affects mplock.s, swtch.s, and possibly other files.  */
end_comment

begin_define
define|#
directive|define
name|CHEAP_TPR
end_define

begin_comment
comment|/******************************************************************************  * LOCAL APIC defines  */
end_comment

begin_comment
comment|/* default physical locations of LOCAL (CPU) APICs */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_APIC_BASE
value|0xfee00000
end_define

begin_comment
comment|/* fields in VER */
end_comment

begin_define
define|#
directive|define
name|APIC_VER_VERSION
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_VER_MAXLVT
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MAXLVTSHIFT
value|16
end_define

begin_comment
comment|/* fields in SVR */
end_comment

begin_define
define|#
directive|define
name|APIC_SVR_VECTOR
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_SVR_VEC_PROG
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|APIC_SVR_VEC_FIX
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|APIC_SVR_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|APIC_SVR_SWDIS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_SVR_SWEN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|APIC_SVR_FOCUS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|APIC_SVR_FEN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_SVR_FDIS
value|0x00000200
end_define

begin_comment
comment|/* fields in TPR */
end_comment

begin_define
define|#
directive|define
name|APIC_TPR_PRIO
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_TPR_INT
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|APIC_TPR_SUB
value|0x0000000f
end_define

begin_comment
comment|/* fields in ICR_LOW */
end_comment

begin_define
define|#
directive|define
name|APIC_VECTOR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_FIXED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_LOWPRIO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_SMI
value|0x00000200
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_RR
value|0x00000300
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_NMI
value|0x00000400
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_INIT
value|0x00000500
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_STARTUP
value|0x00000600
end_define

begin_define
define|#
directive|define
name|APIC_DELMODE_RESV
value|0x00000700
end_define

begin_define
define|#
directive|define
name|APIC_DESTMODE_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|APIC_DESTMODE_PHY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_DESTMODE_LOG
value|0x00000800
end_define

begin_define
define|#
directive|define
name|APIC_DELSTAT_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|APIC_DELSTAT_IDLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_DELSTAT_PEND
value|0x00001000
end_define

begin_define
define|#
directive|define
name|APIC_RESV1_MASK
value|0x00002000
end_define

begin_define
define|#
directive|define
name|APIC_LEVEL_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|APIC_LEVEL_DEASSERT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_LEVEL_ASSERT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|APIC_TRIGMOD_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|APIC_TRIGMOD_EDGE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_TRIGMOD_LEVEL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|APIC_RRSTAT_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|APIC_RRSTAT_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_RRSTAT_INPROG
value|0x00010000
end_define

begin_define
define|#
directive|define
name|APIC_RRSTAT_VALID
value|0x00020000
end_define

begin_define
define|#
directive|define
name|APIC_RRSTAT_RESV
value|0x00030000
end_define

begin_define
define|#
directive|define
name|APIC_DEST_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|APIC_DEST_DESTFLD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_DEST_SELF
value|0x00040000
end_define

begin_define
define|#
directive|define
name|APIC_DEST_ALLISELF
value|0x00080000
end_define

begin_define
define|#
directive|define
name|APIC_DEST_ALLESELF
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|APIC_RESV2_MASK
value|0xfff00000
end_define

begin_comment
comment|/* fields in ICR_HIGH */
end_comment

begin_define
define|#
directive|define
name|APIC_ID_MASK
value|0x0f000000
end_define

begin_comment
comment|/* fields in LVT1/2 */
end_comment

begin_define
define|#
directive|define
name|APIC_LVT_VECTOR
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_LVT_DM
value|0x00000700
end_define

begin_define
define|#
directive|define
name|APIC_LVT_DM_FIXED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_DM_NMI
value|0x00000400
end_define

begin_define
define|#
directive|define
name|APIC_LVT_DM_EXTINT
value|0x00000700
end_define

begin_define
define|#
directive|define
name|APIC_LVT_DS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_IIPP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_IIPP_INTALO
value|0x00002000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_IIPP_INTAHI
value|0x00000000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_RIRR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_TM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|APIC_LVT_M
value|0x00010000
end_define

begin_comment
comment|/* fields in LVT Timer */
end_comment

begin_define
define|#
directive|define
name|APIC_LVTT_VECTOR
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|APIC_LVTT_DS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|APIC_LVTT_M
value|0x00010000
end_define

begin_define
define|#
directive|define
name|APIC_LVTT_TM
value|0x00020000
end_define

begin_comment
comment|/* fields in TDCR */
end_comment

begin_define
define|#
directive|define
name|APIC_TDCR_2
value|0x00
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_4
value|0x01
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_8
value|0x02
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_16
value|0x03
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_32
value|0x08
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_64
value|0x09
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_128
value|0x0a
end_define

begin_define
define|#
directive|define
name|APIC_TDCR_1
value|0x0b
end_define

begin_comment
comment|/*  * fields in IRR  * ISA INTerrupts are in bits 16-31 of the 1st IRR register.  * these masks DON'T EQUAL the isa IRQs of the same name.  */
end_comment

begin_define
define|#
directive|define
name|APIC_IRQ0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|APIC_IRQ1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|APIC_IRQ2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|APIC_IRQ3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|APIC_IRQ4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|APIC_IRQ5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|APIC_IRQ6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|APIC_IRQ7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|APIC_IRQ8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|APIC_IRQ9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|APIC_IRQ10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|APIC_IRQ11
value|0x00000800
end_define

begin_define
define|#
directive|define
name|APIC_IRQ12
value|0x00001000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ13
value|0x00002000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ14
value|0x00004000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ15
value|0x00008000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ16
value|0x00010000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ17
value|0x00020000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ18
value|0x00040000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ19
value|0x00080000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ21
value|0x00200000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ22
value|0x00400000
end_define

begin_define
define|#
directive|define
name|APIC_IRQ23
value|0x00800000
end_define

begin_comment
comment|/******************************************************************************  * I/O APIC defines  */
end_comment

begin_comment
comment|/* default physical locations of an IO APIC */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_IO_APIC_BASE
value|0xfec00000
end_define

begin_comment
comment|/* window register offset */
end_comment

begin_define
define|#
directive|define
name|IOAPIC_WINDOW
value|0x10
end_define

begin_comment
comment|/* indexes into IO APIC */
end_comment

begin_define
define|#
directive|define
name|IOAPIC_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|IOAPIC_VER
value|0x01
end_define

begin_define
define|#
directive|define
name|IOAPIC_ARB
value|0x02
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL
value|0x10
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL0
value|IOAPIC_REDTBL
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL1
value|(IOAPIC_REDTBL+0x02)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL2
value|(IOAPIC_REDTBL+0x04)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL3
value|(IOAPIC_REDTBL+0x06)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL4
value|(IOAPIC_REDTBL+0x08)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL5
value|(IOAPIC_REDTBL+0x0a)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL6
value|(IOAPIC_REDTBL+0x0c)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL7
value|(IOAPIC_REDTBL+0x0e)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL8
value|(IOAPIC_REDTBL+0x10)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL9
value|(IOAPIC_REDTBL+0x12)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL10
value|(IOAPIC_REDTBL+0x14)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL11
value|(IOAPIC_REDTBL+0x16)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL12
value|(IOAPIC_REDTBL+0x18)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL13
value|(IOAPIC_REDTBL+0x1a)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL14
value|(IOAPIC_REDTBL+0x1c)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL15
value|(IOAPIC_REDTBL+0x1e)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL16
value|(IOAPIC_REDTBL+0x20)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL17
value|(IOAPIC_REDTBL+0x22)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL18
value|(IOAPIC_REDTBL+0x24)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL19
value|(IOAPIC_REDTBL+0x26)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL20
value|(IOAPIC_REDTBL+0x28)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL21
value|(IOAPIC_REDTBL+0x2a)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL22
value|(IOAPIC_REDTBL+0x2c)
end_define

begin_define
define|#
directive|define
name|IOAPIC_REDTBL23
value|(IOAPIC_REDTBL+0x2e)
end_define

begin_comment
comment|/* fields in VER */
end_comment

begin_define
define|#
directive|define
name|IOART_VER_VERSION
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IOART_VER_MAXREDIR
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MAXREDIRSHIFT
value|16
end_define

begin_comment
comment|/*  * fields in the IO APIC's redirection table entries  */
end_comment

begin_define
define|#
directive|define
name|IOART_DEST
value|APIC_ID_MASK
end_define

begin_comment
comment|/* broadcast addr: all APICs */
end_comment

begin_define
define|#
directive|define
name|IOART_RESV
value|0x00fe0000
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|IOART_INTMASK
value|0x00010000
end_define

begin_comment
comment|/* R/W: INTerrupt mask */
end_comment

begin_define
define|#
directive|define
name|IOART_INTMCLR
value|0x00000000
end_define

begin_comment
comment|/*       clear, allow INTs */
end_comment

begin_define
define|#
directive|define
name|IOART_INTMSET
value|0x00010000
end_define

begin_comment
comment|/*       set, inhibit INTs */
end_comment

begin_define
define|#
directive|define
name|IOART_TRGRMOD
value|0x00008000
end_define

begin_comment
comment|/* R/W: trigger mode */
end_comment

begin_define
define|#
directive|define
name|IOART_TRGREDG
value|0x00000000
end_define

begin_comment
comment|/*       edge */
end_comment

begin_define
define|#
directive|define
name|IOART_TRGRLVL
value|0x00008000
end_define

begin_comment
comment|/*       level */
end_comment

begin_define
define|#
directive|define
name|IOART_REM_IRR
value|0x00004000
end_define

begin_comment
comment|/* RO: remote IRR */
end_comment

begin_define
define|#
directive|define
name|IOART_INTPOL
value|0x00002000
end_define

begin_comment
comment|/* R/W: INT input pin polarity */
end_comment

begin_define
define|#
directive|define
name|IOART_INTAHI
value|0x00000000
end_define

begin_comment
comment|/*      active high */
end_comment

begin_define
define|#
directive|define
name|IOART_INTALO
value|0x00002000
end_define

begin_comment
comment|/*      active low */
end_comment

begin_define
define|#
directive|define
name|IOART_DELIVS
value|0x00001000
end_define

begin_comment
comment|/* RO: delivery status */
end_comment

begin_define
define|#
directive|define
name|IOART_DESTMOD
value|0x00000800
end_define

begin_comment
comment|/* R/W: destination mode */
end_comment

begin_define
define|#
directive|define
name|IOART_DESTPHY
value|0x00000000
end_define

begin_comment
comment|/*      physical */
end_comment

begin_define
define|#
directive|define
name|IOART_DESTLOG
value|0x00000800
end_define

begin_comment
comment|/*      logical */
end_comment

begin_define
define|#
directive|define
name|IOART_DELMOD
value|0x00000700
end_define

begin_comment
comment|/* R/W: delivery mode */
end_comment

begin_define
define|#
directive|define
name|IOART_DELFIXED
value|0x00000000
end_define

begin_comment
comment|/*       fixed */
end_comment

begin_define
define|#
directive|define
name|IOART_DELLOPRI
value|0x00000100
end_define

begin_comment
comment|/*       lowest priority */
end_comment

begin_define
define|#
directive|define
name|IOART_DELSMI
value|0x00000200
end_define

begin_comment
comment|/*       System Management INT */
end_comment

begin_define
define|#
directive|define
name|IOART_DELRSV1
value|0x00000300
end_define

begin_comment
comment|/*       reserved */
end_comment

begin_define
define|#
directive|define
name|IOART_DELNMI
value|0x00000400
end_define

begin_comment
comment|/*       NMI signal */
end_comment

begin_define
define|#
directive|define
name|IOART_DELINIT
value|0x00000500
end_define

begin_comment
comment|/*       INIT signal */
end_comment

begin_define
define|#
directive|define
name|IOART_DELRSV2
value|0x00000600
end_define

begin_comment
comment|/*       reserved */
end_comment

begin_define
define|#
directive|define
name|IOART_DELEXINT
value|0x00000700
end_define

begin_comment
comment|/*       External INTerrupt */
end_comment

begin_define
define|#
directive|define
name|IOART_INTVEC
value|0x000000ff
end_define

begin_comment
comment|/* R/W: INTerrupt vector field */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_APIC_H_ */
end_comment

end_unit

