begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mem.h	7.2 (Berkeley) 5/7/88  */
end_comment

begin_comment
comment|/*  * Compute maximum possible number of memory controllers,  * for sizing of the mcraddr array.  */
end_comment

begin_if
if|#
directive|if
name|VAX8200
operator|||
name|VAX780
end_if

begin_define
define|#
directive|define
name|MAXNMCR
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNMCR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX780
end_if

begin_comment
comment|/* controller types */
end_comment

begin_define
define|#
directive|define
name|M780C
value|1
end_define

begin_define
define|#
directive|define
name|M780EL
value|2
end_define

begin_define
define|#
directive|define
name|M780EU
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMINTVL
value|(60*10)
end_define

begin_comment
comment|/* 10 minutes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|nmcr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|mcraddr
index|[
name|MAXNMCR
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|VAX780
end_if

begin_decl_stmt
name|int
name|mcrtype
index|[
name|MAXNMCR
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

