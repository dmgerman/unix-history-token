begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_prop.h,v 1.3 2006/11/23 13:59:03 tnozaki Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c)2006 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_PROP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_PROP_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|_CITRUS_PROP_BOOL
init|=
literal|0
block|,
name|_CITRUS_PROP_STR
init|=
literal|1
block|,
name|_CITRUS_PROP_CHR
init|=
literal|2
block|,
name|_CITRUS_PROP_NUM
init|=
literal|3
block|, }
name|_citrus_prop_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_citrus_prop_hint_t
name|_citrus_prop_hint_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CITRUS_PROP_CB0_T
parameter_list|(
name|_func_
parameter_list|,
name|_type_
parameter_list|)
define|\
value|typedef int (*_citrus_prop_##_func_##_cb_func_t) \     (void * __restrict, const char *, _type_); \ typedef struct { \ 	_citrus_prop_##_func_##_cb_func_t func; \ } _citrus_prop_##_func_##_cb_t;
end_define

begin_macro
name|_CITRUS_PROP_CB0_T
argument_list|(
argument|boolean
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|_CITRUS_PROP_CB0_T
argument_list|(
argument|str
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|_CITRUS_PROP_CB0_T
end_undef

begin_define
define|#
directive|define
name|_CITRUS_PROP_CB1_T
parameter_list|(
name|_func_
parameter_list|,
name|_type_
parameter_list|)
define|\
value|typedef int (*_citrus_prop_##_func_##_cb_func_t) \     (void * __restrict, const char *, _type_, _type_); \ typedef struct { \ 	_citrus_prop_##_func_##_cb_func_t func; \ } _citrus_prop_##_func_##_cb_t;
end_define

begin_macro
name|_CITRUS_PROP_CB1_T
argument_list|(
argument|chr
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|_CITRUS_PROP_CB1_T
argument_list|(
argument|num
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|_CITRUS_PROP_CB1_T
end_undef

begin_struct
struct|struct
name|_citrus_prop_hint_t
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|_citrus_prop_type_t
name|type
decl_stmt|;
define|#
directive|define
name|_CITRUS_PROP_CB_T_OPS
parameter_list|(
name|_name_
parameter_list|)
define|\
value|_citrus_prop_##_name_##_cb_t _name_
union|union
block|{
name|_CITRUS_PROP_CB_T_OPS
argument_list|(
name|boolean
argument_list|)
expr_stmt|;
name|_CITRUS_PROP_CB_T_OPS
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|_CITRUS_PROP_CB_T_OPS
argument_list|(
name|chr
argument_list|)
expr_stmt|;
name|_CITRUS_PROP_CB_T_OPS
argument_list|(
name|num
argument_list|)
expr_stmt|;
block|}
name|cb
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_CITRUS_PROP_HINT_BOOL
parameter_list|(
name|name
parameter_list|,
name|cb
parameter_list|)
define|\
value|{ name, _CITRUS_PROP_BOOL, { .boolean = { cb } } }
end_define

begin_define
define|#
directive|define
name|_CITRUS_PROP_HINT_STR
parameter_list|(
name|name
parameter_list|,
name|cb
parameter_list|)
define|\
value|{ name, _CITRUS_PROP_STR, { .str = { cb } } }
end_define

begin_define
define|#
directive|define
name|_CITRUS_PROP_HINT_CHR
parameter_list|(
name|name
parameter_list|,
name|cb
parameter_list|)
define|\
value|{ name, _CITRUS_PROP_CHR, { .chr = { cb } } }
end_define

begin_define
define|#
directive|define
name|_CITRUS_PROP_HINT_NUM
parameter_list|(
name|name
parameter_list|,
name|cb
parameter_list|)
define|\
value|{ name, _CITRUS_PROP_NUM, { .num = { cb } } }
end_define

begin_define
define|#
directive|define
name|_CITRUS_PROP_HINT_END
define|\
value|{ NULL, _CITRUS_PROP_NUM, { .num = { 0 } } }
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|_citrus_prop_parse_variable
parameter_list|(
specifier|const
name|_citrus_prop_hint_t
modifier|*
name|__restrict
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CITRUS_PROP_H_ */
end_comment

end_unit

