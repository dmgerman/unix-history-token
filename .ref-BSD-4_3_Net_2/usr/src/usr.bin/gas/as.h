begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* as.h - global header file    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|asH
end_ifndef

begin_define
define|#
directive|define
name|asH
end_define

begin_comment
comment|/* Don't declare things twice. */
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
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* ignore */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset((s),0,(n))
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|n
parameter_list|)
value|memcpy((to),(from),(n))
end_define

begin_define
define|#
directive|define
name|setbuffer
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CAPITALISED names are #defined.  * "lowercaseH" is #defined if "lowercase.h" has been #include-d.  * "lowercaseT" is a typedef of "lowercase" objects.  * "lowercaseP" is type "pointer to object of type 'lowercase'".  * "lowercaseS" is typedef struct ... lowercaseS.  *  * #define SUSPECT when debugging.  * #define DUMP to include data-structure dumpers.  * #define COMMON as "extern" for all modules except one, where you #define  *	COMMON as "".  * If TEST is #defined, then we are testing a module: #define COMMON as "".  */
end_comment

begin_comment
comment|/* These #defines are for parameters of entire assembler. */
end_comment

begin_comment
comment|/* #define SUSPECT JF remove for speed testing */
end_comment

begin_comment
comment|/* #define DUMP */
end_comment

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_comment
comment|/* JF disable asserts */
end_comment

begin_comment
comment|/* These #includes are for type definitions etc. */
end_comment

begin_comment
comment|/* #include "style.h" */
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

begin_comment
comment|/* These defines are potentially useful */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|TRUE
value|(!FALSE)
end_define

begin_define
define|#
directive|define
name|ASSERT
value|assert
end_define

begin_define
define|#
directive|define
name|BAD_CASE
parameter_list|(
name|value
parameter_list|)
define|\
value|{									\   as_fatal ("Case value %d unexpected at line %d of file \"%s\"\n",	\ 	   value, __LINE__, __FILE__);					\ }
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

begin_ifdef
ifdef|#
directive|ifdef
name|SUSPECT
end_ifdef

begin_define
define|#
directive|define
name|register
end_define

begin_comment
comment|/* no registers: helps debugging */
end_comment

begin_define
define|#
directive|define
name|know
parameter_list|(
name|p
parameter_list|)
value|ASSERT(p)
end_define

begin_comment
comment|/* know() is less ugly than #ifdef SUSPECT/ */
end_comment

begin_comment
comment|/* assert()/#endif. */
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

begin_comment
comment|/* #ifdef SUSPECT */
end_comment

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* keep C compilers happy */
end_comment

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* " */
end_comment

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* " */
end_comment

begin_define
define|#
directive|define
name|xfree
value|free
end_define

begin_escape
end_escape

begin_comment
comment|/* input_scrub.c */
end_comment

begin_comment
comment|/*  * Supplies sanitised buffers to read.c.  * Also understands printing line-number part of error messages.  */
end_comment

begin_comment
comment|/* Line number things. */
end_comment

begin_function_decl
name|int
name|seen_at_least_1_file
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
name|new_logical_line
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
name|as_perror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|as_howmuch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Sanitising things. */
end_comment

begin_function_decl
name|void
name|input_scrub_begin
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

begin_escape
end_escape

begin_comment
comment|/* subsegs.c     Sub-segments. Also, segment(=expression type)s.*/
end_comment

begin_comment
comment|/*  * This table describes the use of segments as EXPRESSION types.  *  *	X_seg	X_add_symbol  X_subtract_symbol	X_add_number  * SEG_NONE						no (legal) expression  * SEG_PASS1						no (defined) "  * SEG_BIG					*> 32 bits const.  * SEG_ABSOLUTE				     	0  * SEG_DATA		*		     	0  * SEG_TEXT		*			0  * SEG_BSS		*			0  * SEG_UNKNOWN		*			0  * SEG_DIFFERENCE	0		*	0  *  * The blank fields MUST be 0, and are nugatory.  * The '0' fields MAY be 0. The '*' fields MAY NOT be 0.  *  * SEG_BIG: X_add_number is< 0 if the result is in  *	generic_floating_point_number.  The value is -'c' where c is the  *	character that introduced the constant.  e.g. "0f6.9" will have  -'f'  *	as a X_add_number value.  *	X_add_number> 0 is a count of how many littlenums it took to  *	represent a bignum.  * SEG_DIFFERENCE:  * If segments of both symbols are known, they are the same segment.  * X_add_symbol != X_sub_symbol (then we just cancel them, => SEG_ABSOLUTE).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SEG_ABSOLUTE
block|,
name|SEG_TEXT
block|,
name|SEG_DATA
block|,
name|SEG_BSS
block|,
name|SEG_UNKNOWN
block|,
name|SEG_NONE
block|,
comment|/* Mythical Segment: NO expression seen. */
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
comment|/* Mythical Segment: absolute difference. */
block|}
name|segT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SEG_MAXIMUM_ORDINAL
value|(SEG_DIFFERENCE)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
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
specifier|const
name|int
name|seg_N_TYPE
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|segT
name|N_TYPE_seg
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|subsegs_begin
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

begin_escape
end_escape

begin_comment
comment|/* relax() */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|rs_fill
block|,
comment|/* Variable chars to be repeated fr_offset */
comment|/* times. Fr_symbol unused. */
comment|/* Used with fr_offset == 0 for a constant */
comment|/* length frag. */
name|rs_align
block|,
comment|/* Align: Fr_offset: power of 2. */
comment|/* 1 variable char: fill character. */
name|rs_org
block|,
comment|/* Org: Fr_offset, fr_symbol: address. */
comment|/* 1 variable char: fill character. */
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
name|int
name|relax_substateT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
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
comment|/*  * A code fragment (frag) is some known number of chars, followed by some  * unknown number of chars. Typically the unknown number of chars is an  * instruction address whose size is yet unknown. We always know the greatest  * possible size the unknown number of chars may become, and reserve that  * much room at the end of the frag.  * Once created, frags do not change address during assembly.  * We chain the frags in (a) forward-linked list(s). The object-file address  * of the 1st char of a frag is generally not known until after relax().  * Many things at assembly time describe an address by {object-file-address  * of a particular frag}+offset.   BUG: it may be smarter to have a single pointer off to various different notes for different frag kinds. See how code pans out.    */
end_comment

begin_struct
struct|struct
name|frag
comment|/* a code fragment */
block|{
name|long
name|unsigned
name|int
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
name|int
name|fr_fix
decl_stmt|;
comment|/* (Fixed) number of chars we know we have. */
comment|/* May be 0. */
name|long
name|int
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
name|int
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
comment|/* Virtual frag_now->fr_fix==obstack_next_free(&frags)-frag_now->fr_literal.*/
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

begin_function_decl
name|void
name|frag_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_more
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|frag_var
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_wane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|frag_align
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef asH */
end_comment

begin_comment
comment|/* end: as.h */
end_comment

end_unit

