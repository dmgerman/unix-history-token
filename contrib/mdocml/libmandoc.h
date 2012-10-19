begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: libmandoc.h,v 1.29 2011/12/02 01:37:14 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBMANDOC_H
end_ifndef

begin_define
define|#
directive|define
name|LIBMANDOC_H
end_define

begin_enum
enum|enum
name|rofferr
block|{
name|ROFF_CONT
block|,
comment|/* continue processing line */
name|ROFF_RERUN
block|,
comment|/* re-run roff interpreter with offset */
name|ROFF_APPEND
block|,
comment|/* re-run main parser, appending next line */
name|ROFF_REPARSE
block|,
comment|/* re-run main parser on the result */
name|ROFF_SO
block|,
comment|/* include another file */
name|ROFF_IGN
block|,
comment|/* ignore current line */
name|ROFF_TBL
block|,
comment|/* a table row was successfully parsed */
name|ROFF_EQN
block|,
comment|/* an equation was successfully parsed */
name|ROFF_ERR
comment|/* badness: puke and stop */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|regs
block|{
name|REG_nS
init|=
literal|0
block|,
comment|/* nS register */
name|REG__MAX
block|}
enum|;
end_enum

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|roff
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mdoc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|man
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|mandoc_msg
parameter_list|(
name|enum
name|mandocerr
parameter_list|,
name|struct
name|mparse
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mandoc_vmsg
parameter_list|(
name|enum
name|mandocerr
parameter_list|,
name|struct
name|mparse
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mandoc_getarg
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mandoc_normdate
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mandoc_eos
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mandoc_getcontrol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mandoc_strntoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|mandoc_a2msec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_free
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mdoc
modifier|*
name|mdoc_alloc
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|,
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdoc_reset
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mdoc_parseln
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mdoc_endparse
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mdoc_addspan
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
specifier|const
name|struct
name|tbl_span
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mdoc_addeqn
parameter_list|(
name|struct
name|mdoc
modifier|*
parameter_list|,
specifier|const
name|struct
name|eqn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_free
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|man
modifier|*
name|man_alloc
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|,
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|man_reset
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_parseln
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_endparse
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_addspan
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
specifier|const
name|struct
name|tbl_span
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|man_addeqn
parameter_list|(
name|struct
name|man
modifier|*
parameter_list|,
specifier|const
name|struct
name|eqn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roff_free
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|roff
modifier|*
name|roff_alloc
parameter_list|(
name|struct
name|mparse
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roff_reset
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|rofferr
name|roff_parseln
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roff_endparse
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|roff_regisset
parameter_list|(
specifier|const
name|struct
name|roff
modifier|*
parameter_list|,
name|enum
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|roff_regget
parameter_list|(
specifier|const
name|struct
name|roff
modifier|*
parameter_list|,
name|enum
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|roff_regunset
parameter_list|(
name|struct
name|roff
modifier|*
parameter_list|,
name|enum
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|roff_strdup
parameter_list|(
specifier|const
name|struct
name|roff
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|char		 roff_eqndelim(const struct roff *); void		 roff_openeqn(struct roff *, const char *,  			int, int, const char *); int		 roff_closeeqn(struct roff *);
endif|#
directive|endif
end_endif

begin_function_decl
specifier|const
name|struct
name|tbl_span
modifier|*
name|roff_span
parameter_list|(
specifier|const
name|struct
name|roff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|eqn
modifier|*
name|roff_eqn
parameter_list|(
specifier|const
name|struct
name|roff
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!LIBMANDOC_H*/
end_comment

end_unit

