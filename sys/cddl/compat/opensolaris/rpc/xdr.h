begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1983, 1984, 1985, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * Portions of this source code were derived from Berkeley 4.3 BSD  * under license from the Regents of the University of California.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_RPC_XDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_RPC_XDR_H_
end_define

begin_empty
empty|#include_next<rpc/xdr.h>
end_empty

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_empty
empty|#include_next<rpc/xdr.h>
end_empty

begin_comment
comment|/*  * Strangely, my glibc version (2.3.6) doesn't have xdr_control(), so  * we have to hack it in here (source taken from OpenSolaris).  * By the way, it is assumed the xdrmem implementation is used.  */
end_comment

begin_undef
undef|#
directive|undef
name|xdr_control
end_undef

begin_define
define|#
directive|define
name|xdr_control
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|xdrmem_control(a,b,c)
end_define

begin_comment
comment|/*  * These are XDR control operators  */
end_comment

begin_define
define|#
directive|define
name|XDR_GET_BYTES_AVAIL
value|1
end_define

begin_struct
struct|struct
name|xdr_bytesrec
block|{
name|bool_t
name|xc_is_last_record
decl_stmt|;
name|size_t
name|xc_num_avail
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xdr_bytesrec
name|xdr_bytesrec
typedef|;
end_typedef

begin_comment
comment|/*  * These are the request arguments to XDR_CONTROL.  *  * XDR_PEEK - returns the contents of the next XDR unit on the XDR stream.  * XDR_SKIPBYTES - skips the next N bytes in the XDR stream.  * XDR_RDMAGET - for xdr implementation over RDMA, gets private flags from  *		 the XDR stream being moved over RDMA  * XDR_RDMANOCHUNK - for xdr implementaion over RDMA, sets private flags in  *                   the XDR stream moving over RDMA.  */
end_comment

begin_define
define|#
directive|define
name|XDR_PEEK
value|2
end_define

begin_define
define|#
directive|define
name|XDR_SKIPBYTES
value|3
end_define

begin_define
define|#
directive|define
name|XDR_RDMAGET
value|4
end_define

begin_define
define|#
directive|define
name|XDR_RDMASET
value|5
end_define

begin_comment
comment|/* FIXME: probably doesn't work */
end_comment

begin_function
specifier|static
name|__inline
name|bool_t
name|xdrmem_control
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|int
name|request
parameter_list|,
name|void
modifier|*
name|info
parameter_list|)
block|{
name|xdr_bytesrec
modifier|*
name|xptr
decl_stmt|;
name|int32_t
modifier|*
name|int32p
decl_stmt|;
name|int
name|len
decl_stmt|;
switch|switch
condition|(
name|request
condition|)
block|{
case|case
name|XDR_GET_BYTES_AVAIL
case|:
name|xptr
operator|=
operator|(
name|xdr_bytesrec
operator|*
operator|)
name|info
expr_stmt|;
name|xptr
operator|->
name|xc_is_last_record
operator|=
name|TRUE
expr_stmt|;
name|xptr
operator|->
name|xc_num_avail
operator|=
name|xdrs
operator|->
name|x_handy
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
case|case
name|XDR_PEEK
case|:
comment|/* 		 * Return the next 4 byte unit in the XDR stream. 		 */
if|if
condition|(
name|xdrs
operator|->
name|x_handy
operator|<
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
name|int32p
operator|=
operator|(
name|int32_t
operator|*
operator|)
name|info
expr_stmt|;
operator|*
name|int32p
operator|=
operator|(
name|int32_t
operator|)
name|ntohl
argument_list|(
call|(
name|uint32_t
call|)
argument_list|(
operator|*
operator|(
operator|(
name|int32_t
operator|*
operator|)
operator|(
name|xdrs
operator|->
name|x_private
operator|)
operator|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
case|case
name|XDR_SKIPBYTES
case|:
comment|/* 		 * Skip the next N bytes in the XDR stream. 		 */
name|int32p
operator|=
operator|(
name|int32_t
operator|*
operator|)
name|info
expr_stmt|;
name|len
operator|=
name|RNDUP
argument_list|(
call|(
name|int
call|)
argument_list|(
operator|*
name|int32p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|xdrs
operator|->
name|x_handy
operator|-=
name|len
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
name|xdrs
operator|->
name|x_private
operator|+=
name|len
expr_stmt|;
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_RPC_XDR_H_ */
end_comment

end_unit

