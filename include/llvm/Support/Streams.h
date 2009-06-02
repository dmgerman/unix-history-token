begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Streams.h - Wrappers for iostreams ----------*- C++ -*-===//
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
comment|// This file implements a wrapper for the STL I/O streams.  It prevents the need
end_comment

begin_comment
comment|// to include<iostream> in a file just to get I/O.
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
name|LLVM_SUPPORT_STREAMS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_STREAMS_H
end_define

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// FlushStream - Function called by BaseStream to flush an ostream.
name|void
name|FlushStream
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|S
argument_list|)
decl_stmt|;
comment|/// BaseStream - Acts like the STL streams. It's a wrapper for the std::cerr,
comment|/// std::cout, std::cin, etc. streams. However, it doesn't require #including
comment|/// @verbatim<iostream> @endverbatm in every file (doing so increases static
comment|/// c'tors& d'tors in the object code).
comment|///
name|template
operator|<
name|typename
name|StreamTy
operator|>
name|class
name|BaseStream
block|{
name|StreamTy
operator|*
name|Stream
block|;
name|public
operator|:
name|BaseStream
argument_list|()
operator|:
name|Stream
argument_list|(
literal|0
argument_list|)
block|{}
name|BaseStream
argument_list|(
name|StreamTy
operator|&
name|S
argument_list|)
operator|:
name|Stream
argument_list|(
argument|&S
argument_list|)
block|{}
name|BaseStream
argument_list|(
name|StreamTy
operator|*
name|S
argument_list|)
operator|:
name|Stream
argument_list|(
argument|S
argument_list|)
block|{}
name|StreamTy
operator|*
name|stream
argument_list|()
specifier|const
block|{
return|return
name|Stream
return|;
block|}
specifier|inline
name|BaseStream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ios_base
operator|&
call|(
modifier|*
name|Func
call|)
argument_list|(
name|std
operator|::
name|ios_base
operator|&
argument_list|)
operator|)
block|{
if|if
condition|(
name|Stream
condition|)
operator|*
name|Stream
operator|<<
name|Func
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|BaseStream
operator|&
name|operator
operator|<<
operator|(
name|StreamTy
operator|&
call|(
modifier|*
name|Func
call|)
argument_list|(
name|StreamTy
operator|&
argument_list|)
operator|)
block|{
if|if
condition|(
name|Stream
condition|)
operator|*
name|Stream
operator|<<
name|Func
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_function
name|void
name|flush
parameter_list|()
block|{
if|if
condition|(
name|Stream
condition|)
name|FlushStream
argument_list|(
operator|*
name|Stream
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|Ty
operator|>
name|BaseStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Ty
operator|&
name|Thing
operator|)
block|{
if|if
condition|(
name|Stream
condition|)
operator|*
name|Stream
operator|<<
name|Thing
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|Ty
operator|>
name|BaseStream
operator|&
name|operator
operator|>>
operator|(
name|Ty
operator|&
name|Thing
operator|)
block|{
if|if
condition|(
name|Stream
condition|)
operator|*
name|Stream
operator|>>
name|Thing
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|Ty
operator|>
name|BaseStream
operator|&
name|write
argument_list|(
argument|const Ty&A
argument_list|,
argument|unsigned N
argument_list|)
block|{
if|if
condition|(
name|Stream
condition|)
name|Stream
operator|->
name|write
argument_list|(
name|A
argument_list|,
name|N
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_macro
unit|}      operator
name|StreamTy
end_macro

begin_expr_stmt
operator|*
operator|(
operator|)
block|{
return|return
name|Stream
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|StreamTy
operator|&
name|S
operator|)
block|{
return|return
operator|&
name|S
operator|==
name|Stream
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|StreamTy
operator|&
name|S
operator|)
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|S
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BaseStream
operator|&
name|S
operator|)
block|{
return|return
name|S
operator|.
name|Stream
operator|==
name|Stream
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|BaseStream
operator|&
name|S
operator|)
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|S
operator|)
return|;
block|}
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|BaseStream
operator|<
name|std
operator|::
name|ostream
operator|>
name|OStream
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|BaseStream
operator|<
name|std
operator|::
name|istream
operator|>
name|IStream
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|BaseStream
operator|<
name|std
operator|::
name|stringstream
operator|>
name|StringStream
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|OStream
name|cout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OStream
name|cerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|IStream
name|cin
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

