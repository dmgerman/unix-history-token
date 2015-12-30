begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Due to ln -sf:
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// RUN: mkdir -p %t.real
end_comment

begin_comment
comment|// RUN: cd %t.real
end_comment

begin_comment
comment|// RUN: ln -sf %clang test-clang
end_comment

begin_comment
comment|// RUN: cd ..
end_comment

begin_comment
comment|// RUN: ln -sf %t.real %t.fake
end_comment

begin_comment
comment|// RUN: cd %t.fake
end_comment

begin_comment
comment|// RUN: ./test-clang -v -S %s 2>&1 | FileCheck --check-prefix=CANONICAL %s
end_comment

begin_comment
comment|// RUN: ./test-clang -v -S %s -no-canonical-prefixes 2>&1 | FileCheck --check-prefix=NON-CANONICAL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This should really be '.real'.
end_comment

begin_comment
comment|// CANONICAL: InstalledDir: {{.*}}.fake
end_comment

begin_comment
comment|// CANONICAL: {{[/|\\]*}}clang{{.*}}" -cc1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NON-CANONICAL: InstalledDir: .{{$}}
end_comment

begin_comment
comment|// NON-CANONICAL: test-clang" -cc1
end_comment

end_unit

