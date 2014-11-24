begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -x c++ -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -x c++ -std=c++11 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -x objective-c -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -x objective-c++ -std=c++11 -verify %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|EXTERN_C
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN_C
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXTERN_C
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|Constant
init|=
literal|0
block|}
name|TestEnum
typedef|;
end_typedef

begin_comment
comment|// Note that in C, the type of 'Constant' is 'int'. In C++ it is 'TestEnum'.
end_comment

begin_comment
comment|// This is why we don't check for that in the expected output.
end_comment

begin_function
name|void
name|test
parameter_list|(
name|TestEnum
name|input
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%d"
argument_list|,
name|input
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%d"
argument_list|,
name|Constant
argument_list|)
expr_stmt|;
comment|// no-warning
name|printf
argument_list|(
literal|"%lld"
argument_list|,
name|input
argument_list|)
expr_stmt|;
comment|// expected-warning-re{{format specifies type 'long long' but the argument has underlying type '{{(unsigned)?}} int'}}
name|printf
argument_list|(
literal|"%lld"
argument_list|,
name|Constant
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'long long'}}
block|}
end_function

begin_typedef
typedef|typedef
enum|enum
block|{
name|LongConstant
init|=
operator|~
literal|0UL
block|}
name|LongEnum
typedef|;
end_typedef

begin_function
name|void
name|testLong
parameter_list|(
name|LongEnum
name|input
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%u"
argument_list|,
name|input
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned int' but the argument has underlying type}}
name|printf
argument_list|(
literal|"%u"
argument_list|,
name|LongConstant
argument_list|)
expr_stmt|;
comment|// expected-warning{{format specifies type 'unsigned int'}}
name|printf
argument_list|(
literal|"%lu"
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%lu"
argument_list|,
name|LongConstant
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

