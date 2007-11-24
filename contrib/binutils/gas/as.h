begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* as.h - global header file    Copyright 1987, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
comment|/* I think this stuff is largely out of date.  xoxorich.  *  * CAPITALISED names are #defined.  * "lowercaseH" is #defined if "lowercase.h" has been #include-d.  * "lowercaseT" is a typedef of "lowercase" objects.  * "lowercaseP" is type "pointer to object of type 'lowercase'".  * "lowercaseS" is typedef struct ... lowercaseS.  *  * #define DEBUG to enable all the "know" assertion tests.  * #define SUSPECT when debugging hash code.  * #define COMMON as "extern" for all modules except one, where you #define  *	COMMON as "".  * If TEST is #defined, then we are testing a module: #define COMMON as "".  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"bin-bugs.h"
end_include

begin_comment
comment|/* This is the code recommended in the autoconf documentation, almost    verbatim.  If it doesn't work for you, let me know, and notify    djm@gnu.ai.mit.edu as well.  */
end_comment

begin_comment
comment|/* Added void* version for STDC case.  This is to be compatible with    the declaration in bison.simple, used for m68k operand parsing.    --KR 1995.08.08 */
end_comment

begin_comment
comment|/* Force void* decl for hpux.  This is what Bison uses.  --KR 1995.08.16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

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

begin_comment
comment|/* Indented so that pre-ansi C compilers will ignore it, rather than    choke on it.  Some versions of AIX require this to be the first    thing in the file.  */
end_comment

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
specifier|extern
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
specifier|extern
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
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/* Now, tend to the rest of the configuration.  */
end_comment

begin_comment
comment|/* System include files first...  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
file|"getopt.h"
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
comment|/* The first getopt value for machine-dependent long options.    190 gives the standard options room to grow.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_MD_BASE
value|190
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
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
operator|)
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
comment|/* Now GNU header files...  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* Define the standard progress macros.  */
end_comment

begin_include
include|#
directive|include
file|"progress.h"
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_ENVIRON
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is needed for VMS.  */
end_comment

begin_if
if|#
directive|if
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
value|memcpy (dest, src, size)
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
value|((int) (P))
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
value|((char *) (P))
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

begin_if
if|#
directive|if
name|defined
name|GO32
operator|||
name|defined
name|__MINGW32__
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
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

begin_include
include|#
directive|include
file|"asintl.h"
end_include

begin_define
define|#
directive|define
name|BAD_CASE
parameter_list|(
name|val
parameter_list|)
define|\
value|{									    \     as_fatal (_("Case value %ld unexpected at line %d of file \"%s\"\n"),   \ 	      (long) val, __LINE__, __FILE__);				    \   }
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
comment|/* declare our COMMONs storage here.  */
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
comment|/* our commons live elsewhere */
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
comment|/* Supplies sanitised buffers to read.c.    Also understands printing line-number part of error messages.  */
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
comment|/* Only happens if AS has a logic error.  */
comment|/* Invented so we don't crash printing */
comment|/* error message involving weird segment.  */
name|SEG_EXPR
block|,
comment|/* Intermediate expression values.  */
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
comment|/* What subseg we are accessing now? */
end_comment

begin_decl_stmt
name|COMMON
name|subsegT
name|now_subseg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Segment our instructions emit to.  */
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
comment|/* Variable chars to be repeated fr_offset times.      Fr_symbol unused. Used with fr_offset == 0 for a      constant length frag.  */
name|rs_fill
init|=
literal|1
block|,
comment|/* Align.  The fr_offset field holds the power of 2 to which to      align.  The fr_var field holds the number of characters in the      fill pattern.  The fr_subtype field holds the maximum number of      bytes to skip when aligning, or 0 if there is no maximum.  */
name|rs_align
block|,
comment|/* Align code.  The fr_offset field holds the power of 2 to which      to align.  This type is only generated by machine specific      code, which is normally responsible for handling the fill      pattern.  The fr_subtype field holds the maximum number of      bytes to skip when aligning, or 0 if there is no maximum.  */
name|rs_align_code
block|,
comment|/* Test for alignment.  Like rs_align, but used by several targets      to warn if data is not properly aligned.  */
name|rs_align_test
block|,
comment|/* Org: Fr_offset, fr_symbol: address. 1 variable char: fill      character.  */
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
comment|/* .space directive with expression operand that needs to be computed      later.  Similar to rs_org, but different.      fr_symbol: operand      1 variable char: fill character  */
name|rs_space
block|,
comment|/* A DWARF leb128 value; only ELF uses this.  The subtype is 0 for      unsigned, 1 for signed.  */
name|rs_leb128
block|,
comment|/* Exception frame information which we may be able to optimize.  */
name|rs_cfa
block|,
comment|/* Cross-fragment dwarf2 line number optimization.  */
name|rs_dwarf2dbg
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

begin_struct
struct|struct
name|relax_type
block|{
comment|/* Forward reach. Signed number.> 0.  */
name|offsetT
name|rlx_forward
decl_stmt|;
comment|/* Backward reach. Signed number.< 0.  */
name|offsetT
name|rlx_backward
decl_stmt|;
comment|/* Bytes length of this address.  */
name|unsigned
name|char
name|rlx_length
decl_stmt|;
comment|/* Next longer relax-state.  0 means there is no 'next' relax-state.  */
name|relax_substateT
name|rlx_more
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|relax_type
name|relax_typeS
typedef|;
end_typedef

begin_escape
end_escape

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
comment|/* True if warnings count as errors.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_fatal_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* --fatal-warnings */
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
comment|/* This is true if the assembler should output time and space usage.  */
end_comment

begin_decl_stmt
name|COMMON
name|unsigned
name|char
name|flag_print_statistics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if local absolute symbols are to be stripped.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_strip_local_absolute
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we should generate a traditional format object file.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_traditional_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if .note.GNU-stack section with SEC_CODE should be created */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_execstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if .note.GNU-stack section with SEC_CODE should be created */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_noexecstack
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
comment|/* TRUE if we need a second pass.  */
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
comment|/* Type of debugging information we should generate.  We currently support    stabs, ECOFF, and DWARF2.     NOTE!  This means debug information about the assembly source code itself    and _not_ about possible debug information from a high-level language.    This is especially relevant to DWARF2, since the compiler may emit line    number directives that the assembler resolves.  */
end_comment

begin_enum
enum|enum
name|debug_info_type
block|{
name|DEBUG_UNSPECIFIED
block|,
name|DEBUG_NONE
block|,
name|DEBUG_STABS
block|,
name|DEBUG_ECOFF
block|,
name|DEBUG_DWARF
block|,
name|DEBUG_DWARF2
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|debug_info_type
name|debug_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_gnu_debug_info_extensions
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

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
comment|/* Verbosity level.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|verbose
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
function_decl|(
modifier|*
name|poc_handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
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

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
end_if

begin_comment
comment|/* Support for double underscores in attribute names was added in gcc    2.6, so avoid them if we are using an earlier version.  */
end_comment

begin_define
define|#
directive|define
name|__printf__
value|printf
end_define

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRINTF_LIKE
parameter_list|(
name|FCN
parameter_list|)
define|\
value|void FCN (const char *format, ...) \     __attribute__ ((__format__ (__printf__, 1, 2)))
end_define

begin_define
define|#
directive|define
name|PRINTF_WHERE_LIKE
parameter_list|(
name|FCN
parameter_list|)
define|\
value|void FCN (char *file, unsigned int line, const char *format, ...) \     __attribute__ ((__format__ (__printf__, 3, 4)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__< 2 || defined(VMS) */
end_comment

begin_define
define|#
directive|define
name|PRINTF_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN (const char *format, ...)
end_define

begin_define
define|#
directive|define
name|PRINTF_WHERE_LIKE
parameter_list|(
name|FCN
parameter_list|)
value|void FCN (char *file, \ 					  unsigned int line, \ 					  const char *format, ...)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__< 2 || defined(VMS) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_STDARG */
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

begin_comment
comment|/* ! USE_STDARG */
end_comment

begin_expr_stmt
name|PRINTF_LIKE
argument_list|(
name|as_bad
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|PRINTF_LIKE
argument_list|(
argument|as_fatal
argument_list|)
end_macro

begin_expr_stmt
name|ATTRIBUTE_NORETURN
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

begin_function_decl
name|void
name|as_assert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|as_abort
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fprint_value
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|addressT
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sprint_value
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|addressT
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_errors
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_warnings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_version_id
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|app_push
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|atof_ieee
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|what_kind
parameter_list|,
name|LITTLENUM_TYPE
modifier|*
name|words
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_include_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|input_scrub_insert_line
parameter_list|(
specifier|const
name|char
modifier|*
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|input_scrub_insert_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_new_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_next_buffer
parameter_list|(
name|char
modifier|*
modifier|*
name|bufp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_scrub_chars
parameter_list|(
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|char
modifier|*
name|to
parameter_list|,
name|int
name|tolen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gen_to_words
parameter_list|(
name|LITTLENUM_TYPE
modifier|*
name|words
parameter_list|,
name|int
name|precision
parameter_list|,
name|long
name|exponent_bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_err
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ignore_input
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cond_finish_check
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cond_exit_macro
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seen_at_least_1_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|app_pop
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_howmuch
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_perror
parameter_list|(
specifier|const
name|char
modifier|*
name|gripe
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_where
parameter_list|(
name|char
modifier|*
modifier|*
name|namep
parameter_list|,
name|unsigned
name|int
modifier|*
name|linep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bump_line_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_scrub_begin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|new_logical_line
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|line_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subsegs_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subseg_change
parameter_list|(
name|segT
name|seg
parameter_list|,
name|int
name|subseg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|segT
name|subseg_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|subsegT
name|subseg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|segT
name|subseg_force_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|subsegT
name|subseg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subseg_set
parameter_list|(
name|segT
name|seg
parameter_list|,
name|subsegT
name|subseg
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_function_decl
name|segT
name|subseg_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|subseg_text_p
parameter_list|(
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_dependencies
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|register_dependency
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_dependencies
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_typedef
typedef|typedef
name|struct
name|symbol
name|symbolS
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|relax_type
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|frag
name|fragS
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_comment
comment|/* literal.c */
end_comment

begin_function_decl
name|valueT
name|add_to_literal_pool
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|segT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|check_eh_frame
parameter_list|(
name|struct
name|expressionS
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eh_frame_estimate_size_before_relax
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eh_frame_relax_frag
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eh_frame_convert_frag
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generic_force_reloc
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_ELF
end_ifdef

begin_define
define|#
directive|define
name|IS_ELF
value|(OUTPUT_FLAVOR == bfd_target_elf_flavour)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|IS_ELF
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_ELF
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

begin_ifdef
ifdef|#
directive|ifdef
name|TC_M68K
end_ifdef

begin_comment
comment|/* True if we are assembling in m68k MRI mode.  */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|flag_m68k_mri
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|flag_m68k_mri
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WARN_COMMENTS
end_ifdef

begin_decl_stmt
name|COMMON
name|int
name|warn_comment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|COMMON
name|unsigned
name|int
name|found_comment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|COMMON
name|char
modifier|*
name|found_comment_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NUMBERS_WITH_SUFFIX
end_ifndef

begin_define
define|#
directive|define
name|NUMBERS_WITH_SUFFIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|LABELS_WITHOUT_COLONS
end_ifndef

begin_define
define|#
directive|define
name|LABELS_WITHOUT_COLONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_PSEUDO_DOT
end_ifndef

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TEXT_SECTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|TEXT_SECTION_NAME
value|".text"
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_NAME
value|".data"
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_NAME
value|".bss"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OCTETS_PER_BYTE_POWER
end_ifndef

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE_POWER
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OCTETS_PER_BYTE
end_ifndef

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE
value|(1<<OCTETS_PER_BYTE_POWER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OCTETS_PER_BYTE
operator|!=
operator|(
literal|1
operator|<<
name|OCTETS_PER_BYTE_POWER
operator|)
end_if

begin_error
error|#
directive|error
literal|"Octets per byte conflicts with its power-of-two definition!"
end_error

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

end_unit

