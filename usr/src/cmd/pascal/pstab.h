begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	static	char sccsid[] = "@(#)pstab.h 1.2 9/9/80"; */
end_comment

begin_comment
comment|/*      *	subtypes within the above type      *	subtypes N_PSO and N_PSOL are	.stabs	name,,0,subtype,0      *	others subtypes are		.stabs	name,,0,subtype,line      */
end_comment

begin_define
define|#
directive|define
name|N_PSO
value|0x1
end_define

begin_comment
comment|/* source file name */
end_comment

begin_define
define|#
directive|define
name|N_PSOL
value|0x2
end_define

begin_comment
comment|/* include file name */
end_comment

begin_define
define|#
directive|define
name|N_PGLABEL
value|0x3
end_define

begin_comment
comment|/* global label */
end_comment

begin_define
define|#
directive|define
name|N_PGCONST
value|0x4
end_define

begin_comment
comment|/* global constant */
end_comment

begin_define
define|#
directive|define
name|N_PGTYPE
value|0x5
end_define

begin_comment
comment|/* global type */
end_comment

begin_define
define|#
directive|define
name|N_PGVAR
value|0x6
end_define

begin_comment
comment|/* global variable */
end_comment

begin_define
define|#
directive|define
name|N_PGFUNC
value|0x7
end_define

begin_comment
comment|/* global function */
end_comment

begin_define
define|#
directive|define
name|N_PGPROC
value|0x8
end_define

begin_comment
comment|/* global procedure */
end_comment

begin_define
define|#
directive|define
name|N_PEFUNC
value|0x9
end_define

begin_comment
comment|/* external function */
end_comment

begin_define
define|#
directive|define
name|N_PEPROC
value|0xa
end_define

begin_comment
comment|/* external procedure */
end_comment

end_unit

