begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Methods for Exception Support for -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1994, 1995 Free Software Foundation
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
comment|// Written by Mike Stump based upon the specification in the 20 September 1994
end_comment

begin_comment
comment|// C++ working paper, ANSI document X3J16/94-0158.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDEXCEPT__
end_ifndef

begin_define
define|#
directive|define
name|__STDEXCEPT__
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
literal|"std/stdexcept.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<typeinfo>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
if|#
directive|if
literal|0
include|#
directive|include
file|<string>
block|typedef string __string;
else|#
directive|else
typedef|typedef
specifier|const
name|char
modifier|*
name|__string
typedef|;
endif|#
directive|endif
name|class
name|exception
block|{
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|raise_handler
function_decl|)
parameter_list|(
name|exception
modifier|&
parameter_list|)
function_decl|;
specifier|static
name|raise_handler
name|set_raise_handler
parameter_list|(
name|raise_handler
name|handler_arg
parameter_list|)
function_decl|;
name|exception
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|desc
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|exception
argument_list|()
block|{ }
name|void
name|raise
argument_list|()
expr_stmt|;
name|virtual
name|__string
name|what
argument_list|()
specifier|const
block|{
return|return
name|desc
return|;
block|}
name|protected
label|:
name|exception
argument_list|()
block|{ }
name|virtual
name|void
name|do_raise
parameter_list|()
block|{ }
name|private
label|:
name|__string
name|desc
decl_stmt|;
block|}
empty_stmt|;
name|class
name|logic_error
range|:
name|public
name|exception
block|{
name|public
operator|:
name|logic_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|exception
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|logic_error
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|domain_error
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|domain_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|logic_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|domain_error
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|invalid_argument
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|invalid_argument
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|logic_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|invalid_argument
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|length_error
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|length_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|logic_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|length_error
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|out_of_range
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|out_of_range
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|logic_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|out_of_range
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|runtime_error
range|:
name|public
name|exception
block|{
name|public
operator|:
name|runtime_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|exception
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|runtime_error
argument_list|()
block|{ }
name|protected
operator|:
name|runtime_error
argument_list|()
operator|:
name|exception
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|range_error
range|:
name|public
name|runtime_error
block|{
name|public
operator|:
name|range_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|runtime_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|range_error
argument_list|()
block|{ }
block|}
decl_stmt|;
name|class
name|overflow_error
range|:
name|public
name|runtime_error
block|{
name|public
operator|:
name|overflow_error
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|runtime_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|overflow_error
argument_list|()
block|{ }
block|}
decl_stmt|;
comment|// These are moved here from typeinfo so that we can compile with -frtti
name|class
name|bad_cast
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|bad_cast
argument_list|(
specifier|const
name|__string
operator|&
name|what_arg
argument_list|)
operator|:
name|logic_error
argument_list|(
argument|what_arg
argument_list|)
block|{ }
name|virtual
operator|~
name|bad_cast
argument_list|()
block|{ }
block|}
decl_stmt|;
specifier|extern
name|bad_cast
name|__bad_cast_object
decl_stmt|;
name|class
name|bad_typeid
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|bad_typeid
argument_list|()
operator|:
name|logic_error
argument_list|(
literal|"bad_typeid"
argument_list|)
block|{ }
name|virtual
operator|~
name|bad_typeid
argument_list|()
block|{ }
block|}
decl_stmt|;
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

