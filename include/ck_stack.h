begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_STACK_H
end_ifndef

begin_define
define|#
directive|define
name|CK_STACK_H
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

begin_include
include|#
directive|include
file|<ck_stddef.h>
end_include

begin_struct
struct|struct
name|ck_stack_entry
block|{
name|struct
name|ck_stack_entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_stack_entry
name|ck_stack_entry_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ck_stack
block|{
name|struct
name|ck_stack_entry
modifier|*
name|head
decl_stmt|;
name|char
modifier|*
name|generation
name|CK_CC_PACKED
decl_stmt|;
block|}
name|CK_CC_ALIASED
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ck_stack
name|ck_stack_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CK_STACK_INITIALIZER
value|{ NULL, NULL }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_PUSH_UPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_PUSH_UPMC
end_define

begin_comment
comment|/*  * Stack producer operation safe for multiple unique producers and multiple consumers.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_stack_push_upmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
name|struct
name|ck_stack_entry
modifier|*
name|stack
decl_stmt|;
name|stack
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
expr_stmt|;
name|entry
operator|->
name|next
operator|=
name|stack
expr_stmt|;
name|ck_pr_fence_store
argument_list|()
expr_stmt|;
while|while
condition|(
name|ck_pr_cas_ptr_value
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|stack
argument_list|,
name|entry
argument_list|,
operator|&
name|stack
argument_list|)
operator|==
name|false
condition|)
block|{
name|entry
operator|->
name|next
operator|=
name|stack
expr_stmt|;
name|ck_pr_fence_store
argument_list|()
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_PUSH_UPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_TRYPUSH_UPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_TRYPUSH_UPMC
end_define

begin_comment
comment|/*  * Stack producer operation for multiple unique producers and multiple consumers.  * Returns true on success and false on failure.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_stack_trypush_upmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
name|struct
name|ck_stack_entry
modifier|*
name|stack
decl_stmt|;
name|stack
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
expr_stmt|;
name|entry
operator|->
name|next
operator|=
name|stack
expr_stmt|;
name|ck_pr_fence_store
argument_list|()
expr_stmt|;
return|return
name|ck_pr_cas_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|stack
argument_list|,
name|entry
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_TRYPUSH_UPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_POP_UPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_POP_UPMC
end_define

begin_comment
comment|/*  * Stack consumer operation safe for multiple unique producers and multiple consumers.  */
end_comment

begin_expr_stmt
name|CK_CC_INLINE
specifier|static
expr|struct
name|ck_stack_entry
operator|*
name|ck_stack_pop_upmc
argument_list|(
argument|struct ck_stack *target
argument_list|)
block|{ 	struct
name|ck_stack_entry
operator|*
name|entry
block|,
operator|*
name|next
block|;
name|entry
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
block|;
if|if
condition|(
name|entry
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|next
operator|=
name|entry
operator|->
name|next
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|ck_pr_cas_ptr_value
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|entry
argument_list|,
name|next
argument_list|,
operator|&
name|entry
argument_list|)
operator|==
name|false
condition|)
block|{
if|if
condition|(
name|entry
operator|==
name|NULL
condition|)
break|break;
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
name|next
operator|=
name|entry
operator|->
name|next
expr_stmt|;
block|}
end_while

begin_return
return|return
name|entry
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_TRYPOP_UPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_TRYPOP_UPMC
end_define

begin_comment
comment|/*  * Stack production operation for multiple unique producers and multiple consumers.  * Returns true on success and false on failure. The value pointed to by the second  * argument is set to a valid ck_stack_entry_t reference if true is returned. If  * false is returned, then the value pointed to by the second argument is undefined.  */
end_comment

begin_function
unit|CK_CC_INLINE
specifier|static
name|bool
name|ck_stack_trypop_upmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
modifier|*
name|r
parameter_list|)
block|{
name|struct
name|ck_stack_entry
modifier|*
name|entry
decl_stmt|;
name|entry
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
expr_stmt|;
if|if
condition|(
name|entry
operator|==
name|NULL
condition|)
return|return
name|false
return|;
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
if|if
condition|(
name|ck_pr_cas_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|entry
argument_list|,
name|entry
operator|->
name|next
argument_list|)
operator|==
name|true
condition|)
block|{
operator|*
name|r
operator|=
name|entry
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_TRYPOP_UPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_BATCH_POP_UPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_BATCH_POP_UPMC
end_define

begin_comment
comment|/*  * Pop all items off the stack.  */
end_comment

begin_expr_stmt
name|CK_CC_INLINE
specifier|static
expr|struct
name|ck_stack_entry
operator|*
name|ck_stack_batch_pop_upmc
argument_list|(
argument|struct ck_stack *target
argument_list|)
block|{ 	struct
name|ck_stack_entry
operator|*
name|entry
block|;
name|entry
operator|=
name|ck_pr_fas_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|NULL
argument_list|)
block|;
name|ck_pr_fence_load
argument_list|()
block|;
return|return
name|entry
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_BATCH_POP_UPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_PUSH_MPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_PUSH_MPMC
end_define

begin_comment
comment|/*  * Stack producer operation safe for multiple producers and multiple consumers.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_stack_push_mpmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
name|ck_stack_push_upmc
argument_list|(
name|target
argument_list|,
name|entry
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
comment|/* CK_F_STACK_PUSH_MPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_TRYPUSH_MPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_TRYPUSH_MPMC
end_define

begin_comment
comment|/*  * Stack producer operation safe for multiple producers and multiple consumers.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|bool
name|ck_stack_trypush_mpmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
return|return
name|ck_stack_trypush_upmc
argument_list|(
name|target
argument_list|,
name|entry
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_TRYPUSH_MPMC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_CAS_PTR_2_VALUE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_POP_MPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_POP_MPMC
end_define

begin_comment
comment|/*  * Stack consumer operation safe for multiple producers and multiple consumers.  */
end_comment

begin_expr_stmt
name|CK_CC_INLINE
specifier|static
expr|struct
name|ck_stack_entry
operator|*
name|ck_stack_pop_mpmc
argument_list|(
argument|struct ck_stack *target
argument_list|)
block|{ 	struct
name|ck_stack
name|original
block|,
name|update
block|;
name|original
operator|.
name|generation
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|generation
argument_list|)
block|;
name|ck_pr_fence_load
argument_list|()
block|;
name|original
operator|.
name|head
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
block|;
if|if
condition|(
name|original
operator|.
name|head
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* Order with respect to next pointer. */
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|update
operator|.
name|generation
operator|=
name|original
operator|.
name|generation
operator|+
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|update
operator|.
name|head
operator|=
name|original
operator|.
name|head
operator|->
name|next
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|ck_pr_cas_ptr_2_value
argument_list|(
name|target
argument_list|,
operator|&
name|original
argument_list|,
operator|&
name|update
argument_list|,
operator|&
name|original
argument_list|)
operator|==
name|false
condition|)
block|{
if|if
condition|(
name|original
operator|.
name|head
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|update
operator|.
name|generation
operator|=
name|original
operator|.
name|generation
operator|+
literal|1
expr_stmt|;
comment|/* Order with respect to next pointer. */
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
name|update
operator|.
name|head
operator|=
name|original
operator|.
name|head
operator|->
name|next
expr_stmt|;
block|}
end_while

begin_return
return|return
name|original
operator|.
name|head
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_POP_MPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_TRYPOP_MPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_TRYPOP_MPMC
end_define

begin_function
unit|CK_CC_INLINE
specifier|static
name|bool
name|ck_stack_trypop_mpmc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
modifier|*
name|r
parameter_list|)
block|{
name|struct
name|ck_stack
name|original
decl_stmt|,
name|update
decl_stmt|;
name|original
operator|.
name|generation
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|generation
argument_list|)
expr_stmt|;
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
name|original
operator|.
name|head
operator|=
name|ck_pr_load_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|)
expr_stmt|;
if|if
condition|(
name|original
operator|.
name|head
operator|==
name|NULL
condition|)
return|return
name|false
return|;
name|update
operator|.
name|generation
operator|=
name|original
operator|.
name|generation
operator|+
literal|1
expr_stmt|;
name|ck_pr_fence_load
argument_list|()
expr_stmt|;
name|update
operator|.
name|head
operator|=
name|original
operator|.
name|head
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|ck_pr_cas_ptr_2_value
argument_list|(
name|target
argument_list|,
operator|&
name|original
argument_list|,
operator|&
name|update
argument_list|,
operator|&
name|original
argument_list|)
operator|==
name|true
condition|)
block|{
operator|*
name|r
operator|=
name|original
operator|.
name|head
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_TRYPOP_MPMC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_PR_CAS_PTR_2_VALUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_BATCH_POP_MPMC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_BATCH_POP_MPMC
end_define

begin_comment
comment|/*  * This is equivalent to the UP/MC version as NULL does not need a  * a generation count.  */
end_comment

begin_expr_stmt
name|CK_CC_INLINE
specifier|static
expr|struct
name|ck_stack_entry
operator|*
name|ck_stack_batch_pop_mpmc
argument_list|(
argument|struct ck_stack *target
argument_list|)
block|{
return|return
name|ck_stack_batch_pop_upmc
argument_list|(
name|target
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_F_STACK_BATCH_POP_MPMC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_F_STACK_PUSH_MPNC
end_ifndef

begin_define
define|#
directive|define
name|CK_F_STACK_PUSH_MPNC
end_define

begin_comment
comment|/*  * Stack producer operation safe with no concurrent consumers.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_stack_push_mpnc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
name|struct
name|ck_stack_entry
modifier|*
name|stack
decl_stmt|;
name|entry
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
name|ck_pr_fence_store_atomic
argument_list|()
expr_stmt|;
name|stack
operator|=
name|ck_pr_fas_ptr
argument_list|(
operator|&
name|target
operator|->
name|head
argument_list|,
name|entry
argument_list|)
expr_stmt|;
name|ck_pr_store_ptr
argument_list|(
operator|&
name|entry
operator|->
name|next
argument_list|,
name|stack
argument_list|)
expr_stmt|;
name|ck_pr_fence_store
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
comment|/* CK_F_STACK_PUSH_MPNC */
end_comment

begin_comment
comment|/*  * Stack producer operation for single producer and no concurrent consumers.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_stack_push_spnc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|,
name|struct
name|ck_stack_entry
modifier|*
name|entry
parameter_list|)
block|{
name|entry
operator|->
name|next
operator|=
name|target
operator|->
name|head
expr_stmt|;
name|target
operator|->
name|head
operator|=
name|entry
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Stack consumer operation for no concurrent producers and single consumer.  */
end_comment

begin_expr_stmt
name|CK_CC_INLINE
specifier|static
expr|struct
name|ck_stack_entry
operator|*
name|ck_stack_pop_npsc
argument_list|(
argument|struct ck_stack *target
argument_list|)
block|{ 	struct
name|ck_stack_entry
operator|*
name|n
block|;
if|if
condition|(
name|target
operator|->
name|head
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|n
operator|=
name|target
operator|->
name|head
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|target
operator|->
name|head
operator|=
name|n
operator|->
name|next
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|n
return|;
end_return

begin_comment
unit|}
comment|/*  * Pop all items off a stack.  */
end_comment

begin_function
unit|CK_CC_INLINE
specifier|static
name|struct
name|ck_stack_entry
modifier|*
name|ck_stack_batch_pop_npsc
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|target
parameter_list|)
block|{
name|struct
name|ck_stack_entry
modifier|*
name|n
decl_stmt|;
name|n
operator|=
name|target
operator|->
name|head
expr_stmt|;
name|target
operator|->
name|head
operator|=
name|NULL
expr_stmt|;
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|/*  * Stack initialization function. Guarantees initialization across processors.  */
end_comment

begin_function
name|CK_CC_INLINE
specifier|static
name|void
name|ck_stack_init
parameter_list|(
name|struct
name|ck_stack
modifier|*
name|stack
parameter_list|)
block|{
name|stack
operator|->
name|head
operator|=
name|NULL
expr_stmt|;
name|stack
operator|->
name|generation
operator|=
name|NULL
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* Defines a container_of functions for */
end_comment

begin_define
define|#
directive|define
name|CK_STACK_CONTAINER
parameter_list|(
name|T
parameter_list|,
name|M
parameter_list|,
name|N
parameter_list|)
value|CK_CC_CONTAINER(ck_stack_entry_t, T, M, N)
end_define

begin_define
define|#
directive|define
name|CK_STACK_ISEMPTY
parameter_list|(
name|m
parameter_list|)
value|((m)->head == NULL)
end_define

begin_define
define|#
directive|define
name|CK_STACK_FIRST
parameter_list|(
name|s
parameter_list|)
value|((s)->head)
end_define

begin_define
define|#
directive|define
name|CK_STACK_NEXT
parameter_list|(
name|m
parameter_list|)
value|((m)->next)
end_define

begin_define
define|#
directive|define
name|CK_STACK_FOREACH
parameter_list|(
name|stack
parameter_list|,
name|entry
parameter_list|)
define|\
value|for ((entry) = CK_STACK_FIRST(stack);			\ 	     (entry) != NULL;					\ 	     (entry) = CK_STACK_NEXT(entry))
end_define

begin_define
define|#
directive|define
name|CK_STACK_FOREACH_SAFE
parameter_list|(
name|stack
parameter_list|,
name|entry
parameter_list|,
name|T
parameter_list|)
define|\
value|for ((entry) = CK_STACK_FIRST(stack);			\ 	     (entry) != NULL&& ((T) = (entry)->next, 1);	\ 	     (entry) = (T))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_STACK_H */
end_comment

end_unit

