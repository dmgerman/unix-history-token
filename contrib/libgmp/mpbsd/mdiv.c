begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mdiv -- BSD compatible divide producing both remainder and quotient.  Copyright (C) 1991, 1994, 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|"mp.h"
end_include

begin_include
include|#
directive|include
file|"gmp.h"
end_include

begin_include
include|#
directive|include
file|"gmp-impl.h"
end_include

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_decl_stmt
name|void
if|#
directive|if
name|__STDC__
name|mdiv
argument_list|(
specifier|const
name|MINT
operator|*
name|num
argument_list|,
specifier|const
name|MINT
operator|*
name|den
argument_list|,
name|MINT
operator|*
name|quot
argument_list|,
name|MINT
operator|*
name|rem
argument_list|)
else|#
directive|else
name|mdiv
argument_list|(
name|num
argument_list|,
name|den
argument_list|,
name|quot
argument_list|,
name|rem
argument_list|)
decl|const
name|MINT
modifier|*
name|num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MINT
modifier|*
name|den
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MINT
modifier|*
name|quot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MINT
modifier|*
name|rem
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COMPUTE_QUOTIENT
end_define

begin_include
include|#
directive|include
file|"dmincl.c"
end_include

end_unit

