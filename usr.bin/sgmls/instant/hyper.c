begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright 1993 Open Software Foundation, Inc., Cambridge, Massachusetts.  *  All rights reserved.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994    * Open Software Foundation, Inc.   *    * Permission is hereby granted to use, copy, modify and freely distribute   * the software in this file and its documentation for any purpose without   * fee, provided that the above copyright notice appears in all copies and   * that both the copyright notice and this permission notice appear in   * supporting documentation.  Further, provided that the name of Open   * Software Foundation, Inc. ("OSF") not be used in advertising or   * publicity pertaining to distribution of the software without prior   * written permission from OSF.  OSF makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"   * without express or implied warranty.   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 X Consortium  * Copyright (c) 1995, 1996 Dalrymple Consulting  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE  * X CONSORTIUM OR DALRYMPLE CONSULTING BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *   * Except as contained in this notice, the names of the X Consortium and  * Dalrymple Consulting shall not be used in advertising or otherwise to  * promote the sale, use or other dealings in this Software without prior  * written authorization.  */
end_comment

begin_comment
comment|/* ________________________________________________________________________  *  *  Hypermedia-related facilities.  *  *  Entry points for this module:  *	AddID(elem, idval)		add elem-id pair to list of known ids  *	FindElemByID(idval)		find elem by id  * ________________________________________________________________________  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|RCSid
init|=
literal|"$Header: /usr/src/docbook-to-man/Instant/RCS/hyper.c,v 1.2 1996/06/02 21:46:10 fld Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_comment
comment|/* ______________________________________________________________________ */
end_comment

begin_function
name|void
name|AddID
parameter_list|(
name|Element
modifier|*
name|e
parameter_list|,
name|char
modifier|*
name|idval
parameter_list|)
block|{
specifier|static
name|ID
modifier|*
name|id_last
decl_stmt|;
if|if
condition|(
operator|!
name|IDList
condition|)
block|{
name|Calloc
argument_list|(
literal|1
argument_list|,
name|id_last
argument_list|,
name|ID
argument_list|)
expr_stmt|;
name|IDList
operator|=
name|id_last
expr_stmt|;
block|}
else|else
block|{
name|Calloc
argument_list|(
literal|1
argument_list|,
name|id_last
operator|->
name|next
argument_list|,
name|ID
argument_list|)
expr_stmt|;
name|id_last
operator|=
name|id_last
operator|->
name|next
expr_stmt|;
block|}
name|id_last
operator|->
name|elem
operator|=
name|e
expr_stmt|;
name|id_last
operator|->
name|id
operator|=
name|idval
expr_stmt|;
block|}
end_function

begin_function
name|Element
modifier|*
name|FindElemByID
parameter_list|(
name|char
modifier|*
name|idval
parameter_list|)
block|{
name|ID
modifier|*
name|id
decl_stmt|;
for|for
control|(
name|id
operator|=
name|IDList
init|;
name|id
condition|;
name|id
operator|=
name|id
operator|->
name|next
control|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|id
operator|->
name|id
argument_list|,
name|idval
argument_list|)
condition|)
return|return
name|id
operator|->
name|elem
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ______________________________________________________________________ */
end_comment

end_unit

