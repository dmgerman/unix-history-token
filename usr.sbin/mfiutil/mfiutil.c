begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, 2009 Yahoo!, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"mfiutil.h"
end_include

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|MFI_DATASET
argument_list|(
name|top
argument_list|)
argument_list|,
expr|struct
name|mfiutil_command
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MFI_TABLE
argument_list|(
name|top
argument_list|,
name|start
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MFI_TABLE
argument_list|(
name|top
argument_list|,
name|stop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MFI_TABLE
argument_list|(
name|top
argument_list|,
name|abort
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|mfi_unit
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: mfiutil [-u unit]<command> ...\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Commands include:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    version\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show adapter              - display controller information\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show battery              - display battery information\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show config               - display RAID configuration\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show drives               - list physical drives\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show events               - display event log\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show firmware             - list firmware images\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show volumes              - list logical volumes\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    show patrol               - display patrol read status\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    fail<drive>              - fail a physical drive\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    good<drive>              - mark a bad physical drive as good\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    rebuild<drive>           - mark failed drive ready for rebuild\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    drive progress<drive>    - display status of active operations\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    drive clear<drive><start|stop> - clear a drive with all 0x00\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    start rebuild<drive>\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    abort rebuild<drive>\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    locate<drive><on|off>   - toggle drive LED\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    cache<volume> [command [setting]]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    name<volume><name>\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    volume progress<volume>  - display status of active operations\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    clear                     - clear volume configuration\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    create<type> [-v]<drive>[,<drive>[,...]] [<drive>[,<drive>[,...]]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    delete<volume>\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    add<drive> [volume]      - add a hot spare\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    remove<drive>            - remove a hot spare\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    patrol<disable|auto|manual> [interval [start]]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    start patrol              - start a patrol read\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    stop patrol               - stop a patrol read\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    flash<firmware>\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    debug                     - debug 'show config'\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    dump                      - display 'saved' config\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|version
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
block|{
name|printf
argument_list|(
literal|"mfiutil version 1.0.13"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|" (DEBUG)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|MFI_COMMAND
argument_list|(
name|top
argument_list|,
name|version
argument_list|,
name|version
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
block|{
name|struct
name|mfiutil_command
modifier|*
modifier|*
name|cmd
decl_stmt|;
name|int
name|ch
decl_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|ac
argument_list|,
name|av
argument_list|,
literal|"u:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'u'
case|:
name|mfi_unit
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
name|usage
argument_list|()
expr_stmt|;
block|}
block|}
name|av
operator|+=
name|optind
expr_stmt|;
name|ac
operator|-=
name|optind
expr_stmt|;
comment|/* getopt() eats av[0], so we can't use mfi_table_handler() directly. */
if|if
condition|(
name|ac
operator|==
literal|0
condition|)
name|usage
argument_list|()
expr_stmt|;
name|SET_FOREACH
argument_list|(
argument|cmd
argument_list|,
argument|MFI_DATASET(top)
argument_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
operator|(
operator|*
name|cmd
operator|)
operator|->
name|name
argument_list|,
name|av
index|[
literal|0
index|]
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|(
operator|*
name|cmd
operator|)
operator|->
name|handler
argument_list|(
name|ac
argument_list|,
name|av
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
name|warnx
argument_list|(
literal|"Unknown command %s."
argument_list|,
name|av
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

