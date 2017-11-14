begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms are freely  * permitted provided that the above copyright notice and this  * paragraph and the following disclaimer are duplicated in all  * such forms.  *  * This software is provided "AS IS" and without any express or  * implied warranties, including, without limitation, the implied  * warranties of merchantability and fitness for a particular  * purpose.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONS_H_
end_define

begin_define
define|#
directive|define
name|IO_KEYBOARD
value|1
end_define

begin_define
define|#
directive|define
name|IO_SERIAL
value|2
end_define

begin_decl_stmt
specifier|extern
name|uint8_t
name|ioctrl
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|putc
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xputc
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putchar
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|(
name|int
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xgetc
parameter_list|(
name|int
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|keyhit
parameter_list|(
name|unsigned
name|int
name|secs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getstr
parameter_list|(
name|char
modifier|*
name|cmdstr
parameter_list|,
name|size_t
name|cmdstrsize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CONS_H_ */
end_comment

end_unit

