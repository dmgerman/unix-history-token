begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: openfirmio.h,v 1.4 2002/09/06 13:23:19 gehenna Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)openpromio.h	8.1 (Berkeley) 6/11/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_OFW_OPENFIRMIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_OFW_OPENFIRMIO_H_
end_define

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_struct
struct|struct
name|ofiocdesc
block|{
name|phandle_t
name|of_nodeid
decl_stmt|;
comment|/* passed or returned node id */
name|int
name|of_namelen
decl_stmt|;
comment|/* length of op_name */
specifier|const
name|char
modifier|*
name|of_name
decl_stmt|;
comment|/* pointer to field name */
name|int
name|of_buflen
decl_stmt|;
comment|/* length of op_buf (value-result) */
name|char
modifier|*
name|of_buf
decl_stmt|;
comment|/* pointer to field value */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OFIOC_BASE
value|'O'
end_define

begin_comment
comment|/* Get openprom field. */
end_comment

begin_define
define|#
directive|define
name|OFIOCGET
value|_IOWR(OFIOC_BASE, 1, struct ofiocdesc)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Set openprom field. */
end_comment

begin_define
define|#
directive|define
name|OFIOCSET
value|_IOW(OFIOC_BASE, 2, struct ofiocdesc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get next property. */
end_comment

begin_define
define|#
directive|define
name|OFIOCNEXTPROP
value|_IOWR(OFIOC_BASE, 3, struct ofiocdesc)
end_define

begin_comment
comment|/* Get options node. */
end_comment

begin_define
define|#
directive|define
name|OFIOCGETOPTNODE
value|_IOR(OFIOC_BASE, 4, phandle_t)
end_define

begin_comment
comment|/* Get next node of node. */
end_comment

begin_define
define|#
directive|define
name|OFIOCGETNEXT
value|_IOWR(OFIOC_BASE, 5, phandle_t)
end_define

begin_comment
comment|/* Get first child of node. */
end_comment

begin_define
define|#
directive|define
name|OFIOCGETCHILD
value|_IOWR(OFIOC_BASE, 6, phandle_t)
end_define

begin_comment
comment|/* Find a specific device. */
end_comment

begin_define
define|#
directive|define
name|OFIOCFINDDEVICE
value|_IOWR(OFIOC_BASE, 7, struct ofiocdesc)
end_define

begin_comment
comment|/* Retrieve the size of a property. */
end_comment

begin_define
define|#
directive|define
name|OFIOCGETPROPLEN
value|_IOWR(OFIOC_BASE, 8, struct ofiocdesc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_OFW_OPENFIRMIO_H_ */
end_comment

end_unit

