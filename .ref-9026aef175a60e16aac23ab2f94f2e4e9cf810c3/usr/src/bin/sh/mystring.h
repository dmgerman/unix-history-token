begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)mystring.h	8.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
name|void
name|scopyn
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prefix
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|number
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
name|is_number
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

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2) == 0)
end_define

begin_define
define|#
directive|define
name|scopy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|((void)strcpy(s2, s1))
end_define

end_unit

