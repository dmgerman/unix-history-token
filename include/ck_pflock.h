begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 John Wittrock.  * Copyright 2013-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_PFLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|CK_PFLOCK_H
end_define

begin_comment
comment|/*  * This is an implementation of phase-fair locks derived from the work  * described in:  *    Brandenburg, B. and Anderson, J. 2010. Spin-Based  *    Reader-Writer Synchronization for Multiprocessor Real-Time Systems  */
end_comment

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

begin_struct
struct|struct
name|ck_pflock
block|{
name|uint32_t
name|rin
decl_stmt|;
name|uint32_t
name|rout
decl_stmt|;
name|uint32_t
name|win
decl_stmt|;
name|uint32_t
name|wout
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_pflock
name|ck_pflock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CK_PFLOCK_LSB
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|CK_PFLOCK_RINC
value|0x100
end_define

begin_comment
comment|/* Reader increment value. */
end_comment

begin_define
define|#
directive|define
name|CK_PFLOCK_WBITS
value|0x3
end_define

begin_comment
comment|/* Writer bits in reader. */
end_comment

begin_define
define|#
directive|define
name|CK_PFLOCK_PRES
value|0x2
end_define

begin_comment
comment|/* Writer present bit. */
end_comment

begin_define
define|#
directive|define
name|CK_PFLOCK_PHID
value|0x1
end_define

begin_comment
comment|/* Phase ID bit. */
end_comment

begin_define
define|#
directive|define
name|CK_PFLOCK_INITIALIZER
value|{0, 0, 0, 0}
end_define

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pflock_init
parameter_list|(
name|struct
name|ck_pflock
modifier|*
name|pf
parameter_list|)
block|{
name|pf
operator|->
name|rin
operator|=
literal|0
expr_stmt|;
name|pf
operator|->
name|rout
operator|=
literal|0
expr_stmt|;
name|pf
operator|->
name|win
operator|=
literal|0
expr_stmt|;
name|pf
operator|->
name|wout
operator|=
literal|0
expr_stmt|;
name|ck_pr_barrier
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pflock_write_unlock
parameter_list|(
name|ck_pflock_t
modifier|*
name|pf
parameter_list|)
block|{
name|ck_pr_fence_unlock
argument_list|()
expr_stmt|;
comment|/* Migrate from write phase to read phase. */
name|ck_pr_and_32
argument_list|(
operator|&
name|pf
operator|->
name|rin
argument_list|,
name|CK_PFLOCK_LSB
argument_list|)
expr_stmt|;
comment|/* Allow other writers to continue. */
name|ck_pr_faa_32
argument_list|(
operator|&
name|pf
operator|->
name|wout
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pflock_write_lock
parameter_list|(
name|ck_pflock_t
modifier|*
name|pf
parameter_list|)
block|{
name|uint32_t
name|ticket
decl_stmt|;
comment|/* Acquire ownership of write-phase. */
name|ticket
operator|=
name|ck_pr_faa_32
argument_list|(
operator|&
name|pf
operator|->
name|win
argument_list|,
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
name|ck_pr_load_32
argument_list|(
operator|&
name|pf
operator|->
name|wout
argument_list|)
operator|!=
name|ticket
condition|)
name|ck_pr_stall
argument_list|()
expr_stmt|;
comment|/* 	 * Acquire ticket on read-side in order to allow them 	 * to flush. Indicates to any incoming reader that a 	 * write-phase is pending. 	 */
name|ticket
operator|=
name|ck_pr_faa_32
argument_list|(
operator|&
name|pf
operator|->
name|rin
argument_list|,
operator|(
name|ticket
operator|&
name|CK_PFLOCK_PHID
operator|)
operator||
name|CK_PFLOCK_PRES
argument_list|)
expr_stmt|;
comment|/* Wait for any pending readers to flush. */
while|while
condition|(
name|ck_pr_load_32
argument_list|(
operator|&
name|pf
operator|->
name|rout
argument_list|)
operator|!=
name|ticket
condition|)
name|ck_pr_stall
argument_list|()
expr_stmt|;
name|ck_pr_fence_lock
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pflock_read_unlock
parameter_list|(
name|ck_pflock_t
modifier|*
name|pf
parameter_list|)
block|{
name|ck_pr_fence_unlock
argument_list|()
expr_stmt|;
name|ck_pr_faa_32
argument_list|(
operator|&
name|pf
operator|->
name|rout
argument_list|,
name|CK_PFLOCK_RINC
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_pflock_read_lock
parameter_list|(
name|ck_pflock_t
modifier|*
name|pf
parameter_list|)
block|{
name|uint32_t
name|w
decl_stmt|;
comment|/* 	 * If no writer is present, then the operation has completed 	 * successfully. 	 */
name|w
operator|=
name|ck_pr_faa_32
argument_list|(
operator|&
name|pf
operator|->
name|rin
argument_list|,
name|CK_PFLOCK_RINC
argument_list|)
operator|&
name|CK_PFLOCK_WBITS
expr_stmt|;
if|if
condition|(
name|w
operator|==
literal|0
condition|)
goto|goto
name|leave
goto|;
comment|/* Wait for current write phase to complete. */
while|while
condition|(
operator|(
name|ck_pr_load_32
argument_list|(
operator|&
name|pf
operator|->
name|rin
argument_list|)
operator|&
name|CK_PFLOCK_WBITS
operator|)
operator|==
name|w
condition|)
name|ck_pr_stall
argument_list|()
expr_stmt|;
name|leave
label|:
comment|/* Acquire semantics with respect to readers. */
name|ck_pr_fence_lock
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_PFLOCK_H */
end_comment

end_unit

