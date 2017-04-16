begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_include
include|#
directive|include
file|"test-include.h"
end_include

begin_define
define|#
directive|define
name|DIVYX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|Y/X
end_define

begin_function
name|void
name|test_01
parameter_list|(
name|int
modifier|*
name|data
parameter_list|)
block|{
name|data
operator|=
literal|0
expr_stmt|;
operator|*
name|data
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer}}
block|}
end_function

begin_function
name|int
name|test_02
parameter_list|()
block|{
name|int
name|res
init|=
name|DIVXY
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
comment|// expected-warning{{Division by zero}}
comment|// expected-warning@-1{{division by zero is undefined}}
return|return
name|res
return|;
block|}
end_function

begin_function
name|int
name|test_03
parameter_list|()
block|{
name|int
name|res
init|=
name|DIVYX
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
comment|// expected-warning{{Division by zero}}
comment|// expected-warning@-1{{division by zero is undefined}}
return|return
name|res
return|;
block|}
end_function

end_unit

