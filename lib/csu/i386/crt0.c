begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: crt0.c,v 1.12 1994/09/18 22:21:04 ache Exp $  */
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

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199306
operator|&&
operator|!
name|defined
argument_list|(
name|MAP_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAP_FILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD>=199306 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|_dynamic
name|_DYNAMIC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ld_entry
modifier|*
name|ld_entry
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
value|__syscall(SYS_exit, (int)(v))
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
value|__syscall(SYS_open, (char *)(name), (int)(f), (int)(m))
end_define

begin_define
define|#
directive|define
name|close
parameter_list|(
name|fd
parameter_list|)
value|__syscall(SYS_close, (int)(fd))
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
value|__syscall(SYS_read, (int)(fd), (void *)(s), (size_t)(n))
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
value|__syscall(SYS_write, (int)(fd), (void *)(s), (size_t)(n))
end_define

begin_define
define|#
directive|define
name|dup
parameter_list|(
name|fd
parameter_list|)
value|__syscall(SYS_dup, (int)(fd))
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
value|__syscall(SYS_dup2, (int)(fd), (int)(fdnew))
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
value|__syscall(SYS_mmap, (caddr_t)(addr), (size_t)(len), (int)(prot), (int)(flags), (int)(fd), (long)0L, (off_t)(off))
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
comment|/* MCRT0 */
if|if
condition|(
name|getenv
argument_list|(
literal|"ENABLE_STARTUP_LOCALE"
argument_list|)
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
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
name|int
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
comment|/* We use MAP_ANON */
name|crt
operator|.
name|crt_dzfd
operator|=
operator|-
literal|1
expr_stmt|;
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
name|crt
operator|.
name|crt_prog
operator|=
name|__progname
expr_stmt|;
name|entry
operator|=
operator|(
name|int
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
if|if
condition|(
call|(
modifier|*
name|entry
call|)
argument_list|(
name|CRT_VERSION_BSD_3
argument_list|,
operator|&
name|crt
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|_FATAL
argument_list|(
literal|"ld.so failed\n"
argument_list|)
expr_stmt|;
block|}
name|ld_entry
operator|=
name|_DYNAMIC
operator|.
name|d_entry
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * DL stubs  */
end_comment

begin_function
name|void
modifier|*
name|dlopen
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|{
if|if
condition|(
name|ld_entry
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|ld_entry
operator|->
name|dlopen
call|)
argument_list|(
name|name
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|dlclose
parameter_list|(
name|fd
parameter_list|)
name|void
modifier|*
name|fd
decl_stmt|;
block|{
if|if
condition|(
name|ld_entry
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
return|return
call|(
name|ld_entry
operator|->
name|dlclose
call|)
argument_list|(
name|fd
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|dlsym
parameter_list|(
name|fd
parameter_list|,
name|name
parameter_list|)
name|void
modifier|*
name|fd
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|ld_entry
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|ld_entry
operator|->
name|dlsym
call|)
argument_list|(
name|fd
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|dlctl
parameter_list|(
name|fd
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
name|void
modifier|*
name|fd
decl_stmt|,
decl|*
name|arg
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|ld_entry
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
return|return
call|(
name|ld_entry
operator|->
name|dlctl
call|)
argument_list|(
name|fd
argument_list|,
name|cmd
argument_list|,
name|arg
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  * Support routines  */
end_comment

begin_decl_stmt
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
decl|register
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

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

