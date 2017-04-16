begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core.NullDereference -analyzer-output=text -fno-caret-diagnostics %s 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|testA
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// CHECK-LABEL: text-diagnostics.c:{{.*}}:6: warning: Dereference of null pointer (loaded from variable 'p')
comment|// CHECK-NEXT: text-diagnostics.c:[[@LINE-4]]:3: note: 'p' initialized to a null pointer value
comment|// CHECK-NEXT: text-diagnostics.c:[[@LINE-4]]:6: note: Dereference of null pointer (loaded from variable 'p')
block|}
end_function

begin_function
name|void
name|testB
parameter_list|(
name|int
modifier|*
name|q
parameter_list|)
block|{
if|if
condition|(
name|q
condition|)
return|return;
operator|*
name|q
operator|=
literal|1
expr_stmt|;
comment|// CHECK-LABEL: text-diagnostics.c:{{.*}}:6: warning: Dereference of null pointer (loaded from variable 'q')
comment|// CHECK-NEXT: text-diagnostics.c:[[@LINE-5]]:7: note: Assuming 'q' is null
comment|// CHECK-NEXT: text-diagnostics.c:[[@LINE-6]]:3: note: Taking false branch
comment|// CHECK-NEXT: text-diagnostics.c:[[@LINE-5]]:6: note: Dereference of null pointer (loaded from variable 'q')
block|}
end_function

end_unit

