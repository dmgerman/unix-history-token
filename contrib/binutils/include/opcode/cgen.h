begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for targets using CGEN: Cpu tools GENerator.  Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.  This file is part of GDB, the GNU debugger, and the GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_H
end_ifndef

begin_define
define|#
directive|define
name|CGEN_H
end_define

begin_comment
comment|/* Prepend the cpu name, defined in cpu-opc.h, and _cgen_ to symbol S.    The lack of spaces in the arg list is important for non-stdc systems.    This file is included by<cpu>-opc.h.    It can be included independently of cpu-opc.h, in which case the cpu    dependent portions will be declared as "unknown_cgen_foo".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_SYM
end_ifndef

begin_define
define|#
directive|define
name|CGEN_SYM
parameter_list|(
name|s
parameter_list|)
value|CONCAT3 (unknown,_cgen_,s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This file contains the static (unchanging) pieces and as much other stuff    as we can reasonably put here.  It's generally cleaner to put stuff here    rather than having it machine generated if possible.  */
end_comment

begin_comment
comment|/* The assembler syntax is made up of expressions (duh...).    At the lowest level the values are mnemonics, register names, numbers, etc.    Above that are subexpressions, if any (an example might be the    "effective address" in m68k cpus).  At the second highest level are the    insns themselves.  Above that are pseudo-insns, synthetic insns, and macros,    if any. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Lots of cpu's have a fixed insn size, or one which rarely changes,    and it's generally easier to handle these by treating the insn as an    integer type, rather than an array of characters.  So we allow targets    to control this.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CGEN_INT_INSN
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|cgen_insn_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|cgen_insn_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|CGEN_INLINE
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGEN_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Perhaps we should just use bfd.h, but it's not clear    one would want to require that yet.  */
end_comment

begin_enum
enum|enum
name|cgen_endian
block|{
name|CGEN_ENDIAN_UNKNOWN
block|,
name|CGEN_ENDIAN_LITTLE
block|,
name|CGEN_ENDIAN_BIG
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Attributes.    Attributes are used to describe various random things.  */
end_comment

begin_comment
comment|/* Struct to record attribute information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|num_nonbools
decl_stmt|;
name|unsigned
name|int
name|bool
decl_stmt|;
name|unsigned
name|int
name|nonbool
index|[
literal|1
index|]
decl_stmt|;
block|}
name|CGEN_ATTR
typedef|;
end_typedef

begin_comment
comment|/* Define a structure member for attributes with N non-boolean entries.    The attributes are sorted so that the non-boolean ones come first.    num_nonbools: count of nonboolean attributes    bool: values of boolean attributes    nonbool: values of non-boolean attributes    There is a maximum of 32 attributes total.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_TYPE
parameter_list|(
name|n
parameter_list|)
define|\
value|const struct { unsigned char num_nonbools; \ 	       unsigned int bool; \ 	       unsigned int nonbool[(n) ? (n) : 1]; }
end_define

begin_comment
comment|/* Given an attribute number, return its mask.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_MASK
parameter_list|(
name|attr
parameter_list|)
value|(1<< (attr))
end_define

begin_comment
comment|/* Return the value of boolean attribute ATTR in ATTRS.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_BOOL_ATTR
parameter_list|(
name|attrs
parameter_list|,
name|attr
parameter_list|)
define|\
value|((CGEN_ATTR_MASK (attr)& (attrs)) != 0)
end_define

begin_comment
comment|/* Return value of attribute ATTR in ATTR_TABLE for OBJ.    OBJ is a pointer to the entity that has the attributes.    It's not used at present but is reserved for future purposes.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_VALUE
parameter_list|(
name|obj
parameter_list|,
name|attr_table
parameter_list|,
name|attr
parameter_list|)
define|\
value|((unsigned int) (attr)< (attr_table)->num_nonbools \  ? ((attr_table)->nonbool[attr]) \  : (((attr_table)->bool& (1<< (attr))) != 0))
end_define

begin_comment
comment|/* Attribute name/value tables.    These are used to assist parsing of descriptions at runtime.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|CGEN_ATTR_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* For each domain (fld,operand,insn), list of attributes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* NULL for boolean attributes.  */
specifier|const
name|CGEN_ATTR_ENTRY
modifier|*
name|vals
decl_stmt|;
block|}
name|CGEN_ATTR_TABLE
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Parse result (also extraction result).     The result of parsing an insn is stored here.    To generate the actual insn, this is passed to the insert handler.    When printing an insn, the result of extraction is stored here.    To print the insn, this is passed to the print handler.     It is machine generated so we don't define it here,    but we do need a forward decl for the handler fns.     There is one member for each possible field in the insn.    The type depends on the field.    Also recorded here is the computed length of the insn for architectures    where it varies. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cgen_fields
name|CGEN_FIELDS
typedef|;
end_typedef

begin_comment
comment|/* Total length of the insn, as recorded in the `fields' struct.  */
end_comment

begin_comment
comment|/* ??? The field insert handler has lots of opportunities for optimization    if it ever gets inlined.  On architectures where insns all have the same    size, may wish to detect that and make this macro a constant - to allow    further optimizations.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_FIELDS_BITSIZE
parameter_list|(
name|fields
parameter_list|)
value|((fields)->length)
end_define

begin_escape
end_escape

begin_comment
comment|/* Associated with each insn or expression is a set of "handlers" for    performing operations like parsing, printing, etc.  */
end_comment

begin_comment
comment|/* Forward decl.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cgen_insn
name|CGEN_INSN
typedef|;
end_typedef

begin_comment
comment|/* Parse handler.    The first argument is a pointer to a struct describing the insn being    parsed.    The second argument is a pointer to a pointer to the text being parsed.    The third argument is a pointer to a cgen_fields struct    in which the results are placed.    If the expression is successfully parsed, the pointer to the text is    updated.  If not it is left alone.    The result is NULL if success or an error message.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
operator|*
operator|(
name|cgen_parse_fn
operator|)
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|cgen_insn
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|CGEN_FIELDS
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Print handler.    The first argument is a pointer to the disassembly info.    Eg: disassemble_info.  It's defined as `PTR' so this file can be included    without dis-asm.h.    The second argument is a pointer to a struct describing the insn being    printed.    The third argument is a pointer to a cgen_fields struct.    The fourth argument is the pc value of the insn.    The fifth argument is the length of the insn, in bytes.  */
end_comment

begin_comment
comment|/* Don't require bfd.h unnecessarily.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION
end_ifdef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|cgen_print_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
expr|struct
name|cgen_insn
operator|*
operator|,
name|CGEN_FIELDS
operator|*
operator|,
name|bfd_vma
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
function_decl|(
name|cgen_print_fn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Insert handler.    The first argument is a pointer to a struct describing the insn being    parsed.    The second argument is a pointer to a cgen_fields struct    from which the values are fetched.    The third argument is a pointer to a buffer in which to place the insn.    The result is an error message or NULL if success.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
operator|*
operator|(
name|cgen_insert_fn
operator|)
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|cgen_insn
operator|*
operator|,
name|CGEN_FIELDS
operator|*
operator|,
name|cgen_insn_t
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Extract handler.    The first argument is a pointer to a struct describing the insn being    parsed.    The second argument is a pointer to a struct controlling extraction    (only used for variable length insns).    The third argument is the first CGEN_BASE_INSN_SIZE bytes.    The fourth argument is a pointer to a cgen_fields struct    in which the results are placed.    The result is the length of the insn or zero if not recognized.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|cgen_extract_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|cgen_insn
operator|*
operator|,
name|void
operator|*
operator|,
name|cgen_insn_t
operator|,
name|CGEN_FIELDS
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* The `parse' and `insert' fields are indices into these tables.    The elements are pointer to specialized handler functions.    Element 0 is special, it means use the default handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|cgen_parse_fn
modifier|*
name|CGEN_SYM
argument_list|(
name|parse_handlers
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_PARSE_FN
parameter_list|(
name|x
parameter_list|)
value|(CGEN_SYM (parse_handlers)[(x)->base.parse])
end_define

begin_decl_stmt
specifier|extern
name|cgen_insert_fn
modifier|*
name|CGEN_SYM
argument_list|(
name|insert_handlers
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_INSERT_FN
parameter_list|(
name|x
parameter_list|)
value|(CGEN_SYM (insert_handlers)[(x)->base.insert])
end_define

begin_comment
comment|/* Likewise for the `extract' and `print' fields.  */
end_comment

begin_decl_stmt
specifier|extern
name|cgen_extract_fn
modifier|*
name|CGEN_SYM
argument_list|(
name|extract_handlers
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_EXTRACT_FN
parameter_list|(
name|x
parameter_list|)
value|(CGEN_SYM (extract_handlers)[(x)->base.extract])
end_define

begin_decl_stmt
specifier|extern
name|cgen_print_fn
modifier|*
name|CGEN_SYM
argument_list|(
name|print_handlers
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_PRINT_FN
parameter_list|(
name|x
parameter_list|)
value|(CGEN_SYM (print_handlers)[(x)->base.print])
end_define

begin_escape
end_escape

begin_comment
comment|/* Base class of parser/printer.    (Don't read too much into the use of the phrase "base class".    It's a name I'm using to organize my thoughts.)     Instructions and expressions all share this data in common.    It's a collection of the common elements needed to parse, insert, extract,    and print each of them.  */
end_comment

begin_struct
struct|struct
name|cgen_base
block|{
comment|/* Indices into the handler tables.      We could use pointers here instead, but in the case of the insn table,      90% of them would be identical and that's a lot of redundant data.      0 means use the default (what the default is is up to the code).  */
name|unsigned
name|char
name|parse
decl_stmt|,
name|insert
decl_stmt|,
name|extract
decl_stmt|,
name|print
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Assembler interface.     The interface to the assembler is intended to be clean in the sense that    libopcodes.a is a standalone entity and could be used with any assembler.    Not that one would necessarily want to do that but rather that it helps    keep a clean interface.  The interface will obviously be slanted towards    GAS, but at least it's a start.     Parsing is controlled by the assembler which calls    CGEN_SYM (assemble_insn).  If it can parse and build the entire insn    it doesn't call back to the assembler.  If it needs/wants to call back    to the assembler, (*cgen_parse_operand_fn) is called which can either     - return a number to be inserted in the insn    - return a "register" value to be inserted      (the register might not be a register per pe)    - queue the argument and return a marker saying the expression has been      queued (eg: a fix-up)    - return an error message indicating the expression wasn't recognizable     The result is an error message or NULL for success.    The parsed value is stored in the bfd_vma *.  */
end_comment

begin_comment
comment|/* Values for indicating what the caller wants.  */
end_comment

begin_enum
enum|enum
name|cgen_parse_operand_type
block|{
name|CGEN_PARSE_OPERAND_INIT
block|,
name|CGEN_PARSE_OPERAND_INTEGER
block|,
name|CGEN_PARSE_OPERAND_ADDRESS
block|}
enum|;
end_enum

begin_comment
comment|/* Values for indicating what was parsed.    ??? Not too useful at present but in time.  */
end_comment

begin_enum
enum|enum
name|cgen_parse_operand_result
block|{
name|CGEN_PARSE_OPERAND_RESULT_NUMBER
block|,
name|CGEN_PARSE_OPERAND_RESULT_REGISTER
block|,
name|CGEN_PARSE_OPERAND_RESULT_QUEUED
block|,
name|CGEN_PARSE_OPERAND_RESULT_ERROR
block|}
enum|;
end_enum

begin_comment
comment|/* Don't require bfd.h unnecessarily.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION
end_ifdef

begin_extern
extern|extern const char * (*cgen_parse_operand_fn
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
expr|enum
name|cgen_parse_operand_type
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|cgen_parse_operand_result
operator|*
operator|,
name|bfd_vma
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Called before trying to match a table entry with the insn.  */
end_comment

begin_decl_stmt
name|void
name|cgen_init_parse_operand
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called from<cpu>-asm.c to initialize operand parsing.  */
end_comment

begin_comment
comment|/* These are GAS specific.  They're not here as part of the interface,    but rather that we need to put them somewhere.  */
end_comment

begin_comment
comment|/* Call this from md_assemble to initialize the assembler callback.  */
end_comment

begin_decl_stmt
name|void
name|cgen_asm_init_parse
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't require bfd.h unnecessarily.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION
end_ifdef

begin_comment
comment|/* The result is an error message or NULL for success.    The parsed value is stored in the bfd_vma *.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_parse_operand
name|PARAMS
argument_list|(
operator|(
expr|enum
name|cgen_parse_operand_type
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|cgen_parse_operand_result
operator|*
operator|,
name|bfd_vma
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
name|void
name|cgen_save_fixups
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
name|cgen_restore_fixups
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
name|cgen_swap_fixups
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a register to the assembler's hash table.    This makes lets GAS parse registers for us.    ??? This isn't currently used, but it could be in the future.  */
end_comment

begin_decl_stmt
name|void
name|cgen_asm_record_register
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
comment|/* After CGEN_SYM (assemble_insn) is done, this is called to    output the insn and record any fixups.  The address of the    assembled instruction is returned in case it is needed by    the caller.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cgen_asm_finish_insn
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|cgen_insn
operator|*
operator|,
name|cgen_insn_t
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Operand values (keywords, integers, symbols, etc.)  */
end_comment

begin_comment
comment|/* Types of assembler elements.  */
end_comment

begin_enum
enum|enum
name|cgen_asm_type
block|{
name|CGEN_ASM_KEYWORD
block|,
name|CGEN_ASM_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* List of hardware elements.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_hw_entry
block|{
comment|/* The type of this entry, one of `enum hw_type'.      This is an int and not the enum as the latter may not be declared yet.  */
name|int
name|type
decl_stmt|;
specifier|const
name|struct
name|cgen_hw_entry
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|cgen_asm_type
name|asm_type
decl_stmt|;
name|PTR
name|asm_data
decl_stmt|;
block|}
name|CGEN_HW_ENTRY
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|cgen_hw_lookup
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
comment|/* This struct is used to describe things like register names, etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_keyword_entry
block|{
comment|/* Name (as in register name).  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Value (as in register number).      The value cannot be -1 as that is used to indicate "not found".      IDEA: Have "FUNCTION" attribute? [function is called to fetch value].  */
name|int
name|value
decl_stmt|;
comment|/* Attributes.      This should, but technically needn't, appear last.  It is a variable sized      array in that one architecture may have 1 nonbool attribute and another      may have more.  Having this last means the non-architecture specific code      needn't care.  */
comment|/* ??? Moving this last should be done by treating keywords like insn lists      and moving the `next' fields into a CGEN_KEYWORD_LIST struct.  */
comment|/* FIXME: Not used yet.  */
ifndef|#
directive|ifndef
name|CGEN_KEYWORD_NBOOL_ATTRS
define|#
directive|define
name|CGEN_KEYWORD_NBOOL_ATTRS
value|1
endif|#
directive|endif
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_KEYWORD_NBOOL_ATTRS
argument_list|)
name|attrs
expr_stmt|;
comment|/* Next name hash table entry.  */
name|struct
name|cgen_keyword_entry
modifier|*
name|next_name
decl_stmt|;
comment|/* Next value hash table entry.  */
name|struct
name|cgen_keyword_entry
modifier|*
name|next_value
decl_stmt|;
block|}
name|CGEN_KEYWORD_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Top level struct for describing a set of related keywords    (e.g. register names).     This struct supports runtime entry of new values, and hashed lookups.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_keyword
block|{
comment|/* Pointer to initial [compiled in] values.  */
name|CGEN_KEYWORD_ENTRY
modifier|*
name|init_entries
decl_stmt|;
comment|/* Number of entries in `init_entries'.  */
name|unsigned
name|int
name|num_init_entries
decl_stmt|;
comment|/* Hash table used for name lookup.  */
name|CGEN_KEYWORD_ENTRY
modifier|*
modifier|*
name|name_hash_table
decl_stmt|;
comment|/* Hash table used for value lookup.  */
name|CGEN_KEYWORD_ENTRY
modifier|*
modifier|*
name|value_hash_table
decl_stmt|;
comment|/* Number of entries in the hash_tables.  */
name|unsigned
name|int
name|hash_table_size
decl_stmt|;
comment|/* Pointer to null keyword "" entry if present.  */
specifier|const
name|CGEN_KEYWORD_ENTRY
modifier|*
name|null_entry
decl_stmt|;
block|}
name|CGEN_KEYWORD
typedef|;
end_typedef

begin_comment
comment|/* Structure used for searching.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Table being searched.  */
specifier|const
name|CGEN_KEYWORD
modifier|*
name|table
decl_stmt|;
comment|/* Specification of what is being searched for.  */
specifier|const
name|char
modifier|*
name|spec
decl_stmt|;
comment|/* Current index in hash table.  */
name|unsigned
name|int
name|current_hash
decl_stmt|;
comment|/* Current element in current hash chain.  */
name|CGEN_KEYWORD_ENTRY
modifier|*
name|current_entry
decl_stmt|;
block|}
name|CGEN_KEYWORD_SEARCH
typedef|;
end_typedef

begin_comment
comment|/* Lookup a keyword from its name.  */
end_comment

begin_decl_stmt
specifier|const
name|CGEN_KEYWORD_ENTRY
modifier|*
name|cgen_keyword_lookup_name
name|PARAMS
argument_list|(
operator|(
name|CGEN_KEYWORD
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lookup a keyword from its value.  */
end_comment

begin_decl_stmt
specifier|const
name|CGEN_KEYWORD_ENTRY
modifier|*
name|cgen_keyword_lookup_value
name|PARAMS
argument_list|(
operator|(
name|CGEN_KEYWORD
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a keyword.  */
end_comment

begin_decl_stmt
name|void
name|cgen_keyword_add
name|PARAMS
argument_list|(
operator|(
name|CGEN_KEYWORD
operator|*
operator|,
name|CGEN_KEYWORD_ENTRY
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keyword searching.    This can be used to retrieve every keyword, or a subset.  */
end_comment

begin_decl_stmt
name|CGEN_KEYWORD_SEARCH
name|cgen_keyword_search_init
name|PARAMS
argument_list|(
operator|(
name|CGEN_KEYWORD
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CGEN_KEYWORD_ENTRY
modifier|*
name|cgen_keyword_search_next
name|PARAMS
argument_list|(
operator|(
name|CGEN_KEYWORD_SEARCH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Operand value support routines.  */
end_comment

begin_comment
comment|/* FIXME: some of the long's here will need to be bfd_vma or some such.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_parse_keyword
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|CGEN_KEYWORD
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_parse_signed_integer
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_parse_unsigned_integer
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|unsigned
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_parse_address
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|cgen_parse_operand_result
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_validate_signed_integer
name|PARAMS
argument_list|(
operator|(
name|long
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_validate_unsigned_integer
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Operand modes.  */
end_comment

begin_comment
comment|/* ??? This duplicates the values in arch.h.  Revisit.    These however need the CGEN_ prefix [as does everything in this file].  */
end_comment

begin_comment
comment|/* ??? Targets may need to add their own modes so we may wish to move this    to<arch>-opc.h, or add a hook.  */
end_comment

begin_enum
enum|enum
name|cgen_mode
block|{
name|CGEN_MODE_VOID
block|,
comment|/* FIXME: rename simulator's VM to VOID */
name|CGEN_MODE_BI
block|,
name|CGEN_MODE_QI
block|,
name|CGEN_MODE_HI
block|,
name|CGEN_MODE_SI
block|,
name|CGEN_MODE_DI
block|,
name|CGEN_MODE_UBI
block|,
name|CGEN_MODE_UQI
block|,
name|CGEN_MODE_UHI
block|,
name|CGEN_MODE_USI
block|,
name|CGEN_MODE_UDI
block|,
name|CGEN_MODE_SF
block|,
name|CGEN_MODE_DF
block|,
name|CGEN_MODE_XF
block|,
name|CGEN_MODE_TF
block|,
name|CGEN_MODE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* FIXME: Until simulator is updated.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_MODE_VM
value|CGEN_MODE_VOID
end_define

begin_escape
end_escape

begin_comment
comment|/* This struct defines each entry in the operand table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_operand
block|{
comment|/* Name as it appears in the syntax string.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The hardware element associated with this operand.  */
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|hw
decl_stmt|;
comment|/* FIXME: We don't yet record ifield definitions, which we should.      When we do it might make sense to delete start/length (since they will      be duplicated in the ifield's definition) and replace them with a      pointer to the ifield entry.  Note that as more complicated situations      need to be handled, going more and more with an OOP paradigm will help      keep the complication under control.  Of course, this was the goal from      the start, but getting there in one step was too much too soon.  */
comment|/* Bit position (msb of first byte = bit 0).      This is just a hint, and may be unused in more complex operands.      May be unused for a modifier.  */
name|unsigned
name|char
name|start
decl_stmt|;
comment|/* The number of bits in the operand.      This is just a hint, and may be unused in more complex operands.      May be unused for a modifier.  */
name|unsigned
name|char
name|length
decl_stmt|;
if|#
directive|if
literal|0
comment|/* ??? Interesting idea but relocs tend to get too complicated, 	 and ABI dependent, for simple table lookups to work.  */
comment|/* Ideally this would be the internal (external?) reloc type.  */
block|int reloc_type;
endif|#
directive|endif
comment|/* Attributes.      This should, but technically needn't, appear last.  It is a variable sized      array in that one architecture may have 1 nonbool attribute and another      may have more.  Having this last means the non-architecture specific code      needn't care, now or tomorrow.  */
ifndef|#
directive|ifndef
name|CGEN_OPERAND_NBOOL_ATTRS
define|#
directive|define
name|CGEN_OPERAND_NBOOL_ATTRS
value|1
endif|#
directive|endif
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_OPERAND_NBOOL_ATTRS
argument_list|)
name|attrs
expr_stmt|;
define|#
directive|define
name|CGEN_OPERAND_ATTRS
parameter_list|(
name|operand
parameter_list|)
value|(&(operand)->attrs)
block|}
name|CGEN_OPERAND
typedef|;
end_typedef

begin_comment
comment|/* Return value of attribute ATTR in OPERAND.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_OPERAND_ATTR
parameter_list|(
name|operand
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE (operand, CGEN_OPERAND_ATTRS (operand), attr)
end_define

begin_comment
comment|/* The operand table is currently a very static entity.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_OPERAND
name|CGEN_SYM
argument_list|(
name|operand_table
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_enum_decl
enum_decl|enum
name|cgen_operand_type
enum_decl|;
end_enum_decl

begin_define
define|#
directive|define
name|CGEN_OPERAND_INDEX
parameter_list|(
name|operand
parameter_list|)
value|((int) ((operand) - CGEN_SYM (operand_table)))
end_define

begin_comment
comment|/* FIXME: Rename, cpu-opc.h defines this as the typedef of the enum.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_OPERAND_TYPE
parameter_list|(
name|operand
parameter_list|)
value|((enum cgen_operand_type) CGEN_OPERAND_INDEX (operand))
end_define

begin_define
define|#
directive|define
name|CGEN_OPERAND_ENTRY
parameter_list|(
name|n
parameter_list|)
value|(& CGEN_SYM (operand_table) [n])
end_define

begin_comment
comment|/* Types of parse/insert/extract/print cover-fn handlers.  */
end_comment

begin_comment
comment|/* FIXME: move opindex first to match caller.  */
end_comment

begin_comment
comment|/* FIXME: also need types of insert/extract/print fns.  */
end_comment

begin_comment
comment|/* FIXME: not currently used as type of 3rd arg varies.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
operator|*
operator|(
name|CGEN_PARSE_OPERAND_FN
operator|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|long
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Instruction operand instances.     For each instruction, a list of the hardware elements that are read and    written are recorded.  */
end_comment

begin_comment
comment|/* The type of the instance.  */
end_comment

begin_enum
enum|enum
name|cgen_operand_instance_type
block|{
comment|/* End of table marker.  */
name|CGEN_OPERAND_INSTANCE_END
init|=
literal|0
block|,
name|CGEN_OPERAND_INSTANCE_INPUT
block|,
name|CGEN_OPERAND_INSTANCE_OUTPUT
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The type of this operand.  */
name|enum
name|cgen_operand_instance_type
name|type
decl_stmt|;
define|#
directive|define
name|CGEN_OPERAND_INSTANCE_TYPE
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->type)
comment|/* The hardware element referenced.  */
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|hw
decl_stmt|;
define|#
directive|define
name|CGEN_OPERAND_INSTANCE_HW
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->hw)
comment|/* The mode in which the operand is being used.  */
name|enum
name|cgen_mode
name|mode
decl_stmt|;
define|#
directive|define
name|CGEN_OPERAND_INSTANCE_MODE
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->mode)
comment|/* The operand table entry or NULL if there is none (i.e. an explicit      hardware reference).  */
specifier|const
name|CGEN_OPERAND
modifier|*
name|operand
decl_stmt|;
define|#
directive|define
name|CGEN_OPERAND_INSTANCE_OPERAND
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->operand)
comment|/* If `operand' is NULL, the index (e.g. into array of registers).  */
name|int
name|index
decl_stmt|;
define|#
directive|define
name|CGEN_OPERAND_INSTANCE_INDEX
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->index)
block|}
name|CGEN_OPERAND_INSTANCE
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Syntax string.     Each insn format and subexpression has one of these.     The syntax "string" consists of characters (n> 0&& n< 128), and operand    values (n>= 128), and is terminated by 0.  Operand values are 128 + index    into the operand table.  The operand table doesn't exist in C, per se, as    the data is recorded in the parse/insert/extract/print switch statements. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_MAX_SYNTAX_BYTES
end_ifndef

begin_define
define|#
directive|define
name|CGEN_MAX_SYNTAX_BYTES
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|syntax
index|[
name|CGEN_MAX_SYNTAX_BYTES
index|]
decl_stmt|;
block|}
name|CGEN_SYNTAX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CGEN_SYNTAX_STRING
parameter_list|(
name|syn
parameter_list|)
value|(syn->syntax)
end_define

begin_define
define|#
directive|define
name|CGEN_SYNTAX_CHAR_P
parameter_list|(
name|c
parameter_list|)
value|((c)< 128)
end_define

begin_define
define|#
directive|define
name|CGEN_SYNTAX_CHAR
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|CGEN_SYNTAX_FIELD
parameter_list|(
name|c
parameter_list|)
value|((c) - 128)
end_define

begin_define
define|#
directive|define
name|CGEN_SYNTAX_MAKE_FIELD
parameter_list|(
name|c
parameter_list|)
value|((c) + 128)
end_define

begin_comment
comment|/* ??? I can't currently think of any case where the mnemonic doesn't come    first [and if one ever doesn't building the hash tables will be tricky].    However, we treat mnemonics as just another operand of the instruction.    A value of 1 means "this is where the mnemonic appears".  1 isn't    special other than it's a non-printable ASCII char.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_SYNTAX_MNEMONIC
value|1
end_define

begin_define
define|#
directive|define
name|CGEN_SYNTAX_MNEMONIC_P
parameter_list|(
name|ch
parameter_list|)
value|((ch) == CGEN_SYNTAX_MNEMONIC)
end_define

begin_escape
end_escape

begin_comment
comment|/* Instruction formats.     Instructions are grouped by format.  Associated with an instruction is its    format.  Each opcode table entry contains a format table entry.    ??? There is usually very few formats compared with the number of insns,    so one can reduce the size of the opcode table by recording the format table    as a separate entity.  Given that we currently don't, format table entries    are also distinguished by their operands.  This increases the size of the    table, but reduces the number of tables.  It's all minutiae anyway so it    doesn't really matter [at this point in time].     ??? Support for variable length ISA's is wip.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Length that MASK and VALUE have been calculated to      [VALUE is recorded elsewhere].      Normally it is CGEN_BASE_INSN_BITSIZE.  On [V]LIW architectures where      the base insn size may be larger than the size of an insn, this field is      less than CGEN_BASE_INSN_BITSIZE.  */
name|unsigned
name|char
name|mask_length
decl_stmt|;
comment|/* Total length of instruction, in bits.  */
name|unsigned
name|char
name|length
decl_stmt|;
comment|/* Mask to apply to the first MASK_LENGTH bits.      Each insn's value is stored with the insn.      The first step in recognizing an insn for disassembly is      (opcode& mask) == value.  */
name|unsigned
name|int
name|mask
decl_stmt|;
block|}
name|CGEN_FORMAT
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* This struct defines each entry in the instruction table.  */
end_comment

begin_struct
struct|struct
name|cgen_insn
block|{
comment|/* ??? Further table size reductions can be had by moving this element      either to the format table or to a separate table of its own.  Not      sure this is desirable yet.  */
name|struct
name|cgen_base
name|base
decl_stmt|;
comment|/* Given a pointer to a cgen_insn struct, return a pointer to `base'.  */
define|#
directive|define
name|CGEN_INSN_BASE
parameter_list|(
name|insn
parameter_list|)
value|(&(insn)->base)
comment|/* Name of entry (that distinguishes it from all other entries).      This is used, for example, in simulator profiling results.  */
comment|/* ??? If mnemonics have operands, try to print full mnemonic.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_NAME
parameter_list|(
name|insn
parameter_list|)
value|((insn)->name)
comment|/* Mnemonic.  This is used when parsing and printing the insn.      In the case of insns that have operands on the mnemonics, this is      only the constant part.  E.g. for conditional execution of an `add' insn,      where the full mnemonic is addeq, addne, etc., this is only "add".  */
specifier|const
name|char
modifier|*
name|mnemonic
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_MNEMONIC
parameter_list|(
name|insn
parameter_list|)
value|((insn)->mnemonic)
comment|/* Syntax string.  */
specifier|const
name|CGEN_SYNTAX
name|syntax
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_SYNTAX
parameter_list|(
name|insn
parameter_list|)
value|(& (insn)->syntax)
comment|/* Format entry.  */
specifier|const
name|CGEN_FORMAT
name|format
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_MASK_BITSIZE
parameter_list|(
name|insn
parameter_list|)
value|((insn)->format.mask_length)
define|#
directive|define
name|CGEN_INSN_BITSIZE
parameter_list|(
name|insn
parameter_list|)
value|((insn)->format.length)
comment|/* Instruction opcode value.  */
name|unsigned
name|int
name|value
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_VALUE
parameter_list|(
name|insn
parameter_list|)
value|((insn)->value)
define|#
directive|define
name|CGEN_INSN_MASK
parameter_list|(
name|insn
parameter_list|)
value|((insn)->format.mask)
comment|/* Pointer to NULL entry terminated table of operands used,      or NULL if none.  */
specifier|const
name|CGEN_OPERAND_INSTANCE
modifier|*
name|operands
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_OPERANDS
parameter_list|(
name|insn
parameter_list|)
value|((insn)->operands)
comment|/* Attributes.      This must appear last.  It is a variable sized array in that one      architecture may have 1 nonbool attribute and another may have more.      Having this last means the non-architecture specific code needn't      care.  */
ifndef|#
directive|ifndef
name|CGEN_INSN_NBOOL_ATTRS
define|#
directive|define
name|CGEN_INSN_NBOOL_ATTRS
value|1
endif|#
directive|endif
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_INSN_NBOOL_ATTRS
argument_list|)
name|attrs
expr_stmt|;
define|#
directive|define
name|CGEN_INSN_ATTRS
parameter_list|(
name|insn
parameter_list|)
value|(&(insn)->attrs)
comment|/* Return value of attribute ATTR in INSN.  */
define|#
directive|define
name|CGEN_INSN_ATTR
parameter_list|(
name|insn
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE (insn, CGEN_INSN_ATTRS (insn), attr)
block|}
struct|;
end_struct

begin_comment
comment|/* Instruction lists.    This is used for adding new entries and for creating the hash lists.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_insn_list
block|{
name|struct
name|cgen_insn_list
modifier|*
name|next
decl_stmt|;
specifier|const
name|CGEN_INSN
modifier|*
name|insn
decl_stmt|;
block|}
name|CGEN_INSN_LIST
typedef|;
end_typedef

begin_comment
comment|/* The table of instructions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Pointer to initial [compiled in] entries.  */
specifier|const
name|CGEN_INSN
modifier|*
name|init_entries
decl_stmt|;
comment|/* Size of an entry (since the attribute member is variable sized).  */
name|unsigned
name|int
name|entry_size
decl_stmt|;
comment|/* Number of entries in `init_entries', including trailing NULL entry.  */
name|unsigned
name|int
name|num_init_entries
decl_stmt|;
comment|/* Values added at runtime.  */
name|CGEN_INSN_LIST
modifier|*
name|new_entries
decl_stmt|;
comment|/* Assembler hash function.  */
name|unsigned
name|int
argument_list|(
operator|*
name|asm_hash
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Number of entries in assembler hash table.  */
name|unsigned
name|int
name|asm_hash_table_size
decl_stmt|;
comment|/* Disassembler hash function.  */
name|unsigned
name|int
argument_list|(
operator|*
name|dis_hash
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
comment|/* Number of entries in disassembler hash table.  */
name|unsigned
name|int
name|dis_hash_table_size
decl_stmt|;
block|}
name|CGEN_INSN_TABLE
typedef|;
end_typedef

begin_comment
comment|/* ??? This is currently used by the simulator.    We want this to be fast and the simulator currently doesn't handle    runtime added instructions so this is ok.  An alternative would be to    store the index in the table.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_INSN
name|CGEN_SYM
argument_list|(
name|insn_table_entries
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_INSN_INDEX
parameter_list|(
name|insn
parameter_list|)
value|((int) ((insn) - CGEN_SYM (insn_table_entries)))
end_define

begin_define
define|#
directive|define
name|CGEN_INSN_ENTRY
parameter_list|(
name|n
parameter_list|)
value|(& CGEN_SYM (insn_table_entries) [n])
end_define

begin_comment
comment|/* Return number of instructions.  This includes any added at runtime.  */
end_comment

begin_decl_stmt
name|int
name|cgen_insn_count
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The assembler insn table is hashed based on some function of the mnemonic    (the actually hashing done is up to the target, but we provide a few    examples like the first letter or a function of the entire mnemonic).    The index of each entry is the index of the corresponding table entry.    The value of each entry is the index of the next entry, with a 0    terminating (thus the first entry is reserved).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_ASM_HASH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CGEN_MNEMONIC_OPERANDS
end_ifdef

begin_define
define|#
directive|define
name|CGEN_ASM_HASH_SIZE
value|127
end_define

begin_define
define|#
directive|define
name|CGEN_ASM_HASH
parameter_list|(
name|string
parameter_list|)
value|(*(unsigned char *) (string) % CGEN_ASM_HASH_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CGEN_ASM_HASH_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|CGEN_ASM_HASH
parameter_list|(
name|string
parameter_list|)
value|(*(unsigned char *) (string) % CGEN_ASM_HASH_SIZE)
end_define

begin_comment
comment|/*FIXME*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|unsigned
name|int
name|CGEN_SYM
parameter_list|(
name|asm_hash_insn
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const char *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|CGEN_INSN_LIST
modifier|*
name|cgen_asm_lookup_insn
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

begin_define
define|#
directive|define
name|CGEN_ASM_LOOKUP_INSN
parameter_list|(
name|insn
parameter_list|)
value|cgen_asm_lookup_insn (insn)
end_define

begin_define
define|#
directive|define
name|CGEN_ASM_NEXT_INSN
parameter_list|(
name|insn
parameter_list|)
value|((insn)->next)
end_define

begin_comment
comment|/* The disassembler insn table is hashed based on some function of machine    instruction (the actually hashing done is up to the target).  */
end_comment

begin_comment
comment|/* It doesn't make much sense to provide a default here,    but while this is under development we do.    BUFFER is a pointer to the bytes of the insn.    INSN is the first CGEN_BASE_INSN_SIZE bytes as an int in host order.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_DIS_HASH
end_ifndef

begin_define
define|#
directive|define
name|CGEN_DIS_HASH_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|CGEN_DIS_HASH
parameter_list|(
name|buffer
parameter_list|,
name|insn
parameter_list|)
value|(*(unsigned char *) (buffer))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|unsigned
name|int
name|CGEN_SYM
parameter_list|(
name|dis_hash_insn
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const char *
operator|,
function_decl|unsigned long
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|CGEN_INSN_LIST
modifier|*
name|cgen_dis_lookup_insn
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_DIS_LOOKUP_INSN
parameter_list|(
name|buf
parameter_list|,
name|insn
parameter_list|)
value|cgen_dis_lookup_insn (buf, insn)
end_define

begin_define
define|#
directive|define
name|CGEN_DIS_NEXT_INSN
parameter_list|(
name|insn
parameter_list|)
value|((insn)->next)
end_define

begin_escape
end_escape

begin_comment
comment|/* Top level structures and functions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|hw_list
decl_stmt|;
comment|/*CGEN_OPERAND_TABLE * operand_table; - FIXME:wip */
name|CGEN_INSN_TABLE
modifier|*
name|insn_table
decl_stmt|;
block|}
name|CGEN_OPCODE_DATA
typedef|;
end_typedef

begin_comment
comment|/* Each CPU has one of these.  */
end_comment

begin_function_decl
specifier|extern
name|CGEN_OPCODE_DATA
name|CGEN_SYM
parameter_list|(
name|opcode_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global state access macros.    Some of these are tucked away and accessed with cover fns.    Simpler things like the current machine and endian are not.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cgen_current_machine
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_CURRENT_MACHINE
value|cgen_current_machine
end_define

begin_decl_stmt
specifier|extern
name|enum
name|cgen_endian
name|cgen_current_endian
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CGEN_CURRENT_ENDIAN
value|cgen_current_endian
end_define

begin_comment
comment|/* Prototypes of major functions.  */
end_comment

begin_comment
comment|/* Set the current cpu (+ mach number, endian, etc.).  */
end_comment

begin_decl_stmt
name|void
name|cgen_set_cpu
name|PARAMS
argument_list|(
operator|(
name|CGEN_OPCODE_DATA
operator|*
operator|,
name|int
operator|,
expr|enum
name|cgen_endian
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the assembler, disassembler.  */
end_comment

begin_decl_stmt
name|void
name|cgen_asm_init
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
name|cgen_dis_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `init_tables' must be called before `xxx_supported'.  */
end_comment

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_tables
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_asm
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|enum cgen_endian
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_dis
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|enum cgen_endian
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_parse
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(void
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_print
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(void
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_insert
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(void
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|CGEN_SYM
parameter_list|(
name|init_extract
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(void
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* FIXME: This prototype is wrong ifndef CGEN_INT_INSN.    Furthermore, ifdef CGEN_INT_INSN, the insn is created in    target byte order (in which case why use int's at all).    Perhaps replace cgen_insn_t * with char *?  */
end_comment

begin_function_decl
specifier|const
name|struct
name|cgen_insn
modifier|*
name|CGEN_SYM
parameter_list|(
name|assemble_insn
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const char *
operator|,
function_decl|CGEN_FIELDS *
operator|,
function_decl|cgen_insn_t *
operator|,
function_decl|char **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* old */
end_comment

begin_endif
unit|int CGEN_SYM (insn_supported) PARAMS ((const struct cgen_insn *)); int CGEN_SYM (opval_supported) PARAMS ((const struct cgen_opval *));
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
specifier|const
name|CGEN_KEYWORD
name|CGEN_SYM
parameter_list|(
name|operand_mach
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CGEN_SYM
parameter_list|(
name|get_mach
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const char *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|CGEN_INSN
modifier|*
name|CGEN_SYM
parameter_list|(
name|get_insn_operands
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const CGEN_INSN *
operator|,
function_decl|cgen_insn_t
operator|,
function_decl|int
operator|,
function_decl|int *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|CGEN_INSN
modifier|*
name|CGEN_SYM
parameter_list|(
name|lookup_insn
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(const CGEN_INSN *
operator|,
function_decl|cgen_insn_t
operator|,
function_decl|int
operator|,
function_decl|CGEN_FIELDS *
operator|,
function_decl|int
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|CGEN_INLINE
name|void
name|CGEN_SYM
parameter_list|(
name|put_operand
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|const long *
operator|,
function_decl|CGEN_FIELDS *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|CGEN_INLINE
name|long
name|CGEN_SYM
parameter_list|(
name|get_operand
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|const CGEN_FIELDS *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|CGEN_SYM
parameter_list|(
name|parse_operand
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|const char **
operator|,
function_decl|CGEN_FIELDS *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|CGEN_SYM
parameter_list|(
name|insert_operand
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(int
operator|,
function_decl|CGEN_FIELDS *
operator|,
function_decl|char *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Default insn parser, printer.  */
end_comment

begin_function_decl
specifier|extern
name|cgen_parse_fn
name|CGEN_SYM
parameter_list|(
name|parse_insn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cgen_insert_fn
name|CGEN_SYM
parameter_list|(
name|insert_insn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cgen_extract_fn
name|CGEN_SYM
parameter_list|(
name|extract_insn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cgen_print_fn
name|CGEN_SYM
parameter_list|(
name|print_insn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read in a cpu description file.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cgen_read_cpu_file
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CGEN_H */
end_comment

end_unit

