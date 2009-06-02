begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-apple-darwin9 -emit-llvm %s -o %t&&
end_comment

begin_comment
comment|// RUN: grep -F '@"\01LC" = internal constant [8 x i8] c"string0\00"' %t&&
end_comment

begin_comment
comment|// RUN: grep -F '@"\01LC1" = internal constant [8 x i8] c"string1\00", section "__TEXT,__cstring,cstring_literals"' %t&&
end_comment

begin_comment
comment|// RUN: grep -F '@__utf16_string_ = internal global [35 x i8] c"h\00e\00l\00l\00o\00 \00\92! \00\03& \00\90! \00w\00o\00r\00l\00d\00\00", section "__TEXT,__ustring", align 2' %t&&
end_comment

begin_comment
comment|// RUN: true
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

end_unit

