begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: conf-bsdapollo.h,v 4.1 89/01/24 14:26:22 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|BSDUNIX
end_define

begin_define
define|#
directive|define
name|BITS32
end_define

begin_define
define|#
directive|define
name|BIG
end_define

begin_define
define|#
directive|define
name|MSBFIRST
end_define

begin_define
define|#
directive|define
name|DES_SHIFT_SHIFT
end_define

begin_comment
comment|/*  * As of SR10, the C compiler claims to be __STDC__, but doesn't support  * const.  Sigh.  */
end_comment

begin_define
define|#
directive|define
name|const
end_define

end_unit

