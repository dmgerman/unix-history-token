begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|ENTROPYBIN
value|256
end_define

begin_comment
comment|/* buckets to harvest entropy events */
end_comment

begin_define
define|#
directive|define
name|ENTROPYSOURCE
value|2
end_define

begin_comment
comment|/* entropy sources (actually classes)    */
end_comment

begin_comment
comment|/* The entropy classes will as follows:  */
end_comment

begin_comment
comment|/*    0 - Keyboard                       */
end_comment

begin_comment
comment|/*    1 - Mouse                          */
end_comment

begin_comment
comment|/* to start with. More will be added     */
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
name|KEYSIZE
value|32
end_define

begin_comment
comment|/* 32 bytes == 256 bits */
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
name|struct
name|timespec
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|esource
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

begin_comment
comment|/* This is the beasite that needs protecting. It contains all of the  * state that we are excited about.  * This is a biiig structure. It may move over to a malloc(9)ed  * replacement.  */
end_comment

begin_struct
struct|struct
name|random_state
block|{
name|u_int64_t
name|counter
decl_stmt|;
comment|/* C */
name|BF_KEY
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
name|u_char
name|ivec
index|[
literal|8
index|]
decl_stmt|;
comment|/* Blowfish internal */
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
struct|struct
name|entropy
block|{
name|struct
name|timespec
name|nanotime
decl_stmt|;
name|u_int64_t
name|data
decl_stmt|;
block|}
name|entropy
index|[
name|ENTROPYBIN
index|]
struct|;
comment|/* entropy units - must each 					   	be<= KEYSIZE */
name|u_int
name|bits
decl_stmt|;
comment|/* estimated bits of entropy */
name|u_int
name|frac
decl_stmt|;
comment|/* fractional bits of entropy 					   (given as 1024/n) */
name|u_int
name|current
decl_stmt|;
comment|/* next insertion point */
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

