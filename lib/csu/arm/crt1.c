begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_comment
comment|/*-  * Copyright 2001 David E. O'Brien.  * All rights reserved.  * Copyright 1996-1998 John D. Polstra.  * All rights reserved.  * Copyright (c) 1997 Jason R. Thorpe.  * Copyright (c) 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *          This product includes software developed for the  *          FreeBSD Project.  See http://www.freebsd.org/ for  *          information about FreeBSD.  *          This product includes software developed for the  *          NetBSD Project.  See http://www.netbsd.org/ for  *          information about NetBSD.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|"ignore_init.c"
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

begin_function_decl
specifier|extern
name|void
name|_start
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
specifier|const
name|struct
name|Struct_Obj_Entry
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
name|ps_strings
modifier|*
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
name|struct
name|ps_strings
modifier|*
name|__ps_strings
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
name|struct
name|ps_strings
modifier|*
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
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
literal|"	mov	r5, r2		/* cleanup */		\n"
literal|"	mov	r4, r1		/* obj_main */		\n"
literal|"	mov	r3, r0		/* ps_strings */	\n"
literal|"	/* Get argc, argv, and envp from stack */	\n"
literal|"	ldr	r0, [sp, #0x0000]	\n"
literal|"	add	r1, sp, #0x0004		\n"
literal|"	add	r2, r1, r0, lsl #2	\n"
literal|"	add	r2, r2, #0x0004		\n"
literal|"	/* Ensure the stack is properly aligned before calling C code. */\n"
literal|"	bic	sp, sp, #7	\n"
literal|"	sub	sp, sp, #8	\n"
literal|"	str	r5, [sp, #4]	\n"
literal|"	str	r4, [sp, #0]	\n"
literal|"\n"
literal|"	b	 __start  "
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* ARGSUSED */
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
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|env
parameter_list|,
name|struct
name|ps_strings
modifier|*
name|ps_strings
parameter_list|,
specifier|const
name|struct
name|Struct_Obj_Entry
modifier|*
name|obj
name|__unused
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
name|ps_strings
operator|!=
operator|(
expr|struct
name|ps_strings
operator|*
operator|)
literal|0
condition|)
name|__ps_strings
operator|=
name|ps_strings
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

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|int32_t
name|namesz
decl_stmt|;
name|int32_t
name|descsz
decl_stmt|;
name|int32_t
name|type
decl_stmt|;
name|char
name|name
index|[
sizeof|sizeof
argument_list|(
name|NOTE_FREEBSD_VENDOR
argument_list|)
index|]
decl_stmt|;
name|char
name|desc
index|[
sizeof|sizeof
argument_list|(
name|MACHINE_ARCH
argument_list|)
index|]
decl_stmt|;
block|}
name|archtag
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
name|NOTE_SECTION
argument_list|)
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
name|__used
init|=
block|{
operator|.
name|namesz
operator|=
sizeof|sizeof
argument_list|(
name|NOTE_FREEBSD_VENDOR
argument_list|)
block|,
operator|.
name|descsz
operator|=
sizeof|sizeof
argument_list|(
name|MACHINE_ARCH
argument_list|)
block|,
operator|.
name|type
operator|=
name|ARCH_NOTETYPE
block|,
operator|.
name|name
operator|=
name|NOTE_FREEBSD_VENDOR
block|,
operator|.
name|desc
operator|=
name|MACHINE_ARCH
block|}
struct|;
end_struct

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

end_unit

