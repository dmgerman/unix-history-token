begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- atomic_signal_fence.c -----------------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  *===------------------------------------------------------------------------===  *  * This file implements atomic_signal_fence from C11's stdatomic.h.  *  *===------------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_undef
undef|#
directive|undef
name|atomic_signal_fence
end_undef

begin_function
name|void
name|atomic_signal_fence
parameter_list|(
name|memory_order
name|order
parameter_list|)
block|{
name|__c11_atomic_signal_fence
argument_list|(
name|order
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

