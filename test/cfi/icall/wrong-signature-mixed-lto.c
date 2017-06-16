begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the checking is done with the actual type of f() even when the
end_comment

begin_comment
comment|// calling module has an incorrect declaration. Test a mix of lto types.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -flto below overrides -flto=thin in %clang_cfi
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_A -c -o %t1_a.o
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_B -c -o %t1_b.o -flto
end_comment

begin_comment
comment|// RUN: %clang_cfi %t1_a.o %t1_b.o -o %t1
end_comment

begin_comment
comment|// RUN: %expect_crash %t1 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_A -c -o %t2_a.o -flto
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_B -c -o %t2_b.o
end_comment

begin_comment
comment|// RUN: %clang_cfi %t2_a.o %t2_b.o -o %t2
end_comment

begin_comment
comment|// RUN: %expect_crash %t2 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_A -c -o %t3_a.o
end_comment

begin_comment
comment|// RUN: %clang_cfi %s -DMODULE_B -c -o %t3_b.o
end_comment

begin_comment
comment|// RUN: %clang_cfi %t3_a.o %t3_b.o -o %t3
end_comment

begin_comment
comment|// RUN: %expect_crash %t3 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: thinlto
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MODULE_B
argument_list|)
end_if

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
literal|42
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MODULE_A
argument_list|)
end_elif

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CFI: 1
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"1\n"
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|*
specifier|volatile
name|p
argument_list|)
argument_list|()
operator|=
operator|&
name|f
expr_stmt|;
name|p
argument_list|()
expr_stmt|;
comment|// CFI-NOT: 2
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"2\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

