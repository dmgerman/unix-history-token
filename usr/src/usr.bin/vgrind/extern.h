begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  *  * %sccs.include.redist.c%  *  *      @(#)extern.h	1.3 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|boolean
name|_escaped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if last character was an escape */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of the current string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_acmbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string introducing a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_acmend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_blkbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string begining of a block */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_blkend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a block */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_chrbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for character constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_chrend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for character constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_combeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string introducing a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_comend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string ending a comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|l_escape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character used to escape characters */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_keywds
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keyword table address */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|l_onecase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper and lower case are equivalent */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_prcbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular expr for procedure begin */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_strbeg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for string constant */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|l_strend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delimiter for string constant */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|l_toplex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedures only defined at top lex level */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the language indicator */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|int
name|STRNCMP
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|convexp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|expmatch
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

