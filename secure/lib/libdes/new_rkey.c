begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/des/new_rkey.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1996 Eric Young (eay@mincom.oz.au)  * All rights reserved.  *   * This file is part of an SSL implementation written  * by Eric Young (eay@mincom.oz.au).  * The implementation was written so as to conform with Netscapes SSL  * specification.  This library and applications are  * FREE FOR COMMERCIAL AND NON-COMMERCIAL USE  * as long as the following conditions are aheared to.  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  If this code is used in a product,  * Eric Young should be given attribution as the author of the parts used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Eric Young (eay@mincom.oz.au)  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995  *	Mark Murray.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Murray  *	and Eric Young  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY MARK MURRAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: new_rnd_key.c,v 1.1 1995/09/16 21:01:51 mark Exp $  */
end_comment

begin_comment
comment|/* 21-Nov-95 - eay - I've finally put this into libdes, I have made a  * few changes since it need to compile on all version of unix and  * there were a few things that would not :-) */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_include
include|#
directive|include
file|"des_locl.h"
end_include

begin_comment
comment|/* This counter keeps track of the pseudo-random sequence */
end_comment

begin_union
specifier|static
union|union
block|{
name|DES_LONG
name|ul0
decl_stmt|,
name|ul1
decl_stmt|;
name|unsigned
name|char
name|uc
index|[
literal|8
index|]
decl_stmt|;
block|}
name|counter
union|;
end_union

begin_comment
comment|/* The current encryption schedule */
end_comment

begin_decl_stmt
specifier|static
name|des_key_schedule
name|current_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *   des_set_random_generator_seed: starts a new pseudorandom sequence  *                                  dependant on the supplied key  */
end_comment

begin_function
name|void
name|des_set_random_generator_seed
parameter_list|(
name|new_key
parameter_list|)
name|des_cblock
modifier|*
name|new_key
decl_stmt|;
block|{
name|des_key_sched
argument_list|(
name|new_key
argument_list|,
name|current_key
argument_list|)
expr_stmt|;
comment|/* reset the counter */
name|counter
operator|.
name|ul0
operator|=
name|counter
operator|.
name|ul1
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *   des_set_sequence_number: set the counter to a known value  */
end_comment

begin_function
name|void
name|des_set_sequence_number
parameter_list|(
name|new_counter
parameter_list|)
name|des_cblock
name|new_counter
decl_stmt|;
block|{
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|counter
operator|.
name|uc
argument_list|,
operator|(
name|char
operator|*
operator|)
name|new_counter
argument_list|,
sizeof|sizeof
argument_list|(
name|counter
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *   des_generate_random_block: returns the next 64 bit random number  */
end_comment

begin_function
name|void
name|des_generate_random_block
parameter_list|(
name|random_block
parameter_list|)
name|des_cblock
modifier|*
name|random_block
decl_stmt|;
block|{
comment|/* Encrypt the counter to get pseudo-random numbers */
name|des_ecb_encrypt
argument_list|(
operator|&
name|counter
operator|.
name|uc
argument_list|,
name|random_block
argument_list|,
name|current_key
argument_list|,
name|DES_ENCRYPT
argument_list|)
expr_stmt|;
comment|/* increment the 64-bit counter  	 * (or that could be a 128 bit counter on a 64 bit box - eay */
if|if
condition|(
operator|!
operator|++
name|counter
operator|.
name|ul0
condition|)
name|counter
operator|.
name|ul1
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *   des_new_random_key: Invents a new, random strong key with odd parity.  */
end_comment

begin_function
name|int
name|des_new_random_key
parameter_list|(
name|new_key
parameter_list|)
name|des_cblock
modifier|*
name|new_key
decl_stmt|;
block|{
do|do
block|{
name|des_generate_random_block
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
name|des_set_odd_parity
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|des_is_weak_key
argument_list|(
name|new_key
argument_list|)
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *   des_init_random_number_generator: intialises the random number generator  *                                     to a truly nasty sequence using system  *                                     supplied volatile variables.  */
end_comment

begin_comment
comment|/* Name shortened for VMS - there is a macro for the old name */
end_comment

begin_function
name|void
name|des_init_random_num_generator
parameter_list|(
name|key
parameter_list|)
name|des_cblock
modifier|*
name|key
decl_stmt|;
block|{
comment|/* 64-bit structures */
struct|struct
block|{
name|u_int32_t
name|pid
decl_stmt|;
name|u_int32_t
name|hostid
decl_stmt|;
block|}
name|sysblock
struct|;
name|struct
name|timeval
name|timeblock
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|tv_sec
decl_stmt|;
name|u_int32_t
name|tv_usec
decl_stmt|;
block|}
name|time64bit
struct|;
name|des_cblock
name|new_key
decl_stmt|;
name|int
name|mib
index|[
literal|2
index|]
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* Get host ID using official BSD 4.4 method */
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|KERN_HOSTID
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|sysblock
operator|.
name|hostid
argument_list|)
expr_stmt|;
name|sysctl
argument_list|(
name|mib
argument_list|,
literal|2
argument_list|,
operator|&
name|sysblock
operator|.
name|hostid
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Get Process ID */
name|sysblock
operator|.
name|pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
comment|/* Generate a new key, and use it to seed the random generator */
name|des_set_random_generator_seed
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|des_set_sequence_number
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|sysblock
argument_list|)
expr_stmt|;
name|des_new_random_key
argument_list|(
operator|&
name|new_key
argument_list|)
expr_stmt|;
name|des_set_random_generator_seed
argument_list|(
operator|&
name|new_key
argument_list|)
expr_stmt|;
comment|/* Try to confuse the sequence counter */
name|gettimeofday
argument_list|(
operator|&
name|timeblock
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|time64bit
operator|.
name|tv_sec
operator|=
operator|(
name|u_int32_t
operator|)
name|timeblock
operator|.
name|tv_sec
expr_stmt|;
name|time64bit
operator|.
name|tv_usec
operator|=
operator|(
name|u_int32_t
operator|)
name|timeblock
operator|.
name|tv_usec
expr_stmt|;
name|des_set_sequence_number
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|time64bit
argument_list|)
expr_stmt|;
comment|/* Do the work */
name|des_new_random_key
argument_list|(
operator|&
name|new_key
argument_list|)
expr_stmt|;
name|des_set_random_generator_seed
argument_list|(
operator|&
name|new_key
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

