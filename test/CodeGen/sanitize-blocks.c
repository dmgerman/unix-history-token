begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsanitize-trap=returns-nonnull-attribute -fsanitize=returns-nonnull-attribute -emit-llvm %s -o - -triple x86_64-apple-darwin10 -fblocks | FileCheck %s
end_comment

begin_comment
comment|// Awkward interactions of sanitizers with blocks.
end_comment

begin_comment
comment|// rdar://22071955
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|TheString
init|=
literal|"Hello, world!"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
function_decl|(
modifier|^
name|getString
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
end_function_decl

begin_return
return|return
name|TheString
return|;
end_return

begin_comment
unit|};
comment|// CHECK-LABEL: define internal i8* @getString_block_invoke
end_comment

begin_comment
comment|// TODO: Actually support returns_nonnull on blocks.
end_comment

end_unit

