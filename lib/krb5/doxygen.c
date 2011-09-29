begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  *   */
end_comment

begin_comment
comment|/*! \mainpage Heimdal Kerberos 5 library  *  * \section intro Introduction  *  * Heimdal libkrb5 library is a implementation of the Kerberos  * protocol.  *   * Kerberos is a system for authenticating users and services on a  * network.  It is built upon the assumption that the network is  * ``unsafe''.  For example, data sent over the network can be  * eavesdropped and altered, and addresses can also be faked.  * Therefore they cannot be used for authentication purposes.  *  * The project web page:\n  * http://www.h5l.org/  *  */
end_comment

begin_comment
comment|/** @defgroup krb5 Heimdal Kerberos 5 library */
end_comment

begin_comment
comment|/** @defgroup krb5_address Heimdal Kerberos 5 address functions */
end_comment

begin_comment
comment|/** @defgroup krb5_ccache Heimdal Kerberos 5 credential cache functions */
end_comment

begin_comment
comment|/** @defgroup krb5_credential Heimdal Kerberos 5 credential handing functions */
end_comment

begin_comment
comment|/** @defgroup krb5_deprecated Heimdal Kerberos 5 deprecated functions */
end_comment

begin_comment
comment|/** @defgroup krb5_digest Heimdal Kerberos 5 digest service */
end_comment

begin_comment
comment|/** @defgroup krb5_error Heimdal Kerberos 5 error reporting functions */
end_comment

begin_comment
comment|/** @defgroup krb5_v4compat Heimdal Kerberos 4 compatiblity functions */
end_comment

begin_comment
comment|/** @defgroup krb5_support Heimdal Kerberos 5 support functions */
end_comment

end_unit

