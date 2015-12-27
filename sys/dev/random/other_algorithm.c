begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*-  * This is a skeleton for folks who wish to build a loadable module  * containing an alternative entropy-processing algorithm for random(4).  *  * The functions below should be completed with the appropriate code,  * and the nearby yarrow.c and fortuna.c may be consulted for examples  * of working code.  *  * The author is willing to provide reasonable help to those wishing to  * write such a module for themselves. Please use the markm@ FreeBSD  * email address, and ensure that you are developing this on a suitably  * supported branch (This is currently 11-CURRENT, and will be no  * older than 11-STABLE in the future).  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<crypto/rijndael/rijndael-api-fst.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha256.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/hash.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/randomdev.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/random_harvestq.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/uint128.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/other_algorithm.h>
end_include

begin_function_decl
specifier|static
name|void
name|random_other_pre_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|random_other_read
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|random_other_seeded
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|random_other_process_event
parameter_list|(
name|struct
name|harvest_event
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|random_other_init_alg
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|random_other_deinit_alg
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * RANDOM_OTHER_NPOOLS is used when reading hardware random  * number sources to ensure that each pool gets one read sample  * per loop iteration. Yarrow has 2 such pools (FAST and SLOW),  * and fortuna has 32 (0-31). The RNG used prior to Yarrow and  * ported from Linux had just 1 pool.  */
end_comment

begin_define
define|#
directive|define
name|RANDOM_OTHER_NPOOLS
value|1
end_define

begin_decl_stmt
name|struct
name|random_algorithm
name|random_alg_context
init|=
block|{
operator|.
name|ra_ident
operator|=
literal|"other"
block|,
operator|.
name|ra_init_alg
operator|=
name|random_other_init_alg
block|,
operator|.
name|ra_deinit_alg
operator|=
name|random_other_deinit_alg
block|,
operator|.
name|ra_pre_read
operator|=
name|random_other_pre_read
block|,
operator|.
name|ra_read
operator|=
name|random_other_read
block|,
operator|.
name|ra_seeded
operator|=
name|random_other_seeded
block|,
operator|.
name|ra_event_processor
operator|=
name|random_other_process_event
block|,
operator|.
name|ra_poolcount
operator|=
name|RANDOM_OTHER_NPOOLS
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use a mutex to protect your reseed variables? */
end_comment

begin_decl_stmt
specifier|static
name|mtx_t
name|other_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * void random_other_init_alg(void *unused __unused)  *  * Do algorithm-specific initialisation here.  */
end_comment

begin_function
name|void
name|random_other_init_alg
parameter_list|(
name|void
modifier|*
name|unused
name|__unused
parameter_list|)
block|{
name|RANDOM_RESEED_INIT_LOCK
argument_list|()
expr_stmt|;
comment|/* 	 * Do set-up work here! 	 */
block|}
end_function

begin_comment
comment|/*  * void random_other_deinit_alg(void *unused __unused)  *  * Do algorithm-specific deinitialisation here.  */
end_comment

begin_function
specifier|static
name|void
name|random_other_deinit_alg
parameter_list|(
name|void
modifier|*
name|unused
name|__unused
parameter_list|)
block|{
comment|/* 	 * Do tear-down work here! 	 */
name|RANDOM_RESEED_DEINIT_LOCK
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * void random_other_pre_read(void)  *  * Do any pre-read preparation you need to. This will be called  * before>=1 calls to random_other_read() corresponding to one  * read(2).  *  * This routine will be called periodically while the generator is  * still blocked and a read is being attempted, giving you an  * opportunity to unblock.  */
end_comment

begin_function
specifier|static
name|void
name|random_other_pre_read
parameter_list|(
name|void
parameter_list|)
block|{
name|RANDOM_RESEED_LOCK
argument_list|()
expr_stmt|;
comment|/* 	 * Do pre-read housekeeping work here! 	 * You may use this as a chance to unblock the generator. 	 */
name|RANDOM_RESEED_UNLOCK
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * void random_other_read(uint8_t *buf, u_int count)  *  * Generate<count> bytes of output into<*buf>.  * You may use the fact that<count> will be a multiple of  * RANDOM_BLOCKSIZE for optimization purposes.  *  * This function will always be called with your generator  * unblocked and ready. If you are not ready to generate  * output here, then feel free to KASSERT() or panic().  */
end_comment

begin_function
specifier|static
name|void
name|random_other_read
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|u_int
name|count
parameter_list|)
block|{
name|RANDOM_RESEED_LOCK
argument_list|()
expr_stmt|;
comment|/* 	 * Do random-number generation work here! 	 */
name|RANDOM_RESEED_UNLOCK
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * bool random_other_seeded(void)  *  * Return true if your generator is ready to generate  * output, and false otherwise.  */
end_comment

begin_function
specifier|static
name|bool
name|random_other_seeded
parameter_list|(
name|void
parameter_list|)
block|{
name|bool
name|seeded
init|=
name|false
decl_stmt|;
comment|/* 	 * Find out if your generator is seeded here! 	 */
return|return
operator|(
name|seeded
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * void random_other_process_event(struct harvest_event *event)  *  * Process one stochastic event<*event> into your entropy  * processor.  *  * The structure of the event may change, so it is easier to  * just grab the whole thing into your accumulation system.  * You may pick-and-choose bits, but please don't complain  * when/if these change.  */
end_comment

begin_function
specifier|static
name|void
name|random_other_process_event
parameter_list|(
name|struct
name|harvest_event
modifier|*
name|event
parameter_list|)
block|{
name|RANDOM_RESEED_LOCK
argument_list|()
expr_stmt|;
comment|/* 	 * Do entropy accumulation work here! 	 * You may use this as a chance to unblock the generator. 	 */
name|RANDOM_RESEED_UNLOCK
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

