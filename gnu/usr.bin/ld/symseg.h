begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  *	from: @(#)symseg.h	5.4 (Berkeley) 4/30/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/* GDB symbol table format definitions.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Format of GDB symbol table data.    There is one symbol segment for each source file or    independant compilation.  These segments are simply concatenated    to form the GDB symbol table.  A zero word where the beginning    of a segment is expected indicates there are no more segments.  Format of a symbol segment:     The symbol segment begins with a word containing 1    if it is in the format described here.  Other formats may    be designed, with other code numbers.     The segment contains many objects which point at each other.    The pointers are offsets in bytes from the beginning of the segment.    Thus, each segment can be loaded into core and its pointers relocated    to make valid in-core pointers.     All the data objects in the segment can be found indirectly from    one of them, the root object, of type `struct symbol_root'.    It appears at the beginning of the segment.     The total size of the segment, in bytes, appears as the `length'    field of this object.  This size includes the size of the    root object.     All the object data types are defined here to contain pointer types    appropriate for in-core use on a relocated symbol segment.    Casts to and from type int are required for working with    unrelocated symbol segments such as are found in the file.     The ldsymaddr word is filled in by the loader to contain    the offset (in bytes) within the ld symbol table    of the first nonglobal symbol from this compilation.    This makes it possible to match those symbols    (which contain line number information) reliably with    the segment they go with.     Core addresses within the program that appear in the symbol segment    are not relocated by the loader.  They are inserted by the assembler    and apply to addresses as output by the assembler, so GDB must    relocate them when it loads the symbol segment.  It gets the information    on how to relocate from the textrel, datarel, bssrel, databeg and bssbeg    words of the root object.     The words textrel, datarel and bssrel    are filled in by ld with the amounts to relocate within-the-file    text, data and bss addresses by; databeg and bssbeg can be    used to tell which kind of relocation an address needs.  */
end_comment

begin_enum
enum|enum
name|language
block|{
name|language_c
block|}
enum|;
end_enum

begin_struct
struct|struct
name|symbol_root
block|{
name|int
name|format
decl_stmt|;
comment|/* Data format version */
name|int
name|length
decl_stmt|;
comment|/* # bytes in this symbol segment */
name|int
name|ldsymoff
decl_stmt|;
comment|/* Offset in ld symtab of this file's syms */
name|int
name|textrel
decl_stmt|;
comment|/* Relocation for text addresses */
name|int
name|datarel
decl_stmt|;
comment|/* Relocation for data addresses */
name|int
name|bssrel
decl_stmt|;
comment|/* Relocation for bss addresses */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Name of main source file compiled */
name|char
modifier|*
name|filedir
decl_stmt|;
comment|/* Name of directory it was reached from */
name|struct
name|blockvector
modifier|*
name|blockvector
decl_stmt|;
comment|/* Vector of all symbol-naming blocks */
name|struct
name|typevector
modifier|*
name|typevector
decl_stmt|;
comment|/* Vector of all data types */
name|enum
name|language
name|language
decl_stmt|;
comment|/* Code identifying the language used */
name|char
modifier|*
name|version
decl_stmt|;
comment|/* Version info.  Not fully specified */
name|char
modifier|*
name|compilation
decl_stmt|;
comment|/* Compilation info.  Not fully specified */
name|int
name|databeg
decl_stmt|;
comment|/* Address within the file of data start */
name|int
name|bssbeg
decl_stmt|;
comment|/* Address within the file of bss start */
name|struct
name|sourcevector
modifier|*
name|sourcevector
decl_stmt|;
comment|/* Vector of line-number info */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* All data types of symbols in the compiled program    are represented by `struct type' objects.    All of these objects are pointed to by the typevector.    The type vector may have empty slots that contain zero.  */
end_comment

begin_struct
struct|struct
name|typevector
block|{
name|int
name|length
decl_stmt|;
comment|/* Number of types described */
name|struct
name|type
modifier|*
name|type
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Different kinds of data types are distinguished by the `code' field.  */
end_comment

begin_enum
enum|enum
name|type_code
block|{
name|TYPE_CODE_UNDEF
block|,
comment|/* Not used; catches errors */
name|TYPE_CODE_PTR
block|,
comment|/* Pointer type */
name|TYPE_CODE_ARRAY
block|,
comment|/* Array type, lower bound zero */
name|TYPE_CODE_STRUCT
block|,
comment|/* C struct or Pascal record */
name|TYPE_CODE_UNION
block|,
comment|/* C union or Pascal variant part */
name|TYPE_CODE_ENUM
block|,
comment|/* Enumeration type */
name|TYPE_CODE_FUNC
block|,
comment|/* Function type */
name|TYPE_CODE_INT
block|,
comment|/* Integer type */
name|TYPE_CODE_FLT
block|,
comment|/* Floating type */
name|TYPE_CODE_VOID
block|,
comment|/* Void type (values zero length) */
name|TYPE_CODE_SET
block|,
comment|/* Pascal sets */
name|TYPE_CODE_RANGE
block|,
comment|/* Range (integers within spec'd bounds) */
name|TYPE_CODE_PASCAL_ARRAY
block|,
comment|/* Array with explicit type of index */
block|}
enum|;
end_enum

begin_comment
comment|/* This appears in a type's flags word for an unsigned integer type.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_UNSIGNED
value|1
end_define

begin_comment
comment|/* Other flag bits are used with GDB.  */
end_comment

begin_struct
struct|struct
name|type
block|{
comment|/* Code for kind of type */
name|enum
name|type_code
name|code
decl_stmt|;
comment|/* Name of this type, or zero if none.      This is used for printing only.      Type names specified as input are defined by symbols.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Length in bytes of storage for a value of this type */
name|int
name|length
decl_stmt|;
comment|/* For a pointer type, describes the type of object pointed to.      For an array type, describes the type of the elements.      For a function type, describes the type of the value.      Unused otherwise.  */
name|struct
name|type
modifier|*
name|target_type
decl_stmt|;
comment|/* Type that is a pointer to this type.      Zero if no such pointer-to type is known yet.      The debugger may add the address of such a type      if it has to construct one later.  */
name|struct
name|type
modifier|*
name|pointer_type
decl_stmt|;
comment|/* Type that is a function returning this type.      Zero if no such function type is known here.      The debugger may add the address of such a type      if it has to construct one later.  */
name|struct
name|type
modifier|*
name|function_type
decl_stmt|;
comment|/* Flags about this type.  */
name|short
name|flags
decl_stmt|;
comment|/* Number of fields described for this type */
name|short
name|nfields
decl_stmt|;
comment|/* For structure and union types, a description of each field.      For set and pascal array types, there is one "field",      whose type is the domain type of the set or array.      For range types, there are two "fields",      the minimum and maximum values (both inclusive).      For enum types, each possible value is described by one "field".      For range types, there are two "fields", that record constant values      (inclusive) for the minimum and maximum.       Using a pointer to a separate array of fields      allows all types to have the same size, which is useful      because we can allocate the space for a type before      we know what to put in it.  */
struct|struct
name|field
block|{
comment|/* Position of this field, counting in bits from start of 	 containing structure.  For a function type, this is the 	 position in the argument list of this argument. 	 For a range bound or enum value, this is the value itself.  */
name|int
name|bitpos
decl_stmt|;
comment|/* Size of this field, in bits, or zero if not packed. 	 For an unpacked field, the field's type's length 	 says how many bytes the field occupies.  */
name|int
name|bitsize
decl_stmt|;
comment|/* In a struct or enum type, type of this field. 	 In a function type, type of this argument. 	 In an array type, the domain-type of the array.  */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* Name of field, value or argument. 	 Zero for range bounds and array domains.  */
name|char
modifier|*
name|name
decl_stmt|;
block|}
modifier|*
name|fields
struct|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* All of the name-scope contours of the program    are represented by `struct block' objects.    All of these objects are pointed to by the blockvector.     Each block represents one name scope.    Each lexical context has its own block.     The first two blocks in the blockvector are special.    The first one contains all the symbols defined in this compilation    whose scope is the entire program linked together.    The second one contains all the symbols whose scope is the    entire compilation excluding other separate compilations.    In C, these correspond to global symbols and static symbols.     Each block records a range of core addresses for the code that    is in the scope of the block.  The first two special blocks    give, for the range of code, the entire range of code produced    by the compilation that the symbol segment belongs to.     The blocks appear in the blockvector    in order of increasing starting-address,    and, within that, in order of decreasing ending-address.     This implies that within the body of one function    the blocks appear in the order of a depth-first tree walk.  */
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

begin_struct
struct|struct
name|block
block|{
comment|/* Addresses in the executable code that are in this block.      Note: in an unrelocated symbol segment in a file,      these are always zero.  They can be filled in from the      N_LBRAC and N_RBRAC symbols in the loader symbol table.  */
name|int
name|startaddr
decl_stmt|,
name|endaddr
decl_stmt|;
comment|/* The symbol that names this block,      if the block is the body of a function;      otherwise, zero.      Note: In an unrelocated symbol segment in an object file,      this field may be zero even when the block has a name.      That is because the block is output before the name      (since the name resides in a higher block).      Since the symbol does point to the block (as its value),      it is possible to find the block and set its name properly.  */
name|struct
name|symbol
modifier|*
name|function
decl_stmt|;
comment|/* The `struct block' for the containing block, or 0 if none.  */
comment|/* Note that in an unrelocated symbol segment in an object file      this pointer may be zero when the correct value should be      the second special block (for symbols whose scope is one compilation).      This is because the compiler ouptuts the special blocks at the      very end, after the other blocks.   */
name|struct
name|block
modifier|*
name|superblock
decl_stmt|;
comment|/* Number of local symbols.  */
name|int
name|nsyms
decl_stmt|;
comment|/* The symbols.  */
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

begin_escape
end_escape

begin_comment
comment|/* Represent one symbol name; a variable, constant, function or typedef.  */
end_comment

begin_comment
comment|/* Different name spaces for symbols.  Looking up a symbol specifies    a namespace and ignores symbol definitions in other name spaces.     VAR_NAMESPACE is the usual namespace.    In C, this contains variables, function names, typedef names    and enum type values.     STRUCT_NAMESPACE is used in C to hold struct, union and enum type names.    Thus, if `struct foo' is used in a C program,    it produces a symbol named `foo' in the STRUCT_NAMESPACE.     LABEL_NAMESPACE may be used for names of labels (for gotos);    currently it is not used and labels are not recorded at all.  */
end_comment

begin_comment
comment|/* For a non-global symbol allocated statically,    the correct core address cannot be determined by the compiler.    The compiler puts an index number into the symbol's value field.    This index number can be matched with the "desc" field of    an entry in the loader symbol table.  */
end_comment

begin_enum
enum|enum
name|namespace
block|{
name|UNDEF_NAMESPACE
block|,
name|VAR_NAMESPACE
block|,
name|STRUCT_NAMESPACE
block|,
name|LABEL_NAMESPACE
block|, }
enum|;
end_enum

begin_comment
comment|/* An address-class says where to find the value of the symbol in core.  */
end_comment

begin_enum
enum|enum
name|address_class
block|{
name|LOC_UNDEF
block|,
comment|/* Not used; catches errors */
name|LOC_CONST
block|,
comment|/* Value is constant int */
name|LOC_STATIC
block|,
comment|/* Value is at fixed address */
name|LOC_REGISTER
block|,
comment|/* Value is in register */
name|LOC_ARG
block|,
comment|/* Value is at spec'd position in arglist */
name|LOC_LOCAL
block|,
comment|/* Value is at spec'd pos in stack frame */
name|LOC_TYPEDEF
block|,
comment|/* Value not used; definition in SYMBOL_TYPE 			   Symbols in the namespace STRUCT_NAMESPACE 			   all have this class.  */
name|LOC_LABEL
block|,
comment|/* Value is address in the code */
name|LOC_BLOCK
block|,
comment|/* Value is address of a `struct block'. 			   Function names have this class.  */
name|LOC_EXTERNAL
block|,
comment|/* Value is at address not in this compilation. 			   This is used for .comm symbols 			   and for extern symbols within functions. 			   Inside GDB, this is changed to LOC_STATIC once the 			   real address is obtained from a loader symbol.  */
name|LOC_CONST_BYTES
comment|/* Value is a constant byte-sequence.   */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|symbol
block|{
comment|/* Symbol name */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name space code.  */
name|enum
name|namespace
name|namespace
decl_stmt|;
comment|/* Address class */
name|enum
name|address_class
name|class
decl_stmt|;
comment|/* Data type of value */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* constant value, or address if static, or register number,      or offset in arguments, or offset in stack frame.  */
union|union
block|{
name|long
name|value
decl_stmt|;
name|struct
name|block
modifier|*
name|block
decl_stmt|;
comment|/* for LOC_BLOCK */
name|char
modifier|*
name|bytes
decl_stmt|;
comment|/* for LOC_CONST_BYTES */
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Source-file information.    This describes the relation between source files and line numbers    and addresses in the program text.  */
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
comment|/* Line number and address of one line.  */
end_comment

begin_struct
struct|struct
name|line
block|{
name|int
name|linenum
decl_stmt|;
name|int
name|address
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
name|int
name|nlines
decl_stmt|;
comment|/* Number of lines that follow */
name|struct
name|line
name|lines
index|[
literal|1
index|]
decl_stmt|;
comment|/* Information on each line */
block|}
struct|;
end_struct

end_unit

