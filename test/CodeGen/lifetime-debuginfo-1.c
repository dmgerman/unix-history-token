begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple x86_64-none-linux-gnu -emit-llvm -debug-info-kind=line-tables-only %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Inserting lifetime markers should not affect debuginfo
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @f
end_comment

begin_function
name|int
name|f
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
operator|&
name|x
decl_stmt|;
comment|// CHECK: ret i32 %{{.*}}, !dbg [[DI:![0-9]*]]
comment|// CHECK: [[DI]] = !DILocation(line: [[@LINE+1]]
return|return
operator|*
name|p
return|;
block|}
end_function

end_unit

