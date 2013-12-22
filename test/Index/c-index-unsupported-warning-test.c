begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:1:1 -Wunknown-foo-bar-warning -Werror %s
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

end_unit

