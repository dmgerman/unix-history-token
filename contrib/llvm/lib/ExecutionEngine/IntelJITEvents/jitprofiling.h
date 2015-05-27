begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- jitprofiling.h - JIT Profiling API-------------------------*- C -*-===*  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===*  *  * This file provides Intel(R) Performance Analyzer JIT (Just-In-Time)   * Profiling API declaration.  *  * NOTE: This file comes in a style different from the rest of LLVM  * source base since  this is a piece of code shared from Intel(R)  * products.  Please do not reformat / re-style this code to make  * subsequent merges and contributions from the original source base eaiser.  *  *===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__JITPROFILING_H__
end_ifndef

begin_define
define|#
directive|define
name|__JITPROFILING_H__
end_define

begin_comment
comment|/*  * Various constants used by functions  */
end_comment

begin_comment
comment|/* event notification */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|iJIT_jvm_event
block|{
comment|/* shutdown  */
comment|/*       * Program exiting EventSpecificData NA      */
name|iJVM_EVENT_TYPE_SHUTDOWN
init|=
literal|2
block|,
comment|/* JIT profiling  */
comment|/*       * issued after method code jitted into memory but before code is executed      * EventSpecificData is an iJIT_Method_Load      */
name|iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED
init|=
literal|13
block|,
comment|/* issued before unload. Method code will no longer be executed, but code       * and info are still in memory. The VTune profiler may capture method       * code only at this point EventSpecificData is iJIT_Method_Id      */
name|iJVM_EVENT_TYPE_METHOD_UNLOAD_START
block|,
comment|/* Method Profiling */
comment|/* method name, Id and stack is supplied       * issued when a method is about to be entered EventSpecificData is       * iJIT_Method_NIDS      */
name|iJVM_EVENT_TYPE_ENTER_NIDS
init|=
literal|19
block|,
comment|/* method name, Id and stack is supplied       * issued when a method is about to be left EventSpecificData is       * iJIT_Method_NIDS      */
name|iJVM_EVENT_TYPE_LEAVE_NIDS
block|}
name|iJIT_JVM_EVENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_iJIT_ModeFlags
block|{
comment|/* No need to Notify VTune, since VTune is not running */
name|iJIT_NO_NOTIFICATIONS
init|=
literal|0x0000
block|,
comment|/* when turned on the jit must call       * iJIT_NotifyEvent      * (      *     iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED,      * )      * for all the method already jitted      */
name|iJIT_BE_NOTIFY_ON_LOAD
init|=
literal|0x0001
block|,
comment|/* when turned on the jit must call      * iJIT_NotifyEvent      * (      *     iJVM_EVENT_TYPE_METHOD_UNLOAD_FINISHED,      *  ) for all the method that are unloaded      */
name|iJIT_BE_NOTIFY_ON_UNLOAD
init|=
literal|0x0002
block|,
comment|/* when turned on the jit must instrument all      * the currently jited code with calls on      * method entries      */
name|iJIT_BE_NOTIFY_ON_METHOD_ENTRY
init|=
literal|0x0004
block|,
comment|/* when turned on the jit must instrument all      * the currently jited code with calls      * on method exit      */
name|iJIT_BE_NOTIFY_ON_METHOD_EXIT
init|=
literal|0x0008
block|}
name|iJIT_ModeFlags
typedef|;
end_typedef

begin_comment
comment|/* Flags used by iJIT_IsProfilingActive() */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_iJIT_IsProfilingActiveFlags
block|{
comment|/* No profiler is running. Currently not used */
name|iJIT_NOTHING_RUNNING
init|=
literal|0x0000
block|,
comment|/* Sampling is running. This is the default value      * returned by iJIT_IsProfilingActive()      */
name|iJIT_SAMPLING_ON
init|=
literal|0x0001
block|,
comment|/* Call Graph is running */
name|iJIT_CALLGRAPH_ON
init|=
literal|0x0002
block|}
name|iJIT_IsProfilingActiveFlags
typedef|;
end_typedef

begin_comment
comment|/* Enumerator for the environment of methods*/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_iJDEnvironmentType
block|{
name|iJDE_JittingAPI
init|=
literal|2
block|}
name|iJDEnvironmentType
typedef|;
end_typedef

begin_comment
comment|/**********************************  * Data structures for the events *  **********************************/
end_comment

begin_comment
comment|/* structure for the events:  * iJVM_EVENT_TYPE_METHOD_UNLOAD_START  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_iJIT_Method_Id
block|{
comment|/* Id of the method (same as the one passed in    * the iJIT_Method_Load struct    */
name|unsigned
name|int
name|method_id
decl_stmt|;
block|}
typedef|*
name|piJIT_Method_Id
operator|,
name|iJIT_Method_Id
typedef|;
end_typedef

begin_comment
comment|/* structure for the events:  * iJVM_EVENT_TYPE_ENTER_NIDS,  * iJVM_EVENT_TYPE_LEAVE_NIDS,  * iJVM_EVENT_TYPE_EXCEPTION_OCCURRED_NIDS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_iJIT_Method_NIDS
block|{
comment|/* unique method ID */
name|unsigned
name|int
name|method_id
decl_stmt|;
comment|/* NOTE: no need to fill this field, it's filled by VTune */
name|unsigned
name|int
name|stack_id
decl_stmt|;
comment|/* method name (just the method, without the class) */
name|char
modifier|*
name|method_name
decl_stmt|;
block|}
typedef|*
name|piJIT_Method_NIDS
operator|,
name|iJIT_Method_NIDS
typedef|;
end_typedef

begin_comment
comment|/* structures for the events:  * iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LineNumberInfo
block|{
comment|/* x86 Offset from the beginning of the method*/
name|unsigned
name|int
name|Offset
decl_stmt|;
comment|/* source line number from the beginning of the source file */
name|unsigned
name|int
name|LineNumber
decl_stmt|;
block|}
typedef|*
name|pLineNumberInfo
operator|,
name|LineNumberInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_iJIT_Method_Load
block|{
comment|/* unique method ID - can be any unique value, (except 0 - 999) */
name|unsigned
name|int
name|method_id
decl_stmt|;
comment|/* method name (can be with or without the class and signature, in any case      * the class name will be added to it)      */
name|char
modifier|*
name|method_name
decl_stmt|;
comment|/* virtual address of that method - This determines the method range for the      * iJVM_EVENT_TYPE_ENTER/LEAVE_METHOD_ADDR events      */
name|void
modifier|*
name|method_load_address
decl_stmt|;
comment|/* Size in memory - Must be exact */
name|unsigned
name|int
name|method_size
decl_stmt|;
comment|/* Line Table size in number of entries - Zero if none */
name|unsigned
name|int
name|line_number_size
decl_stmt|;
comment|/* Pointer to the beginning of the line numbers info array */
name|pLineNumberInfo
name|line_number_table
decl_stmt|;
comment|/* unique class ID */
name|unsigned
name|int
name|class_id
decl_stmt|;
comment|/* class file name */
name|char
modifier|*
name|class_file_name
decl_stmt|;
comment|/* source file name */
name|char
modifier|*
name|source_file_name
decl_stmt|;
comment|/* bits supplied by the user for saving in the JIT file */
name|void
modifier|*
name|user_data
decl_stmt|;
comment|/* the size of the user data buffer */
name|unsigned
name|int
name|user_data_size
decl_stmt|;
comment|/* NOTE: no need to fill this field, it's filled by VTune */
name|iJDEnvironmentType
name|env
decl_stmt|;
block|}
typedef|*
name|piJIT_Method_Load
operator|,
name|iJIT_Method_Load
typedef|;
end_typedef

begin_comment
comment|/* API Functions */
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
ifndef|#
directive|ifndef
name|CDECL
if|#
directive|if
name|defined
name|WIN32
operator|||
name|defined
name|_WIN32
define|#
directive|define
name|CDECL
value|__cdecl
else|#
directive|else
comment|/* defined WIN32 || defined _WIN32 */
if|#
directive|if
name|defined
name|_M_X64
operator|||
name|defined
name|_M_AMD64
operator|||
name|defined
name|__x86_64__
define|#
directive|define
name|CDECL
comment|/* not actual on x86_64 platform */
else|#
directive|else
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
define|#
directive|define
name|CDECL
value|__attribute__ ((cdecl))
endif|#
directive|endif
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
endif|#
directive|endif
comment|/* defined WIN32 || defined _WIN32 */
endif|#
directive|endif
comment|/* CDECL */
define|#
directive|define
name|JITAPI
value|CDECL
comment|/* called when the settings are changed with new settings */
typedef|typedef
name|void
function_decl|(
modifier|*
name|iJIT_ModeChangedEx
function_decl|)
parameter_list|(
name|void
modifier|*
name|UserData
parameter_list|,
name|iJIT_ModeFlags
name|Flags
parameter_list|)
function_decl|;
name|int
name|JITAPI
name|iJIT_NotifyEvent
parameter_list|(
name|iJIT_JVM_EVENT
name|event_type
parameter_list|,
name|void
modifier|*
name|EventSpecificData
parameter_list|)
function_decl|;
comment|/* The new mode call back routine */
name|void
name|JITAPI
name|iJIT_RegisterCallbackEx
parameter_list|(
name|void
modifier|*
name|userdata
parameter_list|,
name|iJIT_ModeChangedEx
name|NewModeCallBackFuncEx
parameter_list|)
function_decl|;
name|iJIT_IsProfilingActiveFlags
name|JITAPI
name|iJIT_IsProfilingActive
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|JITAPI
name|FinalizeThread
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|JITAPI
name|FinalizeProcess
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|unsigned
name|int
name|JITAPI
name|iJIT_GetNewMethodID
parameter_list|(
name|void
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
comment|/* __JITPROFILING_H__ */
end_comment

end_unit

