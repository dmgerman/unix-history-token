begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for the generic parts of PE/PEI; common header information.    Copyright 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Written by Cygnus Solutions.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Most of this hacked by  Steve Chamberlain, 			sac@cygnus.com  PE/PEI rearrangement (and code added): Donn Terry 				       Softway Systems, Inc. */
end_comment

begin_comment
comment|/* Hey look, some documentation [and in a place you expect to find it]!     The main reference for the pei format is "Microsoft Portable Executable    and Common Object File Format Specification 4.1".  Get it if you need to    do some serious hacking on this code.     Another reference:    "Peering Inside the PE: A Tour of the Win32 Portable Executable    File Format", MSJ 1994, Volume 9.     The *sole* difference between the pe format and the pei format is that the    latter has an MSDOS 2.0 .exe header on the front that prints the message    "This app must be run under Windows." (or some such).    (FIXME: Whether that statement is *really* true or not is unknown.    Are there more subtle differences between pe and pei formats?    For now assume there aren't.  If you find one, then for God sakes    document it here!)     The Microsoft docs use the word "image" instead of "executable" because    the former can also refer to a DLL (shared library).  Confusion can arise    because the `i' in `pei' also refers to "image".  The `pe' format can    also create images (i.e. executables), it's just that to run on a win32    system you need to use the pei format.     FIXME: Please add more docs here so the next poor fool that has to hack    on this code has a chance of getting something accomplished without    wasting too much time. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GET_FCN_LNNOPTR
end_ifndef

begin_define
define|#
directive|define
name|GET_FCN_LNNOPTR
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_sym.x_fcnary.x_fcn.x_lnnoptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_FCN_ENDNDX
end_ifndef

begin_define
define|#
directive|define
name|GET_FCN_ENDNDX
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_sym.x_fcnary.x_fcn.x_endndx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_FCN_LNNOPTR
end_ifndef

begin_define
define|#
directive|define
name|PUT_FCN_LNNOPTR
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32(abfd, in, ext->x_sym.x_fcnary.x_fcn.x_lnnoptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_FCN_ENDNDX
end_ifndef

begin_define
define|#
directive|define
name|PUT_FCN_ENDNDX
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32(abfd, in, ext->x_sym.x_fcnary.x_fcn.x_endndx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_LNSZ_LNNO
end_ifndef

begin_define
define|#
directive|define
name|GET_LNSZ_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_16 (abfd, ext->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_LNSZ_SIZE
end_ifndef

begin_define
define|#
directive|define
name|GET_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_16 (abfd, ext->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_LNSZ_LNNO
end_ifndef

begin_define
define|#
directive|define
name|PUT_LNSZ_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_16(abfd, in, ext->x_sym.x_misc.x_lnsz.x_lnno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_LNSZ_SIZE
end_ifndef

begin_define
define|#
directive|define
name|PUT_LNSZ_SIZE
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_16(abfd, in, ext->x_sym.x_misc.x_lnsz.x_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCN_SCNLEN
end_ifndef

begin_define
define|#
directive|define
name|GET_SCN_SCNLEN
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_32 (abfd, ext->x_scn.x_scnlen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCN_NRELOC
end_ifndef

begin_define
define|#
directive|define
name|GET_SCN_NRELOC
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_16 (abfd, ext->x_scn.x_nreloc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCN_NLINNO
end_ifndef

begin_define
define|#
directive|define
name|GET_SCN_NLINNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_16 (abfd, ext->x_scn.x_nlinno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCN_SCNLEN
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCN_SCNLEN
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_32(abfd, in, ext->x_scn.x_scnlen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCN_NRELOC
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCN_NRELOC
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_16(abfd, in, ext->x_scn.x_nreloc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCN_NLINNO
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCN_NLINNO
parameter_list|(
name|abfd
parameter_list|,
name|in
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_16(abfd,in, ext->x_scn.x_nlinno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_LINENO_LNNO
end_ifndef

begin_define
define|#
directive|define
name|GET_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_GET_16 (abfd, ext->l_lnno);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_LINENO_LNNO
end_ifndef

begin_define
define|#
directive|define
name|PUT_LINENO_LNNO
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ext
parameter_list|)
define|\
value|H_PUT_16(abfd,val, ext->l_lnno);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The f_symptr field in the filehdr is sometimes 64 bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GET_FILEHDR_SYMPTR
end_ifndef

begin_define
define|#
directive|define
name|GET_FILEHDR_SYMPTR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_FILEHDR_SYMPTR
end_ifndef

begin_define
define|#
directive|define
name|PUT_FILEHDR_SYMPTR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some fields in the aouthdr are sometimes 64 bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_TSIZE
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_TSIZE
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_TSIZE
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_TSIZE
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_DSIZE
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_DSIZE
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_DSIZE
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_DSIZE
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_BSIZE
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_BSIZE
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_BSIZE
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_ENTRY
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_ENTRY
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_ENTRY
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_ENTRY
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_TEXT_START
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_TEXT_START
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_TEXT_START
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_TEXT_START
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_AOUTHDR_DATA_START
end_ifndef

begin_define
define|#
directive|define
name|GET_AOUTHDR_DATA_START
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_AOUTHDR_DATA_START
end_ifndef

begin_define
define|#
directive|define
name|PUT_AOUTHDR_DATA_START
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some fields in the scnhdr are sometimes 64 bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_PADDR
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_PADDR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_PADDR
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_PADDR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_VADDR
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_VADDR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_VADDR
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_VADDR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_SIZE
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_SIZE
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_SIZE
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_SIZE
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_SCNPTR
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_SCNPTR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_SCNPTR
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_SCNPTR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_RELPTR
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_RELPTR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_RELPTR
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_RELPTR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GET_SCNHDR_LNNOPTR
end_ifndef

begin_define
define|#
directive|define
name|GET_SCNHDR_LNNOPTR
value|H_GET_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SCNHDR_LNNOPTR
end_ifndef

begin_define
define|#
directive|define
name|PUT_SCNHDR_LNNOPTR
value|H_PUT_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_pep
end_ifdef

begin_define
define|#
directive|define
name|GET_OPTHDR_IMAGE_BASE
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_IMAGE_BASE
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_STACK_RESERVE
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_STACK_RESERVE
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_STACK_COMMIT
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_STACK_COMMIT
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_HEAP_RESERVE
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_HEAP_RESERVE
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_HEAP_COMMIT
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_HEAP_COMMIT
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|GET_PDATA_ENTRY
value|bfd_get_64
end_define

begin_define
define|#
directive|define
name|_bfd_XX_bfd_copy_private_bfd_data_common
value|_bfd_pep_bfd_copy_private_bfd_data_common
end_define

begin_define
define|#
directive|define
name|_bfd_XX_bfd_copy_private_section_data
value|_bfd_pep_bfd_copy_private_section_data
end_define

begin_define
define|#
directive|define
name|_bfd_XX_get_symbol_info
value|_bfd_pep_get_symbol_info
end_define

begin_define
define|#
directive|define
name|_bfd_XX_only_swap_filehdr_out
value|_bfd_pep_only_swap_filehdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XX_print_private_bfd_data_common
value|_bfd_pep_print_private_bfd_data_common
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_final_link_postscript
value|_bfd_pepi_final_link_postscript
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_final_link_postscript
value|_bfd_pepi_final_link_postscript
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_only_swap_filehdr_out
value|_bfd_pepi_only_swap_filehdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aouthdr_in
value|_bfd_pepi_swap_aouthdr_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aouthdr_out
value|_bfd_pepi_swap_aouthdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aux_in
value|_bfd_pepi_swap_aux_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aux_out
value|_bfd_pepi_swap_aux_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_lineno_in
value|_bfd_pepi_swap_lineno_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_lineno_out
value|_bfd_pepi_swap_lineno_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_scnhdr_out
value|_bfd_pepi_swap_scnhdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_sym_in
value|_bfd_pepi_swap_sym_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_sym_out
value|_bfd_pepi_swap_sym_out
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !COFF_WITH_pep */
end_comment

begin_define
define|#
directive|define
name|GET_OPTHDR_IMAGE_BASE
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_IMAGE_BASE
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_STACK_RESERVE
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_STACK_RESERVE
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_STACK_COMMIT
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_STACK_COMMIT
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_HEAP_RESERVE
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_HEAP_RESERVE
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|GET_OPTHDR_SIZE_OF_HEAP_COMMIT
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_OPTHDR_SIZE_OF_HEAP_COMMIT
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|GET_PDATA_ENTRY
value|bfd_get_32
end_define

begin_define
define|#
directive|define
name|_bfd_XX_bfd_copy_private_bfd_data_common
value|_bfd_pe_bfd_copy_private_bfd_data_common
end_define

begin_define
define|#
directive|define
name|_bfd_XX_bfd_copy_private_section_data
value|_bfd_pe_bfd_copy_private_section_data
end_define

begin_define
define|#
directive|define
name|_bfd_XX_get_symbol_info
value|_bfd_pe_get_symbol_info
end_define

begin_define
define|#
directive|define
name|_bfd_XX_only_swap_filehdr_out
value|_bfd_pe_only_swap_filehdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XX_print_private_bfd_data_common
value|_bfd_pe_print_private_bfd_data_common
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_final_link_postscript
value|_bfd_pei_final_link_postscript
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_final_link_postscript
value|_bfd_pei_final_link_postscript
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_only_swap_filehdr_out
value|_bfd_pei_only_swap_filehdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aouthdr_in
value|_bfd_pei_swap_aouthdr_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aouthdr_out
value|_bfd_pei_swap_aouthdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aux_in
value|_bfd_pei_swap_aux_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_aux_out
value|_bfd_pei_swap_aux_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_lineno_in
value|_bfd_pei_swap_lineno_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_lineno_out
value|_bfd_pei_swap_lineno_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_scnhdr_out
value|_bfd_pei_swap_scnhdr_out
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_sym_in
value|_bfd_pei_swap_sym_in
end_define

begin_define
define|#
directive|define
name|_bfd_XXi_swap_sym_out
value|_bfd_pei_swap_sym_out
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !COFF_WITH_pep */
end_comment

begin_comment
comment|/* These functions are architecture dependent, and are in peicode.h:    coff_swap_reloc_in    int coff_swap_reloc_out    coff_swap_filehdr_in    coff_swap_scnhdr_in    pe_mkobject    pe_mkobject_hook  */
end_comment

begin_comment
comment|/* The functions described below are common across all PE/PEI    implementations architecture types, and actually appear in    peigen.c.  */
end_comment

begin_decl_stmt
name|void
name|_bfd_XXi_swap_sym_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_sym_in
value|_bfd_XXi_swap_sym_in
end_define

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_swap_sym_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_sym_out
value|_bfd_XXi_swap_sym_out
end_define

begin_decl_stmt
name|void
name|_bfd_XXi_swap_aux_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_aux_in
value|_bfd_XXi_swap_aux_in
end_define

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_swap_aux_out
decl|\
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_aux_out
value|_bfd_XXi_swap_aux_out
end_define

begin_decl_stmt
name|void
name|_bfd_XXi_swap_lineno_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_lineno_in
value|_bfd_XXi_swap_lineno_in
end_define

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_swap_lineno_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_lineno_out
value|_bfd_XXi_swap_lineno_out
end_define

begin_decl_stmt
name|void
name|_bfd_XXi_swap_aouthdr_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_aouthdr_in
value|_bfd_XXi_swap_aouthdr_in
end_define

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_swap_aouthdr_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_aouthdr_out
value|_bfd_XXi_swap_aouthdr_out
end_define

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_swap_scnhdr_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coff_swap_scnhdr_out
value|_bfd_XXi_swap_scnhdr_out
end_define

begin_decl_stmt
name|boolean
name|_bfd_XX_print_private_bfd_data_common
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_XX_bfd_copy_private_bfd_data_common
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_bfd_XX_get_symbol_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|symbol_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_XXi_final_link_postscript
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|coff_final_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|coff_final_link_postscript
end_ifndef

begin_define
define|#
directive|define
name|coff_final_link_postscript
value|_bfd_XXi_final_link_postscript
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following are needed only for ONE of pe or pei, but don't    otherwise vary; peicode.h fixes up ifdefs but we provide the    prototype.  */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XX_only_swap_filehdr_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|_bfd_XXi_only_swap_filehdr_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_XX_bfd_copy_private_section_data
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

