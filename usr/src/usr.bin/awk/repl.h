begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** repl.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	repl.h,v $  * Revision 5.1  91/12/05  07:59:32  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* repl.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REPL_H
end_ifndef

begin_define
define|#
directive|define
name|REPL_H
end_define

begin_decl_stmt
name|PTR
name|PROTO
argument_list|(
name|re_compile
argument_list|,
operator|(
name|STRING
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|re_uncompile
argument_list|,
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|repl_compile
argument_list|,
operator|(
name|STRING
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|repl_uncompile
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|repl_destroy
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|replv_cpy
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|replv_to_repl
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|STRING
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

