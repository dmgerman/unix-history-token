begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== queue.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : mutex header.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_comment
comment|/*  * New queue structures  */
end_comment

begin_struct
struct|struct
name|pthread_queue
block|{
name|struct
name|pthread
modifier|*
name|q_next
decl_stmt|;
name|struct
name|pthread
modifier|*
name|q_last
decl_stmt|;
name|void
modifier|*
name|q_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Static queue initialization values.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_QUEUE_INITIALIZER
value|{ NULL, NULL, NULL }
end_define

begin_comment
comment|/*  * New functions  * Should make pthread_queue_get a macro  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|pthread_queue_init
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_queue_enq
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|,
expr|struct
name|pthread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_queue_remove
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|,
expr|struct
name|pthread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_queue_get
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_queue_deq
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

