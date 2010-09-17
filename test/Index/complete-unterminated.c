begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|Integer
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* blah */
end_comment

begin_function_decl
name|void
name|f0
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f1
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|char
modifier|*
name|hello
init|=
literal|"Hello, world"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|a
init|=
literal|'a'
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a b
end_define

begin_expr_stmt
name|FOO
argument_list|(
name|int
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:5:1 -pedantic %s 2> %t.err | FileCheck %s
end_comment

begin_comment
comment|// RUN: not grep error %t.err
end_comment

begin_comment
comment|// CHECK: {TypedText Integer}
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:8:6 -pedantic %s 2> %t.err
end_comment

begin_comment
comment|// RUN: not grep error %t.err
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:10:28 -pedantic %s 2> %t.err
end_comment

begin_comment
comment|// RUN: not grep unterminated %t.err
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:17 -pedantic %s 2> %t.err
end_comment

begin_comment
comment|// RUN: not grep unterminated %t.err
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:18:10 -pedantic %s 2> %t.err
end_comment

begin_comment
comment|// RUN: not grep unterminated %t.err
end_comment

end_unit

