begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* apps/apps.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
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
file|"e_os.h"
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
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

begin_include
include|#
directive|include
file|<openssl/txt_db.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_OCSP
end_ifndef

begin_include
include|#
directive|include
file|<openssl/ocsp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/ossl_typ.h>
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
name|CONF
modifier|*
name|config
init|=
name|NULL
decl_stmt|;
end_decl_stmt

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
name|CONF
modifier|*
name|config
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
name|CONF
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

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_SYS_NETWARE
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_COMP
end_ifdef

begin_define
define|#
directive|define
name|zlib_cleanup
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|zlib_cleanup
parameter_list|()
value|COMP_zlib_cleanup()
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
define|\
value|do_pipe_sig()
end_define

begin_define
define|#
directive|define
name|apps_shutdown
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_define
define|#
directive|define
name|apps_startup
parameter_list|()
define|\
value|do { do_pipe_sig(); CRYPTO_malloc_init(); \ 			ERR_load_crypto_strings(); OpenSSL_add_all_algorithms(); \ 			ENGINE_load_builtin_engines(); setup_ui_method(); } while(0)
end_define

begin_define
define|#
directive|define
name|apps_shutdown
parameter_list|()
define|\
value|do { CONF_modules_unload(1); destroy_ui_method(); \ 			OBJ_cleanup(); EVP_cleanup(); ENGINE_cleanup(); \ 			CRYPTO_cleanup_all_ex_data(); ERR_remove_thread_state(NULL); \ 			RAND_cleanup(); \ 			ERR_free_strings(); zlib_cleanup();} while(0)
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
value|do { do_pipe_sig(); CRYPTO_malloc_init(); \ 			ERR_load_crypto_strings(); OpenSSL_add_all_algorithms(); \ 			setup_ui_method(); } while(0)
end_define

begin_define
define|#
directive|define
name|apps_shutdown
parameter_list|()
define|\
value|do { CONF_modules_unload(1); destroy_ui_method(); \ 			OBJ_cleanup(); EVP_cleanup(); \ 			CRYPTO_cleanup_all_ex_data(); ERR_remove_thread_state(NULL); \ 			RAND_cleanup(); \ 			ERR_free_strings(); zlib_cleanup(); } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_SYSNAME_WIN32
end_ifdef

begin_define
define|#
directive|define
name|openssl_fdset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|FD_SET((unsigned int)a, b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|openssl_fdset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|FD_SET(a, b)
end_define

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

begin_define
define|#
directive|define
name|PW_MIN_LENGTH
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|pw_cb_data
block|{
specifier|const
name|void
modifier|*
name|password
decl_stmt|;
specifier|const
name|char
modifier|*
name|prompt_info
decl_stmt|;
block|}
name|PW_CB_DATA
typedef|;
end_typedef

begin_function_decl
name|int
name|password_callback
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|bufsiz
parameter_list|,
name|int
name|verify
parameter_list|,
name|PW_CB_DATA
modifier|*
name|cb_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup_ui_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_ui_method
parameter_list|(
name|void
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
specifier|const
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
name|set_cert_ex
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
name|set_ext_copy
parameter_list|(
name|int
modifier|*
name|copy_type
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
name|copy_extensions
parameter_list|(
name|X509
modifier|*
name|x
parameter_list|,
name|X509_REQ
modifier|*
name|req
parameter_list|,
name|int
name|copy_type
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
name|CONF
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
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|,
specifier|const
name|char
modifier|*
name|pass
parameter_list|,
name|ENGINE
modifier|*
name|e
parameter_list|,
specifier|const
name|char
modifier|*
name|cert_descrip
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
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|,
name|int
name|maybe_stdin
parameter_list|,
specifier|const
name|char
modifier|*
name|pass
parameter_list|,
name|ENGINE
modifier|*
name|e
parameter_list|,
specifier|const
name|char
modifier|*
name|key_descrip
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
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|format
parameter_list|,
name|int
name|maybe_stdin
parameter_list|,
specifier|const
name|char
modifier|*
name|pass
parameter_list|,
name|ENGINE
modifier|*
name|e
parameter_list|,
specifier|const
name|char
modifier|*
name|key_descrip
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
argument|const char *file
argument_list|,
argument|int format
argument_list|,
argument|const char *pass
argument_list|,
argument|ENGINE *e
argument_list|,
argument|const char *cert_descrip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STACK_OF
argument_list|(
name|X509_CRL
argument_list|)
operator|*
name|load_crls
argument_list|(
argument|BIO *err
argument_list|,
argument|const char *file
argument_list|,
argument|int format
argument_list|,
argument|const char *pass
argument_list|,
argument|ENGINE *e
argument_list|,
argument|const char *cert_descrip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|X509_STORE
modifier|*
name|setup_verify
parameter_list|(
name|BIO
modifier|*
name|bp
parameter_list|,
name|char
modifier|*
name|CAfile
parameter_list|,
name|char
modifier|*
name|CApath
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_function_decl
name|ENGINE
modifier|*
name|setup_engine
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|engine
parameter_list|,
name|int
name|debug
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
name|OPENSSL_NO_OCSP
end_ifndef

begin_decl_stmt
name|OCSP_RESPONSE
modifier|*
name|process_responder
argument_list|(
name|BIO
operator|*
name|err
argument_list|,
name|OCSP_REQUEST
operator|*
name|req
argument_list|,
name|char
operator|*
name|host
argument_list|,
name|char
operator|*
name|path
argument_list|,
name|char
operator|*
name|port
argument_list|,
name|int
name|use_ssl
argument_list|,
name|STACK_OF
argument_list|(
name|CONF_VALUE
argument_list|)
operator|*
name|headers
argument_list|,
name|int
name|req_timeout
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|load_config
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|CONF
modifier|*
name|cnf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|make_config_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions defined in ca.c and also used in ocsp.c */
end_comment

begin_function_decl
name|int
name|unpack_revinfo
parameter_list|(
name|ASN1_TIME
modifier|*
modifier|*
name|prevtm
parameter_list|,
name|int
modifier|*
name|preason
parameter_list|,
name|ASN1_OBJECT
modifier|*
modifier|*
name|phold
parameter_list|,
name|ASN1_GENERALIZEDTIME
modifier|*
modifier|*
name|pinvtm
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DB_type
value|0
end_define

begin_define
define|#
directive|define
name|DB_exp_date
value|1
end_define

begin_define
define|#
directive|define
name|DB_rev_date
value|2
end_define

begin_define
define|#
directive|define
name|DB_serial
value|3
end_define

begin_comment
comment|/* index - unique */
end_comment

begin_define
define|#
directive|define
name|DB_file
value|4
end_define

begin_define
define|#
directive|define
name|DB_name
value|5
end_define

begin_comment
comment|/* index - unique when active and not disabled */
end_comment

begin_define
define|#
directive|define
name|DB_NUMBER
value|6
end_define

begin_define
define|#
directive|define
name|DB_TYPE_REV
value|'R'
end_define

begin_define
define|#
directive|define
name|DB_TYPE_EXP
value|'E'
end_define

begin_define
define|#
directive|define
name|DB_TYPE_VAL
value|'V'
end_define

begin_typedef
typedef|typedef
struct|struct
name|db_attr_st
block|{
name|int
name|unique_subject
decl_stmt|;
block|}
name|DB_ATTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ca_db_st
block|{
name|DB_ATTR
name|attributes
decl_stmt|;
name|TXT_DB
modifier|*
name|db
decl_stmt|;
block|}
name|CA_DB
typedef|;
end_typedef

begin_function_decl
name|BIGNUM
modifier|*
name|load_serial
parameter_list|(
name|char
modifier|*
name|serialfile
parameter_list|,
name|int
name|create
parameter_list|,
name|ASN1_INTEGER
modifier|*
modifier|*
name|retai
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save_serial
parameter_list|(
name|char
modifier|*
name|serialfile
parameter_list|,
name|char
modifier|*
name|suffix
parameter_list|,
name|BIGNUM
modifier|*
name|serial
parameter_list|,
name|ASN1_INTEGER
modifier|*
modifier|*
name|retai
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rotate_serial
parameter_list|(
name|char
modifier|*
name|serialfile
parameter_list|,
name|char
modifier|*
name|new_suffix
parameter_list|,
name|char
modifier|*
name|old_suffix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rand_serial
parameter_list|(
name|BIGNUM
modifier|*
name|b
parameter_list|,
name|ASN1_INTEGER
modifier|*
name|ai
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CA_DB
modifier|*
name|load_index
parameter_list|(
name|char
modifier|*
name|dbfile
parameter_list|,
name|DB_ATTR
modifier|*
name|dbattr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_index
parameter_list|(
name|CA_DB
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|save_index
parameter_list|(
specifier|const
name|char
modifier|*
name|dbfile
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
parameter_list|,
name|CA_DB
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rotate_index
parameter_list|(
specifier|const
name|char
modifier|*
name|dbfile
parameter_list|,
specifier|const
name|char
modifier|*
name|new_suffix
parameter_list|,
specifier|const
name|char
modifier|*
name|old_suffix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_index
parameter_list|(
name|CA_DB
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|index_name_cmp_noconst
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|index_name_cmp((const OPENSSL_CSTRING *)CHECKED_PTR_OF(OPENSSL_STRING, a), \ 	(const OPENSSL_CSTRING *)CHECKED_PTR_OF(OPENSSL_STRING, b))
end_define

begin_function_decl
name|int
name|index_name_cmp
parameter_list|(
specifier|const
name|OPENSSL_CSTRING
modifier|*
name|a
parameter_list|,
specifier|const
name|OPENSSL_CSTRING
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_yesno
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|def
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509_NAME
modifier|*
name|parse_name
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|long
name|chtype
parameter_list|,
name|int
name|multirdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|args_verify
parameter_list|(
name|char
modifier|*
modifier|*
modifier|*
name|pargs
parameter_list|,
name|int
modifier|*
name|pargc
parameter_list|,
name|int
modifier|*
name|badarg
parameter_list|,
name|BIO
modifier|*
name|err
parameter_list|,
name|X509_VERIFY_PARAM
modifier|*
modifier|*
name|pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|policies_print
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|X509_STORE_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bio_to_mem
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|out
parameter_list|,
name|int
name|maxlen
parameter_list|,
name|BIO
modifier|*
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkey_ctrl_string
parameter_list|(
name|EVP_PKEY_CTX
modifier|*
name|ctx
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_gen_str
parameter_list|(
name|BIO
modifier|*
name|err
parameter_list|,
name|EVP_PKEY_CTX
modifier|*
modifier|*
name|pctx
parameter_list|,
specifier|const
name|char
modifier|*
name|algname
parameter_list|,
name|ENGINE
modifier|*
name|e
parameter_list|,
name|int
name|do_param
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|do_X509_sign
argument_list|(
name|BIO
operator|*
name|err
argument_list|,
name|X509
operator|*
name|x
argument_list|,
name|EVP_PKEY
operator|*
name|pkey
argument_list|,
specifier|const
name|EVP_MD
operator|*
name|md
argument_list|,
name|STACK_OF
argument_list|(
name|OPENSSL_STRING
argument_list|)
operator|*
name|sigopts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_X509_REQ_sign
argument_list|(
name|BIO
operator|*
name|err
argument_list|,
name|X509_REQ
operator|*
name|x
argument_list|,
name|EVP_PKEY
operator|*
name|pkey
argument_list|,
specifier|const
name|EVP_MD
operator|*
name|md
argument_list|,
name|STACK_OF
argument_list|(
name|OPENSSL_STRING
argument_list|)
operator|*
name|sigopts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_X509_CRL_sign
argument_list|(
name|BIO
operator|*
name|err
argument_list|,
name|X509_CRL
operator|*
name|x
argument_list|,
name|EVP_PKEY
operator|*
name|pkey
argument_list|,
specifier|const
name|EVP_MD
operator|*
name|md
argument_list|,
name|STACK_OF
argument_list|(
name|OPENSSL_STRING
argument_list|)
operator|*
name|sigopts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_PSK
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|psk_key
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_JPAKE
end_ifndef

begin_function_decl
name|void
name|jpake_client_auth
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|BIO
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_server_auth
parameter_list|(
name|BIO
modifier|*
name|out
parameter_list|,
name|BIO
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|secret
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_TLSEXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_NEXTPROTONEG
argument_list|)
end_if

begin_function_decl
name|unsigned
name|char
modifier|*
name|next_protos_parse
parameter_list|(
name|unsigned
name|short
modifier|*
name|outlen
parameter_list|,
specifier|const
name|char
modifier|*
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !OPENSSL_NO_TLSEXT&& !OPENSSL_NO_NEXTPROTONEG */
end_comment

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
name|FORMAT_ENGINE
value|7
end_define

begin_define
define|#
directive|define
name|FORMAT_IISSGC
value|8
end_define

begin_comment
comment|/* XXX this stupid macro helps us to avoid 				 * adding yet another param to load_*key() */
end_comment

begin_define
define|#
directive|define
name|FORMAT_PEMRSA
value|9
end_define

begin_comment
comment|/* PEM RSAPubicKey format */
end_comment

begin_define
define|#
directive|define
name|FORMAT_ASN1RSA
value|10
end_define

begin_comment
comment|/* DER RSAPubicKey format */
end_comment

begin_define
define|#
directive|define
name|FORMAT_MSBLOB
value|11
end_define

begin_comment
comment|/* MS Key blob format */
end_comment

begin_define
define|#
directive|define
name|FORMAT_PVK
value|12
end_define

begin_comment
comment|/* MS PVK file format */
end_comment

begin_define
define|#
directive|define
name|EXT_COPY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EXT_COPY_ADD
value|1
end_define

begin_define
define|#
directive|define
name|EXT_COPY_ALL
value|2
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

begin_define
define|#
directive|define
name|SERIAL_RAND_BITS
value|64
end_define

begin_function_decl
name|int
name|app_isdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raw_read_stdin
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|raw_write_stdout
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TM_START
value|0
end_define

begin_define
define|#
directive|define
name|TM_STOP
value|1
end_define

begin_function_decl
name|double
name|app_tminterval
parameter_list|(
name|int
name|stop
parameter_list|,
name|int
name|usertime
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OPENSSL_NO_SSL_INTERN
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

