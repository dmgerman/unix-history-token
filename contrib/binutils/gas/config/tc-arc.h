begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-arc.h - Macros and type defines for the ARC.    Copyright 1994, 1995, 1997, 2000, 2001 Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_ARC
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_arc
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|'%'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LITTLE_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|LITTLE_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BIG_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|BIG_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* The endianness of the target format may change based on command    line arguments.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|arc_target_format
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFAULT_TARGET_FORMAT
value|"elf32-littlearc"
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|arc_target_format
end_define

begin_define
define|#
directive|define
name|DEFAULT_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"ARC GAS "
end_define

begin_comment
comment|/* The ARC needs to parse reloc specifiers in .word.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|arc_parse_cons_expression
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expressionS
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_PARSE_CONS_EXPRESSION
parameter_list|(
name|EXP
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|arc_parse_cons_expression (EXP, NBYTES)
end_define

begin_decl_stmt
specifier|extern
name|void
name|arc_cons_fix_new
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|WHERE
parameter_list|,
name|NBYTES
parameter_list|,
name|EXP
parameter_list|)
define|\
value|arc_cons_fix_new (FRAG, WHERE, NBYTES, EXP)
end_define

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

end_unit

