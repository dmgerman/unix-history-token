begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_comment
comment|/*-  * Copyright 2001 David E. O'Brien.  * All rights reserved.  * Copyright (c) 1995, 1998 Berkeley Software Design, Inc.  * All rights reserved.  * Copyright 1996-1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_include
include|#
directive|include
file|"crtbrand.c"
end_include

begin_struct_decl
struct_decl|struct
name|Struct_Obj_Entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ps_strings
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|_DYNAMIC
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|_DYNAMIC
end_pragma

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
name|void
name|_init
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

begin_function_decl
specifier|extern
name|void
name|_start
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|struct
name|Struct_Obj_Entry
modifier|*
parameter_list|,
name|struct
name|ps_strings
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__sparc_utrap_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|GCRT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_mcleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|monstartup
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|eprol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|etext
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
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

begin_comment
comment|/*  * %o0 holds ps_strings pointer.  *  * Note: kernel may (is not set in stone yet) pass ELF aux vector in %o1,  * but for now we do not use it here.  *  * The SPARC compliance definitions specifies that the kernel pass the  * address of a function to be executed on exit in %g1. We do not make  * use of it as it is quite broken, because gcc can use this register  * as a temporary, so it is not safe from C code. Its even more broken  * for dynamic executables since rtld runs first.  */
end_comment

begin_comment
comment|/* ARGSUSED */
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
name|struct
name|Struct_Obj_Entry
modifier|*
name|obj
name|__unused
parameter_list|,
name|struct
name|ps_strings
modifier|*
name|ps_strings
name|__unused
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
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|argc
operator|=
operator|*
operator|(
name|long
operator|*
operator|)
operator|(
name|void
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
operator|&&
name|argv
index|[
literal|0
index|]
operator|!=
name|NULL
condition|)
block|{
name|__progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
for|for
control|(
name|s
operator|=
name|__progname
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
if|if
condition|(
operator|*
name|s
operator|==
literal|'/'
condition|)
name|__progname
operator|=
name|s
operator|+
literal|1
expr_stmt|;
block|}
name|__sparc_utrap_setup
argument_list|()
expr_stmt|;
if|if
condition|(
operator|&
name|_DYNAMIC
operator|!=
name|NULL
condition|)
name|atexit
argument_list|(
name|cleanup
argument_list|)
expr_stmt|;
else|else
name|_init_tls
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|GCRT
name|atexit
argument_list|(
name|_mcleanup
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|atexit
argument_list|(
name|_fini
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GCRT
name|monstartup
argument_list|(
operator|&
name|eprol
argument_list|,
operator|&
name|etext
argument_list|)
expr_stmt|;
endif|#
directive|endif
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

begin_ifdef
ifdef|#
directive|ifdef
name|GCRT
end_ifdef

begin_asm
asm|__asm__(".text");
end_asm

begin_asm
asm|__asm__("eprol:");
end_asm

begin_asm
asm|__asm__(".previous");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|__asm__(".ident\t\"$FreeBSD$\"");
end_asm

end_unit

