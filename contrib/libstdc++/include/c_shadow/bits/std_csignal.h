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
comment|// ISO C++ 14882: 20.4.6  C library
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_CSIGNAL
end_ifndef

begin_define
define|#
directive|define
name|_CPP_CSIGNAL
value|1
end_define

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
comment|// XXX
undef|#
directive|undef
name|__need_sig_atomic_t
undef|#
directive|undef
name|__need_sigset_t
pragma|#
directive|pragma
name|GCC
name|system_header
empty|#     include_next<signal.h>
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace _C_legacy
end_comment

begin_undef
undef|#
directive|undef
name|sig_atomic_t
end_undef

begin_undef
undef|#
directive|undef
name|raise
end_undef

begin_undef
undef|#
directive|undef
name|signal
end_undef

begin_decl_stmt
name|namespace
name|std
block|{
comment|// Adopt C names into std::
name|using
name|_C_legacy
operator|::
name|sig_atomic_t
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|raise
expr_stmt|;
name|using
name|_C_legacy
operator|::
name|signal
expr_stmt|;
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

