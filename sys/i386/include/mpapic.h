begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: mpapic.h,v 1.3 1997/05/01 19:33:06 fsmp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MPAPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MPAPIC_H_
end_define

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/apic.h>
end_include

begin_comment
comment|/* number of busses */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NBUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NBUS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NBUS */
end_comment

begin_comment
comment|/* total number of APIC INTs, including SHARED INTs */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NINTR
argument_list|)
end_if

begin_define
define|#
directive|define
name|NINTR
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NINTR */
end_comment

begin_comment
comment|/* size of APIC ID list */
end_comment

begin_define
define|#
directive|define
name|NAPICID
value|16
end_define

begin_comment
comment|/* number of IO APICs */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NAPIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|NAPIC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAPIC */
end_comment

begin_comment
comment|/* these don't really belong in here... */
end_comment

begin_enum
enum|enum
name|busTypes
block|{
name|CBUS
init|=
literal|1
block|,
name|CBUSII
init|=
literal|2
block|,
name|EISA
init|=
literal|3
block|,
name|ISA
init|=
literal|6
block|,
name|PCI
init|=
literal|13
block|,
name|XPRESS
init|=
literal|18
block|,
name|MAX_BUSTYPE
init|=
literal|18
block|,
name|UNKNOWN_BUSTYPE
init|=
literal|0xff
block|}
enum|;
end_enum

begin_comment
comment|/*  * the physical/logical APIC ID management macors  */
end_comment

begin_define
define|#
directive|define
name|CPU_TO_ID
parameter_list|(
name|CPU
parameter_list|)
value|(cpu_num_to_apic_id[CPU])
end_define

begin_define
define|#
directive|define
name|ID_TO_CPU
parameter_list|(
name|ID
parameter_list|)
value|(apic_id_to_logical[ID])
end_define

begin_define
define|#
directive|define
name|IO_TO_ID
parameter_list|(
name|IO
parameter_list|)
value|(io_num_to_apic_id[IO])
end_define

begin_define
define|#
directive|define
name|ID_TO_IO
parameter_list|(
name|ID
parameter_list|)
value|(apic_id_to_logical[ID])
end_define

begin_comment
comment|/*  * inline functions to read/write the IO APIC  * NOTES:  *  unlike the local APIC, the IO APIC is accessed indirectly thru 2 registers.  *  the select register is loaded with an index to the desired 'window' reg.  *  the 'window' is accessed as a 32 bit unsigned.  */
end_comment

begin_comment
comment|/*  * read 'reg' from 'apic'  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|__inline
name|u_int32_t
name|io_apic_read
argument_list|(
name|int
name|apic
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|,
name|int
name|reg
argument_list|)
block|{
operator|(
operator|*
name|io_apic_base
operator|)
operator|=
name|reg
expr_stmt|;
return|return
operator|(
operator|*
operator|(
name|io_apic_base
operator|+
operator|(
name|IOAPIC_WINDOW
operator|/
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
operator|)
operator|)
operator|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
end_comment

begin_comment
comment|/*  * write 'value' to 'reg' of 'apic'  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|__inline
name|void
name|io_apic_write
argument_list|(
name|int
name|apic
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|,
name|int
name|reg
argument_list|,
name|u_int32_t
name|value
argument_list|)
block|{
operator|(
operator|*
name|io_apic_base
operator|)
operator|=
name|reg
expr_stmt|;
operator|(
operator|*
operator|(
name|io_apic_base
operator|+
operator|(
name|IOAPIC_WINDOW
operator|/
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
operator|)
operator|)
operator|)
operator|=
name|value
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
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
comment|/*  * set the IO APIC mask for INT# 'i'  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|set_io_apic_mask
parameter_list|(
name|int
name|apic
parameter_list|,
name|u_int32_t
name|i
parameter_list|)
block|{
name|int
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|low_reg
decl_stmt|;
comment|/* the window register is 32 bits */
name|imen
operator||=
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
comment|/* set mask variable */
name|select
operator|=
name|IOAPIC_REDTBL
operator|+
operator|(
name|i
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* calculate addr */
name|low_reg
operator|=
name|io_apic_read
argument_list|(
name|select
argument_list|)
expr_stmt|;
comment|/* read contents */
name|low_reg
operator||=
name|IOART_INTMASK
expr_stmt|;
comment|/* set mask */
name|io_apic_write
argument_list|(
name|select
argument_list|,
name|low_reg
argument_list|)
expr_stmt|;
comment|/* new value */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
end_comment

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
comment|/*  * clear the IO APIC mask for INT# 'i'  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|clr_io_apic_mask
parameter_list|(
name|int
name|apic
parameter_list|,
name|u_int32_t
name|i
parameter_list|)
block|{
name|int
name|select
decl_stmt|;
comment|/* the select register is 8 bits */
name|u_int32_t
name|low_reg
decl_stmt|;
comment|/* the window register is 32 bits */
name|imen
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
comment|/* clear mask variable */
name|select
operator|=
name|IOAPIC_REDTBL
operator|+
operator|(
name|i
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* calculate addr */
name|low_reg
operator|=
name|io_apic_read
argument_list|(
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
name|select
argument_list|,
name|low_reg
argument_list|)
expr_stmt|;
comment|/* new value */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READY */
end_comment

begin_comment
comment|/*  * read current IRQ0 -IRQ23 masks  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLE_IOAPICS
argument_list|)
end_if

begin_error
error|#
directive|error
error|MULTIPLE_IOAPICSXXX
end_error

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|__inline
name|u_int32_t
name|read_io_apic_mask24
argument_list|(
name|int
name|apic
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
return|return
operator|(
name|imen
operator|&
literal|0x00ffffff
operator|)
return|;
comment|/* return our global copy */
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLE_IOAPICS */
end_comment

begin_comment
comment|/*  * send an EndOfInterrupt to the local APIC  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|apic_eoi
parameter_list|(
name|void
parameter_list|)
block|{
name|apic_base
index|[
name|APIC_EOI
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to CPUs in 'targetMap'  * 'targetMap' is a bitfiled of length 14,  *   APIC #0 == bit 0, ..., APIC #14 == bit 14  *   NOTE: these are LOGICAL APIC IDs  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|selected_procs_ipi
parameter_list|(
name|int
name|targetMap
parameter_list|,
name|int
name|vector
parameter_list|)
block|{
return|return
name|selected_apic_ipi
argument_list|(
name|targetMap
argument_list|,
name|vector
argument_list|,
name|APIC_DELMODE_FIXED
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to all CPUs, including myself  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|all_procs_ipi
parameter_list|(
name|int
name|vector
parameter_list|)
block|{
return|return
name|apic_ipi
argument_list|(
name|APIC_DEST_ALLISELF
argument_list|,
name|vector
argument_list|,
name|APIC_DELMODE_FIXED
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to all CPUs EXCEPT myself  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|all_but_self_ipi
parameter_list|(
name|int
name|vector
parameter_list|)
block|{
return|return
name|apic_ipi
argument_list|(
name|APIC_DEST_ALLESELF
argument_list|,
name|vector
argument_list|,
name|APIC_DELMODE_FIXED
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * send an IPI INTerrupt containing 'vector' to myself  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|self_ipi
parameter_list|(
name|int
name|vector
parameter_list|)
block|{
return|return
name|apic_ipi
argument_list|(
name|APIC_DEST_SELF
argument_list|,
name|vector
argument_list|,
name|APIC_DELMODE_FIXED
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MPAPIC_H */
end_comment

end_unit

