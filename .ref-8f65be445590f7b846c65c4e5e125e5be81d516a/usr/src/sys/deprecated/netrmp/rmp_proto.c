begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rmp_proto.c 1.3 89/06/07$  *  *	@(#)rmp_proto.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"rmp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RMP
end_ifdef

begin_comment
comment|/*  * HP Remote Maintenance Protocol (RMP) family: BOOT  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|rmpdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|raw_usrreq
argument_list|()
decl_stmt|,
name|rmp_output
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
name|rmpsw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
operator|&
name|rmpdomain
block|,
name|RMPPROTO_BOOT
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|rmp_output
block|,
literal|0
block|,
literal|0
block|,
name|raw_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,   }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|rmpdomain
init|=
block|{
name|AF_RMP
block|,
literal|"RMP"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|rmpsw
block|,
operator|&
name|rmpsw
index|[
sizeof|sizeof
argument_list|(
name|rmpsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|rmpsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

