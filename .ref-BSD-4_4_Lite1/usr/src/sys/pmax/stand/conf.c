begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<stand/stand.h>
end_include

begin_decl_stmt
specifier|const
name|struct
name|callback
modifier|*
name|callv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nullsys
argument_list|()
decl_stmt|,
name|nodev
argument_list|()
decl_stmt|,
name|noioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rzstrategy
argument_list|()
decl_stmt|,
name|rzopen
argument_list|()
decl_stmt|,
name|rzclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rzioctl
value|noioctl
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BOOT
end_ifndef

begin_decl_stmt
name|int
name|tzstrategy
argument_list|()
decl_stmt|,
name|tzopen
argument_list|()
decl_stmt|,
name|tzclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tzioctl
value|noioctl
end_define

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
init|=
block|{
block|{
literal|"rz"
block|,
name|rzstrategy
block|,
name|rzopen
block|,
name|rzclose
block|,
name|rzioctl
block|}
block|,
comment|/*0*/
ifndef|#
directive|ifndef
name|BOOT
block|{
literal|"tz"
block|,
name|tzstrategy
block|,
name|tzopen
block|,
name|tzclose
block|,
name|tzioctl
block|}
block|,
comment|/*1*/
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndevs
init|=
operator|(
sizeof|sizeof
argument_list|(
name|devsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|devsw
index|[
literal|0
index|]
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

end_unit

