begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stab.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The following are symbols used by various debuggers and by the Pascal  * compiler.  Each of them must have one (or more) of the bits defined by  * the N_STAB mask set.  */
end_comment

begin_define
define|#
directive|define
name|N_GSYM
value|0x20
end_define

begin_comment
comment|/* global symbol */
end_comment

begin_define
define|#
directive|define
name|N_FNAME
value|0x22
end_define

begin_comment
comment|/* F77 function name */
end_comment

begin_define
define|#
directive|define
name|N_FUN
value|0x24
end_define

begin_comment
comment|/* procedure name */
end_comment

begin_define
define|#
directive|define
name|N_STSYM
value|0x26
end_define

begin_comment
comment|/* data segment variable */
end_comment

begin_define
define|#
directive|define
name|N_LCSYM
value|0x28
end_define

begin_comment
comment|/* bss segment variable */
end_comment

begin_define
define|#
directive|define
name|N_MAIN
value|0x2a
end_define

begin_comment
comment|/* main function name */
end_comment

begin_define
define|#
directive|define
name|N_PC
value|0x30
end_define

begin_comment
comment|/* global Pascal symbol */
end_comment

begin_define
define|#
directive|define
name|N_RSYM
value|0x40
end_define

begin_comment
comment|/* register variable */
end_comment

begin_define
define|#
directive|define
name|N_SLINE
value|0x44
end_define

begin_comment
comment|/* text segment line number */
end_comment

begin_define
define|#
directive|define
name|N_DSLINE
value|0x46
end_define

begin_comment
comment|/* data segment line number */
end_comment

begin_define
define|#
directive|define
name|N_BSLINE
value|0x48
end_define

begin_comment
comment|/* bss segment line number */
end_comment

begin_define
define|#
directive|define
name|N_SSYM
value|0x60
end_define

begin_comment
comment|/* structure/union element */
end_comment

begin_define
define|#
directive|define
name|N_SO
value|0x64
end_define

begin_comment
comment|/* main source file name */
end_comment

begin_define
define|#
directive|define
name|N_LSYM
value|0x80
end_define

begin_comment
comment|/* stack variable */
end_comment

begin_define
define|#
directive|define
name|N_BINCL
value|0x82
end_define

begin_comment
comment|/* include file beginning */
end_comment

begin_define
define|#
directive|define
name|N_SOL
value|0x84
end_define

begin_comment
comment|/* included source file name */
end_comment

begin_define
define|#
directive|define
name|N_PSYM
value|0xa0
end_define

begin_comment
comment|/* parameter variable */
end_comment

begin_define
define|#
directive|define
name|N_EINCL
value|0xa2
end_define

begin_comment
comment|/* include file end */
end_comment

begin_define
define|#
directive|define
name|N_ENTRY
value|0xa4
end_define

begin_comment
comment|/* alternate entry point */
end_comment

begin_define
define|#
directive|define
name|N_LBRAC
value|0xc0
end_define

begin_comment
comment|/* left bracket */
end_comment

begin_define
define|#
directive|define
name|N_EXCL
value|0xc2
end_define

begin_comment
comment|/* deleted include file */
end_comment

begin_define
define|#
directive|define
name|N_RBRAC
value|0xe0
end_define

begin_comment
comment|/* right bracket */
end_comment

begin_define
define|#
directive|define
name|N_BCOMM
value|0xe2
end_define

begin_comment
comment|/* begin common */
end_comment

begin_define
define|#
directive|define
name|N_ECOMM
value|0xe4
end_define

begin_comment
comment|/* end common */
end_comment

begin_define
define|#
directive|define
name|N_ECOML
value|0xe8
end_define

begin_comment
comment|/* end common (local name) */
end_comment

begin_define
define|#
directive|define
name|N_LENG
value|0xfe
end_define

begin_comment
comment|/* length of preceding entry */
end_comment

end_unit

