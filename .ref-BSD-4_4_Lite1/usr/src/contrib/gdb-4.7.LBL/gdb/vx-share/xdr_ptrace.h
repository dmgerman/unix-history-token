begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xdr_ptrace.h - xdr header for remote ptrace structures */
end_comment

begin_comment
comment|/*  Copyright 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01b,25may91,maf  now uses counted bytes struct to transfer registers; 		   removed references to old xdr_regs functions. 		 removed includes of "xdr_regs.h" and "reg.h". 01a,05jun90,llk  extracted from xdr_ptrace.h. */
end_comment

begin_comment
comment|/*  *  Counted byte structure used by READ/WRITE TEXT/DATA  *  and GET/SET REGS/FPREGS  */
end_comment

begin_struct
struct|struct
name|c_bytes
block|{
name|u_int
name|len
decl_stmt|;
name|caddr_t
name|bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|c_bytes
name|C_bytes
typedef|;
end_typedef

begin_comment
comment|/*  * enum for discriminated union ptrace_info  */
end_comment

begin_enum
enum|enum
name|ptype
block|{
name|NOINFO
init|=
literal|0
block|,
comment|/* no additional infomation	*/
name|DATA
init|=
literal|1
comment|/* c_bytes */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ptype
name|ptype
typedef|;
end_typedef

begin_comment
comment|/*  * discrimnated union for passing additional data to be   * written to the debugged process.  */
end_comment

begin_struct
struct|struct
name|ptrace_info
block|{
name|ptype
name|ttype
decl_stmt|;
name|caddr_t
name|more_data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ptrace_info
name|Ptrace_info
typedef|;
end_typedef

begin_comment
comment|/*  * structure passed to server on all remote ptrace calls  */
end_comment

begin_struct
struct|struct
name|rptrace
block|{
name|int
name|pid
decl_stmt|;
name|int
name|data
decl_stmt|;
name|int
name|addr
decl_stmt|;
comment|/* FIX! this really should be caddr_t or something */
name|Ptrace_info
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rptrace
name|Rptrace
typedef|;
end_typedef

begin_comment
comment|/*  * structure returned by server on all remote ptrace calls  */
end_comment

begin_struct
struct|struct
name|ptrace_return
block|{
name|int
name|status
decl_stmt|;
name|int
name|errno
decl_stmt|;
name|Ptrace_info
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ptrace_return
name|Ptrace_return
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_c_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_ptrace_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_rptrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_ptrace_return
parameter_list|()
function_decl|;
end_function_decl

end_unit

