begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_struct
struct|struct
name|process
block|{
name|Process
modifier|*
name|p_next
decl_stmt|;
ifdef|#
directive|ifdef
name|PIPEPROCS
name|int
name|p_toproc
decl_stmt|,
comment|/* read p_fromproc and write p_toproc */
name|p_portpid
decl_stmt|,
comment|/* pid of child (the portsrv) */
name|p_pid
decl_stmt|;
comment|/* pid of real child i.e. not portsrv */
else|#
directive|else
name|int
name|p_fd
decl_stmt|,
comment|/* file descriptor of pty? opened r/w */
name|p_pid
decl_stmt|;
comment|/* pid of child (the shell) */
endif|#
directive|endif
name|Buffer
modifier|*
name|p_buffer
decl_stmt|;
comment|/* add output to end of this buffer */
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* ... */
name|char
name|p_state
decl_stmt|,
comment|/* State */
name|p_howdied
decl_stmt|,
comment|/* Killed? or Exited? */
name|p_reason
decl_stmt|;
comment|/* If signaled, p_reason is the signal; else 				   it is the the exit code */
name|Mark
modifier|*
name|p_mark
decl_stmt|;
comment|/* where output left us */
name|char
name|p_dbx_mode
decl_stmt|;
comment|/* whether to parse output for file/lineno 				   pairs */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|NumProcs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PIPEPROCS
end_ifdef

begin_decl_stmt
specifier|extern
name|File
modifier|*
name|ProcInput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kbd_pid
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|long
name|global_fd
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|read_proc
name|proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|,
name|pinit
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|KillProcs
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|pbuftiedp
name|proto
argument_list|(
operator|(
name|Buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pstate
name|proto
argument_list|(
operator|(
name|Process
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

