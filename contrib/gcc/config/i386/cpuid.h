begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2007 Free Software Foundation, Inc.  *  * This file is free software; you can redistribute it and/or modify it  * under the terms of the GNU General Public License as published by the  * Free Software Foundation; either version 2, or (at your option) any  * later version.  *   * In addition to the permissions in the GNU General Public License, the  * Free Software Foundation gives you unlimited permission to link the  * compiled version of this file with other programs, and to distribute  * those programs without any restriction coming from the use of this  * file.  (The General Public License restrictions do apply in other  * respects; for example, they cover modification of the file, and  * distribution when not linked into another program.)  *   * This file is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; see the file COPYING.  If not, write to  * the Free Software Foundation, 51 Franklin Street, Fifth Floor,  * Boston, MA 02110-1301, USA.  *   *    As a special exception, if you link this library with files  *    compiled with GCC to produce an executable, this does not cause  *    the resulting executable to be covered by the GNU General Public License.  *    This exception does not however invalidate any other reasons why  *    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* %ecx */
end_comment

begin_define
define|#
directive|define
name|bit_SSE3
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|bit_SSSE3
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|bit_CMPXCHG16B
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|bit_SSE4_1
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|bit_SSE4_2
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|bit_POPCNT
value|(1<< 23)
end_define

begin_comment
comment|/* %edx */
end_comment

begin_define
define|#
directive|define
name|bit_CMPXCHG8B
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|bit_CMOV
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|bit_MMX
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|bit_FXSAVE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|bit_SSE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|bit_SSE2
value|(1<< 26)
end_define

begin_comment
comment|/* Extended Features */
end_comment

begin_comment
comment|/* %ecx */
end_comment

begin_define
define|#
directive|define
name|bit_LAHF_LM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|bit_SSE4a
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|bit_SSE5
value|(1<< 11)
end_define

begin_comment
comment|/* %edx */
end_comment

begin_define
define|#
directive|define
name|bit_LM
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|bit_3DNOWP
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|bit_3DNOW
value|(1<< 31)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__PIC__
argument_list|)
end_if

begin_comment
comment|/* %ebx may be the PIC register.  */
end_comment

begin_define
define|#
directive|define
name|__cpuid
parameter_list|(
name|level
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("xchg{l}\t{%%}ebx, %1\n\t"			\ 	   "cpuid\n\t"					\ 	   "xchg{l}\t{%%}ebx, %1\n\t"			\ 	   : "=a" (a), "=r" (b), "=c" (c), "=d" (d)	\ 	   : "0" (level))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__cpuid
parameter_list|(
name|level
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("cpuid\n\t"					\ 	   : "=a" (a), "=b" (b), "=c" (c), "=d" (d)	\ 	   : "0" (level))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return highest supported input value for cpuid instruction.  ext can    be either 0x0 or 0x8000000 to return highest supported value for    basic or extended cpuid information.  Function returns 0 if cpuid    is not supported or whatever cpuid returns in eax register.  If sig    pointer is non-null, then first four bytes of the signature    (as found in ebx register) are returned in location pointed by sig.  */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|__get_cpuid_max
parameter_list|(
name|unsigned
name|int
name|__ext
parameter_list|,
name|unsigned
name|int
modifier|*
name|__sig
parameter_list|)
block|{
name|unsigned
name|int
name|__eax
decl_stmt|,
name|__ebx
decl_stmt|,
name|__ecx
decl_stmt|,
name|__edx
decl_stmt|;
ifndef|#
directive|ifndef
name|__x86_64__
comment|/* See if we can use cpuid.  On AMD64 we always can.  */
asm|__asm__ ("pushf{l|d}\n\t" 	   "pushf{l|d}\n\t" 	   "pop{l}\t%0\n\t" 	   "mov{l}\t{%0, %1|%1, %0}\n\t" 	   "xor{l}\t{%2, %0|%0, %2}\n\t" 	   "push{l}\t%0\n\t" 	   "popf{l|d}\n\t" 	   "pushf{l|d}\n\t" 	   "pop{l}\t%0\n\t" 	   "popf{l|d}\n\t" 	   : "=&r" (__eax), "=&r" (__ebx) 	   : "i" (0x00200000));
if|if
condition|(
operator|!
operator|(
operator|(
name|__eax
operator|^
name|__ebx
operator|)
operator|&
literal|0x00200000
operator|)
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
comment|/* Host supports cpuid.  Return highest supported cpuid input value.  */
name|__cpuid
argument_list|(
name|__ext
argument_list|,
name|__eax
argument_list|,
name|__ebx
argument_list|,
name|__ecx
argument_list|,
name|__edx
argument_list|)
expr_stmt|;
if|if
condition|(
name|__sig
condition|)
operator|*
name|__sig
operator|=
name|__ebx
expr_stmt|;
return|return
name|__eax
return|;
block|}
end_function

begin_comment
comment|/* Return cpuid data for requested cpuid level, as found in returned    eax, ebx, ecx and edx registers.  The function checks if cpuid is    supported and returns 1 for valid cpuid information or 0 for    unsupported cpuid level.  All pointers are required to be non-null.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|__get_cpuid
parameter_list|(
name|unsigned
name|int
name|__level
parameter_list|,
name|unsigned
name|int
modifier|*
name|__eax
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ebx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__ecx
parameter_list|,
name|unsigned
name|int
modifier|*
name|__edx
parameter_list|)
block|{
name|unsigned
name|int
name|__ext
init|=
name|__level
operator|&
literal|0x80000000
decl_stmt|;
if|if
condition|(
name|__get_cpuid_max
argument_list|(
name|__ext
argument_list|,
literal|0
argument_list|)
operator|<
name|__level
condition|)
return|return
literal|0
return|;
name|__cpuid
argument_list|(
name|__level
argument_list|,
operator|*
name|__eax
argument_list|,
operator|*
name|__ebx
argument_list|,
operator|*
name|__ecx
argument_list|,
operator|*
name|__edx
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

