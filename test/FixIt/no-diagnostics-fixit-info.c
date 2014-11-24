begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s 2>&1 | FileCheck -check-prefix=WITH-FIXIT %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fno-diagnostics-fixit-info %s 2>&1 | FileCheck -check-prefix=WITHOUT-FIXIT %s
end_comment

begin_struct
struct|struct
name|Foo
block|{
name|int
name|x
decl_stmt|;
block|}
comment|// WITH-FIXIT: error: expected ';' after struct
comment|// WITH-FIXIT-NEXT: }
comment|// WITH-FIXIT-NEXT:  ^
comment|// WITH-FIXIT-NEXT:  ;
comment|// WITHOUT-FIXIT: error: expected ';' after struct
comment|// WITHOUT-FIXIT-NEXT: }
comment|// WITHOUT-FIXIT-NEXT: ^
comment|// WITHOUT-FIXIT-NOT: ;
end_struct

end_unit

