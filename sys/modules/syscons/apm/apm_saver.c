begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Nick Sayer (who stole shamelessly from blank_saver)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<dev/fb/fbreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/fb/splashreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/syscons/syscons.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<machine/apm_bios.h>
end_include

begin_include
include|#
directive|include
file|<machine/pc/bios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<pc98/apm/apm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<i386/apm/apm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|apm_display
name|__P
argument_list|(
operator|(
name|int
name|newstate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|apm_softc
name|apm_softc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|blanked
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|apm_saver
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|blank
parameter_list|)
block|{
if|if
condition|(
operator|!
name|apm_softc
operator|.
name|initialized
operator|||
operator|!
name|apm_softc
operator|.
name|active
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|blank
operator|==
name|blanked
condition|)
return|return
literal|0
return|;
name|blanked
operator|=
name|blank
expr_stmt|;
name|apm_display
argument_list|(
operator|!
name|blanked
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|apm_init
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
block|{
if|if
condition|(
operator|!
name|apm_softc
operator|.
name|initialized
operator|||
operator|!
name|apm_softc
operator|.
name|active
condition|)
name|printf
argument_list|(
literal|"WARNING: apm_saver module requires apm enabled\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|apm_term
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|scrn_saver_t
name|apm_module
init|=
block|{
literal|"apm_saver"
block|,
name|apm_init
block|,
name|apm_term
block|,
name|apm_saver
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SAVER_MODULE
argument_list|(
name|apm_saver
argument_list|,
name|apm_module
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

