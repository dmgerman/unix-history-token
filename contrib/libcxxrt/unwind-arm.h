begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 2012 David Chisnall. All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *   * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE  * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_comment
comment|/**  * ARM-specific unwind definitions.  These are taken from the ARM EHABI  * specification.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|_URC_OK
init|=
literal|0
block|,
comment|/* operation completed successfully */
name|_URC_FOREIGN_EXCEPTION_CAUGHT
init|=
literal|1
block|,
name|_URC_END_OF_STACK
init|=
literal|5
block|,
name|_URC_HANDLER_FOUND
init|=
literal|6
block|,
name|_URC_INSTALL_CONTEXT
init|=
literal|7
block|,
name|_URC_CONTINUE_UNWIND
init|=
literal|8
block|,
name|_URC_FAILURE
init|=
literal|9
block|,
comment|/* unspecified failure of some kind */
name|_URC_FATAL_PHASE1_ERROR
init|=
name|_URC_FAILURE
block|}
name|_Unwind_Reason_Code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|_Unwind_State
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|_Unwind_State
name|_US_VIRTUAL_UNWIND_FRAME
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|_Unwind_State
name|_US_UNWIND_FRAME_STARTING
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|_Unwind_State
name|_US_UNWIND_FRAME_RESUME
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// GCC fails at knowing what a constant expression is
end_comment

begin_define
define|#
directive|define
name|_US_VIRTUAL_UNWIND_FRAME
value|0
end_define

begin_define
define|#
directive|define
name|_US_UNWIND_FRAME_STARTING
value|1
end_define

begin_define
define|#
directive|define
name|_US_UNWIND_FRAME_RESUME
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|_Unwind_Context
name|_Unwind_Context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|_Unwind_EHT_Header
typedef|;
end_typedef

begin_struct
struct|struct
name|_Unwind_Exception
block|{
name|uint64_t
name|exception_class
decl_stmt|;
name|void
function_decl|(
modifier|*
name|exception_cleanup
function_decl|)
parameter_list|(
name|_Unwind_Reason_Code
parameter_list|,
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
comment|/* Unwinder cache, private fields for the unwinder's use */
struct|struct
block|{
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
name|uint32_t
name|reserved4
decl_stmt|;
name|uint32_t
name|reserved5
decl_stmt|;
comment|/* init reserved1 to 0, then don't touch */
block|}
name|unwinder_cache
struct|;
comment|/* Propagation barrier cache (valid after phase 1): */
struct|struct
block|{
name|uint32_t
name|sp
decl_stmt|;
name|uint32_t
name|bitpattern
index|[
literal|5
index|]
decl_stmt|;
block|}
name|barrier_cache
struct|;
comment|/* Cleanup cache (preserved over cleanup): */
struct|struct
block|{
name|uint32_t
name|bitpattern
index|[
literal|4
index|]
decl_stmt|;
block|}
name|cleanup_cache
struct|;
comment|/* Pr cache (for pr's benefit): */
struct|struct
block|{
comment|/** function start address */
name|uint32_t
name|fnstart
decl_stmt|;
comment|/** pointer to EHT entry header word */
name|_Unwind_EHT_Header
modifier|*
name|ehtp
decl_stmt|;
comment|/** additional data */
name|uint32_t
name|additional
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
name|pr_cache
struct|;
comment|/** Force alignment of next item to 8-byte boundary */
name|long
name|long
name|int
range|:
literal|0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Unwinding functions */
end_comment

begin_function_decl
name|_Unwind_Reason_Code
name|_Unwind_RaiseException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|ucbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_Resume
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|ucbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_Complete
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|ucbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_Unwind_DeleteException
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
name|ucbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_Unwind_GetLanguageSpecificData
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|_UVRSR_OK
init|=
literal|0
block|,
name|_UVRSR_NOT_IMPLEMENTED
init|=
literal|1
block|,
name|_UVRSR_FAILED
init|=
literal|2
block|}
name|_Unwind_VRS_Result
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|_UVRSC_CORE
init|=
literal|0
block|,
name|_UVRSC_VFP
init|=
literal|1
block|,
name|_UVRSC_WMMXD
init|=
literal|3
block|,
name|_UVRSC_WMMXC
init|=
literal|4
block|}
name|_Unwind_VRS_RegClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|_UVRSD_UINT32
init|=
literal|0
block|,
name|_UVRSD_VFPX
init|=
literal|1
block|,
name|_UVRSD_UINT64
init|=
literal|3
block|,
name|_UVRSD_FLOAT
init|=
literal|4
block|,
name|_UVRSD_DOUBLE
init|=
literal|5
block|}
name|_Unwind_VRS_DataRepresentation
typedef|;
end_typedef

begin_function_decl
name|_Unwind_VRS_Result
name|_Unwind_VRS_Get
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|_Unwind_VRS_RegClass
name|regclass
parameter_list|,
name|uint32_t
name|regno
parameter_list|,
name|_Unwind_VRS_DataRepresentation
name|representation
parameter_list|,
name|void
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_Unwind_VRS_Result
name|_Unwind_VRS_Set
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|_Unwind_VRS_RegClass
name|regclass
parameter_list|,
name|uint32_t
name|regno
parameter_list|,
name|_Unwind_VRS_DataRepresentation
name|representation
parameter_list|,
name|void
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the base-address for data references.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|_Unwind_GetDataRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the base-address for text references.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|_Unwind_GetTextRelBase
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|_Unwind_GetRegionStart
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|_Unwind_Reason_Code
function_decl|(
modifier|*
name|_Unwind_Trace_Fn
function_decl|)
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|_Unwind_Reason_Code
name|_Unwind_Backtrace
parameter_list|(
name|_Unwind_Trace_Fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_Unwind_Reason_Code
name|_Unwind_Resume_or_Rethrow
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * The next set of functions are compatibility extensions, implementing Itanium  * ABI functions on top of ARM ones.  */
end_comment

begin_define
define|#
directive|define
name|_UA_SEARCH_PHASE
value|1
end_define

begin_define
define|#
directive|define
name|_UA_CLEANUP_PHASE
value|2
end_define

begin_define
define|#
directive|define
name|_UA_HANDLER_FRAME
value|4
end_define

begin_define
define|#
directive|define
name|_UA_FORCE_UNWIND
value|8
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|_Unwind_GetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|int
name|reg
parameter_list|)
block|{
name|unsigned
name|long
name|val
decl_stmt|;
name|_Unwind_VRS_Get
argument_list|(
name|context
argument_list|,
name|_UVRSC_CORE
argument_list|,
name|reg
argument_list|,
name|_UVRSD_UINT32
argument_list|,
operator|&
name|val
argument_list|)
expr_stmt|;
return|return
name|val
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|_Unwind_SetGR
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|int
name|reg
parameter_list|,
name|unsigned
name|long
name|val
parameter_list|)
block|{
name|_Unwind_VRS_Set
argument_list|(
name|context
argument_list|,
name|_UVRSC_CORE
argument_list|,
name|reg
argument_list|,
name|_UVRSD_UINT32
argument_list|,
operator|&
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|_Unwind_GetIP
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
block|{
comment|// Low bit store the thumb state - discard it
return|return
name|_Unwind_GetGR
argument_list|(
name|context
argument_list|,
literal|15
argument_list|)
operator|&
operator|~
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|_Unwind_SetIP
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|long
name|val
parameter_list|)
block|{
comment|// The lowest bit of the instruction pointer indicates whether we're in
comment|// thumb or ARM mode.  This is assumed to be fixed throughout a function,
comment|// so must be propagated when setting the program counter.
name|unsigned
name|long
name|thumbState
init|=
name|_Unwind_GetGR
argument_list|(
name|context
argument_list|,
literal|15
argument_list|)
operator|&
literal|1
decl_stmt|;
name|_Unwind_SetGR
argument_list|(
name|context
argument_list|,
literal|15
argument_list|,
operator|(
name|val
operator||
name|thumbState
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/** GNU API function that unwinds the frame */
end_comment

begin_function_decl
name|_Unwind_Reason_Code
name|__gnu_unwind_frame
parameter_list|(
name|struct
name|_Unwind_Exception
modifier|*
parameter_list|,
name|struct
name|_Unwind_Context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DECLARE_PERSONALITY_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|_Unwind_Reason_Code name(_Unwind_State state,\                          struct _Unwind_Exception *exceptionObject,\                          struct _Unwind_Context *context);
end_define

begin_define
define|#
directive|define
name|BEGIN_PERSONALITY_FUNCTION
parameter_list|(
name|name
parameter_list|)
define|\
value|_Unwind_Reason_Code name(_Unwind_State state,\                          struct _Unwind_Exception *exceptionObject,\                          struct _Unwind_Context *context)\ {\ 	int version = 1;\ 	uint64_t exceptionClass = exceptionObject->exception_class;\ 	int actions;\ 	switch (state)\ 	{\ 		default: return _URC_FAILURE;\ 		case _US_VIRTUAL_UNWIND_FRAME:\ 		{\ 			actions = _UA_SEARCH_PHASE;\ 			break;\ 		}\ 		case _US_UNWIND_FRAME_STARTING:\ 		{\ 			actions = _UA_CLEANUP_PHASE;\ 			if (exceptionObject->barrier_cache.sp == _Unwind_GetGR(context, 13))\ 			{\ 				actions |= _UA_HANDLER_FRAME;\ 			}\ 			break;\ 		}\ 		case _US_UNWIND_FRAME_RESUME:\ 		{\ 			return continueUnwinding(exceptionObject, context);\ 			break;\ 		}\ 	}\ 	_Unwind_SetGR (context, 12, reinterpret_cast<unsigned long>(exceptionObject));\  #define CALL_PERSONALITY_FUNCTION(name) name(state,exceptionObject,context)
end_define

end_unit

