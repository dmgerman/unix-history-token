begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implements a string hashing function.    Copyright (C) 1995, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_VALUES_H
end_ifdef

begin_include
include|#
directive|include
file|<values.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* @@ end of prolog @@ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We assume to have `unsigned long int' value with at least 32 bits.  */
end_comment

begin_define
define|#
directive|define
name|HASHWORDBITS
value|32
end_define

begin_comment
comment|/* Defines the so called `hashpjw' function by P.J. Weinberger    [see Aho/Sethi/Ullman, COMPILERS: Principles, Techniques and Tools,    1986, 1987 Bell Telephone Laboratories, Inc.]  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|hash_string
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__str_param
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|hash_string
parameter_list|(
name|str_param
parameter_list|)
specifier|const
name|char
modifier|*
name|str_param
decl_stmt|;
block|{
name|unsigned
name|long
name|int
name|hval
decl_stmt|,
name|g
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
init|=
name|str_param
decl_stmt|;
comment|/* Compute the hash value for the given string.  */
name|hval
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|str
operator|!=
literal|'\0'
condition|)
block|{
name|hval
operator|<<=
literal|4
expr_stmt|;
name|hval
operator|+=
operator|(
name|unsigned
name|long
operator|)
operator|*
name|str
operator|++
expr_stmt|;
name|g
operator|=
name|hval
operator|&
operator|(
operator|(
name|unsigned
name|long
operator|)
literal|0xf
operator|<<
operator|(
name|HASHWORDBITS
operator|-
literal|4
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|g
operator|!=
literal|0
condition|)
block|{
name|hval
operator|^=
name|g
operator|>>
operator|(
name|HASHWORDBITS
operator|-
literal|8
operator|)
expr_stmt|;
name|hval
operator|^=
name|g
expr_stmt|;
block|}
block|}
return|return
name|hval
return|;
block|}
end_function

end_unit

