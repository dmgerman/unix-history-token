begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Paul Richards.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Paul Richards.  * 4. The name Paul Richards may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PAUL RICHARDS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PAUL RICHARDS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|FK_UP
value|f_keymap[0]
end_define

begin_define
define|#
directive|define
name|FK_DOWN
value|f_keymap[1]
end_define

begin_define
define|#
directive|define
name|FK_RIGHT
value|f_keymap[2]
end_define

begin_define
define|#
directive|define
name|FK_LEFT
value|f_keymap[3]
end_define

begin_define
define|#
directive|define
name|FK_NEXT
value|f_keymap[4]
end_define

begin_define
define|#
directive|define
name|FK_CLEFT
value|f_keymap[5]
end_define

begin_define
define|#
directive|define
name|FK_CRIGHT
value|f_keymap[6]
end_define

begin_define
define|#
directive|define
name|FK_CHOME
value|f_keymap[7]
end_define

begin_define
define|#
directive|define
name|FK_CEND
value|f_keymap[8]
end_define

begin_define
define|#
directive|define
name|FK_CBS
value|f_keymap[9]
end_define

begin_define
define|#
directive|define
name|FK_CDEL
value|f_keymap[10]
end_define

begin_define
define|#
directive|define
name|FK_ACCEPT
value|f_keymap[11]
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|f_keymap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private function declarations */
end_comment

begin_function_decl
name|void
name|display_field
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|struct
name|Field
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_text
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|struct
name|Field
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_input
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|struct
name|Field
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_menu
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|struct
name|Field
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_action
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|struct
name|Field
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|do_key_bind
parameter_list|(
name|struct
name|Form
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_action
parameter_list|(
name|struct
name|Form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_menu
parameter_list|(
name|struct
name|Form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_input
parameter_list|(
name|struct
name|Form
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_field
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|calc_string_width
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|calc_field_height
parameter_list|(
name|struct
name|Field
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|not
end_ifdef

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
name|int
parameter_list|,
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

