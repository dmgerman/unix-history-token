begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)strings.h	5.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Routines described in string(3) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strncat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|,
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strcmp
argument_list|()
decl_stmt|,
name|strncmp
argument_list|()
decl_stmt|,
name|strcasecmp
argument_list|()
decl_stmt|,
name|strncasecmp
argument_list|()
decl_stmt|,
name|strlen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines described in memory(BA_LIB); System V compatibility */
end_comment

begin_decl_stmt
name|char
modifier|*
name|memccpy
argument_list|()
decl_stmt|,
modifier|*
name|memchr
argument_list|()
decl_stmt|,
modifier|*
name|memcpy
argument_list|()
decl_stmt|,
modifier|*
name|memset
argument_list|()
decl_stmt|,
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strdup
argument_list|()
decl_stmt|,
modifier|*
name|strpbrk
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|,
modifier|*
name|strsep
argument_list|()
decl_stmt|,
modifier|*
name|strtok
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|memcmp
argument_list|()
decl_stmt|,
name|strcspn
argument_list|()
decl_stmt|,
name|strspn
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines from ANSI X3J11 */
end_comment

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
end_function_decl

end_unit

