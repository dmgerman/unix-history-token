begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1996-1998 John D. Polstra.  * All rights reserved.  * Copyright (c) 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *    for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *      $Id: crt1.c,v 1.1.1.1 1998/03/07 20:27:10 jdp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_error
error|#
directive|error
literal|"GCC is needed to compile this file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RTLD
end_ifdef

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<rtld.h>
end_include

begin_decl_stmt
specifier|const
name|Obj_Entry
modifier|*
name|__mainprog_obj
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|__syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_exit
parameter_list|(
name|v
parameter_list|)
value|__syscall(SYS_exit, (v))
end_define

begin_define
define|#
directive|define
name|write
parameter_list|(
name|fd
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|__syscall(SYS_write, (fd), (s), (n))
end_define

begin_define
define|#
directive|define
name|_FATAL
parameter_list|(
name|str
parameter_list|)
define|\
value|do {					\ 		write(2, str, sizeof(str));	\ 		_exit(1);			\ 	} while (0)
end_define

begin_pragma
pragma|#
directive|pragma
name|weak
name|_DYNAMIC
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|_DYNAMIC
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * When doing a bootstrap build, the header files for runtime  * loader support are not available, so this source file is  * compiled to a static object.  */
end_comment

begin_define
define|#
directive|define
name|Obj_Entry
value|void
end_define

begin_struct_decl
struct_decl|struct
name|ps_strings
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__progname
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The entry function. */
end_comment

begin_function
name|void
name|_start
parameter_list|(
name|char
modifier|*
modifier|*
name|ap
parameter_list|,
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
comment|/* from shared loader */
specifier|const
name|Obj_Entry
modifier|*
name|obj
parameter_list|,
comment|/* from shared loader */
name|struct
name|ps_strings
modifier|*
name|ps_strings
parameter_list|)
block|{
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
name|argc
operator|=
operator|*
operator|(
name|long
operator|*
operator|)
name|ap
expr_stmt|;
name|argv
operator|=
name|ap
operator|+
literal|1
expr_stmt|;
name|env
operator|=
name|ap
operator|+
literal|2
operator|+
name|argc
expr_stmt|;
name|environ
operator|=
name|env
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|0
condition|)
name|__progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_RTLD
if|if
condition|(
operator|&
name|_DYNAMIC
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|obj
operator|==
name|NULL
operator|)
operator|||
operator|(
name|obj
operator|->
name|magic
operator|!=
name|RTLD_MAGIC
operator|)
condition|)
name|_FATAL
argument_list|(
literal|"Corrupt Obj_Entry pointer in GOT"
argument_list|)
expr_stmt|;
if|if
condition|(
name|obj
operator|->
name|version
operator|!=
name|RTLD_VERSION
condition|)
name|_FATAL
argument_list|(
literal|"Dynamic linker version mismatch"
argument_list|)
expr_stmt|;
name|__mainprog_obj
operator|=
name|obj
expr_stmt|;
name|atexit
argument_list|(
name|cleanup
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|atexit
argument_list|(
name|_fini
argument_list|)
expr_stmt|;
name|_init
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

