begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: mpapic.c,v 1.1 1997/05/01 06:58:10 smp Exp smp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/mpapic.h>
end_include

begin_include
include|#
directive|include
file|<machine/smptests.h>
end_include

begin_comment
comment|/** TEST_LOPRIO, TEST_IPI */
end_comment

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_comment
comment|/* EISA Edge/Level trigger control registers */
end_comment

begin_define
define|#
directive|define
name|ELCR0
value|0x4d0
end_define

begin_comment
comment|/* eisa irq 0-7 */
end_comment

begin_define
define|#
directive|define
name|ELCR1
value|0x4d1
end_define

begin_comment
comment|/* eisa irq 8-15 */
end_comment

begin_comment
comment|/*  * pointers to pmapped apic hardware.  */
end_comment

begin_decl_stmt
specifier|volatile
name|u_int
modifier|*
name|apic_base
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_decl_stmt
specifier|volatile
name|u_int
modifier|*
name|io_apic_base
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_comment
comment|/*  * enable APIC, configure interrupts  */
end_comment

begin_function
name|void
name|apic_initialize
parameter_list|(
name|int
name|is_bsp
parameter_list|)
block|{
name|u_int
name|temp
decl_stmt|;
if|if
condition|(
name|is_bsp
condition|)
block|{
comment|/* setup LVT1 as ExtINT */
name|temp
operator|=
name|apic_base
index|[
name|APIC_LVT1
index|]
expr_stmt|;
name|temp
operator|&=
literal|0xfffe58ff
expr_stmt|;
name|temp
operator||=
literal|0x00000700
expr_stmt|;
name|apic_base
index|[
name|APIC_LVT1
index|]
operator|=
name|temp
expr_stmt|;
block|}
comment|/* setup LVT2 as NMI */
name|temp
operator|=
name|apic_base
index|[
name|APIC_LVT2
index|]
expr_stmt|;
name|temp
operator|&=
literal|0xfffe58ff
expr_stmt|;
name|temp
operator||=
literal|0xffff0400
expr_stmt|;
name|apic_base
index|[
name|APIC_LVT2
index|]
operator|=
name|temp
expr_stmt|;
comment|/* set the Task Priority Register as needed */
name|temp
operator|=
name|apic_base
index|[
name|APIC_TPR
index|]
expr_stmt|;
name|temp
operator|&=
operator|~
name|APIC_TPR_PRIO
expr_stmt|;
comment|/* clear priority field */
if|#
directive|if
name|defined
argument_list|(
name|TEST_LOPRIO
argument_list|)
if|if
condition|(
name|is_bsp
condition|)
name|temp
operator||=
literal|0x10
expr_stmt|;
comment|/* allow INT arbitration */
else|else
name|temp
operator||=
literal|0xff
expr_stmt|;
comment|/* disallow INT arbitration */
endif|#
directive|endif
comment|/* TEST_LOPRIO */
name|apic_base
index|[
name|APIC_TPR
index|]
operator|=
name|temp
expr_stmt|;
comment|/* enable the beast */
name|temp
operator|=
name|apic_base
index|[
name|APIC_SVR
index|]
expr_stmt|;
name|temp
operator||=
name|APIC_SVR_SWEN
expr_stmt|;
comment|/* software enable APIC */
name|temp
operator|&=
operator|~
name|APIC_SVR_FOCUS
expr_stmt|;
comment|/* enable 'focus processor' */
if|#
directive|if
literal|0
block|temp |= 0x20;
comment|/** FIXME: 2f == strayIRQ15 */
endif|#
directive|endif
name|apic_base
index|[
name|APIC_SVR
index|]
operator|=
name|temp
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APIC_IO
argument_list|)
end_if

begin_comment
comment|/*  * IO APIC code,  */
end_comment

begin_define
define|#
directive|define
name|IOAPIC_ISA_INTS
value|16
end_define

begin_define
define|#
directive|define
name|REDIRCNT_IOAPIC
parameter_list|(
name|A
parameter_list|)
define|\
value|((int)((io_apic_versions[(A)]& IOART_VER_MAXREDIR)>> MAXREDIRSHIFT) + 1)
end_define

begin_decl_stmt
specifier|static
name|int
name|trigger
name|__P
argument_list|(
operator|(
name|int
name|apic
operator|,
name|int
name|pin
operator|,
name|u_int32_t
operator|*
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|polarity
name|__P
argument_list|(
operator|(
name|int
name|apic
operator|,
name|int
name|pin
operator|,
name|u_int32_t
operator|*
name|flags
operator|,
name|int
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * setup I/O APIC  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOW_8259_IS_PROGRAMMED
end_ifdef

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
argument_list|,
literal|0x11
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reset; program device, four bytes */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
name|NRSVIDT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* starting at this vector index */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
literal|1
operator|<<
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* slave on line 2 */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 8086 mode */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
operator|+
literal|1
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* leave interrupts masked */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
argument_list|,
literal|0x0a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* default to IRR on read */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU1
argument_list|,
literal|0xc0
operator||
operator|(
literal|3
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pri order 3-7, 0-2 (com2 first) */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
argument_list|,
literal|0x11
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reset; program device, four bytes */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
name|NRSVIDT
operator|+
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* staring at this vector index */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* my slave id is 2 */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 8086 mode */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
operator|+
literal|1
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* leave interrupts masked */
end_comment

begin_expr_stmt
name|outb
argument_list|(
name|IO_ICU2
argument_list|,
literal|0x0a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* default to IRR on read */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOW_8259_IS_PROGRAMMED */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TEST_LOPRIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_FLAGS
define|\
value|((u_int32_t)		\ 	 (IOART_INTMSET |	\ 	  IOART_DESTPHY |	\ 	  IOART_DELLOPRI))
end_define

begin_define
define|#
directive|define
name|DEFAULT_ISA_FLAGS
define|\
value|((u_int32_t)		\ 	 (IOART_INTMSET |	\ 	  IOART_TRGREDG |	\ 	  IOART_INTAHI |	\ 	  IOART_DESTPHY |	\ 	  IOART_DELLOPRI))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_FLAGS
define|\
value|((u_int32_t)		\ 	 (IOART_INTMSET |	\ 	  IOART_DESTPHY |	\ 	  IOART_DELFIXED))
end_define

begin_define
define|#
directive|define
name|DEFAULT_ISA_FLAGS
define|\
value|((u_int32_t)		\ 	 (IOART_INTMSET |	\ 	  IOART_TRGREDG |	\ 	  IOART_INTAHI |	\ 	  IOART_DESTPHY |	\ 	  IOART_DELFIXED))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TEST_LOPRIO */
end_comment

begin_comment
comment|/*  *  */
end_comment

begin_function
name|int
name|io_apic_setup
parameter_list|(
name|int
name|apic
parameter_list|)
block|{
name|int
name|maxpin
decl_stmt|;
name|u_char
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|target
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|vector
decl_stmt|;
comment|/* the window register is 32 bits */
name|int
name|pin
decl_stmt|,
name|level
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|TEST_LOPRIO
argument_list|)
name|target
operator|=
name|IOART_DEST
expr_stmt|;
else|#
directive|else
name|target
operator|=
name|boot_cpu_id
operator|<<
literal|24
expr_stmt|;
endif|#
directive|endif
comment|/* TEST_LOPRIO */
if|if
condition|(
name|apic
operator|==
literal|0
condition|)
block|{
comment|/* APIC[0] INT0 thru INT15 default to ISA */
name|select
operator|=
name|IOAPIC_REDTBL0
expr_stmt|;
name|vector
operator|=
name|NRSVIDT
expr_stmt|;
for|for
control|(
name|pin
operator|=
literal|0
init|;
name|pin
operator|<
name|IOAPIC_ISA_INTS
condition|;
operator|++
name|pin
operator|,
operator|++
name|vector
operator|,
name|select
operator|+=
literal|2
control|)
block|{
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|DEFAULT_ISA_FLAGS
operator||
name|vector
argument_list|)
expr_stmt|;
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
operator|+
literal|1
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
comment|/* remainder of APIC[0] */
if|if
condition|(
operator|(
name|maxpin
operator|=
name|REDIRCNT_IOAPIC
argument_list|(
name|apic
argument_list|)
operator|)
operator|>
name|IOAPIC_ISA_INTS
condition|)
block|{
name|select
operator|=
name|IOAPIC_REDTBL16
expr_stmt|;
name|vector
operator|=
name|NRSVIDT
operator|+
name|IOAPIC_ISA_INTS
expr_stmt|;
for|for
control|(
name|pin
operator|=
name|IOAPIC_ISA_INTS
init|;
name|pin
operator|<
name|maxpin
condition|;
operator|++
name|pin
operator|,
operator|++
name|vector
operator|,
name|select
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|apic_int_type
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
operator|!=
literal|0
condition|)
continue|continue;
name|flags
operator|=
name|DEFAULT_FLAGS
expr_stmt|;
name|level
operator|=
name|trigger
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|,
operator|&
name|flags
argument_list|)
expr_stmt|;
name|polarity
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|,
operator|&
name|flags
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|flags
operator||
name|vector
argument_list|)
expr_stmt|;
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
operator|+
literal|1
argument_list|,
name|target
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|/* program entry according to MP table. */
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
else|#
directive|else
name|panic
argument_list|(
literal|"ioApicSetup: apic #%d\n"
argument_list|,
name|apic
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MULTIPLE_IOAPICS */
block|}
comment|/* return GOOD status */
return|return
literal|0
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|DEFAULT_ISA_FLAGS
end_undef

begin_undef
undef|#
directive|undef
name|DEFAULT_FLAGS
end_undef

begin_define
define|#
directive|define
name|DEFAULT_EXTINT_FLAGS
define|\
value|((u_int32_t)		\ 	 (IOART_INTMSET |	\ 	  IOART_TRGREDG |	\ 	  IOART_INTAHI |	\ 	  IOART_DESTPHY |	\ 	  IOART_DELEXINT))
end_define

begin_comment
comment|/*  *  */
end_comment

begin_function
name|int
name|ext_int_setup
parameter_list|(
name|int
name|apic
parameter_list|,
name|int
name|intr
parameter_list|)
block|{
name|u_char
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|target
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|vector
decl_stmt|;
comment|/* the window register is 32 bits */
if|if
condition|(
name|apic_int_type
argument_list|(
name|apic
argument_list|,
name|intr
argument_list|)
operator|!=
literal|3
condition|)
return|return
operator|-
literal|1
return|;
comment|/** FIXME: where should we steer ExtInts ??? */
if|#
directive|if
name|defined
argument_list|(
name|BROADCAST_EXTINT
argument_list|)
name|target
operator|=
name|IOART_DEST
expr_stmt|;
else|#
directive|else
name|target
operator|=
name|boot_cpu_id
operator|<<
literal|24
expr_stmt|;
endif|#
directive|endif
comment|/* BROADCAST_EXTINT */
name|select
operator|=
name|IOAPIC_REDTBL0
operator|+
operator|(
literal|2
operator|*
name|intr
operator|)
expr_stmt|;
name|vector
operator|=
name|NRSVIDT
operator|+
name|intr
expr_stmt|;
name|flags
operator|=
name|DEFAULT_EXTINT_FLAGS
expr_stmt|;
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|flags
operator||
name|vector
argument_list|)
expr_stmt|;
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
operator|+
literal|1
argument_list|,
name|target
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|DEFAULT_EXTINT_FLAGS
end_undef

begin_comment
comment|/*  *  */
end_comment

begin_function
specifier|static
name|int
name|trigger
parameter_list|(
name|int
name|apic
parameter_list|,
name|int
name|pin
parameter_list|,
name|u_int32_t
modifier|*
name|flags
parameter_list|)
block|{
name|int
name|id
decl_stmt|;
name|int
name|eirq
decl_stmt|;
name|int
name|level
decl_stmt|;
specifier|static
name|int
name|intcontrol
init|=
operator|-
literal|1
decl_stmt|;
switch|switch
condition|(
name|apic_trigger
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
condition|)
block|{
case|case
literal|0x00
case|:
break|break;
case|case
literal|0x01
case|:
operator|*
name|flags
operator|&=
operator|~
name|IOART_TRGRLVL
expr_stmt|;
comment|/* *flags |= IOART_TRGREDG */
return|return
literal|0
return|;
case|case
literal|0x03
case|:
operator|*
name|flags
operator||=
name|IOART_TRGRLVL
expr_stmt|;
return|return
literal|1
return|;
case|case
operator|-
literal|1
case|:
default|default:
goto|goto
name|bad
goto|;
block|}
if|if
condition|(
operator|(
name|id
operator|=
name|apic_src_bus_id
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
goto|goto
name|bad
goto|;
switch|switch
condition|(
name|apic_bus_type
argument_list|(
name|id
argument_list|)
condition|)
block|{
case|case
name|ISA
case|:
operator|*
name|flags
operator|&=
operator|~
name|IOART_TRGRLVL
expr_stmt|;
comment|/* *flags |= IOART_TRGREDG; */
return|return
literal|0
return|;
case|case
name|EISA
case|:
name|eirq
operator|=
name|apic_src_bus_irq
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
expr_stmt|;
if|if
condition|(
name|eirq
operator|<
literal|0
operator|||
name|eirq
operator|>
literal|15
condition|)
block|{
name|printf
argument_list|(
literal|"EISA IRQ %d?!?!\n"
argument_list|,
name|eirq
argument_list|)
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
if|if
condition|(
name|intcontrol
operator|==
operator|-
literal|1
condition|)
block|{
name|intcontrol
operator|=
name|inb
argument_list|(
name|ELCR1
argument_list|)
operator|<<
literal|8
expr_stmt|;
name|intcontrol
operator||=
name|inb
argument_list|(
name|ELCR0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"EISA INTCONTROL = %08x\n"
argument_list|,
name|intcontrol
argument_list|)
expr_stmt|;
block|}
comment|/* EISA IRQ's are identical to ISA irq's, regardless of 		 * whether they are edge or level since they go through the 		 * level/polarity converter gadget. */
name|level
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|level
condition|)
operator|*
name|flags
operator||=
name|IOART_TRGRLVL
expr_stmt|;
else|else
operator|*
name|flags
operator|&=
operator|~
name|IOART_TRGRLVL
expr_stmt|;
return|return
name|level
return|;
case|case
name|PCI
case|:
operator|*
name|flags
operator||=
name|IOART_TRGRLVL
expr_stmt|;
return|return
literal|1
return|;
case|case
operator|-
literal|1
case|:
default|default:
goto|goto
name|bad
goto|;
block|}
name|bad
label|:
name|panic
argument_list|(
literal|"bad APIC IO INT flags\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *  */
end_comment

begin_function
specifier|static
name|void
name|polarity
parameter_list|(
name|int
name|apic
parameter_list|,
name|int
name|pin
parameter_list|,
name|u_int32_t
modifier|*
name|flags
parameter_list|,
name|int
name|level
parameter_list|)
block|{
name|int
name|id
decl_stmt|;
name|int
name|eirq
decl_stmt|;
name|int
name|pol
decl_stmt|;
switch|switch
condition|(
name|apic_polarity
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
condition|)
block|{
case|case
literal|0x00
case|:
break|break;
case|case
literal|0x01
case|:
operator|*
name|flags
operator|&=
operator|~
name|IOART_INTALO
expr_stmt|;
comment|/* *flags |= IOART_INTAHI */
return|return;
case|case
literal|0x03
case|:
operator|*
name|flags
operator||=
name|IOART_INTALO
expr_stmt|;
return|return;
case|case
operator|-
literal|1
case|:
default|default:
goto|goto
name|bad
goto|;
block|}
if|if
condition|(
operator|(
name|id
operator|=
name|apic_src_bus_id
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
goto|goto
name|bad
goto|;
switch|switch
condition|(
name|apic_bus_type
argument_list|(
name|id
argument_list|)
condition|)
block|{
case|case
name|ISA
case|:
operator|*
name|flags
operator|&=
operator|~
name|IOART_INTALO
expr_stmt|;
comment|/* *flags |= IOART_INTAHI */
return|return;
case|case
name|EISA
case|:
name|eirq
operator|=
name|apic_src_bus_irq
argument_list|(
name|apic
argument_list|,
name|pin
argument_list|)
expr_stmt|;
if|if
condition|(
name|eirq
operator|<
literal|0
operator|||
name|eirq
operator|>
literal|15
condition|)
block|{
name|printf
argument_list|(
literal|"EISA POL: IRQ %d??\n"
argument_list|,
name|eirq
argument_list|)
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
comment|/* XXX EISA IRQ's are identical to ISA irq's, regardless of 		 * whether they are edge or level since they go through the 		 * level/polarity converter gadget. */
if|if
condition|(
name|level
operator|==
literal|1
condition|)
comment|/* XXX Always false */
name|pol
operator|=
literal|0
expr_stmt|;
comment|/* If level, active low */
else|else
name|pol
operator|=
literal|1
expr_stmt|;
comment|/* If edge, high edge */
if|if
condition|(
name|pol
operator|==
literal|0
condition|)
operator|*
name|flags
operator||=
name|IOART_INTALO
expr_stmt|;
else|else
operator|*
name|flags
operator|&=
operator|~
name|IOART_INTALO
expr_stmt|;
return|return;
case|case
name|PCI
case|:
operator|*
name|flags
operator||=
name|IOART_INTALO
expr_stmt|;
return|return;
case|case
operator|-
literal|1
case|:
default|default:
goto|goto
name|bad
goto|;
block|}
name|bad
label|:
name|panic
argument_list|(
literal|"bad APIC IO INT flags\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * set INT mask bit for each bit set in 'mask'.  * clear INT mask bit for all others.  * only consider lower 24 bits in mask.  */
end_comment

begin_define
define|#
directive|define
name|IO_MASK
value|(imen& 0x00ffffff)
end_define

begin_define
define|#
directive|define
name|IO_FIELD
value|0x00ffffff
end_define

begin_function
name|void
name|write_io_apic_mask24
parameter_list|(
name|int
name|apic
parameter_list|,
name|u_int32_t
name|mask
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|u_char
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|low_reg
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|diffs
decl_stmt|;
name|mask
operator|&=
name|IO_FIELD
expr_stmt|;
comment|/* safety valve, only use 24 bits */
if|if
condition|(
name|mask
operator|==
name|IO_MASK
condition|)
comment|/* check for same value as current */
return|return;
name|diffs
operator|=
name|mask
operator|^
name|IO_MASK
expr_stmt|;
comment|/* record differences */
for|for
control|(
name|x
operator|=
literal|0
operator|,
name|y
operator|=
name|REDIRCNT_IOAPIC
argument_list|(
name|apic
argument_list|)
init|;
name|x
operator|<
name|y
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|diffs
operator|&
operator|(
literal|1
operator|<<
name|x
operator|)
operator|)
condition|)
continue|continue;
comment|/* no change, skip */
name|select
operator|=
name|IOAPIC_REDTBL
operator|+
operator|(
name|x
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* calculate addr */
name|low_reg
operator|=
name|io_apic_read
argument_list|(
name|apic
argument_list|,
name|select
argument_list|)
expr_stmt|;
comment|/* read contents */
if|if
condition|(
name|mask
operator|&
operator|(
literal|1
operator|<<
name|x
operator|)
condition|)
name|low_reg
operator||=
name|IOART_INTMASK
expr_stmt|;
comment|/* set mask */
else|else
name|low_reg
operator|&=
operator|~
name|IOART_INTMASK
expr_stmt|;
comment|/* clear mask */
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|low_reg
argument_list|)
expr_stmt|;
comment|/* new value */
block|}
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READY
argument_list|)
end_if

begin_comment
comment|/*  * set INT mask bit for each bit set in 'mask'.  * ignore INT mask bit for all others.  * only consider lower 24 bits in mask.  */
end_comment

begin_function
name|void
name|set_io_apic_mask24
parameter_list|(
name|apic
parameter_list|,
name|u_int32_t
name|bits
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|u_char
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|low_reg
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|diffs
decl_stmt|;
name|bits
operator|&=
name|IO_FIELD
expr_stmt|;
comment|/* safety valve, only use 24 bits */
name|diffs
operator|=
name|bits
operator|&
operator|~
name|IO_MASK
expr_stmt|;
comment|/* clear AND needing 'set'ing */
if|if
condition|(
operator|!
name|diffs
condition|)
return|return;
error|#
directive|error
error|imen/IOApicMask NOT merged in setIOApicMask24()
for|for
control|(
name|x
operator|=
literal|0
operator|,
name|y
operator|=
name|REDIRCNT_IOAPIC
argument_list|(
literal|0
argument_list|)
init|;
name|x
operator|<
name|y
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|diffs
operator|&
operator|(
literal|1
operator|<<
name|x
operator|)
operator|)
condition|)
continue|continue;
comment|/* no change, skip */
name|select
operator|=
name|IOAPIC_REDTBL
operator|+
operator|(
name|x
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* calculate addr */
name|low_reg
operator|=
name|io_apic_read
argument_list|(
name|apic
argument_list|,
name|select
argument_list|)
expr_stmt|;
comment|/* read contents */
name|lowReg
operator||=
name|IOART_INTMASK
expr_stmt|;
comment|/* set mask */
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|low_reg
argument_list|)
expr_stmt|;
comment|/* new value */
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READY
argument_list|)
end_if

begin_comment
comment|/*  * clear INT mask bit for each bit set in 'mask'.  * ignore INT mask bit for all others.  * only consider lower 24 bits in mask.  */
end_comment

begin_function
name|void
name|clr_io_apic_mask24
parameter_list|(
name|int
name|apic
parameter_list|,
name|u_int32_t
name|bits
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|u_char
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|low_reg
decl_stmt|;
comment|/* the window register is 32 bits */
name|u_int32_t
name|diffs
decl_stmt|;
name|bits
operator|&=
name|IO_FIELD
expr_stmt|;
comment|/* safety valve, only use 24 bits */
name|diffs
operator|=
name|bits
operator|&
name|IO_MASK
expr_stmt|;
comment|/* set AND needing 'clr'ing */
if|if
condition|(
operator|!
name|diffs
condition|)
return|return;
error|#
directive|error
error|imen/IOApicMask NOT merged in clrIOApicMask24()
for|for
control|(
name|x
operator|=
literal|0
operator|,
name|y
operator|=
name|REDIRCNT_IOAPIC
argument_list|(
name|apic
argument_list|)
init|;
name|x
operator|<
name|y
condition|;
operator|++
name|x
control|)
block|{
if|if
condition|(
operator|!
operator|(
name|diffs
operator|&
operator|(
literal|1
operator|<<
name|x
operator|)
operator|)
condition|)
continue|continue;
comment|/* no change, skip */
name|select
operator|=
name|IOAPIC_REDTBL
operator|+
operator|(
name|x
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* calculate addr */
name|low_reg
operator|=
name|io_apic_read
argument_list|(
name|apic
argument_list|,
name|select
argument_list|)
expr_stmt|;
comment|/* read contents */
name|low_reg
operator|&=
operator|~
name|IOART_INTMASK
expr_stmt|;
comment|/* clear mask */
name|io_apic_write
argument_list|(
name|apic
argument_list|,
name|select
argument_list|,
name|low_reg
argument_list|)
expr_stmt|;
comment|/* new value */
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

begin_undef
undef|#
directive|undef
name|IO_FIELD
end_undef

begin_undef
undef|#
directive|undef
name|IO_MASK
end_undef

begin_comment
comment|/*  * Inter Processor Interrupt functions.  */
end_comment

begin_comment
comment|/*  * send APIC IPI 'vector' to 'destType' via 'deliveryMode'  *  *  destType is 1 of: APIC_DEST_SELF, APIC_DEST_ALLISELF, APIC_DEST_ALLESELF  *  vector is any valid SYSTEM INT vector  *  delivery_mode is 1 of: APIC_DELMODE_FIXED, APIC_DELMODE_LOWPRIO  */
end_comment

begin_define
define|#
directive|define
name|DETECT_DEADLOCK
end_define

begin_function
name|int
name|apic_ipi
parameter_list|(
name|int
name|dest_type
parameter_list|,
name|int
name|vector
parameter_list|,
name|int
name|delivery_mode
parameter_list|)
block|{
name|u_long
name|icr_lo
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DETECT_DEADLOCK
argument_list|)
define|#
directive|define
name|MAX_SPIN1
value|10000000
define|#
directive|define
name|MAX_SPIN2
value|1000
name|int
name|x
decl_stmt|;
comment|/* "lazy delivery", ie we only barf if they stack up on us... */
for|for
control|(
name|x
operator|=
name|MAX_SPIN1
init|;
name|x
condition|;
operator|--
name|x
control|)
block|{
if|if
condition|(
operator|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_DELSTAT_MASK
operator|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"apic_ipi was stuck\n"
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* DETECT_DEADLOCK */
comment|/* build IRC_LOW */
name|icr_lo
operator|=
operator|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_RESV2_MASK
operator|)
operator||
name|dest_type
operator||
name|delivery_mode
operator||
name|vector
expr_stmt|;
comment|/* write APIC ICR */
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|=
name|icr_lo
expr_stmt|;
comment|/* wait for pending status end */
if|#
directive|if
name|defined
argument_list|(
name|DETECT_DEADLOCK
argument_list|)
for|for
control|(
name|x
operator|=
name|MAX_SPIN2
init|;
name|x
condition|;
operator|--
name|x
control|)
block|{
if|if
condition|(
operator|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_DELSTAT_MASK
operator|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"apic_ipi might be stuck\n"
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|MAX_SPIN2
undef|#
directive|undef
name|MAX_SPIN1
else|#
directive|else
while|while
condition|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_DELSTAT_MASK
condition|)
comment|/* spin */
empty_stmt|;
endif|#
directive|endif
comment|/* DETECT_DEADLOCK */
comment|/** FIXME: return result */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * send APIC IPI 'vector' to 'target's via 'delivery_mode'  *  *  target contains a bitfield with a bit set for selected APICs.  *  vector is any valid SYSTEM INT vector  *  delivery_mode is 1 of: APIC_DELMODE_FIXED, APIC_DELMODE_LOWPRIO  */
end_comment

begin_function
name|int
name|selected_apic_ipi
parameter_list|(
name|u_int
name|target
parameter_list|,
name|int
name|vector
parameter_list|,
name|int
name|delivery_mode
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|int
name|status
decl_stmt|;
name|u_long
name|icr_hi
decl_stmt|;
if|if
condition|(
name|target
operator|&
operator|~
literal|0x7fff
condition|)
return|return
operator|-
literal|1
return|;
comment|/* only 15 targets allowed */
for|for
control|(
name|status
operator|=
literal|0
operator|,
name|x
operator|=
literal|0
init|;
name|x
operator|<=
literal|14
condition|;
operator|++
name|x
control|)
if|if
condition|(
name|target
operator|&
operator|(
literal|1
operator|<<
name|x
operator|)
condition|)
block|{
comment|/* write the destination field for the target AP */
name|icr_hi
operator|=
name|apic_base
index|[
name|APIC_ICR_HI
index|]
operator|&
operator|~
name|APIC_ID_MASK
expr_stmt|;
name|icr_hi
operator||=
operator|(
name|CPU_TO_ID
argument_list|(
name|x
argument_list|)
operator|<<
literal|24
operator|)
expr_stmt|;
name|apic_base
index|[
name|APIC_ICR_HI
index|]
operator|=
name|icr_hi
expr_stmt|;
comment|/* send the IPI */
if|if
condition|(
name|apic_ipi
argument_list|(
name|APIC_DEST_DESTFLD
argument_list|,
name|vector
argument_list|,
name|delivery_mode
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|status
operator||=
operator|(
literal|1
operator|<<
name|x
operator|)
expr_stmt|;
block|}
return|return
name|status
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READY
argument_list|)
end_if

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to CPU 'target'  *   NOTE: target is a LOGICAL APIC ID  */
end_comment

begin_function
name|int
name|selected_proc_ipi
parameter_list|(
name|int
name|target
parameter_list|,
name|int
name|vector
parameter_list|)
block|{
name|u_long
name|icr_lo
decl_stmt|;
name|u_long
name|icr_hi
decl_stmt|;
comment|/* write the destination field for the target AP */
name|icr_hi
operator|=
operator|(
name|apic_base
index|[
name|APIC_ICR_HI
index|]
operator|&
operator|~
name|APIC_ID_MASK
operator|)
operator||
operator|(
name|cpu_num_to_apic_id
index|[
name|target
index|]
operator|<<
literal|24
operator|)
expr_stmt|;
name|apic_base
index|[
name|APIC_ICR_HI
index|]
operator|=
name|icr_hi
expr_stmt|;
comment|/* write command */
name|icr_lo
operator|=
operator|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_RESV2_MASK
operator|)
operator||
name|APIC_DEST_DESTFLD
operator||
name|APIC_DELMODE_FIXED
operator||
name|vector
expr_stmt|;
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|=
name|icr_lo
expr_stmt|;
comment|/* wait for pending status end */
while|while
condition|(
name|apic_base
index|[
name|APIC_ICR_LOW
index|]
operator|&
name|APIC_DELSTAT_MASK
condition|)
comment|/* spin */
empty_stmt|;
return|return
literal|0
return|;
comment|/** FIXME: return result */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APIC_IO */
end_comment

begin_comment
comment|/*  * timer code, in development...  * suggested by rgrimes@gndrsh.aac.dev.com  */
end_comment

begin_comment
comment|/** FIXME: temp hack till we can determin bus clock */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUS_CLOCK
end_ifndef

begin_define
define|#
directive|define
name|BUS_CLOCK
value|66000000
end_define

begin_define
define|#
directive|define
name|bus_clock
parameter_list|()
value|66000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READY
argument_list|)
end_if

begin_decl_stmt
name|int
name|acquire_apic_timer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|release_apic_timer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * acquire the APIC timer for exclusive use  */
end_comment

begin_function
name|int
name|acquire_apic_timer
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|1
return|return
literal|0
return|;
else|#
directive|else
comment|/** FIXME: make this really do something */
name|panic
argument_list|(
literal|"APIC timer in use when attempting to aquire\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * return the APIC timer  */
end_comment

begin_function
name|int
name|release_apic_timer
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|1
return|return
literal|0
return|;
else|#
directive|else
comment|/** FIXME: make this really do something */
name|panic
argument_list|(
literal|"APIC timer was already released\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

begin_comment
comment|/*  * load a 'downcount time' in uSeconds  */
end_comment

begin_function
name|void
name|set_apic_timer
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|u_long
name|lvtt
decl_stmt|;
name|long
name|ticks_per_microsec
decl_stmt|;
comment|/* calculate divisor and count from value: 	 *  	 * timeBase == CPU bus clock divisor == [1,2,4,8,16,32,64,128] value == 	 * time in uS */
name|apic_base
index|[
name|APIC_TDCR
index|]
operator|=
name|APIC_TDCR_1
expr_stmt|;
name|ticks_per_microsec
operator|=
name|bus_clock
argument_list|()
operator|/
literal|1000000
expr_stmt|;
comment|/* configure timer as one-shot */
name|lvtt
operator|=
name|apic_base
index|[
name|APIC_LVTT
index|]
expr_stmt|;
name|lvtt
operator|&=
operator|~
operator|(
name|APIC_LVTT_VECTOR
operator||
name|APIC_LVTT_DS
operator||
name|APIC_LVTT_M
operator||
name|APIC_LVTT_TM
operator|)
expr_stmt|;
name|lvtt
operator||=
name|APIC_LVTT_M
expr_stmt|;
comment|/* no INT, one-shot */
name|apic_base
index|[
name|APIC_LVTT
index|]
operator|=
name|lvtt
expr_stmt|;
comment|/* */
name|apic_base
index|[
name|APIC_TICR
index|]
operator|=
name|value
operator|*
name|ticks_per_microsec
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * read remaining time in timer  */
end_comment

begin_function
name|int
name|read_apic_timer
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
literal|0
comment|/** FIXME: we need to return the actual remaining time,          *         for now we just return the remaining count.          */
else|#
directive|else
return|return
name|apic_base
index|[
name|APIC_TCCR
index|]
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * spin-style delay, set delay time in uS, spin till it drains  */
end_comment

begin_function
name|void
name|u_sleep
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|set_apic_timer
argument_list|(
name|count
argument_list|)
expr_stmt|;
while|while
condition|(
name|read_apic_timer
argument_list|()
condition|)
comment|/* spin */
empty_stmt|;
block|}
end_function

end_unit

