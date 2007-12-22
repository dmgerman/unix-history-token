begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: cryptosoft.h,v 1.10 2002/04/22 23:10:09 deraadt Exp $	*/
end_comment

begin_comment
comment|/*-  * The author of this code is Angelos D. Keromytis (angelos@cis.upenn.edu)  *  * This code was written by Angelos D. Keromytis in Athens, Greece, in  * February 2000. Network Security Technologies Inc. (NSTI) kindly  * supported the development of this code.  *  * Copyright (c) 2000 Angelos D. Keromytis  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all source code copies of any software which is or includes a copy or  * modification of this software.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPTO_CRYPTOSOFT_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRYPTO_CRYPTOSOFT_H_
end_define

begin_comment
comment|/* Software session entry */
end_comment

begin_struct
struct|struct
name|swcr_data
block|{
name|int
name|sw_alg
decl_stmt|;
comment|/* Algorithm */
union|union
block|{
struct|struct
block|{
name|u_int8_t
modifier|*
name|SW_ictx
decl_stmt|;
name|u_int8_t
modifier|*
name|SW_octx
decl_stmt|;
name|u_int16_t
name|SW_klen
decl_stmt|;
name|u_int16_t
name|SW_mlen
decl_stmt|;
name|struct
name|auth_hash
modifier|*
name|SW_axf
decl_stmt|;
block|}
name|SWCR_AUTH
struct|;
struct|struct
block|{
name|u_int8_t
modifier|*
name|SW_kschedule
decl_stmt|;
name|struct
name|enc_xform
modifier|*
name|SW_exf
decl_stmt|;
block|}
name|SWCR_ENC
struct|;
struct|struct
block|{
name|u_int32_t
name|SW_size
decl_stmt|;
name|struct
name|comp_algo
modifier|*
name|SW_cxf
decl_stmt|;
block|}
name|SWCR_COMP
struct|;
block|}
name|SWCR_UN
union|;
define|#
directive|define
name|sw_ictx
value|SWCR_UN.SWCR_AUTH.SW_ictx
define|#
directive|define
name|sw_octx
value|SWCR_UN.SWCR_AUTH.SW_octx
define|#
directive|define
name|sw_klen
value|SWCR_UN.SWCR_AUTH.SW_klen
define|#
directive|define
name|sw_mlen
value|SWCR_UN.SWCR_AUTH.SW_mlen
define|#
directive|define
name|sw_axf
value|SWCR_UN.SWCR_AUTH.SW_axf
define|#
directive|define
name|sw_kschedule
value|SWCR_UN.SWCR_ENC.SW_kschedule
define|#
directive|define
name|sw_exf
value|SWCR_UN.SWCR_ENC.SW_exf
define|#
directive|define
name|sw_size
value|SWCR_UN.SWCR_COMP.SW_size
define|#
directive|define
name|sw_cxf
value|SWCR_UN.SWCR_COMP.SW_cxf
name|struct
name|swcr_data
modifier|*
name|sw_next
decl_stmt|;
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
name|u_int8_t
name|hmac_ipad_buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int8_t
name|hmac_opad_buffer
index|[]
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
comment|/* _CRYPTO_CRYPTO_H_ */
end_comment

end_unit

