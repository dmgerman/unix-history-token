begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  *  * SCCS: @(#) tclRegexp.h 1.6 96/04/02 18:43:57  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEXP
end_ifndef

begin_define
define|#
directive|define
name|_REGEXP
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TCL
end_ifndef

begin_include
include|#
directive|include
file|"tcl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NSUBEXP must be at least 10, and no greater than 117 or the parser  * will not work properly.  */
end_comment

begin_define
define|#
directive|define
name|NSUBEXP
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|char
modifier|*
name|startp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
modifier|*
name|endp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
name|regstart
decl_stmt|;
comment|/* Internal use only. */
name|char
name|reganch
decl_stmt|;
comment|/* Internal use only. */
name|char
modifier|*
name|regmust
decl_stmt|;
comment|/* Internal use only. */
name|int
name|regmlen
decl_stmt|;
comment|/* Internal use only. */
name|char
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_decl_stmt
name|EXTERN
name|regexp
modifier|*
name|TclRegComp
name|_ANSI_ARGS_
argument_list|(
operator|(
name|char
operator|*
name|exp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|TclRegExec
name|_ANSI_ARGS_
argument_list|(
operator|(
name|regexp
operator|*
name|prog
operator|,
name|char
operator|*
name|string
operator|,
name|char
operator|*
name|start
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|void
name|TclRegSub
name|_ANSI_ARGS_
argument_list|(
operator|(
name|regexp
operator|*
name|prog
operator|,
name|char
operator|*
name|source
operator|,
name|char
operator|*
name|dest
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|void
name|TclRegError
name|_ANSI_ARGS_
argument_list|(
operator|(
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|TclGetRegError
name|_ANSI_ARGS_
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

begin_comment
comment|/* REGEXP */
end_comment

end_unit

