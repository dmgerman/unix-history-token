begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=FOO %s< %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=A %s< %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=BAR %s< %t1
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=FOOS %s< %t1
end_comment

begin_comment
comment|// END.
end_comment

begin_expr_stmt
specifier|static
name|__attribute
argument_list|(
argument|(annotate(
literal|"sfoo_0"
argument|))
argument_list|)
name|__attribute
argument_list|(
argument|(annotate(
literal|"sfoo_1"
argument|))
argument_list|)
name|char
name|sfoo
expr_stmt|;
end_expr_stmt

begin_macro
name|__attribute
argument_list|(
argument|(annotate(
literal|"foo_0"
argument|))
argument_list|)
end_macro

begin_macro
name|__attribute
argument_list|(
argument|(annotate(
literal|"foo_1"
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|char
name|foo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_0"
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_1"
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_2"
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_3"
argument_list|)
operator|)
argument_list|)
name|a
argument_list|(
name|char
operator|*
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_0"
argument_list|)
operator|)
argument_list|)
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"ann_a_1"
argument_list|)
operator|)
argument_list|)
name|a
argument_list|(
name|char
operator|*
name|a
argument_list|)
block|{
name|__attribute__
argument_list|(
argument|(annotate(
literal|"bar_0"
argument|))
argument_list|)
name|__attribute__
argument_list|(
argument|(annotate(
literal|"bar_1"
argument|))
argument_list|)
specifier|static
name|char
name|bar
decl_stmt|;
name|sfoo
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// FOOS: target triple
end_comment

begin_comment
comment|// FOOS: private unnamed_addr constant [7 x i8] c"sfoo_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// FOOS: private unnamed_addr constant [7 x i8] c"sfoo_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// FOOS-NOT: sfoo_
end_comment

begin_comment
comment|// FOOS: @llvm.global.annotations = appending global [10 x { i8*, i8*, i8*, i32 }] {{.*}}i8* @sfoo{{.*}}i8* @sfoo{{.*}}, section "llvm.metadata"
end_comment

begin_comment
comment|// FOO: target triple
end_comment

begin_comment
comment|// FOO: private unnamed_addr constant [6 x i8] c"foo_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// FOO: private unnamed_addr constant [6 x i8] c"foo_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// FOO-NOT: foo_
end_comment

begin_comment
comment|// FOO: @llvm.global.annotations = appending global [10 x { i8*, i8*, i8*, i32 }] {{.*}}i8* @foo{{.*}}i8* @foo{{.*}}, section "llvm.metadata"
end_comment

begin_comment
comment|// A: target triple
end_comment

begin_comment
comment|// A: private unnamed_addr constant [8 x i8] c"ann_a_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// A: private unnamed_addr constant [8 x i8] c"ann_a_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// A: private unnamed_addr constant [8 x i8] c"ann_a_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// A: private unnamed_addr constant [8 x i8] c"ann_a_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// A-NOT: ann_a_
end_comment

begin_comment
comment|// A: @llvm.global.annotations = appending global [10 x { i8*, i8*, i8*, i32 }] {{.*}}i8* bitcast (void (i8*)* @a to i8*){{.*}}i8* bitcast (void (i8*)* @a to i8*){{.*}}i8* bitcast (void (i8*)* @a to i8*){{.*}}i8* bitcast (void (i8*)* @a to i8*){{.*}}, section "llvm.metadata"
end_comment

begin_comment
comment|// BAR: target triple
end_comment

begin_comment
comment|// BAR: private unnamed_addr constant [6 x i8] c"bar_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// BAR: private unnamed_addr constant [6 x i8] c"bar_{{.}}\00", section "llvm.metadata"
end_comment

begin_comment
comment|// BAR-NOT: bar_
end_comment

begin_comment
comment|// BAR: @llvm.global.annotations = appending global [10 x { i8*, i8*, i8*, i32 }] {{.*}}i8* @a.bar{{.*}}i8* @a.bar{{.*}}, section "llvm.metadata"
end_comment

end_unit

