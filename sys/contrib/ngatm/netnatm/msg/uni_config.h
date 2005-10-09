begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/msg/uni_config.h,v 1.3 2003/09/19 11:58:15 hbb Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_uni_uni_config_h_
end_ifndef

begin_define
define|#
directive|define
name|_uni_uni_config_h_
end_define

begin_enum
enum|enum
block|{
comment|/* maximum number of reported error IEs */
name|UNI_MAX_ERRIE
init|=
literal|50
block|,
comment|/* maximum number of Generic Identifier Transport IE's per message */
name|UNI_NUM_IE_GIT
init|=
literal|3
block|,
comment|/* maximum number of BLLI's in SETUP */
name|UNI_NUM_IE_BLLI
init|=
literal|3
block|,
comment|/* maximum number of CALLEDSUB's */
name|UNI_NUM_IE_CALLEDSUB
init|=
literal|2
block|,
comment|/* maximum number of CALLINGSUB's */
name|UNI_NUM_IE_CALLINGSUB
init|=
literal|2
block|,
comment|/* maximum number of TNS's */
name|UNI_NUM_IE_TNS
init|=
literal|4
block|,
comment|/* maximum length of TNS name */
name|UNI_TNS_MAXLEN
init|=
literal|4
block|,
comment|/* maximum info size in user-to-user signalling IE */
name|UNI_UU_MAXLEN
init|=
literal|128
block|,
comment|/* maximum length of address */
name|UNI_ADDR_MAXLEN
init|=
literal|20
block|,
comment|/* maximum length of subaddress */
name|UNI_SUBADDR_MAXLEN
init|=
literal|20
block|,
comment|/* maximum number of DTLs */
name|UNI_NUM_IE_DTL
init|=
literal|10
block|,
comment|/* maximum number of identifiers in DTL */
name|UNI_DTL_MAXNUM
init|=
literal|20
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

