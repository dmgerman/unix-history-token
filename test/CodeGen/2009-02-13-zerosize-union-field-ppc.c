begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple powerpc-pc-linux -emit-llvm -o - | grep {i32 32} | count 3
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|//  Every printf has 'i32 0' for the GEP of the string; no point counting those.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Foo
name|__attribute__
typedef|((
name|aligned
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Foo
label|:
literal|0
expr_stmt|;
block|}
name|a
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|x
decl_stmt|;
name|Foo
label|:
literal|0
expr_stmt|;
block|}
name|b
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
name|__alignof__
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%ld\n"
argument_list|,
name|__alignof__
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

