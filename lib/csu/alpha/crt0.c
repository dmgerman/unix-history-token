begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: crt0.c,v 1.11 1997/10/20 20:41:09 thorpej Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ECOFF_COMPAT
end_ifdef

begin_undef
undef|#
directive|undef
name|DYNAMIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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
file|<vm/vm.h>
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
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|"rtld.h"
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
name|Obj_Entry
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Lots of the chunks of this file cobbled together from pieces of  * other NetBSD crt files, including the common code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__syscall
name|__P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_strrchr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|struct
name|ps_strings
modifier|*
name|__ps_strings
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_COMPAT
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|__init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__fini
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECOFF_COMPAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
name|void
name|rtld_setup
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|,
specifier|const
name|Obj_Entry
operator|*
name|obj
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|Obj_Entry
modifier|*
name|__mainprog_obj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Arrange for _DYNAMIC to be weak and undefined (and therefore to show up  * as being at address zero, unless something else defines it).  That way,  * if we happen to be compiling without -static but with without any  * shared libs present, things will still work.  */
end_comment

begin_asm
asm|asm(".weak _DYNAMIC");
end_asm

begin_decl_stmt
specifier|extern
name|int
name|_DYNAMIC
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MCRT0
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|monstartup
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_mcleanup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_etext
decl_stmt|,
name|_eprol
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCRT0 */
end_comment

begin_decl_stmt
name|void
name|__start
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|void
argument_list|(
argument|*cleanup
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|,
specifier|const
name|Obj_Entry
operator|*
operator|,
expr|struct
name|ps_strings
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
decl|main
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__start
parameter_list|(
name|sp
parameter_list|,
name|cleanup
parameter_list|,
name|obj
parameter_list|,
name|ps_strings
parameter_list|)
name|char
modifier|*
modifier|*
name|sp
decl_stmt|;
function_decl|void
parameter_list|(
function_decl|*cleanup
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* from shared loader */
end_comment

begin_decl_stmt
specifier|const
name|Obj_Entry
modifier|*
name|obj
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from shared loader */
end_comment

begin_decl_stmt
name|struct
name|ps_strings
modifier|*
name|ps_strings
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|,
modifier|*
name|namep
decl_stmt|;
name|argc
operator|=
operator|*
operator|(
name|long
operator|*
operator|)
name|sp
expr_stmt|;
name|argv
operator|=
name|sp
operator|+
literal|1
expr_stmt|;
name|environ
operator|=
name|sp
operator|+
literal|2
operator|+
name|argc
expr_stmt|;
comment|/* 2: argc + NULL ending argv */
if|if
condition|(
operator|(
name|namep
operator|=
name|argv
index|[
literal|0
index|]
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* NULL ptr if argc = 0 */
if|if
condition|(
operator|(
name|__progname
operator|=
name|_strrchr
argument_list|(
name|namep
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|__progname
operator|=
name|namep
expr_stmt|;
else|else
name|__progname
operator|++
expr_stmt|;
block|}
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
operator|&&
name|ps_strings
operator|!=
operator|(
expr|struct
name|ps_strings
operator|*
operator|)
literal|0xbabefacedeadbeef
condition|)
name|__ps_strings
operator|=
name|ps_strings
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
operator|&
name|_DYNAMIC
operator|!=
name|NULL
condition|)
name|rtld_setup
argument_list|(
name|cleanup
argument_list|,
name|obj
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
operator|(
name|u_long
operator|)
operator|&
name|_eprol
argument_list|,
operator|(
name|u_long
operator|)
operator|&
name|_etext
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ECOFF_COMPAT
name|atexit
argument_list|(
name|__fini
argument_list|)
expr_stmt|;
name|__init
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* ECOFF_COMPAT */
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * NOTE: Leave the RCS ID _after_ __start(), in case it gets placed in .text.  */
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

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: crt0.c,v 1.11 1997/10/20 20:41:09 thorpej Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
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
asm|asm ("  .text");
end_asm

begin_asm
asm|asm ("_eprol:");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_function_decl
name|void
name|rtld_setup
parameter_list|(
name|cleanup
parameter_list|,
name|obj
parameter_list|)
function_decl|void
parameter_list|(
function_decl|*cleanup
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|Obj_Entry
modifier|*
name|obj
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

begin_function
name|void
modifier|*
name|dlopen
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|)
specifier|const
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
name|__mainprog_obj
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|__mainprog_obj
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
name|__mainprog_obj
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
return|return
call|(
name|__mainprog_obj
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
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|__mainprog_obj
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|__mainprog_obj
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not supported for ELF shlibs, apparently */
end_comment

begin_endif
unit|int dlctl(fd, cmd, arg) 	void *fd, *arg; 	int cmd; {  	if (__mainprog_obj == NULL) 		return -1; 	return (__mainprog_obj->dlctl)(fd, cmd, arg); }
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|dlerror
parameter_list|()
block|{
if|if
condition|(
name|__mainprog_obj
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|__mainprog_obj
operator|->
name|dlerror
call|)
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

end_unit

