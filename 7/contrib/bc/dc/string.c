begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * implement string functions for dc  *  * Copyright (C) 1994, 1997, 1998 Free Software Foundation, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, you can either send email to this  * program's author (see below) or write to:  *  *    The Free Software Foundation, Inc.  *    59 Temple Place, Suite 330  *    Boston, MA 02111 USA  */
end_comment

begin_comment
comment|/* This should be the only module that knows the internals of type dc_string */
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
name|HAVE_STDDEF_H
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* ptrdiff_t */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ptrdiff_t
value|size_t
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* memcpy */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMORY_H
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_comment
comment|/* memcpy, maybe */
end_comment

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

begin_comment
comment|/* memcpy, maybe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
file|"dc.h"
end_include

begin_include
include|#
directive|include
file|"dc-proto.h"
end_include

begin_comment
comment|/* here is the completion of the dc_string type: */
end_comment

begin_struct
struct|struct
name|dc_string
block|{
name|char
modifier|*
name|s_ptr
decl_stmt|;
comment|/* pointer to base of string */
name|size_t
name|s_len
decl_stmt|;
comment|/* length of counted string */
name|int
name|s_refs
decl_stmt|;
comment|/* reference count to cut down on memory use by duplicates */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* return a duplicate of the string in the passed value */
end_comment

begin_comment
comment|/* The mismatched data types forces the caller to deal with  * bad dc_type'd dc_data values, and makes it more convenient  * for the caller to not have to do the grunge work of setting  * up a dc_type result.  */
end_comment

begin_decl_stmt
name|dc_data
name|dc_dup_str
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|)
argument_list|)
name|dc_str
name|value
name|DC_DECLEND
block|{
name|dc_data
name|result
decl_stmt|;
operator|++
name|value
operator|->
name|s_refs
expr_stmt|;
name|result
operator|.
name|v
operator|.
name|string
operator|=
name|value
expr_stmt|;
name|result
operator|.
name|dc_type
operator|=
name|DC_STRING
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt

begin_comment
comment|/* free an instance of a dc_str value */
end_comment

begin_decl_stmt
name|void
name|dc_free_str
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|)
argument_list|)
name|dc_str
modifier|*
name|value
name|DC_DECLEND
block|{
name|struct
name|dc_string
modifier|*
name|string
init|=
operator|*
name|value
decl_stmt|;
if|if
condition|(
operator|--
name|string
operator|->
name|s_refs
operator|<
literal|1
condition|)
block|{
name|free
argument_list|(
name|string
operator|->
name|s_ptr
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|string
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/* Output a dc_str value.  * Add a trailing newline if "newline" is set.  * Free the value after use if discard_flag is set.  */
end_comment

begin_decl_stmt
name|void
name|dc_out_str
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|,
name|newline
operator|,
name|discard_flag
operator|)
argument_list|)
name|dc_str
name|value
name|DC_DECLSEP
name|dc_newline
name|newline
name|DC_DECLSEP
name|dc_discard
name|discard_flag
name|DC_DECLEND
block|{
name|fwrite
argument_list|(
name|value
operator|->
name|s_ptr
argument_list|,
name|value
operator|->
name|s_len
argument_list|,
sizeof|sizeof
expr|*
name|value
operator|->
name|s_ptr
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|newline
operator|==
name|DC_WITHNL
condition|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|discard_flag
operator|==
name|DC_TOSS
condition|)
name|dc_free_str
argument_list|(
operator|&
name|value
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/* make a copy of a string (base s, length len)  * into a dc_str value; return a dc_data result  * with this value  */
end_comment

begin_decl_stmt
name|dc_data
name|dc_makestring
name|DC_DECLARG
argument_list|(
operator|(
name|s
operator|,
name|len
operator|)
argument_list|)
decl|const
name|char
modifier|*
name|s
name|DC_DECLSEP
name|size_t
name|len
name|DC_DECLEND
block|{
name|dc_data
name|result
decl_stmt|;
name|struct
name|dc_string
modifier|*
name|string
decl_stmt|;
name|string
operator|=
name|dc_malloc
argument_list|(
sizeof|sizeof
expr|*
name|string
argument_list|)
expr_stmt|;
name|string
operator|->
name|s_ptr
operator|=
name|dc_malloc
argument_list|(
name|len
operator|+
literal|1
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|string
operator|->
name|s_ptr
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|string
operator|->
name|s_ptr
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* nul terminated for those who need it */
name|string
operator|->
name|s_len
operator|=
name|len
expr_stmt|;
name|string
operator|->
name|s_refs
operator|=
literal|1
expr_stmt|;
name|result
operator|.
name|v
operator|.
name|string
operator|=
name|string
expr_stmt|;
name|result
operator|.
name|dc_type
operator|=
name|DC_STRING
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt

begin_comment
comment|/* read a dc_str value from FILE *fp;  * if ldelim == rdelim, then read until a ldelim char or EOF is reached;  * if ldelim != rdelim, then read until a matching rdelim for the  * (already eaten) first ldelim is read.  * Return a dc_data result with the dc_str value as its contents.  */
end_comment

begin_decl_stmt
name|dc_data
name|dc_readstring
name|DC_DECLARG
argument_list|(
operator|(
name|fp
operator|,
name|ldelim
operator|,
name|rdelim
operator|)
argument_list|)
name|FILE
modifier|*
name|fp
name|DC_DECLSEP
name|int
name|ldelim
name|DC_DECLSEP
name|int
name|rdelim
name|DC_DECLEND
block|{
specifier|static
name|char
modifier|*
name|line_buf
init|=
name|NULL
decl_stmt|;
comment|/* a buffer to build the string in */
specifier|static
name|size_t
name|buflen
init|=
literal|0
decl_stmt|;
comment|/* the current size of line_buf */
name|int
name|depth
init|=
literal|1
decl_stmt|;
name|int
name|c
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
specifier|const
name|char
modifier|*
name|end
decl_stmt|;
if|if
condition|(
operator|!
name|line_buf
condition|)
block|{
comment|/* initial buflen should be large enough to handle most cases */
name|buflen
operator|=
literal|2016
expr_stmt|;
name|line_buf
operator|=
name|dc_malloc
argument_list|(
name|buflen
argument_list|)
expr_stmt|;
block|}
name|p
operator|=
name|line_buf
expr_stmt|;
name|end
operator|=
name|line_buf
operator|+
name|buflen
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
break|break;
elseif|else
if|if
condition|(
name|c
operator|==
name|rdelim
operator|&&
operator|--
name|depth
operator|<
literal|1
condition|)
break|break;
elseif|else
if|if
condition|(
name|c
operator|==
name|ldelim
condition|)
operator|++
name|depth
expr_stmt|;
if|if
condition|(
name|p
operator|>=
name|end
condition|)
block|{
name|ptrdiff_t
name|offset
init|=
name|p
operator|-
name|line_buf
decl_stmt|;
comment|/* buflen increment should be big enough 			 * to avoid execessive reallocs: 			 */
name|buflen
operator|+=
literal|2048
expr_stmt|;
name|line_buf
operator|=
name|realloc
argument_list|(
name|line_buf
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|line_buf
condition|)
name|dc_memfail
argument_list|()
expr_stmt|;
name|p
operator|=
name|line_buf
operator|+
name|offset
expr_stmt|;
name|end
operator|=
name|line_buf
operator|+
name|buflen
expr_stmt|;
block|}
operator|*
name|p
operator|++
operator|=
name|c
expr_stmt|;
block|}
return|return
name|dc_makestring
argument_list|(
name|line_buf
argument_list|,
call|(
name|size_t
call|)
argument_list|(
name|p
operator|-
name|line_buf
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/* return the base pointer of the dc_str value;  * This function is needed because no one else knows what dc_str  * looks like.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dc_str2charp
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|)
argument_list|)
name|dc_str
name|value
name|DC_DECLEND
block|{
return|return
name|value
operator|->
name|s_ptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/* return the length of the dc_str value;  * This function is needed because no one else knows what dc_str  * looks like, and strlen(dc_str2charp(value)) won't work  * if there's an embedded '\0'.  */
end_comment

begin_decl_stmt
name|size_t
name|dc_strlen
name|DC_DECLARG
argument_list|(
operator|(
name|value
operator|)
argument_list|)
name|dc_str
name|value
name|DC_DECLEND
block|{
return|return
name|value
operator|->
name|s_len
return|;
block|}
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* initialize the strings subsystem */
end_comment

begin_function
name|void
name|dc_string_init
name|DC_DECLVOID
parameter_list|()
block|{
comment|/* nothing to do for this implementation */
block|}
end_function

end_unit

