begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* appl.h */
end_comment

begin_enum
enum|enum
block|{
name|E_NOMEM
init|=
literal|1
block|,
name|E_DOC
block|,
name|E_EXEC
block|,
name|E_FORK
block|,
name|E_WAIT
block|,
name|E_SIGNAL
block|,
name|E_OPEN
block|,
name|E_CAPBOTCH
block|,
name|E_SUBDOC
block|}
enum|;
end_enum

begin_decl_stmt
name|VOID
name|process_document
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|output_conforming
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|appl_error
name|VP
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUBDOC
end_ifdef

begin_decl_stmt
name|int
name|run_process
name|P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|make_argv
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|get_subcaps
name|P
argument_list|(
operator|(
name|void
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
name|SUPPORT_SUBDOC
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|suberr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|suppsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|locsw
decl_stmt|;
end_decl_stmt

end_unit

