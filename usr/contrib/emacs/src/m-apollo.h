begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Apollo machine.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* The following three symbols give information on  the size of various data types.  */
end_comment

begin_define
define|#
directive|define
name|SHORTBITS
value|16
end_define

begin_comment
comment|/* Number of bits in a short */
end_comment

begin_define
define|#
directive|define
name|INTBITS
value|32
end_define

begin_comment
comment|/* Number of bits in an int */
end_comment

begin_define
define|#
directive|define
name|LONGBITS
value|32
end_define

begin_comment
comment|/* Number of bits in a long */
end_comment

begin_comment
comment|/* 68000 has lowest-numbered byte as most significant */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_comment
comment|/* Define how to take a char and sign-extend into an int.    On machines where char is signed, this is a no-op.  */
end_comment

begin_define
define|#
directive|define
name|SIGN_EXTEND_CHAR
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_comment
comment|/* Say this machine is a 68000 */
end_comment

begin_comment
comment|/* #define m68000 */
end_comment

begin_comment
comment|/* Done by the C compiler */
end_comment

begin_define
define|#
directive|define
name|APOLLO
end_define

begin_comment
comment|/* Use type int rather than a union, to represent Lisp_Object */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_comment
comment|/* Do not define LOAD_AVE_TYPE or LOAD_AVE_CVT    since there is no /dev/kmem */
end_comment

begin_comment
comment|/* Define CANNOT_DUMP because it is impossible to do unexec.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_DUMP
end_define

begin_comment
comment|/* Define VIRT_ADDR_VARIES because the virtual addresses of    pure and impure space as loaded can vary, and even their    relative order cannot be relied on.  */
end_comment

begin_define
define|#
directive|define
name|VIRT_ADDR_VARIES
end_define

begin_comment
comment|/* Define HAVE_ALLOCA because we use the system's version of alloca.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_comment
comment|/* DN460 has a 28 bit virtual address space, and 26 bits are often used */
end_comment

begin_define
define|#
directive|define
name|VALBITS
value|26
end_define

begin_define
define|#
directive|define
name|GCTYPEBITS
value|5
end_define

end_unit

