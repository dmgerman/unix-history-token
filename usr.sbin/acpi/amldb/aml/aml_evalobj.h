begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Takanori Watanabe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aml_evalobj.h,v 1.11 2000/08/16 18:14:53 iwasaki Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AML_EVALOBJ_H_
end_ifndef

begin_define
define|#
directive|define
name|_AML_EVALOBJ_H_
end_define

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_function_decl
name|union
name|aml_object
modifier|*
name|aml_eval_objref
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|,
name|union
name|aml_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|aml_object
modifier|*
name|aml_eval_name
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|,
name|struct
name|aml_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_eval_name_simple
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_objtonum
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|,
name|union
name|aml_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|aml_name
modifier|*
name|aml_execute_method
parameter_list|(
name|struct
name|aml_environ
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|aml_object
modifier|*
name|aml_invoke_method_by_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|union
name|aml_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AML_EVALOBJ_H_ */
end_comment

end_unit

