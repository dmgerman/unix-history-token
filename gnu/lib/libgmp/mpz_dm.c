begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mpz_divmod(quot,rem,dividend,divisor) -- Set QUOT to DIVIDEND/DIVISOR,    and REM to DIVIDEND mod DIVISOR.  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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
ifdef|#
directive|ifdef
name|__STDC__
name|mpz_divmod
argument_list|(
name|MP_INT
operator|*
name|quot
argument_list|,
name|MP_INT
operator|*
name|rem
argument_list|,
specifier|const
name|MP_INT
operator|*
name|num
argument_list|,
specifier|const
name|MP_INT
operator|*
name|den
argument_list|)
else|#
directive|else
name|mpz_divmod
argument_list|(
name|quot
argument_list|,
name|rem
argument_list|,
name|num
argument_list|,
name|den
argument_list|)
name|MP_INT
modifier|*
name|quot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MP_INT
modifier|*
name|rem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MP_INT
modifier|*
name|num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MP_INT
modifier|*
name|den
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
file|"mpz_dmincl.c"
end_include

end_unit

