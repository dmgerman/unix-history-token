begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** files.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	files.h,v $  * Revision 5.1  91/12/05  07:59:18  brennan  * 1.1 pre-release  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILES_H
end_ifndef

begin_define
define|#
directive|define
name|FILES_H
end_define

begin_comment
comment|/* IO redirection types */
end_comment

begin_define
define|#
directive|define
name|F_IN
value|(-5)
end_define

begin_define
define|#
directive|define
name|PIPE_IN
value|(-4)
end_define

begin_define
define|#
directive|define
name|PIPE_OUT
value|(-3)
end_define

begin_define
define|#
directive|define
name|F_APPEND
value|(-2)
end_define

begin_define
define|#
directive|define
name|F_TRUNC
value|(-1)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for pipes and system() */
end_comment

begin_decl_stmt
name|PTR
name|PROTO
argument_list|(
name|file_find
argument_list|,
operator|(
name|STRING
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|file_close
argument_list|,
operator|(
name|STRING
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PTR
name|PROTO
argument_list|(
name|get_pipe
argument_list|,
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|wait_for
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|close_out_pipes
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_FAKE_PIPES
end_if

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|close_fake_pipes
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|close_fake_outpipe
argument_list|,
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|tmp_file_name
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|DOSexec
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|binmode
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|set_binmode
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

