begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: ip_ah.h,v 1.29 2002/06/09 16:26:10 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr) and  * Niels Provos (provos@physnet.uni-hamburg.de).  *  * The original version of this code was written by John Ioannidis  * for BSD/OS in Athens, Greece, in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Additional features in 1999 by Angelos D. Keromytis.  *  * Copyright (C) 1995, 1996, 1997, 1998, 1999 John Ioannidis,  * Angelos D. Keromytis and Niels Provos.  * Copyright (c) 2001 Angelos D. Keromytis.  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.  * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_AH_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_AH_VAR_H_
end_define

begin_comment
comment|/*  * These define the algorithm indices into the histogram.  They're  * presently based on the PF_KEY v2 protocol values which is bogus;  * they should be decoupled from the protocol at which time we can  * pack them and reduce the size of the array to a minimum.  */
end_comment

begin_define
define|#
directive|define
name|AH_ALG_MAX
value|16
end_define

begin_struct
struct|struct
name|ahstat
block|{
name|u_int32_t
name|ahs_hdrops
decl_stmt|;
comment|/* Packet shorter than header shows */
name|u_int32_t
name|ahs_nopf
decl_stmt|;
comment|/* Protocol family not supported */
name|u_int32_t
name|ahs_notdb
decl_stmt|;
name|u_int32_t
name|ahs_badkcr
decl_stmt|;
name|u_int32_t
name|ahs_badauth
decl_stmt|;
name|u_int32_t
name|ahs_noxform
decl_stmt|;
name|u_int32_t
name|ahs_qfull
decl_stmt|;
name|u_int32_t
name|ahs_wrap
decl_stmt|;
name|u_int32_t
name|ahs_replay
decl_stmt|;
name|u_int32_t
name|ahs_badauthl
decl_stmt|;
comment|/* Bad authenticator length */
name|u_int32_t
name|ahs_input
decl_stmt|;
comment|/* Input AH packets */
name|u_int32_t
name|ahs_output
decl_stmt|;
comment|/* Output AH packets */
name|u_int32_t
name|ahs_invalid
decl_stmt|;
comment|/* Trying to use an invalid TDB */
name|u_int64_t
name|ahs_ibytes
decl_stmt|;
comment|/* Input bytes */
name|u_int64_t
name|ahs_obytes
decl_stmt|;
comment|/* Output bytes */
name|u_int32_t
name|ahs_toobig
decl_stmt|;
comment|/* Packet got larger than IP_MAXPACKET */
name|u_int32_t
name|ahs_pdrops
decl_stmt|;
comment|/* Packet blocked due to policy */
name|u_int32_t
name|ahs_crypto
decl_stmt|;
comment|/* Crypto processing failure */
name|u_int32_t
name|ahs_tunnel
decl_stmt|;
comment|/* Tunnel sanity check failure */
name|u_int32_t
name|ahs_hist
index|[
name|AH_ALG_MAX
index|]
decl_stmt|;
comment|/* Per-algorithm op count */
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
name|ah_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ah_cleartos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ahstat
name|ahstat
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
comment|/*_NETIPSEC_AH_VAR_H_*/
end_comment

end_unit

