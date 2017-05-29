begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -index-file %s -target armv7-windows-gnu -fdeclspec 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|__declspec
parameter_list|(
name|dllexport
parameter_list|)
function|export_function
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: [indexDeclaration]: kind: function | name: export_function | {{.*}} | lang: C
end_comment

begin_comment
comment|// CHECK:<attribute>: attribute(dllexport)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|export_gnu_attribute
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK: [indexDeclaration]: kind: function | name: export_gnu_attribute | {{.*}} | lang: C
end_comment

begin_comment
comment|// CHECK:<attribute>: attribute(dllexport)
end_comment

begin_function_decl
name|void
name|__declspec
parameter_list|(
name|dllimport
parameter_list|)
function_decl|import_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: [indexDeclaration]: kind: function | name: import_function | {{.*}} | lang: C
end_comment

begin_comment
comment|// CHECK:<attribute>: attribute(dllimport)
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|import_gnu_attribute
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: [indexDeclaration]: kind: function | name: import_gnu_attribute | {{.*}} | lang: C
end_comment

begin_comment
comment|// CHECK:<attribute>: attribute(dllimport)
end_comment

end_unit

