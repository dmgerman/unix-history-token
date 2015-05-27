begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=legacy -emit-llvm -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: float 0x7FF4000000000000, float 0x7FF8000000000000
end_comment

begin_comment
comment|// CHECK: double 0x7FF4000000000000, double 0x7FF8000000000000
end_comment

begin_decl_stmt
name|float
name|f
index|[]
init|=
block|{
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
block|,
name|__builtin_nans
argument_list|(
literal|""
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
index|[]
init|=
block|{
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
block|,
name|__builtin_nans
argument_list|(
literal|""
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

end_unit

