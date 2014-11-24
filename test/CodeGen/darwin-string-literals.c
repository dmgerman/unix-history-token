begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix CHECK-LSB %s
end_comment

begin_comment
comment|// CHECK-LSB: @.str = private unnamed_addr constant [8 x i8] c"string0\00"
end_comment

begin_comment
comment|// CHECK-LSB: @.str1 = private unnamed_addr constant [8 x i8] c"string1\00"
end_comment

begin_comment
comment|// CHECK-LSB: @.str2 = private unnamed_addr constant [18 x i16] [i16 104, i16 101, i16 108, i16 108, i16 111, i16 32, i16 8594, i16 32, i16 9731, i16 32, i16 8592, i16 32, i16 119, i16 111, i16 114, i16 108, i16 100, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_comment
comment|// CHECK-LSB: @.str4 = private unnamed_addr constant [6 x i16] [i16 116, i16 101, i16 115, i16 116, i16 8482, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix CHECK-MSB %s
end_comment

begin_comment
comment|// CHECK-MSB: @.str = private unnamed_addr constant [8 x i8] c"string0\00"
end_comment

begin_comment
comment|// CHECK-MSB: @.str1 = private unnamed_addr constant [8 x i8] c"string1\00"
end_comment

begin_comment
comment|// CHECK-MSB: @.str2 = private unnamed_addr constant [18 x i16] [i16 104, i16 101, i16 108, i16 108, i16 111, i16 32, i16 8594, i16 32, i16 9731, i16 32, i16 8592, i16 32, i16 119, i16 111, i16 114, i16 108, i16 100, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_comment
comment|// CHECK-MSB: @.str4 = private unnamed_addr constant [6 x i16] [i16 116, i16 101, i16 115, i16 116, i16 8482, i16 0], section "__TEXT,__ustring", align 2
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|g0
init|=
literal|"string0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|void
modifier|*
name|g1
init|=
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"string1"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|void
modifier|*
name|g2
init|=
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"hello \u2192 \u2603 \u2190 world"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|void
modifier|*
name|g3
init|=
name|__builtin___CFStringMakeConstantString
argument_list|(
literal|"testâ¢"
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

