begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Defs for interface to demanglers.    Copyright 1992, 1993, 1994, 1995, 1996, 1997, 1998, 2000, 2001, 2002,    2003, 2004 Free Software Foundation, Inc.        This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEMANGLE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEMANGLE_H
end_define

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/* Options passed to cplus_demangle (in 2nd parameter). */
define|#
directive|define
name|DMGL_NO_OPTS
value|0
comment|/* For readability... */
define|#
directive|define
name|DMGL_PARAMS
value|(1<< 0)
comment|/* Include function args */
define|#
directive|define
name|DMGL_ANSI
value|(1<< 1)
comment|/* Include const, volatile, etc */
define|#
directive|define
name|DMGL_JAVA
value|(1<< 2)
comment|/* Demangle as Java rather than C++. */
define|#
directive|define
name|DMGL_VERBOSE
value|(1<< 3)
comment|/* Include implementation details.  */
define|#
directive|define
name|DMGL_TYPES
value|(1<< 4)
comment|/* Also try to demangle type encodings.  */
define|#
directive|define
name|DMGL_AUTO
value|(1<< 8)
define|#
directive|define
name|DMGL_GNU
value|(1<< 9)
define|#
directive|define
name|DMGL_LUCID
value|(1<< 10)
define|#
directive|define
name|DMGL_ARM
value|(1<< 11)
define|#
directive|define
name|DMGL_HP
value|(1<< 12)
comment|/* For the HP aCC compiler;                                             same as ARM except for                                             template arguments, etc. */
define|#
directive|define
name|DMGL_EDG
value|(1<< 13)
define|#
directive|define
name|DMGL_GNU_V3
value|(1<< 14)
define|#
directive|define
name|DMGL_GNAT
value|(1<< 15)
comment|/* If none of these are set, use 'current_demangling_style' as the default. */
define|#
directive|define
name|DMGL_STYLE_MASK
value|(DMGL_AUTO|DMGL_GNU|DMGL_LUCID|DMGL_ARM|DMGL_HP|DMGL_EDG|DMGL_GNU_V3|DMGL_JAVA|DMGL_GNAT)
comment|/* Enumeration of possible demangling styles.     Lucid and ARM styles are still kept logically distinct, even though    they now both behave identically.  The resulting style is actual the    union of both.  I.E. either style recognizes both "__pt__" and "__rf__"    for operator "->", even though the first is lucid style and the second    is ARM style. (FIXME?) */
specifier|extern
enum|enum
name|demangling_styles
block|{
name|no_demangling
init|=
operator|-
literal|1
block|,
name|unknown_demangling
init|=
literal|0
block|,
name|auto_demangling
init|=
name|DMGL_AUTO
block|,
name|gnu_demangling
init|=
name|DMGL_GNU
block|,
name|lucid_demangling
init|=
name|DMGL_LUCID
block|,
name|arm_demangling
init|=
name|DMGL_ARM
block|,
name|hp_demangling
init|=
name|DMGL_HP
block|,
name|edg_demangling
init|=
name|DMGL_EDG
block|,
name|gnu_v3_demangling
init|=
name|DMGL_GNU_V3
block|,
name|java_demangling
init|=
name|DMGL_JAVA
block|,
name|gnat_demangling
init|=
name|DMGL_GNAT
block|}
name|current_demangling_style
enum|;
comment|/* Define string names for the various demangling styles. */
define|#
directive|define
name|NO_DEMANGLING_STYLE_STRING
value|"none"
define|#
directive|define
name|AUTO_DEMANGLING_STYLE_STRING
value|"auto"
define|#
directive|define
name|GNU_DEMANGLING_STYLE_STRING
value|"gnu"
define|#
directive|define
name|LUCID_DEMANGLING_STYLE_STRING
value|"lucid"
define|#
directive|define
name|ARM_DEMANGLING_STYLE_STRING
value|"arm"
define|#
directive|define
name|HP_DEMANGLING_STYLE_STRING
value|"hp"
define|#
directive|define
name|EDG_DEMANGLING_STYLE_STRING
value|"edg"
define|#
directive|define
name|GNU_V3_DEMANGLING_STYLE_STRING
value|"gnu-v3"
define|#
directive|define
name|JAVA_DEMANGLING_STYLE_STRING
value|"java"
define|#
directive|define
name|GNAT_DEMANGLING_STYLE_STRING
value|"gnat"
comment|/* Some macros to test what demangling style is active. */
define|#
directive|define
name|CURRENT_DEMANGLING_STYLE
value|current_demangling_style
define|#
directive|define
name|AUTO_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_AUTO)
define|#
directive|define
name|GNU_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNU)
define|#
directive|define
name|LUCID_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_LUCID)
define|#
directive|define
name|ARM_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_ARM)
define|#
directive|define
name|HP_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_HP)
define|#
directive|define
name|EDG_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_EDG)
define|#
directive|define
name|GNU_V3_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNU_V3)
define|#
directive|define
name|JAVA_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_JAVA)
define|#
directive|define
name|GNAT_DEMANGLING
value|(((int) CURRENT_DEMANGLING_STYLE)& DMGL_GNAT)
comment|/* Provide information about the available demangle styles. This code is    pulled from gdb into libiberty because it is useful to binutils also.  */
specifier|extern
specifier|const
struct|struct
name|demangler_engine
block|{
specifier|const
name|char
modifier|*
specifier|const
name|demangling_style_name
decl_stmt|;
specifier|const
name|enum
name|demangling_styles
name|demangling_style
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|demangling_style_doc
decl_stmt|;
block|}
name|libiberty_demanglers
index|[]
struct|;
specifier|extern
name|char
modifier|*
name|cplus_demangle
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|cplus_demangle_opname
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|opname
operator|,
name|char
operator|*
name|result
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
name|cplus_mangle_opname
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|opname
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
comment|/* Note: This sets global state.  FIXME if you care about multi-threading. */
specifier|extern
name|void
name|set_cplus_marker_for_demangling
name|PARAMS
argument_list|(
operator|(
name|int
name|ch
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|enum
name|demangling_styles
name|cplus_demangle_set_style
name|PARAMS
argument_list|(
operator|(
expr|enum
name|demangling_styles
name|style
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|enum
name|demangling_styles
name|cplus_demangle_name_to_style
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
comment|/* V3 ABI demangling entry points, defined in cp-demangle.c.  */
specifier|extern
name|char
modifier|*
name|cplus_demangle_v3
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|,
name|int
name|options
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|char
modifier|*
name|java_demangle_v3
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|)
argument_list|)
decl_stmt|;
enum|enum
name|gnu_v3_ctor_kinds
block|{
name|gnu_v3_complete_object_ctor
init|=
literal|1
block|,
name|gnu_v3_base_object_ctor
block|,
name|gnu_v3_complete_object_allocating_ctor
block|}
enum|;
comment|/* Return non-zero iff NAME is the mangled form of a constructor name    in the G++ V3 ABI demangling style.  Specifically, return an `enum    gnu_v3_ctor_kinds' value indicating what kind of constructor    it is.  */
specifier|extern
name|enum
name|gnu_v3_ctor_kinds
name|is_gnu_v3_mangled_ctor
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
enum|enum
name|gnu_v3_dtor_kinds
block|{
name|gnu_v3_deleting_dtor
init|=
literal|1
block|,
name|gnu_v3_complete_object_dtor
block|,
name|gnu_v3_base_object_dtor
block|}
enum|;
comment|/* Return non-zero iff NAME is the mangled form of a destructor name    in the G++ V3 ABI demangling style.  Specifically, return an `enum    gnu_v3_dtor_kinds' value, indicating what kind of destructor    it is.  */
specifier|extern
name|enum
name|gnu_v3_dtor_kinds
name|is_gnu_v3_mangled_dtor
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
comment|/* The V3 demangler works in two passes.  The first pass builds a tree    representation of the mangled name, and the second pass turns the    tree representation into a demangled string.  Here we define an    interface to permit a caller to build their own tree    representation, which they can pass to the demangler to get a    demangled string.  This can be used to canonicalize user input into    something which the demangler might output.  It could also be used    by other demanglers in the future.  */
comment|/* These are the component types which may be found in the tree.  Many    component types have one or two subtrees, referred to as left and    right (a component type with only one subtree puts it in the left    subtree).  */
enum|enum
name|demangle_component_type
block|{
comment|/* A name, with a length and a pointer to a string.  */
name|DEMANGLE_COMPONENT_NAME
block|,
comment|/* A qualified name.  The left subtree is a class or namespace or      some such thing, and the right subtree is a name qualified by      that class.  */
name|DEMANGLE_COMPONENT_QUAL_NAME
block|,
comment|/* A local name.  The left subtree describes a function, and the      right subtree is a name which is local to that function.  */
name|DEMANGLE_COMPONENT_LOCAL_NAME
block|,
comment|/* A typed name.  The left subtree is a name, and the right subtree      describes that name as a function.  */
name|DEMANGLE_COMPONENT_TYPED_NAME
block|,
comment|/* A template.  The left subtree is a template name, and the right      subtree is a template argument list.  */
name|DEMANGLE_COMPONENT_TEMPLATE
block|,
comment|/* A template parameter.  This holds a number, which is the template      parameter index.  */
name|DEMANGLE_COMPONENT_TEMPLATE_PARAM
block|,
comment|/* A constructor.  This holds a name and the kind of      constructor.  */
name|DEMANGLE_COMPONENT_CTOR
block|,
comment|/* A destructor.  This holds a name and the kind of destructor.  */
name|DEMANGLE_COMPONENT_DTOR
block|,
comment|/* A vtable.  This has one subtree, the type for which this is a      vtable.  */
name|DEMANGLE_COMPONENT_VTABLE
block|,
comment|/* A VTT structure.  This has one subtree, the type for which this      is a VTT.  */
name|DEMANGLE_COMPONENT_VTT
block|,
comment|/* A construction vtable.  The left subtree is the type for which      this is a vtable, and the right subtree is the derived type for      which this vtable is built.  */
name|DEMANGLE_COMPONENT_CONSTRUCTION_VTABLE
block|,
comment|/* A typeinfo structure.  This has one subtree, the type for which      this is the tpeinfo structure.  */
name|DEMANGLE_COMPONENT_TYPEINFO
block|,
comment|/* A typeinfo name.  This has one subtree, the type for which this      is the typeinfo name.  */
name|DEMANGLE_COMPONENT_TYPEINFO_NAME
block|,
comment|/* A typeinfo function.  This has one subtree, the type for which      this is the tpyeinfo function.  */
name|DEMANGLE_COMPONENT_TYPEINFO_FN
block|,
comment|/* A thunk.  This has one subtree, the name for which this is a      thunk.  */
name|DEMANGLE_COMPONENT_THUNK
block|,
comment|/* A virtual thunk.  This has one subtree, the name for which this      is a virtual thunk.  */
name|DEMANGLE_COMPONENT_VIRTUAL_THUNK
block|,
comment|/* A covariant thunk.  This has one subtree, the name for which this      is a covariant thunk.  */
name|DEMANGLE_COMPONENT_COVARIANT_THUNK
block|,
comment|/* A Java class.  This has one subtree, the type.  */
name|DEMANGLE_COMPONENT_JAVA_CLASS
block|,
comment|/* A guard variable.  This has one subtree, the name for which this      is a guard variable.  */
name|DEMANGLE_COMPONENT_GUARD
block|,
comment|/* A reference temporary.  This has one subtree, the name for which      this is a temporary.  */
name|DEMANGLE_COMPONENT_REFTEMP
block|,
comment|/* A standard substitution.  This holds the name of the      substitution.  */
name|DEMANGLE_COMPONENT_SUB_STD
block|,
comment|/* The restrict qualifier.  The one subtree is the type which is      being qualified.  */
name|DEMANGLE_COMPONENT_RESTRICT
block|,
comment|/* The volatile qualifier.  The one subtree is the type which is      being qualified.  */
name|DEMANGLE_COMPONENT_VOLATILE
block|,
comment|/* The const qualifier.  The one subtree is the type which is being      qualified.  */
name|DEMANGLE_COMPONENT_CONST
block|,
comment|/* The restrict qualifier modifying a member function.  The one      subtree is the type which is being qualified.  */
name|DEMANGLE_COMPONENT_RESTRICT_THIS
block|,
comment|/* The volatile qualifier modifying a member function.  The one      subtree is the type which is being qualified.  */
name|DEMANGLE_COMPONENT_VOLATILE_THIS
block|,
comment|/* The const qualifier modifying a member function.  The one subtree      is the type which is being qualified.  */
name|DEMANGLE_COMPONENT_CONST_THIS
block|,
comment|/* A vendor qualifier.  The left subtree is the type which is being      qualified, and the right subtree is the name of the      qualifier.  */
name|DEMANGLE_COMPONENT_VENDOR_TYPE_QUAL
block|,
comment|/* A pointer.  The one subtree is the type which is being pointed      to.  */
name|DEMANGLE_COMPONENT_POINTER
block|,
comment|/* A reference.  The one subtree is the type which is being      referenced.  */
name|DEMANGLE_COMPONENT_REFERENCE
block|,
comment|/* A complex type.  The one subtree is the base type.  */
name|DEMANGLE_COMPONENT_COMPLEX
block|,
comment|/* An imaginary type.  The one subtree is the base type.  */
name|DEMANGLE_COMPONENT_IMAGINARY
block|,
comment|/* A builtin type.  This holds the builtin type information.  */
name|DEMANGLE_COMPONENT_BUILTIN_TYPE
block|,
comment|/* A vendor's builtin type.  This holds the name of the type.  */
name|DEMANGLE_COMPONENT_VENDOR_TYPE
block|,
comment|/* A function type.  The left subtree is the return type.  The right      subtree is a list of ARGLIST nodes.  Either or both may be      NULL.  */
name|DEMANGLE_COMPONENT_FUNCTION_TYPE
block|,
comment|/* An array type.  The left subtree is the dimension, which may be      NULL, or a string (represented as DEMANGLE_COMPONENT_NAME), or an      expression.  The right subtree is the element type.  */
name|DEMANGLE_COMPONENT_ARRAY_TYPE
block|,
comment|/* A pointer to member type.  The left subtree is the class type,      and the right subtree is the member type.  CV-qualifiers appear      on the latter.  */
name|DEMANGLE_COMPONENT_PTRMEM_TYPE
block|,
comment|/* An argument list.  The left subtree is the current argument, and      the right subtree is either NULL or another ARGLIST node.  */
name|DEMANGLE_COMPONENT_ARGLIST
block|,
comment|/* A template argument list.  The left subtree is the current      template argument, and the right subtree is either NULL or      another TEMPLATE_ARGLIST node.  */
name|DEMANGLE_COMPONENT_TEMPLATE_ARGLIST
block|,
comment|/* An operator.  This holds information about a standard      operator.  */
name|DEMANGLE_COMPONENT_OPERATOR
block|,
comment|/* An extended operator.  This holds the number of arguments, and      the name of the extended operator.  */
name|DEMANGLE_COMPONENT_EXTENDED_OPERATOR
block|,
comment|/* A typecast, represented as a unary operator.  The one subtree is      the type to which the argument should be cast.  */
name|DEMANGLE_COMPONENT_CAST
block|,
comment|/* A unary expression.  The left subtree is the operator, and the      right subtree is the single argument.  */
name|DEMANGLE_COMPONENT_UNARY
block|,
comment|/* A binary expression.  The left subtree is the operator, and the      right subtree is a BINARY_ARGS.  */
name|DEMANGLE_COMPONENT_BINARY
block|,
comment|/* Arguments to a binary expression.  The left subtree is the first      argument, and the right subtree is the second argument.  */
name|DEMANGLE_COMPONENT_BINARY_ARGS
block|,
comment|/* A trinary expression.  The left subtree is the operator, and the      right subtree is a TRINARY_ARG1.  */
name|DEMANGLE_COMPONENT_TRINARY
block|,
comment|/* Arguments to a trinary expression.  The left subtree is the first      argument, and the right subtree is a TRINARY_ARG2.  */
name|DEMANGLE_COMPONENT_TRINARY_ARG1
block|,
comment|/* More arguments to a trinary expression.  The left subtree is the      second argument, and the right subtree is the third argument.  */
name|DEMANGLE_COMPONENT_TRINARY_ARG2
block|,
comment|/* A literal.  The left subtree is the type, and the right subtree      is the value, represented as a DEMANGLE_COMPONENT_NAME.  */
name|DEMANGLE_COMPONENT_LITERAL
block|,
comment|/* A negative literal.  Like LITERAL, but the value is negated.      This is a minor hack: the NAME used for LITERAL points directly      to the mangled string, but since negative numbers are mangled      using 'n' instead of '-', we want a way to indicate a negative      number which involves neither modifying the mangled string nor      allocating a new copy of the literal in memory.  */
name|DEMANGLE_COMPONENT_LITERAL_NEG
block|}
enum|;
comment|/* Types which are only used internally.  */
struct_decl|struct
name|demangle_operator_info
struct_decl|;
struct_decl|struct
name|demangle_builtin_type_info
struct_decl|;
comment|/* A node in the tree representation is an instance of a struct    demangle_component.  Note that the field names of the struct are    not well protected against macros defined by the file including    this one.  We can fix this if it ever becomes a problem.  */
struct|struct
name|demangle_component
block|{
comment|/* The type of this component.  */
name|enum
name|demangle_component_type
name|type
decl_stmt|;
union|union
block|{
comment|/* For DEMANGLE_COMPONENT_NAME.  */
struct|struct
block|{
comment|/* A pointer to the name (which need not NULL terminated) and 	 its length.  */
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
name|s_name
struct|;
comment|/* For DEMANGLE_COMPONENT_OPERATOR.  */
struct|struct
block|{
comment|/* Operator.  */
specifier|const
name|struct
name|demangle_operator_info
modifier|*
name|op
decl_stmt|;
block|}
name|s_operator
struct|;
comment|/* For DEMANGLE_COMPONENT_EXTENDED_OPERATOR.  */
struct|struct
block|{
comment|/* Number of arguments.  */
name|int
name|args
decl_stmt|;
comment|/* Name.  */
name|struct
name|demangle_component
modifier|*
name|name
decl_stmt|;
block|}
name|s_extended_operator
struct|;
comment|/* For DEMANGLE_COMPONENT_CTOR.  */
struct|struct
block|{
comment|/* Kind of constructor.  */
name|enum
name|gnu_v3_ctor_kinds
name|kind
decl_stmt|;
comment|/* Name.  */
name|struct
name|demangle_component
modifier|*
name|name
decl_stmt|;
block|}
name|s_ctor
struct|;
comment|/* For DEMANGLE_COMPONENT_DTOR.  */
struct|struct
block|{
comment|/* Kind of destructor.  */
name|enum
name|gnu_v3_dtor_kinds
name|kind
decl_stmt|;
comment|/* Name.  */
name|struct
name|demangle_component
modifier|*
name|name
decl_stmt|;
block|}
name|s_dtor
struct|;
comment|/* For DEMANGLE_COMPONENT_BUILTIN_TYPE.  */
struct|struct
block|{
comment|/* Builtin type.  */
specifier|const
name|struct
name|demangle_builtin_type_info
modifier|*
name|type
decl_stmt|;
block|}
name|s_builtin
struct|;
comment|/* For DEMANGLE_COMPONENT_SUB_STD.  */
struct|struct
block|{
comment|/* Standard substitution string.  */
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
comment|/* Length of string.  */
name|int
name|len
decl_stmt|;
block|}
name|s_string
struct|;
comment|/* For DEMANGLE_COMPONENT_TEMPLATE_PARAM.  */
struct|struct
block|{
comment|/* Template parameter index.  */
name|long
name|number
decl_stmt|;
block|}
name|s_number
struct|;
comment|/* For other types.  */
struct|struct
block|{
comment|/* Left (or only) subtree.  */
name|struct
name|demangle_component
modifier|*
name|left
decl_stmt|;
comment|/* Right subtree.  */
name|struct
name|demangle_component
modifier|*
name|right
decl_stmt|;
block|}
name|s_binary
struct|;
block|}
name|u
union|;
block|}
struct|;
comment|/* People building mangled trees are expected to allocate instances of    struct demangle_component themselves.  They can then call one of    the following functions to fill them in.  */
comment|/* Fill in most component types with a left subtree and a right    subtree.  Returns non-zero on success, zero on failure, such as an    unrecognized or inappropriate component type.  */
specifier|extern
name|int
name|cplus_demangle_fill_component
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
expr|enum
name|demangle_component_type
operator|,
expr|struct
name|demangle_component
operator|*
name|left
operator|,
expr|struct
name|demangle_component
operator|*
name|right
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_NAME.  Returns non-zero on success,    zero for bad arguments.  */
specifier|extern
name|int
name|cplus_demangle_fill_name
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_BUILTIN_TYPE, using the name of the    builtin type (e.g., "int", etc.).  Returns non-zero on success,    zero if the type is not recognized.  */
specifier|extern
name|int
name|cplus_demangle_fill_builtin_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
specifier|const
name|char
operator|*
name|typename
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_OPERATOR, using the name of the    operator and the number of arguments which it takes (the latter is    used to disambiguate operators which can be both binary and unary,    such as '-').  Returns non-zero on success, zero if the operator is    not recognized.  */
specifier|extern
name|int
name|cplus_demangle_fill_operator
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
specifier|const
name|char
operator|*
name|opname
operator|,
name|int
name|args
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_EXTENDED_OPERATOR, providing the    number of arguments and the name.  Returns non-zero on success,    zero for bad arguments.  */
specifier|extern
name|int
name|cplus_demangle_fill_extended_operator
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
name|int
name|numargs
operator|,
expr|struct
name|demangle_component
operator|*
name|nm
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_CTOR.  Returns non-zero on success,    zero for bad arguments.  */
specifier|extern
name|int
name|cplus_demangle_fill_ctor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
expr|enum
name|gnu_v3_ctor_kinds
name|kind
operator|,
expr|struct
name|demangle_component
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
comment|/* Fill in a DEMANGLE_COMPONENT_DTOR.  Returns non-zero on success,    zero for bad arguments.  */
specifier|extern
name|int
name|cplus_demangle_fill_dtor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|demangle_component
operator|*
name|fill
operator|,
expr|enum
name|gnu_v3_dtor_kinds
name|kind
operator|,
expr|struct
name|demangle_component
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
comment|/* This function translates a mangled name into a struct    demangle_component tree.  The first argument is the mangled name.    The second argument is DMGL_* options.  This returns a pointer to a    tree on success, or NULL on failure.  On success, the third    argument is set to a block of memory allocated by malloc.  This    block should be passed to free when the tree is no longer    needed.  */
specifier|extern
name|struct
name|demangle_component
modifier|*
name|cplus_demangle_v3_components
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|mangled
operator|,
name|int
name|options
operator|,
name|void
operator|*
operator|*
name|mem
operator|)
argument_list|)
decl_stmt|;
comment|/* This function takes a struct demangle_component tree and returns    the corresponding demangled string.  The first argument is DMGL_*    options.  The second is the tree to demangle.  The third is a guess    at the length of the demangled string, used to initially allocate    the return buffer.  The fourth is a pointer to a size_t.  On    success, this function returns a buffer allocated by malloc(), and    sets the size_t pointed to by the fourth argument to the size of    the allocated buffer (not the length of the returned string).  On    failure, this function returns NULL, and sets the size_t pointed to    by the fourth argument to 0 for an invalid tree, or to 1 for a    memory allocation error.  */
specifier|extern
name|char
modifier|*
name|cplus_demangle_print
name|PARAMS
argument_list|(
operator|(
name|int
name|options
operator|,
specifier|const
expr|struct
name|demangle_component
operator|*
name|tree
operator|,
name|int
name|estimated_length
operator|,
name|size_t
operator|*
name|p_allocated_size
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEMANGLE_H */
end_comment

end_unit

