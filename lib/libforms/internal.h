begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Paul Richards.   *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_define
define|#
directive|define
name|F_UP
value|keymap[0]
end_define

begin_define
define|#
directive|define
name|F_DOWN
value|keymap[1]
end_define

begin_define
define|#
directive|define
name|F_RIGHT
value|keymap[2]
end_define

begin_define
define|#
directive|define
name|F_LEFT
value|keymap[3]
end_define

begin_define
define|#
directive|define
name|F_NEXT
value|keymap[4]
end_define

begin_define
define|#
directive|define
name|F_CLEFT
value|keymap[5]
end_define

begin_define
define|#
directive|define
name|F_CRIGHT
value|keymap[6]
end_define

begin_define
define|#
directive|define
name|F_CHOME
value|keymap[7]
end_define

begin_define
define|#
directive|define
name|F_CEND
value|keymap[8]
end_define

begin_define
define|#
directive|define
name|F_CBS
value|keymap[9]
end_define

begin_define
define|#
directive|define
name|F_CDEL
value|keymap[10]
end_define

begin_define
define|#
directive|define
name|F_ACCEPT
value|F_NEXT
end_define

begin_comment
comment|/* Private function declarations */
end_comment

begin_function_decl
specifier|static
name|void
name|show_form
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disp_text
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disp_menu
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disp_action
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|disp_input
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|field_menu
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|field_input
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|field_action
parameter_list|(
name|struct
name|form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|print_string
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_status
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|next_field
parameter_list|(
name|struct
name|form
modifier|*
name|form
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

