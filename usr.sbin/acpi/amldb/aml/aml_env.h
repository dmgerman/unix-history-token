begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aml_env.h,v 1.11 2000/08/08 14:12:05 iwasaki Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AML_ENV_H_
end_ifndef

begin_define
define|#
directive|define
name|_AML_ENV_H_
end_define

begin_include
include|#
directive|include
file|<aml/aml_name.h>
end_include

begin_include
include|#
directive|include
file|<aml/aml_obj.h>
end_include

begin_include
include|#
directive|include
file|<aml/aml_status.h>
end_include

begin_struct
struct|struct
name|aml_environ
block|{
name|u_int8_t
modifier|*
name|dp
decl_stmt|;
name|u_int8_t
modifier|*
name|end
decl_stmt|;
name|enum
name|aml_status
name|stat
decl_stmt|;
name|struct
name|aml_name
modifier|*
name|curname
decl_stmt|;
name|struct
name|aml_name
name|tempname
decl_stmt|;
name|union
name|aml_object
name|tempobject
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AML_ENV_H_ */
end_comment

end_unit

