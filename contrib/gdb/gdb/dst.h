begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<apollo/dst.h> */
end_comment

begin_comment
comment|/* Apollo object module DST (debug symbol table) description */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|apollo_dst_h
end_ifndef

begin_define
define|#
directive|define
name|apollo_dst_h
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|apollo
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ALIGNED1
value|__attribute( (aligned(1)) )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Remove attribute directives from non-Apollo code: */
end_comment

begin_define
define|#
directive|define
name|ALIGNED1
end_define

begin_comment
comment|/* nil */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Identification of this version of the debug symbol table.  Producers of the    debug symbol table must write these values into the version number field of    the compilation unit record in .blocks .  */
end_comment

begin_define
define|#
directive|define
name|dst_version_major
value|1
end_define

begin_define
define|#
directive|define
name|dst_version_minor
value|3
end_define

begin_comment
comment|/*    ** Enumeration of debug record types appearing in .blocks and .symbols ...  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_typ_pad
block|,
comment|/*  0 */
name|dst_typ_comp_unit
block|,
comment|/*  1 */
name|dst_typ_section_tab
block|,
comment|/*  2 */
name|dst_typ_file_tab
block|,
comment|/*  3 */
name|dst_typ_block
block|,
comment|/*  4 */
name|dst_typ_5
block|,
name|dst_typ_var
block|,
name|dst_typ_pointer
block|,
comment|/*  7 */
name|dst_typ_array
block|,
comment|/*  8 */
name|dst_typ_subrange
block|,
comment|/*  9 */
name|dst_typ_set
block|,
comment|/* 10 */
name|dst_typ_implicit_enum
block|,
comment|/* 11 */
name|dst_typ_explicit_enum
block|,
comment|/* 12 */
name|dst_typ_short_rec
block|,
comment|/* 13 */
name|dst_typ_old_record
block|,
name|dst_typ_short_union
block|,
comment|/* 15 */
name|dst_typ_old_union
block|,
name|dst_typ_file
block|,
comment|/* 17 */
name|dst_typ_offset
block|,
comment|/* 18 */
name|dst_typ_alias
block|,
comment|/* 19 */
name|dst_typ_signature
block|,
comment|/* 20 */
name|dst_typ_21
block|,
name|dst_typ_old_label
block|,
comment|/* 22 */
name|dst_typ_scope
block|,
comment|/* 23 */
name|dst_typ_end_scope
block|,
comment|/* 24 */
name|dst_typ_25
block|,
name|dst_typ_26
block|,
name|dst_typ_string_tab
block|,
comment|/* 27 */
name|dst_typ_global_name_tab
block|,
comment|/* 28 */
name|dst_typ_forward
block|,
comment|/* 29 */
name|dst_typ_aux_size
block|,
comment|/* 30 */
name|dst_typ_aux_align
block|,
comment|/* 31 */
name|dst_typ_aux_field_size
block|,
comment|/* 32 */
name|dst_typ_aux_field_off
block|,
comment|/* 33 */
name|dst_typ_aux_field_align
block|,
comment|/* 34 */
name|dst_typ_aux_qual
block|,
comment|/* 35 */
name|dst_typ_aux_var_bound
block|,
comment|/* 36 */
name|dst_typ_extension
block|,
comment|/* 37 */
name|dst_typ_string
block|,
comment|/* 38 */
name|dst_typ_old_entry
block|,
name|dst_typ_const
block|,
comment|/* 40 */
name|dst_typ_reference
block|,
comment|/* 41 */
name|dst_typ_record
block|,
comment|/* 42 */
name|dst_typ_union
block|,
comment|/* 43 */
name|dst_typ_aux_type_deriv
block|,
comment|/* 44 */
name|dst_typ_locpool
block|,
comment|/* 45 */
name|dst_typ_variable
block|,
comment|/* 46 */
name|dst_typ_label
block|,
comment|/* 47 */
name|dst_typ_entry
block|,
comment|/* 48 */
name|dst_typ_aux_lifetime
block|,
comment|/* 49 */
name|dst_typ_aux_ptr_base
block|,
comment|/* 50 */
name|dst_typ_aux_src_range
block|,
comment|/* 51 */
name|dst_typ_aux_reg_val
block|,
comment|/* 52 */
name|dst_typ_aux_unit_names
block|,
comment|/* 53 */
name|dst_typ_aux_sect_info
block|,
comment|/* 54 */
name|dst_typ_END_OF_ENUM
block|}
name|dst_rec_type_t
typedef|;
end_typedef

begin_comment
comment|/*    ** Dummy bounds for variably dimensioned arrays:  */
end_comment

begin_define
define|#
directive|define
name|dst_dummy_array_size
value|100
end_define

begin_comment
comment|/*    ** Reference to another item in the symbol table.    **    ** The value of a dst_rel_offset_t is the relative offset from the start of the    ** referencing record to the start of the referenced record, string, etc.     **    ** The value of a NIL dst_rel_offset_t is zero.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|dst_rel_offset_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/* FIXME: Here and many places we make assumptions about sizes of host    data types, structure layout, etc.  Only needs to be fixed if we care    about cross-debugging, though.  */
end_comment

begin_comment
comment|/*    ** Section-relative reference.     **    ** The section index field is an index into the local compilation unit's    ** section table (see dst_rec_section_tab_t)--NOT into the object module    ** section table!    **    ** The sect_offset field is the offset in bytes into the section.    **    ** A NIL dst_sect_ref_t has a sect_index field of zero.  Indexes originate    ** at one.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|sect_index
decl_stmt|;
name|unsigned
name|long
name|sect_offset
name|ALIGNED1
decl_stmt|;
block|}
name|dst_sect_ref_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dst_sect_index_nil
value|0
end_define

begin_define
define|#
directive|define
name|dst_sect_index_origin
value|1
end_define

begin_comment
comment|/*    ** Source location descriptor.    **    ** The file_index field is an index into the local compilation unit's    ** file table (see dst_rec_file_tab_t).    **    ** A NIL dst_src_loc_t has a file_index field of zero.  Indexes originate    ** at one.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|boolean
name|reserved
range|:
literal|1
decl_stmt|;
comment|/* reserved for future use */
name|int
name|file_index
range|:
literal|11
decl_stmt|;
comment|/* index into .blocks source file list */
name|int
name|line_number
range|:
literal|20
decl_stmt|;
comment|/* source line number */
block|}
name|dst_src_loc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dst_file_index_nil
value|0
end_define

begin_define
define|#
directive|define
name|dst_file_index_origin
value|1
end_define

begin_comment
comment|/*    ** Standard (primitive) type codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_non_std_type
block|,
name|dst_int8_type
block|,
comment|/* 8 bit integer */
name|dst_int16_type
block|,
comment|/* 16 bit integer */
name|dst_int32_type
block|,
comment|/* 32 bit integer */
name|dst_uint8_type
block|,
comment|/* 8 bit unsigned integer */
name|dst_uint16_type
block|,
comment|/* 16 bit unsigned integer */
name|dst_uint32_type
block|,
comment|/* 32 bit unsigned integer */
name|dst_real32_type
block|,
comment|/* single precision ieee floatining point */
name|dst_real64_type
block|,
comment|/* double precision ieee floatining point */
name|dst_complex_type
block|,
comment|/* single precision complex */
name|dst_dcomplex_type
block|,
comment|/* double precision complex */
name|dst_bool8_type
block|,
comment|/* boolean =logical*1 */
name|dst_bool16_type
block|,
comment|/* boolean =logical*2 */
name|dst_bool32_type
block|,
comment|/* boolean =logical*4 */
name|dst_char_type
block|,
comment|/* 8 bit ascii character */
name|dst_string_type
block|,
comment|/* string of 8 bit ascii characters */
name|dst_ptr_type
block|,
comment|/* univ_pointer */
name|dst_set_type
block|,
comment|/* generic 256 bit set */
name|dst_proc_type
block|,
comment|/* generic procedure (signature not specified) */
name|dst_func_type
block|,
comment|/* generic function (signature not specified) */
name|dst_void_type
block|,
comment|/* c void type */
name|dst_uchar_type
block|,
comment|/* c unsigned char */
name|dst_std_type_END_OF_ENUM
block|}
name|dst_std_type_t
typedef|;
end_typedef

begin_comment
comment|/*    ** General data type descriptor    **    ** If the user_defined_type bit is clear, then the type is a standard type, and    ** the remaining bits contain the dst_std_type_t of the type.  If the bit is    ** set, then the type is defined in a separate dst record, which is referenced    ** by the remaining bits as a dst_rel_offset_t.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|boolean
name|user_defined_type
range|:
literal|1
decl_stmt|;
comment|/* tag field */
name|int
name|must_be_zero
range|:
literal|23
decl_stmt|;
comment|/* 23 bits of pad */
name|dst_std_type_t
name|dtc
range|:
literal|8
decl_stmt|;
comment|/* 8 bit primitive data */
block|}
name|std_type
struct|;
struct|struct
block|{
name|boolean
name|user_defined_type
range|:
literal|1
decl_stmt|;
comment|/* tag field */
name|int
name|doffset
range|:
literal|31
decl_stmt|;
comment|/* offset to type record */
block|}
name|user_type
struct|;
block|}
name|dst_type_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/* The user_type.doffset field is a 31-bit signed value.  Some versions of C    do not support signed bit fields.  The following macro will extract that    field as a signed value:  */
end_comment

begin_define
define|#
directive|define
name|dst_user_type_offset
parameter_list|(
name|type_rec
parameter_list|)
define|\
value|( ((int) ((type_rec).user_type.doffset<< 1))>> 1 )
end_define

begin_comment
comment|/*================================================*/
end_comment

begin_comment
comment|/*========== RECORDS IN .blocks SECTION ==========*/
end_comment

begin_comment
comment|/*================================================*/
end_comment

begin_comment
comment|/*-----------------------   COMPILATION UNIT record    -----------------------   This must be the first record in each .blocks section.   Provides a set of information describing the output of a single compilation   and pointers to additional information for the compilation unit. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_pc_code_locs
block|,
comment|/* ranges in loc strings are pc ranges */
name|dst_comp_unit_END_OF_ENUM
block|}
name|dst_comp_unit_flag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_lang_unk
block|,
comment|/* unknown language */
name|dst_lang_pas
block|,
comment|/* Pascal */
name|dst_lang_ftn
block|,
comment|/* FORTRAN */
name|dst_lang_c
block|,
comment|/* C */
name|dst_lang_mod2
block|,
comment|/* Modula-2 */
name|dst_lang_asm_m68k
block|,
comment|/* 68K assembly language */
name|dst_lang_asm_a88k
block|,
comment|/* AT assembly language */
name|dst_lang_ada
block|,
comment|/* Ada */
name|dst_lang_cxx
block|,
comment|/* C++ */
name|dst_lang_END_OF_ENUM
block|}
name|dst_lang_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
block|{
name|unsigned
name|char
name|major_part
decl_stmt|;
comment|/* = dst_version_major */
name|unsigned
name|char
name|minor_part
decl_stmt|;
comment|/* = dst_version_minor */
block|}
name|version
struct|;
comment|/* version of dst */
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* mask of dst_comp_unit_flag_t */
name|unsigned
name|short
name|lang_type
decl_stmt|;
comment|/* source language */
name|unsigned
name|short
name|number_of_blocks
decl_stmt|;
comment|/* number of blocks records */
name|dst_rel_offset_t
name|root_block_offset
decl_stmt|;
comment|/* offset to root block (module?) */
name|dst_rel_offset_t
name|section_table
comment|/* offset to section table record */
decl_stmt|;
name|dst_rel_offset_t
name|file_table
decl_stmt|;
comment|/* offset to file table record */
name|unsigned
name|long
name|data_size
decl_stmt|;
comment|/* total size of .blocks data */
block|}
name|dst_rec_comp_unit_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------------   SECTION TABLE record   --------------------   There must be one section table associated with each compilation unit.   Other debug records refer to sections via their index in this table.  The   section base addresses in the table are virtual addresses of the sections,   relocated by the linker. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|number_of_sections
decl_stmt|;
comment|/* size of array: */
name|unsigned
name|long
name|section_base
index|[
name|dst_dummy_array_size
index|]
name|ALIGNED1
decl_stmt|;
block|}
name|dst_rec_section_tab_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------   FILE TABLE record   -----------------   There must be one file table associated with each compilation unit describing   the source (and include) files used by each compilation unit.  Other debug    records refer to files via their index in this table.  The first entry is the   primary source file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|dtm
decl_stmt|;
comment|/* time last modified (time_$clock_t) */
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string for source file */
block|}
name|dst_file_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|number_of_files
decl_stmt|;
comment|/* size of array: */
name|dst_file_desc_t
name|files
index|[
name|dst_dummy_array_size
index|]
name|ALIGNED1
decl_stmt|;
block|}
name|dst_rec_file_tab_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------   NAME TABLE record   -----------------   A name table record may appear as an auxiliary record to the file table,   providing additional qualification of the file indexes for languages that    need it (i.e. Ada).  Name table entries parallel file table entries of the   same file index. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|number_of_names
decl_stmt|;
comment|/* size of array: */
name|dst_rel_offset_t
name|names
index|[
name|dst_dummy_array_size
index|]
name|ALIGNED1
decl_stmt|;
block|}
name|dst_rec_name_tab_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------   BLOCK record   --------------   Describes a lexical program block--a procedure, function, module, etc. */
end_comment

begin_comment
comment|/* Block types.  These may be used in any way desired by the compiler writers.     The debugger uses them only to give a description to the user of the type of    a block.  The debugger makes no other assumptions about the meaning of any    of these.  For example, the fact that a block is executable (e.g., program)    or not (e.g., module) is expressed in block attributes (see below), not    guessed at from the block type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_block_module
block|,
comment|/* some pascal = modula = ada types */
name|dst_block_program
block|,
name|dst_block_procedure
block|,
name|dst_block_function
block|,
comment|/* C function */
name|dst_block_subroutine
block|,
comment|/* some fortran block types */
name|dst_block_block_data
block|,
name|dst_block_stmt_function
block|,
name|dst_block_package
block|,
comment|/* a few particular to Ada */
name|dst_block_package_body
block|,
name|dst_block_subunit
block|,
name|dst_block_task
block|,
name|dst_block_file
block|,
comment|/* a C outer scope? */
name|dst_block_class
block|,
comment|/* C++ or Simula */
name|dst_block_END_OF_ENUM
block|}
name|dst_block_type_t
typedef|;
end_typedef

begin_comment
comment|/* Block attributes.  This is the information used by the debugger to represent    the semantics of blocks.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_block_main_entry
block|,
comment|/* the block's entry point is a main entry into 				   the compilation unit */
name|dst_block_executable
block|,
comment|/* the block has an entry point */
name|dst_block_attr_END_OF_ENUM
block|}
name|dst_block_attr_t
typedef|;
end_typedef

begin_comment
comment|/* Code range.  Each block has associated with it one or more code ranges. An    individual code range is identified by a range of source (possibly nil) and    a range of executable code.  For example, a block which has its executable    code spread over multiple sections will have one code range per section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|code_size
decl_stmt|;
comment|/* size of executable code (in bytes ) */
name|dst_sect_ref_t
name|code_start
decl_stmt|;
comment|/* starting address of executable code */
name|dst_sect_ref_t
name|lines_start
decl_stmt|;
comment|/* start of line number tables */
block|}
name|dst_code_range_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_block_type_t
name|block_type
range|:
literal|8
decl_stmt|;
name|unsigned
name|short
name|flags
range|:
literal|8
decl_stmt|;
comment|/* mask of dst_block_attr_t flags */
name|dst_rel_offset_t
name|sibling_block_off
decl_stmt|;
comment|/* offset to next sibling block */
name|dst_rel_offset_t
name|child_block_off
decl_stmt|;
comment|/* offset to first contained block */
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to block name string */
name|dst_sect_ref_t
name|symbols_start
decl_stmt|;
comment|/* start of debug symbols  */
name|unsigned
name|short
name|n_of_code_ranges
decl_stmt|;
comment|/* size of array... */
name|dst_code_range_t
name|code_ranges
index|[
name|dst_dummy_array_size
index|]
name|ALIGNED1
decl_stmt|;
block|}
name|dst_rec_block_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------------------   AUX SECT INFO TABLE record   --------------------------   Appears as an auxiliary to a block record.  Expands code range information   by providing references into additional, language-dependent sections for    information related to specific code ranges of the block.  Sect info table   entries parallel code range array entries of the same index. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|tag
decl_stmt|;
comment|/* currently can only be zero */
name|unsigned
name|char
name|number_of_refs
decl_stmt|;
comment|/* size of array: */
name|dst_sect_ref_t
name|refs
index|[
name|dst_dummy_array_size
index|]
name|ALIGNED1
decl_stmt|;
block|}
name|dst_rec_sect_info_tab_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*=================================================*/
end_comment

begin_comment
comment|/*========== RECORDS IN .symbols SECTION ==========*/
end_comment

begin_comment
comment|/*=================================================*/
end_comment

begin_comment
comment|/*-----------------   CONSTANT record   -----------------   Describes a symbolic constant. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|r
decl_stmt|;
comment|/* real part */
name|float
name|i
decl_stmt|;
comment|/* imaginary part */
block|}
name|dst_complex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|dr
decl_stmt|;
comment|/* real part */
name|double
name|di
decl_stmt|;
comment|/* imaginary part */
block|}
name|dst_double_complex_t
typedef|;
end_typedef

begin_comment
comment|/* The following record provides a way of describing constant values with     non-standard type and no limit on size.   */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|char_data
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
name|short
name|int_data
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
name|long
name|long_data
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|dst_big_kon_t
typedef|;
end_typedef

begin_comment
comment|/* Representation of the value of a general constant.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* size of constant value (bytes) */
union|union
block|{
name|unsigned
name|short
name|kon_int8
decl_stmt|;
name|short
name|kon_int16
decl_stmt|;
name|long
name|kon_int32
name|ALIGNED1
decl_stmt|;
name|float
name|kon_real
name|ALIGNED1
decl_stmt|;
name|double
name|kon_dbl
name|ALIGNED1
decl_stmt|;
name|dst_complex_t
name|kon_cplx
name|ALIGNED1
decl_stmt|;
name|dst_double_complex_t
name|kon_dcplx
name|ALIGNED1
decl_stmt|;
name|char
name|kon_char
decl_stmt|;
name|dst_big_kon_t
name|kon
name|ALIGNED1
decl_stmt|;
block|}
name|val
union|;
comment|/* value data of constant */
block|}
name|dst_const_t
name|ALIGNED1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of const definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* type of this (manifest) constant */
name|dst_const_t
name|value
decl_stmt|;
block|}
name|dst_rec_const_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------   VARIABLE record   ----------------   Describes a program variable. */
end_comment

begin_comment
comment|/* Variable attributes.  These define certain variable semantics to the    debugger.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_var_attr_read_only
block|,
comment|/* is read-only (a program literal) */
name|dst_var_attr_volatile
block|,
comment|/* same as compiler's VOLATILE attribute */
name|dst_var_attr_global
block|,
comment|/* is a global definition or reference */
name|dst_var_attr_compiler_gen
block|,
comment|/* is compiler-generated */
name|dst_var_attr_static
block|,
comment|/* has static location */
name|dst_var_attr_END_OF_ENUM
block|}
name|dst_var_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_rel_offset_t
name|loffset
decl_stmt|;
comment|/* offset to loc string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of variable definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* type descriptor */
name|unsigned
name|short
name|attributes
decl_stmt|;
comment|/* mask of dst_var_attr_t flags */
block|}
name|dst_rec_variable_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------   old VAR record  -----------------  Used by older compilers to describe a variable */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_var_loc_unknown
block|,
comment|/* Actually defined as "unknown" */
name|dst_var_loc_abs
block|,
comment|/* Absolute address */
name|dst_var_loc_sect_off
block|,
comment|/* Absolute address as a section offset */
name|dst_var_loc_ind_sect_off
block|,
comment|/* An indexed section offset ???? */
name|dst_var_loc_reg
block|,
comment|/* register */
name|dst_var_loc_reg_rel
block|,
comment|/* register relative - usually fp */
name|dst_var_loc_ind_reg_rel
block|,
comment|/* Indexed register relative */
name|dst_var_loc_ftn_ptr_based
block|,
comment|/* Fortran pointer based */
name|dst_var_loc_pc_rel
block|,
comment|/* PC relative. Really. */
name|dst_var_loc_external
block|,
comment|/* External */
name|dst_var_loc_END_OF_ENUM
block|}
name|dst_var_loc_t
typedef|;
end_typedef

begin_comment
comment|/* Locations come in two versions. The short, and the long. The difference  * between the short and the long is the addition of a statement number  * field to the start andend of the range of the long, and and unkown  * purpose field in the middle. Also, loc_type and loc_index aren't  * bitfields in the long version.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|loc_type
range|:
literal|4
decl_stmt|;
name|unsigned
name|short
name|loc_index
range|:
literal|12
decl_stmt|;
name|long
name|location
decl_stmt|;
name|short
name|start_line
decl_stmt|;
comment|/* start_line and end_line? */
name|short
name|end_line
decl_stmt|;
comment|/* I'm guessing here.       */
block|}
name|dst_var_loc_short_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|loc_type
decl_stmt|;
name|unsigned
name|short
name|loc_index
decl_stmt|;
name|long
name|location
decl_stmt|;
name|short
name|unknown
decl_stmt|;
comment|/* Always 0003 or 3b3c. Why? */
name|short
name|start_statement
decl_stmt|;
name|short
name|start_line
decl_stmt|;
name|short
name|end_statement
decl_stmt|;
name|short
name|end_line
decl_stmt|;
block|}
name|dst_var_loc_long_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of description */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* Type description */
name|unsigned
name|short
name|attributes
decl_stmt|;
comment|/* mask of dst_var_attr_t flags */
name|unsigned
name|short
name|no_of_locs
range|:
literal|15
decl_stmt|;
comment|/* Number of locations */
name|unsigned
name|short
name|short_locs
range|:
literal|1
decl_stmt|;
comment|/* True if short locations. */
union|union
block|{
name|dst_var_loc_short_t
name|shorts
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
name|dst_var_loc_long_t
name|longs
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|locs
union|;
block|}
name|dst_rec_var_t
typedef|;
end_typedef

begin_comment
comment|/*----------------   old LABEL record  -----------------  Used by older compilers to describe a label */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of description */
name|char
name|location
index|[
literal|12
index|]
decl_stmt|;
comment|/* location string */
block|}
name|dst_rec_old_label_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------   POINTER record   ----------------   Describes a pointer type. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to the name string for this type */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* base type of this pointer */
block|}
name|dst_rec_pointer_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-------------   ARRAY record   -------------   Describes an array type.    Multidimensional arrays are described with a number of dst_rec_array_t    records, one per array dimension, each linked to the next through the   elem_type_desc.doffset field.  Each record must have its multi_dim flag   set.    If column_major is true (as with FORTRAN arrays) then the last array bound in   the declaration is the first array index in memory, which is the opposite of   the usual case (as with Pascal and C arrays).    Variable array bounds are described by auxiliary records; if aux_var_bound   records are present, the lo_bound and hi_bound fields of this record are   ignored by the debugger.    span_comp identifies one of the language-dependent ways in which the distance   between successive array elements (span) is calculated.        dst_use_span_field    -- the span is the value of span field.      dst_compute_from_prev -- the span is the size of the previous dimension.      dst_compute_from_next -- the span is the size of the next dimension.   In the latter two cases, the span field contains an amount of padding to add   to the size of the appropriate dimension to calculate the span. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_use_span_field
block|,
name|dst_compute_from_prev
block|,
name|dst_compute_from_next
block|,
name|dst_span_comp_END_OF_ENUM
block|}
name|dst_span_comp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_type_t
name|elem_type_desc
decl_stmt|;
comment|/* array element type */
name|dst_type_t
name|indx_type_desc
decl_stmt|;
comment|/* array index type */
name|long
name|lo_bound
decl_stmt|;
comment|/* lower bound of index */
name|long
name|hi_bound
decl_stmt|;
comment|/* upper bound of index */
name|unsigned
name|long
name|span
decl_stmt|;
comment|/* see above */
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* total array size (bytes) */
name|boolean
name|multi_dim
range|:
literal|1
decl_stmt|;
name|boolean
name|is_packed
range|:
literal|1
decl_stmt|;
comment|/* true if packed array */
name|boolean
name|is_signed
range|:
literal|1
decl_stmt|;
comment|/* true if packed elements are signed */
name|dst_span_comp_t
name|span_comp
range|:
literal|2
decl_stmt|;
comment|/* how to compute span */
name|boolean
name|column_major
range|:
literal|1
decl_stmt|;
name|unsigned
name|short
name|reserved
range|:
literal|2
decl_stmt|;
comment|/* must be zero */
name|unsigned
name|short
name|elem_size
range|:
literal|8
decl_stmt|;
comment|/* element size if packed (bits) */
block|}
name|dst_rec_array_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------   SUBRANGE record   -----------------   Describes a subrange type. */
end_comment

begin_comment
comment|/* Variable subrange bounds are described by auxiliary records; if aux_var_bound    records are present, the lo_bound and hi_bound fields of this record are    ignored by the debugger.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of subrange definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* parent type */
name|long
name|lo_bound
decl_stmt|;
comment|/* lower bound of subrange */
name|long
name|hi_bound
decl_stmt|;
comment|/* upper bound of subrange */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
block|}
name|dst_rec_subrange_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*---------------   STRING record    ---------------   Describes a string type. */
end_comment

begin_comment
comment|/* Variable subrange bounds are described by auxiliary records; if aux_var_bound    records are present, the lo_bound and hi_bound fields of this record are    ignored by the debugger.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of string definition */
name|dst_type_t
name|elem_type_desc
decl_stmt|;
comment|/* element type */
name|dst_type_t
name|indx_type_desc
decl_stmt|;
comment|/* index type */
name|long
name|lo_bound
decl_stmt|;
comment|/* lower bound */
name|long
name|hi_bound
decl_stmt|;
comment|/* upper bound */
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* total string size (bytes) if fixed */
block|}
name|dst_rec_string_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*---------------   SET record    ---------------   Describes a set type. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* element type */
name|unsigned
name|short
name|nbits
decl_stmt|;
comment|/* number of bits in set */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
block|}
name|dst_rec_set_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------   IMPLICIT ENUMERATION record    -----------------------------   Describes an enumeration type with implicit element values = 0, 1, 2, ...   (Pascal-style). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|unsigned
name|short
name|nelems
decl_stmt|;
comment|/* number of elements in enumeration */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
comment|/* offsets to name strings of elements 0, 1, 2, ... */
name|dst_rel_offset_t
name|elem_noffsets
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|dst_rec_implicit_enum_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------   EXPLICIT ENUMERATION record    -----------------------------   Describes an enumeration type with explicitly assigned element values   (C-style). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to element name string */
name|long
name|value
decl_stmt|;
comment|/* element value */
block|}
name|dst_enum_elem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|unsigned
name|short
name|nelems
decl_stmt|;
comment|/* number of elements in enumeration */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
comment|/* name/value pairs, one describing each enumeration value: */
name|dst_enum_elem_t
name|elems
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|dst_rec_explicit_enum_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------   RECORD / UNION record    -----------------------   Describes a record (struct) or union.    If the record is larger than 2**16 bytes then an attached aux record   specifies its size.  Also, if the record is stored in short form then   attached records specify field offsets larger than 2**16 bytes.    Whether the fields[] array or sfields[] array is used is selected by   the dst_rec_type_t of the overall dst record. */
end_comment

begin_comment
comment|/*    Record field descriptor, short form.  This form handles only fields which    are an even number of bytes long, located some number of bytes from the    start of the record.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to field name string */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* field type */
name|unsigned
name|short
name|foffset
decl_stmt|;
comment|/* field offset from start of record (bytes) */
block|}
name|dst_short_field_t
name|ALIGNED1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* field type */
name|unsigned
name|short
name|foffset
decl_stmt|;
comment|/* byte offset */
name|unsigned
name|short
name|is_packed
range|:
literal|1
decl_stmt|;
comment|/* True if field is packed */
name|unsigned
name|short
name|bit_offset
range|:
literal|6
decl_stmt|;
comment|/* Bit offset */
name|unsigned
name|short
name|size
range|:
literal|6
decl_stmt|;
comment|/* Size in bits */
name|unsigned
name|short
name|sign
range|:
literal|1
decl_stmt|;
comment|/* True if signed */
name|unsigned
name|short
name|pad
range|:
literal|2
decl_stmt|;
comment|/* Padding. Must be 0 */
block|}
name|dst_old_field_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/* Tag enumeration for long record field descriptor:  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_field_byte
block|,
name|dst_field_bit
block|,
name|dst_field_loc
block|,
name|dst_field_END_OF_ENUM
block|}
name|dst_field_format_t
typedef|;
end_typedef

begin_comment
comment|/*    Record field descriptor, long form.  The format of the field information    is identified by the format_tag, which contains one of the above values.    The field_byte variant is equivalent to the short form of field descriptor.    The field_bit variant handles fields which are any number of bits long,    located some number of bits from the start of the record.  The field_loc    variant allows the location of the field to be described by a general loc    string.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name of field */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* type of field */
union|union
block|{
struct|struct
block|{
name|dst_field_format_t
name|format_tag
range|:
literal|2
decl_stmt|;
comment|/* dst_field_byte */
name|unsigned
name|long
name|offset
range|:
literal|30
decl_stmt|;
comment|/* offset of field in bytes */
block|}
name|field_byte
name|ALIGNED1
struct|;
struct|struct
block|{
name|dst_field_format_t
name|format_tag
range|:
literal|2
decl_stmt|;
comment|/* dst_field_bit */
name|unsigned
name|long
name|nbits
range|:
literal|6
decl_stmt|;
comment|/* bit size of field */
name|unsigned
name|long
name|is_signed
range|:
literal|1
decl_stmt|;
comment|/* signed/unsigned attribute */
name|unsigned
name|long
name|bit_offset
range|:
literal|3
decl_stmt|;
comment|/* bit offset from byte boundary */
name|int
name|pad
range|:
literal|4
decl_stmt|;
comment|/* must be zero */
name|unsigned
name|short
name|byte_offset
decl_stmt|;
comment|/* offset of byte boundary */
block|}
name|field_bit
name|ALIGNED1
struct|;
struct|struct
block|{
name|dst_field_format_t
name|format_tag
range|:
literal|2
decl_stmt|;
comment|/* dst_field_loc */
name|int
name|loffset
range|:
literal|30
decl_stmt|;
comment|/* dst_rel_offset_t to loc string */
block|}
name|field_loc
name|ALIGNED1
struct|;
block|}
name|f
name|ALIGNED1
union|;
block|}
name|dst_field_t
typedef|;
end_typedef

begin_comment
comment|/* The field_loc.loffset field is a 30-bit signed value.  Some versions of C do    not support signed bit fields.  The following macro will extract that field    as a signed value:  */
end_comment

begin_define
define|#
directive|define
name|dst_field_loffset
parameter_list|(
name|field_rec
parameter_list|)
define|\
value|( ((int) ((field_rec).f.field_loc.loffset<< 2))>> 2 )
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to record name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line where this record is defined */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
name|unsigned
name|short
name|nfields
decl_stmt|;
comment|/* number of fields in this record */
union|union
block|{
name|dst_field_t
name|fields
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
name|dst_short_field_t
name|sfields
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
name|dst_old_field_t
name|ofields
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|f
union|;
comment|/* array of fields */
block|}
name|dst_rec_record_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-------------   FILE record   -------------   Describes a file type. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line where type was defined */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* file element type */
block|}
name|dst_rec_file_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*---------------   OFFSET record    ---------------    Describes a Pascal offset type.    (This type, an undocumented Domain Pascal extension, is currently not    supported by the debugger) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to the name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_type_t
name|area_type_desc
decl_stmt|;
comment|/* area type */
name|dst_type_t
name|base_type_desc
decl_stmt|;
comment|/* base type */
name|long
name|lo_bound
decl_stmt|;
comment|/* low bound of the offset range */
name|long
name|hi_bound
decl_stmt|;
comment|/* high bound of the offset range */
name|long
name|bias
decl_stmt|;
comment|/* bias */
name|unsigned
name|short
name|scale
decl_stmt|;
comment|/* scale factor */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* storage size (bytes) */
block|}
name|dst_rec_offset_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------   ALIAS record    --------------   Describes a type alias (e.g., typedef). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_type_t
name|type_desc
decl_stmt|;
comment|/* parent type */
block|}
name|dst_rec_alias_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*------------------   SIGNATURE record   ------------------   Describes a procedure/function type. */
end_comment

begin_comment
comment|/* Enumeration of argument semantics.  Note that most are mutually    exclusive.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_arg_attr_val
block|,
comment|/* passed by value */
name|dst_arg_attr_ref
block|,
comment|/* passed by reference */
name|dst_arg_attr_name
block|,
comment|/* passed by name */
name|dst_arg_attr_in
block|,
comment|/* readable in the callee */
name|dst_arg_attr_out
block|,
comment|/* writable in the callee */
name|dst_arg_attr_hidden
block|,
comment|/* not visible in the caller */
name|dst_arg_attr_END_OF_ENUM
block|}
name|dst_arg_attr_t
typedef|;
end_typedef

begin_comment
comment|/* Argument descriptor.  Actually points to a variable record for most of the    information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|var_offset
decl_stmt|;
comment|/* offset to variable record */
name|unsigned
name|short
name|attributes
decl_stmt|;
comment|/* a mask of dst_arg_attr_t flags */
block|}
name|dst_arg_t
name|ALIGNED1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of function definition */
name|dst_rel_offset_t
name|result
decl_stmt|;
comment|/* offset to function result variable record */
name|unsigned
name|short
name|nargs
decl_stmt|;
comment|/* number of arguments */
name|dst_arg_t
name|args
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|dst_rec_signature_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------   SCOPE record   --------------   Obsolete. Use the new ENTRY type instead.   Old compilers may put this in as the first entry in a function,   terminated by an end of scope entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* Name offset */
name|dst_src_loc_t
name|start_line
decl_stmt|;
comment|/* Starting line */
name|dst_src_loc_t
name|end_line
decl_stmt|;
comment|/* Ending line */
block|}
name|dst_rec_scope_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------   ENTRY record   --------------   Describes a procedure/function entry point.  An entry record is to a   signature record roughly as a variable record is to a type descriptor record.    The entry_number field is keyed to the entry numbers in .lines -- the    debugger locates the code location of an entry by searching the line   number table for an entry numbered with the value of entry_number.  The   main entry is numbered zero. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to entry name string */
name|dst_rel_offset_t
name|loffset
decl_stmt|;
comment|/* where to jump to call this entry */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
name|dst_rel_offset_t
name|sig_desc
decl_stmt|;
comment|/* offset to signature descriptor */
name|unsigned
name|int
name|entry_number
range|:
literal|8
decl_stmt|;
name|int
name|pad
range|:
literal|8
decl_stmt|;
comment|/* must be zero */
block|}
name|dst_rec_entry_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------   Old format ENTRY record   -----------------------   Supposedly obsolete but still used by some compilers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* Offset to entry name string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* Location in source */
name|dst_rel_offset_t
name|sig_desc
decl_stmt|;
comment|/* Signature description */
name|char
name|unknown
index|[
literal|36
index|]
decl_stmt|;
block|}
name|dst_rec_old_entry_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*--------------   LABEL record    --------------   Describes a program label. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|noffset
decl_stmt|;
comment|/* offset to label string */
name|dst_rel_offset_t
name|loffset
decl_stmt|;
comment|/* offset to loc string */
name|dst_src_loc_t
name|src_loc
decl_stmt|;
comment|/* file/line of definition */
block|}
name|dst_rec_label_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------   AUXILIARY SIZE record   -----------------------   May appear in the auxiliary record list of any type or variable record to   modify the default size of the type or variable. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* size (bytes) */
block|}
name|dst_rec_aux_size_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------   AUXILIARY ALIGN record   -----------------------   May appear in the auxiliary record list of any type or variable record to   modify the default alignment of the type or variable. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|alignment
decl_stmt|;
comment|/* # of low order zero bits */
block|}
name|dst_rec_aux_align_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------   AUXILIARY FIELD SIZE record   -----------------------------   May appear in the auxiliary record list of any RECORD/UNION record to    modify the default size of a field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|field_no
decl_stmt|;
comment|/* field number */
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* size (bits) */
block|}
name|dst_rec_aux_field_size_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------   AUXILIARY FIELD OFFSET record   -----------------------------   May appear in the auxiliary record list of any RECORD/UNION record to    specify a field offset larger than 2**16. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|field_no
decl_stmt|;
comment|/* field number */
name|unsigned
name|long
name|foffset
decl_stmt|;
comment|/* offset */
block|}
name|dst_rec_aux_field_off_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------------   AUXILIARY FIELD ALIGN record   -----------------------------   May appear in the auxiliary record list of any RECORD/UNION record to    modify the default alignment of a field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|field_no
decl_stmt|;
comment|/* field number */
name|unsigned
name|short
name|alignment
decl_stmt|;
comment|/* number of low order zero bits */
block|}
name|dst_rec_aux_field_align_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------------------   AUXILIARY VAR BOUND record   ----------------------------   May appear in the auxiliary record list of any ARRAY, SUBRANGE or STRING   record to describe a variable bound for the range of the type. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_low_bound
block|,
comment|/* the low bound is variable */
name|dst_high_bound
block|,
comment|/* the high bound is variable */
name|dst_var_bound_END_OF_ENUM
block|}
name|dst_var_bound_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|which
decl_stmt|;
comment|/* which bound */
name|dst_rel_offset_t
name|voffset
name|ALIGNED1
decl_stmt|;
comment|/* variable that defines bound */
block|}
name|dst_rec_aux_var_bound_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------   AUXILIARY TYPE DERIVATION record    ----------------------------------   May appear in the auxiliary record list of any RECORD/UNION record to denote   class inheritance of that type from a parent type.    Inheritance implies that it is possible to convert the inheritor type to the   inherited type, retaining those fields which were inherited.  To allow this,   orig_field_no, a field number into the record type, is provided.  If    orig_is_pointer is false, then the start of the inherited record is located   at the location of the field indexed by orig_field_no.  If orig_is_pointer   is true, then it is located at the address contained in the field indexed   by orig_field_no (assumed to be a pointer). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_type_t
name|parent_type
decl_stmt|;
comment|/* reference to inherited type */
name|unsigned
name|short
name|orig_field_no
decl_stmt|;
name|boolean
name|orig_is_pointer
range|:
literal|1
decl_stmt|;
name|int
name|unused
range|:
literal|15
decl_stmt|;
comment|/* must be zero */
block|}
name|dst_rec_aux_type_deriv_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*------------------------------------   AUXILIARY VARIABLE LIFETIME record   ------------------------------------   May appear in the auxiliary record list of a VARIABLE record to add location   information for an additional variable lifetime. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|loffset
decl_stmt|;
block|}
name|dst_rec_aux_lifetime_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-------------------------------   AUXILIARY POINTER BASE record    -------------------------------   May appear in the auxiliary record list of a VARIABLE record to provide a   pointer base to substitute for references to any such bases in the location   string of the variable.  A pointer base is another VARIABLE record.  When   the variable is evaluated by the debugger, it uses the current value of the   pointer base variable in computing its location.    This is useful for representing FORTRAN pointer-based variables. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|voffset
decl_stmt|;
block|}
name|dst_rec_aux_ptr_base_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------   AUXILIARY REGISTER VALUE record    ---------------------------------   May appear in the auxiliary record list of an ENTRY record to specify   a register that must be set to a specific value before jumping to the entry   point in a debugger "call".  The debugger must set the debuggee register,   specified by the register code, to the value of the *address* to which the   location string resolves.  If the address is register-relative, then the   call cannot be made unless the current stack frame is the lexical parent   of the entry.  An example of this is when a (Pascal) nested procedure   contains references to its parent's variables, which it accesses through   a static link register.  The static link register must be set to some   address relative to the parent's stack base register. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|reg
decl_stmt|;
comment|/* identifies register to set (isp enum) */
name|dst_rel_offset_t
name|loffset
decl_stmt|;
comment|/* references a location string */
block|}
name|dst_rec_aux_reg_val_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*==========================================================*/
end_comment

begin_comment
comment|/*========== RECORDS USED IN .blocks AND .symbols ==========*/
end_comment

begin_comment
comment|/*==========================================================*/
end_comment

begin_comment
comment|/*---------------------   STRING TABLE record   ---------------------   A string table record contains any number of null-terminated, variable length   strings.   The length field gives the size in bytes of the text field, which   can be any size.    The global name table shares this format.  This record appears in the   .blocks section.  Each string in the table identifies a global defined in   the current compilation unit.    The loc pool record shares this format as well.  Loc strings are described   elsewhere. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|length
decl_stmt|;
name|char
name|text
index|[
name|dst_dummy_array_size
index|]
decl_stmt|;
block|}
name|dst_rec_string_tab_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-----------------------   AUXILIARY QUAL record    -----------------------   May appear in the auxiliary record list of any BLOCK, VARIABLE, or type record   to provide it with a fully-qualified, language-dependent name. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|lang_qual_name
decl_stmt|;
block|}
name|dst_rec_aux_qual_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*----------------   FORWARD record   ----------------   Reference to a record somewhere else.  This allows identical definitions in   different scopes to share data. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rel_offset_t
name|rec_off
decl_stmt|;
block|}
name|dst_rec_forward_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*-------------------------------   AUXILIARY SOURCE RANGE record   -------------------------------   May appear in the auxiliary record list of any BLOCK record to specify a   range of source lines over which the block is active. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_src_loc_t
name|first_line
decl_stmt|;
comment|/* first source line */
name|dst_src_loc_t
name|last_line
decl_stmt|;
comment|/* last source line */
block|}
name|dst_rec_aux_src_range_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*------------------   EXTENSION record    ------------------   Provision for "foreign" records, such as might be generated by a non-Apollo   compiler.  Apollo software will ignore these. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|rec_size
decl_stmt|;
comment|/* record size (bytes) */
name|unsigned
name|short
name|ext_type
decl_stmt|;
comment|/* defined by whoever generates it */
name|unsigned
name|short
name|ext_data
decl_stmt|;
comment|/* place-holder for arbitrary amount of data */
block|}
name|dst_rec_extension_t
name|ALIGNED1
typedef|;
end_typedef

begin_comment
comment|/*    ** DEBUG SYMBOL record -- The wrapper for all .blocks and .symbols records.    **    ** This record ties together all previous .blocks and .symbols records     ** together in a union with a common header.  The rec_type field of the    ** header identifies the record type.  The rec_flags field currently only    ** defines auxiliary record lists.     **    ** If a record carries with it a non-null auxiliary record list, its    ** dst_flag_has_aux_recs flag is set, and each of the records that follow    ** it are treated as its auxiliary records, until the end of the compilation    ** unit or scope is reached, or until an auxiliary record with its    ** dst_flag_last_aux_rec flag set is reached.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_flag_has_aux_recs
block|,
name|dst_flag_last_aux_rec
block|,
name|dst_rec_flag_END_OF_ENUM
block|}
name|dst_rec_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|dst_rec_type_t
name|rec_type
range|:
literal|8
decl_stmt|;
comment|/* record type */
name|int
name|rec_flags
range|:
literal|8
decl_stmt|;
comment|/* mask of dst_rec_flags_t */
union|union
comment|/* switched on rec_type field above */
block|{
comment|/* dst_typ_pad requires no additional fields */
name|dst_rec_comp_unit_t
name|comp_unit_
decl_stmt|;
name|dst_rec_section_tab_t
name|section_tab_
decl_stmt|;
name|dst_rec_file_tab_t
name|file_tab_
decl_stmt|;
name|dst_rec_block_t
name|block_
decl_stmt|;
name|dst_rec_var_t
name|var_
decl_stmt|;
name|dst_rec_pointer_t
name|pointer_
decl_stmt|;
name|dst_rec_array_t
name|array_
decl_stmt|;
name|dst_rec_subrange_t
name|subrange_
decl_stmt|;
name|dst_rec_set_t
name|set_
decl_stmt|;
name|dst_rec_implicit_enum_t
name|implicit_enum_
decl_stmt|;
name|dst_rec_explicit_enum_t
name|explicit_enum_
decl_stmt|;
comment|/* dst_typ_short_{rec,union} are represented by 'rec' (below) */
name|dst_rec_file_t
name|file_
decl_stmt|;
name|dst_rec_offset_t
name|offset_
decl_stmt|;
name|dst_rec_alias_t
name|alias_
decl_stmt|;
name|dst_rec_signature_t
name|signature_
decl_stmt|;
name|dst_rec_old_label_t
name|old_label_
decl_stmt|;
name|dst_rec_scope_t
name|scope_
decl_stmt|;
comment|/* dst_typ_end_scope requires no additional fields */
name|dst_rec_string_tab_t
name|string_tab_
decl_stmt|;
comment|/* dst_typ_global_name_tab is represented by 'string_tab' (above) */
name|dst_rec_forward_t
name|forward_
decl_stmt|;
name|dst_rec_aux_size_t
name|aux_size_
decl_stmt|;
name|dst_rec_aux_align_t
name|aux_align_
decl_stmt|;
name|dst_rec_aux_field_size_t
name|aux_field_size_
decl_stmt|;
name|dst_rec_aux_field_off_t
name|aux_field_off_
decl_stmt|;
name|dst_rec_aux_field_align_t
name|aux_field_align_
decl_stmt|;
name|dst_rec_aux_qual_t
name|aux_qual_
decl_stmt|;
name|dst_rec_aux_var_bound_t
name|aux_var_bound_
decl_stmt|;
name|dst_rec_extension_t
name|extension_
decl_stmt|;
name|dst_rec_string_t
name|string_
decl_stmt|;
name|dst_rec_const_t
name|const_
decl_stmt|;
comment|/* dst_typ_reference is represented by 'pointer' (above) */
name|dst_rec_record_t
name|record_
decl_stmt|;
comment|/* dst_typ_union is represented by 'record' (above) */
name|dst_rec_aux_type_deriv_t
name|aux_type_deriv_
decl_stmt|;
comment|/* dst_typ_locpool is represented by 'string_tab' (above) */
name|dst_rec_variable_t
name|variable_
decl_stmt|;
name|dst_rec_label_t
name|label_
decl_stmt|;
name|dst_rec_entry_t
name|entry_
decl_stmt|;
name|dst_rec_aux_lifetime_t
name|aux_lifetime_
decl_stmt|;
name|dst_rec_aux_ptr_base_t
name|aux_ptr_base_
decl_stmt|;
name|dst_rec_aux_src_range_t
name|aux_src_range_
decl_stmt|;
name|dst_rec_aux_reg_val_t
name|aux_reg_val_
decl_stmt|;
name|dst_rec_name_tab_t
name|aux_unit_names_
decl_stmt|;
name|dst_rec_sect_info_tab_t
name|aux_sect_info_
decl_stmt|;
block|}
name|rec_data
name|ALIGNED1
union|;
block|}
name|dst_rec_t
operator|,
typedef|*
name|dst_rec_ptr_t
typedef|;
end_typedef

begin_comment
comment|/*===============================================*/
end_comment

begin_comment
comment|/*========== .lines SECTION DEFINITIONS =========*/
end_comment

begin_comment
comment|/*===============================================*/
end_comment

begin_comment
comment|/*    The .lines section contains a sequence of line number tables.  There is no    record structure within the section.  The start of the table for a routine    is pointed to by the block record, and the end of the table is signaled by    an escape code.     A line number table is a sequence of bytes.  The default entry contains a line    number delta (-7..+7) in the high 4 bits and a pc delta (0..15) in the low 4     bits. Special cases, including when one or both of the values is too large    to fit in 4 bits and other special cases are handled through escape entries.    Escape entries are identified by the value 0x8 in the high 4 bits.  The low 4    bits are occupied by a function code.  Some escape entries are followed by    additional arguments, which may be bytes, words, or longwords.  This data is    not aligned.      The initial PC offset, file number and line number are zero.  Normally, the    table begins with a dst_ln_file escape which establishes the initial file    and line number.  All PC deltas are unsigned (thus the table is ordered by    increasing PC); line number deltas are signed.  The table ends with a     dst_ln_end escape, which is followed by a final table entry whose PC delta    gives the code size of the last statement.     Escape     Semantic    ---------  ------------------------------------------------------------    file       Changes file state.  The current source file remains constant    until another file escape.  Though the line number state is    also updated by a file escape, a file escape does NOT     constitute a line table entry.     statement  Alters the statement number of the next table entry.  By     default, all table entries refer to the first statement on a    line.  Statement number one is the second statement, and so on.     entry      Identifies the next table entry as the position of an entry     point for the current block.  The PC position should follow     any procedure prologue code.  An argument specifies the entry    number, which is keyed to the entry number of the corresponding    .symbols ENTRY record.     exit       Identifies the next table entry as the last position within     the current block before a procedure epiloge and subsequent    procedure exit.     gap        By default, the executable code corresponding to a table entry     is assumed to extend to the beginning of the next table entry.    If this is not the case--there is a "hole" in the table--then    a gap escape should follow the first table entry to specify    where the code for that entry ends.  */
end_comment

begin_define
define|#
directive|define
name|dst_ln_escape_flag
value|-8
end_define

begin_comment
comment|/*    Escape function codes:  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_ln_pad
block|,
comment|/* pad byte */
name|dst_ln_file
block|,
comment|/* file escape.  Next 4 bytes are a dst_src_loc_t */
name|dst_ln_dln1_dpc1
block|,
comment|/* 1 byte line delta, 1 byte pc delta */
name|dst_ln_dln2_dpc2
block|,
comment|/* 2 bytes line delta, 2 bytes pc delta */
name|dst_ln_ln4_pc4
block|,
comment|/* 4 bytes ABSOLUTE line number, 4 bytes ABSOLUTE pc */
name|dst_ln_dln1_dpc0
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
name|dst_ln_escape_11
block|,
comment|/* reserved */
name|dst_ln_escape_12
block|,
comment|/* reserved */
name|dst_ln_escape_13
block|,
comment|/* reserved */
name|dst_ln_nxt_byte
block|,
comment|/* next byte contains the real escape code */
name|dst_ln_end
block|,
comment|/* end escape, final entry follows */
name|dst_ln_escape_END_OF_ENUM
block|}
name|dst_ln_escape_t
typedef|;
end_typedef

begin_comment
comment|/*    Line number table entry  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|unsigned
name|int
name|ln_delta
range|:
literal|4
decl_stmt|;
comment|/* 4 bit line number delta */
name|unsigned
name|int
name|pc_delta
range|:
literal|4
decl_stmt|;
comment|/* 4 bit pc delta */
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
comment|/* alias for ln_delta */
name|dst_ln_escape_t
name|esc_code
range|:
literal|4
decl_stmt|;
comment|/* escape function code */
block|}
name|esc
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
operator|,
name|dst_ln_table_t
index|[
name|dst_dummy_array_size
index|]
typedef|;
end_typedef

begin_comment
comment|/* The following macro will extract the ln_delta field as a signed value:  */
end_comment

begin_define
define|#
directive|define
name|dst_ln_ln_delta
parameter_list|(
name|ln_rec
parameter_list|)
define|\
value|( ((short) ((ln_rec).delta.ln_delta<< 12))>> 12 )
end_define

begin_typedef
typedef|typedef
struct|struct
name|dst_sec_struct
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
name|long
name|position
decl_stmt|;
name|long
name|size
decl_stmt|;
name|long
name|base
decl_stmt|;
block|}
name|dst_sec
typedef|;
end_typedef

begin_comment
comment|/* Macros for access to the data */
end_comment

begin_define
define|#
directive|define
name|DST_comp_unit
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.comp_unit_)
end_define

begin_define
define|#
directive|define
name|DST_section_tab
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.section_tab_)
end_define

begin_define
define|#
directive|define
name|DST_file_tab
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.file_tab_)
end_define

begin_define
define|#
directive|define
name|DST_block
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.block_)
end_define

begin_define
define|#
directive|define
name|DST_var
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.var_)
end_define

begin_define
define|#
directive|define
name|DST_pointer
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.pointer_)
end_define

begin_define
define|#
directive|define
name|DST_array
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.array_)
end_define

begin_define
define|#
directive|define
name|DST_subrange
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.subrange_)
end_define

begin_define
define|#
directive|define
name|DST_set
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.set_)
end_define

begin_define
define|#
directive|define
name|DST_implicit_enum
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.implicit_enum_)
end_define

begin_define
define|#
directive|define
name|DST_explicit_enum
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.explicit_enum_)
end_define

begin_define
define|#
directive|define
name|DST_short_rec
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.record_)
end_define

begin_define
define|#
directive|define
name|DST_short_union
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.record_)
end_define

begin_define
define|#
directive|define
name|DST_file
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.file_)
end_define

begin_define
define|#
directive|define
name|DST_offset
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.offset_)
end_define

begin_define
define|#
directive|define
name|DST_alias
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.alias_)
end_define

begin_define
define|#
directive|define
name|DST_signature
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.signature_)
end_define

begin_define
define|#
directive|define
name|DST_old_label
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.old_label_)
end_define

begin_define
define|#
directive|define
name|DST_scope
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.scope_)
end_define

begin_define
define|#
directive|define
name|DST_string_tab
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.string_tab_)
end_define

begin_define
define|#
directive|define
name|DST_global_name_tab
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.string_tab_)
end_define

begin_define
define|#
directive|define
name|DST_forward
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.forward_)
end_define

begin_define
define|#
directive|define
name|DST_aux_size
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_size_)
end_define

begin_define
define|#
directive|define
name|DST_aux_align
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_align_)
end_define

begin_define
define|#
directive|define
name|DST_aux_field_size
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_field_size_)
end_define

begin_define
define|#
directive|define
name|DST_aux_field_off
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_field_off_)
end_define

begin_define
define|#
directive|define
name|DST_aux_field_align
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_field_align_)
end_define

begin_define
define|#
directive|define
name|DST_aux_qual
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_qual_)
end_define

begin_define
define|#
directive|define
name|DST_aux_var_bound
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_var_bound_)
end_define

begin_define
define|#
directive|define
name|DST_extension
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.extension_)
end_define

begin_define
define|#
directive|define
name|DST_string
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.string_)
end_define

begin_define
define|#
directive|define
name|DST_const
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.const_)
end_define

begin_define
define|#
directive|define
name|DST_reference
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.pointer_)
end_define

begin_define
define|#
directive|define
name|DST_record
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.record_)
end_define

begin_define
define|#
directive|define
name|DST_union
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.record_)
end_define

begin_define
define|#
directive|define
name|DST_aux_type_deriv
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_type_deriv_)
end_define

begin_define
define|#
directive|define
name|DST_locpool
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.string_tab_)
end_define

begin_define
define|#
directive|define
name|DST_variable
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.variable_)
end_define

begin_define
define|#
directive|define
name|DST_label
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.label_)
end_define

begin_define
define|#
directive|define
name|DST_entry
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.entry_)
end_define

begin_define
define|#
directive|define
name|DST_aux_lifetime
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_lifetime_)
end_define

begin_define
define|#
directive|define
name|DST_aux_ptr_base
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_ptr_base_)
end_define

begin_define
define|#
directive|define
name|DST_aux_src_range
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_src_range_)
end_define

begin_define
define|#
directive|define
name|DST_aux_reg_val
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_reg_val_)
end_define

begin_define
define|#
directive|define
name|DST_aux_unit_names
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_unit_names_)
end_define

begin_define
define|#
directive|define
name|DST_aux_sect_info
parameter_list|(
name|x
parameter_list|)
value|((x)->rec_data.aux_sect_info_)
end_define

begin_comment
comment|/*  * Type codes for loc strings. I'm not entirely certain about all of  * these, but they seem to work.  *                              troy@cbme.unsw.EDU.AU  * If you find a variable whose location can't be decoded, you should  * find out it's code using "dstdump -s filename". It will record an  * entry for the variable, and give a text representation of what  * the locstring means. Before that explaination there will be a  * number. In the LOCSTRING table, that number will appear before  * the start of the location string. Location string codes are  * five bit codes with a 3 bit argument. Check the high 5 bits of  * the one byte code, and figure out where it goes in here.  * Then figure out exactly what the meaning is and code it in  * dstread.c  *  * Note that ranged locs mean that the variable is in different locations  * depending on the current PC. We ignore these because (a) gcc can't handle  * them, and (b), If you don't use high levels of optimisation they won't  * occur.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dst_lsc_end
block|,
comment|/* End of string */
name|dst_lsc_indirect
block|,
comment|/* Indirect through previous. Arg == 6 */
comment|/* Or register ax (x=arg) */
name|dst_lsc_dreg
block|,
comment|/* register dx (x=arg) */
name|dst_lsc_03
block|,
name|dst_lsc_section
block|,
comment|/* Section (arg+1) */
name|dst_lsc_05
block|,
name|dst_lsc_06
block|,
name|dst_lsc_add
block|,
comment|/* Add (arg+1)*2 */
name|dst_lsc_sub
block|,
comment|/* Subtract (arg+1)*2 */
name|dst_lsc_09
block|,
name|dst_lsc_0a
block|,
name|dst_lsc_sec_byte
block|,
comment|/* Section of next byte+1 */
name|dst_lsc_add_byte
block|,
comment|/* Add next byte (arg == 5) or next word 				 * (arg == 6) 				 */
name|dst_lsc_sub_byte
block|,
comment|/* Subtract next byte. (arg == 1) or next 				 * word (arg == 6 ?) 				 */
name|dst_lsc_sbreg
block|,
comment|/* Stack base register (frame pointer). Arg==0 */
name|dst_lsc_0f
block|,
name|dst_lsc_ranged
block|,
comment|/* location is pc dependent */
name|dst_lsc_11
block|,
name|dst_lsc_12
block|,
name|dst_lsc_13
block|,
name|dst_lsc_14
block|,
name|dst_lsc_15
block|,
name|dst_lsc_16
block|,
name|dst_lsc_17
block|,
name|dst_lsc_18
block|,
name|dst_lsc_19
block|,
name|dst_lsc_1a
block|,
name|dst_lsc_1b
block|,
name|dst_lsc_1c
block|,
name|dst_lsc_1d
block|,
name|dst_lsc_1e
block|,
name|dst_lsc_1f
block|}
name|dst_loc_string_code_t
typedef|;
end_typedef

begin_comment
comment|/* If the following occurs after an addition/subtraction, that addition  * or subtraction should be multiplied by 256. It's a complete byte, not  * a code.  */
end_comment

begin_define
define|#
directive|define
name|dst_multiply_256
value|((char) 0x73)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|code
range|:
literal|5
decl_stmt|;
name|char
name|arg
range|:
literal|3
decl_stmt|;
block|}
name|dst_loc_header_t
name|ALIGNED1
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|dst_loc_header_t
name|header
decl_stmt|;
name|char
name|data
decl_stmt|;
block|}
name|dst_loc_entry_t
name|ALIGNED1
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|ALIGNED1
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo_dst_h */
end_comment

end_unit

