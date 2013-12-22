begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -o %t1 %s
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=LOCAL %s< %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=UNDEF %s< %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=PARAM %s< %t1
end_comment

begin_comment
comment|// END.
end_comment

begin_comment
comment|// LOCAL: private unnamed_addr constant [15 x i8] c"localvar_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// LOCAL: private unnamed_addr constant [15 x i8] c"localvar_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// UNDEF: private unnamed_addr constant [15 x i8] c"undefvar_ann_0\00", section "llvm.metadata"
end_comment

begin_comment
comment|// PARAM: private unnamed_addr constant [12 x i8] c"param_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// PARAM: private unnamed_addr constant [12 x i8] c"param_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// PARAM: private unnamed_addr constant [12 x i8] c"param_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// PARAM: private unnamed_addr constant [12 x i8] c"param_ann_{{.}}\00", section "llvm.metadata"
end_comment

begin_decl_stmt
name|int
name|foo
argument_list|(
name|int
name|v
name|__attribute__
argument_list|(
argument|(annotate(
literal|"param_ann_2"
argument|))
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"param_ann_3"
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|foo
argument_list|(
name|int
name|v
name|__attribute__
argument_list|(
argument|(annotate(
literal|"param_ann_0"
argument|))
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"param_ann_1"
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|v
operator|+
literal|1
return|;
comment|// PARAM: define {{.*}}@foo
comment|// PARAM:      [[V:%.*]] = alloca i32
comment|// PARAM:      bitcast i32* [[V]] to i8*
comment|// PARAM-NEXT: call void @llvm.var.annotation(
comment|// PARAM-NEXT: bitcast i32* [[V]] to i8*
comment|// PARAM-NEXT: call void @llvm.var.annotation(
comment|// PARAM-NEXT: bitcast i32* [[V]] to i8*
comment|// PARAM-NEXT: call void @llvm.var.annotation(
comment|// PARAM-NEXT: bitcast i32* [[V]] to i8*
comment|// PARAM-NEXT: call void @llvm.var.annotation(
block|}
end_decl_stmt

begin_function
name|void
name|local
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|localvar
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"localvar_ann_0"
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"localvar_ann_1"
argument_list|)
operator|)
argument_list|)
init|=
literal|3
decl_stmt|;
comment|// LOCAL-LABEL: define void @local()
comment|// LOCAL:      [[LOCALVAR:%.*]] = alloca i32,
comment|// LOCAL-NEXT: [[T0:%.*]] = bitcast i32* [[LOCALVAR]] to i8*
comment|// LOCAL-NEXT: call void @llvm.var.annotation(i8* [[T0]], i8* getelementptr inbounds ([15 x i8]* @{{.*}}), i8* getelementptr inbounds ({{.*}}), i32 33)
comment|// LOCAL-NEXT: [[T0:%.*]] = bitcast i32* [[LOCALVAR]] to i8*
comment|// LOCAL-NEXT: call void @llvm.var.annotation(i8* [[T0]], i8* getelementptr inbounds ([15 x i8]* @{{.*}}), i8* getelementptr inbounds ({{.*}}), i32 33)
block|}
end_function

begin_function
name|void
name|undef
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|undefvar
name|__attribute__
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"undefvar_ann_0"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// UNDEF-LABEL: define void @undef()
comment|// UNDEF:      [[UNDEFVAR:%.*]] = alloca i32,
comment|// UNDEF-NEXT: [[T0:%.*]] = bitcast i32* [[UNDEFVAR]] to i8*
comment|// UNDEF-NEXT: call void @llvm.var.annotation(i8* [[T0]], i8* getelementptr inbounds ([15 x i8]* @{{.*}}), i8* getelementptr inbounds ({{.*}}), i32 43)
block|}
end_function

end_unit

