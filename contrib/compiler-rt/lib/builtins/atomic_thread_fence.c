begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- atomic_thread_fence.c -----------------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  *===------------------------------------------------------------------------===  *  * This file implements atomic_thread_fence from C11's stdatomic.h.  *  *===------------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__has_include
end_ifndef

begin_define
define|#
directive|define
name|__has_include
parameter_list|(
name|inc
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|stdatomic
operator|.
name|h
operator|>
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_undef
undef|#
directive|undef
name|atomic_thread_fence
end_undef

begin_function
name|void
name|atomic_thread_fence
parameter_list|(
name|memory_order
name|order
parameter_list|)
block|{
name|__c11_atomic_thread_fence
argument_list|(
name|order
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

