begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
name|sccsid
init|=
literal|"@(#)config.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * This file contains definitions of network data used by Mail  * when replying.  See also:  configdefs.h and optim.c  */
end_comment

begin_comment
comment|/*  * The subterfuge with CONFIGFILE is to keep cc from seeing the  * external defintions in configdefs.h.  */
end_comment

begin_define
define|#
directive|define
name|CONFIGFILE
end_define

begin_include
include|#
directive|include
file|"configdefs.h"
end_include

begin_comment
comment|/*  * Set of network separator characters.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|metanet
init|=
literal|"!^:%@."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Host table of "known" hosts.  See the comment in configdefs.h;  * not all accessible hosts need be here (fortunately).  */
end_comment

begin_decl_stmt
name|struct
name|netmach
name|netmach
index|[]
init|=
block|{
name|EMPTY
block|,
name|EMPTYID
block|,
name|AN
block|,
comment|/* Filled in dynamically */
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Table of ordered of preferred networks.  You probably won't need  * to fuss with this unless you add a new network character (foolishly).  */
end_comment

begin_decl_stmt
name|struct
name|netorder
name|netorder
index|[]
init|=
block|{
name|AN
block|,
literal|'@'
block|,
name|AN
block|,
literal|'%'
block|,
name|SN
block|,
literal|':'
block|,
name|BN
block|,
literal|'!'
block|,
operator|-
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Table to convert from network separator code in address to network  * bit map kind.  With this transformation, we can deal with more than  * one character having the same meaning easily.  */
end_comment

begin_decl_stmt
name|struct
name|ntypetab
name|ntypetab
index|[]
init|=
block|{
literal|'%'
block|,
name|AN
block|,
literal|'@'
block|,
name|AN
block|,
literal|':'
block|,
name|SN
block|,
literal|'!'
block|,
name|BN
block|,
literal|'^'
block|,
name|BN
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nkindtab
name|nkindtab
index|[]
init|=
block|{
name|AN
block|,
name|IMPLICIT
block|,
name|BN
block|,
name|EXPLICIT
block|,
name|SN
block|,
name|IMPLICIT
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

