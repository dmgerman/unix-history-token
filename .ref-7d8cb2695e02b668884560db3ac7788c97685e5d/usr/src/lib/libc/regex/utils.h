begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Henry Spencer.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer of the University of Toronto.  *  * %sccs.include.redist.c%  *  *	@(#)utils.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* utility definitions */
end_comment

begin_define
define|#
directive|define
name|DUPMAX
value|_POSIX2_RE_DUP_MAX
end_define

begin_comment
comment|/* xxx is this right? */
end_comment

begin_define
define|#
directive|define
name|INFINITY
value|(DUPMAX+1)
end_define

begin_define
define|#
directive|define
name|NC
value|((CHAR_MAX)-(CHAR_MIN)+1)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|REDEBUG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_comment
comment|/* no assertions please */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<assert.h>
end_include

end_unit

