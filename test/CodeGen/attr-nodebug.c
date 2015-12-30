begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nodebug
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|t1
parameter_list|()
block|{
name|int
name|a
init|=
literal|10
decl_stmt|;
name|a
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
name|int
name|b
init|=
literal|10
decl_stmt|;
name|b
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// With nodebug, IR should have no llvm.dbg.* calls, or !dbg annotations.
end_comment

begin_comment
comment|// CHECK-LABEL: @t1
end_comment

begin_comment
comment|// CHECK-NOT:   dbg
end_comment

begin_comment
comment|// CHECK:       }
end_comment

begin_comment
comment|// For sanity, check those things do occur normally.
end_comment

begin_comment
comment|// CHECK-LABEL: @t2
end_comment

begin_comment
comment|// CHECK:       call{{.*}}llvm.dbg
end_comment

begin_comment
comment|// CHECK:       !dbg
end_comment

begin_comment
comment|// CHECK:       }
end_comment

begin_comment
comment|// We should see a function description for t2 but not t1.
end_comment

begin_comment
comment|// CHECK-NOT: DISubprogram(name: "t1"
end_comment

begin_comment
comment|// CHECK:     DISubprogram(name: "t2"
end_comment

begin_comment
comment|// CHECK-NOT: DISubprogram(name: "t1"
end_comment

end_unit

