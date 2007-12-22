begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Abstraction of various C++ ABI's we support, and the info we need    to get from them.    Contributed by Daniel Berlin<dberlin@redhat.com>    Copyright 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or    modify    it under the terms of the GNU General Public License as published    by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CP_ABI_H_
end_ifndef

begin_define
define|#
directive|define
name|CP_ABI_H_
value|1
end_define

begin_struct_decl
struct_decl|struct
name|fn_field
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_comment
comment|/* The functions here that attempt to determine what sort of thing a    mangled name refers to may well be revised in the future.  It would    certainly be cleaner to carry this information explicitly in GDB's    data structures than to derive it from the mangled name.  */
end_comment

begin_comment
comment|/* Kinds of constructors.  All these values are guaranteed to be    non-zero.  */
end_comment

begin_enum
enum|enum
name|ctor_kinds
block|{
comment|/* Initialize a complete object, including virtual bases, using      memory provided by caller.  */
name|complete_object_ctor
init|=
literal|1
block|,
comment|/* Initialize a base object of some larger object.  */
name|base_object_ctor
block|,
comment|/* An allocating complete-object constructor.  */
name|complete_object_allocating_ctor
block|}
enum|;
end_enum

begin_comment
comment|/* Return non-zero iff NAME is the mangled name of a constructor.    Actually, return an `enum ctor_kind' value describing what *kind*    of constructor it is.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|ctor_kinds
name|is_constructor_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Kinds of destructors.  All these values are guaranteed to be    non-zero.  */
end_comment

begin_enum
enum|enum
name|dtor_kinds
block|{
comment|/* A destructor which finalizes the entire object, and then calls      `delete' on its storage.  */
name|deleting_dtor
init|=
literal|1
block|,
comment|/* A destructor which finalizes the entire object, but does not call      `delete'.  */
name|complete_object_dtor
block|,
comment|/* A destructor which finalizes a subobject of some larger object.  */
name|base_object_dtor
block|}
enum|;
end_enum

begin_comment
comment|/* Return non-zero iff NAME is the mangled name of a destructor.    Actually, return an `enum dtor_kind' value describing what *kind*    of destructor it is.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|dtor_kinds
name|is_destructor_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero iff NAME is the mangled name of a vtable.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_vtable_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero iff NAME is the un-mangled name of an operator,    perhaps scoped within some class.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_operator_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an object's virtual function as a value.     VALUEP is a pointer to a pointer to a value, holding the object    whose virtual function we want to invoke.  If the ABI requires a    virtual function's caller to adjust the `this' pointer by an amount    retrieved from the vtable before invoking the function (i.e., we're    not using "vtable thunks" to do the adjustment automatically), then    this function may set *VALUEP to point to a new object with an    appropriately tweaked address.     The J'th element of the overload set F is the virtual function of    *VALUEP we want to invoke.     TYPE is the base type of *VALUEP whose method we're invoking ---    this is the type containing F.  OFFSET is the offset of that base    type within *VALUEP.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|value
modifier|*
name|value_virtual_fn_field
parameter_list|(
name|struct
name|value
modifier|*
modifier|*
name|valuep
parameter_list|,
name|struct
name|fn_field
modifier|*
name|f
parameter_list|,
name|int
name|j
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Try to find the run-time type of VALUE, using C++ run-time type    information.  Return the run-time type, or zero if we can't figure    it out.     If we do find the run-time type:    - Set *FULL to non-zero if VALUE already contains the complete      run-time object, not just some embedded base class of the object.    - Set *TOP and *USING_ENC to indicate where the enclosing object      starts relative to VALUE:      - If *USING_ENC is zero, then *TOP is the offset from the start        of the complete object to the start of the embedded subobject        VALUE represents.  In other words, the enclosing object starts        at VALUE_ADDR (VALUE) + VALUE_OFFSET (VALUE) +        VALUE_EMBEDDED_OFFSET (VALUE) + *TOP      - If *USING_ENC is non-zero, then *TOP is the offset from the        address of the complete object to the enclosing object stored        in VALUE.  In other words, the enclosing object starts at        VALUE_ADDR (VALUE) + VALUE_OFFSET (VALUE) + *TOP.      If VALUE's type and enclosing type are the same, then these two      cases are equivalent.     FULL, TOP, and USING_ENC can each be zero, in which case we don't    provide the corresponding piece of information.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|value_rtti_type
parameter_list|(
name|struct
name|value
modifier|*
name|value
parameter_list|,
name|int
modifier|*
name|full
parameter_list|,
name|int
modifier|*
name|top
parameter_list|,
name|int
modifier|*
name|using_enc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute the offset of the baseclass which is    the INDEXth baseclass of class TYPE,    for value at VALADDR (in host) at ADDRESS (in target).    The result is the offset of the baseclass value relative    to (the address of)(ARG) + OFFSET.     -1 is returned on error. */
end_comment

begin_function_decl
specifier|extern
name|int
name|baseclass_offset
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|index
parameter_list|,
name|char
modifier|*
name|valaddr
parameter_list|,
name|CORE_ADDR
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|cp_abi_ops
block|{
specifier|const
name|char
modifier|*
name|shortname
decl_stmt|;
specifier|const
name|char
modifier|*
name|longname
decl_stmt|;
specifier|const
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* ABI-specific implementations for the functions declared above.  */
name|enum
name|ctor_kinds
function_decl|(
modifier|*
name|is_constructor_name
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|enum
name|dtor_kinds
function_decl|(
modifier|*
name|is_destructor_name
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_vtable_name
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_operator_name
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|struct
name|value
modifier|*
function_decl|(
modifier|*
name|virtual_fn_field
function_decl|)
parameter_list|(
name|struct
name|value
modifier|*
modifier|*
name|arg1p
parameter_list|,
name|struct
name|fn_field
modifier|*
name|f
parameter_list|,
name|int
name|j
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
name|struct
name|type
modifier|*
function_decl|(
modifier|*
name|rtti_type
function_decl|)
parameter_list|(
name|struct
name|value
modifier|*
name|v
parameter_list|,
name|int
modifier|*
name|full
parameter_list|,
name|int
modifier|*
name|top
parameter_list|,
name|int
modifier|*
name|using_enc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|baseclass_offset
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|index
parameter_list|,
name|char
modifier|*
name|valaddr
parameter_list|,
name|CORE_ADDR
name|address
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|register_cp_abi
parameter_list|(
name|struct
name|cp_abi_ops
modifier|*
name|abi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_cp_abi_as_auto_default
parameter_list|(
specifier|const
name|char
modifier|*
name|short_name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

