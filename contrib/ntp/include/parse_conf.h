begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/parse_conf.h,v 4.2 1998/06/14 21:09:28 kardel RELEASE_19990228_A  *  * parse_conf.h,v 4.2 1998/06/14 21:09:28 kardel RELEASE_19990228_A  *  * Copyright (c) 1993, 1994, 1995, 1996, 1997, 1998 by Frank Kardel  * Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
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
literal|"parse_conf.h,v 4.2 1998/06/14 21:09:28 kardel RELEASE_19990228_A"
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

end_unit

