begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)pstab.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_comment
comment|/*      *	subtypes within the stab type N_PC      *      *	subtypes N_PSO and N_PSOL are	.stabs	name,N_PC,0,subtype,checksum      *	others subtypes are		.stabs	name,N_PC,0,subtype,line      */
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

begin_define
define|#
directive|define
name|N_PLDATA
value|0xb
end_define

begin_comment
comment|/* library variable */
end_comment

begin_define
define|#
directive|define
name|N_PLTEXT
value|0xc
end_define

begin_comment
comment|/* library routine */
end_comment

begin_comment
comment|/*      *	checksums are used to check if included files have changed.      *	we also use them to check that .o files are up to date with      *	the libraries.      *	if a checksum is less than the flag checksum,      *	then the checksum (and therefore the .o file) is out of date.      *	if a checksum is equal to the flag checksum,      *	then no furthur checking of the checksum is done.      *	this is for the 2nd and subsequent times a file is stabed.      *	to declare a flag day, increment this value. (also be sure       *  to update this value in ../utilities/externs.awk)      */
end_comment

begin_define
define|#
directive|define
name|N_FLAGCHECKSUM
value|1
end_define

end_unit

