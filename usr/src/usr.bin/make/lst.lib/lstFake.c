begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * lstFake.c --  *	This is a file whose sole purpose is to force ranlib to  *	place enough entries in the library's table of contents to  *	prevent it (the table of contents) from looking like an object  *	file. As of this writing, the table had 0410 (shared text) entries  *	in it, so we define five junk variables to up the number beyond  *	the range of the magic numbers.  *  * Copyright (c) 1988 by the Regents of the University of California  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  The University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: lstFake.c,v 1.2 88/11/17 20:52:30 adam Exp $ SPRITE (Berkeley)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|int
name|_junk_one__
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_two__
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_three__
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_four__
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_five__
init|=
literal|5
decl_stmt|;
end_decl_stmt

end_unit

