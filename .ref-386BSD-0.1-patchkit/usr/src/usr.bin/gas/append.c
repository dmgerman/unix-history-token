begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Append a string ontp another string    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* JF:  This is silly.  Why not stuff this in some other file? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|n
parameter_list|)
value|memcpy(to,from,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|append
parameter_list|(
name|charPP
parameter_list|,
name|fromP
parameter_list|,
name|length
parameter_list|)
name|char
modifier|*
modifier|*
name|charPP
decl_stmt|;
name|char
modifier|*
name|fromP
decl_stmt|;
name|unsigned
name|long
name|length
decl_stmt|;
block|{
if|if
condition|(
name|length
condition|)
block|{
comment|/* Don't trust bcopy() of 0 chars. */
name|bcopy
argument_list|(
name|fromP
argument_list|,
operator|*
name|charPP
argument_list|,
operator|(
name|int
operator|)
name|length
argument_list|)
expr_stmt|;
operator|*
name|charPP
operator|+=
name|length
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* end: append.c */
end_comment

end_unit

