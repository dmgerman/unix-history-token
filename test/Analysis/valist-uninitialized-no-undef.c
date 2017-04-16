begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-pc-linux-gnu -analyzer-checker=core,valist.Uninitialized,valist.CopyToSelf -analyzer-output=text -analyzer-store=region -verify %s
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator-for-valist.h"
end_include

begin_comment
comment|// This is called in call_inlined_uses_arg(),
end_comment

begin_comment
comment|// and the warning is generated during the analysis of call_inlined_uses_arg().
end_comment

begin_function
name|void
name|inlined_uses_arg
parameter_list|(
name|va_list
name|arg
parameter_list|)
block|{
operator|(
name|void
operator|)
name|va_arg
argument_list|(
name|arg
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|// expected-warning{{va_arg() is called on an uninitialized va_list}}
comment|// expected-note@-1{{va_arg() is called on an uninitialized va_list}}
block|}
end_function

begin_function
name|void
name|call_inlined_uses_arg
parameter_list|(
name|int
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|inlined_uses_arg
argument_list|(
name|va
argument_list|)
expr_stmt|;
comment|// expected-note{{Calling 'inlined_uses_arg'}}
block|}
end_function

begin_function
name|void
name|f6
parameter_list|(
name|va_list
modifier|*
name|fst
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_start
argument_list|(
operator|*
name|fst
argument_list|,
name|fst
argument_list|)
expr_stmt|;
comment|// FIXME: There should be no warning for this.
operator|(
name|void
operator|)
name|va_arg
argument_list|(
operator|*
name|fst
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|// expected-warning{{va_arg() is called on an uninitialized va_list}}
comment|// expected-note@-1{{va_arg() is called on an uninitialized va_list}}
name|va_end
argument_list|(
operator|*
name|fst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|call_vprintf_bad
parameter_list|(
name|int
name|isstring
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|vprintf
argument_list|(
name|isstring
condition|?
literal|"%s"
else|:
literal|"%d"
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{Function 'vprintf' is called with an uninitialized va_list argument}}
comment|// expected-note@-1{{Function 'vprintf' is called with an uninitialized va_list argument}}
comment|// expected-note@-2{{Assuming 'isstring' is 0}}
comment|// expected-note@-3{{'?' condition is false}}
block|}
end_function

begin_function
name|void
name|call_vsprintf_bad
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
comment|// expected-note{{Initialized va_list}}
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
comment|// expected-note{{Ended va_list}}
name|vsprintf
argument_list|(
name|buffer
argument_list|,
literal|"%s %d %d %lf %03d"
argument_list|,
name|va
argument_list|)
expr_stmt|;
comment|// expected-warning{{Function 'vsprintf' is called with an uninitialized va_list argument}}
comment|// expected-note@-1{{Function 'vsprintf' is called with an uninitialized va_list argument}}
block|}
end_function

end_unit

