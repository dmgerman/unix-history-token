begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RTTI support internals for -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1994, 1995, 1996, 1998, 1999, 2000, 2001, 2004
end_comment

begin_comment
comment|// Free Software Foundation
end_comment

begin_comment
comment|// This file is part of GCC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// the Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// GCC is distributed in the hope that it will be useful,
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
comment|// along with GCC; see the file COPYING.  If not, write to
end_comment

begin_comment
comment|// the Free Software Foundation, 59 Temple Place - Suite 330,
end_comment

begin_comment
comment|// Boston, MA 02111-1307, USA.
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

begin_include
include|#
directive|include
file|"typeinfo"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_comment
comment|// Class declarations shared between the typeinfo implementation files.
end_comment

begin_include
include|#
directive|include
file|<cxxabi.h>
end_include

end_unit

