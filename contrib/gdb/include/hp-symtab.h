begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions and structures for reading debug symbols from the    native HP C compiler.     Written by the Center for Software Science at the University of Utah    and by Cygnus Support.     Copyright 1994, 1995, 1998, 1999, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HP_SYMTAB_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|HP_SYMTAB_INCLUDED
end_define

begin_comment
comment|/* General information:     This header file defines and describes only the data structures    necessary to read debug symbols produced by the HP C compiler,    HP ANSI C++ compiler, and HP FORTRAN 90 compiler using the    SOM object file format.      (For a full description of the debug format, ftp hpux-symtab.h from    jaguar.cs.utah.edu:/dist).        Additional notes (Rich Title)    This file is a reverse-engineered version of a file called    "symtab.h" which exists internal to HP's Computer Languages Organization    in /CLO/Components/DDE/obj/som/symtab.h. Because HP's version of    the file is copyrighted and not distributed, it is necessary for    GDB to use the reverse-engineered version that follows.    Work was done by Cygnus to reverse-engineer the C subset of symtab.h.    The WDB project has extended this to also contain the C++     symbol definitions, the F90 symbol definitions,     and the DOC (debugging-optimized-code) symbol definitions.    In some cases (the C++ symbol definitions)    I have added internal documentation here that    goes beyond what is supplied in HP's symtab.h. If we someday    unify these files again, the extra comments should be merged back    into HP's symtab.h.       -------------------------------------------------------------------     Debug symbols are contained entirely within an unloadable space called    $DEBUG$.  $DEBUG$ contains several subspaces which group related    debug symbols.     $GNTT$ contains information for global variables, types and contants.     $LNTT$ contains information for procedures (including nesting), scoping    information, local variables, types, and constants.     $SLT$ contains source line information so that code addresses may be    mapped to source lines.     $VT$ contains various strings and constants for named objects (variables,    typedefs, functions, etc).  Strings are stored as null-terminated character    lists.  Constants always begin on word boundaries.  The first byte of    the VT must be zero (a null string).     $XT$ is not currently used by GDB.     Many structures within the subspaces point to other structures within    the same subspace, or to structures within a different subspace.  These    pointers are represented as a structure index from the beginning of    the appropriate subspace.  */
end_comment

begin_comment
comment|/* Used to describe where a constant is stored.  */
end_comment

begin_enum
enum|enum
name|location_type
block|{
name|LOCATION_IMMEDIATE
block|,
name|LOCATION_PTR
block|,
name|LOCATION_VT
block|, }
enum|;
end_enum

begin_comment
comment|/* Languages supported by this debug format.  Within the data structures    this type is limited to 4 bits for a maximum of 16 languages.  */
end_comment

begin_enum
enum|enum
name|hp_language
block|{
name|HP_LANGUAGE_UNKNOWN
block|,
name|HP_LANGUAGE_C
block|,
name|HP_LANGUAGE_FORTRAN
block|,
name|HP_LANGUAGE_F77
init|=
name|HP_LANGUAGE_FORTRAN
block|,
name|HP_LANGUAGE_PASCAL
block|,
name|HP_LANGUAGE_MODCAL
block|,
name|HP_LANGUAGE_COBOL
block|,
name|HP_LANGUAGE_BASIC
block|,
name|HP_LANGUAGE_ADA
block|,
name|HP_LANGUAGE_CPLUSPLUS
block|,
name|HP_LANGUAGE_DMPASCAL
block|}
enum|;
end_enum

begin_comment
comment|/* Basic data types available in this debug format.  Within the data    structures this type is limited to 5 bits for a maximum of 32 basic    data types.  */
end_comment

begin_enum
enum|enum
name|hp_type
block|{
name|HP_TYPE_UNDEFINED
block|,
comment|/* 0 */
name|HP_TYPE_BOOLEAN
block|,
comment|/* 1 */
name|HP_TYPE_CHAR
block|,
comment|/* 2 */
name|HP_TYPE_INT
block|,
comment|/* 3 */
name|HP_TYPE_UNSIGNED_INT
block|,
comment|/* 4 */
name|HP_TYPE_REAL
block|,
comment|/* 5 */
name|HP_TYPE_COMPLEX
block|,
comment|/* 6 */
name|HP_TYPE_STRING200
block|,
comment|/* 7 */
name|HP_TYPE_LONGSTRING200
block|,
comment|/* 8 */
name|HP_TYPE_TEXT
block|,
comment|/* 9 */
name|HP_TYPE_FLABEL
block|,
comment|/* 10 */
name|HP_TYPE_FTN_STRING_SPEC
block|,
comment|/* 11 */
name|HP_TYPE_MOD_STRING_SPEC
block|,
comment|/* 12 */
name|HP_TYPE_PACKED_DECIMAL
block|,
comment|/* 13 */
name|HP_TYPE_REAL_3000
block|,
comment|/* 14 */
name|HP_TYPE_MOD_STRING_3000
block|,
comment|/* 15 */
name|HP_TYPE_ANYPOINTER
block|,
comment|/* 16 */
name|HP_TYPE_GLOBAL_ANYPOINTER
block|,
comment|/* 17 */
name|HP_TYPE_LOCAL_ANYPOINTER
block|,
comment|/* 18 */
name|HP_TYPE_COMPLEXS3000
block|,
comment|/* 19 */
name|HP_TYPE_FTN_STRING_S300_COMPAT
block|,
comment|/* 20 */
name|HP_TYPE_FTN_STRING_VAX_COMPAT
block|,
comment|/* 21 */
name|HP_TYPE_BOOLEAN_S300_COMPAT
block|,
comment|/* 22 */
name|HP_TYPE_BOOLEAN_VAX_COMPAT
block|,
comment|/* 23 */
name|HP_TYPE_WIDE_CHAR
block|,
comment|/* 24 */
name|HP_TYPE_LONG
block|,
comment|/* 25 */
name|HP_TYPE_UNSIGNED_LONG
block|,
comment|/* 26 */
name|HP_TYPE_DOUBLE
block|,
comment|/* 27 */
name|HP_TYPE_TEMPLATE_ARG
block|,
comment|/* 28 */
name|HP_TYPE_VOID
comment|/* 29 */
block|}
enum|;
end_enum

begin_comment
comment|/* An immediate name and type table entry.     extension and immediate will always be one.    global will always be zero.    hp_type is the basic type this entry describes.    bitlength is the length in bits for the basic type.  */
end_comment

begin_struct
struct|struct
name|dnttp_immediate
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|immediate
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|type
range|:
literal|5
decl_stmt|;
name|unsigned
name|int
name|bitlength
range|:
literal|24
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A nonimmediate name and type table entry.     extension will always be one.    immediate will always be zero.    if global is zero, this entry points into the LNTT    if global is one, this entry points into the GNTT    index is the index within the GNTT or LNTT for this entry.  */
end_comment

begin_struct
struct|struct
name|dnttp_nonimmediate
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|immediate
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|index
range|:
literal|29
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A pointer to an entry in the GNTT and LNTT tables.  It has two    forms depending on the type being described.     The immediate form is used for simple entries and is one    word.     The nonimmediate form is used for complex entries and contains    an index into the LNTT or GNTT which describes the entire type.     If a dnttpointer is -1, then it is a NIL entry.  */
end_comment

begin_define
define|#
directive|define
name|DNTTNIL
value|(-1)
end_define

begin_typedef
typedef|typedef
union|union
name|dnttpointer
block|{
name|struct
name|dnttp_immediate
name|dntti
decl_stmt|;
name|struct
name|dnttp_nonimmediate
name|dnttp
decl_stmt|;
name|int
name|word
decl_stmt|;
block|}
name|dnttpointer
typedef|;
end_typedef

begin_comment
comment|/* An index into the source line table.  As with dnttpointers, a sltpointer    of -1 indicates a NIL entry.  */
end_comment

begin_define
define|#
directive|define
name|SLTNIL
value|(-1)
end_define

begin_typedef
typedef|typedef
name|int
name|sltpointer
typedef|;
end_typedef

begin_comment
comment|/* Index into DOC (= "Debugging Optimized Code") line table.  */
end_comment

begin_define
define|#
directive|define
name|LTNIL
value|(-1)
end_define

begin_typedef
typedef|typedef
name|int
name|ltpointer
typedef|;
end_typedef

begin_comment
comment|/* Index into context table.  */
end_comment

begin_define
define|#
directive|define
name|CTXTNIL
value|(-1)
end_define

begin_typedef
typedef|typedef
name|int
name|ctxtpointer
typedef|;
end_typedef

begin_comment
comment|/* Unsigned byte offset into the VT.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|vtpointer
typedef|;
end_typedef

begin_comment
comment|/* A DNTT entry (used within the GNTT and LNTT).     DNTT entries are variable sized objects, but are always a multiple    of 3 words (we call each group of 3 words a "block").     The first bit in each block is an extension bit.  This bit is zero    for the first block of a DNTT entry.  If the entry requires more    than one block, then this bit is set to one in all blocks after    the first one.  */
end_comment

begin_comment
comment|/* Each DNTT entry describes a particular debug symbol (beginning of    a source file, a function, variables, structures, etc.     The type of the DNTT entry is stored in the "kind" field within the    DNTT entry itself.  */
end_comment

begin_enum
enum|enum
name|dntt_entry_type
block|{
name|DNTT_TYPE_NIL
init|=
operator|-
literal|1
block|,
name|DNTT_TYPE_SRCFILE
block|,
name|DNTT_TYPE_MODULE
block|,
name|DNTT_TYPE_FUNCTION
block|,
name|DNTT_TYPE_ENTRY
block|,
name|DNTT_TYPE_BEGIN
block|,
name|DNTT_TYPE_END
block|,
name|DNTT_TYPE_IMPORT
block|,
name|DNTT_TYPE_LABEL
block|,
name|DNTT_TYPE_FPARAM
block|,
name|DNTT_TYPE_SVAR
block|,
name|DNTT_TYPE_DVAR
block|,
name|DNTT_TYPE_HOLE1
block|,
name|DNTT_TYPE_CONST
block|,
name|DNTT_TYPE_TYPEDEF
block|,
name|DNTT_TYPE_TAGDEF
block|,
name|DNTT_TYPE_POINTER
block|,
name|DNTT_TYPE_ENUM
block|,
name|DNTT_TYPE_MEMENUM
block|,
name|DNTT_TYPE_SET
block|,
name|DNTT_TYPE_SUBRANGE
block|,
name|DNTT_TYPE_ARRAY
block|,
name|DNTT_TYPE_STRUCT
block|,
name|DNTT_TYPE_UNION
block|,
name|DNTT_TYPE_FIELD
block|,
name|DNTT_TYPE_VARIANT
block|,
name|DNTT_TYPE_FILE
block|,
name|DNTT_TYPE_FUNCTYPE
block|,
name|DNTT_TYPE_WITH
block|,
name|DNTT_TYPE_COMMON
block|,
name|DNTT_TYPE_COBSTRUCT
block|,
name|DNTT_TYPE_XREF
block|,
name|DNTT_TYPE_SA
block|,
name|DNTT_TYPE_MACRO
block|,
name|DNTT_TYPE_BLOCKDATA
block|,
name|DNTT_TYPE_CLASS_SCOPE
block|,
name|DNTT_TYPE_REFERENCE
block|,
name|DNTT_TYPE_PTRMEM
block|,
name|DNTT_TYPE_PTRMEMFUNC
block|,
name|DNTT_TYPE_CLASS
block|,
name|DNTT_TYPE_GENFIELD
block|,
name|DNTT_TYPE_VFUNC
block|,
name|DNTT_TYPE_MEMACCESS
block|,
name|DNTT_TYPE_INHERITANCE
block|,
name|DNTT_TYPE_FRIEND_CLASS
block|,
name|DNTT_TYPE_FRIEND_FUNC
block|,
name|DNTT_TYPE_MODIFIER
block|,
name|DNTT_TYPE_OBJECT_ID
block|,
name|DNTT_TYPE_MEMFUNC
block|,
name|DNTT_TYPE_TEMPLATE
block|,
name|DNTT_TYPE_TEMPLATE_ARG
block|,
name|DNTT_TYPE_FUNC_TEMPLATE
block|,
name|DNTT_TYPE_LINK
block|,
name|DNTT_TYPE_DYN_ARRAY_DESC
block|,
name|DNTT_TYPE_DESC_SUBRANGE
block|,
name|DNTT_TYPE_BEGIN_EXT
block|,
name|DNTT_TYPE_INLN
block|,
name|DNTT_TYPE_INLN_LIST
block|,
name|DNTT_TYPE_ALIAS
block|,
name|DNTT_TYPE_DOC_FUNCTION
block|,
name|DNTT_TYPE_DOC_MEMFUNC
block|,
name|DNTT_TYPE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* DNTT_TYPE_SRCFILE:     One DNTT_TYPE_SRCFILE symbol is output for the start of each source    file and at the begin and end of an included file.  A DNTT_TYPE_SRCFILE    entry is also output before each DNTT_TYPE_FUNC symbol so that debuggers    can determine what file a function was defined in.     LANGUAGE describes the source file's language.     NAME points to an VT entry providing the source file's name.     Note the name used for DNTT_TYPE_SRCFILE entries are exactly as seen    by the compiler (ie they may be relative or absolute).  C include files    via<> inclusion must use absolute paths.     ADDRESS points to an SLT entry from which line number and code locations    may be determined.  */
end_comment

begin_struct
struct|struct
name|dntt_type_srcfile
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* DNTT_TYPE_SRCFILE */
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_MODULE:     A DNTT_TYPE_MODULE symbol is emitted for the start of a pascal    module or C source file. A module indicates a compilation unit    for name-scoping purposes; in that regard there should be     a 1-1 correspondence between GDB "symtab"'s and MODULE symbol records.     Each DNTT_TYPE_MODULE must have an associated DNTT_TYPE_END symbol.     NAME points to a VT entry providing the module's name.  Note C    source files are considered nameless modules.     ALIAS point to a VT entry providing a secondary name.     ADDRESS points to an SLT entry from which line number and code locations    may be determined.  */
end_comment

begin_struct
struct|struct
name|dntt_type_module
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* DNTT_TYPE_MODULE */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|vtpointer
name|alias
decl_stmt|;
name|dnttpointer
name|unused2
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_FUNCTION,    DNTT_TYPE_ENTRY,    DNTT_TYPE_BLOCKDATA,    DNTT_TYPE_MEMFUNC:     A DNTT_TYPE_FUNCTION symbol is emitted for each function definition;    a DNTT_TYPE_ENTRY symbols is used for secondary entry points.  Both    symbols used the dntt_type_function structure.    A DNTT_TYPE_BLOCKDATA symbol is emitted ...?    A DNTT_TYPE_MEMFUNC symbol is emitted for inlined member functions (C++).      Each of DNTT_TYPE_FUNCTION must have a matching DNTT_TYPE_END.     GLOBAL is nonzero if the function has global scope.     LANGUAGE describes the function's source language.     OPT_LEVEL describes the optimization level the function was compiled    with.     VARARGS is nonzero if the function uses varargs.     NAME points to a VT entry providing the function's name.     ALIAS points to a VT entry providing a secondary name for the function.     FIRSTPARAM points to a LNTT entry which describes the parameter list.     ADDRESS points to an SLT entry from which line number and code locations    may be determined.     ENTRYADDR is the memory address corresponding the function's entry point     RETVAL points to a LNTT entry describing the function's return value.     LOWADDR is the lowest memory address associated with this function.     HIADDR is the highest memory address associated with this function.  */
end_comment

begin_struct
struct|struct
name|dntt_type_function
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* DNTT_TYPE_FUNCTION, 				           DNTT_TYPE_ENTRY, 					   DNTT_TYPE_BLOCKDATA 					   or DNTT_TYPE_MEMFUNC */
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|nest_level
range|:
literal|5
decl_stmt|;
name|unsigned
name|int
name|opt_level
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|varargs
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|lang_info
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|localalloc
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|expansion
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|1
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|vtpointer
name|alias
decl_stmt|;
name|dnttpointer
name|firstparam
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
name|CORE_ADDR
name|entryaddr
decl_stmt|;
name|dnttpointer
name|retval
decl_stmt|;
name|CORE_ADDR
name|lowaddr
decl_stmt|;
name|CORE_ADDR
name|hiaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_BEGIN:     A DNTT_TYPE_BEGIN symbol is emitted to begin a new nested scope.    Every DNTT_TYPE_BEGIN symbol must have a matching DNTT_TYPE_END symbol.     CLASSFLAG is nonzero if this is the beginning of a c++ class definition.     ADDRESS points to an SLT entry from which line number and code locations    may be determined.  */
end_comment

begin_struct
struct|struct
name|dntt_type_begin
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|classflag
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|20
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_END:     A DNTT_TYPE_END symbol is emitted when closing a scope started by    a DNTT_TYPE_MODULE, DNTT_TYPE_FUNCTION, DNTT_TYPE_WITH,    DNTT_TYPE_COMMON, DNTT_TYPE_BEGIN, and DNTT_TYPE_CLASS_SCOPE symbols.     ENDKIND describes what type of scope the DNTT_TYPE_END is closing    (one of the above 6 kinds).     CLASSFLAG is nonzero if this is the end of a c++ class definition.     ADDRESS points to an SLT entry from which line number and code locations    may be determined.     BEGINSCOPE points to the LNTT entry which opened the scope.  */
end_comment

begin_struct
struct|struct
name|dntt_type_end
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|endkind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|classflag
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|10
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
name|dnttpointer
name|beginscope
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_IMPORT is unused by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_LABEL is unused by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_FPARAM:     A DNTT_TYPE_FPARAM symbol is emitted for a function argument.  When    chained together the symbols represent an argument list for a function.     REGPARAM is nonzero if this parameter was passed in a register.     INDIRECT is nonzero if this parameter is a pointer to the parameter    (pass by reference or pass by value for large items).     LONGADDR is nonzero if the parameter is a 64bit pointer.     NAME is a pointer into the VT for the parameter's name.     LOCATION describes where the parameter is stored.  Depending on the    parameter type LOCATION could be a register number, or an offset    from the stack pointer.     TYPE points to a NTT entry describing the type of this parameter.     NEXTPARAM points to the LNTT entry describing the next parameter.  */
end_comment

begin_struct
struct|struct
name|dntt_type_fparam
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|regparam
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|longaddr
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|copyparam
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|dflt
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|doc_ranges
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|misc_kind
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|14
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|CORE_ADDR
name|location
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
name|dnttpointer
name|nextparam
decl_stmt|;
name|int
name|misc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_SVAR:     A DNTT_TYPE_SVAR is emitted to describe a variable in static storage.     GLOBAL is nonzero if the variable has global scope.     INDIRECT is nonzero if the variable is a pointer to an object.     LONGADDR is nonzero if the variable is in long pointer space.     STATICMEM is nonzero if the variable is a member of a class.     A_UNION is nonzero if the variable is an anonymous union member.     NAME is a pointer into the VT for the variable's name.     LOCATION provides the memory address for the variable.     TYPE is a pointer into either the GNTT or LNTT which describes    the type of this variable.  */
end_comment

begin_struct
struct|struct
name|dntt_type_svar
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|longaddr
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|staticmem
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|a_union
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused1
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|thread_specific
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused2
range|:
literal|14
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|CORE_ADDR
name|location
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|displacement
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_DVAR:     A DNTT_TYPE_DVAR is emitted to describe automatic variables and variables    held in registers.     GLOBAL is nonzero if the variable has global scope.     INDIRECT is nonzero if the variable is a pointer to an object.     REGVAR is nonzero if the variable is in a register.     A_UNION is nonzero if the variable is an anonymous union member.     NAME is a pointer into the VT for the variable's name.     LOCATION provides the memory address or register number for the variable.     TYPE is a pointer into either the GNTT or LNTT which describes    the type of this variable.  */
end_comment

begin_struct
struct|struct
name|dntt_type_dvar
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|regvar
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|a_union
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|int
name|location
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_CONST:     A DNTT_TYPE_CONST symbol is emitted for program constants.     GLOBAL is nonzero if the constant has global scope.     INDIRECT is nonzero if the constant is a pointer to an object.     LOCATION_TYPE describes where to find the constant's value    (in the VT, memory, or embedded in an instruction).     CLASSMEM is nonzero if the constant is a member of a class.     NAME is a pointer into the VT for the constant's name.     LOCATION provides the memory address, register number or pointer    into the VT for the constant's value.     TYPE is a pointer into either the GNTT or LNTT which describes    the type of this variable.  */
end_comment

begin_struct
struct|struct
name|dntt_type_const
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|location_type
range|:
literal|3
decl_stmt|;
name|unsigned
name|int
name|classmem
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|15
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|CORE_ADDR
name|location
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|displacement
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_TYPEDEF and DNTT_TYPE_TAGDEF:     The same structure is used to describe typedefs and tagdefs.     DNTT_TYPE_TYPEDEFS are associated with C "typedefs".     DNTT_TYPE_TAGDEFs are associated with C "struct", "union", and "enum"    tags, which may have the same name as a typedef in the same scope.    Also they are associated with C++ "class" tags, which implicitly have     the same name as the class type.     GLOBAL is nonzero if the typedef/tagdef has global scope.     TYPEINFO is used to determine if full type information is available    for a tag.  (usually 1, but can be zero for opaque types in C).     NAME is a pointer into the VT for the constant's name.     TYPE points to the underlying type for the typedef/tagdef in the    GNTT or LNTT.  */
end_comment

begin_struct
struct|struct
name|dntt_type_type
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* DNTT_TYPE_TYPEDEF or                                            DNTT_TYPE_TAGDEF.  */
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|typeinfo
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|19
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
comment|/* Underlying type, which for TAGDEF's may be                                           DNTT_TYPE_STRUCT, DNTT_TYPE_UNION,                                           DNTT_TYPE_ENUM, or DNTT_TYPE_CLASS.                                            For TYPEDEF's other underlying types                                           are also possible.  */
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_POINTER:     Used to describe a pointer to an underlying type.     POINTSTO is a pointer into the GNTT or LNTT for the type which this    pointer points to.     BITLENGTH is the length of the pointer (not the underlying type). */
end_comment

begin_struct
struct|struct
name|dntt_type_pointer
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|pointsto
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_ENUM:     Used to describe enumerated types.     FIRSTMEM is a pointer to a DNTT_TYPE_MEMENUM in the GNTT/LNTT which    describes the first member (and contains a pointer to the chain of    members).     BITLENGTH is the number of bits used to hold the values of the enum's    members.  */
end_comment

begin_struct
struct|struct
name|dntt_type_enum
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|firstmem
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_MEMENUM     Used to describe members of an enumerated type.     CLASSMEM is nonzero if this member is part of a class.     NAME points into the VT for the name of this member.     VALUE is the value of this enumeration member.     NEXTMEM points to the next DNTT_TYPE_MEMENUM in the chain.  */
end_comment

begin_struct
struct|struct
name|dntt_type_memenum
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|classmem
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|20
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|unsigned
name|int
name|value
decl_stmt|;
name|dnttpointer
name|nextmem
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_SET     Used to describe PASCAL "set" type.     DECLARATION describes the bitpacking of the set.     SUBTYPE points to a DNTT entry describing the type of the members.     BITLENGTH is the size of the set.  */
end_comment

begin_struct
struct|struct
name|dntt_type_set
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|declaration
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|19
decl_stmt|;
name|dnttpointer
name|subtype
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_SUBRANGE     Used to describe subrange type.     DYN_LOW describes the lower bound of the subrange:       00 for a constant lower bound (found in LOWBOUND).       01 for a dynamic lower bound with the lower bound found in the      memory address pointed to by LOWBOUND.       10 for a dynamic lower bound described by an variable found in the      DNTT/LNTT (LOWBOUND would be a pointer into the DNTT/LNTT).     DYN_HIGH is similar to DYN_LOW, except it describes the upper bound.     SUBTYPE points to the type of the subrange.     BITLENGTH is the length in bits needed to describe the subrange's    values.  */
end_comment

begin_struct
struct|struct
name|dntt_type_subrange
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|dyn_low
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|dyn_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|int
name|lowbound
decl_stmt|;
name|int
name|highbound
decl_stmt|;
name|dnttpointer
name|subtype
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_ARRAY     Used to describe an array type.     DECLARATION describes the bit packing used in the array.     ARRAYISBYTES is nonzero if the field in arraylength describes the    length in bytes rather than in bits.  A value of zero is used to    describe an array with size 2**32.     ELEMISBYTES is nonzero if the length if each element in the array    is describes in bytes rather than bits.  A value of zero is used    to an element with size 2**32.     ELEMORDER is nonzero if the elements are indexed in increasing order.     JUSTIFIED if the elements are left justified to index zero.     ARRAYLENGTH is the length of the array.     INDEXTYPE is a DNTT pointer to the type used to index the array.     ELEMTYPE is a DNTT pointer to the type for the array elements.     ELEMLENGTH is the length of each element in the array (including    any padding).     Multi-dimensional arrays are represented by ELEMTYPE pointing to    another DNTT_TYPE_ARRAY.  */
end_comment

begin_struct
struct|struct
name|dntt_type_array
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|declaration
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|dyn_low
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|dyn_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|arrayisbytes
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|elemisbytes
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|elemorder
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|justified
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|11
decl_stmt|;
name|unsigned
name|int
name|arraylength
decl_stmt|;
name|dnttpointer
name|indextype
decl_stmt|;
name|dnttpointer
name|elemtype
decl_stmt|;
name|unsigned
name|int
name|elemlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_STRUCT     DNTT_TYPE_STRUCT is used to describe a C structure.     DECLARATION describes the bitpacking used.     FIRSTFIELD is a DNTT pointer to the first field of the structure    (each field contains a pointer to the next field, walk the list    to access all fields of the structure).     VARTAGFIELD and VARLIST are used for Pascal variant records.     BITLENGTH is the size of the structure in bits.  */
end_comment

begin_struct
struct|struct
name|dntt_type_struct
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|declaration
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|19
decl_stmt|;
name|dnttpointer
name|firstfield
decl_stmt|;
name|dnttpointer
name|vartagfield
decl_stmt|;
name|dnttpointer
name|varlist
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_UNION     DNTT_TYPE_UNION is used to describe a C union.     FIRSTFIELD is a DNTT pointer to the beginning of the field chain.     BITLENGTH is the size of the union in bits.  */
end_comment

begin_struct
struct|struct
name|dntt_type_union
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|firstfield
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_FIELD     DNTT_TYPE_FIELD describes one field in a structure or union    or C++ class.     VISIBILITY is used to describe the visibility of the field    (for c++.  public = 0, protected = 1, private = 2).     A_UNION is nonzero if this field is a member of an anonymous union.     STATICMEM is nonzero if this field is a static member of a template.     NAME is a pointer into the VT for the name of the field.     BITOFFSET gives the offset of this field in bits from the beginning    of the structure or union this field is a member of.     TYPE is a DNTT pointer to the type describing this field.     BITLENGTH is the size of the entry in bits.     NEXTFIELD is a DNTT pointer to the next field in the chain.  */
end_comment

begin_struct
struct|struct
name|dntt_type_field
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|visibility
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|a_union
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|staticmem
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
name|unsigned
name|int
name|bitoffset
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
name|dnttpointer
name|nextfield
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_VARIANT is unused by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_FILE is unused by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_FUNCTYPE     I think this is used to describe a function type (e.g., would    be emitted as part of a function-pointer description).     VARARGS is nonzero if this function uses varargs.     FIRSTPARAM is a DNTT pointer to the first entry in the parameter    chain.     RETVAL is a DNTT pointer to the type of the return value.  */
end_comment

begin_struct
struct|struct
name|dntt_type_functype
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|varargs
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|info
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|16
decl_stmt|;
name|unsigned
name|int
name|bitlength
decl_stmt|;
name|dnttpointer
name|firstparam
decl_stmt|;
name|dnttpointer
name|retval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_WITH is emitted by C++ to indicate "with" scoping semantics.    (Probably also emitted by PASCAL to support "with"...).        C++ example: Say "memfunc" is a method of class "c", and say    "m" is a data member of class "c". Then from within "memfunc",    it is legal to reference "m" directly (e.g. you don't have to    say "this->m". The symbol table indicates    this by emitting a DNTT_TYPE_WITH symbol within the function "memfunc",    pointing to the type symbol for class "c".      In GDB, this symbol record is unnecessary,     because GDB's symbol lookup algorithm    infers the "with" semantics when it sees a "this" argument to the member    function. So GDB can safely ignore the DNTT_TYPE_WITH record.     A DNTT_TYPE_WITH has a matching DNTT_TYPE_END symbol.  */
end_comment

begin_struct
struct|struct
name|dntt_type_with
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_WITH */
name|unsigned
name|int
name|addrtype
range|:
literal|2
decl_stmt|;
comment|/* 0 => STATTYPE                */
comment|/* 1 => DYNTYPE                 */
comment|/* 2 => REGTYPE                 */
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
comment|/* 1 => pointer to object       */
name|unsigned
name|int
name|longaddr
range|:
literal|1
decl_stmt|;
comment|/* 1 => in long pointer space   */
name|unsigned
name|int
name|nestlevel
range|:
literal|6
decl_stmt|;
comment|/* # of nesting levels back     */
name|unsigned
name|int
name|doc_ranges
range|:
literal|1
decl_stmt|;
comment|/* 1 => location is range list  */
name|unsigned
name|int
name|unused
range|:
literal|10
decl_stmt|;
name|long
name|location
decl_stmt|;
comment|/* where stored (allocated)     */
name|sltpointer
name|address
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
comment|/* type of with expression      */
name|vtpointer
name|name
decl_stmt|;
comment|/* name of with expression      */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* byte offset from location    */
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_COMMON is unsupported by GDB.  */
end_comment

begin_comment
comment|/* A DNTT_TYPE_COMMON symbol must have a matching DNTT_TYPE_END symbol */
end_comment

begin_comment
comment|/* DNTT_TYPE_COBSTRUCT is unsupported by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_XREF is unsupported by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_SA is unsupported by GDB.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_MACRO is unsupported by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_BLOCKDATA has the same structure as DNTT_TYPE_FUNCTION */
end_comment

begin_comment
comment|/* The following are the C++ specific SOM records */
end_comment

begin_comment
comment|/*  The purpose of the DNTT_TYPE_CLASS_SCOPE is to bracket C++ methods     and indicate the method name belongs in the "class scope" rather     than in the module they are being defined in. For example:      class c {     ...     void memfunc(); // member function     };      void c::memfunc()   // definition of class c's "memfunc"     {     ...     }      main()     {     ...     }      In the above, the name "memfunc" is not directly visible from "main".     I.e., you have to say "break c::memfunc".     If it were a normal function (not a method), it would be visible     via the simple "break memfunc". Since "memfunc" otherwise looks     like a normal FUNCTION in the symbol table, the bracketing     CLASS_SCOPE is what is used to indicate it is really a method.          A DNTT_TYPE_CLASS_SCOPE symbol must have a matching DNTT_TYPE_END symbol.  */
end_comment

begin_struct
struct|struct
name|dntt_type_class_scope
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* Always zero.  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* Always DNTT_TYPE_CLASS_SCOPE.  */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
comment|/* Pointer to SLT entry.  */
name|dnttpointer
name|type
decl_stmt|;
comment|/* Pointer to class type DNTT.  */
block|}
struct|;
end_struct

begin_comment
comment|/* C++ reference parameter.    The structure of this record is the same as DNTT_TYPE_POINTER -     refer to struct dntt_type_pointer.  */
end_comment

begin_comment
comment|/* The next two describe C++ pointer-to-data-member type, and     pointer-to-member-function type, respectively.    DNTT_TYPE_PTRMEM and DNTT_TYPE_PTRMEMFUNC have the same structure.  */
end_comment

begin_struct
struct|struct
name|dntt_type_ptrmem
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* Always zero.  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* Always DNTT_TYPE_PTRMEM.  */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|pointsto
decl_stmt|;
comment|/* Pointer to class DNTT.  */
name|dnttpointer
name|memtype
decl_stmt|;
comment|/* Type of member.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dntt_type_ptrmemfunc
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* Always zero.  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* Always DNTT_TYPE_PTRMEMFUNC.  */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|pointsto
decl_stmt|;
comment|/* Pointer to class DNTT.  */
name|dnttpointer
name|memtype
decl_stmt|;
comment|/* Type of member.  */
block|}
struct|;
end_struct

begin_comment
comment|/* The DNTT_TYPE_CLASS symbol is emitted to describe a class type.    "memberlist" points to a chained list of FIELD or GENFIELD records    indicating the class members. "parentlist" points to a chained list    of INHERITANCE records indicating classes from which we inherit    fields.  */
end_comment

begin_struct
struct|struct
name|dntt_type_class
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* Always zero.  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* Always DNTT_TYPE_CLASS.  */
name|unsigned
name|int
name|abstract
range|:
literal|1
decl_stmt|;
comment|/* Is this an abstract class?  */
name|unsigned
name|int
name|class_decl
range|:
literal|2
decl_stmt|;
comment|/* 0=class,1=union,2=struct.  */
name|unsigned
name|int
name|expansion
range|:
literal|1
decl_stmt|;
comment|/* 1=template expansion.  */
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|dnttpointer
name|memberlist
decl_stmt|;
comment|/* Ptr to chain of [GEN]FIELDs.  */
name|unsigned
name|long
name|vtbl_loc
decl_stmt|;
comment|/* Offset in obj of ptr to vtbl.  */
name|dnttpointer
name|parentlist
decl_stmt|;
comment|/* Ptr to K_INHERITANCE list.  */
name|unsigned
name|long
name|bitlength
decl_stmt|;
comment|/* Total at this level.  */
name|dnttpointer
name|identlist
decl_stmt|;
comment|/* Ptr to chain of class ident's.  */
name|dnttpointer
name|friendlist
decl_stmt|;
comment|/* Ptr to K_FRIEND list.  */
name|dnttpointer
name|templateptr
decl_stmt|;
comment|/* Ptr to template.  */
name|dnttpointer
name|nextexp
decl_stmt|;
comment|/* Ptr to next expansion.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Class members are indicated via either the FIELD record (for    data members, same as for C struct fields), or by the GENFIELD record    (for member functions).  */
end_comment

begin_struct
struct|struct
name|dntt_type_genfield
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* Always zero.  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* Always DNTT_TYPE_GENFIELD.  */
name|unsigned
name|int
name|visibility
range|:
literal|2
decl_stmt|;
comment|/* Pub = 0, prot = 1, priv = 2.  */
name|unsigned
name|int
name|a_union
range|:
literal|1
decl_stmt|;
comment|/* 1 => anonymous union member.  */
name|unsigned
name|int
name|unused
range|:
literal|18
decl_stmt|;
name|dnttpointer
name|field
decl_stmt|;
comment|/* Pointer to field or qualifier.  */
name|dnttpointer
name|nextfield
decl_stmt|;
comment|/* Pointer to next field.  */
block|}
struct|;
end_struct

begin_comment
comment|/* C++ virtual functions.  */
end_comment

begin_struct
struct|struct
name|dntt_type_vfunc
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_VFUNC */
name|unsigned
name|int
name|pure
range|:
literal|1
decl_stmt|;
comment|/* pure virtual function ?       */
name|unsigned
name|int
name|unused
range|:
literal|20
decl_stmt|;
name|dnttpointer
name|funcptr
decl_stmt|;
comment|/* points to FUNCTION symbol     */
name|unsigned
name|long
name|vtbl_offset
decl_stmt|;
comment|/* offset into vtbl for virtual  */
block|}
struct|;
end_struct

begin_comment
comment|/* Not precisely sure what this is intended for - DDE ignores it.  */
end_comment

begin_struct
struct|struct
name|dntt_type_memaccess
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_MEMACCESS */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|classptr
decl_stmt|;
comment|/* pointer to base class         */
name|dnttpointer
name|field
decl_stmt|;
comment|/* pointer field                 */
block|}
struct|;
end_struct

begin_comment
comment|/* The DNTT_TYPE_INHERITANCE record describes derived classes.    In particular, the "parentlist" field of the CLASS record points    to a list of INHERITANCE records for classes from which we     inherit members.  */
end_comment

begin_struct
struct|struct
name|dntt_type_inheritance
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_INHERITANCE */
name|unsigned
name|int
name|Virtual
range|:
literal|1
decl_stmt|;
comment|/* virtual base class ?          */
name|unsigned
name|int
name|visibility
range|:
literal|2
decl_stmt|;
comment|/* pub = 0, prot = 1, priv = 2   */
name|unsigned
name|int
name|unused
range|:
literal|18
decl_stmt|;
name|dnttpointer
name|classname
decl_stmt|;
comment|/* first parent class, if any    */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* offset to start of base class */
name|dnttpointer
name|next
decl_stmt|;
comment|/* pointer to next K_INHERITANCE */
name|unsigned
name|long
name|future
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding to 3-word block end   */
block|}
struct|;
end_struct

begin_comment
comment|/* C++ "friend" classes ... */
end_comment

begin_struct
struct|struct
name|dntt_type_friend_class
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_FRIEND_CLASS */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|classptr
decl_stmt|;
comment|/* pointer to class DNTT         */
name|dnttpointer
name|next
decl_stmt|;
comment|/* next DNTT_FRIEND              */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dntt_type_friend_func
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_FRIEND_FUNC */
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|dnttpointer
name|funcptr
decl_stmt|;
comment|/* pointer to function           */
name|dnttpointer
name|classptr
decl_stmt|;
comment|/* pointer to class DNTT         */
name|dnttpointer
name|next
decl_stmt|;
comment|/* next DNTT_FRIEND              */
name|unsigned
name|long
name|future
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding to 3-word block end   */
block|}
struct|;
end_struct

begin_comment
comment|/* DDE appears to ignore the DNTT_TYPE_MODIFIER record.    It could perhaps be used to give better "ptype" output in GDB;    otherwise it is probably safe for GDB to ignore it also.  */
end_comment

begin_struct
struct|struct
name|dntt_type_modifier
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_MODIFIER */
name|unsigned
name|int
name|m_const
range|:
literal|1
decl_stmt|;
comment|/* const                         */
name|unsigned
name|int
name|m_static
range|:
literal|1
decl_stmt|;
comment|/* static                        */
name|unsigned
name|int
name|m_void
range|:
literal|1
decl_stmt|;
comment|/* void                          */
name|unsigned
name|int
name|m_volatile
range|:
literal|1
decl_stmt|;
comment|/* volatile                      */
name|unsigned
name|int
name|m_duplicate
range|:
literal|1
decl_stmt|;
comment|/* duplicate                     */
name|unsigned
name|int
name|unused
range|:
literal|16
decl_stmt|;
name|dnttpointer
name|type
decl_stmt|;
comment|/* subtype                       */
name|unsigned
name|long
name|future
decl_stmt|;
comment|/* padding to 3-word block end   */
block|}
struct|;
end_struct

begin_comment
comment|/* I'm not sure what this was intended for - DDE ignores it.  */
end_comment

begin_struct
struct|struct
name|dntt_type_object_id
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_OBJECT_ID */
name|unsigned
name|int
name|indirect
range|:
literal|1
decl_stmt|;
comment|/* Is object_ident addr of addr? */
name|unsigned
name|int
name|unused
range|:
literal|20
decl_stmt|;
name|unsigned
name|long
name|object_ident
decl_stmt|;
comment|/* object identifier             */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* offset to start of base class */
name|dnttpointer
name|next
decl_stmt|;
comment|/* pointer to next K_OBJECT_ID   */
name|unsigned
name|long
name|segoffset
decl_stmt|;
comment|/* for linker fixup              */
name|unsigned
name|long
name|future
decl_stmt|;
comment|/* padding to 3-word block end   */
block|}
struct|;
end_struct

begin_comment
comment|/* No separate dntt_type_memfunc; same as dntt_type_func */
end_comment

begin_comment
comment|/* Symbol records to support templates. These only get used    in DDE's "describe" output (like GDB's "ptype").  */
end_comment

begin_comment
comment|/* The TEMPLATE record is the header for a template-class.    Like the CLASS record, a TEMPLATE record has a memberlist that    points to a list of template members. It also has an arglist    pointing to a list of TEMPLATE_ARG records.  */
end_comment

begin_struct
struct|struct
name|dntt_type_template
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_TEMPLATE */
name|unsigned
name|int
name|abstract
range|:
literal|1
decl_stmt|;
comment|/* is this an abstract class?    */
name|unsigned
name|int
name|class_decl
range|:
literal|2
decl_stmt|;
comment|/* 0=class,1=union,2=struct      */
name|unsigned
name|int
name|unused
range|:
literal|18
decl_stmt|;
name|dnttpointer
name|memberlist
decl_stmt|;
comment|/* ptr to chain of K_[GEN]FIELDs */
name|long
name|unused2
decl_stmt|;
comment|/* offset in obj of ptr to vtbl  */
name|dnttpointer
name|parentlist
decl_stmt|;
comment|/* ptr to K_INHERITANCE list     */
name|unsigned
name|long
name|bitlength
decl_stmt|;
comment|/* total at this level           */
name|dnttpointer
name|identlist
decl_stmt|;
comment|/* ptr to chain of class ident's */
name|dnttpointer
name|friendlist
decl_stmt|;
comment|/* ptr to K_FRIEND list          */
name|dnttpointer
name|arglist
decl_stmt|;
comment|/* ptr to argument list          */
name|dnttpointer
name|expansions
decl_stmt|;
comment|/* ptr to expansion list         */
block|}
struct|;
end_struct

begin_comment
comment|/* Template-class arguments are a list of TEMPL_ARG records    chained together. The "name" field is the name of the formal.    E.g.:          template<class T> class q { ... };        Then "T" is the name of the formal argument.  */
end_comment

begin_struct
struct|struct
name|dntt_type_templ_arg
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_TEMPL_ARG */
name|unsigned
name|int
name|usagetype
range|:
literal|1
decl_stmt|;
comment|/* 0 type-name 1 expression     */
name|unsigned
name|int
name|unused
range|:
literal|20
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
comment|/* name of argument             */
name|dnttpointer
name|type
decl_stmt|;
comment|/* for non type arguments       */
name|dnttpointer
name|nextarg
decl_stmt|;
comment|/* Next argument if any         */
name|long
name|future
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding to 3-word block end  */
block|}
struct|;
end_struct

begin_comment
comment|/* FUNC_TEMPLATE records are sort of like FUNCTION, but are emitted    for template member functions. E.g.,          template<class T> class q      {         ...         void f();         ...       };        Within the list of FIELDs/GENFIELDs defining the member list    of the template "q", "f" would appear as a FUNC_TEMPLATE.    We'll also see instances of FUNCTION "f" records for each     instantiation of the template.  */
end_comment

begin_struct
struct|struct
name|dntt_type_func_template
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_FUNC_TEMPLATE */
name|unsigned
name|int
name|public
range|:
literal|1
decl_stmt|;
comment|/* 1 => globally visible        */
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
comment|/* type of language             */
name|unsigned
name|int
name|level
range|:
literal|5
decl_stmt|;
comment|/* nesting level (top level = 0)*/
name|unsigned
name|int
name|optimize
range|:
literal|2
decl_stmt|;
comment|/* level of optimization        */
name|unsigned
name|int
name|varargs
range|:
literal|1
decl_stmt|;
comment|/* ellipses.  Pascal/800 later  */
name|unsigned
name|int
name|info
range|:
literal|4
decl_stmt|;
comment|/* lang-specific stuff; F_xxxx  */
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|localloc
range|:
literal|1
decl_stmt|;
comment|/* 0 at top, 1 at end of block  */
name|unsigned
name|int
name|unused
range|:
literal|2
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
comment|/* name of function             */
name|vtpointer
name|alias
decl_stmt|;
comment|/* alternate name, if any       */
name|dnttpointer
name|firstparam
decl_stmt|;
comment|/* first FPARAM, if any         */
name|dnttpointer
name|retval
decl_stmt|;
comment|/* return type, if any          */
name|dnttpointer
name|arglist
decl_stmt|;
comment|/* ptr to argument list         */
block|}
struct|;
end_struct

begin_comment
comment|/* LINK is apparently intended to link together function template    definitions with their instantiations. However, it is not clear    why this would be needed, except to provide the information on    a "ptype" command. And as far as I can tell, aCC does not     generate this record.  */
end_comment

begin_struct
struct|struct
name|dntt_type_link
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* always DNTT_TYPE_LINK */
name|unsigned
name|int
name|linkKind
range|:
literal|4
decl_stmt|;
comment|/* always LINK_UNKNOWN          */
name|unsigned
name|int
name|unused
range|:
literal|17
decl_stmt|;
name|long
name|future1
decl_stmt|;
comment|/* expansion                    */
name|dnttpointer
name|ptr1
decl_stmt|;
comment|/* link from template           */
name|dnttpointer
name|ptr2
decl_stmt|;
comment|/* to expansion                 */
name|long
name|future
index|[
literal|2
index|]
decl_stmt|;
comment|/* padding to 3-word block end  */
block|}
struct|;
end_struct

begin_comment
comment|/* end of C++ specific SOM's.  */
end_comment

begin_comment
comment|/* DNTT_TYPE_DYN_ARRAY_DESC is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_DESC_SUBRANGE is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_BEGIN_EXT is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_INLN is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_INLN_LIST is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_ALIAS is unused by GDB */
end_comment

begin_struct
struct|struct
name|dntt_type_doc_function
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
comment|/* always zero                  */
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
comment|/* K_DOC_FUNCTION or            */
comment|/* K_DOC_MEMFUNC                */
name|unsigned
name|int
name|global
range|:
literal|1
decl_stmt|;
comment|/* 1 => globally visible        */
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
comment|/* type of language             */
name|unsigned
name|int
name|level
range|:
literal|5
decl_stmt|;
comment|/* nesting level (top level = 0)*/
name|unsigned
name|int
name|optimize
range|:
literal|2
decl_stmt|;
comment|/* level of optimization        */
name|unsigned
name|int
name|varargs
range|:
literal|1
decl_stmt|;
comment|/* ellipses.  Pascal/800 later  */
name|unsigned
name|int
name|info
range|:
literal|4
decl_stmt|;
comment|/* lang-specific stuff; F_xxxx  */
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|localloc
range|:
literal|1
decl_stmt|;
comment|/* 0 at top, 1 at end of block  */
name|unsigned
name|int
name|expansion
range|:
literal|1
decl_stmt|;
comment|/* 1 = function expansion       */
name|unsigned
name|int
name|doc_clone
range|:
literal|1
decl_stmt|;
name|vtpointer
name|name
decl_stmt|;
comment|/* name of function             */
name|vtpointer
name|alias
decl_stmt|;
comment|/* alternate name, if any       */
name|dnttpointer
name|firstparam
decl_stmt|;
comment|/* first FPARAM, if any         */
name|sltpointer
name|address
decl_stmt|;
comment|/* code and text locations      */
name|CORE_ADDR
name|entryaddr
decl_stmt|;
comment|/* address of entry point       */
name|dnttpointer
name|retval
decl_stmt|;
comment|/* return type, if any          */
name|CORE_ADDR
name|lowaddr
decl_stmt|;
comment|/* lowest address of function   */
name|CORE_ADDR
name|hiaddr
decl_stmt|;
comment|/* highest address of function  */
name|dnttpointer
name|inline_list
decl_stmt|;
comment|/* pointer to first inline    */
name|ltpointer
name|lt_offset
decl_stmt|;
comment|/* start of frag/cp line table  */
name|ctxtpointer
name|ctxt_offset
decl_stmt|;
comment|/* start of context table for this routine */
block|}
struct|;
end_struct

begin_comment
comment|/* DNTT_TYPE_DOC_MEMFUNC is unused by GDB */
end_comment

begin_comment
comment|/* DNTT_TYPE_GENERIC and DNTT_TYPE_BLOCK are convience structures    so we can examine a DNTT entry in a generic fashion.  */
end_comment

begin_struct
struct|struct
name|dntt_type_generic
block|{
name|unsigned
name|int
name|word
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dntt_type_block
block|{
name|unsigned
name|int
name|extension
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|kind
range|:
literal|10
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|21
decl_stmt|;
name|unsigned
name|int
name|word
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* One entry in a DNTT (either the LNTT or GNTT).      This is a union of the above 60 or so structure definitions.  */
end_comment

begin_union
union|union
name|dnttentry
block|{
name|struct
name|dntt_type_srcfile
name|dsfile
decl_stmt|;
name|struct
name|dntt_type_module
name|dmodule
decl_stmt|;
name|struct
name|dntt_type_function
name|dfunc
decl_stmt|;
name|struct
name|dntt_type_function
name|dentry
decl_stmt|;
name|struct
name|dntt_type_begin
name|dbegin
decl_stmt|;
name|struct
name|dntt_type_end
name|dend
decl_stmt|;
name|struct
name|dntt_type_fparam
name|dfparam
decl_stmt|;
name|struct
name|dntt_type_svar
name|dsvar
decl_stmt|;
name|struct
name|dntt_type_dvar
name|ddvar
decl_stmt|;
name|struct
name|dntt_type_const
name|dconst
decl_stmt|;
name|struct
name|dntt_type_type
name|dtype
decl_stmt|;
name|struct
name|dntt_type_type
name|dtag
decl_stmt|;
name|struct
name|dntt_type_pointer
name|dptr
decl_stmt|;
name|struct
name|dntt_type_enum
name|denum
decl_stmt|;
name|struct
name|dntt_type_memenum
name|dmember
decl_stmt|;
name|struct
name|dntt_type_set
name|dset
decl_stmt|;
name|struct
name|dntt_type_subrange
name|dsubr
decl_stmt|;
name|struct
name|dntt_type_array
name|darray
decl_stmt|;
name|struct
name|dntt_type_struct
name|dstruct
decl_stmt|;
name|struct
name|dntt_type_union
name|dunion
decl_stmt|;
name|struct
name|dntt_type_field
name|dfield
decl_stmt|;
name|struct
name|dntt_type_functype
name|dfunctype
decl_stmt|;
name|struct
name|dntt_type_with
name|dwith
decl_stmt|;
name|struct
name|dntt_type_function
name|dblockdata
decl_stmt|;
name|struct
name|dntt_type_class_scope
name|dclass_scope
decl_stmt|;
name|struct
name|dntt_type_pointer
name|dreference
decl_stmt|;
name|struct
name|dntt_type_ptrmem
name|dptrmem
decl_stmt|;
name|struct
name|dntt_type_ptrmemfunc
name|dptrmemfunc
decl_stmt|;
name|struct
name|dntt_type_class
name|dclass
decl_stmt|;
name|struct
name|dntt_type_genfield
name|dgenfield
decl_stmt|;
name|struct
name|dntt_type_vfunc
name|dvfunc
decl_stmt|;
name|struct
name|dntt_type_memaccess
name|dmemaccess
decl_stmt|;
name|struct
name|dntt_type_inheritance
name|dinheritance
decl_stmt|;
name|struct
name|dntt_type_friend_class
name|dfriend_class
decl_stmt|;
name|struct
name|dntt_type_friend_func
name|dfriend_func
decl_stmt|;
name|struct
name|dntt_type_modifier
name|dmodifier
decl_stmt|;
name|struct
name|dntt_type_object_id
name|dobject_id
decl_stmt|;
name|struct
name|dntt_type_template
name|dtemplate
decl_stmt|;
name|struct
name|dntt_type_templ_arg
name|dtempl_arg
decl_stmt|;
name|struct
name|dntt_type_func_template
name|dfunc_template
decl_stmt|;
name|struct
name|dntt_type_link
name|dlink
decl_stmt|;
name|struct
name|dntt_type_doc_function
name|ddocfunc
decl_stmt|;
name|struct
name|dntt_type_generic
name|dgeneric
decl_stmt|;
name|struct
name|dntt_type_block
name|dblock
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Source line entry types.  */
end_comment

begin_enum
enum|enum
name|slttype
block|{
name|SLT_NORMAL
block|,
name|SLT_SRCFILE
block|,
name|SLT_MODULE
block|,
name|SLT_FUNCTION
block|,
name|SLT_ENTRY
block|,
name|SLT_BEGIN
block|,
name|SLT_END
block|,
name|SLT_WITH
block|,
name|SLT_EXIT
block|,
name|SLT_ASSIST
block|,
name|SLT_MARKER
block|,
name|SLT_CLASS_SCOPE
block|,
name|SLT_INLN
block|,
name|SLT_NORMAL_OFFSET
block|, }
enum|;
end_enum

begin_comment
comment|/* A normal source line entry.  Simply provides a mapping of a source    line number to a code address.     SLTDESC will always be SLT_NORMAL or SLT_EXIT.  */
end_comment

begin_struct
struct|struct
name|slt_normal
block|{
name|unsigned
name|int
name|sltdesc
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|line
range|:
literal|28
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|slt_normal_off
block|{
name|unsigned
name|int
name|sltdesc
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|offset
range|:
literal|6
decl_stmt|;
name|unsigned
name|int
name|line
range|:
literal|22
decl_stmt|;
name|CORE_ADDR
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A special source line entry.  Provides a mapping of a declaration    to a line number.  These entries point back into the DNTT which    references them.  */
end_comment

begin_struct
struct|struct
name|slt_special
block|{
name|unsigned
name|int
name|sltdesc
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|line
range|:
literal|28
decl_stmt|;
name|dnttpointer
name|backptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Used to describe nesting.     For nested languages, an slt_assist entry must follow each SLT_FUNC    entry in the SLT.  The address field will point forward to the    first slt_normal entry within the function's scope.  */
end_comment

begin_struct
struct|struct
name|slt_assist
block|{
name|unsigned
name|int
name|sltdesc
range|:
literal|4
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|28
decl_stmt|;
name|sltpointer
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|slt_generic
block|{
name|unsigned
name|int
name|word
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|sltentry
block|{
name|struct
name|slt_normal
name|snorm
decl_stmt|;
name|struct
name|slt_normal_off
name|snormoff
decl_stmt|;
name|struct
name|slt_special
name|sspec
decl_stmt|;
name|struct
name|slt_assist
name|sasst
decl_stmt|;
name|struct
name|slt_generic
name|sgeneric
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* $LINES$ declarations    This is the line table used for optimized code, which is only present     in the new $PROGRAM_INFO$ debug space.  */
end_comment

begin_define
define|#
directive|define
name|DST_LN_ESCAPE_FLAG1
value|15
end_define

begin_define
define|#
directive|define
name|DST_LN_ESCAPE_FLAG2
value|14
end_define

begin_define
define|#
directive|define
name|DST_LN_CTX_SPEC1
value|13
end_define

begin_define
define|#
directive|define
name|DST_LN_CTX_SPEC2
value|12
end_define

begin_comment
comment|/* Escape function codes:  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_ln_pad
block|,
comment|/* pad byte */
name|dst_ln_escape_1
block|,
comment|/* reserved */
name|dst_ln_dpc1_dln1
block|,
comment|/* 1 byte line delta, 1 byte pc delta */
name|dst_ln_dpc2_dln2
block|,
comment|/* 2 bytes line delta, 2 bytes pc delta */
name|dst_ln_pc4_ln4
block|,
comment|/* 4 bytes ABSOLUTE line number, 4 bytes ABSOLUTE pc */
name|dst_ln_dpc0_dln1
block|,
comment|/* 1 byte line delta, pc delta = 0 */
name|dst_ln_ln_off_1
block|,
comment|/* statement escape, stmt # = 1 (2nd stmt on line) */
name|dst_ln_ln_off
block|,
comment|/* statement escape, stmt # = next byte */
name|dst_ln_entry
block|,
comment|/* entry escape, next byte is entry number */
name|dst_ln_exit
block|,
comment|/* exit escape */
name|dst_ln_stmt_end
block|,
comment|/* gap escape, 4 bytes pc delta */
name|dst_ln_stmt_cp
block|,
comment|/* current stmt is a critical point */
name|dst_ln_escape_12
block|,
comment|/* reserved */
name|dst_ln_escape_13
block|,
comment|/* this is an exception site record */
name|dst_ln_nxt_byte
block|,
comment|/* next byte contains the real escape code */
name|dst_ln_end
block|,
comment|/* end escape, final entry follows */
name|dst_ln_escape1_END_OF_ENUM
block|}
name|dst_ln_escape1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_ln_ctx_1
block|,
comment|/* next byte describes context switch with 5-bit */
comment|/* index into the image table and 3-bit run length. */
comment|/* If run length is 0, end with another cxt specifier or ctx_end */
name|dst_ln_ctx_2
block|,
comment|/* next 2 bytes switch context: 13 bit index, 3 bit run length */
name|dst_ln_ctx_4
block|,
comment|/* next 4 bytes switch context: 29 bit index, 3 bit run length */
name|dst_ln_ctx_end
block|,
comment|/* end current context */
name|dst_ln_col_run_1
block|,
comment|/* next byte is column position of start of next statement, */
comment|/* following byte is length of statement */
name|dst_ln_col_run_2
block|,
comment|/* next 2 bytes is column position of start of next statement, */
comment|/* following 2 bytes is length of statement */
name|dst_ln_init_base1
block|,
comment|/* next 4 bytes are absolute PC, followed by 1 byte of line number */
name|dst_ln_init_base2
block|,
comment|/* next 4 bytes are absolute PC, followed by 2 bytes of line number */
name|dst_ln_init_base3
block|,
comment|/* next 4 bytes are absolute PC, followed by 3 bytes of line number */
name|dst_ln_escape2_END_OF_ENUM
block|}
name|dst_ln_escape2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|unsigned
name|int
name|pc_delta
range|:
literal|4
decl_stmt|;
comment|/* 4 bit pc delta */
name|int
name|ln_delta
range|:
literal|4
decl_stmt|;
comment|/* 4 bit line number delta */
block|}
name|delta
struct|;
struct|struct
block|{
name|unsigned
name|int
name|esc_flag
range|:
literal|4
decl_stmt|;
comment|/* alias for pc_delta  */
name|unsigned
name|int
name|esc_code
range|:
literal|4
decl_stmt|;
comment|/* escape function code (dst_ln_escape1_t, or ...2_t */
block|}
name|esc
struct|;
struct|struct
block|{
name|unsigned
name|int
name|esc_flag
range|:
literal|4
decl_stmt|;
comment|/* dst_ln_ctx_spec1, or dst_ln_ctx_spec2 */
name|unsigned
name|int
name|run_length
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|ctx_index
range|:
literal|2
decl_stmt|;
comment|/* ...spec2 contains index;  ...spec1, index - 4 */
block|}
name|ctx_spec
struct|;
name|char
name|sdata
decl_stmt|;
comment|/* signed data byte */
name|unsigned
name|char
name|udata
decl_stmt|;
comment|/* unsigned data byte */
block|}
name|dst_ln_entry_t
operator|,
typedef|*
name|dst_ln_entry_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* Warning: although the above union occupies only 1 byte the compiler treats    it as having size 2 (the minimum size of a struct).  Therefore a sequence of    dst_ln_entry_t's cannot be described as an array, and walking through such a    sequence requires convoluted code such as         ln_ptr = (dst_ln_entry_ptr_t) (char*) ln_ptr + 1    We regret the inconvenience.  */
end_comment

begin_comment
comment|/* Structure for interpreting the byte following a dst_ln_ctx1 entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|ctx1_index
range|:
literal|5
decl_stmt|;
comment|/* 5 bit index into context table */
name|unsigned
name|int
name|ctx1_run_length
range|:
literal|3
decl_stmt|;
comment|/* 3 bit run length */
block|}
name|dst_ln_ctx1_t
operator|,
typedef|*
name|dst_ln_ctx1_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* Structure for interpreting the bytes following a dst_ln_ctx2 entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|ctx2_index
range|:
literal|13
decl_stmt|;
comment|/* 13 bit index into context table */
name|unsigned
name|int
name|ctx2_run_length
range|:
literal|3
decl_stmt|;
comment|/* 3 bit run length */
block|}
name|dst_ln_ctx2_t
operator|,
typedef|*
name|dst_ln_ctx2_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* Structure for interpreting the bytes following a dst_ln_ctx4 entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|ctx4_index
range|:
literal|29
decl_stmt|;
comment|/* 29 bit index into context table */
name|unsigned
name|int
name|ctx4_run_length
range|:
literal|3
decl_stmt|;
comment|/* 3 bit run length */
block|}
name|dst_ln_ctx4_t
operator|,
typedef|*
name|dst_ln_ctx4_ptr_t
typedef|;
end_typedef

begin_comment
comment|/*  PXDB definitions.       PXDB is a post-processor which takes the executable file    and massages the debug information so that the debugger may    start up and run more efficiently.  Some of the tasks    performed by PXDB are:       o   Remove duplicate global type and variable information        from the GNTT,       o   Append the GNTT onto the end of the LNTT and place both        back in the LNTT section,       o   Build quick look-up tables (description follows) for        files, procedures, modules, and paragraphs (for Cobol),        placing these in the GNTT section,       o   Reconstruct the header appearing in the header section        to access this information.       The "quick look-up" tables are in the $GNTT$ sub-space, in    the following order:           Procedures    -sorted by address        Source files  -sorted by address (of the                       generated code from routines)        Modules       -sorted by address        Classes       -<unsorted?>        Address Alias -sorted by index<?>        Object IDs    -sorted by object identifier       Most quick entries have (0-based) indices into the LNTT tables to    the full entries for the item it describes.       The post-PXDB header is in the $HEADER$ sub-space.  Alas, it    occurs in different forms, depending on the optimization level    in the compilation step and whether PXDB was run or not. The    worst part is the forms aren't self-describing, so we'll have    to grovel in the bits to figure out what kind we're looking at    (see hp_get_header in hp-psymtab-read.c).  */
end_comment

begin_comment
comment|/* PXDB versions.  */
end_comment

begin_define
define|#
directive|define
name|PXDB_VERSION_CPLUSPLUS
value|1
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_7_4
value|2
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_CPP_30
value|3
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_DDE_3_2A
value|4
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_DDE_3_2
value|5
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_DDE_4_0
value|6
end_define

begin_define
define|#
directive|define
name|PXDB_VERSION_2_1
value|1
end_define

begin_comment
comment|/* Header version for the case that there is no DOC info    but the executable has been processed by pxdb (the easy    case, from "cc -g").  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PXDB_struct
block|{
name|int
name|pd_entries
decl_stmt|;
comment|/* # of entries in function look-up table */
name|int
name|fd_entries
decl_stmt|;
comment|/* # of entries in file look-up table */
name|int
name|md_entries
decl_stmt|;
comment|/* # of entries in module look-up table */
name|unsigned
name|int
name|pxdbed
range|:
literal|1
decl_stmt|;
comment|/* 1 => file has been preprocessed      */
name|unsigned
name|int
name|bighdr
range|:
literal|1
decl_stmt|;
comment|/* 1 => this header contains 'time' word */
name|unsigned
name|int
name|sa_header
range|:
literal|1
decl_stmt|;
comment|/* 1 => created by SA version of pxdb */
comment|/*   used for version check in xdb */
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
comment|/* one or more functions have been inlined */
name|unsigned
name|int
name|spare
range|:
literal|12
decl_stmt|;
name|short
name|version
decl_stmt|;
comment|/* pxdb header version */
name|int
name|globals
decl_stmt|;
comment|/* index into the DNTT where GNTT begins */
name|unsigned
name|int
name|time
decl_stmt|;
comment|/* modify time of file before being pxdbed */
name|int
name|pg_entries
decl_stmt|;
comment|/* # of entries in label look-up table */
name|int
name|functions
decl_stmt|;
comment|/* actual number of functions */
name|int
name|files
decl_stmt|;
comment|/* actual number of files */
name|int
name|cd_entries
decl_stmt|;
comment|/* # of entries in class look-up table */
name|int
name|aa_entries
decl_stmt|;
comment|/* # of entries in addr alias look-up table */
name|int
name|oi_entries
decl_stmt|;
comment|/* # of entries in object id look-up table */
block|}
name|PXDB_header
operator|,
typedef|*
name|PXDB_header_ptr
typedef|;
end_typedef

begin_comment
comment|/* Header version for the case that there is no DOC info and the    executable has NOT been processed by pxdb.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|XDB_header_struct
block|{
name|long
name|gntt_length
decl_stmt|;
name|long
name|lntt_length
decl_stmt|;
name|long
name|slt_length
decl_stmt|;
name|long
name|vt_length
decl_stmt|;
name|long
name|xt_length
decl_stmt|;
block|}
name|XDB_header
typedef|;
end_typedef

begin_comment
comment|/* Header version for the case that there is DOC info and the    executable has been processed by pxdb. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DOC_info_PXDB_header_struct
block|{
name|unsigned
name|int
name|xdb_header
range|:
literal|1
decl_stmt|;
comment|/* bit set if this is post-3.1 xdb */
name|unsigned
name|int
name|doc_header
range|:
literal|1
decl_stmt|;
comment|/* bit set if this is doc-style header */
name|unsigned
name|int
name|version
range|:
literal|8
decl_stmt|;
comment|/* version of pxdb see defines 				         PXDB_VERSION_* in this file.  */
name|unsigned
name|int
name|reserved_for_flags
range|:
literal|16
decl_stmt|;
comment|/* for future use; -- must be                                           set to zero.  */
name|unsigned
name|int
name|has_aux_pd_table
range|:
literal|1
decl_stmt|;
comment|/* $GNTT$ has aux PD table */
name|unsigned
name|int
name|has_expr_table
range|:
literal|1
decl_stmt|;
comment|/* space has $EXPR$ */
name|unsigned
name|int
name|has_range_table
range|:
literal|1
decl_stmt|;
comment|/* space has $RANGE$ */
name|unsigned
name|int
name|has_context_table
range|:
literal|1
decl_stmt|;
comment|/* space has $SRC_CTXT$ */
name|unsigned
name|int
name|has_lines_table
range|:
literal|1
decl_stmt|;
comment|/* space contains a $LINES$                                          subspace for line tables.  */
name|unsigned
name|int
name|has_lt_offset_map
range|:
literal|1
decl_stmt|;
comment|/* space contains an lt_offset                                          subspace for line table mapping.  */
comment|/* The following fields are the same as those in the PXDB_header in $DEBUG$ */
name|int
name|pd_entries
decl_stmt|;
comment|/* # of entries in function look-up table */
name|int
name|fd_entries
decl_stmt|;
comment|/* # of entries in file look-up table */
name|int
name|md_entries
decl_stmt|;
comment|/* # of entries in module look-up table */
name|unsigned
name|int
name|pxdbed
range|:
literal|1
decl_stmt|;
comment|/* 1 => file has been preprocessed      */
name|unsigned
name|int
name|bighdr
range|:
literal|1
decl_stmt|;
comment|/* 1 => this header contains 'time' word */
name|unsigned
name|int
name|sa_header
range|:
literal|1
decl_stmt|;
comment|/* 1 => created by SA version of pxdb */
comment|/*   used for version check in xdb */
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
comment|/* one or more functions have been inlined */
name|unsigned
name|int
name|spare
range|:
literal|28
decl_stmt|;
name|int
name|globals
decl_stmt|;
comment|/* index into the DNTT where GNTT begins */
name|unsigned
name|int
name|time
decl_stmt|;
comment|/* modify time of file before being pxdbed */
name|int
name|pg_entries
decl_stmt|;
comment|/* # of entries in label look-up table */
name|int
name|functions
decl_stmt|;
comment|/* actual number of functions */
name|int
name|files
decl_stmt|;
comment|/* actual number of files */
name|int
name|cd_entries
decl_stmt|;
comment|/* # of entries in class look-up table */
name|int
name|aa_entries
decl_stmt|;
comment|/* # of entries in addr alias look-up table */
name|int
name|oi_entries
decl_stmt|;
comment|/* # of entries in object id look-up table */
block|}
name|DOC_info_PXDB_header
typedef|;
end_typedef

begin_comment
comment|/* Header version for the case that there is DOC info and the    executable has NOT been processed by pxdb.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DOC_info_header_struct
block|{
name|unsigned
name|int
name|xdb_header
range|:
literal|1
decl_stmt|;
comment|/* bit set if this is post-3.1 xdb */
name|unsigned
name|int
name|doc_header
range|:
literal|1
decl_stmt|;
comment|/* bit set if this is doc-style header*/
name|unsigned
name|int
name|version
range|:
literal|8
decl_stmt|;
comment|/* version of debug/header                                     format. For 10.0 the value                                     will be 1. For "Davis" the value is 2.  */
name|unsigned
name|int
name|reserved_for_flags
range|:
literal|18
decl_stmt|;
comment|/* for future use; -- must be set to zero.  */
name|unsigned
name|int
name|has_range_table
range|:
literal|1
decl_stmt|;
comment|/* space contains a $RANGE$ subspace for variable ranges.  */
name|unsigned
name|int
name|has_context_table
range|:
literal|1
decl_stmt|;
comment|/* space contains a $CTXT$ subspace for context/inline table.  */
name|unsigned
name|int
name|has_lines_table
range|:
literal|1
decl_stmt|;
comment|/* space contains a $LINES$ subspace for line tables. */
name|unsigned
name|int
name|has_lt_offset_map
range|:
literal|1
decl_stmt|;
comment|/* space contains an lt_offset subspace for line table mapping.  */
name|long
name|gntt_length
decl_stmt|;
comment|/* same as old header */
name|long
name|lntt_length
decl_stmt|;
comment|/* same as old header */
name|long
name|slt_length
decl_stmt|;
comment|/* same as old header */
name|long
name|vt_length
decl_stmt|;
comment|/* same as old header */
name|long
name|xt_length
decl_stmt|;
comment|/* same as old header */
name|long
name|ctxt_length
decl_stmt|;
comment|/* present only if version>= 2 */
name|long
name|range_length
decl_stmt|;
comment|/* present only if version>= 2 */
name|long
name|expr_length
decl_stmt|;
comment|/* present only if version>= 2 */
block|}
name|DOC_info_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|GenericDebugHeader_union
block|{
name|PXDB_header
name|no_doc
decl_stmt|;
name|DOC_info_PXDB_header
name|doc
decl_stmt|;
name|XDB_header
name|no_pxdb_no_doc
decl_stmt|;
name|DOC_info_header
name|no_pxdb_doc
decl_stmt|;
block|}
name|GenericDebugHeader
typedef|;
end_typedef

begin_comment
comment|/*  Procedure Descriptor:     An element of the procedure quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_procedure
block|{
name|long
name|isym
decl_stmt|;
comment|/* 0-based index of first symbol                                    for procedure in $LNTT$,                                     i.e. the procedure itself.  */
name|CORE_ADDR
name|adrStart
decl_stmt|;
comment|/* memory adr of start of proc	*/
name|CORE_ADDR
name|adrEnd
decl_stmt|;
comment|/* memory adr of end of proc	*/
name|char
modifier|*
name|sbAlias
decl_stmt|;
comment|/* alias name of procedure	*/
name|char
modifier|*
name|sbProc
decl_stmt|;
comment|/* real name of procedure	*/
name|CORE_ADDR
name|adrBp
decl_stmt|;
comment|/* address of entry breakpoint  */
name|CORE_ADDR
name|adrExitBp
decl_stmt|;
comment|/* address of exit breakpoint   */
name|int
name|icd
decl_stmt|;
comment|/* member of this class (index) */
name|unsigned
name|int
name|ipd
decl_stmt|;
comment|/* index of template for this   */
comment|/* function (index)           */
name|unsigned
name|int
name|unused
range|:
literal|5
decl_stmt|;
name|unsigned
name|int
name|no_lt_offset
range|:
literal|1
decl_stmt|;
comment|/* no entry in lt_offset table */
name|unsigned
name|int
name|fTemplate
range|:
literal|1
decl_stmt|;
comment|/* function template		*/
name|unsigned
name|int
name|fExpansion
range|:
literal|1
decl_stmt|;
comment|/* function expansion		*/
name|unsigned
name|int
name|linked
range|:
literal|1
decl_stmt|;
comment|/* linked with other expansions	*/
name|unsigned
name|int
name|duplicate
range|:
literal|1
decl_stmt|;
comment|/* clone of another procedure   */
name|unsigned
name|int
name|overloaded
range|:
literal|1
decl_stmt|;
comment|/* overloaded function          */
name|unsigned
name|int
name|member
range|:
literal|1
decl_stmt|;
comment|/* class member function        */
name|unsigned
name|int
name|constructor
range|:
literal|1
decl_stmt|;
comment|/* constructor function         */
name|unsigned
name|int
name|destructor
range|:
literal|1
decl_stmt|;
comment|/* destructor function          */
name|unsigned
name|int
name|Static
range|:
literal|1
decl_stmt|;
comment|/* static function              */
name|unsigned
name|int
name|Virtual
range|:
literal|1
decl_stmt|;
comment|/* virtual function             */
name|unsigned
name|int
name|constant
range|:
literal|1
decl_stmt|;
comment|/* constant function            */
name|unsigned
name|int
name|pure
range|:
literal|1
decl_stmt|;
comment|/* pure (virtual) function      */
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
comment|/* procedure's language         */
name|unsigned
name|int
name|inlined
range|:
literal|1
decl_stmt|;
comment|/* function has been inlined    */
name|unsigned
name|int
name|Operator
range|:
literal|1
decl_stmt|;
comment|/* operator function            */
name|unsigned
name|int
name|stub
range|:
literal|1
decl_stmt|;
comment|/* bodyless function            */
name|unsigned
name|int
name|optimize
range|:
literal|2
decl_stmt|;
comment|/* optimization level   	*/
name|unsigned
name|int
name|level
range|:
literal|5
decl_stmt|;
comment|/* nesting level (top=0)	*/
block|}
name|quick_procedure_entry
operator|,
typedef|*
name|quick_procedure_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/*  Source File Descriptor:     An element of the source file quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_source
block|{
name|long
name|isym
decl_stmt|;
comment|/* 0-based index in $LNTT$ of                                    first symbol for this file.     */
name|CORE_ADDR
name|adrStart
decl_stmt|;
comment|/* mem adr of start of file's code */
name|CORE_ADDR
name|adrEnd
decl_stmt|;
comment|/* mem adr of end of file's code   */
name|char
modifier|*
name|sbFile
decl_stmt|;
comment|/* name of source file		   */
name|unsigned
name|int
name|fHasDecl
range|:
literal|1
decl_stmt|;
comment|/* do we have a .d file?	   */
name|unsigned
name|int
name|fWarned
range|:
literal|1
decl_stmt|;
comment|/* have warned about age problems? */
name|unsigned
name|int
name|fSrcfile
range|:
literal|1
decl_stmt|;
comment|/* 0 => include 1=> source         */
name|unsigned
name|short
name|ilnMac
decl_stmt|;
comment|/* lines in file (0 if don't know) */
name|int
name|ipd
decl_stmt|;
comment|/* 0-based index of first procedure                                    in this file, in the quick                                    look-up table of procedures.    */
name|unsigned
name|int
modifier|*
name|rgLn
decl_stmt|;
comment|/* line pointer array, if any	   */
block|}
name|quick_file_entry
operator|,
typedef|*
name|quick_file_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/*  Module Descriptor:     An element of the module quick reference table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_module
block|{
name|long
name|isym
decl_stmt|;
comment|/* 0-based index of first                                       symbol for module.        */
name|CORE_ADDR
name|adrStart
decl_stmt|;
comment|/* adr of start of mod.	*/
name|CORE_ADDR
name|adrEnd
decl_stmt|;
comment|/* adr of end of mod.	*/
name|char
modifier|*
name|sbAlias
decl_stmt|;
comment|/* alias name of module   	*/
name|char
modifier|*
name|sbMod
decl_stmt|;
comment|/* real name of module	*/
name|unsigned
name|int
name|imports
range|:
literal|1
decl_stmt|;
comment|/* module have any imports?  */
name|unsigned
name|int
name|vars_in_front
range|:
literal|1
decl_stmt|;
comment|/* module globals in front?  */
name|unsigned
name|int
name|vars_in_gaps
range|:
literal|1
decl_stmt|;
comment|/* module globals in gaps?   */
name|unsigned
name|int
name|language
range|:
literal|4
decl_stmt|;
comment|/* type of language          */
name|unsigned
name|int
name|unused
range|:
literal|25
decl_stmt|;
name|unsigned
name|int
name|unused2
decl_stmt|;
comment|/* space for future stuff	*/
block|}
name|quick_module_entry
operator|,
typedef|*
name|quick_module_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/*  Auxiliary Procedure Descriptor:     An element of the auxiliary procedure quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_aux_procedure
block|{
name|long
name|isym_inln
decl_stmt|;
comment|/* start on inline list for proc */
name|long
name|spare
decl_stmt|;
block|}
name|quick_aux_procedure_entry
operator|,
typedef|*
name|quick_aux_procedure_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/*  Paragraph Descriptor:     An element of the paragraph quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_paragraph
block|{
name|long
name|isym
decl_stmt|;
comment|/* first symbol for label (index)  */
name|CORE_ADDR
name|adrStart
decl_stmt|;
comment|/* memory adr of start of label    */
name|CORE_ADDR
name|adrEnd
decl_stmt|;
comment|/* memory adr of end of label      */
name|char
modifier|*
name|sbLab
decl_stmt|;
comment|/* name of label                   */
name|unsigned
name|int
name|inst
decl_stmt|;
comment|/* Used in xdb to store inst @ bp  */
name|unsigned
name|int
name|sect
range|:
literal|1
decl_stmt|;
comment|/* true = section, false = parag.  */
name|unsigned
name|int
name|unused
range|:
literal|31
decl_stmt|;
comment|/* future use                      */
block|}
name|quick_paragraph_entry
operator|,
typedef|*
name|quick_paragraph_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/* Class Descriptor:    An element of the class quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_class
block|{
name|char
modifier|*
name|sbClass
decl_stmt|;
comment|/* name of class	        */
name|long
name|isym
decl_stmt|;
comment|/* class symbol (tag)           */
name|unsigned
name|int
name|type
range|:
literal|2
decl_stmt|;
comment|/* 0=class, 1=union, 2=struct   */
name|unsigned
name|int
name|fTemplate
range|:
literal|1
decl_stmt|;
comment|/* class template               */
name|unsigned
name|int
name|expansion
range|:
literal|1
decl_stmt|;
comment|/* template expansion           */
name|unsigned
name|int
name|unused
range|:
literal|28
decl_stmt|;
name|sltpointer
name|lowscope
decl_stmt|;
comment|/* beginning of defined scope   */
name|sltpointer
name|hiscope
decl_stmt|;
comment|/* end of defined scope         */
block|}
name|quick_class_entry
operator|,
typedef|*
name|quick_class_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/* Address Alias Entry    An element of the address alias quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_alias
block|{
name|CORE_ADDR
name|low
decl_stmt|;
name|CORE_ADDR
name|high
decl_stmt|;
name|int
name|index
decl_stmt|;
name|unsigned
name|int
name|unused
range|:
literal|31
decl_stmt|;
name|unsigned
name|int
name|alternate
range|:
literal|1
decl_stmt|;
comment|/* alternate unnamed aliases?   */
block|}
name|quick_alias_entry
operator|,
typedef|*
name|quick_alias_entry_ptr
typedef|;
end_typedef

begin_comment
comment|/* Object Identification Entry    An element of the object identification quick look-up table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|quick_obj_ID
block|{
name|CORE_ADDR
name|obj_ident
decl_stmt|;
comment|/* class identifier         */
name|long
name|isym
decl_stmt|;
comment|/* class symbol             */
name|long
name|offset
decl_stmt|;
comment|/* offset to object start   */
block|}
name|quick_obj_ID_entry
operator|,
typedef|*
name|quick_obj_ID_entry_ptr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP_SYMTAB_INCLUDED */
end_comment

end_unit

