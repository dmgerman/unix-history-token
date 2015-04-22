begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/include/binio.h,v 4.5 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * binio.h,v 4.5 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * $Created: Sun Jul 20 13:03:05 1997 $  *  * Copyright (c) 1997-2005 by Frank Kardel<kardel<AT> ntp.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BINIO_H
end_ifndef

begin_define
define|#
directive|define
name|BINIO_H
end_define

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function_decl
name|long
name|get_lsb_short
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_lsb_short
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|get_lsb_long
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_lsb_long
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|get_msb_short
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_msb_short
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|get_msb_long
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_msb_long
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * binio.h,v  * Revision 4.5  2005/04/16 17:32:10  kardel  * update copyright  *  * Revision 4.4  2004/11/14 15:29:41  kardel  * support PPSAPI, upgrade Copyright to Berkeley style  *  * Revision 4.2  1998/06/28 16:52:15  kardel  * added binio MSB prototypes for {get,put}_msb_{short,long}  *  * Revision 4.1  1998/06/12 15:07:40  kardel  * fixed prototyping  *  * Revision 4.0  1998/04/10 19:50:38  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:32  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:37  kardel  * new parse structure  *  */
end_comment

end_unit

