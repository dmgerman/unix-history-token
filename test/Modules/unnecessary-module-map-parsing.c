begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This checks that we are not parsing module maps if modules are not enabled.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodules -I %S/Inputs/unnecessary-module-map-parsing -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %S/Inputs/unnecessary-module-map-parsing -fsyntax-only %s
end_comment

begin_comment
comment|// CHECK: error: expected umbrella, header, submodule, or module export
end_comment

begin_include
include|#
directive|include
file|"a1.h"
end_include

end_unit

