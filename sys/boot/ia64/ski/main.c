begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * Copyright (c) 1998,2000 Doug Rabson<dfr@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_include
include|#
directive|include
file|"libski.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|bootprog_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bootprog_rev
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bootprog_date
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bootprog_maker
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ski_devdesc
name|currdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our current device */
end_comment

begin_decl_stmt
name|struct
name|arch_switch
name|archsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MI/MD interface boundary */
end_comment

begin_function
name|void
name|__start
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|char
name|stack
index|[
literal|16384
index|]
name|__aligned
argument_list|(
literal|16
argument_list|)
decl_stmt|;
specifier|static
name|char
name|malloc
index|[
literal|512
operator|*
literal|1024
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
asm|__asm __volatile("movl gp=__gp;;");
asm|__asm __volatile("mov sp=%0" :: "r"(&stack[16384]));
asm|__asm __volatile("bsw.1;;");
asm|__asm __volatile("mov ar.fpsr=%0" :: "r"(IA64_FPSR_DEFAULT));
comment|/*  	 * initialise the heap as early as possible.  Once this is done, 	 * alloc() is usable. The stack is buried inside us, so this is 	 * safe. 	 */
name|setheap
argument_list|(
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|malloc
operator|+
literal|512
operator|*
literal|1024
operator|)
argument_list|)
expr_stmt|;
comment|/*  	 * XXX Chicken-and-egg problem; we want to have console output 	 * early, but some console attributes may depend on reading from 	 * eg. the boot device, which we can't do yet.  We can use 	 * printf() etc. once this is done. 	 */
name|cons_probe
argument_list|()
expr_stmt|;
comment|/* 	 * Initialise the block cache 	 */
name|bcache_init
argument_list|(
literal|32
argument_list|,
literal|512
argument_list|)
expr_stmt|;
comment|/* 16k XXX tune this */
comment|/* 	 * March through the device switch probing for things. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|devsw
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|devsw
index|[
name|i
index|]
operator|->
name|dv_init
operator|!=
name|NULL
condition|)
operator|(
name|devsw
index|[
name|i
index|]
operator|->
name|dv_init
operator|)
operator|(
operator|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s, Revision %s\n"
argument_list|,
name|bootprog_name
argument_list|,
name|bootprog_rev
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"(%s, %s)\n"
argument_list|,
name|bootprog_maker
argument_list|,
name|bootprog_date
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf("Memory: %ld k\n", memsize() / 1024);
endif|#
directive|endif
comment|/* XXX presumes that biosdisk is first in devsw */
name|currdev
operator|.
name|d_dev
operator|=
name|devsw
index|[
literal|0
index|]
expr_stmt|;
name|currdev
operator|.
name|d_type
operator|=
name|currdev
operator|.
name|d_dev
operator|->
name|dv_type
expr_stmt|;
name|currdev
operator|.
name|d_kind
operator|.
name|skidisk
operator|.
name|unit
operator|=
literal|0
expr_stmt|;
comment|/* XXX should be able to detect this, default to autoprobe */
name|currdev
operator|.
name|d_kind
operator|.
name|skidisk
operator|.
name|slice
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* default to 'a' */
name|currdev
operator|.
name|d_kind
operator|.
name|skidisk
operator|.
name|partition
operator|=
literal|0
expr_stmt|;
if|#
directive|if
literal|0
comment|/* Create arc-specific variables */
block|bootfile = GetEnvironmentVariable(ARCENV_BOOTFILE); 	if (bootfile) 		setenv("bootfile", bootfile, 1);
endif|#
directive|endif
name|env_setenv
argument_list|(
literal|"currdev"
argument_list|,
name|EV_VOLATILE
argument_list|,
name|ski_fmtdev
argument_list|(
operator|&
name|currdev
argument_list|)
argument_list|,
name|ski_setcurrdev
argument_list|,
name|env_nounset
argument_list|)
expr_stmt|;
name|env_setenv
argument_list|(
literal|"loaddev"
argument_list|,
name|EV_VOLATILE
argument_list|,
name|ski_fmtdev
argument_list|(
operator|&
name|currdev
argument_list|)
argument_list|,
name|env_noset
argument_list|,
name|env_nounset
argument_list|)
expr_stmt|;
name|setenv
argument_list|(
literal|"LINES"
argument_list|,
literal|"24"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* optional */
name|archsw
operator|.
name|arch_autoload
operator|=
name|ski_autoload
expr_stmt|;
name|archsw
operator|.
name|arch_getdev
operator|=
name|ski_getdev
expr_stmt|;
name|archsw
operator|.
name|arch_copyin
operator|=
name|ski_copyin
expr_stmt|;
name|archsw
operator|.
name|arch_copyout
operator|=
name|ski_copyout
expr_stmt|;
name|archsw
operator|.
name|arch_readin
operator|=
name|ski_readin
expr_stmt|;
name|interact
argument_list|()
expr_stmt|;
comment|/* doesn't return */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|COMMAND_SET
argument_list|(
name|quit
argument_list|,
literal|"quit"
argument_list|,
literal|"exit the loader"
argument_list|,
name|command_quit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|command_quit
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|CMD_OK
operator|)
return|;
block|}
end_function

end_unit

