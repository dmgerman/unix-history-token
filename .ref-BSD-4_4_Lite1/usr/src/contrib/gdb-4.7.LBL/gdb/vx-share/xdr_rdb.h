begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xdr_rdb.h - xdr for additional rdb structures */
end_comment

begin_comment
comment|/* Copyright 1992 Free Software Foundation, Inc.     This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01c,25may91,maf  rolled RDBVERS for VxGDB 1.0 version. 01b,12apr91,maf  rolled RDBVERS. 01a,09jan91,maf  created using v1a of xdr_rdb.h for 4.0.2 VxWorks 68k. 		 added struct SOURCE_STEP. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCxdrrdbh
end_ifndef

begin_define
define|#
directive|define
name|INCxdrrdbh
end_define

begin_enum
enum|enum
name|arg_type
block|{
name|T_UNKNOWN
init|=
literal|0
block|,
name|T_BYTE
init|=
literal|1
block|,
name|T_WORD
init|=
literal|2
block|,
name|T_INT
init|=
literal|3
block|,
name|T_FLOAT
init|=
literal|4
block|,
name|T_DOUBLE
init|=
literal|5
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|arg_type
name|arg_type
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_arg_type
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|arg_value
block|{
name|arg_type
name|type
decl_stmt|;
union|union
block|{
name|char
name|v_byte
decl_stmt|;
name|short
name|v_word
decl_stmt|;
name|int
name|v_int
decl_stmt|;
name|float
name|v_fp
decl_stmt|;
name|double
name|v_dp
decl_stmt|;
block|}
name|arg_value_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arg_value
name|arg_value
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_arg_value
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|func_call
block|{
name|int
name|func_addr
decl_stmt|;
struct|struct
block|{
name|u_int
name|args_len
decl_stmt|;
name|arg_value
modifier|*
name|args_val
decl_stmt|;
block|}
name|args
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|func_call
name|func_call
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_func_call
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|char
modifier|*
name|arg_one
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_arg_one
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|arg_array_len
decl_stmt|;
name|arg_one
modifier|*
name|arg_array_val
decl_stmt|;
block|}
name|arg_array
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_arg_array
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Structures used to pass structures required for  * process control but not part of the standard ptrace interface  */
end_comment

begin_comment
comment|/*  * arg_info is used to pass arguments into process start  */
end_comment

begin_struct
struct|struct
name|arg_info
block|{
name|int
name|rargc
decl_stmt|;
name|char
modifier|*
modifier|*
name|rargv
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arg_info
name|Arg_info
typedef|;
end_typedef

begin_enum
enum|enum
name|EVENT_TYPE
block|{
name|EVENT_BREAK
init|=
literal|0
block|,
name|EVENT_STOP
init|=
literal|1
block|,
name|EVENT_EXIT
init|=
literal|2
block|,
name|EVENT_BUS_ERR
init|=
literal|3
block|,
name|EVENT_SUSPEND
init|=
literal|4
block|,
name|EVENT_ZERO_DIV
init|=
literal|5
block|,
name|EVENT_SIGNAL
init|=
literal|6
block|,
name|EVENT_START
init|=
literal|7
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|EVENT_TYPE
name|EVENT_TYPE
typedef|;
end_typedef

begin_struct
struct|struct
name|RDB_EVENT
block|{
name|int
name|status
decl_stmt|;
name|int
name|taskId
decl_stmt|;
name|EVENT_TYPE
name|eventType
decl_stmt|;
name|int
name|sigType
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|RDB_EVENT
name|RDB_EVENT
typedef|;
end_typedef

begin_struct
struct|struct
name|TASK_START
block|{
name|int
name|status
decl_stmt|;
name|int
name|pid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|TASK_START
name|TASK_START
typedef|;
end_typedef

begin_struct
struct|struct
name|SYMBOL_ADDR
block|{
name|int
name|status
decl_stmt|;
name|u_int
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|SYMBOL_ADDR
name|SYMBOL_ADDR
typedef|;
end_typedef

begin_struct
struct|struct
name|SOURCE_STEP
block|{
name|int
name|taskId
decl_stmt|;
name|u_int
name|startAddr
decl_stmt|;
name|u_int
name|endAddr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|SOURCE_STEP
name|SOURCE_STEP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_ARG_CNT
value|10
end_define

begin_define
define|#
directive|define
name|MAX_FUNC_ARGS
value|100
end_define

begin_define
define|#
directive|define
name|MAX_ARG_LEN
value|100
end_define

begin_function_decl
name|bool_t
name|xdr_arg_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_EVENT_TYPE
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_RDB_EVENT
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_TASK_START
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_SYMBOL_ADDR
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_SOURCE_STEP
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RDBPROG
value|(u_long) 0x44444444
end_define

begin_define
define|#
directive|define
name|RDBVERS
value|(u_long) 3
end_define

begin_endif
endif|#
directive|endif
endif|INCxdrrdbh
end_endif

end_unit

