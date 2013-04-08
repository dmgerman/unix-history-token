begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang -E -C -P %s | FileCheck --strict-whitespace %s    PR2741    comment */
end_comment

begin_macro
name|y
end_macro

begin_comment
comment|// CHECK: {{^}}   comment */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}y{{$}}
end_comment

end_unit

