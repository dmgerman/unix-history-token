begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_acpi.h"
end_include

begin_comment
comment|/* XXX trim includes */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|<dev/acpica/acpivar.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|powerprofile_state
init|=
name|POWERPROFILE_PERFORMANCE
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|powerprofile_get_state
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|powerprofile_state
operator|)
return|;
block|}
end_function

begin_function
name|void
name|powerprofile_set_state
parameter_list|(
name|int
name|state
parameter_list|)
block|{
name|int
name|changed
decl_stmt|;
name|ACPI_LOCK
expr_stmt|;
if|if
condition|(
name|state
operator|!=
name|powerprofile_state
condition|)
block|{
name|powerprofile_state
operator|=
name|state
expr_stmt|;
name|changed
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"system power profile changed to '%s'\n"
argument_list|,
operator|(
name|state
operator|==
name|POWERPROFILE_PERFORMANCE
operator|)
condition|?
literal|"performance"
else|:
literal|"economy"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|changed
operator|=
literal|0
expr_stmt|;
block|}
name|ACPI_UNLOCK
expr_stmt|;
if|if
condition|(
name|changed
condition|)
name|EVENTHANDLER_INVOKE
argument_list|(
name|powerprofile_change
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

