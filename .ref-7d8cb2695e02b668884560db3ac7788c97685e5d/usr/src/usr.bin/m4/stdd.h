begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * %sccs.include.redist.c%  *  *	@(#)stdd.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * standard defines  */
end_comment

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b)? (a): (b))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b)? (a): (b))
end_define

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_comment
comment|/*   * STREQ is an optimised strcmp(a,b)==0   * STREQN is an optimised strncmp(a,b,n)==0; assumes n> 0   */
end_comment

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)[0] == (b)[0]&& strcmp(a, b) == 0)
end_define

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|((a)[0] == (b)[0]&& strncmp(a, b, n) == 0)
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

end_unit

