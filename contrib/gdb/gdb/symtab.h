begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Symbol table definitions for GDB.    Copyright 1986, 89, 91, 92, 93, 94, 95, 96, 1998              Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYMTAB_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYMTAB_H
value|1
end_define

begin_comment
comment|/* Some definitions and declarations to go with use of obstacks.  */
end_comment

begin_include
include|#
directive|include
file|"obstack.h"
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
value|free
end_define

begin_include
include|#
directive|include
file|"bcache.h"
end_include

begin_comment
comment|/* Don't do this; it means that if some .o's are compiled with GNU C    and some are not (easy to do accidentally the way we configure    things; also it is a pain to have to "make clean" every time you    want to switch compilers), then GDB dies a horrible death.  */
end_comment

begin_comment
comment|/* GNU C supports enums that are bitfields.  Some compilers don't. */
end_comment

begin_if
if|#
directive|if
literal|0
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BYTE_BITFIELD
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_BITFIELD
value|:8;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_BITFIELD
end_define

begin_comment
comment|/*nothing*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define a structure for the information that is common to all symbol types,    including minimal symbols, partial symbols, and full symbols.  In a    multilanguage environment, some language specific information may need to    be recorded along with each symbol.     These fields are ordered to encourage good packing, since we frequently    have tens or hundreds of thousands of these.  */
end_comment

begin_struct
struct|struct
name|general_symbol_info
block|{
comment|/* Name of the symbol.  This is a required field.  Storage for the name is      allocated on the psymbol_obstack or symbol_obstack for the associated      objfile. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Value of the symbol.  Which member of this union to use, and what      it means, depends on what kind of symbol this is and its      SYMBOL_CLASS.  See comments there for more details.  All of these      are in host byte order (though what they point to might be in      target byte order, e.g. LOC_CONST_BYTES).  */
union|union
block|{
comment|/* The fact that this is a long not a LONGEST mainly limits the 	 range of a LOC_CONST.  Since LOC_CONST_BYTES exists, I'm not 	 sure that is a big deal.  */
name|long
name|ivalue
decl_stmt|;
name|struct
name|block
modifier|*
name|block
decl_stmt|;
name|char
modifier|*
name|bytes
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
comment|/* for opaque typedef struct chain */
name|struct
name|symbol
modifier|*
name|chain
decl_stmt|;
block|}
name|value
union|;
comment|/* Since one and only one language can apply, wrap the language specific      information inside a union. */
union|union
block|{
struct|struct
name|cplus_specific
comment|/* For C++ */
comment|/*  and Java */
block|{
name|char
modifier|*
name|demangled_name
decl_stmt|;
block|}
name|cplus_specific
struct|;
struct|struct
name|chill_specific
comment|/* For Chill */
block|{
name|char
modifier|*
name|demangled_name
decl_stmt|;
block|}
name|chill_specific
struct|;
block|}
name|language_specific
union|;
comment|/* Record the source code language that applies to this symbol.      This is used to select one of the fields from the language specific      union above. */
name|enum
name|language
name|language
name|BYTE_BITFIELD
decl_stmt|;
comment|/* Which section is this symbol in?  This is an index into      section_offsets for this objfile.  Negative means that the symbol      does not get relocated relative to a section.      Disclaimer: currently this is just used for xcoff, so don't      expect all symbol-reading code to set it correctly (the ELF code      also tries to set it correctly).  */
name|short
name|section
decl_stmt|;
comment|/* The bfd section associated with this symbol. */
name|asection
modifier|*
name|bfd_section
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|symbol_overlayed_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SYMBOL_NAME
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.name
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.value.ivalue
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_ADDRESS
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.value.address
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_BYTES
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.value.bytes
end_define

begin_define
define|#
directive|define
name|SYMBOL_BLOCK_VALUE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.value.block
end_define

begin_define
define|#
directive|define
name|SYMBOL_VALUE_CHAIN
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.value.chain
end_define

begin_define
define|#
directive|define
name|SYMBOL_LANGUAGE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.language
end_define

begin_define
define|#
directive|define
name|SYMBOL_SECTION
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.section
end_define

begin_define
define|#
directive|define
name|SYMBOL_BFD_SECTION
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.bfd_section
end_define

begin_define
define|#
directive|define
name|SYMBOL_CPLUS_DEMANGLED_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(symbol)->ginfo.language_specific.cplus_specific.demangled_name
end_define

begin_comment
comment|/* Macro that initializes the language dependent portion of a symbol    depending upon the language for the symbol. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_INIT_LANGUAGE_SPECIFIC
parameter_list|(
name|symbol
parameter_list|,
name|language
parameter_list|)
define|\
value|do {									\     SYMBOL_LANGUAGE (symbol) = language;				\     if (SYMBOL_LANGUAGE (symbol) == language_cplus			\ 	|| SYMBOL_LANGUAGE (symbol) == language_java			\ 	)								\       {									\ 	SYMBOL_CPLUS_DEMANGLED_NAME (symbol) = NULL;			\       }									\     else if (SYMBOL_LANGUAGE (symbol) == language_chill)		\       {									\ 	SYMBOL_CHILL_DEMANGLED_NAME (symbol) = NULL;			\       }									\     else								\       {									\ 	memset (&(symbol)->ginfo.language_specific, 0,			\ 		sizeof ((symbol)->ginfo.language_specific));		\       }									\   } while (0)
end_define

begin_comment
comment|/* Macro that attempts to initialize the demangled name for a symbol,    based on the language of that symbol.  If the language is set to    language_auto, it will attempt to find any demangling algorithm    that works and then set the language appropriately.  If no demangling    of any kind is found, the language is set back to language_unknown,    so we can avoid doing this work again the next time we encounter    the symbol.  Any required space to store the name is obtained from the    specified obstack. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_INIT_DEMANGLED_NAME
parameter_list|(
name|symbol
parameter_list|,
name|obstack
parameter_list|)
define|\
value|do {									\     char *demangled = NULL;						\     if (SYMBOL_LANGUAGE (symbol) == language_cplus			\ 	|| SYMBOL_LANGUAGE (symbol) == language_auto)			\       {									\ 	demangled =							\ 	  cplus_demangle (SYMBOL_NAME (symbol), DMGL_PARAMS | DMGL_ANSI);\ 	if (demangled != NULL)						\ 	  {								\ 	    SYMBOL_LANGUAGE (symbol) = language_cplus;			\ 	    SYMBOL_CPLUS_DEMANGLED_NAME (symbol) = 			\ 	      obsavestring (demangled, strlen (demangled), (obstack));	\ 	    free (demangled);						\ 	  }								\ 	else								\ 	  {								\ 	    SYMBOL_CPLUS_DEMANGLED_NAME (symbol) = NULL;		\ 	  }								\       }									\     if (SYMBOL_LANGUAGE (symbol) == language_java)			\       {									\ 	demangled =							\ 	  cplus_demangle (SYMBOL_NAME (symbol),				\ 			  DMGL_PARAMS | DMGL_ANSI | DMGL_JAVA);		\ 	if (demangled != NULL)						\ 	  {								\ 	    SYMBOL_LANGUAGE (symbol) = language_java;			\ 	    SYMBOL_CPLUS_DEMANGLED_NAME (symbol) = 			\ 	      obsavestring (demangled, strlen (demangled), (obstack));	\ 	    free (demangled);						\ 	  }								\ 	else								\ 	  {								\ 	    SYMBOL_CPLUS_DEMANGLED_NAME (symbol) = NULL;		\ 	  }								\       }									\     if (demangled == NULL						\&& (SYMBOL_LANGUAGE (symbol) == language_chill			\ 	    || SYMBOL_LANGUAGE (symbol) == language_auto))		\       {									\ 	demangled =							\ 	  chill_demangle (SYMBOL_NAME (symbol));			\ 	if (demangled != NULL)						\ 	  {								\ 	    SYMBOL_LANGUAGE (symbol) = language_chill;			\ 	    SYMBOL_CHILL_DEMANGLED_NAME (symbol) = 			\ 	      obsavestring (demangled, strlen (demangled), (obstack));	\ 	    free (demangled);						\ 	  }								\ 	else								\ 	  {								\ 	    SYMBOL_CHILL_DEMANGLED_NAME (symbol) = NULL;		\ 	  }								\       }									\     if (SYMBOL_LANGUAGE (symbol) == language_auto)			\       {									\ 	SYMBOL_LANGUAGE (symbol) = language_unknown;			\       }									\   } while (0)
end_define

begin_comment
comment|/* Macro that returns the demangled name for a symbol based on the language    for that symbol.  If no demangled name exists, returns NULL. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_DEMANGLED_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(SYMBOL_LANGUAGE (symbol) == language_cplus				\    || SYMBOL_LANGUAGE (symbol) == language_java				\    ? SYMBOL_CPLUS_DEMANGLED_NAME (symbol)				\    : (SYMBOL_LANGUAGE (symbol) == language_chill			\       ? SYMBOL_CHILL_DEMANGLED_NAME (symbol)				\       : NULL))
end_define

begin_define
define|#
directive|define
name|SYMBOL_CHILL_DEMANGLED_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(symbol)->ginfo.language_specific.chill_specific.demangled_name
end_define

begin_comment
comment|/* Macro that returns the "natural source name" of a symbol.  In C++ this is    the "demangled" form of the name if demangle is on and the "mangled" form    of the name if demangle is off.  In other languages this is just the    symbol name.  The result should never be NULL. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_SOURCE_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(demangle&& SYMBOL_DEMANGLED_NAME (symbol) != NULL			\    ? SYMBOL_DEMANGLED_NAME (symbol)					\    : SYMBOL_NAME (symbol))
end_define

begin_comment
comment|/* Macro that returns the "natural assembly name" of a symbol.  In C++ this is    the "mangled" form of the name if demangle is off, or if demangle is on and    asm_demangle is off.  Otherwise if asm_demangle is on it is the "demangled"    form.  In other languages this is just the symbol name.  The result should    never be NULL. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_LINKAGE_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(demangle&& asm_demangle&& SYMBOL_DEMANGLED_NAME (symbol) != NULL	\    ? SYMBOL_DEMANGLED_NAME (symbol)					\    : SYMBOL_NAME (symbol))
end_define

begin_comment
comment|/* Macro that tests a symbol for a match against a specified name string.    First test the unencoded name, then looks for and test a C++ encoded    name if it exists.  Note that whitespace is ignored while attempting to    match a C++ encoded name, so that "foo::bar(int,long)" is the same as    "foo :: bar (int, long)".    Evaluates to zero if the match fails, or nonzero if it succeeds. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_MATCHES_NAME
parameter_list|(
name|symbol
parameter_list|,
name|name
parameter_list|)
define|\
value|(STREQ (SYMBOL_NAME (symbol), (name))					\    || (SYMBOL_DEMANGLED_NAME (symbol) != NULL				\&& strcmp_iw (SYMBOL_DEMANGLED_NAME (symbol), (name)) == 0))
end_define

begin_comment
comment|/* Macro that tests a symbol for an re-match against the last compiled regular    expression.  First test the unencoded name, then look for and test a C++    encoded name if it exists.    Evaluates to zero if the match fails, or nonzero if it succeeds. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_MATCHES_REGEXP
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(re_exec (SYMBOL_NAME (symbol)) != 0					\    || (SYMBOL_DEMANGLED_NAME (symbol) != NULL				\&& re_exec (SYMBOL_DEMANGLED_NAME (symbol)) != 0))
end_define

begin_comment
comment|/* Define a simple structure used to hold some very basic information about    all defined global symbols (text, data, bss, abs, etc).  The only required    information is the general_symbol_info.     In many cases, even if a file was compiled with no special options for    debugging at all, as long as was not stripped it will contain sufficient    information to build a useful minimal symbol table using this structure.    Even when a file contains enough debugging information to build a full    symbol table, these minimal symbols are still useful for quickly mapping    between names and addresses, and vice versa.  They are also sometimes    used to figure out what full symbol table entries need to be read in. */
end_comment

begin_struct
struct|struct
name|minimal_symbol
block|{
comment|/* The general symbol info required for all types of symbols.       The SYMBOL_VALUE_ADDRESS contains the address that this symbol      corresponds to.  */
name|struct
name|general_symbol_info
name|ginfo
decl_stmt|;
comment|/* The info field is available for caching machine-specific information      so it doesn't have to rederive the info constantly (over a serial line).      It is initialized to zero and stays that way until target-dependent code      sets it.  Storage for any data pointed to by this field should be allo-      cated on the symbol_obstack for the associated objfile.        The type would be "void *" except for reasons of compatibility with older      compilers.  This field is optional.       Currently, the AMD 29000 tdep.c uses it to remember things it has decoded      from the instructions in the function header, and the MIPS-16 code uses      it to identify 16-bit procedures.  */
name|char
modifier|*
name|info
decl_stmt|;
ifdef|#
directive|ifdef
name|SOFUN_ADDRESS_MAYBE_MISSING
comment|/* Which source file is this symbol in?  Only relevant for mst_file_*.  */
name|char
modifier|*
name|filename
decl_stmt|;
endif|#
directive|endif
comment|/* Classification types for this symbol.  These should be taken as "advisory      only", since if gdb can't easily figure out a classification it simply      selects mst_unknown.  It may also have to guess when it can't figure out      which is a better match between two types (mst_data versus mst_bss) for      example.  Since the minimal symbol info is sometimes derived from the      BFD library's view of a file, we need to live with what information bfd      supplies. */
enum|enum
name|minimal_symbol_type
block|{
name|mst_unknown
init|=
literal|0
block|,
comment|/* Unknown type, the default */
name|mst_text
block|,
comment|/* Generally executable instructions */
name|mst_data
block|,
comment|/* Generally initialized data */
name|mst_bss
block|,
comment|/* Generally uninitialized data */
name|mst_abs
block|,
comment|/* Generally absolute (nonrelocatable) */
comment|/* GDB uses mst_solib_trampoline for the start address of a shared 	 library trampoline entry.  Breakpoints for shared library functions 	 are put there if the shared library is not yet loaded. 	 After the shared library is loaded, lookup_minimal_symbol will 	 prefer the minimal symbol from the shared library (usually 	 a mst_text symbol) over the mst_solib_trampoline symbol, and the 	 breakpoints will be moved to their true address in the shared 	 library via breakpoint_re_set.  */
name|mst_solib_trampoline
block|,
comment|/* Shared library trampoline code */
comment|/* For the mst_file* types, the names are only guaranteed to be unique 	 within a given .o file.  */
name|mst_file_text
block|,
comment|/* Static version of mst_text */
name|mst_file_data
block|,
comment|/* Static version of mst_data */
name|mst_file_bss
comment|/* Static version of mst_bss */
block|}
name|type
name|BYTE_BITFIELD
enum|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSYMBOL_INFO
parameter_list|(
name|msymbol
parameter_list|)
value|(msymbol)->info
end_define

begin_define
define|#
directive|define
name|MSYMBOL_TYPE
parameter_list|(
name|msymbol
parameter_list|)
value|(msymbol)->type
end_define

begin_escape
end_escape

begin_comment
comment|/* All of the name-scope contours of the program    are represented by `struct block' objects.    All of these objects are pointed to by the blockvector.     Each block represents one name scope.    Each lexical context has its own block.     The blockvector begins with some special blocks.    The GLOBAL_BLOCK contains all the symbols defined in this compilation    whose scope is the entire program linked together.    The STATIC_BLOCK contains all the symbols whose scope is the    entire compilation excluding other separate compilations.    Blocks starting with the FIRST_LOCAL_BLOCK are not special.     Each block records a range of core addresses for the code that    is in the scope of the block.  The STATIC_BLOCK and GLOBAL_BLOCK    give, for the range of code, the entire range of code produced    by the compilation that the symbol segment belongs to.     The blocks appear in the blockvector    in order of increasing starting-address,    and, within that, in order of decreasing ending-address.     This implies that within the body of one function    the blocks appear in the order of a depth-first tree walk.  */
end_comment

begin_struct
struct|struct
name|blockvector
block|{
comment|/* Number of blocks in the list.  */
name|int
name|nblocks
decl_stmt|;
comment|/* The blocks themselves.  */
name|struct
name|block
modifier|*
name|block
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
name|BLOCKVECTOR_NBLOCKS
parameter_list|(
name|blocklist
parameter_list|)
value|(blocklist)->nblocks
end_define

begin_define
define|#
directive|define
name|BLOCKVECTOR_BLOCK
parameter_list|(
name|blocklist
parameter_list|,
name|n
parameter_list|)
value|(blocklist)->block[n]
end_define

begin_comment
comment|/* Special block numbers */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|STATIC_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|FIRST_LOCAL_BLOCK
value|2
end_define

begin_struct
struct|struct
name|block
block|{
comment|/* Addresses in the executable code that are in this block.  */
name|CORE_ADDR
name|startaddr
decl_stmt|;
name|CORE_ADDR
name|endaddr
decl_stmt|;
comment|/* The symbol that names this block, if the block is the body of a      function; otherwise, zero.  */
name|struct
name|symbol
modifier|*
name|function
decl_stmt|;
comment|/* The `struct block' for the containing block, or 0 if none.       The superblock of a top-level local block (i.e. a function in the      case of C) is the STATIC_BLOCK.  The superblock of the      STATIC_BLOCK is the GLOBAL_BLOCK.  */
name|struct
name|block
modifier|*
name|superblock
decl_stmt|;
comment|/* Version of GCC used to compile the function corresponding      to this block, or 0 if not compiled with GCC.  When possible,      GCC should be compatible with the native compiler, or if that      is not feasible, the differences should be fixed during symbol      reading.  As of 16 Apr 93, this flag is never used to distinguish      between gcc2 and the native compiler.       If there is no function corresponding to this block, this meaning      of this flag is undefined.  */
name|unsigned
name|char
name|gcc_compile_flag
decl_stmt|;
comment|/* Number of local symbols.  */
name|int
name|nsyms
decl_stmt|;
comment|/* The symbols.  If some of them are arguments, then they must be      in the order in which we would like to print them.  */
name|struct
name|symbol
modifier|*
name|sym
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
name|BLOCK_START
parameter_list|(
name|bl
parameter_list|)
value|(bl)->startaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_END
parameter_list|(
name|bl
parameter_list|)
value|(bl)->endaddr
end_define

begin_define
define|#
directive|define
name|BLOCK_NSYMS
parameter_list|(
name|bl
parameter_list|)
value|(bl)->nsyms
end_define

begin_define
define|#
directive|define
name|BLOCK_SYM
parameter_list|(
name|bl
parameter_list|,
name|n
parameter_list|)
value|(bl)->sym[n]
end_define

begin_define
define|#
directive|define
name|BLOCK_FUNCTION
parameter_list|(
name|bl
parameter_list|)
value|(bl)->function
end_define

begin_define
define|#
directive|define
name|BLOCK_SUPERBLOCK
parameter_list|(
name|bl
parameter_list|)
value|(bl)->superblock
end_define

begin_define
define|#
directive|define
name|BLOCK_GCC_COMPILED
parameter_list|(
name|bl
parameter_list|)
value|(bl)->gcc_compile_flag
end_define

begin_comment
comment|/* Nonzero if symbols of block BL should be sorted alphabetically.    Don't sort a block which corresponds to a function.  If we did the    sorting would have to preserve the order of the symbols for the    arguments.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_SHOULD_SORT
parameter_list|(
name|bl
parameter_list|)
value|((bl)->nsyms>= 40&& BLOCK_FUNCTION (bl) == NULL)
end_define

begin_escape
end_escape

begin_comment
comment|/* Represent one symbol name; a variable, constant, function or typedef.  */
end_comment

begin_comment
comment|/* Different name spaces for symbols.  Looking up a symbol specifies a    namespace and ignores symbol definitions in other name spaces. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* UNDEF_NAMESPACE is used when a namespace has not been discovered or      none of the following apply.  This usually indicates an error either      in the symbol information or in gdb's handling of symbols. */
name|UNDEF_NAMESPACE
block|,
comment|/* VAR_NAMESPACE is the usual namespace.  In C, this contains variables,      function names, typedef names and enum type values. */
name|VAR_NAMESPACE
block|,
comment|/* STRUCT_NAMESPACE is used in C to hold struct, union and enum type names.      Thus, if `struct foo' is used in a C program, it produces a symbol named      `foo' in the STRUCT_NAMESPACE. */
name|STRUCT_NAMESPACE
block|,
comment|/* LABEL_NAMESPACE may be used for names of labels (for gotos);      currently it is not used and labels are not recorded at all.  */
name|LABEL_NAMESPACE
block|,
comment|/* Searching namespaces. These overlap with VAR_NAMESPACE, providing      some granularity with the search_symbols function. */
comment|/* Everything in VAR_NAMESPACE minus FUNCTIONS_-, TYPES_-, and      METHODS_NAMESPACE */
name|VARIABLES_NAMESPACE
block|,
comment|/* All functions -- for some reason not methods, though. */
name|FUNCTIONS_NAMESPACE
block|,
comment|/* All defined types */
name|TYPES_NAMESPACE
block|,
comment|/* All class methods -- why is this separated out? */
name|METHODS_NAMESPACE
block|}
name|namespace_enum
typedef|;
end_typedef

begin_comment
comment|/* An address-class says where to find the value of a symbol.  */
end_comment

begin_enum
enum|enum
name|address_class
block|{
comment|/* Not used; catches errors */
name|LOC_UNDEF
block|,
comment|/* Value is constant int SYMBOL_VALUE, host byteorder */
name|LOC_CONST
block|,
comment|/* Value is at fixed address SYMBOL_VALUE_ADDRESS */
name|LOC_STATIC
block|,
comment|/* Value is in register.  SYMBOL_VALUE is the register number.  */
name|LOC_REGISTER
block|,
comment|/* It's an argument; the value is at SYMBOL_VALUE offset in arglist.  */
name|LOC_ARG
block|,
comment|/* Value address is at SYMBOL_VALUE offset in arglist.  */
name|LOC_REF_ARG
block|,
comment|/* Value is in register number SYMBOL_VALUE.  Just like LOC_REGISTER      except this is an argument.  Probably the cleaner way to handle      this would be to separate address_class (which would include      separate ARG and LOCAL to deal with FRAME_ARGS_ADDRESS versus      FRAME_LOCALS_ADDRESS), and an is_argument flag.       For some symbol formats (stabs, for some compilers at least),      the compiler generates two symbols, an argument and a register.      In some cases we combine them to a single LOC_REGPARM in symbol      reading, but currently not for all cases (e.g. it's passed on the      stack and then loaded into a register).  */
name|LOC_REGPARM
block|,
comment|/* Value is in specified register.  Just like LOC_REGPARM except the      register holds the address of the argument instead of the argument      itself. This is currently used for the passing of structs and unions      on sparc and hppa.  It is also used for call by reference where the      address is in a register, at least by mipsread.c.  */
name|LOC_REGPARM_ADDR
block|,
comment|/* Value is a local variable at SYMBOL_VALUE offset in stack frame.  */
name|LOC_LOCAL
block|,
comment|/* Value not used; definition in SYMBOL_TYPE.  Symbols in the namespace      STRUCT_NAMESPACE all have this class.  */
name|LOC_TYPEDEF
block|,
comment|/* Value is address SYMBOL_VALUE_ADDRESS in the code */
name|LOC_LABEL
block|,
comment|/* In a symbol table, value is SYMBOL_BLOCK_VALUE of a `struct block'.      In a partial symbol table, SYMBOL_VALUE_ADDRESS is the start address      of the block.  Function names have this class. */
name|LOC_BLOCK
block|,
comment|/* Value is a constant byte-sequence pointed to by SYMBOL_VALUE_BYTES, in      target byte order.  */
name|LOC_CONST_BYTES
block|,
comment|/* Value is arg at SYMBOL_VALUE offset in stack frame. Differs from      LOC_LOCAL in that symbol is an argument; differs from LOC_ARG in      that we find it in the frame (FRAME_LOCALS_ADDRESS), not in the      arglist (FRAME_ARGS_ADDRESS).  Added for i960, which passes args      in regs then copies to frame.  */
name|LOC_LOCAL_ARG
block|,
comment|/* Value is at SYMBOL_VALUE offset from the current value of      register number SYMBOL_BASEREG.  This exists mainly for the same      things that LOC_LOCAL and LOC_ARG do; but we need to do this      instead because on 88k DWARF gives us the offset from the      frame/stack pointer, rather than the offset from the "canonical      frame address" used by COFF, stabs, etc., and we don't know how      to convert between these until we start examining prologues.       Note that LOC_BASEREG is much less general than a DWARF expression.      We don't need the generality (at least not yet), and storing a general      DWARF expression would presumably take up more space than the existing      scheme.  */
name|LOC_BASEREG
block|,
comment|/* Same as LOC_BASEREG but it is an argument.  */
name|LOC_BASEREG_ARG
block|,
comment|/* Value is at fixed address, but the address of the variable has      to be determined from the minimal symbol table whenever the      variable is referenced.      This happens if debugging information for a global symbol is      emitted and the corresponding minimal symbol is defined      in another object file or runtime common storage.      The linker might even remove the minimal symbol if the global      symbol is never referenced, in which case the symbol remains      unresolved.  */
name|LOC_UNRESOLVED
block|,
comment|/* Value is at a thread-specific location calculated by a      target-specific method. */
name|LOC_THREAD_LOCAL_STATIC
block|,
comment|/* The variable does not actually exist in the program.      The value is ignored.  */
name|LOC_OPTIMIZED_OUT
block|,
comment|/* The variable is static, but actually lives at * (address).    * I.e. do an extra indirection to get to it.    * This is used on HP-UX to get at globals that are allocated    * in shared libraries, where references from images other    * than the one where the global was allocated are done    * with a level of indirection.    */
name|LOC_INDIRECT
block|}
enum|;
end_enum

begin_comment
comment|/* Linked list of symbol's live ranges. */
end_comment

begin_struct
struct|struct
name|range_list
block|{
name|CORE_ADDR
name|start
decl_stmt|;
name|CORE_ADDR
name|end
decl_stmt|;
name|struct
name|range_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Linked list of aliases for a particular main/primary symbol.  */
end_comment

begin_struct
struct|struct
name|alias_list
block|{
name|struct
name|symbol
modifier|*
name|sym
decl_stmt|;
name|struct
name|alias_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|symbol
block|{
comment|/* The general symbol info required for all types of symbols. */
name|struct
name|general_symbol_info
name|ginfo
decl_stmt|;
comment|/* Data type of value */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* Name space code.  */
ifdef|#
directive|ifdef
name|__MFC4__
comment|/* FIXME: don't conflict with C++'s namespace */
comment|/* would be safer to do a global change for all namespace identifiers. */
define|#
directive|define
name|namespace
value|_namespace
endif|#
directive|endif
name|namespace_enum
name|namespace
name|BYTE_BITFIELD
decl_stmt|;
comment|/* Address class */
name|enum
name|address_class
name|aclass
name|BYTE_BITFIELD
decl_stmt|;
comment|/* Line number of definition.  FIXME:  Should we really make the assumption      that nobody will try to debug files longer than 64K lines?  What about      machine generated programs? */
name|unsigned
name|short
name|line
decl_stmt|;
comment|/* Some symbols require an additional value to be recorded on a per-      symbol basis.  Stash those values here. */
union|union
block|{
comment|/* Used by LOC_BASEREG and LOC_BASEREG_ARG.  */
name|short
name|basereg
decl_stmt|;
block|}
name|aux_value
union|;
comment|/* Link to a list of aliases for this symbol.      Only a "primary/main symbol may have aliases.  */
name|struct
name|alias_list
modifier|*
name|aliases
decl_stmt|;
comment|/* List of ranges where this symbol is active.  This is only      used by alias symbols at the current time.  */
name|struct
name|range_list
modifier|*
name|ranges
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYMBOL_NAMESPACE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->namespace
end_define

begin_define
define|#
directive|define
name|SYMBOL_CLASS
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aclass
end_define

begin_define
define|#
directive|define
name|SYMBOL_TYPE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->type
end_define

begin_define
define|#
directive|define
name|SYMBOL_LINE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->line
end_define

begin_define
define|#
directive|define
name|SYMBOL_BASEREG
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aux_value.basereg
end_define

begin_define
define|#
directive|define
name|SYMBOL_ALIASES
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aliases
end_define

begin_define
define|#
directive|define
name|SYMBOL_RANGES
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ranges
end_define

begin_escape
end_escape

begin_comment
comment|/* A partial_symbol records the name, namespace, and address class of    symbols whose types we have not parsed yet.  For functions, it also    contains their memory address, so we can find them from a PC value.    Each partial_symbol sits in a partial_symtab, all of which are chained    on a  partial symtab list and which points to the corresponding     normal symtab once the partial_symtab has been referenced.  */
end_comment

begin_struct
struct|struct
name|partial_symbol
block|{
comment|/* The general symbol info required for all types of symbols. */
name|struct
name|general_symbol_info
name|ginfo
decl_stmt|;
comment|/* Name space code.  */
name|namespace_enum
name|namespace
name|BYTE_BITFIELD
decl_stmt|;
comment|/* Address class (for info_symbols) */
name|enum
name|address_class
name|aclass
name|BYTE_BITFIELD
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PSYMBOL_NAMESPACE
parameter_list|(
name|psymbol
parameter_list|)
value|(psymbol)->namespace
end_define

begin_define
define|#
directive|define
name|PSYMBOL_CLASS
parameter_list|(
name|psymbol
parameter_list|)
value|(psymbol)->aclass
end_define

begin_escape
end_escape

begin_comment
comment|/* Source-file information.  This describes the relation between source files,    ine numbers and addresses in the program text.  */
end_comment

begin_struct
struct|struct
name|sourcevector
block|{
name|int
name|length
decl_stmt|;
comment|/* Number of source files described */
name|struct
name|source
modifier|*
name|source
index|[
literal|1
index|]
decl_stmt|;
comment|/* Descriptions of the files */
block|}
struct|;
end_struct

begin_comment
comment|/* Each item represents a line-->pc (or the reverse) mapping.  This is    somewhat more wasteful of space than one might wish, but since only    the files which are actually debugged are read in to core, we don't    waste much space.  */
end_comment

begin_struct
struct|struct
name|linetable_entry
block|{
name|int
name|line
decl_stmt|;
name|CORE_ADDR
name|pc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The order of entries in the linetable is significant.  They should    be sorted by increasing values of the pc field.  If there is more than    one entry for a given pc, then I'm not sure what should happen (and    I not sure whether we currently handle it the best way).     Example: a C for statement generally looks like this     	10	0x100	- for the init/test part of a for stmt.    	20	0x200    	30	0x300    	10	0x400	- for the increment part of a for stmt.     */
end_comment

begin_struct
struct|struct
name|linetable
block|{
name|int
name|nitems
decl_stmt|;
comment|/* Actually NITEMS elements.  If you don't like this use of the      `struct hack', you can shove it up your ANSI (seriously, if the      committee tells us how to do it, we can probably go along).  */
name|struct
name|linetable_entry
name|item
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* All the information on one source file.  */
end_comment

begin_struct
struct|struct
name|source
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of file */
name|struct
name|linetable
name|contents
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* How to relocate the symbols from each section in a symbol file.    Each struct contains an array of offsets.    The ordering and meaning of the offsets is file-type-dependent;    typically it is indexed by section numbers or symbol types or    something like that.     To give us flexibility in changing the internal representation    of these offsets, the ANOFFSET macro must be used to insert and    extract offset values in the struct.  */
end_comment

begin_struct
struct|struct
name|section_offsets
block|{
name|CORE_ADDR
name|offsets
index|[
literal|1
index|]
decl_stmt|;
comment|/* As many as needed. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ANOFFSET
parameter_list|(
name|secoff
parameter_list|,
name|whichone
parameter_list|)
value|(secoff->offsets[whichone])
end_define

begin_comment
comment|/* The maximum possible size of a section_offsets table.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SECTION_OFFSETS
define|\
value|(sizeof (struct section_offsets) \    + sizeof (((struct section_offsets *) 0)->offsets) * (SECT_OFF_MAX-1))
end_define

begin_comment
comment|/* Each source file or header is represented by a struct symtab.     These objects are chained through the `next' field.  */
end_comment

begin_struct
struct|struct
name|symtab
block|{
comment|/* Chain of all existing symtabs.  */
name|struct
name|symtab
modifier|*
name|next
decl_stmt|;
comment|/* List of all symbol scope blocks for this symtab.  May be shared        between different symtabs (and normally is for all the symtabs        in a given compilation unit).  */
name|struct
name|blockvector
modifier|*
name|blockvector
decl_stmt|;
comment|/* Table mapping core addresses to line numbers for this file.        Can be NULL if none.  Never shared between different symtabs.  */
name|struct
name|linetable
modifier|*
name|linetable
decl_stmt|;
comment|/* Section in objfile->section_offsets for the blockvector and        the linetable.  Probably always SECT_OFF_TEXT.  */
name|int
name|block_line_section
decl_stmt|;
comment|/* If several symtabs share a blockvector, exactly one of them        should be designed the primary, so that the blockvector        is relocated exactly once by objfile_relocate.  */
name|int
name|primary
decl_stmt|;
comment|/* Name of this source file.  */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Directory in which it was compiled, or NULL if we don't know.  */
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* This component says how to free the data we point to:        free_contents => do a tree walk and free each object.        free_nothing => do nothing; some other symtab will free          the data this one uses.       free_linetable => free just the linetable.  FIXME: Is this redundant       with the primary field?  */
enum|enum
name|free_code
block|{
name|free_nothing
block|,
name|free_contents
block|,
name|free_linetable
block|}
name|free_code
enum|;
comment|/* Pointer to one block of storage to be freed, if nonzero.  */
comment|/* This is IN ADDITION to the action indicated by free_code.  */
name|char
modifier|*
name|free_ptr
decl_stmt|;
comment|/* Total number of lines found in source file.  */
name|int
name|nlines
decl_stmt|;
comment|/* line_charpos[N] is the position of the (N-1)th line of the        source file.  "position" means something we can lseek() to; it        is not guaranteed to be useful any other way.  */
name|int
modifier|*
name|line_charpos
decl_stmt|;
comment|/* Language of this source file.  */
name|enum
name|language
name|language
decl_stmt|;
comment|/* String that identifies the format of the debugging information, such        as "stabs", "dwarf 1", "dwarf 2", "coff", etc.  This is mostly useful        for automated testing of gdb but may also be information that is        useful to the user. */
name|char
modifier|*
name|debugformat
decl_stmt|;
comment|/* String of version information.  May be zero.  */
name|char
modifier|*
name|version
decl_stmt|;
comment|/* Full name of file as found by searching the source path.        NULL if not yet known.  */
name|char
modifier|*
name|fullname
decl_stmt|;
comment|/* Object file from which this symbol information was read.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLOCKVECTOR
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->blockvector
end_define

begin_define
define|#
directive|define
name|LINETABLE
parameter_list|(
name|symtab
parameter_list|)
value|(symtab)->linetable
end_define

begin_escape
end_escape

begin_comment
comment|/* Each source file that has not been fully read in is represented by    a partial_symtab.  This contains the information on where in the    executable the debugging symbols for a specific file are, and a    list of names of global symbols which are located in this file.    They are all chained on partial symtab lists.     Even after the source file has been read into a symtab, the    partial_symtab remains around.  They are allocated on an obstack,    psymbol_obstack.  FIXME, this is bad for dynamic linking or VxWorks-    style execution of a bunch of .o's.  */
end_comment

begin_struct
struct|struct
name|partial_symtab
block|{
comment|/* Chain of all existing partial symtabs.  */
name|struct
name|partial_symtab
modifier|*
name|next
decl_stmt|;
comment|/* Name of the source file which this partial_symtab defines */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Information about the object file from which symbols should be read.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* Set of relocation offsets to apply to each section.  */
name|struct
name|section_offsets
modifier|*
name|section_offsets
decl_stmt|;
comment|/* Range of text addresses covered by this file; texthigh is the      beginning of the next section. */
name|CORE_ADDR
name|textlow
decl_stmt|;
name|CORE_ADDR
name|texthigh
decl_stmt|;
comment|/* Array of pointers to all of the partial_symtab's which this one      depends on.  Since this array can only be set to previous or      the current (?) psymtab, this dependency tree is guaranteed not      to have any loops.  "depends on" means that symbols must be read      for the dependencies before being read for this psymtab; this is      for type references in stabs, where if foo.c includes foo.h, declarations      in foo.h may use type numbers defined in foo.c.  For other debugging      formats there may be no need to use dependencies.  */
name|struct
name|partial_symtab
modifier|*
modifier|*
name|dependencies
decl_stmt|;
name|int
name|number_of_dependencies
decl_stmt|;
comment|/* Global symbol list.  This list will be sorted after readin to      improve access.  Binary search will be the usual method of      finding a symbol within it. globals_offset is an integer offset      within global_psymbols[].  */
name|int
name|globals_offset
decl_stmt|;
name|int
name|n_global_syms
decl_stmt|;
comment|/* Static symbol list.  This list will *not* be sorted after readin;      to find a symbol in it, exhaustive search must be used.  This is      reasonable because searches through this list will eventually      lead to either the read in of a files symbols for real (assumed      to take a *lot* of time; check) or an error (and we don't care      how long errors take).  This is an offset and size within      static_psymbols[].  */
name|int
name|statics_offset
decl_stmt|;
name|int
name|n_static_syms
decl_stmt|;
comment|/* Pointer to symtab eventually allocated for this source file, 0 if      !readin or if we haven't looked for the symtab after it was readin.  */
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
comment|/* Pointer to function which will read in the symtab corresponding to      this psymtab.  */
name|void
argument_list|(
argument|*read_symtab
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Information that lets read_symtab() locate the part of the symbol table      that this psymtab corresponds to.  This information is private to the      format-dependent symbol reading routines.  For further detail examine      the various symbol reading modules.  Should really be (void *) but is      (char *) as with other such gdb variables.  (FIXME) */
name|char
modifier|*
name|read_symtab_private
decl_stmt|;
comment|/* Non-zero if the symtab corresponding to this psymtab has been readin */
name|unsigned
name|char
name|readin
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A fast way to get from a psymtab to its symtab (after the first time).  */
end_comment

begin_define
define|#
directive|define
name|PSYMTAB_TO_SYMTAB
parameter_list|(
name|pst
parameter_list|)
define|\
value|((pst) -> symtab != NULL ? (pst) -> symtab : psymtab_to_symtab (pst))
end_define

begin_escape
end_escape

begin_comment
comment|/* The virtual function table is now an array of structures which have the    form { int16 offset, delta; void *pfn; }.      In normal virtual function tables, OFFSET is unused.    DELTA is the amount which is added to the apparent object's base    address in order to point to the actual object to which the    virtual function should be applied.    PFN is a pointer to the virtual function.     Note that this macro is g++ specific (FIXME). */
end_comment

begin_define
define|#
directive|define
name|VTBL_FNADDR_OFFSET
value|2
end_define

begin_comment
comment|/* Macro that yields non-zero value iff NAME is the prefix for C++ operator    names.  If you leave out the parenthesis here you will lose!    Currently 'o' 'p' CPLUS_MARKER is used for both the symbol in the    symbol-file and the names in gdb's symbol table.    Note that this macro is g++ specific (FIXME). */
end_comment

begin_define
define|#
directive|define
name|OPNAME_PREFIX_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|((NAME)[0] == 'o'&& (NAME)[1] == 'p'&& is_cplus_marker ((NAME)[2]))
end_define

begin_comment
comment|/* Macro that yields non-zero value iff NAME is the prefix for C++ vtbl    names.  Note that this macro is g++ specific (FIXME).    '_vt$' is the old cfront-style vtables; '_VT$' is the new    style, using thunks (where '$' is really CPLUS_MARKER). */
end_comment

begin_define
define|#
directive|define
name|VTBL_PREFIX_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|((NAME)[0] == '_' \&& (((NAME)[1] == 'V'&& (NAME)[2] == 'T') \        || ((NAME)[1] == 'v'&& (NAME)[2] == 't')) \&& is_cplus_marker ((NAME)[3]))
end_define

begin_comment
comment|/* Macro that yields non-zero value iff NAME is the prefix for C++ destructor    names.  Note that this macro is g++ specific (FIXME).  */
end_comment

begin_define
define|#
directive|define
name|DESTRUCTOR_PREFIX_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|((NAME)[0] == '_'&& is_cplus_marker ((NAME)[1])&& (NAME)[2] == '_')
end_define

begin_escape
end_escape

begin_comment
comment|/* External variables and functions for the objects described above. */
end_comment

begin_comment
comment|/* This symtab variable specifies the current file for printing source lines */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|current_source_symtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the next line to print for listing source lines.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_source_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See the comment in symfile.c about how current_objfile is used. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|current_objfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we are nested inside psymtab_to_symtab. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|currently_reading_symtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From utils.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|demangle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|asm_demangle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symtab.c lookup functions */
end_comment

begin_comment
comment|/* lookup a symbol table by source file name */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lookup_symtab
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup a symbol by name (optional block, optional symtab) */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|block
operator|*
operator|,
specifier|const
name|namespace_enum
operator|,
name|int
operator|*
operator|,
expr|struct
name|symtab
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup a symbol by name, within a specified block */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_block_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|block
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|namespace_enum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup a [struct, union, enum] by name, within a specified block */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_struct
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_union
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_enum
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup the function corresponding to the block */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|block_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from blockframe.c: */
end_comment

begin_comment
comment|/* lookup the function symbol corresponding to the address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|find_pc_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup the function corresponding to the address and section */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|find_pc_sect_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup function from address, return name, start addr and end addr */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|find_pc_partial_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|char
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_pc_function_cache
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_pc_sect_partial_function
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from symtab.c: */
end_comment

begin_comment
comment|/* lookup partial symbol table by filename */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|lookup_partial_symtab
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup partial symbol table by address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_pc_psymtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup partial symbol table by address and section */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_pc_sect_psymtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup full symbol table by address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_symtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup full symbol table by address and section */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_sect_symtab
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup partial symbol by address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_psymbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup partial symbol by address and section */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_sect_psymbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|,
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_pc_line_pc_range
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|contained_in
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|,
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reread_symbols
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lookup_transparent_type
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro for name of symbol to indicate a file compiled with gcc. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_COMPILED_FLAG_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|GCC_COMPILED_FLAG_SYMBOL
value|"gcc_compiled."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macro for name of symbol to indicate a file compiled with gcc2. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC2_COMPILED_FLAG_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|GCC2_COMPILED_FLAG_SYMBOL
value|"gcc2_compiled."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions for dealing with the minimal symbol table, really a misc    address<->symbol mapping for things we don't have debug symbols for.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|prim_record_minimal_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|minimal_symbol_type
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|prim_record_minimal_symbol_and_info
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
expr|enum
name|minimal_symbol_type
operator|,
name|char
operator|*
name|info
operator|,
name|int
name|section
operator|,
name|asection
operator|*
name|bfd_section
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SOFUN_ADDRESS_MAYBE_MISSING
end_ifdef

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|find_stab_function_addr
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|partial_symtab
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_text
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_solib_trampoline
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_by_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_by_pc_section
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_solib_trampoline_symbol_by_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|find_solib_trampoline_target
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_minimal_symbol_collection
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|discard_minimal_symbols
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|install_minimal_symbols
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sort all the minimal symbols in OBJFILE.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|msymbols_sort
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
name|objfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|symtab_and_line
block|{
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
name|asection
modifier|*
name|section
decl_stmt|;
comment|/* Line number.  Line numbers start at 1 and proceed through symtab->nlines.      0 is never a valid line number; it is used to indicate that line number      information is not available.  */
name|int
name|line
decl_stmt|;
name|CORE_ADDR
name|pc
decl_stmt|;
name|CORE_ADDR
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INIT_SAL
parameter_list|(
name|sal
parameter_list|)
value|{ \   (sal)->symtab  = 0;   \   (sal)->section = 0;   \   (sal)->line    = 0;   \   (sal)->pc      = 0;   \   (sal)->end     = 0;   \ }
end_define

begin_struct
struct|struct
name|symtabs_and_lines
block|{
name|struct
name|symtab_and_line
modifier|*
name|sals
decl_stmt|;
name|int
name|nelts
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Some types and macros needed for exception catchpoints.    Can't put these in target.h because symtab_and_line isn't    known there. This file will be included by breakpoint.c,    hppa-tdep.c, etc. */
end_comment

begin_comment
comment|/* Enums for exception-handling support */
end_comment

begin_enum
enum|enum
name|exception_event_kind
block|{
name|EX_EVENT_THROW
block|,
name|EX_EVENT_CATCH
block|}
enum|;
end_enum

begin_comment
comment|/* Type for returning info about an exception */
end_comment

begin_struct
struct|struct
name|exception_event_record
block|{
name|enum
name|exception_event_kind
name|kind
decl_stmt|;
name|struct
name|symtab_and_line
name|throw_sal
decl_stmt|;
name|struct
name|symtab_and_line
name|catch_sal
decl_stmt|;
comment|/* This may need to be extended in the future, if      some platforms allow reporting more information,      such as point of rethrow, type of exception object,      type expected by catch clause, etc. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_KIND
value|(current_exception_event->kind)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_CATCH_SAL
value|(current_exception_event->catch_sal)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_CATCH_LINE
value|(current_exception_event->catch_sal.line)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_CATCH_FILE
value|(current_exception_event->catch_sal.symtab->filename)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_CATCH_PC
value|(current_exception_event->catch_sal.pc)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_THROW_SAL
value|(current_exception_event->throw_sal)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_THROW_LINE
value|(current_exception_event->throw_sal.line)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_THROW_FILE
value|(current_exception_event->throw_sal.symtab->filename)
end_define

begin_define
define|#
directive|define
name|CURRENT_EXCEPTION_THROW_PC
value|(current_exception_event->throw_sal.pc)
end_define

begin_escape
end_escape

begin_comment
comment|/* Given a pc value, return line number it is in.  Second arg nonzero means    if pc is on the boundary use the previous statement's line number.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab_and_line
name|find_pc_line
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Same function, but specify a section as well as an address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab_and_line
name|find_pc_sect_line
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an address, return the nearest symbol at or below it in memory.    Optionally return the symtab it's from through 2nd arg, and the    address in inferior memory of the symbol through 3rd arg.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|find_addr_symbol
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
expr|struct
name|symtab
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a symtab and line number, return the pc there.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|find_line_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_line_pc_range
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab_and_line
operator|,
name|CORE_ADDR
operator|*
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resolve_sal_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab_and_line
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a string, return the line specified by it.  For commands like "list"    and "breakpoint".  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec_1
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_1
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|,
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|MAINTENANCE_CMDS
end_if

begin_comment
comment|/* Symmisc.c */
end_comment

begin_decl_stmt
name|void
name|maintenance_print_symbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_psymbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_msymbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_print_objfiles
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|maintenance_check_symtabs
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maint.c */
end_comment

begin_decl_stmt
name|void
name|maintenance_print_statistics
name|PARAMS
argument_list|(
operator|(
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

begin_decl_stmt
specifier|extern
name|void
name|free_symtab
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symbol-reading stuff in symfile.c and solib.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|psymtab_to_symtab
name|PARAMS
argument_list|(
operator|(
expr|struct
name|partial_symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_solib
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|objfile
modifier|*
name|symbol_file_add
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|identify_source_line
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_source_lines
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|forget_cached_source_info
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|select_source_symtab
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|make_symbol_completion_list
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
modifier|*
name|make_symbol_overload_list
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symtab.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_main_psymtab
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blockframe.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|blockvector
modifier|*
name|blockvector_for_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|blockvector
modifier|*
name|blockvector_for_pc_sect
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|asection
operator|*
operator|,
name|int
operator|*
operator|,
expr|struct
name|symtab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symfile.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_symtab_users
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|language
name|deduce_language_from_filename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symtab.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_prologue
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|pc
operator|,
name|CORE_ADDR
name|func_start
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symbol
modifier|*
name|fixup_symbol_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
expr|struct
name|objfile
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Symbol searching */
end_comment

begin_comment
comment|/* When using search_symbols, a list of the following structs is returned.    Callers must free the search list using free_symbol_search! */
end_comment

begin_struct
struct|struct
name|symbol_search
block|{
comment|/* The block in which the match was found. Could be, for example,      STATIC_BLOCK or GLOBAL_BLOCK. */
name|int
name|block
decl_stmt|;
comment|/* Information describing what was found.       If symtab abd symbol are NOT NULL, then information was found      for this match. */
name|struct
name|symtab
modifier|*
name|symtab
decl_stmt|;
name|struct
name|symbol
modifier|*
name|symbol
decl_stmt|;
comment|/* If msymbol is non-null, then a match was made on something for      which only minimal_symbols exist. */
name|struct
name|minimal_symbol
modifier|*
name|msymbol
decl_stmt|;
comment|/* A link to the next match, or NULL for the end. */
name|struct
name|symbol_search
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|search_symbols
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|namespace_enum
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
expr|struct
name|symbol_search
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_search_symbols
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol_search
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(SYMTAB_H) */
end_comment

end_unit

