begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)disp_asc.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_comment
comment|/*  * Define the translate tables used to go between 3270 display code  * and ascii  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|disp_asc
index|[
literal|256
index|]
decl_stmt|,
comment|/* Goes between display code and ascii */
name|asc_disp
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Goes between ascii and display code */
end_comment

end_unit

