begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-apple-darwin9 %s -DHAVE
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-linux-gnu %s -DHAVE_NOT
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE
end_ifdef

begin_typedef
typedef|typedef
name|int
name|i128
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|TI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|u128
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|TI
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|a
index|[
operator|(
operator|(
name|i128
operator|)
operator|-
literal|1
operator|^
operator|(
name|i128
operator|)
operator|-
literal|2
operator|)
operator|==
literal|1
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
index|[
operator|(
name|u128
operator|)
operator|-
literal|1
operator|>
literal|1LL
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
index|[
name|__SIZEOF_INT128__
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR5435
end_comment

begin_decl_stmt
name|__uint128_t
name|b
init|=
operator|(
name|__uint128_t
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR11916: Support for libstdc++ 4.7
end_comment

begin_decl_stmt
name|__int128
name|i
init|=
operator|(
name|__int128
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|__int128
name|u
init|=
operator|(
name|unsigned
name|__int128
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|SignedTooBig
init|=
literal|123456789012345678901234567890
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{integer literal is too large to be represented in any integer type}}
end_comment

begin_decl_stmt
name|unsigned
name|long
name|long
name|UnsignedTooBig
init|=
literal|123456789012345678901234567890
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{integer literal is too large to be represented in any integer type}}
end_comment

begin_function_decl
name|void
name|MPI_Send
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|mpi
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|mpi_int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test
parameter_list|(
name|int
modifier|*
name|buf
parameter_list|)
block|{ }
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|__int128
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{__int128 is not supported on this target}}
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SIZEOF_INT128__
argument_list|)
end_if

begin_error
error|#
directive|error
error|__SIZEOF_INT128__ should not be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

