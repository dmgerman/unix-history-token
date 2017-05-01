begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *notice, this list of conditions and the following disclaimer in the  *documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: dwarf.h 3494 2016-09-20 17:16:13Z emaste $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DWARF_H_
end_ifndef

begin_define
define|#
directive|define
name|_DWARF_H_
end_define

begin_define
define|#
directive|define
name|DW_TAG_array_type
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_TAG_class_type
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_TAG_entry_point
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_TAG_enumeration_type
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_TAG_formal_parameter
value|0x05
end_define

begin_define
define|#
directive|define
name|DW_TAG_imported_declaration
value|0x08
end_define

begin_define
define|#
directive|define
name|DW_TAG_label
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_TAG_lexical_block
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_TAG_member
value|0x0d
end_define

begin_define
define|#
directive|define
name|DW_TAG_pointer_type
value|0x0f
end_define

begin_define
define|#
directive|define
name|DW_TAG_reference_type
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_TAG_compile_unit
value|0x11
end_define

begin_define
define|#
directive|define
name|DW_TAG_string_type
value|0x12
end_define

begin_define
define|#
directive|define
name|DW_TAG_structure_type
value|0x13
end_define

begin_define
define|#
directive|define
name|DW_TAG_subroutine_type
value|0x15
end_define

begin_define
define|#
directive|define
name|DW_TAG_typedef
value|0x16
end_define

begin_define
define|#
directive|define
name|DW_TAG_union_type
value|0x17
end_define

begin_define
define|#
directive|define
name|DW_TAG_unspecified_parameters
value|0x18
end_define

begin_define
define|#
directive|define
name|DW_TAG_variant
value|0x19
end_define

begin_define
define|#
directive|define
name|DW_TAG_common_block
value|0x1a
end_define

begin_define
define|#
directive|define
name|DW_TAG_common_inclusion
value|0x1b
end_define

begin_define
define|#
directive|define
name|DW_TAG_inheritance
value|0x1c
end_define

begin_define
define|#
directive|define
name|DW_TAG_inlined_subroutine
value|0x1d
end_define

begin_define
define|#
directive|define
name|DW_TAG_module
value|0x1e
end_define

begin_define
define|#
directive|define
name|DW_TAG_ptr_to_member_type
value|0x1f
end_define

begin_define
define|#
directive|define
name|DW_TAG_set_type
value|0x20
end_define

begin_define
define|#
directive|define
name|DW_TAG_subrange_type
value|0x21
end_define

begin_define
define|#
directive|define
name|DW_TAG_with_stmt
value|0x22
end_define

begin_define
define|#
directive|define
name|DW_TAG_access_declaration
value|0x23
end_define

begin_define
define|#
directive|define
name|DW_TAG_base_type
value|0x24
end_define

begin_define
define|#
directive|define
name|DW_TAG_catch_block
value|0x25
end_define

begin_define
define|#
directive|define
name|DW_TAG_const_type
value|0x26
end_define

begin_define
define|#
directive|define
name|DW_TAG_constant
value|0x27
end_define

begin_define
define|#
directive|define
name|DW_TAG_enumerator
value|0x28
end_define

begin_define
define|#
directive|define
name|DW_TAG_friend
value|0x2a
end_define

begin_define
define|#
directive|define
name|DW_TAG_namelist
value|0x2b
end_define

begin_define
define|#
directive|define
name|DW_TAG_namelist_item
value|0x2c
end_define

begin_define
define|#
directive|define
name|DW_TAG_packed_type
value|0x2d
end_define

begin_define
define|#
directive|define
name|DW_TAG_subprogram
value|0x2e
end_define

begin_define
define|#
directive|define
name|DW_TAG_template_type_parameter
value|0x2f
end_define

begin_define
define|#
directive|define
name|DW_TAG_template_type_param
value|0x2f
end_define

begin_define
define|#
directive|define
name|DW_TAG_template_value_parameter
value|0x30
end_define

begin_define
define|#
directive|define
name|DW_TAG_template_value_param
value|0x30
end_define

begin_define
define|#
directive|define
name|DW_TAG_thrown_type
value|0x31
end_define

begin_define
define|#
directive|define
name|DW_TAG_try_block
value|0x32
end_define

begin_define
define|#
directive|define
name|DW_TAG_variant_part
value|0x33
end_define

begin_define
define|#
directive|define
name|DW_TAG_variable
value|0x34
end_define

begin_define
define|#
directive|define
name|DW_TAG_volatile_type
value|0x35
end_define

begin_define
define|#
directive|define
name|DW_TAG_dwarf_procedure
value|0x36
end_define

begin_define
define|#
directive|define
name|DW_TAG_restrict_type
value|0x37
end_define

begin_define
define|#
directive|define
name|DW_TAG_interface_type
value|0x38
end_define

begin_define
define|#
directive|define
name|DW_TAG_namespace
value|0x39
end_define

begin_define
define|#
directive|define
name|DW_TAG_imported_module
value|0x3a
end_define

begin_define
define|#
directive|define
name|DW_TAG_unspecified_type
value|0x3b
end_define

begin_define
define|#
directive|define
name|DW_TAG_partial_unit
value|0x3c
end_define

begin_define
define|#
directive|define
name|DW_TAG_imported_unit
value|0x3d
end_define

begin_define
define|#
directive|define
name|DW_TAG_condition
value|0x3f
end_define

begin_define
define|#
directive|define
name|DW_TAG_shared_type
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_TAG_type_unit
value|0x41
end_define

begin_define
define|#
directive|define
name|DW_TAG_rvalue_reference_type
value|0x42
end_define

begin_define
define|#
directive|define
name|DW_TAG_template_alias
value|0x43
end_define

begin_define
define|#
directive|define
name|DW_TAG_lo_user
value|0x4080
end_define

begin_define
define|#
directive|define
name|DW_TAG_hi_user
value|0xffff
end_define

begin_comment
comment|/* GNU extensions. */
end_comment

begin_define
define|#
directive|define
name|DW_TAG_format_label
value|0x4101
end_define

begin_define
define|#
directive|define
name|DW_TAG_function_template
value|0x4102
end_define

begin_define
define|#
directive|define
name|DW_TAG_class_template
value|0x4103
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_BINCL
value|0x4104
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_EINCL
value|0x4105
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_template_template_parameter
value|0x4106
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_template_template_param
value|0x4106
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_template_parameter_pack
value|0x4107
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_formal_parameter_pack
value|0x4108
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_call_site
value|0x4109
end_define

begin_define
define|#
directive|define
name|DW_TAG_GNU_call_site_parameter
value|0x410a
end_define

begin_define
define|#
directive|define
name|DW_CHILDREN_no
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_CHILDREN_yes
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_AT_sibling
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_AT_location
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_AT_name
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_AT_ordering
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_AT_subscr_data
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_AT_byte_size
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_AT_bit_offset
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_AT_bit_size
value|0x0d
end_define

begin_define
define|#
directive|define
name|DW_AT_element_list
value|0x0f
end_define

begin_define
define|#
directive|define
name|DW_AT_stmt_list
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_AT_low_pc
value|0x11
end_define

begin_define
define|#
directive|define
name|DW_AT_high_pc
value|0x12
end_define

begin_define
define|#
directive|define
name|DW_AT_language
value|0x13
end_define

begin_define
define|#
directive|define
name|DW_AT_member
value|0x14
end_define

begin_define
define|#
directive|define
name|DW_AT_discr
value|0x15
end_define

begin_define
define|#
directive|define
name|DW_AT_discr_value
value|0x16
end_define

begin_define
define|#
directive|define
name|DW_AT_visibility
value|0x17
end_define

begin_define
define|#
directive|define
name|DW_AT_import
value|0x18
end_define

begin_define
define|#
directive|define
name|DW_AT_string_length
value|0x19
end_define

begin_define
define|#
directive|define
name|DW_AT_common_reference
value|0x1a
end_define

begin_define
define|#
directive|define
name|DW_AT_comp_dir
value|0x1b
end_define

begin_define
define|#
directive|define
name|DW_AT_const_value
value|0x1c
end_define

begin_define
define|#
directive|define
name|DW_AT_containing_type
value|0x1d
end_define

begin_define
define|#
directive|define
name|DW_AT_default_value
value|0x1e
end_define

begin_define
define|#
directive|define
name|DW_AT_inline
value|0x20
end_define

begin_define
define|#
directive|define
name|DW_AT_is_optional
value|0x21
end_define

begin_define
define|#
directive|define
name|DW_AT_lower_bound
value|0x22
end_define

begin_define
define|#
directive|define
name|DW_AT_producer
value|0x25
end_define

begin_define
define|#
directive|define
name|DW_AT_prototyped
value|0x27
end_define

begin_define
define|#
directive|define
name|DW_AT_return_addr
value|0x2a
end_define

begin_define
define|#
directive|define
name|DW_AT_start_scope
value|0x2c
end_define

begin_define
define|#
directive|define
name|DW_AT_bit_stride
value|0x2e
end_define

begin_define
define|#
directive|define
name|DW_AT_stride_size
value|0x2e
end_define

begin_define
define|#
directive|define
name|DW_AT_upper_bound
value|0x2f
end_define

begin_define
define|#
directive|define
name|DW_AT_abstract_origin
value|0x31
end_define

begin_define
define|#
directive|define
name|DW_AT_accessibility
value|0x32
end_define

begin_define
define|#
directive|define
name|DW_AT_address_class
value|0x33
end_define

begin_define
define|#
directive|define
name|DW_AT_artificial
value|0x34
end_define

begin_define
define|#
directive|define
name|DW_AT_base_types
value|0x35
end_define

begin_define
define|#
directive|define
name|DW_AT_calling_convention
value|0x36
end_define

begin_define
define|#
directive|define
name|DW_AT_count
value|0x37
end_define

begin_define
define|#
directive|define
name|DW_AT_data_member_location
value|0x38
end_define

begin_define
define|#
directive|define
name|DW_AT_decl_column
value|0x39
end_define

begin_define
define|#
directive|define
name|DW_AT_decl_file
value|0x3a
end_define

begin_define
define|#
directive|define
name|DW_AT_decl_line
value|0x3b
end_define

begin_define
define|#
directive|define
name|DW_AT_declaration
value|0x3c
end_define

begin_define
define|#
directive|define
name|DW_AT_discr_list
value|0x3d
end_define

begin_define
define|#
directive|define
name|DW_AT_encoding
value|0x3e
end_define

begin_define
define|#
directive|define
name|DW_AT_external
value|0x3f
end_define

begin_define
define|#
directive|define
name|DW_AT_frame_base
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_AT_friend
value|0x41
end_define

begin_define
define|#
directive|define
name|DW_AT_identifier_case
value|0x42
end_define

begin_define
define|#
directive|define
name|DW_AT_macro_info
value|0x43
end_define

begin_define
define|#
directive|define
name|DW_AT_namelist_item
value|0x44
end_define

begin_define
define|#
directive|define
name|DW_AT_priority
value|0x45
end_define

begin_define
define|#
directive|define
name|DW_AT_segment
value|0x46
end_define

begin_define
define|#
directive|define
name|DW_AT_specification
value|0x47
end_define

begin_define
define|#
directive|define
name|DW_AT_static_link
value|0x48
end_define

begin_define
define|#
directive|define
name|DW_AT_type
value|0x49
end_define

begin_define
define|#
directive|define
name|DW_AT_use_location
value|0x4a
end_define

begin_define
define|#
directive|define
name|DW_AT_variable_parameter
value|0x4b
end_define

begin_define
define|#
directive|define
name|DW_AT_virtuality
value|0x4c
end_define

begin_define
define|#
directive|define
name|DW_AT_vtable_elem_location
value|0x4d
end_define

begin_define
define|#
directive|define
name|DW_AT_allocated
value|0x4e
end_define

begin_define
define|#
directive|define
name|DW_AT_associated
value|0x4f
end_define

begin_define
define|#
directive|define
name|DW_AT_data_location
value|0x50
end_define

begin_define
define|#
directive|define
name|DW_AT_byte_stride
value|0x51
end_define

begin_define
define|#
directive|define
name|DW_AT_entry_pc
value|0x52
end_define

begin_define
define|#
directive|define
name|DW_AT_use_UTF8
value|0x53
end_define

begin_define
define|#
directive|define
name|DW_AT_extension
value|0x54
end_define

begin_define
define|#
directive|define
name|DW_AT_ranges
value|0x55
end_define

begin_define
define|#
directive|define
name|DW_AT_trampoline
value|0x56
end_define

begin_define
define|#
directive|define
name|DW_AT_call_column
value|0x57
end_define

begin_define
define|#
directive|define
name|DW_AT_call_file
value|0x58
end_define

begin_define
define|#
directive|define
name|DW_AT_call_line
value|0x59
end_define

begin_define
define|#
directive|define
name|DW_AT_description
value|0x5a
end_define

begin_define
define|#
directive|define
name|DW_AT_binary_scale
value|0x5b
end_define

begin_define
define|#
directive|define
name|DW_AT_decimal_scale
value|0x5c
end_define

begin_define
define|#
directive|define
name|DW_AT_small
value|0x5d
end_define

begin_define
define|#
directive|define
name|DW_AT_decimal_sign
value|0x5e
end_define

begin_define
define|#
directive|define
name|DW_AT_digit_count
value|0x5f
end_define

begin_define
define|#
directive|define
name|DW_AT_picture_string
value|0x60
end_define

begin_define
define|#
directive|define
name|DW_AT_mutable
value|0x61
end_define

begin_define
define|#
directive|define
name|DW_AT_threads_scaled
value|0x62
end_define

begin_define
define|#
directive|define
name|DW_AT_explicit
value|0x63
end_define

begin_define
define|#
directive|define
name|DW_AT_object_pointer
value|0x64
end_define

begin_define
define|#
directive|define
name|DW_AT_endianity
value|0x65
end_define

begin_define
define|#
directive|define
name|DW_AT_elemental
value|0x66
end_define

begin_define
define|#
directive|define
name|DW_AT_pure
value|0x67
end_define

begin_define
define|#
directive|define
name|DW_AT_recursive
value|0x68
end_define

begin_define
define|#
directive|define
name|DW_AT_signature
value|0x69
end_define

begin_define
define|#
directive|define
name|DW_AT_main_subprogram
value|0x6a
end_define

begin_define
define|#
directive|define
name|DW_AT_data_bit_offset
value|0x6b
end_define

begin_define
define|#
directive|define
name|DW_AT_const_expr
value|0x6c
end_define

begin_define
define|#
directive|define
name|DW_AT_enum_class
value|0x6d
end_define

begin_define
define|#
directive|define
name|DW_AT_linkage_name
value|0x6e
end_define

begin_define
define|#
directive|define
name|DW_AT_lo_user
value|0x2000
end_define

begin_define
define|#
directive|define
name|DW_AT_hi_user
value|0x3fff
end_define

begin_comment
comment|/* SGI/MIPS extensions. */
end_comment

begin_define
define|#
directive|define
name|DW_AT_MIPS_fde
value|0x2001
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_loop_begin
value|0x2002
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_tail_loop_begin
value|0x2003
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_epilog_begin
value|0x2004
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_loop_unroll_factor
value|0x2005
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_software_pipeline_depth
value|0x2006
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_linkage_name
value|0x2007
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_stride
value|0x2008
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_abstract_name
value|0x2009
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_clone_origin
value|0x200a
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_has_inlines
value|0x200b
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_stride_byte
value|0x200c
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_stride_elem
value|0x200d
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_ptr_dopetype
value|0x200e
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_allocatable_dopetype
value|0x200f
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_assumed_shape_dopetype
value|0x2010
end_define

begin_define
define|#
directive|define
name|DW_AT_MIPS_assumed_size
value|0x2011
end_define

begin_comment
comment|/* GNU extensions. */
end_comment

begin_define
define|#
directive|define
name|DW_AT_sf_names
value|0x2101
end_define

begin_define
define|#
directive|define
name|DW_AT_src_info
value|0x2102
end_define

begin_define
define|#
directive|define
name|DW_AT_mac_info
value|0x2103
end_define

begin_define
define|#
directive|define
name|DW_AT_src_coords
value|0x2104
end_define

begin_define
define|#
directive|define
name|DW_AT_body_begin
value|0x2105
end_define

begin_define
define|#
directive|define
name|DW_AT_body_end
value|0x2106
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_vector
value|0x2107
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_guarded_by
value|0x2108
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_pt_guarded_by
value|0x2109
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_guarded
value|0x210a
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_pt_guarded
value|0x210b
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_locks_excluded
value|0x210c
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_exclusive_locks_required
value|0x210d
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_shared_locks_required
value|0x210e
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_odr_signature
value|0x210f
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_template_name
value|0x2110
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_call_site_value
value|0x2111
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_call_site_data_value
value|0x2112
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_call_site_target
value|0x2113
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_call_site_target_clobbered
value|0x2114
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_tail_call
value|0x2115
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_all_tail_call_sites
value|0x2116
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_all_call_sites
value|0x2117
end_define

begin_define
define|#
directive|define
name|DW_AT_GNU_all_source_call_sites
value|0x2118
end_define

begin_comment
comment|/* Apple extensions. */
end_comment

begin_define
define|#
directive|define
name|DW_AT_APPLE_optimized
value|0x3fe1
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_flags
value|0x3fe2
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_isa
value|0x3fe3
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_block
value|0x3fe4
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_major_runtime_vers
value|0x3fe5
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_runtime_class
value|0x3fe6
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_omit_frame_ptr
value|0x3fe7
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_property_name
value|0x3fe8
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_property_getter
value|0x3fe9
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_property_setter
value|0x3fea
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_property_attribute
value|0x3feb
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_objc_complete_type
value|0x3fec
end_define

begin_define
define|#
directive|define
name|DW_AT_APPLE_property
value|0x3fed
end_define

begin_define
define|#
directive|define
name|DW_FORM_addr
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_FORM_block2
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_FORM_block4
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_FORM_data2
value|0x05
end_define

begin_define
define|#
directive|define
name|DW_FORM_data4
value|0x06
end_define

begin_define
define|#
directive|define
name|DW_FORM_data8
value|0x07
end_define

begin_define
define|#
directive|define
name|DW_FORM_string
value|0x08
end_define

begin_define
define|#
directive|define
name|DW_FORM_block
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_FORM_block1
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_FORM_data1
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_FORM_flag
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_FORM_sdata
value|0x0d
end_define

begin_define
define|#
directive|define
name|DW_FORM_strp
value|0x0e
end_define

begin_define
define|#
directive|define
name|DW_FORM_udata
value|0x0f
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref_addr
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref1
value|0x11
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref2
value|0x12
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref4
value|0x13
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref8
value|0x14
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref_udata
value|0x15
end_define

begin_define
define|#
directive|define
name|DW_FORM_indirect
value|0x16
end_define

begin_define
define|#
directive|define
name|DW_FORM_sec_offset
value|0x17
end_define

begin_define
define|#
directive|define
name|DW_FORM_exprloc
value|0x18
end_define

begin_define
define|#
directive|define
name|DW_FORM_flag_present
value|0x19
end_define

begin_define
define|#
directive|define
name|DW_FORM_ref_sig8
value|0x20
end_define

begin_define
define|#
directive|define
name|DW_FORM_GNU_ref_alt
value|0x1f20
end_define

begin_define
define|#
directive|define
name|DW_FORM_GNU_strp_alt
value|0x1f21
end_define

begin_define
define|#
directive|define
name|DW_OP_addr
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_OP_deref
value|0x06
end_define

begin_define
define|#
directive|define
name|DW_OP_const1u
value|0x08
end_define

begin_define
define|#
directive|define
name|DW_OP_const1s
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_OP_const2u
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_OP_const2s
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_OP_const4u
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_OP_const4s
value|0x0d
end_define

begin_define
define|#
directive|define
name|DW_OP_const8u
value|0x0e
end_define

begin_define
define|#
directive|define
name|DW_OP_const8s
value|0x0f
end_define

begin_define
define|#
directive|define
name|DW_OP_constu
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_OP_consts
value|0x11
end_define

begin_define
define|#
directive|define
name|DW_OP_dup
value|0x12
end_define

begin_define
define|#
directive|define
name|DW_OP_drop
value|0x13
end_define

begin_define
define|#
directive|define
name|DW_OP_over
value|0x14
end_define

begin_define
define|#
directive|define
name|DW_OP_pick
value|0x15
end_define

begin_define
define|#
directive|define
name|DW_OP_swap
value|0x16
end_define

begin_define
define|#
directive|define
name|DW_OP_rot
value|0x17
end_define

begin_define
define|#
directive|define
name|DW_OP_xderef
value|0x18
end_define

begin_define
define|#
directive|define
name|DW_OP_abs
value|0x19
end_define

begin_define
define|#
directive|define
name|DW_OP_and
value|0x1a
end_define

begin_define
define|#
directive|define
name|DW_OP_div
value|0x1b
end_define

begin_define
define|#
directive|define
name|DW_OP_minus
value|0x1c
end_define

begin_define
define|#
directive|define
name|DW_OP_mod
value|0x1d
end_define

begin_define
define|#
directive|define
name|DW_OP_mul
value|0x1e
end_define

begin_define
define|#
directive|define
name|DW_OP_neg
value|0x1f
end_define

begin_define
define|#
directive|define
name|DW_OP_not
value|0x20
end_define

begin_define
define|#
directive|define
name|DW_OP_or
value|0x21
end_define

begin_define
define|#
directive|define
name|DW_OP_plus
value|0x22
end_define

begin_define
define|#
directive|define
name|DW_OP_plus_uconst
value|0x23
end_define

begin_define
define|#
directive|define
name|DW_OP_shl
value|0x24
end_define

begin_define
define|#
directive|define
name|DW_OP_shr
value|0x25
end_define

begin_define
define|#
directive|define
name|DW_OP_shra
value|0x26
end_define

begin_define
define|#
directive|define
name|DW_OP_xor
value|0x27
end_define

begin_define
define|#
directive|define
name|DW_OP_bra
value|0x28
end_define

begin_define
define|#
directive|define
name|DW_OP_eq
value|0x29
end_define

begin_define
define|#
directive|define
name|DW_OP_ge
value|0x2a
end_define

begin_define
define|#
directive|define
name|DW_OP_gt
value|0x2b
end_define

begin_define
define|#
directive|define
name|DW_OP_le
value|0x2c
end_define

begin_define
define|#
directive|define
name|DW_OP_lt
value|0x2d
end_define

begin_define
define|#
directive|define
name|DW_OP_ne
value|0x2e
end_define

begin_define
define|#
directive|define
name|DW_OP_skip
value|0x2f
end_define

begin_define
define|#
directive|define
name|DW_OP_lit0
value|0x30
end_define

begin_define
define|#
directive|define
name|DW_OP_lit1
value|0x31
end_define

begin_define
define|#
directive|define
name|DW_OP_lit2
value|0x32
end_define

begin_define
define|#
directive|define
name|DW_OP_lit3
value|0x33
end_define

begin_define
define|#
directive|define
name|DW_OP_lit4
value|0x34
end_define

begin_define
define|#
directive|define
name|DW_OP_lit5
value|0x35
end_define

begin_define
define|#
directive|define
name|DW_OP_lit6
value|0x36
end_define

begin_define
define|#
directive|define
name|DW_OP_lit7
value|0x37
end_define

begin_define
define|#
directive|define
name|DW_OP_lit8
value|0x38
end_define

begin_define
define|#
directive|define
name|DW_OP_lit9
value|0x39
end_define

begin_define
define|#
directive|define
name|DW_OP_lit10
value|0x3a
end_define

begin_define
define|#
directive|define
name|DW_OP_lit11
value|0x3b
end_define

begin_define
define|#
directive|define
name|DW_OP_lit12
value|0x3c
end_define

begin_define
define|#
directive|define
name|DW_OP_lit13
value|0x3d
end_define

begin_define
define|#
directive|define
name|DW_OP_lit14
value|0x3e
end_define

begin_define
define|#
directive|define
name|DW_OP_lit15
value|0x3f
end_define

begin_define
define|#
directive|define
name|DW_OP_lit16
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_OP_lit17
value|0x41
end_define

begin_define
define|#
directive|define
name|DW_OP_lit18
value|0x42
end_define

begin_define
define|#
directive|define
name|DW_OP_lit19
value|0x43
end_define

begin_define
define|#
directive|define
name|DW_OP_lit20
value|0x44
end_define

begin_define
define|#
directive|define
name|DW_OP_lit21
value|0x45
end_define

begin_define
define|#
directive|define
name|DW_OP_lit22
value|0x46
end_define

begin_define
define|#
directive|define
name|DW_OP_lit23
value|0x47
end_define

begin_define
define|#
directive|define
name|DW_OP_lit24
value|0x48
end_define

begin_define
define|#
directive|define
name|DW_OP_lit25
value|0x49
end_define

begin_define
define|#
directive|define
name|DW_OP_lit26
value|0x4a
end_define

begin_define
define|#
directive|define
name|DW_OP_lit27
value|0x4b
end_define

begin_define
define|#
directive|define
name|DW_OP_lit28
value|0x4c
end_define

begin_define
define|#
directive|define
name|DW_OP_lit29
value|0x4d
end_define

begin_define
define|#
directive|define
name|DW_OP_lit30
value|0x4e
end_define

begin_define
define|#
directive|define
name|DW_OP_lit31
value|0x4f
end_define

begin_define
define|#
directive|define
name|DW_OP_reg0
value|0x50
end_define

begin_define
define|#
directive|define
name|DW_OP_reg1
value|0x51
end_define

begin_define
define|#
directive|define
name|DW_OP_reg2
value|0x52
end_define

begin_define
define|#
directive|define
name|DW_OP_reg3
value|0x53
end_define

begin_define
define|#
directive|define
name|DW_OP_reg4
value|0x54
end_define

begin_define
define|#
directive|define
name|DW_OP_reg5
value|0x55
end_define

begin_define
define|#
directive|define
name|DW_OP_reg6
value|0x56
end_define

begin_define
define|#
directive|define
name|DW_OP_reg7
value|0x57
end_define

begin_define
define|#
directive|define
name|DW_OP_reg8
value|0x58
end_define

begin_define
define|#
directive|define
name|DW_OP_reg9
value|0x59
end_define

begin_define
define|#
directive|define
name|DW_OP_reg10
value|0x5a
end_define

begin_define
define|#
directive|define
name|DW_OP_reg11
value|0x5b
end_define

begin_define
define|#
directive|define
name|DW_OP_reg12
value|0x5c
end_define

begin_define
define|#
directive|define
name|DW_OP_reg13
value|0x5d
end_define

begin_define
define|#
directive|define
name|DW_OP_reg14
value|0x5e
end_define

begin_define
define|#
directive|define
name|DW_OP_reg15
value|0x5f
end_define

begin_define
define|#
directive|define
name|DW_OP_reg16
value|0x60
end_define

begin_define
define|#
directive|define
name|DW_OP_reg17
value|0x61
end_define

begin_define
define|#
directive|define
name|DW_OP_reg18
value|0x62
end_define

begin_define
define|#
directive|define
name|DW_OP_reg19
value|0x63
end_define

begin_define
define|#
directive|define
name|DW_OP_reg20
value|0x64
end_define

begin_define
define|#
directive|define
name|DW_OP_reg21
value|0x65
end_define

begin_define
define|#
directive|define
name|DW_OP_reg22
value|0x66
end_define

begin_define
define|#
directive|define
name|DW_OP_reg23
value|0x67
end_define

begin_define
define|#
directive|define
name|DW_OP_reg24
value|0x68
end_define

begin_define
define|#
directive|define
name|DW_OP_reg25
value|0x69
end_define

begin_define
define|#
directive|define
name|DW_OP_reg26
value|0x6a
end_define

begin_define
define|#
directive|define
name|DW_OP_reg27
value|0x6b
end_define

begin_define
define|#
directive|define
name|DW_OP_reg28
value|0x6c
end_define

begin_define
define|#
directive|define
name|DW_OP_reg29
value|0x6d
end_define

begin_define
define|#
directive|define
name|DW_OP_reg30
value|0x6e
end_define

begin_define
define|#
directive|define
name|DW_OP_reg31
value|0x6f
end_define

begin_define
define|#
directive|define
name|DW_OP_breg0
value|0x70
end_define

begin_define
define|#
directive|define
name|DW_OP_breg1
value|0x71
end_define

begin_define
define|#
directive|define
name|DW_OP_breg2
value|0x72
end_define

begin_define
define|#
directive|define
name|DW_OP_breg3
value|0x73
end_define

begin_define
define|#
directive|define
name|DW_OP_breg4
value|0x74
end_define

begin_define
define|#
directive|define
name|DW_OP_breg5
value|0x75
end_define

begin_define
define|#
directive|define
name|DW_OP_breg6
value|0x76
end_define

begin_define
define|#
directive|define
name|DW_OP_breg7
value|0x77
end_define

begin_define
define|#
directive|define
name|DW_OP_breg8
value|0x78
end_define

begin_define
define|#
directive|define
name|DW_OP_breg9
value|0x79
end_define

begin_define
define|#
directive|define
name|DW_OP_breg10
value|0x7a
end_define

begin_define
define|#
directive|define
name|DW_OP_breg11
value|0x7b
end_define

begin_define
define|#
directive|define
name|DW_OP_breg12
value|0x7c
end_define

begin_define
define|#
directive|define
name|DW_OP_breg13
value|0x7d
end_define

begin_define
define|#
directive|define
name|DW_OP_breg14
value|0x7e
end_define

begin_define
define|#
directive|define
name|DW_OP_breg15
value|0x7f
end_define

begin_define
define|#
directive|define
name|DW_OP_breg16
value|0x80
end_define

begin_define
define|#
directive|define
name|DW_OP_breg17
value|0x81
end_define

begin_define
define|#
directive|define
name|DW_OP_breg18
value|0x82
end_define

begin_define
define|#
directive|define
name|DW_OP_breg19
value|0x83
end_define

begin_define
define|#
directive|define
name|DW_OP_breg20
value|0x84
end_define

begin_define
define|#
directive|define
name|DW_OP_breg21
value|0x85
end_define

begin_define
define|#
directive|define
name|DW_OP_breg22
value|0x86
end_define

begin_define
define|#
directive|define
name|DW_OP_breg23
value|0x87
end_define

begin_define
define|#
directive|define
name|DW_OP_breg24
value|0x88
end_define

begin_define
define|#
directive|define
name|DW_OP_breg25
value|0x89
end_define

begin_define
define|#
directive|define
name|DW_OP_breg26
value|0x8a
end_define

begin_define
define|#
directive|define
name|DW_OP_breg27
value|0x8b
end_define

begin_define
define|#
directive|define
name|DW_OP_breg28
value|0x8c
end_define

begin_define
define|#
directive|define
name|DW_OP_breg29
value|0x8d
end_define

begin_define
define|#
directive|define
name|DW_OP_breg30
value|0x8e
end_define

begin_define
define|#
directive|define
name|DW_OP_breg31
value|0x8f
end_define

begin_define
define|#
directive|define
name|DW_OP_regx
value|0x90
end_define

begin_define
define|#
directive|define
name|DW_OP_fbreg
value|0x91
end_define

begin_define
define|#
directive|define
name|DW_OP_bregx
value|0x92
end_define

begin_define
define|#
directive|define
name|DW_OP_piece
value|0x93
end_define

begin_define
define|#
directive|define
name|DW_OP_deref_size
value|0x94
end_define

begin_define
define|#
directive|define
name|DW_OP_xderef_size
value|0x95
end_define

begin_define
define|#
directive|define
name|DW_OP_nop
value|0x96
end_define

begin_define
define|#
directive|define
name|DW_OP_push_object_address
value|0x97
end_define

begin_define
define|#
directive|define
name|DW_OP_call2
value|0x98
end_define

begin_define
define|#
directive|define
name|DW_OP_call4
value|0x99
end_define

begin_define
define|#
directive|define
name|DW_OP_call_ref
value|0x9a
end_define

begin_define
define|#
directive|define
name|DW_OP_form_tls_address
value|0x9b
end_define

begin_define
define|#
directive|define
name|DW_OP_call_frame_cfa
value|0x9c
end_define

begin_define
define|#
directive|define
name|DW_OP_bit_piece
value|0x9d
end_define

begin_define
define|#
directive|define
name|DW_OP_implicit_value
value|0x9e
end_define

begin_define
define|#
directive|define
name|DW_OP_stack_value
value|0x9f
end_define

begin_define
define|#
directive|define
name|DW_OP_lo_user
value|0xe0
end_define

begin_define
define|#
directive|define
name|DW_OP_hi_user
value|0xff
end_define

begin_comment
comment|/* GNU extensions. */
end_comment

begin_define
define|#
directive|define
name|DW_OP_GNU_push_tls_address
value|0xe0
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_uninit
value|0xf0
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_encoded_addr
value|0xf1
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_implicit_pointer
value|0xf2
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_entry_value
value|0xf3
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_const_type
value|0xf4
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_regval_type
value|0xf5
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_deref_type
value|0xf6
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_convert
value|0xf7
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_reinterpret
value|0xf9
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_parameter_ref
value|0xfa
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_addr_index
value|0xfb
end_define

begin_define
define|#
directive|define
name|DW_OP_GNU_const_index
value|0xfc
end_define

begin_define
define|#
directive|define
name|DW_ATE_address
value|0x1
end_define

begin_define
define|#
directive|define
name|DW_ATE_boolean
value|0x2
end_define

begin_define
define|#
directive|define
name|DW_ATE_complex_float
value|0x3
end_define

begin_define
define|#
directive|define
name|DW_ATE_float
value|0x4
end_define

begin_define
define|#
directive|define
name|DW_ATE_signed
value|0x5
end_define

begin_define
define|#
directive|define
name|DW_ATE_signed_char
value|0x6
end_define

begin_define
define|#
directive|define
name|DW_ATE_unsigned
value|0x7
end_define

begin_define
define|#
directive|define
name|DW_ATE_unsigned_char
value|0x8
end_define

begin_define
define|#
directive|define
name|DW_ATE_imaginary_float
value|0x9
end_define

begin_define
define|#
directive|define
name|DW_ATE_packed_decimal
value|0xa
end_define

begin_define
define|#
directive|define
name|DW_ATE_numeric_string
value|0xb
end_define

begin_define
define|#
directive|define
name|DW_ATE_edited
value|0xc
end_define

begin_define
define|#
directive|define
name|DW_ATE_signed_fixed
value|0xd
end_define

begin_define
define|#
directive|define
name|DW_ATE_unsigned_fixed
value|0xe
end_define

begin_define
define|#
directive|define
name|DW_ATE_decimal_float
value|0xf
end_define

begin_define
define|#
directive|define
name|DW_ATE_lo_user
value|0x80
end_define

begin_define
define|#
directive|define
name|DW_ATE_hi_user
value|0xff
end_define

begin_define
define|#
directive|define
name|DW_ACCESS_public
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_ACCESS_protected
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_ACCESS_private
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_END_default
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_END_big
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_END_little
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_END_lo_user
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_END_high_user
value|0xff
end_define

begin_define
define|#
directive|define
name|DW_VIS_local
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_VIS_exported
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_VIS_qualified
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_VIRTUALITY_none
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_VIRTUALITY_virtual
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_VIRTUALITY_pure_virtual
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_LANG_C89
value|0x0001
end_define

begin_define
define|#
directive|define
name|DW_LANG_C
value|0x0002
end_define

begin_define
define|#
directive|define
name|DW_LANG_Ada83
value|0x0003
end_define

begin_define
define|#
directive|define
name|DW_LANG_C_plus_plus
value|0x0004
end_define

begin_define
define|#
directive|define
name|DW_LANG_Cobol74
value|0x0005
end_define

begin_define
define|#
directive|define
name|DW_LANG_Cobol85
value|0x0006
end_define

begin_define
define|#
directive|define
name|DW_LANG_Fortran77
value|0x0007
end_define

begin_define
define|#
directive|define
name|DW_LANG_Fortran90
value|0x0008
end_define

begin_define
define|#
directive|define
name|DW_LANG_Pascal83
value|0x0009
end_define

begin_define
define|#
directive|define
name|DW_LANG_Modula2
value|0x000a
end_define

begin_define
define|#
directive|define
name|DW_LANG_Java
value|0x000b
end_define

begin_define
define|#
directive|define
name|DW_LANG_C99
value|0x000c
end_define

begin_define
define|#
directive|define
name|DW_LANG_Ada95
value|0x000d
end_define

begin_define
define|#
directive|define
name|DW_LANG_Fortran95
value|0x000e
end_define

begin_define
define|#
directive|define
name|DW_LANG_PLI
value|0x000f
end_define

begin_define
define|#
directive|define
name|DW_LANG_ObjC
value|0x0010
end_define

begin_define
define|#
directive|define
name|DW_LANG_ObjC_plus_plus
value|0x0011
end_define

begin_define
define|#
directive|define
name|DW_LANG_UPC
value|0x0012
end_define

begin_define
define|#
directive|define
name|DW_LANG_D
value|0x0013
end_define

begin_define
define|#
directive|define
name|DW_LANG_lo_user
value|0x8000
end_define

begin_define
define|#
directive|define
name|DW_LANG_Mips_Assembler
value|0x8001
end_define

begin_define
define|#
directive|define
name|DW_LANG_hi_user
value|0xffff
end_define

begin_define
define|#
directive|define
name|DW_ID_case_sensitive
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_ID_up_case
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_ID_down_case
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_ID_case_insensitive
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_CC_normal
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_CC_program
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_CC_nocall
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_CC_lo_user
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_CC_hi_user
value|0xff
end_define

begin_define
define|#
directive|define
name|DW_INL_not_inlined
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_INL_inlined
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_INL_declared_not_inlined
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_INL_declared_inlined
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_ORD_row_major
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_ORD_col_major
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_DS_unsigned
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_DS_leading_overpunch
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_DS_trailing_overpunch
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_DS_leading_separate
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_DS_trailing_separate
value|0x05
end_define

begin_define
define|#
directive|define
name|DW_DSC_label
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_DSC_range
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_LNS_copy
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_LNS_advance_pc
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_LNS_advance_line
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_file
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_column
value|0x05
end_define

begin_define
define|#
directive|define
name|DW_LNS_negate_stmt
value|0x06
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_basic_block
value|0x07
end_define

begin_define
define|#
directive|define
name|DW_LNS_const_add_pc
value|0x08
end_define

begin_define
define|#
directive|define
name|DW_LNS_fixed_advance_pc
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_prologue_end
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_epilogue_begin
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_LNS_set_isa
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_LNE_end_sequence
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_LNE_set_address
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_LNE_define_file
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_LNE_lo_user
value|0x80
end_define

begin_define
define|#
directive|define
name|DW_LNE_hi_user
value|0xff
end_define

begin_define
define|#
directive|define
name|DW_MACINFO_define
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_MACINFO_undef
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_MACINFO_start_file
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_MACINFO_end_file
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_MACINFO_vendor_ext
value|0xff
end_define

begin_define
define|#
directive|define
name|DW_CFA_advance_loc
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_CFA_offset
value|0x80
end_define

begin_define
define|#
directive|define
name|DW_CFA_restore
value|0xc0
end_define

begin_define
define|#
directive|define
name|DW_CFA_extended
value|0
end_define

begin_define
define|#
directive|define
name|DW_CFA_nop
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_CFA_set_loc
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_CFA_advance_loc1
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_CFA_advance_loc2
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_CFA_advance_loc4
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_CFA_offset_extended
value|0x05
end_define

begin_define
define|#
directive|define
name|DW_CFA_restore_extended
value|0x06
end_define

begin_define
define|#
directive|define
name|DW_CFA_undefined
value|0x07
end_define

begin_define
define|#
directive|define
name|DW_CFA_same_value
value|0x08
end_define

begin_define
define|#
directive|define
name|DW_CFA_register
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_CFA_remember_state
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_CFA_restore_state
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa_register
value|0x0d
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa_offset
value|0x0e
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa_expression
value|0x0f
end_define

begin_define
define|#
directive|define
name|DW_CFA_expression
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_CFA_offset_extended_sf
value|0x11
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa_sf
value|0x12
end_define

begin_define
define|#
directive|define
name|DW_CFA_def_cfa_offset_sf
value|0x13
end_define

begin_define
define|#
directive|define
name|DW_CFA_val_offset
value|0x14
end_define

begin_define
define|#
directive|define
name|DW_CFA_val_offset_sf
value|0x15
end_define

begin_define
define|#
directive|define
name|DW_CFA_val_expression
value|0x16
end_define

begin_define
define|#
directive|define
name|DW_CFA_lo_user
value|0x1c
end_define

begin_define
define|#
directive|define
name|DW_CFA_high_user
value|0x3f
end_define

begin_comment
comment|/*  * LSB(Linux Standard Base) extension to DWARF2.  */
end_comment

begin_define
define|#
directive|define
name|DW_EH_PE_absptr
value|0x00
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_uleb128
value|0x01
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_udata2
value|0x02
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_udata4
value|0x03
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_udata8
value|0x04
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_sleb128
value|0x09
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_sdata2
value|0x0a
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_sdata4
value|0x0b
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_sdata8
value|0x0c
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_pcrel
value|0x10
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_textrel
value|0x20
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_datarel
value|0x30
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_funcrel
value|0x40
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_aligned
value|0x50
end_define

begin_define
define|#
directive|define
name|DW_EH_PE_omit
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DWARF_H_ */
end_comment

end_unit

