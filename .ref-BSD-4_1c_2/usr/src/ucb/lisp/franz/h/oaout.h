begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 14:00:59 1983 by jkf]-  * 	oaout.h			$Locker:  $  * old a.out format  *  * $Header: /na/franz/franz/h/oaout.h,v 1.1 83/01/29 14:07:19 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/*  * Format of an a.out header  */
end_comment

begin_struct
struct|struct
name|exec
block|{
comment|/* a.out header */
name|int
name|a_magic
decl_stmt|;
comment|/* magic number */
name|unsigned
name|a_text
decl_stmt|;
comment|/* size of text segment */
name|unsigned
name|a_data
decl_stmt|;
comment|/* size of initialized data */
name|unsigned
name|a_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|unsigned
name|a_syms
decl_stmt|;
comment|/* size of symbol table */
name|unsigned
name|a_entry
decl_stmt|;
comment|/* entry point */
name|unsigned
name|a_trsize
decl_stmt|;
comment|/* size of text relocation */
name|unsigned
name|a_drsize
decl_stmt|;
comment|/* size of data relocation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|A_MAGIC1
value|0407
end_define

begin_comment
comment|/* normal */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC2
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC3
value|0411
end_define

begin_comment
comment|/* separated I&D (not on VAX) */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC4
value|0405
end_define

begin_comment
comment|/* overlay */
end_comment

begin_define
define|#
directive|define
name|A_MAGIC5
value|0413
end_define

begin_comment
comment|/* demand page read-only text */
end_comment

begin_struct
struct|struct
name|relocation_info
block|{
name|long
name|r_address
decl_stmt|;
comment|/* relative to current segment */
name|long
name|r_symbolnum
range|:
literal|24
decl_stmt|,
comment|/* if extern then symbol table */
comment|/* ordinal (0, 1, 2, ...) else */
comment|/* segment number (same as symbol types) */
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* if so, segment offset has already */
comment|/* been subtracted */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* 0=byte, 1=word, 2=long */
name|r_extern
range|:
literal|1
decl_stmt|,
comment|/* does not include value */
comment|/* of symbol referenced */
name|r_offset
range|:
literal|1
decl_stmt|,
comment|/* already includes origin */
comment|/* of this segment (?) */
name|r_pad
range|:
literal|3
decl_stmt|;
comment|/* nothing, yet */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NCPS
end_ifndef

begin_define
define|#
directive|define
name|NCPS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|nlist
block|{
comment|/* symbol table entry */
name|char
name|n_name
index|[
name|NCPS
index|]
decl_stmt|;
comment|/* symbol name */
name|char
name|n_type
decl_stmt|;
comment|/* type flag */
name|char
name|n_other
decl_stmt|;
name|short
name|n_desc
decl_stmt|;
name|unsigned
name|n_value
decl_stmt|;
comment|/* value */
block|}
struct|;
end_struct

begin_comment
comment|/* values for type flag */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|02
end_define

begin_comment
comment|/* absolute */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|04
end_define

begin_comment
comment|/* text */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|06
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|08
end_define

begin_define
define|#
directive|define
name|N_TYPE
value|037
end_define

begin_define
define|#
directive|define
name|N_FN
value|037
end_define

begin_comment
comment|/* file name symbol */
end_comment

begin_define
define|#
directive|define
name|N_GSYM
value|0040
end_define

begin_comment
comment|/* global sym: name,,type,0 */
end_comment

begin_define
define|#
directive|define
name|N_FNAME
value|0042
end_define

begin_comment
comment|/* procedure name (f77 kludge): name,,,0 */
end_comment

begin_define
define|#
directive|define
name|N_FUN
value|0044
end_define

begin_comment
comment|/* procedure: name,,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_STSYM
value|0046
end_define

begin_comment
comment|/* static symbol: name,,type,address */
end_comment

begin_define
define|#
directive|define
name|N_LCSYM
value|0048
end_define

begin_comment
comment|/* .lcomm symbol: name,,type,address */
end_comment

begin_define
define|#
directive|define
name|N_RSYM
value|0100
end_define

begin_comment
comment|/* register sym: name,,register,offset */
end_comment

begin_define
define|#
directive|define
name|N_SLINE
value|0104
end_define

begin_comment
comment|/* src line: ,,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_SSYM
value|0140
end_define

begin_comment
comment|/* structure elt: name,,type,struct_offset */
end_comment

begin_define
define|#
directive|define
name|N_SO
value|0144
end_define

begin_comment
comment|/* source file name: name,,,address */
end_comment

begin_define
define|#
directive|define
name|N_LSYM
value|0200
end_define

begin_comment
comment|/* local sym: name,,type,offset */
end_comment

begin_define
define|#
directive|define
name|N_SOL
value|0204
end_define

begin_comment
comment|/* #line source filename: name,,,address */
end_comment

begin_define
define|#
directive|define
name|N_PSYM
value|0240
end_define

begin_comment
comment|/* parameter: name,,type,offset */
end_comment

begin_define
define|#
directive|define
name|N_ENTRY
value|0244
end_define

begin_comment
comment|/* alternate entry: name,,linenumber,address */
end_comment

begin_define
define|#
directive|define
name|N_LBRAC
value|0300
end_define

begin_comment
comment|/* left bracket: ,,nesting level,address */
end_comment

begin_define
define|#
directive|define
name|N_RBRAC
value|0340
end_define

begin_comment
comment|/* right bracket: ,,nesting level,address */
end_comment

begin_define
define|#
directive|define
name|N_BCOMM
value|0342
end_define

begin_comment
comment|/* begin common: name,,, */
end_comment

begin_define
define|#
directive|define
name|N_ECOMM
value|0344
end_define

begin_comment
comment|/* end common: name,,, */
end_comment

begin_define
define|#
directive|define
name|N_ECOML
value|0348
end_define

begin_comment
comment|/* end common (local name): ,,,address */
end_comment

begin_define
define|#
directive|define
name|N_LENG
value|0376
end_define

begin_comment
comment|/* second stab entry with length information */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|01
end_define

begin_comment
comment|/* external bit, or'ed in */
end_comment

begin_define
define|#
directive|define
name|FORMAT
value|"%08x"
end_define

begin_define
define|#
directive|define
name|STABTYPES
value|0340
end_define

end_unit

