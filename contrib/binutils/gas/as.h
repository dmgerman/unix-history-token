begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* as.h - global header file    Copyright (C) 1987, 90, 91, 92, 93, 94, 95, 96, 1997    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAS
end_ifndef

begin_define
define|#
directive|define
name|GAS
value|1
end_define

begin_comment
comment|/*  * I think this stuff is largely out of date.  xoxorich.  *  * CAPITALISED names are #defined.  * "lowercaseH" is #defined if "lowercase.h" has been #include-d.  * "lowercaseT" is a typedef of "lowercase" objects.  * "lowercaseP" is type "pointer to object of type 'lowercase'".  * "lowercaseS" is typedef struct ... lowercaseS.  *  * #define DEBUG to enable all the "know" assertion tests.  * #define SUSPECT when debugging hash code.  * #define COMMON as "extern" for all modules except one, where you #define  *	COMMON as "".  * If TEST is #defined, then we are testing a module: #define COMMON as "".  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* This is the code recommended in the autoconf documentation, almost    verbatim.  If it doesn't work for you, let me know, and notify    djm@gnu.ai.mit.edu as well.  */
end_comment

begin_comment
comment|/* Added #undef for DJ Delorie.  The right fix is to ensure that as.h    is included first, before even any system header files, in all files    that use it.  KR 1994.11.03 */
end_comment

begin_comment
comment|/* Added void* version for STDC case.  This is to be compatible with    the declaration in bison.simple, used for m68k operand parsing.    --KR 1995.08.08 */
end_comment

begin_comment
comment|/* Force void* decl for hpux.  This is what Bison uses.  --KR 1995.08.16 */
end_comment

begin_comment
comment|/* AIX requires this to be the first thing in the file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* predefined by HP cc +Olibcalls */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__, __hpux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* alloca */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now, tend to the rest of the configuration.  */
end_comment

begin_comment
comment|/* System include files first... */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_comment
comment|/* for size_t, pid_t */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_comment
comment|/* The first getopt value for machine-independent long options.    150 isn't special; it's just an arbitrary non-ASCII char value.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_STD_BASE
value|150
end_define

begin_comment
comment|/* The first getopt value for machine-dependent long options.    170 gives the standard options room to grow.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_MD_BASE
value|170
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_undef
undef|#
directive|undef
name|NDEBUG
end_undef

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
name|__GNUC__
argument_list|)
operator|||
name|__GNUC_MINOR__
operator|<=
literal|5
end_if

begin_define
define|#
directive|define
name|__PRETTY_FUNCTION__
value|((char*)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Handle lossage with assert.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_ASSERT
end_ifndef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BROKEN_ASSERT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|p
parameter_list|)
value|((p) ? 0 : (as_assert (__FILE__, __LINE__, __PRETTY_FUNCTION__), 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|p
parameter_list|)
value|((p), 0)
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
comment|/* BROKEN_ASSERT */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0 : (as_assert (__FILE__, __LINE__, __PRETTY_FUNCTION__), 0))
end_define

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|as_abort (__FILE__, __LINE__, __PRETTY_FUNCTION__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now GNU header files... */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_include
include|#
directive|include
file|<bfd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<libiberty.h>
end_include

begin_comment
comment|/* Define the standard progress macros.  */
end_comment

begin_include
include|#
directive|include
file|<progress.h>
end_include

begin_comment
comment|/* This doesn't get taken care of anywhere.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MWERKS__
end_ifndef

begin_comment
comment|/* Metrowerks C chokes on the "defined (inline)" */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|inline
argument_list|)
end_if

begin_define
define|#
directive|define
name|inline
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
comment|/* !__MWERKS__ */
end_comment

begin_comment
comment|/* Other stuff from config.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRSTR
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_MALLOC
end_ifdef

begin_function_decl
specifier|extern
name|PTR
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PTR
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_FREE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_ERRNO
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is needed for VMS with DEC C.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_UNLINK
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_REMOVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|unlink
value|remove
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hack to make "gcc -Wall" not complain about obstack macros.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|memcpy
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|bcopy
argument_list|)
end_if

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|,
name|size
parameter_list|)
value|memcpy(dest,src,size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make Saber happier on obstack.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SABER
end_ifdef

begin_undef
undef|#
directive|undef
name|__PTR_TO_INT
end_undef

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_undef
undef|#
directive|undef
name|__INT_TO_PTR
end_undef

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
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
value|"unknown"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LINE__ */
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
value|"unknown"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FILE__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FOPEN_WB
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GO32
end_ifdef

begin_include
include|#
directive|include
file|"fopen-bin.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|obstack_chunk_alloc
value|xmalloc
end_define

begin_define
define|#
directive|define
name|obstack_chunk_free
value|xfree
end_define

begin_define
define|#
directive|define
name|xfree
value|free
end_define

begin_define
define|#
directive|define
name|BAD_CASE
parameter_list|(
name|val
parameter_list|)
define|\
value|{ \       as_fatal("Case value %ld unexpected at line %d of file \"%s\"\n", \ 	       (long) val, __LINE__, __FILE__); \ 	   }
end_define

begin_escape
end_escape

begin_include
include|#
directive|include
file|"flonum.h"
end_include

begin_comment
comment|/* These are assembler-wide concepts */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|stdoutput
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|bfd_vma
name|addressT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bfd_signed_vma
name|offsetT
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|addressT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|offsetT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Type of symbol value, etc.  For use in prototypes.  */
end_comment

begin_typedef
typedef|typedef
name|addressT
name|valueT
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|COMMON
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_define
define|#
directive|define
name|COMMON
end_define

begin_comment
comment|/* declare our COMMONs storage here. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMMON
value|extern
end_define

begin_comment
comment|/* our commons live elswhere */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMON now defined */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|know
end_ifndef

begin_define
define|#
directive|define
name|know
parameter_list|(
name|p
parameter_list|)
value|assert(p)
end_define

begin_comment
comment|/* Verify our assumptions! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not yet defined */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|know
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* know() checks are no-op.ed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* input_scrub.c */
end_comment

begin_comment
comment|/*  * Supplies sanitised buffers to read.c.  * Also understands printing line-number part of error messages.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* subsegs.c     Sub-segments. Also, segment(=expression type)s.*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MANY_SEGMENTS
end_ifdef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_define
define|#
directive|define
name|N_SEGMENTS
value|40
end_define

begin_define
define|#
directive|define
name|SEG_NORMAL
parameter_list|(
name|x
parameter_list|)
value|((x)>= SEG_E0&& (x)<= SEG_E39)
end_define

begin_define
define|#
directive|define
name|SEG_LIST
value|SEG_E0,SEG_E1,SEG_E2,SEG_E3,SEG_E4,SEG_E5,SEG_E6,SEG_E7,SEG_E8,SEG_E9,\ 		 SEG_E10,SEG_E11,SEG_E12,SEG_E13,SEG_E14,SEG_E15,SEG_E16,SEG_E17,SEG_E18,SEG_E19,\ 		 SEG_E20,SEG_E21,SEG_E22,SEG_E23,SEG_E24,SEG_E25,SEG_E26,SEG_E27,SEG_E28,SEG_E29,\ 		 SEG_E30,SEG_E31,SEG_E32,SEG_E33,SEG_E34,SEG_E35,SEG_E36,SEG_E37,SEG_E38,SEG_E39
end_define

begin_define
define|#
directive|define
name|SEG_TEXT
value|SEG_E0
end_define

begin_define
define|#
directive|define
name|SEG_DATA
value|SEG_E1
end_define

begin_define
define|#
directive|define
name|SEG_BSS
value|SEG_E2
end_define

begin_define
define|#
directive|define
name|SEG_LAST
value|SEG_E39
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_SEGMENTS
value|3
end_define

begin_define
define|#
directive|define
name|SEG_NORMAL
parameter_list|(
name|x
parameter_list|)
value|((x) == SEG_TEXT || (x) == SEG_DATA || (x) == SEG_BSS)
end_define

begin_define
define|#
directive|define
name|SEG_LIST
value|SEG_TEXT,SEG_DATA,SEG_BSS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
name|_segT
block|{
name|SEG_ABSOLUTE
init|=
literal|0
block|,
name|SEG_LIST
block|,
name|SEG_UNKNOWN
block|,
name|SEG_GOOF
block|,
comment|/* Only happens if AS has a logic error. */
comment|/* Invented so we don't crash printing */
comment|/* error message involving weird segment. */
name|SEG_EXPR
block|,
comment|/* Intermediate expression values. */
name|SEG_DEBUG
block|,
comment|/* Debug segment */
name|SEG_NTV
block|,
comment|/* Transfert vector preload segment */
name|SEG_PTV
block|,
comment|/* Transfert vector postload segment */
name|SEG_REGISTER
comment|/* Mythical: a register-valued expression */
block|}
name|segT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SEG_MAXIMUM_ORDINAL
value|(SEG_REGISTER)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|asection
modifier|*
name|segT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SEG_NORMAL
parameter_list|(
name|SEG
parameter_list|)
value|((SEG) != absolute_section	\&& (SEG) != undefined_section	\&& (SEG) != reg_section	\&& (SEG) != expr_section)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|subsegT
typedef|;
end_typedef

begin_comment
comment|/* What subseg we are accreting now? */
end_comment

begin_decl_stmt
name|COMMON
name|subsegT
name|now_subseg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Segment our instructions emit to. */
end_comment

begin_decl_stmt
name|COMMON
name|segT
name|now_seg
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|segment_name
parameter_list|(
name|SEG
parameter_list|)
value|bfd_get_section_name (stdoutput, SEG)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
specifier|const
name|seg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|segment_name
parameter_list|(
name|SEG
parameter_list|)
value|seg_name[(int) (SEG)]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|section_alignment
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|segT
name|reg_section
decl_stmt|,
name|expr_section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shouldn't these be eliminated someday?  */
end_comment

begin_decl_stmt
specifier|extern
name|segT
name|text_section
decl_stmt|,
name|data_section
decl_stmt|,
name|bss_section
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|absolute_section
value|bfd_abs_section_ptr
end_define

begin_define
define|#
directive|define
name|undefined_section
value|bfd_und_section_ptr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|reg_section
value|SEG_REGISTER
end_define

begin_define
define|#
directive|define
name|expr_section
value|SEG_EXPR
end_define

begin_define
define|#
directive|define
name|text_section
value|SEG_TEXT
end_define

begin_define
define|#
directive|define
name|data_section
value|SEG_DATA
end_define

begin_define
define|#
directive|define
name|bss_section
value|SEG_BSS
end_define

begin_define
define|#
directive|define
name|absolute_section
value|SEG_ABSOLUTE
end_define

begin_define
define|#
directive|define
name|undefined_section
value|SEG_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* relax() */
end_comment

begin_enum
enum|enum
name|_relax_state
block|{
comment|/* Variable chars to be repeated fr_offset times.        Fr_symbol unused. Used with fr_offset == 0 for a        constant length frag. */
name|rs_fill
init|=
literal|1
block|,
comment|/* Align.  The fr_offset field holds the power of 2 to which to        align.  The fr_var field holds the number of characters in the        fill pattern.  The fr_subtype field holds the maximum number of        bytes to skip when aligning, or 0 if there is no maximum.  */
name|rs_align
block|,
comment|/* Align code.  The fr_offset field holds the power of 2 to which        to align.  This type is only generated by machine specific        code, which is normally responsible for handling the fill        pattern.  The fr_subtype field holds the maximum number of        bytes to skip when aligning, or 0 if there is no maximum.  */
name|rs_align_code
block|,
comment|/* Org: Fr_offset, fr_symbol: address. 1 variable char: fill        character. */
name|rs_org
block|,
ifndef|#
directive|ifndef
name|WORKING_DOT_WORD
comment|/* JF: gunpoint */
name|rs_broken_word
block|,
endif|#
directive|endif
comment|/* machine-specific relaxable (or similarly alterable) instruction */
name|rs_machine_dependent
block|,
comment|/* .space directive with expression operand that needs to be computed        later.  Similar to rs_org, but different.        fr_symbol: operand        1 variable char: fill character  */
name|rs_space
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_relax_state
name|relax_stateT
typedef|;
end_typedef

begin_comment
comment|/* This type is used in prototypes, so it can't be a type that will be    widened for argument passing.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|relax_substateT
typedef|;
end_typedef

begin_comment
comment|/* Enough bits for address, but still an integer type.    Could be a problem, cross-assembling for 64-bit machines.  */
end_comment

begin_typedef
typedef|typedef
name|addressT
name|relax_addressT
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* frags.c */
end_comment

begin_comment
comment|/*  * A code fragment (frag) is some known number of chars, followed by some  * unknown number of chars. Typically the unknown number of chars is an  * instruction address whose size is yet unknown. We always know the greatest  * possible size the unknown number of chars may become, and reserve that  * much room at the end of the frag.  * Once created, frags do not change address during assembly.  * We chain the frags in (a) forward-linked list(s). The object-file address  * of the 1st char of a frag is generally not known until after relax().  * Many things at assembly time describe an address by {object-file-address  * of a particular frag}+offset.   BUG: it may be smarter to have a single pointer off to various different  notes for different frag kinds. See how code pans  */
end_comment

begin_struct
struct|struct
name|frag
block|{
comment|/* Object file address. */
name|addressT
name|fr_address
decl_stmt|;
comment|/* Chain forward; ascending address order.  Rooted in frch_root. */
name|struct
name|frag
modifier|*
name|fr_next
decl_stmt|;
comment|/* (Fixed) number of chars we know we have.  May be 0. */
name|offsetT
name|fr_fix
decl_stmt|;
comment|/* (Variable) number of chars after above.  May be 0. */
name|offsetT
name|fr_var
decl_stmt|;
comment|/* For variable-length tail. */
name|struct
name|symbol
modifier|*
name|fr_symbol
decl_stmt|;
comment|/* For variable-length tail. */
name|offsetT
name|fr_offset
decl_stmt|;
comment|/* Points to opcode low addr byte, for relaxation.  */
name|char
modifier|*
name|fr_opcode
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_LISTING
name|struct
name|list_info_struct
modifier|*
name|line
decl_stmt|;
endif|#
directive|endif
comment|/* What state is my tail in? */
name|relax_stateT
name|fr_type
decl_stmt|;
name|relax_substateT
name|fr_subtype
decl_stmt|;
union|union
block|{
comment|/* These are needed only on the NS32K machines.  But since we don't        include targ-cpu.h until after this structure has been defined,        we can't really conditionalize it.  This code should be        rearranged a bit to make that possible.  */
struct|struct
block|{
name|char
name|pcrel_adjust
decl_stmt|,
name|bsr
decl_stmt|;
block|}
name|ns32k
struct|;
ifdef|#
directive|ifdef
name|USING_CGEN
comment|/* Don't include this unless using CGEN to keep frag size down.  */
struct|struct
block|{
specifier|const
name|struct
name|cgen_insn
modifier|*
name|insn
decl_stmt|;
name|unsigned
name|char
name|opindex
decl_stmt|,
name|opinfo
decl_stmt|;
block|}
name|cgen
struct|;
endif|#
directive|endif
block|}
name|fr_targ
union|;
comment|/* Where the frag was created, or where it became a variant frag.  */
name|char
modifier|*
name|fr_file
decl_stmt|;
name|unsigned
name|int
name|fr_line
decl_stmt|;
comment|/* Data begins here.  */
name|char
name|fr_literal
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_FRAG
define|\
value|((char *)zero_address_frag.fr_literal-(char *)&zero_address_frag)
end_define

begin_comment
comment|/* We want to say fr_literal[0] above. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|frag
name|fragS
typedef|;
end_typedef

begin_comment
comment|/* Current frag we are building.  This frag is incomplete.  It is, however,    included in frchain_now.  The fr_fix field is bogus; instead, use:    obstack_next_free(&frags)-frag_now->fr_literal.  */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
modifier|*
name|frag_now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frag_now_fix
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For foreign-segment symbol fixups. */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|zero_address_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For local common (N_BSS segment) fixups. */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|bss_address_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main program "as.c" (command arguments etc) */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_no_comments
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -f */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -D */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_signed_overflow_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -J */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORKING_DOT_WORD
end_ifndef

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_warn_displacement
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -K */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* True if local symbols should be retained.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_keep_locals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -L */
end_comment

begin_comment
comment|/* True if we are assembling in MRI mode.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_mri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we are assembling in m68k MRI mode.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_m68k_mri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should the data section be made read-only and appended to the text    section?  */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_readonly_data_in_text
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -R */
end_comment

begin_comment
comment|/* True if warnings should be inhibited.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_no_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -W */
end_comment

begin_comment
comment|/* True if we should attempt to generate output even if non-fatal errors    are detected.  */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_always_generate_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -Z */
end_comment

begin_comment
comment|/* This is true if the assembler should output time and space usage. */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_print_statistics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of emitted object file */
end_comment

begin_decl_stmt
name|COMMON
name|char
modifier|*
name|out_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file defining extensions to the basic instruction set */
end_comment

begin_decl_stmt
name|COMMON
name|char
modifier|*
name|insttbl_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we need a second pass. */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|need_pass_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we should do no relaxing, and    leave lots of padding.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|linkrelax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we should produce a listing.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|listing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum level of macro nesting.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_macro_nest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Obstack chunk size.  Keep large for efficient space use, make small to    increase malloc calls for monitoring memory allocation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|chunksize
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|_pseudo_type
block|{
comment|/* assembler mnemonic, lower case, no '.' */
specifier|const
name|char
modifier|*
name|poc_name
decl_stmt|;
comment|/* Do the work */
name|void
argument_list|(
argument|*poc_handler
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Value to pass to handler */
name|int
name|poc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_pseudo_type
name|pseudo_typeS
typedef|;
end_typedef

begin_comment
comment|/* Prefer varargs for non-ANSI compiler, since some will barf if the    ellipsis definition is used with a no-arguments declaration.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VARARGS_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_STDARG_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDARG_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_STDARG
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
argument_list|(
name|USE_STDARG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_VARARGS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_VARARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDARG
end_ifdef

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|>=
literal|2
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_comment
comment|/* for use with -Wformat */
end_comment

begin_define
define|#
directive|define
name|PRINTF_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN (const char *format, ...) \ 					__attribute__ ((format (printf, 1, 2)))
end_define

begin_define
define|#
directive|define
name|PRINTF_WHERE_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN (char *file, unsigned int line, \ 					  const char *format, ...) \ 					__attribute__ ((format (printf, 3, 4)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ANSI C with stdarg, but not GNU C */
end_comment

begin_define
define|#
directive|define
name|PRINTF_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN PARAMS ((const char *format, ...))
end_define

begin_define
define|#
directive|define
name|PRINTF_WHERE_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN PARAMS ((char *file, \ 						  unsigned int line, \ 					  	  const char *format, ...))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not using stdarg */
end_comment

begin_define
define|#
directive|define
name|PRINTF_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN ()
end_define

begin_define
define|#
directive|define
name|PRINTF_WHERE_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|PRINTF_LIKE
argument_list|(
name|as_bad
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PRINTF_LIKE
argument_list|(
name|as_fatal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PRINTF_LIKE
argument_list|(
name|as_tsktsk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PRINTF_LIKE
argument_list|(
name|as_warn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PRINTF_WHERE_LIKE
argument_list|(
name|as_bad_where
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PRINTF_WHERE_LIKE
argument_list|(
name|as_warn_where
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|as_assert
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|as_abort
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fprint_value
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|file
operator|,
name|addressT
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sprint_value
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|addressT
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|had_errors
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|had_warnings
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_version_id
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|app_push
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|atof_ieee
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|int
name|what_kind
operator|,
name|LITTLENUM_TYPE
operator|*
name|words
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|input_scrub_include_file
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|position
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|input_scrub_new_file
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|input_scrub_next_buffer
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
name|bufp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_scrub_chars
name|PARAMS
argument_list|(
operator|(
name|int
argument_list|(
operator|*
name|get
argument_list|)
argument_list|(
name|char
operator|*
operator|*
argument_list|)
operator|,
name|char
operator|*
name|to
operator|,
name|int
name|tolen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gen_to_words
name|PARAMS
argument_list|(
operator|(
name|LITTLENUM_TYPE
operator|*
name|words
operator|,
name|int
name|precision
operator|,
name|long
name|exponent_bits
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|had_err
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ignore_input
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cond_finish_check
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cond_exit_macro
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|seen_at_least_1_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|app_pop
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|as_howmuch
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|as_perror
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|gripe
operator|,
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|as_where
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
name|namep
operator|,
name|unsigned
name|int
operator|*
name|linep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bump_line_counters
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|do_scrub_begin
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|input_scrub_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|input_scrub_close
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|input_scrub_end
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|new_logical_line
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|fname
operator|,
name|int
name|line_number
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|subsegs_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|subseg_change
name|PARAMS
argument_list|(
operator|(
name|segT
name|seg
operator|,
name|int
name|subseg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|segT
name|subseg_new
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|subsegT
name|subseg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|segT
name|subseg_force_new
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|subsegT
name|subseg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|subseg_set
name|PARAMS
argument_list|(
operator|(
name|segT
name|seg
operator|,
name|subsegT
name|subseg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
name|segT
name|subseg_get
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|expressionS
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|relax_type
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_comment
comment|/* literal.c */
end_comment

begin_decl_stmt
name|valueT
name|add_to_literal_pool
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
name|valueT
operator|,
name|segT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"expr.h"
end_include

begin_comment
comment|/* Before targ-*.h */
end_comment

begin_comment
comment|/* this one starts the chain of target dependant headers */
end_comment

begin_include
include|#
directive|include
file|"targ-env.h"
end_include

begin_include
include|#
directive|include
file|"struc-symbol.h"
end_include

begin_include
include|#
directive|include
file|"write.h"
end_include

begin_include
include|#
directive|include
file|"frags.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"read.h"
end_include

begin_include
include|#
directive|include
file|"symbols.h"
end_include

begin_include
include|#
directive|include
file|"tc.h"
end_include

begin_include
include|#
directive|include
file|"obj.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_EMULATIONS
end_ifdef

begin_include
include|#
directive|include
file|"emul.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"listing.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABELS_DOLLAR
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABELS_FB
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
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
comment|/* GAS */
end_comment

begin_comment
comment|/* end of as.h */
end_comment

end_unit

