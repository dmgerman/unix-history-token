begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)dcrept.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

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
file|"trek.h"
end_include

begin_comment
comment|/* **  damage control report ** **	Print damages and time to fix.  This is taken from the event **	list.  A couple of factors are set up, based on whether or not **	we are docked.  (One of these factors will always be 1.0.) **	The event list is then scanned for damage fix events, the **	time until they occur is determined, and printed out.  The **	magic number DAMFAC is used to tell how much faster you can **	fix things if you are docked. */
end_comment

begin_macro
name|dcrept
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|,
name|f
decl_stmt|;
name|double
name|x
decl_stmt|;
name|double
name|m1
decl_stmt|,
name|m2
decl_stmt|;
name|struct
name|event
modifier|*
name|e
decl_stmt|;
comment|/* set up the magic factors to output the time till fixed */
if|if
condition|(
name|Ship
operator|.
name|cond
operator|==
name|DOCKED
condition|)
block|{
name|m1
operator|=
literal|1.0
operator|/
name|Param
operator|.
name|dockfac
expr_stmt|;
name|m2
operator|=
literal|1.0
expr_stmt|;
block|}
else|else
block|{
name|m1
operator|=
literal|1.0
expr_stmt|;
name|m2
operator|=
name|Param
operator|.
name|dockfac
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Damage control report:\n"
argument_list|)
expr_stmt|;
name|f
operator|=
literal|1
expr_stmt|;
comment|/* scan for damages */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXEVENTS
condition|;
name|i
operator|++
control|)
block|{
name|e
operator|=
operator|&
name|Event
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|evcode
operator|!=
name|E_FIXDV
condition|)
continue|continue;
comment|/* output the title first time */
if|if
condition|(
name|f
condition|)
block|{
name|printf
argument_list|(
literal|"\t\t\t  repair times\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"device\t\t\tin flight  docked\n"
argument_list|)
expr_stmt|;
name|f
operator|=
literal|0
expr_stmt|;
block|}
comment|/* compute time till fixed, then adjust by the magic factors */
name|x
operator|=
name|e
operator|->
name|date
operator|-
name|Now
operator|.
name|date
expr_stmt|;
name|printf
argument_list|(
literal|"%-24s%7.2f  %7.2f\n"
argument_list|,
name|Device
index|[
name|e
operator|->
name|systemname
index|]
operator|.
name|name
argument_list|,
name|x
operator|*
name|m1
operator|+
literal|0.005
argument_list|,
name|x
operator|*
name|m2
operator|+
literal|0.005
argument_list|)
expr_stmt|;
comment|/* do a little consistancy checking */
block|}
comment|/* if everything was ok, reassure the nervous captain */
if|if
condition|(
name|f
condition|)
name|printf
argument_list|(
literal|"All devices functional\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

