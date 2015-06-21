begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -I%S/Inputs/invalidate-identifiers -emit-llvm-only %s
end_comment

begin_include
include|#
directive|include
file|"b.h"
end_include

end_unit

