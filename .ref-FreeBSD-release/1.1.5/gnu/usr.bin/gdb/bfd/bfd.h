begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Main header file for the bfd library -- portable access to object files.    Copyright 1990, 1991, 1992, 1993 Free Software Foundation, Inc.    Contributed by Cygnus Support.  ** NOTE: bfd.h and bfd-in2.h are GENERATED files.  Don't change them; ** instead, change bfd-in.h or the other BFD source files processed to ** generate these files.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* bfd.h -- The only header file required by users of the bfd library   The bfd.h file is generated from bfd-in.h and various .c files; if you change it, your changes will probably be lost.  All the prototypes and definitions following the comment "THE FOLLOWING IS EXTRACTED FROM THE SOURCE" are extracted from the source files for BFD.  If you change it, someone oneday will extract it from the source again, and your changes will be lost.  To save yourself from this bind, change the definitions in the source in the bfd directory.  Type "make docs" and then "make headers" in that directory, and magically this file will change to reflect your changes.  If you don't have the tools to perform the extraction, then you are safe from someone on your system trampling over your header files. You should still maintain the equivalence between the source and this file though; every change you make to the .c file should be reflected here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BFD_H_SEEN__
end_ifndef

begin_define
define|#
directive|define
name|__BFD_H_SEEN__
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_define
define|#
directive|define
name|BFD_VERSION
value|"2.2"
end_define

begin_define
define|#
directive|define
name|BFD_ARCH_SIZE
value|32
end_define

begin_if
if|#
directive|if
name|BFD_ARCH_SIZE
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|BFD64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|INLINE
value|__inline__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
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
comment|/* 64-bit type definition (if any) from bfd's sysdep.h goes here */
end_comment

begin_comment
comment|/* forward declaration */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_bfd
name|bfd
typedef|;
end_typedef

begin_comment
comment|/* To squelch erroneous compiler warnings ("illegal pointer    combination") from the SVR3 compiler, we would like to typedef    boolean to int (it doesn't like functions which return boolean.    Making sure they are never implicitly declared to return int    doesn't seem to help).  But this file is not configured based on    the host.  */
end_comment

begin_comment
comment|/* General rules: functions which are boolean return true on success    and false on failure (unless they're a predicate).   -- bfd.doc */
end_comment

begin_comment
comment|/* I'm sure this is going to break something and someone is going to    force me to change it. */
end_comment

begin_comment
comment|/* typedef enum boolean {false, true} boolean; */
end_comment

begin_comment
comment|/* Yup, SVR4 has a "typedef enum boolean" in<sys/types.h>  -fnf */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_boolean
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_comment
comment|/* A pointer to a position in a file.  */
end_comment

begin_comment
comment|/* FIXME:  This should be using off_t from<sys/types.h>.    For now, try to avoid breaking stuff by not including<sys/types.h> here.    This will break on systems with 64-bit file offsets (e.g. 4.4BSD).    Probably the best long-term answer is to avoid using file_ptr AND off_t     in this header file, and to handle this in the BFD implementation    rather than in its interface.  */
end_comment

begin_comment
comment|/* typedef off_t	file_ptr; */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|file_ptr
typedef|;
end_typedef

begin_comment
comment|/* Support for different sizes of target format ints and addresses.  If the    host implements 64-bit values, it defines HOST_64_BIT to be the appropriate    type.  Otherwise, this code will fall back on gcc's "long long" type if gcc    is being used.  HOST_64_BIT must be defined in such a way as to be a valid    type name by itself or with "unsigned" prefixed.  It should be a signed    type by itself.     If neither is the case, then compilation will fail if 64-bit targets are    requested.  If you don't request any 64-bit targets, you should be safe. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD64
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HOST_64_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_64_BIT
value|long long
end_define

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|int64_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|HOST_64_BIT
name|uint64_type
typedef|;
end_typedef

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
name|uint64_type
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|uint64_type
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|int64_type
value|long long
end_define

begin_define
define|#
directive|define
name|uint64_typeLOW
parameter_list|(
name|x
parameter_list|)
value|(unsigned long)(((x)& 0xffffffff))
end_define

begin_define
define|#
directive|define
name|uint64_typeHIGH
parameter_list|(
name|x
parameter_list|)
value|(unsigned long)(((x)>> 32)& 0xffffffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|HOST_64_BIT
name|bfd_vma
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HOST_64_BIT
name|bfd_signed_vma
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|HOST_64_BIT
name|bfd_size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|HOST_64_BIT
name|symvalue
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
define|\
value|fprintf(s,"%08x%08x", uint64_typeHIGH(x), uint64_typeLOW(x))
end_define

begin_define
define|#
directive|define
name|sprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
define|\
value|sprintf(s,"%08x%08x", uint64_typeHIGH(x), uint64_typeLOW(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not BFD64  */
end_comment

begin_comment
comment|/* Represent a target address.  Also used as a generic unsigned type    which is guaranteed to be big enough to hold any arithmetic types    we need to deal with.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_vma
typedef|;
end_typedef

begin_comment
comment|/* A generic signed type which is guaranteed to be big enough to hold any    arithmetic types we need to deal with.  Can be assumed to be compatible    with bfd_vma in the same way that signed and unsigned ints are compatible    (as parameters, in assignment, etc).  */
end_comment

begin_typedef
typedef|typedef
name|long
name|bfd_signed_vma
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|symvalue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bfd_size_type
typedef|;
end_typedef

begin_comment
comment|/* Print a bfd_vma x on stream s.  */
end_comment

begin_define
define|#
directive|define
name|fprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
value|fprintf(s, "%08lx", x)
end_define

begin_define
define|#
directive|define
name|sprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
value|sprintf(s, "%08lx", x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BFD64  */
end_comment

begin_define
define|#
directive|define
name|printf_vma
parameter_list|(
name|x
parameter_list|)
value|fprintf_vma(stdout,x)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|flagword
typedef|;
end_typedef

begin_comment
comment|/* 32 bits of flags */
end_comment

begin_escape
end_escape

begin_comment
comment|/** File formats */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_format
block|{
name|bfd_unknown
init|=
literal|0
block|,
comment|/* file format is unknown */
name|bfd_object
block|,
comment|/* linker/assember/compiler output */
name|bfd_archive
block|,
comment|/* object archive file */
name|bfd_core
block|,
comment|/* core dump */
name|bfd_type_end
block|}
comment|/* marks the end; don't use it! */
name|bfd_format
typedef|;
end_typedef

begin_comment
comment|/* Object file flag values */
end_comment

begin_define
define|#
directive|define
name|NO_FLAGS
value|0x00
end_define

begin_define
define|#
directive|define
name|HAS_RELOC
value|0x01
end_define

begin_define
define|#
directive|define
name|EXEC_P
value|0x02
end_define

begin_define
define|#
directive|define
name|HAS_LINENO
value|0x04
end_define

begin_define
define|#
directive|define
name|HAS_DEBUG
value|0x08
end_define

begin_define
define|#
directive|define
name|HAS_SYMS
value|0x10
end_define

begin_define
define|#
directive|define
name|HAS_LOCALS
value|0x20
end_define

begin_define
define|#
directive|define
name|DYNAMIC
value|0x40
end_define

begin_define
define|#
directive|define
name|WP_TEXT
value|0x80
end_define

begin_define
define|#
directive|define
name|D_PAGED
value|0x100
end_define

begin_define
define|#
directive|define
name|BFD_IS_RELAXABLE
value|0x200
end_define

begin_escape
end_escape

begin_comment
comment|/* symbols and relocation */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|symindex
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BFD_NO_MORE_SYMBOLS
value|((symindex) ~0)
end_define

begin_typedef
typedef|typedef
enum|enum
name|bfd_symclass
block|{
name|bfd_symclass_unknown
init|=
literal|0
block|,
name|bfd_symclass_fcommon
block|,
comment|/* fortran common symbols */
name|bfd_symclass_global
block|,
comment|/* global symbol, what a surprise */
name|bfd_symclass_debugger
block|,
comment|/* some debugger symbol */
name|bfd_symclass_undefined
comment|/* none known */
block|}
name|symclass
typedef|;
end_typedef

begin_comment
comment|/* general purpose part of a symbol;    target specific parts will be found in libcoff.h, liba.out.h etc */
end_comment

begin_define
define|#
directive|define
name|bfd_get_section
parameter_list|(
name|x
parameter_list|)
value|((x)->section)
end_define

begin_define
define|#
directive|define
name|bfd_get_output_section
parameter_list|(
name|x
parameter_list|)
value|((x)->section->output_section)
end_define

begin_define
define|#
directive|define
name|bfd_set_section
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->section) = (y)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_base
parameter_list|(
name|x
parameter_list|)
value|((x)->section->vma)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_value
parameter_list|(
name|x
parameter_list|)
value|(bfd_asymbol_base(x) + (x)->value)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_name
parameter_list|(
name|x
parameter_list|)
value|((x)->name)
end_define

begin_comment
comment|/*Perhaps future: #define bfd_asymbol_bfd(x) ((x)->section->owner)*/
end_comment

begin_define
define|#
directive|define
name|bfd_asymbol_bfd
parameter_list|(
name|x
parameter_list|)
value|((x)->the_bfd)
end_define

begin_define
define|#
directive|define
name|bfd_asymbol_flavour
parameter_list|(
name|x
parameter_list|)
value|(bfd_asymbol_bfd(x)->xvec->flavour)
end_define

begin_comment
comment|/* This is a type pun with struct ranlib on purpose! */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|carsym
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|file_ptr
name|file_offset
decl_stmt|;
comment|/* look here to find the file */
block|}
name|carsym
typedef|;
end_typedef

begin_comment
comment|/* to make these you call a carsymogen */
end_comment

begin_comment
comment|/* Used in generating armaps.  Perhaps just a forward definition would do? */
end_comment

begin_struct
struct|struct
name|orl
block|{
comment|/* output ranlib */
name|char
modifier|*
modifier|*
name|name
decl_stmt|;
comment|/* symbol name */
name|file_ptr
name|pos
decl_stmt|;
comment|/* bfd* or file position */
name|int
name|namidx
decl_stmt|;
comment|/* index into string table */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Linenumber stuff */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lineno_cache_entry
block|{
name|unsigned
name|int
name|line_number
decl_stmt|;
comment|/* Linenumber from start of function*/
union|union
block|{
name|struct
name|symbol_cache_entry
modifier|*
name|sym
decl_stmt|;
comment|/* Function name */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* Offset into section */
block|}
name|u
union|;
block|}
name|alent
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* object and core file sections */
end_comment

begin_define
define|#
directive|define
name|align_power
parameter_list|(
name|addr
parameter_list|,
name|align
parameter_list|)
define|\
value|( ((addr) + ((1<<(align))-1))& (-1<< (align)))
end_define

begin_typedef
typedef|typedef
name|struct
name|sec
modifier|*
name|sec_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bfd_get_section_name
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->name + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->vma + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->alignment_power + 0)
end_define

begin_define
define|#
directive|define
name|bfd_section_name
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->name)
end_define

begin_define
define|#
directive|define
name|bfd_section_size
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|(bfd_get_section_size_before_reloc(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->vma)
end_define

begin_define
define|#
directive|define
name|bfd_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->alignment_power)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_flags
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->flags + 0)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_userdata
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|)
value|((ptr)->userdata)
end_define

begin_define
define|#
directive|define
name|bfd_is_com_section
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)->flags& SEC_IS_COMMON) != 0)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_vma
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->vma = (ptr)->lma= (val)), ((ptr)->user_set_vma = true), true)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_alignment
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->alignment_power = (val)),true)
end_define

begin_define
define|#
directive|define
name|bfd_set_section_userdata
parameter_list|(
name|bfd
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|)
value|(((ptr)->userdata = (val)),true)
end_define

begin_typedef
typedef|typedef
name|struct
name|stat
name|stat_type
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/** Error handling */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|bfd_error
block|{
name|no_error
init|=
literal|0
block|,
name|system_call_error
block|,
name|invalid_target
block|,
name|wrong_format
block|,
name|invalid_operation
block|,
name|no_memory
block|,
name|no_symbols
block|,
name|no_relocation_info
block|,
name|no_more_archived_files
block|,
name|malformed_archive
block|,
name|symbol_not_found
block|,
name|file_not_recognized
block|,
name|file_ambiguously_recognized
block|,
name|no_contents
block|,
name|bfd_error_nonrepresentable_section
block|,
name|no_debug_section
block|,
name|bad_value
block|,
comment|/* An input file is shorter than expected.  */
name|file_truncated
block|,
name|invalid_error_code
block|}
name|bfd_ec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bfd_ec
name|bfd_error
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|reloc_cache_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bfd_seclet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|bfd_error_vector
block|{
name|void
argument_list|(
argument|* nonrepresentable_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
name|bfd
operator|*
name|CONST
name|abfd
operator|,
name|CONST
name|char
operator|*
name|CONST
name|name
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* undefined_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
name|CONST
expr|struct
name|bfd_seclet
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* reloc_value_truncated
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
expr|struct
name|bfd_seclet
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* reloc_dangerous
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
expr|struct
name|reloc_cache_entry
operator|*
name|rel
operator|,
name|CONST
expr|struct
name|bfd_seclet
operator|*
name|sec
operator|)
argument_list|)
expr_stmt|;
block|}
name|bfd_error_vector_type
typedef|;
end_typedef

begin_decl_stmt
name|CONST
name|char
modifier|*
name|bfd_errmsg
name|PARAMS
argument_list|(
operator|(
name|bfd_ec
name|error_tag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_perror
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_typedef
typedef|typedef
enum|enum
name|bfd_print_symbol
block|{
name|bfd_print_symbol_name
block|,
name|bfd_print_symbol_more
block|,
name|bfd_print_symbol_all
block|}
name|bfd_print_symbol_type
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Information about a symbol that nm needs.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_symbol_info
block|{
name|symvalue
name|value
decl_stmt|;
name|char
name|type
decl_stmt|;
comment|/*  */
name|CONST
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Symbol name.  */
name|char
name|stab_other
decl_stmt|;
comment|/* Unused. */
name|short
name|stab_desc
decl_stmt|;
comment|/* Info for N_TYPE.  */
name|CONST
name|char
modifier|*
name|stab_name
decl_stmt|;
block|}
name|symbol_info
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* The code that implements targets can initialize a jump table with this    macro.  It must name all its routines the same way (a prefix plus    the standard routine suffix), or it must #define the routines that    are not so named, before calling JUMP_TABLE in the initializer.  */
end_comment

begin_comment
comment|/* Semi-portable string concatenation in cpp.    The CAT4 hack is to avoid a problem with some strict ANSI C preprocessors.    The problem is, "32_" is not a valid preprocessing token, and we don't    want extra underscores (e.g., "nlm_32_").  The XCAT2 macro will cause the    inner CAT macros to be evaluated first, producing still-valid pp-tokens.    Then the final concatenation can be done.  (Sigh.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SABER
end_ifdef

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a##b##c##d
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|XCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CAT(a,b)
end_define

begin_define
define|#
directive|define
name|CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|XCAT2(CAT(a,b),CAT(c,d))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_define
define|#
directive|define
name|CAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
end_define

begin_define
define|#
directive|define
name|CAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
comment|/**/
value|d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JUMP_TABLE
parameter_list|(
name|NAME
parameter_list|)
define|\
value|CAT(NAME,_core_file_failing_command),\ CAT(NAME,_core_file_failing_signal),\ CAT(NAME,_core_file_matches_executable_p),\ CAT(NAME,_slurp_armap),\ CAT(NAME,_slurp_extended_name_table),\ CAT(NAME,_truncate_arname),\ CAT(NAME,_write_armap),\ CAT(NAME,_close_and_cleanup),\ CAT(NAME,_set_section_contents),\ CAT(NAME,_get_section_contents),\ CAT(NAME,_new_section_hook),\ CAT(NAME,_get_symtab_upper_bound),\ CAT(NAME,_get_symtab),\ CAT(NAME,_get_reloc_upper_bound),\ CAT(NAME,_canonicalize_reloc),\ CAT(NAME,_make_empty_symbol),\ CAT(NAME,_print_symbol),\ CAT(NAME,_get_symbol_info),\ CAT(NAME,_get_lineno),\ CAT(NAME,_set_arch_mach),\ CAT(NAME,_openr_next_archived_file),\ CAT(NAME,_find_nearest_line),\ CAT(NAME,_generic_stat_arch_elt),\ CAT(NAME,_sizeof_headers),\ CAT(NAME,_bfd_debug_info_start),\ CAT(NAME,_bfd_debug_info_end),\ CAT(NAME,_bfd_debug_info_accumulate),\ CAT(NAME,_bfd_get_relocated_section_contents),\ CAT(NAME,_bfd_relax_section),\ CAT(NAME,_bfd_seclet_link),\ CAT(NAME,_bfd_reloc_type_lookup),\ CAT(NAME,_bfd_make_debug_symbol)
end_define

begin_define
define|#
directive|define
name|COFF_SWAP_TABLE
value|(PTR)&bfd_coff_std_swap_table
end_define

begin_escape
end_escape

begin_comment
comment|/* User program access to BFD facilities */
end_comment

begin_comment
comment|/* Cast from const char * to char * so that caller can assign to    a char * without a warning.  */
end_comment

begin_define
define|#
directive|define
name|bfd_get_filename
parameter_list|(
name|abfd
parameter_list|)
value|((char *) (abfd)->filename)
end_define

begin_define
define|#
directive|define
name|bfd_get_format
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->format)
end_define

begin_define
define|#
directive|define
name|bfd_get_target
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->name)
end_define

begin_define
define|#
directive|define
name|bfd_get_file_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->flags)
end_define

begin_define
define|#
directive|define
name|bfd_applicable_file_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->object_flags)
end_define

begin_define
define|#
directive|define
name|bfd_applicable_section_flags
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->section_flags)
end_define

begin_define
define|#
directive|define
name|bfd_my_archive
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->my_archive)
end_define

begin_define
define|#
directive|define
name|bfd_has_map
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->has_armap)
end_define

begin_define
define|#
directive|define
name|bfd_valid_reloc_types
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->valid_reloc_types)
end_define

begin_define
define|#
directive|define
name|bfd_usrdata
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->usrdata)
end_define

begin_define
define|#
directive|define
name|bfd_get_start_address
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->start_address)
end_define

begin_define
define|#
directive|define
name|bfd_get_symcount
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->symcount)
end_define

begin_define
define|#
directive|define
name|bfd_get_outsymbols
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->outsymbols)
end_define

begin_define
define|#
directive|define
name|bfd_count_sections
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->section_count)
end_define

begin_define
define|#
directive|define
name|bfd_get_symbol_leading_char
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->xvec->symbol_leading_char)
end_define

begin_comment
comment|/* Byte swapping routines.  */
end_comment

begin_decl_stmt
name|bfd_vma
name|bfd_getb64
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_getl64
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getb_signed_64
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getl_signed_64
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_getb32
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_getl32
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getb_signed_32
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getl_signed_32
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_getb16
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_getl16
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getb_signed_16
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_signed_vma
name|bfd_getl_signed_16
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putb64
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putl64
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putb32
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putl32
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putb16
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_putl16
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And more from the source.  */
end_comment

begin_decl_stmt
name|void
name|bfd_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_openr
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|filename
operator|,
name|CONST
name|char
operator|*
name|target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_fdopenr
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|filename
operator|,
name|CONST
name|char
operator|*
name|target
operator|,
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_openw
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|filename
operator|,
name|CONST
name|char
operator|*
name|target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_close
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_close_all_done
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_size_type
name|bfd_alloc_size
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_create
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|filename
operator|,
name|bfd
operator|*
name|templ
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Byte swapping macros for user section data.  */
end_comment

begin_define
define|#
directive|define
name|bfd_put_8
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(*((unsigned char *)(ptr)) = (unsigned char)val)
end_define

begin_define
define|#
directive|define
name|bfd_put_signed_8
define|\
value|bfd_put_8
end_define

begin_define
define|#
directive|define
name|bfd_get_8
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(*(unsigned char *)(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_get_signed_8
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((*(unsigned char *)(ptr) ^ 0x80) - 0x80)
end_define

begin_define
define|#
directive|define
name|bfd_put_16
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_putx16, ((val),(ptr)))
end_define

begin_define
define|#
directive|define
name|bfd_put_signed_16
define|\
value|bfd_put_16
end_define

begin_define
define|#
directive|define
name|bfd_get_16
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_getx16, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_get_signed_16
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND (abfd, bfd_getx_signed_16, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_put_32
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_putx32, ((val),(ptr)))
end_define

begin_define
define|#
directive|define
name|bfd_put_signed_32
define|\
value|bfd_put_32
end_define

begin_define
define|#
directive|define
name|bfd_get_32
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_getx32, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_get_signed_32
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_getx_signed_32, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_put_64
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_putx64, ((val), (ptr)))
end_define

begin_define
define|#
directive|define
name|bfd_put_signed_64
define|\
value|bfd_put_64
end_define

begin_define
define|#
directive|define
name|bfd_get_64
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_getx64, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_get_signed_64
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_getx_signed_64, (ptr))
end_define

begin_comment
comment|/* Byte swapping macros for file header data.  */
end_comment

begin_define
define|#
directive|define
name|bfd_h_put_8
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|bfd_put_8 (abfd, val, ptr)
end_define

begin_define
define|#
directive|define
name|bfd_h_put_signed_8
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|bfd_put_8 (abfd, val, ptr)
end_define

begin_define
define|#
directive|define
name|bfd_h_get_8
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|bfd_get_8 (abfd, ptr)
end_define

begin_define
define|#
directive|define
name|bfd_h_get_signed_8
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|bfd_get_signed_8 (abfd, ptr)
end_define

begin_define
define|#
directive|define
name|bfd_h_put_16
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_putx16,(val,ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_put_signed_16
define|\
value|bfd_h_put_16
end_define

begin_define
define|#
directive|define
name|bfd_h_get_16
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx16,(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_get_signed_16
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx_signed_16, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_put_32
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_putx32,(val,ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_put_signed_32
define|\
value|bfd_h_put_32
end_define

begin_define
define|#
directive|define
name|bfd_h_get_32
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx32,(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_get_signed_32
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx_signed_32, (ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_put_64
parameter_list|(
name|abfd
parameter_list|,
name|val
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_putx64,(val, ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_put_signed_64
define|\
value|bfd_h_put_64
end_define

begin_define
define|#
directive|define
name|bfd_h_get_64
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx64,(ptr))
end_define

begin_define
define|#
directive|define
name|bfd_h_get_signed_64
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|)
define|\
value|BFD_SEND(abfd, bfd_h_getx_signed_64, (ptr))
end_define

begin_typedef
typedef|typedef
struct|struct
name|sec
block|{
comment|/* The name of the section, the name isn't a copy, the pointer is         the same as that passed to bfd_make_section. */
name|CONST
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Which section is it 0.nth      */
name|int
name|index
decl_stmt|;
comment|/* The next section in the list belonging to the BFD, or NULL. */
name|struct
name|sec
modifier|*
name|next
decl_stmt|;
comment|/* The field flags contains attributes of the section. Some of            flags are read in from the object file, and some are            synthesized from other information.  */
name|flagword
name|flags
decl_stmt|;
define|#
directive|define
name|SEC_NO_FLAGS
value|0x000
comment|/* Tells the OS to allocate space for this section when loaded.            This would clear for a section containing debug information            only. */
define|#
directive|define
name|SEC_ALLOC
value|0x001
comment|/* Tells the OS to load the section from the file when loading.            This would be clear for a .bss section */
define|#
directive|define
name|SEC_LOAD
value|0x002
comment|/* The section contains data still to be relocated, so there will            be some relocation information too. */
define|#
directive|define
name|SEC_RELOC
value|0x004
if|#
directive|if
literal|0
comment|/* Obsolete ? */
define|#
directive|define
name|SEC_BALIGN
value|0x008
endif|#
directive|endif
comment|/* A signal to the OS that the section contains read only           data. */
define|#
directive|define
name|SEC_READONLY
value|0x010
comment|/* The section contains code only. */
define|#
directive|define
name|SEC_CODE
value|0x020
comment|/* The section contains data only. */
define|#
directive|define
name|SEC_DATA
value|0x040
comment|/* The section will reside in ROM. */
define|#
directive|define
name|SEC_ROM
value|0x080
comment|/* The section contains constructor information. This section            type is used by the linker to create lists of constructors and            destructors used by<<g++>>. When a back end sees a symbol            which should be used in a constructor list, it creates a new            section for the type of name (eg<<__CTOR_LIST__>>), attaches            the symbol to it and builds a relocation. To build the lists            of constructors, all the linker has to do is catenate all the            sections called<<__CTOR_LIST__>> and relocte the data            contained within - exactly the operations it would peform on            standard data. */
define|#
directive|define
name|SEC_CONSTRUCTOR
value|0x100
comment|/* The section is a constuctor, and should be placed at the           end of the text, data, or bss section(?). */
define|#
directive|define
name|SEC_CONSTRUCTOR_TEXT
value|0x1100
define|#
directive|define
name|SEC_CONSTRUCTOR_DATA
value|0x2100
define|#
directive|define
name|SEC_CONSTRUCTOR_BSS
value|0x3100
comment|/* The section has contents - a data section could be<<SEC_ALLOC>> |<<SEC_HAS_CONTENTS>>, a debug section could be<<SEC_HAS_CONTENTS>> */
define|#
directive|define
name|SEC_HAS_CONTENTS
value|0x200
comment|/* An instruction to the linker not to output sections           containing this flag even if they have information which           would normally be written. */
define|#
directive|define
name|SEC_NEVER_LOAD
value|0x400
comment|/* The section is a shared library section.  The linker must leave            these completely alone, as the vma and size are used when            the executable is loaded. */
define|#
directive|define
name|SEC_SHARED_LIBRARY
value|0x800
comment|/* The section is a common section (symbols may be defined            multiple times, the value of a symbol is the amount of            space it requires, and the largest symbol value is the one            used).  Most targets have exactly one of these (which we 	    translate to bfd_com_section), but ECOFF has two. */
define|#
directive|define
name|SEC_IS_COMMON
value|0x8000
comment|/* The section contains only debugging information.  For            example, this is set for ELF .debug and .stab sections.            strip tests this flag to see if a section can be            discarded. */
define|#
directive|define
name|SEC_DEBUGGING
value|0x10000
comment|/*  End of section flags.  */
comment|/*  The virtual memory address of the section - where it will be            at run time.  The symbols are relocated against this.  The 	    user_set_vma flag is maintained by bfd; if it's not set, the 	    backend can assign addresses (for example, in<<a.out>>, where 	    the default address for<<.data>> is dependent on the specific 	    target and various flags).  */
name|bfd_vma
name|vma
decl_stmt|;
name|boolean
name|user_set_vma
decl_stmt|;
comment|/*  The load address of the section - where it would be in a            rom image, really only used for writing section header 	    information. */
name|bfd_vma
name|lma
decl_stmt|;
comment|/* The size of the section in bytes, as it will be output.            contains a value even if the section has no contents (eg, the            size of<<.bss>>). This will be filled in after relocation */
name|bfd_size_type
name|_cooked_size
decl_stmt|;
comment|/* The size on disk of the section in bytes originally.  Normally this 	    value is the same as the size, but if some relaxing has 	    been done, then this value will be bigger.  */
name|bfd_size_type
name|_raw_size
decl_stmt|;
comment|/* If this section is going to be output, then this value is the            offset into the output section of the first byte in the input            section. Eg, if this was going to start at the 100th byte in            the output section, this value would be 100. */
name|bfd_vma
name|output_offset
decl_stmt|;
comment|/* The output section through which to map on output. */
name|struct
name|sec
modifier|*
name|output_section
decl_stmt|;
comment|/* The alignment requirement of the section, as an exponent - eg            3 aligns to 2^3 (or 8) */
name|unsigned
name|int
name|alignment_power
decl_stmt|;
comment|/* If an input section, a pointer to a vector of relocation            records for the data in this section. */
name|struct
name|reloc_cache_entry
modifier|*
name|relocation
decl_stmt|;
comment|/* If an output section, a pointer to a vector of pointers to            relocation records for the data in this section. */
name|struct
name|reloc_cache_entry
modifier|*
modifier|*
name|orelocation
decl_stmt|;
comment|/* The number of relocation records in one of the above  */
name|unsigned
name|reloc_count
decl_stmt|;
comment|/* Information below is back end specific - and not always used            or updated.  */
comment|/* File position of section data    */
name|file_ptr
name|filepos
decl_stmt|;
comment|/* File position of relocation info */
name|file_ptr
name|rel_filepos
decl_stmt|;
comment|/* File position of line data       */
name|file_ptr
name|line_filepos
decl_stmt|;
comment|/* Pointer to data for applications */
name|PTR
name|userdata
decl_stmt|;
name|struct
name|lang_output_section
modifier|*
name|otheruserdata
decl_stmt|;
comment|/* Attached line number information */
name|alent
modifier|*
name|lineno
decl_stmt|;
comment|/* Number of line number records   */
name|unsigned
name|int
name|lineno_count
decl_stmt|;
comment|/* When a section is being output, this value changes as more            linenumbers are written out */
name|file_ptr
name|moving_line_filepos
decl_stmt|;
comment|/* what the section number is in the target world  */
name|int
name|target_index
decl_stmt|;
name|PTR
name|used_by_bfd
decl_stmt|;
comment|/* If this is a constructor section then here is a list of the            relocations created to relocate items within it. */
name|struct
name|relent_chain
modifier|*
name|constructor_chain
decl_stmt|;
comment|/* The BFD which owns the section. */
name|bfd
modifier|*
name|owner
decl_stmt|;
name|boolean
name|reloc_done
decl_stmt|;
comment|/* A symbol which points at this section only */
name|struct
name|symbol_cache_entry
modifier|*
name|symbol
decl_stmt|;
name|struct
name|symbol_cache_entry
modifier|*
modifier|*
name|symbol_ptr_ptr
decl_stmt|;
name|struct
name|bfd_seclet
modifier|*
name|seclets_head
decl_stmt|;
name|struct
name|bfd_seclet
modifier|*
name|seclets_tail
decl_stmt|;
block|}
name|asection
typedef|;
end_typedef

begin_comment
comment|/* These sections are global, and are managed by BFD.  The application        and target back end are not permitted to change the values in 	these sections.  */
end_comment

begin_define
define|#
directive|define
name|BFD_ABS_SECTION_NAME
value|"*ABS*"
end_define

begin_define
define|#
directive|define
name|BFD_UND_SECTION_NAME
value|"*UND*"
end_define

begin_define
define|#
directive|define
name|BFD_COM_SECTION_NAME
value|"*COM*"
end_define

begin_define
define|#
directive|define
name|BFD_IND_SECTION_NAME
value|"*IND*"
end_define

begin_comment
comment|/* the absolute section */
end_comment

begin_decl_stmt
specifier|extern
name|asection
name|bfd_abs_section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the undefined section */
end_comment

begin_decl_stmt
specifier|extern
name|asection
name|bfd_und_section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the common section */
end_comment

begin_decl_stmt
specifier|extern
name|asection
name|bfd_com_section
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the indirect section */
end_comment

begin_decl_stmt
specifier|extern
name|asection
name|bfd_ind_section
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol_cache_entry
modifier|*
name|bfd_abs_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol_cache_entry
modifier|*
name|bfd_com_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol_cache_entry
modifier|*
name|bfd_und_symbol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol_cache_entry
modifier|*
name|bfd_ind_symbol
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bfd_get_section_size_before_reloc
parameter_list|(
name|section
parameter_list|)
define|\
value|(section->reloc_done ? (abort(),1): (section)->_raw_size)
end_define

begin_define
define|#
directive|define
name|bfd_get_section_size_after_reloc
parameter_list|(
name|section
parameter_list|)
define|\
value|((section->reloc_done) ? (section)->_cooked_size: (abort(),1))
end_define

begin_decl_stmt
name|asection
modifier|*
name|bfd_get_section_by_name
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|asection
modifier|*
name|bfd_make_section_old_way
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|asection
modifier|*
name|bfd_make_section_anyway
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|asection
modifier|*
name|bfd_make_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|CONST
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_section_flags
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|flagword
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_map_over_sections
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|void
argument_list|(
argument|*func
argument_list|)
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sect
operator|,
name|PTR
name|obj
operator|)
operator|,
name|PTR
name|obj
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_section_size
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_size_type
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_section_contents
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|PTR
name|data
operator|,
name|file_ptr
name|offset
operator|,
name|bfd_size_type
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_get_section_contents
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|section
operator|,
name|PTR
name|location
operator|,
name|file_ptr
name|offset
operator|,
name|bfd_size_type
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|bfd_architecture
block|{
name|bfd_arch_unknown
block|,
comment|/* File arch not known */
name|bfd_arch_obscure
block|,
comment|/* Arch known, not one of these */
name|bfd_arch_m68k
block|,
comment|/* Motorola 68xxx */
name|bfd_arch_vax
block|,
comment|/* DEC Vax */
name|bfd_arch_i960
block|,
comment|/* Intel 960 */
comment|/* The order of the following is important.        lower number indicates a machine type that         only accepts a subset of the instructions        available to machines with higher numbers.        The exception is the "ca", which is        incompatible with all other machines except         "core". */
define|#
directive|define
name|bfd_mach_i960_core
value|1
define|#
directive|define
name|bfd_mach_i960_ka_sa
value|2
define|#
directive|define
name|bfd_mach_i960_kb_sb
value|3
define|#
directive|define
name|bfd_mach_i960_mc
value|4
define|#
directive|define
name|bfd_mach_i960_xa
value|5
define|#
directive|define
name|bfd_mach_i960_ca
value|6
name|bfd_arch_a29k
block|,
comment|/* AMD 29000 */
name|bfd_arch_sparc
block|,
comment|/* SPARC */
name|bfd_arch_mips
block|,
comment|/* MIPS Rxxxx */
name|bfd_arch_i386
block|,
comment|/* Intel 386 */
name|bfd_arch_we32k
block|,
comment|/* AT&T WE32xxx */
name|bfd_arch_tahoe
block|,
comment|/* CCI/Harris Tahoe */
name|bfd_arch_i860
block|,
comment|/* Intel 860 */
name|bfd_arch_romp
block|,
comment|/* IBM ROMP PC/RT */
name|bfd_arch_alliant
block|,
comment|/* Alliant */
name|bfd_arch_convex
block|,
comment|/* Convex */
name|bfd_arch_m88k
block|,
comment|/* Motorola 88xxx */
name|bfd_arch_pyramid
block|,
comment|/* Pyramid Technology */
name|bfd_arch_h8300
block|,
comment|/* Hitachi H8/300 */
define|#
directive|define
name|bfd_mach_h8300
value|1
define|#
directive|define
name|bfd_mach_h8300h
value|2
name|bfd_arch_rs6000
block|,
comment|/* IBM RS/6000 */
name|bfd_arch_hppa
block|,
comment|/* HP PA RISC */
name|bfd_arch_z8k
block|,
comment|/* Zilog Z8000 */
define|#
directive|define
name|bfd_mach_z8001
value|1
define|#
directive|define
name|bfd_mach_z8002
value|2
name|bfd_arch_h8500
block|,
comment|/* Hitachi H8/500 */
name|bfd_arch_sh
block|,
comment|/* Hitachi SH */
name|bfd_arch_alpha
block|,
comment|/* Dec Alpha */
name|bfd_arch_last
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|bfd_arch_info
block|{
name|int
name|bits_per_word
decl_stmt|;
name|int
name|bits_per_address
decl_stmt|;
name|int
name|bits_per_byte
decl_stmt|;
name|enum
name|bfd_architecture
name|arch
decl_stmt|;
name|long
name|mach
decl_stmt|;
name|char
modifier|*
name|arch_name
decl_stmt|;
name|CONST
name|char
modifier|*
name|printable_name
decl_stmt|;
name|unsigned
name|int
name|section_align_power
decl_stmt|;
comment|/* true if this is the default machine for the architecture */
name|boolean
name|the_default
decl_stmt|;
name|CONST
name|struct
name|bfd_arch_info
modifier|*
argument_list|(
operator|*
name|compatible
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
expr|struct
name|bfd_arch_info
operator|*
name|a
operator|,
name|CONST
expr|struct
name|bfd_arch_info
operator|*
name|b
operator|)
argument_list|)
decl_stmt|;
name|boolean
argument_list|(
argument|*scan
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CONST
expr|struct
name|bfd_arch_info
operator|*
operator|,
name|CONST
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* How to disassemble an instruction, producing a printable      representation on a specified stdio stream.  This isn't      defined for most processors at present, because of the size      of the additional tables it would drag in, and because gdb      wants to use a different interface.  */
name|unsigned
name|int
argument_list|(
operator|*
name|disassemble
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
name|addr
operator|,
name|CONST
name|char
operator|*
name|data
operator|,
name|PTR
name|stream
operator|)
argument_list|)
decl_stmt|;
name|struct
name|bfd_arch_info
modifier|*
name|next
decl_stmt|;
block|}
name|bfd_arch_info_type
typedef|;
end_typedef

begin_decl_stmt
name|CONST
name|char
modifier|*
name|bfd_printable_name
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_arch_info_type
modifier|*
name|bfd_scan_arch
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CONST
name|bfd_arch_info_type
modifier|*
name|bfd_arch_get_compatible
name|PARAMS
argument_list|(
operator|(
name|CONST
name|bfd
operator|*
name|abfd
operator|,
name|CONST
name|bfd
operator|*
name|bbfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_set_arch_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_arch_info_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|bfd_architecture
name|bfd_get_arch
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|bfd_get_mach
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|bfd_arch_bits_per_byte
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|bfd_arch_bits_per_address
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_arch_info_type
modifier|*
name|bfd_get_arch_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_arch_info_type
modifier|*
name|bfd_lookup_arch
name|PARAMS
argument_list|(
operator|(
expr|enum
name|bfd_architecture
name|arch
operator|,
name|long
name|machine
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CONST
name|char
modifier|*
name|bfd_printable_arch_mach
name|PARAMS
argument_list|(
operator|(
expr|enum
name|bfd_architecture
name|arch
operator|,
name|unsigned
name|long
name|machine
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
name|bfd_reloc_status
block|{
comment|/* No errors detected */
name|bfd_reloc_ok
block|,
comment|/* The relocation was performed, but there was an overflow. */
name|bfd_reloc_overflow
block|,
comment|/* The address to relocate was not within the section supplied. */
name|bfd_reloc_outofrange
block|,
comment|/* Used by special functions */
name|bfd_reloc_continue
block|,
comment|/* Unused */
name|bfd_reloc_notsupported
block|,
comment|/* Unsupported relocation size requested. */
name|bfd_reloc_other
block|,
comment|/* The symbol to relocate against was undefined. */
name|bfd_reloc_undefined
block|,
comment|/* The relocation was performed, but may not be ok - presently           generated only when linking i960 coff files with i960 b.out           symbols. */
name|bfd_reloc_dangerous
block|}
name|bfd_reloc_status_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|reloc_cache_entry
block|{
comment|/* A pointer into the canonical table of pointers  */
name|struct
name|symbol_cache_entry
modifier|*
modifier|*
name|sym_ptr_ptr
decl_stmt|;
comment|/* offset in section */
name|bfd_size_type
name|address
decl_stmt|;
comment|/* addend for relocation value */
name|bfd_vma
name|addend
decl_stmt|;
comment|/* Pointer to how to perform the required relocation */
name|CONST
name|struct
name|reloc_howto_struct
modifier|*
name|howto
decl_stmt|;
block|}
name|arelent
typedef|;
end_typedef

begin_enum
enum|enum
name|complain_overflow
block|{
comment|/* Do not complain on overflow. */
name|complain_overflow_dont
block|,
comment|/* Complain if the bitfield overflows, whether it is considered 	   as signed or unsigned. */
name|complain_overflow_bitfield
block|,
comment|/* Complain if the value overflows when considered as signed 	   number. */
name|complain_overflow_signed
block|,
comment|/* Complain if the value overflows when considered as an 	   unsigned number. */
name|complain_overflow_unsigned
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|CONST
struct|struct
name|reloc_howto_struct
block|{
comment|/*  The type field has mainly a documetary use - the back end can            to what it wants with it, though the normally the back end's            external idea of what a reloc number would be would be stored            in this field. For example, the a PC relative word relocation            in a coff environment would have the type 023 - because that's            what the outside world calls a R_PCRWORD reloc. */
name|unsigned
name|int
name|type
decl_stmt|;
comment|/*  The value the final relocation is shifted right by. This drops            unwanted data from the relocation.  */
name|unsigned
name|int
name|rightshift
decl_stmt|;
comment|/*  The size of the item to be relocated.  This is *not* a 	    power-of-two measure. 		 0 : one byte 		 1 : two bytes 		 2 : four bytes 		 3 : nothing done (unless special_function is nonzero) 		 4 : eight bytes 		-2 : two bytes, result should be subtracted from the 		     data instead of added 	    There is currently no trivial way to extract a "number of 	    bytes" from a howto pointer.  */
name|int
name|size
decl_stmt|;
comment|/*  The number of bits in the item to be relocated.  This is used 	    when doing overflow checking.  */
name|unsigned
name|int
name|bitsize
decl_stmt|;
comment|/*  Notes that the relocation is relative to the location in the            data section of the addend. The relocation function will            subtract from the relocation value the address of the location            being relocated. */
name|boolean
name|pc_relative
decl_stmt|;
comment|/*  The bit position of the reloc value in the destination. 	    The relocated value is left shifted by this amount. */
name|unsigned
name|int
name|bitpos
decl_stmt|;
comment|/* What type of overflow error should be checked for when 	   relocating. */
name|enum
name|complain_overflow
name|complain_on_overflow
decl_stmt|;
comment|/* If this field is non null, then the supplied function is           called rather than the normal function. This allows really           strange relocation methods to be accomodated (e.g., i960 callj           instructions). */
name|bfd_reloc_status_type
argument_list|(
argument|*special_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|arelent
operator|*
name|reloc_entry
operator|,
expr|struct
name|symbol_cache_entry
operator|*
name|symbol
operator|,
name|PTR
name|data
operator|,
name|asection
operator|*
name|input_section
operator|,
name|bfd
operator|*
name|output_bfd
operator|)
argument_list|)
expr_stmt|;
comment|/* The textual name of the relocation type. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* When performing a partial link, some formats must modify the           relocations rather than the data - this flag signals this.*/
name|boolean
name|partial_inplace
decl_stmt|;
comment|/* The src_mask is used to select what parts of the read in data           are to be used in the relocation sum.  E.g., if this was an 8 bit           bit of data which we read and relocated, this would be           0x000000ff. When we have relocs which have an addend, such as           sun4 extended relocs, the value in the offset part of a           relocating field is garbage so we never use it. In this case           the mask would be 0x00000000. */
name|bfd_vma
name|src_mask
decl_stmt|;
comment|/* The dst_mask is what parts of the instruction are replaced           into the instruction. In most cases src_mask == dst_mask,           except in the above special case, where dst_mask would be           0x000000ff, and src_mask would be 0x00000000.   */
name|bfd_vma
name|dst_mask
decl_stmt|;
comment|/* When some formats create PC relative instructions, they leave           the value of the pc of the place being relocated in the offset           slot of the instruction, so that a PC relative relocation can           be made just by adding in an ordinary offset (e.g., sun3 a.out).           Some formats leave the displacement part of an instruction           empty (e.g., m88k bcs), this flag signals the fact.*/
name|boolean
name|pcrel_offset
decl_stmt|;
block|}
name|reloc_howto_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HOWTO
parameter_list|(
name|C
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|,
name|B
parameter_list|,
name|P
parameter_list|,
name|BI
parameter_list|,
name|O
parameter_list|,
name|SF
parameter_list|,
name|NAME
parameter_list|,
name|INPLACE
parameter_list|,
name|MASKSRC
parameter_list|,
name|MASKDST
parameter_list|,
name|PC
parameter_list|)
define|\
value|{(unsigned)C,R,S,B, P, BI, O,SF,NAME,INPLACE,MASKSRC,MASKDST,PC}
end_define

begin_define
define|#
directive|define
name|NEWHOWTO
parameter_list|(
name|FUNCTION
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|REL
parameter_list|,
name|IN
parameter_list|)
value|HOWTO(0,0,SIZE,0,REL,0,complain_overflow_dont,FUNCTION, NAME,false,0,0,IN)
end_define

begin_define
define|#
directive|define
name|HOWTO_PREPARE
parameter_list|(
name|relocation
parameter_list|,
name|symbol
parameter_list|)
define|\
value|{                                            \   if (symbol != (asymbol *)NULL) {             \     if (bfd_is_com_section (symbol->section)) { \       relocation = 0;                          \     }                                          \     else {                                     \       relocation = symbol->value;              \     }                                          \   }                                            \ }
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bfd_byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|relent_chain
block|{
name|arelent
name|relent
decl_stmt|;
name|struct
name|relent_chain
modifier|*
name|next
decl_stmt|;
block|}
name|arelent_chain
typedef|;
end_typedef

begin_decl_stmt
name|bfd_reloc_status_type
name|bfd_perform_relocation
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|arelent
operator|*
name|reloc_entry
operator|,
name|PTR
name|data
operator|,
name|asection
operator|*
name|input_section
operator|,
name|bfd
operator|*
name|output_bfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
name|bfd_reloc_code_real
block|{
comment|/* Basic absolute relocations */
name|BFD_RELOC_64
block|,
name|BFD_RELOC_32
block|,
name|BFD_RELOC_16
block|,
name|BFD_RELOC_8
block|,
comment|/* PC-relative relocations */
name|BFD_RELOC_64_PCREL
block|,
name|BFD_RELOC_32_PCREL
block|,
name|BFD_RELOC_24_PCREL
block|,
comment|/* used by i960 */
name|BFD_RELOC_16_PCREL
block|,
name|BFD_RELOC_8_PCREL
block|,
comment|/* Linkage-table relative */
name|BFD_RELOC_32_BASEREL
block|,
name|BFD_RELOC_16_BASEREL
block|,
name|BFD_RELOC_8_BASEREL
block|,
comment|/* The type of reloc used to build a contructor table - at the moment      probably a 32 bit wide abs address, but the cpu can choose. */
name|BFD_RELOC_CTOR
block|,
comment|/* 8 bits wide, but used to form an address like 0xffnn */
name|BFD_RELOC_8_FFnn
block|,
comment|/* 32-bit pc-relative, shifted right 2 bits (i.e., 30-bit      word displacement, e.g. for SPARC) */
name|BFD_RELOC_32_PCREL_S2
block|,
comment|/* High 22 bits of 32-bit value, placed into lower 22 bits of      target word; simple reloc.  */
name|BFD_RELOC_HI22
block|,
comment|/* Low 10 bits.  */
name|BFD_RELOC_LO10
block|,
comment|/* Reloc types used for i960/b.out.  */
name|BFD_RELOC_I960_CALLJ
block|,
comment|/* now for the sparc/elf codes */
name|BFD_RELOC_NONE
block|,
comment|/* actually used */
name|BFD_RELOC_SPARC_WDISP22
block|,
name|BFD_RELOC_SPARC22
block|,
name|BFD_RELOC_SPARC13
block|,
name|BFD_RELOC_SPARC_GOT10
block|,
name|BFD_RELOC_SPARC_GOT13
block|,
name|BFD_RELOC_SPARC_GOT22
block|,
name|BFD_RELOC_SPARC_PC10
block|,
name|BFD_RELOC_SPARC_PC22
block|,
name|BFD_RELOC_SPARC_WPLT30
block|,
name|BFD_RELOC_SPARC_COPY
block|,
name|BFD_RELOC_SPARC_GLOB_DAT
block|,
name|BFD_RELOC_SPARC_JMP_SLOT
block|,
name|BFD_RELOC_SPARC_RELATIVE
block|,
name|BFD_RELOC_SPARC_UA32
block|,
comment|/* these are a.out specific? */
name|BFD_RELOC_SPARC_BASE13
block|,
name|BFD_RELOC_SPARC_BASE22
block|,
comment|/* Bits 27..2 of the relocation address shifted right 2 bits;      simple reloc otherwise.  */
name|BFD_RELOC_MIPS_JMP
block|,
comment|/* signed 16-bit pc-relative, shifted right 2 bits (e.g. for MIPS) */
name|BFD_RELOC_16_PCREL_S2
block|,
comment|/* High 16 bits of 32-bit value; simple reloc.  */
name|BFD_RELOC_HI16
block|,
comment|/* High 16 bits of 32-bit value but the low 16 bits will be sign      extended and added to form the final result.  If the low 16      bits form a negative number, we need to add one to the high value      to compensate for the borrow when the low bits are added.  */
name|BFD_RELOC_HI16_S
block|,
comment|/* Low 16 bits.  */
name|BFD_RELOC_LO16
block|,
comment|/* 16 bit relocation relative to the global pointer.  */
name|BFD_RELOC_MIPS_GPREL
block|,
comment|/* These are, so far, specific to HPPA processors.  I'm not sure that some      don't duplicate other reloc types, such as BFD_RELOC_32 and _32_PCREL.      Also, many more were in the list I got that don't fit in well in the      model BFD uses, so I've omitted them for now.  If we do make this reloc      type get used for code that really does implement the funky reloc types,      they'll have to be added to this list.  */
name|BFD_RELOC_HPPA_32
block|,
name|BFD_RELOC_HPPA_11
block|,
name|BFD_RELOC_HPPA_14
block|,
name|BFD_RELOC_HPPA_17
block|,
name|BFD_RELOC_HPPA_L21
block|,
name|BFD_RELOC_HPPA_R11
block|,
name|BFD_RELOC_HPPA_R14
block|,
name|BFD_RELOC_HPPA_R17
block|,
name|BFD_RELOC_HPPA_LS21
block|,
name|BFD_RELOC_HPPA_RS11
block|,
name|BFD_RELOC_HPPA_RS14
block|,
name|BFD_RELOC_HPPA_RS17
block|,
name|BFD_RELOC_HPPA_LD21
block|,
name|BFD_RELOC_HPPA_RD11
block|,
name|BFD_RELOC_HPPA_RD14
block|,
name|BFD_RELOC_HPPA_RD17
block|,
name|BFD_RELOC_HPPA_LR21
block|,
name|BFD_RELOC_HPPA_RR14
block|,
name|BFD_RELOC_HPPA_RR17
block|,
name|BFD_RELOC_HPPA_GOTOFF_11
block|,
name|BFD_RELOC_HPPA_GOTOFF_14
block|,
name|BFD_RELOC_HPPA_GOTOFF_L21
block|,
name|BFD_RELOC_HPPA_GOTOFF_R11
block|,
name|BFD_RELOC_HPPA_GOTOFF_R14
block|,
name|BFD_RELOC_HPPA_GOTOFF_LS21
block|,
name|BFD_RELOC_HPPA_GOTOFF_RS11
block|,
name|BFD_RELOC_HPPA_GOTOFF_RS14
block|,
name|BFD_RELOC_HPPA_GOTOFF_LD21
block|,
name|BFD_RELOC_HPPA_GOTOFF_RD11
block|,
name|BFD_RELOC_HPPA_GOTOFF_RD14
block|,
name|BFD_RELOC_HPPA_GOTOFF_LR21
block|,
name|BFD_RELOC_HPPA_GOTOFF_RR14
block|,
name|BFD_RELOC_HPPA_DLT_32
block|,
name|BFD_RELOC_HPPA_DLT_11
block|,
name|BFD_RELOC_HPPA_DLT_14
block|,
name|BFD_RELOC_HPPA_DLT_L21
block|,
name|BFD_RELOC_HPPA_DLT_R11
block|,
name|BFD_RELOC_HPPA_DLT_R14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_11
block|,
name|BFD_RELOC_HPPA_ABS_CALL_14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_17
block|,
name|BFD_RELOC_HPPA_ABS_CALL_L21
block|,
name|BFD_RELOC_HPPA_ABS_CALL_R11
block|,
name|BFD_RELOC_HPPA_ABS_CALL_R14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_R17
block|,
name|BFD_RELOC_HPPA_ABS_CALL_LS21
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RS11
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RS14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RS17
block|,
name|BFD_RELOC_HPPA_ABS_CALL_LD21
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RD11
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RD14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RD17
block|,
name|BFD_RELOC_HPPA_ABS_CALL_LR21
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RR14
block|,
name|BFD_RELOC_HPPA_ABS_CALL_RR17
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_11
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_12
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_14
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_17
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_L21
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_R11
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_R14
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_R17
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_LS21
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RS11
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RS14
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RS17
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_LD21
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RD11
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RD14
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RD17
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_LR21
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RR14
block|,
name|BFD_RELOC_HPPA_PCREL_CALL_RR17
block|,
name|BFD_RELOC_HPPA_PLABEL_32
block|,
name|BFD_RELOC_HPPA_PLABEL_11
block|,
name|BFD_RELOC_HPPA_PLABEL_14
block|,
name|BFD_RELOC_HPPA_PLABEL_L21
block|,
name|BFD_RELOC_HPPA_PLABEL_R11
block|,
name|BFD_RELOC_HPPA_PLABEL_R14
block|,
name|BFD_RELOC_HPPA_UNWIND_ENTRY
block|,
name|BFD_RELOC_HPPA_UNWIND_ENTRIES
block|,
comment|/* i386/elf relocations */
name|BFD_RELOC_386_GOT32
block|,
name|BFD_RELOC_386_PLT32
block|,
name|BFD_RELOC_386_COPY
block|,
name|BFD_RELOC_386_GLOB_DAT
block|,
name|BFD_RELOC_386_JUMP_SLOT
block|,
name|BFD_RELOC_386_RELATIVE
block|,
name|BFD_RELOC_386_GOTOFF
block|,
name|BFD_RELOC_386_GOTPC
block|,
comment|/* this must be the highest numeric value */
name|BFD_RELOC_UNUSED
block|}
name|bfd_reloc_code_real_type
typedef|;
end_typedef

begin_decl_stmt
name|CONST
name|struct
name|reloc_howto_struct
modifier|*
name|bfd_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|symbol_cache_entry
block|{
comment|/* A pointer to the BFD which owns the symbol. This information 	   is necessary so that a back end can work out what additional    	   information (invisible to the application writer) is carried 	   with the symbol.  	   This field is *almost* redundant, since you can use section->owner 	   instead, except that some symbols point to the global sections 	   bfd_{abs,com,und}_section.  This could be fixed by making 	   these globals be per-bfd (or per-target-flavor).  FIXME. */
name|struct
name|_bfd
modifier|*
name|the_bfd
decl_stmt|;
comment|/* Use bfd_asymbol_bfd(sym) to access this field. */
comment|/* The text of the symbol. The name is left alone, and not copied - the 	   application may not alter it. */
name|CONST
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The value of the symbol.  This really should be a union of a           numeric value with a pointer, since some flags indicate that           a pointer to another symbol is stored here.  */
name|symvalue
name|value
decl_stmt|;
comment|/* Attributes of a symbol: */
define|#
directive|define
name|BSF_NO_FLAGS
value|0x00
comment|/* The symbol has local scope;<<static>> in<<C>>. The value  	   is the offset into the section of the data. */
define|#
directive|define
name|BSF_LOCAL
value|0x01
comment|/* The symbol has global scope; initialized data in<<C>>. The 	   value is the offset into the section of the data. */
define|#
directive|define
name|BSF_GLOBAL
value|0x02
comment|/* The symbol has global scope, and is exported. The value is 	   the offset into the section of the data. */
define|#
directive|define
name|BSF_EXPORT
value|BSF_GLOBAL
comment|/* no real difference */
comment|/* A normal C symbol would be one of:<<BSF_LOCAL>>,<<BSF_FORT_COMM>>,<<BSF_UNDEFINED>> or<<BSF_GLOBAL>> */
comment|/* The symbol is a debugging record. The value has an arbitary 	   meaning. */
define|#
directive|define
name|BSF_DEBUGGING
value|0x08
comment|/* The symbol denotes a function entry point.  Used in ELF, 	   perhaps others someday.  */
define|#
directive|define
name|BSF_FUNCTION
value|0x10
comment|/* Used by the linker. */
define|#
directive|define
name|BSF_KEEP
value|0x20
define|#
directive|define
name|BSF_KEEP_G
value|0x40
comment|/* A weak global symbol, overridable without warnings by 	   a regular global symbol of the same name.  */
define|#
directive|define
name|BSF_WEAK
value|0x80
comment|/* This symbol was created to point to a section, e.g. ELF's 	   STT_SECTION symbols.  */
define|#
directive|define
name|BSF_SECTION_SYM
value|0x100
comment|/* The symbol used to be a common symbol, but now it is 	   allocated. */
define|#
directive|define
name|BSF_OLD_COMMON
value|0x200
comment|/* The default value for common data. */
define|#
directive|define
name|BFD_FORT_COMM_DEFAULT_VALUE
value|0
comment|/* In some files the type of a symbol sometimes alters its 	   location in an output file - ie in coff a<<ISFCN>> symbol 	   which is also<<C_EXT>> symbol appears where it was 	   declared and not at the end of a section.  This bit is set   	   by the target BFD part to convey this information. */
define|#
directive|define
name|BSF_NOT_AT_END
value|0x400
comment|/* Signal that the symbol is the label of constructor section. */
define|#
directive|define
name|BSF_CONSTRUCTOR
value|0x800
comment|/* Signal that the symbol is a warning symbol. If the symbol 	   is a warning symbol, then the value field (I know this is 	   tacky) will point to the asymbol which when referenced will 	   cause the warning. */
define|#
directive|define
name|BSF_WARNING
value|0x1000
comment|/* Signal that the symbol is indirect. The value of the symbol 	   is a pointer to an undefined asymbol which contains the 	   name to use instead. */
define|#
directive|define
name|BSF_INDIRECT
value|0x2000
comment|/* BSF_FILE marks symbols that contain a file name.  This is used 	   for ELF STT_FILE symbols.  */
define|#
directive|define
name|BSF_FILE
value|0x4000
name|flagword
name|flags
decl_stmt|;
comment|/* A pointer to the section to which this symbol is  	   relative.  This will always be non NULL, there are special           sections for undefined and absolute symbols */
name|struct
name|sec
modifier|*
name|section
decl_stmt|;
comment|/* Back end special data. This is being phased out in favour 	   of making this a union. */
name|PTR
name|udata
decl_stmt|;
block|}
name|asymbol
typedef|;
end_typedef

begin_define
define|#
directive|define
name|get_symtab_upper_bound
parameter_list|(
name|abfd
parameter_list|)
define|\
value|BFD_SEND (abfd, _get_symtab_upper_bound, (abfd))
end_define

begin_define
define|#
directive|define
name|bfd_canonicalize_symtab
parameter_list|(
name|abfd
parameter_list|,
name|location
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_canonicalize_symtab,\                   (abfd, location))
end_define

begin_decl_stmt
name|boolean
name|bfd_set_symtab
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_print_symbol_vandf
name|PARAMS
argument_list|(
operator|(
name|PTR
name|file
operator|,
name|asymbol
operator|*
name|symbol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bfd_make_empty_symbol
parameter_list|(
name|abfd
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_make_empty_symbol, (abfd))
end_define

begin_define
define|#
directive|define
name|bfd_make_debug_symbol
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_make_debug_symbol, (abfd, ptr, size))
end_define

begin_decl_stmt
name|int
name|bfd_decode_symclass
name|PARAMS
argument_list|(
operator|(
name|asymbol
operator|*
name|symbol
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_symbol_info
name|PARAMS
argument_list|(
operator|(
name|asymbol
operator|*
name|symbol
operator|,
name|symbol_info
operator|*
name|ret
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|_bfd
block|{
comment|/* The filename the application opened the BFD with.  */
name|CONST
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* A pointer to the target jump table.             */
name|struct
name|bfd_target
modifier|*
name|xvec
decl_stmt|;
comment|/* To avoid dragging too many header files into every file that        includes `<<bfd.h>>', IOSTREAM has been declared as a "char        *", and MTIME as a "long".  Their correct types, to which they        are cast when used, are "FILE *" and "time_t".    The iostream        is the result of an fopen on the filename. */
name|char
modifier|*
name|iostream
decl_stmt|;
comment|/* Is the file being cached */
name|boolean
name|cacheable
decl_stmt|;
comment|/* Marks whether there was a default target specified when the        BFD was opened. This is used to select what matching algorithm        to use to chose the back end. */
name|boolean
name|target_defaulted
decl_stmt|;
comment|/* The caching routines use these to maintain a        least-recently-used list of BFDs */
name|struct
name|_bfd
modifier|*
name|lru_prev
decl_stmt|,
modifier|*
name|lru_next
decl_stmt|;
comment|/* When a file is closed by the caching routines, BFD retains        state information on the file here:       */
name|file_ptr
name|where
decl_stmt|;
comment|/* and here:*/
name|boolean
name|opened_once
decl_stmt|;
comment|/* Set if we have a locally maintained mtime value, rather than        getting it from the file each time: */
name|boolean
name|mtime_set
decl_stmt|;
comment|/* File modified time, if mtime_set is true: */
name|long
name|mtime
decl_stmt|;
comment|/* Reserved for an unimplemented file locking extension.*/
name|int
name|ifd
decl_stmt|;
comment|/* The format which belongs to the BFD.*/
name|bfd_format
name|format
decl_stmt|;
comment|/* The direction the BFD was opened with*/
enum|enum
name|bfd_direction
block|{
name|no_direction
init|=
literal|0
block|,
name|read_direction
init|=
literal|1
block|,
name|write_direction
init|=
literal|2
block|,
name|both_direction
init|=
literal|3
block|}
name|direction
enum|;
comment|/* Format_specific flags*/
name|flagword
name|flags
decl_stmt|;
comment|/* Currently my_archive is tested before adding origin to        anything. I believe that this can become always an add of        origin, with origin set to 0 for non archive files.   */
name|file_ptr
name|origin
decl_stmt|;
comment|/* Remember when output has begun, to stop strange things        happening. */
name|boolean
name|output_has_begun
decl_stmt|;
comment|/* Pointer to linked list of sections*/
name|struct
name|sec
modifier|*
name|sections
decl_stmt|;
comment|/* The number of sections */
name|unsigned
name|int
name|section_count
decl_stmt|;
comment|/* Stuff only useful for object files:         The start address. */
name|bfd_vma
name|start_address
decl_stmt|;
comment|/* Used for input and output*/
name|unsigned
name|int
name|symcount
decl_stmt|;
comment|/* Symbol table for output BFD*/
name|struct
name|symbol_cache_entry
modifier|*
modifier|*
name|outsymbols
decl_stmt|;
comment|/* Pointer to structure which contains architecture information*/
name|struct
name|bfd_arch_info
modifier|*
name|arch_info
decl_stmt|;
comment|/* Stuff only useful for archives:*/
name|PTR
name|arelt_data
decl_stmt|;
name|struct
name|_bfd
modifier|*
name|my_archive
decl_stmt|;
name|struct
name|_bfd
modifier|*
name|next
decl_stmt|;
name|struct
name|_bfd
modifier|*
name|archive_head
decl_stmt|;
name|boolean
name|has_armap
decl_stmt|;
comment|/* Used by the back end to hold private data. */
union|union
block|{
name|struct
name|aout_data_struct
modifier|*
name|aout_data
decl_stmt|;
name|struct
name|artdata
modifier|*
name|aout_ar_data
decl_stmt|;
name|struct
name|_oasys_data
modifier|*
name|oasys_obj_data
decl_stmt|;
name|struct
name|_oasys_ar_data
modifier|*
name|oasys_ar_data
decl_stmt|;
name|struct
name|coff_tdata
modifier|*
name|coff_obj_data
decl_stmt|;
name|struct
name|ecoff_tdata
modifier|*
name|ecoff_obj_data
decl_stmt|;
name|struct
name|ieee_data_struct
modifier|*
name|ieee_data
decl_stmt|;
name|struct
name|ieee_ar_data_struct
modifier|*
name|ieee_ar_data
decl_stmt|;
name|struct
name|srec_data_struct
modifier|*
name|srec_data
decl_stmt|;
name|struct
name|tekhex_data_struct
modifier|*
name|tekhex_data
decl_stmt|;
name|struct
name|elf_obj_tdata
modifier|*
name|elf_obj_data
decl_stmt|;
name|struct
name|nlm_obj_tdata
modifier|*
name|nlm_obj_data
decl_stmt|;
name|struct
name|bout_data_struct
modifier|*
name|bout_data
decl_stmt|;
name|struct
name|sun_core_struct
modifier|*
name|sun_core_data
decl_stmt|;
name|struct
name|trad_core_struct
modifier|*
name|trad_core_data
decl_stmt|;
name|struct
name|hppa_data_struct
modifier|*
name|hppa_data
decl_stmt|;
name|struct
name|hpux_core_struct
modifier|*
name|hpux_core_data
decl_stmt|;
name|struct
name|sgi_core_struct
modifier|*
name|sgi_core_data
decl_stmt|;
name|struct
name|lynx_core_struct
modifier|*
name|lynx_core_data
decl_stmt|;
name|struct
name|osf_core_struct
modifier|*
name|osf_core_data
decl_stmt|;
name|PTR
name|any
decl_stmt|;
block|}
name|tdata
union|;
comment|/* Used by the application to hold private data*/
name|PTR
name|usrdata
decl_stmt|;
comment|/* Where all the allocated stuff under this BFD goes */
name|struct
name|obstack
name|memory
decl_stmt|;
comment|/* Is this really needed in addition to usrdata?  */
name|asymbol
modifier|*
modifier|*
name|ld_symbols
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|unsigned
name|int
name|bfd_get_reloc_upper_bound
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sect
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|bfd_canonicalize_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sec
operator|,
name|arelent
operator|*
operator|*
name|loc
operator|,
name|asymbol
operator|*
operator|*
name|syms
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_file_flags
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|flagword
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_set_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asection
operator|*
name|sec
operator|,
name|arelent
operator|*
operator|*
name|rel
operator|,
name|unsigned
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_start_address
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bfd_get_mtime
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bfd_get_size
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bfd_get_gp_size
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_set_gp_size
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_vma
name|bfd_scan_vma
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
name|string
operator|,
name|CONST
name|char
operator|*
operator|*
name|end
operator|,
name|int
name|base
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bfd_sizeof_headers
parameter_list|(
name|abfd
parameter_list|,
name|reloc
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_sizeof_headers, (abfd, reloc))
end_define

begin_define
define|#
directive|define
name|bfd_find_nearest_line
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|syms
parameter_list|,
name|off
parameter_list|,
name|file
parameter_list|,
name|func
parameter_list|,
name|line
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_find_nearest_line,  (abfd, sec, syms, off, file, func, line))
end_define

begin_comment
comment|/* Do these three do anything useful at all, for any back end?  */
end_comment

begin_define
define|#
directive|define
name|bfd_debug_info_start
parameter_list|(
name|abfd
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_debug_info_start, (abfd))
end_define

begin_define
define|#
directive|define
name|bfd_debug_info_end
parameter_list|(
name|abfd
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_debug_info_end, (abfd))
end_define

begin_define
define|#
directive|define
name|bfd_debug_info_accumulate
parameter_list|(
name|abfd
parameter_list|,
name|section
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_debug_info_accumulate, (abfd, section))
end_define

begin_define
define|#
directive|define
name|bfd_stat_arch_elt
parameter_list|(
name|abfd
parameter_list|,
name|stat
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_stat_arch_elt,(abfd, stat))
end_define

begin_define
define|#
directive|define
name|bfd_set_arch_mach
parameter_list|(
name|abfd
parameter_list|,
name|arch
parameter_list|,
name|mach
parameter_list|)
define|\
value|BFD_SEND ( abfd, _bfd_set_arch_mach, (abfd, arch, mach))
end_define

begin_define
define|#
directive|define
name|bfd_get_relocated_section_contents
parameter_list|(
name|abfd
parameter_list|,
name|seclet
parameter_list|,
name|data
parameter_list|,
name|relocateable
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_get_relocated_section_contents, (abfd, seclet, data, relocateable))
end_define

begin_define
define|#
directive|define
name|bfd_relax_section
parameter_list|(
name|abfd
parameter_list|,
name|section
parameter_list|,
name|symbols
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_relax_section, (abfd, section, symbols))
end_define

begin_define
define|#
directive|define
name|bfd_seclet_link
parameter_list|(
name|abfd
parameter_list|,
name|data
parameter_list|,
name|relocateable
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_seclet_link, (abfd, data, relocateable))
end_define

begin_decl_stmt
name|symindex
name|bfd_get_next_mapent
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|symindex
name|previous
operator|,
name|carsym
operator|*
operator|*
name|sym
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_archive_head
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|output
operator|,
name|bfd
operator|*
name|new_head
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_get_elt_at_index
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|archive
operator|,
name|int
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|bfd_openr_next_archived_file
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|archive
operator|,
name|bfd
operator|*
name|previous
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CONST
name|char
modifier|*
name|bfd_core_file_failing_command
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bfd_core_file_failing_signal
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|core_file_matches_executable_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|core_bfd
operator|,
name|bfd
operator|*
name|exec_bfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BFD_SEND
parameter_list|(
name|bfd
parameter_list|,
name|message
parameter_list|,
name|arglist
parameter_list|)
define|\
value|((*((bfd)->xvec->message)) arglist)
end_define

begin_define
define|#
directive|define
name|BFD_SEND_FMT
parameter_list|(
name|bfd
parameter_list|,
name|message
parameter_list|,
name|arglist
parameter_list|)
define|\
value|(((bfd)->xvec->message[(int)((bfd)->format)]) arglist)
end_define

begin_typedef
typedef|typedef
struct|struct
name|bfd_target
block|{
name|char
modifier|*
name|name
decl_stmt|;
enum|enum
name|target_flavour
block|{
name|bfd_target_unknown_flavour
block|,
name|bfd_target_aout_flavour
block|,
name|bfd_target_coff_flavour
block|,
name|bfd_target_ecoff_flavour
block|,
name|bfd_target_elf_flavour
block|,
name|bfd_target_ieee_flavour
block|,
name|bfd_target_nlm_flavour
block|,
name|bfd_target_oasys_flavour
block|,
name|bfd_target_tekhex_flavour
block|,
name|bfd_target_srec_flavour
block|,
name|bfd_target_hppa_flavour
block|}
name|flavour
enum|;
name|boolean
name|byteorder_big_p
decl_stmt|;
name|boolean
name|header_byteorder_big_p
decl_stmt|;
name|flagword
name|object_flags
decl_stmt|;
name|flagword
name|section_flags
decl_stmt|;
name|char
name|symbol_leading_char
decl_stmt|;
name|char
name|ar_pad_char
decl_stmt|;
name|unsigned
name|short
name|ar_max_namelen
decl_stmt|;
name|unsigned
name|int
name|align_power_min
decl_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_getx64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_getx_signed_64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_putx64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_getx32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_getx_signed_32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_putx32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_getx16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_getx_signed_16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_putx16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_h_getx64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_h_getx_signed_64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_h_putx64
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_h_getx32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_h_getx_signed_32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_h_putx32
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*bfd_h_getx16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_signed_vma
argument_list|(
argument|*bfd_h_getx_signed_16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*bfd_h_putx16
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
expr_stmt|;
name|struct
name|bfd_target
modifier|*
argument_list|(
operator|*
name|_bfd_check_format
index|[
name|bfd_type_end
index|]
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
name|boolean
argument_list|(
argument|*_bfd_set_format[bfd_type_end]
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_write_contents[bfd_type_end]
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|char
operator|*
operator|(
operator|*
name|_core_file_failing_command
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*_core_file_failing_signal
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_core_file_matches_executable_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_slurp_armap
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_slurp_extended_name_table
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*_bfd_truncate_arname
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|CONST
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*write_armap
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|arch
operator|,
name|unsigned
name|int
name|elength
operator|,
expr|struct
name|orl
operator|*
name|map
operator|,
name|unsigned
name|int
name|orl_count
operator|,
name|int
name|stridx
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_close_and_cleanup
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_set_section_contents
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|sec_ptr
operator|,
name|PTR
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_get_section_contents
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|sec_ptr
operator|,
name|PTR
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_new_section_hook
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|sec_ptr
operator|)
argument_list|)
expr_stmt|;
name|unsigned
name|int
argument_list|(
operator|*
name|_get_symtab_upper_bound
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
argument_list|(
operator|*
name|_bfd_canonicalize_symtab
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
argument_list|(
operator|*
name|_get_reloc_upper_bound
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|sec_ptr
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
argument_list|(
operator|*
name|_bfd_canonicalize_reloc
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|sec_ptr
operator|,
name|arelent
operator|*
operator|*
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
name|struct
name|symbol_cache_entry
modifier|*
argument_list|(
operator|*
name|_bfd_make_empty_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
name|void
argument_list|(
argument|*_bfd_print_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|,
name|bfd_print_symbol_type
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|bfd_print_symbol
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|,
name|e
parameter_list|)
value|BFD_SEND(b, _bfd_print_symbol, (b,p,s,e))
name|void
argument_list|(
argument|*_bfd_get_symbol_info
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|,
name|symbol_info
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|bfd_get_symbol_info
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|,
name|e
parameter_list|)
value|BFD_SEND(b, _bfd_get_symbol_info, (b,p,e))
name|alent
operator|*
operator|(
operator|*
name|_get_lineno
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_set_arch_mach
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|enum
name|bfd_architecture
operator|,
name|unsigned
name|long
operator|)
argument_list|)
expr_stmt|;
name|bfd
operator|*
operator|(
operator|*
name|openr_next_archived_file
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|arch
operator|,
name|bfd
operator|*
name|prev
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_find_nearest_line
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
expr|struct
name|sec
operator|*
name|section
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|*
name|symbols
operator|,
name|bfd_vma
name|offset
operator|,
name|CONST
name|char
operator|*
operator|*
name|file
operator|,
name|CONST
name|char
operator|*
operator|*
name|func
operator|,
name|unsigned
name|int
operator|*
name|line
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*_bfd_stat_arch_elt
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*_bfd_sizeof_headers
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*_bfd_debug_info_start
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*_bfd_debug_info_end
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*_bfd_debug_info_accumulate
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|sec
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_byte
operator|*
operator|(
operator|*
name|_bfd_get_relocated_section_contents
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_seclet
operator|*
operator|,
name|bfd_byte
operator|*
name|data
operator|,
name|boolean
name|relocateable
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_relax_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|sec
operator|*
operator|,
expr|struct
name|symbol_cache_entry
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|*_bfd_seclet_link
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
name|data
operator|,
name|boolean
name|relocateable
operator|)
argument_list|)
expr_stmt|;
comment|/* See documentation on reloc types.  */
name|CONST
name|struct
name|reloc_howto_struct
modifier|*
argument_list|(
operator|*
name|reloc_type_lookup
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
comment|/* Back-door to allow format-aware applications to create debug symbols     while using BFD for everything else.  Currently used by the assembler     when creating COFF files.  */
name|asymbol
operator|*
operator|(
operator|*
name|_bfd_make_debug_symbol
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|void
operator|*
name|ptr
operator|,
name|unsigned
name|long
name|size
operator|)
argument_list|)
expr_stmt|;
name|PTR
name|backend_data
decl_stmt|;
block|}
name|bfd_target
typedef|;
end_typedef

begin_decl_stmt
name|bfd_target
modifier|*
name|bfd_find_target
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CONST
name|char
modifier|*
modifier|*
name|bfd_target_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_check_format
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_format
name|format
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_set_format
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_format
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CONST
name|char
modifier|*
name|bfd_format_string
name|PARAMS
argument_list|(
operator|(
name|bfd_format
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

