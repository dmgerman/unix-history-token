begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)getpar.h	5.4 (Berkeley) 6/1/90  */
end_comment

begin_struct
struct|struct
name|cvntab
comment|/* used for getcodpar() paramater list */
block|{
name|char
modifier|*
name|abrev
decl_stmt|;
name|char
modifier|*
name|full
decl_stmt|;
name|int
function_decl|(
modifier|*
name|value
function_decl|)
parameter_list|()
function_decl|;
name|int
name|value2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|double
name|getfltpar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cvntab
modifier|*
name|getcodpar
parameter_list|()
function_decl|;
end_function_decl

end_unit

