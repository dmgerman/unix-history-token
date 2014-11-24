begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c-header -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -emit-pch -I %S/Inputs/Headers -o %t/use_LibA.pch %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -I %S/Inputs/Headers -verify-pch %t/use_LibA.pch
end_comment

begin_comment
comment|// RUN: rm -f %t/modules-cache/LibA.pcm
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodules -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -I %S/Inputs/Headers -verify-pch %t/use_LibA.pch 2>&1 | FileCheck -check-prefix=VERIFY %s
end_comment

begin_comment
comment|// RUN: not c-index-test -test-load-source all -x c -fmodules -Xclang -fdisable-module-hash -fmodules-cache-path=%t/modules-cache -I %S/Inputs/Headers -include-pch %t/use_LibA.pch %s 2>&1 | FileCheck -check-prefix=INDEX %s
end_comment

begin_comment
comment|// VERIFY: fatal error: malformed or corrupted AST file: 'Unable to load module
end_comment

begin_comment
comment|// INDEX: {{^}}Failure: AST deserialization error occurred{{$}}
end_comment

end_unit

