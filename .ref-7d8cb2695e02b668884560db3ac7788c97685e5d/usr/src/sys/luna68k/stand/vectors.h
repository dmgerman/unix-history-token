begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)vectors.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* vectors.h */
end_comment

begin_comment
comment|/* by A.Fujita, Nov-18-1991 */
end_comment

begin_define
define|#
directive|define
name|NVECTBL
value|0x400
end_define

begin_comment
comment|/* size of vector table */
end_comment

begin_define
define|#
directive|define
name|ILLGINST
value|0x010
end_define

begin_comment
comment|/* Illegal Instruction */
end_comment

begin_define
define|#
directive|define
name|TRACEVEC
value|0x024
end_define

begin_comment
comment|/* Trace Vector offset */
end_comment

begin_define
define|#
directive|define
name|NMIVEC
value|0x07c
end_define

begin_comment
comment|/* Level 7 Interrupt Auto Vector (NMI) offset */
end_comment

begin_define
define|#
directive|define
name|EVTRAPF
value|0x0bc
end_define

begin_comment
comment|/* Trap #15 Instraction Vector */
end_comment

end_unit

