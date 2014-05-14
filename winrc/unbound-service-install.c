begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * winrc/unbound-service-install.c - windows services installation util  *  * Copyright (c) 2009, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to integrate with the windows services API.  * This means it handles the commandline switches to install and remove  * the service (via CreateService and DeleteService), it handles  * the ServiceMain() main service entry point when started as a service,  * and it handles the Handler[_ex]() to process requests to the service  * (such as start and stop and status).  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"winrc/w_inst.h"
end_include

begin_comment
comment|/** Install service main */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|FILE
modifier|*
name|out
init|=
name|stdout
decl_stmt|;
comment|/* out = fopen("unbound-service-install.log", "w");*/
if|if
condition|(
name|argc
operator|==
literal|2
operator|&&
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"start"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|wsvc_rc_start
argument_list|(
name|out
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|argc
operator|!=
literal|1
condition|)
block|{
if|if
condition|(
name|out
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"Usage: %s [start]\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Usage: %s [start]\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|wsvc_install
argument_list|(
name|out
argument_list|,
literal|"unbound-service-install.exe"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

