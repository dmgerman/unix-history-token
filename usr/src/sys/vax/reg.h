begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)reg.h	7.2 (Berkeley) 1/13/87  */
end_comment

begin_comment
comment|/*  * Location of the users' stored  * registers relative to R0.  * Usage is u.u_ar0[XX].  */
end_comment

begin_define
define|#
directive|define
name|R0
value|(-18)
end_define

begin_define
define|#
directive|define
name|R1
value|(-17)
end_define

begin_define
define|#
directive|define
name|R2
value|(-16)
end_define

begin_define
define|#
directive|define
name|R3
value|(-15)
end_define

begin_define
define|#
directive|define
name|R4
value|(-14)
end_define

begin_define
define|#
directive|define
name|R5
value|(-13)
end_define

begin_define
define|#
directive|define
name|R6
value|(-12)
end_define

begin_define
define|#
directive|define
name|R7
value|(-11)
end_define

begin_define
define|#
directive|define
name|R8
value|(-10)
end_define

begin_define
define|#
directive|define
name|R9
value|(-9)
end_define

begin_define
define|#
directive|define
name|R10
value|(-8)
end_define

begin_define
define|#
directive|define
name|R11
value|(-7)
end_define

begin_define
define|#
directive|define
name|R12
value|(-21)
end_define

begin_define
define|#
directive|define
name|R13
value|(-20)
end_define

begin_define
define|#
directive|define
name|AP
value|(-21)
end_define

begin_define
define|#
directive|define
name|FP
value|(-20)
end_define

begin_define
define|#
directive|define
name|SP
value|(-5)
end_define

begin_define
define|#
directive|define
name|PS
value|(-1)
end_define

begin_define
define|#
directive|define
name|PC
value|(-2)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPCREG
end_ifdef

begin_define
define|#
directive|define
name|NIPCREG
value|16
end_define

begin_decl_stmt
name|int
name|ipcreg
index|[
name|NIPCREG
index|]
init|=
block|{
name|R0
block|,
name|R1
block|,
name|R2
block|,
name|R3
block|,
name|R4
block|,
name|R5
block|,
name|R6
block|,
name|R7
block|,
name|R8
block|,
name|R9
block|,
name|R10
block|,
name|R11
block|,
name|AP
block|,
name|FP
block|,
name|SP
block|,
name|PC
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

