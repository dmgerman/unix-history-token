begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fnmatch.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FNMATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_FNMATCH_H_
end_define

begin_define
define|#
directive|define
name|FNM_NOMATCH
value|1
end_define

begin_comment
comment|/* Match failed. */
end_comment

begin_define
define|#
directive|define
name|FNM_NOESCAPE
value|0x01
end_define

begin_comment
comment|/* Disable backslash escaping. */
end_comment

begin_define
define|#
directive|define
name|FNM_PATHNAME
value|0x02
end_define

begin_comment
comment|/* Slash must be matched by slash. */
end_comment

begin_define
define|#
directive|define
name|FNM_PERIOD
value|0x04
end_define

begin_comment
comment|/* Period must be matched by period. */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
name|int
name|fnmatch
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FNMATCH_H_ */
end_comment

end_unit

