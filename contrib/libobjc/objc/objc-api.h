begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Objective-C Runtime API.    Copyright (C) 1993, 1995, 1996, 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled    with GCC to produce an executable, this does not cause the resulting    executable to be covered by the GNU General Public License.  This    exception does not however invalidate any other reasons why the    executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__objc_api_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__objc_api_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|"objc/objc.h"
end_include

begin_include
include|#
directive|include
file|"objc/hash.h"
end_include

begin_include
include|#
directive|include
file|"objc/thr.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* For functions which return Method_t */
end_comment

begin_define
define|#
directive|define
name|METHOD_NULL
value|(Method_t)0
end_define

begin_comment
comment|/* Boolean typedefs */
end_comment

begin_comment
comment|/* ** Method descriptor returned by introspective Object methods. ** This is really just the first part of the more complete objc_method ** structure defined below and used internally by the runtime. */
end_comment

begin_struct
struct|struct
name|objc_method_description
block|{
name|SEL
name|name
decl_stmt|;
comment|/* this is a selector, not a string */
name|char
modifier|*
name|types
decl_stmt|;
comment|/* type encoding */
block|}
struct|;
end_struct

begin_comment
comment|/* Filer types used to describe Ivars and Methods.  */
end_comment

begin_define
define|#
directive|define
name|_C_ID
value|'@'
end_define

begin_define
define|#
directive|define
name|_C_CLASS
value|'#'
end_define

begin_define
define|#
directive|define
name|_C_SEL
value|':'
end_define

begin_define
define|#
directive|define
name|_C_CHR
value|'c'
end_define

begin_define
define|#
directive|define
name|_C_UCHR
value|'C'
end_define

begin_define
define|#
directive|define
name|_C_SHT
value|'s'
end_define

begin_define
define|#
directive|define
name|_C_USHT
value|'S'
end_define

begin_define
define|#
directive|define
name|_C_INT
value|'i'
end_define

begin_define
define|#
directive|define
name|_C_UINT
value|'I'
end_define

begin_define
define|#
directive|define
name|_C_LNG
value|'l'
end_define

begin_define
define|#
directive|define
name|_C_ULNG
value|'L'
end_define

begin_define
define|#
directive|define
name|_C_LNG_LNG
value|'q'
end_define

begin_define
define|#
directive|define
name|_C_ULNG_LNG
value|'Q'
end_define

begin_define
define|#
directive|define
name|_C_FLT
value|'f'
end_define

begin_define
define|#
directive|define
name|_C_DBL
value|'d'
end_define

begin_define
define|#
directive|define
name|_C_BFLD
value|'b'
end_define

begin_define
define|#
directive|define
name|_C_VOID
value|'v'
end_define

begin_define
define|#
directive|define
name|_C_UNDEF
value|'?'
end_define

begin_define
define|#
directive|define
name|_C_PTR
value|'^'
end_define

begin_define
define|#
directive|define
name|_C_CHARPTR
value|'*'
end_define

begin_define
define|#
directive|define
name|_C_ATOM
value|'%'
end_define

begin_define
define|#
directive|define
name|_C_ARY_B
value|'['
end_define

begin_define
define|#
directive|define
name|_C_ARY_E
value|']'
end_define

begin_define
define|#
directive|define
name|_C_UNION_B
value|'('
end_define

begin_define
define|#
directive|define
name|_C_UNION_E
value|')'
end_define

begin_define
define|#
directive|define
name|_C_STRUCT_B
value|'{'
end_define

begin_define
define|#
directive|define
name|_C_STRUCT_E
value|'}'
end_define

begin_comment
comment|/* ** Error handling ** ** Call objc_error() or objc_verror() to record an error; this error ** routine will generally exit the program but not necessarily if the ** user has installed his own error handler. ** ** Call objc_set_error_handler to assign your own function for ** handling errors.  The function should return YES if it is ok ** to continue execution, or return NO or just abort if the ** program should be stopped.  The default error handler is just to ** print a message on stderr. ** ** The error handler function should be of type objc_error_handler ** The first parameter is an object instance of relevance. ** The second parameter is an error code. ** The third parameter is a format string in the printf style. ** The fourth parameter is a variable list of arguments. */
end_comment

begin_function_decl
specifier|extern
name|void
name|objc_error
parameter_list|(
name|id
name|object
parameter_list|,
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|objc_verror
parameter_list|(
name|id
name|object
parameter_list|,
name|int
name|code
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
end_function_decl

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
modifier|*
name|objc_error_handler
function_decl|)
parameter_list|(
name|id
parameter_list|,
name|int
name|code
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
end_typedef

begin_function_decl
name|objc_error_handler
name|objc_set_error_handler
parameter_list|(
name|objc_error_handler
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Error codes ** These are used by the runtime library, and your ** error handling may use them to determine if the error is ** hard or soft thus whether execution can continue or abort. */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_UNKNOWN
value|0
end_define

begin_comment
comment|/* Generic error */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_OBJC_VERSION
value|1
end_define

begin_comment
comment|/* Incorrect runtime version */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_GCC_VERSION
value|2
end_define

begin_comment
comment|/* Incorrect compiler version */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_MODULE_SIZE
value|3
end_define

begin_comment
comment|/* Bad module size */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_PROTOCOL_VERSION
value|4
end_define

begin_comment
comment|/* Incorrect protocol version */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_MEMORY
value|10
end_define

begin_comment
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_RECURSE_ROOT
value|20
end_define

begin_comment
comment|/* Attempt to archive the root 					  object more than once. */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_DATA
value|21
end_define

begin_comment
comment|/* Didn't read expected data */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_KEY
value|22
end_define

begin_comment
comment|/* Bad key for object */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_CLASS
value|23
end_define

begin_comment
comment|/* Unknown class */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_TYPE
value|24
end_define

begin_comment
comment|/* Bad type specification */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_NO_READ
value|25
end_define

begin_comment
comment|/* Cannot read stream */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_NO_WRITE
value|26
end_define

begin_comment
comment|/* Cannot write stream */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_STREAM_VERSION
value|27
end_define

begin_comment
comment|/* Incorrect stream version */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_OPCODE
value|28
end_define

begin_comment
comment|/* Bad opcode */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_UNIMPLEMENTED
value|30
end_define

begin_comment
comment|/* Method is not implemented */
end_comment

begin_define
define|#
directive|define
name|OBJC_ERR_BAD_STATE
value|40
end_define

begin_comment
comment|/* Bad thread state */
end_comment

begin_comment
comment|/* ** Set this variable nonzero to print a line describing each ** message that is sent.  (this is currently disabled) */
end_comment

begin_decl_stmt
specifier|extern
name|BOOL
name|objc_trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For every class which happens to have statically allocated instances in    this module, one OBJC_STATIC_INSTANCES is allocated by the compiler.    INSTANCES is NULL terminated and points to all statically allocated    instances of this class.  */
end_comment

begin_struct
struct|struct
name|objc_static_instances
block|{
name|char
modifier|*
name|class_name
decl_stmt|;
name|id
name|instances
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Whereas a Module (defined further down) is the root (typically) of a file, ** a Symtab is the root of the class and category definitions within the ** module.   **  ** A Symtab contains a variable length array of pointers to classes and ** categories  defined in the module.  */
end_comment

begin_typedef
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
comment|/* Variable array of pointers.                                                   cls_def_cnt of type Class                                                    followed by cat_def_cnt of                                                   type Category_t, followed 						  by a NULL terminated array 						  of objc_static_instances. */
block|}
name|Symtab
operator|,
typedef|*
name|Symtab_t
typedef|;
end_typedef

begin_comment
comment|/* ** The compiler generates one of these structures for each module that ** composes the executable (eg main.m).   **  ** This data structure is the root of the definition tree for the module.   **  ** A collect program runs between ld stages and creates a ObjC ctor array.  ** That array holds a pointer to each module structure of the executable.  */
end_comment

begin_typedef
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
comment|/* Pointer to the Symtab of                                                   the module.  The Symtab                                                   holds an array of  						  pointers to                                                    the classes and categories                                                    defined in the module. */
block|}
name|Module
operator|,
typedef|*
name|Module_t
typedef|;
end_typedef

begin_comment
comment|/* ** The compiler generates one of these structures for a class that has ** instance variables defined in its specification.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|objc_ivar
modifier|*
name|Ivar_t
typedef|;
end_typedef

begin_typedef
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
end_typedef

begin_comment
comment|/* ** The compiler generates one (or more) of these structures for a class that ** has methods defined in its specification.  **  ** The implementation of a class can be broken into separate pieces in a file ** and categories can break them across modules. To handle this problem is a ** singly linked list of methods.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|objc_method
name|Method
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Method
modifier|*
name|Method_t
typedef|;
end_typedef

begin_typedef
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
comment|/* This variable is the method's                                                  name.  It is a char*.                                                    The unique integer passed to                                                  objc_msg_send is a char* too.                                                   It is compared against                                                  method_name using strcmp. */
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
end_typedef

begin_struct
struct|struct
name|objc_protocol_list
block|{
name|struct
name|objc_protocol_list
modifier|*
name|next
decl_stmt|;
name|int
name|count
decl_stmt|;
name|Protocol
modifier|*
name|list
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** This is used to assure consistent access to the info field of  ** classes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_BITS_PER_LONG
end_ifndef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|(sizeof(long)*8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__CLS_INFO
parameter_list|(
name|cls
parameter_list|)
value|((cls)->info)
end_define

begin_define
define|#
directive|define
name|__CLS_ISINFO
parameter_list|(
name|cls
parameter_list|,
name|mask
parameter_list|)
value|((__CLS_INFO(cls)&mask)==mask)
end_define

begin_define
define|#
directive|define
name|__CLS_SETINFO
parameter_list|(
name|cls
parameter_list|,
name|mask
parameter_list|)
value|(__CLS_INFO(cls) |= mask)
end_define

begin_comment
comment|/* The structure is of type MetaClass */
end_comment

begin_define
define|#
directive|define
name|_CLS_META
value|0x2L
end_define

begin_define
define|#
directive|define
name|CLS_ISMETA
parameter_list|(
name|cls
parameter_list|)
value|((cls)&&__CLS_ISINFO(cls, _CLS_META))
end_define

begin_comment
comment|/* The structure is of type Class */
end_comment

begin_define
define|#
directive|define
name|_CLS_CLASS
value|0x1L
end_define

begin_define
define|#
directive|define
name|CLS_ISCLASS
parameter_list|(
name|cls
parameter_list|)
value|((cls)&&__CLS_ISINFO(cls, _CLS_CLASS))
end_define

begin_comment
comment|/* ** The class is initialized within the runtime.  This means that  ** it has had correct super and sublinks assigned */
end_comment

begin_define
define|#
directive|define
name|_CLS_RESOLV
value|0x8L
end_define

begin_define
define|#
directive|define
name|CLS_ISRESOLV
parameter_list|(
name|cls
parameter_list|)
value|__CLS_ISINFO(cls, _CLS_RESOLV)
end_define

begin_define
define|#
directive|define
name|CLS_SETRESOLV
parameter_list|(
name|cls
parameter_list|)
value|__CLS_SETINFO(cls, _CLS_RESOLV)
end_define

begin_comment
comment|/* ** The class has been send a +initialize message or a such is not  ** defined for this class */
end_comment

begin_define
define|#
directive|define
name|_CLS_INITIALIZED
value|0x04L
end_define

begin_define
define|#
directive|define
name|CLS_ISINITIALIZED
parameter_list|(
name|cls
parameter_list|)
value|__CLS_ISINFO(cls, _CLS_INITIALIZED)
end_define

begin_define
define|#
directive|define
name|CLS_SETINITIALIZED
parameter_list|(
name|cls
parameter_list|)
value|__CLS_SETINFO(cls, _CLS_INITIALIZED)
end_define

begin_comment
comment|/* ** The class number of this class.  This must be the same for both the  ** class and its meta class object */
end_comment

begin_define
define|#
directive|define
name|CLS_GETNUMBER
parameter_list|(
name|cls
parameter_list|)
value|(__CLS_INFO(cls)>> (HOST_BITS_PER_LONG/2))
end_define

begin_define
define|#
directive|define
name|CLS_SETNUMBER
parameter_list|(
name|cls
parameter_list|,
name|num
parameter_list|)
define|\
value|({ (cls)->info<<= (HOST_BITS_PER_LONG/2); \      (cls)->info>>= (HOST_BITS_PER_LONG/2); \      __CLS_SETINFO(cls, (((unsigned long)num)<< (HOST_BITS_PER_LONG/2))); })
end_define

begin_comment
comment|/* ** The compiler generates one of these structures for each category.  A class ** may have many categories and contain both instance and factory methods.   */
end_comment

begin_typedef
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
name|struct
name|objc_protocol_list
modifier|*
name|protocols
decl_stmt|;
comment|/* List of Protocols  					         conformed to */
block|}
name|Category
operator|,
typedef|*
name|Category_t
typedef|;
end_typedef

begin_comment
comment|/* ** Structure used when a message is send to a class's super class.  The ** compiler generates one of these structures and passes it to ** objc_msg_super. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|objc_super
block|{
name|id
name|self
decl_stmt|;
comment|/* Id of the object sending                                                 the message. */
name|Class
name|class
decl_stmt|;
comment|/* Object's super class. */
block|}
name|Super
operator|,
typedef|*
name|Super_t
typedef|;
end_typedef

begin_function_decl
name|IMP
name|objc_msg_lookup_super
parameter_list|(
name|Super_t
name|super
parameter_list|,
name|SEL
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|retval_t
name|objc_msg_sendv
parameter_list|(
name|id
parameter_list|,
name|SEL
parameter_list|,
name|arglist_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** This is a hook which is called by objc_lookup_class and ** objc_get_class if the runtime is not able to find the class. ** This may e.g. try to load in the class using dynamic loading. ** The function is guaranteed to be passed a non-NULL name string. */
end_comment

begin_function_decl
specifier|extern
name|Class
function_decl|(
modifier|*
name|_objc_lookup_class
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** This is a hook which is called by __objc_exec_class every time a class ** or a category is loaded into the runtime.  This may e.g. help a ** dynamic loader determine the classes that have been loaded when ** an object file is dynamically linked in. */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|_objc_load_callback
function_decl|)
parameter_list|(
name|Class
name|class
parameter_list|,
name|Category
modifier|*
name|category
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Hook functions for allocating, copying and disposing of instances */
end_comment

begin_function_decl
specifier|extern
name|id
function_decl|(
modifier|*
name|_objc_object_alloc
function_decl|)
parameter_list|(
name|Class
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|id
function_decl|(
modifier|*
name|_objc_object_copy
function_decl|)
parameter_list|(
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|id
function_decl|(
modifier|*
name|_objc_object_dispose
function_decl|)
parameter_list|(
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Standard functions for memory allocation and disposal. ** Users should use these functions in their ObjC programs so ** that they work properly with garbage collectors as well as ** can take advantage of the exception/error handling available. */
end_comment

begin_function_decl
name|void
modifier|*
name|objc_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|objc_atomic_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|objc_valloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|objc_realloc
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|objc_calloc
parameter_list|(
name|size_t
name|nelem
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|objc_free
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** Hook functions for memory allocation and disposal. ** This makes it easy to substitute garbage collection systems ** such as Boehm's GC by assigning these function pointers ** to the GC's allocation routines.  By default these point ** to the ANSI standard malloc, realloc, free, etc. ** ** Users should call the normal objc routines above for ** memory allocation and disposal within their programs. */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_objc_malloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_objc_atomic_malloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_objc_valloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_objc_realloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|_objc_calloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|_objc_free
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Method_t
name|class_get_class_method
parameter_list|(
name|MetaClass
name|class
parameter_list|,
name|SEL
name|aSel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Method_t
name|class_get_instance_method
parameter_list|(
name|Class
name|class
parameter_list|,
name|SEL
name|aSel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Class
name|class_pose_as
parameter_list|(
name|Class
name|impostor
parameter_list|,
name|Class
name|superclass
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Class
name|objc_get_class
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Class
name|objc_lookup_class
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Class
name|objc_next_class
parameter_list|(
name|void
modifier|*
modifier|*
name|enum_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sel_get_name
parameter_list|(
name|SEL
name|selector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sel_get_type
parameter_list|(
name|SEL
name|selector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_get_uid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_get_any_uid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_get_any_typed_uid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_get_typed_uid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_register_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SEL
name|sel_register_typed_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOL
name|sel_is_mapped
parameter_list|(
name|SEL
name|aSel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|id
name|class_create_instance
parameter_list|(
name|Class
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|class_get_class_name
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|name
else|:
operator|(
operator|(
name|class
operator|==
name|Nil
operator|)
condition|?
literal|"Nil"
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|class_get_instance_size
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|instance_size
else|:
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|MetaClass
name|class_get_meta_class
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|class_pointer
else|:
name|Nil
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|Class
name|class_get_super_class
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|super_class
else|:
name|Nil
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|class_get_version
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|version
else|:
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOL
name|class_is_class
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOL
name|class_is_meta_class
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISMETA
argument_list|(
name|class
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|class_set_version
parameter_list|(
name|Class
name|class
parameter_list|,
name|long
name|version
parameter_list|)
block|{
if|if
condition|(
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|)
name|class
operator|->
name|version
operator|=
name|version
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|class_get_gc_object_type
parameter_list|(
name|Class
name|class
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
name|class
argument_list|)
condition|?
name|class
operator|->
name|gc_object_type
else|:
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Mark the instance variable as innaccessible to the garbage collector */
end_comment

begin_function_decl
specifier|extern
name|void
name|class_ivar_set_gcinvisible
parameter_list|(
name|Class
name|class
parameter_list|,
specifier|const
name|char
modifier|*
name|ivarname
parameter_list|,
name|BOOL
name|gcInvisible
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|IMP
name|method_get_imp
parameter_list|(
name|Method_t
name|method
parameter_list|)
block|{
return|return
operator|(
name|method
operator|!=
name|METHOD_NULL
operator|)
condition|?
name|method
operator|->
name|method_imp
else|:
operator|(
name|IMP
operator|)
literal|0
return|;
block|}
end_function

begin_function_decl
name|IMP
name|get_imp
parameter_list|(
name|Class
name|class
parameter_list|,
name|SEL
name|sel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Redefine on NeXTSTEP so as not to conflict with system function */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NeXT__
end_ifdef

begin_define
define|#
directive|define
name|object_copy
value|gnu_object_copy
end_define

begin_define
define|#
directive|define
name|object_dispose
value|gnu_object_dispose
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|id
name|object_copy
parameter_list|(
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|id
name|object_dispose
parameter_list|(
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|Class
name|object_get_class
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
operator|(
operator|(
name|object
operator|!=
name|nil
operator|)
condition|?
operator|(
name|CLS_ISCLASS
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
name|object
operator|->
name|class_pointer
else|:
operator|(
name|CLS_ISMETA
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
operator|(
name|Class
operator|)
name|object
else|:
name|Nil
operator|)
operator|)
else|:
name|Nil
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|object_get_class_name
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
operator|(
operator|(
name|object
operator|!=
name|nil
operator|)
condition|?
operator|(
name|CLS_ISCLASS
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
name|object
operator|->
name|class_pointer
operator|->
name|name
else|:
operator|(
operator|(
name|Class
operator|)
name|object
operator|)
operator|->
name|name
operator|)
else|:
literal|"Nil"
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|MetaClass
name|object_get_meta_class
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
operator|(
operator|(
name|object
operator|!=
name|nil
operator|)
condition|?
operator|(
name|CLS_ISCLASS
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
name|object
operator|->
name|class_pointer
operator|->
name|class_pointer
else|:
operator|(
name|CLS_ISMETA
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
name|object
operator|->
name|class_pointer
else|:
name|Nil
operator|)
operator|)
else|:
name|Nil
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|Class
name|object_get_super_class
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
operator|(
operator|(
name|object
operator|!=
name|nil
operator|)
condition|?
operator|(
name|CLS_ISCLASS
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
name|object
operator|->
name|class_pointer
operator|->
name|super_class
else|:
operator|(
name|CLS_ISMETA
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
condition|?
operator|(
operator|(
name|Class
operator|)
name|object
operator|)
operator|->
name|super_class
else|:
name|Nil
operator|)
operator|)
else|:
name|Nil
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOL
name|object_is_class
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
name|CLS_ISCLASS
argument_list|(
operator|(
name|Class
operator|)
name|object
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOL
name|object_is_instance
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
operator|(
name|object
operator|!=
name|nil
operator|)
operator|&&
name|CLS_ISCLASS
argument_list|(
name|object
operator|->
name|class_pointer
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOL
name|object_is_meta_class
parameter_list|(
name|id
name|object
parameter_list|)
block|{
return|return
name|CLS_ISMETA
argument_list|(
operator|(
name|Class
operator|)
name|object
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|struct
name|sarray
modifier|*
name|objc_get_uninstalled_dtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __objc_api_INCLUDE_GNU */
end_comment

end_unit

