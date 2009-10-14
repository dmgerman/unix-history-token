begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -P -E -fms-extensions %s | sed '/^#.\+/d' | tr -d '\n'> %t&&
end_comment

begin_comment
comment|// RUN: grep '^int foo;int bar;int baz;$' %t | count 1
end_comment

begin_comment
comment|// This horrible stuff should preprocess into (other than whitespace):
end_comment

begin_comment
comment|//   int foo;
end_comment

begin_comment
comment|//   int bar;
end_comment

begin_comment
comment|//   int baz;
end_comment

begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|comment
value|/##/  dead tokens live here
end_define

begin_decl_stmt
name|comment
name|This
name|is
name|stupidity
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nested
parameter_list|(
name|x
parameter_list|)
value|int x comment cute little dead tokens...
end_define

begin_macro
name|nested
argument_list|(
argument|baz
argument_list|)
end_macro

begin_decl_stmt
name|rise
name|of
name|the
name|dead
name|tokens
decl_stmt|;
end_decl_stmt

end_unit

