begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)dctype.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ECTYPE
end_define

begin_define
define|#
directive|define
name|D_UPPER
value|0x01
end_define

begin_define
define|#
directive|define
name|D_LOWER
value|0x02
end_define

begin_define
define|#
directive|define
name|D_DIGIT
value|0x04
end_define

begin_define
define|#
directive|define
name|D_SPACE
value|0x08
end_define

begin_define
define|#
directive|define
name|D_PUNCT
value|0x10
end_define

begin_define
define|#
directive|define
name|D_PRINT
value|0x20
end_define

begin_define
define|#
directive|define
name|Disalpha
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&(D_UPPER|D_LOWER))
end_define

begin_define
define|#
directive|define
name|Disupper
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_UPPER)
end_define

begin_define
define|#
directive|define
name|Dislower
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_LOWER)
end_define

begin_define
define|#
directive|define
name|Disdigit
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_DIGIT)
end_define

begin_define
define|#
directive|define
name|Disalnum
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&(D_UPPER|D_LOWER|D_DIGIT))
end_define

begin_define
define|#
directive|define
name|Disspace
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_SPACE)
end_define

begin_comment
comment|/* blank or null */
end_comment

begin_define
define|#
directive|define
name|Dispunct
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_PUNCT)
end_define

begin_define
define|#
directive|define
name|Disprint
parameter_list|(
name|c
parameter_list|)
value|(dctype[(c)]&D_PRINT)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|dctype
index|[
literal|192
index|]
decl_stmt|;
end_decl_stmt

end_unit

