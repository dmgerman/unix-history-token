begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Michael Smith (msmith@freebsd.org)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * 	From Id: probe_keyboard.c,v 1.13 1997/06/09 05:10:55 bde Exp  *  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_comment
comment|/* in comconsole.S */
end_comment

begin_function_decl
specifier|extern
name|void
name|cominit
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|computc
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comgetc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comiskey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|int
name|comc_in
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|console
name|comconsole
init|=
block|{
literal|"comconsole"
block|,
literal|"BIOS serial port"
block|,
literal|0
block|,
name|comc_probe
block|,
name|comc_init
block|,
name|computc
block|,
name|comc_in
block|,
name|comiskey
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
comment|/* XXX arg is unit number, should we use variables instead? */
name|cominit
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|comc_in
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|comiskey
argument_list|()
condition|)
block|{
return|return
operator|(
name|comgetc
argument_list|()
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_function

end_unit

