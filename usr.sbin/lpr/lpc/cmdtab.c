begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/* static char sccsid[] = "@(#)cmdtab.c	8.1 (Berkeley) 6/6/93"; */
end_comment

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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|"lpc.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * lpc -- command tables  */
end_comment

begin_decl_stmt
name|char
name|aborthelp
index|[]
init|=
literal|"terminate a spooling daemon immediately and disable printing"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cleanhelp
index|[]
init|=
literal|"remove cruft files from a queue"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|enablehelp
index|[]
init|=
literal|"turn a spooling queue on"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|disablehelp
index|[]
init|=
literal|"turn a spooling queue off"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|downhelp
index|[]
init|=
literal|"do a 'stop' followed by 'disable' and put a message in status"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|helphelp
index|[]
init|=
literal|"get help on commands"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|quithelp
index|[]
init|=
literal|"exit lpc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|restarthelp
index|[]
init|=
literal|"kill (if possible) and restart a spooling daemon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|starthelp
index|[]
init|=
literal|"enable printing and start a spooling daemon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|statushelp
index|[]
init|=
literal|"show status of daemon and queue"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|stophelp
index|[]
init|=
literal|"stop a spooling daemon after current job completes and disable printing"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tcleanhelp
index|[]
init|=
literal|"test to see what files a clean cmd would remove"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|topqhelp
index|[]
init|=
literal|"put job at top of printer queue"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|uphelp
index|[]
init|=
literal|"enable everything and restart spooling daemon"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PR
value|1
end_define

begin_comment
comment|/* a privileged command */
end_comment

begin_decl_stmt
name|struct
name|cmd
name|cmdtab
index|[]
init|=
block|{
block|{
literal|"abort"
block|,
name|aborthelp
block|,
name|PR
block|,
literal|0
block|,
name|doabort
block|}
block|,
block|{
literal|"clean"
block|,
name|cleanhelp
block|,
name|PR
block|,
name|init_clean
block|,
name|clean_q
block|}
block|,
block|{
literal|"enable"
block|,
name|enablehelp
block|,
name|PR
block|,
literal|0
block|,
name|enable
block|}
block|,
block|{
literal|"exit"
block|,
name|quithelp
block|,
literal|0
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"disable"
block|,
name|disablehelp
block|,
name|PR
block|,
literal|0
block|,
name|disable
block|}
block|,
block|{
literal|"down"
block|,
name|downhelp
block|,
name|PR
block|,
name|down
block|,
literal|0
block|}
block|,
block|{
literal|"help"
block|,
name|helphelp
block|,
literal|0
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|"quit"
block|,
name|quithelp
block|,
literal|0
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"restart"
block|,
name|restarthelp
block|,
literal|0
block|,
literal|0
block|,
name|restart
block|}
block|,
block|{
literal|"start"
block|,
name|starthelp
block|,
name|PR
block|,
literal|0
block|,
name|startcmd
block|}
block|,
block|{
literal|"status"
block|,
name|statushelp
block|,
literal|0
block|,
literal|0
block|,
name|status
block|}
block|,
block|{
literal|"stop"
block|,
name|stophelp
block|,
name|PR
block|,
literal|0
block|,
name|stop
block|}
block|,
block|{
literal|"tclean"
block|,
name|tcleanhelp
block|,
literal|0
block|,
name|init_tclean
block|,
name|clean_q
block|}
block|,
block|{
literal|"topq"
block|,
name|topqhelp
block|,
name|PR
block|,
name|topq
block|,
literal|0
block|}
block|,
block|{
literal|"up"
block|,
name|uphelp
block|,
name|PR
block|,
literal|0
block|,
name|up
block|}
block|,
block|{
literal|"?"
block|,
name|helphelp
block|,
literal|0
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NCMDS
init|=
sizeof|sizeof
argument_list|(
name|cmdtab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cmdtab
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

