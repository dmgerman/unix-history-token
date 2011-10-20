begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -I%S/Before -index-header-map -I%S/Index -I%S/After %s -### 2>> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_comment
comment|// CHECK: {{-I.*Before.*-index-header-map.*-I.*Index.*-I.*After}}
end_comment

end_unit

