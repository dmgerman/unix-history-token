begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)icu.h	5.6 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT/386 Interrupt Control constants  * W. Jolitz 8/89  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_ICU_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_ICU_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Note:  *	Most of the SMP equivilants of the icu macros are coded  *	elsewhere in an MP-safe fashion.  *	In particular note that the 'imen' variable is opaque.  *	DO NOT access imen directly, use INTREN()/INTRDIS().  */
end_comment

begin_function_decl
name|void
name|INTREN
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|INTRDIS
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|apic_imen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* APIC interrupt mask enable */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|unsigned
name|imen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt mask enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_comment
comment|/*  * Note: The APIC uses different values for IRQxxx.  *	 Unfortunately many drivers use the 8259 values as indexes  *	 into tables, etc.  The APIC equivilants are kept as APIC_IRQxxx.  *	 The 8259 versions have to be used in SMP for legacy operation  *	 of the drivers.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_comment
comment|/*  * Interrupt enable bits - in normal order of priority (which we change)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|IRQ0
value|0x0001
end_define

begin_define
define|#
directive|define
name|IRQ1
value|0x0002
end_define

begin_define
define|#
directive|define
name|IRQ2
value|0x0004
end_define

begin_define
define|#
directive|define
name|IRQ3
value|0x0008
end_define

begin_define
define|#
directive|define
name|IRQ4
value|0x0010
end_define

begin_define
define|#
directive|define
name|IRQ5
value|0x0020
end_define

begin_define
define|#
directive|define
name|IRQ6
value|0x0040
end_define

begin_define
define|#
directive|define
name|IRQ7
value|0x0080
end_define

begin_define
define|#
directive|define
name|IRQ_SLAVE
value|0x0080
end_define

begin_define
define|#
directive|define
name|IRQ8
value|0x0100
end_define

begin_define
define|#
directive|define
name|IRQ9
value|0x0200
end_define

begin_define
define|#
directive|define
name|IRQ10
value|0x0400
end_define

begin_define
define|#
directive|define
name|IRQ11
value|0x0800
end_define

begin_define
define|#
directive|define
name|IRQ12
value|0x1000
end_define

begin_define
define|#
directive|define
name|IRQ13
value|0x2000
end_define

begin_define
define|#
directive|define
name|IRQ14
value|0x4000
end_define

begin_define
define|#
directive|define
name|IRQ15
value|0x8000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IRQ0
value|0x0001
end_define

begin_comment
comment|/* highest priority - timer */
end_comment

begin_define
define|#
directive|define
name|IRQ1
value|0x0002
end_define

begin_define
define|#
directive|define
name|IRQ_SLAVE
value|0x0004
end_define

begin_define
define|#
directive|define
name|IRQ8
value|0x0100
end_define

begin_define
define|#
directive|define
name|IRQ9
value|0x0200
end_define

begin_define
define|#
directive|define
name|IRQ2
value|IRQ9
end_define

begin_define
define|#
directive|define
name|IRQ10
value|0x0400
end_define

begin_define
define|#
directive|define
name|IRQ11
value|0x0800
end_define

begin_define
define|#
directive|define
name|IRQ12
value|0x1000
end_define

begin_define
define|#
directive|define
name|IRQ13
value|0x2000
end_define

begin_define
define|#
directive|define
name|IRQ14
value|0x4000
end_define

begin_define
define|#
directive|define
name|IRQ15
value|0x8000
end_define

begin_define
define|#
directive|define
name|IRQ3
value|0x0008
end_define

begin_comment
comment|/* this is highest after rotation */
end_comment

begin_define
define|#
directive|define
name|IRQ4
value|0x0010
end_define

begin_define
define|#
directive|define
name|IRQ5
value|0x0020
end_define

begin_define
define|#
directive|define
name|IRQ6
value|0x0040
end_define

begin_define
define|#
directive|define
name|IRQ7
value|0x0080
end_define

begin_comment
comment|/* lowest - parallel printer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interrupt Control offset into Interrupt descriptor table (IDT)  */
end_comment

begin_define
define|#
directive|define
name|ICU_OFFSET
value|32
end_define

begin_comment
comment|/* 0-31 are processor exceptions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|ICU_IMR_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|ICU_SLAVEID
value|7
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ICU_IMR_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|ICU_SLAVEID
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ICU_EOI
value|0x20
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_comment
comment|/* 32-47: ISA IRQ0-IRQ15, 48-63: IO APIC IRQ16-IRQ31 */
end_comment

begin_define
define|#
directive|define
name|ICU_LEN
value|32
end_define

begin_define
define|#
directive|define
name|HWI_MASK
value|0xffffffff
end_define

begin_comment
comment|/* bits for h/w interrupts */
end_comment

begin_define
define|#
directive|define
name|NHWI
value|32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ICU_LEN
value|16
end_define

begin_comment
comment|/* 32-47 are ISA interrupts */
end_comment

begin_define
define|#
directive|define
name|HWI_MASK
value|0xffff
end_define

begin_comment
comment|/* bits for h/w interrupts */
end_comment

begin_define
define|#
directive|define
name|NHWI
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_define
define|#
directive|define
name|INTRCNT_COUNT
value|(1 + ICU_LEN + 2 * ICU_LEN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ICU_H_ */
end_comment

end_unit

