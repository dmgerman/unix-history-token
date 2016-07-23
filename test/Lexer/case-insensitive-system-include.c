begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: case-insensitive-filesystem
end_comment

begin_comment
comment|// RUN: mkdir -p %T/asystempath
end_comment

begin_comment
comment|// RUN: cp %S/Inputs/case-insensitive-include.h %T/asystempath/
end_comment

begin_comment
comment|// RUN: cd %T
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -include %s -isystem %T/asystempath -verify -Wnonportable-system-include-path
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s -include %s -isystem %T/asystempath -Wnonportable-system-include-path 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"CASE-INSENSITIVE-INCLUDE.H"
end_include

begin_comment
comment|// expected-warning {{non-portable path}}
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-1]]:10-[[@LINE-1]]:38}:"\"case-insensitive-include.h\""
end_comment

end_unit

