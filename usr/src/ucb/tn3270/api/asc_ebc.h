begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)asc_ebc.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_comment
comment|/*  * Definitions of translate tables used for ascii<->ebcdic translation.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ASCEBC
end_define

begin_comment
comment|/*  * ascii/ebcdic translation information  */
end_comment

begin_define
define|#
directive|define
name|NASCII
value|128
end_define

begin_comment
comment|/* number of ascii characters */
end_comment

begin_define
define|#
directive|define
name|NEBC
value|256
end_define

begin_comment
comment|/* number of ebcdic characters */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|asc_ebc
index|[
name|NASCII
index|]
decl_stmt|,
name|ebc_asc
index|[
name|NEBC
index|]
decl_stmt|;
end_decl_stmt

end_unit

