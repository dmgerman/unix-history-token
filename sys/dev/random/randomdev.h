begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* This header contains only those definitions that are global  * and non algorithm-specific for the entropy processor  */
end_comment

begin_comment
comment|/* #define ENTROPYSOURCE nn	   entropy sources (actually classes)  *					This is properly defined in  *					an enum in sys/random.h  */
end_comment

begin_comment
comment|/* Cryptographic block size in bits */
end_comment

begin_define
define|#
directive|define
name|BLOCKSIZE
value|256
end_define

begin_comment
comment|/* The ring size _MUST_ be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|HARVEST_RING_SIZE
value|1024
end_define

begin_comment
comment|/* harvest ring buffer size */
end_comment

begin_define
define|#
directive|define
name|HARVEST_RING_MASK
value|(HARVEST_RING_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|HARVESTSIZE
value|16
end_define

begin_comment
comment|/* max size of each harvested entropy unit */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_random
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* These are used to queue harvested packets of entropy. The entropy  * buffer size is pretty arbitrary.  */
end_comment

begin_struct
struct|struct
name|harvest
block|{
name|u_int64_t
name|somecounter
decl_stmt|;
comment|/* fast counter for clock jitter */
name|u_char
name|entropy
index|[
name|HARVESTSIZE
index|]
decl_stmt|;
comment|/* the harvested entropy */
name|u_int
name|size
decl_stmt|,
name|bits
decl_stmt|,
name|frac
decl_stmt|;
comment|/* stats about the entropy */
name|enum
name|esource
name|source
decl_stmt|;
comment|/* stats about the entropy */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|random_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_init_harvester
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|u_int64_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|esource
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_deinit_harvester
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_set_wakeup_exit
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_process_event
parameter_list|(
name|struct
name|harvest
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_reseed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_random_real
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If this was c++, this would be a template */
end_comment

begin_define
define|#
directive|define
name|RANDOM_CHECK_UINT
parameter_list|(
name|name
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|static int								\ random_check_uint_##name(SYSCTL_HANDLER_ARGS)				\ {									\ 	if (oidp->oid_arg1 != NULL) {					\ 		 if (*(u_int *)(oidp->oid_arg1)<= (min))		\ 			*(u_int *)(oidp->oid_arg1) = (min);		\ 		 else if (*(u_int *)(oidp->oid_arg1)> (max))		\ 			*(u_int *)(oidp->oid_arg1) = (max);		\ 	}								\         return sysctl_handle_int(oidp, oidp->oid_arg1, oidp->oid_arg2,	\ 		req);							\ }
end_define

end_unit

