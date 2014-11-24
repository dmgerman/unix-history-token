begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: not %clang -Wall -fsyntax-only %s --serialize-diagnostics %t.dia> /dev/null 2>&1
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t.dia 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %S/Inputs/serialized-diags-stable.dia 2>&1 | FileCheck %s
end_comment

begin_function
name|int
name|foo
parameter_list|()
block|{
comment|// CHECK: serialized-diags-stable.c:[[@LINE+2]]:1: warning: control reaches end of non-void function [-Wreturn-type] [Semantic Issue]
comment|// CHECK-NEXT: Number FIXITs = 0
block|}
end_function

begin_comment
comment|// CHECK: serialized-diags-stable.c:[[@LINE+5]]:13: error: redefinition of 'bar' as different kind of symbol [] [Semantic Issue]
end_comment

begin_comment
comment|// CHECK-NEXT: Number FIXITs = 0
end_comment

begin_comment
comment|// CHECK-NEXT: +-{{.*}}serialized-diags-stable.c:[[@LINE+2]]:6: note: previous definition is here [] []
end_comment

begin_comment
comment|// CHECK-NEXT: Number FIXITs = 0
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{}
end_function

begin_typedef
typedef|typedef
name|int
name|bar
typedef|;
end_typedef

begin_comment
comment|// CHECK-LABEL: Number of diagnostics: 2
end_comment

end_unit

