begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_HRT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_HRT_H_
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CNTL
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CNTL_RES
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CNTL_TOFD
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CNTL_START
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CNTL_GET
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_DO
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_REP
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_TOD
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_FUTREP
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_TODREP
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ALRM_PEND
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_SLP
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_SLP_INT
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_SLP_TOD
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_BSD
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_BSD_PEND
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_BSD_REP1
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_BSD_REP2
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_BSD_CANCEL
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CAN
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_SEC
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_MSEC
value|1000
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_USEC
value|1000000
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_NSEC
value|1000000000
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_TRUNC
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_RND
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|i_word1
decl_stmt|;
name|u_long
name|i_word2
decl_stmt|;
name|int
name|i_clock
decl_stmt|;
block|}
name|svr4_hrt_interval_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|h_sec
decl_stmt|;
name|long
name|h_rem
decl_stmt|;
name|u_long
name|h_res
decl_stmt|;
block|}
name|svr4_hrt_time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SVR4_HRT_DONE
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CLK_STD
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CLK_USERVIRT
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_HRT_CLK_PROCVIRT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_HRT_H_ */
end_comment

end_unit

