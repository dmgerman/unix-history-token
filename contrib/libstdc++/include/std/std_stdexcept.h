begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Standard exception classes  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
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
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO C++ 19.1  Exception classes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/** @file stdexcept  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_STDEXCEPT
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_STDEXCEPT
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<exception>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/** Logic errors represent problems in the internal logic of a program;    *  in theory, these are preventable, and even detectable before the    *  program runs (e.g., violations of class invariants).    *  @brief One of two subclasses of exception.    */
name|class
name|logic_error
range|:
name|public
name|exception
block|{
name|string
name|_M_msg
block|;
name|public
operator|:
comment|/** Takes a character string describing the error.  */
name|explicit
name|logic_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;
name|virtual
operator|~
name|logic_error
argument_list|()
name|throw
argument_list|()
block|;
comment|/** Returns a C-style character string describing the general cause of      *  the current error (the same string passed to the ctor).  */
name|virtual
specifier|const
name|char
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|;   }
decl_stmt|;
comment|/** Thrown by the library, or by you, to report domain errors (domain in    *  the mathmatical sense).  */
name|class
name|domain_error
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|explicit
name|domain_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** Thrown to report invalid arguments to functions.  */
name|class
name|invalid_argument
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|explicit
name|invalid_argument
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** Thrown when an object is constructed that would exceed its maximum    *  permitted size (e.g., a basic_string instance).  */
name|class
name|length_error
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|explicit
name|length_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** This represents an argument whose value is not within the expected    *  range (e.g., boundary checks in basic_string).  */
name|class
name|out_of_range
range|:
name|public
name|logic_error
block|{
name|public
operator|:
name|explicit
name|out_of_range
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** Runtime errors represent problems outside the scope of a program;    *  they cannot be easily predicted and can generally only be caught as    *  the program executes.    *  @brief One of two subclasses of exception.    */
name|class
name|runtime_error
range|:
name|public
name|exception
block|{
name|string
name|_M_msg
block|;
name|public
operator|:
comment|/** Takes a character string describing the error.  */
name|explicit
name|runtime_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;
name|virtual
operator|~
name|runtime_error
argument_list|()
name|throw
argument_list|()
block|;
comment|/** Returns a C-style character string describing the general cause of      *  the current error (the same string passed to the ctor).  */
name|virtual
specifier|const
name|char
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|;   }
decl_stmt|;
comment|/** Thrown to indicate range errors in internal computations.  */
name|class
name|range_error
range|:
name|public
name|runtime_error
block|{
name|public
operator|:
name|explicit
name|range_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** Thrown to indicate arithmetic overflow.  */
name|class
name|overflow_error
range|:
name|public
name|runtime_error
block|{
name|public
operator|:
name|explicit
name|overflow_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
comment|/** Thrown to indicate arithmetic underflow.  */
name|class
name|underflow_error
range|:
name|public
name|runtime_error
block|{
name|public
operator|:
name|explicit
name|underflow_error
argument_list|(
specifier|const
name|string
operator|&
name|__arg
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GLIBCXX_STDEXCEPT */
end_comment

end_unit

