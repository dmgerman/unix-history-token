begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declare functions used within Objective C runtime support.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__objc_proto_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__objc_proto_INCLUDE_GNU
end_define

begin_comment
comment|/* This used to be #ifndef __OBJC__, but it turns out that    object.m needs these declarations.  I don't understand why one    might want to avoid them in object.m.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/*  * objc_getClass returns the id of the class   *  object for the aClassName class.   The class   *  object holds information used by instances of   *  the class.    *  * Print a message to the standard error stream if   *  aClassName isn't part of the executable image.  */
end_comment

begin_function_decl
name|Class_t
name|objc_getClass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * objc_getMetaClass returns the id of the   *  meta class object for the aClassName class.    *  The meta class object holds information used   *  by the class object, just as the class   *  object holds information used by instances   *  of the class.    *  * Print a message to the standard error stream   *  if aClassName isn't part of the executable image.  */
end_comment

begin_function_decl
name|MetaClass_t
name|objc_getMetaClass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The compiler converts every message expression into a   *  call on one of these two functions.  Messages to   *  super are converted to calls on objc_msgSendSuper;   *  all others are converted to calls on objc_msgSend.  *  * These functions return the address of the method   *  implementation.  The compiler then generates calls  *  to those methods passing the full argument array.  *  * Calls to objc_msgSend and objc_msgSendSuper   *  should be generated only by the compiler.  You shouldn't   *  call them directly in the Objective-C code you write.  */
end_comment

begin_function_decl
name|IMP
name|objc_msgSend
parameter_list|(
name|id
parameter_list|,
name|SEL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|IMP
name|objc_msgSendSuper
parameter_list|(
name|Super_t
parameter_list|,
name|SEL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Given the name of a variable within a class's   *  definition, return a pointer to a structure that  *  describes it.  */
end_comment

begin_function_decl
name|Ivar_t
name|object_getIvarAddress
parameter_list|(
name|id
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|variableName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Given a class and a selector, return a pointer to the method's method  * structure.  Return NULL if not found.   *  * This is a method internal to the run-time.   */
end_comment

begin_function_decl
name|Method_t
name|searchForMethodInHierarchy
parameter_list|(
name|Class_t
parameter_list|,
name|SEL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The first function, sel_getUid, returns a selector that's   *  used at run time to identify the aName method.  Whenever   *  possible, you should use the @selector directive to   *  ask the compiler, rather than the run-time system,   *  to provide the selector for a method.  This function   *  should be used only if the name isn't known at compile   *  time.  *  * The second function, sel_getName, is the inverse   *  of the first.  It returns the name that was mapped to   *  aSelector.  */
end_comment

begin_function_decl
name|SEL
name|sel_getUid
parameter_list|(
specifier|const
name|STR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|STR
name|sel_getName
parameter_list|(
name|SEL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * This function returns the number of arguments that METHOD  *  the takes.  This will be at least two, since it   *  includes the ªhiddenº arguments, self and _cmd,   *  which are the first two arguments passed to every   *  method implementation.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|method_getNumberOfArguments
parameter_list|(
name|Method_t
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This functiontakes an index into METHOD's argument   *  list and returns, by reference, the type of the argument   *  and the offset to the location of that argument in the   *  list.  Indices begin with 0.  The ªhiddenº arguments   *  self and _cmd are indexed at 0 and 1; method-specific   *  arguments begin at index 2.  The offset is measured in   *  bytes and depends on the size of arguments preceding the   *  indexed argument in the argument list.  The type is   *  encoded according to the conventions of the @encode   *  compiler directive.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|method_getArgumentInfo
parameter_list|(
name|Method_t
parameter_list|,
name|int
name|indx
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|type
parameter_list|,
name|int
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function is used to support archiving when a unknown class is to read  *  from a archive.  This function returns a instantiated object.  To further  *  dearchive the object it should be sent: -readFrom:.  *  * This function positions the file pointer just past class Object's class  *  data.  */
end_comment

begin_function_decl
name|id
name|objc_objectFromFile
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*  * class_getInstanceMethod returns a pointer   *  to the data structure that describes the method.    *  * The selector must identify an   *  instance method.  *  * Return a NULL pointer if SEL doesn't   *  identify a method defined in or inherited   *  by CLASS.  */
end_comment

begin_function
specifier|static
specifier|inline
name|Method_t
name|class_getInstanceMethod
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|SEL
name|sel
parameter_list|)
block|{
return|return
name|searchForMethodInHierarchy
argument_list|(
name|class
argument_list|,
name|sel
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * class_getClassMethod returns a pointer to   *  the data structure that describes the method.    *  * The selector must identify a class (factory) method.    *  * Return a NULL pointer if SEL doesn't   *  identify a method defined in or inherited by CLASS.  */
end_comment

begin_function
specifier|static
specifier|inline
name|Method_t
name|class_getClassMethod
parameter_list|(
name|MetaClass_t
name|class
parameter_list|,
name|SEL
name|sel
parameter_list|)
block|{
return|return
name|searchForMethodInHierarchy
argument_list|(
operator|(
name|Class_t
operator|)
name|class
argument_list|,
name|sel
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This function returns the name of OBJ's   *  class.  anObject should be an instance   *  object, not a class object.  */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|object_getClassName
parameter_list|(
name|id
name|obj
parameter_list|)
block|{
return|return
name|obj
operator|->
name|class_pointer
operator|->
name|name
return|;
block|}
end_function

begin_comment
comment|/*  * This function returns the name of the   *  class.   */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|class_getClassName
parameter_list|(
name|Class_t
name|class
parameter_list|)
block|{
return|return
name|class
operator|->
name|name
return|;
block|}
end_function

begin_comment
comment|/*  * Add a class to the class hash table and assign it a class number.   */
end_comment

begin_function_decl
name|void
name|addClassToHash
parameter_list|(
name|Class_t
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function takes a list of methods and adds them to the method list of  * a class.  The method list must remain intact during the lifetime of the  * class.   */
end_comment

begin_function_decl
name|void
name|addMethodsToClass
parameter_list|(
name|Class_t
parameter_list|,
name|MethodList_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function creates a new instance of CLASS, initializes its class_pointer  * instance variable to point to the class, and return the new instance.    *  * All other instance variables are initialized to 0.   */
end_comment

begin_function
specifier|static
specifier|inline
name|id
name|class_createInstance
parameter_list|(
name|Class_t
name|class
parameter_list|)
block|{
return|return
call|(
modifier|*
name|_alloc
call|)
argument_list|(
name|class
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * object_dispose frees the memory occupied by OBJ after setting its  * class_pointer instance variable to nil, and returns nil.  The function it calls to  * do this work can be changed by reassigning the _dealloc variable.   */
end_comment

begin_function
specifier|static
specifier|inline
name|id
name|object_dispose
parameter_list|(
name|id
name|obj
parameter_list|)
block|{
return|return
call|(
modifier|*
name|_dealloc
call|)
argument_list|(
name|obj
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * object_copy creates a new object that's an exact copy of anObject and  * return the new object.  The second argument, indexedIvarBytes, specifies  * the number of additional bytes that should be allocated for the copy to  * accommodate indexed instance variables; it serves the same purpose as the  * second argument to class_createInstance.  The function that  * object_copy calls to do this work can be changed by reassigning the  * _copy variable.   */
end_comment

begin_function
specifier|static
specifier|inline
name|id
name|object_copy
parameter_list|(
name|id
name|obj
parameter_list|)
block|{
return|return
call|(
modifier|*
name|_copy
call|)
argument_list|(
name|obj
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * object_realloc reallocates storage for anObject, adding numBytes if  * possible.  The memory previously occupied by anObject is freed if it can't  * be reused, and a pointer to the new location of anObject is returned.  The  * function that object_realloc calls to do this work can be changed by  * reassigning the _realloc variable.   */
end_comment

begin_function
specifier|static
specifier|inline
name|id
name|object_realloc
parameter_list|(
name|id
name|obj
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
block|{
return|return
call|(
modifier|*
name|_realloc
call|)
argument_list|(
name|obj
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This function causes one class to pose as its super class.  Messages sent  * to the super class will actually be sent to the posing class.   *  * Instance variables should not be declared in the posing class.  The posing  * class can add new methods to the class or override existing methods in the  * super class.   */
end_comment

begin_function_decl
name|Class_t
name|class_poseAs
parameter_list|(
name|Class_t
parameter_list|,
name|Class_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These functions set and return the class version number. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|class_setVersion
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|long
name|version
parameter_list|)
block|{
name|class
operator|->
name|version
operator|=
name|version
expr_stmt|;
name|class
operator|->
name|class_pointer
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
name|long
name|class_getVersion
parameter_list|(
name|Class_t
name|class
parameter_list|)
block|{
return|return
name|class
operator|->
name|version
return|;
block|}
end_function

begin_comment
comment|/*  * Class numbers are stored in the class's info variable. This is temporary.   * Eventually we will allocate a member to the class so that some efficiency  * can be gained by not shifting.   */
end_comment

begin_define
define|#
directive|define
name|CLASS_LOCATION_SHIFT
value|(HOST_BITS_PER_LONG / 2)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|setClassNumber
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|unsigned
name|long
name|number
parameter_list|)
block|{
name|class
operator|->
name|info
operator||=
name|number
operator|<<
name|CLASS_LOCATION_SHIFT
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|getClassNumber
parameter_list|(
name|Class_t
name|class
parameter_list|)
block|{
return|return
name|class
operator|->
name|info
operator|>>
name|CLASS_LOCATION_SHIFT
return|;
block|}
end_function

begin_comment
comment|/*  * class_addInstanceMethods adds methods that can be   *  used by instances of the class and class_addClassMethods   *  adds methods used by the class object.  Before adding a   *  method, both functions check for duplicates.  A warning   *  is sent to the standard error stream if any ambiguities exist.  *  * The passed structure and its contents must exist for the the  *  duration of the program.  These functions don't support  *  linked structures.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|class_addInstanceMethods
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|MethodList_t
name|method_list
parameter_list|)
block|{
name|addMethodsToClass
argument_list|(
name|class
argument_list|,
name|method_list
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|class_addClassMethods
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|MethodList_t
name|method_list
parameter_list|)
block|{
name|addMethodsToClass
argument_list|(
operator|(
name|Class_t
operator|)
name|class
operator|->
name|class_pointer
argument_list|,
name|method_list
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This function returns the number of bytes that all of METHOD's  *  arguments, taken together, would occupy on the stack.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|method_getSizeOfArguments
parameter_list|(
name|Method_t
name|method
parameter_list|)
block|{
return|return
name|atoi
argument_list|(
operator|&
name|method
operator|->
name|method_types
index|[
literal|1
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * This function returns the size in bytes of a   *  instance of OBJ.  */
end_comment

begin_function
specifier|static
specifier|inline
name|long
name|objc_classSize
parameter_list|(
name|id
name|obj
parameter_list|)
block|{
return|return
name|obj
operator|->
name|class_pointer
operator|->
name|instance_size
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Some functions that I've been told are useful by Henry Flurry */
end_comment

begin_comment
comment|/* Returns a C string representing the ASCII rep of the selector. */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|SELNAME
parameter_list|(
name|SEL
name|sel
parameter_list|)
block|{
return|return
name|sel_getName
argument_list|(
name|sel
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Converts a C string to a SEL that can be used in perform: methods,  * objc_msgSend, etc.   */
end_comment

begin_function
specifier|static
specifier|inline
name|SEL
name|SELUID
parameter_list|(
specifier|const
name|STR
name|str
parameter_list|)
block|{
return|return
name|sel_getUid
argument_list|(
name|str
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Returns the class name of the object (or meta class name of a class  * object), or some _nilName if obj is nil.   */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|NAMEOF
parameter_list|(
name|id
name|obj
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|obj
condition|)
block|{
if|if
condition|(
name|obj
operator|->
name|class_pointer
operator|->
name|info
operator|&
name|CLS_CLASS
condition|)
name|name
operator|=
name|object_getClassName
argument_list|(
name|obj
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
operator|(
name|Class_t
operator|)
name|obj
operator|)
operator|->
name|class_pointer
operator|->
name|info
operator|&
name|CLS_META
condition|)
name|name
operator|=
name|class_getClassName
argument_list|(
operator|(
name|Class_t
operator|)
name|obj
argument_list|)
expr_stmt|;
block|}
return|return
name|name
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * These functions add and remove methods in a list from a class.  These  * functions perform the actual work required for those functions.    *  * The appropriate run-time is to provide the user callable functions to  * perform these functions.  Typically those functions perform something  * specific to their run-time type and call these functions to perform the   * actual work.  */
end_comment

begin_function_decl
name|void
name|class_removeMethods
parameter_list|(
name|Class_t
name|class
parameter_list|,
name|MethodList_t
name|method_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the named method in a linked list of methods.   */
end_comment

begin_function_decl
name|Method_t
name|searchForMethodInList
parameter_list|(
name|MethodList_t
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * printf is used if we're debugging.  If DEBUG isn't defined then this  * def isn't defined thereby causing the compiler to eliminate the parameter  * decl.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_PRINTF
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_PRINTF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Function that dumps information about all of the classes to stdout.   */
end_comment

begin_function_decl
name|void
name|debug_dump_classes
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
comment|/* not __objc_proto_INCLUDE_GNU */
end_comment

end_unit

