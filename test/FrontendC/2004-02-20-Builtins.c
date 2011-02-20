begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O3 -xc %s -S -o - | not grep builtin
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|void
name|zsqrtxxx
parameter_list|(
name|float
name|num
parameter_list|)
block|{
name|num
operator|=
name|sqrt
argument_list|(
name|num
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

