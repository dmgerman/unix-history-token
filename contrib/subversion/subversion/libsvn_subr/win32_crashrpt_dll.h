begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * win32_crashrpt_dll.h : private header file.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_WIN32_CRASHRPT_DLL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_WIN32_CRASHRPT_DLL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_USE_WIN32_CRASHHANDLER
end_ifdef

begin_comment
comment|/* public functions in dbghelp.dll */
end_comment

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|MINIDUMPWRITEDUMP
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD
name|ProcessId
parameter_list|,
name|HANDLE
name|hFile
parameter_list|,
name|MINIDUMP_TYPE
name|DumpType
parameter_list|,
name|CONST
name|PMINIDUMP_EXCEPTION_INFORMATION
name|ExceptionParam
parameter_list|,
name|CONST
name|PMINIDUMP_USER_STREAM_INFORMATION
name|UserStreamParam
parameter_list|,
name|CONST
name|PMINIDUMP_CALLBACK_INFORMATION
name|CallbackParam
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMINITIALIZE
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|PSTR
name|UserSearchPath
parameter_list|,
name|BOOL
name|fInvadeProcess
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|SYMSETOPTIONS
function_decl|)
parameter_list|(
name|DWORD
name|SymOptions
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|DWORD
function_decl|(
name|WINAPI
modifier|*
name|SYMGETOPTIONS
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMCLEANUP
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMGETTYPEINFO
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD64
name|ModBase
parameter_list|,
name|ULONG
name|TypeId
parameter_list|,
name|IMAGEHLP_SYMBOL_TYPE_INFO
name|GetType
parameter_list|,
name|PVOID
name|pInfo
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMGETLINEFROMADDR64
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD64
name|dwAddr
parameter_list|,
name|PDWORD
name|pdwDisplacement
parameter_list|,
name|PIMAGEHLP_LINE64
name|Line
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMENUMSYMBOLS
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|ULONG64
name|BaseOfDll
parameter_list|,
name|PCSTR
name|Mask
parameter_list|,
name|PSYM_ENUMERATESYMBOLS_CALLBACK
name|EnumSymbolsCallback
parameter_list|,
name|PVOID
name|UserContext
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMSETCONTEXT
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|PIMAGEHLP_STACK_FRAME
name|StackFrame
parameter_list|,
name|PIMAGEHLP_CONTEXT
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|SYMFROMADDR
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD64
name|Address
parameter_list|,
name|PDWORD64
name|Displacement
parameter_list|,
name|PSYMBOL_INFO
name|Symbol
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|STACKWALK64
function_decl|)
parameter_list|(
name|DWORD
name|MachineType
parameter_list|,
name|HANDLE
name|hProcess
parameter_list|,
name|HANDLE
name|hThread
parameter_list|,
name|LPSTACKFRAME64
name|StackFrame
parameter_list|,
name|PVOID
name|ContextRecord
parameter_list|,
name|PREAD_PROCESS_MEMORY_ROUTINE64
name|ReadMemoryRoutine
parameter_list|,
name|PFUNCTION_TABLE_ACCESS_ROUTINE64
name|FunctionTableAccessRoutine
parameter_list|,
name|PGET_MODULE_BASE_ROUTINE64
name|GetModuleBaseRoutine
parameter_list|,
name|PTRANSLATE_ADDRESS_ROUTINE64
name|TranslateAddress
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|PVOID
function_decl|(
name|WINAPI
modifier|*
name|SYMFUNCTIONTABLEACCESS64
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD64
name|AddrBase
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|DWORD64
function_decl|(
name|WINAPI
modifier|*
name|SYMGETMODULEBASE64
function_decl|)
parameter_list|(
name|HANDLE
name|hProcess
parameter_list|,
name|DWORD64
name|dwAddr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* public functions in kernel32.dll */
end_comment

begin_typedef
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|ISDEBUGGERPRESENT
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* function pointers */
end_comment

begin_decl_stmt
name|MINIDUMPWRITEDUMP
name|MiniDumpWriteDump_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMINITIALIZE
name|SymInitialize_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMSETOPTIONS
name|SymSetOptions_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMGETOPTIONS
name|SymGetOptions_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMCLEANUP
name|SymCleanup_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMGETTYPEINFO
name|SymGetTypeInfo_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMGETLINEFROMADDR64
name|SymGetLineFromAddr64_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMENUMSYMBOLS
name|SymEnumSymbols_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMSETCONTEXT
name|SymSetContext_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMFROMADDR
name|SymFromAddr_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STACKWALK64
name|StackWalk64_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMFUNCTIONTABLEACCESS64
name|SymFunctionTableAccess64_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMGETMODULEBASE64
name|SymGetModuleBase64_
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_USE_WIN32_CRASHHANDLER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_SUBR_WIN32_CRASHRPT_DLL_H */
end_comment

end_unit

