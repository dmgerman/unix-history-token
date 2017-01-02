begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-const-variable -x c-header -ffreestanding -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-const-variable -x c++-header -ffreestanding -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|unused
index|[]
init|=
block|{
literal|2
block|,
literal|3
block|,
literal|5
block|,
literal|7
block|,
literal|11
block|,
literal|13
block|}
decl_stmt|;
end_decl_stmt

end_unit

