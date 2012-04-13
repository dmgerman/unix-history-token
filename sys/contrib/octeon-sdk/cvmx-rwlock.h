begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This file provides reader/writer locks.  *  *<hr>$Revision: 70030 $<hr>  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_RWLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_RWLOCK_H__
end_define

begin_comment
comment|/* include to get atomic compare and store */
end_comment

begin_include
include|#
directive|include
file|"cvmx-atomic.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Flags for lock value in rw lock structure */
define|#
directive|define
name|CVMX_RWLOCK_WRITE_FLAG
value|0x1
define|#
directive|define
name|CVMX_RWLOCK_READ_INC
value|0x2
comment|/* Writer preference locks (wp).  Can be starved by writers.  When a writer  * is waiting, no readers are given the lock until all writers are done.  */
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|lock
decl_stmt|;
specifier|volatile
name|uint32_t
name|write_req
decl_stmt|;
specifier|volatile
name|uint32_t
name|write_comp
decl_stmt|;
block|}
name|cvmx_rwlock_wp_lock_t
typedef|;
comment|/**  * Initialize a reader/writer lock.  This must be done  * by a single core before used.  *  * @param lock   pointer to rwlock structure  */
specifier|static
specifier|inline
name|void
name|cvmx_rwlock_wp_init
parameter_list|(
name|cvmx_rwlock_wp_lock_t
modifier|*
name|lock
parameter_list|)
block|{
name|lock
operator|->
name|lock
operator|=
literal|0
expr_stmt|;
name|lock
operator|->
name|write_req
operator|=
literal|0
expr_stmt|;
name|lock
operator|->
name|write_comp
operator|=
literal|0
expr_stmt|;
block|}
comment|/**  * Perform a reader lock.  If a writer is pending, this  * will wait for that writer to complete before locking.  *  * NOTE: Each thread/process must only lock any rwlock  * once, or else a deadlock may result.  *  * @param lock   pointer to rwlock structure  */
specifier|static
specifier|inline
name|void
name|cvmx_rwlock_wp_read_lock
parameter_list|(
name|cvmx_rwlock_wp_lock_t
modifier|*
name|lock
parameter_list|)
block|{
comment|/* Wait for outstanding write requests to be serviced */
while|while
condition|(
name|lock
operator|->
name|write_req
operator|!=
name|lock
operator|->
name|write_comp
condition|)
empty_stmt|;
comment|/* Add ourselves to interested reader count */
name|cvmx_atomic_add32_nosync
argument_list|(
operator|(
name|int32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|lock
operator|)
argument_list|,
name|CVMX_RWLOCK_READ_INC
argument_list|)
expr_stmt|;
comment|/* Wait for writer to finish.  No writer will start again     ** until after we are done since we have already incremented     ** the reader count     */
while|while
condition|(
name|lock
operator|->
name|lock
operator|&
name|CVMX_RWLOCK_WRITE_FLAG
condition|)
empty_stmt|;
block|}
comment|/**  * Perform a reader unlock.  *  * @param lock   pointer to rwlock structure  */
specifier|static
specifier|inline
name|void
name|cvmx_rwlock_wp_read_unlock
parameter_list|(
name|cvmx_rwlock_wp_lock_t
modifier|*
name|lock
parameter_list|)
block|{
comment|/* Remove ourselves to reader count */
name|cvmx_atomic_add32_nosync
argument_list|(
operator|(
name|int32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|lock
operator|)
argument_list|,
operator|-
name|CVMX_RWLOCK_READ_INC
argument_list|)
expr_stmt|;
block|}
comment|/**  * Perform a writer lock.  Any readers that attempt  * to get a lock while there are any pending write locks  * will wait until all writers have completed.  Starvation  * of readers by writers is possible and must be avoided  * by the application.  *  * @param lock   pointer to rwlock structure  */
specifier|static
specifier|inline
name|void
name|cvmx_rwlock_wp_write_lock
parameter_list|(
name|cvmx_rwlock_wp_lock_t
modifier|*
name|lock
parameter_list|)
block|{
comment|/* Get previous value of write requests */
name|uint32_t
name|prev_writers
init|=
operator|(
operator|(
name|uint32_t
operator|)
name|cvmx_atomic_fetch_and_add32
argument_list|(
operator|(
name|int32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|write_req
operator|)
argument_list|,
literal|1
argument_list|)
operator|)
decl_stmt|;
comment|/* Spin until our turn */
while|while
condition|(
name|prev_writers
operator|!=
name|lock
operator|->
name|write_comp
condition|)
empty_stmt|;
comment|/* Spin until no other readers or writers, then set write flag */
while|while
condition|(
operator|!
name|cvmx_atomic_compare_and_store32
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|lock
operator|)
argument_list|,
literal|0
argument_list|,
name|CVMX_RWLOCK_WRITE_FLAG
argument_list|)
condition|)
empty_stmt|;
block|}
comment|/**  * Perform a writer unlock.  *  * @param lock   pointer to rwlock structure  */
specifier|static
specifier|inline
name|void
name|cvmx_rwlock_wp_write_unlock
parameter_list|(
name|cvmx_rwlock_wp_lock_t
modifier|*
name|lock
parameter_list|)
block|{
comment|/* Remove our writer flag */
name|CVMX_SYNCWS
expr_stmt|;
comment|/* Make sure all writes in protected region are visible before unlock */
name|cvmx_atomic_add32_nosync
argument_list|(
operator|(
name|int32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|lock
operator|)
argument_list|,
operator|-
name|CVMX_RWLOCK_WRITE_FLAG
argument_list|)
expr_stmt|;
name|cvmx_atomic_add32_nosync
argument_list|(
operator|(
name|int32_t
operator|*
operator|)
operator|&
operator|(
name|lock
operator|->
name|write_comp
operator|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|CVMX_SYNCWS
expr_stmt|;
comment|/* push unlock writes out, but don't stall */
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_RWLOCK_H__ */
end_comment

end_unit

