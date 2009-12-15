begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fmessage-length 72 %s 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: clang-cc -fmessage-length 1 %s
end_comment

begin_comment
comment|// Hack so we can check things better, force the file name and line.
end_comment

begin_empty
empty|# 1 "FILE" 1
end_empty

begin_comment
comment|/* It's tough to verify the results of this test mechanically, since    the length of the filename (and, therefore, how the word-wrapping    behaves) changes depending on where the test-suite resides in the    file system. */
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|,
name|char
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|fp1
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|,
name|short
parameter_list|,
name|float
parameter_list|)
init|=
name|f
function_decl|;
name|int
function_decl|(
modifier|*
name|fp2
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|,
name|short
parameter_list|,
name|float
parameter_list|)
init|=
name|f
function_decl|;
block|}
end_function

begin_function_decl
name|void
name|a_func_to_call
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|a_very_long_line
parameter_list|(
name|int
modifier|*
name|ip
parameter_list|,
name|float
modifier|*
name|FloatPointer
parameter_list|)
block|{
for|for
control|(
name|int
name|ALongIndexName
init|=
literal|0
init|;
name|ALongIndexName
operator|<
literal|100
condition|;
name|ALongIndexName
operator|++
control|)
if|if
condition|(
name|ip
index|[
name|ALongIndexName
index|]
operator|==
literal|17
condition|)
name|a_func_to_call
argument_list|(
name|ip
operator|==
name|FloatPointer
argument_list|,
name|ip
index|[
name|ALongIndexName
index|]
argument_list|,
name|FloatPointer
index|[
name|ALongIndexName
index|]
argument_list|)
expr_stmt|;
name|int
name|array0
index|[]
init|=
block|{
index|[
literal|3
index|]
literal|3
block|,
literal|5
block|,
literal|7
block|,
literal|4
block|,
literal|2
block|,
literal|7
block|,
literal|6
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|12
block|,
literal|345
block|,
literal|14
block|,
literal|345
block|,
literal|789
block|,
literal|234
block|,
literal|678
block|,
literal|345
block|,
literal|123
block|,
literal|765
block|,
literal|234
block|}
decl_stmt|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|STDC
name|CX_LIMITED_RANGE
end_pragma

begin_comment
comment|// some long comment text and a brace, eh {}
end_comment

begin_comment
comment|// CHECK: FILE:23:78
end_comment

begin_comment
comment|// CHECK: {{^  ...// some long comment text and a brace, eh {} }}
end_comment

end_unit

