begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_comment
comment|/*-  * Copyright 1996-1998 John D. Polstra.  * Copyright 2014 Andrew Turner.  * Copyright 2014-2015 The FreeBSD Foundation.  * All rights reserved.  *  * Portions of this software were developed by Andrew Turner  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|"ignore_init.c"
end_include

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
specifier|extern
name|long
modifier|*
name|_end
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__start
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
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The entry function. */
end_comment

begin_asm
asm|__asm("	.text			\n"
end_asm

begin_expr_stmt
literal|"	.align	0		\n"
literal|"	.globl	_start		\n"
literal|"	_start:			\n"
literal|"	mov	x3, x2		\n"
comment|/* cleanup */
literal|"	add	x1, x0, #8	\n"
comment|/* load argv */
literal|"	ldr	x0, [x0]	\n"
comment|/* load argc */
literal|"	add	x2, x1, x0, lsl #3 \n"
comment|/* env is after argv */
literal|"	add	x2, x2, #8	\n"
comment|/* argv is null terminated */
literal|"	b	 __start  "
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The entry function. */
end_comment

begin_function
name|void
name|__start
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|env
index|[]
parameter_list|,
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|handle_argv
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
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
name|monstartup
argument_list|(
operator|&
name|eprol
argument_list|,
operator|&
name|etext
argument_list|)
expr_stmt|;
asm|__asm__("eprol:");
endif|#
directive|endif
name|handle_static_init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
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

