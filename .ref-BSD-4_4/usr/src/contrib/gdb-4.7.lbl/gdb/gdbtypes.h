begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal type definitions for GDB.    Copyright (C) 1992 Free Software Foundation, Inc.    Contributed by Cygnus Support, using pieces from other GDB modules.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDBTYPES_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDBTYPES_H
value|1
end_define

begin_comment
comment|/* When gdb creates fundamental types, it uses one of the following    type identifiers.  The identifiers are used to index a vector of    pointers to any types that are created. */
end_comment

begin_define
define|#
directive|define
name|FT_VOID
value|0
end_define

begin_define
define|#
directive|define
name|FT_BOOLEAN
value|1
end_define

begin_define
define|#
directive|define
name|FT_CHAR
value|2
end_define

begin_define
define|#
directive|define
name|FT_SIGNED_CHAR
value|3
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_CHAR
value|4
end_define

begin_define
define|#
directive|define
name|FT_SHORT
value|5
end_define

begin_define
define|#
directive|define
name|FT_SIGNED_SHORT
value|6
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_SHORT
value|7
end_define

begin_define
define|#
directive|define
name|FT_INTEGER
value|8
end_define

begin_define
define|#
directive|define
name|FT_SIGNED_INTEGER
value|9
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_INTEGER
value|10
end_define

begin_define
define|#
directive|define
name|FT_LONG
value|11
end_define

begin_define
define|#
directive|define
name|FT_SIGNED_LONG
value|12
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_LONG
value|13
end_define

begin_define
define|#
directive|define
name|FT_LONG_LONG
value|14
end_define

begin_define
define|#
directive|define
name|FT_SIGNED_LONG_LONG
value|15
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_LONG_LONG
value|16
end_define

begin_define
define|#
directive|define
name|FT_FLOAT
value|17
end_define

begin_define
define|#
directive|define
name|FT_DBL_PREC_FLOAT
value|18
end_define

begin_define
define|#
directive|define
name|FT_EXT_PREC_FLOAT
value|19
end_define

begin_define
define|#
directive|define
name|FT_COMPLEX
value|20
end_define

begin_define
define|#
directive|define
name|FT_DBL_PREC_COMPLEX
value|21
end_define

begin_define
define|#
directive|define
name|FT_EXT_PREC_COMPLEX
value|22
end_define

begin_define
define|#
directive|define
name|FT_STRING
value|23
end_define

begin_define
define|#
directive|define
name|FT_FIXED_DECIMAL
value|24
end_define

begin_define
define|#
directive|define
name|FT_FLOAT_DECIMAL
value|25
end_define

begin_define
define|#
directive|define
name|FT_NUM_MEMBERS
value|26
end_define

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
name|TYPE_CODE_ERROR
block|,
comment|/* Unknown type */
comment|/* C++ */
name|TYPE_CODE_MEMBER
block|,
comment|/* Member type */
name|TYPE_CODE_METHOD
block|,
comment|/* Method type */
name|TYPE_CODE_REF
block|,
comment|/* C++ Reference types */
comment|/* Modula-2 */
name|TYPE_CODE_CHAR
block|,
comment|/* *real* character type */
name|TYPE_CODE_BOOL
comment|/* Builtin Modula-2 BOOLEAN */
block|}
enum|;
end_enum

begin_comment
comment|/* For now allow source to use TYPE_CODE_CLASS for C++ classes, as an    alias for TYPE_CODE_STRUCT.  Eventually these should probably be    officially distinct types within gdb. */
end_comment

begin_define
define|#
directive|define
name|TYPE_CODE_CLASS
value|TYPE_CODE_STRUCT
end_define

begin_comment
comment|/* Some bits for the type's flags word. */
end_comment

begin_comment
comment|/* Explicitly unsigned integer type */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_UNSIGNED
value|(1<< 0)
end_define

begin_comment
comment|/* Explicitly signed integer type */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_SIGNED
value|(1<< 1)
end_define

begin_comment
comment|/* This appears in a type's flags word if it is a stub type (eg. if    someone referenced a type that wasn't defined in a source file    via (struct sir_not_appearing_in_this_film *)).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_STUB
value|(1<< 2)
end_define

begin_struct
struct|struct
name|type
block|{
comment|/* Code for kind of type */
name|enum
name|type_code
name|code
decl_stmt|;
comment|/* Name of this type, or NULL if none.      This is used for printing only, except by poorly designed C++ code.      Type names specified as input are defined by symbols.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Length in bytes of storage for a value of this type */
name|unsigned
name|length
decl_stmt|;
comment|/* Every type is now associated with a particular objfile, and the      type is allocated on the type_obstack for that objfile.  One problem      however, is that there are times when gdb allocates new types while      it is not in the process of reading symbols from a particular objfile.      Fortunately, these happen when the type being created is a derived      type of an existing type, such as in lookup_pointer_type().  So      we can just allocate the new type using the same objfile as the      existing type, but to do this we need a backpointer to the objfile      from the existing type.  Yes this is somewhat ugly, but without      major overhaul of the internal type system, it can't be avoided      for now. */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* For a pointer type, describes the type of object pointed to.      For an array type, describes the type of the elements.      For a function or method type, describes the type of the return value.      For a range type, describes the type of the full range.      Unused otherwise.  */
name|struct
name|type
modifier|*
name|target_type
decl_stmt|;
comment|/* Type that is a pointer to this type.      NULL if no such pointer-to type is known yet.      The debugger may add the address of such a type      if it has to construct one later.  */
name|struct
name|type
modifier|*
name|pointer_type
decl_stmt|;
comment|/* C++: also need a reference type.  */
name|struct
name|type
modifier|*
name|reference_type
decl_stmt|;
comment|/* Type that is a function returning this type.      NULL if no such function type is known here.      The debugger may add the address of such a type      if it has to construct one later.  */
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
comment|/* For structure and union types, a description of each field.      For set and pascal array types, there is one "field",      whose type is the domain type of the set or array.      For range types, there are two "fields",      the minimum and maximum values (both inclusive).      For enum types, each possible value is described by one "field".      For C++ classes, there is one field for each base class (if it is      a derived class) plus one field for each class data member.  Member      functions are recorded elsewhere.       Using a pointer to a separate array of fields      allows all types to have the same size, which is useful      because we can allocate the space for a type before      we know what to put in it.  */
struct|struct
name|field
block|{
comment|/* Position of this field, counting in bits from start of 	 containing structure.  For a function type, this is the 	 position in the argument list of this argument. 	 For a range bound or enum value, this is the value itself. 	 For BITS_BIG_ENDIAN=1 targets, it is the bit offset to the MSB. 	 For BITS_BIG_ENDIAN=0 targets, it is the bit offset to the LSB. */
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
comment|/* Name of field, value or argument. 	 NULL for range bounds and array domains.  */
name|char
modifier|*
name|name
decl_stmt|;
block|}
modifier|*
name|fields
struct|;
comment|/* For types with virtual functions, VPTR_BASETYPE is the base class which      defined the virtual function table pointer.  VPTR_FIELDNO is      the field number of that pointer in the structure.       For types that are pointer to member types, VPTR_BASETYPE      is the type that this pointer is a member of.       Unused otherwise.  */
name|struct
name|type
modifier|*
name|vptr_basetype
decl_stmt|;
name|int
name|vptr_fieldno
decl_stmt|;
comment|/* Slot to point to additional language-specific fields of this type.  */
union|union
name|type_specific
block|{
comment|/* ARG_TYPES is for TYPE_CODE_METHOD and TYPE_CODE_FUNC.  */
name|struct
name|type
modifier|*
modifier|*
name|arg_types
decl_stmt|;
comment|/* CPLUS_STUFF is for TYPE_CODE_STRUCT.  It is initialized to point to 	 cplus_struct_default, a default static instance of a struct 	 cplus_struct_type. */
name|struct
name|cplus_struct_type
modifier|*
name|cplus_stuff
decl_stmt|;
block|}
name|type_specific
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_TYPE
value|((struct type *) 0)
end_define

begin_comment
comment|/* C++ language-specific information for TYPE_CODE_STRUCT and TYPE_CODE_UNION    nodes.  */
end_comment

begin_struct
struct|struct
name|cplus_struct_type
block|{
comment|/* Number of base classes this type derives from. */
name|short
name|n_baseclasses
decl_stmt|;
comment|/* Number of methods with unique names.  All overloaded methods with      the same name count only once. */
name|short
name|nfn_fields
decl_stmt|;
comment|/* Number of methods described for this type plus all the      methods that it derives from.  */
name|int
name|nfn_fields_total
decl_stmt|;
comment|/* For derived classes, the number of base classes is given by n_baseclasses      and virtual_field_bits is a bit vector containing one bit per base class.      If the base class is virtual, the corresponding bit will be set.      I.E, given:  	class A{}; 	class B{}; 	class C : public B, public virtual A {};       B is a baseclass of C; A is a virtual baseclass for C.      This is a C++ 2.0 language feature. */
name|B_TYPE
modifier|*
name|virtual_field_bits
decl_stmt|;
comment|/* For classes with private fields, the number of fields is given by      nfields and private_field_bits is a bit vector containing one bit      per field.      If the field is private, the corresponding bit will be set. */
name|B_TYPE
modifier|*
name|private_field_bits
decl_stmt|;
comment|/* For classes with protected fields, the number of fields is given by      nfields and protected_field_bits is a bit vector containing one bit      per field.      If the field is private, the corresponding bit will be set. */
name|B_TYPE
modifier|*
name|protected_field_bits
decl_stmt|;
comment|/* For classes, structures, and unions, a description of each field,      which consists of an overloaded name, followed by the types of      arguments that the method expects, and then the name after it      has been renamed to make it distinct.       fn_fieldlists points to an array of nfn_fields of these. */
struct|struct
name|fn_fieldlist
block|{
comment|/* The overloaded name.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The number of methods with this name.  */
name|int
name|length
decl_stmt|;
comment|/* The list of methods.  */
struct|struct
name|fn_field
block|{
comment|/* The name after it has been processed */
name|char
modifier|*
name|physname
decl_stmt|;
comment|/* The return value of the method */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* The argument list */
name|struct
name|type
modifier|*
modifier|*
name|args
decl_stmt|;
comment|/* For virtual functions. 	     First baseclass that defines this virtual function.   */
name|struct
name|type
modifier|*
name|fcontext
decl_stmt|;
comment|/* Attributes. */
name|unsigned
name|int
name|is_const
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_volatile
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_private
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_protected
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_stub
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|dummy
range|:
literal|3
decl_stmt|;
comment|/* Index into that baseclass's virtual function table, 	     minus 2; else if static: VOFFSET_STATIC; else: 0.  */
name|unsigned
name|int
name|voffset
range|:
literal|24
decl_stmt|;
define|#
directive|define
name|VOFFSET_STATIC
value|1
block|}
modifier|*
name|fn_fields
struct|;
block|}
modifier|*
name|fn_fieldlists
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* The default value of TYPE_CPLUS_SPECIFIC(T) points to the    this shared static structure. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cplus_struct_type
name|cplus_struct_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|allocate_cplus_struct_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_CPLUS_SPECIFIC
parameter_list|(
name|type
parameter_list|)
define|\
value|(TYPE_CPLUS_SPECIFIC(type)=(struct cplus_struct_type*)&cplus_struct_default)
end_define

begin_define
define|#
directive|define
name|ALLOCATE_CPLUS_STRUCT_TYPE
parameter_list|(
name|type
parameter_list|)
value|allocate_cplus_struct_type (type)
end_define

begin_define
define|#
directive|define
name|HAVE_CPLUS_STRUCT
parameter_list|(
name|type
parameter_list|)
define|\
value|(TYPE_CPLUS_SPECIFIC(type) !=&cplus_struct_default)
end_define

begin_define
define|#
directive|define
name|TYPE_NAME
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->name
end_define

begin_define
define|#
directive|define
name|TYPE_TARGET_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->target_type
end_define

begin_define
define|#
directive|define
name|TYPE_POINTER_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->pointer_type
end_define

begin_define
define|#
directive|define
name|TYPE_REFERENCE_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->reference_type
end_define

begin_define
define|#
directive|define
name|TYPE_FUNCTION_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->function_type
end_define

begin_define
define|#
directive|define
name|TYPE_LENGTH
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->length
end_define

begin_define
define|#
directive|define
name|TYPE_OBJFILE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->objfile
end_define

begin_define
define|#
directive|define
name|TYPE_FLAGS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->flags
end_define

begin_define
define|#
directive|define
name|TYPE_UNSIGNED
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|TYPE_CODE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->code
end_define

begin_define
define|#
directive|define
name|TYPE_NFIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->nfields
end_define

begin_define
define|#
directive|define
name|TYPE_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->fields
end_define

begin_comment
comment|/* C++ */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPTR_BASETYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_basetype
end_define

begin_define
define|#
directive|define
name|TYPE_DOMAIN_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_basetype
end_define

begin_define
define|#
directive|define
name|TYPE_VPTR_FIELDNO
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->vptr_fieldno
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_NFN_FIELDS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->nfn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_NFN_FIELDS_TOTAL
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->nfn_fields_total
end_define

begin_define
define|#
directive|define
name|TYPE_TYPE_SPECIFIC
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->type_specific
end_define

begin_define
define|#
directive|define
name|TYPE_ARG_TYPES
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->type_specific.arg_types
end_define

begin_define
define|#
directive|define
name|TYPE_CPLUS_SPECIFIC
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->type_specific.cplus_stuff
end_define

begin_define
define|#
directive|define
name|TYPE_BASECLASS
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
value|(thistype)->fields[index].type
end_define

begin_define
define|#
directive|define
name|TYPE_N_BASECLASSES
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->n_baseclasses
end_define

begin_define
define|#
directive|define
name|TYPE_BASECLASS_NAME
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
value|(thistype)->fields[index].name
end_define

begin_define
define|#
directive|define
name|TYPE_BASECLASS_BITPOS
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
value|(thistype)->fields[index].bitpos
end_define

begin_define
define|#
directive|define
name|BASETYPE_VIA_PUBLIC
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
value|(!TYPE_FIELD_PRIVATE(thistype, index))
end_define

begin_define
define|#
directive|define
name|BASETYPE_VIA_VIRTUAL
parameter_list|(
name|thistype
parameter_list|,
name|index
parameter_list|)
define|\
value|B_TST(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits, (index))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_TYPE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].type
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_NAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].name
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_VALUE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(* (int*)&(thistype)->fields[n].type)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_BITPOS
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitpos
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_BITSIZE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitsize
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PACKED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|(thistype)->fields[n].bitsize
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PRIVATE_BITS
parameter_list|(
name|thistype
parameter_list|)
define|\
value|TYPE_CPLUS_SPECIFIC(thistype)->private_field_bits
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PROTECTED_BITS
parameter_list|(
name|thistype
parameter_list|)
define|\
value|TYPE_CPLUS_SPECIFIC(thistype)->protected_field_bits
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_VIRTUAL_BITS
parameter_list|(
name|thistype
parameter_list|)
define|\
value|TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FIELD_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|B_SET (TYPE_CPLUS_SPECIFIC(thistype)->private_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FIELD_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|B_SET (TYPE_CPLUS_SPECIFIC(thistype)->protected_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|SET_TYPE_FIELD_VIRTUAL
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|B_SET (TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PRIVATE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|(TYPE_CPLUS_SPECIFIC(thistype)->private_field_bits == NULL ? 0 \     : B_TST(TYPE_CPLUS_SPECIFIC(thistype)->private_field_bits, (n)))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_PROTECTED
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|(TYPE_CPLUS_SPECIFIC(thistype)->protected_field_bits == NULL ? 0 \     : B_TST(TYPE_CPLUS_SPECIFIC(thistype)->protected_field_bits, (n)))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_VIRTUAL
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|B_TST(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits, (n))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)->fields[n].bitpos == -1)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC_PHYSNAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((char *)(thistype)->fields[n].bitsize)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLISTS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fieldlists
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fieldlists[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST1
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fieldlists[n].fn_fields
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST_NAME
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fieldlists[n].name
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELDLIST_LENGTH
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->fn_fieldlists[n].length
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|(thisfn)[n]
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_PHYSNAME
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|(thisfn)[n].physname
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_TYPE
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|(thisfn)[n].type
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_ARGS
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|TYPE_ARG_TYPES ((thisfn)[n].type)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_CONST
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_const)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_VOLATILE
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_volatile)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_PRIVATE
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_private)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_PROTECTED
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_protected)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_STUB
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_stub)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_FCONTEXT
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].fcontext)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_VOFFSET
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].voffset-2)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_VIRTUAL_P
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].voffset> 1)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_STATIC_P
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].voffset == VOFFSET_STATIC)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_void
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_signed_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_long_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_complex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_double_complex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This type represents a type that was unrecognized in symbol    read-in.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_long_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_unsigned_long_long
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modula-2 types */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_m2_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_m2_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_m2_card
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_m2_real
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_m2_bool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LONG_LONG is defined if the host has "long long".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long_long
end_define

begin_define
define|#
directive|define
name|BUILTIN_TYPE_UNSIGNED_LONGEST
value|builtin_type_unsigned_long_long
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not LONG_LONG.  */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long
end_define

begin_define
define|#
directive|define
name|BUILTIN_TYPE_UNSIGNED_LONGEST
value|builtin_type_unsigned_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not LONG_LONG.  */
end_comment

begin_comment
comment|/* Maximum and minimum values of built-in types */
end_comment

begin_define
define|#
directive|define
name|MAX_OF_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|TYPE_UNSIGNED(t) ? UMAX_OF_SIZE(TYPE_LENGTH(t)) \     : MAX_OF_SIZE(TYPE_LENGTH(t))
end_define

begin_define
define|#
directive|define
name|MIN_OF_TYPE
parameter_list|(
name|t
parameter_list|)
define|\
value|TYPE_UNSIGNED(t) ? UMIN_OF_SIZE(TYPE_LENGTH(t)) \     : MIN_OF_SIZE(TYPE_LENGTH(t))
end_define

begin_comment
comment|/* Allocate space for storing data associated with a particular type.    We ensure that the space is allocated using the same mechanism that    was used to allocate the space for the type structure itself.  I.E.    if the type is on an objfile's type_obstack, then the space for data    associated with that type will also be allocated on the type_obstack.    If the type is not associated with any particular objfile (such as    builtin types), then the data space will be allocated with xmalloc,    the same as for the type structure. */
end_comment

begin_define
define|#
directive|define
name|TYPE_ALLOC
parameter_list|(
name|t
parameter_list|,
name|size
parameter_list|)
define|\
value|(TYPE_OBJFILE (t) != NULL  \     ? obstack_alloc (&TYPE_OBJFILE (t) -> type_obstack, size) \     : xmalloc (size))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|alloc_type
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

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|init_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|type_code
operator|,
name|int
operator|,
name|int
operator|,
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
name|type
modifier|*
name|lookup_reference_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|make_reference_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
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
name|lookup_member_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|smash_to_method_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|smash_to_member_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
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
name|allocate_stub_method
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|type_name_no_tag
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|type
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
name|lookup_struct_elt_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
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
name|type
modifier|*
name|make_pointer_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
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
name|lookup_pointer_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|make_function_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
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
name|lookup_function_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|create_array_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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
name|type
modifier|*
name|lookup_unsigned_typename
name|PARAMS
argument_list|(
operator|(
name|char
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
name|lookup_signed_typename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_stub_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_stub_method
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
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
name|struct
name|type
modifier|*
name|lookup_primitive_typename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gdb_mangle_name
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
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
name|struct
name|type
modifier|*
name|builtin_type
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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
name|error_type
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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
name|lookup_typename
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|block
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
name|type
modifier|*
name|lookup_template_type
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|type
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
name|lookup_fundamental_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
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
name|fill_in_vptr_fieldno
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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

begin_decl_stmt
specifier|extern
name|void
name|recursive_dump_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
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

begin_comment
comment|/* printcmd.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_scalar_formatted
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|type
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
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

begin_decl_stmt
specifier|extern
name|void
name|maintenance_print_type
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBTYPES_H */
end_comment

end_unit

