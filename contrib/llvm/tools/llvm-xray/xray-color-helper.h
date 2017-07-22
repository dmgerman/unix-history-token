begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray-graph.h - XRay Function Call Graph Renderer --------*- C++ -*-===//
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
comment|// A class to get a color from a specified gradient.
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
name|XRAY_COLOR_HELPER_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_COLOR_HELPER_H
end_define

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
comment|/// The color helper class it a healper class which allows you to easily get a
comment|/// color in a gradient. This is used to color-code edges in XRay-Graph tools.
comment|///
comment|/// There are two types of color schemes in this class:
comment|///   - Sequential schemes, which are used to represent information from some
comment|///     minimum to some maximum. These take an input in the range [0,1]
comment|///   - Diverging schemes, which are used to represent information representing
comment|///     differenes, or a range that goes from negative to positive. These take
comment|///     an input in the range [-1,1].
comment|/// Usage;
comment|/// ColorHelper S(ColorHelper::SequentialScheme::OrRd); //Chose a color scheme.
comment|/// for (double p = 0.0; p<= 1; p += 0.1){
comment|///   cout()<< S.getColor(p)<< " \n"; // Sample the gradient at 0.1 intervals
comment|/// }
comment|///
comment|/// ColorHelper D(ColorHelper::DivergingScheme::Spectral); // Choose a color
comment|///                                                        // scheme.
comment|/// for (double p= -1; p<= 1 ; p += 0.1){
comment|///   cout()<< D.getColor(p)<< " \n"; // sample the gradient at 0.1 intervals
comment|/// }
name|class
name|ColorHelper
block|{
name|double
name|MinIn
decl_stmt|;
name|double
name|MaxIn
decl_stmt|;
name|ArrayRef
operator|<
name|std
operator|::
name|tuple
operator|<
name|uint8_t
operator|,
name|uint8_t
operator|,
name|uint8_t
operator|>>
name|ColorMap
expr_stmt|;
name|ArrayRef
operator|<
name|std
operator|::
name|tuple
operator|<
name|uint8_t
operator|,
name|uint8_t
operator|,
name|uint8_t
operator|>>
name|BoundMap
expr_stmt|;
name|public
label|:
comment|/// Enum of the availible Sequential Color Schemes
name|enum
name|class
name|SequentialScheme
block|{
comment|// Schemes based on the ColorBrewer Color schemes of the same name from
comment|// http://www.colorbrewer.org/ by Cynthis A Brewer Penn State University.
name|Greys
operator|,
name|OrRd
operator|,
name|PuBu
block|}
empty_stmt|;
name|ColorHelper
argument_list|(
argument|SequentialScheme S
argument_list|)
empty_stmt|;
comment|/// Enum of the availible Diverging Color Schemes
name|enum
name|class
name|DivergingScheme
block|{
comment|// Schemes based on the ColorBrewer Color schemes of the same name from
comment|// http://www.colorbrewer.org/ by Cynthis A Brewer Penn State University.
name|PiYG
block|}
empty_stmt|;
name|ColorHelper
argument_list|(
argument|DivergingScheme S
argument_list|)
empty_stmt|;
comment|// Sample the gradient at the input point.
name|std
operator|::
name|tuple
operator|<
name|uint8_t
operator|,
name|uint8_t
operator|,
name|uint8_t
operator|>
name|getColorTuple
argument_list|(
argument|double Point
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|getColorString
argument_list|(
argument|double Point
argument_list|)
specifier|const
expr_stmt|;
comment|// Get the Default color, at the moment allways black.
name|std
operator|::
name|tuple
operator|<
name|uint8_t
operator|,
name|uint8_t
operator|,
name|uint8_t
operator|>
name|getDefaultColorTuple
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_tuple
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|std
operator|::
name|string
name|getDefaultColorString
argument_list|()
specifier|const
block|{
return|return
literal|"black"
return|;
block|}
comment|// Convert a tuple to a string
specifier|static
name|std
operator|::
name|string
name|getColorString
argument_list|(
name|std
operator|::
name|tuple
operator|<
name|uint8_t
argument_list|,
name|uint8_t
argument_list|,
name|uint8_t
operator|>
name|t
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

