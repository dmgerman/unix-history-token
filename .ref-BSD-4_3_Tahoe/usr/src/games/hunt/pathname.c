begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)pathname.c	5.2 (Berkeley) 6/27/88"
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
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_comment
comment|/*  * There is no particular significance to the numbers assigned  * to Test_port and Sock_port.  They're just random numbers greater  * than then range reserved for privileged sockets.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|Driver
init|=
literal|"/va/conrad/games/src/hunt/hunt.driver.dbg"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_decl_stmt
name|int
name|Test_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'t'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Sock_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'s'
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_decl_stmt
name|char
modifier|*
name|Sock_name
init|=
literal|"/tmp/hunt"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_else
else|#
directive|else
else|DEBUG
end_else

begin_decl_stmt
name|char
modifier|*
name|Driver
init|=
literal|"/usr/games/lib/hunt.driver"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INTERNET
end_ifdef

begin_decl_stmt
name|int
name|Test_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'t'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Sock_port
init|=
operator|(
literal|'h'
operator|<<
literal|8
operator|)
operator||
literal|'s'
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|INTERNET
end_else

begin_decl_stmt
name|char
modifier|*
name|Sock_name
init|=
literal|"/tmp/hunt"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|INTERNET
end_endif

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

end_unit

