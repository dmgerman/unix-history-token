begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aml_common.h,v 1.4 2000/08/08 14:12:05 iwasaki Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AML_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_AML_COMMON_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|AML_SYSABORT
parameter_list|()
value|do {						\ 	printf("aml: fatal errer at %s:%d\n", __FILE__, __LINE__);	\ 	panic("panic in AML interpreter!");				\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_SYSASSERT
parameter_list|(
name|x
parameter_list|)
value|do {						\ 	if (!(x)) {							\ 		AML_SYSABORT();						\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_SYSERRX
parameter_list|(
name|eval
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\ 	printf(fmt, args);						\ } while(0)
end_define

begin_define
define|#
directive|define
name|AML_DEBUGGER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_comment
comment|/* no debugger in kernel */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|AML_SYSASSERT
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_define
define|#
directive|define
name|AML_SYSABORT
parameter_list|()
value|abort()
end_define

begin_define
define|#
directive|define
name|AML_SYSERRX
parameter_list|(
name|eval
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|errx(eval, fmt, args)
end_define

begin_define
define|#
directive|define
name|AML_DEBUGGER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|aml_dbgr(x, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_union_decl
union_decl|union
name|aml_object
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|aml_name
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|aml_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AML_DEBUGPRINT
parameter_list|(
name|args
modifier|...
parameter_list|)
value|do {					\ 	if (aml_debug) {						\ 		printf(args);						\ 	}								\ } while(0)
end_define

begin_function_decl
name|void
name|aml_showobject
parameter_list|(
name|union
name|aml_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_showtree
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_print_curname
parameter_list|(
name|struct
name|aml_name
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_print_namestring
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aml_print_indent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|aml_bufferfield_read
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aml_bufferfield_write
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AML_COMMON_H_ */
end_comment

end_unit

