begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|aligned_double
typedef|;
end_typedef

begin_decl_stmt
name|void
name|foo
argument_list|(
name|aligned_double
name|x
argument_list|,
name|double
operator|*
name|y
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{ }
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error@+1 {{requested alignment is not a power of 2}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|63
argument_list|)
operator|)
argument_list|)
name|aligned_double1
typedef|;
end_typedef

begin_comment
comment|// expected-error@+1 {{requested alignment is not a power of 2}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
operator|-
literal|2
argument_list|)
operator|)
argument_list|)
name|aligned_double2
typedef|;
end_typedef

begin_comment
comment|// expected-error@+1 {{attribute takes one argument}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|63
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
name|aligned_double3
typedef|;
end_typedef

begin_comment
comment|// expected-error@+1 {{attribute takes one argument}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|()
operator|)
argument_list|)
name|aligned_double3a
typedef|;
end_typedef

begin_comment
comment|// expected-error@+1 {{attribute takes one argument}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
operator|)
argument_list|)
name|aligned_double3b
typedef|;
end_typedef

begin_comment
comment|// expected-error@+1 {{'align_value' attribute requires integer constant}}
end_comment

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|4.5
argument_list|)
operator|)
argument_list|)
name|aligned_double4
typedef|;
end_typedef

begin_comment
comment|// expected-warning@+1 {{'align_value' attribute only applies to a pointer or reference ('int' is invalid)}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|aligned_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
modifier|*
name|__attribute__
argument_list|(
operator|(
name|align_value
argument_list|(
literal|32
operator|*
literal|2
argument_list|)
operator|)
argument_list|)
name|aligned_double5
typedef|;
end_typedef

begin_comment
comment|// expected-warning@+1 {{'align_value' attribute only applies to variables and typedefs}}
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(align_value
parameter_list|(
function_decl|32
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

