begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -o %t1 %s
end_comment

begin_comment
comment|// RUN: %t1 2>&1 | FileCheck --check-prefix=NCFI %s
end_comment

begin_comment
comment|// RUN: %clang_cfi -o %t2 %s
end_comment

begin_comment
comment|// RUN: %expect_crash %t2 2>&1 | FileCheck --check-prefix=CFI %s
end_comment

begin_comment
comment|// RUN: %clang_cfi_diag -g -o %t3 %s
end_comment

begin_comment
comment|// RUN: %t3 2>&1 | FileCheck --check-prefix=CFI-DIAG %s
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CFI: 1
comment|// NCFI: 1
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"1\n"
argument_list|)
expr_stmt|;
comment|// CFI-DIAG: runtime error: control flow integrity check for type 'void (int)' failed during indirect function call
comment|// CFI-DIAG: f defined here
operator|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
name|f
operator|)
operator|(
literal|42
operator|)
expr_stmt|;
comment|// UB here
comment|// CFI-NOT: 2
comment|// NCFI: 2
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"2\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

