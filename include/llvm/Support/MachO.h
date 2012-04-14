begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/MachO.h - The MachO file format ------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines manifest constants for the MachO object file format.
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
name|LLVM_SUPPORT_MACHO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MACHO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_comment
comment|// NOTE: The enums in this file are intentially named to be different than those
end_comment

begin_comment
comment|// in the headers in /usr/include/mach (on darwin systems) to avoid conflicts
end_comment

begin_comment
comment|// with those macros.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|MachO
block|{
comment|// Enums from<mach-o/loader.h>
enum|enum
block|{
comment|// Constants for the "magic" field in llvm::MachO::mach_header and
comment|// llvm::MachO::mach_header_64
name|HeaderMagic32
init|=
literal|0xFEEDFACEu
block|,
comment|// MH_MAGIC
name|HeaderMagic32Swapped
init|=
literal|0xCEFAEDFEu
block|,
comment|// MH_CIGAM
name|HeaderMagic64
init|=
literal|0xFEEDFACFu
block|,
comment|// MH_MAGIC_64
name|HeaderMagic64Swapped
init|=
literal|0xCFFAEDFEu
block|,
comment|// MH_CIGAM_64
name|UniversalMagic
init|=
literal|0xCAFEBABEu
block|,
comment|// FAT_MAGIC
name|UniversalMagicSwapped
init|=
literal|0xBEBAFECAu
block|,
comment|// FAT_CIGAM
comment|// Constants for the "filetype" field in llvm::MachO::mach_header and
comment|// llvm::MachO::mach_header_64
name|HeaderFileTypeObject
init|=
literal|0x1u
block|,
comment|// MH_OBJECT
name|HeaderFileTypeExecutable
init|=
literal|0x2u
block|,
comment|// MH_EXECUTE
name|HeaderFileTypeFixedVMShlib
init|=
literal|0x3u
block|,
comment|// MH_FVMLIB
name|HeaderFileTypeCore
init|=
literal|0x4u
block|,
comment|// MH_CORE
name|HeaderFileTypePreloadedExecutable
init|=
literal|0x5u
block|,
comment|// MH_PRELOAD
name|HeaderFileTypeDynamicShlib
init|=
literal|0x6u
block|,
comment|// MH_DYLIB
name|HeaderFileTypeDynamicLinkEditor
init|=
literal|0x7u
block|,
comment|// MH_DYLINKER
name|HeaderFileTypeBundle
init|=
literal|0x8u
block|,
comment|// MH_BUNDLE
name|HeaderFileTypeDynamicShlibStub
init|=
literal|0x9u
block|,
comment|// MH_DYLIB_STUB
name|HeaderFileTypeDSYM
init|=
literal|0xAu
block|,
comment|// MH_DSYM
name|HeaderFileTypeKextBundle
init|=
literal|0xBu
block|,
comment|// MH_KEXT_BUNDLE
comment|// Constant bits for the "flags" field in llvm::MachO::mach_header and
comment|// llvm::MachO::mach_header_64
name|HeaderFlagBitNoUndefinedSymbols
init|=
literal|0x00000001u
block|,
comment|// MH_NOUNDEFS
name|HeaderFlagBitIsIncrementalLinkObject
init|=
literal|0x00000002u
block|,
comment|// MH_INCRLINK
name|HeaderFlagBitIsDynamicLinkObject
init|=
literal|0x00000004u
block|,
comment|// MH_DYLDLINK
name|HeaderFlagBitBindAtLoad
init|=
literal|0x00000008u
block|,
comment|// MH_BINDATLOAD
name|HeaderFlagBitPrebound
init|=
literal|0x00000010u
block|,
comment|// MH_PREBOUND
name|HeaderFlagBitSplitSegments
init|=
literal|0x00000020u
block|,
comment|// MH_SPLIT_SEGS
name|HeaderFlagBitLazyInit
init|=
literal|0x00000040u
block|,
comment|// MH_LAZY_INIT
name|HeaderFlagBitTwoLevelNamespace
init|=
literal|0x00000080u
block|,
comment|// MH_TWOLEVEL
name|HeaderFlagBitForceFlatNamespace
init|=
literal|0x00000100u
block|,
comment|// MH_FORCE_FLAT
name|HeaderFlagBitNoMultipleDefintions
init|=
literal|0x00000200u
block|,
comment|// MH_NOMULTIDEFS
name|HeaderFlagBitNoFixPrebinding
init|=
literal|0x00000400u
block|,
comment|// MH_NOFIXPREBINDING
name|HeaderFlagBitPrebindable
init|=
literal|0x00000800u
block|,
comment|// MH_PREBINDABLE
name|HeaderFlagBitAllModulesBound
init|=
literal|0x00001000u
block|,
comment|// MH_ALLMODSBOUND
name|HeaderFlagBitSubsectionsViaSymbols
init|=
literal|0x00002000u
block|,
comment|// MH_SUBSECTIONS_VIA_SYMBOLS
name|HeaderFlagBitCanonical
init|=
literal|0x00004000u
block|,
comment|// MH_CANONICAL
name|HeaderFlagBitWeakDefines
init|=
literal|0x00008000u
block|,
comment|// MH_WEAK_DEFINES
name|HeaderFlagBitBindsToWeak
init|=
literal|0x00010000u
block|,
comment|// MH_BINDS_TO_WEAK
name|HeaderFlagBitAllowStackExecution
init|=
literal|0x00020000u
block|,
comment|// MH_ALLOW_STACK_EXECUTION
name|HeaderFlagBitRootSafe
init|=
literal|0x00040000u
block|,
comment|// MH_ROOT_SAFE
name|HeaderFlagBitSetUIDSafe
init|=
literal|0x00080000u
block|,
comment|// MH_SETUID_SAFE
name|HeaderFlagBitNoReexportedDylibs
init|=
literal|0x00100000u
block|,
comment|// MH_NO_REEXPORTED_DYLIBS
name|HeaderFlagBitPIE
init|=
literal|0x00200000u
block|,
comment|// MH_PIE
name|HeaderFlagBitDeadStrippableDylib
init|=
literal|0x00400000u
block|,
comment|// MH_DEAD_STRIPPABLE_DYLIB
comment|// Constants for the "cmd" field in llvm::MachO::load_command
name|LoadCommandDynamicLinkerRequired
init|=
literal|0x80000000u
block|,
comment|// LC_REQ_DYLD
name|LoadCommandSegment32
init|=
literal|0x00000001u
block|,
comment|// LC_SEGMENT
name|LoadCommandSymtab
init|=
literal|0x00000002u
block|,
comment|// LC_SYMTAB
name|LoadCommandSymSeg
init|=
literal|0x00000003u
block|,
comment|// LC_SYMSEG
name|LoadCommandThread
init|=
literal|0x00000004u
block|,
comment|// LC_THREAD
name|LoadCommandUnixThread
init|=
literal|0x00000005u
block|,
comment|// LC_UNIXTHREAD
name|LoadCommandFixedVMShlibLoad
init|=
literal|0x00000006u
block|,
comment|// LC_LOADFVMLIB
name|LoadCommandFixedVMShlibIdent
init|=
literal|0x00000007u
block|,
comment|// LC_IDFVMLIB
name|LoadCommandIdent
init|=
literal|0x00000008u
block|,
comment|// LC_IDENT
name|LoadCommandFixedVMFileInclusion
init|=
literal|0x00000009u
block|,
comment|// LC_FVMFILE
name|LoadCommandPrePage
init|=
literal|0x0000000Au
block|,
comment|// LC_PREPAGE
name|LoadCommandDynamicSymtabInfo
init|=
literal|0x0000000Bu
block|,
comment|// LC_DYSYMTAB
name|LoadCommandDylibLoad
init|=
literal|0x0000000Cu
block|,
comment|// LC_LOAD_DYLIB
name|LoadCommandDylibIdent
init|=
literal|0x0000000Du
block|,
comment|// LC_ID_DYLIB
name|LoadCommandDynamicLinkerLoad
init|=
literal|0x0000000Eu
block|,
comment|// LC_LOAD_DYLINKER
name|LoadCommandDynamicLinkerIdent
init|=
literal|0x0000000Fu
block|,
comment|// LC_ID_DYLINKER
name|LoadCommandDylibPrebound
init|=
literal|0x00000010u
block|,
comment|// LC_PREBOUND_DYLIB
name|LoadCommandRoutines32
init|=
literal|0x00000011u
block|,
comment|// LC_ROUTINES
name|LoadCommandSubFramework
init|=
literal|0x00000012u
block|,
comment|// LC_SUB_FRAMEWORK
name|LoadCommandSubUmbrella
init|=
literal|0x00000013u
block|,
comment|// LC_SUB_UMBRELLA
name|LoadCommandSubClient
init|=
literal|0x00000014u
block|,
comment|// LC_SUB_CLIENT
name|LoadCommandSubLibrary
init|=
literal|0x00000015u
block|,
comment|// LC_SUB_LIBRARY
name|LoadCommandTwoLevelHints
init|=
literal|0x00000016u
block|,
comment|// LC_TWOLEVEL_HINTS
name|LoadCommandPreBindChecksum
init|=
literal|0x00000017u
block|,
comment|// LC_PREBIND_CKSUM
name|LoadCommandDylibLoadWeak
init|=
literal|0x80000018u
block|,
comment|// LC_LOAD_WEAK_DYLIB
name|LoadCommandSegment64
init|=
literal|0x00000019u
block|,
comment|// LC_SEGMENT_64
name|LoadCommandRoutines64
init|=
literal|0x0000001Au
block|,
comment|// LC_ROUTINES_64
name|LoadCommandUUID
init|=
literal|0x0000001Bu
block|,
comment|// LC_UUID
name|LoadCommandRunpath
init|=
literal|0x8000001Cu
block|,
comment|// LC_RPATH
name|LoadCommandCodeSignature
init|=
literal|0x0000001Du
block|,
comment|// LC_CODE_SIGNATURE
name|LoadCommandSegmentSplitInfo
init|=
literal|0x0000001Eu
block|,
comment|// LC_SEGMENT_SPLIT_INFO
name|LoadCommandDylibReexport
init|=
literal|0x8000001Fu
block|,
comment|// LC_REEXPORT_DYLIB
name|LoadCommandDylibLazyLoad
init|=
literal|0x00000020u
block|,
comment|// LC_LAZY_LOAD_DYLIB
name|LoadCommandEncryptionInfo
init|=
literal|0x00000021u
block|,
comment|// LC_ENCRYPTION_INFO
name|LoadCommandDynamicLinkerInfo
init|=
literal|0x00000022u
block|,
comment|// LC_DYLD_INFO
name|LoadCommandDynamicLinkerInfoOnly
init|=
literal|0x80000022u
block|,
comment|// LC_DYLD_INFO_ONLY
name|LoadCommandDylibLoadUpward
init|=
literal|0x80000023u
block|,
comment|// LC_LOAD_UPWARD_DYLIB
name|LoadCommandVersionMinMacOSX
init|=
literal|0x00000024u
block|,
comment|// LC_VERSION_MIN_MACOSX
name|LoadCommandVersionMinIPhoneOS
init|=
literal|0x00000025u
block|,
comment|// LC_VERSION_MIN_IPHONEOS
name|LoadCommandFunctionStarts
init|=
literal|0x00000026u
block|,
comment|// LC_FUNCTION_STARTS
name|LoadCommandDyldEnvironment
init|=
literal|0x00000027u
block|,
comment|// LC_DYLD_ENVIRONMENT
name|LoadCommandMain
init|=
literal|0x80000028u
block|,
comment|// LC_MAIN
name|LoadCommandDataInCode
init|=
literal|0x00000029u
block|,
comment|// LC_DATA_IN_CODE
name|LoadCommandSourceVersion
init|=
literal|0x0000002Au
block|,
comment|// LC_SOURCE_VERSION
name|LoadCommandCodeSignDRs
init|=
literal|0x0000002Bu
block|,
comment|// LC_DYLIB_CODE_SIGN_DRS
comment|// Constant bits for the "flags" field in llvm::MachO::segment_command
name|SegmentCommandFlagBitHighVM
init|=
literal|0x1u
block|,
comment|// SG_HIGHVM
name|SegmentCommandFlagBitFixedVMLibrary
init|=
literal|0x2u
block|,
comment|// SG_FVMLIB
name|SegmentCommandFlagBitNoRelocations
init|=
literal|0x4u
block|,
comment|// SG_NORELOC
name|SegmentCommandFlagBitProtectedVersion1
init|=
literal|0x8u
block|,
comment|// SG_PROTECTED_VERSION_1
comment|// Constant masks for the "flags" field in llvm::MachO::section and
comment|// llvm::MachO::section_64
name|SectionFlagMaskSectionType
init|=
literal|0x000000ffu
block|,
comment|// SECTION_TYPE
name|SectionFlagMaskAllAttributes
init|=
literal|0xffffff00u
block|,
comment|// SECTION_ATTRIBUTES
name|SectionFlagMaskUserAttributes
init|=
literal|0xff000000u
block|,
comment|// SECTION_ATTRIBUTES_USR
name|SectionFlagMaskSystemAttributes
init|=
literal|0x00ffff00u
block|,
comment|// SECTION_ATTRIBUTES_SYS
comment|// Constant masks for the "flags[7:0]" field in llvm::MachO::section and
comment|// llvm::MachO::section_64 (mask "flags" with SECTION_TYPE)
name|SectionTypeRegular
init|=
literal|0x00u
block|,
comment|// S_REGULAR
name|SectionTypeZeroFill
init|=
literal|0x01u
block|,
comment|// S_ZEROFILL
name|SectionTypeCStringLiterals
init|=
literal|0x02u
block|,
comment|// S_CSTRING_LITERALS
name|SectionType4ByteLiterals
init|=
literal|0x03u
block|,
comment|// S_4BYTE_LITERALS
name|SectionType8ByteLiterals
init|=
literal|0x04u
block|,
comment|// S_8BYTE_LITERALS
name|SectionTypeLiteralPointers
init|=
literal|0x05u
block|,
comment|// S_LITERAL_POINTERS
name|SectionTypeNonLazySymbolPointers
init|=
literal|0x06u
block|,
comment|// S_NON_LAZY_SYMBOL_POINTERS
name|SectionTypeLazySymbolPointers
init|=
literal|0x07u
block|,
comment|// S_LAZY_SYMBOL_POINTERS
name|SectionTypeSymbolStubs
init|=
literal|0x08u
block|,
comment|// S_SYMBOL_STUBS
name|SectionTypeModuleInitFunctionPointers
init|=
literal|0x09u
block|,
comment|// S_MOD_INIT_FUNC_POINTERS
name|SectionTypeModuleTermFunctionPointers
init|=
literal|0x0au
block|,
comment|// S_MOD_TERM_FUNC_POINTERS
name|SectionTypeCoalesced
init|=
literal|0x0bu
block|,
comment|// S_COALESCED
name|SectionTypeZeroFillLarge
init|=
literal|0x0cu
block|,
comment|// S_GB_ZEROFILL
name|SectionTypeInterposing
init|=
literal|0x0du
block|,
comment|// S_INTERPOSING
name|SectionType16ByteLiterals
init|=
literal|0x0eu
block|,
comment|// S_16BYTE_LITERALS
name|SectionTypeDTraceObjectFormat
init|=
literal|0x0fu
block|,
comment|// S_DTRACE_DOF
name|SectionTypeLazyDylibSymbolPointers
init|=
literal|0x10u
block|,
comment|// S_LAZY_DYLIB_SYMBOL_POINTERS
comment|// Constant masks for the "flags[31:24]" field in llvm::MachO::section and
comment|// llvm::MachO::section_64 (mask "flags" with SECTION_ATTRIBUTES_USR)
name|SectionAttrUserPureInstructions
init|=
literal|0x80000000u
block|,
comment|// S_ATTR_PURE_INSTRUCTIONS
name|SectionAttrUserNoTableOfContents
init|=
literal|0x40000000u
block|,
comment|// S_ATTR_NO_TOC
name|SectionAttrUserCanStripStaticSymbols
init|=
literal|0x20000000u
block|,
comment|// S_ATTR_STRIP_STATIC_SYMS
name|SectionAttrUserNoDeadStrip
init|=
literal|0x10000000u
block|,
comment|// S_ATTR_NO_DEAD_STRIP
name|SectionAttrUserLiveSupport
init|=
literal|0x08000000u
block|,
comment|// S_ATTR_LIVE_SUPPORT
name|SectionAttrUserSelfModifyingCode
init|=
literal|0x04000000u
block|,
comment|// S_ATTR_SELF_MODIFYING_CODE
name|SectionAttrUserDebug
init|=
literal|0x02000000u
block|,
comment|// S_ATTR_DEBUG
comment|// Constant masks for the "flags[23:8]" field in llvm::MachO::section and
comment|// llvm::MachO::section_64 (mask "flags" with SECTION_ATTRIBUTES_SYS)
name|SectionAttrSytemSomeInstructions
init|=
literal|0x00000400u
block|,
comment|// S_ATTR_SOME_INSTRUCTIONS
name|SectionAttrSytemHasExternalRelocations
init|=
literal|0x00000200u
block|,
comment|// S_ATTR_EXT_RELOC
name|SectionAttrSytemHasLocalRelocations
init|=
literal|0x00000100u
block|,
comment|// S_ATTR_LOC_RELOC
name|IndirectSymbolLocal
init|=
literal|0x80000000u
block|,
comment|// INDIRECT_SYMBOL_LOCAL
name|IndirectSymbolAbsolute
init|=
literal|0x40000000u
block|,
comment|// INDIRECT_SYMBOL_ABS
name|RebaseTypePointer
init|=
literal|1u
block|,
comment|// REBASE_TYPE_POINTER
name|RebaseTypeTextAbsolute32
init|=
literal|2u
block|,
comment|// REBASE_TYPE_TEXT_ABSOLUTE32
name|RebaseTypeTextPCRelative32
init|=
literal|3u
block|,
comment|// REBASE_TYPE_TEXT_PCREL32
name|RebaseOpcodeMask
init|=
literal|0xF0u
block|,
comment|// REBASE_OPCODE_MASK
name|RebaseImmediateMask
init|=
literal|0x0Fu
block|,
comment|// REBASE_IMMEDIATE_MASK
name|RebaseOpcodeDone
init|=
literal|0x00u
block|,
comment|// REBASE_OPCODE_DONE
name|RebaseOpcodeSetTypeImmediate
init|=
literal|0x10u
block|,
comment|// REBASE_OPCODE_SET_TYPE_IMM
name|RebaseOpcodeSetSegmentAndOffsetULEB
init|=
literal|0x20u
block|,
comment|// REBASE_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB
name|RebaseOpcodeAddAddressULEB
init|=
literal|0x30u
block|,
comment|// REBASE_OPCODE_ADD_ADDR_ULEB
name|RebaseOpcodeAddAddressImmediateScaled
init|=
literal|0x40u
block|,
comment|// REBASE_OPCODE_ADD_ADDR_IMM_SCALED
name|RebaseOpcodeDoRebaseImmediateTimes
init|=
literal|0x50u
block|,
comment|// REBASE_OPCODE_DO_REBASE_IMM_TIMES
name|RebaseOpcodeDoRebaseULEBTimes
init|=
literal|0x60u
block|,
comment|// REBASE_OPCODE_DO_REBASE_ULEB_TIMES
name|RebaseOpcodeDoRebaseAddAddressULEB
init|=
literal|0x70u
block|,
comment|// REBASE_OPCODE_DO_REBASE_ADD_ADDR_ULEB
name|RebaseOpcodeDoRebaseULEBTimesSkippingULEB
init|=
literal|0x80u
block|,
comment|// REBASE_OPCODE_DO_REBASE_ULEB_TIMES_SKIPPING_ULEB
name|BindTypePointer
init|=
literal|1u
block|,
comment|// BIND_TYPE_POINTER
name|BindTypeTextAbsolute32
init|=
literal|2u
block|,
comment|// BIND_TYPE_TEXT_ABSOLUTE32
name|BindTypeTextPCRelative32
init|=
literal|3u
block|,
comment|// BIND_TYPE_TEXT_PCREL32
name|BindSpecialDylibSelf
init|=
literal|0u
block|,
comment|// BIND_SPECIAL_DYLIB_SELF
name|BindSpecialDylibMainExecutable
init|=
operator|-
literal|1u
block|,
comment|// BIND_SPECIAL_DYLIB_MAIN_EXECUTABLE
name|BindSpecialDylibFlatLookup
init|=
operator|-
literal|2u
block|,
comment|// BIND_SPECIAL_DYLIB_FLAT_LOOKUP
name|BindSymbolFlagsWeakImport
init|=
literal|0x1u
block|,
comment|// BIND_SYMBOL_FLAGS_WEAK_IMPORT
name|BindSymbolFlagsNonWeakDefinition
init|=
literal|0x8u
block|,
comment|// BIND_SYMBOL_FLAGS_NON_WEAK_DEFINITION
name|BindOpcodeMask
init|=
literal|0xF0u
block|,
comment|// BIND_OPCODE_MASK
name|BindImmediateMask
init|=
literal|0x0Fu
block|,
comment|// BIND_IMMEDIATE_MASK
name|BindOpcodeDone
init|=
literal|0x00u
block|,
comment|// BIND_OPCODE_DONE
name|BindOpcodeSetDylibOrdinalImmediate
init|=
literal|0x10u
block|,
comment|// BIND_OPCODE_SET_DYLIB_ORDINAL_IMM
name|BindOpcodeSetDylibOrdinalULEB
init|=
literal|0x20u
block|,
comment|// BIND_OPCODE_SET_DYLIB_ORDINAL_ULEB
name|BindOpcodeSetDylibSpecialImmediate
init|=
literal|0x30u
block|,
comment|// BIND_OPCODE_SET_DYLIB_SPECIAL_IMM
name|BindOpcodeSetSymbolTrailingFlagsImmediate
init|=
literal|0x40u
block|,
comment|// BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM
name|BindOpcodeSetTypeImmediate
init|=
literal|0x50u
block|,
comment|// BIND_OPCODE_SET_TYPE_IMM
name|BindOpcodeSetAppendSLEB
init|=
literal|0x60u
block|,
comment|// BIND_OPCODE_SET_ADDEND_SLEB
name|BindOpcodeSetSegmentAndOffsetULEB
init|=
literal|0x70u
block|,
comment|// BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB
name|BindOpcodeAddAddressULEB
init|=
literal|0x80u
block|,
comment|// BIND_OPCODE_ADD_ADDR_ULEB
name|BindOpcodeDoBind
init|=
literal|0x90u
block|,
comment|// BIND_OPCODE_DO_BIND
name|BindOpcodeDoBindAddAddressULEB
init|=
literal|0xA0u
block|,
comment|// BIND_OPCODE_DO_BIND_ADD_ADDR_ULEB
name|BindOpcodeDoBindAddAddressImmediateScaled
init|=
literal|0xB0u
block|,
comment|// BIND_OPCODE_DO_BIND_ADD_ADDR_IMM_SCALED
name|BindOpcodeDoBindULEBTimesSkippingULEB
init|=
literal|0xC0u
block|,
comment|// BIND_OPCODE_DO_BIND_ULEB_TIMES_SKIPPING_ULEB
name|ExportSymbolFlagsKindMask
init|=
literal|0x03u
block|,
comment|// EXPORT_SYMBOL_FLAGS_KIND_MASK
name|ExportSymbolFlagsKindRegular
init|=
literal|0x00u
block|,
comment|// EXPORT_SYMBOL_FLAGS_KIND_REGULAR
name|ExportSymbolFlagsKindThreadLocal
init|=
literal|0x01u
block|,
comment|// EXPORT_SYMBOL_FLAGS_KIND_THREAD_LOCAL
name|ExportSymbolFlagsWeakDefinition
init|=
literal|0x04u
block|,
comment|// EXPORT_SYMBOL_FLAGS_WEAK_DEFINITION
name|ExportSymbolFlagsIndirectDefinition
init|=
literal|0x08u
block|,
comment|// EXPORT_SYMBOL_FLAGS_INDIRECT_DEFINITION
name|ExportSymbolFlagsHasSpecializations
init|=
literal|0x10u
block|,
comment|// EXPORT_SYMBOL_FLAGS_HAS_SPECIALIZATIONS
comment|// Constant masks for the "n_type" field in llvm::MachO::nlist and
comment|// llvm::MachO::nlist_64
name|NlistMaskStab
init|=
literal|0xe0
block|,
comment|// N_STAB
name|NlistMaskPrivateExternal
init|=
literal|0x10
block|,
comment|// N_PEXT
name|NlistMaskType
init|=
literal|0x0e
block|,
comment|// N_TYPE
name|NlistMaskExternal
init|=
literal|0x01
block|,
comment|// N_EXT
comment|// Constants for the "n_type& N_TYPE" llvm::MachO::nlist and
comment|// llvm::MachO::nlist_64
name|NListTypeUndefined
init|=
literal|0x0u
block|,
comment|// N_UNDF
name|NListTypeAbsolute
init|=
literal|0x2u
block|,
comment|// N_ABS
name|NListTypeSection
init|=
literal|0xeu
block|,
comment|// N_SECT
name|NListTypePreboundUndefined
init|=
literal|0xcu
block|,
comment|// N_PBUD
name|NListTypeIndirect
init|=
literal|0xau
block|,
comment|// N_INDR
comment|// Constant masks for the "n_sect" field in llvm::MachO::nlist and
comment|// llvm::MachO::nlist_64
name|NListSectionNoSection
init|=
literal|0u
block|,
comment|// NO_SECT
name|NListSectionMaxSection
init|=
literal|0xffu
block|,
comment|// MAX_SECT
name|NListDescWeakRef
init|=
literal|0x40u
block|,
name|NListDescWeakDef
init|=
literal|0x80u
block|,
comment|// Constant values for the "n_type" field in llvm::MachO::nlist and
comment|// llvm::MachO::nlist_64 when "(n_type& NlistMaskStab) != 0"
name|StabGlobalSymbol
init|=
literal|0x20u
block|,
comment|// N_GSYM
name|StabFunctionName
init|=
literal|0x22u
block|,
comment|// N_FNAME
name|StabFunction
init|=
literal|0x24u
block|,
comment|// N_FUN
name|StabStaticSymbol
init|=
literal|0x26u
block|,
comment|// N_STSYM
name|StabLocalCommon
init|=
literal|0x28u
block|,
comment|// N_LCSYM
name|StabBeginSymbol
init|=
literal|0x2Eu
block|,
comment|// N_BNSYM
name|StabSourceFileOptions
init|=
literal|0x3Cu
block|,
comment|// N_OPT
name|StabRegisterSymbol
init|=
literal|0x40u
block|,
comment|// N_RSYM
name|StabSourceLine
init|=
literal|0x44u
block|,
comment|// N_SLINE
name|StabEndSymbol
init|=
literal|0x4Eu
block|,
comment|// N_ENSYM
name|StabStructureType
init|=
literal|0x60u
block|,
comment|// N_SSYM
name|StabSourceFileName
init|=
literal|0x64u
block|,
comment|// N_SO
name|StabObjectFileName
init|=
literal|0x66u
block|,
comment|// N_OSO
name|StabLocalSymbol
init|=
literal|0x80u
block|,
comment|// N_LSYM
name|StabBeginIncludeFileName
init|=
literal|0x82u
block|,
comment|// N_BINCL
name|StabIncludeFileName
init|=
literal|0x84u
block|,
comment|// N_SOL
name|StabCompilerParameters
init|=
literal|0x86u
block|,
comment|// N_PARAMS
name|StabCompilerVersion
init|=
literal|0x88u
block|,
comment|// N_VERSION
name|StabCompilerOptLevel
init|=
literal|0x8Au
block|,
comment|// N_OLEVEL
name|StabParameter
init|=
literal|0xA0u
block|,
comment|// N_PSYM
name|StabEndIncludeFile
init|=
literal|0xA2u
block|,
comment|// N_EINCL
name|StabAlternateEntry
init|=
literal|0xA4u
block|,
comment|// N_ENTRY
name|StabLeftBracket
init|=
literal|0xC0u
block|,
comment|// N_LBRAC
name|StabDeletedIncludeFile
init|=
literal|0xC2u
block|,
comment|// N_EXCL
name|StabRightBracket
init|=
literal|0xE0u
block|,
comment|// N_RBRAC
name|StabBeginCommon
init|=
literal|0xE2u
block|,
comment|// N_BCOMM
name|StabEndCommon
init|=
literal|0xE4u
block|,
comment|// N_ECOMM
name|StabEndCommonLocal
init|=
literal|0xE8u
block|,
comment|// N_ECOML
name|StabLength
init|=
literal|0xFEu
comment|// N_LENG
block|}
enum|;
comment|// Structs from<mach-o/loader.h>
struct|struct
name|mach_header
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|cputype
decl_stmt|;
name|uint32_t
name|cpusubtype
decl_stmt|;
name|uint32_t
name|filetype
decl_stmt|;
name|uint32_t
name|ncmds
decl_stmt|;
name|uint32_t
name|sizeofcmds
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
struct|struct
name|mach_header_64
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|cputype
decl_stmt|;
name|uint32_t
name|cpusubtype
decl_stmt|;
name|uint32_t
name|filetype
decl_stmt|;
name|uint32_t
name|ncmds
decl_stmt|;
name|uint32_t
name|sizeofcmds
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
struct|struct
name|load_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
block|}
struct|;
struct|struct
name|segment_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|char
name|segname
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|vmaddr
decl_stmt|;
name|uint32_t
name|vmsize
decl_stmt|;
name|uint32_t
name|fileoff
decl_stmt|;
name|uint32_t
name|filesize
decl_stmt|;
name|uint32_t
name|maxprot
decl_stmt|;
name|uint32_t
name|initprot
decl_stmt|;
name|uint32_t
name|nsects
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
struct|struct
name|segment_command_64
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|char
name|segname
index|[
literal|16
index|]
decl_stmt|;
name|uint64_t
name|vmaddr
decl_stmt|;
name|uint64_t
name|vmsize
decl_stmt|;
name|uint64_t
name|fileoff
decl_stmt|;
name|uint64_t
name|filesize
decl_stmt|;
name|uint32_t
name|maxprot
decl_stmt|;
name|uint32_t
name|initprot
decl_stmt|;
name|uint32_t
name|nsects
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
struct|struct
name|section
block|{
name|char
name|sectname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|segname
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|align
decl_stmt|;
name|uint32_t
name|reloff
decl_stmt|;
name|uint32_t
name|nreloc
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
struct|struct
name|section_64
block|{
name|char
name|sectname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|segname
index|[
literal|16
index|]
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|align
decl_stmt|;
name|uint32_t
name|reloff
decl_stmt|;
name|uint32_t
name|nreloc
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
block|}
struct|;
struct|struct
name|fvmlib
block|{
name|uint32_t
name|name
decl_stmt|;
name|uint32_t
name|minor_version
decl_stmt|;
name|uint32_t
name|header_addr
decl_stmt|;
block|}
struct|;
struct|struct
name|fvmlib_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|struct
name|fvmlib
name|fvmlib
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib
block|{
name|uint32_t
name|name
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|current_version
decl_stmt|;
name|uint32_t
name|compatibility_version
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|struct
name|dylib
name|dylib
decl_stmt|;
block|}
struct|;
struct|struct
name|sub_framework_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|umbrella
decl_stmt|;
block|}
struct|;
struct|struct
name|sub_client_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|client
decl_stmt|;
block|}
struct|;
struct|struct
name|sub_umbrella_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|sub_umbrella
decl_stmt|;
block|}
struct|;
struct|struct
name|sub_library_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|sub_library
decl_stmt|;
block|}
struct|;
struct|struct
name|prebound_dylib_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|name
decl_stmt|;
name|uint32_t
name|nmodules
decl_stmt|;
name|uint32_t
name|linked_modules
decl_stmt|;
block|}
struct|;
struct|struct
name|dylinker_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|name
decl_stmt|;
block|}
struct|;
struct|struct
name|thread_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
block|}
struct|;
struct|struct
name|routines_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|init_address
decl_stmt|;
name|uint32_t
name|init_module
decl_stmt|;
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
name|uint32_t
name|reserved6
decl_stmt|;
block|}
struct|;
struct|struct
name|routines_command_64
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint64_t
name|init_address
decl_stmt|;
name|uint64_t
name|init_module
decl_stmt|;
name|uint64_t
name|reserved1
decl_stmt|;
name|uint64_t
name|reserved2
decl_stmt|;
name|uint64_t
name|reserved3
decl_stmt|;
name|uint64_t
name|reserved4
decl_stmt|;
name|uint64_t
name|reserved5
decl_stmt|;
name|uint64_t
name|reserved6
decl_stmt|;
block|}
struct|;
struct|struct
name|symtab_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|symoff
decl_stmt|;
name|uint32_t
name|nsyms
decl_stmt|;
name|uint32_t
name|stroff
decl_stmt|;
name|uint32_t
name|strsize
decl_stmt|;
block|}
struct|;
struct|struct
name|dysymtab_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|ilocalsym
decl_stmt|;
name|uint32_t
name|nlocalsym
decl_stmt|;
name|uint32_t
name|iextdefsym
decl_stmt|;
name|uint32_t
name|nextdefsym
decl_stmt|;
name|uint32_t
name|iundefsym
decl_stmt|;
name|uint32_t
name|nundefsym
decl_stmt|;
name|uint32_t
name|tocoff
decl_stmt|;
name|uint32_t
name|ntoc
decl_stmt|;
name|uint32_t
name|modtaboff
decl_stmt|;
name|uint32_t
name|nmodtab
decl_stmt|;
name|uint32_t
name|extrefsymoff
decl_stmt|;
name|uint32_t
name|nextrefsyms
decl_stmt|;
name|uint32_t
name|indirectsymoff
decl_stmt|;
name|uint32_t
name|nindirectsyms
decl_stmt|;
name|uint32_t
name|extreloff
decl_stmt|;
name|uint32_t
name|nextrel
decl_stmt|;
name|uint32_t
name|locreloff
decl_stmt|;
name|uint32_t
name|nlocrel
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib_table_of_contents
block|{
name|uint32_t
name|symbol_index
decl_stmt|;
name|uint32_t
name|module_index
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib_module
block|{
name|uint32_t
name|module_name
decl_stmt|;
name|uint32_t
name|iextdefsym
decl_stmt|;
name|uint32_t
name|nextdefsym
decl_stmt|;
name|uint32_t
name|irefsym
decl_stmt|;
name|uint32_t
name|nrefsym
decl_stmt|;
name|uint32_t
name|ilocalsym
decl_stmt|;
name|uint32_t
name|nlocalsym
decl_stmt|;
name|uint32_t
name|iextrel
decl_stmt|;
name|uint32_t
name|nextrel
decl_stmt|;
name|uint32_t
name|iinit_iterm
decl_stmt|;
name|uint32_t
name|ninit_nterm
decl_stmt|;
name|uint32_t
name|objc_module_info_addr
decl_stmt|;
name|uint32_t
name|objc_module_info_size
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib_module_64
block|{
name|uint32_t
name|module_name
decl_stmt|;
name|uint32_t
name|iextdefsym
decl_stmt|;
name|uint32_t
name|nextdefsym
decl_stmt|;
name|uint32_t
name|irefsym
decl_stmt|;
name|uint32_t
name|nrefsym
decl_stmt|;
name|uint32_t
name|ilocalsym
decl_stmt|;
name|uint32_t
name|nlocalsym
decl_stmt|;
name|uint32_t
name|iextrel
decl_stmt|;
name|uint32_t
name|nextrel
decl_stmt|;
name|uint32_t
name|iinit_iterm
decl_stmt|;
name|uint32_t
name|ninit_nterm
decl_stmt|;
name|uint32_t
name|objc_module_info_size
decl_stmt|;
name|uint64_t
name|objc_module_info_addr
decl_stmt|;
block|}
struct|;
struct|struct
name|dylib_reference
block|{
name|uint32_t
name|isym
range|:
literal|24
decl_stmt|,
name|flags
range|:
literal|8
decl_stmt|;
block|}
struct|;
struct|struct
name|twolevel_hints_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|nhints
decl_stmt|;
block|}
struct|;
struct|struct
name|twolevel_hint
block|{
name|uint32_t
name|isub_image
range|:
literal|8
decl_stmt|,
name|itoc
range|:
literal|24
decl_stmt|;
block|}
struct|;
struct|struct
name|prebind_cksum_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|cksum
decl_stmt|;
block|}
struct|;
struct|struct
name|uuid_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint8_t
name|uuid
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|rpath_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|path
decl_stmt|;
block|}
struct|;
struct|struct
name|linkedit_data_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|dataoff
decl_stmt|;
name|uint32_t
name|datasize
decl_stmt|;
block|}
struct|;
struct|struct
name|encryption_info_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|cryptoff
decl_stmt|;
name|uint32_t
name|cryptsize
decl_stmt|;
name|uint32_t
name|cryptid
decl_stmt|;
block|}
struct|;
struct|struct
name|version_min_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
struct|struct
name|dyld_info_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|rebase_off
decl_stmt|;
name|uint32_t
name|rebase_size
decl_stmt|;
name|uint32_t
name|bind_off
decl_stmt|;
name|uint32_t
name|bind_size
decl_stmt|;
name|uint32_t
name|weak_bind_off
decl_stmt|;
name|uint32_t
name|weak_bind_size
decl_stmt|;
name|uint32_t
name|lazy_bind_off
decl_stmt|;
name|uint32_t
name|lazy_bind_size
decl_stmt|;
name|uint32_t
name|export_off
decl_stmt|;
name|uint32_t
name|export_size
decl_stmt|;
block|}
struct|;
struct|struct
name|symseg_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
struct|struct
name|ident_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
block|}
struct|;
struct|struct
name|fvmfile_command
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cmdsize
decl_stmt|;
name|uint32_t
name|name
decl_stmt|;
name|uint32_t
name|header_addr
decl_stmt|;
block|}
struct|;
comment|// Structs from<mach-o/fat.h>
struct|struct
name|fat_header
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|nfat_arch
decl_stmt|;
block|}
struct|;
struct|struct
name|fat_arch
block|{
name|uint32_t
name|cputype
decl_stmt|;
name|uint32_t
name|cpusubtype
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|align
decl_stmt|;
block|}
struct|;
comment|// Structs from<mach-o/fat.h>
struct|struct
name|nlist
block|{
name|uint32_t
name|n_strx
decl_stmt|;
name|uint8_t
name|n_type
decl_stmt|;
name|uint8_t
name|n_sect
decl_stmt|;
name|int16_t
name|n_desc
decl_stmt|;
name|uint32_t
name|n_value
decl_stmt|;
block|}
struct|;
struct|struct
name|nlist_64
block|{
name|uint32_t
name|n_strx
decl_stmt|;
name|uint8_t
name|n_type
decl_stmt|;
name|uint8_t
name|n_sect
decl_stmt|;
name|uint16_t
name|n_desc
decl_stmt|;
name|uint64_t
name|n_value
decl_stmt|;
block|}
struct|;
comment|// Get/Set functions from<mach-o/nlist.h>
specifier|static
specifier|inline
name|uint16_t
name|GET_LIBRARY_ORDINAL
parameter_list|(
name|uint16_t
name|n_desc
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|n_desc
operator|)
operator|>>
literal|8u
operator|)
operator|&
literal|0xffu
operator|)
return|;
block|}
specifier|static
specifier|inline
name|void
name|SET_LIBRARY_ORDINAL
parameter_list|(
name|uint16_t
modifier|&
name|n_desc
parameter_list|,
name|uint8_t
name|ordinal
parameter_list|)
block|{
name|n_desc
operator|=
operator|(
operator|(
operator|(
name|n_desc
operator|)
operator|&
literal|0x00ff
operator|)
operator||
operator|(
operator|(
operator|(
name|ordinal
operator|)
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|uint8_t
name|GET_COMM_ALIGN
parameter_list|(
name|uint16_t
name|n_desc
parameter_list|)
block|{
return|return
operator|(
name|n_desc
operator|>>
literal|8u
operator|)
operator|&
literal|0x0fu
return|;
block|}
specifier|static
specifier|inline
name|void
name|SET_COMM_ALIGN
parameter_list|(
name|uint16_t
modifier|&
name|n_desc
parameter_list|,
name|uint8_t
name|align
parameter_list|)
block|{
name|n_desc
operator|=
operator|(
operator|(
name|n_desc
operator|&
literal|0xf0ffu
operator|)
operator||
operator|(
operator|(
name|align
operator|&
literal|0x0fu
operator|)
operator|<<
literal|8u
operator|)
operator|)
expr_stmt|;
block|}
comment|// Enums from<mach/machine.h>
enum|enum
block|{
comment|// Capability bits used in the definition of cpu_type.
name|CPUArchMask
init|=
literal|0xff000000
block|,
comment|// Mask for architecture bits
name|CPUArchABI64
init|=
literal|0x01000000
block|,
comment|// 64 bit ABI
comment|// Constants for the cputype field.
name|CPUTypeI386
init|=
literal|7
block|,
name|CPUTypeX86_64
init|=
name|CPUTypeI386
operator||
name|CPUArchABI64
block|,
name|CPUTypeARM
init|=
literal|12
block|,
name|CPUTypeSPARC
init|=
literal|14
block|,
name|CPUTypePowerPC
init|=
literal|18
block|,
name|CPUTypePowerPC64
init|=
name|CPUTypePowerPC
operator||
name|CPUArchABI64
block|,
comment|// Constants for the cpusubtype field.
comment|// X86
name|CPUSubType_I386_ALL
init|=
literal|3
block|,
name|CPUSubType_X86_64_ALL
init|=
literal|3
block|,
comment|// ARM
name|CPUSubType_ARM_ALL
init|=
literal|0
block|,
name|CPUSubType_ARM_V4T
init|=
literal|5
block|,
name|CPUSubType_ARM_V5
init|=
literal|7
block|,
name|CPUSubType_ARM_V6
init|=
literal|6
block|,
name|CPUSubType_ARM_V7
init|=
literal|9
block|,
comment|// PowerPC
name|CPUSubType_POWERPC_ALL
init|=
literal|0
block|,
name|CPUSubType_SPARC_ALL
init|=
literal|0
block|}
enum|;
block|}
comment|// end namespace MachO
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

