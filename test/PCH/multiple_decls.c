begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -include %S/multiple_decls.h -fsyntax-only -ast-print -o - %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t %S/multiple_decls.h
end_comment

begin_comment
comment|// RUN: clang-cc -include-pch %t -fsyntax-only -ast-print -o - %s
end_comment

begin_function
name|void
name|f0
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|wide
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|wide
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|narrow
name|n
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|narrow
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

