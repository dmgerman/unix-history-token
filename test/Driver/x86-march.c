begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure we support the various CPU architecture names.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=nocona 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=nocona
end_comment

begin_comment
comment|// nocona: "-target-cpu" "nocona"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=core2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=core2
end_comment

begin_comment
comment|// core2: "-target-cpu" "core2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=penryn 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=penryn
end_comment

begin_comment
comment|// penryn: "-target-cpu" "penryn"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=nehalem 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=nehalem
end_comment

begin_comment
comment|// nehalem: "-target-cpu" "nehalem"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=westmere 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=westmere
end_comment

begin_comment
comment|// westmere: "-target-cpu" "westmere"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=sandybridge 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=sandybridge
end_comment

begin_comment
comment|// sandybridge: "-target-cpu" "sandybridge"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=ivybridge 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=ivybridge
end_comment

begin_comment
comment|// ivybridge: "-target-cpu" "ivybridge"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=haswell 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=haswell
end_comment

begin_comment
comment|// haswell: "-target-cpu" "haswell"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=broadwell 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=broadwell
end_comment

begin_comment
comment|// broadwell: "-target-cpu" "broadwell"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=bonnell 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=bonnell
end_comment

begin_comment
comment|// bonnell: "-target-cpu" "bonnell"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=silvermont 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=silvermont
end_comment

begin_comment
comment|// silvermont: "-target-cpu" "silvermont"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=k8 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=k8
end_comment

begin_comment
comment|// k8: "-target-cpu" "k8"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=opteron 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=opteron
end_comment

begin_comment
comment|// opteron: "-target-cpu" "opteron"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=athlon64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=athlon64
end_comment

begin_comment
comment|// athlon64: "-target-cpu" "athlon64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=athlon-fx 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=athlon-fx
end_comment

begin_comment
comment|// athlon-fx: "-target-cpu" "athlon-fx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=k8-sse3 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=k8-sse3
end_comment

begin_comment
comment|// k8-sse3: "-target-cpu" "k8-sse3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=opteron-sse3 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=opteron-sse3
end_comment

begin_comment
comment|// opteron-sse3: "-target-cpu" "opteron-sse3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=athlon64-sse3 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=athlon64-sse3
end_comment

begin_comment
comment|// athlon64-sse3: "-target-cpu" "athlon64-sse3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=amdfam10 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=amdfam10
end_comment

begin_comment
comment|// amdfam10: "-target-cpu" "amdfam10"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=barcelona 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=barcelona
end_comment

begin_comment
comment|// barcelona: "-target-cpu" "barcelona"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=bdver1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=bdver1
end_comment

begin_comment
comment|// bdver1: "-target-cpu" "bdver1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=bdver2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=bdver2
end_comment

begin_comment
comment|// bdver2: "-target-cpu" "bdver2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=bdver3 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=bdver3
end_comment

begin_comment
comment|// bdver3: "-target-cpu" "bdver3"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=bdver4 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=bdver4
end_comment

begin_comment
comment|// bdver4: "-target-cpu" "bdver4"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=btver1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=btver1
end_comment

begin_comment
comment|// btver1: "-target-cpu" "btver1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -c -### %s -march=btver2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=btver2
end_comment

begin_comment
comment|// btver2: "-target-cpu" "btver2"
end_comment

end_unit

