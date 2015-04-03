begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/libntp/gpstolfp.c,v 4.8 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * gpstolfp.c,v 4.8 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * $Created: Sun Jun 28 16:30:38 1998 $  *  * Copyright (c) 1998-2005 by Frank Kardel<kardel<AT> ntp.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_define
define|#
directive|define
name|GPSORIGIN
value|2524953600UL
end_define

begin_comment
comment|/* NTP origin - GPS origin in seconds */
end_comment

begin_define
define|#
directive|define
name|SECSPERWEEK
value|(unsigned)(604800)
end_define

begin_comment
comment|/* seconds per week - GPS tells us about weeks */
end_comment

begin_define
define|#
directive|define
name|GPSWRAP
value|990
end_define

begin_comment
comment|/* assume week count less than this in the previous epoch */
end_comment

begin_function
name|void
name|gpstolfp
parameter_list|(
name|int
name|weeks
parameter_list|,
name|int
name|days
parameter_list|,
name|unsigned
name|long
name|seconds
parameter_list|,
name|l_fp
modifier|*
name|lfp
parameter_list|)
block|{
if|if
condition|(
name|weeks
operator|<
name|GPSWRAP
condition|)
block|{
name|weeks
operator|+=
literal|1024
expr_stmt|;
block|}
name|lfp
operator|->
name|l_ui
operator|=
name|weeks
operator|*
name|SECSPERWEEK
operator|+
name|days
operator|*
literal|86400
operator|+
name|seconds
operator|+
name|GPSORIGIN
expr_stmt|;
comment|/* convert to NTP time */
name|lfp
operator|->
name|l_uf
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * History:  *  * gpstolfp.c,v  * Revision 4.8  2005/04/16 17:32:10  kardel  * update copyright  *  * Revision 4.7  2004/11/14 15:29:41  kardel  * support PPSAPI, upgrade Copyright to Berkeley style  *  * Revision 4.3  1999/02/28 11:42:44  kardel  * (GPSWRAP): update GPS rollover to 990 weeks  *  * Revision 4.2  1998/07/11 10:05:25  kardel  * Release 4.0.73d reconcilation  *  * Revision 4.1  1998/06/28 16:47:15  kardel  * added gpstolfp() function  */
end_comment

end_unit

