begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== cond.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : mutex header.  *  *  1.00 93/10/30 proven  *      -Started coding this file.  */
end_comment

begin_comment
comment|/*  * New cond structures  */
end_comment

begin_enum
enum|enum
name|pthread_cond_type
block|{
name|COND_TYPE_FAST
block|,
name|COND_TYPE_STATIC_FAST
block|,
name|COND_TYPE_METERED
block|,
name|COND_TYPE_DEBUG
block|,
comment|/* Debug conds will have lots of options */
name|COND_TYPE_MAX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|pthread_cond
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|struct
name|pthread_queue
name|c_queue
decl_stmt|;
name|semaphore
name|c_lock
decl_stmt|;
name|void
modifier|*
name|c_data
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
block|}
name|pthread_cond_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pthread_cond_attr
block|{
name|enum
name|pthread_cond_type
name|c_type
decl_stmt|;
name|long
name|c_flags
decl_stmt|;
block|}
name|pthread_condattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for conds.  */
end_comment

begin_define
define|#
directive|define
name|COND_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|COND_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Static cond initialization values.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_COND_INITIALIZER
define|\
value|{ COND_TYPE_STATIC_FAST, PTHREAD_QUEUE_INITIALIZER, \ 	 NULL, SEMAPHORE_CLEAR, COND_FLAGS_INITED }
end_define

begin_comment
comment|/*  * New functions  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|pthread_cond_init
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|,
name|pthread_condattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_wait
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|,
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_signal
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_broadcast
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_cond_destroy
name|__P
argument_list|(
operator|(
name|pthread_cond_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

