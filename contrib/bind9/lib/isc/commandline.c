begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: commandline.c,v 1.15.206.1 2004/03/06 08:14:28 marka Exp $ */
end_comment

begin_comment
comment|/*  * This file was adapted from the NetBSD project's source tree, RCS ID:  *    NetBSD: getopt.c,v 1.15 1999/09/20 04:39:37 lukem Exp  *  * The primary change has been to rename items to the ISC namespace  * and format in the ISC coding style.  */
end_comment

begin_comment
comment|/*  * Principal Authors: Computer Systems Research Group at UC Berkeley  * Principal ISC caretaker: DCL  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/commandline.h>
end_include

begin_include
include|#
directive|include
file|<isc/msgs.h>
end_include

begin_include
include|#
directive|include
file|<isc/string.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/* Index into parent argv vector. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|int
name|isc_commandline_index
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character checked for validity. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|int
name|isc_commandline_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument associated with option. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|char
modifier|*
name|isc_commandline_argument
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For printing error messages. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|char
modifier|*
name|isc_commandline_progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print error messages. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|isc_boolean_t
name|isc_commandline_errprint
init|=
name|ISC_TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset processing. */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|isc_boolean_t
name|isc_commandline_reset
init|=
name|ISC_TRUE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|endopt
init|=
literal|'\0'
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BADOPT
value|'?'
end_define

begin_define
define|#
directive|define
name|BADARG
value|':'
end_define

begin_define
define|#
directive|define
name|ENDOPT
value|&endopt
end_define

begin_comment
comment|/*  * getopt --  *	Parse argc/argv argument vector.  */
end_comment

begin_function
name|int
name|isc_commandline_parse
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|options
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|place
init|=
name|ENDOPT
decl_stmt|;
name|char
modifier|*
name|option
decl_stmt|;
comment|/* Index into *options of option. */
name|REQUIRE
argument_list|(
name|argc
operator|>=
literal|0
operator|&&
name|argv
operator|!=
name|NULL
operator|&&
name|options
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* 	 * Update scanning pointer, either because a reset was requested or 	 * the previous argv was finished. 	 */
if|if
condition|(
name|isc_commandline_reset
operator|||
operator|*
name|place
operator|==
literal|'\0'
condition|)
block|{
name|isc_commandline_reset
operator|=
name|ISC_FALSE
expr_stmt|;
if|if
condition|(
name|isc_commandline_progname
operator|==
name|NULL
condition|)
name|isc_commandline_progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|isc_commandline_index
operator|>=
name|argc
operator|||
operator|*
operator|(
name|place
operator|=
name|argv
index|[
name|isc_commandline_index
index|]
operator|)
operator|!=
literal|'-'
condition|)
block|{
comment|/* 			 * Index out of range or points to non-option. 			 */
name|place
operator|=
name|ENDOPT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|place
index|[
literal|1
index|]
operator|!=
literal|'\0'
operator|&&
operator|*
operator|++
name|place
operator|==
literal|'-'
operator|&&
name|place
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
comment|/* 			 * Found '--' to signal end of options.  Advance 			 * index to next argv, the first non-option. 			 */
name|isc_commandline_index
operator|++
expr_stmt|;
name|place
operator|=
name|ENDOPT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
name|isc_commandline_option
operator|=
operator|*
name|place
operator|++
expr_stmt|;
name|option
operator|=
name|strchr
argument_list|(
name|options
argument_list|,
name|isc_commandline_option
argument_list|)
expr_stmt|;
comment|/* 	 * Ensure valid option has been passed as specified by options string. 	 * '-:' is never a valid command line option because it could not 	 * distinguish ':' from the argument specifier in the options string. 	 */
if|if
condition|(
name|isc_commandline_option
operator|==
literal|':'
operator|||
name|option
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|place
operator|==
literal|'\0'
condition|)
name|isc_commandline_index
operator|++
expr_stmt|;
if|if
condition|(
name|isc_commandline_errprint
operator|&&
operator|*
name|options
operator|!=
literal|':'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s -- %c\n"
argument_list|,
name|isc_commandline_progname
argument_list|,
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_MSGSET_COMMANDLINE
argument_list|,
name|ISC_MSG_ILLEGALOPT
argument_list|,
literal|"illegal option"
argument_list|)
argument_list|,
name|isc_commandline_option
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADOPT
operator|)
return|;
block|}
if|if
condition|(
operator|*
operator|++
name|option
operator|!=
literal|':'
condition|)
block|{
comment|/* 		 * Option does not take an argument. 		 */
name|isc_commandline_argument
operator|=
name|NULL
expr_stmt|;
comment|/* 		 * Skip to next argv if at the end of the current argv. 		 */
if|if
condition|(
operator|*
name|place
operator|==
literal|'\0'
condition|)
operator|++
name|isc_commandline_index
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * Option needs an argument. 		 */
if|if
condition|(
operator|*
name|place
operator|!=
literal|'\0'
condition|)
comment|/* 			 * Option is in this argv, -D1 style. 			 */
name|isc_commandline_argument
operator|=
name|place
expr_stmt|;
elseif|else
if|if
condition|(
name|argc
operator|>
operator|++
name|isc_commandline_index
condition|)
comment|/* 			 * Option is next argv, -D 1 style. 			 */
name|isc_commandline_argument
operator|=
name|argv
index|[
name|isc_commandline_index
index|]
expr_stmt|;
else|else
block|{
comment|/* 			 * Argument needed, but no more argv. 			 */
name|place
operator|=
name|ENDOPT
expr_stmt|;
comment|/* 			 * Silent failure with "missing argument" return 			 * when ':' starts options string, per historical spec. 			 */
if|if
condition|(
operator|*
name|options
operator|==
literal|':'
condition|)
return|return
operator|(
name|BADARG
operator|)
return|;
if|if
condition|(
name|isc_commandline_errprint
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s -- %c\n"
argument_list|,
name|isc_commandline_progname
argument_list|,
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_MSGSET_COMMANDLINE
argument_list|,
name|ISC_MSG_OPTNEEDARG
argument_list|,
literal|"option requires "
literal|"an argument"
argument_list|)
argument_list|,
name|isc_commandline_option
argument_list|)
expr_stmt|;
return|return
operator|(
name|BADOPT
operator|)
return|;
block|}
name|place
operator|=
name|ENDOPT
expr_stmt|;
comment|/* 		 * Point to argv that follows argument. 		 */
name|isc_commandline_index
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|isc_commandline_option
operator|)
return|;
block|}
end_function

end_unit

