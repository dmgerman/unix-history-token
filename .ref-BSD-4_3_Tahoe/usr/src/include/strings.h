begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)strings.h	5.3 (Berkeley) 11/18/87  */
end_comment

begin_comment
comment|/*  * External function definitions  * for routines described in string(3).  */
end_comment

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcasecmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strncasecmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S5 compatibility */
end_comment

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strpbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strspn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcspn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|()
function_decl|;
end_function_decl

end_unit

