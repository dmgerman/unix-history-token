begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- Exception handling and frame unwind runtime interface routines.
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of GCC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// the Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with GCC; see the file COPYING.  If not, write to
end_comment

begin_comment
comment|// the Free Software Foundation, 51 Franklin Street, Fifth Floor,
end_comment

begin_comment
comment|// Boston, MA 02110-1301, USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|// This is derived from the C++ ABI for IA-64.  Where we diverge
end_comment

begin_comment
comment|// for cross-architecture compatibility are noted with "@@@".
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNWIND_CXX_H
end_ifndef

begin_define
define|#
directive|define
name|_UNWIND_CXX_H
value|1
end_define

begin_comment
comment|// Level 2: C++ ABI
end_comment

begin_include
include|#
directive|include
file|<typeinfo>
end_include

begin_include
include|#
directive|include
file|<exception>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|default
name|)
end_pragma

begin_decl_stmt
name|namespace
name|__cxxabiv1
block|{
comment|// A C++ exception object consists of a header, which is a wrapper around
comment|// an unwind object header with additional C++ specific information,
comment|// followed by the exception object itself.
struct|struct
name|__cxa_exception
block|{
comment|// Manage the exception object itself.
name|std
operator|::
name|type_info
operator|*
name|exceptionType
expr_stmt|;
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
comment|// The C++ standard has entertaining rules wrt calling set_terminate
comment|// and set_unexpected in the middle of the exception cleanup process.
name|std
operator|::
name|unexpected_handler
name|unexpectedHandler
expr_stmt|;
name|std
operator|::
name|terminate_handler
name|terminateHandler
expr_stmt|;
comment|// The caught exception stack threads through here.
name|__cxa_exception
modifier|*
name|nextException
decl_stmt|;
comment|// How many nested handlers have caught this exception.  A negated
comment|// value is a signal that this object has been rethrown.
name|int
name|handlerCount
decl_stmt|;
ifdef|#
directive|ifdef
name|__ARM_EABI_UNWINDER__
comment|// Stack of exceptions in cleanups.
name|__cxa_exception
modifier|*
name|nextPropagatingException
decl_stmt|;
comment|// The nuber of active cleanup handlers for this exception.
name|int
name|propagationCount
decl_stmt|;
else|#
directive|else
comment|// Cache parsed handler data from the personality routine Phase 1
comment|// for Phase 2 and __cxa_call_unexpected.
name|int
name|handlerSwitchValue
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|actionRecord
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|languageSpecificData
decl_stmt|;
name|_Unwind_Ptr
name|catchTemp
decl_stmt|;
name|void
modifier|*
name|adjustedPtr
decl_stmt|;
endif|#
directive|endif
comment|// The generic exception header.  Must be last.
name|_Unwind_Exception
name|unwindHeader
decl_stmt|;
block|}
struct|;
comment|// Each thread in a C++ program has access to a __cxa_eh_globals object.
struct|struct
name|__cxa_eh_globals
block|{
name|__cxa_exception
modifier|*
name|caughtExceptions
decl_stmt|;
name|unsigned
name|int
name|uncaughtExceptions
decl_stmt|;
ifdef|#
directive|ifdef
name|__ARM_EABI_UNWINDER__
name|__cxa_exception
modifier|*
name|propagatingExceptions
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|// The __cxa_eh_globals for the current thread can be obtained by using
comment|// either of the following functions.  The "fast" version assumes at least
comment|// one prior call of __cxa_get_globals has been made from the current
comment|// thread, so no initialization is necessary.
extern|extern
literal|"C"
name|__cxa_eh_globals
modifier|*
name|__cxa_get_globals
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
extern|extern
literal|"C"
name|__cxa_eh_globals
modifier|*
name|__cxa_get_globals_fast
parameter_list|()
function_decl|throw
parameter_list|()
function_decl|;
comment|// Allocate memory for the exception plus the thown object.
extern|extern
literal|"C"
name|void
modifier|*
name|__cxa_allocate_exception
argument_list|(
name|std
operator|::
name|size_t
name|thrown_size
argument_list|)
name|throw
argument_list|()
decl_stmt|;
comment|// Free the space allocated for the exception.
extern|extern
literal|"C"
name|void
name|__cxa_free_exception
parameter_list|(
name|void
modifier|*
name|thrown_exception
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
comment|// Throw the exception.
extern|extern
literal|"C"
name|void
name|__cxa_throw
argument_list|(
name|void
operator|*
name|thrown_exception
argument_list|,
name|std
operator|::
name|type_info
operator|*
name|tinfo
argument_list|,
name|void
argument_list|(
operator|*
name|dest
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
comment|// Used to implement exception handlers.
extern|extern
literal|"C"
name|void
modifier|*
name|__cxa_get_exception_ptr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
extern|extern
literal|"C"
name|void
modifier|*
name|__cxa_begin_catch
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
extern|extern
literal|"C"
name|void
name|__cxa_end_catch
parameter_list|()
function_decl|;
extern|extern
literal|"C"
name|void
name|__cxa_rethrow
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
block|)
decl_stmt|);
end_decl_stmt

begin_comment
comment|// These facilitate code generation for recurring situations.
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|__cxa_bad_cast
parameter_list|()
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|void
name|__cxa_bad_typeid
parameter_list|()
function_decl|;
end_extern

begin_comment
comment|// @@@ These are not directly specified by the IA-64 C++ ABI.
end_comment

begin_comment
comment|// Handles re-checking the exception specification if unexpectedHandler
end_comment

begin_comment
comment|// throws, and if bad_exception needs to be thrown.  Called from the
end_comment

begin_comment
comment|// compiler.
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|__cxa_call_unexpected
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|__cxa_call_terminate
parameter_list|(
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_EABI_UNWINDER__
end_ifdef

begin_comment
comment|// Arm EABI specified routines.
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ctm_failed
init|=
literal|0
block|,
name|ctm_succeeded
init|=
literal|1
block|,
name|ctm_succeeded_with_ptr_to_base
init|=
literal|2
block|}
name|__cxa_type_match_result
typedef|;
end_typedef

begin_extern
extern|extern
literal|"C"
name|__cxa_type_match_result
name|__cxa_type_match
argument_list|(
name|_Unwind_Exception
operator|*
argument_list|,
specifier|const
name|std
operator|::
name|type_info
operator|*
argument_list|,
name|bool
argument_list|,
name|void
operator|*
operator|*
argument_list|)
decl_stmt|;
end_extern

begin_extern
extern|extern
literal|"C"
name|bool
name|__cxa_begin_cleanup
parameter_list|(
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|void
name|__cxa_end_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Invokes given handler, dying appropriately if the user handler was
end_comment

begin_comment
comment|// so inconsiderate as to return.
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__terminate
argument_list|(
name|std
operator|::
name|terminate_handler
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__unexpected
argument_list|(
name|std
operator|::
name|unexpected_handler
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The current installed user handlers.
end_comment

begin_extern
extern|extern std::terminate_handler __terminate_handler;
end_extern

begin_extern
extern|extern std::unexpected_handler __unexpected_handler;
end_extern

begin_comment
comment|// These are explicitly GNU C++ specific.
end_comment

begin_comment
comment|// Acquire the C++ exception header from the C++ object.
end_comment

begin_function
specifier|static
specifier|inline
name|__cxa_exception
modifier|*
name|__get_exception_header_from_obj
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|__cxa_exception
operator|*
operator|>
operator|(
name|ptr
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|// Acquire the C++ exception header from the generic exception header.
end_comment

begin_function
specifier|static
specifier|inline
name|__cxa_exception
modifier|*
name|__get_exception_header_from_ue
parameter_list|(
name|_Unwind_Exception
modifier|*
name|exc
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|__cxa_exception
operator|*
operator|>
operator|(
name|exc
operator|+
literal|1
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI_UNWINDER__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|bool
name|__is_gxx_exception_class
parameter_list|(
name|_Unwind_Exception_Class
name|c
parameter_list|)
block|{
comment|// TODO: Take advantage of the fact that c will always be word aligned.
return|return
name|c
index|[
literal|0
index|]
operator|==
literal|'G'
operator|&&
name|c
index|[
literal|1
index|]
operator|==
literal|'N'
operator|&&
name|c
index|[
literal|2
index|]
operator|==
literal|'U'
operator|&&
name|c
index|[
literal|3
index|]
operator|==
literal|'C'
operator|&&
name|c
index|[
literal|4
index|]
operator|==
literal|'C'
operator|&&
name|c
index|[
literal|5
index|]
operator|==
literal|'+'
operator|&&
name|c
index|[
literal|6
index|]
operator|==
literal|'+'
operator|&&
name|c
index|[
literal|7
index|]
operator|==
literal|'\0'
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__GXX_INIT_EXCEPTION_CLASS
parameter_list|(
name|_Unwind_Exception_Class
name|c
parameter_list|)
block|{
name|c
index|[
literal|0
index|]
operator|=
literal|'G'
expr_stmt|;
name|c
index|[
literal|1
index|]
operator|=
literal|'N'
expr_stmt|;
name|c
index|[
literal|2
index|]
operator|=
literal|'U'
expr_stmt|;
name|c
index|[
literal|3
index|]
operator|=
literal|'C'
expr_stmt|;
name|c
index|[
literal|4
index|]
operator|=
literal|'C'
expr_stmt|;
name|c
index|[
literal|5
index|]
operator|=
literal|'+'
expr_stmt|;
name|c
index|[
literal|6
index|]
operator|=
literal|'+'
expr_stmt|;
name|c
index|[
literal|7
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !__ARM_EABI_UNWINDER__ || __FreeBSD__
end_comment

begin_comment
comment|// This is the exception class we report -- "GNUCC++\0".
end_comment

begin_decl_stmt
specifier|const
name|_Unwind_Exception_Class
name|__gxx_exception_class
init|=
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'G'
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'N'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'U'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'C'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'C'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'+'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'+'
operator|)
operator|<<
literal|8
operator||
operator|(
name|_Unwind_Exception_Class
operator|)
literal|'\0'
operator|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|bool
name|__is_gxx_exception_class
parameter_list|(
name|_Unwind_Exception_Class
name|c
parameter_list|)
block|{
return|return
name|c
operator|==
name|__gxx_exception_class
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__GXX_INIT_EXCEPTION_CLASS
parameter_list|(
name|c
parameter_list|)
value|c = __gxx_exception_class
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_EABI_UNWINDER__
end_ifdef

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|__gxx_caught_object
parameter_list|(
name|_Unwind_Exception
modifier|*
name|eo
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|eo
operator|->
name|barrier_cache
operator|.
name|bitpattern
index|[
literal|0
index|]
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !__ARM_EABI_UNWINDER__
end_comment

begin_comment
comment|// GNU C++ personality routine, Version 0.
end_comment

begin_extern
extern|extern
literal|"C"
name|_Unwind_Reason_Code
name|__gxx_personality_v0
parameter_list|(
name|int
parameter_list|,
name|_Unwind_Action
parameter_list|,
name|_Unwind_Exception_Class
parameter_list|,
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|,
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|// GNU C++ sjlj personality routine, Version 0.
end_comment

begin_extern
extern|extern
literal|"C"
name|_Unwind_Reason_Code
name|__gxx_personality_sj0
parameter_list|(
name|int
parameter_list|,
name|_Unwind_Action
parameter_list|,
name|_Unwind_Exception_Class
parameter_list|,
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|,
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|__gxx_caught_object
parameter_list|(
name|_Unwind_Exception
modifier|*
name|eo
parameter_list|)
block|{
name|__cxa_exception
modifier|*
name|header
init|=
name|__get_exception_header_from_ue
argument_list|(
name|eo
argument_list|)
decl_stmt|;
return|return
name|header
operator|->
name|adjustedPtr
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !__ARM_EABI_UNWINDER__
end_comment

begin_comment
unit|}
comment|/* namespace __cxxabiv1 */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _UNWIND_CXX_H
end_comment

end_unit

