begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)specialreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * 386 Special registers:  */
end_comment

begin_define
define|#
directive|define
name|CR0_PE
value|0x00000001
end_define

begin_comment
comment|/* Protected mode Enable */
end_comment

begin_define
define|#
directive|define
name|CR0_MP
value|0x00000002
end_define

begin_comment
comment|/* "Math" Present (e.g. npx), wait for it */
end_comment

begin_define
define|#
directive|define
name|CR0_EM
value|0x00000004
end_define

begin_comment
comment|/* EMulate NPX, e.g. trap, don't execute code */
end_comment

begin_define
define|#
directive|define
name|CR0_TS
value|0x00000008
end_define

begin_comment
comment|/* Process has done Task Switch, do NPX save */
end_comment

begin_define
define|#
directive|define
name|CR0_ET
value|0x00000010
end_define

begin_comment
comment|/* 32 bit (if set) vs 16 bit (387 vs 287) */
end_comment

begin_define
define|#
directive|define
name|CR0_PG
value|0x80000000
end_define

begin_comment
comment|/* Paging Enable */
end_comment

end_unit

