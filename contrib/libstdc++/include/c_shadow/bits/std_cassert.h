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
comment|// ISO C++ 14882: 19.2  Assertions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NB: This is assumed to be a conforming implementation.
end_comment

begin_comment
comment|// ISO/IEC 9899:1999 (E), section 7.2
end_comment

begin_comment
comment|// assert.h
end_comment

begin_comment
comment|// ..defines the assert macro...
end_comment

begin_comment
comment|// ISO 14882
end_comment

begin_comment
comment|// 17.4.1.2 Headers
end_comment

begin_comment
comment|// ... declarations and definitions (except for macros) are within
end_comment

begin_comment
comment|// namespace scope of the namepace std...
end_comment

begin_comment
comment|//#ifndef _CPP_CASSERT
end_comment

begin_comment
comment|//#define _CPP_CASSERT 1
end_comment

begin_comment
comment|//namespace _C_legacy {
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|//#   define _IN_C_LEGACY_
pragma|#
directive|pragma
name|GCC
name|system_header
empty|#   include_next<assert.h>
block|}
end_extern

begin_comment
comment|//} // namespace _C_legacy
end_comment

begin_comment
comment|//#undef _IN_C_LEGACY_
end_comment

begin_comment
comment|//#endif
end_comment

end_unit

