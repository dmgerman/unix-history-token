begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)ectype.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_ECTYPE
end_define

begin_define
define|#
directive|define
name|E_UPPER
value|0x01
end_define

begin_define
define|#
directive|define
name|E_LOWER
value|0x02
end_define

begin_define
define|#
directive|define
name|E_DIGIT
value|0x04
end_define

begin_define
define|#
directive|define
name|E_SPACE
value|0x08
end_define

begin_define
define|#
directive|define
name|E_PUNCT
value|0x10
end_define

begin_define
define|#
directive|define
name|E_PRINT
value|0x20
end_define

begin_define
define|#
directive|define
name|Eisalpha
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&(E_UPPER|E_LOWER))
end_define

begin_define
define|#
directive|define
name|Eisupper
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_UPPER)
end_define

begin_define
define|#
directive|define
name|Eislower
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_LOWER)
end_define

begin_define
define|#
directive|define
name|Eisdigit
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_DIGIT)
end_define

begin_define
define|#
directive|define
name|Eisalnum
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&(E_UPPER|E_LOWER|E_DIGIT))
end_define

begin_define
define|#
directive|define
name|Eisspace
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_SPACE)
end_define

begin_comment
comment|/* blank or null */
end_comment

begin_define
define|#
directive|define
name|Eispunct
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_PUNCT)
end_define

begin_define
define|#
directive|define
name|Eisprint
parameter_list|(
name|c
parameter_list|)
value|(ectype[(c)&0xff]&E_PRINT)
end_define

end_unit

