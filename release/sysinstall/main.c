begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated for what's essentially a complete rewrite.  *  * $Id: main.c,v 1.12.2.2 1995/06/02 15:31:25 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
name|choice
decl_stmt|,
name|scroll
decl_stmt|,
name|curr
decl_stmt|,
name|max
decl_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning:  This utility should be run as root.\n"
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Set up whatever things need setting up */
name|systemInitialize
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Try to preserve our scroll-back buffer */
if|if
condition|(
name|OnVTY
condition|)
for|for
control|(
name|curr
operator|=
literal|0
init|;
name|curr
operator|<
literal|25
condition|;
name|curr
operator|++
control|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
comment|/* Probe for all relevant devices on the system */
name|deviceGetAll
argument_list|()
expr_stmt|;
comment|/* Default to English */
name|lang_set_English
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
comment|/* Default to passive mode ftp since it's the only thing we currently support :-( */
name|OptFlags
operator||=
name|OPT_FTP_PASSIVE
expr_stmt|;
comment|/* Begin user dialog at outer menu */
while|while
condition|(
literal|1
condition|)
block|{
name|choice
operator|=
name|scroll
operator|=
name|curr
operator|=
name|max
operator|=
literal|0
expr_stmt|;
name|dmenuOpen
argument_list|(
operator|&
name|MenuInitial
argument_list|,
operator|&
name|choice
argument_list|,
operator|&
name|scroll
argument_list|,
operator|&
name|curr
argument_list|,
operator|&
name|max
argument_list|)
expr_stmt|;
if|if
condition|(
name|getpid
argument_list|()
operator|!=
literal|1
operator|||
operator|!
name|msgYesNo
argument_list|(
literal|"Are you sure you wish to exit?  System will reboot."
argument_list|)
condition|)
break|break;
block|}
comment|/* Write out any changes to /etc/sysconfig */
name|configSysconfig
argument_list|()
expr_stmt|;
comment|/* Say goodnight, Gracie */
name|systemShutdown
argument_list|()
expr_stmt|;
comment|/* If we're running as init, we should never get here */
return|return
literal|0
return|;
block|}
end_function

end_unit

