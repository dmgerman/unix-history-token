begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)table.c	8.3 (Berkeley) 4/2/94"
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
ifdef|#
directive|ifdef
name|RESTRICT_FULLNAME_CHANGE
comment|/* do not allow fullname changes */
block|{
literal|"full name"
block|,
name|p_gecos
block|,
literal|1
block|,
literal|9
block|,
name|e2
block|,   }
block|,
else|#
directive|else
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
endif|#
directive|endif
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
literal|"office location"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|15
block|,
name|e2
block|,   }
block|,
block|{
literal|"other information"
block|,
name|p_gecos
block|,
literal|0
block|,
literal|11
block|,
name|e1
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

