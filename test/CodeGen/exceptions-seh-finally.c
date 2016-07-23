begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
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

begin_function_decl
name|void
name|might_crash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_condition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|basic_finally
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|cleanup
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @basic_finally()
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash()
end_comment

begin_comment
comment|// CHECK:     to label %[[invoke_cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[invoke_cont]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"({{i8( zeroext)?}} 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[pad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"({{i8( zeroext)?}} 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[pad]] unwind to caller
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@basic_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: call void @cleanup()
end_comment

begin_comment
comment|// Mostly check that we don't double emit 'r' which would crash.
end_comment

begin_function
name|void
name|decl_in_finally
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|int
name|r
decl_stmt|;
block|}
block|}
end_function

begin_comment
comment|// Ditto, don't crash double emitting 'l'.
end_comment

begin_function
name|void
name|label_in_finally
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|l
label|:
name|cleanup
argument_list|()
expr_stmt|;
if|if
condition|(
name|check_condition
argument_list|()
condition|)
goto|goto
name|l
goto|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @label_in_finally()
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash()
end_comment

begin_comment
comment|// CHECK:     to label %[[invoke_cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[invoke_cont]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@label_in_finally@@"({{i8( zeroext)?}} 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@label_in_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: br label %[[l:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[l]]
end_comment

begin_comment
comment|// CHECK: call void @cleanup()
end_comment

begin_comment
comment|// CHECK: call i32 @check_condition()
end_comment

begin_comment
comment|// CHECK: br i1 {{.*}}, label
end_comment

begin_comment
comment|// CHECK: br label %[[l]]
end_comment

begin_decl_stmt
name|int
name|crashed
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|use_abnormal_termination
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|crashed
operator|=
name|__abnormal_termination
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @use_abnormal_termination()
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash()
end_comment

begin_comment
comment|// CHECK:     to label %[[invoke_cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[invoke_cont]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@use_abnormal_termination@@"({{i8( zeroext)?}} 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[pad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@use_abnormal_termination@@"({{i8( zeroext)?}} 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[pad]] unwind to caller
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@use_abnormal_termination@@"({{i8( zeroext)?}} %[[abnormal:abnormal_termination]], i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: %[[abnormal_zext:[^ ]*]] = zext i8 %[[abnormal]] to i32
end_comment

begin_comment
comment|// CHECK: store i32 %[[abnormal_zext]], i32* @crashed
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_function
name|void
name|noreturn_noop_finally
parameter_list|()
block|{
name|__try
block|{
name|__noop
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @noreturn_noop_finally()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@noreturn_noop_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@noreturn_noop_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: call void @abort()
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|void
name|noreturn_finally
parameter_list|()
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @noreturn_finally()
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash()
end_comment

begin_comment
comment|// CHECK:     to label %[[cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@noreturn_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[pad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@noreturn_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[pad]] unwind to caller
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@noreturn_finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: call void @abort()
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|int
name|finally_with_return
parameter_list|()
block|{
name|__try
block|{
return|return
literal|42
return|;
block|}
name|__finally
block|{   }
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @finally_with_return()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@finally_with_return@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 42
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@finally_with_return@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK-NOT: br i1
end_comment

begin_comment
comment|// CHECK-NOT: br label
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|int
name|nested___finally___finally
parameter_list|()
block|{
name|__try
block|{
name|__try
block|{     }
name|__finally
block|{
return|return
literal|1
return|;
block|}
block|}
name|__finally
block|{
comment|// Intentionally no return here.
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @nested___finally___finally
end_comment

begin_comment
comment|// CHECK: invoke void @"\01?fin$1@0@nested___finally___finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK:          to label %[[outercont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[outercont]]
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@nested___finally___finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[pad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@nested___finally___finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[pad]] unwind to caller
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@nested___finally___finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$1@0@nested___finally___finally@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_comment
comment|// FIXME: Our behavior seems suspiciously different.
end_comment

begin_function
name|int
name|nested___finally___finally_with_eh_edge
parameter_list|()
block|{
name|__try
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
return|return
literal|899
return|;
block|}
block|}
name|__finally
block|{
comment|// Intentionally no return here.
block|}
return|return
literal|912
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @nested___finally___finally_with_eh_edge
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash()
end_comment

begin_comment
comment|// CHECK-NEXT: to label %[[invokecont:[^ ]*]] unwind label %[[lpad1:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [[invokecont]]
end_comment

begin_comment
comment|// CHECK: invoke void @"\01?fin$1@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:       to label %[[outercont:[^ ]*]] unwind label %[[lpad2:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[outercont]]
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: ret i32 912
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad1]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[innerpad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: invoke void @"\01?fin$1@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT:    label %[[innercleanupretbb:[^ ]*]] unwind label %[[lpad2:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[innercleanupretbb]]
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[innerpad]] unwind label %[[lpad2]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad2]]
end_comment

begin_comment
comment|// CHECK-NEXT: %[[outerpad:[^ ]*]] = cleanuppad
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-NEXT: cleanupret from %[[outerpad]] unwind to caller
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$1@0@nested___finally___finally_with_eh_edge@@"({{.*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: unreachable
end_comment

begin_function
name|void
name|finally_within_finally
parameter_list|()
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
name|__try
block|{
name|might_crash
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{     }
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @finally_within_finally(
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash(
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@finally_within_finally@@"(
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@finally_within_finally@@"({{.*}}) [ "funclet"(
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$0@0@finally_within_finally@@"({{[^)]*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// CHECK: invoke void @might_crash(
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$1@0@finally_within_finally@@"(
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$1@0@finally_within_finally@@"({{.*}}) [ "funclet"(
end_comment

begin_comment
comment|// CHECK-LABEL: define internal void @"\01?fin$1@0@finally_within_finally@@"({{[^)]*}})
end_comment

begin_comment
comment|// CHECK-SAME: [[finally_attrs]]
end_comment

begin_comment
comment|// Look for the absence of noinline. Enum attributes come first, so check that
end_comment

begin_comment
comment|// a string attribute is the first to verify that no enum attributes are
end_comment

begin_comment
comment|// present.
end_comment

begin_comment
comment|// CHECK: attributes [[finally_attrs]] = { "{{.*}}" }
end_comment

end_unit

