begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)float.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|FLT_RADIX
value|2
end_define

begin_comment
comment|/* b */
end_comment

begin_define
define|#
directive|define
name|FLT_ROUNDS
value|1
end_define

begin_comment
comment|/* FP addition rounds to nearest */
end_comment

begin_define
define|#
directive|define
name|FLT_MANT_DIG
value|24
end_define

begin_comment
comment|/* p */
end_comment

begin_define
define|#
directive|define
name|FLT_EPSILON
value|1.19209290E-07F
end_define

begin_comment
comment|/* b**(1-p) */
end_comment

begin_define
define|#
directive|define
name|FLT_DIG
value|6
end_define

begin_comment
comment|/* floor((p-1)*log10(b))+(b == 10) */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN_EXP
value|-127
end_define

begin_comment
comment|/* emin */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN
value|2.93873588E-39F
end_define

begin_comment
comment|/* b**(emin-1) */
end_comment

begin_define
define|#
directive|define
name|FLT_MIN_10_EXP
value|-38
end_define

begin_comment
comment|/* ceil(log10(b**(emin-1))) */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX_EXP
value|127
end_define

begin_comment
comment|/* emax */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX
value|1.70141173E+38F
end_define

begin_comment
comment|/* (1-b**(-p))*b**emax */
end_comment

begin_define
define|#
directive|define
name|FLT_MAX_10_EXP
value|38
end_define

begin_comment
comment|/* floor(log10((1-b**(-p))*b**emax)) */
end_comment

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|56
end_define

begin_define
define|#
directive|define
name|DBL_EPSILON
value|2.775557561562891351E-17
end_define

begin_define
define|#
directive|define
name|DBL_DIG
value|16
end_define

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|-127
end_define

begin_define
define|#
directive|define
name|DBL_MIN
value|2.938735877055718770E-39
end_define

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|-38
end_define

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|127
end_define

begin_define
define|#
directive|define
name|DBL_MAX
value|1.701411834604692294E+38
end_define

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|38
end_define

begin_define
define|#
directive|define
name|LDBL_MANT_DIG
value|DBL_MANT_DIG
end_define

begin_define
define|#
directive|define
name|LDBL_EPSILON
value|DBL_EPSILON
end_define

begin_define
define|#
directive|define
name|LDBL_DIG
value|DBL_DIG
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_EXP
value|DBL_MIN_EXP
end_define

begin_define
define|#
directive|define
name|LDBL_MIN
value|DBL_MIN
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_10_EXP
value|DBL_MIN_10_EXP
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_EXP
value|DBL_MAX_EXP
end_define

begin_define
define|#
directive|define
name|LDBL_MAX
value|DBL_MAX
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_10_EXP
value|DBL_MAX_10_EXP
end_define

end_unit

