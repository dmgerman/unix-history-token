begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)getpar.h	5.2 (Berkeley) %G%  */
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

