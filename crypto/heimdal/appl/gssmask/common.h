begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of KTH nor the names of its contributors may be  *    used to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY KTH AND ITS CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KTH OR ITS CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * pthread support is disable because the pthread  * test have no "application pthread libflags" variable,  * when this is fixed pthread support can be enabled again.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_PTHREAD_SUPPORT
end_undef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UTSNAME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_include
include|#
directive|include
file|<gssapi/gssapi_krb5.h>
end_include

begin_include
include|#
directive|include
file|<gssapi/gssapi_spnego.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_function_decl
name|krb5_error_code
name|store_string
parameter_list|(
name|krb5_storage
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ret16
parameter_list|(
name|_client
parameter_list|,
name|num
parameter_list|)
define|\
value|do {							\         if (krb5_ret_int16((_client)->sock,&(num)) != 0)	\ 	    errx(1, "krb5_ret_int16 " #num);		\     } while(0)
end_define

begin_define
define|#
directive|define
name|ret32
parameter_list|(
name|_client
parameter_list|,
name|num
parameter_list|)
define|\
value|do {							\         if (krb5_ret_int32((_client)->sock,&(num)) != 0)	\ 	    errx(1, "krb5_ret_int32 " #num);		\     } while(0)
end_define

begin_define
define|#
directive|define
name|retdata
parameter_list|(
name|_client
parameter_list|,
name|data
parameter_list|)
define|\
value|do {							\         if (krb5_ret_data((_client)->sock,&(data)) != 0)	\ 	    errx(1, "krb5_ret_data " #data);		\     } while(0)
end_define

begin_define
define|#
directive|define
name|retstring
parameter_list|(
name|_client
parameter_list|,
name|data
parameter_list|)
define|\
value|do {							\         if (krb5_ret_string((_client)->sock,&(data)) != 0)	\ 	    errx(1, "krb5_ret_data " #data);		\     } while(0)
end_define

begin_define
define|#
directive|define
name|put32
parameter_list|(
name|_client
parameter_list|,
name|num
parameter_list|)
define|\
value|do {							\         if (krb5_store_int32((_client)->sock, num) != 0)	\ 	    errx(1, "krb5_store_int32 " #num);	\     } while(0)
end_define

begin_define
define|#
directive|define
name|putdata
parameter_list|(
name|_client
parameter_list|,
name|data
parameter_list|)
define|\
value|do {							\         if (krb5_store_data((_client)->sock, data) != 0)	\ 	    errx(1, "krb5_store_data " #data);	\     } while(0)
end_define

begin_define
define|#
directive|define
name|putstring
parameter_list|(
name|_client
parameter_list|,
name|str
parameter_list|)
define|\
value|do {							\         if (store_string((_client)->sock, str) != 0)		\ 	    errx(1, "krb5_store_str " #str);			\     } while(0)
end_define

begin_function_decl
name|char
modifier|*
modifier|*
modifier|*
name|permutate_all
parameter_list|(
name|struct
name|getarg_strings
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

