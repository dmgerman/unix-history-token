begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Topspin Communications.  All rights reserved.  * Copyright (c) 2007 Cisco Systems, Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_VERBS_H
end_ifndef

begin_define
define|#
directive|define
name|IB_VERBS_H
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/driver.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_VALGRIND_MEMCHECK_H
end_ifdef

begin_include
include|#
directive|include
file|<valgrind/memcheck.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|VALGRIND_MAKE_MEM_DEFINED
end_ifndef

begin_warning
warning|#
directive|warning
literal|"Valgrind support requested, but VALGRIND_MAKE_MEM_DEFINED not available"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_VALGRIND_MEMCHECK_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALGRIND_MAKE_MEM_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HIDDEN
value|__attribute__((visibility ("hidden")))
end_define

begin_define
define|#
directive|define
name|INIT
value|__attribute__((constructor))
end_define

begin_define
define|#
directive|define
name|FINI
value|__attribute__((destructor))
end_define

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|"IBVERBS_1.1"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYMVER_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|symver
parameter_list|(
name|name
parameter_list|,
name|api
parameter_list|,
name|ver
parameter_list|)
define|\
value|asm(".symver " #name "," #api "@" #ver)
end_define

begin_define
define|#
directive|define
name|default_symver
parameter_list|(
name|name
parameter_list|,
name|api
parameter_list|)
define|\
value|asm(".symver " #name "," #api "@@" DEFAULT_ABI)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|symver
parameter_list|(
name|name
parameter_list|,
name|api
parameter_list|,
name|ver
parameter_list|)
end_define

begin_define
define|#
directive|define
name|default_symver
parameter_list|(
name|name
parameter_list|,
name|api
parameter_list|)
define|\
value|extern __typeof(name) api __attribute__((alias(#name)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYMVER_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|PFX
value|"libibverbs: "
end_define

begin_struct
struct|struct
name|ibv_abi_compat_v2
block|{
name|struct
name|ibv_comp_channel
name|channel
decl_stmt|;
name|pthread_mutex_t
name|in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|HIDDEN
name|int
name|abi_ver
decl_stmt|;
end_decl_stmt

begin_function_decl
name|HIDDEN
name|int
name|ibverbs_init
parameter_list|(
name|struct
name|ibv_device
modifier|*
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IBV_INIT_CMD
parameter_list|(
name|cmd
parameter_list|,
name|size
parameter_list|,
name|opcode
parameter_list|)
define|\
value|do {								\ 		if (abi_ver> 2)					\ 			(cmd)->command = IB_USER_VERBS_CMD_##opcode;	\ 		else							\ 			(cmd)->command = IB_USER_VERBS_CMD_##opcode##_V2; \ 		(cmd)->in_words  = (size) / 4;				\ 		(cmd)->out_words = 0;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IBV_INIT_CMD_RESP
parameter_list|(
name|cmd
parameter_list|,
name|size
parameter_list|,
name|opcode
parameter_list|,
name|out
parameter_list|,
name|outsize
parameter_list|)
define|\
value|do {								\ 		if (abi_ver> 2)					\ 			(cmd)->command = IB_USER_VERBS_CMD_##opcode;	\ 		else							\ 			(cmd)->command = IB_USER_VERBS_CMD_##opcode##_V2; \ 		(cmd)->in_words  = (size) / 4;				\ 		(cmd)->out_words = (outsize) / 4;			\ 		(cmd)->response  = (uintptr_t) (out);			\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_VERBS_H */
end_comment

end_unit

