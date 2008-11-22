begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<config.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_STRSTR
end_if

begin_comment
comment|/*  * Amanda, The Advanced Maryland Automatic Network Disk Archiver  * Copyright (c) 1991-1998 University of Maryland at College Park  * All Rights Reserved.  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of U.M. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  U.M. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * U.M. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL U.M.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author: James da Silva, Systems Design and Analysis Group  *			   Computer Science Department  *			   University of Maryland at College Park  */
end_comment

begin_comment
comment|/*  * $Id$  *  * replacement for missing ANSI-C strstr function  */
end_comment

begin_function
name|char
modifier|*
name|strstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|int
name|alen
decl_stmt|,
name|blen
decl_stmt|,
name|i
decl_stmt|;
name|alen
operator|=
name|strlen
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|blen
operator|=
name|strlen
argument_list|(
name|b
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|alen
operator|-
name|blen
condition|;
name|i
operator|++
operator|,
name|a
operator|++
control|)
if|if
condition|(
name|strncmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|blen
argument_list|)
operator|==
literal|0
condition|)
return|return
name|a
return|;
return|return
name|NULL
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|strstr_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

