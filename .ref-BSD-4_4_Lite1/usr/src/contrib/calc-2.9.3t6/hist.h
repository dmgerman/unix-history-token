begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Definitions for command history module.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|HIST_PROTO
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HIST_PROTO
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Default binding file and history size.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HIST_BINDING_FILE
end_ifndef

begin_define
define|#
directive|define
name|HIST_BINDING_FILE
value|"/usr/lib/hist.bind"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HIST_SIZE
end_ifndef

begin_define
define|#
directive|define
name|HIST_SIZE
value|(1024*10)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * path search defines  */
end_comment

begin_define
define|#
directive|define
name|HOMECHAR
value|'~'
end_define

begin_comment
comment|/* char which indicates home directory */
end_comment

begin_define
define|#
directive|define
name|DOTCHAR
value|'.'
end_define

begin_comment
comment|/* char which indicates current directory */
end_comment

begin_define
define|#
directive|define
name|PATHCHAR
value|'/'
end_define

begin_comment
comment|/* char which separates path components */
end_comment

begin_define
define|#
directive|define
name|LISTCHAR
value|':'
end_define

begin_comment
comment|/* char which separates paths in a list */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|1024
end_define

begin_comment
comment|/* maximum length of path name */
end_comment

begin_comment
comment|/*  * Possible returns from hist_init.  Note that an error from hist_init does  * not prevent calling the other routines, but fancy command line editing  * is then disabled.  */
end_comment

begin_define
define|#
directive|define
name|HIST_SUCCESS
value|0
end_define

begin_comment
comment|/* successfully inited */
end_comment

begin_define
define|#
directive|define
name|HIST_INITED
value|1
end_define

begin_comment
comment|/* initialization is already done */
end_comment

begin_define
define|#
directive|define
name|HIST_NOFILE
value|2
end_define

begin_comment
comment|/* bindings file could not be read */
end_comment

begin_define
define|#
directive|define
name|HIST_NOTTY
value|3
end_define

begin_comment
comment|/* terminal modes could not be set */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hist_init
name|HIST_PROTO
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hist_term
name|HIST_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hist_getline
name|HIST_PROTO
argument_list|(
operator|(
name|char
operator|*
name|prompt
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|hist_saveline
name|HIST_PROTO
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* END CODE */
end_comment

end_unit

