begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -emit-llvm -o - | grep 0x3BFD83C940000000 | count 2&&
end_comment

begin_comment
comment|// RUN: clang-cc %s -emit-llvm -o - | grep 2.000000e+32 | count 2
end_comment

begin_decl_stmt
name|float
name|F
init|=
literal|1e-19f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|D
init|=
literal|2e32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|F2
init|=
literal|01e-19f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|D2
init|=
literal|02e32
decl_stmt|;
end_decl_stmt

end_unit

