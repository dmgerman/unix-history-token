begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ /* From: NetBSD: elf_machdep.h,v 1.3 1997/04/06 08:47:24 cgd Exp */
end_comment

begin_define
define|#
directive|define
name|ELF32_MACHDEP_ENDIANNESS
value|XXX
end_define

begin_comment
comment|/* break compilation */
end_comment

begin_define
define|#
directive|define
name|ELF32_MACHDEP_ID_CASES
end_define

begin_comment
unit|\
comment|/* no 32-bit ELF machine types supported */
end_comment

begin_define
define|#
directive|define
name|ELF64_MACHDEP_ENDIANNESS
value|Elf_ed_2lsb
end_define

begin_define
define|#
directive|define
name|ELF64_MACHDEP_ID_CASES
define|\
value|case Elf_em_alpha:					\ 			break;
end_define

begin_comment
comment|/*  * Alpha Relocation Types  */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_NONE
value|0
end_define

begin_comment
comment|/* No reloc */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_REFLONG
value|1
end_define

begin_comment
comment|/* Direct 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_REFQUAD
value|2
end_define

begin_comment
comment|/* Direct 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPREL32
value|3
end_define

begin_comment
comment|/* GP relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_LITERAL
value|4
end_define

begin_comment
comment|/* GP relative 16 bit w/optimization */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_LITUSE
value|5
end_define

begin_comment
comment|/* Optimization hint for LITERAL */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPDISP
value|6
end_define

begin_comment
comment|/* Add displacement to GP */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_BRADDR
value|7
end_define

begin_comment
comment|/* PC+4 relative 23 bit shifted */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_HINT
value|8
end_define

begin_comment
comment|/* PC+4 relative 16 bit shifted */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL16
value|9
end_define

begin_comment
comment|/* PC relative 16 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL32
value|10
end_define

begin_comment
comment|/* PC relative 32 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_SREL64
value|11
end_define

begin_comment
comment|/* PC relative 64 bit */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PUSH
value|12
end_define

begin_comment
comment|/* OP stack push */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_STORE
value|13
end_define

begin_comment
comment|/* OP stack pop and store */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PSUB
value|14
end_define

begin_comment
comment|/* OP stack subtract */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_OP_PRSHIFT
value|15
end_define

begin_comment
comment|/* OP stack right shift */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GPVALUE
value|16
end_define

begin_define
define|#
directive|define
name|R_ALPHA_GPRELHIGH
value|17
end_define

begin_define
define|#
directive|define
name|R_ALPHA_GPRELLOW
value|18
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_GP_16
value|19
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_GP_HI32
value|20
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_SCN_HI32
value|21
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_BR_HI32
value|22
end_define

begin_define
define|#
directive|define
name|R_ALPHA_IMMED_LO32
value|23
end_define

begin_define
define|#
directive|define
name|R_ALPHA_COPY
value|24
end_define

begin_comment
comment|/* Copy symbol at runtime */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_GLOB_DAT
value|25
end_define

begin_comment
comment|/* Create GOT entry */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_JMP_SLOT
value|26
end_define

begin_comment
comment|/* Create PLT entry */
end_comment

begin_define
define|#
directive|define
name|R_ALPHA_RELATIVE
value|27
end_define

begin_comment
comment|/* Adjust by program base */
end_comment

begin_define
define|#
directive|define
name|R_TYPE
parameter_list|(
name|name
parameter_list|)
value|__CONCAT(R_ALPHA_,name)
end_define

end_unit

