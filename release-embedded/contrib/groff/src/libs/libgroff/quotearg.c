begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2004    Free Software Foundation, Inc.      Written by:  Jeff Conrad    (jeff_conrad@msn.com)        and        Keith Marshall (keith.d.marshall@ntlworld.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* Define the default mechanism, and messages, for error reporting  * (user may substitute a preferred alternative, by defining his own  *  implementation of the macros REPORT_ERROR, QUOTE_ARG_MALLOC_FAILED  *  and QUOTE_ARG_REALLOC_FAILED, in the header file `nonposix.h').  */
end_comment

begin_include
include|#
directive|include
file|"nonposix.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|REPORT_ERROR
end_ifndef

begin_define
define|#
directive|define
name|REPORT_ERROR
parameter_list|(
name|WHY
parameter_list|)
value|fprintf(stderr, "%s:%s\n", program_name, WHY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QUOTE_ARG_MALLOC_ERROR
end_ifndef

begin_define
define|#
directive|define
name|QUOTE_ARG_MALLOC_ERROR
value|"malloc: Buffer allocation failed"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QUOTE_ARG_REALLOC_ERROR
end_ifndef

begin_define
define|#
directive|define
name|QUOTE_ARG_REALLOC_ERROR
value|"realloc: Buffer resize failed"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main program must define this */
end_comment

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_function
specifier|static
name|int
name|needs_quoting
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
block|{
comment|/* Scan `string' to see whether it needs quoting for MSVC `spawn'/`exec'    * (i.e., whether it contains whitespace or embedded quotes).    */
if|if
condition|(
name|string
operator|==
name|NULL
condition|)
comment|/* ignore NULL strings */
return|return
name|FALSE
return|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'\0'
condition|)
comment|/* explicit arguments of zero length	  */
return|return
name|TRUE
return|;
comment|/* need quoting, so they aren't discarded */
while|while
condition|(
operator|*
name|string
condition|)
block|{
comment|/* Scan non-NULL strings, up to '\0' terminator,      * returning 'TRUE' if quote or white space found.      */
if|if
condition|(
operator|*
name|string
operator|==
literal|'"'
operator|||
name|isspace
argument_list|(
operator|*
name|string
argument_list|)
condition|)
return|return
name|TRUE
return|;
comment|/* otherwise, continue scanning to end of string */
operator|++
name|string
expr_stmt|;
block|}
comment|/* Fall through, if no quotes or white space found,    * in which case, return `FALSE'.    */
return|return
name|FALSE
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|quote_arg
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
block|{
comment|/* Enclose arguments in double quotes so that the parsing done in the    * MSVC runtime startup code doesn't split them at whitespace.  Escape    * embedded double quotes so that they emerge intact from the parsing.    */
name|int
name|backslashes
decl_stmt|;
name|char
modifier|*
name|quoted
decl_stmt|,
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
if|if
condition|(
name|needs_quoting
argument_list|(
name|string
argument_list|)
condition|)
block|{
comment|/* Need to create a quoted copy of `string';      * maximum buffer space needed is twice the original length,      * plus two enclosing quotes and one `\0' terminator.      */
if|if
condition|(
operator|(
name|quoted
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|2
operator|*
name|strlen
argument_list|(
name|string
argument_list|)
operator|+
literal|3
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* Couldn't get a buffer for the quoted string,        * so complain, and bail out gracefully.        */
name|REPORT_ERROR
argument_list|(
name|QUOTE_ARG_MALLOC_ERROR
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Ok to proceed:      * insert the opening quote, then copy the source string,      * adding escapes as required.      */
operator|*
name|quoted
operator|=
literal|'"'
expr_stmt|;
for|for
control|(
name|backslashes
operator|=
literal|0
operator|,
name|p
operator|=
name|string
operator|,
name|q
operator|=
name|quoted
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\\'
condition|)
block|{
comment|/* Just count backslashes when we find them. 	 * We will copy them out later, when we know if the count 	 * needs to be adjusted, to escape an embedded quote. 	 */
operator|++
name|backslashes
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'"'
condition|)
block|{
comment|/* This embedded quote character must be escaped, 	 * but first double up any immediately preceding backslashes, 	 * with one extra, as the escape character. 	 */
for|for
control|(
name|backslashes
operator|+=
name|backslashes
operator|+
literal|1
init|;
name|backslashes
condition|;
name|backslashes
operator|--
control|)
operator|*
operator|++
name|q
operator|=
literal|'\\'
expr_stmt|;
comment|/* and now, add the quote character itself */
operator|*
operator|++
name|q
operator|=
literal|'"'
expr_stmt|;
block|}
else|else
block|{
comment|/* Any other character is simply copied, 	 * but first, if we have any pending backslashes, 	 * we must now insert them, without any count adjustment. 	 */
while|while
condition|(
name|backslashes
condition|)
block|{
operator|*
operator|++
name|q
operator|=
literal|'\\'
expr_stmt|;
operator|--
name|backslashes
expr_stmt|;
block|}
comment|/* and then, copy the current character */
operator|*
operator|++
name|q
operator|=
operator|*
name|p
expr_stmt|;
block|}
block|}
comment|/* At end of argument:      * If any backslashes remain to be copied out, append them now,      * doubling the actual count to protect against reduction by MSVC,      * as a consequence of the immediately following closing quote.      */
for|for
control|(
name|backslashes
operator|+=
name|backslashes
init|;
name|backslashes
condition|;
name|backslashes
operator|--
control|)
operator|*
operator|++
name|q
operator|=
literal|'\\'
expr_stmt|;
comment|/* Finally,      * add the closing quote, terminate the quoted string,      * and adjust its size to what was actually required,      * ready for return.      */
operator|*
operator|++
name|q
operator|=
literal|'"'
expr_stmt|;
operator|*
operator|++
name|q
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|string
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|quoted
argument_list|,
name|strlen
argument_list|(
name|quoted
argument_list|)
operator|+
literal|1
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* but bail out gracefully, on error */
name|REPORT_ERROR
argument_list|(
name|QUOTE_ARG_REALLOC_ERROR
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* `string' now refers to the argument,    * quoted and escaped, as required.    */
return|return
name|string
return|;
block|}
end_function

begin_function
name|void
name|purge_quoted_args
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|/* To avoid memory leaks,    * free all memory previously allocated by `quoted_arg()',    * within the scope of the referring argument vector, `argv'.    */
if|if
condition|(
name|argv
condition|)
while|while
condition|(
operator|*
name|argv
condition|)
block|{
comment|/* Any argument beginning with a double quote        * SHOULD have been allocated by `quoted_arg()'.        */
if|if
condition|(
operator|*
operator|*
name|argv
operator|==
literal|'"'
condition|)
name|free
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
comment|/* so free its allocation */
operator|++
name|argv
expr_stmt|;
comment|/* and continue to the next argument */
block|}
block|}
end_function

begin_comment
comment|/* quotearg.c: end of file */
end_comment

end_unit

