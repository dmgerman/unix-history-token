begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  * From: $NetBSD: bbinfo.h,v 1.3 1997/11/07 16:59:41 drochner Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* data structure shared by bootsector  and installboot  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_struct
struct|struct
name|fraglist
block|{
name|int
name|magic
decl_stmt|;
name|int
name|loadsz
decl_stmt|;
comment|/* blocks loaded by primary boot */
name|int
name|numentries
decl_stmt|,
name|maxentries
decl_stmt|;
struct|struct
block|{
name|int
name|offset
decl_stmt|,
name|num
decl_stmt|;
block|}
name|entries
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FRAGLISTVERSION
value|0
end_define

begin_define
define|#
directive|define
name|FRAGLISTMAGIC
value|(0xb00deda5 + FRAGLISTVERSION)
end_define

begin_comment
comment|/* only used by bootsect code (not by installboot) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXFLENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MAXFLENTRIES
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRIM_LOADSZ
end_ifndef

begin_define
define|#
directive|define
name|PRIM_LOADSZ
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

