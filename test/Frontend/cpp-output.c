begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -E -o %t -C %s
end_comment

begin_comment
comment|// RUN: grep '^int x; // comment' %t
end_comment

begin_comment
comment|// RUN: grep '^x x' %t
end_comment

begin_comment
comment|// RUN: clang -E -o %t -CC %s
end_comment

begin_comment
comment|// RUN: grep '^int x; // comment' %t
end_comment

begin_comment
comment|// RUN: grep '^x /\* comment \*/ x /\* comment \*/' %t
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// comment
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|foo bar
end_define

begin_define
define|#
directive|define
name|B
value|x
end_define

begin_comment
comment|// comment
end_comment

begin_macro
name|A
argument_list|(
argument|B
argument_list|,
argument|B
argument_list|)
end_macro

end_unit

