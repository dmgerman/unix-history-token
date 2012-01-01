begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: uart.c,v 1.2 2007/03/23 20:05:47 dogcow Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
block|{  }
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
name|char
name|chr
decl_stmt|;
name|chr
operator|=
name|c
expr_stmt|;
while|while
condition|(
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|long
operator|*
operator|)
literal|0xb2600018
operator|)
operator|)
operator|&
literal|0x20
condition|)
empty_stmt|;
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|long
operator|*
operator|)
literal|0xb2600000
operator|)
operator|)
operator|=
name|c
expr_stmt|;
while|while
condition|(
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|long
operator|*
operator|)
literal|0xb2600018
operator|)
operator|)
operator|&
literal|0x20
condition|)
empty_stmt|;
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
while|while
condition|(
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|long
operator|*
operator|)
literal|0xb2600018
operator|)
operator|)
operator|&
literal|0x10
condition|)
empty_stmt|;
return|return
operator|(
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|long
operator|*
operator|)
literal|0xb2600000
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
name|uart_cnterm
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

begin_expr_stmt
name|CONSOLE_DRIVER
argument_list|(
name|uart
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

