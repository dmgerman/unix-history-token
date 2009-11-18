begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix LSB %s
end_comment

begin_comment
comment|// CHECK-LSB: @.str = private constant [8 x i8] c"string0\00"
end_comment

begin_comment
comment|// CHECK-LSB: @.str1 = private constant [8 x i8] c"string1\00"
end_comment

begin_comment
comment|// CHECK-LSB: @.str2 = internal constant [36 x i8] c"h\00e\00l\00l\00o\00 \00\92! \00\03& \00\90! \00w\00o\00r\00l\00d\00\00\00", section "__TEXT,__ustring", align 2
end_comment

begin_comment
comment|// RUN: clang-cc -triple powerpc-apple-darwin9 -emit-llvm %s -o - | FileCheck -check-prefix MSB %s
end_comment

begin_comment
comment|// CHECK-MSB: @.str = private constant [8 x i8] c"string0\00"
end_comment

begin_comment
comment|// CHECK-MSB: @.str1 = private constant [8 x i8] c"string1\00"
end_comment

begin_comment
comment|// CHECK-MSB: @.str2 = internal constant [36 x i8] c"\00h\00e\00l\00l\00o\00 !\92\00&\03\00 !\90\00 \00w\00o\00r\00l\00d\00\00", section "__TEXT,__ustring", align 2
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

