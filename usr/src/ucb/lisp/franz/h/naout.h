begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:58:59 1983 by jkf]-  * 	naout.h				$Locker:  $  * executable file format   *  * $Header: /na/franz/franz/h/naout.h,v 1.1 83/01/29 14:07:06 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/* u_* types come from<sys/types.h> */
end_comment

begin_comment
comment|/* PAGSIZ comes from<pagsiz.h> */
end_comment

begin_comment
comment|/*  * Header prepended to each a.out file.  */
end_comment

begin_struct
struct|struct
name|exec
block|{
name|long
name|a_magic
decl_stmt|;
comment|/* magic number */
name|u_long
name|a_text
decl_stmt|;
comment|/* size of text segment */
name|u_long
name|a_data
decl_stmt|;
comment|/* size of initialized data */
name|u_long
name|a_bss
decl_stmt|;
comment|/* size of uninitialized data */
name|u_long
name|a_syms
decl_stmt|;
comment|/* size of symbol table */
name|u_long
name|a_entry
decl_stmt|;
comment|/* entry point */
name|u_long
name|a_trsize
decl_stmt|;
comment|/* size of text relocation */
name|u_long
name|a_drsize
decl_stmt|;
comment|/* size of data relocation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OMAGIC
value|0407
end_define

begin_comment
comment|/* old impure format */
end_comment

begin_define
define|#
directive|define
name|NMAGIC
value|0410
end_define

begin_comment
comment|/* read-only text */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC
value|0413
end_define

begin_comment
comment|/* demand load format */
end_comment

begin_comment
comment|/*  * Macros which take exec structures as arguments and tell whether  * the file has a reasonable magic number or offsets to text|symbols|strings.  */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x).a_magic)!=OMAGIC&& ((x).a_magic)!=NMAGIC&& ((x).a_magic)!=ZMAGIC)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|((x).a_magic==ZMAGIC ? PAGSIZ : sizeof (struct exec))
end_define

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_TXTOFF(x) + (x).a_text+(x).a_data + (x).a_trsize+(x).a_drsize)
end_define

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_SYMOFF(x) + (x).a_syms)
end_define

begin_comment
comment|/*  * Format of a relocation datum.  */
end_comment

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* address which is relocated */
name|u_int
name|r_symbolnum
range|:
literal|24
decl_stmt|,
comment|/* local symbol ordinal */
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* was relocated pc relative already */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* 0=byte, 1=word, 2=long */
name|r_extern
range|:
literal|1
decl_stmt|,
comment|/* does not include value of sym referenced */
range|:
literal|4
decl_stmt|;
comment|/* nothing, yet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Format of a symbol table entry; this file is included by<a.out.h>  * and should be used if you aren't interested the a.out header  * or relocation information.  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
union|union
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* for use when in-core */
name|long
name|n_strx
decl_stmt|;
comment|/* index into file string table */
block|}
name|n_un
union|;
name|u_char
name|n_type
decl_stmt|;
comment|/* type flag, i.e. N_TEXT etc; see below */
name|char
name|n_other
decl_stmt|;
comment|/* unused */
name|short
name|n_desc
decl_stmt|;
comment|/* see<stab.h> */
name|u_long
name|n_value
decl_stmt|;
comment|/* value of this symbol (or sdb offset) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_hash
value|n_desc
end_define

begin_comment
comment|/* used internally by ld */
end_comment

begin_comment
comment|/*  * Simple values for n_type.  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0x0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|0x2
end_define

begin_comment
comment|/* absolute */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|0x4
end_define

begin_comment
comment|/* text */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|0x6
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|0x8
end_define

begin_comment
comment|/* bss */
end_comment

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* common (internal to ld) */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1f
end_define

begin_comment
comment|/* file name symbol */
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
name|N_TYPE
value|0x1e
end_define

begin_comment
comment|/* mask for all the type bits */
end_comment

begin_comment
comment|/*  * Sdb entries have some of the N_STAB bits set.  * These are given in<stab.h>  */
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0xe0
end_define

begin_comment
comment|/* if any of these bits set, a SDB entry */
end_comment

begin_comment
comment|/*  * Format for namelist values.  */
end_comment

begin_define
define|#
directive|define
name|N_FORMAT
value|"%08x"
end_define

end_unit

