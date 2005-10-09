begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Header file for dc routines  *  * Copyright (C) 1994, 1997, 1998 Free Software Foundation, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, you can either send email to this  * program's author (see below) or write to:  *  *    The Free Software Foundation, Inc.  *    59 Temple Place, Suite 330  *    Boston, MA 02111 USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DC_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|DC_DEFS_H
end_define

begin_comment
comment|/* 'I' is a command, and bases 17 and 18 are quite  * unusual, so we limit ourselves to bases 2 to 16  */
end_comment

begin_define
define|#
directive|define
name|DC_IBASE_MAX
value|16
end_define

begin_define
define|#
directive|define
name|DC_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|DC_DOMAIN_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|DC_FAIL
value|2
end_define

begin_comment
comment|/* generic failure */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|DC_PROTO
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|DC_DECLVOID
parameter_list|()
value|()
end_define

begin_define
define|#
directive|define
name|DC_DECLARG
parameter_list|(
name|arglist
parameter_list|)
value|arglist
end_define

begin_define
define|#
directive|define
name|DC_DECLSEP
value|;
end_define

begin_define
define|#
directive|define
name|DC_DECLEND
value|;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|DC_PROTO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|DC_DECLVOID
parameter_list|()
value|(void)
end_define

begin_define
define|#
directive|define
name|DC_DECLARG
parameter_list|(
name|arglist
parameter_list|)
value|(
end_define

begin_define
define|#
directive|define
name|DC_DECLSEP
value|,
end_define

begin_define
define|#
directive|define
name|DC_DECLEND
value|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DC_TOSS
block|,
name|DC_KEEP
block|}
name|dc_discard
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DC_NONL
block|,
name|DC_WITHNL
block|}
name|dc_newline
typedef|;
end_typedef

begin_comment
comment|/* type discriminant for dc_data */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DC_UNINITIALIZED
block|,
name|DC_NUMBER
block|,
name|DC_STRING
block|}
name|dc_value_type
typedef|;
end_typedef

begin_comment
comment|/* only numeric.c knows what dc_num's *really* look like */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dc_number
modifier|*
name|dc_num
typedef|;
end_typedef

begin_comment
comment|/* only string.c knows what dc_str's *really* look like */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dc_string
modifier|*
name|dc_str
typedef|;
end_typedef

begin_comment
comment|/* except for the two implementation-specific modules, all  * dc functions only know of this one generic type of object  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dc_value_type
name|dc_type
decl_stmt|;
comment|/* discriminant for union */
union|union
block|{
name|dc_num
name|number
decl_stmt|;
name|dc_str
name|string
decl_stmt|;
block|}
name|v
union|;
block|}
name|dc_data
typedef|;
end_typedef

begin_comment
comment|/* This is dc's only global variable: */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* basename of program invocation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DC_DEFS_H */
end_comment

end_unit

