begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jim Gillogly at The Rand Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1991, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setup.c	8.1 (Berkeley) 5/31/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Setup: keep the structure of the original Adventure port, but use an  * internal copy of the data file, serving as a sort of virtual disk.  It's  * lightly encrypted to prevent casual snooping of the executable.  *  * Also do appropriate things to tabs so that bogus editors will do the right  * thing with the data file.  *  */
end_comment

begin_define
define|#
directive|define
name|SIG1
value|" *      Jim Gillogly"
end_define

begin_define
define|#
directive|define
name|SIG2
value|" *      Sterday, 6 Thrimidge S.R. 1993, 15:24"
end_define

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
file|"hdr.h"
end_include

begin_comment
comment|/* SEED lives in there; keep them coordinated. */
end_comment

begin_define
define|#
directive|define
name|USAGE
value|"Usage: setup file> data.c (file is typically glorkz)\n"
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_function_decl
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LINE
value|10
end_define

begin_comment
comment|/* How many values do we get on a line? */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|FILE
modifier|*
name|infile
decl_stmt|;
name|int
name|c
decl_stmt|,
name|count
decl_stmt|,
name|linestart
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|fatal
argument_list|(
name|USAGE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|infile
operator|=
name|fopen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"Can't read file %s.\n"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"/*\n * data.c: created by setup from the ascii data file."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|SIG1
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|SIG2
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" */"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n\nchar data_file[] =\n{"
argument_list|)
expr_stmt|;
name|srandom
argument_list|(
name|SEED
argument_list|)
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
name|linestart
operator|=
name|YES
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|infile
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
if|if
condition|(
name|linestart
operator|&&
name|c
operator|==
literal|' '
condition|)
comment|/* Convert first spaces to tab */
block|{
if|if
condition|(
name|count
operator|++
operator|%
name|LINE
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"0x%02x,"
argument_list|,
operator|(
literal|'\t'
operator|^
name|random
argument_list|()
operator|)
operator|&
literal|0xFF
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|infile
argument_list|)
operator|)
operator|==
literal|' '
operator|&&
name|c
operator|!=
name|EOF
condition|)
empty_stmt|;
comment|/* Drop the non-whitespace character through */
name|linestart
operator|=
name|NO
expr_stmt|;
block|}
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'\t'
case|:
name|linestart
operator|=
name|NO
expr_stmt|;
comment|/* Don't need to convert spaces */
break|break;
case|case
literal|'\n'
case|:
name|linestart
operator|=
name|YES
expr_stmt|;
comment|/* Ready to convert spaces again */
break|break;
block|}
if|if
condition|(
name|count
operator|++
operator|%
name|LINE
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"0x%02x,"
argument_list|,
operator|(
name|c
operator|^
name|random
argument_list|()
operator|)
operator|&
literal|0xFF
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|"\n\t0\n};"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|infile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fatal
parameter_list|(
name|format
parameter_list|,
name|arg
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|format
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

