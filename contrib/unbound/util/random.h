begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/random.h - thread safe random generator, which is reasonably secure.  *   * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_RANDOM_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_RANDOM_H
end_define

begin_comment
comment|/**  * \file  * Thread safe random functions. Similar to arc4random() with an explicit  * initialisation routine.  */
end_comment

begin_comment
comment|/**  * random state structure.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Initialize the system randomness.  Obtains entropy from the system  * before a chroot or privilege makes it unavailable.   * You do not have to call this, otherwise ub_initstate does so.  * @param seed: seed value to create state (if no good entropy is found).  */
end_comment

begin_function_decl
name|void
name|ub_systemseed
parameter_list|(
name|unsigned
name|int
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize a random generator state for use   * @param seed: seed value to create state contents.  *	(ignored for arc4random).  * @param from: if not NULL, the seed is taken from this random structure.  * 	can be used to seed random states via a parent-random-state that  * 	is itself seeded with entropy.  * @return new state or NULL alloc failure.  */
end_comment

begin_function_decl
name|struct
name|ub_randstate
modifier|*
name|ub_initstate
parameter_list|(
name|unsigned
name|int
name|seed
parameter_list|,
name|struct
name|ub_randstate
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Generate next random number from the state passed along.  * Thread safe, so random numbers are repeatable.  * @param state: must have been initialised with ub_initstate.  * @return: random 31 bit value.  */
end_comment

begin_function_decl
name|long
name|int
name|ub_random
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Generate random number between 0 and x-1.  No modulo bias.  * @param state: must have been initialised with ub_initstate.  * @param x: an upper limit. not (negative or zero). must be smaller than 2**31.  * @return: random value between 0..x-1. Possibly more than one  * random number is picked from the random stream to satisfy this.  */
end_comment

begin_function_decl
name|long
name|int
name|ub_random_max
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|state
parameter_list|,
name|long
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete the random state.  * @param state: to delete.  */
end_comment

begin_function_decl
name|void
name|ub_randfree
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_RANDOM_H */
end_comment

end_unit

