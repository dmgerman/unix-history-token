begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-win32 -fms-extensions -emit-llvm -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=CHECK --check-prefix=X64
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-win32 -fms-extensions -emit-llvm -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=CHECK --check-prefix=X86
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-pc-windows-gnu -fms-extensions -emit-llvm -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=X86-GNU
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-windows-gnu -fms-extensions -emit-llvm -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=X64-GNU
end_comment

begin_function
name|void
name|try_body
parameter_list|(
name|int
name|numerator
parameter_list|,
name|int
name|denominator
parameter_list|,
name|int
modifier|*
name|myres
parameter_list|)
block|{
operator|*
name|myres
operator|=
name|numerator
operator|/
name|denominator
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @try_body(i32 %numerator, i32 %denominator, i32* %myres)
end_comment

begin_comment
comment|// CHECK: sdiv i32
end_comment

begin_comment
comment|// CHECK: store i32 %{{.*}}, i32*
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|int
name|safe_div
parameter_list|(
name|int
name|numerator
parameter_list|,
name|int
name|denominator
parameter_list|,
name|int
modifier|*
name|res
parameter_list|)
block|{
name|int
name|myres
init|=
literal|0
decl_stmt|;
name|int
name|success
init|=
literal|1
decl_stmt|;
name|__try
block|{
name|try_body
argument_list|(
name|numerator
argument_list|,
name|denominator
argument_list|,
operator|&
name|myres
argument_list|)
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
name|success
operator|=
operator|-
literal|42
expr_stmt|;
block|}
operator|*
name|res
operator|=
name|myres
expr_stmt|;
return|return
name|success
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @safe_div(i32 %numerator, i32 %denominator, i32* %res)
end_comment

begin_comment
comment|// X64-SAME:      personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// X86-SAME:      personality i8* bitcast (i32 (...)* @_except_handler3 to i8*)
end_comment

begin_comment
comment|// CHECK: invoke void @try_body(i32 %{{.*}}, i32 %{{.*}}, i32* %{{.*}}) #[[NOINLINE:[0-9]+]]
end_comment

begin_comment
comment|// CHECK:       to label %{{.*}} unwind label %[[catchpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[catchpad]]
end_comment

begin_comment
comment|// X64: %[[padtoken:[^ ]*]] = catchpad within %{{[^ ]*}} [i8* null]
end_comment

begin_comment
comment|// X86: %[[padtoken:[^ ]*]] = catchpad within %{{[^ ]*}} [i8* bitcast (i32 ()* @"\01?filt$0@0@safe_div@@" to i8*)]
end_comment

begin_comment
comment|// CHECK-NEXT: catchret from %[[padtoken]] to label %[[except:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[except]]
end_comment

begin_comment
comment|// CHECK: store i32 -42, i32* %[[success:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: %[[res:[^ ]*]] = load i32, i32* %[[success]]
end_comment

begin_comment
comment|// CHECK: ret i32 %[[res]]
end_comment

begin_comment
comment|// 32-bit SEH needs this filter to save the exception code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86-LABEL: define internal i32 @"\01?filt$0@0@safe_div@@"()
end_comment

begin_comment
comment|// X86: %[[ebp:[^ ]*]] = call i8* @llvm.frameaddress(i32 1)
end_comment

begin_comment
comment|// X86: %[[fp:[^ ]*]] = call i8* @llvm.x86.seh.recoverfp(i8* bitcast (i32 (i32, i32, i32*)* @safe_div to i8*), i8* %[[ebp]])
end_comment

begin_comment
comment|// X86: call i8* @llvm.localrecover(i8* bitcast (i32 (i32, i32, i32*)* @safe_div to i8*), i8* %[[fp]], i32 0)
end_comment

begin_comment
comment|// X86: load i8*, i8**
end_comment

begin_comment
comment|// X86: load i32*, i32**
end_comment

begin_comment
comment|// X86: load i32, i32*
end_comment

begin_comment
comment|// X86: store i32 %{{.*}}, i32*
end_comment

begin_comment
comment|// X86: ret i32 1
end_comment

begin_comment
comment|// Mingw uses msvcrt, so it can also use _except_handler3.
end_comment

begin_comment
comment|// X86-GNU-LABEL: define i32 @safe_div(i32 %numerator, i32 %denominator, i32* %res)
end_comment

begin_comment
comment|// X86-GNU-SAME:      personality i8* bitcast (i32 (...)* @_except_handler3 to i8*)
end_comment

begin_comment
comment|// X64-GNU-LABEL: define i32 @safe_div(i32 %numerator, i32 %denominator, i32* %res)
end_comment

begin_comment
comment|// X64-GNU-SAME:      personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_function_decl
name|void
name|j
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|filter_expr_capture
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|r
init|=
literal|42
decl_stmt|;
name|__try
block|{
name|j
argument_list|()
expr_stmt|;
block|}
name|__except
argument_list|(
argument|r = -
literal|1
argument_list|)
block|{
name|r
operator|=
literal|13
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @filter_expr_capture()
end_comment

begin_comment
comment|// X64-SAME: personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// X86-SAME: personality i8* bitcast (i32 (...)* @_except_handler3 to i8*)
end_comment

begin_comment
comment|// X64: call void (...) @llvm.localescape(i32* %[[r:[^ ,]*]])
end_comment

begin_comment
comment|// X86: call void (...) @llvm.localescape(i32* %[[r:[^ ,]*]], i32* %[[code:[^ ,]*]])
end_comment

begin_comment
comment|// CHECK: store i32 42, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: invoke void @j() #[[NOINLINE]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: catchpad within %{{[^ ]*}} [i8* bitcast (i32 ({{.*}})* @"\01?filt$0@0@filter_expr_capture@@" to i8*)]
end_comment

begin_comment
comment|// CHECK: store i32 13, i32* %[[r]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: %[[rv:[^ ]*]] = load i32, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: ret i32 %[[rv]]
end_comment

begin_comment
comment|// X64-LABEL: define internal i32 @"\01?filt$0@0@filter_expr_capture@@"(i8* %exception_pointers, i8* %frame_pointer)
end_comment

begin_comment
comment|// X64: %[[fp:[^ ]*]] = call i8* @llvm.x86.seh.recoverfp(i8* bitcast (i32 ()* @filter_expr_capture to i8*), i8* %frame_pointer)
end_comment

begin_comment
comment|// X64: call i8* @llvm.localrecover(i8* bitcast (i32 ()* @filter_expr_capture to i8*), i8* %[[fp]], i32 0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86-LABEL: define internal i32 @"\01?filt$0@0@filter_expr_capture@@"()
end_comment

begin_comment
comment|// X86: %[[ebp:[^ ]*]] = call i8* @llvm.frameaddress(i32 1)
end_comment

begin_comment
comment|// X86: %[[fp:[^ ]*]] = call i8* @llvm.x86.seh.recoverfp(i8* bitcast (i32 ()* @filter_expr_capture to i8*), i8* %[[ebp]])
end_comment

begin_comment
comment|// X86: call i8* @llvm.localrecover(i8* bitcast (i32 ()* @filter_expr_capture to i8*), i8* %[[fp]], i32 0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: store i32 -1, i32* %{{.*}}
end_comment

begin_comment
comment|// CHECK: ret i32 -1
end_comment

begin_function
name|int
name|nested_try
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|r
init|=
literal|42
decl_stmt|;
name|__try
block|{
name|__try
block|{
name|j
argument_list|()
expr_stmt|;
name|r
operator|=
literal|0
expr_stmt|;
block|}
name|__except
argument_list|(
argument|_exception_code() ==
literal|123
argument_list|)
block|{
name|r
operator|=
literal|123
expr_stmt|;
block|}
block|}
name|__except
argument_list|(
argument|_exception_code() ==
literal|456
argument_list|)
block|{
name|r
operator|=
literal|456
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @nested_try()
end_comment

begin_comment
comment|// X64-SAME: personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// X86-SAME: personality i8* bitcast (i32 (...)* @_except_handler3 to i8*)
end_comment

begin_comment
comment|// CHECK: store i32 42, i32* %[[r:[^ ,]*]]
end_comment

begin_comment
comment|// CHECK: invoke void @j() #[[NOINLINE]]
end_comment

begin_comment
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[cswitch_inner:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cswitch_inner]]
end_comment

begin_comment
comment|// CHECK: %[[cs_inner:[^ ]*]] = catchswitch within none [label %[[cpad_inner:[^ ]*]]] unwind label %[[cswitch_outer:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cswitch_outer]]
end_comment

begin_comment
comment|// CHECK: %[[cs_outer:[^ ]*]] = catchswitch within none [label %[[cpad_outer:[^ ]*]]] unwind to caller
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cpad_outer]]
end_comment

begin_comment
comment|// CHECK: catchpad within %{{[^ ]*}} [i8* bitcast (i32 ({{.*}})* @"\01?filt$0@0@nested_try@@" to i8*)]
end_comment

begin_comment
comment|// CHECK-NEXT: catchret {{.*}} to label %[[except_outer:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[except_outer]]
end_comment

begin_comment
comment|// CHECK: store i32 456, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: br label %[[outer_try_cont:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[outer_try_cont]]
end_comment

begin_comment
comment|// CHECK: %[[r_load:[^ ]*]] = load i32, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: ret i32 %[[r_load]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cpad_inner]]
end_comment

begin_comment
comment|// CHECK: catchpad within %[[cs_inner]] [i8* bitcast (i32 ({{.*}})* @"\01?filt$1@0@nested_try@@" to i8*)]
end_comment

begin_comment
comment|// CHECK-NEXT: catchret {{.*}} to label %[[except_inner:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[except_inner]]
end_comment

begin_comment
comment|// CHECK: store i32 123, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: br label %[[inner_try_cont:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[inner_try_cont]]
end_comment

begin_comment
comment|// CHECK: br label %[[outer_try_cont]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: store i32 0, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: br label %[[inner_try_cont]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define internal i32 @"\01?filt$0@0@nested_try@@"({{.*}})
end_comment

begin_comment
comment|// X86: call i8* @llvm.x86.seh.recoverfp({{.*}})
end_comment

begin_comment
comment|// CHECK: load i32*, i32**
end_comment

begin_comment
comment|// CHECK: load i32, i32*
end_comment

begin_comment
comment|// CHECK: icmp eq i32 %{{.*}}, 456
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define internal i32 @"\01?filt$1@0@nested_try@@"({{.*}})
end_comment

begin_comment
comment|// X86: call i8* @llvm.x86.seh.recoverfp({{.*}})
end_comment

begin_comment
comment|// CHECK: load i32*, i32**
end_comment

begin_comment
comment|// CHECK: load i32, i32*
end_comment

begin_comment
comment|// CHECK: icmp eq i32 %{{.*}}, 123
end_comment

begin_function
name|int
name|basic_finally
parameter_list|(
name|int
name|g
parameter_list|)
block|{
name|__try
block|{
name|j
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
operator|++
name|g
expr_stmt|;
block|}
return|return
name|g
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @basic_finally(i32 %g)
end_comment

begin_comment
comment|// X64-SAME: personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// X86-SAME: personality i8* bitcast (i32 (...)* @_except_handler3 to i8*)
end_comment

begin_comment
comment|// CHECK: %[[g_addr:[^ ]*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK: call void (...) @llvm.localescape(i32* %[[g_addr]])
end_comment

begin_comment
comment|// CHECK: store i32 %g, i32* %[[g_addr]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: invoke void @j()
end_comment

begin_comment
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[cleanuppad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"({{i8( zeroext)?}} 0, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: load i32, i32* %[[g_addr]], align 4
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cleanuppad]]
end_comment

begin_comment
comment|// CHECK: %[[padtoken:[^ ]*]] = cleanuppad within none []
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"({{i8( zeroext)?}} 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: cleanupret from %[[padtoken]] unwind to caller
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@basic_finally@@"({{i8( zeroext)?}} %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK:   call i8* @llvm.localrecover(i8* bitcast (i32 (i32)* @basic_finally to i8*), i8* %frame_pointer, i32 0)
end_comment

begin_comment
comment|// CHECK:   load i32, i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK:   add nsw i32 %{{.*}}, 1
end_comment

begin_comment
comment|// CHECK:   store i32 %{{.*}}, i32* %{{.*}}, align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function_decl
name|int
name|returns_int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|except_return
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
return|return
name|returns_int
argument_list|()
return|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
return|return
literal|42
return|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @except_return()
end_comment

begin_comment
comment|// CHECK: %[[tmp:[^ ]*]] = invoke i32 @returns_int()
end_comment

begin_comment
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[catchpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[catchpad]]
end_comment

begin_comment
comment|// CHECK: catchpad
end_comment

begin_comment
comment|// CHECK: catchret
end_comment

begin_comment
comment|// CHECK: store i32 42, i32* %[[rv:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: br label %[[retbb:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: store i32 %[[tmp]], i32* %[[rv]]
end_comment

begin_comment
comment|// CHECK: br label %[[retbb]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[retbb]]
end_comment

begin_comment
comment|// CHECK: %[[r:[^ ]*]] = load i32, i32* %[[rv]]
end_comment

begin_comment
comment|// CHECK: ret i32 %[[r]]
end_comment

begin_comment
comment|// PR 24751: don't assert if a variable is used twice in a __finally block.
end_comment

begin_comment
comment|// Also, make sure we don't do redundant work to capture/project it.
end_comment

begin_function
name|void
name|finally_capture_twice
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|__try
block|{   }
name|__finally
block|{
name|int
name|y
init|=
name|x
decl_stmt|;
name|int
name|z
init|=
name|x
decl_stmt|;
block|}
block|}
end_function

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define void @finally_capture_twice(
end_comment

begin_comment
comment|// CHECK:         [[X:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK:         call void (...) @llvm.localescape(i32* [[X]])
end_comment

begin_comment
comment|// CHECK-NEXT:    store i32 {{.*}}, i32* [[X]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    [[LOCAL:%.*]] = call i8* @llvm.localaddress()
end_comment

begin_comment
comment|// CHECK-NEXT:    call void [[FINALLY:@.*]](i8{{ zeroext | }}0, i8* [[LOCAL]])
end_comment

begin_comment
comment|// CHECK:       define internal void [[FINALLY]](
end_comment

begin_comment
comment|// CHECK:         [[LOCAL:%.*]] = call i8* @llvm.localrecover(
end_comment

begin_comment
comment|// CHECK:         [[X:%.*]] = bitcast i8* [[LOCAL]] to i32*
end_comment

begin_comment
comment|// CHECK-NEXT:    [[Y:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    [[Z:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    store i8*
end_comment

begin_comment
comment|// CHECK-NEXT:    store i8
end_comment

begin_comment
comment|// CHECK-NEXT:    [[T0:%.*]] = load i32, i32* [[X]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    store i32 [[T0]], i32* [[Y]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    [[T0:%.*]] = load i32, i32* [[X]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    store i32 [[T0]], i32* [[Z]], align 4
end_comment

begin_comment
comment|// CHECK-NEXT:    ret void
end_comment

begin_function
name|int
name|exception_code_in_except
parameter_list|(
name|void
parameter_list|)
block|{
name|__try
block|{
name|try_body
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|__except
argument_list|(
literal|1
argument_list|)
block|{
return|return
name|_exception_code
argument_list|()
return|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @exception_code_in_except()
end_comment

begin_comment
comment|// CHECK: %[[ret_slot:[^ ]*]] = alloca i32
end_comment

begin_comment
comment|// CHECK: %[[code_slot:[^ ]*]] = alloca i32
end_comment

begin_comment
comment|// CHECK: invoke void @try_body(i32 0, i32 0, i32* null)
end_comment

begin_comment
comment|// CHECK: %[[pad:[^ ]*]] = catchpad
end_comment

begin_comment
comment|// CHECK: catchret from %[[pad]]
end_comment

begin_comment
comment|// X64: %[[code:[^ ]*]] = call i32 @llvm.eh.exceptioncode(token %[[pad]])
end_comment

begin_comment
comment|// X64: store i32 %[[code]], i32* %[[code_slot]]
end_comment

begin_comment
comment|// CHECK: %[[ret1:[^ ]*]] = load i32, i32* %[[code_slot]]
end_comment

begin_comment
comment|// CHECK: store i32 %[[ret1]], i32* %[[ret_slot]]
end_comment

begin_comment
comment|// CHECK: %[[ret2:[^ ]*]] = load i32, i32* %[[ret_slot]]
end_comment

begin_comment
comment|// CHECK: ret i32 %[[ret2]]
end_comment

begin_comment
comment|// CHECK: attributes #[[NOINLINE]] = { {{.*noinline.*}} }
end_comment

end_unit

