begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *	@(#)pat_rep.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * data structure for storing user supplied replacement strings (-s)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|replace
block|{
name|char
modifier|*
name|nstr
decl_stmt|;
comment|/* the new string we will substitute with */
ifdef|#
directive|ifdef
name|NET2_REGEX
name|regexp
modifier|*
name|rcmp
decl_stmt|;
comment|/* compiled regular expression used to match */
else|#
directive|else
name|regex_t
name|rcmp
decl_stmt|;
comment|/* compiled regular expression used to match */
endif|#
directive|endif
name|int
name|flgs
decl_stmt|;
comment|/* print conversions? global in operation?  */
define|#
directive|define
name|PRNT
value|0x1
define|#
directive|define
name|GLOB
value|0x2
name|struct
name|replace
modifier|*
name|fow
decl_stmt|;
comment|/* pointer to next pattern */
block|}
name|REPLACE
typedef|;
end_typedef

end_unit

