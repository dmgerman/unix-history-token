begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/o_dir.c */
end_comment

begin_comment
comment|/*  * Written by Richard Levitte (richard@levitte.org) for the OpenSSL project  * 2004.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2004 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<e_os.h>
end_include

begin_comment
comment|/*  * The routines really come from the Levitte Programming, so to make life  * simple, let's just use the raw files and hack the symbols to fit our  * namespace.  */
end_comment

begin_define
define|#
directive|define
name|LP_DIR_CTX
value|OPENSSL_DIR_CTX
end_define

begin_define
define|#
directive|define
name|LP_dir_context_st
value|OPENSSL_dir_context_st
end_define

begin_define
define|#
directive|define
name|LP_find_file
value|OPENSSL_DIR_read
end_define

begin_define
define|#
directive|define
name|LP_find_file_end
value|OPENSSL_DIR_end
end_define

begin_include
include|#
directive|include
file|"o_dir.h"
end_include

begin_define
define|#
directive|define
name|LPDIR_H
end_define

begin_if
if|#
directive|if
name|defined
name|OPENSSL_SYS_UNIX
operator|||
name|defined
name|DJGPP
expr|\
operator|||
operator|(
name|defined
name|__VMS_VER
operator|&&
name|__VMS_VER
operator|>=
literal|70000000
operator|)
end_if

begin_include
include|#
directive|include
file|"LPdir_unix.c"
end_include

begin_elif
elif|#
directive|elif
name|defined
name|OPENSSL_SYS_VMS
end_elif

begin_include
include|#
directive|include
file|"LPdir_vms.c"
end_include

begin_elif
elif|#
directive|elif
name|defined
name|OPENSSL_SYS_WIN32
end_elif

begin_include
include|#
directive|include
file|"LPdir_win32.c"
end_include

begin_elif
elif|#
directive|elif
name|defined
name|OPENSSL_SYS_WINCE
end_elif

begin_include
include|#
directive|include
file|"LPdir_wince.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"LPdir_nyi.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

