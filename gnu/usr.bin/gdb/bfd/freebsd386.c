begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries under BSD.    Copyright (C) 1990, 1991, 1992 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This data should be correct for the format used under all the various    BSD ports for 386 machines.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_define
define|#
directive|define
name|ARCH
value|32
end_define

begin_comment
comment|/* ZMAGIC files never have the header in the text.  */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* ZMAGIC files start at address 0.  This does not apply to QMAGIC.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
value|((mtype) == M_386 || (mtype) == M_386_NETBSD || (mtype) == M_UNKNOWN)
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(freebsd386_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-freebsd-386"
end_define

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex).a_info& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|ex
parameter_list|)
define|\
value|( (N_GETMAGIC_NET(ex) == ZMAGIC) ? N_GETMID_NET(ex) : \ 	((ex).a_info>> 16)& 0x03ff )
end_define

begin_define
define|#
directive|define
name|N_FLAGS
parameter_list|(
name|ex
parameter_list|)
define|\
value|( (N_GETMAGIC_NET(ex) == ZMAGIC) ? N_GETFLAG_NET(ex) : \ 	((ex).a_info>> 26)& 0x3f )
end_define

begin_define
define|#
directive|define
name|N_SET_INFO
parameter_list|(
name|ex
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|flag
parameter_list|)
define|\
value|( (ex).a_info = (((flag)& 0x3f)<<26) | (((mid)& 0x03ff)<< 16) | \ 	((mag)& 0xffff) )
end_define

begin_define
define|#
directive|define
name|N_GETMAGIC_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|(ntohl((ex).a_info)& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_GETMID_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ntohl((ex).a_info)>> 16)& 0x03ff)
end_define

begin_define
define|#
directive|define
name|N_GETFLAG_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ntohl((ex).a_info)>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|N_SETMAGIC_NET
parameter_list|(
name|ex
parameter_list|,
name|mag
parameter_list|,
name|mid
parameter_list|,
name|flag
parameter_list|)
define|\
value|( (ex).a_info = htonl( (((flag)&0x3f)<<26) | (((mid)&0x03ff)<<16) | \ 	(((mag)&0xffff)) ) )
end_define

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
file|"libaout.h"
end_include

begin_define
define|#
directive|define
name|N_ALIGN
parameter_list|(
name|ex
parameter_list|,
name|x
parameter_list|)
define|\
value|(N_MAGIC(ex) == ZMAGIC || N_MAGIC(ex) == QMAGIC || \ 	 N_GETMAGIC_NET(ex) == ZMAGIC || N_GETMAGIC_NET(ex) == QMAGIC ? \ 	 ((x) + PAGE_SIZE - 1)& ~(PAGE_SIZE - 1) : (x))
end_define

begin_comment
comment|/* Valid magic number check. */
end_comment

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_MAGIC(ex) != OMAGIC&& N_MAGIC(ex) != NMAGIC&& \ 	 N_MAGIC(ex) != ZMAGIC&& N_MAGIC(ex) != QMAGIC&& \ 	 N_GETMAGIC_NET(ex) != OMAGIC&& N_GETMAGIC_NET(ex) != NMAGIC&& \ 	 N_GETMAGIC_NET(ex) != ZMAGIC&& N_GETMAGIC_NET(ex) != QMAGIC)
end_define

begin_comment
comment|/* Address of the bottom of the text segment. */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|ex
parameter_list|)
define|\
value|((N_MAGIC(ex) == OMAGIC || N_MAGIC(ex) == NMAGIC || \ 	N_MAGIC(ex) == ZMAGIC) ? 0 : PAGE_SIZE)
end_define

begin_comment
comment|/* Address of the bottom of the data segment. */
end_comment

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|ex
parameter_list|)
define|\
value|N_ALIGN(ex, N_TXTADDR(ex) + (ex).a_text)
end_define

begin_comment
comment|/* Text segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_MAGIC(ex) == ZMAGIC ? PAGE_SIZE : (N_MAGIC(ex) == QMAGIC || \ 	N_GETMAGIC_NET(ex) == ZMAGIC) ? 0 : EXEC_BYTES_SIZE)
end_define

begin_comment
comment|/* Data segment offset. */
end_comment

begin_define
define|#
directive|define
name|N_DATOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|N_ALIGN(ex, N_TXTOFF(ex) + (ex).a_text)
end_define

begin_comment
comment|/* Relocation table offset. */
end_comment

begin_define
define|#
directive|define
name|N_RELOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|N_ALIGN(ex, N_DATOFF(ex) + (ex).a_data)
end_define

begin_comment
comment|/* Symbol table offset. */
end_comment

begin_define
define|#
directive|define
name|N_SYMOFF
parameter_list|(
name|ex
parameter_list|)
define|\
value|(N_RELOFF(ex) + (ex).a_trsize + (ex).a_drsize)
end_define

begin_comment
comment|/* String table offset. */
end_comment

begin_define
define|#
directive|define
name|N_STROFF
parameter_list|(
name|ex
parameter_list|)
value|(N_SYMOFF(ex) + (ex).a_syms)
end_define

begin_define
define|#
directive|define
name|NO_SWAP_MAGIC
end_define

begin_comment
comment|/* magic number already in correct endian format */
end_comment

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

