begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST3
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST4
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST5
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST6
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST7
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST8
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -DTEST9 -ffreestanding
end_comment

begin_if
if|#
directive|if
name|TEST1
end_if

begin_decl_stmt
name|int
decl|main
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{variable named 'main' with external linkage has undefined behavior}}
end_comment

begin_elif
elif|#
directive|elif
name|TEST2
end_elif

begin_decl_stmt
specifier|extern
name|int
decl|main
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{variable named 'main' with external linkage has undefined behavior}}
end_comment

begin_elif
elif|#
directive|elif
name|TEST3
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|x
parameter_list|()
block|{
specifier|static
name|int
decl|main
decl_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST4
end_elif

begin_function
name|void
name|x
parameter_list|()
block|{
specifier|extern
name|int
decl|main
decl_stmt|;
comment|// expected-warning{{variable named 'main' with external linkage has undefined behavior}}
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST5
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|x
parameter_list|()
block|{
name|int
decl|main
decl_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST6
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
specifier|static
name|int
decl|main
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|TEST7
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|x
parameter_list|()
block|{
specifier|auto
name|int
decl|main
decl_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST8
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|x
parameter_list|()
block|{
specifier|register
name|int
decl|main
decl_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST9
end_elif

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
name|int
decl|main
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown Test
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

