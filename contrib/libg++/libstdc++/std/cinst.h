begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Forward declarations of -*- C++ -*- complex number instantiations.
end_comment

begin_comment
comment|// Copyright (C) 1994 Free Software Foundation
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.  This library is free
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
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
end_comment

begin_comment
comment|// As a special exception, if you link this library with files
end_comment

begin_comment
comment|// compiled with a GNU compiler to produce an executable, this does not cause
end_comment

begin_comment
comment|// the resulting executable to be covered by the GNU General Public License.
end_comment

begin_comment
comment|// This exception does not however invalidate any other reasons why
end_comment

begin_comment
comment|// the executable file might be covered by the GNU General Public License.
end_comment

begin_comment
comment|// Written by Jason Merrill based upon the specification in the 27 May 1994
end_comment

begin_comment
comment|// C++ working paper, ANSI document X3J16/94-0098.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CINST__
end_ifndef

begin_define
define|#
directive|define
name|__CINST__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_G_NO_EXTERN_TEMPLATES
end_ifndef

begin_extern
extern|extern
literal|"C++"
block|{
extern|extern template class complex<float>;
extern|extern template class complex<double>;
extern|extern template class complex<long double>;
define|#
directive|define
name|__B
parameter_list|(
name|type
parameter_list|)
value|bool
define|#
directive|define
name|__C
parameter_list|(
name|type
parameter_list|)
value|complex<type>
define|#
directive|define
name|__F
parameter_list|(
name|type
parameter_list|)
value|type
define|#
directive|define
name|__I
parameter_list|(
name|type
parameter_list|)
value|int
define|#
directive|define
name|__IS
parameter_list|(
name|type
parameter_list|)
value|istream&
define|#
directive|define
name|__OS
parameter_list|(
name|type
parameter_list|)
value|ostream&
define|#
directive|define
name|__CR
parameter_list|(
name|type
parameter_list|)
value|complex<type>&
define|#
directive|define
name|__CCR
parameter_list|(
name|type
parameter_list|)
value|const complex<type>&
define|#
directive|define
name|__D2
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|ret
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
value|ret(type) name (arg1(type), arg2(type));
define|#
directive|define
name|__S1
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|ret
parameter_list|,
name|arg1
parameter_list|)
define|\
value|extern template ret(type) name (arg1(type));
define|#
directive|define
name|__S2
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|ret
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|extern template __D2 (name,type,ret,arg1,arg2)
define|#
directive|define
name|__DO1
parameter_list|(
name|name
parameter_list|,
name|ret
parameter_list|,
name|arg1
parameter_list|)
define|\
value|__S1(name,float,ret,arg1) \   __S1(name,double,ret,arg1) \   __S1(name,long double,ret,arg1)
define|#
directive|define
name|__DO2
parameter_list|(
name|name
parameter_list|,
name|ret
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|__S2(name,float,ret,arg1,arg2) \   __S2(name,double,ret,arg1,arg2) \   __S2(name,long double,ret,arg1,arg2)
define|#
directive|define
name|__DOCCC
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__C,__CCR,__CCR)
define|#
directive|define
name|__DOCCF
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__C,__CCR,__F)
define|#
directive|define
name|__DOCFC
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__C,__F,__CCR)
define|#
directive|define
name|__DOCFF
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__C,__F,__F)
define|#
directive|define
name|__DOBCC
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__B,__CCR,__CCR)
define|#
directive|define
name|__DOBCF
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__B,__CCR,__F)
define|#
directive|define
name|__DOBFC
parameter_list|(
name|name
parameter_list|)
value|__DO2(name,__B,__F,__CCR)
define|#
directive|define
name|__DOFC
parameter_list|(
name|name
parameter_list|)
value|__DO1(name,__F,__CCR)
define|#
directive|define
name|__DOCC
parameter_list|(
name|name
parameter_list|)
value|__DO1(name,__C,__CCR)
name|__DO2
argument_list|(
argument|operator+
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator+
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO2
argument_list|(
argument|operator+
argument_list|,
argument|__C
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator-
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator-
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO2
argument_list|(
argument|operator-
argument_list|,
argument|__C
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator*
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator*
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO2
argument_list|(
argument|operator*
argument_list|,
argument|__C
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator/
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO1
argument_list|(
argument|operator+
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|)
name|__DO1
argument_list|(
argument|operator-
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator==
argument_list|,
argument|__B
argument_list|,
argument|__CCR
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator==
argument_list|,
argument|__B
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO2
argument_list|(
argument|operator==
argument_list|,
argument|__B
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator!=
argument_list|,
argument|__B
argument_list|,
argument|__CCR
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|operator!=
argument_list|,
argument|__B
argument_list|,
argument|__CCR
argument_list|,
argument|__F
argument_list|)
name|__DO2
argument_list|(
argument|operator!=
argument_list|,
argument|__B
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO1
argument_list|(
argument|abs
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO1
argument_list|(
argument|arg
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
name|__DO2
argument_list|(
argument|polar
argument_list|,
argument|__C
argument_list|,
argument|__F
argument_list|,
argument|__F
argument_list|)
name|__DO1
argument_list|(
argument|conj
argument_list|,
argument|__C
argument_list|,
argument|__CCR
argument_list|)
name|__DO1
argument_list|(
argument|norm
argument_list|,
argument|__F
argument_list|,
argument|__CCR
argument_list|)
undef|#
directive|undef
name|__DO1
undef|#
directive|undef
name|__DO2
undef|#
directive|undef
name|__S1
undef|#
directive|undef
name|__S2
undef|#
directive|undef
name|__D2
undef|#
directive|undef
name|__B
undef|#
directive|undef
name|__C
undef|#
directive|undef
name|__F
undef|#
directive|undef
name|__I
undef|#
directive|undef
name|__IS
undef|#
directive|undef
name|__OS
undef|#
directive|undef
name|__CR
undef|#
directive|undef
name|__CCR
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

