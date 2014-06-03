begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 2012 David Chisnall. All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE  * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CXXABI_H_
end_ifndef

begin_define
define|#
directive|define
name|__CXXABI_H_
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|class
name|type_info
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/*  * The cxxabi.h header provides a set of public definitions for types and  * functions defined by the Itanium C++ ABI specification.  For reference, see  * the ABI specification here:  *  * http://sourcery.mentor.com/public/cxx-abi/abi.html  *  * All deviations from this specification, unless otherwise noted, are  * accidental.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_decl_stmt
name|namespace
name|__cxxabiv1
block|{
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * Function type to call when an unexpected exception is encountered.  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|unexpected_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/**  * Function type to call when an unrecoverable condition is encountered.  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|terminate_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/**  * Structure used as a header on thrown exceptions.  This is the same layout as  * defined by the Itanium ABI spec, so should be interoperable with any other  * implementation of this spec, such as GNU libsupc++.  *  * This structure is allocated when an exception is thrown.  Unwinding happens  * in two phases, the first looks for a handler and the second installs the  * context.  This structure stores a cache of the handler location between  * phase 1 and phase 2.  Unfortunately, cleanup information is not cached, so  * must be looked up in both phases.  This happens for two reasons.  The first  * is that we don't know how many frames containing cleanups there will be, and  * we should avoid dynamic allocation during unwinding (the exception may be  * reporting that we've run out of memory).  The second is that finding  * cleanups is much cheaper than finding handlers, because we don't have to  * look at the type table at all.  *  * Note: Several fields of this structure have not-very-informative names.  * These are taken from the ABI spec and have not been changed to make it  * easier for people referring to to the spec while reading this code.  */
struct|struct
name|__cxa_exception
block|{
if|#
directive|if
name|__LP64__
comment|/** 	 * Reference count.  Used to support the C++11 exception_ptr class.  This 	 * is prepended to the structure in 64-bit mode and squeezed in to the 	 * padding left before the 64-bit aligned _Unwind_Exception at the end in 	 * 32-bit mode. 	 * 	 * Note that it is safe to extend this structure at the beginning, rather 	 * than the end, because the public API for creating it returns the address 	 * of the end (where the exception object can be stored). 	 */
name|uintptr_t
name|referenceCount
decl_stmt|;
endif|#
directive|endif
comment|/** Type info for the thrown object. */
name|std
operator|::
name|type_info
operator|*
name|exceptionType
expr_stmt|;
comment|/** Destructor for the object, if one exists. */
name|void
function_decl|(
modifier|*
name|exceptionDestructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** Handler called when an exception specification is violated. */
name|unexpected_handler
name|unexpectedHandler
decl_stmt|;
comment|/** Hander called to terminate. */
name|terminate_handler
name|terminateHandler
decl_stmt|;
comment|/** 	 * Next exception in the list.  If an exception is thrown inside a catch 	 * block and caught in a nested catch, this points to the exception that 	 * will be handled after the inner catch block completes. 	 */
name|__cxa_exception
modifier|*
name|nextException
decl_stmt|;
comment|/** 	 * The number of handlers that currently have references to this 	 * exception.  The top (non-sign) bit of this is used as a flag to indicate 	 * that the exception is being rethrown, so should not be deleted when its 	 * handler count reaches 0 (which it doesn't with the top bit set). 	 */
name|int
name|handlerCount
decl_stmt|;
ifdef|#
directive|ifdef
name|__arm__
comment|/** 	 * The ARM EH ABI requires the unwind library to keep track of exceptions 	 * during cleanups.  These support nesting, so we need to keep a list of 	 * them. 	 */
name|_Unwind_Exception
modifier|*
name|nextCleanup
decl_stmt|;
comment|/** 	 * The number of cleanups that are currently being run on this exception.  	 */
name|int
name|cleanupCount
decl_stmt|;
endif|#
directive|endif
comment|/** 	 * The selector value to be returned when installing the catch handler. 	 * Used at the call site to determine which catch() block should execute. 	 * This is found in phase 1 of unwinding then installed in phase 2. 	 */
name|int
name|handlerSwitchValue
decl_stmt|;
comment|/** 	 * The action record for the catch.  This is cached during phase 1 	 * unwinding. 	 */
specifier|const
name|char
modifier|*
name|actionRecord
decl_stmt|;
comment|/** 	 * Pointer to the language-specific data area (LSDA) for the handler 	 * frame.  This is unused in this implementation, but set for ABI 	 * compatibility in case we want to mix code in very weird ways. 	 */
specifier|const
name|char
modifier|*
name|languageSpecificData
decl_stmt|;
comment|/** The cached landing pad for the catch handler.*/
name|void
modifier|*
name|catchTemp
decl_stmt|;
comment|/** 	 * The pointer that will be returned as the pointer to the object.  When 	 * throwing a class and catching a virtual superclass (for example), we 	 * need to adjust the thrown pointer to make it all work correctly. 	 */
name|void
modifier|*
name|adjustedPtr
decl_stmt|;
if|#
directive|if
operator|!
name|__LP64__
comment|/** 	 * Reference count.  Used to support the C++11 exception_ptr class.  This 	 * is prepended to the structure in 64-bit mode and squeezed in to the 	 * padding left before the 64-bit aligned _Unwind_Exception at the end in 	 * 32-bit mode. 	 * 	 * Note that it is safe to extend this structure at the beginning, rather 	 * than the end, because the public API for creating it returns the address 	 * of the end (where the exception object can be stored)  	 */
name|uintptr_t
name|referenceCount
decl_stmt|;
endif|#
directive|endif
comment|/** The language-agnostic part of the exception header. */
name|_Unwind_Exception
name|unwindHeader
decl_stmt|;
block|}
struct|;
comment|/**  * ABI-specified globals structure.  Returned by the __cxa_get_globals()  * function and its fast variant.  This is a per-thread structure - every  * thread will have one lazily allocated.  *  * This structure is defined by the ABI, so may be used outside of this  * library.  */
struct|struct
name|__cxa_eh_globals
block|{
comment|/** 	 * A linked list of exceptions that are currently caught.  There may be 	 * several of these in nested catch() blocks. 	 */
name|__cxa_exception
modifier|*
name|caughtExceptions
decl_stmt|;
comment|/** 	 * The number of uncaught exceptions. 	 */
name|unsigned
name|int
name|uncaughtExceptions
decl_stmt|;
block|}
struct|;
comment|/**  * ABI function returning the __cxa_eh_globals structure.  */
name|__cxa_eh_globals
modifier|*
name|__cxa_get_globals
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Version of __cxa_get_globals() assuming that __cxa_get_globals() has already  * been called at least once by this thread.  */
name|__cxa_eh_globals
modifier|*
name|__cxa_get_globals_fast
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|std
operator|::
name|type_info
operator|*
name|__cxa_current_exception_type
argument_list|()
expr_stmt|;
comment|/**  * Throws an exception returned by __cxa_current_primary_exception().  This  * exception may have been caught in another thread.  */
name|void
name|__cxa_rethrow_primary_exception
parameter_list|(
name|void
modifier|*
name|thrown_exception
parameter_list|)
function_decl|;
comment|/**  * Returns the current exception in a form that can be stored in an  * exception_ptr object and then rethrown by a call to  * __cxa_rethrow_primary_exception().  */
name|void
modifier|*
name|__cxa_current_primary_exception
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Increments the reference count of an exception.  Called when an  * exception_ptr is copied.  */
name|void
name|__cxa_increment_exception_refcount
parameter_list|(
name|void
modifier|*
name|thrown_exception
parameter_list|)
function_decl|;
comment|/**  * Decrements the reference count of an exception.  Called when an  * exception_ptr is deleted.  */
name|void
name|__cxa_decrement_exception_refcount
parameter_list|(
name|void
modifier|*
name|thrown_exception
parameter_list|)
function_decl|;
comment|/**  * Demangles a C++ symbol or type name.  The buffer, if non-NULL, must be  * allocated with malloc() and must be *n bytes or more long.  This function  * may call realloc() on the value pointed to by buf, and will return the  * length of the string via *n.  *  * The value pointed to by status is set to one of the following:  *  * 0: success  * -1: memory allocation failure  * -2: invalid mangled name  * -3: invalid arguments  */
name|char
modifier|*
name|__cxa_demangle
parameter_list|(
specifier|const
name|char
modifier|*
name|mangled_name
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|int
modifier|*
name|status
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
comment|// extern "C"
block|}
end_decl_stmt

begin_comment
comment|// namespace
end_comment

begin_decl_stmt
name|namespace
name|abi
init|=
name|__cxxabiv1
decl_stmt|;
end_decl_stmt

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
comment|/* __CXXABI_H_ */
end_comment

end_unit

