begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    -*- C++ -*-
end_comment

begin_comment
comment|//    This is part of the iostream library, providing parametrized manipulators
end_comment

begin_comment
comment|//    Written by Heinz G. Seidl, Copyright (C) 1992 Cygnus Support
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is free software; you can redistribute it and/or
end_comment

begin_comment
comment|//    modify it under the terms of the GNU Library General Public
end_comment

begin_comment
comment|//    License as published by the Free Software Foundation; either
end_comment

begin_comment
comment|//    version 2 of the License, or (at your option) any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|//    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
end_comment

begin_comment
comment|//    Library General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    You should have received a copy of the GNU Library General Public
end_comment

begin_comment
comment|//    License along with this library; if not, write to the Free
end_comment

begin_comment
comment|//    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOMANIP_H
end_ifndef

begin_comment
comment|//
end_comment

begin_comment
comment|// Not specifying `pragma interface' causes the compiler to emit the
end_comment

begin_comment
comment|// template definitions in the files, where they are used.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//#ifdef __GNUG__
end_comment

begin_comment
comment|//#pragma interface
end_comment

begin_comment
comment|//#endif
end_comment

begin_define
define|#
directive|define
name|_IOMANIP_H
end_define

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_G_NO_TEMPLATES
end_ifndef

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//	Parametrized Manipulators as specified by ANSI draft
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//	Stream Manipulators
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|smanip
expr_stmt|;
end_expr_stmt

begin_comment
comment|// TP = Type Param
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|sapp
block|{
name|ios
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|ios
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|public
operator|:
name|sapp
argument_list|(
name|ios
operator|&
call|(
modifier|*
name|f
call|)
argument_list|(
name|ios
operator|&
argument_list|,
name|TP
argument_list|)
argument_list|)
operator|:
name|_f
argument_list|(
argument|f
argument_list|)
block|{}
comment|//
name|smanip
operator|<
name|TP
operator|>
name|operator
argument_list|()
operator|(
name|TP
name|a
operator|)
block|{
return|return
name|smanip
operator|<
name|TP
operator|>
operator|(
name|_f
operator|,
name|a
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|smanip
block|{
name|ios
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|ios
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|TP
name|_a
block|;
name|public
operator|:
name|smanip
argument_list|(
argument|ios& (*f)(ios&, TP)
argument_list|,
argument|TP a
argument_list|)
operator|:
name|_f
argument_list|(
name|f
argument_list|)
block|,
name|_a
argument_list|(
argument|a
argument_list|)
block|{}
comment|//
name|friend
name|istream
operator|&
name|operator
operator|>>
operator|(
name|istream
operator|&
name|i
operator|,
specifier|const
name|smanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|;
name|friend
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|ostream
operator|&
name|o
operator|,
specifier|const
name|smanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
specifier|inline
name|istream
operator|&
name|operator
operator|>>
operator|(
name|istream
operator|&
name|i
operator|,
specifier|const
name|smanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|{
call|(
modifier|*
name|m
operator|.
name|_f
call|)
argument_list|(
name|i
argument_list|,
name|m
operator|.
name|_a
argument_list|)
block|;
return|return
name|i
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
specifier|inline
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|ostream
operator|&
name|o
operator|,
specifier|const
name|smanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|{
call|(
modifier|*
name|m
operator|.
name|_f
call|)
argument_list|(
name|o
argument_list|,
name|m
operator|.
name|_a
argument_list|)
block|;
return|return
name|o
return|;
block|}
end_expr_stmt

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//	Input-Stream Manipulators
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|imanip
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|iapp
block|{
name|istream
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|istream
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|public
operator|:
name|iapp
argument_list|(
name|ostream
operator|&
call|(
modifier|*
name|f
call|)
argument_list|(
name|istream
operator|&
argument_list|,
name|TP
argument_list|)
argument_list|)
operator|:
name|_f
argument_list|(
argument|f
argument_list|)
block|{}
comment|//
name|imanip
operator|<
name|TP
operator|>
name|operator
argument_list|()
operator|(
name|TP
name|a
operator|)
block|{
return|return
name|imanip
operator|<
name|TP
operator|>
operator|(
name|_f
operator|,
name|a
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|imanip
block|{
name|istream
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|istream
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|TP
name|_a
block|;
name|public
operator|:
name|imanip
argument_list|(
argument|istream& (*f)(istream&, TP)
argument_list|,
argument|TP a
argument_list|)
operator|:
name|_f
argument_list|(
name|f
argument_list|)
block|,
name|_a
argument_list|(
argument|a
argument_list|)
block|{}
comment|//
name|friend
name|istream
operator|&
name|operator
operator|>>
operator|(
name|istream
operator|&
name|i
operator|,
specifier|const
name|imanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|{
return|return
call|(
modifier|*
name|m
operator|.
name|_f
call|)
argument_list|(
name|i
argument_list|,
name|m
operator|.
name|_a
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//	Output-Stream Manipulators
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|omanip
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|oapp
block|{
name|ostream
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|ostream
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|public
operator|:
name|oapp
argument_list|(
name|ostream
operator|&
call|(
modifier|*
name|f
call|)
argument_list|(
name|ostream
operator|&
argument_list|,
name|TP
argument_list|)
argument_list|)
operator|:
name|_f
argument_list|(
argument|f
argument_list|)
block|{}
comment|//
name|omanip
operator|<
name|TP
operator|>
name|operator
argument_list|()
operator|(
name|TP
name|a
operator|)
block|{
return|return
name|omanip
operator|<
name|TP
operator|>
operator|(
name|_f
operator|,
name|a
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|TP
operator|>
name|class
name|omanip
block|{
name|ostream
operator|&
call|(
modifier|*
name|_f
call|)
argument_list|(
name|ostream
operator|&
argument_list|,
name|TP
argument_list|)
block|;
name|TP
name|_a
block|;
name|public
operator|:
name|omanip
argument_list|(
argument|ostream& (*f)(ostream&, TP)
argument_list|,
argument|TP a
argument_list|)
operator|:
name|_f
argument_list|(
name|f
argument_list|)
block|,
name|_a
argument_list|(
argument|a
argument_list|)
block|{}
comment|//
name|friend
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|ostream
operator|&
name|o
operator|,
name|omanip
operator|<
name|TP
operator|>
operator|&
name|m
operator|)
block|{
return|return
call|(
modifier|*
name|m
operator|.
name|_f
call|)
argument_list|(
name|o
argument_list|,
name|m
operator|.
name|_a
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//	Available Manipulators
end_comment

begin_comment
comment|//-----------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Macro to define an iomanip function, with one argument
end_comment

begin_comment
comment|// The underlying function is `__iomanip_<name>'
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|__DEFINE_IOMANIP_FN1
parameter_list|(
name|type
parameter_list|,
name|param
parameter_list|,
name|function
parameter_list|)
define|\
value|extern ios& __iomanip_##function (ios&, param); \ 	inline type<param> function (param n)           \ 		        { return type<param> (__iomanip_##function, n); }
end_define

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|int
argument_list|,
argument|setbase
argument_list|)
end_macro

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|int
argument_list|,
argument|setfill
argument_list|)
end_macro

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|int
argument_list|,
argument|setprecision
argument_list|)
end_macro

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|int
argument_list|,
argument|setw
argument_list|)
end_macro

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|ios::fmtflags
argument_list|,
argument|resetiosflags
argument_list|)
end_macro

begin_macro
name|__DEFINE_IOMANIP_FN1
argument_list|(
argument|smanip
argument_list|,
argument|ios::fmtflags
argument_list|,
argument|setiosflags
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_G_NO_TEMPLATES*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_IOMANIP_H*/
end_comment

end_unit

