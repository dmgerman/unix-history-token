begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)table.c	8.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"chpass.h"
end_include

begin_decl_stmt
name|char
name|e1
index|[]
init|=
literal|": "
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|e2
index|[]
init|=
literal|":,"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ENTRY
name|list
index|[]
init|=
block|{
block|{
literal|"login"
block|,
name|p_login
block|,
literal|1
block|,
literal|5
block|,
name|e1
block|,   }
block|,
block|{
literal|"password"
block|,
name|p_passwd
block|,
literal|1
block|,
literal|8
block|,
name|e1
block|,   }
block|,
block|{
literal|"uid"
block|,
name|p_uid
block|,
literal|1
block|,
literal|3
block|,
name|e1
block|,   }
block|,
block|{
literal|"gid"
block|,
name|p_gid
block|,
literal|1
block|,
literal|3
block|,
name|e1
block|,   }
block|,
block|{
literal|"class"
block|,
name|p_class
block|,
literal|1
block|,
literal|5
block|,
name|e1
block|,   }
block|,
block|{
literal|"change"
block|,
name|p_change
block|,
literal|1
block|,
literal|6
block|,
name|NULL
block|, }
block|,
block|{
literal|"expire"
block|,
name|p_expire
block|,
literal|1
block|,
literal|6
block|,
name|NULL
block|, }
block|,
block|{
literal|"full name"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|9
block|,
name|e2
block|,   }
block|,
block|{
literal|"office phone"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|12
block|,
name|e2
block|,   }
block|,
block|{
literal|"home phone"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|10
block|,
name|e2
block|,   }
block|,
block|{
literal|"location"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|8
block|,
name|e2
block|,   }
block|,
block|{
literal|"home directory"
block|,
name|p_hdir
block|,
literal|1
block|,
literal|14
block|,
name|e1
block|,   }
block|,
block|{
literal|"shell"
block|,
name|p_shell
block|,
literal|0
block|,
literal|5
block|,
name|e1
block|,   }
block|,
block|{
name|NULL
block|,
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

end_unit

