begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// (sanity check)
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-output=plist-html -o %t.dir/index.plist %s
end_comment

begin_comment
comment|// RUN: ls %t.dir | grep '\.html' | count 1
end_comment

begin_comment
comment|// RUN: grep '\.html' %t.dir/index.plist | count 1
end_comment

begin_comment
comment|// This tests two things: that the two calls to null_deref below are coalesced
end_comment

begin_comment
comment|// into a single bug by both the plist and HTML diagnostics, and that the plist
end_comment

begin_comment
comment|// diagnostics have a reference to the HTML diagnostics. (It would be nice to
end_comment

begin_comment
comment|// check more carefully that the two actually match, but that's hard to write
end_comment

begin_comment
comment|// in a lit RUN line.)
end_comment

begin_define
define|#
directive|define
name|CALL_FN
parameter_list|(
name|a
parameter_list|)
value|null_deref(a)
end_define

begin_function
name|void
name|null_deref
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
return|return;
operator|*
name|a
operator|=
literal|1
expr_stmt|;
comment|// expected-warning{{null}}
block|}
end_function

begin_function
name|void
name|test1
parameter_list|()
block|{
name|CALL_FN
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|CALL_FN
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

