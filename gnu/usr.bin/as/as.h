begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* as.h - global header file    Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|GAS
value|1
end_define

begin_comment
comment|/* #include<ansidecl.h> */
end_comment

begin_include
include|#
directive|include
file|"host.h"
end_include

begin_include
include|#
directive|include
file|"flonum.h"
end_include

begin_if
if|#
directive|if
name|__STDC__
operator|!=
literal|1
end_if

begin_define
define|#
directive|define
name|volatile
end_define

begin_comment
comment|/**/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* const */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_define
define|#
directive|define
name|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

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
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|!=
literal|1
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|x
parameter_list|)
value|x
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
comment|/*PARAMS */
end_comment

begin_comment
comment|/*  * I think this stuff is largely out of date.  xoxorich.  *  * CAPITALISED names are #defined.  * "lowercaseH" is #defined if "lowercase.h" has been #include-d.  * "lowercaseT" is a typedef of "lowercase" objects.  * "lowercaseP" is type "pointer to object of type 'lowercase'".  * "lowercaseS" is typedef struct ... lowercaseS.  *  * #define DEBUG to enable all the "know" assertion tests.  * #define SUSPECT when debugging.  * #define COMMON as "extern" for all modules except one, where you #define  *	COMMON as "".  * If TEST is #defined, then we are testing a module: #define COMMON as "".  */
end_comment

begin_comment
comment|/* These #defines are for parameters of entire assembler. */
end_comment

begin_comment
comment|/* #define SUSPECT JF remove for speed testing */
end_comment

begin_comment
comment|/* These #includes are for type definitions etc. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

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
name|value
parameter_list|)
define|\
value|{ \       as_fatal("Case value %d unexpected at line %d of file \"%s\"\n", \ 	       value, __LINE__, __FILE__); \ 	   }
end_define

begin_escape
end_escape

begin_comment
comment|/* These are assembler-wide concepts */
end_comment

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

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* temporary */
end_comment

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

begin_comment
comment|/*  * This table describes the use of segments as EXPRESSION types.  *  *	X_seg	X_add_symbol  X_subtract_symbol	X_add_number  * SEG_ABSENT						no (legal) expression  * SEG_PASS1						no (defined) "  * SEG_BIG					*> 32 bits const.  * SEG_ABSOLUTE				     	0  * SEG_DATA		*		     	0  * SEG_TEXT		*			0  * SEG_BSS		*			0  * SEG_UNKNOWN		*			0  * SEG_DIFFERENCE	0		*	0  * SEG_REGISTER					*  *  * The blank fields MUST be 0, and are nugatory.  * The '0' fields MAY be 0. The '*' fields MAY NOT be 0.  *  * SEG_BIG: X_add_number is< 0 if the result is in  *	generic_floating_point_number.  The value is -'c' where c is the  *	character that introduced the constant.  e.g. "0f6.9" will have  -'f'  *	as a X_add_number value.  *	X_add_number> 0 is a count of how many littlenums it took to  *	represent a bignum.  * SEG_DIFFERENCE:  * If segments of both symbols are known, they are the same segment.  * X_add_symbol != X_sub_symbol (then we just cancel them, => SEG_ABSOLUTE).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MANY_SEGMENTS
end_ifdef

begin_define
define|#
directive|define
name|N_SEGMENTS
value|10
end_define

begin_define
define|#
directive|define
name|SEG_NORMAL
parameter_list|(
name|x
parameter_list|)
value|((x)>= SEG_E0&& (x)<= SEG_E9)
end_define

begin_define
define|#
directive|define
name|SEG_LIST
value|SEG_E0,SEG_E1,SEG_E2,SEG_E3,SEG_E4,SEG_E5,SEG_E6,SEG_E7,SEG_E8,SEG_E9
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
name|SEG_TEXT
value|SEG_E0
end_define

begin_define
define|#
directive|define
name|SEG_BSS
value|SEG_E2
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
name|SEG_ABSENT
block|,
comment|/* Mythical Segment (absent): NO expression seen. */
name|SEG_PASS1
block|,
comment|/* Mythical Segment: Need another pass. */
name|SEG_GOOF
block|,
comment|/* Only happens if AS has a logic error. */
comment|/* Invented so we don't crash printing */
comment|/* error message involving weird segment. */
name|SEG_BIG
block|,
comment|/* Bigger than 32 bits constant. */
name|SEG_DIFFERENCE
block|,
comment|/* Mythical Segment: absolute difference. */
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
block|,
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

begin_typedef
typedef|typedef
name|int
name|subsegT
typedef|;
end_typedef

begin_decl_stmt
name|COMMON
name|subsegT
name|now_subseg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What subseg we are accreting now? */
end_comment

begin_decl_stmt
name|COMMON
name|segT
name|now_seg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Segment our instructions emit to. */
end_comment

begin_comment
comment|/* Only OK values are SEG_TEXT or SEG_DATA. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
specifier|const
name|seg_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|section_alignment
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* relax() */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_relax_state
block|{
name|rs_fill
block|,
comment|/* Variable chars to be repeated fr_offset times. Fr_symbol 		    unused. Used with fr_offset == 0 for a constant length 		    frag. */
name|rs_align
block|,
comment|/* Align: Fr_offset: power of 2. 1 variable char: fill 		     character. */
name|rs_org
block|,
comment|/* Org: Fr_offset, fr_symbol: address. 1 variable char: fill 		   character. */
name|rs_machine_dependent
block|,
ifndef|#
directive|ifndef
name|WORKING_DOT_WORD
name|rs_broken_word
block|,
comment|/* JF: gunpoint */
endif|#
directive|endif
block|}
name|relax_stateT
typedef|;
end_typedef

begin_comment
comment|/* typedef unsigned char relax_substateT; */
end_comment

begin_comment
comment|/* JF this is more likely to leave the end of a struct frag on an align    boundry.  Be very careful with this.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|relax_substateT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|relax_addressT
typedef|;
end_typedef

begin_comment
comment|/* Enough bits for address. */
end_comment

begin_comment
comment|/* Still an integer type. */
end_comment

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
comment|/* a code fragment */
block|{
name|unsigned
name|long
name|fr_address
decl_stmt|;
comment|/* Object file address. */
name|struct
name|frag
modifier|*
name|fr_next
decl_stmt|;
comment|/* Chain forward; ascending address order. */
comment|/* Rooted in frch_root. */
name|long
name|fr_fix
decl_stmt|;
comment|/* (Fixed) number of chars we know we have. */
comment|/* May be 0. */
name|long
name|fr_var
decl_stmt|;
comment|/* (Variable) number of chars after above. */
comment|/* May be 0. */
name|struct
name|symbol
modifier|*
name|fr_symbol
decl_stmt|;
comment|/* For variable-length tail. */
name|long
name|fr_offset
decl_stmt|;
comment|/* For variable-length tail. */
name|char
modifier|*
name|fr_opcode
decl_stmt|;
comment|/*->opcode low addr byte,for relax()ation*/
name|relax_stateT
name|fr_type
decl_stmt|;
comment|/* What state is my tail in? */
name|relax_substateT
name|fr_subtype
decl_stmt|;
comment|/* These are needed only on the NS32K machines */
name|char
name|fr_pcrel_adjust
decl_stmt|;
name|char
name|fr_bsr
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
name|char
name|fr_literal
index|[
literal|1
index|]
decl_stmt|;
comment|/* Chars begin here. */
comment|/* One day we will compile fr_literal[0]. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_FRAG
define|\
value|((int)zero_address_frag.fr_literal-(int)&zero_address_frag)
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

begin_decl_stmt
name|COMMON
name|fragS
modifier|*
name|frag_now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> current frag we are building. */
end_comment

begin_comment
comment|/* This frag is incomplete. */
end_comment

begin_comment
comment|/* It is, however, included in frchain_now. */
end_comment

begin_comment
comment|/* Frag_now->fr_fix is bogus. Use: */
end_comment

begin_comment
comment|/* Virtual frag_now->fr_fix == obstack_next_free(&frags)-frag_now->fr_literal.*/
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|zero_address_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For foreign-segment symbol fixups. */
end_comment

begin_decl_stmt
name|COMMON
name|fragS
name|bss_address_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For local common (N_BSS segment) fixups. */
end_comment

begin_comment
comment|/* main program "as.c" (command arguments etc) */
end_comment

begin_decl_stmt
name|COMMON
name|char
name|flagseen
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ['x'] TRUE if "-x" seen. */
end_comment

begin_decl_stmt
name|COMMON
name|char
modifier|*
name|out_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of emitted object file */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|need_pass_2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we need a second pass. */
end_comment

begin_decl_stmt
name|COMMON
name|int
name|picmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if "-k" or "-K" seen. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|poc_name
decl_stmt|;
comment|/* assembler mnemonic, lower case, no '.' */
name|void
function_decl|(
modifier|*
name|poc_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* Do the work */
name|int
name|poc_val
decl_stmt|;
comment|/* Value to pass to handler */
block|}
name|pseudo_typeS
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|__STDC__
operator|==
literal|1
operator|)
operator|&
operator|!
name|defined
argument_list|(
name|NO_STDARG
argument_list|)
end_if

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
name|as_bad
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_tsktsk
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_warn
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|had_errors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_warnings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_bad
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_tsktsk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_warn
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__& !NO_STDARG */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

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
name|char
modifier|*
name|strstr
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|wanted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|long
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_scrub_next_char
parameter_list|(
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|()
parameter_list|,
name|void
function_decl|(
modifier|*
name|unget
function_decl|)
parameter_list|()
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
name|int
name|ignore_input
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_string
parameter_list|(
name|void
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
parameter_list|,
name|unsigned
name|int
modifier|*
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
name|void
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
name|void
name|int_to_gen
parameter_list|(
name|long
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
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
name|scrub_to_file
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scrub_to_string
parameter_list|(
name|int
name|ch
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
name|void
name|subseg_new
parameter_list|(
name|segT
name|seg
parameter_list|,
name|subsegT
name|subseg
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|char
modifier|*
name|app_push
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|atof_ieee
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_include_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_new_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|input_scrub_next_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_scrub_next_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gen_to_words
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_err
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_errors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|had_warnings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ignore_input
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scrub_from_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seen_at_least_1_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|app_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_howmuch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_perror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_where
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bump_line_counters
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_scrub_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|input_scrub_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|int_to_gen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|new_logical_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scrub_to_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scrub_to_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subseg_change
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subseg_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|subsegs_begin
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_comment
comment|/* this one starts the chain of target dependant headers */
end_comment

begin_include
include|#
directive|include
file|"targ-env.h"
end_include

begin_comment
comment|/* these define types needed by the interfaces */
end_comment

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
file|"expr.h"
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

begin_include
include|#
directive|include
file|"listing.h"
end_include

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of as.h */
end_comment

end_unit

