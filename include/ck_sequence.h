begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_SEQUENCE_H
end_ifndef

begin_define
define|#
directive|define
name|CK_SEQUENCE_H
end_define

begin_include
include|#
directive|include
file|<ck_cc.h>
end_include

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_include
include|#
directive|include
file|<ck_stdbool.h>
end_include

begin_struct
struct|struct
name|ck_sequence
block|{
name|unsigned
name|int
name|sequence
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_sequence
name|ck_sequence_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CK_SEQUENCE_INITIALIZER
value|{ .sequence = 0 }
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_sequence_init
parameter_list|(
name|struct
name|ck_sequence
modifier|*
name|sq
parameter_list|)
block|{
name|ck_pr_store_uint
argument_list|(
operator|&
name|sq
operator|->
name|sequence
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|unsigned
name|int
name|ck_sequence_read_begin
parameter_list|(
specifier|const
name|struct
name|ck_sequence
modifier|*
name|sq
parameter_list|)
block|{
name|unsigned
name|int
name|version
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|version
operator|=
name|ck_pr_load_uint
argument_list|(
operator|&
name|sq
operator|->
name|sequence
argument_list|)
expr_stmt|;
comment|/* 		 * If a sequence is even then associated data may be in a 		 * consistent state. 		 */
if|if
condition|(
name|CK_CC_LIKELY
argument_list|(
operator|(
name|version
operator|&
literal|1
operator|)
operator|==
literal|0
argument_list|)
condition|)
break|break;
comment|/* 		 * If a sequence is odd then a thread is in the middle of an 		 * update. Retry the read to avoid operating on inconsistent 		 * data. 		 */
name|ck_pr_stall
argument_list|()
expr_stmt|;
block|}
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
return|return
name|version
return|;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_sequence_read_retry
parameter_list|(
specifier|const
name|struct
name|ck_sequence
modifier|*
name|sq
parameter_list|,
name|unsigned
name|int
name|version
parameter_list|)
block|{
comment|/* 	 * If the sequence number was updated then a read should be 	 * re-attempted. 	 */
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
return|return
name|ck_pr_load_uint
argument_list|(
operator|&
name|sq
operator|->
name|sequence
argument_list|)
operator|!=
name|version
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CK_SEQUENCE_READ
parameter_list|(
name|seqlock
parameter_list|,
name|version
parameter_list|)
define|\
value|for (*(version) = 1;								\ 	    (*(version) != 0)&& (*(version) = ck_sequence_read_begin(seqlock), 1);	\ 	    *(version) = ck_sequence_read_retry(seqlock, *(version)))
end_define

begin_comment
comment|/*  * This must be called after a successful mutex acquisition.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_sequence_write_begin
parameter_list|(
name|struct
name|ck_sequence
modifier|*
name|sq
parameter_list|)
block|{
comment|/* 	 * Increment the sequence to an odd number to indicate 	 * the beginning of a write update. 	 */
name|ck_pr_store_uint
argument_list|(
operator|&
name|sq
operator|->
name|sequence
argument_list|,
name|sq
operator|->
name|sequence
operator|+
literal|1
argument_list|)
expr_stmt|;
name|ck_pr_fence_store
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * This must be called before mutex ownership is relinquished.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_sequence_write_end
parameter_list|(
name|struct
name|ck_sequence
modifier|*
name|sq
parameter_list|)
block|{
comment|/* 	 * Increment the sequence to an even number to indicate 	 * completion of a write update. 	 */
name|ck_pr_fence_store
argument_list|()
expr_stmt|;
name|ck_pr_store_uint
argument_list|(
operator|&
name|sq
operator|->
name|sequence
argument_list|,
name|sq
operator|->
name|sequence
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_SEQUENCE_H */
end_comment

end_unit

