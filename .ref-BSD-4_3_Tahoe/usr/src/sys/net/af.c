begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)af.c	7.4 (Berkeley) 6/27/88  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"af.h"
end_include

begin_comment
comment|/*  * Address family support routines  */
end_comment

begin_decl_stmt
name|int
name|null_hash
argument_list|()
decl_stmt|,
name|null_netmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFNULL
define|\
value|{ null_hash,	null_netmatch }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|inet_hash
argument_list|()
decl_stmt|,
name|inet_netmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFINET
define|\
value|{ inet_hash,	inet_netmatch }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AFINET
value|AFNULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ns_hash
argument_list|()
decl_stmt|,
name|ns_netmatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFNS
define|\
value|{ ns_hash,	ns_netmatch }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AFNS
value|AFNULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
init|=
block|{
name|AFNULL
block|,
name|AFNULL
block|,
name|AFINET
block|,
name|AFINET
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNS
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
name|AFNULL
block|,
comment|/* through 16 */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|null_init
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|afswitch
modifier|*
name|af
decl_stmt|;
for|for
control|(
name|af
operator|=
name|afswitch
init|;
name|af
operator|<
operator|&
name|afswitch
index|[
name|AF_MAX
index|]
condition|;
name|af
operator|++
control|)
if|if
condition|(
name|af
operator|->
name|af_hash
operator|==
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
condition|)
block|{
name|af
operator|->
name|af_hash
operator|=
name|null_hash
expr_stmt|;
name|af
operator|->
name|af_netmatch
operator|=
name|null_netmatch
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_hash
argument_list|(
argument|addr
argument_list|,
argument|hp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|afhash
modifier|*
name|hp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|hp
operator|->
name|afh_nethash
operator|=
name|hp
operator|->
name|afh_hosthash
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|null_netmatch
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|a1
decl_stmt|,
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

