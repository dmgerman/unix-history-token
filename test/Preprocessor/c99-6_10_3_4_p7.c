begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Example from C99 6.10.3.4p7
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|t
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|x ## y ## z
end_define

begin_decl_stmt
name|int
name|j
index|[]
init|=
block|{
name|t
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
block|,
name|t
argument_list|(,
literal|4
argument_list|,
literal|5
argument_list|)
block|,
name|t
argument_list|(
literal|6
argument_list|,,
literal|7
argument_list|)
block|,
name|t
argument_list|(
literal|8
argument_list|,
literal|9
argument_list|,)
block|,
name|t
argument_list|(
literal|10
argument_list|,,)
block|,
name|t
argument_list|(,
literal|11
argument_list|,)
block|,
name|t
argument_list|(,,
literal|12
argument_list|)
block|,
name|t
argument_list|(
argument_list|,
argument_list|,)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int j[] = { 123, 45, 67, 89,
end_comment

begin_comment
comment|// CHECK: 10, 11, 12, };
end_comment

end_unit

