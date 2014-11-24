begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++98 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fno-signed-char -fsyntax-only -verify %s
end_comment

begin_struct
struct|struct
name|A
block|{}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|A
modifier|*
name|MPI_Datatype
typedef|;
end_typedef

begin_function_decl
name|int
name|wrong1
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'pointer_with_type_tag' attribute requires parameter 1 to be an identifier}}
end_comment

begin_function_decl
name|int
name|wrong2
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|mpi
parameter_list|,
function_decl|0
operator|,
function_decl|7
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute parameter 2 is out of bounds}}
end_comment

begin_function_decl
name|int
name|wrong3
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|mpi
parameter_list|,
function_decl|3
operator|,
function_decl|7
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute parameter 2 is out of bounds}}
end_comment

begin_function_decl
name|int
name|wrong4
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
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
function_decl|0
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|int
name|wrong5
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
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
function_decl|3
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|int
name|wrong6
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|mpi
parameter_list|,
function_decl|0x8000000000000001ULL
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute parameter 2 is out of bounds}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|wrong7
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
name|datatype
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|mpi
parameter_list|,
name|x
parameter_list|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute requires parameter 2 to be an integer constant}}
end_comment

begin_function_decl
name|int
name|wrong8
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|MPI_Datatype
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
function_decl|x
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute requires parameter 3 to be an integer constant}}
end_comment

begin_decl_stmt
name|int
name|wrong9
name|__attribute__
argument_list|(
operator|(
name|pointer_with_type_tag
argument_list|(
name|mpi
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|int
name|wrong10
parameter_list|(
name|double
name|buf
parameter_list|,
name|MPI_Datatype
name|type
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

begin_comment
comment|// expected-error {{'pointer_with_type_tag' attribute only applies to pointer arguments}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong1
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'type_tag_for_datatype' attribute requires parameter 1 to be an identifier}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong2
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected a type}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong3
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|not_a_type
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{unknown type name 'not_a_type'}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong4
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected identifier}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong5
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|int
argument_list|,
name|not_a_flag
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid comparison flag 'not_a_flag'}}
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|A
name|datatype_wrong6
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|int
argument_list|,
name|layout_compatible
argument_list|,
name|not_a_flag
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid comparison flag 'not_a_flag'}}
end_comment

begin_function_decl
name|void
name|datatype_wrong7
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(type_tag_for_datatype
parameter_list|(
name|datatype_wrong7
parameter_list|,
name|int
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'type_tag_for_datatype' attribute only applies to variables}}
end_comment

begin_comment
comment|// Using a tag with kind A in a place where the function requires kind B should
end_comment

begin_comment
comment|// warn.
end_comment

begin_function_decl
name|void
name|A_func
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|a
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
specifier|extern
name|struct
name|A
name|A_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|a
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|A
name|B_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|b
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|C_func
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|tag
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|c
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
name|C_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|c
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|D_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|d
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_tag_mismatch
parameter_list|(
name|int
modifier|*
name|ptr
parameter_list|)
block|{
name|A_func
argument_list|(
name|ptr
argument_list|,
operator|&
name|A_tag
argument_list|)
expr_stmt|;
comment|// no-warning
name|A_func
argument_list|(
name|ptr
argument_list|,
operator|&
name|B_tag
argument_list|)
expr_stmt|;
comment|// expected-warning {{this type tag was not designed to be used with this function}}
name|C_func
argument_list|(
name|ptr
argument_list|,
name|C_tag
argument_list|)
expr_stmt|;
comment|// no-warning
name|C_func
argument_list|(
name|ptr
argument_list|,
name|D_tag
argument_list|)
expr_stmt|;
comment|// expected-warning {{this type tag was not designed to be used with this function}}
name|C_func
argument_list|(
name|ptr
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|C_func
argument_list|(
name|ptr
argument_list|,
literal|20
argument_list|)
expr_stmt|;
comment|// should warn, but may cause false positives
block|}
end_function

begin_function
name|void
name|test_null_pointer
parameter_list|()
block|{
name|C_func
argument_list|(
literal|0
argument_list|,
name|C_tag
argument_list|)
expr_stmt|;
comment|// no-warning
name|C_func
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
name|C_tag
argument_list|)
expr_stmt|;
comment|// no-warning
name|C_func
argument_list|(
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|,
name|C_tag
argument_list|)
expr_stmt|;
comment|// no-warning
name|C_func
argument_list|(
operator|(
name|long
operator|*
operator|)
literal|0
argument_list|,
name|C_tag
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'c' type tag that requires 'int *'}}
block|}
end_function

begin_comment
comment|// Check that we look through typedefs in the special case of allowing 'char'
end_comment

begin_comment
comment|// to be matched with 'signed char' or 'unsigned char'.
end_comment

begin_function_decl
name|void
name|E_func
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|tag
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|e
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|char
name|E_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|E_char_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|E_char_signed
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|E_char_unsigned
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|int
name|E_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|e
argument_list|,
name|E_char
argument_list|)
operator|)
argument_list|)
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_char_typedef
parameter_list|(
name|char
modifier|*
name|char_buf
parameter_list|,
name|E_char_2
modifier|*
name|e_char_buf
parameter_list|,
name|E_char_signed
modifier|*
name|e_char_signed_buf
parameter_list|,
name|E_char_unsigned
modifier|*
name|e_char_unsigned_buf
parameter_list|)
block|{
name|E_func
argument_list|(
name|char_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
name|E_func
argument_list|(
name|e_char_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
name|E_func
argument_list|(
name|e_char_signed_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'E_char_signed *' (aka 'signed char *') doesn't match specified 'e' type tag that requires 'E_char *' (aka 'char *')}}
name|E_func
argument_list|(
name|e_char_unsigned_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
else|#
directive|else
name|E_func
argument_list|(
name|e_char_signed_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
name|E_func
argument_list|(
name|e_char_unsigned_buf
argument_list|,
name|E_tag
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'E_char_unsigned *' (aka 'unsigned char *') doesn't match specified 'e' type tag that requires 'E_char *' (aka 'char *')}}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// Tests for argument_with_type_tag.
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|10
end_define

begin_define
define|#
directive|define
name|F_SETLK
value|20
end_define

begin_struct
struct|struct
name|flock
block|{ }
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|int
name|F_DUPFD_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|fcntl
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
init|=
name|F_DUPFD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|F_SETLK_tag
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|fcntl
argument_list|,
expr|struct
name|flock
operator|*
argument_list|)
operator|)
argument_list|)
init|=
name|F_SETLK
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|fcntl
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|cmd
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( argument_with_type_tag
parameter_list|(
name|fcntl
parameter_list|,
function_decl|3
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_argument_with_type_tag
parameter_list|(
name|struct
name|flock
modifier|*
name|f
parameter_list|)
block|{
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_DUPFD
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETLK
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// no-warning
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_SETLK
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'int' doesn't match specified 'fcntl' type tag that requires 'struct flock *'}}
name|fcntl
argument_list|(
literal|0
argument_list|,
name|F_DUPFD
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct flock *' doesn't match specified 'fcntl' type tag that requires 'int'}}
block|}
end_function

begin_function
name|void
name|test_tag_expresssion
parameter_list|(
name|int
name|b
parameter_list|)
block|{
name|fcntl
argument_list|(
literal|0
argument_list|,
name|b
condition|?
name|F_DUPFD
else|:
name|F_SETLK
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|fcntl
argument_list|(
literal|0
argument_list|,
name|b
operator|+
name|F_DUPFD
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// no-warning
name|fcntl
argument_list|(
literal|0
argument_list|,
operator|(
name|b
operator|,
name|F_DUPFD
operator|)
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
block|}
end_function

begin_comment
comment|// Check that using 64-bit magic values as tags works and tag values do not
end_comment

begin_comment
comment|// overflow internally.
end_comment

begin_function_decl
name|void
name|F_func
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|unsigned
name|long
name|long
name|tag
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(pointer_with_type_tag
parameter_list|(
name|f
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
name|unsigned
name|long
name|long
name|F_tag1
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|f
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
init|=
literal|0xFFFFFFFFFFFFFFFFULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|long
name|long
name|F_tag2
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|f
argument_list|,
name|float
argument_list|)
operator|)
argument_list|)
init|=
literal|0xFFFFFFFFULL
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_64bit_magic
parameter_list|(
name|int
modifier|*
name|int_ptr
parameter_list|,
name|float
modifier|*
name|float_ptr
parameter_list|)
block|{
name|F_func
argument_list|(
name|int_ptr
argument_list|,
literal|0xFFFFFFFFFFFFFFFFULL
argument_list|)
expr_stmt|;
name|F_func
argument_list|(
name|int_ptr
argument_list|,
literal|0xFFFFFFFFULL
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'int *' doesn't match specified 'f' type tag that requires 'float *'}}
name|F_func
argument_list|(
name|float_ptr
argument_list|,
literal|0xFFFFFFFFFFFFFFFFULL
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'float *' doesn't match specified 'f' type tag that requires 'int *'}}
name|F_func
argument_list|(
name|float_ptr
argument_list|,
literal|0xFFFFFFFFULL
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

