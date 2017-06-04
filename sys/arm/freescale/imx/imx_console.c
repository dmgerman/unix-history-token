begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Simple UART console driver for Freescale i.MX515 */
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

begin_comment
comment|/* Allow it to be predefined, to be able to use another UART for console */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX_UART_BASE
end_ifndef

begin_define
define|#
directive|define
name|IMX_UART_BASE
value|0xe3fbc000
end_define

begin_comment
comment|/* imx51 UART1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IMX_RXD
value|0x00
end_define

begin_define
define|#
directive|define
name|IMX_TXD
value|0x40
end_define

begin_define
define|#
directive|define
name|IMX_UFCR
value|0x90
end_define

begin_define
define|#
directive|define
name|IMX_USR1
value|0x94
end_define

begin_define
define|#
directive|define
name|IMX_USR1_TRDY
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IMX_USR2
value|0x98
end_define

begin_define
define|#
directive|define
name|IMX_USR2_RDR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMX_USR2_TXFE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IMX_USR2_TXDC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IMX_UTS
value|0xb4
end_define

begin_define
define|#
directive|define
name|IMX_UTS_TXFULL
value|(1<< 4)
end_define

begin_comment
comment|/*  * The base address of the uart registers.  *  * This is global so that it can be changed on the fly from the outside.  For  * example, set imx_uart_base=physaddr and then call cninit() as the first two  * lines of initarm() and enjoy printf() availability through the tricky bits of  * startup.  After initarm() switches from physical to virtual addressing, just  * set imx_uart_base=virtaddr and printf keeps working.  */
end_comment

begin_decl_stmt
name|uint32_t
name|imx_uart_base
init|=
name|IMX_UART_BASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * uart related funcs  */
end_comment

begin_function
specifier|static
name|uint32_t
name|ub_getreg
parameter_list|(
name|uint32_t
name|off
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
name|imx_uart_base
operator|+
name|off
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|ub_setreg
parameter_list|(
name|uint32_t
name|off
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
name|imx_uart_base
operator|+
name|off
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
name|ub_tstc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ub_getreg
argument_list|(
name|IMX_USR2
argument_list|)
operator|&
name|IMX_USR2_RDR
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
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
operator|!
name|ub_tstc
argument_list|()
condition|)
empty_stmt|;
asm|__asm __volatile("nop");
return|return
operator|(
name|ub_getreg
argument_list|(
name|IMX_RXD
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
name|ub_getreg
argument_list|(
name|IMX_UTS
argument_list|)
operator|&
name|IMX_UTS_TXFULL
condition|)
asm|__asm __volatile("nop");
name|ub_setreg
argument_list|(
name|IMX_TXD
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
block|{  }
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
block|{  }
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
comment|/* Init fifo trigger levels to 32 bytes, refclock div to 2. */
name|ub_setreg
argument_list|(
name|IMX_UFCR
argument_list|,
literal|0x00004210
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
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
specifier|static
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
block|{  }
end_function

begin_expr_stmt
name|CONSOLE_DRIVER
argument_list|(
name|uart
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

