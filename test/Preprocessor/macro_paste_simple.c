begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|FOO
value|bar ## baz ## 123
end_define

begin_comment
comment|// CHECK: A: barbaz123
end_comment

begin_label
name|A
label|:
end_label

begin_decl_stmt
name|FOO
comment|// PR9981
define|#
directive|define
name|M1
parameter_list|(
name|A
parameter_list|)
value|A
define|#
directive|define
name|M2
parameter_list|(
name|X
parameter_list|)
value|X
name|B
range|:
name|M1
argument_list|(
argument|M2(##)
argument_list|)
end_decl_stmt

begin_comment
comment|// CHECK: B: ##
end_comment

end_unit

