begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  * Copyright (c) 2010, Secure Endpoints Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * - Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  *  * - Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the  *   distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_KRB5_CCACHE_PLUGIN_H
end_ifndef

begin_define
define|#
directive|define
name|HEIMDAL_KRB5_CCACHE_PLUGIN_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_define
define|#
directive|define
name|KRB5_PLUGIN_CCACHE
value|"ccache_ops"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_KRB5_CCACHE_PLUGIN_H */
end_comment

end_unit

