begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-unknown-linux -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=sw0"
argument_list|)
operator|)
argument_list|)
name|isr_sw0
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_sw0() [[SW0:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=sw1"
argument_list|)
operator|)
argument_list|)
name|isr_sw1
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_sw1() [[SW1:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw0"
argument_list|)
operator|)
argument_list|)
name|isr_hw0
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw0() [[HW0:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw1"
argument_list|)
operator|)
argument_list|)
name|isr_hw1
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw1() [[HW1:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw2"
argument_list|)
operator|)
argument_list|)
name|isr_hw2
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw2() [[HW2:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw3"
argument_list|)
operator|)
argument_list|)
name|isr_hw3
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw3() [[HW3:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw4"
argument_list|)
operator|)
argument_list|)
name|isr_hw4
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw4() [[HW4:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
argument_list|(
literal|"vector=hw5"
argument_list|)
operator|)
argument_list|)
name|isr_hw5
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_hw5() [[HW5:#[0-9]+]]
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|interrupt
operator|)
argument_list|)
name|isr_eic
argument_list|(
name|void
argument_list|)
block|{
comment|// CHECK: define void @isr_eic() [[EIC:#[0-9]+]]
block|}
end_decl_stmt

begin_comment
comment|// CHECK: attributes [[SW0]] = { {{.*}} "interrupt"="sw0" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[SW1]] = { {{.*}} "interrupt"="sw1" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW0]] = { {{.*}} "interrupt"="hw0" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW1]] = { {{.*}} "interrupt"="hw1" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW2]] = { {{.*}} "interrupt"="hw2" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW3]] = { {{.*}} "interrupt"="hw3" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW4]] = { {{.*}} "interrupt"="hw4" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[HW5]] = { {{.*}} "interrupt"="hw5" {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[EIC]] = { {{.*}} "interrupt"="eic" {{.*}} }
end_comment

end_unit

