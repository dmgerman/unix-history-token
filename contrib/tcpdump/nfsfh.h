begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/nfsfh.h,v 1.13 2002/04/24 06:27:05 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993, 1994 Jeffrey C. Mogul, Digital Equipment Corporation,  * Western Research Laboratory. All rights reserved.  * Copyright (c) 2001 Compaq Computer Corporation. All rights reserved.  *  *  Permission to use, copy, and modify this software and its  *  documentation is hereby granted only under the following terms and  *  conditions.  Both the above copyright notice and this permission  *  notice must appear in all copies of the software, derivative works  *  or modified versions, and any portions thereof, and both notices  *  must appear in supporting documentation.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *    1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *    2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  *  THE SOFTWARE IS PROVIDED "AS IS" AND COMPAQ COMPUTER CORPORATION  *  DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING  *  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.   IN NO  *  EVENT SHALL COMPAQ COMPUTER CORPORATION BE LIABLE FOR ANY  *  SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN  *  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  *  OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  *  SOFTWARE.  */
end_comment

begin_comment
comment|/*  * nfsfh.h - NFS file handle definitions (for portable use)  *  * Jeffrey C. Mogul  * Digital Equipment Corporation  * Western Research Laboratory  *	$FreeBSD$  *	$NetBSD: nfsfh.h,v 1.1.1.2 1997/10/03 17:25:13 christos Exp $  */
end_comment

begin_comment
comment|/*  * Internal representation of dev_t, because different NFS servers  * that we might be spying upon use different external representations.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|Minor
decl_stmt|;
comment|/* upper case to avoid clashing with macro names */
name|u_int32_t
name|Major
decl_stmt|;
block|}
name|my_devt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dev_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a.Minor == b.Minor)&& (a.Major == b.Major))
end_define

begin_comment
comment|/*  * Many file servers now use a large file system ID.  This is  * our internal representation of that.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|my_devt
name|Fsid_dev
decl_stmt|;
comment|/* XXX avoid name conflict with AIX */
name|char
name|Opaque_Handle
index|[
literal|2
operator|*
literal|32
operator|+
literal|1
index|]
decl_stmt|;
name|u_int32_t
name|fsid_code
decl_stmt|;
block|}
name|my_fsid
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fsid_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a.fsid_code == b.fsid_code)&&\ 			 dev_eq(a.Fsid_dev, b.Fsid_dev))
end_define

begin_function_decl
specifier|extern
name|void
name|Parse_fh
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|my_fsid
modifier|*
parameter_list|,
name|ino_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

