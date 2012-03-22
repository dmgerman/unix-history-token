begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2004 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"krb5_locl.h"
end_include

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_config_file
init|=
ifdef|#
directive|ifdef
name|__APPLE__
literal|"~/Library/Preferences/com.apple.Kerberos.plist"
name|PATH_SEP
literal|"/Library/Preferences/com.apple.Kerberos.plist"
name|PATH_SEP
literal|"~/Library/Preferences/edu.mit.Kerberos"
name|PATH_SEP
literal|"/Library/Preferences/edu.mit.Kerberos"
name|PATH_SEP
endif|#
directive|endif
comment|/* __APPLE__ */
literal|"~/.krb5/config"
name|PATH_SEP
name|SYSCONFDIR
literal|"/krb5.conf"
ifdef|#
directive|ifdef
name|_WIN32
name|PATH_SEP
literal|"%{COMMON_APPDATA}/Kerberos/krb5.conf"
name|PATH_SEP
literal|"%{WINDOWS}/krb5.ini"
else|#
directive|else
name|PATH_SEP
literal|"/etc/krb5.conf"
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_defkeyname
init|=
name|KEYTAB_DEFAULT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_api
init|=
literal|"API"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_file
init|=
literal|"FILE"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_memory
init|=
literal|"MEMORY"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_kcm
init|=
literal|"KCM"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KRB5_LIB_VARIABLE
specifier|const
name|char
modifier|*
name|krb5_cc_type_scc
init|=
literal|"SCC"
decl_stmt|;
end_decl_stmt

end_unit

