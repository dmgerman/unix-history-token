begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -Wunused -fsyntax-only %s
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|fp0
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|f0
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// On K&R
end_comment

begin_function_decl
name|int
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'unused' attribute takes no arguments}}
end_comment

begin_struct
struct|struct
name|Test0_unused
block|{}
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|Test0_not_unused
block|{}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|Int_unused
name|__attribute__
typedef|((
name|unused
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|Int_not_unused
typedef|;
end_typedef

begin_function
name|void
name|test0
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|// expected-warning {{unused variable}}
name|Int_not_unused
name|i0
decl_stmt|;
comment|// expected-warning {{unused variable}}
name|Int_unused
name|i1
decl_stmt|;
comment|// expected-warning {{'Int_unused' was marked unused but was used}}
name|struct
name|Test0_not_unused
name|s0
decl_stmt|;
comment|// expected-warning {{unused variable}}
name|struct
name|Test0_unused
name|s1
decl_stmt|;
comment|// expected-warning {{'Test0_unused' was marked unused but was used}}
block|}
end_function

begin_function
name|int
name|f3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// expected-warning{{unused parameter 'x'}}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|f4
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_decl_stmt
name|int
name|f5
argument_list|(
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|f6
argument_list|(
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|x
return|;
comment|// expected-warning{{'x' was marked unused but was used}}
block|}
end_decl_stmt

end_unit

