begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NLM (NetWare Loadable Module) support for BFD.    Copyright (C) 1993 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is part of NLM support for BFD, and contains the portions    that are common to both the internal and external representations. */
end_comment

begin_comment
comment|/* Semi-portable string concatenation in cpp.    The NLM_CAT4 hack is to avoid a problem with some strict ANSI C    preprocessors.  The problem is, "32_" or "64_" are not a valid    preprocessing tokens, and we don't want extra underscores (e.g.,    "nlm_32_").  The XNLM_CAT2 macro will cause the inner NLM_CAT macros    to be evaluated first, producing still-valid pp-tokens.  Then the    final concatenation can be done.  (Sigh.)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SABER
end_ifdef

begin_define
define|#
directive|define
name|NLM_CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|NLM_CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|NLM_CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a##b##c##d
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|NLM_CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|NLM_CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|XNLM_CAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|NLM_CAT(a,b)
end_define

begin_define
define|#
directive|define
name|NLM_CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|XNLM_CAT2(NLM_CAT(a,b),NLM_CAT(c,d))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NLM_CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_define
define|#
directive|define
name|NLM_CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
end_define

begin_define
define|#
directive|define
name|NLM_CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
comment|/**/
value|d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If NLM_ARCH_SIZE is not defined, default to 32.  NLM_ARCH_SIZE is    optionally defined by the application. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NLM_ARCH_SIZE
end_ifndef

begin_define
define|#
directive|define
name|NLM_ARCH_SIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NLM_ARCH_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|NLM_TARGET_LONG_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NLM_TARGET_ADDRESS_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NLM_NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|NLM_CAT4(x,32,_,y)
end_define

begin_define
define|#
directive|define
name|NLM_HIBIT
value|(((bfd_vma) 1)<< 31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NLM_ARCH_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|NLM_TARGET_LONG_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|NLM_TARGET_ADDRESS_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|NLM_NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|NLM_CAT4(x,64,_,y)
end_define

begin_define
define|#
directive|define
name|NLM_HIBIT
value|(((bfd_vma) 1)<< 63)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NlmNAME
parameter_list|(
name|X
parameter_list|)
value|NLM_NAME(Nlm,X)
end_define

begin_define
define|#
directive|define
name|nlmNAME
parameter_list|(
name|X
parameter_list|)
value|NLM_NAME(nlm,X)
end_define

begin_comment
comment|/* Give names to things that should not change. */
end_comment

begin_define
define|#
directive|define
name|NLM_MAX_DESCRIPTION_LENGTH
value|127
end_define

begin_define
define|#
directive|define
name|NLM_MAX_SCREEN_NAME_LENGTH
value|71
end_define

begin_define
define|#
directive|define
name|NLM_MAX_THREAD_NAME_LENGTH
value|71
end_define

begin_define
define|#
directive|define
name|NLM_MAX_COPYRIGHT_MESSAGE_LENGTH
value|255
end_define

begin_define
define|#
directive|define
name|NLM_OTHER_DATA_LENGTH
value|400
end_define

begin_comment
comment|/* FIXME */
end_comment

begin_define
define|#
directive|define
name|NLM_OLD_THREAD_NAME_LENGTH
value|5
end_define

begin_define
define|#
directive|define
name|NLM_SIGNATURE_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|NLM_HEADER_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|NLM_MODULE_NAME_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|NLM_DEFAULT_STACKSIZE
value|(8 * 1024)
end_define

begin_escape
end_escape

begin_comment
comment|/* Alpha information.  This should probably be in a separate Alpha    header file, but it can't go in alpha-ext.h because some of it is    needed by nlmconv.c.  */
end_comment

begin_comment
comment|/* Magic number in Alpha prefix header.  */
end_comment

begin_define
define|#
directive|define
name|NLM32_ALPHA_MAGIC
value|(0x83561840)
end_define

begin_comment
comment|/* The r_type field in an Alpha reloc is one of the following values.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFLONG
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_REFQUAD
value|2
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPREL32
value|3
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LITERAL
value|4
end_define

begin_define
define|#
directive|define
name|ALPHA_R_LITUSE
value|5
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPDISP
value|6
end_define

begin_define
define|#
directive|define
name|ALPHA_R_BRADDR
value|7
end_define

begin_define
define|#
directive|define
name|ALPHA_R_HINT
value|8
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL16
value|9
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL32
value|10
end_define

begin_define
define|#
directive|define
name|ALPHA_R_SREL64
value|11
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PUSH
value|12
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_STORE
value|13
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PSUB
value|14
end_define

begin_define
define|#
directive|define
name|ALPHA_R_OP_PRSHIFT
value|15
end_define

begin_define
define|#
directive|define
name|ALPHA_R_GPVALUE
value|16
end_define

begin_define
define|#
directive|define
name|ALPHA_R_NW_RELOC
value|250
end_define

begin_comment
comment|/* A local reloc, other than ALPHA_R_GPDISP or ALPHA_R_IGNORE, must be    against one of these symbol indices.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_RELOC_SECTION_TEXT
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_RELOC_SECTION_DATA
value|3
end_define

begin_comment
comment|/* An ALPHA_R_NW_RELOC has one of these values in the size field.  If    it is SETGP, the r_vaddr field holds the GP value to use.  If it is    LITA, the r_vaddr field holds the address of the .lita section and    the r_symndx field holds the size of the .lita section.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_R_NW_RELOC_SETGP
value|1
end_define

begin_define
define|#
directive|define
name|ALPHA_R_NW_RELOC_LITA
value|2
end_define

end_unit

