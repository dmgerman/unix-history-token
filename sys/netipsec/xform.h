begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: ip_ipsp.h,v 1.119 2002/03/14 01:27:11 millert Exp $	*/
end_comment

begin_comment
comment|/*-  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr),  * Niels Provos (provos@physnet.uni-hamburg.de) and  * Niklas Hallqvist (niklas@appli.se).  *  * The original version of this code was written by John Ioannidis  * for BSD/OS in Athens, Greece, in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Additional features in 1999 by Angelos D. Keromytis and Niklas Hallqvist.  *  * Copyright (c) 1995, 1996, 1997, 1998, 1999 by John Ioannidis,  * Angelos D. Keromytis and Niels Provos.  * Copyright (c) 1999 Niklas Hallqvist.  * Copyright (c) 2001, Angelos D. Keromytis.  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.  * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_XFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_XFORM_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform.h>
end_include

begin_define
define|#
directive|define
name|AH_HMAC_HASHLEN
value|12
end_define

begin_comment
comment|/* 96 bits of authenticator */
end_comment

begin_define
define|#
directive|define
name|AH_HMAC_MAXHASHLEN
value|(SHA2_512_HASH_LEN/2)
end_define

begin_comment
comment|/* Keep this updated */
end_comment

begin_define
define|#
directive|define
name|AH_HMAC_INITIAL_RPL
value|1
end_define

begin_comment
comment|/* replay counter initial value */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|secpolicy
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secasvar
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Packet tag assigned on completion of IPsec processing; used  * to speedup security policy checking for INBOUND packets.  */
end_comment

begin_struct
struct|struct
name|xform_history
block|{
name|union
name|sockaddr_union
name|dst
decl_stmt|;
comment|/* destination address */
name|uint32_t
name|spi
decl_stmt|;
comment|/* Security Parameters Index */
name|uint8_t
name|proto
decl_stmt|;
comment|/* IPPROTO_ESP or IPPROTO_AH */
name|uint8_t
name|mode
decl_stmt|;
comment|/* transport or tunnel */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opaque data structure hung off a crypto operation descriptor.  */
end_comment

begin_struct
struct|struct
name|xform_data
block|{
name|struct
name|secpolicy
modifier|*
name|sp
decl_stmt|;
comment|/* security policy */
name|struct
name|secasvar
modifier|*
name|sav
decl_stmt|;
comment|/* related SA */
name|uint64_t
name|cryptoid
decl_stmt|;
comment|/* used crypto session id */
name|u_int
name|idx
decl_stmt|;
comment|/* IPsec request index */
name|int
name|protoff
decl_stmt|;
comment|/* current protocol offset */
name|int
name|skip
decl_stmt|;
comment|/* data offset */
name|uint8_t
name|nxt
decl_stmt|;
comment|/* next protocol, e.g. IPV4 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XF_IP4
value|1
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|XF_AH
value|2
end_define

begin_comment
comment|/* AH */
end_comment

begin_define
define|#
directive|define
name|XF_ESP
value|3
end_define

begin_comment
comment|/* ESP */
end_comment

begin_define
define|#
directive|define
name|XF_TCPSIGNATURE
value|5
end_define

begin_comment
comment|/* TCP MD5 Signature option, RFC 2358 */
end_comment

begin_define
define|#
directive|define
name|XF_IPCOMP
value|6
end_define

begin_comment
comment|/* IPCOMP */
end_comment

begin_struct
struct|struct
name|xformsw
block|{
name|u_short
name|xf_type
decl_stmt|;
comment|/* xform ID */
name|char
modifier|*
name|xf_name
decl_stmt|;
comment|/* human-readable name */
name|int
function_decl|(
modifier|*
name|xf_init
function_decl|)
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|,
name|struct
name|xformsw
modifier|*
parameter_list|)
function_decl|;
comment|/* setup */
name|int
function_decl|(
modifier|*
name|xf_zeroize
function_decl|)
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
comment|/* cleanup */
name|int
function_decl|(
modifier|*
name|xf_input
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
comment|/* input */
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|xf_output
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
comment|/* output */
name|struct
name|secpolicy
modifier|*
parameter_list|,
name|struct
name|secasvar
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|LIST_ENTRY
argument_list|(
argument|xformsw
argument_list|)
name|chain
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|enc_xform
modifier|*
name|enc_algorithm_lookup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|auth_hash
modifier|*
name|auth_algorithm_lookup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|comp_algo
modifier|*
name|comp_algorithm_lookup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xform_attach
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xform_detach
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|cryptoini
struct_decl|;
end_struct_decl

begin_comment
comment|/* XF_AH */
end_comment

begin_function_decl
name|int
name|xform_ah_authsize
parameter_list|(
specifier|const
name|struct
name|auth_hash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ah_init0
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|,
name|struct
name|xformsw
modifier|*
parameter_list|,
name|struct
name|cryptoini
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ah_zeroize
parameter_list|(
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ah_hdrsiz
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XF_ESP */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|esp_hdrsiz
parameter_list|(
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _NETIPSEC_XFORM_H_ */
end_comment

end_unit

