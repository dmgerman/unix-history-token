begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCOP - SSCOP SAP interface processing   *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_var.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_misc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_var.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables  */
end_comment

begin_comment
comment|/*  * Stack commands with arg1 containing an buffer pointer  */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|sscop_buf1
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
comment|/* SSCOP_INIT */
literal|0
block|,
comment|/* SSCOP_TERM */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
comment|/* SSCOP_ESTABLISH_REQ */
literal|0
block|,
literal|1
block|,
comment|/* SSCOP_ESTABLISH_RSP */
literal|0
block|,
literal|1
block|,
comment|/* SSCOP_RELEASE_REQ */
literal|0
block|,
literal|0
block|,
literal|1
block|,
comment|/* SSCOP_DATA_REQ */
literal|0
block|,
literal|1
block|,
comment|/* SSCOP_RESYNC_REQ */
literal|0
block|,
literal|0
block|,
comment|/* SSCOP_RESYNC_RSP */
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* SSCOP_RECOVER_RSP */
literal|1
block|,
comment|/* SSCOP_UNITDATA_REQ */
literal|0
block|,
literal|0
block|,
comment|/* SSCOP_RETRIEVE_REQ */
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SSCOP Lower Stack Command Handler  *   * This function will receive all of the stack commands issued from the   * layer above SSCOP (ie. using the SSCOP SAP).  The appropriate processing  * function will be determined based on the received stack command and the   * current sscop control block state.  *  * Arguments:  *	cmd	stack command code  *	tok	session token  *	arg1	command specific argument  *	arg2	command specific argument  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_lower
parameter_list|(
name|cmd
parameter_list|,
name|tok
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|int
name|cmd
decl_stmt|;
name|void
modifier|*
name|tok
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
name|struct
name|sscop
modifier|*
name|sop
init|=
operator|(
expr|struct
name|sscop
operator|*
operator|)
name|tok
decl_stmt|;
name|void
function_decl|(
modifier|*
modifier|*
name|stab
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|val
decl_stmt|;
name|ATM_DEBUG5
argument_list|(
literal|"sscop_lower: cmd=0x%x, sop=%p, state=%d, arg1=0x%x, arg2=0x%x\n"
argument_list|,
name|cmd
argument_list|,
name|sop
argument_list|,
name|sop
operator|->
name|so_state
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
comment|/* 	 * Validate stack command 	 */
name|val
operator|=
name|cmd
operator|&
name|STKCMD_VAL_MASK
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|u_int
operator|)
name|cmd
operator|<
operator|(
name|u_int
operator|)
name|SSCOP_CMD_MIN
operator|)
operator|||
operator|(
operator|(
name|u_int
operator|)
name|cmd
operator|>
operator|(
name|u_int
operator|)
name|SSCOP_CMD_MAX
operator|)
operator|||
operator|(
operator|(
name|stab
operator|=
operator|(
name|sop
operator|->
name|so_vers
operator|==
name|SSCOP_VERS_QSAAL
condition|?
name|sscop_qsaal_aatab
index|[
name|val
index|]
else|:
name|sscop_q2110_aatab
index|[
name|val
index|]
operator|)
operator|)
operator|==
name|NULL
operator|)
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sscop_lower: unknown cmd 0x%x, sop=%p\n"
argument_list|,
name|cmd
argument_list|,
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Validate sscop state 	 */
if|if
condition|(
name|sop
operator|->
name|so_state
operator|>
name|SOS_MAXSTATE
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sscop_lower: invalid state sop=%p, state=%d\n"
argument_list|,
name|sop
argument_list|,
name|sop
operator|->
name|so_state
argument_list|)
expr_stmt|;
comment|/* 		 * Release possible buffer 		 */
if|if
condition|(
name|sscop_buf1
index|[
name|val
index|]
condition|)
block|{
if|if
condition|(
name|arg1
condition|)
name|KB_FREEALL
argument_list|(
operator|(
name|KBuffer
operator|*
operator|)
name|arg1
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
comment|/* 	 * Validate command/state combination 	 */
name|func
operator|=
name|stab
index|[
name|sop
operator|->
name|so_state
index|]
expr_stmt|;
if|if
condition|(
name|func
operator|==
name|NULL
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sscop_lower: invalid cmd/state: sop=%p, cmd=0x%x, state=%d\n"
argument_list|,
name|sop
argument_list|,
name|cmd
argument_list|,
name|sop
operator|->
name|so_state
argument_list|)
expr_stmt|;
comment|/* 		 * Release possible buffer 		 */
if|if
condition|(
name|sscop_buf1
index|[
name|val
index|]
condition|)
block|{
if|if
condition|(
name|arg1
condition|)
name|KB_FREEALL
argument_list|(
operator|(
name|KBuffer
operator|*
operator|)
name|arg1
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
comment|/* 	 * Call event processing function 	 */
call|(
modifier|*
name|func
call|)
argument_list|(
name|sop
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * No-op Processor (no buffers)  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	command-specific argument  *	arg2	command-specific argument  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_aa_noop_0
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * Nothing to do 	 */
return|return;
block|}
end_function

begin_comment
comment|/*  * No-op Processor (arg1 == buffer)  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	command-specific argument (buffer pointer)  *	arg2	command-specific argument  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_aa_noop_1
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
comment|/* 	 * Just free buffer chain 	 */
if|if
condition|(
name|arg1
condition|)
name|KB_FREEALL
argument_list|(
operator|(
name|KBuffer
operator|*
operator|)
name|arg1
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SSCOP_INIT / SOS_INST Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	command specific argument  *	arg2	command specific argument  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_init_inst
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Make ourselves ready and pass on the INIT 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
comment|/* 	 * Validate SSCOP version to use 	 */
switch|switch
condition|(
operator|(
expr|enum
name|sscop_vers
operator|)
name|arg1
condition|)
block|{
case|case
name|SSCOP_VERS_QSAAL
case|:
break|break;
case|case
name|SSCOP_VERS_Q2110
case|:
break|break;
default|default:
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop: bad version\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|sop
operator|->
name|so_vers
operator|=
operator|(
expr|enum
name|sscop_vers
operator|)
name|arg1
expr_stmt|;
comment|/* 	 * Copy SSCOP connection parameters to use 	 */
name|sop
operator|->
name|so_parm
operator|=
operator|*
operator|(
expr|struct
name|sscop_parms
operator|*
operator|)
name|arg2
expr_stmt|;
comment|/* 	 * Initialize lower layers 	 */
name|STACK_CALL
argument_list|(
name|CPCS_INIT
argument_list|,
name|sop
operator|->
name|so_lower
argument_list|,
name|sop
operator|->
name|so_tokl
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* 		 * Should never happen 		 */
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop: INIT failure\n"
argument_list|)
expr_stmt|;
return|return;
block|}
return|return;
block|}
end_function

begin_comment
comment|/*  * SSCOP_TERM / SOS_* Command Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	arg1	command specific argument  *	arg2	command specific argument  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|sscop_term_all
parameter_list|(
name|sop
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|int
name|arg1
decl_stmt|;
name|int
name|arg2
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Set termination state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_TERM
expr_stmt|;
comment|/* 	 * Pass the TERM down the stack 	 */
name|STACK_CALL
argument_list|(
name|CPCS_TERM
argument_list|,
name|sop
operator|->
name|so_lower
argument_list|,
name|sop
operator|->
name|so_tokl
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* 		 * Should never happen 		 */
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop: TERM failure\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Unlink and free the connection block 	 */
name|UNLINK
argument_list|(
name|sop
argument_list|,
expr|struct
name|sscop
argument_list|,
name|sscop_head
argument_list|,
name|so_next
argument_list|)
expr_stmt|;
name|atm_free
argument_list|(
operator|(
name|caddr_t
operator|)
name|sop
argument_list|)
expr_stmt|;
name|sscop_vccnt
operator|--
expr_stmt|;
return|return;
block|}
end_function

end_unit

