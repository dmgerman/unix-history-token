begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-linux-gnu -w %s -emit-llvm -o -
end_comment

begin_comment
comment|// PR854
end_comment

begin_struct
struct|struct
name|kernel_symbol
block|{
name|unsigned
name|long
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|unsigned
name|long
name|loops_per_jiffy
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|__kstrtab_loops_per_jiffy
index|[]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"__ksymtab_strings"
argument_list|)
operator|)
argument_list|)
init|=
literal|"loops_per_jiffy"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|kernel_symbol
name|__ksymtab_loops_per_jiffy
name|__attribute__
argument_list|(
operator|(
name|__used__
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|"__ksymtab"
argument_list|)
operator|)
argument_list|)
init|=
block|{
operator|(
name|unsigned
name|long
operator|)
operator|&
name|loops_per_jiffy
block|,
name|__kstrtab_loops_per_jiffy
block|}
decl_stmt|;
end_decl_stmt

end_unit

