begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/REPOSITORY/v3/include/parse_conf.h,v 3.5 1994/01/25 19:04:23 kardel Exp  *  * parse_conf.h,v 3.5 1994/01/25 19:04:23 kardel Exp  *  * Copyright (c) 1993,1994  * Frank Kardel Friedrich-Alexander Universitaet Erlangen-Nuernberg  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
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
name|dcfhrcsid
index|[]
init|=
literal|"parse_conf.h,v 3.5 1994/01/25 19:04:23 kardel Exp FAU"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * field location structure (Meinberg clocks/simple format)  */
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
name|char
name|offset
decl_stmt|;
comment|/* offset into buffer */
name|char
name|length
decl_stmt|;
comment|/* length of field */
block|}
name|field_offsets
index|[
name|O_COUNT
index|]
struct|;
name|char
modifier|*
name|fixed_string
decl_stmt|;
comment|/* string with must be chars (blanks = wildcards) */
name|unsigned
name|LONG
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

