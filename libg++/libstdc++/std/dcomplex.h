begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- double_complex class.
end_comment

begin_comment
comment|// Copyright (C) 1994 Free Software Foundation
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
end_comment

begin_comment
comment|// As a special exception, if you link this library with files
end_comment

begin_comment
comment|// compiled with a GNU compiler to produce an executable, this does not cause
end_comment

begin_comment
comment|// the resulting executable to be covered by the GNU General Public License.
end_comment

begin_comment
comment|// This exception does not however invalidate any other reasons why
end_comment

begin_comment
comment|// the executable file might be covered by the GNU General Public License.
end_comment

begin_comment
comment|// Written by Jason Merrill based upon the specification in the 27 May 1994
end_comment

begin_comment
comment|// C++ working paper, ANSI document X3J16/94-0098.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DCOMPLEX__
end_ifndef

begin_define
define|#
directive|define
name|__DCOMPLEX__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"dcomplex"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|complex
operator|<
name|double
operator|>
block|{
name|public
operator|:
name|complex
argument_list|(
argument|double r =
literal|0
argument_list|,
argument|double i =
literal|0
argument_list|)
operator|:
name|re
argument_list|(
name|r
argument_list|)
block|,
name|im
argument_list|(
argument|i
argument_list|)
block|{ }
name|complex
argument_list|(
specifier|const
name|complex
operator|<
name|float
operator|>
operator|&
name|r
argument_list|)
operator|:
name|re
argument_list|(
name|r
operator|.
name|real
argument_list|()
argument_list|)
block|,
name|im
argument_list|(
argument|r.imag ()
argument_list|)
block|{ }
name|explicit
name|complex
argument_list|(
argument|const complex<long double>& r
argument_list|)
block|;
name|complex
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|complex
operator|&
operator|)
block|;
name|complex
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|complex
operator|&
operator|)
block|;
name|complex
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|complex
operator|&
operator|)
block|;
name|complex
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|complex
operator|&
operator|)
block|;
name|double
name|real
argument_list|()
specifier|const
block|{
return|return
name|re
return|;
block|}
name|double
name|imag
argument_list|()
specifier|const
block|{
return|return
name|im
return|;
block|}
name|private
label|:
name|double
name|re
decl_stmt|,
name|im
decl_stmt|;
comment|// These functions are specified as friends for purposes of name injection;
comment|// they do not actually reference private members.
name|friend
name|double
name|real
parameter_list|(
specifier|const
name|complex
modifier|&
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|real
argument_list|()
return|;
block|}
name|friend
name|double
name|imag
parameter_list|(
specifier|const
name|complex
modifier|&
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|imag
argument_list|()
return|;
block|}
name|friend
name|complex
name|operator
operator|+
operator|(
specifier|const
name|complex
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
operator|+
operator|(
specifier|const
name|complex
operator|&
operator|,
name|double
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
operator|+
operator|(
name|double
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
operator|-
operator|(
specifier|const
name|complex
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
operator|-
operator|(
specifier|const
name|complex
operator|&
operator|,
name|double
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
operator|-
operator|(
name|double
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
name|friend
name|complex
name|operator
modifier|*
parameter_list|(
specifier|const
name|complex
modifier|&
parameter_list|,
specifier|const
name|complex
modifier|&
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|operator
modifier|*
parameter_list|(
specifier|const
name|complex
modifier|&
parameter_list|,
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|operator
modifier|*
parameter_list|(
name|double
parameter_list|,
specifier|const
name|complex
modifier|&
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|friend
name|complex
name|operator
operator|/
operator|(
specifier|const
name|complex
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|complex
name|operator
operator|/
operator|(
specifier|const
name|complex
operator|&
operator|,
name|double
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|complex
name|operator
operator|/
operator|(
name|double
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|complex
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|complex
operator|&
operator|,
name|double
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|double
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|complex
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|complex
operator|&
operator|,
name|double
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|double
operator|,
specifier|const
name|complex
operator|&
operator|)
name|__attribute__
argument_list|(
operator|(
specifier|const
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|friend
name|complex
name|polar
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|pow
parameter_list|(
specifier|const
name|complex
modifier|&
parameter_list|,
specifier|const
name|complex
modifier|&
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|pow
parameter_list|(
specifier|const
name|complex
modifier|&
parameter_list|,
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|pow
parameter_list|(
specifier|const
name|complex
modifier|&
parameter_list|,
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|friend
name|complex
name|pow
parameter_list|(
name|double
parameter_list|,
specifier|const
name|complex
modifier|&
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|friend
name|istream
operator|&
name|operator
operator|>>
operator|(
name|istream
operator|&
operator|,
name|complex
operator|&
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|ostream
operator|&
operator|,
specifier|const
name|complex
operator|&
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
specifier|inline
name|complex
operator|<
name|float
operator|>
operator|::
name|complex
argument_list|(
specifier|const
name|complex
operator|<
name|double
operator|>
operator|&
name|r
argument_list|)
operator|:
name|re
argument_list|(
name|r
operator|.
name|real
argument_list|()
argument_list|)
operator|,
name|im
argument_list|(
argument|r.imag ()
argument_list|)
block|{ }
end_expr_stmt

begin_comment
unit|}
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

