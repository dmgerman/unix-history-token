begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2001 David E. O'Brien  * All rights reserved.  * Copyright (c) 1995, 1998 Berkeley Software Design, Inc.  * All rights reserved.  * Copyright 1996-1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_function_decl
specifier|extern
name|void
name|__sparc64_utrap_setup
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
comment|/*  *  * %o0 holds ps_strings pointer.  For Solaris compat and/or shared  * libraries, if %g1 is not 0, it is a routine to pass to atexit().  * (By passing the pointer in the usual argument register, we avoid  * having to do any inline assembly, except to recover %g1.)  *  * Note: kernel may (is not set in stone yet) pass ELF aux vector in %o1,  * but for now we do not use it here.  */
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
name|struct
name|Struct_Obj_Entry
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
if|#
directive|if
literal|0
block|void (*term)(void);
comment|/* Grab %g1 before it gets used for anything by the compiler. */
comment|/* Sparc ELF psABI specifies a termination routine (if any) will be in 	   %g1 */
block|__asm__ volatile("mov %%g1,%0" : "=r"(term));
endif|#
directive|endif
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
operator|&&
name|argv
index|[
literal|0
index|]
operator|!=
name|NULL
condition|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
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
if|#
directive|if
literal|0
comment|/* 	 * If the kernel or a shared library wants us to call 	 * a termination function, arrange to do so. 	 */
block|if (term) 		atexit(term);
endif|#
directive|endif
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
if|#
directive|if
literal|0
block|atexit(_fini);
endif|#
directive|endif
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
if|#
directive|if
literal|0
block|_init();
endif|#
directive|endif
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

begin_comment
comment|/*  * NOTE: Leave the RCS ID _after_ __start(), in case it gets placed in .text.  */
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

end_unit

