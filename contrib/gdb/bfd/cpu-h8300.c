begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD library support routines for the Hitachi H8/300 architecture.    Copyright (C) 1990, 91, 92, 93, 94, 1995 Free Software Foundation, Inc.    Hacked by Steve Chamberlain of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* not used currently */
end_comment

begin_comment
comment|/* Relocations for the H8  */
end_comment

begin_endif
unit|static bfd_reloc_status_type howto16_callback (abfd, reloc_entry, symbol_in, data, 		  ignore_input_section, ignore_bfd)      bfd * abfd;      arelent * reloc_entry;      struct symbol_cache_entry *symbol_in;      PTR data;      asection * ignore_input_section;      bfd * ignore_bfd; {   long relocation = 0;   bfd_vma addr = reloc_entry->address;   long x = bfd_get_16 (abfd, (bfd_byte *) data + addr);    HOWTO_PREPARE (relocation, symbol_in);    x = (x + relocation + reloc_entry->addend);    bfd_put_16 (abfd, x, (bfd_byte *) data + addr);   return bfd_reloc_ok; }   static bfd_reloc_status_type howto8_callback (abfd, reloc_entry, symbol_in, data, 		 ignore_input_section, ignore_bfd)      bfd * abfd;      arelent * reloc_entry;      struct symbol_cache_entry *symbol_in;      PTR data;      asection * ignore_input_section;      bfd * ignore_bfd; {   long relocation = 0;   bfd_vma addr = reloc_entry->address;   long x = bfd_get_8 (abfd, (bfd_byte *) data + addr);    HOWTO_PREPARE (relocation, symbol_in);    x = (x + relocation + reloc_entry->addend);    bfd_put_8 (abfd, x, (bfd_byte *) data + addr);   return bfd_reloc_ok; }   static bfd_reloc_status_type howto8_FFnn_callback (abfd, reloc_entry, symbol_in, data, 		      ignore_input_section, ignore_bfd)      bfd * abfd;      arelent * reloc_entry;      struct symbol_cache_entry *symbol_in;      PTR data;      asection * ignore_input_section;      bfd * ignore_bfd; {   long relocation = 0;   bfd_vma addr = reloc_entry->address;    long x = bfd_get_8 (abfd, (bfd_byte *) data + addr);   abort ();   HOWTO_PREPARE (relocation, symbol_in);    x = (x + relocation + reloc_entry->addend);    bfd_put_8 (abfd, x, (bfd_byte *) data + addr);   return bfd_reloc_ok; }  static bfd_reloc_status_type howto8_pcrel_callback (abfd, reloc_entry, symbol_in, data, 		       ignore_input_section, ignore_bfd)      bfd * abfd;      arelent * reloc_entry;      struct symbol_cache_entry *symbol_in;      PTR data;      asection * ignore_input_section;      bfd * ignore_bfd; {   long relocation = 0;   bfd_vma addr = reloc_entry->address;   long x = bfd_get_8 (abfd, (bfd_byte *) data + addr);   abort ();   HOWTO_PREPARE (relocation, symbol_in);    x = (x + relocation + reloc_entry->addend);    bfd_put_8 (abfd, x, (bfd_byte *) data + addr);   return bfd_reloc_ok; }  static reloc_howto_type howto_16 = NEWHOWTO (howto16_callback, "abs16", 1, false, false); static reloc_howto_type howto_8 = NEWHOWTO (howto8_callback, "abs8", 0, false, false);  static reloc_howto_type howto_8_FFnn = NEWHOWTO (howto8_FFnn_callback, "ff00+abs8", 0, false, false);  static reloc_howto_type howto_8_pcrel = NEWHOWTO (howto8_pcrel_callback, "pcrel8", 0, false, true);  static reloc_howto_type * local_bfd_reloc_type_lookup (arch, code)      const struct bfd_arch_info *arch;      bfd_reloc_code_real_type code; {     switch (code)       {       case BFD_RELOC_16: 	return&howto_16;       case BFD_RELOC_8_FFnn: 	return&howto_8_FFnn;       case BFD_RELOC_8: 	return&howto_8;       case BFD_RELOC_8_PCREL: 	return&howto_8_pcrel;       default: 	return (reloc_howto_type *) NULL;       }   }
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|bfd_default_scan_num_mach
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|boolean
name|h8300_scan
parameter_list|(
name|info
parameter_list|,
name|string
parameter_list|)
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|info
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|string
operator|!=
literal|'h'
operator|&&
operator|*
name|string
operator|!=
literal|'H'
condition|)
return|return
name|false
return|;
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'8'
condition|)
return|return
name|false
return|;
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'/'
condition|)
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'3'
condition|)
return|return
name|false
return|;
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'0'
condition|)
return|return
name|false
return|;
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'0'
condition|)
return|return
name|false
return|;
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'-'
condition|)
name|string
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|==
literal|'h'
operator|||
operator|*
name|string
operator|==
literal|'H'
condition|)
block|{
return|return
operator|(
name|info
operator|->
name|mach
operator|==
name|bfd_mach_h8300h
operator|)
return|;
block|}
else|else
block|{
return|return
name|info
operator|->
name|mach
operator|==
name|bfd_mach_h8300
return|;
block|}
block|}
end_function

begin_comment
comment|/* This routine is provided two arch_infos and works out the     machine which would be compatible with both and returns a pointer    to its info structure */
end_comment

begin_function
specifier|static
specifier|const
name|bfd_arch_info_type
modifier|*
name|compatible
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
specifier|const
name|bfd_arch_info_type
modifier|*
name|in
decl_stmt|;
specifier|const
name|bfd_arch_info_type
modifier|*
name|out
decl_stmt|;
block|{
comment|/* If the output is non-H and the input is -H, that's bad */
if|if
condition|(
name|in
operator|->
name|mach
operator|==
name|bfd_mach_h8300h
operator|&&
name|out
operator|->
name|mach
operator|==
name|bfd_mach_h8300
condition|)
return|return
literal|0
return|;
comment|/* If either is an -H, the answer is -H */
if|if
condition|(
name|in
operator|->
name|mach
operator|==
name|bfd_mach_h8300h
condition|)
return|return
name|in
return|;
return|return
name|out
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bfd_arch_info_type
name|h8300_info_struct
init|=
block|{
literal|16
block|,
comment|/* 16 bits in a word */
literal|16
block|,
comment|/* 16 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_h8300
block|,
name|bfd_mach_h8300
block|,
literal|"h8300"
block|,
comment|/* arch_name  */
literal|"h8300"
block|,
comment|/* printable name */
literal|1
block|,
name|true
block|,
comment|/* the default machine */
name|compatible
block|,
name|h8300_scan
block|,
comment|/*    local_bfd_reloc_type_lookup, */
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|bfd_arch_info_type
name|bfd_h8300_arch
init|=
block|{
literal|32
block|,
comment|/* 32 bits in a word */
literal|32
block|,
comment|/* 32 bits in an address */
literal|8
block|,
comment|/* 8 bits in a byte */
name|bfd_arch_h8300
block|,
name|bfd_mach_h8300h
block|,
literal|"h8300h"
block|,
comment|/* arch_name  */
literal|"h8300h"
block|,
comment|/* printable name */
literal|1
block|,
name|false
block|,
comment|/* the default machine */
name|compatible
block|,
name|h8300_scan
block|,
comment|/*    local_bfd_reloc_type_lookup, */
operator|&
name|h8300_info_struct
block|, }
decl_stmt|;
end_decl_stmt

end_unit

