begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************                     s y s d e p . h ** Forth Inspired Command Language ** Author: John Sadler (john_sadler@alum.mit.edu) ** Created: 16 Oct 1997 ** Ficl system dependent types and prototypes... ** ** Note: Ficl also depends on the use of "assert" when ** FICL_ROBUST is enabled. This may require some consideration ** in firmware systems since assert often ** assumes stderr/stdout.   ** $Id: sysdep.h,v 1.11 2001/12/05 07:21:34 jsadler Exp $ *******************************************************************/
end_comment

begin_comment
comment|/* ** Copyright (c) 1997-2001 John Sadler (john_sadler@alum.mit.edu) ** All rights reserved. ** ** Get the latest Ficl release at http://ficl.sourceforge.net ** ** I am interested in hearing from anyone who uses ficl. If you have ** a problem, a success story, a defect, an enhancement request, or ** if you would like to contribute to the ficl release, please ** contact me by email at the address above. ** ** L I C E N S E  and  D I S C L A I M E R **  ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ** ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE ** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL ** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS ** OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT ** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY ** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF ** SUCH DAMAGE. ** ** $Id: sysdep.h,v 1.6 2001-04-26 21:41:55-07 jsadler Exp jsadler $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__SYSDEP_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SYSDEP_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t, NULL */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
name|IGNORE
end_if

begin_comment
comment|/* Macro to silence unused param warnings */
end_comment

begin_define
define|#
directive|define
name|IGNORE
parameter_list|(
name|x
parameter_list|)
value|&x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** TRUE and FALSE for C boolean operations, and ** portable 32 bit types for CELLs **  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|TRUE
end_if

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|FALSE
end_if

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** System dependent data type declarations... */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|INT32
end_if

begin_define
define|#
directive|define
name|INT32
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|UNS32
end_if

begin_define
define|#
directive|define
name|UNS32
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|UNS16
end_if

begin_define
define|#
directive|define
name|UNS16
value|unsigned short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|UNS8
end_if

begin_define
define|#
directive|define
name|UNS8
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|NULL
end_if

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_UNS and FICL_INT must have the same size as a void* on ** the target system. A CELL is a union of void*, FICL_UNS, and ** FICL_INT.  ** (11/2000: same for FICL_FLOAT) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_INT
end_if

begin_define
define|#
directive|define
name|FICL_INT
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_UNS
end_if

begin_define
define|#
directive|define
name|FICL_UNS
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_FLOAT
end_if

begin_define
define|#
directive|define
name|FICL_FLOAT
value|float
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** Ficl presently supports values of 32 and 64 for BITS_PER_CELL */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|BITS_PER_CELL
end_if

begin_define
define|#
directive|define
name|BITS_PER_CELL
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|BITS_PER_CELL
operator|!=
literal|32
operator|)
operator|&&
operator|(
name|BITS_PER_CELL
operator|!=
literal|64
operator|)
operator|)
end_if

begin_expr_stmt
name|Error
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|FICL_UNS
name|hi
decl_stmt|;
name|FICL_UNS
name|lo
decl_stmt|;
block|}
name|DPUNS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FICL_UNS
name|quot
decl_stmt|;
name|FICL_UNS
name|rem
decl_stmt|;
block|}
name|UNSQR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FICL_INT
name|hi
decl_stmt|;
name|FICL_INT
name|lo
decl_stmt|;
block|}
name|DPINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|FICL_INT
name|quot
decl_stmt|;
name|FICL_INT
name|rem
decl_stmt|;
block|}
name|INTQR
typedef|;
end_typedef

begin_comment
comment|/* ** B U I L D   C O N T R O L S */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_MINIMAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_MINIMAL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|FICL_MINIMAL
operator|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_SOFTWORDS
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_FILE
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_FLOAT
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_USER
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_LOCALS
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_DEBUGGER
value|0
end_define

begin_define
define|#
directive|define
name|FICL_WANT_OOP
value|0
end_define

begin_define
define|#
directive|define
name|FICL_PLATFORM_EXTEND
value|0
end_define

begin_define
define|#
directive|define
name|FICL_MULTITHREAD
value|0
end_define

begin_define
define|#
directive|define
name|FICL_ROBUST
value|0
end_define

begin_define
define|#
directive|define
name|FICL_EXTENDED_PREFIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_PLATFORM_EXTEND ** Includes words defined in ficlCompilePlatform */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_PLATFORM_EXTEND
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_PLATFORM_EXTEND
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_WANT_FILE ** Includes the FILE and FILE-EXT wordset and associated code. Turn this off if you do not ** have a file system! ** Contributed by Larry Hastings */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_FILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_FILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_WANT_FLOAT ** Includes a floating point stack for the VM, and words to do float operations. ** Contributed by Guy Carver */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_FLOAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_FLOAT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_WANT_DEBUGGER ** Inludes a simple source level debugger */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_DEBUGGER
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_DEBUGGER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_EXTENDED_PREFIX enables a bunch of extra prefixes in prefix.c and prefix.fr (if ** included as part of softcore.c) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_EXTENDED_PREFIX
end_if

begin_define
define|#
directive|define
name|FICL_EXTENDED_PREFIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** User variables: per-instance variables bound to the VM. ** Kinda like thread-local storage. Could be implemented in a  ** VM private dictionary, but I've chosen the lower overhead ** approach of an array of CELLs instead. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_WANT_USER
end_if

begin_define
define|#
directive|define
name|FICL_WANT_USER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_USER_CELLS
end_if

begin_define
define|#
directive|define
name|FICL_USER_CELLS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  ** FICL_WANT_LOCALS controls the creation of the LOCALS wordset and ** a private dictionary for local variable compilation. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_WANT_LOCALS
end_if

begin_define
define|#
directive|define
name|FICL_WANT_LOCALS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Max number of local variables per definition */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_MAX_LOCALS
end_if

begin_define
define|#
directive|define
name|FICL_MAX_LOCALS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_WANT_OOP ** Inludes object oriented programming support (in softwords) ** OOP support requires locals and user variables! */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|FICL_WANT_LOCALS
operator|)
operator|||
operator|!
operator|(
name|FICL_WANT_USER
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_OOP
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_OOP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_OOP
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_OOP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_WANT_SOFTWORDS ** Controls inclusion of all softwords in softcore.c */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_WANT_SOFTWORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_WANT_SOFTWORDS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_MULTITHREAD enables dictionary mutual exclusion ** wia the ficlLockDictionary system dependent function. ** Note: this implementation is experimental and poorly ** tested. Further, it's unnecessary unless you really ** intend to have multiple SESSIONS (poor choice of name ** on my part) - that is, threads that modify the dictionary ** at the same time. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_MULTITHREAD
end_if

begin_define
define|#
directive|define
name|FICL_MULTITHREAD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** PORTABLE_LONGMULDIV causes ficlLongMul and ficlLongDiv to be ** defined in C in sysdep.c. Use this if you cannot easily  ** generate an inline asm definition */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PORTABLE_LONGMULDIV
argument_list|)
end_if

begin_define
define|#
directive|define
name|PORTABLE_LONGMULDIV
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** INLINE_INNER_LOOP causes the inner interpreter to be inline code ** instead of a function call. This is mainly because MS VC++ 5 ** chokes with an internal compiler error on the function version. ** in release mode. Sheesh. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|INLINE_INNER_LOOP
end_if

begin_if
if|#
directive|if
name|defined
name|_DEBUG
end_if

begin_define
define|#
directive|define
name|INLINE_INNER_LOOP
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE_INNER_LOOP
value|1
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
comment|/* ** FICL_ROBUST enables bounds checking of stacks and the dictionary. ** This will detect stack over and underflows and dictionary overflows. ** Any exceptional condition will result in an assertion failure. ** (As generated by the ANSI assert macro) ** FICL_ROBUST == 1 --> stack checking in the outer interpreter ** FICL_ROBUST == 2 also enables checking in many primitives */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_ROBUST
end_if

begin_define
define|#
directive|define
name|FICL_ROBUST
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_DEFAULT_STACK Specifies the default size (in CELLs) of ** a new virtual machine's stacks, unless overridden at  ** create time. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_DEFAULT_STACK
end_if

begin_define
define|#
directive|define
name|FICL_DEFAULT_STACK
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_DEFAULT_DICT specifies the number of CELLs to allocate ** for the system dictionary by default. The value ** can be overridden at startup time as well. ** FICL_DEFAULT_ENV specifies the number of cells to allot ** for the environment-query dictionary. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_DEFAULT_DICT
end_if

begin_define
define|#
directive|define
name|FICL_DEFAULT_DICT
value|12288
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_DEFAULT_ENV
end_if

begin_define
define|#
directive|define
name|FICL_DEFAULT_ENV
value|260
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_DEFAULT_VOCS specifies the maximum number of wordlists in  ** the dictionary search order. See Forth DPANS sec 16.3.3 ** (file://dpans16.htm#16.3.3) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_DEFAULT_VOCS
end_if

begin_define
define|#
directive|define
name|FICL_DEFAULT_VOCS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_MAX_PARSE_STEPS controls the size of an array in the FICL_SYSTEM structure ** that stores pointers to parser extension functions. I would never expect to have ** more than 8 of these, so that's the default limit. Too many of these functions ** will probably exact a nasty performance penalty. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_MAX_PARSE_STEPS
end_if

begin_define
define|#
directive|define
name|FICL_MAX_PARSE_STEPS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** FICL_ALIGN is the power of two to which the dictionary ** pointer address must be aligned. This value is usually ** either 1 or 2, depending on the memory architecture ** of the target system; 2 is safe on any 16 or 32 bit ** machine. 3 would be appropriate for a 64 bit machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|FICL_ALIGN
end_if

begin_define
define|#
directive|define
name|FICL_ALIGN
value|3
end_define

begin_define
define|#
directive|define
name|FICL_ALIGN_ADD
value|((1<< FICL_ALIGN) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** System dependent routines -- ** edit the implementations in sysdep.c to be compatible ** with your runtime environment... ** ficlTextOut sends a NULL terminated string to the  **   default output device - used for system error messages ** ficlMalloc and ficlFree have the same semantics as malloc and free **   in standard C ** ficlLongMul multiplies two UNS32s and returns a 64 bit unsigned  **   product ** ficlLongDiv divides an UNS64 by an UNS32 and returns UNS32 quotient **   and remainder */
end_comment

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ficlTextOut
parameter_list|(
name|struct
name|vm
modifier|*
name|pVM
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|fNewline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ficlMalloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ficlFree
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ficlRealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Stub function for dictionary access control - does nothing ** by default, user can redefine to guarantee exclusive dict ** access to a single thread for updates. All dict update code ** must be bracketed as follows: ** ficlLockDictionary(TRUE); **<code that updates dictionary> ** ficlLockDictionary(FALSE); ** ** Returns zero if successful, nonzero if unable to acquire lock ** before timeout (optional - could also block forever) ** ** NOTE: this function must be implemented with lock counting ** semantics: nested calls must behave properly. */
end_comment

begin_if
if|#
directive|if
name|FICL_MULTITHREAD
end_if

begin_function_decl
name|int
name|ficlLockDictionary
parameter_list|(
name|short
name|fLock
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ficlLockDictionary
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* ignore */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** 64 bit integer math support routines: multiply two UNS32s ** to get a 64 bit product,& divide the product by an UNS32 ** to get an UNS32 quotient and remainder. Much easier in asm ** on a 32 bit CPU than in C, which usually doesn't support  ** the double length result (but it should). */
end_comment

begin_function_decl
name|DPUNS
name|ficlLongMul
parameter_list|(
name|FICL_UNS
name|x
parameter_list|,
name|FICL_UNS
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UNSQR
name|ficlLongDiv
parameter_list|(
name|DPUNS
name|q
parameter_list|,
name|FICL_UNS
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** FICL_HAVE_FTRUNCATE indicates whether the current OS supports ** the ftruncate() function (available on most UNIXes).  This ** function is necessary to provide the complete File-Access wordset. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FICL_HAVE_FTRUNCATE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FICL_HAVE_FTRUNCATE
value|0
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
comment|/*__SYSDEP_H__*/
end_comment

end_unit

