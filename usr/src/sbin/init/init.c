begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 William F. Jolitz, TeleMuse  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This software is a component of "386BSD" developed by  	William F. Jolitz, TeleMuse.  * 4. Neither the name of the developer nor the name "386BSD"  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS A COMPONENT OF 386BSD DEVELOPED BY WILLIAM F. JOLITZ   * AND IS INTENDED FOR RESEARCH AND EDUCATIONAL PURPOSES ONLY. THIS   * SOFTWARE SHOULD NOT BE CONSIDERED TO BE A COMMERCIAL PRODUCT.   * THE DEVELOPER URGES THAT USERS WHO REQUIRE A COMMERCIAL PRODUCT   * NOT MAKE USE THIS WORK.  *  * FOR USERS WHO WISH TO UNDERSTAND THE 386BSD SYSTEM DEVELOPED  * BY WILLIAM F. JOLITZ, WE RECOMMEND THE USER STUDY WRITTEN   * REFERENCES SUCH AS THE  "PORTING UNIX TO THE 386" SERIES   * (BEGINNING JANUARY 1991 "DR. DOBBS JOURNAL", USA AND BEGINNING   * JUNE 1991 "UNIX MAGAZIN", GERMANY) BY WILLIAM F. JOLITZ AND   * LYNNE GREER JOLITZ, AS WELL AS OTHER BOOKS ON UNIX AND THE   * ON-LINE 386BSD USER MANUAL BEFORE USE. A BOOK DISCUSSING THE INTERNALS   * OF 386BSD ENTITLED "386BSD FROM THE INSIDE OUT" WILL BE AVAILABLE LATE 1992.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPER BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|char
modifier|*
name|shargv
index|[]
init|=
block|{
comment|/*"sh"*/
literal|"-"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|shenv
index|[]
init|=
block|{
literal|"HOME=/"
block|,
literal|"TERM=pc3"
block|,
literal|"USER=root"
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|initarg
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpid
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|int
name|n
decl_stmt|;
name|int
name|off
init|=
literal|0
decl_stmt|;
extern|extern child(
block|)
function|;
end_function

begin_comment
comment|/* did some idiot try to run us? */
end_comment

begin_if
if|if
condition|(
name|getpid
argument_list|()
operator|!=
literal|1
condition|)
block|{
name|write
argument_list|(
literal|2
argument_list|,
literal|"System daemon, runnable only by system\n"
argument_list|,
literal|39
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0xff
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* look for system's argument */
end_comment

begin_if
if|if
condition|(
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
condition|)
block|{
name|strcpy
argument_list|(
name|initarg
argument_list|,
literal|"INITARG="
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|initarg
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|shenv
index|[
literal|3
index|]
operator|=
name|initarg
expr_stmt|;
block|}
end_if

begin_comment
comment|/* restart here if shell dies */
end_comment

begin_expr_stmt
name|setjmp
argument_list|(
name|buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* allocate a session for init */
end_comment

begin_expr_stmt
operator|(
name|void
operator|)
name|setsid
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* protect against signals, listen for children */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGTTIN
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGTTOU
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|child
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* close any open files */
end_comment

begin_for
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
literal|20
condition|;
name|n
operator|++
control|)
name|close
argument_list|(
name|n
argument_list|)
expr_stmt|;
end_for

begin_comment
comment|/* make a process */
end_comment

begin_if
if|if
condition|(
operator|(
name|cpid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* signals, to default state */
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* clean off console */
name|revoke
argument_list|(
literal|"/dev/console"
argument_list|)
expr_stmt|;
comment|/* do open and configuration of console */
name|login_tty
argument_list|(
name|open
argument_list|(
literal|"/dev/console"
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
comment|/* all ready to execute the shell */
name|execve
argument_list|(
literal|"/bin/sh"
argument_list|,
name|shargv
argument_list|,
name|shenv
argument_list|)
expr_stmt|;
comment|/* oops */
name|write
argument_list|(
literal|"execve failed: /bin/sh\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0xff
argument_list|)
expr_stmt|;
block|}
end_if

begin_for
for|for
control|(
init|;
condition|;
control|)
name|pause
argument_list|()
expr_stmt|;
end_for

begin_include
unit|}
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_expr_stmt
unit|child
operator|(
operator|)
block|{
name|int
name|status
block|;
if|if
condition|(
name|cpid
operator|==
name|waitpid
argument_list|(
operator|-
literal|1
argument_list|,
operator|&
name|status
argument_list|,
name|WNOHANG
argument_list|)
condition|)
name|longjmp
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|child
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

