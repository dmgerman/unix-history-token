begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic data types for Objective C.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__objc_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__objc_INCLUDE_GNU
end_define

begin_comment
comment|/* If someone is using a c++ compiler then adjust the types in the    file back to C.  */
end_comment

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
include|#
directive|include
file|"record.h"
define|#
directive|define
name|nil
value|(id)0
comment|/* id of Nil instance */
define|#
directive|define
name|Nil
value|(Class_t)0
comment|/* id of Nil class */
typedef|typedef
name|char
modifier|*
name|STR
typedef|;
comment|/* String alias */
comment|/* Boolean typedefs */
typedef|typedef
name|char
name|BOOL
typedef|;
define|#
directive|define
name|YES
value|(BOOL)1
define|#
directive|define
name|NO
value|(BOOL)0
comment|/* Definition of a selector.  Selectors are really of type char*. The    run-time hashes the string's address to locate the method.  If the    method isn't in the hash table then a search is made through the    class hierarchy using strcmp to locate the method.  */
if|#
directive|if
literal|0
block|typedef struct objc_selector*   SEL;
else|#
directive|else
typedef|typedef
name|void
modifier|*
name|SEL
typedef|;
endif|#
directive|endif
comment|/* ObjC uses this typedef for untyped instances.  */
typedef|typedef
struct|struct
name|objc_object
block|{
name|struct
name|objc_class
modifier|*
name|class_pointer
decl_stmt|;
block|}
typedef|*
name|id
typedef|;
comment|/* Prototype for method functions. */
typedef|typedef
name|id
function_decl|(
modifier|*
name|IMP
function_decl|)
parameter_list|(
name|id
parameter_list|,
name|SEL
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* Filer types used to describe Ivars and Methods.  */
define|#
directive|define
name|_C_ID
value|'@'
define|#
directive|define
name|_C_CLASS
value|'#'
define|#
directive|define
name|_C_SEL
value|':'
define|#
directive|define
name|_C_CHR
value|'c'
define|#
directive|define
name|_C_UCHR
value|'C'
define|#
directive|define
name|_C_SHT
value|'s'
define|#
directive|define
name|_C_USHT
value|'S'
define|#
directive|define
name|_C_INT
value|'i'
define|#
directive|define
name|_C_UINT
value|'I'
define|#
directive|define
name|_C_LNG
value|'l'
define|#
directive|define
name|_C_ULNG
value|'L'
define|#
directive|define
name|_C_FLT
value|'f'
define|#
directive|define
name|_C_DBL
value|'d'
define|#
directive|define
name|_C_BFLD
value|'b'
define|#
directive|define
name|_C_VOID
value|'v'
define|#
directive|define
name|_C_UNDEF
value|'?'
define|#
directive|define
name|_C_PTR
value|'^'
define|#
directive|define
name|_C_CHARPTR
value|'*'
define|#
directive|define
name|_C_ARY_B
value|'['
define|#
directive|define
name|_C_ARY_E
value|']'
define|#
directive|define
name|_C_UNION_B
value|'('
define|#
directive|define
name|_C_UNION_E
value|')'
define|#
directive|define
name|_C_STRUCT_B
value|'{'
define|#
directive|define
name|_C_STRUCT_E
value|'}'
comment|/* These definitions are masks used with the "info" member variable in    the lass and meta class structures.  */
define|#
directive|define
name|CLS_CLASS
value|0x1L
comment|/* The structure is of type                                                   class (Class_t). */
define|#
directive|define
name|CLS_META
value|0x2L
comment|/* The structure is of type                                                   meta class (MetaClass_t). */
define|#
directive|define
name|CLS_INITIALIZED
value|0x4L
comment|/* Class is initialized. A                                                   +initialize method is the                                                   first message sent to a                                                   class.  It isn't guaranteed                                                   to be sent only once. */
define|#
directive|define
name|CLS_RTI
value|0x8L
comment|/* The class has been initialized 						   within the run time library. */
comment|/* Set this variable nonzero to print a line describing each    message that is sent.  */
specifier|extern
name|BOOL
name|objc_trace
decl_stmt|;
comment|/*  * Whereas a Module (defined further down) is the root (typically) of a file,  * a Symtab is the root of the class and category definitions within the  * module.    *  * A Symtab contains a variable length array of pointers to classes and  * categories  defined in the module.   */
typedef|typedef
struct|struct
name|objc_symtab
block|{
name|unsigned
name|long
name|sel_ref_cnt
decl_stmt|;
comment|/* Unknown. */
name|SEL
modifier|*
name|refs
decl_stmt|;
comment|/* Unknown. */
name|unsigned
name|short
name|cls_def_cnt
decl_stmt|;
comment|/* Number of classes compiled                                                   (defined) in the module. */
name|unsigned
name|short
name|cat_def_cnt
decl_stmt|;
comment|/* Number of categories                                                    compiled (defined) in the                                                    module. */
name|void
modifier|*
name|defs
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable array of pointers.                                                   cls_def_cnt of type Class_t                                                    followed by cat_def_cnt of                                                   type Category_t. */
block|}
name|Symtab
operator|,
typedef|*
name|Symtab_t
typedef|;
comment|/*  * The compiler generates one of these structures for each module that  * composes the executable (eg main.m).    *  * This data structure is the root of the definition tree for the module.    *  * A collect program runs between ld stages and creates a ObjC ctor array.   * That array holds a pointer to each module structure of the executable.   */
typedef|typedef
struct|struct
name|objc_module
block|{
name|unsigned
name|long
name|version
decl_stmt|;
comment|/* Compiler revision. */
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* sizeof(Module). */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the file where the                                                    module was generated.   The                                                    name includes the path. */
name|Symtab_t
name|symtab
decl_stmt|;
comment|/* Pointer to the Symtab of                                                   the module.  The Symtab                                                   holds an array of pointers to                                                    the classes and categories                                                    defined in the module. */
block|}
name|Module
operator|,
typedef|*
name|Module_t
typedef|;
comment|/*  * The compiler generates one of these structures for a class that has  * instance variables defined in its specification.   */
typedef|typedef
name|struct
name|objc_ivar
modifier|*
name|Ivar_t
typedef|;
typedef|typedef
struct|struct
name|objc_ivar_list
block|{
name|int
name|ivar_count
decl_stmt|;
comment|/* Number of structures (Ivar)                                                    contained in the list.  One                                                   structure per instance                                                    variable defined in the                                                   class. */
struct|struct
name|objc_ivar
block|{
specifier|const
name|char
modifier|*
name|ivar_name
decl_stmt|;
comment|/* Name of the instance                                                   variable as entered in the                                                   class definition. */
specifier|const
name|char
modifier|*
name|ivar_type
decl_stmt|;
comment|/* Description of the Ivar's                                                   type.  Useful for                                                    debuggers. */
name|int
name|ivar_offset
decl_stmt|;
comment|/* Byte offset from the base                                                    address of the instance                                                    structure to the variable. */
block|}
name|ivar_list
index|[
literal|1
index|]
struct|;
comment|/* Variable length                                                    structure. */
block|}
name|IvarList
operator|,
typedef|*
name|IvarList_t
typedef|;
comment|/*  * The compiler generates one (or more) of these structures for a class that  * has methods defined in its specification.   *  * The implementation of a class can be broken into separate pieces in a file  * and categories can break them across modules. To handle this problem is a  * singly linked list of methods.   */
typedef|typedef
name|struct
name|objc_method
name|Method
typedef|;
typedef|typedef
name|Method
modifier|*
name|Method_t
typedef|;
typedef|typedef
struct|struct
name|objc_method_list
block|{
name|struct
name|objc_method_list
modifier|*
name|method_next
decl_stmt|;
comment|/* This variable is used to link                                                  a method list to another.  It                                                  is a singly linked list. */
name|int
name|method_count
decl_stmt|;
comment|/* Number of methods defined in                                                  this structure. */
struct|struct
name|objc_method
block|{
name|SEL
name|method_name
decl_stmt|;
comment|/* This variable is the method's                                                  name.  It is a char*.                                                    The unique integer passed to                                                  objc_msgSend is a char* too.                                                   It is compared against                                                  method_name using strcmp. */
specifier|const
name|char
modifier|*
name|method_types
decl_stmt|;
comment|/* Description of the method's                                                 parameter list.  Useful for                                                 debuggers. */
name|IMP
name|method_imp
decl_stmt|;
comment|/* Address of the method in the                                                  executable. */
block|}
name|method_list
index|[
literal|1
index|]
struct|;
comment|/* Variable length                                                  structure. */
block|}
name|MethodList
operator|,
typedef|*
name|MethodList_t
typedef|;
comment|/*  * The compiler generates one of these structures for each class.    *  * This structure is the definition for meta classes. By definition a meta  * class is the class's class.  Its most relevant contribution is that its  * method list contain the class's factory methods.   *  * This structure is generated by the compiler in the executable and used by  * the run-time during normal messaging operations.  Therefore some members  * change type. The compiler generates "char* const" and places a string in  * the following member variables:  class_pointer and super_class.   */
typedef|typedef
struct|struct
name|objc_metaClass
block|{
name|struct
name|objc_metaClass
modifier|*
name|class_pointer
decl_stmt|;
comment|/* Pointer to Object meta class. */
name|struct
name|objc_metaClass
modifier|*
name|super_class
decl_stmt|;
comment|/* Pointer to meta class's                                                 super class. NULL for                                                  Object. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the meta class. */
name|long
name|version
decl_stmt|;
comment|/* Unknown. */
name|long
name|info
decl_stmt|;
comment|/* Bit mask.  See class masks                                                  defined above. */
name|long
name|instance_size
decl_stmt|;
comment|/* Always 0 except for Object.                                                 Should be ignored. */
name|IvarList_t
name|ivars
decl_stmt|;
comment|/* Always NULL except for                                                  Object.  Should be ignored. */
name|MethodList_t
name|methods
decl_stmt|;
comment|/* Linked List of factory methods                                                  for the class. */
name|struct
name|record
modifier|*
modifier|*
name|cache
decl_stmt|;
comment|/* Pointer to factory method dispatch table. */
block|}
name|MetaClass
operator|,
typedef|*
name|MetaClass_t
typedef|;
comment|/*  * The compiler generates one of these structures for each class.    *  * This structure is the definition for classes.   *  * This structure is generated by the compiler in the executable and used by  * the run-time during normal messaging operations.  Therefore some members  * change type. The compiler generates "char* const" and places a string in  * the following member variables:  super_class.   */
typedef|typedef
struct|struct
name|objc_class
block|{
name|MetaClass_t
name|class_pointer
decl_stmt|;
comment|/* Pointer to the class's                                                 meta class. */
name|struct
name|objc_class
modifier|*
name|super_class
decl_stmt|;
comment|/* Pointer to the super                                                  class. NULL for class                                                  Object. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the class. */
name|long
name|version
decl_stmt|;
comment|/* Unknown. */
name|long
name|info
decl_stmt|;
comment|/* Bit mask.  See class masks                                                  defined above. */
name|long
name|instance_size
decl_stmt|;
comment|/* Size in bytes of the class.                                                   The sum of the class definition                                                  and all super class                                                  definitions. */
name|IvarList_t
name|ivars
decl_stmt|;
comment|/* Pointer to a structure that                                                 describes the instance                                                  variables in the class                                                 definition.  NULL indicates                                                 no instance variables.  Does                                                 not include super class                                                 variables. */
name|MethodList_t
name|methods
decl_stmt|;
comment|/* Linked list of instance                                                 methods defined for the                                                  class. */
name|struct
name|record
modifier|*
modifier|*
name|cache
decl_stmt|;
comment|/* Pointer to instance method dispatch table. */
block|}
name|Class
operator|,
typedef|*
name|Class_t
typedef|;
comment|/*  * The compiler generates one of these structures for each category.  A class  * may have many categories and contain both instance and factory methods.    */
typedef|typedef
struct|struct
name|objc_category
block|{
specifier|const
name|char
modifier|*
name|category_name
decl_stmt|;
comment|/* Name of the category.  Name                                                 contained in the () of the                                                 category definition. */
specifier|const
name|char
modifier|*
name|class_name
decl_stmt|;
comment|/* Name of the class to which                                                 the category belongs. */
name|MethodList_t
name|instance_methods
decl_stmt|;
comment|/* Linked list of instance                                                 methods defined in the                                                  category. NULL indicates no                                                 instance methods defined. */
name|MethodList_t
name|class_methods
decl_stmt|;
comment|/* Linked list of factory                                                  methods defined in the                                                 category.  NULL indicates no                                                 class methods defined. */
block|}
name|Category
operator|,
typedef|*
name|Category_t
typedef|;
comment|/*  * Structure used when a message is send to a class's super class.  The  * compiler generates one of these structures and passes it to  * objc_msgSuper.   */
typedef|typedef
struct|struct
name|objc_super
block|{
name|id
name|receiver
decl_stmt|;
comment|/* Id of the object sending                                                 the message. */
name|Class_t
name|class
decl_stmt|;
comment|/* Object's super class. */
block|}
name|Super
operator|,
typedef|*
name|Super_t
typedef|;
comment|/*  * _alloc points to the function, called through class_createInstance, used  * to allocate memory for new instances.   */
specifier|extern
name|id
function_decl|(
modifier|*
name|_alloc
function_decl|)
parameter_list|(
name|Class_t
parameter_list|)
function_decl|;
comment|/*  * _dealloc points to the function, called through object_dispose, used to  * free instances.   */
specifier|extern
name|id
function_decl|(
modifier|*
name|_dealloc
function_decl|)
parameter_list|(
name|id
parameter_list|)
function_decl|;
comment|/*  * _realloc points to the function, called through object_realloc, used to  * reallocate memory for an object   */
specifier|extern
name|id
function_decl|(
modifier|*
name|_realloc
function_decl|)
parameter_list|(
name|id
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
comment|/*  * _copy points to the function, called through object_copy, used to create  * an exact copy of an object.   */
specifier|extern
name|id
function_decl|(
modifier|*
name|_copy
function_decl|)
parameter_list|(
name|id
parameter_list|)
function_decl|;
comment|/*  * _error points to the function that the run-time system calls in response  * to an error.  By default, it prints formatted error messages to the  * standard error stream and calls abort to produce a core file.   */
specifier|extern
name|void
function_decl|(
modifier|*
name|_error
function_decl|)
parameter_list|(
name|id
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __objc_INCLUDE_GNU */
end_comment

end_unit

