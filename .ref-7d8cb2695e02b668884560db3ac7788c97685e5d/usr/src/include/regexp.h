begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 by University of Toronto.  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Henry Spencer.  *  * %sccs.include.redist.c%  *  *	@(#)regexp.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEXP_H_
end_ifndef

begin_define
define|#
directive|define
name|_REGEXP_H_
end_define

begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_define
define|#
directive|define
name|NSUBEXP
value|10
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|regexp
modifier|*
name|regcomp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|regexec
name|__P
argument_list|(
operator|(
specifier|const
name|regexp
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regsub
name|__P
argument_list|(
operator|(
specifier|const
name|regexp
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regerror
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_REGEXP_H_ */
end_comment

end_unit

