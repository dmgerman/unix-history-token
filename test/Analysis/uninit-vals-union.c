begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core.builtin -analyzer-store=region -verify -Wno-unused %s
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|y
decl_stmt|;
block|}
name|U
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
block|}
name|A
typedef|;
end_typedef

begin_function
name|void
name|foo
parameter_list|()
block|{
name|U
name|u
init|=
block|{}
decl_stmt|;
name|A
modifier|*
name|a
init|=
operator|&
name|u
decl_stmt|;
comment|// expected-warning{{incompatible pointer types}}
name|a
operator|->
name|x
expr_stmt|;
comment|// no-crash
block|}
end_function

end_unit

