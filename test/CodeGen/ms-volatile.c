begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 -fms-extensions -emit-llvm -fms-volatile -o -< %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|foo
block|{
specifier|volatile
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bar
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|__declspec
typedef|(
name|align
typedef|(8))
name|baz
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_struct
struct|struct
name|qux
block|{
specifier|volatile
name|int
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_function
name|void
name|test1
parameter_list|(
name|struct
name|foo
modifier|*
name|p
parameter_list|,
name|struct
name|foo
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test1
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|,
specifier|volatile
name|int
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test2
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|struct
name|foo
modifier|*
name|p
parameter_list|,
name|struct
name|foo
modifier|*
name|q
parameter_list|)
block|{
name|p
operator|->
name|x
operator|=
name|q
operator|->
name|x
expr_stmt|;
comment|// CHECK-LABEL: @test3
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
specifier|volatile
name|struct
name|foo
modifier|*
name|p
parameter_list|,
specifier|volatile
name|struct
name|foo
modifier|*
name|q
parameter_list|)
block|{
name|p
operator|->
name|x
operator|=
name|q
operator|->
name|x
expr_stmt|;
comment|// CHECK-LABEL: @test4
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test5
parameter_list|(
specifier|volatile
name|struct
name|foo
modifier|*
name|p
parameter_list|,
specifier|volatile
name|struct
name|foo
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test5
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test6
parameter_list|(
name|struct
name|bar
modifier|*
name|p
parameter_list|,
name|struct
name|bar
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test6
comment|// CHECK-NOT: load atomic volatile {{.*}}
comment|// CHECK-NOT: store atomic volatile {{.*}}, {{.*}}
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
specifier|volatile
name|struct
name|bar
modifier|*
name|p
parameter_list|,
specifier|volatile
name|struct
name|bar
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test7
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|void
name|test8
parameter_list|(
specifier|volatile
name|double
modifier|*
name|p
parameter_list|,
specifier|volatile
name|double
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test8
comment|// CHECK: load volatile {{.*}}
comment|// CHECK: store volatile {{.*}}, {{.*}}
block|}
end_function

begin_function
name|void
name|test9
parameter_list|(
specifier|volatile
name|baz
modifier|*
name|p
parameter_list|,
name|baz
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test9
comment|// CHECK: store volatile {{.*}}, {{.*}}
comment|// CHECK: store volatile {{.*}}, {{.*}}
block|}
end_function

begin_function
name|void
name|test10
parameter_list|(
specifier|volatile
name|long
name|long
modifier|*
name|p
parameter_list|,
specifier|volatile
name|long
name|long
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test10
comment|// CHECK: load volatile {{.*}}
comment|// CHECK: store volatile {{.*}}, {{.*}}
block|}
end_function

begin_function
name|void
name|test11
parameter_list|(
specifier|volatile
name|float
modifier|*
name|p
parameter_list|,
specifier|volatile
name|float
modifier|*
name|q
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|*
name|q
expr_stmt|;
comment|// CHECK-LABEL: @test11
comment|// CHECK: load atomic volatile {{.*}} acquire
comment|// CHECK: store atomic volatile {{.*}}, {{.*}} release
block|}
end_function

begin_function
name|int
name|test12
parameter_list|(
name|struct
name|qux
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
operator|->
name|f
return|;
comment|// CHECK-LABEL: @test12
comment|// CHECK: load volatile {{.*}}
block|}
end_function

end_unit

