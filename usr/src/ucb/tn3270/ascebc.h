begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

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

end_unit

