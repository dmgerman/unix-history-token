begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: reg.h 1.1 90/07/09$  *  *	@(#)reg.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Location of the users' stored  * registers relative to ZERO.  * Usage is p->p_regs[XX].  */
end_comment

begin_define
define|#
directive|define
name|ZERO
value|0
end_define

begin_define
define|#
directive|define
name|AST
value|1
end_define

begin_define
define|#
directive|define
name|V0
value|2
end_define

begin_define
define|#
directive|define
name|V1
value|3
end_define

begin_define
define|#
directive|define
name|A0
value|4
end_define

begin_define
define|#
directive|define
name|A1
value|5
end_define

begin_define
define|#
directive|define
name|A2
value|6
end_define

begin_define
define|#
directive|define
name|A3
value|7
end_define

begin_define
define|#
directive|define
name|T0
value|8
end_define

begin_define
define|#
directive|define
name|T1
value|9
end_define

begin_define
define|#
directive|define
name|T2
value|10
end_define

begin_define
define|#
directive|define
name|T3
value|11
end_define

begin_define
define|#
directive|define
name|T4
value|12
end_define

begin_define
define|#
directive|define
name|T5
value|13
end_define

begin_define
define|#
directive|define
name|T6
value|14
end_define

begin_define
define|#
directive|define
name|T7
value|15
end_define

begin_define
define|#
directive|define
name|S0
value|16
end_define

begin_define
define|#
directive|define
name|S1
value|17
end_define

begin_define
define|#
directive|define
name|S2
value|18
end_define

begin_define
define|#
directive|define
name|S3
value|19
end_define

begin_define
define|#
directive|define
name|S4
value|20
end_define

begin_define
define|#
directive|define
name|S5
value|21
end_define

begin_define
define|#
directive|define
name|S6
value|22
end_define

begin_define
define|#
directive|define
name|S7
value|23
end_define

begin_define
define|#
directive|define
name|T8
value|24
end_define

begin_define
define|#
directive|define
name|T9
value|25
end_define

begin_define
define|#
directive|define
name|K0
value|26
end_define

begin_define
define|#
directive|define
name|K1
value|27
end_define

begin_define
define|#
directive|define
name|GP
value|28
end_define

begin_define
define|#
directive|define
name|SP
value|29
end_define

begin_define
define|#
directive|define
name|S8
value|30
end_define

begin_define
define|#
directive|define
name|RA
value|31
end_define

begin_define
define|#
directive|define
name|MULLO
value|32
end_define

begin_define
define|#
directive|define
name|MULHI
value|33
end_define

begin_define
define|#
directive|define
name|PC
value|34
end_define

begin_define
define|#
directive|define
name|SR
value|35
end_define

begin_define
define|#
directive|define
name|PS
value|35
end_define

begin_comment
comment|/* alias for SR */
end_comment

begin_define
define|#
directive|define
name|F0
value|36
end_define

begin_define
define|#
directive|define
name|F1
value|37
end_define

begin_define
define|#
directive|define
name|F2
value|38
end_define

begin_define
define|#
directive|define
name|F3
value|39
end_define

begin_define
define|#
directive|define
name|F4
value|40
end_define

begin_define
define|#
directive|define
name|F5
value|41
end_define

begin_define
define|#
directive|define
name|F6
value|42
end_define

begin_define
define|#
directive|define
name|F7
value|43
end_define

begin_define
define|#
directive|define
name|F8
value|44
end_define

begin_define
define|#
directive|define
name|F9
value|45
end_define

begin_define
define|#
directive|define
name|F10
value|46
end_define

begin_define
define|#
directive|define
name|F11
value|47
end_define

begin_define
define|#
directive|define
name|F12
value|48
end_define

begin_define
define|#
directive|define
name|F13
value|49
end_define

begin_define
define|#
directive|define
name|F14
value|50
end_define

begin_define
define|#
directive|define
name|F15
value|51
end_define

begin_define
define|#
directive|define
name|F16
value|52
end_define

begin_define
define|#
directive|define
name|F17
value|53
end_define

begin_define
define|#
directive|define
name|F18
value|54
end_define

begin_define
define|#
directive|define
name|F19
value|55
end_define

begin_define
define|#
directive|define
name|F20
value|56
end_define

begin_define
define|#
directive|define
name|F21
value|57
end_define

begin_define
define|#
directive|define
name|F22
value|58
end_define

begin_define
define|#
directive|define
name|F23
value|59
end_define

begin_define
define|#
directive|define
name|F24
value|60
end_define

begin_define
define|#
directive|define
name|F25
value|61
end_define

begin_define
define|#
directive|define
name|F26
value|62
end_define

begin_define
define|#
directive|define
name|F27
value|63
end_define

begin_define
define|#
directive|define
name|F28
value|64
end_define

begin_define
define|#
directive|define
name|F29
value|65
end_define

begin_define
define|#
directive|define
name|F30
value|66
end_define

begin_define
define|#
directive|define
name|F31
value|67
end_define

begin_define
define|#
directive|define
name|FSR
value|68
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
value|69
end_define

begin_decl_stmt
name|int
name|ipcreg
index|[
name|NIPCREG
index|]
init|=
block|{
name|ZERO
block|,
name|AST
block|,
name|V0
block|,
name|V1
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|T0
block|,
name|T1
block|,
name|T2
block|,
name|T3
block|,
name|T4
block|,
name|T5
block|,
name|T6
block|,
name|T7
block|,
name|S0
block|,
name|S1
block|,
name|S2
block|,
name|S3
block|,
name|S4
block|,
name|S5
block|,
name|S6
block|,
name|S7
block|,
name|T8
block|,
name|T9
block|,
name|K0
block|,
name|K1
block|,
name|GP
block|,
name|SP
block|,
name|S8
block|,
name|RA
block|,
name|MULLO
block|,
name|MULHI
block|,
name|PC
block|,
name|F0
block|,
name|F1
block|,
name|F2
block|,
name|F3
block|,
name|F4
block|,
name|F5
block|,
name|F6
block|,
name|F7
block|,
name|F8
block|,
name|F9
block|,
name|F10
block|,
name|F11
block|,
name|F12
block|,
name|F13
block|,
name|F14
block|,
name|F15
block|,
name|F16
block|,
name|F17
block|,
name|F18
block|,
name|F19
block|,
name|F20
block|,
name|F21
block|,
name|F22
block|,
name|F23
block|,
name|F24
block|,
name|F25
block|,
name|F26
block|,
name|F27
block|,
name|F28
block|,
name|F29
block|,
name|F30
block|,
name|F31
block|,
name|FSR
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LANGUAGE_C
end_ifdef

begin_comment
comment|/*  * Register set accessible via /proc/$pid/reg  */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|int
name|r_regs
index|[
literal|69
index|]
decl_stmt|;
comment|/* numbered as above */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LANGUAGE_C */
end_comment

end_unit

