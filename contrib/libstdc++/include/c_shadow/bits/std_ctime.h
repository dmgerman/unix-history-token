begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*- header wrapper.
end_comment

begin_comment
comment|// Copyright (C) 1997-1999, 2000 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 20.5  Date and time
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CTIME
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CTIME
value|1
end_define

begin_include
include|#
directive|include
file|<bits/std_cstddef.h>
end_include

begin_decl_stmt
name|namespace
name|_C_legacy
block|{
extern|extern
literal|"C"
block|{
define|#
directive|define
name|_IN_C_LEGACY_
pragma|#
directive|pragma
name|GCC
name|system_header
comment|// XXX
comment|// glibc 2.1.x time.h is on crack
undef|#
directive|undef
name|__need_time_t
undef|#
directive|undef
name|__need_clock_t
undef|#
directive|undef
name|__need_timespec
empty|#     include_next<time.h>
block|}
typedef|typedef
name|clock_t
name|_CPP_clock_t_capture
typedef|;
typedef|typedef
name|time_t
name|_CPP_time_t_capture
typedef|;
typedef|typedef
name|tm
name|_CPP_tm_capture
typedef|;
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|clock_t
end_undef

begin_undef
undef|#
directive|undef
name|time_t
end_undef

begin_undef
undef|#
directive|undef
name|tm
end_undef

begin_undef
undef|#
directive|undef
name|clock
end_undef

begin_undef
undef|#
directive|undef
name|difftime
end_undef

begin_undef
undef|#
directive|undef
name|mktime
end_undef

begin_undef
undef|#
directive|undef
name|time
end_undef

begin_undef
undef|#
directive|undef
name|asctime
end_undef

begin_undef
undef|#
directive|undef
name|ctime
end_undef

begin_undef
undef|#
directive|undef
name|gmtime
end_undef

begin_undef
undef|#
directive|undef
name|localtime
end_undef

begin_undef
undef|#
directive|undef
name|strftime
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Adopt C names into std::
typedef|typedef
name|_C_legacy
operator|::
name|_CPP_clock_t_capture
name|clock_t
expr_stmt|;
typedef|typedef
name|_C_legacy
operator|::
name|_CPP_time_t_capture
name|time_t
expr_stmt|;
name|struct
name|tm
range|:
name|_C_legacy
operator|::
name|_CPP_tm_capture
block|{ }
decl_stmt|;
name|using
name|_C_legacy
operator|::
name|clock
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|difftime
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|mktime
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|time
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|ctime
expr_stmt|;
specifier|inline
name|char
modifier|*
name|asctime
parameter_list|(
specifier|const
name|tm
modifier|*
name|__t
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|asctime
argument_list|(
name|static_cast
operator|<
name|_C_legacy
operator|::
name|_CPP_tm_capture
specifier|const
operator|*
operator|>
operator|(
name|__t
operator|)
argument_list|)
return|;
block|}
specifier|inline
name|tm
modifier|*
name|gmtime
parameter_list|(
name|time_t
specifier|const
modifier|*
name|__tp
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|tm
operator|*
operator|>
operator|(
name|_C_legacy
operator|::
name|gmtime
argument_list|(
name|__tp
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
name|__tp
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|tm
operator|*
operator|>
operator|(
name|_C_legacy
operator|::
name|localtime
argument_list|(
name|__tp
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|size_t
name|strftime
parameter_list|(
name|char
modifier|*
name|__buf
parameter_list|,
name|size_t
name|__maxsz
parameter_list|,
name|char
specifier|const
modifier|*
name|__fmt
parameter_list|,
name|tm
specifier|const
modifier|*
name|__tp
parameter_list|)
block|{
return|return
name|_C_legacy
operator|::
name|strftime
argument_list|(
name|__buf
argument_list|,
name|__maxsz
argument_list|,
name|__fmt
argument_list|,
name|static_cast
operator|<
name|_C_legacy
operator|::
name|_CPP_tm_capture
specifier|const
operator|*
operator|>
operator|(
name|__tp
operator|)
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_undef
undef|#
directive|undef
name|_IN_C_LEGACY_
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

