begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ******************************************************************************  *  * Module: bb_phase.c  *  * Functions:   *	    bb_read_phases()	- Read or create the phases file.  *	    bb_phase_update()	- Update the phases file on disk.  *	    bb_set_phase()	- Add the specified flags to a phase.  *	    bb_unset_phase()	- Remove the specified flags from a phase.  *	    bb_phase_ok()	- Check if the phase is ok to make changes.  *  *  ******************************************************************************  */
end_comment

begin_comment
comment|/*  ******************************************************************************  * Include Files  ******************************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_read_phases - If the phases file exists read the entries into 	** **  the phases array.  Otherwise create the file with 0'ed entries.	** **									** *************************************************************************/
end_comment

begin_decl_stmt
name|BB_phase
name|phases
index|[
name|BB_MAX_IMP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The phases array.		*/
end_comment

begin_function
name|int
name|bb_read_phases
parameter_list|()
block|{
name|FILE
modifier|*
name|phase_file
decl_stmt|;
comment|/* Pointer to the phase file.	*/
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|/* Index into phase array.	*/
name|int
name|num_imps
decl_stmt|;
comment|/* The number of implementations*/
name|char
name|line
index|[
name|BB_MAX_LINE_LEN
index|]
decl_stmt|;
comment|/* Space for the input line.	*/
name|num_imps
operator|=
name|bb_get_imp_cnt
argument_list|()
expr_stmt|;
comment|/*     **  If the file exists read it into the phase array.     */
if|if
condition|(
operator|(
name|phase_file
operator|=
name|fopen
argument_list|(
name|BB_PHASE_FILE
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_imps
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|phases
index|[
name|i
index|]
operator|=
name|getw
argument_list|(
name|phase_file
argument_list|)
operator|)
operator|==
operator|(
name|u_char
operator|)
name|EOF
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: Phase data file incomplete.\n"
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
block|}
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_SUCCESS
return|;
block|}
comment|/*     **  The file did not exist so create it.     */
if|if
condition|(
operator|(
name|phase_file
operator|=
name|fopen
argument_list|(
name|BB_PHASE_FILE
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FAILED opening the phase data file '%s'.\n"
argument_list|,
name|BB_PHASE_FILE
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
comment|/*     **  Fill the file with zeroed phases.     */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_imps
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|putw
argument_list|(
operator|(
name|int
operator|)
name|BB_BOARD_UNSET
argument_list|,
name|phase_file
argument_list|)
operator|==
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"FAILED writting new phase file.\n"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
block|}
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_SUCCESS
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_phase_update() - The phase of the client has changed and should	** **  be written to disk.  						** **									** *************************************************************************/
end_comment

begin_function
name|int
name|bb_phase_update
parameter_list|(
name|client
parameter_list|)
name|int
name|client
decl_stmt|;
comment|/* The client with the change of phase.	*/
block|{
name|int
name|num_imps
decl_stmt|;
comment|/* The number of implementations.	*/
name|FILE
modifier|*
name|phase_file
decl_stmt|;
comment|/* Pointer to the phase file.		*/
name|long
name|seek_to
decl_stmt|;
comment|/* The position to seek to in the file.	*/
name|num_imps
operator|=
name|bb_get_imp_cnt
argument_list|()
expr_stmt|;
if|if
condition|(
name|client
operator|>=
name|num_imps
condition|)
block|{
return|return
name|BB_FAILURE
return|;
block|}
comment|/*     **  The word that we want to write is at the location client     **  integers into the file.  Take the client index and multiply     **  that by the size of the integer and that is the offset.     */
name|seek_to
operator|=
name|client
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
expr_stmt|;
comment|/*     **  Open the phase file.     */
if|if
condition|(
operator|(
name|phase_file
operator|=
name|fopen
argument_list|(
name|BB_PHASE_FILE
argument_list|,
literal|"r+"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: Could not open phase file for update.\n"
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
if|if
condition|(
name|fseek
argument_list|(
name|phase_file
argument_list|,
name|seek_to
argument_list|,
literal|0
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: Could not seek in phase file.\n"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
if|if
condition|(
name|putw
argument_list|(
operator|(
name|int
operator|)
name|phases
index|[
name|client
index|]
argument_list|,
name|phase_file
argument_list|)
operator|==
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: Could not update phase file.\n"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_FAILURE
return|;
block|}
name|fclose
argument_list|(
name|phase_file
argument_list|)
expr_stmt|;
return|return
name|BB_SUCCESS
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_set_phase() - Change the phase of a client.  This adds the	** **  flags specified to the phase in the phase list.			** **									** *************************************************************************/
end_comment

begin_function
name|int
name|bb_set_phase
parameter_list|(
name|client
parameter_list|,
name|phase
parameter_list|)
name|BB_id
name|client
decl_stmt|;
comment|/* The name of the client to change.	*/
name|int
name|phase
decl_stmt|;
comment|/* The phase to add to the client.	*/
block|{
name|int
name|client_id
decl_stmt|;
comment|/* The index of the client.		*/
comment|/*     **  Get the client's id.     */
if|if
condition|(
operator|(
name|client_id
operator|=
name|bb_get_hash
argument_list|(
name|client
argument_list|)
operator|)
operator|==
name|BB_HASH_ID_NOT_FOUND
condition|)
block|{
return|return
name|BB_BAD_CLIENT
return|;
block|}
comment|/*     **  Or the bits together to turn them on.  The bits are saying OOO WEEE.     */
name|phases
index|[
name|client_id
index|]
operator||=
name|phase
expr_stmt|;
comment|/*     **  If the phase cannot be written to disk, return an error.     */
return|return
name|bb_phase_update
argument_list|(
name|client_id
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_unset_phase() - Change the phase of a client.  This deletes the	** **  flags specified from the phase in the phase list.			** **									** *************************************************************************/
end_comment

begin_function
name|int
name|bb_unset_phase
parameter_list|(
name|client
parameter_list|,
name|phase
parameter_list|)
name|BB_id
name|client
decl_stmt|;
comment|/* The name of the client to change.	*/
name|int
name|phase
decl_stmt|;
comment|/* The phase to add to the client.	*/
block|{
name|int
name|client_id
decl_stmt|;
comment|/* The index of the client.		*/
comment|/*     **  Get the client's id.     */
if|if
condition|(
operator|(
name|client_id
operator|=
name|bb_get_hash
argument_list|(
name|client
argument_list|)
operator|)
operator|==
name|BB_HASH_ID_NOT_FOUND
condition|)
block|{
return|return
name|BB_BAD_CLIENT
return|;
block|}
comment|/*     **  Or the bits together to turn them on.  The bits are saying OOO WEEE.     */
name|phases
index|[
name|client_id
index|]
operator|&=
operator|~
name|phase
expr_stmt|;
comment|/*     **  If the phase cannot be written to disk, return an error.     */
return|return
name|bb_phase_update
argument_list|(
name|client_id
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_phase_ok() - Check to see if the phase is ok for the change to	** **  the board that will be made.					** **									** *************************************************************************/
end_comment

begin_function
name|int
name|bb_phase_ok
parameter_list|(
name|client
parameter_list|)
name|BB_id
name|client
decl_stmt|;
comment|/* The client identifier.		*/
block|{
name|int
name|client_id
decl_stmt|;
comment|/* The index of the client.		*/
comment|/*     **  Get the client's id.     */
if|if
condition|(
operator|(
name|client_id
operator|=
name|bb_get_hash
argument_list|(
name|client
argument_list|)
operator|)
operator|==
name|BB_HASH_ID_NOT_FOUND
condition|)
block|{
return|return
name|BB_BAD_CLIENT
return|;
block|}
if|if
condition|(
name|phases
index|[
name|client_id
index|]
operator|&
name|BB_SUN_PHASE
condition|)
return|return
name|BB_SUCCESS
return|;
else|else
return|return
name|BB_FAILURE
return|;
block|}
end_function

end_unit

