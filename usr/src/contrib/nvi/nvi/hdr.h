begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hdr.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/*  * The HDR structure is a special structure for heading doubly linked lists.  * It depends on all structures using these lists beginning with the exact  * same four pointer fields.  There are macros below which insert, append  * and delete into doubly linked lists.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_hdr
block|{
name|void
modifier|*
name|next
decl_stmt|;
comment|/* First set of pointers. */
name|void
modifier|*
name|prev
decl_stmt|;
name|void
modifier|*
name|snext
decl_stmt|;
comment|/* Second set of pointers. */
name|void
modifier|*
name|sprev
decl_stmt|;
define|#
directive|define
name|HDR_INUSE
value|0x01
comment|/* Is active flag. */
name|u_char
name|flags
decl_stmt|;
block|}
name|HDR
typedef|;
end_typedef

begin_comment
comment|/* Initialize the doubly linked list header. */
end_comment

begin_define
define|#
directive|define
name|HDR_INIT
parameter_list|(
name|hdr
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
value|{						\ 	(hdr).n = (hdr).p =&(hdr);					\ }
end_define

begin_comment
comment|/* Insert after node in a doubly linked list. */
end_comment

begin_define
define|#
directive|define
name|HDR_APPEND
parameter_list|(
name|ins
parameter_list|,
name|node
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|)
value|{				\         (ins)->n = ((cast *)(node))->n;					\         (ins)->p = (cast *)(node);					\         ((cast *)(node))->n->p = (ins);					\         ((cast *)(node))->n = (ins);					\ }
end_define

begin_comment
comment|/* Insert before node in a doubly linked list. */
end_comment

begin_define
define|#
directive|define
name|HDR_INSERT
parameter_list|(
name|ins
parameter_list|,
name|node
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|)
value|{				\ 	((cast *)(node))->p->n = (ins);					\ 	(ins)->p = ((cast *)(node))->p;					\ 	((cast *)(node))->p = (ins);					\ 	(ins)->n = (cast *)(node);					\ }
end_define

begin_comment
comment|/* Delete node from doubly linked list. */
end_comment

begin_define
define|#
directive|define
name|HDR_DELETE
parameter_list|(
name|node
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|)
value|{					\ 	((cast *)(node))->p->n = ((cast *)node)->n;			\ 	((cast *)(node))->n->p = ((cast *)node)->p;			\ }
end_define

end_unit

