begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * adb: breakpoints.  *  *	@(#)bkpt.h	5.1 (Berkeley) 1/16/89  */
end_comment

begin_define
define|#
directive|define
name|MAX_BKPTCOM
value|64
end_define

begin_comment
comment|/* maximum length of command at bkpt */
end_comment

begin_enum
enum|enum
name|bkflag
block|{
name|BKPT_FREE
block|,
name|BKPT_SET
block|,
name|BKPT_TRIPPED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|bkpt
block|{
name|struct
name|bkpt
modifier|*
name|next
decl_stmt|;
comment|/* linked list */
name|enum
name|bkflag
name|state
decl_stmt|;
comment|/* state */
name|addr_t
name|loc
decl_stmt|;
comment|/* where set (in SP_INSTR) */
name|bpt_t
name|ins
decl_stmt|;
comment|/* original instruction(s) */
name|int
name|count
decl_stmt|;
comment|/* ??? */
name|int
name|initcnt
decl_stmt|;
comment|/* ??? */
name|char
name|comm
index|[
name|MAX_BKPTCOM
index|]
decl_stmt|;
comment|/* command to execute when tripped */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|bkpt
modifier|*
name|scanbkpt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look up a breakpoint given an address */
end_comment

end_unit

