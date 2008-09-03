begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/include/parse_conf.h,v 4.7 2005/06/25 10:58:45 kardel RELEASE_20050625_A  *  * parse_conf.h,v 4.7 2005/06/25 10:58:45 kardel RELEASE_20050625_A  *  * Copyright (c) 1995-2005 by Frank Kardel<kardel<AT> ntp.org>  * Copyright (c) 1989-1994 by Frank Kardel, Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PARSE_CONF_H__
end_ifndef

begin_define
define|#
directive|define
name|__PARSE_CONF_H__
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|lint
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|static
name|char
name|prshrcsid
index|[]
init|=
literal|"parse_conf.h,v 4.7 2005/06/25 10:58:45 kardel RELEASE_20050625_A"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * field location structure  */
end_comment

begin_define
define|#
directive|define
name|O_DAY
value|0
end_define

begin_define
define|#
directive|define
name|O_MONTH
value|1
end_define

begin_define
define|#
directive|define
name|O_YEAR
value|2
end_define

begin_define
define|#
directive|define
name|O_HOUR
value|3
end_define

begin_define
define|#
directive|define
name|O_MIN
value|4
end_define

begin_define
define|#
directive|define
name|O_SEC
value|5
end_define

begin_define
define|#
directive|define
name|O_WDAY
value|6
end_define

begin_define
define|#
directive|define
name|O_FLAGS
value|7
end_define

begin_define
define|#
directive|define
name|O_ZONE
value|8
end_define

begin_define
define|#
directive|define
name|O_UTCHOFFSET
value|9
end_define

begin_define
define|#
directive|define
name|O_UTCMOFFSET
value|10
end_define

begin_define
define|#
directive|define
name|O_UTCSOFFSET
value|11
end_define

begin_define
define|#
directive|define
name|O_COUNT
value|(O_UTCSOFFSET+1)
end_define

begin_define
define|#
directive|define
name|MBG_EXTENDED
value|0x00000001
end_define

begin_comment
comment|/*  * see below for field offsets  */
end_comment

begin_struct
struct|struct
name|format
block|{
struct|struct
name|foff
block|{
name|unsigned
name|short
name|offset
decl_stmt|;
comment|/* offset into buffer */
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* length of field */
block|}
name|field_offsets
index|[
name|O_COUNT
index|]
struct|;
specifier|const
name|unsigned
name|char
modifier|*
name|fixed_string
decl_stmt|;
comment|/* string with must be chars (blanks = wildcards) */
name|u_long
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * parse_conf.h,v  * Revision 4.7  2005/06/25 10:58:45  kardel  * add missing log keywords  *  */
end_comment

end_unit

