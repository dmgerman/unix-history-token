begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"opt_cpu.h"
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
file|<sys/termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/tlsbreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/gbusreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/zsvar.h>
end_include

begin_function_decl
name|void
name|dec_3000_300_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dec_3000_300_cons_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|alpha_variation_table
name|dec_3000_300_variations
index|[]
init|=
block|{
block|{
name|SV_ST_PELICAN
block|,
literal|"DEC 3000/300 (\"Pelican\")"
block|}
block|,
block|{
name|SV_ST_PELICA
block|,
literal|"DEC 3000/300L (\"Pelica\")"
block|}
block|,
block|{
name|SV_ST_PELICANPLUS
block|,
literal|"DEC 3000/300X (\"Pelican+\")"
block|}
block|,
block|{
name|SV_ST_PELICAPLUS
block|,
literal|"DEC 3000/300LX (\"Pelica+\")"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|dec_3000_300_init
parameter_list|(
name|int
name|cputype
parameter_list|)
block|{
name|u_int64_t
name|variation
decl_stmt|;
name|platform
operator|.
name|family
operator|=
literal|"DEC 3000/300 (\"Pelican\")"
expr_stmt|;
if|if
condition|(
operator|(
name|platform
operator|.
name|model
operator|=
name|alpha_dsr_sysname
argument_list|()
operator|)
operator|==
name|NULL
condition|)
block|{
name|variation
operator|=
name|hwrpb
operator|->
name|rpb_variation
operator|&
name|SV_ST_MASK
expr_stmt|;
if|if
condition|(
operator|(
name|platform
operator|.
name|model
operator|=
name|alpha_variation_name
argument_list|(
name|variation
argument_list|,
name|dec_3000_300_variations
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|platform
operator|.
name|model
operator|=
name|alpha_unknown_sysname
argument_list|()
expr_stmt|;
block|}
name|platform
operator|.
name|iobus
operator|=
literal|"tcasic"
expr_stmt|;
name|platform
operator|.
name|cons_init
operator|=
name|dec_3000_300_cons_init
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * dec_3000_300_cons_init- not needed right now.  *  */
end_comment

begin_function
specifier|static
name|void
name|dec_3000_300_cons_init
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

