begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Simple UART console driver for Allwinner A10 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|A10_UART_BASE
end_ifndef

begin_define
define|#
directive|define
name|A10_UART_BASE
value|0xe1c28000
end_define

begin_comment
comment|/* UART0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|UART_DLL
value|0
end_define

begin_comment
comment|/* Out: Divisor Latch Low */
end_comment

begin_define
define|#
directive|define
name|UART_DLM
value|1
end_define

begin_comment
comment|/* Out: Divisor Latch High */
end_comment

begin_define
define|#
directive|define
name|UART_FCR
value|2
end_define

begin_comment
comment|/* Out: FIFO Control Register */
end_comment

begin_define
define|#
directive|define
name|UART_LCR
value|3
end_define

begin_comment
comment|/* Out: Line Control Register */
end_comment

begin_define
define|#
directive|define
name|UART_MCR
value|4
end_define

begin_comment
comment|/* Out: Modem Control Register */
end_comment

begin_define
define|#
directive|define
name|UART_LSR
value|5
end_define

begin_comment
comment|/* In:  Line Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_LSR_THRE
value|0x20
end_define

begin_comment
comment|/* Transmit-hold-register empty */
end_comment

begin_define
define|#
directive|define
name|UART_LSR_DR
value|0x01
end_define

begin_comment
comment|/* Receiver data ready */
end_comment

begin_define
define|#
directive|define
name|UART_MSR
value|6
end_define

begin_comment
comment|/* In:  Modem Status Register */
end_comment

begin_define
define|#
directive|define
name|UART_SCR
value|7
end_define

begin_comment
comment|/* I/O: Scratch Register */
end_comment

begin_function
specifier|static
name|uint32_t
name|uart_getreg
parameter_list|(
name|uint32_t
modifier|*
name|bas
parameter_list|)
block|{
return|return
operator|*
operator|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|bas
operator|)
operator|)
operator|&
literal|0xff
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|uart_setreg
parameter_list|(
name|uint32_t
modifier|*
name|bas
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
operator|*
operator|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|bas
operator|)
operator|)
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|ub_getc
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
operator|(
name|uart_getreg
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|A10_UART_BASE
operator|+
operator|(
name|UART_LSR
operator|<<
name|REG_SHIFT
operator|)
operator|)
argument_list|)
operator|&
name|UART_LSR_DR
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
asm|__asm __volatile("nop");
return|return
operator|(
name|uart_getreg
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
name|A10_UART_BASE
argument_list|)
operator|&
literal|0xff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|ub_putc
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|)
block|{
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|ub_putc
argument_list|(
literal|'\r'
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|uart_getreg
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|A10_UART_BASE
operator|+
operator|(
name|UART_LSR
operator|<<
name|REG_SHIFT
operator|)
operator|)
argument_list|)
operator|&
name|UART_LSR_THRE
operator|)
operator|==
literal|0
condition|)
asm|__asm __volatile("nop");
name|uart_setreg
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
name|A10_UART_BASE
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|cn_probe_t
name|uart_cnprobe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_init_t
name|uart_cninit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_term_t
name|uart_cnterm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_getc_t
name|uart_cngetc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_putc_t
name|uart_cnputc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_grab_t
name|uart_cngrab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|cn_ungrab_t
name|uart_cnungrab
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|uart_cngrab
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|uart_cnungrab
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|uart_cnprobe
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{
name|sprintf
argument_list|(
name|cp
operator|->
name|cn_name
argument_list|,
literal|"uart"
argument_list|)
expr_stmt|;
name|cp
operator|->
name|cn_pri
operator|=
name|CN_NORMAL
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|uart_cninit
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{
name|uart_setreg
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
operator|(
name|A10_UART_BASE
operator|+
operator|(
name|UART_FCR
operator|<<
name|REG_SHIFT
operator|)
operator|)
argument_list|,
literal|0x06
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|uart_cnputc
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|ub_putc
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|uart_cngetc
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{
return|return
name|ub_getc
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|uart_cnterm
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
block|{ }
end_function

begin_expr_stmt
name|CONSOLE_DRIVER
argument_list|(
name|uart
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

