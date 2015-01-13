begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  */
end_comment

begin_comment
comment|/* double __floatdidf(di_int a); */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_include
include|#
directive|include
file|"../int_lib.h"
end_include

begin_function
name|double
name|__floatdidf
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|double
operator|)
name|a
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

end_unit

