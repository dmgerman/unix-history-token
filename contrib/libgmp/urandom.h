begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* urandom.h -- define urandom returning a full unsigned long random value.  Copyright (C) 1995, 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
end_if

begin_comment
comment|/* HPUX lacks random().  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
return|return
name|mrand48
argument_list|()
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__URANDOM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__URANDOM
argument_list|)
end_if

begin_comment
comment|/* DEC OSF/1 1.2 random() returns a double.  */
end_comment

begin_function_decl
name|long
name|mrand48
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
return|return
name|mrand48
argument_list|()
operator||
operator|(
name|mrand48
argument_list|()
operator|<<
literal|32
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__URANDOM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BITS_PER_MP_LIMB
operator|==
literal|32
operator|&&
operator|!
name|defined
argument_list|(
name|__URANDOM
argument_list|)
end_if

begin_function_decl
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
comment|/* random() returns 31 bits, we want 32.  */
return|return
name|random
argument_list|()
operator|^
operator|(
name|random
argument_list|()
operator|<<
literal|1
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__URANDOM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BITS_PER_MP_LIMB
operator|==
literal|64
operator|&&
operator|!
name|defined
argument_list|(
name|__URANDOM
argument_list|)
end_if

begin_function_decl
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|urandom
parameter_list|()
block|{
comment|/* random() returns 31 bits, we want 64.  */
return|return
name|random
argument_list|()
operator|^
operator|(
name|random
argument_list|()
operator|<<
literal|31
operator|)
operator|^
operator|(
name|random
argument_list|()
operator|<<
literal|62
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__URANDOM
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

