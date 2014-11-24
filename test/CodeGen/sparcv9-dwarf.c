begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple sparcv9-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|dwarf_reg_size_table
index|[
literal|102
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test
parameter_list|()
block|{
name|__builtin_init_dwarf_reg_size_table
argument_list|(
name|dwarf_reg_size_table
argument_list|)
expr_stmt|;
return|return
name|__builtin_dwarf_sp_column
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i32 @test()
end_comment

begin_comment
comment|// CHECK:       store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 0)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 1)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 2)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 3)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 4)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 5)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 6)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 7)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 8)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 9)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 10)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 11)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 12)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 13)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 14)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 15)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 16)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 17)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 18)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 19)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 20)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 21)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 22)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 23)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 24)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 25)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 26)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 27)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 28)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 29)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 30)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 31)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 32)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 33)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 34)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 35)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 36)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 37)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 38)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 39)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 40)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 41)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 42)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 43)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 44)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 45)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 46)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 47)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 48)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 49)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 50)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 51)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 52)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 53)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 54)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 55)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 56)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 57)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 58)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 59)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 60)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 61)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 62)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 4, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 63)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 64)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 65)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 66)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 67)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 68)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 69)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 70)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 71)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 72)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 73)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 74)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 75)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 76)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 77)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 78)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 79)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 80)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 81)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 82)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 83)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 84)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 85)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 86)
end_comment

begin_comment
comment|// CHECK-NEXT:  store i8 8, i8* getelementptr inbounds ([103 x i8]* @dwarf_reg_size_table, i32 0, i32 87)
end_comment

begin_comment
comment|// CHECK-NEXT:  ret i32 14
end_comment

end_unit

