begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c11 %s -fsyntax-only -verify -pedantic
end_comment

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
name|int
name|atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
specifier|_Atomic
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|atomic_int
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{duplicate '_Atomic' declaration specifier}}
end_comment

begin_typedef
typedef|typedef
specifier|const
name|int
name|const_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|atomic_int
name|const_atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
specifier|const
name|int
name|const_atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
specifier|_Atomic
name|int
name|const_atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|const_atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
atomic|_Atomic
argument_list|(
type|_Atomic
name|int
typedef|) const_atomic_int;
end_typedef

begin_comment
comment|// expected-error {{_Atomic cannot be applied to atomic type '_Atomic(int)'}}
end_comment

begin_typedef
typedef|typedef
specifier|_Atomic
name|const_int
name|const_atomic_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|const_int
argument_list|)
name|const_atomic_int
typedef|;
end_typedef

begin_comment
comment|// expected-error {{_Atomic cannot be applied to qualified type 'const_int' (aka 'const int')}}
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
specifier|_Atomic
name|atomic_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
operator|*
argument_list|)
name|atomic_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
expr|_Atomic
name|atomic_int_ptr
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
specifier|_Atomic
modifier|*
name|int_atomic_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|int_atomic_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int_fn
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
name|int_fn
name|atomic_int_fn
typedef|;
end_typedef

begin_comment
comment|// expected-error {{_Atomic cannot be applied to function type 'int_fn' (aka 'int ()')}}
end_comment

begin_typedef
typedef|typedef
specifier|_Atomic
name|int
name|atomic_int_array
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
name|atomic_int_array
name|atomic_int_atomic_array
typedef|;
end_typedef

begin_comment
comment|// expected-error {{_Atomic cannot be applied to array type 'atomic_int_array' (aka '_Atomic(int) [3]')}}
end_comment

begin_struct
specifier|_Atomic
struct|struct
name|S
block|{
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'_Atomic' ignored on this declaration}}
end_comment

begin_typedef
typedef|typedef
specifier|_Atomic
name|int
name|__attribute__
typedef|((
name|address_space
typedef|(1)))
name|atomic_addr_space_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
name|atomic_addr_space_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Atomic
name|int
name|__attribute__
typedef|((
name|vector_size
typedef|(16)))
name|atomic_vector_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
atomic|_Atomic
argument_list|(
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
argument_list|)
name|atomic_vector_int
typedef|;
end_typedef

begin_decl_stmt
name|struct
name|S
specifier|_Atomic
name|atomic_s_no_missing_semicolon
decl_stmt|;
end_decl_stmt

end_unit

