begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_function_decl
name|void
name|sio_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sio_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sio_putc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sio_getc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sio_ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

