begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -fR %T/dir
end_comment

begin_comment
comment|// RUN: mkdir %T/dir
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-output=html -analyzer-checker=core -o %T/dir %s
end_comment

begin_comment
comment|// RUN: ls %T/dir | grep report
end_comment

begin_comment
comment|// PR16547: Test relative paths
end_comment

begin_comment
comment|// RUN: cd %T/dir
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-output=html -analyzer-checker=core -o testrelative %s
end_comment

begin_comment
comment|// RUN: ls %T/dir/testrelative | grep report
end_comment

begin_comment
comment|// Currently this test mainly checks that the HTML diagnostics doesn't crash
end_comment

begin_comment
comment|// when handling macros will calls with macros.  We should actually validate
end_comment

begin_comment
comment|// the output, but that requires being able to match against a specifically
end_comment

begin_comment
comment|// generate HTML file.
end_comment

begin_define
define|#
directive|define
name|DEREF
parameter_list|(
name|p
parameter_list|)
value|*p = 0xDEADBEEF
end_define

begin_function
name|void
name|has_bug
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|DEREF
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

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

