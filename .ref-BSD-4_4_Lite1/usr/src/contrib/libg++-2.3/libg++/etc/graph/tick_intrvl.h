begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"math.h"
end_include

begin_comment
comment|// The resolution of the output device is much less than seven digits.
end_comment

begin_comment
comment|// A_HAIR_MORE is used to ingore the effects of round off error which should
end_comment

begin_comment
comment|// occur in the last few of the 16 digits.
end_comment

begin_define
define|#
directive|define
name|A_HAIR_MORE
value|1.0000001
end_define

begin_comment
comment|// TICK_INTERVAL returns the step size which can be used to put a
end_comment

begin_comment
comment|// specified NO_OF_TICKS beteen the specified UPPER_LIMIT and LOWER_LIMIT.
end_comment

begin_function_decl
name|double
name|tick_interval
parameter_list|(
name|double
name|no_of_ticks
parameter_list|,
name|double
modifier|&
name|lower_limit
parameter_list|,
name|double
modifier|&
name|upper_limit
parameter_list|)
function_decl|;
end_function_decl

end_unit

