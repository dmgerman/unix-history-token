begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-win32 -fms-extensions -emit-llvm -o - | opt -instnamer -S | FileCheck %s
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// __leave with __except
end_comment

begin_comment
comment|// Nothing in the __try block can trap, so __try.cont isn't created.
end_comment

begin_function
name|int
name|__leave_with___except_simple
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|myres
operator|=
literal|15
expr_stmt|;
name|__leave
expr_stmt|;
name|myres
operator|=
literal|23
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @__leave_with___except_simple()
end_comment

begin_comment
comment|// CHECK: store i32 15, i32* %myres
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 1
end_comment

begin_comment
comment|// The "normal" case.
end_comment

begin_function
name|int
name|__leave_with___except
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
name|myres
operator|=
literal|23
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @__leave_with___except()
end_comment

begin_comment
comment|// CHECK: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[cont:.*]] unwind label %{{.*}}
end_comment

begin_comment
comment|// For __excepts, instead of an explicit __try.__leave label, we could use
end_comment

begin_comment
comment|// use invoke.cont as __leave jump target instead.  However, not doing this
end_comment

begin_comment
comment|// keeps the CodeGen code simpler, __leave is very rare, and SimplifyCFG will
end_comment

begin_comment
comment|// simplify this anyways.
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %
end_comment

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// __leave with __finally
end_comment

begin_function_decl
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Nothing in the __try block can trap, so __finally.cont and friends aren't
end_comment

begin_comment
comment|// created.
end_comment

begin_function
name|int
name|__leave_with___finally_simple
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|myres
operator|=
literal|15
expr_stmt|;
name|__leave
expr_stmt|;
name|myres
operator|=
literal|23
expr_stmt|;
block|}
name|__finally
block|{
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @__leave_with___finally_simple()
end_comment

begin_comment
comment|// CHECK: store i32 15, i32* %myres
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@__leave_with___finally_simple@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// __finally block doesn't return, __finally.cont doesn't exist.
end_comment

begin_function
name|int
name|__leave_with___finally_noreturn
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|myres
operator|=
literal|15
expr_stmt|;
name|__leave
expr_stmt|;
name|myres
operator|=
literal|23
expr_stmt|;
block|}
name|__finally
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @__leave_with___finally_noreturn()
end_comment

begin_comment
comment|// CHECK: store i32 15, i32* %myres
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@__leave_with___finally_noreturn@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// The "normal" case.
end_comment

begin_function
name|int
name|__leave_with___finally
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
name|myres
operator|=
literal|23
expr_stmt|;
block|}
name|__finally
block|{
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @__leave_with___finally()
end_comment

begin_comment
comment|// CHECK: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[cont:.*]] unwind label %{{.*}}
end_comment

begin_comment
comment|// For __finally, there needs to be an explicit __try.__leave, because
end_comment

begin_comment
comment|// abnormal.termination.slot needs to be set there.
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@__leave_with___finally@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|//////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Mixed, nested cases.
end_comment

begin_function
name|int
name|nested___except___finally
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
comment|// Refers to the outer __try, not the __finally!
name|myres
operator|=
literal|23
expr_stmt|;
return|return
literal|0
return|;
block|}
name|myres
operator|=
literal|51
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{   }
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @nested___except___finally()
end_comment

begin_comment
comment|// CHECK-LABEL: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g1_cont1:.*]] unwind label %[[g1_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g1_cont1]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: invoke void @"\01?fin$0@0@nested___except___finally@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[fin_cont:.*]] unwind label %[[g2_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[fin_cont]]
end_comment

begin_comment
comment|// CHECK: store i32 51, i32* %
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[trycont:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[g1_lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: cleanuppad
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: invoke void @"\01?fin$0@0@nested___except___finally@@"(i8 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g1_resume:.*]] unwind label %[[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: cleanupret {{.*}} unwind label %[[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: [[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: catchpad {{.*}} [i8* null]
end_comment

begin_comment
comment|// CHECK: catchret
end_comment

begin_comment
comment|// CHECK: br label %[[trycont]]
end_comment

begin_comment
comment|// CHECK: [[trycont]]
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 1
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@nested___except___finally@@"(i8 %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK: call void @g()
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|int
name|nested___except___except
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
name|myres
operator|=
literal|16
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
comment|// Refers to the outer __try, not the __except we're in!
name|myres
operator|=
literal|23
expr_stmt|;
return|return
literal|0
return|;
block|}
name|myres
operator|=
literal|51
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{   }
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// The order of basic blocks in the below doesn't matter.
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @nested___except___except()
end_comment

begin_comment
comment|// CHECK-LABEL: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g1_cont:.*]] unwind label %[[g1_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g1_lpad]]
end_comment

begin_comment
comment|// CHECK: catchpad {{.*}} [i8* null]
end_comment

begin_comment
comment|// CHECK: catchret {{.*}} to label %[[except:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[except]]
end_comment

begin_comment
comment|// CHECK: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g2_cont:.*]] unwind label %[[g2_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: catchpad {{.*}} [i8* null]
end_comment

begin_comment
comment|// CHECK: catchret
end_comment

begin_comment
comment|// CHECK: br label %[[trycont4:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[trycont4]]
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 1
end_comment

begin_comment
comment|// CHECK: [[g2_cont]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: store i32 23
end_comment

begin_comment
comment|// CHECK: [[g1_cont]]
end_comment

begin_comment
comment|// CHECK: store i32 16, i32* %myres
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[trycont:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[trycont]]
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 51, i32* %myres
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave]]
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[trycont4]]
end_comment

begin_function
name|int
name|nested___finally___except
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
comment|// Refers to the outer __try, not the __except!
name|myres
operator|=
literal|23
expr_stmt|;
return|return
literal|0
return|;
block|}
name|myres
operator|=
literal|51
expr_stmt|;
block|}
name|__finally
block|{   }
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// The order of basic blocks in the below doesn't matter.
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @nested___finally___except()
end_comment

begin_comment
comment|// CHECK-LABEL: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g1_cont:.*]] unwind label %[[g1_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g1_lpad]]
end_comment

begin_comment
comment|// CHECK: catchpad
end_comment

begin_comment
comment|// CHECK: catchret
end_comment

begin_comment
comment|// CHECK: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g2_cont:.*]] unwind label %[[g2_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g2_cont]]
end_comment

begin_comment
comment|// CHECK: br label %[[tryleave:[^ ]*]]
end_comment

begin_comment
comment|// CHECK-NOT: 23
end_comment

begin_comment
comment|// CHECK: [[g1_cont]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[trycont:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[trycont]]
end_comment

begin_comment
comment|// CHECK: store i32 51, i32* %
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[tryleave]]
end_comment

begin_comment
comment|// CHECK: [[tryleave]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@nested___finally___except@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 1
end_comment

begin_comment
comment|// CHECK: [[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: cleanuppad
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@nested___finally___except@@"(i8 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: cleanupret {{.*}} unwind to caller
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@nested___finally___except@@"(i8 %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|int
name|nested___finally___finally
parameter_list|()
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|__try
block|{
name|__try
block|{
name|g
argument_list|()
expr_stmt|;
name|myres
operator|=
literal|16
expr_stmt|;
block|}
name|__finally
block|{
name|g
argument_list|()
expr_stmt|;
name|__leave
expr_stmt|;
comment|// Refers to the outer __try, not the __finally we're in!
name|myres
operator|=
literal|23
expr_stmt|;
return|return
literal|0
return|;
block|}
name|myres
operator|=
literal|51
expr_stmt|;
block|}
name|__finally
block|{   }
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// The order of basic blocks in the below doesn't matter.
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @nested___finally___finally()
end_comment

begin_comment
comment|// CHECK: invoke void @g()
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[g1_cont:.*]] unwind label %[[g1_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[g1_cont]]
end_comment

begin_comment
comment|// CHECK: store i32 16, i32* %[[myres:[^ ]*]],
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: invoke void @"\01?fin$1@0@nested___finally___finally@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[finally_cont:.*]] unwind label %[[g2_lpad:.*]]
end_comment

begin_comment
comment|// CHECK: [[finally_cont]]
end_comment

begin_comment
comment|// CHECK: store i32 51, i32* %[[myres]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@nested___finally___finally@@"(i8 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 1
end_comment

begin_comment
comment|// CHECK: [[g1_lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[padtoken:[^ ]*]] = cleanuppad within none []
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: invoke void @"\01?fin$1@0@nested___finally___finally@@"(i8 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[finally_cont2:.*]] unwind label %[[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: [[finally_cont2]]
end_comment

begin_comment
comment|// CHECK: cleanupret from %[[padtoken]] unwind label %[[g2_lpad]]
end_comment

begin_comment
comment|// CHECK: [[g2_lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[padtoken:[^ ]*]] = cleanuppad within none []
end_comment

begin_comment
comment|// CHECK-NEXT: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT: call void @"\01?fin$0@0@nested___finally___finally@@"(i8 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: cleanupret from %[[padtoken]] unwind to caller
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@nested___finally___finally@@"(i8 %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$1@0@nested___finally___finally@@"(i8 %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK: call void @g()
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

end_unit

