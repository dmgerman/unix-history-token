begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: getdirentries.c,v 1.1 1997/10/10 02:15:56 fvdl Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Frank van der Linden  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Frank van der Linden for  *      the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_decl_stmt
name|int
name|getdents
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|getdirentries
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|nbytes
parameter_list|,
name|basep
parameter_list|)
name|int
name|fd
decl_stmt|,
name|nbytes
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|long
modifier|*
name|basep
decl_stmt|;
block|{
operator|*
name|basep
operator|=
name|lseek
argument_list|(
name|fd
argument_list|,
literal|0
argument_list|,
name|SEEK_CUR
argument_list|)
expr_stmt|;
return|return
name|getdents
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|nbytes
argument_list|)
return|;
block|}
end_function

end_unit

