begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* std.h */
end_comment

begin_comment
comment|/* Standard definitions for Aladdin Enterprises code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|std_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|std_INCLUDED
end_define

begin_comment
comment|/* Include the architecture definitions. */
end_comment

begin_include
include|#
directive|include
file|"arch.h"
end_include

begin_define
define|#
directive|define
name|arch_ints_are_short
value|(arch_sizeof_int == arch_sizeof_short)
end_define

begin_comment
comment|/*  * Here we deal with the vagaries of various C compilers.  We assume that:  *	ANSI-standard Unix compilers define __STDC__.  *	Turbo C and Turbo C++ define __MSDOS__ and __TURBOC__.  *	Borland C++ defines __BORLANDC__, __MSDOS__, and __TURBOC__.  *	Microsoft C defines MSDOS.  *	Watcom C defines __WATCOMC__ and MSDOS.  * We arrange to define __MSDOS__ on all the MS-DOS platforms.  * Also, not used much here, but used in other header files, we assume:  *	Unix System V environments define USG or SYSV.  *	  (GNU software uses the former, non-GNU tends to use the latter.)  *	VMS systems define VMS.  *	bsd 4.2 or 4.3 systems define BSD4_2.  *	POSIX-compliant environments define _POSIX_SOURCE.  *	Motorola 88K BCS/OCS systems defined m88k.  *  * We make fairly heroic efforts to confine all uses of these flags to  * header files, and never to use them in code.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__PROTOTYPES__
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Recognize USG and SYSV as synonyms.  GNU software uses the former, */
end_comment

begin_comment
comment|/* non-GNU tends to use the latter.  We use the latter. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|SYSV
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define dummy values for __FILE__ and __LINE__ if the compiler */
end_comment

begin_comment
comment|/* doesn't provide these.  Note that places that use __FILE__ */
end_comment

begin_comment
comment|/* must check explicitly for a null pointer. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FILE__
end_ifndef

begin_define
define|#
directive|define
name|__FILE__
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LINE__
end_ifndef

begin_define
define|#
directive|define
name|__LINE__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Disable 'const' if the compiler can't handle it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PROTOTYPES__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Disable MS-DOS specialized pointer types on non-MS-DOS systems. */
end_comment

begin_comment
comment|/* Watcom C defines near, far, and huge as macros, so we must undef them. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TURBOC__
end_ifndef

begin_undef
undef|#
directive|undef
name|near
end_undef

begin_define
define|#
directive|define
name|near
end_define

begin_comment
comment|/* */
end_comment

begin_undef
undef|#
directive|undef
name|far
end_undef

begin_define
define|#
directive|define
name|far
end_define

begin_comment
comment|/* */
end_comment

begin_undef
undef|#
directive|undef
name|huge
end_undef

begin_define
define|#
directive|define
name|huge
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|_cs
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|_ds
end_define

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* _es is never safe to use */
end_comment

begin_define
define|#
directive|define
name|_ss
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define a couple of useful language extensions. */
end_comment

begin_comment
comment|/* Get the size of a statically declared array. */
end_comment

begin_define
define|#
directive|define
name|countof
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof((a)[0]))
end_define

begin_comment
comment|/* Define short names for the unsigned types. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uchar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ushort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ulong
typedef|;
end_typedef

begin_comment
comment|/* Since sys/types.h often defines one or more of these (depending on */
end_comment

begin_comment
comment|/* the platform), we have to take steps to prevent name clashes. */
end_comment

begin_comment
comment|/*** NOTE: This requires that you include std.h *before* any other ***/
end_comment

begin_comment
comment|/*** header file that includes sys/types.h. ***/
end_comment

begin_define
define|#
directive|define
name|uchar
value|uchar_
end_define

begin_define
define|#
directive|define
name|uint
value|uint_
end_define

begin_define
define|#
directive|define
name|ushort
value|ushort_
end_define

begin_define
define|#
directive|define
name|ulong
value|ulong_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_undef
undef|#
directive|undef
name|uchar
end_undef

begin_undef
undef|#
directive|undef
name|uint
end_undef

begin_undef
undef|#
directive|undef
name|ushort
end_undef

begin_undef
undef|#
directive|undef
name|ulong
end_undef

begin_comment
comment|/* Maximum values for the unsigned types. */
end_comment

begin_comment
comment|/* The "+0" is to get around apparent bugs in the UTek compiler. */
end_comment

begin_define
define|#
directive|define
name|max_uchar
value|((uchar)0xff + (uchar)0)
end_define

begin_define
define|#
directive|define
name|max_ushort
value|((ushort)0xffff + (ushort)0)
end_define

begin_define
define|#
directive|define
name|max_uint
value|((uint)0xffffffff + (uint)0)
end_define

begin_define
define|#
directive|define
name|max_ulong
value|((ulong)0xffffffffL + (ulong)0)
end_define

begin_comment
comment|/* Define a reliable arithmetic right shift. */
end_comment

begin_comment
comment|/* Must use arith_rshift_1 for a shift by a literal 1. */
end_comment

begin_define
define|#
directive|define
name|arith_rshift_slow
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|((x)< 0 ? ~(~(x)>> (n)) : (x)>> (n))
end_define

begin_if
if|#
directive|if
name|arch_arith_rshift
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|arith_rshift
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|((x)>> (n))
end_define

begin_define
define|#
directive|define
name|arith_rshift_1
parameter_list|(
name|x
parameter_list|)
value|((x)>> 1)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|arch_arith_rshift
operator|==
literal|1
end_if

begin_comment
comment|/* OK except for n=1 */
end_comment

begin_define
define|#
directive|define
name|arith_rshift
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|((x)>> (n))
end_define

begin_define
define|#
directive|define
name|arith_rshift_1
parameter_list|(
name|x
parameter_list|)
value|arith_rshift_slow(x,1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|arith_rshift
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|arith_rshift_slow(x,n)
end_define

begin_define
define|#
directive|define
name|arith_rshift_1
parameter_list|(
name|x
parameter_list|)
value|arith_rshift_slow(x,1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The type to be used for comparing pointers for order (<,>=, etc.). */
end_comment

begin_comment
comment|/* Turbo C large model doesn't compare pointers per se correctly. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ptr_ord_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|ptr_ord_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define all the pointer comparison operations. */
end_comment

begin_define
define|#
directive|define
name|_ptr_cmp
parameter_list|(
name|p1
parameter_list|,
name|rel
parameter_list|,
name|p2
parameter_list|)
value|((ptr_ord_t)(p1) rel (ptr_ord_t)(p2))
end_define

begin_define
define|#
directive|define
name|ptr_le
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|_ptr_cmp(p1,<=, p2)
end_define

begin_define
define|#
directive|define
name|ptr_lt
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|_ptr_cmp(p1,<, p2)
end_define

begin_define
define|#
directive|define
name|ptr_ge
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|_ptr_cmp(p1,>=, p2)
end_define

begin_define
define|#
directive|define
name|ptr_gt
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
value|_ptr_cmp(p1,>, p2)
end_define

begin_define
define|#
directive|define
name|ptr_between
parameter_list|(
name|ptr
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
define|\
value|(ptr_ge(ptr, lo)&& ptr_lt(ptr, hi))
end_define

begin_comment
comment|/* In case stdio.h doesn't have these: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS doesn't have the unlink system call.  Use delete instead. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|unlink
parameter_list|(
name|fname
parameter_list|)
value|delete(fname)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* K&R specifies that float parameters get converted to double. */
end_comment

begin_comment
comment|/* However, if we pass a float to a function that has been declared */
end_comment

begin_comment
comment|/* with a prototype, and the parameter has been declared as float, */
end_comment

begin_comment
comment|/* the ANSI standard specifies that the parameter is left as float. */
end_comment

begin_comment
comment|/* To avoid problems when mixing ANSI and non-ANSI compilation, */
end_comment

begin_comment
comment|/* we declare all float parameters as double. */
end_comment

begin_typedef
typedef|typedef
name|double
name|floatp
typedef|;
end_typedef

begin_comment
comment|/* If we are debugging, make all static variables and procedures public */
end_comment

begin_comment
comment|/* so they get passed through the linker. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOPRIVATE
end_ifdef

begin_define
define|#
directive|define
name|private
end_define

begin_comment
comment|/* */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for argument templates.  ANSI C has these, as does Turbo C,  * but older pcc-derived (K&R) Unix compilers don't.  The syntax is  *	resulttype func(Pn(arg1, ..., argn));  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PROTOTYPES__
end_ifdef

begin_define
define|#
directive|define
name|P0
parameter_list|()
value|void
end_define

begin_define
define|#
directive|define
name|P1
parameter_list|(
name|t1
parameter_list|)
value|t1
end_define

begin_define
define|#
directive|define
name|P2
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
value|t1,t2
end_define

begin_define
define|#
directive|define
name|P3
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|)
value|t1,t2,t3
end_define

begin_define
define|#
directive|define
name|P4
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|)
value|t1,t2,t3,t4
end_define

begin_define
define|#
directive|define
name|P5
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|)
value|t1,t2,t3,t4,t5
end_define

begin_define
define|#
directive|define
name|P6
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|)
value|t1,t2,t3,t4,t5,t6
end_define

begin_define
define|#
directive|define
name|P7
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7
end_define

begin_define
define|#
directive|define
name|P8
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7,t8
end_define

begin_define
define|#
directive|define
name|P9
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7,t8,t9
end_define

begin_define
define|#
directive|define
name|P10
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7,t8,t9,t10
end_define

begin_define
define|#
directive|define
name|P11
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|,
name|t11
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11
end_define

begin_define
define|#
directive|define
name|P12
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|,
name|t11
parameter_list|,
name|t12
parameter_list|)
value|t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P0
parameter_list|()
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P1
parameter_list|(
name|t1
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P2
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P3
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P4
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P5
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P6
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P7
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P8
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P9
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P10
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P11
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|,
name|t11
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P12
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|,
name|t3
parameter_list|,
name|t4
parameter_list|,
name|t5
parameter_list|,
name|t6
parameter_list|,
name|t7
parameter_list|,
name|t8
parameter_list|,
name|t9
parameter_list|,
name|t10
parameter_list|,
name|t11
parameter_list|,
name|t12
parameter_list|)
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Types for client-supplied allocate and free procedures. */
end_comment

begin_comment
comment|/* For accountability, debugging, and error messages, */
end_comment

begin_comment
comment|/* we pass an identifying string to alloc and free. */
end_comment

begin_comment
comment|/* Note that the arguments are like calloc, not like malloc, */
end_comment

begin_comment
comment|/* but an alloc procedure doesn't clear the block. */
end_comment

begin_typedef
typedef|typedef
name|char
argument_list|*
call|(
modifier|*
name|proc_alloc_t
call|)
argument_list|(
name|P3
argument_list|(
argument|unsigned num_elements
argument_list|,
argument|unsigned element_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
argument_list|; typedef
name|void
argument_list|(
operator|*
name|proc_free_t
argument_list|)
argument_list|(
name|P4
argument_list|(
argument|char *data
argument_list|,
argument|unsigned num_elements
argument_list|,
argument|unsigned element_size
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
argument_list|;
end_typedef

begin_comment
comment|/* Standard error printing macros. */
end_comment

begin_comment
comment|/* Use dprintf for messages that just go to dstderr, */
end_comment

begin_comment
comment|/* eprintf for error messages to estderr that include the program name, */
end_comment

begin_comment
comment|/* lprintf for debugging messages that should include line number info. */
end_comment

begin_comment
comment|/* dstderr and estderr may be redefined. */
end_comment

begin_define
define|#
directive|define
name|dstderr
value|stderr
end_define

begin_define
define|#
directive|define
name|estderr
value|stderr
end_define

begin_define
define|#
directive|define
name|dputc
parameter_list|(
name|chr
parameter_list|)
value|fputc(chr, dstderr)
end_define

begin_define
define|#
directive|define
name|dputs
parameter_list|(
name|str
parameter_list|)
value|fputs(str, dstderr)
end_define

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|str
parameter_list|)
define|\
value|fprintf(dstderr, str)
end_define

begin_define
define|#
directive|define
name|dprintf1
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1)
end_define

begin_define
define|#
directive|define
name|dprintf2
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|dprintf3
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3)
end_define

begin_define
define|#
directive|define
name|dprintf4
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4)
end_define

begin_define
define|#
directive|define
name|dprintf5
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5)
end_define

begin_define
define|#
directive|define
name|dprintf6
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5, arg6)
end_define

begin_define
define|#
directive|define
name|dprintf7
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
end_define

begin_define
define|#
directive|define
name|dprintf8
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
end_define

begin_define
define|#
directive|define
name|dprintf9
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
end_define

begin_define
define|#
directive|define
name|dprintf10
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|fprintf(dstderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROGRAM_NAME
end_ifdef

begin_define
define|#
directive|define
name|_epn
value|fprintf(estderr, PROGRAM_NAME),
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_epn
end_define

begin_comment
comment|/* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|eprintf
parameter_list|(
name|str
parameter_list|)
define|\
value|(_epn fprintf(estderr, str))
end_define

begin_define
define|#
directive|define
name|eprintf1
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1))
end_define

begin_define
define|#
directive|define
name|eprintf2
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2))
end_define

begin_define
define|#
directive|define
name|eprintf3
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3))
end_define

begin_define
define|#
directive|define
name|eprintf4
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4))
end_define

begin_define
define|#
directive|define
name|eprintf5
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5))
end_define

begin_define
define|#
directive|define
name|eprintf6
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6))
end_define

begin_define
define|#
directive|define
name|eprintf7
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7))
end_define

begin_define
define|#
directive|define
name|eprintf8
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8))
end_define

begin_define
define|#
directive|define
name|eprintf9
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9))
end_define

begin_define
define|#
directive|define
name|eprintf10
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|(_epn fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10))
end_define

begin_if
if|#
directive|if
name|__LINE__
end_if

begin_comment
comment|/* compiler provides it */
end_comment

begin_define
define|#
directive|define
name|_epl
value|_epn fprintf(estderr, "%s(%d): ", __FILE__, __LINE__),
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_epl
value|_epn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|lprintf
parameter_list|(
name|str
parameter_list|)
define|\
value|(_epl fprintf(estderr, str))
end_define

begin_define
define|#
directive|define
name|lprintf1
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1))
end_define

begin_define
define|#
directive|define
name|lprintf2
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2))
end_define

begin_define
define|#
directive|define
name|lprintf3
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3))
end_define

begin_define
define|#
directive|define
name|lprintf4
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4))
end_define

begin_define
define|#
directive|define
name|lprintf5
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5))
end_define

begin_define
define|#
directive|define
name|lprintf6
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6))
end_define

begin_define
define|#
directive|define
name|lprintf7
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7))
end_define

begin_define
define|#
directive|define
name|lprintf8
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8))
end_define

begin_define
define|#
directive|define
name|lprintf9
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9))
end_define

begin_define
define|#
directive|define
name|lprintf10
parameter_list|(
name|str
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|(_epl fprintf(estderr, str, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* std_INCLUDED */
end_comment

end_unit

