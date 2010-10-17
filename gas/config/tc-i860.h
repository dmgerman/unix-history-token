begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i860.h -- Header file for the i860.    Copyright 1991, 1992, 1995, 1998, 2000, 2001, 2002    Free Software Foundation, Inc.     Brought back from the dead and completely reworked    by Jason Eckhardt<jle@cygnus.com>.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with GAS; see the file COPYING.  If not, write to the Free Software    Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I860
end_ifndef

begin_define
define|#
directive|define
name|TC_I860
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|i860 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|i860_fix_info
block|{
name|OP_NONE
init|=
literal|0x00000
block|,
name|OP_IMM_U5
init|=
literal|0x00001
block|,
name|OP_IMM_S16
init|=
literal|0x00002
block|,
name|OP_IMM_U16
init|=
literal|0x00004
block|,
name|OP_IMM_SPLIT16
init|=
literal|0x00008
block|,
name|OP_IMM_BR26
init|=
literal|0x00010
block|,
name|OP_IMM_BR16
init|=
literal|0x00020
block|,
name|OP_ENCODE1
init|=
literal|0x00040
block|,
name|OP_ENCODE2
init|=
literal|0x00080
block|,
name|OP_ENCODE3
init|=
literal|0x00100
block|,
name|OP_SEL_HA
init|=
literal|0x00200
block|,
name|OP_SEL_H
init|=
literal|0x00400
block|,
name|OP_SEL_L
init|=
literal|0x00800
block|,
name|OP_SEL_GOT
init|=
literal|0x01000
block|,
name|OP_SEL_GOTOFF
init|=
literal|0x02000
block|,
name|OP_SEL_PLT
init|=
literal|0x04000
block|,
name|OP_ALIGN2
init|=
literal|0x08000
block|,
name|OP_ALIGN4
init|=
literal|0x10000
block|,
name|OP_ALIGN8
init|=
literal|0x20000
block|,
name|OP_ALIGN16
init|=
literal|0x40000
block|}
enum|;
end_enum

begin_comment
comment|/* Set the endianness we are using.  Default to little endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTES_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Whether or not the target is big endian.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BFD target architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_i860
end_define

begin_comment
comment|/* The target BFD format.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "elf32-i860" : "elf32-i860-little")
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|i860 GAS currently supports only the ELF object format
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"GAS for i860"
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|as_fatal (_("i860_convert_frag\n"));
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_comment
comment|/* Bits for post-processing of a user defined label to check if    it has a double colon (Intel syntax only).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i860_check_label
parameter_list|(
name|symbolS
modifier|*
name|labelsym
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_check_label
parameter_list|(
name|ls
parameter_list|)
value|i860_check_label (ls)
end_define

begin_comment
comment|/* Bits for filling in rs_align_code fragments with NOPs.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i860_handle_align
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragp
parameter_list|)
value|i860_handle_align (fragp)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4 + 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I860 */
end_comment

end_unit

