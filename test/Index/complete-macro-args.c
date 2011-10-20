begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO2
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|x
parameter_list|)
value|MACRO2(x)
end_define

begin_function
name|void
name|test
parameter_list|(
name|struct
name|Point
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|x
expr_stmt|;
name|MACRO
argument_list|(
name|p
operator|->
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:12 %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:12:12 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK:      FieldDecl:{ResultType float}{TypedText x} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl:{ResultType float}{TypedText y} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: FieldDecl:{ResultType float}{TypedText z} (35)
end_comment

begin_comment
comment|// CHECK-NEXT: Completion contexts:
end_comment

begin_comment
comment|// CHECK-NEXT: Arrow member access
end_comment

begin_comment
comment|// CHECK-NEXT: Container Kind: StructDecl
end_comment

end_unit

