begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: tty_input.h,v 1.1 1998/12/19 22:42:57 tom Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TTY_INPUT_H
end_ifndef

begin_define
define|#
directive|define
name|TTY_INPUT_H
value|1
end_define

begin_function_decl
specifier|extern
name|bool
name|_nc_tty_mouse_mask
parameter_list|(
name|mmask_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|_nc_tty_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_nc_tty_next_event
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_tty_flags_changed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_tty_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_tty_input_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nc_tty_input_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tty_input_data
block|{
name|int
name|_ifd
decl_stmt|;
comment|/* input file ptr for screen        */
name|int
name|_keypad_xmit
decl_stmt|;
comment|/* current terminal state           */
name|int
name|_meta_on
decl_stmt|;
comment|/* current terminal state           */
comment|/* 	 * These are the data that support the mouse interface. 	 */
name|bool
function_decl|(
modifier|*
name|_mouse_event
function_decl|)
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|_mouse_inline
function_decl|)
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|_mouse_parse
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_mouse_resume
function_decl|)
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_mouse_wrap
function_decl|)
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
name|int
name|_mouse_fd
decl_stmt|;
comment|/* file-descriptor, if any */
name|int
name|mousetype
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TTY_INPUT_H */
end_comment

end_unit

