begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2003 Free Software Foundation, Inc.
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
comment|// ISO C++ 14882: 22.1  Locales
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ctype bits to be inlined go here. Non-inlinable (ie virtual do_*)
end_comment

begin_comment
comment|// functions go in ctype.cc
end_comment

begin_expr_stmt
name|bool
name|ctype
operator|<
name|char
operator|>
operator|::
name|is
argument_list|(
argument|mask __m
argument_list|,
argument|char __c
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_table
condition|)
return|return
name|_M_table
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
name|__c
operator|)
index|]
operator|&
name|__m
return|;
else|else
return|return
name|__istype
argument_list|(
name|__c
argument_list|,
name|__m
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|char
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|is
argument_list|(
argument|const char* __low
argument_list|,
argument|const char* __high
argument_list|,
argument|mask* __vec
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_table
condition|)
while|while
condition|(
name|__low
operator|<
name|__high
condition|)
operator|*
name|__vec
operator|++
operator|=
name|_M_table
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|*
name|__low
operator|++
operator|)
index|]
expr_stmt|;
else|else
for|for
control|(
init|;
name|__low
operator|<
name|__high
condition|;
operator|++
name|__vec
operator|,
operator|++
name|__low
control|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_CTYPE_S
argument_list|)
operator|||
name|defined
argument_list|(
name|__istype
argument_list|)
operator|*
name|__vec
operator|=
name|__maskrune
argument_list|(
operator|*
name|__low
argument_list|,
name|upper
operator||
name|lower
operator||
name|alpha
operator||
name|digit
operator||
name|xdigit
operator||
name|space
operator||
name|print
operator||
name|graph
operator||
name|cntrl
operator||
name|punct
operator||
name|alnum
argument_list|)
expr_stmt|;
else|#
directive|else
name|mask
name|__m
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|upper
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|upper
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|lower
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|lower
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|alpha
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|alpha
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|digit
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|digit
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|xdigit
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|xdigit
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|space
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|space
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|print
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|print
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|graph
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|graph
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|cntrl
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|cntrl
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|punct
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|punct
expr_stmt|;
comment|// Do not include explicit line for alnum mask since it is a
comment|// pure composite of masks on FreeBSD.
operator|*
name|__vec
operator|=
name|__m
expr_stmt|;
endif|#
directive|endif
block|}
end_expr_stmt

begin_return
return|return
name|__high
return|;
end_return

begin_expr_stmt
unit|}    const
name|char
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|scan_is
argument_list|(
argument|mask __m
argument_list|,
argument|const char* __low
argument_list|,
argument|const char* __high
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_table
condition|)
while|while
condition|(
name|__low
operator|<
name|__high
operator|&&
operator|!
operator|(
name|_M_table
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|*
name|__low
operator|)
index|]
operator|&
name|__m
operator|)
condition|)
operator|++
name|__low
expr_stmt|;
else|else
while|while
condition|(
name|__low
operator|<
name|__high
operator|&&
operator|!
name|this
operator|->
name|is
argument_list|(
name|__m
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
operator|++
name|__low
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__low
return|;
end_return

begin_expr_stmt
unit|}    const
name|char
operator|*
name|ctype
operator|<
name|char
operator|>
operator|::
name|scan_not
argument_list|(
argument|mask __m
argument_list|,
argument|const char* __low
argument_list|,
argument|const char* __high
argument_list|)
specifier|const
block|{
if|if
condition|(
name|_M_table
condition|)
while|while
condition|(
name|__low
operator|<
name|__high
operator|&&
operator|(
name|_M_table
index|[
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
operator|*
name|__low
operator|)
index|]
operator|&
name|__m
operator|)
operator|!=
literal|0
condition|)
operator|++
name|__low
expr_stmt|;
else|else
while|while
condition|(
name|__low
operator|<
name|__high
operator|&&
name|this
operator|->
name|is
argument_list|(
name|__m
argument_list|,
operator|*
name|__low
argument_list|)
operator|!=
literal|0
condition|)
operator|++
name|__low
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__low
return|;
end_return

unit|}
end_unit

