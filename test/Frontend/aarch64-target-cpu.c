begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Ensure we support the various CPU names.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cortex-a35 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cortex-a53 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cortex-a57 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cortex-a72 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cortex-a73 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu cyclone -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu exynos-m1 -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu generic -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu kryo -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -target-cpu thunderx2t99 -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

