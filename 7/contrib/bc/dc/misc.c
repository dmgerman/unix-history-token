begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * misc. functions for the "dc" Desk Calculator language.  *  * Copyright (C) 1994, 1997, 1998, 2000 Free Software Foundation, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, you can either send email to this  * program's author (see below) or write to:  *   The Free Software Foundation, Inc.  *   59 Temple Place, Suite 330  *   Boston, MA 02111 USA  */
end_comment

begin_comment
comment|/* This module contains miscelaneous functions that have no  * special knowledge of any private data structures.  * They could all be moved to their own separate modules, but  * are agglomerated here for convenience.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|isgraph
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ISGRAPH
end_ifndef

begin_define
define|#
directive|define
name|isgraph
value|isprint
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_include
include|#
directive|include
file|"dc.h"
end_include

begin_include
include|#
directive|include
file|"dc-proto.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_comment
comment|/* C89<stdlib.h> */
end_comment

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* print an "out of memory" diagnostic and exit program */
end_comment

begin_function
name|void
name|dc_memfail
name|DC_DECLVOID
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: out of memory\n"
argument_list|,
name|progname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* malloc or die */
end_comment

begin_decl_stmt
name|void
modifier|*
name|dc_malloc
name|DC_DECLARG
argument_list|(
operator|(
name|len
operator|)
argument_list|)
name|size_t
name|len
name|DC_DECLEND
block|{
name|void
modifier|*
name|result
init|=
name|malloc
argument_list|(
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
name|dc_memfail
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* print the id in a human-understandable form  *  fp is the output stream to place the output on  *  id is the name of the register (or command) to be printed  *  suffix is a modifier (such as "stack") to be printed  */
end_comment

begin_decl_stmt
name|void
name|dc_show_id
name|DC_DECLARG
argument_list|(
operator|(
name|fp
operator|,
name|id
operator|,
name|suffix
operator|)
argument_list|)
name|FILE
modifier|*
name|fp
name|DC_DECLSEP
name|int
name|id
name|DC_DECLSEP
decl|const
name|char
modifier|*
name|suffix
name|DC_DECLEND
block|{
if|if
condition|(
name|isgraph
argument_list|(
name|id
argument_list|)
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"'%c' (%#o)%s"
argument_list|,
name|id
argument_list|,
name|id
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%#o%s"
argument_list|,
name|id
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* report that corrupt data has been detected;  * use the msg and regid (if nonnegative) to give information  * about where the garbage was found,  *  * will abort() so that a debugger might be used to help find  * the bug  */
end_comment

begin_comment
comment|/* If this routine is called, then there is a bug in the code;  * i.e. it is _not_ a data or user error  */
end_comment

begin_decl_stmt
name|void
name|dc_garbage
name|DC_DECLARG
argument_list|(
operator|(
name|msg
operator|,
name|regid
operator|)
argument_list|)
decl|const
name|char
modifier|*
name|msg
name|DC_DECLSEP
name|int
name|regid
name|DC_DECLEND
block|{
if|if
condition|(
name|regid
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: garbage %s\n"
argument_list|,
name|progname
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%s register "
argument_list|,
name|progname
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|dc_show_id
argument_list|(
name|stderr
argument_list|,
name|regid
argument_list|,
literal|" is garbage\n"
argument_list|)
expr_stmt|;
block|}
name|abort
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* call system() with the passed string;  * if the string contains a newline, terminate the string  * there before calling system.  * Return a pointer to the first unused character in the string  * (i.e. past the '\n' if there was one, to the '\0' otherwise).  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dc_system
name|DC_DECLARG
argument_list|(
operator|(
name|s
operator|)
argument_list|)
decl|const
name|char
modifier|*
name|s
name|DC_DECLEND
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|tmpstr
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|p
operator|=
name|strchr
argument_list|(
name|s
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
condition|)
block|{
name|len
operator|=
name|p
operator|-
name|s
expr_stmt|;
name|tmpstr
operator|=
name|dc_malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|tmpstr
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|tmpstr
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
name|system
argument_list|(
name|tmpstr
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|tmpstr
argument_list|)
expr_stmt|;
return|return
name|p
operator|+
literal|1
return|;
block|}
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|s
operator|+
name|strlen
argument_list|(
name|s
argument_list|)
return|;
block|}
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* print out the indicated value */
end_comment

begin_decl_stmt
name|void
name|dc_print
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|,
name|obase
operator|,
name|newline_p
operator|,
name|discard_p
operator|)
argument_list|)
name|dc_data
name|value
name|DC_DECLSEP
name|int
name|obase
name|DC_DECLSEP
name|dc_newline
name|newline_p
name|DC_DECLSEP
name|dc_discard
name|discard_p
name|DC_DECLEND
block|{
if|if
condition|(
name|value
operator|.
name|dc_type
operator|==
name|DC_NUMBER
condition|)
block|{
name|dc_out_num
argument_list|(
name|value
operator|.
name|v
operator|.
name|number
argument_list|,
name|obase
argument_list|,
name|newline_p
argument_list|,
name|discard_p
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|value
operator|.
name|dc_type
operator|==
name|DC_STRING
condition|)
block|{
name|dc_out_str
argument_list|(
name|value
operator|.
name|v
operator|.
name|string
argument_list|,
name|newline_p
argument_list|,
name|discard_p
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dc_garbage
argument_list|(
literal|"in data being printed"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/* return a duplicate of the passed value, regardless of type */
end_comment

begin_decl_stmt
name|dc_data
name|dc_dup
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|)
argument_list|)
name|dc_data
name|value
name|DC_DECLEND
block|{
if|if
condition|(
name|value
operator|.
name|dc_type
operator|!=
name|DC_NUMBER
operator|&&
name|value
operator|.
name|dc_type
operator|!=
name|DC_STRING
condition|)
name|dc_garbage
argument_list|(
literal|"in value being duplicated"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|.
name|dc_type
operator|==
name|DC_NUMBER
condition|)
return|return
name|dc_dup_num
argument_list|(
name|value
operator|.
name|v
operator|.
name|number
argument_list|)
return|;
comment|/*else*/
return|return
name|dc_dup_str
argument_list|(
name|value
operator|.
name|v
operator|.
name|string
argument_list|)
return|;
block|}
end_decl_stmt

end_unit

