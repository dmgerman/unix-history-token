begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal type definitions for GDB.    Copyright (C) 1992, 1993, 1994, 1996, 1998, 1999    Free Software Foundation, Inc.    Contributed by Cygnus Support, using pieces from other GDB modules.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Codes for `fundamental types'.  This is a monstrosity based on the    bogus notion that there are certain compiler-independent    `fundamental types'.  None of these is well-defined (how big is    FT_SHORT?  Does it depend on the language?  How does the    language-specific code know which type to correlate to FT_SHORT?)  */
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

begin_comment
comment|/* we use this for not-unsigned C/C++ chars */
end_comment

begin_define
define|#
directive|define
name|FT_SIGNED_CHAR
value|3
end_define

begin_comment
comment|/* we use this for C++ signed chars */
end_comment

begin_define
define|#
directive|define
name|FT_UNSIGNED_CHAR
value|4
end_define

begin_comment
comment|/* we use this for C/C++ unsigned chars */
end_comment

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
name|FT_BYTE
value|26
end_define

begin_define
define|#
directive|define
name|FT_UNSIGNED_BYTE
value|27
end_define

begin_define
define|#
directive|define
name|FT_TEMPLATE_ARG
value|28
end_define

begin_define
define|#
directive|define
name|FT_NUM_MEMBERS
value|29
end_define

begin_comment
comment|/* Highest FT_* above, plus one. */
end_comment

begin_comment
comment|/* Some macros for char-based bitfields.  */
end_comment

begin_define
define|#
directive|define
name|B_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3] |= (1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_CLR
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3]&= ~(1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_TST
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|((a)[(x)>>3]& (1<< ((x)&7)))
end_define

begin_define
define|#
directive|define
name|B_TYPE
value|unsigned char
end_define

begin_define
define|#
directive|define
name|B_BYTES
parameter_list|(
name|x
parameter_list|)
value|( 1 + ((x)>>3) )
end_define

begin_define
define|#
directive|define
name|B_CLRALL
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
value|memset ((a), 0, B_BYTES(x))
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
comment|/* Array type with lower& upper bounds. */
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
comment|/* Floating type.  This is *NOT* a complex type.  Beware, there are parts      of GDB which bogusly assume that TYPE_CODE_FLT can mean complex.  */
name|TYPE_CODE_FLT
block|,
comment|/* Void type.  The length field specifies the length (probably always      one) which is used in pointer arithmetic involving pointers to      this type, but actually dereferencing such a pointer is invalid;      a void type has no length and no actual representation in memory      or registers.  A pointer to a void type is a generic pointer.  */
name|TYPE_CODE_VOID
block|,
name|TYPE_CODE_SET
block|,
comment|/* Pascal sets */
name|TYPE_CODE_RANGE
block|,
comment|/* Range (integers within spec'd bounds) */
comment|/* A string type which is like an array of character but prints      differently (at least for CHILL).  It does not contain a length      field as Pascal strings (for many Pascals, anyway) do; if we want      to deal with such strings, we should use a new type code.  */
name|TYPE_CODE_STRING
block|,
comment|/* String of bits; like TYPE_CODE_SET but prints differently (at least      for CHILL).  */
name|TYPE_CODE_BITSTRING
block|,
comment|/* Unknown type.  The length field is valid if we were able to      deduce that much about the type, or 0 if we don't even know that.  */
name|TYPE_CODE_ERROR
block|,
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
name|TYPE_CODE_CHAR
block|,
comment|/* *real* character type */
comment|/* Boolean type.  0 is false, 1 is true, and other values are non-boolean      (e.g. FORTRAN "logical" used as unsigned int).  */
name|TYPE_CODE_BOOL
block|,
comment|/* Fortran */
name|TYPE_CODE_COMPLEX
block|,
comment|/* Complex float */
name|TYPE_CODE_TYPEDEF
block|,
name|TYPE_CODE_TEMPLATE
block|,
comment|/* C++ template */
name|TYPE_CODE_TEMPLATE_ARG
comment|/* C++ template arg */
block|}
enum|;
end_enum

begin_comment
comment|/* For now allow source to use TYPE_CODE_CLASS for C++ classes, as an    alias for TYPE_CODE_STRUCT.  This is for DWARF, which has a distinct    "class" attribute.  Perhaps we should actually have a separate TYPE_CODE    so that we can print "class" or "struct" depending on what the debug    info said.  It's not clear we should bother.  */
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
comment|/* Unsigned integer type.  If this is not set for a TYPE_CODE_INT, the    type is signed (unless TYPE_FLAG_NOSIGN (below) is set). */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_UNSIGNED
value|(1<< 0)
end_define

begin_comment
comment|/* No sign for this type.  In C++, "char", "signed char", and "unsigned    char" are distinct types; so we need an extra flag to indicate the    absence ofa sign! */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_NOSIGN
value|(1<< 1)
end_define

begin_comment
comment|/* This appears in a type's flags word if it is a stub type (e.g., if    someone referenced a type that wasn't defined in a source file    via (struct sir_not_appearing_in_this_film *)).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_STUB
value|(1<< 2)
end_define

begin_comment
comment|/* The target type of this type is a stub type, and this type needs to    be updated if it gets un-stubbed in check_typedef.    Used for arrays and ranges, in which TYPE_LENGTH of the array/range    gets set based on the TYPE_LENGTH of the target type.    Also, set for TYPE_CODE_TYPEDEF. */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_TARGET_STUB
value|(1<< 3)
end_define

begin_comment
comment|/* Static type.  If this is set, the corresponding type had   * a static modifier.  * Note: This may be unnecessary, since static data members  * are indicated by other means (bitpos == -1)  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_STATIC
value|(1<< 4)
end_define

begin_comment
comment|/* Constant type.  If this is set, the corresponding type has a  * const modifier.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_CONST
value|(1<< 5)
end_define

begin_comment
comment|/* Volatile type.  If this is set, the corresponding type has a  * volatile modifier.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_VOLATILE
value|(1<< 6)
end_define

begin_comment
comment|/* This is a function type which appears to have a prototype.  We need this    for function calls in order to tell us if it's necessary to coerce the args,    or to just do the standard conversions.  This is used with a short field. */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_PROTOTYPED
value|(1<< 7)
end_define

begin_comment
comment|/* This flag is used to indicate that processing for this type    is incomplete.      (Mostly intended for HP platforms, where class methods, for    instance, can be encountered before their classes in the debug    info; the incomplete type has to be marked so that the class and    the method can be assigned correct types.) */
end_comment

begin_define
define|#
directive|define
name|TYPE_FLAG_INCOMPLETE
value|(1<< 8)
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
comment|/* Name of this type, or NULL if none.       This is used for printing only, except by poorly designed C++ code.      For looking up a name, look for a symbol in the VAR_NAMESPACE.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Tag name for this type, or NULL if none.  This means that the      name of the type consists of a keyword followed by the tag name.      Which keyword is determined by the type code ("struct" for      TYPE_CODE_STRUCT, etc.).  As far as I know C/C++ are the only languages      with this feature.       This is used for printing only, except by poorly designed C++ code.      For looking up a name, look for a symbol in the STRUCT_NAMESPACE.      One more legitimate use is that if TYPE_FLAG_STUB is set, this is      the name to use to look for definitions in other files.  */
name|char
modifier|*
name|tag_name
decl_stmt|;
comment|/* Length of storage for a value of this type.  Various places pass      this to memcpy and such, meaning it must be in units of      HOST_CHAR_BIT.  Various other places expect they can calculate      addresses by adding it and such, meaning it must be in units of      TARGET_CHAR_BIT.  For some DSP targets, in which HOST_CHAR_BIT      will (presumably) be 8 and TARGET_CHAR_BIT will be (say) 32, this      is a problem.  One fix would be to make this field in bits      (requiring that it always be a multiple of HOST_CHAR_BIT and      TARGET_CHAR_BIT)--the other choice would be to make it      consistently in units of HOST_CHAR_BIT.  */
name|unsigned
name|length
decl_stmt|;
comment|/* FIXME, these should probably be restricted to a Fortran-specific      field in some fashion.  */
define|#
directive|define
name|BOUND_CANNOT_BE_DETERMINED
value|5
define|#
directive|define
name|BOUND_BY_REF_ON_STACK
value|4
define|#
directive|define
name|BOUND_BY_VALUE_ON_STACK
value|3
define|#
directive|define
name|BOUND_BY_REF_IN_REG
value|2
define|#
directive|define
name|BOUND_BY_VALUE_IN_REG
value|1
define|#
directive|define
name|BOUND_SIMPLE
value|0
name|int
name|upper_bound_type
decl_stmt|;
name|int
name|lower_bound_type
decl_stmt|;
comment|/* Every type is now associated with a particular objfile, and the      type is allocated on the type_obstack for that objfile.  One problem      however, is that there are times when gdb allocates new types while      it is not in the process of reading symbols from a particular objfile.      Fortunately, these happen when the type being created is a derived      type of an existing type, such as in lookup_pointer_type().  So      we can just allocate the new type using the same objfile as the      existing type, but to do this we need a backpointer to the objfile      from the existing type.  Yes this is somewhat ugly, but without      major overhaul of the internal type system, it can't be avoided      for now. */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* For a pointer type, describes the type of object pointed to.      For an array type, describes the type of the elements.      For a function or method type, describes the type of the return value.      For a range type, describes the type of the full range.      For a complex type, describes the type of each coordinate.      Unused otherwise.  */
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
comment|/* C-v variant chain. This points to a type that      differs from this one only in a const or volatile      attribute (or both). The various c-v variants      are chained together in a ring. */
name|struct
name|type
modifier|*
name|cv_type
decl_stmt|;
comment|/* Flags about this type.  */
name|int
name|flags
decl_stmt|;
comment|/* Number of fields described for this type */
name|short
name|nfields
decl_stmt|;
comment|/* For structure and union types, a description of each field.      For set and pascal array types, there is one "field",      whose type is the domain type of the set or array.      For range types, there are two "fields",      the minimum and maximum values (both inclusive).      For enum types, each possible value is described by one "field".      For a function type, a "field" for each parameter type.      For C++ classes, there is one field for each base class (if it is      a derived class) plus one field for each class data member.  Member      functions are recorded elsewhere.       Using a pointer to a separate array of fields      allows all types to have the same size, which is useful      because we can allocate the space for a type before      we know what to put in it.  */
struct|struct
name|field
block|{
union|union
name|field_location
block|{
comment|/* Position of this field, counting in bits from start of 	     containing structure. 	     For BITS_BIG_ENDIAN=1 targets, it is the bit offset to the MSB. 	     For BITS_BIG_ENDIAN=0 targets, it is the bit offset to the LSB. 	     For a function type, this is the position in the argument list 	     of this argument. 	     For a range bound or enum value, this is the value itself. */
name|int
name|bitpos
decl_stmt|;
comment|/* For a static field, if TYPE_FIELD_STATIC_HAS_ADDR then physaddr 	     is the location (in the target) of the static field. 	     Otherwise, physname is the mangled label of the static field. */
name|CORE_ADDR
name|physaddr
decl_stmt|;
name|char
modifier|*
name|physname
decl_stmt|;
block|}
name|loc
union|;
comment|/* Size of this field, in bits, or zero if not packed. 	 For an unpacked field, the field's type's length 	 says how many bytes the field occupies. 	 A value of -1 or -2 indicates a static field;  -1 means the location 	 is specified by the label loc.physname;  -2 means that loc.physaddr 	 specifies the actual address. */
name|int
name|bitsize
decl_stmt|;
comment|/* In a struct or union type, type of this field. 	 In a function type, type of this argument. 	 In an array type, the domain-type of the array.  */
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
comment|/* For types with virtual functions (TYPE_CODE_STRUCT), VPTR_BASETYPE      is the base class which defined the virtual function table pointer.         For types that are pointer to member types (TYPE_CODE_MEMBER),      VPTR_BASETYPE is the type that this pointer is a member of.       For method types (TYPE_CODE_METHOD), VPTR_BASETYPE is the aggregate      type that contains the method.       Unused otherwise.  */
name|struct
name|type
modifier|*
name|vptr_basetype
decl_stmt|;
comment|/* Field number of the virtual function table pointer in      VPTR_BASETYPE.  If -1, we were unable to find the virtual      function table pointer in initial symbol reading, and      fill_in_vptr_fieldno should be called to find it if possible.       Unused if this type does not have virtual functions.  */
name|int
name|vptr_fieldno
decl_stmt|;
comment|/* Slot to point to additional language-specific fields of this type.  */
union|union
name|type_specific
block|{
comment|/* ARG_TYPES is for TYPE_CODE_METHOD. 	 Contains the type of each argument, ending with a void type 	 after the last argument for normal member functions or a NULL 	 pointer after the last argument for functions with variable 	 arguments.  */
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
comment|/* Number of base classes this type derives from.  The baseclasses are      stored in the first N_BASECLASSES fields (i.e. the `fields' field of      the struct type).  I think only the `type' field of such a field has      any meaning.  */
name|short
name|n_baseclasses
decl_stmt|;
comment|/* Number of methods with unique names.  All overloaded methods with      the same name count only once. */
name|short
name|nfn_fields
decl_stmt|;
comment|/* Number of methods described for this type, not including the      methods that it derives from.  */
name|short
name|nfn_fields_total
decl_stmt|;
comment|/* The "declared_type" field contains a code saying how the      user really declared this type, e.g., "class s", "union s",      "struct s".      The 3 above things come out from the C++ compiler looking like classes,       but we keep track of the real declaration so we can give      the correct information on "ptype". (Note: TEMPLATE may not      belong in this list...)  */
define|#
directive|define
name|DECLARED_TYPE_CLASS
value|0
define|#
directive|define
name|DECLARED_TYPE_UNION
value|1
define|#
directive|define
name|DECLARED_TYPE_STRUCT
value|2
define|#
directive|define
name|DECLARED_TYPE_TEMPLATE
value|3
name|short
name|declared_type
decl_stmt|;
comment|/* One of the above codes */
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
comment|/* for classes with fields to be ignored, either this is optimized out      or this field has length 0 */
name|B_TYPE
modifier|*
name|ignore_field_bits
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
comment|/* If is_stub is clear, this is the mangled name which we can 	     look up to find the address of the method (FIXME: it would 	     be cleaner to have a pointer to the struct symbol here 	     instead).  */
comment|/* If is_stub is set, this is the portion of the mangled 	     name which specifies the arguments.  For example, "ii", 	     if there are two int arguments, or "" if there are no 	     arguments.  See gdb_mangle_name for the conversion from this 	     format to the one used if is_stub is clear.  */
name|char
modifier|*
name|physname
decl_stmt|;
comment|/* The function type for the method.              (This comment used to say "The return value of the method",              but that's wrong. The function type               is expected here, i.e. something with TYPE_CODE_FUNC,              and *not* the return-value type). */
name|struct
name|type
modifier|*
name|type
decl_stmt|;
comment|/* The argument list.  Only valid if is_stub is clear.  Contains 	     the type of each argument, including `this', and ending with 	     a NULL pointer after the last argument.  Should not contain 	     a `this' pointer for static member functions.  */
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
name|is_public
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_abstract
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_static
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_final
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_synchronized
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_native
range|:
literal|1
decl_stmt|;
comment|/* A stub method only has some fields valid (but they are enough 	     to reconstruct the rest of the fields).  */
name|unsigned
name|int
name|is_stub
range|:
literal|1
decl_stmt|;
comment|/* C++ method that is inlined */
name|unsigned
name|int
name|is_inlined
range|:
literal|1
decl_stmt|;
comment|/* Unused.  */
name|unsigned
name|int
name|dummy
range|:
literal|4
decl_stmt|;
comment|/* Index into that baseclass's virtual function table, 	     minus 2; else if static: VOFFSET_STATIC; else: 0.  */
name|unsigned
name|int
name|voffset
range|:
literal|16
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
comment|/* If this "struct type" describes a template, then it       * has arguments. "template_args" points to an array of      * template arg descriptors, of length "ntemplate_args".      * The only real information in each of these template arg descriptors      * is a name. "type" will typically just point to a "struct type" with      * the placeholder TYPE_CODE_TEMPLATE_ARG type.      */
name|short
name|ntemplate_args
decl_stmt|;
struct|struct
name|template_arg
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|type
modifier|*
name|type
decl_stmt|;
block|}
modifier|*
name|template_args
struct|;
comment|/* If this "struct type" describes a template, it has a list      * of instantiations. "instantiations" is a pointer to an array      * of type's, one representing each instantiation. There      * are "ninstantiations" elements in this array.      */
name|short
name|ninstantiations
decl_stmt|;
name|struct
name|type
modifier|*
modifier|*
name|instantiations
decl_stmt|;
comment|/* The following points to information relevant to the runtime model      * of the compiler.      * Currently being used only for HP's ANSI C++ compiler.      * (This type may have to be changed/enhanced for other compilers.)      *      * RUNTIME_PTR is NULL if there is no runtime information (currently      * this means the type was not compiled by HP aCC).      *      * Fields in structure pointed to:      * ->HAS_VTABLE : 0 => no virtual table, 1 => vtable present      *       * ->PRIMARY_BASE points to the first non-virtual base class that has      * a virtual table.      *      * ->VIRTUAL_BASE_LIST points to a list of struct type * pointers that      * point to the type information for all virtual bases among this type's      * ancestors.      */
struct|struct
name|runtime_info
block|{
name|short
name|has_vtable
decl_stmt|;
name|struct
name|type
modifier|*
name|primary_base
decl_stmt|;
name|struct
name|type
modifier|*
modifier|*
name|virtual_base_list
decl_stmt|;
block|}
modifier|*
name|runtime_ptr
struct|;
comment|/* Pointer to information about enclosing scope, if this is a      * local type.  If it is not a local type, this is NULL      */
struct|struct
name|local_type_info
block|{
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
modifier|*
name|localtype_ptr
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* Struct used in computing virtual base list */
end_comment

begin_struct
struct|struct
name|vbase
block|{
name|struct
name|type
modifier|*
name|vbasetype
decl_stmt|;
comment|/* pointer to virtual base */
name|struct
name|vbase
modifier|*
name|next
decl_stmt|;
comment|/* next in chain */
block|}
struct|;
end_struct

begin_comment
comment|/* Struct used for ranking a function for overload resolution */
end_comment

begin_struct
struct|struct
name|badness_vector
block|{
name|int
name|length
decl_stmt|;
name|int
modifier|*
name|rank
decl_stmt|;
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
name|TYPE_TAG_NAME
parameter_list|(
name|type
parameter_list|)
value|((type)->tag_name)
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
name|TYPE_CV_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->cv_type
end_define

begin_comment
comment|/* Note that if thistype is a TYPEDEF type, you have to call check_typedef.    But check_typedef does set the TYPE_LENGTH of the TYPEDEF type,    so you only have to call check_typedef once.  Since allocate_value    calls check_typedef, TYPE_LENGTH (VALUE_TYPE (X)) is safe.  */
end_comment

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
name|TYPE_NOSIGN
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_NOSIGN)
end_define

begin_define
define|#
directive|define
name|TYPE_CONST
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_CONST)
end_define

begin_define
define|#
directive|define
name|TYPE_VOLATILE
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_VOLATILE)
end_define

begin_define
define|#
directive|define
name|TYPE_INCOMPLETE
parameter_list|(
name|thistype
parameter_list|)
value|((thistype)->flags& TYPE_FLAG_INCOMPLETE)
end_define

begin_comment
comment|/* Note that TYPE_CODE can be TYPE_CODE_TYPEDEF, so if you wan the real    type, you need to do TYPE_CODE (check_type (this_type)). */
end_comment

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

begin_define
define|#
directive|define
name|TYPE_TEMPLATE_ARGS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->template_args
end_define

begin_define
define|#
directive|define
name|TYPE_INSTANTIATIONS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->instantiations
end_define

begin_define
define|#
directive|define
name|TYPE_INDEX_TYPE
parameter_list|(
name|type
parameter_list|)
value|TYPE_FIELD_TYPE (type, 0)
end_define

begin_define
define|#
directive|define
name|TYPE_LOW_BOUND
parameter_list|(
name|range_type
parameter_list|)
value|TYPE_FIELD_BITPOS (range_type, 0)
end_define

begin_define
define|#
directive|define
name|TYPE_HIGH_BOUND
parameter_list|(
name|range_type
parameter_list|)
value|TYPE_FIELD_BITPOS (range_type, 1)
end_define

begin_comment
comment|/* Moto-specific stuff for FORTRAN arrays */
end_comment

begin_define
define|#
directive|define
name|TYPE_ARRAY_UPPER_BOUND_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->upper_bound_type
end_define

begin_define
define|#
directive|define
name|TYPE_ARRAY_LOWER_BOUND_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|(thistype)->lower_bound_type
end_define

begin_define
define|#
directive|define
name|TYPE_ARRAY_UPPER_BOUND_VALUE
parameter_list|(
name|arraytype
parameter_list|)
define|\
value|(TYPE_FIELD_BITPOS((TYPE_FIELD_TYPE((arraytype),0)),1))
end_define

begin_define
define|#
directive|define
name|TYPE_ARRAY_LOWER_BOUND_VALUE
parameter_list|(
name|arraytype
parameter_list|)
define|\
value|(TYPE_FIELD_BITPOS((TYPE_FIELD_TYPE((arraytype),0)),0))
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
name|TYPE_NTEMPLATE_ARGS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->ntemplate_args
end_define

begin_define
define|#
directive|define
name|TYPE_NINSTANTIATIONS
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->ninstantiations
end_define

begin_define
define|#
directive|define
name|TYPE_DECLARED_TYPE
parameter_list|(
name|thistype
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->declared_type
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
value|TYPE_FIELD_BITPOS(thistype,index)
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
define|\
value|((!TYPE_FIELD_PRIVATE(thistype, index))&& (!TYPE_FIELD_PROTECTED(thistype, index)))
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
value|(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits == NULL ? 0 \     : B_TST(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits, (index)))
end_define

begin_define
define|#
directive|define
name|FIELD_TYPE
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).type)
end_define

begin_define
define|#
directive|define
name|FIELD_NAME
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).name)
end_define

begin_define
define|#
directive|define
name|FIELD_BITPOS
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).loc.bitpos)
end_define

begin_define
define|#
directive|define
name|FIELD_BITSIZE
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).bitsize)
end_define

begin_define
define|#
directive|define
name|FIELD_PHYSNAME
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).loc.physname)
end_define

begin_define
define|#
directive|define
name|FIELD_PHYSADDR
parameter_list|(
name|thisfld
parameter_list|)
value|((thisfld).loc.physaddr)
end_define

begin_define
define|#
directive|define
name|SET_FIELD_PHYSNAME
parameter_list|(
name|thisfld
parameter_list|,
name|name
parameter_list|)
define|\
value|((thisfld).bitsize = -1, FIELD_PHYSNAME(thisfld) = (name))
end_define

begin_define
define|#
directive|define
name|SET_FIELD_PHYSADDR
parameter_list|(
name|thisfld
parameter_list|,
name|name
parameter_list|)
define|\
value|((thisfld).bitsize = -2, FIELD_PHYSADDR(thisfld) = (name))
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
value|FIELD_TYPE(TYPE_FIELD(thistype, n))
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
value|FIELD_NAME(TYPE_FIELD(thistype, n))
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
value|FIELD_BITPOS(TYPE_FIELD(thistype,n))
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
value|FIELD_BITSIZE(TYPE_FIELD(thistype,n))
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
value|(FIELD_BITSIZE(TYPE_FIELD(thistype,n))!=0)
end_define

begin_define
define|#
directive|define
name|TYPE_TEMPLATE_ARG
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->template_args[n]
end_define

begin_define
define|#
directive|define
name|TYPE_INSTANTIATION
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|TYPE_CPLUS_SPECIFIC(thistype)->instantiations[n]
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
name|TYPE_FIELD_IGNORE_BITS
parameter_list|(
name|thistype
parameter_list|)
define|\
value|TYPE_CPLUS_SPECIFIC(thistype)->ignore_field_bits
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
name|SET_TYPE_FIELD_IGNORE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|B_SET (TYPE_CPLUS_SPECIFIC(thistype)->ignore_field_bits, (n))
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
name|TYPE_FIELD_IGNORE
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
define|\
value|(TYPE_CPLUS_SPECIFIC(thistype)->ignore_field_bits == NULL ? 0 \     : B_TST(TYPE_CPLUS_SPECIFIC(thistype)->ignore_field_bits, (n)))
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
value|(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits == NULL ? 0 \     : B_TST(TYPE_CPLUS_SPECIFIC(thistype)->virtual_field_bits, (n)))
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
value|((thistype)->fields[n].bitsize< 0)
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC_HAS_ADDR
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|((thistype)->fields[n].bitsize == -2)
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
value|FIELD_PHYSNAME(TYPE_FIELD(thistype, n))
end_define

begin_define
define|#
directive|define
name|TYPE_FIELD_STATIC_PHYSADDR
parameter_list|(
name|thistype
parameter_list|,
name|n
parameter_list|)
value|FIELD_PHYSADDR(TYPE_FIELD(thistype, n))
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
name|TYPE_FN_FIELD_PUBLIC
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_public)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_STATIC
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_static)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_FINAL
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_final)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_SYNCHRONIZED
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_synchronized)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_NATIVE
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_native)
end_define

begin_define
define|#
directive|define
name|TYPE_FN_FIELD_ABSTRACT
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_abstract)
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
name|TYPE_FN_FIELD_INLINED
parameter_list|(
name|thisfn
parameter_list|,
name|n
parameter_list|)
value|((thisfn)[n].is_inlined)
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

begin_define
define|#
directive|define
name|TYPE_RUNTIME_PTR
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_CPLUS_SPECIFIC(thistype)->runtime_ptr)
end_define

begin_define
define|#
directive|define
name|TYPE_VTABLE
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_RUNTIME_PTR(thistype)->has_vtable)
end_define

begin_define
define|#
directive|define
name|TYPE_HAS_VTABLE
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_RUNTIME_PTR(thistype)&& TYPE_VTABLE(thistype))
end_define

begin_define
define|#
directive|define
name|TYPE_PRIMARY_BASE
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_RUNTIME_PTR(thistype)->primary_base)
end_define

begin_define
define|#
directive|define
name|TYPE_VIRTUAL_BASE_LIST
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_RUNTIME_PTR(thistype)->virtual_base_list)
end_define

begin_define
define|#
directive|define
name|TYPE_LOCALTYPE_PTR
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_CPLUS_SPECIFIC(thistype)->localtype_ptr)
end_define

begin_define
define|#
directive|define
name|TYPE_LOCALTYPE_FILE
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_CPLUS_SPECIFIC(thistype)->localtype_ptr->file)
end_define

begin_define
define|#
directive|define
name|TYPE_LOCALTYPE_LINE
parameter_list|(
name|thistype
parameter_list|)
value|(TYPE_CPLUS_SPECIFIC(thistype)->localtype_ptr->line)
end_define

begin_define
define|#
directive|define
name|TYPE_IS_OPAQUE
parameter_list|(
name|thistype
parameter_list|)
value|(((TYPE_CODE (thistype) == TYPE_CODE_STRUCT) ||        \                                    (TYPE_CODE (thistype) == TYPE_CODE_UNION))&& \                                   (TYPE_NFIELDS (thistype) == 0)&& \                                   (TYPE_CPLUS_SPECIFIC (thistype)&& (TYPE_NFN_FIELDS (thistype) == 0)))
end_define

begin_comment
comment|/* Implicit sizes */
end_comment

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

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_bool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Explicit sizes - see<intypes.h> for naming schema */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_uint8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_uint16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_uint32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_int64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_uint64
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
comment|/* Chill types */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_chill_bool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_chill_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_chill_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_chill_ulong
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_chill_real
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fortran (F77) types */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_character
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_logical
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_logical_s1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_logical_s2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_integer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_integer_s2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_real
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_real_s8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_real_s16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_complex_s8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_complex_s16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_complex_s32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_f_void
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RTTI for C++ */
end_comment

begin_comment
comment|/* extern struct type *builtin_type_cxx_typeinfo; */
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
name|make_cv_type
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
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
name|create_range_type
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
name|create_array_type
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
name|create_string_type
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
name|struct
name|type
modifier|*
name|create_set_type
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
name|int
name|chill_varying_type
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
name|struct
name|type
modifier|*
name|check_typedef
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
name|CHECK_TYPEDEF
parameter_list|(
name|TYPE
parameter_list|)
value|(TYPE) = check_typedef (TYPE)
end_define

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

begin_decl_stmt
specifier|extern
name|int
name|get_destructor_fn_field
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_discrete_bounds
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|LONGEST
operator|*
operator|,
name|LONGEST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_ancestor
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
name|int
name|has_vtable
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
name|primary_base_class
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
modifier|*
name|virtual_base_list
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
name|int
name|virtual_base_list_length
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
name|int
name|virtual_base_list_length_skip_primaries
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
name|int
name|virtual_base_index
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
name|int
name|virtual_base_index_skip_primaries
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
name|int
name|class_index_in_primary_list
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
name|int
name|count_virtual_fns
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

begin_comment
comment|/* Constants for HP/Taligent ANSI C++ runtime model */
end_comment

begin_comment
comment|/* Where virtual function entries begin in the  * virtual table, in the non-RRBC vtable format.  * First 4 are the metavtable pointer, top offset,  * typeinfo pointer, and dup base info pointer */
end_comment

begin_define
define|#
directive|define
name|HP_ACC_VFUNC_START
value|4
end_define

begin_comment
comment|/* (Negative) Offset where virtual base offset entries begin   * in the virtual table. Skips over metavtable pointer and  * the self-offset entry.   * NOTE: NEGATE THIS BEFORE USING! The virtual base offsets  * appear before the address point of the vtable (the slot  * pointed to by the object's vtable pointer), i.e. at lower  * addresses than the vtable pointer. */
end_comment

begin_define
define|#
directive|define
name|HP_ACC_VBASE_START
value|2
end_define

begin_comment
comment|/* (Positive) Offset where the pointer to the typeinfo  * object is present in the virtual table */
end_comment

begin_define
define|#
directive|define
name|HP_ACC_TYPEINFO_OFFSET
value|2
end_define

begin_comment
comment|/* (Positive) Offset where the ``top offset'' entry of  * the virtual table is */
end_comment

begin_define
define|#
directive|define
name|HP_ACC_TOP_OFFSET_OFFSET
value|1
end_define

begin_comment
comment|/* Overload resolution */
end_comment

begin_define
define|#
directive|define
name|LENGTH_MATCH
parameter_list|(
name|bv
parameter_list|)
value|((bv)->rank[0])
end_define

begin_comment
comment|/* Badness if parameter list length doesn't match arg list length */
end_comment

begin_define
define|#
directive|define
name|LENGTH_MISMATCH_BADNESS
value|100
end_define

begin_comment
comment|/* Dummy badness value for nonexistent parameter positions */
end_comment

begin_define
define|#
directive|define
name|TOO_FEW_PARAMS_BADNESS
value|100
end_define

begin_comment
comment|/* Badness if no conversion among types */
end_comment

begin_define
define|#
directive|define
name|INCOMPATIBLE_TYPE_BADNESS
value|100
end_define

begin_comment
comment|/* Badness of coercing large integer to smaller size */
end_comment

begin_define
define|#
directive|define
name|INTEGER_COERCION_BADNESS
value|100
end_define

begin_comment
comment|/* Badness of coercing large floating type to smaller size */
end_comment

begin_define
define|#
directive|define
name|FLOAT_COERCION_BADNESS
value|100
end_define

begin_comment
comment|/* Badness of integral promotion */
end_comment

begin_define
define|#
directive|define
name|INTEGER_PROMOTION_BADNESS
value|1
end_define

begin_comment
comment|/* Badness of floating promotion */
end_comment

begin_define
define|#
directive|define
name|FLOAT_PROMOTION_BADNESS
value|1
end_define

begin_comment
comment|/* Badness of integral conversion */
end_comment

begin_define
define|#
directive|define
name|INTEGER_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of floating conversion */
end_comment

begin_define
define|#
directive|define
name|FLOAT_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of integer<->floating conversions */
end_comment

begin_define
define|#
directive|define
name|INT_FLOAT_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of converting to a boolean */
end_comment

begin_define
define|#
directive|define
name|BOOLEAN_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of pointer conversion */
end_comment

begin_define
define|#
directive|define
name|POINTER_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of conversion of pointer to void pointer */
end_comment

begin_define
define|#
directive|define
name|VOID_PTR_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Badness of convering derived to base class */
end_comment

begin_define
define|#
directive|define
name|BASE_CONVERSION_BADNESS
value|2
end_define

begin_comment
comment|/* Non-standard conversions allowed by the debugger */
end_comment

begin_comment
comment|/* Converting a pointer to an int is usually OK */
end_comment

begin_define
define|#
directive|define
name|NS_POINTER_CONVERSION_BADNESS
value|10
end_define

begin_decl_stmt
specifier|extern
name|int
name|compare_badness
name|PARAMS
argument_list|(
operator|(
expr|struct
name|badness_vector
operator|*
operator|,
expr|struct
name|badness_vector
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|badness_vector
modifier|*
name|rank_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|*
operator|,
name|int
operator|,
expr|struct
name|type
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rank_one_type
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
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_dereference
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

begin_comment
comment|/* typeprint.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|print_type_scalar
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|LONGEST
operator|,
name|GDB_FILE
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
comment|/* GDBTYPES_H */
end_comment

end_unit

