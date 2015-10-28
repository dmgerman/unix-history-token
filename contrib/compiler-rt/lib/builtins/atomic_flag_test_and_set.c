begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- atomic_flag_test_and_set.c ------------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  *===------------------------------------------------------------------------===  *  * This file implements atomic_flag_test_and_set from C11's stdatomic.h.  *  *===------------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_undef
undef|#
directive|undef
name|atomic_flag_test_and_set
end_undef

begin_function
name|_Bool
name|atomic_flag_test_and_set
parameter_list|(
specifier|volatile
name|atomic_flag
modifier|*
name|object
parameter_list|)
block|{
return|return
name|__c11_atomic_exchange
argument_list|(
operator|&
operator|(
name|object
operator|)
operator|->
name|_Value
argument_list|,
literal|1
argument_list|,
name|__ATOMIC_SEQ_CST
argument_list|)
return|;
block|}
end_function

end_unit

