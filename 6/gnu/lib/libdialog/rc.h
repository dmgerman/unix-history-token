begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  rc.h -- declarations for configuration file processing  *  *  AUTHOR: Savio Lam (lam836@cs.cuhk.hk)  *  *  This program is free software; you can redistribute it and/or  *  modify it under the terms of the GNU General Public License  *  as published by the Free Software Foundation; either version 2  *  of the License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|DIALOGRC
value|".dialogrc"
end_define

begin_define
define|#
directive|define
name|VAR_LEN
value|30
end_define

begin_define
define|#
directive|define
name|COMMENT_LEN
value|70
end_define

begin_comment
comment|/* Types of values */
end_comment

begin_define
define|#
directive|define
name|VAL_INT
value|0
end_define

begin_define
define|#
directive|define
name|VAL_STR
value|1
end_define

begin_define
define|#
directive|define
name|VAL_BOOL
value|2
end_define

begin_define
define|#
directive|define
name|VAL_ATTR
value|3
end_define

begin_comment
comment|/* Type of line in configuration file */
end_comment

begin_define
define|#
directive|define
name|LINE_BLANK
value|2
end_define

begin_define
define|#
directive|define
name|LINE_COMMENT
value|1
end_define

begin_define
define|#
directive|define
name|LINE_OK
value|0
end_define

begin_define
define|#
directive|define
name|LINE_ERROR
value|-1
end_define

begin_comment
comment|/* number of configuration variables */
end_comment

begin_define
define|#
directive|define
name|VAR_COUNT
value|(sizeof(vars) / sizeof(vars_st))
end_define

begin_comment
comment|/* check if character is white space */
end_comment

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(c == ' ' || c == '\t')
end_define

begin_comment
comment|/* check if character is string quoting characters */
end_comment

begin_define
define|#
directive|define
name|isquote
parameter_list|(
name|c
parameter_list|)
value|(c == '"' || c == '\'')
end_define

begin_comment
comment|/* get last character of string */
end_comment

begin_define
define|#
directive|define
name|lastch
parameter_list|(
name|str
parameter_list|)
value|str[strlen(str)-1]
end_define

begin_comment
comment|/*  * Configuration variables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|name
index|[
name|VAR_LEN
index|]
decl_stmt|;
comment|/* name of configuration variable as in DIALOGRC */
name|void
modifier|*
name|var
decl_stmt|;
comment|/* address of actually variable to change */
name|int
name|type
decl_stmt|;
comment|/* type of value */
name|unsigned
name|char
name|comment
index|[
name|COMMENT_LEN
index|]
decl_stmt|;
comment|/* comment to put in "rc" file */
block|}
name|vars_st
typedef|;
end_typedef

begin_decl_stmt
name|vars_st
name|vars
index|[]
init|=
block|{
block|{
literal|"use_shadow"
block|,
operator|&
name|use_shadow
block|,
name|VAL_BOOL
block|,
literal|"Shadow dialog boxes? This also turns on color."
block|}
block|,
block|{
literal|"use_colors"
block|,
operator|&
name|use_colors
block|,
name|VAL_BOOL
block|,
literal|"Turn color support ON or OFF"
block|}
block|,
block|{
literal|"screen_color"
block|,
name|color_table
index|[
literal|0
index|]
block|,
name|VAL_ATTR
block|,
literal|"Screen color"
block|}
block|,
block|{
literal|"shadow_color"
block|,
name|color_table
index|[
literal|1
index|]
block|,
name|VAL_ATTR
block|,
literal|"Shadow color"
block|}
block|,
block|{
literal|"dialog_color"
block|,
name|color_table
index|[
literal|2
index|]
block|,
name|VAL_ATTR
block|,
literal|"Dialog box color"
block|}
block|,
block|{
literal|"title_color"
block|,
name|color_table
index|[
literal|3
index|]
block|,
name|VAL_ATTR
block|,
literal|"Dialog box title color"
block|}
block|,
block|{
literal|"border_color"
block|,
name|color_table
index|[
literal|4
index|]
block|,
name|VAL_ATTR
block|,
literal|"Dialog box border color"
block|}
block|,
block|{
literal|"button_active_color"
block|,
name|color_table
index|[
literal|5
index|]
block|,
name|VAL_ATTR
block|,
literal|"Active button color"
block|}
block|,
block|{
literal|"button_inactive_color"
block|,
name|color_table
index|[
literal|6
index|]
block|,
name|VAL_ATTR
block|,
literal|"Inactive button color"
block|}
block|,
block|{
literal|"button_key_active_color"
block|,
name|color_table
index|[
literal|7
index|]
block|,
name|VAL_ATTR
block|,
literal|"Active button key color"
block|}
block|,
block|{
literal|"button_key_inactive_color"
block|,
name|color_table
index|[
literal|8
index|]
block|,
name|VAL_ATTR
block|,
literal|"Inactive button key color"
block|}
block|,
block|{
literal|"button_label_active_color"
block|,
name|color_table
index|[
literal|9
index|]
block|,
name|VAL_ATTR
block|,
literal|"Active button label color"
block|}
block|,
block|{
literal|"button_label_inactive_color"
block|,
name|color_table
index|[
literal|10
index|]
block|,
name|VAL_ATTR
block|,
literal|"Inactive button label color"
block|}
block|,
block|{
literal|"inputbox_color"
block|,
name|color_table
index|[
literal|11
index|]
block|,
name|VAL_ATTR
block|,
literal|"Input box color"
block|}
block|,
block|{
literal|"inputbox_border_color"
block|,
name|color_table
index|[
literal|12
index|]
block|,
name|VAL_ATTR
block|,
literal|"Input box border color"
block|}
block|,
block|{
literal|"searchbox_color"
block|,
name|color_table
index|[
literal|13
index|]
block|,
name|VAL_ATTR
block|,
literal|"Search box color"
block|}
block|,
block|{
literal|"searchbox_title_color"
block|,
name|color_table
index|[
literal|14
index|]
block|,
name|VAL_ATTR
block|,
literal|"Search box title color"
block|}
block|,
block|{
literal|"searchbox_border_color"
block|,
name|color_table
index|[
literal|15
index|]
block|,
name|VAL_ATTR
block|,
literal|"Search box border color"
block|}
block|,
block|{
literal|"position_indicator_color"
block|,
name|color_table
index|[
literal|16
index|]
block|,
name|VAL_ATTR
block|,
literal|"File position indicator color"
block|}
block|,
block|{
literal|"menubox_color"
block|,
name|color_table
index|[
literal|17
index|]
block|,
name|VAL_ATTR
block|,
literal|"Menu box color"
block|}
block|,
block|{
literal|"menubox_border_color"
block|,
name|color_table
index|[
literal|18
index|]
block|,
name|VAL_ATTR
block|,
literal|"Menu box border color"
block|}
block|,
block|{
literal|"item_color"
block|,
name|color_table
index|[
literal|19
index|]
block|,
name|VAL_ATTR
block|,
literal|"Item color"
block|}
block|,
block|{
literal|"item_selected_color"
block|,
name|color_table
index|[
literal|20
index|]
block|,
name|VAL_ATTR
block|,
literal|"Selected item color"
block|}
block|,
block|{
literal|"tag_color"
block|,
name|color_table
index|[
literal|21
index|]
block|,
name|VAL_ATTR
block|,
literal|"Tag color"
block|}
block|,
block|{
literal|"tag_selected_color"
block|,
name|color_table
index|[
literal|22
index|]
block|,
name|VAL_ATTR
block|,
literal|"Selected tag color"
block|}
block|,
block|{
literal|"tag_key_color"
block|,
name|color_table
index|[
literal|23
index|]
block|,
name|VAL_ATTR
block|,
literal|"Tag key color"
block|}
block|,
block|{
literal|"tag_key_selected_color"
block|,
name|color_table
index|[
literal|24
index|]
block|,
name|VAL_ATTR
block|,
literal|"Selected tag key color"
block|}
block|,
block|{
literal|"check_color"
block|,
name|color_table
index|[
literal|25
index|]
block|,
name|VAL_ATTR
block|,
literal|"Check box color"
block|}
block|,
block|{
literal|"check_selected_color"
block|,
name|color_table
index|[
literal|26
index|]
block|,
name|VAL_ATTR
block|,
literal|"Selected check box color"
block|}
block|,
block|{
literal|"uarrow_color"
block|,
name|color_table
index|[
literal|27
index|]
block|,
name|VAL_ATTR
block|,
literal|"Up arrow color"
block|}
block|,
block|{
literal|"darrow_color"
block|,
name|color_table
index|[
literal|28
index|]
block|,
name|VAL_ATTR
block|,
literal|"Down arrow color"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vars */
end_comment

begin_comment
comment|/*  * Routines to process configuration file  */
end_comment

begin_function_decl
name|int
name|parse_rc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

