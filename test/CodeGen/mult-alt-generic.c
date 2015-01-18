begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparcv9 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumb %s -emit-llvm -o - | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|mout0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|min1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|marray
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @single_m
end_comment

begin_function
name|void
name|single_m
parameter_list|()
block|{
comment|// CHECK: call void asm "foo $1,$0", "=*m,*m[[CLOBBERS:[a-zA-Z0-9@%{},~_$ ]*\"]](i32* {{[a-zA-Z0-9@%]+}}, i32* {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=m" (mout0) : "m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_o
end_comment

begin_function
name|void
name|single_o
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|index
init|=
literal|1
decl_stmt|;
comment|// Doesn't really do an offset...
comment|//asm("foo %1, %2,%0" : "=r" (out0) : "o" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_V
end_comment

begin_function
name|void
name|single_V
parameter_list|()
block|{
comment|//  asm("foo %1,%0" : "=m" (mout0) : "V" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_lt
end_comment

begin_function
name|void
name|single_lt
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,<r[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "<r" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,r<[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "r<" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @single_gt
end_comment

begin_function
name|void
name|single_gt
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,>r[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : ">r" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,r>[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "r>" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @single_r
end_comment

begin_function
name|void
name|single_r
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,r[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "r" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @single_i
end_comment

begin_function
name|void
name|single_i
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,i[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r" (out0) : "i" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_n
end_comment

begin_function
name|void
name|single_n
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,n[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r" (out0) : "n" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_E
end_comment

begin_function
name|void
name|single_E
parameter_list|()
block|{
specifier|register
name|double
name|out0
init|=
literal|0.0
decl_stmt|;
comment|// CHECK: call double asm "foo $1,$0", "=r,E[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "E" (1.0e+01));
block|}
end_function

begin_comment
comment|// CHECK: @single_F
end_comment

begin_function
name|void
name|single_F
parameter_list|()
block|{
specifier|register
name|double
name|out0
init|=
literal|0.0
decl_stmt|;
comment|// CHECK: call double asm "foo $1,$0", "=r,F[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "F" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @single_s
end_comment

begin_function
name|void
name|single_s
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|//asm("foo %1,%0" : "=r" (out0) : "s" (single_s));
block|}
end_function

begin_comment
comment|// CHECK: @single_g
end_comment

begin_function
name|void
name|single_g
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,imr[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "g" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,imr[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "g" (min1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,imr[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r" (out0) : "g" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_X
end_comment

begin_function
name|void
name|single_X
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "X" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "X" (min1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r" (out0) : "X" (1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](i32* getelementptr inbounds ([2 x i32]* {{[a-zA-Z0-9@%]+}}, i32 0, i32 0))
asm|asm("foo %1,%0" : "=r" (out0) : "X" (marray));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "X" (1.0e+01));
comment|// CHECK: call i32 asm "foo $1,$0", "=r,X[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r" (out0) : "X" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @single_p
end_comment

begin_function
name|void
name|single_p
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// Constraint converted differently on different platforms moved to platform-specific.
comment|// : call i32 asm "foo $1,$0", "=r,im[[CLOBBERS]](i32* getelementptr inbounds ([2 x i32]* {{[a-zA-Z0-9@%]+}}, i32 0, i32 0))
asm|asm("foo %1,%0" : "=r" (out0) : "p" (marray));
block|}
end_function

begin_comment
comment|// CHECK: @multi_m
end_comment

begin_function
name|void
name|multi_m
parameter_list|()
block|{
comment|// CHECK: call void asm "foo $1,$0", "=*m|r,m|r[[CLOBBERS]](i32* {{[a-zA-Z0-9@%]+}}, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=m,r" (mout0) : "m,r" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_o
end_comment

begin_function
name|void
name|multi_o
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|index
init|=
literal|1
decl_stmt|;
comment|// Doesn't really do an offset...
comment|//asm("foo %1, %2,%0" : "=r,r" (out0) : "r,o" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_V
end_comment

begin_function
name|void
name|multi_V
parameter_list|()
block|{
comment|//  asm("foo %1,%0" : "=m,r" (mout0) : "r,V" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_lt
end_comment

begin_function
name|void
name|multi_lt
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|<r[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,<r" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|r<[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,r<" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_gt
end_comment

begin_function
name|void
name|multi_gt
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|>r[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,>r" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|r>[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,r>" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_r
end_comment

begin_function
name|void
name|multi_r
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|m[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,m" (in1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_i
end_comment

begin_function
name|void
name|multi_i
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|i[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,i" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_n
end_comment

begin_function
name|void
name|multi_n
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|n[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,n" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_E
end_comment

begin_function
name|void
name|multi_E
parameter_list|()
block|{
specifier|register
name|double
name|out0
init|=
literal|0.0
decl_stmt|;
comment|// CHECK: call double asm "foo $1,$0", "=r|r,r|E[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,E" (1.0e+01));
block|}
end_function

begin_comment
comment|// CHECK: @multi_F
end_comment

begin_function
name|void
name|multi_F
parameter_list|()
block|{
specifier|register
name|double
name|out0
init|=
literal|0.0
decl_stmt|;
comment|// CHECK: call double asm "foo $1,$0", "=r|r,r|F[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,F" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @multi_s
end_comment

begin_function
name|void
name|multi_s
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|//asm("foo %1,%0" : "=r,r" (out0) : "r,s" (multi_s));
block|}
end_function

begin_comment
comment|// CHECK: @multi_g
end_comment

begin_function
name|void
name|multi_g
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|imr[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,g" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|imr[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,g" (min1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|imr[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,g" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_X
end_comment

begin_function
name|void
name|multi_X
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|in1
init|=
literal|1
decl_stmt|;
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (in1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (min1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](i32 1)
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (1));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](i32* getelementptr inbounds ([2 x i32]* {{[a-zA-Z0-9@%]+}}, i32 0, i32 0))
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (marray));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (1.0e+01));
comment|// CHECK: call i32 asm "foo $1,$0", "=r|r,r|X[[CLOBBERS]](double {{[0-9.eE+-]+}})
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,X" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @multi_p
end_comment

begin_function
name|void
name|multi_p
parameter_list|()
block|{
specifier|register
name|int
name|out0
init|=
literal|0
decl_stmt|;
comment|// Constraint converted differently on different platforms moved to platform-specific.
comment|// : call i32 asm "foo $1,$0", "=r|r,r|im[[CLOBBERS]](i32* getelementptr inbounds ([2 x i32]* {{[a-zA-Z0-9@%]+}}, i32 0, i32 0))
asm|asm("foo %1,%0" : "=r,r" (out0) : "r,p" (marray));
block|}
end_function

end_unit

