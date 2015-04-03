begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* apps/s_apps.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *  * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from  *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *  * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* conflicts with winsock2 stuff on netware */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_SYS_NETWARE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|OPENSSL_SYS_MSDOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|_kbhit
value|kbhit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OPENSSL_SYS_VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FD_SET
argument_list|)
end_if

begin_comment
comment|/*  * VAX C does not defined fd_set and friends, but it's actually quite simple  */
end_comment

begin_comment
comment|/* These definitions are borrowed from SOCKETSHR.       /Richard Levitte */
end_comment

begin_define
define|#
directive|define
name|MAX_NOFILE
value|32
end_define

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|MAX_NOFILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FD_SETSIZE */
end_comment

begin_comment
comment|/* How many things we'll allow select to use. 0 if unlimited */
end_comment

begin_define
define|#
directive|define
name|MAXSELFD
value|MAX_NOFILE
end_define

begin_typedef
typedef|typedef
name|int
name|fd_mask
typedef|;
end_typedef

begin_comment
comment|/* int here! VMS prototypes int, not long */
end_comment

begin_define
define|#
directive|define
name|NFDBITS
value|(sizeof(fd_mask) * NBBY)
end_define

begin_comment
comment|/* bits per mask (power of 2!) */
end_comment

begin_define
define|#
directive|define
name|NFDSHIFT
value|5
end_define

begin_comment
comment|/* Shift based on above */
end_comment

begin_typedef
typedef|typedef
name|fd_mask
name|fd_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*(p) |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*(p)&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*(p)& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|memset((char *)(p), 0, sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PORT
value|4433
end_define

begin_define
define|#
directive|define
name|PORT_STR
value|"4433"
end_define

begin_define
define|#
directive|define
name|PROTOCOL
value|"tcp"
end_define

begin_function_decl
name|int
name|do_server
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|ret
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|char
modifier|*
name|hostname
parameter_list|,
name|int
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|context
parameter_list|)
parameter_list|,
name|unsigned
name|char
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HEADER_X509_H
end_ifdef

begin_function_decl
name|int
name|MS_CALLBACK
name|verify_callback
parameter_list|(
name|int
name|ok
parameter_list|,
name|X509_STORE_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HEADER_SSL_H
end_ifdef

begin_function_decl
name|int
name|set_cert_stuff
parameter_list|(
name|SSL_CTX
modifier|*
name|ctx
parameter_list|,
name|char
modifier|*
name|cert_file
parameter_list|,
name|char
modifier|*
name|key_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_cert_key_stuff
parameter_list|(
name|SSL_CTX
modifier|*
name|ctx
parameter_list|,
name|X509
modifier|*
name|cert
parameter_list|,
name|EVP_PKEY
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|init_client
parameter_list|(
name|int
modifier|*
name|sock
parameter_list|,
name|char
modifier|*
name|server
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|should_retry
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extract_port
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|short
modifier|*
name|port_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extract_host_port
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|host_ptr
parameter_list|,
name|unsigned
name|char
modifier|*
name|ip
parameter_list|,
name|short
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|MS_CALLBACK
name|bio_dump_callback
parameter_list|(
name|BIO
modifier|*
name|bio
parameter_list|,
name|int
name|cmd
parameter_list|,
specifier|const
name|char
modifier|*
name|argp
parameter_list|,
name|int
name|argi
parameter_list|,
name|long
name|argl
parameter_list|,
name|long
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HEADER_SSL_H
end_ifdef

begin_function_decl
name|void
name|MS_CALLBACK
name|apps_ssl_info_callback
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|where
parameter_list|,
name|int
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MS_CALLBACK
name|msg_cb
parameter_list|(
name|int
name|write_p
parameter_list|,
name|int
name|version
parameter_list|,
name|int
name|content_type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|SSL
modifier|*
name|ssl
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MS_CALLBACK
name|tlsext_cb
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|client_server
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|MS_CALLBACK
name|generate_cookie_callback
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|unsigned
name|char
modifier|*
name|cookie
parameter_list|,
name|unsigned
name|int
modifier|*
name|cookie_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|MS_CALLBACK
name|verify_cookie_callback
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|unsigned
name|char
modifier|*
name|cookie
parameter_list|,
name|unsigned
name|int
name|cookie_len
parameter_list|)
function_decl|;
end_function_decl

end_unit

