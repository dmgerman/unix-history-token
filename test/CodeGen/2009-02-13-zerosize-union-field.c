begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple i686-apple-darwin -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Every printf has 'i32 0' for the GEP of the string; no point counting those.
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
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0), i32 0
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
comment|// CHECK: getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0), i32 1
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
comment|// CHECK: getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0), i32 4
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
comment|// CHECK: getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0), i32 4
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

