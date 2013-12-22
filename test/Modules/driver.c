begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fmodules %s -### 2>&1 | FileCheck -check-prefix CHECK-NO_MODULE_CACHE %s
end_comment

begin_comment
comment|// RUN: %clang -fmodules -fmodules-cache-path=blarg %s -### 2>&1 | FileCheck -check-prefix CHECK-WITH_MODULE_CACHE %s
end_comment

begin_comment
comment|// CHECK-NO_MODULE_CACHE: {{clang.*"-fmodules-cache-path=.*ModuleCache"}}
end_comment

begin_comment
comment|// CHECK-WITH_MODULE_CACHE: {{clang.*"-fmodules-cache-path=blarg"}}
end_comment

end_unit

