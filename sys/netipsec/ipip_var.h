begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: ip_ipip.h,v 1.5 2002/06/09 16:26:10 itojun Exp $ */
end_comment

begin_comment
comment|/*-  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr) and  * Niels Provos (provos@physnet.uni-hamburg.de).  *  * The original version of this code was written by John Ioannidis  * for BSD/OS in Athens, Greece, in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Additional features in 1999 by Angelos D. Keromytis.  *  * Copyright (C) 1995, 1996, 1997, 1998, 1999 by John Ioannidis,  * Angelos D. Keromytis and Niels Provos.  * Copyright (c) 2001, Angelos D. Keromytis.  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.  * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IPIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IPIP_H_
end_define

begin_comment
comment|/*  * IP-inside-IP processing.  * Not quite all the functionality of RFC-1853, but the main idea is there.  */
end_comment

begin_struct
struct|struct
name|ipipstat
block|{
name|u_int32_t
name|ipips_ipackets
decl_stmt|;
comment|/* total input packets */
name|u_int32_t
name|ipips_opackets
decl_stmt|;
comment|/* total output packets */
name|u_int32_t
name|ipips_hdrops
decl_stmt|;
comment|/* packet shorter than header shows */
name|u_int32_t
name|ipips_qfull
decl_stmt|;
name|u_int64_t
name|ipips_ibytes
decl_stmt|;
name|u_int64_t
name|ipips_obytes
decl_stmt|;
name|u_int32_t
name|ipips_pdrops
decl_stmt|;
comment|/* packet dropped due to policy */
name|u_int32_t
name|ipips_spoof
decl_stmt|;
comment|/* IP spoofing attempts */
name|u_int32_t
name|ipips_family
decl_stmt|;
comment|/* Protocol family mismatch */
name|u_int32_t
name|ipips_unspec
decl_stmt|;
comment|/* Missing tunnel endpoint address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ipip_allow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipipstat
name|ipipstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IPIP_H_ */
end_comment

end_unit

