begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: crt0.c,v 1.6 1993/11/09 04:26:11 paul Exp $  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"%W% (Erasmus) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_callmain
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|N_GETMAGIC
end_ifndef

begin_define
define|#
directive|define
name|N_GETMAGIC
parameter_list|(
name|x
parameter_list|)
value|((x).a_magic)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_BSSADDR
end_ifndef

begin_define
define|#
directive|define
name|N_BSSADDR
parameter_list|(
name|x
parameter_list|)
value|(N_DATADDR(x)+(x).a_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

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
file|<link.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|link_dynamic
name|_DYNAMIC
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|__do_dynamic_link
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|_getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|_strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_expr_stmt
specifier|static
name|__call
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|LDSO
value|"/usr/lib/ld.so"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|LDSO
value|"/usr/libexec/ld.so"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_function_decl
specifier|static
name|char
modifier|*
name|_strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|eprol
name|asm
argument_list|(
literal|"eprol"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern			start(
end_extern

begin_asm
unit|)
asm|asm("start");
end_asm

begin_extern
extern|extern			mcount(
end_extern

begin_asm
unit|)
asm|asm ("mcount");
end_asm

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|empty
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__progname
init|=
name|empty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We need these system calls, but can't use library stubs  */
end_comment

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
name|open
parameter_list|(
name|name
parameter_list|,
name|f
parameter_list|,
name|m
parameter_list|)
value|__syscall(SYS_open, (name), (f), (m))
end_define

begin_define
define|#
directive|define
name|close
parameter_list|(
name|fd
parameter_list|)
value|__syscall(SYS_close, (fd))
end_define

begin_define
define|#
directive|define
name|read
parameter_list|(
name|fd
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|__syscall(SYS_read, (fd), (s), (n))
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
name|dup
parameter_list|(
name|fd
parameter_list|)
value|__syscall(SYS_dup, (fd))
end_define

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|fd
parameter_list|,
name|fdnew
parameter_list|)
value|__syscall(SYS_dup2, (fd), (fdnew))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|mmap
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|prot
parameter_list|,
name|flags
parameter_list|,
name|fd
parameter_list|,
name|off
parameter_list|)
define|\
value|__syscall(SYS_mmap, (addr), (len), (prot), _MAP_NEW|(flags), (fd), (off))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mmap
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|prot
parameter_list|,
name|flags
parameter_list|,
name|fd
parameter_list|,
name|off
parameter_list|)
define|\
value|__syscall(SYS_mmap, (addr), (len), (prot), (flags), (fd), (off))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FATAL
parameter_list|(
name|str
parameter_list|)
define|\
value|write(2, str, sizeof(str)), \ 	_exit(1);
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_asm
asm|asm ("	.global start");
end_asm

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("	start:");
end_asm

begin_comment
comment|/* Set up `argc', `argv', and `envp' into local registers (from GNU Emacs). */
end_comment

begin_asm
asm|asm ("	mov	0, %fp");
end_asm

begin_asm
asm|asm ("	ld	[%sp + 64], %l0");
end_asm

begin_comment
comment|/* argc */
end_comment

begin_asm
asm|asm ("	add	%sp, 68, %l1");
end_asm

begin_comment
comment|/* argv */
end_comment

begin_asm
asm|asm ("	sll	%l0, 2,	%l2");
end_asm

begin_comment
comment|/**/
end_comment

begin_asm
asm|asm ("	add	%l2, 4,	%l2");
end_asm

begin_comment
comment|/* envp = argv + (argc<< 2) + 4 */
end_comment

begin_asm
asm|asm ("	add	%l1, %l2, %l2");
end_asm

begin_comment
comment|/**/
end_comment

begin_asm
asm|asm ("	sethi	%hi(_environ), %l3");
end_asm

begin_asm
asm|asm ("	st	%l2, [%l3+%lo(_environ)]");
end_asm

begin_comment
comment|/* *environ = l2 */
end_comment

begin_comment
comment|/* Finish diddling with stack. */
end_comment

begin_asm
asm|asm ("	andn	%sp, 7,	%sp");
end_asm

begin_asm
asm|asm ("	sub	%sp, 24, %sp");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_comment
comment|/* Resolve symbols in dynamic libraries */
end_comment

begin_asm
asm|asm ("	call	___do_dynamic_link");
end_asm

begin_asm
asm|asm ("	nop");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* From here, all symbols should have been resolved, so we can use libc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MCRT0
end_ifdef

begin_asm
asm|asm ("	call	___do_mcrt");
end_asm

begin_asm
asm|asm ("	nop");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stay Sun compatible (currently (SunOS 4.1.2) does nothing on sun4) */
end_comment

begin_asm
asm|asm ("	call	start_float");
end_asm

begin_asm
asm|asm ("	nop");
end_asm

begin_comment
comment|/* Move `argc', `argv', and `envp' from locals to parameters for `main'.  */
end_comment

begin_asm
asm|asm ("	mov	%l0,%o0");
end_asm

begin_asm
asm|asm ("	mov	%l1,%o1");
end_asm

begin_asm
asm|asm ("__callmain:");
end_asm

begin_comment
comment|/* Defined for the benefit of debuggers */
end_comment

begin_asm
asm|asm ("	call	_main");
end_asm

begin_asm
asm|asm ("	mov	%l2,%o2");
end_asm

begin_asm
asm|asm ("	call	_exit");
end_asm

begin_asm
asm|asm ("	nop");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|MCRT0
end_ifdef

begin_function
specifier|static
name|void
name|__do_mcrt
parameter_list|()
block|{
specifier|extern
name|unsigned
name|char
name|eprol
decl_stmt|,
name|etext
decl_stmt|;
specifier|extern
name|void
name|_mcleanup
parameter_list|()
function_decl|;
name|on_exit
argument_list|(
name|_mcleanup
argument_list|,
literal|0
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
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_macro
name|start
argument_list|()
end_macro

begin_block
block|{
struct|struct
name|kframe
block|{
name|int
name|kargc
decl_stmt|;
name|char
modifier|*
name|kargv
index|[
literal|1
index|]
decl_stmt|;
comment|/* size depends on kargc */
name|char
name|kargstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
name|char
name|kenvstr
index|[
literal|1
index|]
decl_stmt|;
comment|/* size varies */
block|}
struct|;
comment|/* 	 *	ALL REGISTER VARIABLES!!! 	 */
specifier|register
name|struct
name|kframe
modifier|*
name|kfp
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|targv
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|extern
name|void
name|_mcleanup
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|DYNAMIC
specifier|volatile
name|caddr_t
name|x
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|lint
name|kfp
operator|=
literal|0
expr_stmt|;
name|initcode
operator|=
name|initcode
operator|=
literal|0
expr_stmt|;
else|#
directive|else
comment|/* not lint */
comment|/* just above the saved frame pointer */
asm|asm ("lea 4(%%ebp), %0" : "=r" (kfp) );
endif|#
directive|endif
comment|/* not lint */
for|for
control|(
name|argv
operator|=
name|targv
operator|=
operator|&
name|kfp
operator|->
name|kargv
index|[
literal|0
index|]
init|;
operator|*
name|targv
operator|++
condition|;
comment|/* void */
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|targv
operator|>=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
operator|*
name|argv
operator|)
condition|)
operator|--
name|targv
expr_stmt|;
name|environ
operator|=
name|targv
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNAMIC
comment|/* ld(1) convention: if DYNAMIC = 0 then statically linked */
ifdef|#
directive|ifdef
name|stupid_gcc
if|if
condition|(
operator|&
name|_DYNAMIC
condition|)
name|__do_dynamic_link
argument_list|()
expr_stmt|;
else|#
directive|else
name|x
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|_DYNAMIC
expr_stmt|;
if|if
condition|(
name|x
condition|)
name|__do_dynamic_link
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* DYNAMIC */
asm|asm("eprol:");
ifdef|#
directive|ifdef
name|MCRT0
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
endif|MCRT0
if|#
directive|if
literal|0
block|errno = 0;
endif|#
directive|endif
if|if
condition|(
name|argv
index|[
literal|0
index|]
condition|)
if|if
condition|(
operator|(
name|__progname
operator|=
name|_strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|__progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
else|else
operator|++
name|__progname
expr_stmt|;
asm|asm ("__callmain:");
comment|/* Defined for the benefit of debuggers */
name|exit
argument_list|(
name|main
argument_list|(
name|kfp
operator|->
name|kargc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_function
specifier|static
name|void
name|__do_dynamic_link
parameter_list|()
block|{
name|struct
name|crt_ldso
name|crt
decl_stmt|;
name|struct
name|exec
name|hdr
decl_stmt|;
name|char
modifier|*
name|ldso
decl_stmt|;
name|int
name|dupzfd
decl_stmt|;
name|void
function_decl|(
modifier|*
name|entry
function_decl|)
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|DEBUG
comment|/* Provision for alternate ld.so - security risk! */
if|if
condition|(
operator|!
operator|(
name|ldso
operator|=
name|_getenv
argument_list|(
literal|"LDSO"
argument_list|)
operator|)
condition|)
endif|#
directive|endif
name|ldso
operator|=
name|LDSO
expr_stmt|;
name|crt
operator|.
name|crt_ldfd
operator|=
name|open
argument_list|(
name|ldso
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|crt
operator|.
name|crt_ldfd
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"No ld.so\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Read LDSO exec header */
if|if
condition|(
name|read
argument_list|(
name|crt
operator|.
name|crt_ldfd
argument_list|,
operator|&
name|hdr
argument_list|,
sizeof|sizeof
name|hdr
argument_list|)
operator|<
sizeof|sizeof
name|hdr
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Failure reading ld.so\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|N_GETMAGIC_NET
argument_list|(
name|hdr
argument_list|)
operator|!=
name|ZMAGIC
operator|)
operator|&&
operator|(
name|N_GETMAGIC
argument_list|(
name|hdr
argument_list|)
operator|!=
name|QMAGIC
operator|)
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Bad magic: ld.so\n"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|sun
comment|/* Get bucket of zeroes */
name|crt
operator|.
name|crt_dzfd
operator|=
name|open
argument_list|(
literal|"/dev/zero"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|crt
operator|.
name|crt_dzfd
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"No /dev/zero\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BSD
comment|/* We use MAP_ANON */
name|crt
operator|.
name|crt_dzfd
operator|=
operator|-
literal|1
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|DUPZFD
argument_list|)
if|if
condition|(
operator|(
name|dupzfd
operator|=
name|dup
argument_list|(
name|crt
operator|.
name|crt_dzfd
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Cannot dup /dev/zero\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Map in ld.so */
name|crt
operator|.
name|crt_ba
operator|=
name|mmap
argument_list|(
literal|0
argument_list|,
name|hdr
operator|.
name|a_text
argument_list|,
name|PROT_READ
operator||
name|PROT_EXEC
argument_list|,
name|MAP_FILE
operator||
name|MAP_COPY
argument_list|,
name|crt
operator|.
name|crt_ldfd
argument_list|,
name|N_TXTOFF
argument_list|(
name|hdr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|crt
operator|.
name|crt_ba
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Cannot map ld.so\n"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|BSD
comment|/* !!!  * This is gross, ld.so is a ZMAGIC a.out, but has `sizeof(hdr)' for  * an entry point and not at PAGSIZ as the N_*ADDR macros assume.  */
undef|#
directive|undef
name|N_DATADDR
undef|#
directive|undef
name|N_BSSADDR
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|x
parameter_list|)
value|((x).a_text)
define|#
directive|define
name|N_BSSADDR
parameter_list|(
name|x
parameter_list|)
value|((x).a_text + (x).a_data)
endif|#
directive|endif
comment|/* Map in data segment of ld.so writable */
if|if
condition|(
name|mmap
argument_list|(
name|crt
operator|.
name|crt_ba
operator|+
name|N_DATADDR
argument_list|(
name|hdr
argument_list|)
argument_list|,
name|hdr
operator|.
name|a_data
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_FIXED
operator||
name|MAP_FILE
operator||
name|MAP_COPY
argument_list|,
name|crt
operator|.
name|crt_ldfd
argument_list|,
name|N_DATOFF
argument_list|(
name|hdr
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Cannot map ld.so\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Map bss segment of ld.so zero */
if|if
condition|(
name|hdr
operator|.
name|a_bss
operator|&&
name|mmap
argument_list|(
name|crt
operator|.
name|crt_ba
operator|+
name|N_BSSADDR
argument_list|(
name|hdr
argument_list|)
argument_list|,
name|hdr
operator|.
name|a_bss
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_FIXED
operator||
name|MAP_ANON
operator||
name|MAP_COPY
argument_list|,
name|crt
operator|.
name|crt_dzfd
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Cannot map ld.so\n"
argument_list|)
expr_stmt|;
block|}
name|crt
operator|.
name|crt_dp
operator|=
operator|&
name|_DYNAMIC
expr_stmt|;
name|crt
operator|.
name|crt_ep
operator|=
name|environ
expr_stmt|;
name|crt
operator|.
name|crt_bp
operator|=
operator|(
name|caddr_t
operator|)
name|_callmain
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|SUN_COMPAT
argument_list|)
comment|/* Call Sun's ld.so entry point: version 1, offset crt */
name|__call
argument_list|(
name|CRT_VERSION_SUN
argument_list|,
operator|&
name|crt
argument_list|,
name|crt
operator|.
name|crt_ba
operator|+
sizeof|sizeof
name|hdr
argument_list|)
expr_stmt|;
else|#
directive|else
name|entry
operator|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
operator|(
name|crt
operator|.
name|crt_ba
operator|+
sizeof|sizeof
name|hdr
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SUN_COMPAT
call|(
modifier|*
name|entry
call|)
argument_list|(
name|CRT_VERSION_SUN
argument_list|,
operator|&
name|crt
argument_list|)
expr_stmt|;
else|#
directive|else
call|(
modifier|*
name|entry
call|)
argument_list|(
name|CRT_VERSION_BSD
argument_list|,
operator|&
name|crt
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
name|defined
argument_list|(
name|DUPZFD
argument_list|)
if|if
condition|(
name|dup2
argument_list|(
name|dupzfd
argument_list|,
name|crt
operator|.
name|crt_dzfd
argument_list|)
operator|<
literal|0
condition|)
block|{
name|_FATAL
argument_list|(
literal|"Cannot dup2 /dev/zero\n"
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|close
argument_list|(
name|dupzfd
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_expr_stmt
specifier|static
name|__call
argument_list|()
block|{
comment|/* 	 * adjust the C generated pointer to the crt struct to the 	 * likings of ld.so, which is an offset relative to its %fp 	 */
if|#
directive|if
literal|0
block|asm("___call:"); 	asm("call	%o2"); 	asm("sub	%o1, %sp, %o1");
comment|/* adjust parameter */
else|#
directive|else
else|Hmmm...
name|asm
argument_list|(
literal|"mov	%i0, %o0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"mov	%i1, %o1"
argument_list|)
block|;
name|asm
argument_list|(
literal|"call	%i2"
argument_list|)
block|;
name|asm
argument_list|(
literal|"sub	%o1, %sp, %o1"
argument_list|)
block|;
comment|/*NOTREACHED, control is transferred directly to our caller */
endif|#
directive|endif
block|}
endif|#
directive|endif
comment|/*  * Support routines  */
specifier|static
name|int
name|_strncmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
specifier|register
name|char
operator|*
name|s1
operator|,
operator|*
name|s2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
do|do
block|{
if|if
condition|(
operator|*
name|s1
operator|!=
operator|*
name|s2
operator|++
condition|)
return|return
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s1
operator|-
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|--
name|s2
operator|)
return|;
if|if
condition|(
operator|*
name|s1
operator|++
operator|==
literal|0
condition|)
break|break;
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
specifier|static
name|char
modifier|*
name|_getenv
parameter_list|(
name|name
parameter_list|)
specifier|register
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
specifier|register
name|int
name|len
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|P
decl_stmt|,
modifier|*
name|C
decl_stmt|;
for|for
control|(
name|C
operator|=
name|name
operator|,
name|len
operator|=
literal|0
init|;
operator|*
name|C
operator|&&
operator|*
name|C
operator|!=
literal|'='
condition|;
operator|++
name|C
operator|,
operator|++
name|len
control|)
empty_stmt|;
for|for
control|(
name|P
operator|=
name|environ
init|;
operator|*
name|P
condition|;
operator|++
name|P
control|)
if|if
condition|(
operator|!
name|_strncmp
argument_list|(
operator|*
name|P
argument_list|,
name|name
argument_list|,
name|len
argument_list|)
condition|)
if|if
condition|(
operator|*
operator|(
name|C
operator|=
operator|*
name|P
operator|+
name|len
operator|)
operator|==
literal|'='
condition|)
block|{
return|return
operator|(
operator|++
name|C
operator|)
return|;
block|}
return|return
operator|(
name|char
operator|*
operator|)
literal|0
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_comment
comment|/* System call entry */
end_comment

begin_asm
asm|asm("___syscall:");
end_asm

begin_asm
asm|asm("clr	%g1");
end_asm

begin_asm
asm|asm("ta		%g0");
end_asm

begin_asm
asm|asm("bgeu	Lsyscallx");
end_asm

begin_comment
comment|/* good result ? */
end_comment

begin_asm
asm|asm("nop");
end_asm

begin_asm
asm|asm("mov	-0x1, %o0");
end_asm

begin_comment
comment|/* Note: no `errno' */
end_comment

begin_asm
asm|asm("Lsyscallx:");
end_asm

begin_asm
asm|asm("jmp	%o7 + 0x8");
end_asm

begin_asm
asm|asm("nop");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_asm
asm|asm("	___syscall:");
end_asm

begin_asm
asm|asm("		popl %ecx");
end_asm

begin_asm
asm|asm("		popl %eax");
end_asm

begin_asm
asm|asm("		pushl %ecx");
end_asm

begin_asm
asm|asm("		.byte 0x9a");
end_asm

begin_asm
asm|asm("		.long 0");
end_asm

begin_asm
asm|asm("		.word 7");
end_asm

begin_asm
asm|asm("		pushl %ecx");
end_asm

begin_asm
asm|asm("		jc 1f");
end_asm

begin_asm
asm|asm("		ret");
end_asm

begin_asm
asm|asm("	1:");
end_asm

begin_asm
asm|asm("		movl	$-1,%eax");
end_asm

begin_asm
asm|asm("		ret");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|_strrchr
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
name|ch
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|save
decl_stmt|;
for|for
control|(
name|save
operator|=
name|NULL
init|;
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|ch
condition|)
name|save
operator|=
operator|(
name|char
operator|*
operator|)
name|p
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|p
condition|)
return|return
operator|(
name|save
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MCRT0
end_ifdef

begin_asm
asm|asm ("	.text");
end_asm

begin_asm
asm|asm ("_eprol:");
end_asm

begin_endif
endif|#
directive|endif
end_endif

end_unit

