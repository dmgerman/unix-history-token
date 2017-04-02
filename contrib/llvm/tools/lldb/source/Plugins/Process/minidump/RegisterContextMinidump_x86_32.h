begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextMinidump_x86_32.h ------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_RegisterContextMinidump_x86_32_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextMinidump_x86_32_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"MinidumpTypes.h"
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/RegisterInfoInterface.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/lldb-x86-register-enums.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitmaskEnum.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_comment
comment|// C includes
end_comment

begin_comment
comment|// C++ includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|minidump
block|{
comment|// This function receives an ArrayRef pointing to the bytes of the Minidump
comment|// register context and returns a DataBuffer that's ordered by the offsets
comment|// specified in the RegisterInfoInterface argument
comment|// This way we can reuse the already existing register contexts
name|lldb
operator|::
name|DataBufferSP
name|ConvertMinidumpContext_x86_32
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|source_data
argument_list|,
name|RegisterInfoInterface
operator|*
name|target_reg_interface
argument_list|)
expr_stmt|;
comment|// Reference: see breakpad/crashpad source or WinNT.h
struct|struct
name|MinidumpFloatingSaveAreaX86
block|{
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|control_word
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|status_word
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|tag_word
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|error_offset
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|error_selector
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|data_offset
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|data_selector
expr_stmt|;
enum|enum
block|{
name|RegisterAreaSize
init|=
literal|80
block|,   }
enum|;
comment|// register_area contains eight 80-bit (x87 "long double") quantities for
comment|// floating-point registers %st0 (%mm0) through %st7 (%mm7).
name|uint8_t
name|register_area
index|[
name|RegisterAreaSize
index|]
decl_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|cr0_npx_state
expr_stmt|;
block|}
struct|;
struct|struct
name|MinidumpContext_x86_32
block|{
comment|// The context_flags field determines which parts
comment|// of the structure are populated (have valid values)
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|context_flags
expr_stmt|;
comment|// The next 6 registers are included with
comment|// MinidumpContext_x86_32_Flags::DebugRegisters
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr0
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr1
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr2
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr3
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr6
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|dr7
expr_stmt|;
comment|// The next field is included with
comment|// MinidumpContext_x86_32_Flags::FloatingPoint
name|MinidumpFloatingSaveAreaX86
name|float_save
decl_stmt|;
comment|// The next 4 registers are included with
comment|// MinidumpContext_x86_32_Flags::Segments
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|gs
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|fs
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|es
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|ds
expr_stmt|;
comment|// The next 6 registers are included with
comment|// MinidumpContext_x86_32_Flags::Integer
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|edi
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|esi
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|ebx
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|edx
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|ecx
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|eax
expr_stmt|;
comment|// The next 6 registers are included with
comment|// MinidumpContext_x86_32_Flags::Control
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|ebp
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|eip
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|cs
expr_stmt|;
comment|// WinNT.h says "must be sanitized"
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|eflags
expr_stmt|;
comment|// WinNT.h says "must be sanitized"
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|esp
expr_stmt|;
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
name|ss
expr_stmt|;
comment|// The next field is included with
comment|// MinidumpContext_x86_32_Flags::ExtendedRegisters
comment|// It contains vector (MMX/SSE) registers.  It it laid out in the
comment|// format used by the fxsave and fsrstor instructions, so it includes
comment|// a copy of the x87 floating-point registers as well.  See FXSAVE in
comment|// "Intel Architecture Software Developer's Manual, Volume 2."
enum|enum
block|{
name|ExtendedRegistersSize
init|=
literal|512
block|,   }
enum|;
name|uint8_t
name|extended_registers
index|[
name|ExtendedRegistersSize
index|]
decl_stmt|;
block|}
struct|;
name|LLVM_ENABLE_BITMASK_ENUMS_IN_NAMESPACE
argument_list|()
expr_stmt|;
comment|// For context_flags. These values indicate the type of
comment|// context stored in the structure. The high 24 bits identify the CPU, the
comment|// low 8 bits identify the type of context saved.
name|enum
name|class
name|MinidumpContext_x86_32_Flags
range|:
name|uint32_t
block|{
name|x86_32_Flag
operator|=
literal|0x00010000
block|,
comment|// CONTEXT_i386, CONTEXT_i486
name|Control
operator|=
name|x86_32_Flag
operator||
literal|0x00000001
block|,
name|Integer
operator|=
name|x86_32_Flag
operator||
literal|0x00000002
block|,
name|Segments
operator|=
name|x86_32_Flag
operator||
literal|0x00000004
block|,
name|FloatingPoint
operator|=
name|x86_32_Flag
operator||
literal|0x00000008
block|,
name|DebugRegisters
operator|=
name|x86_32_Flag
operator||
literal|0x00000010
block|,
name|ExtendedRegisters
operator|=
name|x86_32_Flag
operator||
literal|0x00000020
block|,
name|XState
operator|=
name|x86_32_Flag
operator||
literal|0x00000040
block|,
name|Full
operator|=
name|Control
operator||
name|Integer
operator||
name|Segments
block|,
name|All
operator|=
name|Full
operator||
name|FloatingPoint
operator||
name|DebugRegisters
operator||
name|ExtendedRegisters
block|,
name|LLVM_MARK_AS_BITMASK_ENUM
argument_list|(
comment|/* LargestValue = */
argument|All
argument_list|)
block|}
decl_stmt|;
block|}
comment|// end namespace minidump
block|}
end_decl_stmt

begin_comment
comment|// end namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextMinidump_x86_32_h_
end_comment

end_unit

