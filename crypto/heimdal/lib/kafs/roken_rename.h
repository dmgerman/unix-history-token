begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: roken_rename.h,v 1.5 2001/11/01 22:33:40 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__roken_rename_h__
end_ifndef

begin_define
define|#
directive|define
name|__roken_rename_h__
end_define

begin_comment
comment|/*  * Libroken routines that are added libkafs  */
end_comment

begin_define
define|#
directive|define
name|_resolve_debug
value|_roken_resolve_debug
end_define

begin_define
define|#
directive|define
name|dns_free_data
value|_kafs_dns_free_data
end_define

begin_define
define|#
directive|define
name|dns_lookup
value|_kafs_dns_lookup
end_define

begin_define
define|#
directive|define
name|dns_string_to_type
value|_kafs_dns_string_to_type
end_define

begin_define
define|#
directive|define
name|dns_type_to_string
value|_kafs_dns_type_to_string
end_define

begin_define
define|#
directive|define
name|dns_srv_order
value|_kafs_dns_srv_order
end_define

begin_define
define|#
directive|define
name|strtok_r
value|_kafs_strtok_r
end_define

begin_define
define|#
directive|define
name|strlcpy
value|_kafs_strlcpy
end_define

begin_define
define|#
directive|define
name|strsep
value|_kafs_strsep
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __roken_rename_h__ */
end_comment

end_unit

