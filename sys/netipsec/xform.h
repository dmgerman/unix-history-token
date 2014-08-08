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

begin_comment
comment|/*  * Packet tag assigned on completion of IPsec processing; used  * to speedup processing when/if the packet comes back for more  * processing.  */
end_comment

begin_struct
struct|struct
name|tdb_ident
block|{
name|u_int32_t
name|spi
decl_stmt|;
name|union
name|sockaddr_union
name|dst
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
comment|/* Cache those two for enc(4) in xform_ipip. */
name|u_int8_t
name|alg_auth
decl_stmt|;
name|u_int8_t
name|alg_enc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opaque data structure hung off a crypto operation descriptor.  */
end_comment

begin_struct
struct|struct
name|tdb_crypto
block|{
name|struct
name|ipsecrequest
modifier|*
name|tc_isr
decl_stmt|;
comment|/* ipsec request state */
name|u_int32_t
name|tc_spi
decl_stmt|;
comment|/* associated SPI */
name|union
name|sockaddr_union
name|tc_dst
decl_stmt|;
comment|/* dst addr of packet */
name|u_int8_t
name|tc_proto
decl_stmt|;
comment|/* current protocol, e.g. AH */
name|u_int8_t
name|tc_nxt
decl_stmt|;
comment|/* next protocol, e.g. IPV4 */
name|int
name|tc_protoff
decl_stmt|;
comment|/* current protocol offset */
name|int
name|tc_skip
decl_stmt|;
comment|/* data offset */
name|caddr_t
name|tc_ptr
decl_stmt|;
comment|/* associated crypto data */
name|struct
name|secasvar
modifier|*
name|tc_sav
decl_stmt|;
comment|/* related SA */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|secasvar
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipescrequest
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|xformsw
block|{
name|u_short
name|xf_type
decl_stmt|;
comment|/* xform ID */
define|#
directive|define
name|XF_IP4
value|1
comment|/* IP inside IP */
define|#
directive|define
name|XF_AH
value|2
comment|/* AH */
define|#
directive|define
name|XF_ESP
value|3
comment|/* ESP */
define|#
directive|define
name|XF_TCPSIGNATURE
value|5
comment|/* TCP MD5 Signature option, RFC 2358 */
define|#
directive|define
name|XF_IPCOMP
value|6
comment|/* IPCOMP */
name|u_short
name|xf_flags
decl_stmt|;
define|#
directive|define
name|XFT_AUTH
value|0x0001
define|#
directive|define
name|XFT_CONF
value|0x0100
define|#
directive|define
name|XFT_COMP
value|0x1000
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
name|ipsecrequest
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|struct
name|xformsw
modifier|*
name|xf_next
decl_stmt|;
comment|/* list of registered xforms */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|xform_register
parameter_list|(
name|struct
name|xformsw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xform_init
parameter_list|(
name|struct
name|secasvar
modifier|*
name|sav
parameter_list|,
name|int
name|xftype
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|cryptoini
struct_decl|;
end_struct_decl

begin_comment
comment|/* XF_IP4 */
end_comment

begin_function_decl
specifier|extern
name|int
name|ip4_input6
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|,
name|int
modifier|*
name|offp
parameter_list|,
name|int
name|proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ip4_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ipip_output
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ipsecrequest
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XF_AH */
end_comment

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
name|struct
name|auth_hash
modifier|*
name|ah_algorithm_lookup
parameter_list|(
name|int
name|alg
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
name|struct
name|enc_xform
modifier|*
name|esp_algorithm_lookup
parameter_list|(
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* XF_COMP */
end_comment

begin_function_decl
specifier|extern
name|struct
name|comp_algo
modifier|*
name|ipcomp_algorithm_lookup
parameter_list|(
name|int
name|alg
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

