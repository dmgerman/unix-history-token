begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** bi_funct.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	bi_funct.h,v $  * Revision 5.1  91/12/05  07:59:03  brennan  * 1.1 pre-release  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BI_FUNCT_H
end_ifndef

begin_define
define|#
directive|define
name|BI_FUNCT_H
value|1
end_define

begin_include
include|#
directive|include
file|"symtype.h"
end_include

begin_decl_stmt
specifier|extern
name|BI_REC
name|bi_funct
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|bi_init
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* builtin string functions */
end_comment

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|bi_print
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
name|bi_printf
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
name|bi_length
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
name|bi_index
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
name|bi_substr
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
name|bi_sprintf
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
name|bi_split
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
name|bi_match
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
name|bi_getline
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
name|bi_sub
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
name|bi_gsub
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
name|bi_toupper
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
name|bi_tolower
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* builtin arith functions */
end_comment

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|bi_sin
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
name|bi_cos
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
name|bi_atan2
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
name|bi_log
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
name|bi_exp
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
name|bi_int
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
name|bi_sqrt
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
name|bi_srand
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
name|bi_rand
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* other builtins */
end_comment

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|bi_close
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
name|bi_system
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BI_FUNCT_H  */
end_comment

end_unit

