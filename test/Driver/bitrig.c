begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target amd64-pc-bitrig %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-C %s
end_comment

begin_comment
comment|// CHECK-LD-C: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-LD-C: ld{{.*}}" {{.*}} "-lc" "-lclang_rt.amd64"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes -target amd64-pc-bitrig %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-CXX-STDLIB %s
end_comment

begin_comment
comment|// CHECK-LD-CXX-STDLIB: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-LD-CXX-STDLIB: ld{{.*}}" {{.*}} "-lc++" "-lc++abi" "-lpthread" "-lm" "-lc" "-lclang_rt.amd64"
end_comment

begin_comment
comment|// RUN: %clangxx -stdlib=libstdc++ -no-canonical-prefixes -target amd64-pc-bitrig %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-CXX %s
end_comment

begin_comment
comment|// CHECK-LD-CXX: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-LD-CXX: ld{{.*}}" {{.*}} "-lstdc++" "-lm" "-lc" "-lclang_rt.amd64"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target amd64-pc-bitrig -pthread %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PTHREAD %s
end_comment

begin_comment
comment|// CHECK-PTHREAD: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-PTHREAD: ld{{.*}}" {{.*}} "{{.*}}crtbegin.o" {{.*}}.o" "-lpthread" "-lc" "-lclang_rt.amd64" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target amd64-pc-bitrig -pg -pthread %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PG-PTHREAD %s
end_comment

begin_comment
comment|// CHECK-PG-PTHREAD: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-PG-PTHREAD: ld{{.*}}" {{.*}} "{{.*}}crtbegin.o" {{.*}}.o" "-lpthread_p" "-lc_p" "-lclang_rt.amd64" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target amd64-pc-bitrig -shared -pg -pthread %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PG-PTHREAD-SHARED %s
end_comment

begin_comment
comment|// CHECK-PG-PTHREAD-SHARED: clang{{.*}}" "-cc1" "-triple" "amd64-pc-bitrig"
end_comment

begin_comment
comment|// CHECK-PG-PTHREAD-SHARED: ld{{.*}}" {{.*}} "{{.*}}crtbeginS.o" {{.*}}.o" "-lpthread" "-lclang_rt.amd64" "{{.*}}crtendS.o"
end_comment

end_unit

