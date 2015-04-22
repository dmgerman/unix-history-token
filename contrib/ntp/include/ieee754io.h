begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/include/ieee754io.h,v 4.3 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * ieee754io.h,v 4.3 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * $Created: Sun Jul 13 12:22:11 1997 $  *  * Copyright (c) 1997-2005 by Frank Kardel<kardel<AT> ntp.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE754IO_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE754IO_H
end_define

begin_define
define|#
directive|define
name|IEEE_SINGLE
value|1
end_define

begin_define
define|#
directive|define
name|IEEE_DOUBLE
value|2
end_define

begin_define
define|#
directive|define
name|IEEE_MSB
value|1
end_define

begin_define
define|#
directive|define
name|IEEE_LSB
value|2
end_define

begin_define
define|#
directive|define
name|IEEE_OK
value|0
end_define

begin_comment
comment|/* conversion ok */
end_comment

begin_define
define|#
directive|define
name|IEEE_BADCALL
value|1
end_define

begin_comment
comment|/* bad call parameters */
end_comment

begin_define
define|#
directive|define
name|IEEE_NAN
value|2
end_define

begin_comment
comment|/* found an NaN */
end_comment

begin_define
define|#
directive|define
name|IEEE_POSINFINITY
value|3
end_define

begin_comment
comment|/* positive infinity */
end_comment

begin_define
define|#
directive|define
name|IEEE_NEGINFINITY
value|4
end_define

begin_comment
comment|/* negative infinity */
end_comment

begin_define
define|#
directive|define
name|IEEE_POSOVERFLOW
value|5
end_define

begin_comment
comment|/* positive overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_NEGOVERFLOW
value|6
end_define

begin_comment
comment|/* negative overflow */
end_comment

begin_define
define|#
directive|define
name|IEEE_OFFSETS
value|8
end_define

begin_comment
comment|/* number of byte positions */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|offsets_t
index|[
name|IEEE_OFFSETS
index|]
typedef|;
end_typedef

begin_function_decl
name|int
name|fetch_ieee754
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|bufp
parameter_list|,
name|int
name|size
parameter_list|,
name|l_fp
modifier|*
name|lfpp
parameter_list|,
name|offsets_t
name|offsets
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|put_ieee754
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|bufpp
parameter_list|,
name|int
name|size
parameter_list|,
name|l_fp
modifier|*
name|lfpp
parameter_list|,
name|offsets_t
name|offsets
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * ieee754io.h,v  * Revision 4.3  2005/04/16 17:32:10  kardel  * update copyright  *  * Revision 4.2  2004/11/14 15:29:41  kardel  * support PPSAPI, upgrade Copyright to Berkeley style  *  * Revision 4.0  1998/04/10 19:50:40  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:33  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:37  kardel  * new parse structure  *  */
end_comment

end_unit

