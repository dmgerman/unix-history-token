begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* debug.h -- Describe generic debugging information.    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Written by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_H
end_define

begin_comment
comment|/* This header file describes a generic debugging information format.    We may eventually have readers which convert different formats into    this generic format, and writers which write it out.  The initial    impetus for this was writing a convertor from stabs to HP IEEE-695    debugging format.  */
end_comment

begin_comment
comment|/* Different kinds of types.  */
end_comment

begin_enum
enum|enum
name|debug_type_kind
block|{
comment|/* Not used.  */
name|DEBUG_KIND_ILLEGAL
block|,
comment|/* Indirect via a pointer.  */
name|DEBUG_KIND_INDIRECT
block|,
comment|/* Void.  */
name|DEBUG_KIND_VOID
block|,
comment|/* Integer.  */
name|DEBUG_KIND_INT
block|,
comment|/* Floating point.  */
name|DEBUG_KIND_FLOAT
block|,
comment|/* Complex.  */
name|DEBUG_KIND_COMPLEX
block|,
comment|/* Boolean.  */
name|DEBUG_KIND_BOOL
block|,
comment|/* Struct.  */
name|DEBUG_KIND_STRUCT
block|,
comment|/* Union.  */
name|DEBUG_KIND_UNION
block|,
comment|/* Class.  */
name|DEBUG_KIND_CLASS
block|,
comment|/* Union class (can this really happen?).  */
name|DEBUG_KIND_UNION_CLASS
block|,
comment|/* Enumeration type.  */
name|DEBUG_KIND_ENUM
block|,
comment|/* Pointer.  */
name|DEBUG_KIND_POINTER
block|,
comment|/* Function.  */
name|DEBUG_KIND_FUNCTION
block|,
comment|/* Reference.  */
name|DEBUG_KIND_REFERENCE
block|,
comment|/* Range.  */
name|DEBUG_KIND_RANGE
block|,
comment|/* Array.  */
name|DEBUG_KIND_ARRAY
block|,
comment|/* Set.  */
name|DEBUG_KIND_SET
block|,
comment|/* Based pointer.  */
name|DEBUG_KIND_OFFSET
block|,
comment|/* Method.  */
name|DEBUG_KIND_METHOD
block|,
comment|/* Const qualified type.  */
name|DEBUG_KIND_CONST
block|,
comment|/* Volatile qualified type.  */
name|DEBUG_KIND_VOLATILE
block|,
comment|/* Named type.  */
name|DEBUG_KIND_NAMED
block|,
comment|/* Tagged type.  */
name|DEBUG_KIND_TAGGED
block|}
enum|;
end_enum

begin_comment
comment|/* Different kinds of variables.  */
end_comment

begin_enum
enum|enum
name|debug_var_kind
block|{
comment|/* Not used.  */
name|DEBUG_VAR_ILLEGAL
block|,
comment|/* A global variable.  */
name|DEBUG_GLOBAL
block|,
comment|/* A static variable.  */
name|DEBUG_STATIC
block|,
comment|/* A local static variable.  */
name|DEBUG_LOCAL_STATIC
block|,
comment|/* A local variable.  */
name|DEBUG_LOCAL
block|,
comment|/* A register variable.  */
name|DEBUG_REGISTER
block|}
enum|;
end_enum

begin_comment
comment|/* Different kinds of function parameters.  */
end_comment

begin_enum
enum|enum
name|debug_parm_kind
block|{
comment|/* Not used.  */
name|DEBUG_PARM_ILLEGAL
block|,
comment|/* A stack based parameter.  */
name|DEBUG_PARM_STACK
block|,
comment|/* A register parameter.  */
name|DEBUG_PARM_REG
block|,
comment|/* A stack based reference parameter.  */
name|DEBUG_PARM_REFERENCE
block|,
comment|/* A register reference parameter.  */
name|DEBUG_PARM_REF_REG
block|}
enum|;
end_enum

begin_comment
comment|/* Different kinds of visibility.  */
end_comment

begin_enum
enum|enum
name|debug_visibility
block|{
comment|/* A public field (e.g., a field in a C struct).  */
name|DEBUG_VISIBILITY_PUBLIC
block|,
comment|/* A protected field.  */
name|DEBUG_VISIBILITY_PROTECTED
block|,
comment|/* A private field.  */
name|DEBUG_VISIBILITY_PRIVATE
block|,
comment|/* A field which should be ignored.  */
name|DEBUG_VISIBILITY_IGNORE
block|}
enum|;
end_enum

begin_comment
comment|/* A type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|debug_type
modifier|*
name|debug_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEBUG_TYPE_NULL
value|((debug_type) NULL)
end_define

begin_comment
comment|/* A field in a struct or union.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|debug_field
modifier|*
name|debug_field
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEBUG_FIELD_NULL
value|((debug_field) NULL)
end_define

begin_comment
comment|/* A base class for an object.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|debug_baseclass
modifier|*
name|debug_baseclass
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEBUG_BASECLASS_NULL
value|((debug_baseclass) NULL)
end_define

begin_comment
comment|/* A method of an object.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|debug_method
modifier|*
name|debug_method
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEBUG_METHOD_NULL
value|((debug_method) NULL)
end_define

begin_comment
comment|/* The arguments to a method function of an object.  These indicate    which method to run.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|debug_method_variant
modifier|*
name|debug_method_variant
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEBUG_METHOD_VARIANT_NULL
value|((debug_method_variant) NULL)
end_define

begin_comment
comment|/* This structure is passed to debug_write.  It holds function    pointers that debug_write will call based on the accumulated    debugging information.  */
end_comment

begin_struct
struct|struct
name|debug_write_fns
block|{
comment|/* This is called at the start of each new compilation unit with the      name of the main file in the new unit.  */
name|boolean
argument_list|(
argument|*start_compilation_unit
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* This is called at the start of each source file within a      compilation unit, before outputting any global information for      that file.  The argument is the name of the file.  */
name|boolean
argument_list|(
argument|*start_source
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Each writer must keep a stack of types.  */
comment|/* Push an empty type onto the type stack.  This type can appear if      there is a reference to a type which is never defined.  */
name|boolean
argument_list|(
argument|*empty_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a void type onto the type stack.  */
name|boolean
argument_list|(
argument|*void_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Push an integer type onto the type stack, given the size and      whether it is unsigned.  */
name|boolean
argument_list|(
argument|*int_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a floating type onto the type stack, given the size.  */
name|boolean
argument_list|(
argument|*float_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a complex type onto the type stack, given the size.  */
name|boolean
argument_list|(
argument|*complex_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a boolean type onto the type stack, given the size.  */
name|boolean
argument_list|(
argument|*bool_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Push an enum type onto the type stack, given the tag, a NULL      terminated array of names and the associated values.  If there is      no tag, the tag argument will be NULL.  If this is an undefined      enum, the names and values arguments will be NULL.  */
name|boolean
argument_list|(
argument|*enum_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
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
name|bfd_signed_vma
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type on the type stack, and push a pointer to that      type onto the type stack.  */
name|boolean
argument_list|(
argument|*pointer_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a function type onto the type stack.  The second argument      indicates the number of argument types that have been pushed onto      the stack.  If the number of argument types is passed as -1, then      the argument types of the function are unknown, and no types have      been pushed onto the stack.  The third argument is true if the      function takes a variable number of arguments.  The return type      of the function is pushed onto the type stack below the argument      types, if any.  */
name|boolean
argument_list|(
argument|*function_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|int
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type on the type stack, and push a reference to that      type onto the type stack.  */
name|boolean
argument_list|(
argument|*reference_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type on the type stack, and push a range of that type      with the given lower and upper bounds onto the type stack.  */
name|boolean
argument_list|(
argument|*range_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_signed_vma
operator|,
name|bfd_signed_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Push an array type onto the type stack.  The top type on the type      stack is the range, and the next type on the type stack is the      element type.  These should be popped before the array type is      pushed.  The arguments are the lower bound, the upper bound, and      whether the array is a string.  */
name|boolean
argument_list|(
argument|*array_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_signed_vma
operator|,
name|bfd_signed_vma
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type on the type stack, and push a set of that type      onto the type stack.  The argument indicates whether this set is      a bitstring.  */
name|boolean
argument_list|(
argument|*set_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Push an offset type onto the type stack.  The top type on the      type stack is the target type, and the next type on the type      stack is the base type.  These should be popped before the offset      type is pushed.  */
name|boolean
argument_list|(
argument|*offset_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a method type onto the type stack.  If the second argument      is true, the top type on the stack is the class to which the      method belongs; otherwise, the class must be determined by the      class to which the method is attached.  The third argument is the      number of argument types; these are pushed onto the type stack in      reverse order (the first type popped is the last argument to the      method).  A value of -1 for the third argument means that no      argument information is available.  The fourth argument is true      if the function takes a variable number of arguments.  The next      type on the type stack below the domain and the argument types is      the return type of the method.  All these types must be popped,      and then the method type must be pushed.  */
name|boolean
argument_list|(
argument|*method_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|boolean
operator|,
name|int
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type off the type stack, and push a const qualified      version of that type onto the type stack.  */
name|boolean
argument_list|(
argument|*const_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the top type off the type stack, and push a volatile      qualified version of that type onto the type stack.  */
name|boolean
argument_list|(
argument|*volatile_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Start building a struct.  This is followed by calls to the      struct_field function, and finished by a call to the      end_struct_type function.  The second argument is the tag; this      will be NULL if there isn't one.  If the second argument is NULL,      the third argument is a constant identifying this struct for use      with tag_type.  The fourth argument is true for a struct, false      for a union.  The fifth argument is the size.  If this is an      undefined struct or union, the size will be 0 and struct_field      will not be called before end_struct_type is called.  */
name|boolean
argument_list|(
argument|*start_struct_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
name|boolean
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Add a field to the struct type currently being built.  The type      of the field should be popped off the type stack.  The arguments      are the name, the bit position, the bit size (may be zero if the      field is not packed), and the visibility.  */
name|boolean
argument_list|(
argument|*struct_field
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_vma
operator|,
name|bfd_vma
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
expr_stmt|;
comment|/* Finish building a struct, and push it onto the type stack.  */
name|boolean
argument_list|(
argument|*end_struct_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Start building a class.  This is followed by calls to several      functions: struct_field, class_static_member, class_baseclass,      class_start_method, class_method_variant,      class_static_method_variant, and class_end_method.  The class is      finished by a call to end_class_type.  The first five arguments      are the same as for start_struct_type.  The sixth argument is      true if there is a virtual function table; if there is, the      seventh argument is true if the virtual function table can be      found in the type itself, and is false if the type of the object      holding the virtual function table should be popped from the type      stack.  */
name|boolean
argument_list|(
argument|*start_class_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
name|boolean
operator|,
name|unsigned
name|int
operator|,
name|boolean
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Add a static member to the class currently being built.  The      arguments are the field name, the physical name, and the      visibility.  The type must be popped off the type stack.  */
name|boolean
argument_list|(
argument|*class_static_member
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
expr_stmt|;
comment|/* Add a baseclass to the class currently being built.  The type of      the baseclass must be popped off the type stack.  The arguments      are the bit position, whether the class is virtual, and the      visibility.  */
name|boolean
argument_list|(
argument|*class_baseclass
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|,
name|boolean
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
expr_stmt|;
comment|/* Start adding a method to the class currently being built.  This      is followed by calls to class_method_variant and      class_static_method_variant to describe different variants of the      method which take different arguments.  The method is finished      with a call to class_end_method.  The argument is the method      name.  */
name|boolean
argument_list|(
argument|*class_start_method
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Describe a variant to the class method currently being built.      The type of the variant must be popped off the type stack.  The      second argument is the physical name of the function.  The      following arguments are the visibility, whether the variant is      const, whether the variant is volatile, the offset in the virtual      function table, and whether the context is on the type stack      (below the variant type).  */
name|boolean
argument_list|(
argument|*class_method_variant
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_visibility
operator|,
name|boolean
operator|,
name|boolean
operator|,
name|bfd_vma
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Describe a static variant to the class method currently being      built.  The arguments are the same as for class_method_variant,      except that the last two arguments are omitted.  The type of the      variant must be popped off the type stack.  */
name|boolean
argument_list|(
argument|*class_static_method_variant
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_visibility
operator|,
name|boolean
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Finish describing a class method.  */
name|boolean
argument_list|(
argument|*class_end_method
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Finish describing a class, and push it onto the type stack.  */
name|boolean
argument_list|(
argument|*end_class_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a type on the stack which was given a name by an earlier      call to typdef.  */
name|boolean
argument_list|(
argument|*typedef_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Push a tagged type on the stack which was defined earlier.  If      the second argument is not NULL, the type was defined by a call      to tag.  If the second argument is NULL, the type was defined by      a call to start_struct_type or start_class_type with a tag of      NULL and the number of the third argument.  Either way, the      fourth argument is the tag kind.  Note that this may be called      for a struct (class) being defined, in between the call to      start_struct_type (start_class_type) and the call to      end_struct_type (end_class_type).  */
name|boolean
argument_list|(
argument|*tag_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|,
expr|enum
name|debug_type_kind
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the type stack, and typedef it to the given name.  */
name|boolean
argument_list|(
argument|*typdef
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Pop the type stack, and declare it as a tagged struct or union or      enum or whatever.  The tag passed down here is redundant, since      was also passed when enum_type, start_struct_type, or      start_class_type was called.  */
name|boolean
argument_list|(
argument|*tag
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* This is called to record a named integer constant.  */
name|boolean
argument_list|(
argument|*int_constant
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* This is called to record a named floating point constant.  */
name|boolean
argument_list|(
argument|*float_constant
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|double
operator|)
argument_list|)
expr_stmt|;
comment|/* This is called to record a typed integer constant.  The type is      popped off the type stack.  */
name|boolean
argument_list|(
argument|*typed_constant
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* This is called to record a variable.  The type is popped off the      type stack.  */
name|boolean
argument_list|(
argument|*variable
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_var_kind
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Start writing out a function.  The return type must be popped off      the stack.  The boolean is true if the function is global.  This      is followed by calls to function_parameter, followed by block      information.  */
name|boolean
argument_list|(
argument|*start_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
comment|/* Record a function parameter for the current function.  The type      must be popped off the stack.  */
name|boolean
argument_list|(
argument|*function_parameter
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_parm_kind
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Start writing out a block.  There is at least one top level block      per function.  Blocks may be nested.  The argument is the      starting address of the block.  */
name|boolean
argument_list|(
argument|*start_block
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Finish writing out a block.  The argument is the ending address      of the block.  */
name|boolean
argument_list|(
argument|*end_block
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Finish writing out a function.  */
name|boolean
argument_list|(
argument|*end_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Record line number information for the current compilation unit.  */
name|boolean
argument_list|(
argument|*lineno
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|long
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Exported functions.  */
end_comment

begin_comment
comment|/* The first argument to most of these functions is a handle.  This    handle is returned by the debug_init function.  The purpose of the    handle is to permit the debugging routines to not use static    variables, and hence to be reentrant.  This would be useful for a    program which wanted to handle two executables simultaneously.  */
end_comment

begin_comment
comment|/* Return a debugging handle.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|debug_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the source filename.  This implicitly starts a new compilation    unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_set_filename
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change source files to the given file name.  This is used for    include files in a single compilation unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_start_source
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a function definition.  This implicitly starts a function    block.  The debug_type argument is the type of the return value.    The boolean indicates whether the function is globally visible.    The bfd_vma is the address of the start of the function.  Currently    the parameter types are specified by calls to    debug_record_parameter.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_function
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
name|boolean
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a parameter for the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_parameter
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
expr|enum
name|debug_parm_kind
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End a function definition.  The argument is the address where the    function ends.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_end_function
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start a block in a function.  All local information will be    recorded in this block, until the matching call to debug_end_block.    debug_start_block and debug_end_block may be nested.  The argument    is the address at which this block starts.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_start_block
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish a block in a function.  This matches the call to    debug_start_block.  The argument is the address at which this block    ends.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_end_block
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Associate a line number in the current source file with a given    address.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_line
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|long
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start a named common block.  This is a block of variables that may    move in memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_start_common_block
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End a named common block.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_end_common_block
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a named integer constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_int_const
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a named floating point constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_float_const
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a typed constant with an integral value.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_typed_const
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a label.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_label
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a variable.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_variable
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
expr|enum
name|debug_var_kind
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an indirect type.  The first argument is a pointer to the    location where the real type will be placed.  The second argument    is the type tag, if there is one; this may be NULL; the only    purpose of this argument is so that debug_get_type_name can return    something useful.  This function may be used when a type is    referenced before it is defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_indirect_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
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
comment|/* Make a void type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_void_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an integer type of a given size.  The boolean argument is true    if the integer is unsigned.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_int_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a floating point type of a given size.  FIXME: On some    platforms, like an Alpha, you probably need to be able to specify    the format.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_float_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a boolean type of a given size.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_bool_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a complex type of a given size.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_complex_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a structure type.  The second argument is true for a struct,    false for a union.  The third argument is the size of the struct.    The fourth argument is a NULL terminated array of fields.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_struct_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|boolean
operator|,
name|bfd_vma
operator|,
name|debug_field
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an object type.  The first three arguments after the handle    are the same as for debug_make_struct_type.  The next arguments are    a NULL terminated array of base classes, a NULL terminated array of    methods, the type of the object holding the virtual function table    if it is not this object, and a boolean which is true if this    object has its own virtual function table.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_object_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|boolean
operator|,
name|bfd_vma
operator|,
name|debug_field
operator|*
operator|,
name|debug_baseclass
operator|*
operator|,
name|debug_method
operator|*
operator|,
name|debug_type
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an enumeration type.  The arguments are a null terminated    array of strings, and an array of corresponding values.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_enum_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|bfd_signed_vma
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a pointer to a given type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_pointer_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a function type.  The second argument is the return type.  The    third argument is a NULL terminated array of argument types.  The    fourth argument is true if the function takes a variable number of    arguments.  If the third argument is NULL, then the argument types    are unknown.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_function_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|debug_type
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a reference to a given type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_reference_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a range of a given type from a lower to an upper bound.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_range_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|bfd_signed_vma
operator|,
name|bfd_signed_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an array type.  The second argument is the type of an element    of the array.  The third argument is the type of a range of the    array.  The fourth and fifth argument are the lower and upper    bounds, respectively (if the bounds are not known, lower should be    0 and upper should be -1).  The sixth argument is true if this    array is actually a string, as in C.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_array_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|debug_type
operator|,
name|bfd_signed_vma
operator|,
name|bfd_signed_vma
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a set of a given type.  For example, a Pascal set type.  The    boolean argument is true if this set is actually a bitstring, as in    CHILL.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_set_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a type for a pointer which is relative to an object.  The    second argument is the type of the object to which the pointer is    relative.  The third argument is the type that the pointer points    to.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_offset_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a type for a method function.  The second argument is the    return type.  The third argument is the domain.  The fourth    argument is a NULL terminated array of argument types.  The fifth    argument is true if the function takes a variable number of    arguments, in which case the array of argument types indicates the    types of the first arguments.  The domain and the argument array    may be NULL, in which case this is a stub method and that    information is not available.  Stabs debugging uses this, and gets    the argument types from the mangled name.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_method_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|debug_type
operator|,
name|debug_type
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a const qualified version of a given type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_const_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a volatile qualified version of a given type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_volatile_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make an undefined tagged type.  For example, a struct which has    been mentioned, but not defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_make_undefined_tagged_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_type_kind
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a base class for an object.  The second argument is the base    class type.  The third argument is the bit position of this base    class in the object.  The fourth argument is whether this is a    virtual class.  The fifth argument is the visibility of the base    class.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_baseclass
name|debug_make_baseclass
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|bfd_vma
operator|,
name|boolean
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a field for a struct.  The second argument is the name.  The    third argument is the type of the field.  The fourth argument is    the bit position of the field.  The fifth argument is the size of    the field (it may be zero).  The sixth argument is the visibility    of the field.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_field
name|debug_make_field
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
name|bfd_vma
operator|,
name|bfd_vma
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a static member of an object.  The second argument is the    name.  The third argument is the type of the member.  The fourth    argument is the physical name of the member (i.e., the name as a    global variable).  The fifth argument is the visibility of the    member.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_field
name|debug_make_static_member
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_visibility
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a method.  The second argument is the name, and the third    argument is a NULL terminated array of method variants.  Each    method variant is a method with this name but with different    argument types.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_method
name|debug_make_method
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_method_variant
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a method variant.  The second argument is the physical name of    the function.  The third argument is the type of the function,    probably constructed by debug_make_method_type.  The fourth    argument is the visibility.  The fifth argument is whether this is    a const function.  The sixth argument is whether this is a volatile    function.  The seventh argument is the index in the virtual    function table, if any.  The eighth argument is the virtual    function context.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_method_variant
name|debug_make_method_variant
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
expr|enum
name|debug_visibility
operator|,
name|boolean
operator|,
name|boolean
operator|,
name|bfd_vma
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a static method argument.  The arguments are the same as for    debug_make_method_variant, except that the last two are omitted    since a static method can not also be virtual.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_method_variant
name|debug_make_static_method_variant
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|,
expr|enum
name|debug_visibility
operator|,
name|boolean
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name a type.  This returns a new type with an attached name.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_name_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Give a tag to a type, such as a struct or union.  This returns a    new type with an attached tag.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_tag_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record the size of a given type.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_record_type_size
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find a named type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_find_named_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find a tagged type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_find_tagged_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|char
operator|*
operator|,
expr|enum
name|debug_type_kind
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the kind of a type.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|debug_type_kind
name|debug_get_type_kind
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the name of a type.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|debug_get_type_name
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the size of a type.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|debug_get_type_size
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the return type of a function or method type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_get_return_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the NULL terminated array of parameter types for a function or    method type (actually, parameter types are not currently stored for    function types).  This may be used to determine whether a method    type is a stub method or not.  The last argument points to a    boolean which is set to true if the function takes a variable    number of arguments.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|debug_type
modifier|*
name|debug_get_parameter_types
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|,
name|boolean
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the target type of a pointer or reference or const or volatile    type.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_get_target_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the NULL terminated array of fields for a struct, union, or    class.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|debug_field
modifier|*
name|debug_get_fields
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the type of a field.  */
end_comment

begin_decl_stmt
specifier|extern
name|debug_type
name|debug_get_field_type
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the name of a field.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|debug_get_field_name
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the bit position of a field within the containing structure.    If the field is a static member, this will return (bfd_vma) -1.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|debug_get_field_bitpos
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the bit size of a field.  If the field is a static member, this    will return (bfd_vma) -1.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|debug_get_field_bitsize
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the visibility of a field.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|debug_visibility
name|debug_get_field_visibility
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the physical name of a field, if it is a static member.  If the    field is not a static member, this will return NULL.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|debug_get_field_physname
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|debug_field
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out the recorded debugging information.  This takes a set of    function pointers which are called to do the actual writing.  The    first PTR is the debugging handle.  The second PTR is a handle    which is passed to the functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|debug_write
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
expr|struct
name|debug_write_fns
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_H */
end_comment

end_unit

