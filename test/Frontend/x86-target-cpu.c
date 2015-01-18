begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure we support the various CPU names.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu nocona -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu core2 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu penryn -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu nehalem -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu westmere -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu sandybridge -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu ivybridge -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu haswell -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu broadwell -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu bonnell -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu silvermont -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu k8 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu opteron -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu athlon64 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu athlon-fx -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu k8-sse3 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu opteron-sse3 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu athlon64-sse3 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu amdfam10 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu barcelona -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu bdver1 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu bdver2 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu bdver3 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu bdver4 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu btver1 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-cpu btver2 -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

