begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|const
name|char
modifier|*
name|func
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MORE
value|__FILE__
end_define

begin_define
define|#
directive|define
name|M
parameter_list|(
name|x
parameter_list|)
value|"1"#x
end_define

begin_define
define|#
directive|define
name|N
parameter_list|(
name|x
parameter_list|)
value|func("2"#x MORE)
end_define

begin_function_decl
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|()
block|{
name|foo
argument_list|(
name|M
argument_list|(
name|x
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|foo
argument_list|(
name|N
argument_list|(
name|x
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:11 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:12:11 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Natural language
end_comment

end_unit

