begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)astosc.h	4.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This defines the structure used to translate:  *  *	ascii name ==> (scancode, shiftstate)  *  * (Actually, map3270 does "ascii name ==> index", and  * termin does "index ==> (scancode, shiftstate)".  Both  * mappings use this structure.)  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ASTOSC
end_define

begin_struct
struct|struct
name|astosc
block|{
name|unsigned
name|char
name|scancode
decl_stmt|,
comment|/* Scan code for this function */
name|shiftstate
decl_stmt|;
comment|/* Shift state for this function */
name|enum
name|ctlrfcn
name|function
decl_stmt|;
comment|/* Internal function identifier */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this function */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ascii_to_index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Function to feed InitControl() */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|astosc
name|astosc
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

end_unit

