begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)version.c	5.3 (Berkeley) 2/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notdef */
end_comment

begin_comment
comment|/*  * Just keep track of the date/sid of this version of Mail.  * Load this file first to get a "total" Mail version.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsID
init|=
literal|"@(#)UCB Mail Version 5.3 (2/18/88)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|version
init|=
literal|"5.3 2/18/88"
decl_stmt|;
end_decl_stmt

end_unit

