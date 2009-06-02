begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Format.h - Efficient printf-style formatting for streams -*- C++ -*-===//
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
comment|// This file implements the format() function, which can be used with other
end_comment

begin_comment
comment|// LLVM subsystems to provide printf-style formatting.  This gives all the power
end_comment

begin_comment
comment|// and risk of printf.  This can be used like this (with raw_ostreams as an
end_comment

begin_comment
comment|// example):
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    OS<< "mynumber: "<< format("%4.5f", 1234.412)<< '\n';
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Or if you prefer:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  OS<< format("mynumber: %4.5f\n", 1234.412);
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
name|LLVM_SUPPORT_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMAT_H
end_define

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// format_object_base - This is a helper class used for handling formatted
comment|/// output.  It is the abstract base class of a templated derived class.
name|class
name|format_object_base
block|{
name|protected
label|:
specifier|const
name|char
modifier|*
name|Fmt
decl_stmt|;
name|virtual
name|void
name|home
parameter_list|()
function_decl|;
comment|// Out of line virtual method.
name|public
label|:
name|format_object_base
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|)
operator|:
name|Fmt
argument_list|(
argument|fmt
argument_list|)
block|{}
name|virtual
operator|~
name|format_object_base
argument_list|()
block|{}
comment|/// print - Format the object into the specified buffer.  On success, this
comment|/// returns the length of the formatted string.  If the buffer is too small,
comment|/// this returns a length to retry with, which will be larger than BufferSize.
name|virtual
name|unsigned
name|print
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// format_object1 - This is a templated helper class used by the format
comment|/// function that captures the object to be formated and the format string. When
comment|/// actually printed, this synthesizes the string into a temporary buffer
comment|/// provided and returns whether or not it is big enough.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|format_object1
operator|:
name|public
name|format_object_base
block|{
name|T
name|Val
block|;
name|public
operator|:
name|format_object1
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T
operator|&
name|val
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val
argument_list|(
argument|val
argument_list|)
block|{   }
comment|/// print - Format the object into the specified buffer.  On success, this
comment|/// returns the length of the formatted string.  If the buffer is too small,
comment|/// this returns a length to retry with, which will be larger than BufferSize.
name|virtual
name|unsigned
name|print
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
block|{
name|int
name|N
operator|=
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
operator|-
literal|1
argument_list|,
name|Fmt
argument_list|,
name|Val
argument_list|)
block|;
if|if
condition|(
name|N
operator|<
literal|0
condition|)
comment|// VC++ and old GlibC return negative on overflow.
return|return
name|BufferSize
operator|*
literal|2
return|;
if|if
condition|(
name|unsigned
argument_list|(
name|N
argument_list|)
operator|>=
name|BufferSize
operator|-
literal|1
condition|)
comment|// Other impls yield number of bytes needed.
return|return
name|N
operator|+
literal|1
return|;
comment|// If N is positive and<= BufferSize-1, then the string fit, yay.
return|return
name|N
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// format_object2 - This is a templated helper class used by the format
end_comment

begin_comment
comment|/// function that captures the object to be formated and the format string. When
end_comment

begin_comment
comment|/// actually printed, this synthesizes the string into a temporary buffer
end_comment

begin_comment
comment|/// provided and returns whether or not it is big enough.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|class
name|format_object2
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|public
operator|:
name|format_object2
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
argument|val2
argument_list|)
block|{   }
comment|/// print - Format the object into the specified buffer.  On success, this
comment|/// returns the length of the formatted string.  If the buffer is too small,
comment|/// this returns a length to retry with, which will be larger than BufferSize.
name|virtual
name|unsigned
name|print
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
block|{
name|int
name|N
operator|=
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
operator|-
literal|1
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|)
block|;
if|if
condition|(
name|N
operator|<
literal|0
condition|)
comment|// VC++ and old GlibC return negative on overflow.
return|return
name|BufferSize
operator|*
literal|2
return|;
if|if
condition|(
name|unsigned
argument_list|(
name|N
argument_list|)
operator|>=
name|BufferSize
operator|-
literal|1
condition|)
comment|// Other impls yield number of bytes needed.
return|return
name|N
operator|+
literal|1
return|;
end_expr_stmt

begin_comment
comment|// If N is positive and<= BufferSize-1, then the string fit, yay.
end_comment

begin_return
return|return
name|N
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// format_object3 - This is a templated helper class used by the format
end_comment

begin_comment
comment|/// function that captures the object to be formated and the format string. When
end_comment

begin_comment
comment|/// actually printed, this synthesizes the string into a temporary buffer
end_comment

begin_comment
comment|/// provided and returns whether or not it is big enough.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
name|class
name|format_object3
operator|:
name|public
name|format_object_base
block|{
name|T1
name|Val1
block|;
name|T2
name|Val2
block|;
name|T3
name|Val3
block|;
name|public
operator|:
name|format_object3
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
specifier|const
name|T1
operator|&
name|val1
argument_list|,
specifier|const
name|T2
operator|&
name|val2
argument_list|,
specifier|const
name|T3
operator|&
name|val3
argument_list|)
operator|:
name|format_object_base
argument_list|(
name|fmt
argument_list|)
block|,
name|Val1
argument_list|(
name|val1
argument_list|)
block|,
name|Val2
argument_list|(
name|val2
argument_list|)
block|,
name|Val3
argument_list|(
argument|val3
argument_list|)
block|{   }
comment|/// print - Format the object into the specified buffer.  On success, this
comment|/// returns the length of the formatted string.  If the buffer is too small,
comment|/// this returns a length to retry with, which will be larger than BufferSize.
name|virtual
name|unsigned
name|print
argument_list|(
argument|char *Buffer
argument_list|,
argument|unsigned BufferSize
argument_list|)
specifier|const
block|{
name|int
name|N
operator|=
name|snprintf
argument_list|(
name|Buffer
argument_list|,
name|BufferSize
operator|-
literal|1
argument_list|,
name|Fmt
argument_list|,
name|Val1
argument_list|,
name|Val2
argument_list|,
name|Val3
argument_list|)
block|;
if|if
condition|(
name|N
operator|<
literal|0
condition|)
comment|// VC++ and old GlibC return negative on overflow.
return|return
name|BufferSize
operator|*
literal|2
return|;
if|if
condition|(
name|unsigned
argument_list|(
name|N
argument_list|)
operator|>=
name|BufferSize
operator|-
literal|1
condition|)
comment|// Other impls yield number of bytes needed.
return|return
name|N
operator|+
literal|1
return|;
end_expr_stmt

begin_comment
comment|// If N is positive and<= BufferSize-1, then the string fit, yay.
end_comment

begin_return
return|return
name|N
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// format - This is a helper function that is used to produce formatted output.
end_comment

begin_comment
comment|/// This is typically used like:  OS<< format("%0.4f", myfloat)<< '\n';
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|format_object1
operator|<
name|T
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T&Val
argument_list|)
block|{
return|return
name|format_object1
operator|<
name|T
operator|>
operator|(
name|Fmt
operator|,
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// format - This is a helper function that is used to produce formatted output.
end_comment

begin_comment
comment|/// This is typically used like:  OS<< format("%0.4f", myfloat)<< '\n';
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|format_object2
operator|<
name|T1
operator|,
name|T2
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|)
block|{
return|return
name|format_object2
operator|<
name|T1
operator|,
name|T2
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// format - This is a helper function that is used to produce formatted output.
end_comment

begin_comment
comment|/// This is typically used like:  OS<< format("%0.4f", myfloat)<< '\n';
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|,
name|typename
name|T3
operator|>
specifier|inline
name|format_object3
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|>
name|format
argument_list|(
argument|const char *Fmt
argument_list|,
argument|const T1&Val1
argument_list|,
argument|const T2&Val2
argument_list|,
argument|const T3&Val3
argument_list|)
block|{
return|return
name|format_object3
operator|<
name|T1
operator|,
name|T2
operator|,
name|T3
operator|>
operator|(
name|Fmt
operator|,
name|Val1
operator|,
name|Val2
operator|,
name|Val3
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

