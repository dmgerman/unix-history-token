begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ENTROPY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|random_adaptors
block|{
name|LIST_ENTRY
argument_list|(
argument|random_adaptors
argument_list|)
name|entries
expr_stmt|;
comment|/* list of providers */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of random adaptor */
name|struct
name|random_adaptor
modifier|*
name|rsp
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|random_adaptor
modifier|*
name|random_adaptor_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random_adaptor_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|random_adaptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_adaptor_choose
parameter_list|(
name|struct
name|random_adaptor
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|random_adaptor
modifier|*
name|random_adaptor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * random_adaptor's should be registered prior to  * random module (SI_SUB_DRIVERS/SI_ORDER_MIDDLE)  */
end_comment

begin_define
define|#
directive|define
name|RANDOM_ADAPTOR_MODULE
parameter_list|(
name|name
parameter_list|,
name|modevent
parameter_list|,
name|ver
parameter_list|)
define|\
value|static moduledata_t name##_mod = {				\ 	#name,							\ 	modevent,						\ 	0							\     };								\     DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS,		\ 		   SI_ORDER_SECOND);				\     MODULE_VERSION(name, ver);					\     MODULE_DEPEND(name, random, 1, 1, 1);
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|random_adaptor_attach_hook
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|random_adaptor
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|random_adaptor_attach
argument_list|,
name|random_adaptor_attach_hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* kern.random sysctls */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_comment
comment|/* from sysctl.h */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_random
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_DECL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_RANDOM_RANDOM_ADAPTORS_H_INCLUDED */
end_comment

end_unit

