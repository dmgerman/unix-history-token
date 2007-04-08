begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Andrea Bittau<a.bittau@cs.ucl.ac.uk>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// Number of bytes we use for our table of seen IVs, this is (2^24)/8
end_comment

begin_define
define|#
directive|define
name|PTW_IVTABLELEN
value|2097152
end_define

begin_comment
comment|// How many sessions do we use to check if a guessed key is correct
end_comment

begin_comment
comment|// 10 seems to be a reasonable choice
end_comment

begin_define
define|#
directive|define
name|PTW_CONTROLSESSIONS
value|10
end_define

begin_comment
comment|// The maximum possible length of the main key, 13 is the maximum for a 104 bit key
end_comment

begin_define
define|#
directive|define
name|PTW_KEYHSBYTES
value|13
end_define

begin_comment
comment|// How long the IV is, 3 is the default value for WEP
end_comment

begin_define
define|#
directive|define
name|PTW_IVBYTES
value|3
end_define

begin_comment
comment|// How many bytes of a keystream we collect, 16 are needed for a 104 bit key
end_comment

begin_define
define|#
directive|define
name|PTW_KSBYTES
value|16
end_define

begin_comment
comment|// The MAGIC VALUE!!
end_comment

begin_define
define|#
directive|define
name|PTW_n
value|256
end_define

begin_comment
comment|// We use this to keep track of the outputs of A_i
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// How often the value b appeard as an output of A_i
name|int
name|votes
decl_stmt|;
name|uint8_t
name|b
decl_stmt|;
block|}
name|PTW_tableentry
typedef|;
end_typedef

begin_comment
comment|// A recovered session
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// The IV used in this session
name|uint8_t
name|iv
index|[
name|PTW_IVBYTES
index|]
decl_stmt|;
comment|// The keystream used in this session
name|uint8_t
name|keystream
index|[
name|PTW_KSBYTES
index|]
decl_stmt|;
block|}
name|PTW_session
typedef|;
end_typedef

begin_comment
comment|// The state of an attack
end_comment

begin_comment
comment|// You should usually never modify these values manually
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// How many unique packets or IVs have been collected
name|int
name|packets_collected
decl_stmt|;
comment|// Table to check for duplicate IVs
name|uint8_t
name|seen_iv
index|[
name|PTW_IVTABLELEN
index|]
decl_stmt|;
comment|// How many sessions for checking a guessed key have been collected
name|int
name|sessions_collected
decl_stmt|;
comment|// The actual recovered sessions
name|PTW_session
name|sessions
index|[
name|PTW_CONTROLSESSIONS
index|]
decl_stmt|;
comment|// The table with votes for the keybytesums
name|PTW_tableentry
name|table
index|[
name|PTW_KEYHSBYTES
index|]
index|[
name|PTW_n
index|]
decl_stmt|;
block|}
name|PTW_attackstate
typedef|;
end_typedef

begin_function_decl
name|PTW_attackstate
modifier|*
name|PTW_newattackstate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PTW_freeattackstate
parameter_list|(
name|PTW_attackstate
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PTW_addsession
parameter_list|(
name|PTW_attackstate
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PTW_computeKey
parameter_list|(
name|PTW_attackstate
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

