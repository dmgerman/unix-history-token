begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *    for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|NOSHARED
end_ifndef

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

begin_decl_stmt
name|struct
name|ps_strings
modifier|*
name|__ps_strings
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|__gccmain
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|__main
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|/*  * Historically, mips has used __start for the beginning address of programs.  * However, the Cavium toolchain (and maybe others) use _start.  Define both  * here.  The assembler code here tries to juggle the arguments such that they  * are right for all ABIs and then calls __start_mips which is what used to  * be just plain __start, and still is on other BSD ports.  */
end_comment

begin_comment
comment|/* The entry function. */
end_comment

begin_asm
asm|__asm("	.text			\n"
end_asm

begin_expr_stmt
literal|"	.align	8		\n"
literal|"	.globl	_start		\n"
literal|"	_start:			\n"
literal|"	.globl	__start		\n"
literal|"	__start:		\n"
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
literal|"	.cpsetup $25, $24, __start\n"
else|#
directive|else
literal|"	.set noreorder		\n"
literal|"	.cpload $25		\n"
literal|"	.set reorder		\n"
endif|#
directive|endif
literal|"	/* Get cleanup routine and main object set by rtld */\n"
literal|"	/* Note that a2 is already set to ps_string by _rtld_start */\n"
literal|"	/* move	a3, a0        */\n"
literal|"	/* move	t0, a1        */\n"
literal|"	/* Get argc, argv from stack */	\n"
literal|"	/* lw	a0, 0(sp)     */\n"
literal|"	/* move	a1, sp        */\n"
literal|"	/* addu	a1, 4         */\n"
literal|"				\n"
literal|"	/* Stack should 8bytes aligned */\n"
literal|"	/* required by ABI to pass     */\n"
literal|"	/* 64-bits arguments           */\n"
literal|"	/* and	sp, ~8        */\n"
literal|"	/* subu	sp, sp, 20    */\n"
literal|"	/* sw	t0, 16(sp)    */\n"
literal|"				\n"
literal|"	move	$7, $4		/* atexit */\n"
literal|"	move	$8, $5		/* main_obj entry */\n"
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
literal|"	ld	$4, 0($29)	\n"
literal|"	move	$5, $29		\n"
literal|"	addu	$5, 8		\n"
else|#
directive|else
literal|"	lw	$4, 0($29)	\n"
literal|"	move	$5, $29		\n"
literal|"	addu	$5, 4		\n"
endif|#
directive|endif
literal|"				\n"
literal|"	and	$29, 0xfffffff8	\n"
literal|"	subu	$29, $29, 24	/* args slot + cleanup + 4 bytes padding */ \n"
literal|"	sw	$8, 16($29)	\n"
literal|"\n"
literal|"	la	 $25, __start_mips  \n"
literal|"	nop	 \n"
literal|"	j	 $25\n"
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
name|__start_mips
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|struct
name|ps_strings
modifier|*
name|ps_strings
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
parameter_list|)
block|{
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
name|env
operator|=
name|argv
operator|+
name|argc
operator|+
literal|1
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
ifndef|#
directive|ifndef
name|NOGPREL
name|_init
argument_list|()
expr_stmt|;
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

end_unit

