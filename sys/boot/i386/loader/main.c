begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: main.c,v 1.4 1998/09/14 18:27:06 msmith Exp $  */
end_comment

begin_comment
comment|/*  * MD bootstrap main() and assorted miscellaneous  * commands.  */
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
file|"bootstrap.h"
end_include

begin_include
include|#
directive|include
file|"libi386/libi386.h"
end_include

begin_include
include|#
directive|include
file|"btxv86.h"
end_include

begin_decl_stmt
name|struct
name|arch_switch
name|archsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MI/MD interface boundary */
end_comment

begin_comment
comment|/* from vers.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|bootprog_name
index|[]
decl_stmt|,
name|bootprog_rev
index|[]
decl_stmt|,
name|bootprog_date
index|[]
decl_stmt|,
name|bootprog_maker
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX debugging */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|i386_devdesc
name|currdev
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/*       * Initialise the heap as early as possible.  Once this is done, malloc() is usable.      *      * XXX better to locate end of memory and use that      */
name|setheap
argument_list|(
operator|(
name|void
operator|*
operator|)
name|end
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|end
operator|+
operator|(
literal|384
operator|*
literal|1024
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|/*       * XXX Chicken-and-egg problem; we want to have console output early, but some      * console attributes may depend on reading from eg. the boot device, which we      * can't do yet.      *      * We can use printf() etc. once this is done.      */
name|cons_probe
argument_list|()
expr_stmt|;
comment|/*      * March through the device switch probing for things.      */
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
name|printf
argument_list|(
literal|"memory: %d/%dkB\n"
argument_list|,
name|getbasemem
argument_list|()
argument_list|,
name|getextmem
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf("diskbuf at %p, %d sectors\n",&diskbuf, diskbuf_size);     printf("using %d bytes of stack at %p\n",  (&stacktop -&stackbase),&stacktop);
endif|#
directive|endif
comment|/* We're booting from a BIOS disk, try to spiff this */
name|currdev
operator|.
name|d_dev
operator|=
name|devsw
index|[
literal|0
index|]
expr_stmt|;
comment|/* XXX presumes that biosdisk is first in devsw */
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
name|biosdisk
operator|.
name|unit
operator|=
literal|0
expr_stmt|;
comment|/* XXX wrong, need to get from bootinfo etc. */
name|currdev
operator|.
name|d_kind
operator|.
name|biosdisk
operator|.
name|slice
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* XXX should be able to detect this, default to autoprobe */
name|currdev
operator|.
name|d_kind
operator|.
name|biosdisk
operator|.
name|partition
operator|=
literal|0
expr_stmt|;
comment|/* default to 'a' */
comment|/* Create i386-specific variables */
name|env_setenv
argument_list|(
literal|"currdev"
argument_list|,
name|EV_VOLATILE
argument_list|,
name|i386_fmtdev
argument_list|(
operator|&
name|currdev
argument_list|)
argument_list|,
name|i386_setcurrdev
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
name|i386_fmtdev
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
name|i386_autoload
expr_stmt|;
name|archsw
operator|.
name|arch_getdev
operator|=
name|i386_getdev
expr_stmt|;
name|archsw
operator|.
name|arch_copyin
operator|=
name|i386_copyin
expr_stmt|;
name|archsw
operator|.
name|arch_copyout
operator|=
name|i386_copyout
expr_stmt|;
name|archsw
operator|.
name|arch_readin
operator|=
name|i386_readin
expr_stmt|;
comment|/*      * XXX should these be in the MI source?      */
if|#
directive|if
literal|0
block|legacy_config();
comment|/* read old /boot.config file */
endif|#
directive|endif
name|interact
argument_list|()
expr_stmt|;
comment|/* doesn't return */
block|}
end_function

begin_expr_stmt
name|COMMAND_SET
argument_list|(
name|reboot
argument_list|,
literal|"reboot"
argument_list|,
literal|"reboot the system"
argument_list|,
name|command_reboot
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|command_reboot
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
name|printf
argument_list|(
literal|"Rebooting...\n"
argument_list|)
expr_stmt|;
name|delay
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
name|__exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* provide this for panic */
end_comment

begin_function
name|void
name|exit
parameter_list|(
name|int
name|code
parameter_list|)
block|{
name|__exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX learn to ask BTX */
end_comment

begin_endif
unit|COMMAND_SET(stack, "stack", "show stack usage", command_stack);  extern char stackbase, stacktop;  static int command_stack(int argc, char *argv[]) {     char	*cp;      for (cp =&stackbase; cp<&stacktop; cp++) 	if (*cp != 0) 	    break;          printf("%d bytes of stack used\n",&stacktop - cp);     return(CMD_OK); }
endif|#
directive|endif
end_endif

begin_expr_stmt
name|COMMAND_SET
argument_list|(
name|heap
argument_list|,
literal|"heap"
argument_list|,
literal|"show heap usage"
argument_list|,
name|command_heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|command_heap
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
name|printf
argument_list|(
literal|"heap base at %p, top at %p, used %d\n"
argument_list|,
name|end
argument_list|,
name|sbrk
argument_list|(
literal|0
argument_list|)
argument_list|,
name|sbrk
argument_list|(
literal|0
argument_list|)
operator|-
name|end
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

