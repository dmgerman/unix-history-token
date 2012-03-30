begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_asn1.h>
end_include

begin_include
include|#
directive|include
file|<der.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_krb5.h>
end_include

begin_include
include|#
directive|include
file|"mechqueue.h"
end_include

begin_include
include|#
directive|include
file|"context.h"
end_include

begin_include
include|#
directive|include
file|"cred.h"
end_include

begin_include
include|#
directive|include
file|"mech_switch.h"
end_include

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_include
include|#
directive|include
file|"utils.h"
end_include

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_define
define|#
directive|define
name|_mg_buffer_zero
parameter_list|(
name|buffer
parameter_list|)
define|\
value|do {					\ 		if (buffer) {			\ 			(buffer)->value = NULL;	\ 			(buffer)->length = 0;	\ 		 }				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|_mg_oid_set_zero
parameter_list|(
name|oid_set
parameter_list|)
define|\
value|do {						\ 		if (oid_set) {				\ 			(oid_set)->elements = NULL;	\ 			(oid_set)->count = 0;		\ 		 }					\ 	} while(0)
end_define

end_unit

