begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/CreateELF.h -----------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file provides a simple way to create an object templated on
end_comment

begin_comment
comment|/// ELFType depending on the runtime type needed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_ELF_CREATE_ELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_CREATE_ELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
name|using
name|llvm
operator|::
name|object
operator|::
name|ELFType
expr_stmt|;
comment|/// \func createELF
comment|/// \brief Create an object depending on the runtime attributes and alignment
comment|/// of an ELF file.
comment|///
comment|/// \param Traits
comment|/// Traits::result_type must be a type convertable from what create returns.
comment|/// Traits::create must be a template function which takes an ELFType and
comment|/// returns something convertable to Traits::result_type.
comment|///
comment|/// \param ident pair of EI_CLASS and EI_DATA.
comment|/// \param maxAlignment the maximum alignment of the file.
comment|/// \param args arguments forwarded to CreateELFTraits<T>::create.
define|#
directive|define
name|LLVM_CREATE_ELF_CreateELFTraits
parameter_list|(
name|endian
parameter_list|,
name|align
parameter_list|,
name|is64
parameter_list|,
modifier|...
parameter_list|)
define|\
value|Traits::template create<ELFType<llvm::support::endian, align, is64>>( \       __VA_ARGS__);
if|#
directive|if
operator|!
name|LLVM_IS_UNALIGNED_ACCESS_FAST
define|#
directive|define
name|LLVM_CREATE_ELF_MaxAlignCheck
parameter_list|(
name|normal
parameter_list|,
name|low
parameter_list|,
name|endian
parameter_list|,
name|is64
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if (maxAlignment>= normal) \     return LLVM_CREATE_ELF_CreateELFTraits(endian, normal, is64, __VA_ARGS__) \   else if (maxAlignment>= low) \     return LLVM_CREATE_ELF_CreateELFTraits(endian, low, is64, __VA_ARGS__) \   else \     llvm_unreachable("Invalid alignment for ELF file!");
else|#
directive|else
define|#
directive|define
name|LLVM_CREATE_ELF_MaxAlignCheck
parameter_list|(
name|normal
parameter_list|,
name|low
parameter_list|,
name|endian
parameter_list|,
name|is64
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if (maxAlignment>= low) \     return LLVM_CREATE_ELF_CreateELFTraits(endian, low, is64, __VA_ARGS__) \   else \     llvm_unreachable("Invalid alignment for ELF file!");
endif|#
directive|endif
define|#
directive|define
name|LLVM_CREATE_ELF_IMPL
parameter_list|(
modifier|...
parameter_list|)
define|\
value|if (ident.first == llvm::ELF::ELFCLASS32&& \         ident.second == llvm::ELF::ELFDATA2LSB) { \       LLVM_CREATE_ELF_MaxAlignCheck(4, 2, little, false, __VA_ARGS__) \     } else if (ident.first == llvm::ELF::ELFCLASS32&& \                ident.second == llvm::ELF::ELFDATA2MSB) { \       LLVM_CREATE_ELF_MaxAlignCheck(4, 2, big, false, __VA_ARGS__) \     } else if (ident.first == llvm::ELF::ELFCLASS64&& \                ident.second == llvm::ELF::ELFDATA2MSB) { \       LLVM_CREATE_ELF_MaxAlignCheck(8, 2, big, true, __VA_ARGS__) \     } else if (ident.first == llvm::ELF::ELFCLASS64&& \                ident.second == llvm::ELF::ELFDATA2LSB) { \       LLVM_CREATE_ELF_MaxAlignCheck(8, 2, little, true, __VA_ARGS__) \     } \     llvm_unreachable("Invalid ELF type!");
if|#
directive|if
name|LLVM_HAS_VARIADIC_TEMPLATES
name|template
operator|<
name|class
name|Traits
operator|,
name|class
operator|...
name|Args
operator|>
name|typename
name|Traits
operator|::
name|result_type
name|createELF
argument_list|(
argument|std::pair<unsigned char
argument_list|,
argument|unsigned char> ident
argument_list|,
argument|std::size_t maxAlignment
argument_list|,
argument|Args&&...args
argument_list|)
block|{
name|LLVM_CREATE_ELF_IMPL
argument_list|(
argument|std::forward<Args>(args)...
argument_list|)
block|}
else|#
directive|else
name|template
operator|<
name|class
name|Traits
operator|,
name|class
name|T1
operator|>
name|typename
name|Traits
operator|::
name|result_type
name|createELF
argument_list|(
argument|std::pair<unsigned char
argument_list|,
argument|unsigned char> ident
argument_list|,
argument|std::size_t maxAlignment
argument_list|,
argument|T1&&t1
argument_list|)
block|{
name|LLVM_CREATE_ELF_IMPL
argument_list|(
argument|std::forward<T1>(t1)
argument_list|)
block|}
name|template
operator|<
name|class
name|Traits
operator|,
name|class
name|T1
operator|,
name|class
name|T2
operator|>
name|typename
name|Traits
operator|::
name|result_type
name|createELF
argument_list|(
argument|std::pair<unsigned char
argument_list|,
argument|unsigned char> ident
argument_list|,
argument|std::size_t maxAlignment
argument_list|,
argument|T1&&t1
argument_list|,
argument|T2&&t2
argument_list|)
block|{
name|LLVM_CREATE_ELF_IMPL
argument_list|(
argument|std::forward<T1>(t1)
argument_list|,
argument|std::forward<T2>(t2)
argument_list|)
block|}
name|template
operator|<
name|class
name|Traits
operator|,
name|class
name|T1
operator|,
name|class
name|T2
operator|,
name|class
name|T3
operator|>
name|typename
name|Traits
operator|::
name|result_type
name|createELF
argument_list|(
argument|std::pair<unsigned char
argument_list|,
argument|unsigned char> ident
argument_list|,
argument|std::size_t maxAlignment
argument_list|,
argument|T1&&t1
argument_list|,
argument|T2&&t2
argument_list|,
argument|T3&&t3
argument_list|)
block|{
name|LLVM_CREATE_ELF_IMPL
argument_list|(
argument|std::forward<T1>(t1)
argument_list|,
argument|std::forward<T2>(t2)
argument_list|,
argument|std::forward<T3>(t3)
argument_list|)
block|}
name|template
operator|<
name|class
name|Traits
operator|,
name|class
name|T1
operator|,
name|class
name|T2
operator|,
name|class
name|T3
operator|,
name|class
name|T4
operator|>
name|typename
name|Traits
operator|::
name|result_type
name|createELF
argument_list|(
argument|std::pair<unsigned char
argument_list|,
argument|unsigned char> ident
argument_list|,
argument|std::size_t maxAlignment
argument_list|,
argument|T1&&t1
argument_list|,
argument|T2&&t2
argument_list|,
argument|T3&&t3
argument_list|,
argument|T4&&t4
argument_list|)
block|{
name|LLVM_CREATE_ELF_IMPL
argument_list|(
argument|std::forward<T1>(t1)
argument_list|,
argument|std::forward<T2>(t2)
argument_list|,
argument|std::forward<T3>(t3)
argument_list|,
argument|std::forward<T4>(t4)
argument_list|)
block|}
endif|#
directive|endif
comment|// LLVM_HAS_VARIADIC_TEMPLATES
block|}
end_block

begin_comment
comment|// end anon namespace
end_comment

begin_undef
undef|#
directive|undef
name|LLVM_CREATE_ELF_CreateELFTraits
end_undef

begin_undef
undef|#
directive|undef
name|LLVM_CREATE_ELF_MaxAlignCheck
end_undef

begin_undef
undef|#
directive|undef
name|LLVM_CREATE_ELF_IMPL
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

