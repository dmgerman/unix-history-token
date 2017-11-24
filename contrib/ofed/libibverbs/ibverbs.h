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

begin_define
define|#
directive|define
name|INIT
value|__attribute__((constructor))
end_define

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|"IBVERBS_1.1"
end_define

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

begin_define
define|#
directive|define
name|private_symver
parameter_list|(
name|name
parameter_list|,
name|api
parameter_list|)
define|\
value|asm(".symver " #name "," #api "@@IBVERBS_PRIVATE_14")
end_define

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
name|int
name|abi_ver
decl_stmt|;
end_decl_stmt

begin_function_decl
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

begin_struct
struct|struct
name|verbs_ex_private
block|{
name|struct
name|ibv_cq_ex
modifier|*
function_decl|(
modifier|*
name|create_cq_ex
function_decl|)
parameter_list|(
name|struct
name|ibv_context
modifier|*
name|context
parameter_list|,
name|struct
name|ibv_cq_init_attr_ex
modifier|*
name|init_attr
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|IBV_INIT_CMD_RESP_EX_V
parameter_list|(
name|cmd
parameter_list|,
name|cmd_size
parameter_list|,
name|size
parameter_list|,
name|opcode
parameter_list|,
name|out
parameter_list|,
name|resp_size
parameter_list|,\
name|outsize
parameter_list|)
define|\
value|do {                                                               \ 		size_t c_size = cmd_size - sizeof(struct ex_hdr);	   \ 		if (abi_ver> 2)					   \ 			(cmd)->hdr.command = IB_USER_VERBS_CMD_##opcode;   \ 		else							   \ 			(cmd)->hdr.command =				   \ 				IB_USER_VERBS_CMD_##opcode##_V2;	   \ 		(cmd)->hdr.in_words  = ((c_size) / 8);                     \ 		(cmd)->hdr.out_words = ((resp_size) / 8);                  \ 		(cmd)->hdr.provider_in_words   = (((size) - (cmd_size))/8);\ 		(cmd)->hdr.provider_out_words  =			   \ 			     (((outsize) - (resp_size)) / 8);              \ 		(cmd)->hdr.response  = (uintptr_t) (out);                  \ 		(cmd)->hdr.reserved = 0;				   \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|IBV_INIT_CMD_RESP_EX_VCMD
parameter_list|(
name|cmd
parameter_list|,
name|cmd_size
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
value|IBV_INIT_CMD_RESP_EX_V(cmd, cmd_size, size, opcode, out,	     \ 			sizeof(*(out)), outsize)
end_define

begin_define
define|#
directive|define
name|IBV_INIT_CMD_RESP_EX
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
value|IBV_INIT_CMD_RESP_EX_V(cmd, sizeof(*(cmd)), size, opcode, out,    \ 			sizeof(*(out)), outsize)
end_define

begin_define
define|#
directive|define
name|IBV_INIT_CMD_EX
parameter_list|(
name|cmd
parameter_list|,
name|size
parameter_list|,
name|opcode
parameter_list|)
define|\
value|IBV_INIT_CMD_RESP_EX_V(cmd, sizeof(*(cmd)), size, opcode, NULL, 0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_VERBS_H */
end_comment

end_unit

