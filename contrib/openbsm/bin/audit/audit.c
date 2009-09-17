begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Apple Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $P4: //depot/projects/trustedbsd/openbsm/bin/audit/audit.c#13 $  */
end_comment

begin_comment
comment|/*  * Program to trigger the audit daemon with a message that is either:  *    - Open a new audit log file  *    - Read the audit control file and take action on it  *    - Close the audit log file and exit  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<config/config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FULL_QUEUE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_FULL_QUEUE_H */
end_comment

begin_include
include|#
directive|include
file|<compat/queue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_FULL_QUEUE_H */
end_comment

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<bsm/libbsm.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
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
file|<unistd.h>
end_include

begin_function_decl
specifier|static
name|int
name|send_trigger
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MACH_IPC
end_ifdef

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_include
include|#
directive|include
file|<servers/netname.h>
end_include

begin_include
include|#
directive|include
file|<mach/message.h>
end_include

begin_include
include|#
directive|include
file|<mach/port.h>
end_include

begin_include
include|#
directive|include
file|<mach/mach_error.h>
end_include

begin_include
include|#
directive|include
file|<mach/host_special_ports.h>
end_include

begin_include
include|#
directive|include
file|<servers/bootstrap.h>
end_include

begin_include
include|#
directive|include
file|"auditd_control.h"
end_include

begin_comment
comment|/*   * XXX the following is temporary until this can be added to the kernel  * audit.h header.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUDIT_TRIGGER_INITIALIZE
end_ifndef

begin_define
define|#
directive|define
name|AUDIT_TRIGGER_INITIALIZE
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|send_trigger
parameter_list|(
name|unsigned
name|int
name|trigger
parameter_list|)
block|{
name|mach_port_t
name|serverPort
decl_stmt|;
name|kern_return_t
name|error
decl_stmt|;
name|error
operator|=
name|host_get_audit_control_port
argument_list|(
name|mach_host_self
argument_list|()
argument_list|,
operator|&
name|serverPort
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
name|KERN_SUCCESS
condition|)
block|{
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|errno
operator|=
name|EPERM
expr_stmt|;
name|perror
argument_list|(
literal|"audit requires root privileges"
argument_list|)
expr_stmt|;
block|}
else|else
name|mach_error
argument_list|(
literal|"Cannot get auditd_control Mach port:"
argument_list|,
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|error
operator|=
name|auditd_control
argument_list|(
name|serverPort
argument_list|,
name|trigger
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
name|KERN_SUCCESS
condition|)
block|{
name|mach_error
argument_list|(
literal|"Error sending trigger: "
argument_list|,
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_MACH_IPC */
end_comment

begin_function
specifier|static
name|int
name|send_trigger
parameter_list|(
name|unsigned
name|int
name|trigger
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|auditon
argument_list|(
name|A_SENDTRIGGER
argument_list|,
operator|&
name|trigger
argument_list|,
sizeof|sizeof
argument_list|(
name|trigger
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|error
operator|==
name|EPERM
condition|)
name|perror
argument_list|(
literal|"audit requires root privileges"
argument_list|)
expr_stmt|;
else|else
name|perror
argument_list|(
literal|"Error sending trigger"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_MACH_IPC */
end_comment

begin_function
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: audit -i | -n | -s | -t \n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Main routine to process command line options.  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|ch
decl_stmt|;
name|unsigned
name|int
name|trigger
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"inst"
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
literal|'i'
case|:
name|trigger
operator|=
name|AUDIT_TRIGGER_INITIALIZE
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|trigger
operator|=
name|AUDIT_TRIGGER_ROTATE_USER
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|trigger
operator|=
name|AUDIT_TRIGGER_READ_FILE
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
name|trigger
operator|=
name|AUDIT_TRIGGER_CLOSE_AND_DIE
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|send_trigger
argument_list|(
name|trigger
argument_list|)
operator|<
literal|0
condition|)
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Trigger sent.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

