begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 LSIIT Laboratory.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_define
define|#
directive|define
name|UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|EMPTY
value|1
end_define

begin_define
define|#
directive|define
name|PHYINT
value|2
end_define

begin_define
define|#
directive|define
name|CANDIDATE_RP
value|3
end_define

begin_define
define|#
directive|define
name|GROUP_PREFIX
value|4
end_define

begin_define
define|#
directive|define
name|BOOTSTRAP_RP
value|5
end_define

begin_define
define|#
directive|define
name|REG_THRESHOLD
value|6
end_define

begin_define
define|#
directive|define
name|DATA_THRESHOLD
value|7
end_define

begin_define
define|#
directive|define
name|DEFAULT_SOURCE_METRIC
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_SOURCE_PREFERENCE
value|9
end_define

begin_define
define|#
directive|define
name|HELLO_PERIOD
value|10
end_define

begin_define
define|#
directive|define
name|GRANULARITY
value|11
end_define

begin_define
define|#
directive|define
name|JOIN_PRUNE_PERIOD
value|12
end_define

begin_define
define|#
directive|define
name|DATA_TIMEOUT
value|13
end_define

begin_define
define|#
directive|define
name|REGISTER_SUPPRESSION_TIMEOUT
value|14
end_define

begin_define
define|#
directive|define
name|PROBE_TIME
value|15
end_define

begin_define
define|#
directive|define
name|ASSERT_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|EQUAL
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp((s1), (s2)) == 0)
end_define

begin_decl_stmt
name|void
name|config_vifs_from_kernel
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|config_vifs_from_file
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

