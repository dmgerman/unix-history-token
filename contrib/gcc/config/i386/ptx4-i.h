begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running Dynix/ptx v4    Copyright (C) 1996 Free Software Foundation, Inc.     Modified from sysv4.h    Originally written by Ron Guilmette (rfg@netcom.com).    Modified by Tim Wright (timw@sequent.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 Sequent Dynix/ptx Version 4)");
end_define

begin_comment
comment|/* The svr4 ABI for the i386 says that records and unions are returned    in memory.  */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_IN_MEMORY
end_undef

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_MODE (TYPE) == BLKmode \    || (VECTOR_MODE_P (TYPE_MODE (TYPE))&& int_size_in_bytes (TYPE) == 8))
end_define

begin_comment
comment|/* Define which macros to predefine.  _SEQUENT_ is our extension.  */
end_comment

begin_comment
comment|/* This used to define X86, but james@bigtex.cactus.org says that    is supposed to be defined optionally by user programs--not by default.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dunix -D_SEQUENT_ -Asystem=unix -Asystem=ptx4"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
value|svr4_dbx_register_map[n]
end_define

begin_comment
comment|/* The routine used to output sequences of byte values.  We use a special    version of this for most svr4 targets because doing so makes the    generated assembly code more compact (and thus faster to assemble)    as well as more readable.  Note that if we find subparts of the    character sequence which end with NUL (and which are shorter than    STRING_LIMIT) we output those using ASM_OUTPUT_LIMITED_STRING.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|do									\     {									\       register const unsigned char *_ascii_bytes =			\         (const unsigned char *) (STR);					\       register const unsigned char *limit = _ascii_bytes + (LENGTH);	\       register unsigned bytes_in_chunk = 0;				\       for (; _ascii_bytes< limit; _ascii_bytes++)			\         {								\ 	  register const unsigned char *p;				\ 	  if (bytes_in_chunk>= 64)					\ 	    {								\ 	      fputc ('\n', (FILE));					\ 	      bytes_in_chunk = 0;					\ 	    }								\ 	  for (p = _ascii_bytes; p< limit&& *p != '\0'; p++)		\ 	    continue;							\ 	  if (p< limit&& (p - _ascii_bytes)<= (long) STRING_LIMIT)	\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 		{							\ 		  fputc ('\n', (FILE));					\ 		  bytes_in_chunk = 0;					\ 		}							\ 	      ASM_OUTPUT_LIMITED_STRING ((FILE), _ascii_bytes);		\ 	      _ascii_bytes = p;						\ 	    }								\ 	  else								\ 	    {								\ 	      if (bytes_in_chunk == 0)					\ 		fprintf ((FILE), "\t.byte\t");				\ 	      else							\ 		fputc (',', (FILE));					\ 	      fprintf ((FILE), "0x%02x", *_ascii_bytes);		\ 	      bytes_in_chunk += 5;					\ 	    }								\ 	}								\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\n");						\     }									\   while (0)
end_define

end_unit

