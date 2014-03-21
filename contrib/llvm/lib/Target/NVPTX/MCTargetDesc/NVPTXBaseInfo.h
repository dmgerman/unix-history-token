begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXBaseInfo.h - Top-level definitions for NVPTX -------*- C++ -*-===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the NVPTX target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
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
name|NVPTXBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|NVPTXBASEINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
enum|enum
name|AddressSpace
block|{
name|ADDRESS_SPACE_GENERIC
init|=
literal|0
block|,
name|ADDRESS_SPACE_GLOBAL
init|=
literal|1
block|,
name|ADDRESS_SPACE_SHARED
init|=
literal|3
block|,
name|ADDRESS_SPACE_CONST
init|=
literal|4
block|,
name|ADDRESS_SPACE_LOCAL
init|=
literal|5
block|,
comment|// NVVM Internal
name|ADDRESS_SPACE_PARAM
init|=
literal|101
block|}
enum|;
enum|enum
name|PropertyAnnotation
block|{
name|PROPERTY_MAXNTID_X
init|=
literal|0
block|,
name|PROPERTY_MAXNTID_Y
block|,
name|PROPERTY_MAXNTID_Z
block|,
name|PROPERTY_REQNTID_X
block|,
name|PROPERTY_REQNTID_Y
block|,
name|PROPERTY_REQNTID_Z
block|,
name|PROPERTY_MINNCTAPERSM
block|,
name|PROPERTY_ISTEXTURE
block|,
name|PROPERTY_ISSURFACE
block|,
name|PROPERTY_ISSAMPLER
block|,
name|PROPERTY_ISREADONLY_IMAGE_PARAM
block|,
name|PROPERTY_ISWRITEONLY_IMAGE_PARAM
block|,
name|PROPERTY_ISKERNEL_FUNCTION
block|,
name|PROPERTY_ALIGN
block|,
comment|// last property
name|PROPERTY_LAST
block|}
enum|;
specifier|const
name|unsigned
name|AnnotationNameLen
init|=
literal|8
decl_stmt|;
comment|// length of each annotation name
specifier|const
name|char
name|PropertyAnnotationNames
index|[
name|PROPERTY_LAST
operator|+
literal|1
index|]
index|[
name|AnnotationNameLen
operator|+
literal|1
index|]
init|=
block|{
literal|"maxntidx"
block|,
comment|// PROPERTY_MAXNTID_X
literal|"maxntidy"
block|,
comment|// PROPERTY_MAXNTID_Y
literal|"maxntidz"
block|,
comment|// PROPERTY_MAXNTID_Z
literal|"reqntidx"
block|,
comment|// PROPERTY_REQNTID_X
literal|"reqntidy"
block|,
comment|// PROPERTY_REQNTID_Y
literal|"reqntidz"
block|,
comment|// PROPERTY_REQNTID_Z
literal|"minctasm"
block|,
comment|// PROPERTY_MINNCTAPERSM
literal|"texture"
block|,
comment|// PROPERTY_ISTEXTURE
literal|"surface"
block|,
comment|// PROPERTY_ISSURFACE
literal|"sampler"
block|,
comment|// PROPERTY_ISSAMPLER
literal|"rdoimage"
block|,
comment|// PROPERTY_ISREADONLY_IMAGE_PARAM
literal|"wroimage"
block|,
comment|// PROPERTY_ISWRITEONLY_IMAGE_PARAM
literal|"kernel"
block|,
comment|// PROPERTY_ISKERNEL_FUNCTION
literal|"align"
block|,
comment|// PROPERTY_ALIGN
comment|// last property
literal|"proplast"
block|,
comment|// PROPERTY_LAST
block|}
decl_stmt|;
comment|// name of named metadata used for global annotations
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
comment|// As this is declared to be static but some of the .cpp files that
comment|// include NVVM.h do not use this array, gcc gives a warning when
comment|// compiling those .cpp files, hence __attribute__((unused)).
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
endif|#
directive|endif
specifier|static
specifier|const
name|char
modifier|*
name|NamedMDForAnnotations
init|=
literal|"nvvm.annotations"
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

