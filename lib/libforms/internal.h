begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Paul Richards.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Paul Richards.  * 4. The name Paul Richards may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PAUL RICHARDS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PAUL RICHARDS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* Object status values */
end_comment

begin_define
define|#
directive|define
name|O_VISIBLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|O_ACTIVE
value|0x0002
end_define

begin_comment
comment|/* Standard attribute commands */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ATTR_BOX
block|,
name|ATTR_CENTER
block|,
name|ATTR_RIGHT
block|,
name|ATTR_SHADOW
block|,
name|ATTR_UNKNOWN
block|}
name|AttrType
typedef|;
end_typedef

begin_struct
struct|struct
name|attr_cmnd
block|{
name|char
modifier|*
name|attr_name
decl_stmt|;
name|AttrType
name|attr_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Ncurses color pairs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|color_pair
block|{
name|int
name|no
decl_stmt|;
name|int
name|fg
decl_stmt|;
name|int
name|bg
decl_stmt|;
block|}
name|COLPAIR
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|attr_cmnd
name|attr_cmnds
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hash_table
modifier|*
name|root_table
decl_stmt|,
modifier|*
name|cbind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DISPLAY
modifier|*
name|cdisp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private function declarations */
end_comment

begin_function_decl
name|int
name|display_tuples
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
name|refresh_displays
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
name|copy_object_tree
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
name|void
name|process_tuple
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_object
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_input_object
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_menu_object
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_text_object
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DISPLAY
modifier|*
name|default_open
parameter_list|(
name|DISPLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DISPLAY
modifier|*
name|ncurses_open
parameter_list|(
name|DISPLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncurses_print_string
parameter_list|(
name|OBJECT
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_print_status
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncurses_bind_key
parameter_list|(
name|OBJECT
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_action
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_compound
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_function
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_input
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_menu
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_display_text
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_process_action
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_process_input
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_process_menu
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncurses_process_text
parameter_list|(
name|OBJECT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

