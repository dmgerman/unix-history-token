begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This defines a structure for a receive or send ring buffer.  *  * The circular buffer actually has three parts:  *(((  *	full, sent, not acked:	[ack, send)  *	full, not sent:		[send, add)  *	empty:			[add, ack)  *]]]  *  * Any given byte will go through "empty" -> "send" -> "ack" -> "empty"  * as data is moved through it.  The transition from "ack" to "empty"  * may occur instantaneously (as in the case of sending data up to another  * process).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|ack
decl_stmt|,
comment|/* where you can't add at */
modifier|*
name|send
decl_stmt|,
comment|/* where data comes out of */
modifier|*
name|add
decl_stmt|,
comment|/* where data comes in to */
modifier|*
name|bottom
decl_stmt|,
comment|/* lowest address in buffer */
modifier|*
name|top
decl_stmt|;
comment|/* highest address+1 in buffer */
name|int
name|size
decl_stmt|;
comment|/* size in bytes of buffer */
name|u_long
name|acktime
decl_stmt|,
comment|/* the relations between these clocks */
name|sendtime
decl_stmt|,
comment|/* help us keep straight full, empty, etc. */
name|addtime
decl_stmt|;
block|}
name|Ring
typedef|;
end_typedef

begin_comment
comment|/* Here are some functions and macros to deal with the ring buffer */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LINT_ARGS
argument_list|)
end_if

begin_comment
comment|/* Initialization routine */
end_comment

begin_function_decl
specifier|extern
name|int
name|ring_init
parameter_list|(
name|Ring
modifier|*
name|ring
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Data movement routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ring_add_data
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|char
operator|*
name|buffer
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|,
name|ring_send_data
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|char
operator|*
name|buffer
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer state transition routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ring_added
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|,
name|ring_sent
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|,
name|ring_acked
argument_list|(
name|Ring
operator|*
name|ring
argument_list|,
name|int
name|count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer state query routines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ring_empty_count
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_empty_consecutive
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_unsent_count
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_unsent_consecutive
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|,
name|ring_unacked_count
argument_list|(
name|Ring
operator|*
name|ring
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LINT_ARGS) */
end_comment

end_unit

