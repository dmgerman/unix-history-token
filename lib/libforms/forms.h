begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Paul Richards.   *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_define
define|#
directive|define
name|F_END
value|0
end_define

begin_define
define|#
directive|define
name|F_TEXT
value|1
end_define

begin_define
define|#
directive|define
name|F_ACTION
value|2
end_define

begin_define
define|#
directive|define
name|F_INPUT
value|3
end_define

begin_define
define|#
directive|define
name|F_MENU
value|4
end_define

begin_define
define|#
directive|define
name|F_DEFATTR
value|0
end_define

begin_define
define|#
directive|define
name|F_SELATTR
value|A_REVERSE
end_define

begin_define
define|#
directive|define
name|F_DONE
value|1
end_define

begin_define
define|#
directive|define
name|F_CANCEL
value|-1
end_define

begin_struct
struct|struct
name|form
block|{
name|int
name|no_fields
decl_stmt|;
name|int
name|current_field
decl_stmt|;
name|struct
name|field
modifier|*
name|field
decl_stmt|;
name|int
name|height
decl_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|x
decl_stmt|;
name|WINDOW
modifier|*
name|window
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|text_field
block|{
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|action_field
block|{
name|char
modifier|*
name|text
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|input_field
block|{
name|int
name|lbl_flag
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|char
modifier|*
name|input
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|menu_field
block|{
name|int
name|no_options
decl_stmt|;
name|int
name|selected
decl_stmt|;
name|char
modifier|*
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|help_link
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|field
block|{
name|int
name|type
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|x
decl_stmt|;
name|int
name|disp_width
decl_stmt|;
name|int
name|width
decl_stmt|;
name|int
name|attr
decl_stmt|;
name|int
name|next
decl_stmt|;
name|int
name|up
decl_stmt|;
name|int
name|down
decl_stmt|;
name|int
name|left
decl_stmt|;
name|int
name|right
decl_stmt|;
union|union
block|{
name|struct
name|text_field
modifier|*
name|text
decl_stmt|;
name|struct
name|action_field
modifier|*
name|action
decl_stmt|;
name|struct
name|input_field
modifier|*
name|input
decl_stmt|;
name|struct
name|menu_field
modifier|*
name|menu
decl_stmt|;
block|}
name|field
union|;
comment|/* 	struct help_link help; 	*/
block|}
struct|;
end_struct

begin_comment
comment|/* Externally visible keymap table for user-definable keymaps */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|keymap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Externally visible function declarations */
end_comment

begin_function_decl
name|int
name|update_form
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initfrm
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endfrm
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit_form
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cancel_form
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

