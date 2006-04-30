begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Symbol table definitions for GDB.     Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995,    1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 Free Software    Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
comment|/* Opaque declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|blockvector
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|axs_value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|agent_expr
struct_decl|;
end_struct_decl

begin_comment
comment|/* Some of the structures in this file are space critical.    The space-critical structures are:       struct general_symbol_info      struct symbol      struct partial_symbol     These structures are layed out to encourage good packing.    They use ENUM_BITFIELD and short int fields, and they order the    structure members so that fields less than a word are next    to each other so they can be packed together. */
end_comment

begin_comment
comment|/* Rearranged: used ENUM_BITFIELD and rearranged field order in    all the space critical structures (plus struct minimal_symbol).    Memory usage dropped from 99360768 bytes to 90001408 bytes.    I measured this with before-and-after tests of    "HEAD-old-gdb -readnow HEAD-old-gdb" and    "HEAD-new-gdb -readnow HEAD-old-gdb" on native i686-pc-linux-gnu,    red hat linux 8, with LD_LIBRARY_PATH=/usr/lib/debug,    typing "maint space 1" at the first command prompt.     Here is another measurement (from andrew c):      # no /usr/lib/debug, just plain glibc, like a normal user      gdb HEAD-old-gdb      (gdb) break internal_error      (gdb) run      (gdb) maint internal-error      (gdb) backtrace      (gdb) maint space 1     gdb gdb_6_0_branch  2003-08-19  space used: 8896512    gdb HEAD            2003-08-19  space used: 8904704    gdb HEAD            2003-08-21  space used: 8396800 (+symtab.h)    gdb HEAD            2003-08-21  space used: 8265728 (+gdbtypes.h)     The third line shows the savings from the optimizations in symtab.h.    The fourth line shows the savings from the optimizations in    gdbtypes.h.  Both optimizations are in gdb HEAD now.     --chastain 2003-08-21  */
end_comment

begin_comment
comment|/* Define a structure for the information that is common to all symbol types,    including minimal symbols, partial symbols, and full symbols.  In a    multilanguage environment, some language specific information may need to    be recorded along with each symbol. */
end_comment

begin_comment
comment|/* This structure is space critical.  See space comments at the top. */
end_comment

begin_struct
struct|struct
name|general_symbol_info
block|{
comment|/* Name of the symbol.  This is a required field.  Storage for the      name is allocated on the objfile_obstack for the associated      objfile.  For languages like C++ that make a distinction between      the mangled name and demangled name, this is the mangled      name.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Value of the symbol.  Which member of this union to use, and what      it means, depends on what kind of symbol this is and its      SYMBOL_CLASS.  See comments there for more details.  All of these      are in host byte order (though what they point to might be in      target byte order, e.g. LOC_CONST_BYTES).  */
union|union
block|{
comment|/* The fact that this is a long not a LONGEST mainly limits the        range of a LOC_CONST.  Since LOC_CONST_BYTES exists, I'm not        sure that is a big deal.  */
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
block|{
comment|/* This is in fact used for C++, Java, and Objective C.  */
name|char
modifier|*
name|demangled_name
decl_stmt|;
block|}
name|cplus_specific
struct|;
block|}
name|language_specific
union|;
comment|/* Record the source code language that applies to this symbol.      This is used to select one of the fields from the language specific      union above. */
name|ENUM_BITFIELD
argument_list|(
argument|language
argument_list|)
name|language
label|:
literal|8
expr_stmt|;
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

begin_function_decl
specifier|extern
name|CORE_ADDR
name|symbol_overlayed_address
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Note that all the following SYMBOL_* macros are used with the    SYMBOL argument being either a partial symbol, a minimal symbol or    a full symbol.  All three types have a ginfo field.  In particular    the SYMBOL_INIT_LANGUAGE_SPECIFIC, SYMBOL_INIT_DEMANGLED_NAME,    SYMBOL_DEMANGLED_NAME macros cannot be entirely substituted by    functions, unless the callers are changed to pass in the ginfo    field only, instead of the SYMBOL parameter.  */
end_comment

begin_define
define|#
directive|define
name|DEPRECATED_SYMBOL_NAME
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
comment|/* Initializes the language dependent portion of a symbol    depending upon the language for the symbol. */
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
value|(symbol_init_language_specific (&(symbol)->ginfo, (language)))
end_define

begin_function_decl
specifier|extern
name|void
name|symbol_init_language_specific
parameter_list|(
name|struct
name|general_symbol_info
modifier|*
name|symbol
parameter_list|,
name|enum
name|language
name|language
parameter_list|)
function_decl|;
end_function_decl

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
value|(symbol_init_demangled_name (&(symbol)->ginfo, (obstack)))
end_define

begin_function_decl
specifier|extern
name|void
name|symbol_init_demangled_name
parameter_list|(
name|struct
name|general_symbol_info
modifier|*
name|symbol
parameter_list|,
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SYMBOL_SET_NAMES
parameter_list|(
name|symbol
parameter_list|,
name|linkage_name
parameter_list|,
name|len
parameter_list|,
name|objfile
parameter_list|)
define|\
value|symbol_set_names (&(symbol)->ginfo, linkage_name, len, objfile)
end_define

begin_function_decl
specifier|extern
name|void
name|symbol_set_names
parameter_list|(
name|struct
name|general_symbol_info
modifier|*
name|symbol
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
name|int
name|len
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Now come lots of name accessor macros.  Short version as to when to    use which: Use SYMBOL_NATURAL_NAME to refer to the name of the    symbol in the original source code.  Use SYMBOL_LINKAGE_NAME if you    want to know what the linker thinks the symbol's name is.  Use    SYMBOL_PRINT_NAME for output.  Use SYMBOL_DEMANGLED_NAME if you    specifically need to know whether SYMBOL_NATURAL_NAME and    SYMBOL_LINKAGE_NAME are different.  Don't use    DEPRECATED_SYMBOL_NAME at all: instances of that macro should be    replaced by SYMBOL_NATURAL_NAME, SYMBOL_LINKAGE_NAME, or perhaps    SYMBOL_PRINT_NAME.  */
end_comment

begin_comment
comment|/* Return SYMBOL's "natural" name, i.e. the name that it was called in    the original source code.  In languages like C++ where symbols may    be mangled for ease of manipulation by the linker, this is the    demangled name.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_NATURAL_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(symbol_natural_name (&(symbol)->ginfo))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|symbol_natural_name
parameter_list|(
specifier|const
name|struct
name|general_symbol_info
modifier|*
name|symbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return SYMBOL's name from the point of view of the linker.  In    languages like C++ where symbols may be mangled for ease of    manipulation by the linker, this is the mangled name; otherwise,    it's the same as SYMBOL_NATURAL_NAME.  This is currently identical    to DEPRECATED_SYMBOL_NAME, but please use SYMBOL_LINKAGE_NAME when    appropriate: it conveys the additional semantic information that    you really have thought about the issue and decided that you mean    SYMBOL_LINKAGE_NAME instead of SYMBOL_NATURAL_NAME.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_LINKAGE_NAME
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ginfo.name
end_define

begin_comment
comment|/* Return the demangled name for a symbol based on the language for    that symbol.  If no demangled name exists, return NULL. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_DEMANGLED_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(symbol_demangled_name (&(symbol)->ginfo))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|symbol_demangled_name
parameter_list|(
name|struct
name|general_symbol_info
modifier|*
name|symbol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macro that returns a version of the name of a symbol that is    suitable for output.  In C++ this is the "demangled" form of the    name if demangle is on and the "mangled" form of the name if    demangle is off.  In other languages this is just the symbol name.    The result should never be NULL.  Don't use this for internal    purposes (e.g. storing in a hashtable): it's only suitable for    output.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_PRINT_NAME
parameter_list|(
name|symbol
parameter_list|)
define|\
value|(demangle ? SYMBOL_NATURAL_NAME (symbol) : SYMBOL_LINKAGE_NAME (symbol))
end_define

begin_comment
comment|/* Macro that tests a symbol for a match against a specified name string.    First test the unencoded name, then looks for and test a C++ encoded    name if it exists.  Note that whitespace is ignored while attempting to    match a C++ encoded name, so that "foo::bar(int,long)" is the same as    "foo :: bar (int, long)".    Evaluates to zero if the match fails, or nonzero if it succeeds. */
end_comment

begin_comment
comment|/* Macro that tests a symbol for a match against a specified name    string.  It tests against SYMBOL_NATURAL_NAME, and it ignores    whitespace and trailing parentheses.  (See strcmp_iw for details    about its behavior.)  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_MATCHES_NATURAL_NAME
parameter_list|(
name|symbol
parameter_list|,
name|name
parameter_list|)
define|\
value|(strcmp_iw (SYMBOL_NATURAL_NAME (symbol), (name)) == 0)
end_define

begin_comment
comment|/* Classification types for a minimal symbol.  These should be taken as    "advisory only", since if gdb can't easily figure out a    classification it simply selects mst_unknown.  It may also have to    guess when it can't figure out which is a better match between two    types (mst_data versus mst_bss) for example.  Since the minimal    symbol info is sometimes derived from the BFD library's view of a    file, we need to live with what information bfd supplies. */
end_comment

begin_enum
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
comment|/* GDB uses mst_solib_trampoline for the start address of a shared      library trampoline entry.  Breakpoints for shared library functions      are put there if the shared library is not yet loaded.      After the shared library is loaded, lookup_minimal_symbol will      prefer the minimal symbol from the shared library (usually      a mst_text symbol) over the mst_solib_trampoline symbol, and the      breakpoints will be moved to their true address in the shared      library via breakpoint_re_set.  */
name|mst_solib_trampoline
block|,
comment|/* Shared library trampoline code */
comment|/* For the mst_file* types, the names are only guaranteed to be unique      within a given .o file.  */
name|mst_file_text
block|,
comment|/* Static version of mst_text */
name|mst_file_data
block|,
comment|/* Static version of mst_data */
name|mst_file_bss
comment|/* Static version of mst_bss */
block|}
enum|;
end_enum

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
comment|/* The info field is available for caching machine-specific      information so it doesn't have to rederive the info constantly      (over a serial line).  It is initialized to zero and stays that      way until target-dependent code sets it.  Storage for any data      pointed to by this field should be allocated on the      objfile_obstack for the associated objfile.  The type would be      "void *" except for reasons of compatibility with older      compilers.  This field is optional.       Currently, the AMD 29000 tdep.c uses it to remember things it has decoded      from the instructions in the function header, and the MIPS-16 code uses      it to identify 16-bit procedures.  */
name|char
modifier|*
name|info
decl_stmt|;
comment|/* Size of this symbol.  end_psymtab in dbxread.c uses this      information to calculate the end of the partial symtab based on the      address of the last symbol plus the size of the last symbol.  */
name|unsigned
name|long
name|size
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
comment|/* Classification type for this minimal symbol.  */
name|ENUM_BITFIELD
argument_list|(
argument|minimal_symbol_type
argument_list|)
name|type
label|:
literal|8
expr_stmt|;
comment|/* Minimal symbols with the same hash key are kept on a linked      list.  This is the link.  */
name|struct
name|minimal_symbol
modifier|*
name|hash_next
decl_stmt|;
comment|/* Minimal symbols are stored in two different hash tables.  This is      the `next' pointer for the demangled hash table.  */
name|struct
name|minimal_symbol
modifier|*
name|demangled_hash_next
decl_stmt|;
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
name|MSYMBOL_SIZE
parameter_list|(
name|msymbol
parameter_list|)
value|(msymbol)->size
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
comment|/* Represent one symbol name; a variable, constant, function or typedef.  */
end_comment

begin_comment
comment|/* Different name domains for symbols.  Looking up a symbol specifies a    domain and ignores symbol definitions in other name domains. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|domain_enum_tag
block|{
comment|/* UNDEF_DOMAIN is used when a domain has not been discovered or      none of the following apply.  This usually indicates an error either      in the symbol information or in gdb's handling of symbols. */
name|UNDEF_DOMAIN
block|,
comment|/* VAR_DOMAIN is the usual domain.  In C, this contains variables,      function names, typedef names and enum type values. */
name|VAR_DOMAIN
block|,
comment|/* STRUCT_DOMAIN is used in C to hold struct, union and enum type names.      Thus, if `struct foo' is used in a C program, it produces a symbol named      `foo' in the STRUCT_DOMAIN. */
name|STRUCT_DOMAIN
block|,
comment|/* LABEL_DOMAIN may be used for names of labels (for gotos);      currently it is not used and labels are not recorded at all.  */
name|LABEL_DOMAIN
block|,
comment|/* Searching domains. These overlap with VAR_DOMAIN, providing      some granularity with the search_symbols function. */
comment|/* Everything in VAR_DOMAIN minus FUNCTIONS_-, TYPES_-, and      METHODS_DOMAIN */
name|VARIABLES_DOMAIN
block|,
comment|/* All functions -- for some reason not methods, though. */
name|FUNCTIONS_DOMAIN
block|,
comment|/* All defined types */
name|TYPES_DOMAIN
block|,
comment|/* All class methods -- why is this separated out? */
name|METHODS_DOMAIN
block|}
name|domain_enum
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
comment|/* Value is in register number SYMBOL_VALUE.  Just like LOC_REGISTER      except this is an argument.  Probably the cleaner way to handle      this would be to separate address_class (which would include      separate ARG and LOCAL to deal with the frame's arguments      (get_frame_args_address) versus the frame's locals      (get_frame_locals_address), and an is_argument flag.       For some symbol formats (stabs, for some compilers at least),      the compiler generates two symbols, an argument and a register.      In some cases we combine them to a single LOC_REGPARM in symbol      reading, but currently not for all cases (e.g. it's passed on the      stack and then loaded into a register).  */
name|LOC_REGPARM
block|,
comment|/* Value is in specified register.  Just like LOC_REGPARM except the      register holds the address of the argument instead of the argument      itself. This is currently used for the passing of structs and unions      on sparc and hppa.  It is also used for call by reference where the      address is in a register, at least by mipsread.c.  */
name|LOC_REGPARM_ADDR
block|,
comment|/* Value is a local variable at SYMBOL_VALUE offset in stack frame.  */
name|LOC_LOCAL
block|,
comment|/* Value not used; definition in SYMBOL_TYPE.  Symbols in the domain      STRUCT_DOMAIN all have this class.  */
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
comment|/* Value is arg at SYMBOL_VALUE offset in stack frame. Differs from      LOC_LOCAL in that symbol is an argument; differs from LOC_ARG in      that we find it in the frame (get_frame_locals_address), not in      the arglist (get_frame_args_address).  Added for i960, which      passes args in regs then copies to frame.  */
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
comment|/* Value is at a thread-specific location calculated by a      target-specific method. This is used only by hppa.  */
name|LOC_HP_THREAD_LOCAL_STATIC
block|,
comment|/* The variable does not actually exist in the program.      The value is ignored.  */
name|LOC_OPTIMIZED_OUT
block|,
comment|/* The variable is static, but actually lives at * (address).    * I.e. do an extra indirection to get to it.    * This is used on HP-UX to get at globals that are allocated    * in shared libraries, where references from images other    * than the one where the global was allocated are done    * with a level of indirection.    */
name|LOC_INDIRECT
block|,
comment|/* The variable's address is computed by a set of location      functions (see "struct location_funcs" below).  */
name|LOC_COMPUTED
block|,
comment|/* Same as LOC_COMPUTED, but for function arguments.  */
name|LOC_COMPUTED_ARG
block|}
enum|;
end_enum

begin_comment
comment|/* The methods needed to implement a symbol class.  These methods can    use the symbol's .aux_value for additional per-symbol information.     At present this is only used to implement location expressions.  */
end_comment

begin_struct
struct|struct
name|symbol_ops
block|{
comment|/* Return the value of the variable SYMBOL, relative to the stack      frame FRAME.  If the variable has been optimized out, return      zero.       Iff `read_needs_frame (SYMBOL)' is zero, then FRAME may be zero.  */
name|struct
name|value
modifier|*
function_decl|(
modifier|*
name|read_variable
function_decl|)
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
comment|/* Return non-zero if we need a frame to find the value of the SYMBOL.  */
name|int
function_decl|(
modifier|*
name|read_needs_frame
function_decl|)
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|)
function_decl|;
comment|/* Write to STREAM a natural-language description of the location of      SYMBOL.  */
name|int
function_decl|(
modifier|*
name|describe_location
function_decl|)
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|/* Tracepoint support.  Append bytecodes to the tracepoint agent      expression AX that push the address of the object SYMBOL.  Set      VALUE appropriately.  Note --- for objects in registers, this      needn't emit any code; as long as it sets VALUE properly, then      the caller will generate the right code in the process of      treating this as an lvalue or rvalue.  */
name|void
function_decl|(
modifier|*
name|tracepoint_var_ref
function_decl|)
parameter_list|(
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|agent_expr
modifier|*
name|ax
parameter_list|,
name|struct
name|axs_value
modifier|*
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is space critical.  See space comments at the top. */
end_comment

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
comment|/* Domain code.  */
name|ENUM_BITFIELD
argument_list|(
argument|domain_enum_tag
argument_list|)
name|domain
label|:
literal|6
expr_stmt|;
comment|/* Address class */
comment|/* NOTE: cagney/2003-11-02: The fields "aclass" and "ops" contain      overlapping information.  By creating a per-aclass ops vector, or      using the aclass as an index into an ops table, the aclass and      ops fields can be merged.  The latter, for instance, would shave      32-bits from each symbol (relative to a symbol lookup, any table      index overhead would be in the noise).  */
name|ENUM_BITFIELD
argument_list|(
argument|address_class
argument_list|)
name|aclass
label|:
literal|6
expr_stmt|;
comment|/* Line number of definition.  FIXME:  Should we really make the assumption      that nobody will try to debug files longer than 64K lines?  What about      machine generated programs? */
name|unsigned
name|short
name|line
decl_stmt|;
comment|/* Method's for symbol's of this class.  */
comment|/* NOTE: cagney/2003-11-02: See comment above attached to "aclass".  */
specifier|const
name|struct
name|symbol_ops
modifier|*
name|ops
decl_stmt|;
comment|/* Some symbols require additional information to be recorded on a      per- symbol basis.  Stash those values here. */
union|union
block|{
comment|/* Used by LOC_BASEREG and LOC_BASEREG_ARG.  */
name|short
name|basereg
decl_stmt|;
comment|/* An arbitrary data pointer.  Note that this data must be        allocated using the same obstack as the symbol itself.  */
comment|/* So far it is only used by LOC_COMPUTED and LOC_COMPUTED_ARG to        find the location location information.  For a LOC_BLOCK symbol        for a function in a compilation unit compiled with DWARF 2        information, this is information used internally by the DWARF 2        code --- specifically, the location expression for the frame        base for this function.  */
comment|/* FIXME drow/2003-02-21: For the LOC_BLOCK case, it might be better        to add a magic symbol to the block containing this information,        or to have a generic debug info annotation slot for symbols.  */
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|aux_value
union|;
name|struct
name|symbol
modifier|*
name|hash_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYMBOL_DOMAIN
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->domain
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
name|SYMBOL_OBJFILE
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aux_value.objfile
end_define

begin_define
define|#
directive|define
name|SYMBOL_OPS
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->ops
end_define

begin_define
define|#
directive|define
name|SYMBOL_LOCATION_BATON
parameter_list|(
name|symbol
parameter_list|)
value|(symbol)->aux_value.ptr
end_define

begin_escape
end_escape

begin_comment
comment|/* A partial_symbol records the name, domain, and address class of    symbols whose types we have not parsed yet.  For functions, it also    contains their memory address, so we can find them from a PC value.    Each partial_symbol sits in a partial_symtab, all of which are chained    on a  partial symtab list and which points to the corresponding     normal symtab once the partial_symtab has been referenced.  */
end_comment

begin_comment
comment|/* This structure is space critical.  See space comments at the top. */
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
name|ENUM_BITFIELD
argument_list|(
argument|domain_enum_tag
argument_list|)
name|domain
label|:
literal|6
expr_stmt|;
comment|/* Address class (for info_symbols) */
name|ENUM_BITFIELD
argument_list|(
argument|address_class
argument_list|)
name|aclass
label|:
literal|6
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PSYMBOL_DOMAIN
parameter_list|(
name|psymbol
parameter_list|)
value|(psymbol)->domain
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
comment|/* The order of entries in the linetable is significant.  They should    be sorted by increasing values of the pc field.  If there is more than    one entry for a given pc, then I'm not sure what should happen (and    I not sure whether we currently handle it the best way).     Example: a C for statement generally looks like this     10   0x100   - for the init/test part of a for stmt.    20   0x200    30   0x300    10   0x400   - for the increment part of a for stmt.     If an entry has a line number of zero, it marks the start of a PC    range for which no line number information is available.  It is    acceptable, though wasteful of table space, for such a range to be    zero length.  */
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
define|\
value|((whichone == -1) \     ? (internal_error (__FILE__, __LINE__, "Section index is uninitialized"), -1) \     : secoff->offsets[whichone])
end_define

begin_comment
comment|/* The size of a section_offsets table for N sections.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_N_SECTION_OFFSETS
parameter_list|(
name|n
parameter_list|)
define|\
value|(sizeof (struct section_offsets) \    + sizeof (((struct section_offsets *) 0)->offsets) * ((n)-1))
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
comment|/* List of all symbol scope blocks for this symtab.  May be shared      between different symtabs (and normally is for all the symtabs      in a given compilation unit).  */
name|struct
name|blockvector
modifier|*
name|blockvector
decl_stmt|;
comment|/* Table mapping core addresses to line numbers for this file.      Can be NULL if none.  Never shared between different symtabs.  */
name|struct
name|linetable
modifier|*
name|linetable
decl_stmt|;
comment|/* Section in objfile->section_offsets for the blockvector and      the linetable.  Probably always SECT_OFF_TEXT.  */
name|int
name|block_line_section
decl_stmt|;
comment|/* If several symtabs share a blockvector, exactly one of them      should be designated the primary, so that the blockvector      is relocated exactly once by objfile_relocate.  */
name|int
name|primary
decl_stmt|;
comment|/* The macro table for this symtab.  Like the blockvector, this      may be shared between different symtabs --- and normally is for      all the symtabs in a given compilation unit.  */
name|struct
name|macro_table
modifier|*
name|macro_table
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
comment|/* This component says how to free the data we point to:      free_contents => do a tree walk and free each object.      free_nothing => do nothing; some other symtab will free      the data this one uses.      free_linetable => free just the linetable.  FIXME: Is this redundant      with the primary field?  */
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
comment|/* A function to call to free space, if necessary.  This is IN      ADDITION to the action indicated by free_code.  */
name|void
function_decl|(
modifier|*
name|free_func
function_decl|)
parameter_list|(
name|struct
name|symtab
modifier|*
name|symtab
parameter_list|)
function_decl|;
comment|/* Total number of lines found in source file.  */
name|int
name|nlines
decl_stmt|;
comment|/* line_charpos[N] is the position of the (N-1)th line of the      source file.  "position" means something we can lseek() to; it      is not guaranteed to be useful any other way.  */
name|int
modifier|*
name|line_charpos
decl_stmt|;
comment|/* Language of this source file.  */
name|enum
name|language
name|language
decl_stmt|;
comment|/* String that identifies the format of the debugging information, such      as "stabs", "dwarf 1", "dwarf 2", "coff", etc.  This is mostly useful      for automated testing of gdb but may also be information that is      useful to the user. */
name|char
modifier|*
name|debugformat
decl_stmt|;
comment|/* String of version information.  May be zero.  */
name|char
modifier|*
name|version
decl_stmt|;
comment|/* Full name of file as found by searching the source path.      NULL if not yet known.  */
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
comment|/* Each source file that has not been fully read in is represented by    a partial_symtab.  This contains the information on where in the    executable the debugging symbols for a specific file are, and a    list of names of global symbols which are located in this file.    They are all chained on partial symtab lists.     Even after the source file has been read into a symtab, the    partial_symtab remains around.  They are allocated on an obstack,    objfile_obstack.  FIXME, this is bad for dynamic linking or VxWorks-    style execution of a bunch of .o's.  */
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
comment|/* Full path of the source file.  NULL if not known.  */
name|char
modifier|*
name|fullname
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
function_decl|(
modifier|*
name|read_symtab
function_decl|)
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|)
function_decl|;
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
comment|/* External variables and functions for the objects described above. */
end_comment

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

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|lookup_symtab
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup a symbol by name (optional block, optional symtab) */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
parameter_list|,
specifier|const
name|domain_enum
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A default version of lookup_symbol_nonlocal for use by languages    that can't think of anything better to do.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|basic_lookup_symbol_nonlocal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
parameter_list|,
specifier|const
name|domain_enum
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Some helper functions for languages that need to write their own    lookup_symbol_nonlocal functions.  */
end_comment

begin_comment
comment|/* Lookup a symbol in the static block associated to BLOCK, if there    is one; do nothing if BLOCK is NULL or a global block.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol_static
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|,
specifier|const
name|domain_enum
name|domain
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|symtab
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lookup a symbol in all files' global blocks (searching psymtabs if    necessary).  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol_global
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
specifier|const
name|domain_enum
name|domain
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|symtab
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lookup a symbol within the block BLOCK.  This, unlike    lookup_symbol_block, will set SYMTAB and BLOCK_FOUND correctly, and    will fix up the symbol if necessary.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_symbol_aux_block
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|,
specifier|const
name|domain_enum
name|domain
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|symtab
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lookup a partial symbol.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|lookup_partial_symbol
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|domain_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup a symbol by name, within a specified block */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|lookup_block_symbol
parameter_list|(
specifier|const
name|struct
name|block
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|domain_enum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup a [struct, union, enum] by name, within a specified block */
end_comment

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_struct
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_union
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_enum
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from blockframe.c: */
end_comment

begin_comment
comment|/* lookup the function symbol corresponding to the address */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|find_pc_function
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup the function corresponding to the address and section */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|find_pc_sect_function
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup function from address, return name, start addr and end addr */
end_comment

begin_function_decl
specifier|extern
name|int
name|find_pc_partial_function
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_pc_function_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_pc_sect_partial_function
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from symtab.c: */
end_comment

begin_comment
comment|/* lookup partial symbol table by filename */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|lookup_partial_symtab
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup partial symbol table by address */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_pc_psymtab
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup partial symbol table by address and section */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_pc_sect_psymtab
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup full symbol table by address */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_symtab
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup full symbol table by address and section */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|find_pc_sect_symtab
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup partial symbol by address */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_psymbol
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup partial symbol by address and section */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|find_pc_sect_psymbol
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_pc_line_pc_range
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reread_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lookup_transparent_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|basic_lookup_transparent_type
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|prim_record_minimal_symbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|enum
name|minimal_symbol_type
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|prim_record_minimal_symbol_and_info
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|enum
name|minimal_symbol_type
parameter_list|,
name|char
modifier|*
name|info
parameter_list|,
name|int
name|section
parameter_list|,
name|asection
modifier|*
name|bfd_section
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|msymbol_hash_iw
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|msymbol_hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_minsym_to_hash_table
parameter_list|(
name|struct
name|minimal_symbol
modifier|*
name|sym
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_text
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_solib_trampoline
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_by_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_minimal_symbol_by_pc_section
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|minimal_symbol
modifier|*
name|lookup_solib_trampoline_symbol_by_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|find_solib_trampoline_target
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_minimal_symbol_collection
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup_discard_minimal_symbols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|install_minimal_symbols
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sort all the minimal symbols in OBJFILE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|msymbols_sort
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|init_sal
parameter_list|(
name|struct
name|symtab_and_line
modifier|*
name|sal
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|struct
name|symtab_and_line
name|find_pc_line
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Same function, but specify a section as well as an address */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtab_and_line
name|find_pc_sect_line
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a symtab and line number, return the pc there.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|find_line_pc
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_line_pc_range
parameter_list|(
name|struct
name|symtab_and_line
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resolve_sal_pc
parameter_list|(
name|struct
name|symtab_and_line
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a string, return the line specified by it.  For commands like "list"    and "breakpoint".  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtabs_and_lines
name|decode_line_spec_1
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Symmisc.c */
end_comment

begin_function_decl
name|void
name|maintenance_print_symbols
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_print_psymbols
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_print_msymbols
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_print_objfiles
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_info_symtabs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_info_psymtabs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|maintenance_check_symtabs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* maint.c */
end_comment

begin_function_decl
name|void
name|maintenance_print_statistics
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_symtab
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Symbol-reading stuff in symfile.c and solib.c.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|psymtab_to_symtab
parameter_list|(
name|struct
name|partial_symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_solib
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* source.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|identify_source_line
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_source_lines
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forget_cached_source_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|select_source_symtab
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|make_symbol_completion_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|make_file_symbol_completion_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|make_source_files_completion_list
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* symtab.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|partial_symtab
modifier|*
name|find_main_psymtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtab
modifier|*
name|find_line_symtab
parameter_list|(
name|struct
name|symtab
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symtab_and_line
name|find_function_start_sal
parameter_list|(
name|struct
name|symbol
modifier|*
name|sym
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* symfile.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|clear_symtab_users
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|language
name|deduce_language_from_filename
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* symtab.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|in_prologue
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|func_start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|skip_prologue_using_sal
parameter_list|(
name|CORE_ADDR
name|func_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|fixup_symbol_section
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|,
name|struct
name|objfile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|partial_symbol
modifier|*
name|fixup_psymbol_section
parameter_list|(
name|struct
name|partial_symbol
modifier|*
name|psym
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Symbol searching */
end_comment

begin_comment
comment|/* When using search_symbols, a list of the following structs is returned.    Callers must free the search list using free_search_symbols! */
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

begin_function_decl
specifier|extern
name|void
name|search_symbols
parameter_list|(
name|char
modifier|*
parameter_list|,
name|domain_enum
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|symbol_search
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_search_symbols
parameter_list|(
name|struct
name|symbol_search
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cleanup
modifier|*
name|make_cleanup_free_search_symbols
parameter_list|(
name|struct
name|symbol_search
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The name of the ``main'' function.    FIXME: cagney/2001-03-20: Can't make main_name() const since some    of the calling code currently assumes that the string isn't    const. */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_main_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
comment|/*const */
name|char
modifier|*
name|main_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(SYMTAB_H) */
end_comment

end_unit

