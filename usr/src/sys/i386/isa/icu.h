begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)icu.h	5.9 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ICU__
end_ifndef

begin_define
define|#
directive|define
name|__ICU__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Interrupt "level" mechanism variables, masks, and macros  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|imen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt mask enable */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|cpl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current priority level mask */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|highmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splhigh() */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|ttymask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with spltty() */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|biomask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splbio() */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|netmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group of interrupts masked with splimp() */
end_comment

begin_define
define|#
directive|define
name|INTREN
parameter_list|(
name|s
parameter_list|)
value|imen&= ~(s)
end_define

begin_define
define|#
directive|define
name|INTRDIS
parameter_list|(
name|s
parameter_list|)
value|imen |= (s)
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
value|msk |= (s)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Macro's for interrupt level priority masks (used in interrupt vector entry)  */
end_comment

begin_comment
comment|/* Mask a group of interrupts atomically */
end_comment

begin_define
define|#
directive|define
name|INTR_HEAD
parameter_list|(
name|unit
parameter_list|,
name|mask
parameter_list|,
name|offst
parameter_list|)
define|\
value|pushl	$ offst ; \ 	pushl	$ T_ASTFLT ; \ 	pushal ; \ 	movb	$0x20,%al ; \  #define INTR_TAIL(unit,mask,offst) \ 	outb	%al,$ IO_ICU1 ; \ 	pushl	%ds ; \ 	pushl	%es ; \ 	movw	$0x10, %ax ; \ 	movw	%ax, %ds ; \ 	movw	%ax,%es ; \ 	incl	_cnt+V_INTR ; \ 	incl	_isa_intr + offst * 4 ; \ 	movzwl	_cpl,%eax ; \ 	pushl	%eax ; \ 	pushl	$ unit ; \ 	orw	mask ,%ax ; \ 	movw	%ax,_cpl ; \ 	orw	_imen,%ax ; \ 	outb	%al,$ IO_ICU1+1 ; \ 	movb	%ah,%al ; \ 	outb	%al,$ IO_ICU2+1	; \ 	sti ;
end_define

begin_define
define|#
directive|define
name|INTR1
parameter_list|(
name|unit
parameter_list|,
name|mask
parameter_list|,
name|offst
parameter_list|)
define|\
value|INTR_HEAD(unit,mask,offst) \ 	INTR_TAIL(unit,mask,offst)
end_define

begin_define
define|#
directive|define
name|INTR2
parameter_list|(
name|unit
parameter_list|,
name|mask
parameter_list|,
name|offst
parameter_list|)
define|\
value|INTR_HEAD(unit,mask,offst) \ 	outb	%al,$ IO_ICU2 ; \ 	INTR_TAIL(unit,mask,offst)
end_define

begin_comment
comment|/* Interrupt vector exit macros */
end_comment

begin_comment
comment|/* First eight interrupts (ICU1) */
end_comment

begin_define
define|#
directive|define
name|INTREXIT1
define|\
value|jmp	doreti
end_define

begin_comment
comment|/* Second eight interrupts (ICU2) */
end_comment

begin_define
define|#
directive|define
name|INTREXIT2
define|\
value|jmp	doreti
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interrupt enable bits -- in order of priority  */
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
endif|__ICU__
end_endif

end_unit

