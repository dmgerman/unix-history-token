begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2002 Free Software Foundation, Inc.
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

begin_comment
comment|// The following definitions are portable, but insanely slow. If one
end_comment

begin_comment
comment|// cares at all about performance, then specialized ctype
end_comment

begin_comment
comment|// functionality should be added for the native os in question: see
end_comment

begin_comment
comment|// the config/os/bits/ctype_*.h files.
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
name|bool
name|__ret
block|;
switch|switch
condition|(
name|__m
condition|)
block|{
case|case
name|space
case|:
name|__ret
operator|=
name|isspace
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|print
case|:
name|__ret
operator|=
name|isprint
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|cntrl
case|:
name|__ret
operator|=
name|iscntrl
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|upper
case|:
name|__ret
operator|=
name|isupper
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|lower
case|:
name|__ret
operator|=
name|islower
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|alpha
case|:
name|__ret
operator|=
name|isalpha
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|digit
case|:
name|__ret
operator|=
name|isdigit
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|punct
case|:
name|__ret
operator|=
name|ispunct
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|xdigit
case|:
name|__ret
operator|=
name|isxdigit
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|alnum
case|:
name|__ret
operator|=
name|isalnum
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
case|case
name|graph
case|:
name|__ret
operator|=
name|isgraph
argument_list|(
name|__c
argument_list|)
expr_stmt|;
break|break;
default|default:
name|__ret
operator|=
name|false
expr_stmt|;
break|break;
block|}
end_expr_stmt

begin_return
return|return
name|__ret
return|;
end_return

begin_expr_stmt
unit|}       const
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
specifier|const
name|int
name|__bitmasksize
operator|=
literal|11
block|;
comment|// Highest bitmask in ctype_base == 10
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
name|mask
name|__m
init|=
literal|0
decl_stmt|;
name|int
name|__i
init|=
literal|0
decl_stmt|;
comment|// Lowest bitmask in ctype_base == 0
for|for
control|(
init|;
name|__i
operator|<
name|__bitmasksize
condition|;
operator|++
name|__i
control|)
block|{
name|mask
name|__bit
init|=
name|static_cast
operator|<
name|mask
operator|>
operator|(
literal|1
operator|<<
name|__i
operator|)
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|is
argument_list|(
name|__bit
argument_list|,
operator|*
name|__low
argument_list|)
condition|)
name|__m
operator||=
name|__bit
expr_stmt|;
block|}
operator|*
name|__vec
operator|=
name|__m
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}     return
name|__high
expr_stmt|;
end_expr_stmt

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

