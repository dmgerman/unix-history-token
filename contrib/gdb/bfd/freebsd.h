begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end definitions used by all FreeBSD targets.    Copyright (C) 1990, 1991, 1992, 1996 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* FreeBSD ZMAGIC files never have the header in the text. */
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
comment|/* A ZMAGIC file can start at almost any address if it is a kernel. */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|dont use TEXT_START_ADDR
end_define

begin_comment
comment|/* The following definitions are essentially the same as the ones in    FreeBSD's<sys/imgact_aout.h>.  They override gdb's versions, which    don't work for kernels.  See ../include/aout/aout64.h.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_GETMAGIC(x) == OMAGIC || N_GETMAGIC(x) == NMAGIC \ 	 || N_GETMAGIC(x) == ZMAGIC \ 	 ? ((x).a_entry< (x).a_text ? 0 : (x).a_entry& ~TARGET_PAGE_SIZE) \ 	 : TARGET_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
define|\
value|(N_GETMAGIC(x) == ZMAGIC ? TARGET_PAGE_SIZE \ 	 : (N_GETMAGIC(x) == QMAGIC || N_GETMAGIC_NET(x) == ZMAGIC) ? 0 \ 	 : sizeof(struct external_exec))
end_define

begin_define
define|#
directive|define
name|N_TXTSIZE
parameter_list|(
name|x
parameter_list|)
value|((x).a_text)
end_define

begin_define
define|#
directive|define
name|N_GETMAGIC
parameter_list|(
name|exec
parameter_list|)
define|\
value|((exec).a_info& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_GETMAGIC_NET
parameter_list|(
name|exec
parameter_list|)
define|\
value|(ntohl ((exec).a_info)& 0xffff)
end_define

begin_define
define|#
directive|define
name|N_GETMID_NET
parameter_list|(
name|exec
parameter_list|)
define|\
value|((ntohl ((exec).a_info)>> 16)& 0x3ff)
end_define

begin_define
define|#
directive|define
name|N_GETFLAG_NET
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ntohl ((exec).a_info)>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|exec
parameter_list|)
define|\
value|((enum machine_type) \ 	 ((N_GETMAGIC_NET (exec) == ZMAGIC) ? N_GETMID_NET (exec) : \ 	  ((exec).a_info>> 16)& 0x3ff))
end_define

begin_define
define|#
directive|define
name|N_FLAGS
parameter_list|(
name|exec
parameter_list|)
define|\
value|((N_GETMAGIC_NET (exec) == ZMAGIC) ? N_GETFLAG_NET (exec) : \ 	 ((exec).a_info>> 26)& 0x3f)
end_define

begin_define
define|#
directive|define
name|N_SET_INFO
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = ((magic)& 0xffff) \ 	 | (((int)(type)& 0x3ff)<< 16) \ 	 | (((flags)& 0x3f)<< 26))
end_define

begin_define
define|#
directive|define
name|N_SET_MACHTYPE
parameter_list|(
name|exec
parameter_list|,
name|machtype
parameter_list|)
define|\
value|((exec).a_info = \          ((exec).a_info& 0xfb00ffff) | ((((int)(machtype))&0x3ff)<< 16))
end_define

begin_define
define|#
directive|define
name|N_SET_FLAGS
parameter_list|(
name|exec
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = \ 	 ((exec).a_info& 0x03ffffff) | ((flags& 0x03f)<< 26))
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

begin_comment
comment|/* On FreeBSD, the magic number is always in correct endian format */
end_comment

begin_define
define|#
directive|define
name|NO_SWAP_MAGIC
end_define

begin_define
define|#
directive|define
name|MY_write_object_contents
value|MY(write_object_contents)
end_define

begin_function_decl
specifier|static
name|boolean
name|MY
parameter_list|(
name|write_object_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

begin_comment
comment|/* Write an object file.    Section contents have already been written.  We write the    file header, symbols, and relocation.  */
end_comment

begin_function
specifier|static
name|boolean
name|MY
function|(
name|write_object_contents
function|)
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|external_exec
name|exec_bytes
decl_stmt|;
name|struct
name|internal_exec
modifier|*
name|execp
init|=
name|exec_hdr
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
if|#
directive|if
name|CHOOSE_RELOC_SIZE
name|CHOOSE_RELOC_SIZE
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
else|#
directive|else
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_STD_SIZE
expr_stmt|;
endif|#
directive|endif
comment|/* Magic number, maestro, please!  */
switch|switch
condition|(
name|bfd_get_arch
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
case|case
name|bfd_arch_m68k
case|:
if|if
condition|(
name|strcmp
argument_list|(
name|abfd
operator|->
name|xvec
operator|->
name|name
argument_list|,
literal|"a.out-m68k4k-netbsd"
argument_list|)
operator|==
literal|0
condition|)
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_68K4K_NETBSD
argument_list|)
expr_stmt|;
else|else
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_68K_NETBSD
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_arch_sparc
case|:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_SPARC_NETBSD
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_arch_i386
case|:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_386_NETBSD
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_arch_ns32k
case|:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_532_NETBSD
argument_list|)
expr_stmt|;
break|break;
default|default:
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_UNKNOWN
argument_list|)
expr_stmt|;
break|break;
block|}
name|WRITE_HEADERS
argument_list|(
name|abfd
argument_list|,
name|execp
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

end_unit

