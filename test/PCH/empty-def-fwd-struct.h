begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -x c++-header %s -std=c++14 -o %t.pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm-only -x c++ /dev/null -std=c++14 -include-pch %t.pch -o %t.o
end_comment

begin_struct_decl
struct_decl|struct
name|FVector
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|FVector
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|FBox
block|{
name|FVector
name|Min
decl_stmt|;
name|FBox
argument_list|(
name|int
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|namespace
end_macro

begin_block
block|{
name|FBox
name|InvalidBoundingBox
argument_list|(
literal|0
argument_list|)
decl_stmt|;
block|}
end_block

end_unit

