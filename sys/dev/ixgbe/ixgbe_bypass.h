begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_BYPASS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_BYPASS_H_
end_define

begin_comment
comment|/*  * The bypass driver needs to set FW to a epoc of the number of  * seconds we are into this year.  This macro's help support that.  */
end_comment

begin_define
define|#
directive|define
name|SEC_PER_DAY
value|(60 * 60 * 24)
end_define

begin_define
define|#
directive|define
name|SEC_PER_YEAR
value|(SEC_PER_DAY * 365)
end_define

begin_define
define|#
directive|define
name|SEC_PER_LYEAR
value|(SEC_PER_DAY * 366)
end_define

begin_define
define|#
directive|define
name|LEAP_YR
parameter_list|(
name|y
parameter_list|)
value|((y % 400 == 0) || ((y % 4 == 0)&& (y % 100 != 0)))
end_define

begin_define
define|#
directive|define
name|SEC_THIS_YEAR
parameter_list|(
name|y
parameter_list|)
value|(LEAP_YR(y) ? SEC_PER_LYEAR : SEC_PER_YEAR)
end_define

begin_function_decl
name|void
name|ixgbe_bypass_init
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_BYPASS_H_ */
end_comment

end_unit

