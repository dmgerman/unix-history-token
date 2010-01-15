begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test code-completion in the presence of tabs
end_comment

begin_struct
struct|struct
name|Point
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
comment|// RUN: c-index-test -code-completion-at=%s:5:5 %s | FileCheck -check-prefix=CHECK-CC1 %s
comment|// CHECK-CC1: {TypedText x}
comment|// CHECK-CC1: {TypedText y}
end_function

end_unit

