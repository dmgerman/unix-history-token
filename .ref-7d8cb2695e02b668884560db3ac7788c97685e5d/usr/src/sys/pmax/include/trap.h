begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: trap.h 1.1 90/07/09$  *  *	@(#)trap.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Trap codes  * also known in trap.c for name strings  */
end_comment

begin_define
define|#
directive|define
name|T_INT
value|0
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|T_TLB_MOD
value|1
end_define

begin_comment
comment|/* TLB modified fault */
end_comment

begin_define
define|#
directive|define
name|T_TLB_LD_MISS
value|2
end_define

begin_comment
comment|/* TLB miss on load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_TLB_ST_MISS
value|3
end_define

begin_comment
comment|/* TLB miss on a store */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_LD
value|4
end_define

begin_comment
comment|/* Address error on a load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_ST
value|5
end_define

begin_comment
comment|/* Address error on a store */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_IFETCH
value|6
end_define

begin_comment
comment|/* Bus error on an ifetch */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_LD_ST
value|7
end_define

begin_comment
comment|/* Bus error on a load or store */
end_comment

begin_define
define|#
directive|define
name|T_SYSCALL
value|8
end_define

begin_comment
comment|/* System call */
end_comment

begin_define
define|#
directive|define
name|T_BREAK
value|9
end_define

begin_comment
comment|/* Breakpoint */
end_comment

begin_define
define|#
directive|define
name|T_RES_INST
value|10
end_define

begin_comment
comment|/* Reserved instruction exception */
end_comment

begin_define
define|#
directive|define
name|T_COP_UNUSABLE
value|11
end_define

begin_comment
comment|/* Coprocessor unusable */
end_comment

begin_define
define|#
directive|define
name|T_OVFLOW
value|12
end_define

begin_comment
comment|/* Arithmetic overflow */
end_comment

begin_define
define|#
directive|define
name|T_USER
value|0x10
end_define

begin_comment
comment|/* user-mode flag or'ed with type */
end_comment

end_unit

