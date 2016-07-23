begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Message Passing Interface mock header. Mocks MPI constants and functions, in
end_comment

begin_comment
comment|// order to make them available in distinct integration test files.
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|// mock types
end_comment

begin_typedef
typedef|typedef
name|int
name|MPI_Datatype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MPI_Comm
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MPI_Request
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MPI_Status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|MPI_Op
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int64_t
typedef|;
end_typedef

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|complex
block|{
name|T
name|real
block|;
name|T
name|imag
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// mock constants
end_comment

begin_define
define|#
directive|define
name|MPI_DATATYPE_NULL
value|0
end_define

begin_define
define|#
directive|define
name|MPI_CHAR
value|0
end_define

begin_define
define|#
directive|define
name|MPI_BYTE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_INT
value|0
end_define

begin_define
define|#
directive|define
name|MPI_LONG
value|0
end_define

begin_define
define|#
directive|define
name|MPI_LONG_DOUBLE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_UNSIGNED
value|0
end_define

begin_define
define|#
directive|define
name|MPI_INT8_T
value|0
end_define

begin_define
define|#
directive|define
name|MPI_UINT8_T
value|0
end_define

begin_define
define|#
directive|define
name|MPI_UINT16_T
value|0
end_define

begin_define
define|#
directive|define
name|MPI_C_LONG_DOUBLE_COMPLEX
value|0
end_define

begin_define
define|#
directive|define
name|MPI_FLOAT
value|0
end_define

begin_define
define|#
directive|define
name|MPI_DOUBLE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_CXX_BOOL
value|0
end_define

begin_define
define|#
directive|define
name|MPI_CXX_FLOAT_COMPLEX
value|0
end_define

begin_define
define|#
directive|define
name|MPI_CXX_DOUBLE_COMPLEX
value|0
end_define

begin_define
define|#
directive|define
name|MPI_CXX_LONG_DOUBLE_COMPLEX
value|0
end_define

begin_define
define|#
directive|define
name|MPI_IN_PLACE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_COMM_WORLD
value|0
end_define

begin_define
define|#
directive|define
name|MPI_STATUS_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_STATUSES_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|MPI_SUM
value|0
end_define

begin_comment
comment|// mock functions
end_comment

begin_function_decl
name|int
name|MPI_Comm_size
parameter_list|(
name|MPI_Comm
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Comm_rank
parameter_list|(
name|MPI_Comm
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Send
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Recv
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|,
name|MPI_Status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Isend
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|,
name|MPI_Request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Irecv
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|,
name|MPI_Request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Wait
parameter_list|(
name|MPI_Request
modifier|*
parameter_list|,
name|MPI_Status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Waitall
parameter_list|(
name|int
parameter_list|,
name|MPI_Request
index|[]
parameter_list|,
name|MPI_Status
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Reduce
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|MPI_Op
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Ireduce
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|MPI_Op
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|,
name|MPI_Request
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MPI_Bcast
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
name|count
parameter_list|,
name|MPI_Datatype
parameter_list|,
name|int
parameter_list|,
name|MPI_Comm
parameter_list|)
function_decl|;
end_function_decl

end_unit

