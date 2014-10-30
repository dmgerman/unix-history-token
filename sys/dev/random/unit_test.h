begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIT_TEST_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|UNIT_TEST_H_INCLUDED
end_define

begin_function_decl
name|void
name|random_adaptor_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Shaddup! */
return|return
operator|(
literal|4ULL
operator|)
return|;
block|}
end_function

begin_comment
comment|// #define PAGE_SIZE	4096
end_comment

begin_define
define|#
directive|define
name|HARVESTSIZE
value|16
end_define

begin_enum
enum|enum
name|random_entropy_source
block|{
name|RANDOM_START
init|=
literal|0
block|,
name|RANDOM_CACHED
init|=
literal|0
block|,
name|ENTROPYSOURCE
init|=
literal|32
block|}
enum|;
end_enum

begin_struct
struct|struct
name|harvest_event
block|{
name|uintmax_t
name|he_somecounter
decl_stmt|;
comment|/* fast counter for clock jitter */
name|uint8_t
name|he_entropy
index|[
name|HARVESTSIZE
index|]
decl_stmt|;
comment|/* some harvested entropy */
name|u_int
name|he_size
decl_stmt|;
comment|/* harvested entropy byte count */
name|u_int
name|he_bits
decl_stmt|;
comment|/* stats about the entropy */
name|u_int
name|he_destination
decl_stmt|;
comment|/* destination pool of this entropy */
name|enum
name|random_entropy_source
name|he_source
decl_stmt|;
comment|/* origin of the entropy */
name|void
modifier|*
name|he_next
decl_stmt|;
comment|/* next item on the list */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CTASSERT
parameter_list|(
name|x
parameter_list|)
value|_Static_assert(x, "compile-time assertion failed")
end_define

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
value|do {	\ 	if (!(exp)) {		\ 		printf msg;	\ 		exit(0);	\ 	}			\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIT_TEST_H_INCLUDED */
end_comment

end_unit

