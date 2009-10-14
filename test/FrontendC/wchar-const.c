begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep {constant \\\[18 x} | grep { 84, }
end_comment

begin_comment
comment|// This should pass for any endianness combination of host and target.
end_comment

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|foo
argument_list|(
literal|L"This is some text"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

