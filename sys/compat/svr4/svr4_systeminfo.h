begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SYSTEMINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SYSTEMINFO_H_
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SYSNAME
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_SI_HOSTNAME
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_SI_RELEASE
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_SI_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_SI_MACHINE
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_SI_ARCHITECTURE
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_SI_HW_SERIAL
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_SI_HW_PROVIDER
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SRPC_DOMAIN
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SET_HOSTNAME
value|258
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SET_SRPC_DOMAIN
value|265
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SET_KERB_REALM
value|266
end_define

begin_define
define|#
directive|define
name|SVR4_SI_KERB_REALM
value|267
end_define

begin_define
define|#
directive|define
name|SVR4_SI_PLATFORM
value|513
end_define

begin_define
define|#
directive|define
name|SVR4_SI_ISALIST
value|514
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SYSTEMINFO_H_ */
end_comment

end_unit

