begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(annotate(
literal|"foo"
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|foo
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|a
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
block|{
name|__attribute__
argument_list|(
argument|(annotate(
literal|"bar"
argument|))
argument_list|)
specifier|static
name|char
name|bar
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @llvm.global.annotations = appending global [2 x %0]
end_comment

end_unit

