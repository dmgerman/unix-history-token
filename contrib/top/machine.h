begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  This file defines the interface between top and the machine-dependent  *  module.  It is NOT machine dependent and should not need to be changed  *  for any specific machine.  */
end_comment

begin_comment
comment|/*  * the statics struct is filled in by machine_init  */
end_comment

begin_struct
struct|struct
name|statics
block|{
name|char
modifier|*
modifier|*
name|procstate_names
decl_stmt|;
name|char
modifier|*
modifier|*
name|cpustate_names
decl_stmt|;
name|char
modifier|*
modifier|*
name|memory_names
decl_stmt|;
name|char
modifier|*
modifier|*
name|swap_names
decl_stmt|;
ifdef|#
directive|ifdef
name|ORDER
name|char
modifier|*
modifier|*
name|order_names
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * the system_info struct is filled in by a machine dependent routine.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|p_active
end_ifdef

begin_comment
comment|/* uw7 define macro p_active */
end_comment

begin_define
define|#
directive|define
name|P_ACTIVE
value|p_pactive
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_ACTIVE
value|p_active
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|system_info
block|{
name|int
name|last_pid
decl_stmt|;
name|double
name|load_avg
index|[
name|NUM_AVERAGES
index|]
decl_stmt|;
name|int
name|p_total
decl_stmt|;
name|int
name|P_ACTIVE
decl_stmt|;
comment|/* number of procs considered "active" */
name|int
modifier|*
name|procstates
decl_stmt|;
name|int
modifier|*
name|cpustates
decl_stmt|;
name|int
modifier|*
name|memory
decl_stmt|;
name|int
modifier|*
name|swap
decl_stmt|;
name|struct
name|timeval
name|boottime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* cpu_states is an array of percentages * 10.  For example,     the (integer) value 105 is 10.5% (or .105).  */
end_comment

begin_comment
comment|/*  * the process_select struct tells get_process_info what processes we  * are interested in seeing  */
end_comment

begin_struct
struct|struct
name|process_select
block|{
name|int
name|idle
decl_stmt|;
comment|/* show idle processes */
name|int
name|self
decl_stmt|;
comment|/* show self */
name|int
name|system
decl_stmt|;
comment|/* show system processes */
name|int
name|thread
decl_stmt|;
comment|/* show threads */
name|int
name|uid
decl_stmt|;
comment|/* only this uid (unless uid == -1) */
name|int
name|wcpu
decl_stmt|;
comment|/* show weighted cpu */
name|int
name|jail
decl_stmt|;
comment|/* show jail id */
name|char
modifier|*
name|command
decl_stmt|;
comment|/* only this command (unless == NULL) */
block|}
struct|;
end_struct

begin_comment
comment|/* routines defined by the machine dependent module */
end_comment

begin_function_decl
name|char
modifier|*
name|format_header
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|format_next_process
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* non-int routines typically used by the machine dependent module */
end_comment

begin_function_decl
name|char
modifier|*
name|printable
parameter_list|()
function_decl|;
end_function_decl

end_unit

