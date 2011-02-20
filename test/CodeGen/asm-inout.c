begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR3800
end_comment

begin_function_decl
name|int
modifier|*
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK: [[REGCALLRESULT:%[a-zA-Z0-9\.]+]] = call i32* @foo()
comment|// CHECK: call void asm "foobar", "=*m,*m,~{dirflag},~{fpsr},~{flags}"(i32* [[REGCALLRESULT]], i32* [[REGCALLRESULT]])
asm|asm ("foobar" : "+m"(*foo()));
block|}
end_function

begin_comment
comment|// CHECK: @test2
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// CHECK: [[REGCALLRESULT:%[a-zA-Z0-9\.]+]] = call i32* @foo()
comment|// CHECK: load i32* [[REGCALLRESULT]]
comment|// CHECK: call i32 asm
comment|// CHECK: store i32 {{%[a-zA-Z0-9\.]+}}, i32* [[REGCALLRESULT]]
asm|asm ("foobar" : "+r"(*foo()));
block|}
end_function

begin_comment
comment|// PR7338
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
modifier|*
name|vout
parameter_list|,
name|int
name|vin
parameter_list|)
block|{
comment|// CHECK: call void asm "opr $0,$1", "=*r|m|r,r|m|r,~{di},~{dirflag},~{fpsr},~{flags}"
asm|asm( 		"opr %[vout],%[vin]" 		: [vout] "=r,=m,=r" (*vout) 		: [vin] "r,m,r" (vin) 		: "edi" 		);
block|}
end_function

end_unit

