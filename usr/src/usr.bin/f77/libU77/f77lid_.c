begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)f77lid_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * f77lid_ - the ID strings for f77 libraries.  *  * Usage:  *	include 'external f77lid' in the declarations in any f77 module.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|libU77_id
index|[]
decl_stmt|,
name|libI77_id
index|[]
decl_stmt|,
name|libF77_id
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f77lid_
index|[]
init|=
block|{
name|libU77_id
block|,
name|libI77_id
block|,
name|libF77_id
block|}
decl_stmt|;
end_decl_stmt

end_unit

