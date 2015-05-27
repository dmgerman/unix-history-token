begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 2010-2011 PathScale, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS  * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * dwarf_eh.h - Defines some helper functions for parsing DWARF exception  * handling tables.  *  * This file contains various helper functions that are independent of the  * language-specific code.  It can be used in any personality function for the  * Itanium ABI.  */
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|// TODO: Factor out Itanium / ARM differences.  We probably want an itanium.h
end_comment

begin_comment
comment|// and arm.h that can be included by this file depending on the target ABI.
end_comment

begin_comment
comment|// _GNU_SOURCE must be defined for unwind.h to expose some of the functions
end_comment

begin_comment
comment|// that we want.  If it isn't, then we define it and undefine it to make sure
end_comment

begin_comment
comment|// that it doesn't impact the rest of the program.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_undef
undef|#
directive|undef
name|_GNU_SOURCE
end_undef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/// Type used for pointers into DWARF data
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|dw_eh_ptr_t
typedef|;
end_typedef

begin_comment
comment|// Flag indicating a signed quantity
end_comment

begin_define
define|#
directive|define
name|DW_EH_PE_signed
value|0x08
end_define

begin_comment
comment|/// DWARF data encoding types.
end_comment

begin_enum
enum|enum
name|dwarf_data_encoding
block|{
comment|/// Absolute pointer value
name|DW_EH_PE_absptr
init|=
literal|0x00
block|,
comment|/// Unsigned, little-endian, base 128-encoded (variable length).
name|DW_EH_PE_uleb128
init|=
literal|0x01
block|,
comment|/// Unsigned 16-bit integer.
name|DW_EH_PE_udata2
init|=
literal|0x02
block|,
comment|/// Unsigned 32-bit integer.
name|DW_EH_PE_udata4
init|=
literal|0x03
block|,
comment|/// Unsigned 64-bit integer.
name|DW_EH_PE_udata8
init|=
literal|0x04
block|,
comment|/// Signed, little-endian, base 128-encoded (variable length)
name|DW_EH_PE_sleb128
init|=
name|DW_EH_PE_uleb128
operator||
name|DW_EH_PE_signed
block|,
comment|/// Signed 16-bit integer.
name|DW_EH_PE_sdata2
init|=
name|DW_EH_PE_udata2
operator||
name|DW_EH_PE_signed
block|,
comment|/// Signed 32-bit integer.
name|DW_EH_PE_sdata4
init|=
name|DW_EH_PE_udata4
operator||
name|DW_EH_PE_signed
block|,
comment|/// Signed 32-bit integer.
name|DW_EH_PE_sdata8
init|=
name|DW_EH_PE_udata8
operator||
name|DW_EH_PE_signed
block|}
enum|;
end_enum

begin_comment
comment|/**  * Returns the encoding for a DWARF EH table entry.  The encoding is stored in  * the low four of an octet.  The high four bits store the addressing mode.  */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|dwarf_data_encoding
name|get_encoding
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
name|static_cast
operator|<
expr|enum
name|dwarf_data_encoding
operator|>
operator|(
name|x
operator|&
literal|0xf
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * DWARF addressing mode constants.  When reading a pointer value from a DWARF  * exception table, you must know how it is stored and what the addressing mode  * is.  The low four bits tell you the encoding, allowing you to decode a  * number.  The high four bits tell you the addressing mode, allowing you to  * turn that number into an address in memory.  */
end_comment

begin_enum
enum|enum
name|dwarf_data_relative
block|{
comment|/// Value is omitted
name|DW_EH_PE_omit
init|=
literal|0xff
block|,
comment|/// Value relative to program counter
name|DW_EH_PE_pcrel
init|=
literal|0x10
block|,
comment|/// Value relative to the text segment
name|DW_EH_PE_textrel
init|=
literal|0x20
block|,
comment|/// Value relative to the data segment
name|DW_EH_PE_datarel
init|=
literal|0x30
block|,
comment|/// Value relative to the start of the function
name|DW_EH_PE_funcrel
init|=
literal|0x40
block|,
comment|/// Aligned pointer (Not supported yet - are they actually used?)
name|DW_EH_PE_aligned
init|=
literal|0x50
block|,
comment|/// Pointer points to address of real value
name|DW_EH_PE_indirect
init|=
literal|0x80
block|}
enum|;
end_enum

begin_comment
comment|/**  * Returns the addressing mode component of this encoding.  */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|dwarf_data_relative
name|get_base
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
name|static_cast
operator|<
expr|enum
name|dwarf_data_relative
operator|>
operator|(
name|x
operator|&
literal|0x70
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Returns whether an encoding represents an indirect address.  */
end_comment

begin_function
specifier|static
name|int
name|is_indirect
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
operator|(
operator|(
name|x
operator|&
name|DW_EH_PE_indirect
operator|)
operator|==
name|DW_EH_PE_indirect
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Returns the size of a fixed-size encoding.  This function will abort if  * called with a value that is not a fixed-size encoding.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|dwarf_size_of_fixed_size_field
parameter_list|(
name|unsigned
name|char
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|get_encoding
argument_list|(
name|type
argument_list|)
condition|)
block|{
default|default:
name|abort
argument_list|()
expr_stmt|;
case|case
name|DW_EH_PE_sdata2
case|:
case|case
name|DW_EH_PE_udata2
case|:
return|return
literal|2
return|;
case|case
name|DW_EH_PE_sdata4
case|:
case|case
name|DW_EH_PE_udata4
case|:
return|return
literal|4
return|;
case|case
name|DW_EH_PE_sdata8
case|:
case|case
name|DW_EH_PE_udata8
case|:
return|return
literal|8
return|;
case|case
name|DW_EH_PE_absptr
case|:
return|return
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/**   * Read an unsigned, little-endian, base-128, DWARF value.  Updates *data to  * point to the end of the value.  Stores the number of bits read in the value  * pointed to by b, allowing you to determine the value of the highest bit, and  * therefore the sign of a signed value.  *  * This function is not intended to be called directly.  Use read_sleb128() or  * read_uleb128() for reading signed and unsigned versions, respectively.  */
end_comment

begin_function
specifier|static
name|uint64_t
name|read_leb128
parameter_list|(
name|dw_eh_ptr_t
modifier|*
name|data
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
name|uint64_t
name|uleb
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|bit
init|=
literal|0
decl_stmt|;
name|unsigned
name|char
name|digit
init|=
literal|0
decl_stmt|;
comment|// We have to read at least one octet, and keep reading until we get to one
comment|// with the high bit unset
do|do
block|{
comment|// This check is a bit too strict - we should also check the highest
comment|// bit of the digit.
name|assert
argument_list|(
name|bit
operator|<
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|*
literal|8
argument_list|)
expr_stmt|;
comment|// Get the base 128 digit
name|digit
operator|=
operator|(
operator|*
operator|*
name|data
operator|)
operator|&
literal|0x7f
expr_stmt|;
comment|// Add it to the current value
name|uleb
operator|+=
name|digit
operator|<<
name|bit
expr_stmt|;
comment|// Increase the shift value
name|bit
operator|+=
literal|7
expr_stmt|;
comment|// Proceed to the next octet
operator|(
operator|*
name|data
operator|)
operator|++
expr_stmt|;
comment|// Terminate when we reach a value that does not have the high bit set
comment|// (i.e. which was not modified when we mask it with 0x7f)
block|}
do|while
condition|(
operator|(
operator|*
operator|(
operator|*
name|data
operator|-
literal|1
operator|)
operator|)
operator|!=
name|digit
condition|)
do|;
operator|*
name|b
operator|=
name|bit
expr_stmt|;
return|return
name|uleb
return|;
block|}
end_function

begin_comment
comment|/**  * Reads an unsigned little-endian base-128 value starting at the address  * pointed to by *data.  Updates *data to point to the next byte after the end  * of the variable-length value.  */
end_comment

begin_function
specifier|static
name|int64_t
name|read_uleb128
parameter_list|(
name|dw_eh_ptr_t
modifier|*
name|data
parameter_list|)
block|{
name|int
name|b
decl_stmt|;
return|return
name|read_leb128
argument_list|(
name|data
argument_list|,
operator|&
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Reads a signed little-endian base-128 value starting at the address pointed  * to by *data.  Updates *data to point to the next byte after the end of the  * variable-length value.  */
end_comment

begin_function
specifier|static
name|int64_t
name|read_sleb128
parameter_list|(
name|dw_eh_ptr_t
modifier|*
name|data
parameter_list|)
block|{
name|int
name|bits
decl_stmt|;
comment|// Read as if it's signed
name|uint64_t
name|uleb
init|=
name|read_leb128
argument_list|(
name|data
argument_list|,
operator|&
name|bits
argument_list|)
decl_stmt|;
comment|// If the most significant bit read is 1, then we need to sign extend it
if|if
condition|(
operator|(
name|uleb
operator|>>
operator|(
name|bits
operator|-
literal|1
operator|)
operator|)
operator|==
literal|1
condition|)
block|{
comment|// Sign extend by setting all bits in front of it to 1
name|uleb
operator||=
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
operator|-
literal|1
operator|)
operator|<<
name|bits
expr_stmt|;
block|}
return|return
name|static_cast
operator|<
name|int64_t
operator|>
operator|(
name|uleb
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Reads a value using the specified encoding from the address pointed to by  * *data.  Updates the value of *data to point to the next byte after the end  * of the data.  */
end_comment

begin_function
specifier|static
name|uint64_t
name|read_value
parameter_list|(
name|char
name|encoding
parameter_list|,
name|dw_eh_ptr_t
modifier|*
name|data
parameter_list|)
block|{
name|enum
name|dwarf_data_encoding
name|type
init|=
name|get_encoding
argument_list|(
name|encoding
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
comment|// Read fixed-length types
define|#
directive|define
name|READ
parameter_list|(
name|dwarf
parameter_list|,
name|type
parameter_list|)
define|\
value|case dwarf:\ 		{\ 			type t;\ 			memcpy(&t, *data, sizeof t);\ 			*data += sizeof t;\ 			return static_cast<uint64_t>(t);\ 		}
name|READ
argument_list|(
argument|DW_EH_PE_udata2
argument_list|,
argument|uint16_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_udata4
argument_list|,
argument|uint32_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_udata8
argument_list|,
argument|uint64_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_sdata2
argument_list|,
argument|int16_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_sdata4
argument_list|,
argument|int32_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_sdata8
argument_list|,
argument|int64_t
argument_list|)
name|READ
argument_list|(
argument|DW_EH_PE_absptr
argument_list|,
argument|intptr_t
argument_list|)
undef|#
directive|undef
name|READ
comment|// Read variable-length types
case|case
name|DW_EH_PE_sleb128
case|:
return|return
name|read_sleb128
argument_list|(
name|data
argument_list|)
return|;
case|case
name|DW_EH_PE_uleb128
case|:
return|return
name|read_uleb128
argument_list|(
name|data
argument_list|)
return|;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/**  * Resolves an indirect value.  This expects an unwind context, an encoding, a  * decoded value, and the start of the region as arguments.  The returned value  * is a pointer to the address identified by the encoded value.  *  * If the encoding does not specify an indirect value, then this returns v.  */
end_comment

begin_function
specifier|static
name|uint64_t
name|resolve_indirect_value
parameter_list|(
name|_Unwind_Context
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|encoding
parameter_list|,
name|int64_t
name|v
parameter_list|,
name|dw_eh_ptr_t
name|start
parameter_list|)
block|{
switch|switch
condition|(
name|get_base
argument_list|(
name|encoding
argument_list|)
condition|)
block|{
case|case
name|DW_EH_PE_pcrel
case|:
name|v
operator|+=
name|reinterpret_cast
operator|<
name|uint64_t
operator|>
operator|(
name|start
operator|)
expr_stmt|;
break|break;
case|case
name|DW_EH_PE_textrel
case|:
name|v
operator|+=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|_Unwind_GetTextRelBase
argument_list|(
name|c
argument_list|)
operator|)
operator|)
expr_stmt|;
break|break;
case|case
name|DW_EH_PE_datarel
case|:
name|v
operator|+=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|_Unwind_GetDataRelBase
argument_list|(
name|c
argument_list|)
operator|)
operator|)
expr_stmt|;
break|break;
case|case
name|DW_EH_PE_funcrel
case|:
name|v
operator|+=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|_Unwind_GetRegionStart
argument_list|(
name|c
argument_list|)
operator|)
operator|)
expr_stmt|;
default|default:
break|break;
block|}
comment|// If this is an indirect value, then it is really the address of the real
comment|// value
comment|// TODO: Check whether this should really always be a pointer - it seems to
comment|// be a GCC extensions, so not properly documented...
if|if
condition|(
name|is_indirect
argument_list|(
name|encoding
argument_list|)
condition|)
block|{
name|v
operator|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|*
name|reinterpret_cast
operator|<
name|void
operator|*
operator|*
operator|>
operator|(
name|v
operator|)
operator|)
operator|)
expr_stmt|;
block|}
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|/**  * Reads an encoding and a value, updating *data to point to the next byte.    */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|read_value_with_encoding
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|dw_eh_ptr_t
modifier|*
name|data
parameter_list|,
name|uint64_t
modifier|*
name|out
parameter_list|)
block|{
name|dw_eh_ptr_t
name|start
init|=
operator|*
name|data
decl_stmt|;
name|unsigned
name|char
name|encoding
init|=
operator|*
operator|(
operator|(
operator|*
name|data
operator|)
operator|++
operator|)
decl_stmt|;
comment|// If this value is omitted, skip it and don't touch the output value
if|if
condition|(
name|encoding
operator|==
name|DW_EH_PE_omit
condition|)
block|{
return|return;
block|}
operator|*
name|out
operator|=
name|read_value
argument_list|(
name|encoding
argument_list|,
name|data
argument_list|)
expr_stmt|;
operator|*
name|out
operator|=
name|resolve_indirect_value
argument_list|(
name|context
argument_list|,
name|encoding
argument_list|,
operator|*
name|out
argument_list|,
name|start
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Structure storing a decoded language-specific data area.  Use parse_lsda()  * to generate an instance of this structure from the address returned by the  * generic unwind library.    *  * You should not need to inspect the fields of this structure directly if you  * are just using this header.  The structure stores the locations of the  * various tables used for unwinding exceptions and is used by the functions  * for reading values from these tables.  */
end_comment

begin_struct
struct|struct
name|dwarf_eh_lsda
block|{
comment|/// The start of the region.  This is a cache of the value returned by
comment|/// _Unwind_GetRegionStart().
name|dw_eh_ptr_t
name|region_start
decl_stmt|;
comment|/// The start of the landing pads table.
name|dw_eh_ptr_t
name|landing_pads
decl_stmt|;
comment|/// The start of the type table.
name|dw_eh_ptr_t
name|type_table
decl_stmt|;
comment|/// The encoding used for entries in the type tables.
name|unsigned
name|char
name|type_table_encoding
decl_stmt|;
comment|/// The location of the call-site table.
name|dw_eh_ptr_t
name|call_site_table
decl_stmt|;
comment|/// The location of the action table.
name|dw_eh_ptr_t
name|action_table
decl_stmt|;
comment|/// The encoding used for entries in the call-site table.
name|unsigned
name|char
name|callsite_encoding
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Parse the header on the language-specific data area and return a structure  * containing the addresses and encodings of the various tables.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|dwarf_eh_lsda
name|parse_lsda
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
block|{
name|struct
name|dwarf_eh_lsda
name|lsda
decl_stmt|;
name|lsda
operator|.
name|region_start
operator|=
name|reinterpret_cast
operator|<
name|dw_eh_ptr_t
operator|>
operator|(
name|_Unwind_GetRegionStart
argument_list|(
name|context
argument_list|)
operator|)
expr_stmt|;
comment|// If the landing pads are relative to anything other than the start of
comment|// this region, find out where.  This is @LPStart in the spec, although the
comment|// encoding that GCC uses does not quite match the spec.
name|uint64_t
name|v
init|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|lsda
operator|.
name|region_start
operator|)
operator|)
decl_stmt|;
name|read_value_with_encoding
argument_list|(
name|context
argument_list|,
operator|&
name|data
argument_list|,
operator|&
name|v
argument_list|)
expr_stmt|;
name|lsda
operator|.
name|landing_pads
operator|=
name|reinterpret_cast
operator|<
name|dw_eh_ptr_t
operator|>
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|v
operator|)
operator|)
expr_stmt|;
comment|// If there is a type table, find out where it is.  This is @TTBase in the
comment|// spec.  Note: we find whether there is a type table pointer by checking
comment|// whether the leading byte is DW_EH_PE_omit (0xff), which is not what the
comment|// spec says, but does seem to be how G++ indicates this.
name|lsda
operator|.
name|type_table
operator|=
literal|0
expr_stmt|;
name|lsda
operator|.
name|type_table_encoding
operator|=
operator|*
name|data
operator|++
expr_stmt|;
if|if
condition|(
name|lsda
operator|.
name|type_table_encoding
operator|!=
name|DW_EH_PE_omit
condition|)
block|{
name|v
operator|=
name|read_uleb128
argument_list|(
operator|&
name|data
argument_list|)
expr_stmt|;
name|dw_eh_ptr_t
name|type_table
init|=
name|data
decl_stmt|;
name|type_table
operator|+=
name|v
expr_stmt|;
name|lsda
operator|.
name|type_table
operator|=
name|type_table
expr_stmt|;
comment|//lsda.type_table = (uintptr_t*)(data + v);
block|}
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ARM_DWARF_EH__
argument_list|)
name|lsda
operator|.
name|type_table_encoding
operator|=
operator|(
name|DW_EH_PE_pcrel
operator||
name|DW_EH_PE_indirect
operator|)
expr_stmt|;
endif|#
directive|endif
name|lsda
operator|.
name|callsite_encoding
operator|=
name|static_cast
operator|<
expr|enum
name|dwarf_data_encoding
operator|>
operator|(
operator|*
operator|(
name|data
operator|++
operator|)
operator|)
expr_stmt|;
comment|// Action table is immediately after the call site table
name|lsda
operator|.
name|action_table
operator|=
name|data
expr_stmt|;
name|uintptr_t
name|callsite_size
init|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|read_uleb128
argument_list|(
operator|&
name|data
argument_list|)
operator|)
decl_stmt|;
name|lsda
operator|.
name|action_table
operator|=
name|data
operator|+
name|callsite_size
expr_stmt|;
comment|// Call site table is immediately after the header
name|lsda
operator|.
name|call_site_table
operator|=
name|static_cast
operator|<
name|dw_eh_ptr_t
operator|>
operator|(
name|data
operator|)
expr_stmt|;
return|return
name|lsda
return|;
block|}
end_function

begin_comment
comment|/**  * Structure representing an action to be performed while unwinding.  This  * contains the address that should be unwound to and the action record that  * provoked this action.  */
end_comment

begin_struct
struct|struct
name|dwarf_eh_action
block|{
comment|/**  	 * The address that this action directs should be the new program counter 	 * value after unwinding. 	 */
name|dw_eh_ptr_t
name|landing_pad
decl_stmt|;
comment|/// The address of the action record.
name|dw_eh_ptr_t
name|action_record
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Look up the landing pad that corresponds to the current invoke.  * Returns true if record exists.  The context is provided by the generic  * unwind library and the lsda should be the result of a call to parse_lsda().  *  * The action record is returned via the result parameter.    */
end_comment

begin_function
specifier|static
name|bool
name|dwarf_eh_find_callsite
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|struct
name|dwarf_eh_lsda
modifier|*
name|lsda
parameter_list|,
name|struct
name|dwarf_eh_action
modifier|*
name|result
parameter_list|)
block|{
name|result
operator|->
name|action_record
operator|=
literal|0
expr_stmt|;
name|result
operator|->
name|landing_pad
operator|=
literal|0
expr_stmt|;
comment|// The current instruction pointer offset within the region
name|uint64_t
name|ip
init|=
name|_Unwind_GetIP
argument_list|(
name|context
argument_list|)
operator|-
name|_Unwind_GetRegionStart
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|unsigned
name|char
modifier|*
name|callsite_table
init|=
name|static_cast
operator|<
name|unsigned
name|char
operator|*
operator|>
operator|(
name|lsda
operator|->
name|call_site_table
operator|)
decl_stmt|;
while|while
condition|(
name|callsite_table
operator|<=
name|lsda
operator|->
name|action_table
condition|)
block|{
comment|// Once again, the layout deviates from the spec.
name|uint64_t
name|call_site_start
decl_stmt|,
name|call_site_size
decl_stmt|,
name|landing_pad
decl_stmt|,
name|action
decl_stmt|;
name|call_site_start
operator|=
name|read_value
argument_list|(
name|lsda
operator|->
name|callsite_encoding
argument_list|,
operator|&
name|callsite_table
argument_list|)
expr_stmt|;
name|call_site_size
operator|=
name|read_value
argument_list|(
name|lsda
operator|->
name|callsite_encoding
argument_list|,
operator|&
name|callsite_table
argument_list|)
expr_stmt|;
comment|// Call site entries are sorted, so if we find a call site that's after
comment|// the current instruction pointer then there is no action associated
comment|// with this call and we should unwind straight through this frame
comment|// without doing anything.
if|if
condition|(
name|call_site_start
operator|>
name|ip
condition|)
block|{
break|break;
block|}
comment|// Read the address of the landing pad and the action from the call
comment|// site table.
name|landing_pad
operator|=
name|read_value
argument_list|(
name|lsda
operator|->
name|callsite_encoding
argument_list|,
operator|&
name|callsite_table
argument_list|)
expr_stmt|;
name|action
operator|=
name|read_uleb128
argument_list|(
operator|&
name|callsite_table
argument_list|)
expr_stmt|;
comment|// We should not include the call_site_start (beginning of the region)
comment|// address in the ip range. For each call site:
comment|//
comment|// address1: call proc
comment|// address2: next instruction
comment|//
comment|// The call stack contains address2 and not address1, address1 can be
comment|// at the end of another EH region.
if|if
condition|(
name|call_site_start
operator|<
name|ip
operator|&&
name|ip
operator|<=
name|call_site_start
operator|+
name|call_site_size
condition|)
block|{
if|if
condition|(
name|action
condition|)
block|{
comment|// Action records are 1-biased so both no-record and zeroth
comment|// record can be stored.
name|result
operator|->
name|action_record
operator|=
name|lsda
operator|->
name|action_table
operator|+
name|action
operator|-
literal|1
expr_stmt|;
block|}
comment|// No landing pad means keep unwinding.
if|if
condition|(
name|landing_pad
condition|)
block|{
comment|// Landing pad is the offset from the value in the header
name|result
operator|->
name|landing_pad
operator|=
name|lsda
operator|->
name|landing_pads
operator|+
name|landing_pad
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
block|}
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/// Defines an exception class from 8 bytes (endian independent)
end_comment

begin_define
define|#
directive|define
name|EXCEPTION_CLASS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
define|\
value|((static_cast<uint64_t>(a)<< 56) +\ 	 (static_cast<uint64_t>(b)<< 48) +\ 	 (static_cast<uint64_t>(c)<< 40) +\ 	 (static_cast<uint64_t>(d)<< 32) +\ 	 (static_cast<uint64_t>(e)<< 24) +\ 	 (static_cast<uint64_t>(f)<< 16) +\ 	 (static_cast<uint64_t>(g)<< 8) +\ 	 (static_cast<uint64_t>(h)))
end_define

begin_define
define|#
directive|define
name|GENERIC_EXCEPTION_CLASS
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
define|\
value|(static_cast<uint32_t>(e)<< 24) +\ 	 (static_cast<uint32_t>(f)<< 16) +\ 	 (static_cast<uint32_t>(g)<< 8) +\ 	 (static_cast<uint32_t>(h))
end_define

end_unit

