begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config unix.mallo:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config uni:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config uni.:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config ..:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config unix.:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config unrelated:Optimistic=true 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc -analyzer-config unix.Malloc:Optimistic=true
end_comment

begin_comment
comment|// Just to test clang is working.
end_comment

begin_empty
empty|# foo
end_empty

begin_comment
comment|// CHECK: error:
end_comment

end_unit

