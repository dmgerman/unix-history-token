begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -analyze -analyzer-experimental-internal-checks -checker-cfref -analyzer-store=basic %s
end_comment

begin_struct
struct|struct
name|tea_cheese
block|{
name|unsigned
name|magic
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tea_cheese
name|kernel_tea_cheese_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|kernel_tea_cheese_t
name|_wonky_gesticulate_cheese
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This test case exercises the ElementRegion::getRValueType() logic.
end_comment

begin_comment
comment|// All it tests is that it does not crash or do anything weird.
end_comment

begin_comment
comment|// The out-of-bounds-access on line 19 is caught using the region store variant.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|kernel_tea_cheese_t
modifier|*
name|wonky
init|=
operator|&
name|_wonky_gesticulate_cheese
decl_stmt|;
name|struct
name|load_wine
modifier|*
name|cmd
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|wonky
index|[
literal|1
index|]
decl_stmt|;
name|cmd
operator|=
name|cmd
expr_stmt|;
name|char
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
operator|&
name|wonky
index|[
literal|1
index|]
decl_stmt|;
operator|*
name|p
operator|=
literal|1
expr_stmt|;
name|kernel_tea_cheese_t
modifier|*
name|q
init|=
operator|&
name|wonky
index|[
literal|1
index|]
decl_stmt|;
name|kernel_tea_cheese_t
name|r
init|=
operator|*
name|q
decl_stmt|;
comment|// no-warning
block|}
end_function

end_unit

