begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: slrm.c,v 4.2 91/11/25 19:44:59 nicklin Exp $  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slrm() removes a singly linked list.  */
end_comment

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

begin_function
name|void
name|slrm
parameter_list|(
name|slist
parameter_list|)
name|SLIST
modifier|*
name|slist
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|SLBLK
modifier|*
name|nxtblk
decl_stmt|;
comment|/* next list block */
while|while
condition|(
name|slist
operator|->
name|head
operator|!=
name|NULL
condition|)
block|{
name|nxtblk
operator|=
name|slist
operator|->
name|head
operator|->
name|next
expr_stmt|;
name|free
argument_list|(
name|slist
operator|->
name|head
operator|->
name|key
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|slist
operator|->
name|head
argument_list|)
expr_stmt|;
name|slist
operator|->
name|head
operator|=
name|nxtblk
expr_stmt|;
block|}
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|slist
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

