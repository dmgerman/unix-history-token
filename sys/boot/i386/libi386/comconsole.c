begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Michael Smith (msmith@freebsd.org)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<bootstrap.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|"libi386.h"
end_include

begin_comment
comment|/* selected defines from ns16550.h */
end_comment

begin_define
define|#
directive|define
name|com_data
value|0
end_define

begin_comment
comment|/* data register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|0
end_define

begin_comment
comment|/* divisor latch low (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|1
end_define

begin_comment
comment|/* divisor latch high (W) */
end_comment

begin_define
define|#
directive|define
name|com_ier
value|1
end_define

begin_comment
comment|/* interrupt enable (W) */
end_comment

begin_define
define|#
directive|define
name|com_iir
value|2
end_define

begin_comment
comment|/* interrupt identification (R) */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|2
end_define

begin_comment
comment|/* FIFO control (W) */
end_comment

begin_define
define|#
directive|define
name|com_lctl
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_mcr
value|4
end_define

begin_comment
comment|/* modem control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_lsr
value|5
end_define

begin_comment
comment|/* line status register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_msr
value|6
end_define

begin_comment
comment|/* modem status register (R/W) */
end_comment

begin_comment
comment|/* selected defines from sioreg.h */
end_comment

begin_define
define|#
directive|define
name|CFCR_DLAB
value|0x80
end_define

begin_define
define|#
directive|define
name|MCR_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|MCR_DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|LSR_TXRDY
value|0x20
end_define

begin_define
define|#
directive|define
name|LSR_RXRDY
value|0x01
end_define

begin_define
define|#
directive|define
name|COMC_FMT
value|0x3
end_define

begin_comment
comment|/* 8N1 */
end_comment

begin_define
define|#
directive|define
name|COMC_TXWAIT
value|0x40000
end_define

begin_comment
comment|/* transmit timeout */
end_comment

begin_define
define|#
directive|define
name|COMC_BPS
parameter_list|(
name|x
parameter_list|)
value|(115200 / (x))
end_define

begin_comment
comment|/* speed to DLAB divisor */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPORT
end_ifndef

begin_define
define|#
directive|define
name|COMPORT
value|0x3f8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COMSPEED
end_ifndef

begin_define
define|#
directive|define
name|COMSPEED
value|9600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|comc_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|comc_init
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|comc_putchar
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|comc_getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|comc_ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|comc_started
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|console
name|comconsole
init|=
block|{
literal|"comconsole"
block|,
literal|"serial port"
block|,
literal|0
block|,
name|comc_probe
block|,
name|comc_init
block|,
name|comc_putchar
block|,
name|comc_getchar
block|,
name|comc_ischar
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|comc_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
block|{
comment|/* XXX check the BIOS equipment list? */
name|cp
operator|->
name|c_flags
operator||=
operator|(
name|C_PRESENTIN
operator||
name|C_PRESENTOUT
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|comc_init
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|comc_started
operator|&&
name|arg
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|comc_started
operator|=
literal|1
expr_stmt|;
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_cfcr
argument_list|,
name|CFCR_DLAB
operator||
name|COMC_FMT
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_dlbl
argument_list|,
name|COMC_BPS
argument_list|(
name|COMSPEED
argument_list|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_dlbh
argument_list|,
name|COMC_BPS
argument_list|(
name|COMSPEED
argument_list|)
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_cfcr
argument_list|,
name|COMC_FMT
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_mcr
argument_list|,
name|MCR_RTS
operator||
name|MCR_DTR
argument_list|)
expr_stmt|;
do|do
name|inb
argument_list|(
name|COMPORT
operator|+
name|com_data
argument_list|)
expr_stmt|;
do|while
condition|(
name|inb
argument_list|(
name|COMPORT
operator|+
name|com_lsr
argument_list|)
operator|&
name|LSR_RXRDY
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|comc_putchar
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|int
name|wait
decl_stmt|;
for|for
control|(
name|wait
operator|=
name|COMC_TXWAIT
init|;
name|wait
operator|>
literal|0
condition|;
name|wait
operator|--
control|)
if|if
condition|(
name|inb
argument_list|(
name|COMPORT
operator|+
name|com_lsr
argument_list|)
operator|&
name|LSR_TXRDY
condition|)
block|{
name|outb
argument_list|(
name|COMPORT
operator|+
name|com_data
argument_list|,
operator|(
name|u_char
operator|)
name|c
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|comc_getchar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|comc_ischar
argument_list|()
condition|?
name|inb
argument_list|(
name|COMPORT
operator|+
name|com_data
argument_list|)
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|comc_ischar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|inb
argument_list|(
name|COMPORT
operator|+
name|com_lsr
argument_list|)
operator|&
name|LSR_RXRDY
operator|)
return|;
block|}
end_function

end_unit

