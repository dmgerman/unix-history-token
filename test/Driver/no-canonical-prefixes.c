begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// RUN: mkdir -p %t
end_comment

begin_comment
comment|// RUN: cd %t
end_comment

begin_comment
comment|// RUN: ln -sf %clang test-clang
end_comment

begin_comment
comment|// RUN: ./test-clang -v -S %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: ./test-clang -v -S %s -no-canonical-prefixes 2>&1 | FileCheck --check-prefix=NCP %s
end_comment

begin_comment
comment|// CHECK: /clang{{.*}}" -cc1
end_comment

begin_comment
comment|// NCP: test-clang" -cc1
end_comment

end_unit

