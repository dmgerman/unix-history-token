begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|MAP_COPY
value|MAP_PRIVATE
end_define

begin_define
define|#
directive|define
name|MAP_FILE
value|0
end_define

begin_define
define|#
directive|define
name|MAP_ANON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_comment
comment|/* Need do better than this */
end_comment

begin_define
define|#
directive|define
name|NEED_DEV_ZERO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|caddr_t
name|sbrk
parameter_list|(
name|incr
parameter_list|)
name|int
name|incr
decl_stmt|;
block|{
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
name|caddr_t
name|curbrk
decl_stmt|;
comment|/* Round-up increment to page size */
name|incr
operator|=
operator|(
operator|(
name|incr
operator|+
name|PAGE_SIZE
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|PAGE_SIZE
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
if|#
directive|if
name|DEBUG
name|xprintf
argument_list|(
literal|"sbrk: incr = %#x\n"
argument_list|,
name|incr
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NEED_DEV_ZERO
name|fd
operator|=
name|open
argument_list|(
literal|"/dev/zero"
argument_list|,
name|O_RDWR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|perror
argument_list|(
literal|"/dev/zero"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|curbrk
operator|=
name|mmap
argument_list|(
literal|0
argument_list|,
name|incr
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_ANON
operator||
name|MAP_COPY
argument_list|,
name|fd
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|(
name|caddr_t
operator|)
operator|-
literal|1
condition|)
block|{
name|xprintf
argument_list|(
literal|"Cannot map anonymous memory"
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|xprintf
argument_list|(
literal|"sbrk: curbrk = %#x\n"
argument_list|,
name|curbrk
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NEED_DEV_ZERO
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|curbrk
operator|)
return|;
block|}
end_function

end_unit

