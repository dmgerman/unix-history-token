begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/mpls.h,v 1.1 2004/06/14 14:47:58 hannes Exp $ (LBL)  * Copyright (C) 2001 WIDE Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|LABEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|EXP_MASK
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|EXP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|STACK_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|STACK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TTL_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TTL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MPLS_LABEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& LABEL_MASK)>> LABEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_EXP
parameter_list|(
name|x
parameter_list|)
value|(((x)& EXP_MASK)>> EXP_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_STACK
parameter_list|(
name|x
parameter_list|)
value|(((x)& STACK_MASK)>> STACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPLS_TTL
parameter_list|(
name|x
parameter_list|)
value|(((x)& TTL_MASK)>> TTL_SHIFT)
end_define

end_unit

