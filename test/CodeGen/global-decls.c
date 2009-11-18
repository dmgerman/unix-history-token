begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-pc-linux-gnu -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g0_ext = extern_weak global i32' %t
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g0_ext
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep 'declare extern_weak i32 @g1_ext()' %t
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|g1_ext
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep '@g0_common = weak global i32' %t
end_comment

begin_decl_stmt
name|int
name|g0_common
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep '@g0_def = weak global i32' %t
end_comment

begin_decl_stmt
name|int
name|g0_def
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
init|=
literal|52
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep 'define weak i32 @g1_def()' %t
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|g1_def
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|// Force _ext references
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|int
name|a
init|=
name|g0_ext
decl_stmt|;
name|int
name|b
init|=
name|g1_ext
argument_list|()
decl_stmt|;
block|}
end_function

end_unit

