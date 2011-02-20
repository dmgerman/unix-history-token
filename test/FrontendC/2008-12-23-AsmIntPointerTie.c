begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -O1 -o -
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_function
name|int
name|test
parameter_list|(
name|void
modifier|*
name|b
parameter_list|)
block|{
name|intptr_t
name|a
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("%0 %1 " : "=r" (a): "0" (b));
return|return
name|a
return|;
block|}
end_function

end_unit

