begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: macro.h,v 1.2 85/03/19 09:18:02 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * General macro function definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_function_decl
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string comparison */
end_comment

begin_undef
undef|#
directive|undef
name|CHDIR
end_undef

begin_define
define|#
directive|define
name|CHDIR
parameter_list|(
name|d
parameter_list|)
define|\
value|(chdir(d) == 0)
end_define

begin_comment
comment|/* change directory */
end_comment

begin_undef
undef|#
directive|undef
name|DOTDIR
end_undef

begin_define
define|#
directive|define
name|DOTDIR
parameter_list|(
name|dp
parameter_list|)
define|\
value|(dp->d_name[0] == '.'&& dp->d_name[1] == '\0')
end_define

begin_comment
comment|/* current directory? */
end_comment

begin_undef
undef|#
directive|undef
name|DOTDOTDIR
end_undef

begin_define
define|#
directive|define
name|DOTDOTDIR
parameter_list|(
name|dp
parameter_list|)
define|\
value|(dp->d_name[0] == '.'&& dp->d_name[1] == '.'&& dp->d_name[2] == '\0')
end_define

begin_comment
comment|/* parent directory? */
end_comment

begin_undef
undef|#
directive|undef
name|EQUAL
end_undef

begin_define
define|#
directive|define
name|EQUAL
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|(strcmp(s1,s2) == 0)
end_define

begin_comment
comment|/* string comparison */
end_comment

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)< (b)) ? (a) : (b))
end_define

begin_comment
comment|/* minimum of two values */
end_comment

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)> (b)) ? (a) : (b))
end_define

begin_comment
comment|/* maximum of two values */
end_comment

begin_undef
undef|#
directive|undef
name|WHITESPACE
end_undef

begin_define
define|#
directive|define
name|WHITESPACE
parameter_list|(
name|c
parameter_list|)
define|\
value|(c == ' ' || c == '\t')
end_define

begin_comment
comment|/* unseen space in a file */
end_comment

end_unit

