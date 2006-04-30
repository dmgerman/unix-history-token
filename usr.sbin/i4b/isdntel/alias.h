begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	isdn4bsd common alias file handling header  *      ==========================================  *  *      $Id: alias.h,v 1.5 1999/12/13 21:25:26 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:53:44 1999]  *  *----------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_H_
end_define

begin_define
define|#
directive|define
name|ALIASFILE
value|"/etc/isdn/isdntel.alias"
end_define

begin_struct
struct|struct
name|alias
block|{
name|char
modifier|*
name|number
decl_stmt|;
comment|/* telephone number string	*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name string			*/
name|struct
name|alias
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next alias		*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALIAS_H_ */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

