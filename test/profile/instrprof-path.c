begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_pgogen -O2 -o %t.0 %s
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.d1 -O2 -o %t.1 %s
end_comment

begin_comment
comment|// RUN: %clang_pgogen=%t.d1/%t.d2 -O2 -o %t.2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %run %t.0  ""
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.d1/default.profraw %run %t.0  %t.d1/
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.d1/%t.d2/default.profraw %run %t.0 %t.d1/%t.d2/
end_comment

begin_comment
comment|// RUN: %run %t.1 %t.d1/
end_comment

begin_comment
comment|// RUN: %run %t.2 %t.d1/%t.d2/
end_comment

begin_comment
comment|// RUN: %run %t.2 %t.d1/%t.d2/ %t.d1/%t.d2/%t.d3/blah.profraw %t.d1/%t.d2/%t.d3/
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function_decl
specifier|const
name|char
modifier|*
name|__llvm_profile_get_path_prefix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_set_filanem
parameter_list|(
specifier|const
name|char
modifier|*
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
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|expected
decl_stmt|;
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
return|return
literal|1
return|;
name|expected
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|prefix
operator|=
name|__llvm_profile_get_path_prefix
argument_list|()
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|prefix
argument_list|,
name|expected
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|argc
operator|==
literal|4
condition|)
block|{
name|__llvm_profile_set_filename
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|prefix
operator|=
name|__llvm_profile_get_path_prefix
argument_list|()
expr_stmt|;
name|expected
operator|=
name|argv
index|[
literal|3
index|]
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|prefix
argument_list|,
name|expected
argument_list|)
condition|)
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

