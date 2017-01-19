begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acefi.h - OS specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACEFI_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACEFI_H__
end_define

begin_comment
comment|/* EDK2 EFI environemnt */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_EDK2_EFI
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GNU_EFI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|USE_MS_ABI
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_EXTENSIONS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_EFI_API
value|__cdecl
end_define

begin_elif
elif|#
directive|elif
name|USE_MS_ABI
end_elif

begin_define
define|#
directive|define
name|ACPI_EFI_API
value|__attribute__((ms_abi))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_EFI_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|64
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_comment
comment|/* for x86_64, EFI_FUNCTION_WRAPPER must be defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_MS_ABI
end_ifndef

begin_define
define|#
directive|define
name|USE_EFI_FUNCTION_WRAPPER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_EXTENSIONS
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4731
name|)
end_pragma

begin_comment
comment|/* Suppress warnings about modification of EBP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UINTN
value|uint64_t
end_define

begin_define
define|#
directive|define
name|INTN
value|int64_t
end_define

begin_define
define|#
directive|define
name|ACPI_EFI_ERR
parameter_list|(
name|a
parameter_list|)
value|(0x8000000000000000 | a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|UINTN
value|uint32_t
end_define

begin_define
define|#
directive|define
name|INTN
value|int32_t
end_define

begin_define
define|#
directive|define
name|ACPI_EFI_ERR
parameter_list|(
name|a
parameter_list|)
value|(0x80000000 | a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHAR16
value|uint16_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_EFI_FUNCTION_WRAPPER
end_ifdef

begin_define
define|#
directive|define
name|__VA_NARG__
parameter_list|(
modifier|...
parameter_list|)
define|\
value|__VA_NARG_(_0, ## __VA_ARGS__, __RSEQ_N())
end_define

begin_define
define|#
directive|define
name|__VA_NARG_
parameter_list|(
modifier|...
parameter_list|)
define|\
value|__VA_ARG_N(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__VA_ARG_N
parameter_list|(                             \
name|_0
parameter_list|,
name|_1
parameter_list|,
name|_2
parameter_list|,
name|_3
parameter_list|,
name|_4
parameter_list|,
name|_5
parameter_list|,
name|_6
parameter_list|,
name|_7
parameter_list|,
name|_8
parameter_list|,
name|_9
parameter_list|,
name|_10
parameter_list|,
name|N
parameter_list|,
modifier|...
parameter_list|)
value|N
end_define

begin_define
define|#
directive|define
name|__RSEQ_N
parameter_list|()
define|\
value|10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0
end_define

begin_define
define|#
directive|define
name|__VA_ARG_NSUFFIX__
parameter_list|(
name|prefix
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__VA_ARG_NSUFFIX_N(prefix, __VA_NARG__(__VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|__VA_ARG_NSUFFIX_N
parameter_list|(
name|prefix
parameter_list|,
name|nargs
parameter_list|)
define|\
value|__VA_ARG_NSUFFIX_N_(prefix, nargs)
end_define

begin_define
define|#
directive|define
name|__VA_ARG_NSUFFIX_N_
parameter_list|(
name|prefix
parameter_list|,
name|nargs
parameter_list|)
define|\
value|prefix ## nargs
end_define

begin_comment
comment|/* Prototypes of EFI cdecl -> stdcall trampolines */
end_comment

begin_function_decl
name|UINT64
name|efi_call0
parameter_list|(
name|void
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call1
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call2
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call3
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call4
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call5
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call6
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|,
name|UINT64
name|arg6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call7
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|,
name|UINT64
name|arg6
parameter_list|,
name|UINT64
name|arg7
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call8
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|,
name|UINT64
name|arg6
parameter_list|,
name|UINT64
name|arg7
parameter_list|,
name|UINT64
name|arg8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call9
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|,
name|UINT64
name|arg6
parameter_list|,
name|UINT64
name|arg7
parameter_list|,
name|UINT64
name|arg8
parameter_list|,
name|UINT64
name|arg9
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|efi_call10
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|UINT64
name|arg1
parameter_list|,
name|UINT64
name|arg2
parameter_list|,
name|UINT64
name|arg3
parameter_list|,
name|UINT64
name|arg4
parameter_list|,
name|UINT64
name|arg5
parameter_list|,
name|UINT64
name|arg6
parameter_list|,
name|UINT64
name|arg7
parameter_list|,
name|UINT64
name|arg8
parameter_list|,
name|UINT64
name|arg9
parameter_list|,
name|UINT64
name|arg10
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Front-ends to efi_callX to avoid compiler warnings */
end_comment

begin_define
define|#
directive|define
name|_cast64_efi_call0
parameter_list|(
name|f
parameter_list|)
define|\
value|efi_call0(f)
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call1
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|)
define|\
value|efi_call1(f, (UINT64)(a1))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call2
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|efi_call2(f, (UINT64)(a1), (UINT64)(a2))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call3
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|efi_call3(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call4
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
define|\
value|efi_call4(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call5
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
define|\
value|efi_call5(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \             (UINT64)(a5))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call6
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
define|\
value|efi_call6(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \             (UINT64)(a5), (UINT64)(a6))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call7
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|)
define|\
value|efi_call7(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \             (UINT64)(a5), (UINT64)(a6), (UINT64)(a7))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call8
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|)
define|\
value|efi_call8(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \             (UINT64)(a5), (UINT64)(a6), (UINT64)(a7), (UINT64)(a8))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call9
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|,
name|a9
parameter_list|)
define|\
value|efi_call9(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \             (UINT64)(a5), (UINT64)(a6), (UINT64)(a7), (UINT64)(a8), \             (UINT64)(a9))
end_define

begin_define
define|#
directive|define
name|_cast64_efi_call10
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|,
name|a9
parameter_list|,
name|a10
parameter_list|)
define|\
value|efi_call10(f, (UINT64)(a1), (UINT64)(a2), (UINT64)(a3), (UINT64)(a4), \              (UINT64)(a5), (UINT64)(a6), (UINT64)(a7), (UINT64)(a8), \              (UINT64)(a9), (UINT64)(a10))
end_define

begin_comment
comment|/* main wrapper (va_num ignored) */
end_comment

begin_define
define|#
directive|define
name|uefi_call_wrapper
parameter_list|(
name|func
parameter_list|,
name|va_num
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__VA_ARG_NSUFFIX__(_cast64_efi_call, __VA_ARGS__) (func , ##__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|uefi_call_wrapper
parameter_list|(
name|func
parameter_list|,
name|va_num
parameter_list|,
modifier|...
parameter_list|)
value|func(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AED EFI definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
end_if

begin_comment
comment|/* _int64 works for both IA32 and IA64 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|__int64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned __int64
end_define

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
end_define

begin_comment
comment|/* warn C4142: redefinition of type */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4142
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU EFI definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
end_if

begin_comment
comment|/*  * Math helpers  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DIV_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|d32
parameter_list|,
name|q32
parameter_list|,
name|r32
parameter_list|)
define|\
value|do {                                             \         UINT64 __n = ((UINT64) n_hi)<< 32 | (n_lo); \         (q32) = DivU64x32 ((__n), (d32),&(r32));    \     } while (0)
end_define

begin_define
define|#
directive|define
name|ACPI_SHIFT_RIGHT_64
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|)
define|\
value|do {                                \         (n_lo)>>= 1;                   \         (n_lo) |= (((n_hi)& 1)<< 31); \         (n_hi)>>= 1;                   \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|_ACPI_SIMPLE_TEXT_OUTPUT_INTERFACE
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_SIMPLE_INPUT_INTERFACE
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_EFI_FILE_IO_INTERFACE
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_EFI_FILE_HANDLE
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_EFI_BOOT_SERVICES
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_EFI_SYSTEM_TABLE
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ACPI_EFI_PCI_IO
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|_ACPI_EFI_SYSTEM_TABLE
modifier|*
name|ST
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_ACPI_EFI_BOOT_SERVICES
modifier|*
name|BS
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|union
name|acpi_efi_file
name|ACPI_EFI_FILE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FILE
value|ACPI_EFI_FILE
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stderr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACEFI_H__ */
end_comment

end_unit

