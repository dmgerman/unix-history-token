begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Joerg Wunsch  *  * All rights reserved.  *  * This program is free software.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Joerg Wunsch  * 4. The name of the developer may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Header  * The author may be reached unter<joerg_wunsch@uriah.sax.de>  *  * $Log: vgaio.h,v $  * Revision 1.1  1994/03/29  02:47:25  mycroft  * pcvt 3.0, with some performance enhancements by Joerg Wunsch and me.  *  * Revision 1.2  1994/01/08  17:42:58  j  * cleanup  * made multiple commands per line work  * wrote man page  *  *  */
end_comment

begin_comment
comment|/* common structure to hold the definition for a VGA register */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VGAIO_H
end_ifndef

begin_define
define|#
directive|define
name|VGAIO_H
end_define

begin_struct
struct|struct
name|reg
block|{
name|int
name|group
decl_stmt|,
name|num
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VGAIO_H */
end_comment

end_unit

