begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: dlist.h,v 4.2 91/11/25 19:45:47 nicklin Exp $  *  * Dependency list definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Dependency list block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dlblk
block|{
name|int
name|d_type
decl_stmt|;
comment|/* source file type */
name|struct
name|slblk
modifier|*
name|d_src
decl_stmt|;
comment|/* points to a source list block */
name|struct
name|_iblk
modifier|*
name|d_incl
decl_stmt|;
comment|/* pointer to include block chain */
name|struct
name|_dlblk
modifier|*
name|d_next
decl_stmt|;
comment|/* ptr to next list block */
block|}
name|DLBLK
typedef|;
end_typedef

begin_comment
comment|/*  * Dependency list head block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dlisthb
block|{
name|DLBLK
modifier|*
name|d_head
decl_stmt|;
comment|/* pointer to first list block */
name|DLBLK
modifier|*
name|d_tail
decl_stmt|;
comment|/* pointer to last list block */
block|}
name|DLIST
typedef|;
end_typedef

begin_comment
comment|/*  * Functions defined for dependency list operations  */
end_comment

begin_function_decl
specifier|extern
name|DLBLK
modifier|*
name|dlappend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* append to list */
end_comment

begin_function_decl
specifier|extern
name|DLIST
modifier|*
name|dlinit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize list */
end_comment

begin_function_decl
specifier|extern
name|void
name|dlprint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* print list */
end_comment

end_unit

