begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)stab.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_comment
comment|/* IF YOU ADD DEFINITIONS, ADD THEM TO nm.c as well */
end_comment

begin_comment
comment|/*  * This file gives definitions supplementing<a.out.h>  * for permanent symbol table entries.  * These must have one of the N_STAB bits on,  * and are subject to relocation according to the masks in<a.out.h>.  */
end_comment

begin_comment
comment|/*  * for symbolic debugger, sdb(1):  */
end_comment

begin_define
define|#
directive|define
name|N_GSYM
value|0x20
end_define

begin_comment
comment|/* global symbol: name,,0,type,0 */
end_comment

begin_define
define|#
directive|define
name|N_FNAME
value|0x22
end_define

begin_comment
comment|/* procedure name (f77 kludge): name,,0 */
end_comment

begin_define
define|#
directive|define
name|N_FUN
value|0x24
end_define

begin_comment
comment|/* procedure: name,,0,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_STSYM
value|0x26
end_define

begin_comment
comment|/* static symbol: name,,0,type,address */
end_comment

begin_define
define|#
directive|define
name|N_LCSYM
value|0x28
end_define

begin_comment
comment|/* .lcomm symbol: name,,0,type,address */
end_comment

begin_define
define|#
directive|define
name|N_RSYM
value|0x40
end_define

begin_comment
comment|/* register sym: name,,0,type,register */
end_comment

begin_define
define|#
directive|define
name|N_SLINE
value|0x44
end_define

begin_comment
comment|/* src line: 0,,0,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_SSYM
value|0x60
end_define

begin_comment
comment|/* structure elt: name,,0,type,struct_offset */
end_comment

begin_define
define|#
directive|define
name|N_SO
value|0x64
end_define

begin_comment
comment|/* source file name: name,,0,0,address */
end_comment

begin_define
define|#
directive|define
name|N_LSYM
value|0x80
end_define

begin_comment
comment|/* local sym: name,,0,type,offset */
end_comment

begin_define
define|#
directive|define
name|N_SOL
value|0x84
end_define

begin_comment
comment|/* #included file name: name,,0,0,address */
end_comment

begin_define
define|#
directive|define
name|N_PSYM
value|0xa0
end_define

begin_comment
comment|/* parameter: name,,0,type,offset */
end_comment

begin_define
define|#
directive|define
name|N_ENTRY
value|0xa4
end_define

begin_comment
comment|/* alternate entry: name,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_LBRAC
value|0xc0
end_define

begin_comment
comment|/* left bracket: 0,,0,nesting level,address */
end_comment

begin_define
define|#
directive|define
name|N_RBRAC
value|0xe0
end_define

begin_comment
comment|/* right bracket: 0,,0,nesting level,address */
end_comment

begin_define
define|#
directive|define
name|N_BCOMM
value|0xe2
end_define

begin_comment
comment|/* begin common: name,, */
end_comment

begin_define
define|#
directive|define
name|N_ECOMM
value|0xe4
end_define

begin_comment
comment|/* end common: name,, */
end_comment

begin_define
define|#
directive|define
name|N_ECOML
value|0xe8
end_define

begin_comment
comment|/* end common (local name): ,,address */
end_comment

begin_define
define|#
directive|define
name|N_LENG
value|0xfe
end_define

begin_comment
comment|/* second stab entry with length information */
end_comment

begin_comment
comment|/*  * for the berkeley pascal compiler, pc(1):  */
end_comment

begin_define
define|#
directive|define
name|N_PC
value|0x30
end_define

begin_comment
comment|/* global pascal symbol: name,,0,subtype,line */
end_comment

end_unit

