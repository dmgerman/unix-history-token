begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | grep 'foo{a, b, c, d, e}'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep 'foo2{d, C, B}'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep 'foo2{d,e, C, B}'
end_comment

begin_define
define|#
directive|define
name|va1
parameter_list|(
modifier|...
parameter_list|)
value|foo{a, __VA_ARGS__, e}
end_define

begin_macro
name|va1
argument_list|(
argument|b
argument_list|,
argument|c
argument_list|,
argument|d
argument_list|)
end_macro

begin_define
define|#
directive|define
name|va2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
modifier|...
parameter_list|)
value|foo2{__VA_ARGS__, b, a}
end_define

begin_macro
name|va2
argument_list|(
argument|B
argument_list|,
argument|C
argument_list|,
argument|d
argument_list|)
end_macro

begin_macro
name|va2
argument_list|(
argument|B
argument_list|,
argument|C
argument_list|,
argument|d
argument_list|,
argument|e
argument_list|)
end_macro

end_unit

