begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)openpromio.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: openpromio.h,v 1.2 93/04/20 11:14:46 torek Exp $  */
end_comment

begin_struct
struct|struct
name|opiocdesc
block|{
name|int
name|op_nodeid
decl_stmt|;
comment|/* passed or returned node id */
name|int
name|op_namelen
decl_stmt|;
comment|/* length of op_name */
name|char
modifier|*
name|op_name
decl_stmt|;
comment|/* pointer to field name */
name|int
name|op_buflen
decl_stmt|;
comment|/* length of op_buf (value-result) */
name|char
modifier|*
name|op_buf
decl_stmt|;
comment|/* pointer to field value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OPIOCGET
value|_IOWR('O', 1, struct opiocdesc)
end_define

begin_comment
comment|/* get openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCSET
value|_IOW('O', 2, struct opiocdesc)
end_define

begin_comment
comment|/* set openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCNEXTPROP
value|_IOWR('O', 3, struct opiocdesc)
end_define

begin_comment
comment|/* get next property */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETOPTNODE
value|_IOR('O', 4, int)
end_define

begin_comment
comment|/* get openprom field */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETNEXT
value|_IOWR('O', 5, int)
end_define

begin_comment
comment|/* get next node of node */
end_comment

begin_define
define|#
directive|define
name|OPIOCGETCHILD
value|_IOWR('O', 6, int)
end_define

begin_comment
comment|/* get first child of node */
end_comment

end_unit

