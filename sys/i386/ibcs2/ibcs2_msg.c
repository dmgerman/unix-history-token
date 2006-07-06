begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Steven Wallace  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_comment
comment|/*  * IBCS2 message compatibility module.  *  */
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
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_signal.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_util.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_proto.h>
end_include

begin_function
name|int
name|ibcs2_getmsg
parameter_list|(
name|td
parameter_list|,
name|uap
parameter_list|)
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|struct
name|ibcs2_getmsg_args
modifier|*
name|uap
decl_stmt|;
block|{
return|return
literal|0
return|;
comment|/* fake */
block|}
end_function

begin_function
name|int
name|ibcs2_putmsg
parameter_list|(
name|td
parameter_list|,
name|uap
parameter_list|)
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|struct
name|ibcs2_putmsg_args
modifier|*
name|uap
decl_stmt|;
block|{
return|return
literal|0
return|;
comment|/* fake */
block|}
end_function

end_unit

