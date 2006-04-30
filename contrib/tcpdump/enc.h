begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/enc.h,v 1.1 2003/03/08 08:55:33 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/* From $OpenBSD: if_enc.h,v 1.8 2001/06/25 05:14:00 angelos Exp $ */
end_comment

begin_comment
comment|/*  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr) and   * Niels Provos (provos@physnet.uni-hamburg.de).  *  * This code was written by John Ioannidis for BSD/OS in Athens, Greece,   * in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Copyright (C) 1995, 1996, 1997, 1998 by John Ioannidis, Angelos D. Keromytis  * and Niels Provos.  * Copyright (c) 2001, Angelos D. Keromytis.  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.   * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|ENC_HDRLEN
value|12
end_define

begin_comment
comment|/* From $OpenBSD: mbuf.h,v 1.56 2002/01/25 15:50:23 art Exp $	*/
end_comment

begin_define
define|#
directive|define
name|M_CONF
value|0x0400
end_define

begin_comment
comment|/* packet was encrypted (ESP-transport) */
end_comment

begin_define
define|#
directive|define
name|M_AUTH
value|0x0800
end_define

begin_comment
comment|/* packet was authenticated (AH) */
end_comment

begin_struct
struct|struct
name|enchdr
block|{
name|u_int32_t
name|af
decl_stmt|;
name|u_int32_t
name|spi
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

end_unit

