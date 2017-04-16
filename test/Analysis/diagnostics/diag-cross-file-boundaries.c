begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=html -o PR12421.html %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Test for PR12421
end_comment

begin_include
include|#
directive|include
file|"diag-cross-file-boundaries.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: warning: Path diagnostic report is not generated.
end_comment

end_unit

