begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)expand.h	8.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|strlist
block|{
name|struct
name|strlist
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arglist
block|{
name|struct
name|strlist
modifier|*
name|list
decl_stmt|;
name|struct
name|strlist
modifier|*
modifier|*
name|lastp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * expandarg() flags  */
end_comment

begin_define
define|#
directive|define
name|EXP_FULL
value|0x1
end_define

begin_comment
comment|/* perform word splitting& file globbing */
end_comment

begin_define
define|#
directive|define
name|EXP_TILDE
value|0x2
end_define

begin_comment
comment|/* do normal tilde expansion */
end_comment

begin_define
define|#
directive|define
name|EXP_VARTILDE
value|0x4
end_define

begin_comment
comment|/* expand tildes in an assignment */
end_comment

begin_define
define|#
directive|define
name|EXP_REDIR
value|0x8
end_define

begin_comment
comment|/* file glob for a redirection (1 match only) */
end_comment

begin_define
define|#
directive|define
name|EXP_CASE
value|0x10
end_define

begin_comment
comment|/* keeps quotes around for CASE pattern */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_function_decl
name|void
name|expandarg
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|struct
name|arglist
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expandhere
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|patmatch
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmescapes
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|casematch
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|expandarg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expandhere
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|patmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmescapes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|casematch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

