begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)cons.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * $Header: cons.h,v 4.4 88/09/09 19:01:28 nhall Exp $  * $Source: /usr/argo/sys/netiso/RCS/cons.h,v $  *  * interface between TP and CONS  */
end_comment

begin_define
define|#
directive|define
name|CONSOPT_X25CRUD
value|0x01
end_define

begin_comment
comment|/* set x.25 call request user data */
end_comment

begin_struct
struct|struct
name|dte_addr
block|{
name|u_char
name|dtea_addr
index|[
literal|7
index|]
decl_stmt|;
name|u_char
name|dtea_niblen
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CONN_OPEN
value|0x33
end_define

begin_define
define|#
directive|define
name|CONN_CONFIRM
value|0x30
end_define

begin_define
define|#
directive|define
name|CONN_REFUSE
value|0x31
end_define

begin_define
define|#
directive|define
name|CONN_CLOSE
value|0x32
end_define

begin_define
define|#
directive|define
name|CONS_IS_DGM
value|0x1
end_define

begin_define
define|#
directive|define
name|CONS_NOT_DGM
value|0x0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PRC_NCMDS
end_ifndef

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRC_NCMDS */
end_comment

begin_define
define|#
directive|define
name|PRC_CONS_SEND_DONE
value|2
end_define

begin_comment
comment|/* something unused in protosw.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

