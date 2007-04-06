begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
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
comment|/*  * University Copyright- Copyright (c) 1982, 1986, 1988  * The Regents of the University of California  * All Rights Reserved  *  * University Acknowledgment- Portions of this document are derived from  * software developed by the University of California, Berkeley, and its  * contributors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_BYTEORDER_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_BYTEORDER_H_
end_define

begin_comment
comment|/*  * Macros to reverse byte order  */
end_comment

begin_define
define|#
directive|define
name|BSWAP_8
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|BSWAP_16
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_8(x)<< 8) | BSWAP_8((x)>> 8))
end_define

begin_define
define|#
directive|define
name|BSWAP_32
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_16(x)<< 16) | BSWAP_16((x)>> 16))
end_define

begin_define
define|#
directive|define
name|BSWAP_64
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_32(x)<< 32) | BSWAP_32((x)>> 32))
end_define

begin_define
define|#
directive|define
name|BMASK_8
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|BMASK_16
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|BMASK_32
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|BMASK_64
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/*  * Macros to convert from a specific byte order to/from native byte order  */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LE_64
parameter_list|(
name|x
parameter_list|)
value|BSWAP_64(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LE_64
parameter_list|(
name|x
parameter_list|)
value|BMASK_64(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_BYTEORDER_H_ */
end_comment

end_unit

