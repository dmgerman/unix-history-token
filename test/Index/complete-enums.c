begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_enum
enum|enum
block|{
name|Red
init|=
literal|17
block|,
name|Green
block|,
name|Blue
block|}
enum|;
end_enum

begin_function
name|void
name|f
parameter_list|()
block|{    }
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:1 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: EnumConstantDecl:{ResultType enum<anonymous>}{TypedText Red}
end_comment

end_unit

