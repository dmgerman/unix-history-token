begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)getpar.h	5.4 (Berkeley) %G%  */
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

