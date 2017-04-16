begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %t.dir
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-output=html -analyzer-checker=core -o %t.dir %s
end_comment

begin_comment
comment|// RUN: ls %t.dir | not grep report
end_comment

begin_comment
comment|// RUN: rm -fR %t.dir
end_comment

begin_comment
comment|// This tests that we do not currently emit HTML diagnostics for reports that
end_comment

begin_comment
comment|// cross file boundaries.
end_comment

begin_include
include|#
directive|include
file|"html-diags-multifile.h"
end_include

begin_define
define|#
directive|define
name|CALL_HAS_BUG
parameter_list|(
name|q
parameter_list|)
value|has_bug(q)
end_define

begin_function
name|void
name|test_call_macro
parameter_list|()
block|{
name|CALL_HAS_BUG
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

