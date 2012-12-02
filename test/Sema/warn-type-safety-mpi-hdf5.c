begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -DOPEN_MPI -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -DMPICH -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++98 -DOPEN_MPI -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -std=c++98 -DMPICH -fsyntax-only -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -DOPEN_MPI -fno-signed-char -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -DMPICH -fno-signed-char -fsyntax-only -verify %s
end_comment

begin_comment
comment|//===--- limits.h mock ----------------------------------------------------===//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
end_ifdef

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|(__SCHAR_MAX__*2  +1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_MIN
value|(-__SCHAR_MAX__-1)
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|__SCHAR_MAX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//===--- mpi.h mock -------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OPEN_MPI
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|ompi_datatype_t
modifier|*
name|MPI_Datatype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MPICH
end_ifdef

begin_typedef
typedef|typedef
name|int
name|MPI_Datatype
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|MPI_Send
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|count
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

begin_function_decl
name|int
name|MPI_Gather
parameter_list|(
name|void
modifier|*
name|sendbuf
parameter_list|,
name|int
name|sendcount
parameter_list|,
name|MPI_Datatype
name|sendtype
parameter_list|,
name|void
modifier|*
name|recvbuf
parameter_list|,
name|int
name|recvcount
parameter_list|,
name|MPI_Datatype
name|recvtype
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

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|pointer_with_type_tag
argument_list|(
name|mpi
argument_list|,
literal|4
argument_list|,
literal|6
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OPEN_MPI
end_ifdef

begin_comment
comment|// OpenMPI and LAM/MPI-style datatype definitions
end_comment

begin_define
define|#
directive|define
name|OMPI_PREDEFINED_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|global
parameter_list|)
value|((type)&(global))
end_define

begin_define
define|#
directive|define
name|MPI_DATATYPE_NULL
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_datatype_null)
end_define

begin_define
define|#
directive|define
name|MPI_FLOAT
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_float)
end_define

begin_define
define|#
directive|define
name|MPI_INT
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_int)
end_define

begin_define
define|#
directive|define
name|MPI_LONG
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_long)
end_define

begin_define
define|#
directive|define
name|MPI_LONG_LONG_INT
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_long_long_int)
end_define

begin_define
define|#
directive|define
name|MPI_CHAR
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_char)
end_define

begin_define
define|#
directive|define
name|MPI_FLOAT_INT
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_float_int)
end_define

begin_define
define|#
directive|define
name|MPI_2INT
value|OMPI_PREDEFINED_GLOBAL(MPI_Datatype, ompi_mpi_2int)
end_define

begin_define
define|#
directive|define
name|MPI_IN_PLACE
value|((void *) 1)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_datatype_null
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|void
argument_list|,
name|must_be_null
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_float
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|float
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_int
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_long
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|long
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_long_long_int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
argument|mpi
argument_list|,
argument|long long int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_char
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|char
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ompi_struct_mpi_float_int
block|{
name|float
name|f
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_float_int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|ompi_struct_mpi_float_int
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ompi_struct_mpi_2int
block|{
name|int
name|i1
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ompi_predefined_datatype_t
name|ompi_mpi_2int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|ompi_struct_mpi_2int
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MPICH
end_ifdef

begin_comment
comment|// MPICH2 and MVAPICH2-style datatype definitions
end_comment

begin_define
define|#
directive|define
name|MPI_COMM_WORLD
value|((MPI_Comm) 0x44000000)
end_define

begin_define
define|#
directive|define
name|MPI_DATATYPE_NULL
value|((MPI_Datatype) 0xa0000000)
end_define

begin_define
define|#
directive|define
name|MPI_FLOAT
value|((MPI_Datatype) 0xa0000001)
end_define

begin_define
define|#
directive|define
name|MPI_INT
value|((MPI_Datatype) 0xa0000002)
end_define

begin_define
define|#
directive|define
name|MPI_LONG
value|((MPI_Datatype) 0xa0000003)
end_define

begin_define
define|#
directive|define
name|MPI_LONG_LONG_INT
value|((MPI_Datatype) 0xa0000004)
end_define

begin_define
define|#
directive|define
name|MPI_CHAR
value|((MPI_Datatype) 0xa0000005)
end_define

begin_define
define|#
directive|define
name|MPI_FLOAT_INT
value|((MPI_Datatype) 0xa0000006)
end_define

begin_define
define|#
directive|define
name|MPI_2INT
value|((MPI_Datatype) 0xa0000007)
end_define

begin_define
define|#
directive|define
name|MPI_IN_PLACE
value|(void *) -1
end_define

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_datatype_null
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|void
argument_list|,
name|must_be_null
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_float
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|float
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000001
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_int
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
literal|0xa0000002
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_long
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|long
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000003
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_long_long_int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
argument|mpi
argument_list|,
argument|long long int
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000004
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_char
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
name|char
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000005
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|mpich_struct_mpi_float_int
block|{
name|float
name|f
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpich_struct_mpi_2int
block|{
name|int
name|i1
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_float_int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|mpich_struct_mpi_float_int
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000006
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|MPI_Datatype
name|mpich_mpi_2int
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|mpich_struct_mpi_2int
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
init|=
literal|0xa0000007
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//===--- HDF5 headers mock ------------------------------------------------===//
end_comment

begin_typedef
typedef|typedef
name|int
name|hid_t
typedef|;
end_typedef

begin_function_decl
name|void
name|H5open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HDF_PRIVATE
end_ifndef

begin_define
define|#
directive|define
name|H5OPEN
value|H5open(),
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|H5OPEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|H5T_NATIVE_CHAR
value|(CHAR_MIN?H5T_NATIVE_SCHAR:H5T_NATIVE_UCHAR)
end_define

begin_define
define|#
directive|define
name|H5T_NATIVE_SCHAR
value|(H5OPEN H5T_NATIVE_SCHAR_g)
end_define

begin_define
define|#
directive|define
name|H5T_NATIVE_UCHAR
value|(H5OPEN H5T_NATIVE_UCHAR_g)
end_define

begin_define
define|#
directive|define
name|H5T_NATIVE_INT
value|(H5OPEN H5T_NATIVE_INT_g)
end_define

begin_define
define|#
directive|define
name|H5T_NATIVE_LONG
value|(H5OPEN H5T_NATIVE_LONG_g)
end_define

begin_decl_stmt
name|hid_t
name|H5T_NATIVE_SCHAR_g
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
argument|hdf5
argument_list|,
argument|signed char
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|hid_t
name|H5T_NATIVE_UCHAR_g
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
argument|hdf5
argument_list|,
argument|unsigned char
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|hid_t
name|H5T_NATIVE_INT_g
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|hdf5
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|hid_t
name|H5T_NATIVE_LONG_g
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|hdf5
argument_list|,
name|long
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|H5Dwrite
parameter_list|(
name|hid_t
name|mem_type_id
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|( pointer_with_type_tag
parameter_list|(
name|hdf5
parameter_list|,
function_decl|2
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|) ))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===--- Tests ------------------------------------------------------------===//
end_comment

begin_comment
comment|//===--- MPI
end_comment

begin_struct
struct|struct
name|pair_float_int
block|{
name|float
name|f
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pair_int_int
block|{
name|int
name|i1
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test_mpi_predefined_types
parameter_list|(
name|int
modifier|*
name|int_buf
parameter_list|,
name|long
modifier|*
name|long_buf1
parameter_list|,
name|long
modifier|*
name|long_buf2
parameter_list|,
name|void
modifier|*
name|void_buf
parameter_list|,
name|struct
name|pair_float_int
modifier|*
name|pfi
parameter_list|,
name|struct
name|pair_int_int
modifier|*
name|pii
parameter_list|)
block|{
name|char
name|char_buf
index|[
literal|255
index|]
decl_stmt|;
comment|// Layout-compatible scalar types.
name|MPI_Send
argument_list|(
name|int_buf
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Null pointer constant.
name|MPI_Send
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Layout-compatible class types.
name|MPI_Send
argument_list|(
name|pfi
argument_list|,
literal|1
argument_list|,
name|MPI_FLOAT_INT
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|pii
argument_list|,
literal|1
argument_list|,
name|MPI_2INT
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Layout-incompatible scalar types.
name|MPI_Send
argument_list|(
name|long_buf1
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag that requires 'int *'}}
comment|// Layout-incompatible class types.
name|MPI_Send
argument_list|(
name|pii
argument_list|,
literal|1
argument_list|,
name|MPI_FLOAT_INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct pair_int_int *' doesn't match specified 'mpi' type tag}}
name|MPI_Send
argument_list|(
name|pfi
argument_list|,
literal|1
argument_list|,
name|MPI_2INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct pair_float_int *' doesn't match specified 'mpi' type tag}}
comment|// Layout-incompatible class-scalar types.
name|MPI_Send
argument_list|(
name|long_buf1
argument_list|,
literal|1
argument_list|,
name|MPI_2INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag}}
comment|// Function with two buffers.
name|MPI_Gather
argument_list|(
name|long_buf1
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|,
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag that requires 'int *'}}
name|long_buf2
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag that requires 'int *'}}
comment|// Array buffers should work like pointer buffers.
name|MPI_Send
argument_list|(
name|char_buf
argument_list|,
literal|255
argument_list|,
name|MPI_CHAR
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// Explicit casts should not be dropped.
name|MPI_Send
argument_list|(
operator|(
name|int
operator|*
operator|)
name|char_buf
argument_list|,
literal|255
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
operator|(
name|int
operator|*
operator|)
name|char_buf
argument_list|,
literal|255
argument_list|,
name|MPI_CHAR
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'int *' doesn't match specified 'mpi' type tag that requires 'char *'}}
comment|// `void*' buffer should never warn.
name|MPI_Send
argument_list|(
name|void_buf
argument_list|,
literal|255
argument_list|,
name|MPI_CHAR
argument_list|)
expr_stmt|;
comment|// no-warning
comment|// We expect that MPI_IN_PLACE is `void*', shouldn't warn.
name|MPI_Gather
argument_list|(
name|MPI_IN_PLACE
argument_list|,
literal|0
argument_list|,
name|MPI_INT
argument_list|,
name|int_buf
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// Special handling for MPI_DATATYPE_NULL: buffer pointer should be either
comment|// a `void*' pointer or a null pointer constant.
name|MPI_Gather
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|MPI_DATATYPE_NULL
argument_list|,
comment|// no-warning
name|int_buf
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
name|MPI_Gather
argument_list|(
name|int_buf
argument_list|,
literal|0
argument_list|,
name|MPI_DATATYPE_NULL
argument_list|,
comment|// expected-warning {{specified mpi type tag requires a null pointer}}
name|int_buf
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|MPI_Datatype
name|my_int_datatype
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
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S1
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|MPI_Datatype
name|my_s1_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|S1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Layout-compatible to S1, but should be treated as a different type.
end_comment

begin_struct
struct|struct
name|S2
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|MPI_Datatype
name|my_s2_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|S2
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_user_types
parameter_list|(
name|int
modifier|*
name|int_buf
parameter_list|,
name|long
modifier|*
name|long_buf
parameter_list|,
name|struct
name|S1
modifier|*
name|s1_buf
parameter_list|,
name|struct
name|S2
modifier|*
name|s2_buf
parameter_list|)
block|{
name|MPI_Send
argument_list|(
name|int_buf
argument_list|,
literal|1
argument_list|,
name|my_int_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|long_buf
argument_list|,
literal|1
argument_list|,
name|my_int_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag that requires 'int *'}}
name|MPI_Send
argument_list|(
name|s1_buf
argument_list|,
literal|1
argument_list|,
name|my_s1_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|s1_buf
argument_list|,
literal|1
argument_list|,
name|my_s2_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct S1 *' doesn't match specified 'mpi' type tag that requires 'struct S2 *'}}
name|MPI_Send
argument_list|(
name|long_buf
argument_list|,
literal|1
argument_list|,
name|my_s1_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'mpi' type tag that requires 'struct S1 *'}}
name|MPI_Send
argument_list|(
name|s1_buf
argument_list|,
literal|1
argument_list|,
name|MPI_INT
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct S1 *' doesn't match specified 'mpi' type tag that requires 'int *'}}
block|}
end_function

begin_decl_stmt
name|MPI_Datatype
name|my_unknown_datatype
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_not_annotated
parameter_list|(
name|int
modifier|*
name|int_buf
parameter_list|,
name|long
modifier|*
name|long_buf
parameter_list|,
name|MPI_Datatype
name|type
parameter_list|)
block|{
comment|// Using 'MPI_Datatype's without attributes should not produce warnings.
name|MPI_Send
argument_list|(
name|long_buf
argument_list|,
literal|1
argument_list|,
name|my_unknown_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|int_buf
argument_list|,
literal|1
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_struct
struct|struct
name|S1_compat
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|MPI_Datatype
name|my_s1_compat_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|S1_compat
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S3
block|{
name|int
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|double
name|c
decl_stmt|;
name|double
name|d
decl_stmt|;
name|struct
name|S1
name|s1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S3_compat
block|{
name|int
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|double
name|c
decl_stmt|;
name|double
name|d
decl_stmt|;
name|struct
name|S2
name|s2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|MPI_Datatype
name|my_s3_compat_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|S3_compat
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S4
block|{
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S4_compat
block|{
name|signed
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|MPI_Datatype
name|my_s4_compat_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|struct
name|S4_compat
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|U1
block|{
name|int
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|double
name|c
decl_stmt|;
name|double
name|d
decl_stmt|;
name|struct
name|S1
name|s1
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|U1_compat
block|{
name|long
name|b
decl_stmt|;
name|double
name|c
decl_stmt|;
name|struct
name|S2
name|s
decl_stmt|;
name|int
name|a
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|MPI_Datatype
name|my_u1_compat_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|union
name|U1_compat
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_union
union|union
name|U2
block|{
name|int
name|a
decl_stmt|;
name|long
name|b
decl_stmt|;
name|double
name|c
decl_stmt|;
name|struct
name|S1
name|s1
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|MPI_Datatype
name|my_u2_datatype
name|__attribute__
argument_list|(
operator|(
name|type_tag_for_datatype
argument_list|(
name|mpi
argument_list|,
expr|union
name|U2
argument_list|,
name|layout_compatible
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_layout_compatibility
parameter_list|(
name|struct
name|S1
modifier|*
name|s1_buf
parameter_list|,
name|struct
name|S3
modifier|*
name|s3_buf
parameter_list|,
name|struct
name|S4
modifier|*
name|s4_buf
parameter_list|,
name|union
name|U1
modifier|*
name|u1_buf
parameter_list|,
name|union
name|U2
modifier|*
name|u2_buf
parameter_list|)
block|{
name|MPI_Send
argument_list|(
name|s1_buf
argument_list|,
literal|1
argument_list|,
name|my_s1_compat_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|s3_buf
argument_list|,
literal|1
argument_list|,
name|my_s3_compat_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|s1_buf
argument_list|,
literal|1
argument_list|,
name|my_s3_compat_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct S1 *' doesn't match specified 'mpi' type tag}}
name|MPI_Send
argument_list|(
name|s4_buf
argument_list|,
literal|1
argument_list|,
name|my_s4_compat_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'struct S4 *' doesn't match specified 'mpi' type tag}}
name|MPI_Send
argument_list|(
name|u1_buf
argument_list|,
literal|1
argument_list|,
name|my_u1_compat_datatype
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|u1_buf
argument_list|,
literal|1
argument_list|,
name|my_u2_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'union U1 *' doesn't match specified 'mpi' type tag}}
name|MPI_Send
argument_list|(
name|u2_buf
argument_list|,
literal|1
argument_list|,
name|my_u1_compat_datatype
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'union U2 *' doesn't match specified 'mpi' type tag}}
block|}
end_function

begin_comment
comment|// There is an MPI_REAL predefined in MPI, but some existing MPI programs do
end_comment

begin_comment
comment|// this.
end_comment

begin_typedef
typedef|typedef
name|float
name|real
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_REAL
value|MPI_FLOAT
end_define

begin_function
name|void
name|test_mpi_real_user_type
parameter_list|(
name|real
modifier|*
name|real_buf
parameter_list|,
name|float
modifier|*
name|float_buf
parameter_list|)
block|{
name|MPI_Send
argument_list|(
name|real_buf
argument_list|,
literal|1
argument_list|,
name|MPI_REAL
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|real_buf
argument_list|,
literal|1
argument_list|,
name|MPI_FLOAT
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|float_buf
argument_list|,
literal|1
argument_list|,
name|MPI_REAL
argument_list|)
expr_stmt|;
comment|// no-warning
name|MPI_Send
argument_list|(
name|float_buf
argument_list|,
literal|1
argument_list|,
name|MPI_FLOAT
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//===--- HDF5
end_comment

begin_function
name|void
name|test_hdf5
parameter_list|(
name|char
modifier|*
name|char_buf
parameter_list|,
name|signed
name|char
modifier|*
name|schar_buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|uchar_buf
parameter_list|,
name|int
modifier|*
name|int_buf
parameter_list|,
name|long
modifier|*
name|long_buf
parameter_list|)
block|{
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|char_buf
argument_list|)
expr_stmt|;
comment|// no-warning
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|schar_buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'signed char *' doesn't match specified 'hdf5' type tag that requires 'unsigned char *'}}
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|uchar_buf
argument_list|)
expr_stmt|;
comment|// no-warning
else|#
directive|else
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|schar_buf
argument_list|)
expr_stmt|;
comment|// no-warning
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|uchar_buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'unsigned char *' doesn't match specified 'hdf5' type tag that requires 'signed char *'}}
endif|#
directive|endif
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_SCHAR
argument_list|,
name|schar_buf
argument_list|)
expr_stmt|;
comment|// no-warning
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_UCHAR
argument_list|,
name|uchar_buf
argument_list|)
expr_stmt|;
comment|// no-warning
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_INT
argument_list|,
name|int_buf
argument_list|)
expr_stmt|;
comment|// no-warning
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_LONG
argument_list|,
name|long_buf
argument_list|)
expr_stmt|;
comment|// no-warning
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|int_buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'int *' doesn't match specified 'hdf5' type tag that requires 'unsigned char *'}}
else|#
directive|else
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_CHAR
argument_list|,
name|int_buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'int *' doesn't match specified 'hdf5' type tag that requires 'signed char *'}}
endif|#
directive|endif
name|H5Dwrite
argument_list|(
name|H5T_NATIVE_INT
argument_list|,
name|long_buf
argument_list|)
expr_stmt|;
comment|// expected-warning {{argument type 'long *' doesn't match specified 'hdf5' type tag that requires 'int *'}}
comment|// FIXME: we should warn here, but it will cause false positives because
comment|// different kinds may use same magic values.
comment|//H5Dwrite(MPI_INT, int_buf);
block|}
end_function

end_unit

