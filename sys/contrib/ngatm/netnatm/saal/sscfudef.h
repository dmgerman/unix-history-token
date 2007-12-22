begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscfudef.h,v 1.4 2004/07/08 08:22:16 brandt Exp $  *  * Definitions of UNI SSCF constants.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SAAL_SSCFUDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SAAL_SSCFUDEF_H_
end_define

begin_comment
comment|/*  * Signals at the upper boundary of the SSCF.  */
end_comment

begin_enum
enum|enum
name|saal_sig
block|{
name|SAAL_ESTABLISH_request
block|,
comment|/* U -> SAAL: (UU) */
name|SAAL_ESTABLISH_indication
block|,
comment|/* SAAL -> U: (UU) */
name|SAAL_ESTABLISH_confirm
block|,
comment|/* SAAL -> U: (UU) */
name|SAAL_RELEASE_request
block|,
comment|/* U -> SAAL: (UU) */
name|SAAL_RELEASE_confirm
block|,
comment|/* SAAL -> U: */
name|SAAL_RELEASE_indication
block|,
comment|/* SAAL -> U: (UU) */
name|SAAL_DATA_request
block|,
comment|/* U -> SAAL: (DATA) */
name|SAAL_DATA_indication
block|,
comment|/* SAAL -> U: (DATA) */
name|SAAL_UDATA_request
block|,
comment|/* U -> SAAL: (UDATA) */
name|SAAL_UDATA_indication
block|,
comment|/* SAAL -> U: (UDATA) */
block|}
enum|;
end_enum

begin_comment
comment|/*  * States of the SSCF  */
end_comment

begin_enum
enum|enum
name|sscfu_state
block|{
name|SSCFU_RELEASED
block|,
comment|/* 1/1 */
name|SSCFU_AWAITING_ESTABLISH
block|,
comment|/* 2/2 */
name|SSCFU_AWAITING_RELEASE
block|,
comment|/* 4/10 */
name|SSCFU_ESTABLISHED
block|,
comment|/* 3/4 */
name|SSCFU_RESYNC
block|,
comment|/* 2/5 */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Debugging flags  */
end_comment

begin_enum
enum|enum
block|{
name|SSCFU_DBG_LSIG
init|=
literal|0x01
block|,
name|SSCFU_DBG_ERR
init|=
literal|0x02
block|,
name|SSCFU_DBG_STATE
init|=
literal|0x04
block|,
name|SSCFU_DBG_EXEC
init|=
literal|0x08
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

