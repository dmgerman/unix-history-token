begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: slsort.c,v 4.3 91/11/25 19:44:59 nicklin Exp $  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slsort() sorts list slist according to comparison function compar().  * compar() is to be called with two arguments and must return an integer  * greater than, equal to, or less than 0, depending on the lexicographic  * relationship between the two arguments. Returns integer YES if  * successful, otherwise NO if out of memory.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_function_decl
specifier|static
name|int
name|comparb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compare 2 list blocks */
end_comment

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|sscmp
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string compare function */
end_comment

begin_macro
name|slsort
argument_list|(
argument|compar
argument_list|,
argument|slist
argument_list|)
end_macro

begin_function_decl
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compare two strings */
end_comment

begin_decl_stmt
name|SLIST
modifier|*
name|slist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to list head block */
end_comment

begin_block
block|{
name|char
modifier|*
modifier|*
name|kp
decl_stmt|;
comment|/* pointer to key pointer array */
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|char
modifier|*
modifier|*
name|skp
decl_stmt|;
comment|/* ptr to start of key ptr array */
name|SLBLK
modifier|*
name|curblk
decl_stmt|;
comment|/* current list block */
if|if
condition|(
name|slist
operator|->
name|nk
operator|<=
literal|0
condition|)
return|return
operator|(
name|YES
operator|)
return|;
elseif|else
if|if
condition|(
operator|(
name|skp
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|slist
operator|->
name|nk
operator|*
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|nocore
argument_list|()
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
for|for
control|(
name|kp
operator|=
name|skp
operator|,
name|curblk
operator|=
name|slist
operator|->
name|head
init|;
name|curblk
operator|!=
name|NULL
condition|;
name|kp
operator|++
operator|,
name|curblk
operator|=
name|curblk
operator|->
name|next
control|)
operator|*
name|kp
operator|=
name|curblk
operator|->
name|key
expr_stmt|;
name|sscmp
operator|=
name|compar
expr_stmt|;
name|qsort
argument_list|(
operator|(
name|char
operator|*
operator|)
name|skp
argument_list|,
name|slist
operator|->
name|nk
argument_list|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
argument_list|,
name|comparb
argument_list|)
expr_stmt|;
for|for
control|(
name|kp
operator|=
name|skp
operator|,
name|curblk
operator|=
name|slist
operator|->
name|head
init|;
name|curblk
operator|!=
name|NULL
condition|;
name|kp
operator|++
operator|,
name|curblk
operator|=
name|curblk
operator|->
name|next
control|)
name|curblk
operator|->
name|key
operator|=
operator|*
name|kp
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|skp
argument_list|)
expr_stmt|;
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * comparb() compares key strings in 2 list blocks. Returns whatever  * sscmp() returns. sscmp() is a string compare function.  */
end_comment

begin_function
specifier|static
name|int
name|comparb
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
modifier|*
name|s1
decl_stmt|;
comment|/* string pointer */
name|char
modifier|*
modifier|*
name|s2
decl_stmt|;
comment|/* string pointer */
block|{
return|return
operator|(
call|(
modifier|*
name|sscmp
call|)
argument_list|(
operator|*
name|s1
argument_list|,
operator|*
name|s2
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

