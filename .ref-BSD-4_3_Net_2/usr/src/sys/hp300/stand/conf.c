begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.c	7.3 (Berkeley) 5/5/91  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"saio.h"
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|BOOT
end_ifndef

begin_decl_stmt
name|int
name|ctstrategy
argument_list|()
decl_stmt|,
name|ctopen
argument_list|()
decl_stmt|,
name|ctclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ctioctl
value|noioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|rdstrategy
argument_list|()
decl_stmt|,
name|rdopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rdioctl
value|noioctl
end_define

begin_decl_stmt
name|int
name|sdstrategy
argument_list|()
decl_stmt|,
name|sdopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sdioctl
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
literal|"rd"
block|,
name|rdstrategy
block|,
name|rdopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 0 = rd */
block|{
literal|"sd"
block|,
name|sdstrategy
block|,
name|sdopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|,
comment|/* 1 = sd */
ifndef|#
directive|ifndef
name|BOOT
block|{
literal|"ct"
block|,
name|ctstrategy
block|,
name|ctopen
block|,
name|ctclose
block|,
name|noioctl
block|}
block|,
comment|/* 2 = ct */
endif|#
directive|endif
block|{
name|NULL
block|}
block|, }
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

