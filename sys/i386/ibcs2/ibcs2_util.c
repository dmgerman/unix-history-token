begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Christos Zoulas  * Copyright (c) 1995 Frank van der Linden  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: svr4_util.c,v 1.5 1995/01/22 23:44:50 christos Exp  */
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
file|<sys/fcntl.h>
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
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_util.h>
end_include

begin_decl_stmt
specifier|const
name|char
name|ibcs2_emul_path
index|[]
init|=
literal|"/compat/ibcs2"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Search an alternate path before passing pathname arguments on  * to system calls. Useful for keeping a separate 'emulation tree'.  *  * If cflag is set, we check if an attempt can be made to create  * the named file, i.e. we check if the directory it should  * be in exists.  */
end_comment

begin_function
name|int
name|ibcs2_emul_find
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|enum
name|uio_seg
name|pathseg
parameter_list|,
name|char
modifier|*
modifier|*
name|pbuf
parameter_list|,
name|int
name|cflag
parameter_list|)
block|{
return|return
operator|(
name|kern_alternate_path
argument_list|(
name|td
argument_list|,
name|ibcs2_emul_path
argument_list|,
name|path
argument_list|,
name|pathseg
argument_list|,
name|pbuf
argument_list|,
name|cflag
argument_list|,
name|AT_FDCWD
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

