begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** init.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	init.h,v $  * Revision 5.1  91/12/05  07:59:22  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* init.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INIT_H
end_ifndef

begin_define
define|#
directive|define
name|INIT_H
end_define

begin_include
include|#
directive|include
file|"symtype.h"
end_include

begin_comment
comment|/* nodes to link file names for multiple    -f option */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pfile
block|{
name|struct
name|pfile
modifier|*
name|link
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
block|}
name|PFILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|PFILE
modifier|*
name|pfile_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sprintf_buff
decl_stmt|,
modifier|*
name|sprintf_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|initialize
argument_list|,
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|code_init
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
name|code_cleanup
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
name|compile_cleanup
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
name|scan_init
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|scan_cleanup
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
name|bi_vars_init
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
name|bi_funct_init
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
name|print_init
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
name|kw_init
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
name|field_init
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
name|fpe_init
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
name|load_environ
argument_list|,
operator|(
name|ARRAY
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|set_stderr
argument_list|,
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
comment|/* INIT_H  */
end_comment

end_unit

