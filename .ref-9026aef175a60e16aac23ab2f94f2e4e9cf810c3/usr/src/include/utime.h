begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)utime.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTIME_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTIME_H_
end_define

begin_struct
struct|struct
name|utimbuf
block|{
name|time_t
name|actime
decl_stmt|;
comment|/* Access time */
name|time_t
name|modtime
decl_stmt|;
comment|/* Modification time */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|utime
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|utimbuf
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
comment|/* !_UTIME_H_ */
end_comment

end_unit

