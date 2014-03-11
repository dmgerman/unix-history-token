begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Baptiste Daroussin<bapt@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PKG_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_PKG_CONFIG_H
end_define

begin_define
define|#
directive|define
name|_LOCALBASE
value|"/usr/local"
end_define

begin_define
define|#
directive|define
name|URL_SCHEME_PREFIX
value|"pkg+"
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PACKAGESITE
init|=
literal|0
block|,
name|ABI
block|,
name|MIRROR_TYPE
block|,
name|ASSUME_ALWAYS_YES
block|,
name|SIGNATURE_TYPE
block|,
name|FINGERPRINTS
block|,
name|REPOS_DIR
block|,
name|CONFIG_SIZE
block|}
name|pkg_config_key
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PKG_CONFIG_STRING
init|=
literal|0
block|,
name|PKG_CONFIG_BOOL
block|,
name|PKG_CONFIG_LIST
block|, }
name|pkg_config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CONFFILE_PKG
init|=
literal|0
block|,
name|CONFFILE_REPO
block|, }
name|pkg_conf_file_t
typedef|;
end_typedef

begin_function_decl
name|int
name|config_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|config_string
parameter_list|(
name|pkg_config_key
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|config_bool
parameter_list|(
name|pkg_config_key
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

