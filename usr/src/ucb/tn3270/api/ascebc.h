begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)ascebc.h	1.2 (Berkeley) 3/28/88  */
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
name|NASCEBC
value|4
end_define

begin_comment
comment|/* number of ascii to ebcdic tables */
end_comment

begin_define
define|#
directive|define
name|AE_NO
value|-1
end_define

begin_comment
comment|/* no translation - user has already done it */
end_comment

begin_define
define|#
directive|define
name|AE_PR
value|0
end_define

begin_comment
comment|/* ascii to ebcdic "print" translation */
end_comment

begin_define
define|#
directive|define
name|AE_IN
value|1
end_define

begin_comment
comment|/* ascii to ebcdic "input" translation */
end_comment

begin_define
define|#
directive|define
name|AE_SP
value|2
end_define

begin_comment
comment|/* ascii to ebcdic special translation */
end_comment

begin_define
define|#
directive|define
name|AE_TX
value|3
end_define

begin_comment
comment|/* ascii to ebcdic pure text translation */
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

begin_define
define|#
directive|define
name|NEBCASC
value|1
end_define

begin_comment
comment|/* number of ebcdic to ascii tables */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|ascebc
index|[
name|NASCEBC
index|]
index|[
name|NASCII
index|]
decl_stmt|,
name|ebcasc
index|[
name|NEBCASC
index|]
index|[
name|NEBC
index|]
decl_stmt|;
end_decl_stmt

end_unit

