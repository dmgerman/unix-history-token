begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -fsyntax-only -fdiagnostics-parseable-fixits 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// vim: set binary noeol:
end_comment

begin_comment
comment|// This file intentionally ends without a \n on the last line.  Make sure your
end_comment

begin_comment
comment|// editor doesn't add one. The trailing space is also intentional.
end_comment

begin_comment
comment|// CHECK: :9:8: warning: duplicate 'extern' declaration specifier
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{9:8-9:15}:""
end_comment

begin_extern
extern|extern extern
end_extern

end_unit

