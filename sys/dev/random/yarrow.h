begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Mark Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|BINS
value|10
end_define

begin_comment
comment|/* t */
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

begin_comment
comment|/* This is the beasite that needs protecting. It contains all of the  * state that we are excited about.  */
end_comment

begin_struct
struct|struct
name|state
block|{
name|u_int64_t
name|counter
decl_stmt|;
comment|/* C */
name|BF_KEY
name|key
decl_stmt|;
comment|/* K */
name|unsigned
name|char
name|ivec
index|[
literal|8
index|]
decl_stmt|;
comment|/* Blowfish internal */
name|int
name|gengateinterval
decl_stmt|;
comment|/* Pg */
name|int
name|outputblocks
decl_stmt|;
name|unsigned
name|char
name|randomstuff
index|[
literal|1024
index|]
decl_stmt|;
comment|/* XXX to be done properly */
block|}
struct|;
end_struct

end_unit

