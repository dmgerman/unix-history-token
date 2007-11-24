begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2003 Hewlett-Packard Development Company, L.P. Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UWX_SELF_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|__UWX_SELF_INCLUDED
value|1
end_define

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__UWX_INCLUDED
end_ifndef

begin_include
include|#
directive|include
file|"uwx.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __UWX_INCLUDED */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__EXTERN_C
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__EXTERN_C
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|uwx_self_info
struct_decl|;
end_struct_decl

begin_function_decl
name|__EXTERN_C
name|struct
name|uwx_self_info
modifier|*
name|uwx_self_init_info
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_free_info
parameter_list|(
name|struct
name|uwx_self_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_init_context
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_init_from_sigcontext
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_self_info
modifier|*
name|info
parameter_list|,
name|ucontext_t
modifier|*
name|ucontext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_do_context_frame
parameter_list|(
name|struct
name|uwx_env
modifier|*
name|env
parameter_list|,
name|struct
name|uwx_self_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_copyin
parameter_list|(
name|int
name|request
parameter_list|,
name|char
modifier|*
name|loc
parameter_list|,
name|uint64_t
name|rem
parameter_list|,
name|int
name|len
parameter_list|,
name|intptr_t
name|tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__EXTERN_C
name|int
name|uwx_self_lookupip
parameter_list|(
name|int
name|request
parameter_list|,
name|uint64_t
name|ip
parameter_list|,
name|intptr_t
name|tok
parameter_list|,
name|uint64_t
modifier|*
modifier|*
name|resultp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UWX_SELF_ERR_BADABICONTEXT
value|(-101)
end_define

begin_undef
undef|#
directive|undef
name|__EXTERN_C
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_decl_stmt
name|class
name|UnwindExpressSelf
range|:
name|public
name|UnwindExpress
block|{
name|public
operator|:
name|UnwindExpressSelf
argument_list|()
block|{
name|info
operator|=
name|uwx_self_init_info
argument_list|(
name|env
argument_list|)
block|;
operator|(
name|void
operator|)
name|uwx_register_callbacks
argument_list|(
name|env
argument_list|,
operator|(
name|intptr_t
operator|)
name|info
argument_list|,
name|uwx_self_copyin
argument_list|,
name|uwx_self_lookupip
argument_list|)
block|;     }
operator|~
name|UnwindExpressSelf
argument_list|()
block|{
if|if
condition|(
name|info
operator|!=
literal|0
condition|)
name|uwx_self_free_info
argument_list|(
name|info
argument_list|)
expr_stmt|;
name|info
operator|=
literal|0
block|;     }
name|int
name|init_context
argument_list|()
block|{
return|return
name|uwx_self_init_context
argument_list|(
name|env
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|int
name|init_context
parameter_list|(
name|ucontext_t
modifier|*
name|ucontext
parameter_list|)
block|{
return|return
name|uwx_self_init_from_sigcontext
argument_list|(
name|env
argument_list|,
name|info
argument_list|,
name|ucontext
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|do_context_frame
parameter_list|()
block|{
return|return
name|uwx_self_do_context_frame
argument_list|(
name|env
argument_list|,
name|info
argument_list|)
return|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|struct
name|uwx_self_info
modifier|*
name|info
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __UWX_SELF_INCLUDED */
end_comment

end_unit

