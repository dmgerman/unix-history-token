begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PPC ELF support for BFD.    Copyright (C) 1995 Free Software Foundation, Inc.     By Michael Meissner, Cygnus Support,<meissner@cygnus.com>, from information    in the System V Application Binary Interface, PowerPC Processor Supplement    and the PowerPC Embedded Application Binary Interface (eabi).  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the PPC ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_PPC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_PPC_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_EMB
value|0x80000000
end_define

begin_comment
comment|/* PowerPC embedded flag  */
end_comment

begin_comment
comment|/* CYGNUS local bits below */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_RELOCATABLE
value|0x00010000
end_define

begin_comment
comment|/* PowerPC -mrelocatable flag */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_RELOCATABLE_LIB
value|0x00008000
end_define

begin_comment
comment|/* PowerPC -mrelocatable-lib flag */
end_comment

begin_comment
comment|/* Processor specific section headers, sh_type field */
end_comment

begin_define
define|#
directive|define
name|SHT_ORDERED
value|SHT_HIPROC
end_define

begin_comment
comment|/* Link editor is to sort the \ 						   entries in this section \ 						   based on the address \ 						   specified in the associated \ 						   symbol table entry.  */
end_comment

begin_comment
comment|/* Processor specific section flags, sh_flags field */
end_comment

begin_define
define|#
directive|define
name|SHF_EXCLUDE
value|0x80000000
end_define

begin_comment
comment|/* Link editor is to exclude \ 						   this section from executable \ 						   and shared objects that it \ 						   builds when those objects \ 						   are not to be furhter \ 						   relocated.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_PPC_H */
end_comment

end_unit

