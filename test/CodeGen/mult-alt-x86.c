begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 -emit-llvm %s -o - | FileCheck %s
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

begin_decl_stmt
name|double
name|dout0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|din1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @single_R
end_comment

begin_function
name|void
name|single_R
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=R,R[[CLOBBERS:[a-zA-Z0-9@%{},~_ ]*\"]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=R" (mout0) : "R" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_q
end_comment

begin_function
name|void
name|single_q
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=q,q[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=q" (mout0) : "q" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_Q
end_comment

begin_function
name|void
name|single_Q
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=Q,Q[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=Q" (mout0) : "Q" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_a
end_comment

begin_function
name|void
name|single_a
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={ax},{ax}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=a" (mout0) : "a" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_b
end_comment

begin_function
name|void
name|single_b
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={bx},{bx}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=b" (mout0) : "b" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_c
end_comment

begin_function
name|void
name|single_c
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={cx},{cx}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=c" (mout0) : "c" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_d
end_comment

begin_function
name|void
name|single_d
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={dx},{dx}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=d" (mout0) : "d" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_S
end_comment

begin_function
name|void
name|single_S
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={si},{si}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=S" (mout0) : "S" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_D
end_comment

begin_function
name|void
name|single_D
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "={di},{di}[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=D" (mout0) : "D" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_A
end_comment

begin_function
name|void
name|single_A
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=A,A[[CLOBBERS]](i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=A" (mout0) : "A" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_f
end_comment

begin_function
name|void
name|single_f
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @single_t
end_comment

begin_function
name|void
name|single_t
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @single_u
end_comment

begin_function
name|void
name|single_u
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @single_y
end_comment

begin_function
name|void
name|single_y
parameter_list|()
block|{
comment|// CHECK: call double asm "foo $1,$0", "=y,y[[CLOBBERS]](double {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=y" (dout0) : "y" (din1));
block|}
end_function

begin_comment
comment|// CHECK: @single_x
end_comment

begin_function
name|void
name|single_x
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=x,x[[CLOBBERS]](double {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=x" (dout0) : "x" (din1));
block|}
end_function

begin_comment
comment|// CHECK: @single_Y
end_comment

begin_function
name|void
name|single_Y0
parameter_list|()
block|{
comment|// Y constraint currently broken.
comment|//asm("foo %1,%0" : "=Y0" (mout0) : "Y0" (min1));
comment|//asm("foo %1,%0" : "=Yz" (mout0) : "Yz" (min1));
comment|//asm("foo %1,%0" : "=Yt" (mout0) : "Yt" (min1));
comment|//asm("foo %1,%0" : "=Yi" (mout0) : "Yi" (min1));
comment|//asm("foo %1,%0" : "=Ym" (mout0) : "Ym" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @single_I
end_comment

begin_function
name|void
name|single_I
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,I[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "I" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_J
end_comment

begin_function
name|void
name|single_J
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,J[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "J" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_K
end_comment

begin_function
name|void
name|single_K
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,K[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "K" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_L
end_comment

begin_function
name|void
name|single_L
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,L[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "L" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_M
end_comment

begin_function
name|void
name|single_M
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,M[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "M" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_N
end_comment

begin_function
name|void
name|single_N
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,N[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "N" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_G
end_comment

begin_function
name|void
name|single_G
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,G[[CLOBBERS]](i32* @mout0, double {{1.[0]+e[+]*[0]+}})
asm|asm("foo %1,%0" : "=m" (mout0) : "G" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @single_C
end_comment

begin_function
name|void
name|single_C
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,C[[CLOBBERS]](i32* @mout0, double {{1.[0]+e[+]*[0]+}})
asm|asm("foo %1,%0" : "=m" (mout0) : "C" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @single_e
end_comment

begin_function
name|void
name|single_e
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,e[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "e" (1));
block|}
end_function

begin_comment
comment|// CHECK: @single_Z
end_comment

begin_function
name|void
name|single_Z
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*m,Z[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=m" (mout0) : "Z" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_R
end_comment

begin_function
name|void
name|multi_R
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|R|m,r|R|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=R,=m" (mout0) : "r,R,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_q
end_comment

begin_function
name|void
name|multi_q
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|q|m,r|q|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=q,=m" (mout0) : "r,q,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_Q
end_comment

begin_function
name|void
name|multi_Q
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|Q|m,r|Q|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=Q,=m" (mout0) : "r,Q,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_a
end_comment

begin_function
name|void
name|multi_a
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{ax}|m,r|{ax}|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=a,=m" (mout0) : "r,a,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_b
end_comment

begin_function
name|void
name|multi_b
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{bx}|m,r|{bx}|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=b,=m" (mout0) : "r,b,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_c
end_comment

begin_function
name|void
name|multi_c
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{cx}|m,r|{cx}|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=c,=m" (mout0) : "r,c,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_d
end_comment

begin_function
name|void
name|multi_d
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{dx}|m,r|{dx}[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=d,=m" (mout0) : "r,d" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_S
end_comment

begin_function
name|void
name|multi_S
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{si}|m,r|{si}|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=S,=m" (mout0) : "r,S,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_D
end_comment

begin_function
name|void
name|multi_D
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|{di}|m,r|{di}|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=D,=m" (mout0) : "r,D,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_A
end_comment

begin_function
name|void
name|multi_A
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|A|m,r|A|m[[CLOBBERS]](i32* @mout0, i32 {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=A,=m" (mout0) : "r,A,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_f
end_comment

begin_function
name|void
name|multi_f
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @multi_t
end_comment

begin_function
name|void
name|multi_t
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @multi_u
end_comment

begin_function
name|void
name|multi_u
parameter_list|()
block|{
comment|//FIXME: I don't know how to do an 80387 floating point stack register operation, which I think is fp80.
block|}
end_function

begin_comment
comment|// CHECK: @multi_y
end_comment

begin_function
name|void
name|multi_y
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|y|m,r|y|m[[CLOBBERS]](double* @dout0, double {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=y,=m" (dout0) : "r,y,m" (din1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_x
end_comment

begin_function
name|void
name|multi_x
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|x|m,r|x|m[[CLOBBERS]](double* @dout0, double {{[a-zA-Z0-9@%]+}})
asm|asm("foo %1,%0" : "=r,=x,=m" (dout0) : "r,x,m" (din1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_Y
end_comment

begin_function
name|void
name|multi_Y0
parameter_list|()
block|{
comment|// Y constraint currently broken.
comment|//asm("foo %1,%0" : "=r,=Y0,=m" (mout0) : "r,Y0,m" (min1));
comment|//asm("foo %1,%0" : "=r,=Yz,=m" (mout0) : "r,Yz,m" (min1));
comment|//asm("foo %1,%0" : "=r,=Yt,=m" (mout0) : "r,Yt,m" (min1));
comment|//asm("foo %1,%0" : "=r,=Yi,=m" (mout0) : "r,Yi,m" (min1));
comment|//asm("foo %1,%0" : "=r,=Ym,=m" (mout0) : "r,Ym,m" (min1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_I
end_comment

begin_function
name|void
name|multi_I
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|I|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,I,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_J
end_comment

begin_function
name|void
name|multi_J
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|J|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,J,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_K
end_comment

begin_function
name|void
name|multi_K
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|K|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,K,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_L
end_comment

begin_function
name|void
name|multi_L
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|L|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,L,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_M
end_comment

begin_function
name|void
name|multi_M
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|M|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,M,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_N
end_comment

begin_function
name|void
name|multi_N
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|N|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,N,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_G
end_comment

begin_function
name|void
name|multi_G
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|G|m[[CLOBBERS]](i32* @mout0, double {{1.[0]+e[+]*[0]+}})
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,G,m" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @multi_C
end_comment

begin_function
name|void
name|multi_C
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|C|m[[CLOBBERS]](i32* @mout0, double {{1.[0]+e[+]*[0]+}})
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,C,m" (1.0));
block|}
end_function

begin_comment
comment|// CHECK: @multi_e
end_comment

begin_function
name|void
name|multi_e
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|e|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,e,m" (1));
block|}
end_function

begin_comment
comment|// CHECK: @multi_Z
end_comment

begin_function
name|void
name|multi_Z
parameter_list|()
block|{
comment|// CHECK: asm "foo $1,$0", "=*r|m|m,r|Z|m[[CLOBBERS]](i32* @mout0, i32 1)
asm|asm("foo %1,%0" : "=r,=m,=m" (mout0) : "r,Z,m" (1));
block|}
end_function

end_unit

