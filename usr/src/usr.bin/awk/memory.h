begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** memory.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	memory.h,v $  * Revision 5.1  91/12/05  07:59:28  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  memory.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEMORY_H
end_ifndef

begin_define
define|#
directive|define
name|MEMORY_H
end_define

begin_include
include|#
directive|include
file|"zmalloc.h"
end_include

begin_define
define|#
directive|define
name|new_CELL
parameter_list|()
value|(CELL *) zmalloc(sizeof(CELL))
end_define

begin_define
define|#
directive|define
name|free_CELL
parameter_list|(
name|p
parameter_list|)
value|zfree(p,sizeof(CELL))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPRESS_NEW_STRING_PROTO
end_ifndef

begin_decl_stmt
name|STRING
modifier|*
name|PROTO
argument_list|(
name|new_STRING
argument_list|,
operator|(
name|char
operator|*
operator|,
operator|...
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
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|DB_free_STRING
argument_list|,
operator|(
name|STRING
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|free_STRING
parameter_list|(
name|s
parameter_list|)
value|DB_free_STRING(s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|free_STRING
parameter_list|(
name|sval
parameter_list|)
value|if ( -- (sval)->ref_cnt == 0 )\                                 zfree(sval, (sval)->len+STRING_OH) ; else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MEMORY_H */
end_comment

end_unit

