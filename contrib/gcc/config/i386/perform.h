begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for AT&T assembler syntax for the Intel 80386.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Defines to be able to build libgcc.a with GCC.  */
end_comment

begin_comment
comment|/* It might seem that these are not important, since gcc 2 will never    call libgcc for these functions.  But programs might be linked with    code compiled by gcc 1, and then these will be used.  */
end_comment

begin_comment
comment|/* The arg names used to be a and b, but `a' appears inside strings    and that confuses non-ANSI cpp.  */
end_comment

begin_define
define|#
directive|define
name|perform_udivsi3
parameter_list|(
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = arg0;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (arg1), "d" (dx)); \   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_divsi3
parameter_list|(
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\   register int cx asm("cx");						\ 									\   ax = arg0;								\   cx = arg1;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=&d" (dx) : "a" (ax), "c" (cx)); \   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_umodsi3
parameter_list|(
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = arg0;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (arg1), "d" (dx)); \   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_modsi3
parameter_list|(
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\   register int cx asm("cx");						\ 									\   ax = arg0;								\   cx = arg1;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=&d" (dx) : "a" (ax), "c" (cx)); \   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_fixdfsi
parameter_list|(
name|arg0
parameter_list|)
define|\
value|{									\   auto unsigned short ostatus;						\   auto unsigned short nstatus;						\   auto int ret;								\   auto double tmp;							\ 									\&ostatus;
comment|/* guarantee these land in memory */
value|\&nstatus;								\&ret;									\&tmp;									\ 									\   asm volatile ("fnstcw %0" : "=m" (ostatus));				\   nstatus = ostatus | 0x0c00;						\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (nstatus));		\   tmp = arg0;								\   asm volatile ("fldl %0" :
comment|/* no outputs */
value|: "m" (tmp));		\   asm volatile ("fistpl %0" : "=m" (ret));				\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (ostatus));		\ 									\   return ret;								\ }
end_define

end_unit

