begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -Wnewline-eof -verify %s
end_comment

begin_comment
comment|// rdar://9133072
end_comment

begin_comment
comment|// The following line isn't terminated, don't fix it.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning{{No newline at end of file}}
end_comment

end_unit

