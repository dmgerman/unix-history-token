begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/des/RCS/new_rnd_key.c,v $  * $Author: bostic $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * New pseudo-random key generator, using DES encryption to make the  * pseudo-random cycle as hard to break as DES.  *  * Written by Mark Lillibridge, MIT Project Athena  *  * Under U.S. law, this software may not be exported outside the US  * without license from the U.S. Commerce department.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_new_rnd_key_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/des/RCS/new_rnd_key.c,v 4.2 91/02/25 15:14:22 bostic Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|"des_internal.h"
end_include

begin_function_decl
specifier|extern
name|void
name|des_fixup_key_parity
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|des_is_weak_key
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|des_set_random_generator_seed
argument_list|()
decl_stmt|,
name|des_set_sequence_number
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|des_generate_random_block
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * des_new_random_key: create a random des key  *  * Requires: des_set_random_number_generater_seed must be at called least  *           once before this routine is called.  *  * Notes: the returned key has correct parity and is guarenteed not  *        to be a weak des key.  Des_generate_random_block is used to  *        provide the random bits.  */
end_comment

begin_function
name|int
name|des_new_random_key
parameter_list|(
name|key
parameter_list|)
name|des_cblock
name|key
decl_stmt|;
block|{
do|do
block|{
name|des_generate_random_block
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|des_fixup_key_parity
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|des_is_weak_key
argument_list|(
name|key
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
comment|/*  * des_init_random_number_generator:  *  *    This routine takes a secret key possibly shared by a number  * of servers and uses it to generate a random number stream that is  * not shared by any of the other servers.  It does this by using the current  * process id, host id, and the current time to the nearest second.  The  * resulting stream seed is not useful information for cracking the secret  * key.   Moreover, this routine keeps no copy of the secret key.  * This routine is used for example, by the kerberos server(s) with the  * key in question being the kerberos master key.  *  * Note: this routine calls des_set_random_generator_seed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSDUNIX
end_ifndef

begin_decl_stmt
name|you
name|lose
modifier|...
argument_list|(
name|aka
argument_list|,
name|you
name|get
name|to
name|implement
name|an
name|analog
name|of
name|this
for|for your 		 system...
argument_list|)
else|#
directive|else
include|#
directive|include
file|<sys/time.h>
name|void
name|des_init_random_number_generator
argument_list|(
name|key
argument_list|)
name|des_cblock
name|key
decl_stmt|;
end_decl_stmt

begin_block
block|{
struct|struct
block|{
comment|/* This must be 64 bits exactly */
name|long
name|process_id
decl_stmt|;
name|long
name|host_id
decl_stmt|;
block|}
name|seed
struct|;
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* this must also be 64 bits exactly */
name|des_cblock
name|new_key
decl_stmt|;
name|long
name|gethostid
parameter_list|()
function_decl|;
comment|/*      * use a host id and process id in generating the seed to ensure      * that different servers have different streams:      */
name|seed
operator|.
name|host_id
operator|=
name|gethostid
argument_list|()
expr_stmt|;
name|seed
operator|.
name|process_id
operator|=
name|getpid
argument_list|()
expr_stmt|;
comment|/*      * Generate a tempory value that depends on the key, host_id, and      * process_id such that it gives no useful information about the key:      */
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
name|seed
argument_list|)
expr_stmt|;
name|des_new_random_key
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
comment|/*      * use it to select a random stream:      */
name|des_set_random_generator_seed
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
comment|/*      * use a time stamp to ensure that a server started later does not reuse      * an old stream:      */
name|gettimeofday
argument_list|(
operator|&
name|time
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
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
name|time
argument_list|)
expr_stmt|;
comment|/*      * use the time stamp finally to select the final seed using the      * current random number stream:      */
name|des_new_random_key
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
name|des_set_random_generator_seed
argument_list|(
name|new_key
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef BSDUNIX */
end_comment

begin_comment
comment|/*  * This module implements a random number generator faculty such that the next  * number in any random number stream is very hard to predict without knowing  * the seed for that stream even given the preceeding random numbers.  */
end_comment

begin_comment
comment|/*  * The secret des key schedule for the current stream of random numbers:  */
end_comment

begin_decl_stmt
specifier|static
name|des_key_schedule
name|random_sequence_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The sequence # in the current stream of random numbers:  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|sequence_number
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * des_set_random_generator_seed: this routine is used to select a random  *                                number stream.  The stream that results is  *                                totally determined by the passed in key.  *                                (I.e., calling this routine again with the  *                                same key allows repeating a sequence of  *                                random numbers)  *  * Requires: key is a valid des key.  I.e., has correct parity and is not a  *           weak des key.  */
end_comment

begin_function
name|void
name|des_set_random_generator_seed
parameter_list|(
name|key
parameter_list|)
name|des_cblock
name|key
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* select the new stream: (note errors are not possible here...) */
name|des_key_sched
argument_list|(
name|key
argument_list|,
name|random_sequence_key
argument_list|)
expr_stmt|;
comment|/* "seek" to the start of the stream: */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|sequence_number
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * des_set_sequence_number: this routine is used to set the sequence number  *                          of the current random number stream.  This routine  *                          may be used to "seek" within the current random  *                          number stream.  *  * Note that des_set_random_generator_seed resets the sequence number to 0.  */
end_comment

begin_function
name|void
name|des_set_sequence_number
parameter_list|(
name|new_sequence_number
parameter_list|)
name|des_cblock
name|new_sequence_number
decl_stmt|;
block|{
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new_sequence_number
argument_list|,
operator|(
name|char
operator|*
operator|)
name|sequence_number
argument_list|,
sizeof|sizeof
argument_list|(
name|sequence_number
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * des_generate_random_block: routine to return the next random number  *                            from the current random number stream.  *                            The returned number is 64 bits long.  *  * Requires: des_set_random_generator_seed must have been called at least once  *           before this routine is called.  */
end_comment

begin_function
name|void
name|des_generate_random_block
parameter_list|(
name|block
parameter_list|)
name|des_cblock
name|block
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/*      * Encrypt the sequence number to get the new random block:      */
name|des_ecb_encrypt
argument_list|(
name|sequence_number
argument_list|,
name|block
argument_list|,
name|random_sequence_key
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/*      * Increment the sequence number as an 8 byte unsigned number with wrap:      * (using LSB here)      */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|sequence_number
index|[
name|i
index|]
operator|=
operator|(
name|sequence_number
index|[
name|i
index|]
operator|+
literal|1
operator|)
operator|&
literal|0xff
expr_stmt|;
if|if
condition|(
name|sequence_number
index|[
name|i
index|]
condition|)
break|break;
block|}
block|}
end_function

end_unit

