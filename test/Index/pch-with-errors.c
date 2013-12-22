begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_include
include|#
directive|include
file|"blahblah.h"
end_include

begin_function_decl
name|void
name|erroneous
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|erroneous
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|bar
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|zed
block|{
name|bar
name|g
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|baz
block|{
name|zed
name|h
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|errparm
parameter_list|(
name|zed
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|S
block|{
block|{
empty_stmt|;
else|#
directive|else
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|erroneous
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: c-index-test -write-pch %t.h.pch %s -Xclang -detailed-preprocessing-record
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source local %s -include %t.h -Xclang -detailed-preprocessing-record | FileCheck -check-prefix=CHECK-PARSE %s
end_comment

begin_comment
comment|// RUN: c-index-test -index-file %s -include %t.h -Xclang -detailed-preprocessing-record | FileCheck -check-prefix=CHECK-INDEX %s
end_comment

begin_comment
comment|// CHECK-PARSE: pch-with-errors.c:{{.*}}:6: FunctionDecl=foo
end_comment

begin_comment
comment|// CHECK-PARSE: pch-with-errors.c:{{.*}}:3: CallExpr=erroneous
end_comment

begin_comment
comment|// CHECK-INDEX: [indexDeclaration]: kind: function | name: foo
end_comment

begin_comment
comment|// CHECK-INDEX: [indexEntityReference]: kind: function | name: erroneous
end_comment

begin_comment
comment|// RUN: not %clang -fsyntax-only %s -include %t.h 2>&1 | FileCheck -check-prefix=PCH-ERR %s
end_comment

begin_comment
comment|// PCH-ERR: error: PCH file contains compiler errors
end_comment

begin_comment
comment|// RUN: not c-index-test -write-pch %t.pch foobar.c 2>&1 | FileCheck -check-prefix=NONEXISTENT %s
end_comment

begin_comment
comment|// NONEXISTENT: Unable to load translation unit
end_comment

end_unit

