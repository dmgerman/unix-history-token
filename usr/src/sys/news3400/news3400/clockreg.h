begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department, Ralph Campbell, Sony Corp. and Kazumasa  * Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: clockreg.h 1.14 91/01/18$  *  *	@(#)clockreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|SECMIN
value|((unsigned)60)
end_define

begin_comment
comment|/* seconds per minute */
end_comment

begin_define
define|#
directive|define
name|SECHOUR
value|((unsigned)(60*SECMIN))
end_define

begin_comment
comment|/* seconds per hour */
end_comment

begin_define
define|#
directive|define
name|SECDAY
value|((unsigned)(24*SECHOUR))
end_define

begin_comment
comment|/* seconds per day */
end_comment

begin_define
define|#
directive|define
name|SECYR
value|((unsigned)(365*SECDAY))
end_define

begin_comment
comment|/* seconds per common year */
end_comment

begin_define
define|#
directive|define
name|YRREF
value|1970
end_define

begin_define
define|#
directive|define
name|LEAPYEAR
parameter_list|(
name|year
parameter_list|)
value|(((year) % 4) == 0)
end_define

begin_define
define|#
directive|define
name|MK48T02
end_define

begin_define
define|#
directive|define
name|SET_CLOCK
value|0x80
end_define

begin_define
define|#
directive|define
name|READ_CLOCK
value|0x40
end_define

end_unit

