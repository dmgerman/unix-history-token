begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-win32 -fms-extensions -emit-llvm -o - | FileCheck %s
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
comment|// CHECK: invoke void @try_body(i32 %{{.*}}, i32 %{{.*}}, i32* %{{.*}}) #[[NOINLINE:[0-9]+]]
end_comment

begin_comment
comment|// CHECK:       to label %{{.*}} unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK: landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// CHECK-NEXT: catch i8* null
end_comment

begin_comment
comment|// CHECK-NOT: br i1
end_comment

begin_comment
comment|// CHECK: br label %[[except:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: [[except]]
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 -42, i32* %[[success:[^ ]*]]
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
comment|// CHECK: call void (...) @llvm.frameescape(i32* %[[r:[^ ,]*]])
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
comment|// CHECK: landingpad
end_comment

begin_comment
comment|// CHECK-NEXT: catch i8* bitcast (i32 (i8*, i8*)* @"\01?filt$0@0@filter_expr_capture@@" to i8*)
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
comment|// CHECK-LABEL: define internal i32 @"\01?filt$0@0@filter_expr_capture@@"(i8* %exception_pointers, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK: call i8* @llvm.framerecover(i8* bitcast (i32 ()* @filter_expr_capture to i8*), i8* %frame_pointer, i32 0)
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
comment|// CHECK: store i32 42, i32* %[[r:[^ ,]*]]
end_comment

begin_comment
comment|// CHECK: invoke void @j() #[[NOINLINE]]
end_comment

begin_comment
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
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
comment|// CHECK: br label %[[inner_try_cont:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK: landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// CHECK: catch i8* bitcast (i32 (i8*, i8*)* @"\01?filt$1@0@nested_try@@" to i8*)
end_comment

begin_comment
comment|// CHECK: catch i8* bitcast (i32 (i8*, i8*)* @"\01?filt$0@0@nested_try@@" to i8*)
end_comment

begin_comment
comment|// CHECK: store i8* %{{.*}}, i8** %[[ehptr_slot:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: store i32 %{{.*}}, i32* %[[sel_slot:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: load i32, i32* %[[sel_slot]]
end_comment

begin_comment
comment|// CHECK: call i32 @llvm.eh.typeid.for(i8* bitcast (i32 (i8*, i8*)* @"\01?filt$1@0@nested_try@@" to i8*))
end_comment

begin_comment
comment|// CHECK: icmp eq i32
end_comment

begin_comment
comment|// CHECK: br i1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: load i32, i32* %[[sel_slot]]
end_comment

begin_comment
comment|// CHECK: call i32 @llvm.eh.typeid.for(i8* bitcast (i32 (i8*, i8*)* @"\01?filt$0@0@nested_try@@" to i8*))
end_comment

begin_comment
comment|// CHECK: icmp eq i32
end_comment

begin_comment
comment|// CHECK: br i1
end_comment

begin_comment
comment|//
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
comment|// CHECK: store i32 123, i32* %[[r]]
end_comment

begin_comment
comment|// CHECK: br label %[[inner_try_cont]]
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

begin_decl_stmt
specifier|static
name|unsigned
name|g
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|basic_finally
parameter_list|(
name|void
parameter_list|)
block|{
operator|++
name|g
expr_stmt|;
name|__try
block|{
name|j
argument_list|()
expr_stmt|;
block|}
name|__finally
block|{
operator|--
name|g
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @basic_finally()
end_comment

begin_comment
comment|// CHECK: load i32, i32* @g
end_comment

begin_comment
comment|// CHECK: add i32 %{{.*}}, 1
end_comment

begin_comment
comment|// CHECK: store i32 %{{.*}}, i32* @g
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: invoke void @j()
end_comment

begin_comment
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.frameaddress(i32 0)
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"(i8 0, i8* %[[fp]])
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
comment|// CHECK: landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__C_specific_handler to i8*)
end_comment

begin_comment
comment|// CHECK-NEXT: cleanup
end_comment

begin_comment
comment|// CHECK: %[[fp:[^ ]*]] = call i8* @llvm.frameaddress(i32 0)
end_comment

begin_comment
comment|// CHECK: call void @"\01?fin$0@0@basic_finally@@"(i8 1, i8* %[[fp]])
end_comment

begin_comment
comment|// CHECK: resume
end_comment

begin_comment
comment|// CHECK: define internal void @"\01?fin$0@0@basic_finally@@"(i8 %abnormal_termination, i8* %frame_pointer)
end_comment

begin_comment
comment|// CHECK:   load i32, i32* @g, align 4
end_comment

begin_comment
comment|// CHECK:   add i32 %{{.*}}, -1
end_comment

begin_comment
comment|// CHECK:   store i32 %{{.*}}, i32* @g, align 4
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
comment|// CHECK:       to label %[[cont:[^ ]*]] unwind label %[[lpad:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[cont]]
end_comment

begin_comment
comment|// CHECK: store i32 %[[tmp]], i32* %[[rv:[^ ]*]]
end_comment

begin_comment
comment|// CHECK: br label %[[retbb:[^ ]*]]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: [[lpad]]
end_comment

begin_comment
comment|// CHECK: store i32 42, i32* %[[rv]]
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
comment|// CHECK: attributes #[[NOINLINE]] = { {{.*noinline.*}} }
end_comment

end_unit

