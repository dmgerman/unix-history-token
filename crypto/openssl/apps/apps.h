begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* apps/apps.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_APPS_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_APPS_H
end_define

begin_include
include|#
directive|include
file|"openssl/e_os.h"
end_include

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/lhash.h>
end_include

begin_include
include|#
directive|include
file|<openssl/conf.h>
end_include

begin_function_decl
name|int
name|app_RAND_load_file
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|BIO
modifier|*
name|bio_e
parameter_list|,
name|int
name|dont_warn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|app_RAND_write_file
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|BIO
modifier|*
name|bio_e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When `file' is NULL, use defaults.  * `bio_e' is for error messages. */
end_comment

begin_function_decl
name|void
name|app_RAND_allow_write_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|app_RAND_load_files
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* `file' is a list of files to read,                                        * separated by LIST_SEPARATOR_CHAR                                        * (see e_os.h).  The string is                                        * destroyed! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_STDIO
end_ifdef

begin_function_decl
name|BIO_METHOD
modifier|*
name|BIO_s_file
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|rename
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|WIN32_rename((from),(to))
end_define

begin_function_decl
name|int
name|WIN32_rename
parameter_list|(
name|char
modifier|*
name|oldname
parameter_list|,
name|char
modifier|*
name|newname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MONOLITH
end_ifndef

begin_define
define|#
directive|define
name|MAIN
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|main(a,v)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NON_MAIN
end_ifndef

begin_decl_stmt
name|BIO
modifier|*
name|bio_err
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|BIO
modifier|*
name|bio_err
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAIN
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|PROG(a,v)
end_define

begin_decl_stmt
specifier|extern
name|LHASH
modifier|*
name|config
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_config_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BIO
modifier|*
name|bio_err
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIGPIPE
end_ifdef

begin_define
define|#
directive|define
name|do_pipe_sig
parameter_list|()
value|signal(SIGPIPE,SIG_IGN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_pipe_sig
parameter_list|()
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
name|MONOLITH
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_C
argument_list|)
end_if

begin_define
define|#
directive|define
name|apps_startup
parameter_list|()
value|do_pipe_sig()
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN16
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_O_BINARY
end_ifdef

begin_define
define|#
directive|define
name|apps_startup
parameter_list|()
define|\
value|_fmode=_O_BINARY; do_pipe_sig(); CRYPTO_malloc_init(); \ 		SSLeay_add_all_algorithms()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|apps_startup
parameter_list|()
define|\
value|_fmode=O_BINARY; do_pipe_sig(); CRYPTO_malloc_init(); \ 		SSLeay_add_all_algorithms()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|apps_startup
parameter_list|()
value|do_pipe_sig(); SSLeay_add_all_algorithms();
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|args_st
block|{
name|char
modifier|*
modifier|*
name|data
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|ARGS
typedef|;
end_typedef

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
name|args_from_file
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str2fmt
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|program_name
parameter_list|(
name|char
modifier|*
name|in
parameter_list|,
name|char
modifier|*
name|out
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chopup_args
parameter_list|(
name|ARGS
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
index|[]
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
name|dump_cert_text
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_name
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|X509_NAME
modifier|*
name|nm
parameter_list|,
name|unsigned
name|long
name|lflags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|set_name_ex
parameter_list|(
name|unsigned
name|long
modifier|*
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|app_passwd
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|char
modifier|*
name|arg1
parameter_list|,
name|char
modifier|*
name|arg2
parameter_list|,
name|char
modifier|*
modifier|*
name|pass1
parameter_list|,
name|char
modifier|*
modifier|*
name|pass2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_oid_section
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|LHASH
modifier|*
name|conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509
modifier|*
name|load_cert
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVP_PKEY
modifier|*
name|load_key
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|,
name|char
modifier|*
name|pass
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVP_PKEY
modifier|*
name|load_pubkey
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|load_certs
argument_list|(
argument|BIO *err
argument_list|,
argument|char *file
argument_list|,
argument|int format
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|FORMAT_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|FORMAT_ASN1
value|1
end_define

begin_define
define|#
directive|define
name|FORMAT_TEXT
value|2
end_define

begin_define
define|#
directive|define
name|FORMAT_PEM
value|3
end_define

begin_define
define|#
directive|define
name|FORMAT_NETSCAPE
value|4
end_define

begin_define
define|#
directive|define
name|FORMAT_PKCS12
value|5
end_define

begin_define
define|#
directive|define
name|FORMAT_SMIME
value|6
end_define

begin_define
define|#
directive|define
name|NETSCAPE_CERT_HDR
value|"certificate"
end_define

begin_define
define|#
directive|define
name|APP_PASS_LEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

