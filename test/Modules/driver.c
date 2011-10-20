begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -### 2>&1 | FileCheck -check-prefix NO_MODULE_CACHE %s
end_comment

begin_comment
comment|// RUN: %clang -fmodule-cache-path blarg %s -### 2>&1 | FileCheck -check-prefix WITH_MODULE_CACHE %s
end_comment

begin_comment
comment|// CHECK-NO_MODULE_CACHE: {{clang.*"-fmodule-cache-path"}}
end_comment

begin_comment
comment|// CHECK-WITH_MODULE_CACHE: {{clang.*"-fmodule-cache-path" "blarg"}}
end_comment

end_unit

