begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*   * This file is only used with AIX   */
end_comment

begin_include
include|#
directive|include
file|"kafs_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: afslib.c,v 1.6 1999/12/02 16:58:40 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|aix_pioctl
parameter_list|(
name|char
modifier|*
name|a_path
parameter_list|,
name|int
name|o_opcode
parameter_list|,
name|struct
name|ViceIoctl
modifier|*
name|a_paramsP
parameter_list|,
name|int
name|a_followSymlinks
parameter_list|)
block|{
return|return
name|lpioctl
argument_list|(
name|a_path
argument_list|,
name|o_opcode
argument_list|,
name|a_paramsP
argument_list|,
name|a_followSymlinks
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|aix_setpag
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|lsetpag
argument_list|()
return|;
block|}
end_function

end_unit

