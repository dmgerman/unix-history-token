begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: stringx.h,v 4.6 91/11/25 19:45:47 nicklin Exp $  *  * String definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRINGX_H
end_ifndef

begin_define
define|#
directive|define
name|STRINGX_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_HasIncludeStrings
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_HasStrDcl
end_ifndef

begin_function_decl
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HasStrDcl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HasStrchr
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|strchr
end_ifndef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|strrchr
end_ifndef

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

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

begin_comment
comment|/* STRINGX_H */
end_comment

end_unit

