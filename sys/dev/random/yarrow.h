begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* #define ENTROPYSOURCE nn	   entropy sources (actually classes)  *					This is properly defined in  *					an enum in sys/random.h  */
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
name|TIMEBIN
value|16
end_define

begin_comment
comment|/* max value for Pt/t */
end_comment

begin_define
define|#
directive|define
name|HARVESTSIZE
value|16
end_define

begin_comment
comment|/* max size of each harvested entropy unit */
end_comment

begin_define
define|#
directive|define
name|FAST
value|0
end_define

begin_define
define|#
directive|define
name|SLOW
value|1
end_define

begin_function_decl
name|int
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
name|u_int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
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
name|random_reseed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|read_random_real
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_random
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is the beastie that needs protecting. It contains all of the  * state that we are excited about.  */
end_comment

begin_struct
struct|struct
name|random_state
block|{
name|u_int64_t
name|counter
decl_stmt|;
comment|/* C */
name|struct
name|yarrowkey
name|key
decl_stmt|;
comment|/* K */
name|int
name|gengateinterval
decl_stmt|;
comment|/* Pg */
name|int
name|bins
decl_stmt|;
comment|/* Pt/t */
name|int
name|outputblocks
decl_stmt|;
comment|/* count output blocks for gates */
name|u_int
name|slowoverthresh
decl_stmt|;
comment|/* slow pool overthreshhold reseed count */
struct|struct
name|pool
block|{
struct|struct
name|source
block|{
name|u_int
name|bits
decl_stmt|;
comment|/* estimated bits of entropy */
name|u_int
name|frac
decl_stmt|;
comment|/* fractional bits of entropy 					   (given as 1024/n) */
block|}
name|source
index|[
name|ENTROPYSOURCE
index|]
struct|;
name|u_int
name|thresh
decl_stmt|;
comment|/* pool reseed threshhold */
name|struct
name|yarrowhash
name|hash
decl_stmt|;
comment|/* accumulated entropy */
block|}
name|pool
index|[
literal|2
index|]
struct|;
comment|/* pool[0] is fast, pool[1] is slow */
name|int
name|which
decl_stmt|;
comment|/* toggle - shows the current insertion pool */
name|int
name|seeded
decl_stmt|;
comment|/* 0 causes blocking 1 allows normal output */
name|struct
name|selinfo
name|rsel
decl_stmt|;
comment|/* For poll(2) */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|random_state
name|random_state
decl_stmt|;
end_decl_stmt

end_unit

