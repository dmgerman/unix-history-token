begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: slist.h,v 4.2 91/11/25 19:45:47 nicklin Exp $  *  * Singly-linked list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Singly-linked list macros  */
end_comment

begin_define
define|#
directive|define
name|SLNUM
parameter_list|(
name|slist
parameter_list|)
value|(slist)->nk
end_define

begin_comment
comment|/*  * Singly-linked list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|slblk
block|{
name|char
modifier|*
name|key
decl_stmt|;
comment|/* points to a key */
name|struct
name|slblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|SLBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Singly-linked list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|slisthb
block|{
name|int
name|nk
decl_stmt|;
comment|/* number of keys in list */
name|int
name|maxkey
decl_stmt|;
comment|/* length of longest key */
name|SLBLK
modifier|*
name|head
decl_stmt|;
comment|/* pointer to first list block */
name|SLBLK
modifier|*
name|curblk
decl_stmt|;
comment|/* pointer to current block */
name|SLBLK
modifier|*
name|tail
decl_stmt|;
comment|/* pointer to last list block */
block|}
name|SLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for singly-linked list operations  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|slappend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* append key */
end_comment

begin_function_decl
specifier|extern
name|SLIST
modifier|*
name|slinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize list */
end_comment

begin_function_decl
specifier|extern
name|void
name|slrm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove list item */
end_comment

begin_function_decl
specifier|extern
name|int
name|slsort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* sort list */
end_comment

begin_function_decl
specifier|extern
name|SLBLK
modifier|*
modifier|*
name|slvect
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* make linked list vector */
end_comment

begin_function_decl
specifier|extern
name|void
name|slvtol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* convert vector to linked list */
end_comment

end_unit

