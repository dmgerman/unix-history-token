begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETKEY_KEY_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETKEY_KEY_VAR_H_
end_define

begin_comment
comment|/* sysctl */
end_comment

begin_define
define|#
directive|define
name|KEYCTL_DEBUG_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|KEYCTL_SPI_TRY
value|2
end_define

begin_define
define|#
directive|define
name|KEYCTL_SPI_MIN_VALUE
value|3
end_define

begin_define
define|#
directive|define
name|KEYCTL_SPI_MAX_VALUE
value|4
end_define

begin_define
define|#
directive|define
name|KEYCTL_RANDOM_INT
value|5
end_define

begin_define
define|#
directive|define
name|KEYCTL_LARVAL_LIFETIME
value|6
end_define

begin_define
define|#
directive|define
name|KEYCTL_BLOCKACQ_COUNT
value|7
end_define

begin_define
define|#
directive|define
name|KEYCTL_BLOCKACQ_LIFETIME
value|8
end_define

begin_define
define|#
directive|define
name|KEYCTL_MAXID
value|9
end_define

begin_define
define|#
directive|define
name|KEYCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "debug", CTLTYPE_INT }, \ 	{ "spi_try", CTLTYPE_INT }, \ 	{ "spi_min_value", CTLTYPE_INT }, \ 	{ "spi_max_value", CTLTYPE_INT }, \ 	{ "random_int", CTLTYPE_INT }, \ 	{ "larval_lifetime", CTLTYPE_INT }, \ 	{ "blockacq_count", CTLTYPE_INT }, \ 	{ "blockacq_lifetime", CTLTYPE_INT }, \ }
end_define

begin_define
define|#
directive|define
name|KEYCTL_VARS
value|{ \ 	0, \&key_debug_level, \&key_spi_trycnt, \&key_spi_minval, \&key_spi_maxval, \&key_int_random, \&key_larval_lifetime, \&key_blockacq_count, \&key_blockacq_lifetime, \ }
end_define

begin_define
define|#
directive|define
name|_ARRAYLEN
parameter_list|(
name|p
parameter_list|)
value|(sizeof(p)/sizeof(p[0]))
end_define

begin_define
define|#
directive|define
name|_KEYLEN
parameter_list|(
name|key
parameter_list|)
value|((u_int)((key)->sadb_key_bits>> 3))
end_define

begin_define
define|#
directive|define
name|_KEYBITS
parameter_list|(
name|key
parameter_list|)
value|((u_int)((key)->sadb_key_bits))
end_define

begin_define
define|#
directive|define
name|_KEYBUF
parameter_list|(
name|key
parameter_list|)
value|((caddr_t)((caddr_t)(key) + sizeof(struct sadb_key)))
end_define

begin_define
define|#
directive|define
name|_INADDR
parameter_list|(
name|in
parameter_list|)
value|((struct sockaddr_in *)(in))
end_define

begin_comment
comment|/* should not ifdef kernel opt in kernel header file */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INET6
argument_list|)
end_if

begin_define
define|#
directive|define
name|_IN6ADDR
parameter_list|(
name|in6
parameter_list|)
value|((struct sockaddr_in6 *)(in6))
end_define

begin_define
define|#
directive|define
name|_SALENBYAF
parameter_list|(
name|family
parameter_list|)
define|\
value|(((family) == AF_INET) ? \ 		(u_int)sizeof(struct sockaddr_in) : \ 		(u_int)sizeof(struct sockaddr_in6))
end_define

begin_define
define|#
directive|define
name|_INALENBYAF
parameter_list|(
name|family
parameter_list|)
define|\
value|(((family) == AF_INET) ? \ 		(u_int)sizeof(struct in_addr) : \ 		(u_int)sizeof(struct in6_addr))
end_define

begin_define
define|#
directive|define
name|_INADDRBYSA
parameter_list|(
name|saddr
parameter_list|)
define|\
value|((((struct sockaddr *)(saddr))->sa_family == AF_INET) ? \ 		(caddr_t)&((struct sockaddr_in *)(saddr))->sin_addr : \ 		(caddr_t)&((struct sockaddr_in6 *)(saddr))->sin6_addr)
end_define

begin_define
define|#
directive|define
name|_INPORTBYSA
parameter_list|(
name|saddr
parameter_list|)
define|\
value|((((struct sockaddr *)(saddr))->sa_family == AF_INET) ? \ 		((struct sockaddr_in *)(saddr))->sin_port : \ 		((struct sockaddr_in6 *)(saddr))->sin6_port)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_IN6ADDR
parameter_list|(
name|in6
parameter_list|)
value|"#error"
end_define

begin_define
define|#
directive|define
name|_SALENBYAF
parameter_list|(
name|family
parameter_list|)
value|sizeof(struct sockaddr_in)
end_define

begin_define
define|#
directive|define
name|_INALENBYAF
parameter_list|(
name|family
parameter_list|)
value|sizeof(struct in_addr)
end_define

begin_define
define|#
directive|define
name|_INADDRBYSA
parameter_list|(
name|saddr
parameter_list|)
value|((caddr_t)&((struct sockaddr_in *)(saddr))->sin_addr)
end_define

begin_define
define|#
directive|define
name|_INPORTBYSA
parameter_list|(
name|saddr
parameter_list|)
value|(((struct sockaddr_in *)(saddr))->sin_port)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(INET6) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(KERNEL)&& !defined(_KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETKEY_KEY_VAR_H_ */
end_comment

end_unit

