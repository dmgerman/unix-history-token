begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -fsyntax-only -Wunused-parameter %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -fsyntax-only -Wunused %s 2>&1 | FileCheck -check-prefix=CHECK-unused %s
end_comment

begin_decl_stmt
name|int
name|f0
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|z
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|x
return|;
block|}
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
operator|(
name|void
operator|)
lambda|^
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|z
name|__attribute__
lambda|(
parameter_list|(
name|unused
parameter_list|)
block|)
end_function

begin_block
unit|)
block|{
return|return
name|x
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// Used when testing '-Wunused' to see that we only emit one diagnostic, and no
end_comment

begin_comment
comment|// warnings for the above cases.
end_comment

begin_function
unit|static
name|void
name|achor
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: 5:12: warning: unused parameter 'y'
end_comment

begin_comment
comment|// CHECK: 12:15: warning: unused parameter 'y'
end_comment

begin_comment
comment|// CHECK-unused: 1 warning generated
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -fsyntax-only -Weverything %s 2>&1 | FileCheck -check-prefix=CHECK-everything %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fblocks -fsyntax-only -Weverything -Werror %s 2>&1 | FileCheck -check-prefix=CHECK-everything-error %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -fsyntax-only -Weverything -Wno-unused %s 2>&1 | FileCheck -check-prefix=CHECK-everything-no-unused %s
end_comment

begin_comment
comment|// CHECK-everything: 6 warnings generated
end_comment

begin_comment
comment|// CHECK-everything-error: 5 errors generated
end_comment

begin_comment
comment|// CHECK-everything-no-unused: 5 warnings generated
end_comment

end_unit

