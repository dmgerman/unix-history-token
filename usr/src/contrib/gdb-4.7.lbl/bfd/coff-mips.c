begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for MIPS Extended-Coff files.    Copyright 1990, 1991, 1992 Free Software Foundation, Inc.    Written by Per Bothner.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/mips.h"
end_include

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"libcoff.h"
end_include

begin_comment
comment|/* to allow easier abstraction-breaking */
end_comment

begin_include
include|#
directive|include
file|"trad-core.h"
end_include

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|ECOFFBADMAG(x)
end_define

begin_comment
comment|/* Can't read these relocs */
end_comment

begin_define
define|#
directive|define
name|RTYPE2HOWTO
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|;
end_define

begin_comment
comment|/* Define NO_COFF_SYMBOLS and NO_COFF_LINENOS to avoid coffcode.h    defining a mess of useless functions.  */
end_comment

begin_define
define|#
directive|define
name|NO_COFF_SYMBOLS
end_define

begin_define
define|#
directive|define
name|NO_COFF_LINENOS
end_define

begin_comment
comment|/* Define MIPS to get MIPS magic numbers and such */
end_comment

begin_define
define|#
directive|define
name|MIPS
value|1
end_define

begin_comment
comment|/* Define additional MIPS section types */
end_comment

begin_define
define|#
directive|define
name|STYP_OTHER_LOAD
value|0x98000300
end_define

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_comment
comment|/* We do not implement symbols for ecoff. */
end_comment

begin_define
define|#
directive|define
name|coff_get_symtab_upper_bound
value|(PROTO(unsigned int, (*),(bfd *)))bfd_false
end_define

begin_define
define|#
directive|define
name|coff_get_symtab
value|(PROTO(unsigned int, (*), (bfd *, asymbol **)))bfd_0
end_define

begin_define
define|#
directive|define
name|coff_print_symbol
define|\
value|(PROTO(void,(*),(bfd *, PTR, asymbol *, enum bfd_print_symbol))) bfd_void
end_define

begin_define
define|#
directive|define
name|coff_swap_sym_in
value|(PROTO(void,(*),(bfd *,PTR,PTR))) bfd_void
end_define

begin_define
define|#
directive|define
name|coff_swap_aux_in
value|(PROTO(void,(*),(bfd *,PTR,int,int,PTR))) bfd_void
end_define

begin_define
define|#
directive|define
name|coff_swap_sym_out
value|(PROTO(unsigned,(*),(bfd *,PTR,PTR))) bfd_void
end_define

begin_define
define|#
directive|define
name|coff_swap_aux_out
value|(PROTO(unsigned,(*),(bfd *,PTR,int,int,PTR))) bfd_void
end_define

begin_comment
comment|/* We do not implement linenos for ecoff. */
end_comment

begin_define
define|#
directive|define
name|coff_get_lineno
value|(struct lineno_cache_entry *(*)()) bfd_nullvoidptr
end_define

begin_define
define|#
directive|define
name|coff_swap_lineno_in
value|(PROTO(void,(*),(bfd *,PTR,PTR))) bfd_void
end_define

begin_define
define|#
directive|define
name|coff_find_nearest_line
value|(PROTO(boolean, (*),(bfd*,asection*,asymbol**,bfd_vma, CONST char**, CONST char**, unsigned int *))) bfd_false
end_define

begin_define
define|#
directive|define
name|coff_swap_lineno_out
value|(PROTO(unsigned,(*),(bfd *,PTR,PTR))) bfd_void
end_define

begin_decl_stmt
name|bfd_target
name|ecoff_little_vec
init|=
block|{
literal|"ecoff-littlemips"
block|,
comment|/* name */
name|bfd_target_coff_flavour
block|,
name|false
block|,
comment|/* data byte order is little */
name|false
block|,
comment|/* header byte order is little */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* object flags */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator|)
block|,
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* sect 							    flags */
literal|0
block|,
comment|/* leading underscore */
literal|'/'
block|,
comment|/* ar_pad_char */
literal|15
block|,
comment|/* ar_max_namelen */
literal|3
block|,
comment|/* minimum alignment power */
name|_do_getl64
block|,
name|_do_putl64
block|,
name|_do_getl32
block|,
name|_do_putl32
block|,
name|_do_getl16
block|,
name|_do_putl16
block|,
comment|/* data */
name|_do_getl64
block|,
name|_do_putl64
block|,
name|_do_getl32
block|,
name|_do_putl32
block|,
name|_do_getl16
block|,
name|_do_putl16
block|,
comment|/* hdrs */
block|{
name|_bfd_dummy_target
block|,
name|coff_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|_bfd_dummy_target
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_mkobject
block|,
name|bfd_false
block|,
comment|/* bfd_set_format */
name|bfd_false
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_write_object_contents
block|,
name|bfd_false
block|,
name|bfd_false
block|}
block|,
name|JUMP_TABLE
argument_list|(
argument|coff
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_target
name|ecoff_big_vec
init|=
block|{
literal|"ecoff-bigmips"
block|,
comment|/* name */
name|bfd_target_coff_flavour
block|,
name|true
block|,
comment|/* data byte order is big */
name|true
block|,
comment|/* header byte order is big */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* object flags */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator|)
block|,
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* sect flags */
literal|0
block|,
comment|/* leading underscore */
literal|' '
block|,
comment|/* ar_pad_char */
literal|16
block|,
comment|/* ar_max_namelen */
literal|3
block|,
comment|/* minimum alignment power */
name|_do_getb64
block|,
name|_do_putb64
block|,
name|_do_getb32
block|,
name|_do_putb32
block|,
name|_do_getb16
block|,
name|_do_putb16
block|,
name|_do_getb64
block|,
name|_do_putb64
block|,
name|_do_getb32
block|,
name|_do_putb32
block|,
name|_do_getb16
block|,
name|_do_putb16
block|,
block|{
name|_bfd_dummy_target
block|,
name|coff_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|_bfd_dummy_target
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_mkobject
block|,
name|bfd_false
block|,
comment|/* bfd_set_format */
name|bfd_false
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_write_object_contents
block|,
comment|/* bfd_write_contents */
name|bfd_false
block|,
name|bfd_false
block|}
block|,
name|JUMP_TABLE
argument_list|(
name|coff
argument_list|)
block|,
name|COFF_SWAP_TABLE
block|}
decl_stmt|;
end_decl_stmt

end_unit

