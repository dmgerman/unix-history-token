begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)icu.h	5.6 (Berkeley) 5/9/91  *	$Id: icu.h,v 1.15 1997/07/22 20:12:05 fsmp Exp $  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|APIC_IO
end_ifdef

begin_comment
comment|/* #define MP_SAFE  * Note:  *	Most of the SMP equivilants of the icu macros are coded  *	elsewhere in an MP-safe fashion.  *	In particular note that the 'imen' variable is opaque.  *	DO NOT access imen directly, use INTREN()/INTRDIS().  */
end_comment

begin_decl_stmt
name|void
name|INTREN
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|INTRDIS
name|__P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INTRMASK
parameter_list|(
name|msk
parameter_list|,
name|s
parameter_list|)
value|(msk |= (s))
end_define

begin_define
define|#
directive|define
name|INTRUNMASK
parameter_list|(
name|msk
parameter_list|,
name|s
parameter_list|)
value|(msk&= ~(s))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* APIC_IO */
end_comment

begin_comment
comment|/*  * Interrupt "level" mechanism variables, masks, and macros  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|imen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt mask enable */
end_comment

begin_define
define|#
directive|define
name|INTREN
parameter_list|(
name|s
parameter_list|)
value|(imen&= ~(s), SET_ICUS())
end_define

begin_define
define|#
directive|define
name|INTRDIS
parameter_list|(
name|s
parameter_list|)
value|(imen |= (s), SET_ICUS())
end_define

begin_define
define|#
directive|define
name|INTRMASK
parameter_list|(
name|msk
parameter_list|,
name|s
parameter_list|)
value|(msk |= (s))
end_define

begin_define
define|#
directive|define
name|INTRUNMASK
parameter_list|(
name|msk
parameter_list|,
name|s
parameter_list|)
value|(msk&= ~(s))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SET_ICUS
parameter_list|()
value|(outb(IO_ICU1 + 2, imen), outb(IU_ICU2 + 2, imen>> 8))
end_define

begin_define
define|#
directive|define
name|INTRGET
parameter_list|()
value|((inb(IO_ICU2)<< 8 | inb(IO_ICU1))& 0xffff)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC */
end_comment

begin_define
define|#
directive|define
name|SET_ICUS
parameter_list|()
value|(outb(IO_ICU1 + 1, imen), outb(IU_ICU2 + 1, imen>> 8))
end_define

begin_define
define|#
directive|define
name|INTRGET
parameter_list|()
value|((inb(IO_ICU2)<< 8 | inb(IO_ICU1))& 0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * XXX - IO_ICU* are defined in isa.h, not icu.h, and nothing much bothers to  * include isa.h, while too many things include icu.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|SET_ICUS
parameter_list|()
value|(outb(0x02, imen), outb(0x0a, imen>> 8))
end_define

begin_comment
comment|/* XXX is this correct? */
end_comment

begin_define
define|#
directive|define
name|INTRGET
parameter_list|()
value|((inb(0x0a)<< 8 | inb(0x02))& 0xffff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_ICUS
parameter_list|()
value|(outb(0x21, imen), outb(0xa1, imen>> 8))
end_define

begin_define
define|#
directive|define
name|INTRGET
parameter_list|()
value|((inb(0xa1)<< 8 | inb(0x21))& 0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_undef
undef|#
directive|undef
name|IRQ2
end_undef

begin_define
define|#
directive|define
name|IRQ2
value|0x0004
end_define

begin_undef
undef|#
directive|undef
name|IRQ_SLAVE
end_undef

begin_define
define|#
directive|define
name|IRQ_SLAVE
value|0x0080
end_define

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
name|APIC_IO
end_ifdef

begin_comment
comment|/* 32-47: ISA IRQ0-IRQ15, 48-55: IO APIC IRQ16-IRQ23 */
end_comment

begin_define
define|#
directive|define
name|ICU_LEN
value|24
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_ICU_H_ */
end_comment

end_unit

