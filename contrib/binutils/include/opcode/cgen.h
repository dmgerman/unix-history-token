begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for targets using CGEN: Cpu tools GENerator.  Copyright 1996, 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GDB, the GNU debugger, and the GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* ??? This file requires bfd.h but only to get bfd_vma.    Seems like an awful lot to require just to get such a fundamental type.    Perhaps the definition of bfd_vma can be moved outside of bfd.h.    Or perhaps one could duplicate its definition in another file.    Until such time, this file conditionally compiles definitions that require    bfd_vma using BFD_VERSION_DATE.  */
end_comment

begin_comment
comment|/* Enums must be defined before they can be used.    Allow them to be used in struct definitions, even though the enum must    be defined elsewhere.    If CGEN_ARCH isn't defined, this file is being included by something other    than<arch>-desc.h.  */
end_comment

begin_comment
comment|/* Prepend the arch name, defined in<arch>-desc.h, and _cgen_ to symbol S.    The lack of spaces in the arg list is important for non-stdc systems.    This file is included by<arch>-desc.h.    It can be included independently of<arch>-desc.h, in which case the arch    dependent portions will be declared as "unknown_cgen_foo".  */
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
comment|/* The assembler syntax is made up of expressions (duh...).    At the lowest level the values are mnemonics, register names, numbers, etc.    Above that are subexpressions, if any (an example might be the    "effective address" in m68k cpus).  Subexpressions are wip.    At the second highest level are the insns themselves.  Above that are    pseudo-insns, synthetic insns, and macros, if any.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Lots of cpu's have a fixed insn size, or one which rarely changes,    and it's generally easier to handle these by treating the insn as an    integer type, rather than an array of characters.  So we allow targets    to control this.  When an integer type the value is in host byte order,    when an array of characters the value is in target byte order.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|CGEN_INSN_INT
typedef|;
end_typedef

begin_if
if|#
directive|if
name|CGEN_INT_INSN_P
end_if

begin_typedef
typedef|typedef
name|CGEN_INSN_INT
name|CGEN_INSN_BYTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CGEN_INSN_INT
modifier|*
name|CGEN_INSN_BYTES_PTR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|CGEN_INSN_BYTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|CGEN_INSN_BYTES_PTR
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
value|__inline__
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
comment|/* Opaque pointer version for use by external world.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cgen_cpu_desc
modifier|*
name|CGEN_CPU_DESC
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Attributes.    Attributes are used to describe various random things associated with    an object (ifield, hardware, operand, insn, whatever) and are specified    as name/value pairs.    Integer attributes computed at compile time are currently all that's    supported, though adding string attributes and run-time computation is    straightforward.  Integer attribute values are always host int's    (signed or unsigned).  For portability, this means 32 bits.    Integer attributes are further categorized as boolean, bitset, integer,    and enum types.  Boolean attributes appear frequently enough that they're    recorded in one host int.  This limits the maximum number of boolean    attributes to 32, though that's a *lot* of attributes.  */
end_comment

begin_comment
comment|/* Type of attribute values.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|CGEN_ATTR_VALUE_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Struct to record attribute information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Boolean attributes.  */
name|unsigned
name|int
name|bool
decl_stmt|;
comment|/* Non-boolean integer attributes.  */
name|CGEN_ATTR_VALUE_TYPE
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
comment|/* Define a structure member for attributes with N non-boolean entries.    There is no maximum number of non-boolean attributes.    There is a maximum of 32 boolean attributes (since they are all recorded    in one host int).  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_TYPE
parameter_list|(
name|n
parameter_list|)
define|\
value|struct { unsigned int bool; \ 	 CGEN_ATTR_VALUE_TYPE nonbool[(n) ? (n) : 1]; }
end_define

begin_comment
comment|/* Return the boolean attributes.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_BOOLS
parameter_list|(
name|a
parameter_list|)
value|((a)->bool)
end_define

begin_comment
comment|/* Non-boolean attribute numbers are offset by this much.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_ATTR_NBOOL_OFFSET
value|32
end_define

begin_comment
comment|/* Given a boolean attribute number, return its mask.  */
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
value|((CGEN_ATTR_MASK (attr)& (attrs)) != 0)
end_define

begin_comment
comment|/* Return value of attribute ATTR in ATTR_TABLE for OBJ.    OBJ is a pointer to the entity that has the attributes    (??? not used at present but is reserved for future purposes - eventually    the goal is to allow recording attributes in source form and computing    them lazily at runtime, not sure of the details yet).  */
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
value|((unsigned int) (attr)< CGEN_ATTR_NBOOL_OFFSET \  ? ((CGEN_ATTR_BOOLS (attr_table)& CGEN_ATTR_MASK (attr)) != 0) \  : ((attr_table)->nonbool[(attr) - CGEN_ATTR_NBOOL_OFFSET]))
end_define

begin_comment
comment|/* Attribute name/value tables.    These are used to assist parsing of descriptions at run-time.  */
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
name|CGEN_ATTR_VALUE_TYPE
name|value
decl_stmt|;
block|}
name|CGEN_ATTR_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* For each domain (ifld,hw,operand,insn), list of attributes.  */
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
specifier|const
name|CGEN_ATTR_ENTRY
modifier|*
name|dfault
decl_stmt|;
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
comment|/* Instruction set variants.  */
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
comment|/* Default instruction size (in bits).      This is used by the assembler when it encounters an unknown insn.  */
name|unsigned
name|int
name|default_insn_bitsize
decl_stmt|;
comment|/* Base instruction size (in bits).      For non-LIW cpus this is generally the length of the smallest insn.      For LIW cpus its wip (work-in-progress).  For the m32r its 32.  */
name|unsigned
name|int
name|base_insn_bitsize
decl_stmt|;
comment|/* Minimum/maximum instruction size (in bits).  */
name|unsigned
name|int
name|min_insn_bitsize
decl_stmt|;
name|unsigned
name|int
name|max_insn_bitsize
decl_stmt|;
block|}
name|CGEN_ISA
typedef|;
end_typedef

begin_comment
comment|/* Machine variants.  */
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
comment|/* The argument to bfd_arch_info->scan.  */
specifier|const
name|char
modifier|*
name|bfd_name
decl_stmt|;
comment|/* one of enum mach_attr */
name|int
name|num
decl_stmt|;
comment|/* parameter from mach->cpu */
name|unsigned
name|int
name|insn_chunk_bitsize
decl_stmt|;
block|}
name|CGEN_MACH
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
comment|/* Extraction support for variable length insn sets.  */
end_comment

begin_comment
comment|/* When disassembling we don't know the number of bytes to read at the start.    So the first CGEN_BASE_INSN_SIZE bytes are read at the start and the rest    are read when needed.  This struct controls this.  It is basically the    disassemble_info stuff, except that we provide a cache for values already    read (since bytes can typically be read several times to fetch multiple    operands that may be in them), and that extraction of fields is needed    in contexts other than disassembly.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* A pointer to the disassemble_info struct.      We don't require dis-asm.h so we use PTR for the type here.      If NULL, BYTES is full of valid data (VALID == -1).  */
name|PTR
name|dis_info
decl_stmt|;
comment|/* Points to a working buffer of sufficient size.  */
name|unsigned
name|char
modifier|*
name|insn_bytes
decl_stmt|;
comment|/* Mask of bytes that are valid in INSN_BYTES.  */
name|unsigned
name|int
name|valid
decl_stmt|;
block|}
name|CGEN_EXTRACT_INFO
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Associated with each insn or expression is a set of "handlers" for    performing operations like parsing, printing, etc.  These require a bfd_vma    value to be passed around but we don't want all applications to need bfd.h.    So this stuff is only provided if bfd.h has been included.  */
end_comment

begin_comment
comment|/* Parse handler.    CD is a cpu table descriptor.    INSN is a pointer to a struct describing the insn being parsed.    STRP is a pointer to a pointer to the text being parsed.    FIELDS is a pointer to a cgen_fields struct in which the results are placed.    If the expression is successfully parsed, *STRP is updated.    If not it is left alone.    The result is NULL if success or an error message.  */
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
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
specifier|const
name|char
operator|*
operator|*
name|strp_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Insert handler.    CD is a cpu table descriptor.    INSN is a pointer to a struct describing the insn being parsed.    FIELDS is a pointer to a cgen_fields struct from which the values    are fetched.    INSNP is a pointer to a buffer in which to place the insn.    PC is the pc value of the insn.    The result is an error message or NULL if success.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
end_ifdef

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
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|CGEN_INSN_BYTES_PTR
name|insnp_
operator|,
name|bfd_vma
name|pc_
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
specifier|const
name|char
modifier|*
function_decl|(
name|cgen_insert_fn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract handler.    CD is a cpu table descriptor.    INSN is a pointer to a struct describing the insn being parsed.    The second argument is a pointer to a struct controlling extraction    (only used for variable length insns).    EX_INFO is a pointer to a struct for controlling reading of further    bytes for the insn.    BASE_INSN is the first CGEN_BASE_INSN_SIZE bytes (host order).    FIELDS is a pointer to a cgen_fields struct in which the results are placed.    PC is the pc value of the insn.    The result is the length of the insn in bits or zero if not recognized.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
end_ifdef

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|cgen_extract_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
name|CGEN_EXTRACT_INFO
operator|*
name|ex_info_
operator|,
name|CGEN_INSN_INT
name|base_insn_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|bfd_vma
name|pc_
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
name|int
function_decl|(
name|cgen_extract_fn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Print handler.    CD is a cpu table descriptor.    INFO is a pointer to the disassembly info.    Eg: disassemble_info.  It's defined as `PTR' so this file can be included    without dis-asm.h.    INSN is a pointer to a struct describing the insn being printed.    FIELDS is a pointer to a cgen_fields struct.    PC is the pc value of the insn.    LEN is the length of the insn, in bits.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
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
name|CGEN_CPU_DESC
operator|,
name|PTR
name|info_
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|bfd_vma
name|pc_
operator|,
name|int
name|len_
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
comment|/* Parse/insert/extract/print handlers.     Indices into the handler tables.    We could use pointers here instead, but 90% of them are generally identical    and that's a lot of redundant data.  Making these unsigned char indices    into tables of pointers saves a bit of space.    Using indices also keeps assembler code out of the disassembler and    vice versa.  */
end_comment

begin_struct
struct|struct
name|cgen_opcode_handler
block|{
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
comment|/* Assembler interface.     The interface to the assembler is intended to be clean in the sense that    libopcodes.a is a standalone entity and could be used with any assembler.    Not that one would necessarily want to do that but rather that it helps    keep a clean interface.  The interface will obviously be slanted towards    GAS, but at least it's a start.    ??? Note that one possible user of the assembler besides GAS is GDB.     Parsing is controlled by the assembler which calls    CGEN_SYM (assemble_insn).  If it can parse and build the entire insn    it doesn't call back to the assembler.  If it needs/wants to call back    to the assembler, cgen_parse_operand_fn is called which can either     - return a number to be inserted in the insn    - return a "register" value to be inserted      (the register might not be a register per pe)    - queue the argument and return a marker saying the expression has been      queued (eg: a fix-up)    - return an error message indicating the expression wasn't recognizable     The result is an error message or NULL for success.    The parsed value is stored in the bfd_vma *.  */
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
comment|/* Values for indicating what was parsed.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
end_ifdef

begin_comment
comment|/* Don't require bfd.h unnecessarily.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
operator|*
operator|(
name|cgen_parse_operand_fn
operator|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
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
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|cgen_parse_operand_fn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the cgen_parse_operand_fn callback.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cgen_set_parse_operand_fn
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|cgen_parse_operand_fn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called before trying to match a table entry with the insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cgen_init_parse_operand
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
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
name|CGEN_ASM_NONE
block|,
name|CGEN_ASM_KEYWORD
block|,
name|CGEN_ASM_MAX
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_ARCH
end_ifndef

begin_enum
enum|enum
name|cgen_hw_type
block|{
name|CGEN_HW_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* List of hardware elements.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|cgen_hw_type
name|type
decl_stmt|;
comment|/* There is currently no example where both index specs and value specs      are required, so for now both are clumped under "asm_data".  */
name|enum
name|cgen_asm_type
name|asm_type
decl_stmt|;
name|PTR
name|asm_data
decl_stmt|;
ifndef|#
directive|ifndef
name|CGEN_HW_NBOOL_ATTRS
define|#
directive|define
name|CGEN_HW_NBOOL_ATTRS
value|1
endif|#
directive|endif
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_HW_NBOOL_ATTRS
argument_list|)
name|attrs
expr_stmt|;
define|#
directive|define
name|CGEN_HW_ATTRS
parameter_list|(
name|hw
parameter_list|)
value|(&(hw)->attrs)
block|}
name|CGEN_HW_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Return value of attribute ATTR in HW.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_HW_ATTR_VALUE
parameter_list|(
name|hw
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE ((hw), CGEN_HW_ATTRS (hw), (attr))
end_define

begin_comment
comment|/* Table of hardware elements for selected mach, computed at runtime.    enum cgen_hw_type is an index into this table (specifically `entries').  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Pointer to null terminated table of all compiled in entries.  */
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|init_entries
decl_stmt|;
name|unsigned
name|int
name|entry_size
decl_stmt|;
comment|/* since the attribute member is variable sized */
comment|/* Array of all entries, initial and run-time added.  */
specifier|const
name|CGEN_HW_ENTRY
modifier|*
modifier|*
name|entries
decl_stmt|;
comment|/* Number of elements in `entries'.  */
name|unsigned
name|int
name|num_entries
decl_stmt|;
comment|/* For now, xrealloc is called each time a new entry is added at runtime.      ??? May wish to keep track of some slop to reduce the number of calls to      xrealloc, except that there's unlikely to be many and not expected to be      in speed critical code.  */
block|}
name|CGEN_HW_TABLE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|cgen_hw_lookup_by_name
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_HW_ENTRY
modifier|*
name|cgen_hw_lookup_by_num
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|unsigned
name|int
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
comment|/* Attributes.      This should, but technically needn't, appear last.  It is a variable sized      array in that one architecture may have 1 nonbool attribute and another      may have more.  Having this last means the non-architecture specific code      needn't care.  The goal is to eventually record      attributes in their raw form, evaluate them at run-time, and cache the      values, so this worry will go away anyway.  */
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
comment|/* ??? Putting these here means compiled in entries can't be const.      Not a really big deal, but something to consider.  */
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
comment|/* Top level struct for describing a set of related keywords    (e.g. register names).     This struct supports run-time entry of new values, and hashed lookups.  */
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
comment|/* String containing non-alphanumeric characters used      in keywords.        At present, the highest number of entries used is 1.  */
name|char
name|nonalpha_chars
index|[
literal|8
index|]
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_parse_keyword
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
end_ifdef

begin_comment
comment|/* Don't require bfd.h unnecessarily.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_parse_signed_integer
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
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
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_parse_unsigned_integer
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
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
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_parse_address
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
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

begin_decl_stmt
specifier|extern
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
specifier|extern
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* ??? rename simulator's VM to VOID? */
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
name|CGEN_MODE_TARGET_MAX
block|,
name|CGEN_MODE_INT
block|,
name|CGEN_MODE_UINT
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
comment|/* Operands.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_ARCH
end_ifndef

begin_enum
enum|enum
name|cgen_operand_type
block|{
name|CGEN_OPERAND_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* "nil" indicator for the operand instance table */
end_comment

begin_define
define|#
directive|define
name|CGEN_OPERAND_NIL
value|CGEN_OPERAND_MAX
end_define

begin_comment
comment|/* A tree of these structs represents the multi-ifield    structure of an operand's hw-index value, if it exists.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cgen_ifld
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|cgen_maybe_multi_ifield
block|{
name|int
name|count
decl_stmt|;
comment|/* 0: indexed by single cgen_ifld (possibly null: dead entry); 		n: indexed by array of more cgen_maybe_multi_ifields.  */
union|union
block|{
name|struct
name|cgen_maybe_multi_ifield
modifier|*
name|multi
decl_stmt|;
name|struct
name|cgen_ifld
modifier|*
name|leaf
decl_stmt|;
block|}
name|val
union|;
block|}
name|CGEN_MAYBE_MULTI_IFLD
typedef|;
end_typedef

begin_comment
comment|/* This struct defines each entry in the operand table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Name as it appears in the syntax string.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Operand type.  */
name|enum
name|cgen_operand_type
name|type
decl_stmt|;
comment|/* The hardware element associated with this operand.  */
name|enum
name|cgen_hw_type
name|hw_type
decl_stmt|;
comment|/* FIXME: We don't yet record ifield definitions, which we should.      When we do it might make sense to delete start/length (since they will      be duplicated in the ifield's definition) and replace them with a      pointer to the ifield entry.  */
comment|/* Bit position.      This is just a hint, and may be unused in more complex operands.      May be unused for a modifier.  */
name|unsigned
name|char
name|start
decl_stmt|;
comment|/* The number of bits in the operand.      This is just a hint, and may be unused in more complex operands.      May be unused for a modifier.  */
name|unsigned
name|char
name|length
decl_stmt|;
comment|/* The (possibly-multi) ifield used as an index for this operand, if it      is indexed by a field at all. This substitutes / extends the start and      length fields above, but unsure at this time whether they are used      anywhere.  */
name|CGEN_MAYBE_MULTI_IFLD
name|index_fields
decl_stmt|;
if|#
directive|if
literal|0
comment|/* ??? Interesting idea but relocs tend to get too complicated, 	 and ABI dependent, for simple table lookups to work.  */
comment|/* Ideally this would be the internal (external?) reloc type.  */
block|int reloc_type;
endif|#
directive|endif
comment|/* Attributes.      This should, but technically needn't, appear last.  It is a variable sized      array in that one architecture may have 1 nonbool attribute and another      may have more.  Having this last means the non-architecture specific code      needn't care, now or tomorrow.  The goal is to eventually record      attributes in their raw form, evaluate them at run-time, and cache the      values, so this worry will go away anyway.  */
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
name|CGEN_OPERAND_ATTR_VALUE
parameter_list|(
name|operand
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE ((operand), CGEN_OPERAND_ATTRS (operand), (attr))
end_define

begin_comment
comment|/* Table of operands for selected mach/isa, computed at runtime.    enum cgen_operand_type is an index into this table (specifically    `entries').  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Pointer to null terminated table of all compiled in entries.  */
specifier|const
name|CGEN_OPERAND
modifier|*
name|init_entries
decl_stmt|;
name|unsigned
name|int
name|entry_size
decl_stmt|;
comment|/* since the attribute member is variable sized */
comment|/* Array of all entries, initial and run-time added.  */
specifier|const
name|CGEN_OPERAND
modifier|*
modifier|*
name|entries
decl_stmt|;
comment|/* Number of elements in `entries'.  */
name|unsigned
name|int
name|num_entries
decl_stmt|;
comment|/* For now, xrealloc is called each time a new entry is added at runtime.      ??? May wish to keep track of some slop to reduce the number of calls to      xrealloc, except that there's unlikely to be many and not expected to be      in speed critical code.  */
block|}
name|CGEN_OPERAND_TABLE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_OPERAND
modifier|*
name|cgen_operand_lookup_by_name
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_OPERAND
modifier|*
name|cgen_operand_lookup_by_num
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|cgen_opinst_type
block|{
comment|/* End of table marker.  */
name|CGEN_OPINST_END
init|=
literal|0
block|,
name|CGEN_OPINST_INPUT
block|,
name|CGEN_OPINST_OUTPUT
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Input or output indicator.  */
name|enum
name|cgen_opinst_type
name|type
decl_stmt|;
comment|/* Name of operand.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The hardware element referenced.  */
name|enum
name|cgen_hw_type
name|hw_type
decl_stmt|;
comment|/* The mode in which the operand is being used.  */
name|enum
name|cgen_mode
name|mode
decl_stmt|;
comment|/* The operand table entry CGEN_OPERAND_NIL if there is none      (i.e. an explicit hardware reference).  */
name|enum
name|cgen_operand_type
name|op_type
decl_stmt|;
comment|/* If `operand' is "nil", the index (e.g. into array of registers).  */
name|int
name|index
decl_stmt|;
comment|/* Attributes.      ??? This perhaps should be a real attribute struct but there's      no current need, so we save a bit of space and just have a set of      flags.  The interface is such that this can easily be made attributes      should it prove useful.  */
name|unsigned
name|int
name|attrs
decl_stmt|;
define|#
directive|define
name|CGEN_OPINST_ATTRS
parameter_list|(
name|opinst
parameter_list|)
value|((opinst)->attrs)
comment|/* Return value of attribute ATTR in OPINST.  */
define|#
directive|define
name|CGEN_OPINST_ATTR
parameter_list|(
name|opinst
parameter_list|,
name|attr
parameter_list|)
define|\
value|((CGEN_OPINST_ATTRS (opinst)& (attr)) != 0)
comment|/* Operand is conditionally referenced (read/written).  */
define|#
directive|define
name|CGEN_OPINST_COND_REF
value|1
block|}
name|CGEN_OPINST
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* Syntax string.     Each insn format and subexpression has one of these.     The syntax "string" consists of characters (n> 0&& n< 128), and operand    values (n>= 128), and is terminated by 0.  Operand values are 128 + index    into the operand table.  The operand table doesn't exist in C, per se, as    the data is recorded in the parse/insert/extract/print switch statements. */
end_comment

begin_comment
comment|/* This should be at least as large as necessary for any target. */
end_comment

begin_define
define|#
directive|define
name|CGEN_MAX_SYNTAX_ELEMENTS
value|48
end_define

begin_comment
comment|/* A target may know its own precise maximum.  Assert that it falls below    the above limit. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS
end_ifdef

begin_if
if|#
directive|if
name|CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS
operator|>
name|CGEN_MAX_SYNTAX_ELEMENTS
end_if

begin_error
error|#
directive|error
literal|"CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS too high - enlarge CGEN_MAX_SYNTAX_ELEMENTS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CGEN_SYNTAX_CHAR_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CGEN_SYNTAX_CHAR_TYPE
name|syntax
index|[
name|CGEN_MAX_SYNTAX_ELEMENTS
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
value|((unsigned char)c)
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
comment|/* Instruction fields.     ??? We currently don't allow adding fields at run-time.    Easy to fix when needed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_ifld
block|{
comment|/* Enum of ifield.  */
name|int
name|num
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_NUM
parameter_list|(
name|f
parameter_list|)
value|((f)->num)
comment|/* Name of the field, distinguishes it from all other fields.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_NAME
parameter_list|(
name|f
parameter_list|)
value|((f)->name)
comment|/* Default offset, in bits, from the start of the insn to the word      containing the field.  */
name|int
name|word_offset
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_WORD_OFFSET
parameter_list|(
name|f
parameter_list|)
value|((f)->word_offset)
comment|/* Default length of the word containing the field.  */
name|int
name|word_size
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_WORD_SIZE
parameter_list|(
name|f
parameter_list|)
value|((f)->word_size)
comment|/* Default starting bit number.      Whether lsb=0 or msb=0 is determined by CGEN_INSN_LSB0_P.  */
name|int
name|start
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_START
parameter_list|(
name|f
parameter_list|)
value|((f)->start)
comment|/* Length of the field, in bits.  */
name|int
name|length
decl_stmt|;
define|#
directive|define
name|CGEN_IFLD_LENGTH
parameter_list|(
name|f
parameter_list|)
value|((f)->length)
ifndef|#
directive|ifndef
name|CGEN_IFLD_NBOOL_ATTRS
define|#
directive|define
name|CGEN_IFLD_NBOOL_ATTRS
value|1
endif|#
directive|endif
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_IFLD_NBOOL_ATTRS
argument_list|)
name|attrs
expr_stmt|;
define|#
directive|define
name|CGEN_IFLD_ATTRS
parameter_list|(
name|f
parameter_list|)
value|(&(f)->attrs)
block|}
name|CGEN_IFLD
typedef|;
end_typedef

begin_comment
comment|/* Return value of attribute ATTR in IFLD.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_IFLD_ATTR_VALUE
parameter_list|(
name|ifld
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE ((ifld), CGEN_IFLD_ATTRS (ifld), (attr))
end_define

begin_escape
end_escape

begin_comment
comment|/* Instruction data.  */
end_comment

begin_comment
comment|/* Instruction formats.     Instructions are grouped by format.  Associated with an instruction is its    format.  Each insn's opcode table entry contains a format table entry.    ??? There is usually very few formats compared with the number of insns,    so one can reduce the size of the opcode table by recording the format table    as a separate entity.  Given that we currently don't, format table entries    are also distinguished by their operands.  This increases the size of the    table, but reduces the number of tables.  It's all minutiae anyway so it    doesn't really matter [at this point in time].     ??? Support for variable length ISA's is wip.  */
end_comment

begin_comment
comment|/* Accompanying each iformat description is a list of its fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|CGEN_IFLD
modifier|*
name|ifld
decl_stmt|;
define|#
directive|define
name|CGEN_IFMT_IFLD_IFLD
parameter_list|(
name|ii
parameter_list|)
value|((ii)->ifld)
block|}
name|CGEN_IFMT_IFLD
typedef|;
end_typedef

begin_comment
comment|/* This should be at least as large as necessary for any target. */
end_comment

begin_define
define|#
directive|define
name|CGEN_MAX_IFMT_OPERANDS
value|16
end_define

begin_comment
comment|/* A target may know its own precise maximum.  Assert that it falls below    the above limit. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CGEN_ACTUAL_MAX_IFMT_OPERANDS
end_ifdef

begin_if
if|#
directive|if
name|CGEN_ACTUAL_MAX_IFMT_OPERANDS
operator|>
name|CGEN_MAX_IFMT_OPERANDS
end_if

begin_error
error|#
directive|error
literal|"CGEN_ACTUAL_MAX_IFMT_OPERANDS too high - enlarge CGEN_MAX_IFMT_OPERANDS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Length that MASK and VALUE have been calculated to      [VALUE is recorded elsewhere].      Normally it is base_insn_bitsize.  On [V]LIW architectures where the base      insn size may be larger than the size of an insn, this field is less than      base_insn_bitsize.  */
name|unsigned
name|char
name|mask_length
decl_stmt|;
define|#
directive|define
name|CGEN_IFMT_MASK_LENGTH
parameter_list|(
name|ifmt
parameter_list|)
value|((ifmt)->mask_length)
comment|/* Total length of instruction, in bits.  */
name|unsigned
name|char
name|length
decl_stmt|;
define|#
directive|define
name|CGEN_IFMT_LENGTH
parameter_list|(
name|ifmt
parameter_list|)
value|((ifmt)->length)
comment|/* Mask to apply to the first MASK_LENGTH bits.      Each insn's value is stored with the insn.      The first step in recognizing an insn for disassembly is      (opcode& mask) == value.  */
name|CGEN_INSN_INT
name|mask
decl_stmt|;
define|#
directive|define
name|CGEN_IFMT_MASK
parameter_list|(
name|ifmt
parameter_list|)
value|((ifmt)->mask)
comment|/* Instruction fields.      +1 for trailing NULL.  */
name|CGEN_IFMT_IFLD
name|iflds
index|[
name|CGEN_MAX_IFMT_OPERANDS
operator|+
literal|1
index|]
decl_stmt|;
define|#
directive|define
name|CGEN_IFMT_IFLDS
parameter_list|(
name|ifmt
parameter_list|)
value|((ifmt)->iflds)
block|}
name|CGEN_IFMT
typedef|;
end_typedef

begin_comment
comment|/* Instruction values.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The opcode portion of the base insn.  */
name|CGEN_INSN_INT
name|base_value
decl_stmt|;
ifdef|#
directive|ifdef
name|CGEN_MAX_EXTRA_OPCODE_OPERANDS
comment|/* Extra opcode values beyond base_value.  */
name|unsigned
name|long
name|ifield_values
index|[
name|CGEN_MAX_EXTRA_OPCODE_OPERANDS
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|CGEN_IVALUE
typedef|;
end_typedef

begin_comment
comment|/* Instruction opcode table.    This contains the syntax and format data of an instruction.  */
end_comment

begin_comment
comment|/* ??? Some ports already have an opcode table yet still need to use the rest    of what cgen_insn has.  Plus keeping the opcode data with the operand    instance data can create a pretty big file.  So we keep them separately.    Not sure this is a good idea in the long run.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Indices into parse/insert/extract/print handler tables.  */
name|struct
name|cgen_opcode_handler
name|handlers
decl_stmt|;
define|#
directive|define
name|CGEN_OPCODE_HANDLERS
parameter_list|(
name|opc
parameter_list|)
value|(& (opc)->handlers)
comment|/* Syntax string.  */
name|CGEN_SYNTAX
name|syntax
decl_stmt|;
define|#
directive|define
name|CGEN_OPCODE_SYNTAX
parameter_list|(
name|opc
parameter_list|)
value|(& (opc)->syntax)
comment|/* Format entry.  */
specifier|const
name|CGEN_IFMT
modifier|*
name|format
decl_stmt|;
define|#
directive|define
name|CGEN_OPCODE_FORMAT
parameter_list|(
name|opc
parameter_list|)
value|((opc)->format)
define|#
directive|define
name|CGEN_OPCODE_MASK_BITSIZE
parameter_list|(
name|opc
parameter_list|)
value|CGEN_IFMT_MASK_LENGTH (CGEN_OPCODE_FORMAT (opc))
define|#
directive|define
name|CGEN_OPCODE_BITSIZE
parameter_list|(
name|opc
parameter_list|)
value|CGEN_IFMT_LENGTH (CGEN_OPCODE_FORMAT (opc))
define|#
directive|define
name|CGEN_OPCODE_IFLDS
parameter_list|(
name|opc
parameter_list|)
value|CGEN_IFMT_IFLDS (CGEN_OPCODE_FORMAT (opc))
comment|/* Instruction opcode value.  */
name|CGEN_IVALUE
name|value
decl_stmt|;
define|#
directive|define
name|CGEN_OPCODE_VALUE
parameter_list|(
name|opc
parameter_list|)
value|(& (opc)->value)
define|#
directive|define
name|CGEN_OPCODE_BASE_VALUE
parameter_list|(
name|opc
parameter_list|)
value|(CGEN_OPCODE_VALUE (opc)->base_value)
define|#
directive|define
name|CGEN_OPCODE_BASE_MASK
parameter_list|(
name|opc
parameter_list|)
value|CGEN_IFMT_MASK (CGEN_OPCODE_FORMAT (opc))
block|}
name|CGEN_OPCODE
typedef|;
end_typedef

begin_comment
comment|/* Instruction attributes.    This is made a published type as applications can cache a pointer to    the attributes for speed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_INSN_NBOOL_ATTRS
end_ifndef

begin_define
define|#
directive|define
name|CGEN_INSN_NBOOL_ATTRS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CGEN_ATTR_TYPE
argument_list|(
argument|CGEN_INSN_NBOOL_ATTRS
argument_list|)
name|CGEN_INSN_ATTR_TYPE
expr_stmt|;
end_typedef

begin_comment
comment|/* Enum of architecture independent attributes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_ARCH
end_ifndef

begin_comment
comment|/* ??? Numbers here are recorded in two places.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|cgen_insn_attr
block|{
name|CGEN_INSN_ALIAS
init|=
literal|0
block|}
name|CGEN_INSN_ATTR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This struct defines each entry in the instruction table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Each real instruction is enumerated.  */
comment|/* ??? This may go away in time.  */
name|int
name|num
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_NUM
parameter_list|(
name|insn
parameter_list|)
value|((insn)->base->num)
comment|/* Name of entry (that distinguishes it from all other entries).  */
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
value|((insn)->base->name)
comment|/* Mnemonic.  This is used when parsing and printing the insn.      In the case of insns that have operands on the mnemonics, this is      only the constant part.  E.g. for conditional execution of an `add' insn,      where the full mnemonic is addeq, addne, etc., and the condition is      treated as an operand, this is only "add".  */
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
value|((insn)->base->mnemonic)
comment|/* Total length of instruction, in bits.  */
name|int
name|bitsize
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_BITSIZE
parameter_list|(
name|insn
parameter_list|)
value|((insn)->base->bitsize)
if|#
directive|if
literal|0
comment|/* ??? Disabled for now as there is a problem with embedded newlines 	 and the table is already pretty big.  Should perhaps be moved 	 to a file of its own.  */
comment|/* Semantics, as RTL.  */
comment|/* ??? Plain text or bytecodes?  */
comment|/* ??? Note that the operand instance table could be computed at run-time      if we parse this and cache the results.  Something to eventually do.  */
block|const char *rtx;
define|#
directive|define
name|CGEN_INSN_RTX
parameter_list|(
name|insn
parameter_list|)
value|((insn)->base->rtx)
endif|#
directive|endif
comment|/* Attributes.      This must appear last.  It is a variable sized array in that one      architecture may have 1 nonbool attribute and another may have more.      Having this last means the non-architecture specific code needn't      care.  The goal is to eventually record attributes in their raw form,      evaluate them at run-time, and cache the values, so this worry will go      away anyway.  */
name|CGEN_INSN_ATTR_TYPE
name|attrs
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_ATTRS
parameter_list|(
name|insn
parameter_list|)
value|(&(insn)->base->attrs)
comment|/* Return value of attribute ATTR in INSN.  */
define|#
directive|define
name|CGEN_INSN_ATTR_VALUE
parameter_list|(
name|insn
parameter_list|,
name|attr
parameter_list|)
define|\
value|CGEN_ATTR_VALUE ((insn), CGEN_INSN_ATTRS (insn), (attr))
block|}
name|CGEN_IBASE
typedef|;
end_typedef

begin_comment
comment|/* Return non-zero if INSN is the "invalid" insn marker.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_INVALID_P
parameter_list|(
name|insn
parameter_list|)
value|(CGEN_INSN_MNEMONIC (insn) == 0)
end_define

begin_comment
comment|/* Main struct contain instruction information.    BASE is always present, the rest is present only if asked for.  */
end_comment

begin_struct
struct|struct
name|cgen_insn
block|{
comment|/* ??? May be of use to put a type indicator here.      Then this struct could different info for different classes of insns.  */
comment|/* ??? A speedup can be had by moving `base' into this struct.      Maybe later.  */
specifier|const
name|CGEN_IBASE
modifier|*
name|base
decl_stmt|;
specifier|const
name|CGEN_OPCODE
modifier|*
name|opcode
decl_stmt|;
specifier|const
name|CGEN_OPINST
modifier|*
name|opinst
decl_stmt|;
comment|/* Regex to disambiguate overloaded opcodes */
name|void
modifier|*
name|rx
decl_stmt|;
define|#
directive|define
name|CGEN_INSN_RX
parameter_list|(
name|insn
parameter_list|)
value|((insn)->rx)
define|#
directive|define
name|CGEN_MAX_RX_ELEMENTS
value|(CGEN_MAX_SYNTAX_ELEMENTS * 5)
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
comment|/* Table of instructions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|CGEN_INSN
modifier|*
name|init_entries
decl_stmt|;
name|unsigned
name|int
name|entry_size
decl_stmt|;
comment|/* since the attribute member is variable sized */
name|unsigned
name|int
name|num_init_entries
decl_stmt|;
name|CGEN_INSN_LIST
modifier|*
name|new_entries
decl_stmt|;
block|}
name|CGEN_INSN_TABLE
typedef|;
end_typedef

begin_comment
comment|/* Return number of instructions.  This includes any added at run-time.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cgen_insn_count
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cgen_macro_insn_count
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros to access the other insn elements not recorded in CGEN_IBASE.  */
end_comment

begin_comment
comment|/* Fetch INSN's operand instance table.  */
end_comment

begin_comment
comment|/* ??? Doesn't handle insns added at runtime.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_OPERANDS
parameter_list|(
name|insn
parameter_list|)
value|((insn)->opinst)
end_define

begin_comment
comment|/* Return INSN's opcode table entry.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_OPCODE
parameter_list|(
name|insn
parameter_list|)
value|((insn)->opcode)
end_define

begin_comment
comment|/* Return INSN's handler data.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_HANDLERS
parameter_list|(
name|insn
parameter_list|)
value|CGEN_OPCODE_HANDLERS (CGEN_INSN_OPCODE (insn))
end_define

begin_comment
comment|/* Return INSN's syntax.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_SYNTAX
parameter_list|(
name|insn
parameter_list|)
value|CGEN_OPCODE_SYNTAX (CGEN_INSN_OPCODE (insn))
end_define

begin_comment
comment|/* Return size of base mask in bits.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_MASK_BITSIZE
parameter_list|(
name|insn
parameter_list|)
define|\
value|CGEN_OPCODE_MASK_BITSIZE (CGEN_INSN_OPCODE (insn))
end_define

begin_comment
comment|/* Return mask of base part of INSN.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_BASE_MASK
parameter_list|(
name|insn
parameter_list|)
define|\
value|CGEN_OPCODE_BASE_MASK (CGEN_INSN_OPCODE (insn))
end_define

begin_comment
comment|/* Return value of base part of INSN.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_BASE_VALUE
parameter_list|(
name|insn
parameter_list|)
define|\
value|CGEN_OPCODE_BASE_VALUE (CGEN_INSN_OPCODE (insn))
end_define

begin_comment
comment|/* Standard way to test whether INSN is supported by MACH.    MACH is one of enum mach_attr.    The "|1" is because the base mach is always selected.  */
end_comment

begin_define
define|#
directive|define
name|CGEN_INSN_MACH_HAS_P
parameter_list|(
name|insn
parameter_list|,
name|mach
parameter_list|)
define|\
value|((CGEN_INSN_ATTR_VALUE ((insn), CGEN_INSN_MACH)& ((1<< (mach)) | 1)) != 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Macro instructions.    Macro insns aren't real insns, they map to one or more real insns.    E.g. An architecture's "nop" insn may actually be an "mv r0,r0" or    some such.     Macro insns can expand to nothing (e.g. a nop that is optimized away).    This is useful in multi-insn macros that build a constant in a register.    Of course this isn't the default behaviour and must be explicitly enabled.     Assembly of macro-insns is relatively straightforward.  Disassembly isn't.    However, disassembly of at least some kinds of macro insns is important    in order that the disassembled code preserve the readability of the original    insn.  What is attempted here is to disassemble all "simple" macro-insns,    where "simple" is currently defined to mean "expands to one real insn".     Simple macro-insns are handled specially.  They are emitted as ALIAS's    of real insns.  This simplifies their handling since there's usually more    of them than any other kind of macro-insn, and proper disassembly of them    falls out for free.  */
end_comment

begin_comment
comment|/* For each macro-insn there may be multiple expansion possibilities,    depending on the arguments.  This structure is accessed via the `data'    member of CGEN_INSN.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_minsn_expansion
block|{
comment|/* Function to do the expansion.      If the expansion fails (e.g. "no match") NULL is returned.      Space for the expansion is obtained with malloc.      It is up to the caller to free it.  */
specifier|const
name|char
operator|*
operator|(
operator|*
name|fn
operator|)
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|cgen_minsn_expansion
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|CGEN_OPERAND
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|CGEN_MIEXPN_FN
parameter_list|(
name|ex
parameter_list|)
value|((ex)->fn)
comment|/* Instruction(s) the macro expands to.      The format of STR is defined by FN.      It is typically the assembly code of the real insn, but it could also be      the original Scheme expression or a tokenized form of it (with FN being      an appropriate interpreter).  */
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
define|#
directive|define
name|CGEN_MIEXPN_STR
parameter_list|(
name|ex
parameter_list|)
value|((ex)->str)
block|}
name|CGEN_MINSN_EXPANSION
typedef|;
end_typedef

begin_comment
comment|/* Normal expander.    When supported, this function will convert the input string to another    string and the parser will be invoked recursively.  The output string    may contain further macro invocations.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_expand_macro_insn
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
expr|struct
name|cgen_minsn_expansion
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|CGEN_OPERAND
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The assembler insn table is hashed based on some function of the mnemonic    (the actually hashing done is up to the target, but we provide a few    examples like the first letter or a function of the entire mnemonic).  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_INSN_LIST
modifier|*
name|cgen_asm_lookup_insn
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
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
name|cd
parameter_list|,
name|string
parameter_list|)
value|cgen_asm_lookup_insn ((cd), (string))
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

begin_decl_stmt
specifier|extern
name|CGEN_INSN_LIST
modifier|*
name|cgen_dis_lookup_insn
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|char
operator|*
operator|,
name|CGEN_INSN_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FIXME: delete these two */
end_comment

begin_define
define|#
directive|define
name|CGEN_DIS_LOOKUP_INSN
parameter_list|(
name|cd
parameter_list|,
name|buf
parameter_list|,
name|value
parameter_list|)
value|cgen_dis_lookup_insn ((cd), (buf), (value))
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
comment|/* The CPU description.    A copy of this is created when the cpu table is "opened".    All global state information is recorded here.    Access macros are provided for "public" members.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cgen_cpu_desc
block|{
comment|/* Bitmap of selected machine(s) (a la BFD machine number).  */
name|int
name|machs
decl_stmt|;
comment|/* Bitmap of selected isa(s).      ??? Simultaneous multiple isas might not make sense, but it's not (yet)      precluded.  */
name|int
name|isas
decl_stmt|;
comment|/* Current endian.  */
name|enum
name|cgen_endian
name|endian
decl_stmt|;
define|#
directive|define
name|CGEN_CPU_ENDIAN
parameter_list|(
name|cd
parameter_list|)
value|((cd)->endian)
comment|/* Current insn endian.  */
name|enum
name|cgen_endian
name|insn_endian
decl_stmt|;
define|#
directive|define
name|CGEN_CPU_INSN_ENDIAN
parameter_list|(
name|cd
parameter_list|)
value|((cd)->insn_endian)
comment|/* Word size (in bits).  */
comment|/* ??? Or maybe maximum word size - might we ever need to allow a cpu table      to be opened for both sparc32/sparc64?      ??? Another alternative is to create a table of selected machs and      lazily fetch the data from there.  */
name|unsigned
name|int
name|word_bitsize
decl_stmt|;
comment|/* Instruction chunk size (in bits), for purposes of endianness      conversion.  */
name|unsigned
name|int
name|insn_chunk_bitsize
decl_stmt|;
comment|/* Indicator if sizes are unknown.      This is used by default_insn_bitsize,base_insn_bitsize if there is a      difference between the selected isa's.  */
define|#
directive|define
name|CGEN_SIZE_UNKNOWN
value|65535
comment|/* Default instruction size (in bits).      This is used by the assembler when it encounters an unknown insn.  */
name|unsigned
name|int
name|default_insn_bitsize
decl_stmt|;
comment|/* Base instruction size (in bits).      For non-LIW cpus this is generally the length of the smallest insn.      For LIW cpus its wip (work-in-progress).  For the m32r its 32.  */
name|unsigned
name|int
name|base_insn_bitsize
decl_stmt|;
comment|/* Minimum/maximum instruction size (in bits).  */
name|unsigned
name|int
name|min_insn_bitsize
decl_stmt|;
name|unsigned
name|int
name|max_insn_bitsize
decl_stmt|;
comment|/* Instruction set variants.  */
specifier|const
name|CGEN_ISA
modifier|*
name|isa_table
decl_stmt|;
comment|/* Machine variants.  */
specifier|const
name|CGEN_MACH
modifier|*
name|mach_table
decl_stmt|;
comment|/* Hardware elements.  */
name|CGEN_HW_TABLE
name|hw_table
decl_stmt|;
comment|/* Instruction fields.  */
specifier|const
name|CGEN_IFLD
modifier|*
name|ifld_table
decl_stmt|;
comment|/* Operands.  */
name|CGEN_OPERAND_TABLE
name|operand_table
decl_stmt|;
comment|/* Main instruction table.  */
name|CGEN_INSN_TABLE
name|insn_table
decl_stmt|;
define|#
directive|define
name|CGEN_CPU_INSN_TABLE
parameter_list|(
name|cd
parameter_list|)
value|(& (cd)->insn_table)
comment|/* Macro instructions are defined separately and are combined with real      insns during hash table computation.  */
name|CGEN_INSN_TABLE
name|macro_insn_table
decl_stmt|;
comment|/* Copy of CGEN_INT_INSN_P.  */
name|int
name|int_insn_p
decl_stmt|;
comment|/* Called to rebuild the tables after something has changed.  */
name|void
argument_list|(
argument|*rebuild_tables
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|)
argument_list|)
expr_stmt|;
comment|/* Operand parser callback.  */
name|cgen_parse_operand_fn
modifier|*
name|parse_operand_fn
decl_stmt|;
comment|/* Parse/insert/extract/print cover fns for operands.  */
specifier|const
name|char
operator|*
operator|(
operator|*
name|parse_operand
operator|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
specifier|const
name|char
operator|*
operator|(
operator|*
name|insert_operand
operator|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|CGEN_INSN_BYTES_PTR
operator|,
name|bfd_vma
name|pc_
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*extract_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
name|CGEN_EXTRACT_INFO
operator|*
operator|,
name|CGEN_INSN_INT
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|bfd_vma
name|pc_
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*print_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
name|PTR
name|info_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|void
specifier|const
operator|*
name|attrs_
operator|,
name|bfd_vma
name|pc_
operator|,
name|int
name|length_
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|insert_operand
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|extract_operand
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|print_operand
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
define|#
directive|define
name|CGEN_CPU_PARSE_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->parse_operand)
define|#
directive|define
name|CGEN_CPU_INSERT_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->insert_operand)
define|#
directive|define
name|CGEN_CPU_EXTRACT_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->extract_operand)
define|#
directive|define
name|CGEN_CPU_PRINT_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->print_operand)
comment|/* Size of CGEN_FIELDS struct.  */
name|unsigned
name|int
name|sizeof_fields
decl_stmt|;
define|#
directive|define
name|CGEN_CPU_SIZEOF_FIELDS
parameter_list|(
name|cd
parameter_list|)
value|((cd)->sizeof_fields)
comment|/* Set the bitsize field.  */
name|void
argument_list|(
argument|*set_fields_bitsize
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|int
name|size_
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|CGEN_CPU_SET_FIELDS_BITSIZE
parameter_list|(
name|cd
parameter_list|)
value|((cd)->set_fields_bitsize)
comment|/* CGEN_FIELDS accessors.  */
name|int
argument_list|(
argument|*get_int_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
specifier|const
name|CGEN_FIELDS
operator|*
name|fields_
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*set_int_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|int
name|value_
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BFD_VERSION_DATE
name|bfd_vma
argument_list|(
argument|*get_vma_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
specifier|const
name|CGEN_FIELDS
operator|*
name|fields_
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*set_vma_operand
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|int
name|opindex_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|bfd_vma
name|value_
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|long
function_decl|(
modifier|*
name|get_vma_operand
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|set_vma_operand
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
define|#
directive|define
name|CGEN_CPU_GET_INT_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->get_int_operand)
define|#
directive|define
name|CGEN_CPU_SET_INT_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->set_int_operand)
define|#
directive|define
name|CGEN_CPU_GET_VMA_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->get_vma_operand)
define|#
directive|define
name|CGEN_CPU_SET_VMA_OPERAND
parameter_list|(
name|cd
parameter_list|)
value|((cd)->set_vma_operand)
comment|/* Instruction parse/insert/extract/print handlers.  */
comment|/* FIXME: make these types uppercase.  */
name|cgen_parse_fn
modifier|*
specifier|const
modifier|*
name|parse_handlers
decl_stmt|;
name|cgen_insert_fn
modifier|*
specifier|const
modifier|*
name|insert_handlers
decl_stmt|;
name|cgen_extract_fn
modifier|*
specifier|const
modifier|*
name|extract_handlers
decl_stmt|;
name|cgen_print_fn
modifier|*
specifier|const
modifier|*
name|print_handlers
decl_stmt|;
define|#
directive|define
name|CGEN_PARSE_FN
parameter_list|(
name|cd
parameter_list|,
name|insn
parameter_list|)
value|(cd->parse_handlers[(insn)->opcode->handlers.parse])
define|#
directive|define
name|CGEN_INSERT_FN
parameter_list|(
name|cd
parameter_list|,
name|insn
parameter_list|)
value|(cd->insert_handlers[(insn)->opcode->handlers.insert])
define|#
directive|define
name|CGEN_EXTRACT_FN
parameter_list|(
name|cd
parameter_list|,
name|insn
parameter_list|)
value|(cd->extract_handlers[(insn)->opcode->handlers.extract])
define|#
directive|define
name|CGEN_PRINT_FN
parameter_list|(
name|cd
parameter_list|,
name|insn
parameter_list|)
value|(cd->print_handlers[(insn)->opcode->handlers.print])
comment|/* Return non-zero if insn should be added to hash table.  */
name|int
argument_list|(
argument|* asm_hash_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|CGEN_INSN
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|asm_hash_size
decl_stmt|;
comment|/* Return non-zero if insn should be added to hash table.  */
name|int
argument_list|(
argument|* dis_hash_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|CGEN_INSN
operator|*
operator|)
argument_list|)
expr_stmt|;
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
name|CGEN_INSN_INT
operator|)
argument_list|)
decl_stmt|;
comment|/* Number of entries in disassembler hash table.  */
name|unsigned
name|int
name|dis_hash_size
decl_stmt|;
comment|/* Assembler instruction hash table.  */
name|CGEN_INSN_LIST
modifier|*
modifier|*
name|asm_hash_table
decl_stmt|;
name|CGEN_INSN_LIST
modifier|*
name|asm_hash_table_entries
decl_stmt|;
comment|/* Disassembler instruction hash table.  */
name|CGEN_INSN_LIST
modifier|*
modifier|*
name|dis_hash_table
decl_stmt|;
name|CGEN_INSN_LIST
modifier|*
name|dis_hash_table_entries
decl_stmt|;
comment|/* This field could be turned into a bitfield if room for other flags is needed.  */
name|unsigned
name|int
name|signed_overflow_ok_p
decl_stmt|;
block|}
name|CGEN_CPU_TABLE
typedef|;
end_typedef

begin_comment
comment|/* wip */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_WORD_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|CGEN_WORD_ENDIAN
parameter_list|(
name|cd
parameter_list|)
value|CGEN_CPU_ENDIAN (cd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CGEN_INSN_WORD_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|CGEN_INSN_WORD_ENDIAN
parameter_list|(
name|cd
parameter_list|)
value|CGEN_CPU_INSN_ENDIAN (cd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Prototypes of major functions.  */
end_comment

begin_comment
comment|/* FIXME: Move more CGEN_SYM-defined functions into CGEN_CPU_DESC.    Not the init fns though, as that would drag in things that mightn't be    used and might not even exist.  */
end_comment

begin_comment
comment|/* Argument types to cpu_open.  */
end_comment

begin_enum
enum|enum
name|cgen_cpu_open_arg
block|{
name|CGEN_CPU_OPEN_END
block|,
comment|/* Select instruction set(s), arg is bitmap or 0 meaning "unspecified".  */
name|CGEN_CPU_OPEN_ISAS
block|,
comment|/* Select machine(s), arg is bitmap or 0 meaning "unspecified".  */
name|CGEN_CPU_OPEN_MACHS
block|,
comment|/* Select machine, arg is mach's bfd name.      Multiple machines can be specified by repeated use.  */
name|CGEN_CPU_OPEN_BFDMACH
block|,
comment|/* Select endian, arg is CGEN_ENDIAN_*.  */
name|CGEN_CPU_OPEN_ENDIAN
block|}
enum|;
end_enum

begin_comment
comment|/* Open a cpu descriptor table for use.    ??? We only support ISO C stdargs here, not K&R.    Laziness, plus experiment to see if anything requires K&R - eventually    K&R will no longer be supported - e.g. GDB is currently trying this.  */
end_comment

begin_function_decl
specifier|extern
name|CGEN_CPU_DESC
name|CGEN_SYM
function_decl|(
name|cpu_open
function_decl|)
parameter_list|(
name|enum
name|cgen_cpu_open_arg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cover fn to handle simple case.  */
end_comment

begin_function_decl
specifier|extern
name|CGEN_CPU_DESC
name|CGEN_SYM
parameter_list|(
name|cpu_open_1
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
specifier|const
name|char
modifier|*
name|mach_name_
decl_stmt|,
decl|enum
name|cgen_endian
name|endian_
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Close it.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|cpu_close
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Initialize the opcode table for use.    Called by init_asm/init_dis.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|init_opcode_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC cd_
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* build the insn selection regex.    called by init_opcode_table */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|CGEN_SYM
parameter_list|(
name|build_insn_regex
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_INSN *insn_
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Initialize the ibld table for use.    Called by init_asm/init_dis.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|init_ibld_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC cd_
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Initialize an cpu table for assembler or disassembler use.    These must be called immediately after cpu_open.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|init_asm
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|init_dis
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Initialize the operand instance table for use.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|CGEN_SYM
parameter_list|(
name|init_opinst_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC cd_
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Assemble an instruction.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|CGEN_INSN
modifier|*
name|CGEN_SYM
parameter_list|(
name|assemble_insn
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(CGEN_CPU_DESC
operator|,
function_decl|const char *
operator|,
function_decl|CGEN_FIELDS *
operator|,
function_decl|CGEN_INSN_BYTES_PTR
operator|,
function_decl|char **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

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
specifier|extern
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

begin_comment
comment|/* Operand index computation.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_INSN
modifier|*
name|cgen_lookup_insn
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
name|CGEN_INSN_INT
name|int_value_
operator|,
name|unsigned
name|char
operator|*
name|bytes_value_
operator|,
name|int
name|length_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|int
name|alias_p_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cgen_get_insn_operands
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
specifier|const
name|CGEN_FIELDS
operator|*
name|fields_
operator|,
name|int
operator|*
name|indices_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|CGEN_INSN
modifier|*
name|cgen_lookup_get_insn_operands
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|CGEN_INSN
operator|*
name|insn_
operator|,
name|CGEN_INSN_INT
name|int_value_
operator|,
name|unsigned
name|char
operator|*
name|bytes_value_
operator|,
name|int
name|length_
operator|,
name|int
operator|*
name|indices_
operator|,
name|CGEN_FIELDS
operator|*
name|fields_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cover fns to bfd_get/set.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_INSN_INT
name|cgen_get_insn_value
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|unsigned
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
name|void
name|cgen_put_insn_value
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|CGEN_INSN_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read in a cpu description file.    ??? For future concerns, including adding instructions to the assembler/    disassembler at run-time.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cgen_read_cpu_file
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
specifier|const
name|char
operator|*
name|filename_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allow signed overflow of instruction fields.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cgen_set_signed_overflow_ok
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate an error message if a signed field in an instruction overflows.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cgen_clear_signed_overflow_ok
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Will an error message be generated if a signed field in an instruction overflows ? */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|cgen_signed_overflow_ok_p
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
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

