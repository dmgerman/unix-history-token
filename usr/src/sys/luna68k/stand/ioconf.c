begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ioconf.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/device.h>
end_include

begin_define
define|#
directive|define
name|C
value|(caddr_t)
end_define

begin_define
define|#
directive|define
name|D
value|(struct driver *)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|scdriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|sddriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|driver
name|stdriver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hp_ctlr
name|hp_cinit
index|[]
init|=
block|{
comment|/*	driver,		unit,	alive,	addr,	flags */
block|{
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
name|C
literal|0x0
block|,
literal|0x0
block|}
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hp_device
name|hp_dinit
index|[]
init|=
block|{
comment|/*driver,	cdriver,	unit,	ctlr,	slave,	addr,	dk,	flags*/
block|{
operator|&
name|sddriver
block|,
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
literal|6
block|,
name|C
literal|0x0
block|,
literal|1
block|,
literal|0x0
block|}
block|,
block|{
operator|&
name|sddriver
block|,
operator|&
name|scdriver
block|,
literal|1
block|,
literal|0
block|,
literal|5
block|,
name|C
literal|0x0
block|,
literal|1
block|,
literal|0x0
block|}
block|,
block|{
operator|&
name|stdriver
block|,
operator|&
name|scdriver
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
name|C
literal|0x0
block|,
literal|0
block|,
literal|0x0
block|}
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

