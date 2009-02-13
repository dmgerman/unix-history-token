begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Locale support (codecvt) -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006
end_comment

begin_comment
comment|//  Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
comment|// ISO C++ 14882: 22.2.1.5 Template class codecvt
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Written by Benjamin Kosnik<bkoz@redhat.com>
end_comment

begin_comment
comment|/** @file ext/codecvt_specializations.h  *  This file is a GNU extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXT_CODECVT_SPECIALIZATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|_EXT_CODECVT_SPECIALIZATIONS_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_ICONV
end_ifdef

begin_include
include|#
directive|include
file|<locale>
end_include

begin_include
include|#
directive|include
file|<iconv.h>
end_include

begin_comment
comment|// XXX
end_comment

begin_comment
comment|// Define this here so codecvt.cc can have _S_max_size definition.
end_comment

begin_define
define|#
directive|define
name|_GLIBCXX_USE_ENCODING_STATE
value|1
end_define

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_comment
comment|/// @brief  Extension to use icov for dealing with character encodings.
end_comment

begin_comment
comment|// This includes conversions and comparisons between various character
end_comment

begin_comment
comment|// sets.  This object encapsulates data that may need to be shared between
end_comment

begin_comment
comment|// char_traits, codecvt and ctype.
end_comment

begin_decl_stmt
name|class
name|encoding_state
block|{
name|public
label|:
comment|// Types:
comment|// NB: A conversion descriptor subsumes and enhances the
comment|// functionality of a simple state type such as mbstate_t.
typedef|typedef
name|iconv_t
name|descriptor_type
typedef|;
name|protected
label|:
comment|// Name of internal character set encoding.
name|std
operator|::
name|string
name|_M_int_enc
expr_stmt|;
comment|// Name of external character set encoding.
name|std
operator|::
name|string
name|_M_ext_enc
expr_stmt|;
comment|// Conversion descriptor between external encoding to internal encoding.
name|descriptor_type
name|_M_in_desc
decl_stmt|;
comment|// Conversion descriptor between internal encoding to external encoding.
name|descriptor_type
name|_M_out_desc
decl_stmt|;
comment|// The byte-order marker for the external encoding, if necessary.
name|int
name|_M_ext_bom
decl_stmt|;
comment|// The byte-order marker for the internal encoding, if necessary.
name|int
name|_M_int_bom
decl_stmt|;
comment|// Number of external bytes needed to construct one complete
comment|// character in the internal encoding.
comment|// NB: -1 indicates variable, or stateful, encodings.
name|int
name|_M_bytes
decl_stmt|;
name|public
label|:
name|explicit
name|encoding_state
argument_list|()
operator|:
name|_M_in_desc
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_out_desc
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_ext_bom
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_int_bom
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_bytes
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|encoding_state
argument_list|(
argument|const char* __int
argument_list|,
argument|const char* __ext
argument_list|,
argument|int __ibom =
literal|0
argument_list|,
argument|int __ebom =
literal|0
argument_list|,
argument|int __bytes =
literal|1
argument_list|)
operator|:
name|_M_int_enc
argument_list|(
name|__int
argument_list|)
operator|,
name|_M_ext_enc
argument_list|(
name|__ext
argument_list|)
operator|,
name|_M_in_desc
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_out_desc
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_ext_bom
argument_list|(
name|__ebom
argument_list|)
operator|,
name|_M_int_bom
argument_list|(
name|__ibom
argument_list|)
operator|,
name|_M_bytes
argument_list|(
argument|__bytes
argument_list|)
block|{
name|init
argument_list|()
block|; }
comment|// 21.1.2 traits typedefs
comment|// p4
comment|// typedef STATE_T state_type
comment|// requires: state_type shall meet the requirements of
comment|// CopyConstructible types (20.1.3)
comment|// NB: This does not preseve the actual state of the conversion
comment|// descriptor member, but it does duplicate the encoding
comment|// information.
name|encoding_state
argument_list|(
specifier|const
name|encoding_state
operator|&
name|__obj
argument_list|)
operator|:
name|_M_in_desc
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_out_desc
argument_list|(
literal|0
argument_list|)
block|{
name|construct
argument_list|(
name|__obj
argument_list|)
block|; }
comment|// Need assignment operator as well.
name|encoding_state
operator|&
name|operator
operator|=
operator|(
specifier|const
name|encoding_state
operator|&
name|__obj
operator|)
block|{
name|construct
argument_list|(
name|__obj
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|encoding_state
argument_list|()
block|{
name|destroy
argument_list|()
block|; }
name|bool
name|good
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
specifier|const
name|descriptor_type
name|__err
operator|=
name|reinterpret_cast
operator|<
name|iconv_t
operator|>
operator|(
operator|-
literal|1
operator|)
block|;
name|bool
name|__test
operator|=
name|_M_in_desc
operator|&&
name|_M_in_desc
operator|!=
name|__err
block|;
name|__test
operator|&=
name|_M_out_desc
operator|&&
name|_M_out_desc
operator|!=
name|__err
block|;
return|return
name|__test
return|;
block|}
name|int
name|character_ratio
argument_list|()
specifier|const
block|{
return|return
name|_M_bytes
return|;
block|}
specifier|const
name|std
operator|::
name|string
name|internal_encoding
argument_list|()
specifier|const
block|{
return|return
name|_M_int_enc
return|;
block|}
name|int
name|internal_bom
argument_list|()
specifier|const
block|{
return|return
name|_M_int_bom
return|;
block|}
specifier|const
name|std
operator|::
name|string
name|external_encoding
argument_list|()
specifier|const
block|{
return|return
name|_M_ext_enc
return|;
block|}
name|int
name|external_bom
argument_list|()
specifier|const
block|{
return|return
name|_M_ext_bom
return|;
block|}
specifier|const
name|descriptor_type
operator|&
name|in_descriptor
argument_list|()
specifier|const
block|{
return|return
name|_M_in_desc
return|;
block|}
specifier|const
name|descriptor_type
operator|&
name|out_descriptor
argument_list|()
specifier|const
block|{
return|return
name|_M_out_desc
return|;
block|}
name|protected
label|:
name|void
name|init
parameter_list|()
block|{
specifier|const
name|descriptor_type
name|__err
init|=
name|reinterpret_cast
operator|<
name|iconv_t
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
specifier|const
name|bool
name|__have_encodings
init|=
name|_M_int_enc
operator|.
name|size
argument_list|()
operator|&&
name|_M_ext_enc
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|_M_in_desc
operator|&&
name|__have_encodings
condition|)
block|{
name|_M_in_desc
operator|=
name|iconv_open
argument_list|(
name|_M_int_enc
operator|.
name|c_str
argument_list|()
argument_list|,
name|_M_ext_enc
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|_M_in_desc
operator|==
name|__err
condition|)
name|std
operator|::
name|__throw_runtime_error
argument_list|(
name|__N
argument_list|(
literal|"encoding_state::_M_init "
literal|"creating iconv input descriptor failed"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|_M_out_desc
operator|&&
name|__have_encodings
condition|)
block|{
name|_M_out_desc
operator|=
name|iconv_open
argument_list|(
name|_M_ext_enc
operator|.
name|c_str
argument_list|()
argument_list|,
name|_M_int_enc
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|_M_out_desc
operator|==
name|__err
condition|)
name|std
operator|::
name|__throw_runtime_error
argument_list|(
name|__N
argument_list|(
literal|"encoding_state::_M_init "
literal|"creating iconv output descriptor failed"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|construct
parameter_list|(
specifier|const
name|encoding_state
modifier|&
name|__obj
parameter_list|)
block|{
name|destroy
argument_list|()
expr_stmt|;
name|_M_int_enc
operator|=
name|__obj
operator|.
name|_M_int_enc
expr_stmt|;
name|_M_ext_enc
operator|=
name|__obj
operator|.
name|_M_ext_enc
expr_stmt|;
name|_M_ext_bom
operator|=
name|__obj
operator|.
name|_M_ext_bom
expr_stmt|;
name|_M_int_bom
operator|=
name|__obj
operator|.
name|_M_int_bom
expr_stmt|;
name|_M_bytes
operator|=
name|__obj
operator|.
name|_M_bytes
expr_stmt|;
name|init
argument_list|()
expr_stmt|;
block|}
name|void
name|destroy
parameter_list|()
function|throw
parameter_list|()
block|{
specifier|const
name|descriptor_type
name|__err
init|=
name|reinterpret_cast
operator|<
name|iconv_t
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
if|if
condition|(
name|_M_in_desc
operator|&&
name|_M_in_desc
operator|!=
name|__err
condition|)
block|{
name|iconv_close
argument_list|(
name|_M_in_desc
argument_list|)
expr_stmt|;
name|_M_in_desc
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|_M_out_desc
operator|&&
name|_M_out_desc
operator|!=
name|__err
condition|)
block|{
name|iconv_close
argument_list|(
name|_M_out_desc
argument_list|)
expr_stmt|;
name|_M_out_desc
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief  encoding_char_traits.
end_comment

begin_comment
comment|// Custom traits type with encoding_state for the state type, and the
end_comment

begin_comment
comment|// associated fpos<encoding_state> for the position type, all other
end_comment

begin_comment
comment|// bits equivalent to the required char_traits instantiations.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
expr|struct
name|encoding_char_traits
operator|:
name|public
name|std
operator|::
name|char_traits
operator|<
name|_CharT
operator|>
block|{
typedef|typedef
name|encoding_state
name|state_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|fpos
operator|<
name|state_type
operator|>
name|pos_type
expr_stmt|;
end_typedef

begin_decl_stmt
unit|};
name|_GLIBCXX_END_NAMESPACE
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
name|using
name|__gnu_cxx
decl|::
name|encoding_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief  codecvt<InternT, _ExternT, encoding_state> specialization.
end_comment

begin_comment
comment|// This partial specialization takes advantage of iconv to provide
end_comment

begin_comment
comment|// code conversions between a large number of character encodings.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|class
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|:
name|public
name|__codecvt_abstract_base
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
block|{
name|public
operator|:
comment|// Types:
typedef|typedef
name|codecvt_base
operator|::
name|result
name|result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_InternT
name|intern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_ExternT
name|extern_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|encoding_state
name|state_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|state_type
operator|::
name|descriptor_type
name|descriptor_type
expr_stmt|;
end_typedef

begin_comment
comment|// Data Members:
end_comment

begin_expr_stmt
specifier|static
name|locale
operator|::
name|id
name|id
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|codecvt
argument_list|(
argument|size_t __refs =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|__codecvt_abstract_base
operator|<
name|intern_type
operator|,
name|extern_type
operator|,
name|state_type
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|explicit
name|codecvt
argument_list|(
argument|state_type& __enc
argument_list|,
argument|size_t __refs =
literal|0
argument_list|)
operator|:
name|__codecvt_abstract_base
operator|<
name|intern_type
operator|,
name|extern_type
operator|,
name|state_type
operator|>
operator|(
name|__refs
operator|)
block|{ }
name|protected
operator|:
name|virtual
operator|~
name|codecvt
argument_list|()
block|{ }
name|virtual
name|result
name|do_out
argument_list|(
argument|state_type& __state
argument_list|,
argument|const intern_type* __from
argument_list|,
argument|const intern_type* __from_end
argument_list|,
argument|const intern_type*& __from_next
argument_list|,
argument|extern_type* __to
argument_list|,
argument|extern_type* __to_end
argument_list|,
argument|extern_type*& __to_next
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|result
name|do_unshift
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
name|extern_type
operator|*
name|__to
argument_list|,
name|extern_type
operator|*
name|__to_end
argument_list|,
name|extern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|result
name|do_in
argument_list|(
name|state_type
operator|&
name|__state
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from_end
argument_list|,
specifier|const
name|extern_type
operator|*
operator|&
name|__from_next
argument_list|,
name|intern_type
operator|*
name|__to
argument_list|,
name|intern_type
operator|*
name|__to_end
argument_list|,
name|intern_type
operator|*
operator|&
name|__to_next
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|bool
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|int
name|do_length
argument_list|(
name|state_type
operator|&
argument_list|,
specifier|const
name|extern_type
operator|*
name|__from
argument_list|,
specifier|const
name|extern_type
operator|*
name|__end
argument_list|,
name|size_t
name|__max
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|int
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|locale
operator|::
name|id
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|id
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This adaptor works around the signature problems of the second
end_comment

begin_comment
comment|// argument to iconv():  SUSv2 and others use 'const char**', but glibc 2.2
end_comment

begin_comment
comment|// uses 'char**', which matches the POSIX 1003.1-2001 standard.
end_comment

begin_comment
comment|// Using this adaptor, g++ will do the work for us.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|size_t
name|__iconv_adaptor
argument_list|(
argument|size_t(*__func)(iconv_t, _Tp, size_t*, char**, size_t*)
argument_list|,
argument|iconv_t __cd
argument_list|,
argument|char** __inbuf
argument_list|,
argument|size_t* __inbytes
argument_list|,
argument|char** __outbuf
argument_list|,
argument|size_t* __outbytes
argument_list|)
block|{
return|return
name|__func
argument_list|(
name|__cd
argument_list|,
operator|(
name|_Tp
operator|)
name|__inbuf
argument_list|,
name|__inbytes
argument_list|,
name|__outbuf
argument_list|,
name|__outbytes
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|codecvt_base
operator|::
name|result
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_out
argument_list|(
argument|state_type& __state
argument_list|,
argument|const intern_type* __from
argument_list|,
argument|const intern_type* __from_end
argument_list|,
argument|const intern_type*& __from_next
argument_list|,
argument|extern_type* __to
argument_list|,
argument|extern_type* __to_end
argument_list|,
argument|extern_type*& __to_next
argument_list|)
specifier|const
block|{
name|result
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
block|;
if|if
condition|(
name|__state
operator|.
name|good
argument_list|()
condition|)
block|{
specifier|const
name|descriptor_type
modifier|&
name|__desc
init|=
name|__state
operator|.
name|out_descriptor
argument_list|()
decl_stmt|;
specifier|const
name|size_t
name|__fmultiple
init|=
sizeof|sizeof
argument_list|(
name|intern_type
argument_list|)
decl_stmt|;
name|size_t
name|__fbytes
init|=
name|__fmultiple
operator|*
operator|(
name|__from_end
operator|-
name|__from
operator|)
decl_stmt|;
specifier|const
name|size_t
name|__tmultiple
init|=
sizeof|sizeof
argument_list|(
name|extern_type
argument_list|)
decl_stmt|;
name|size_t
name|__tbytes
init|=
name|__tmultiple
operator|*
operator|(
name|__to_end
operator|-
name|__to
operator|)
decl_stmt|;
comment|// Argument list for iconv specifies a byte sequence. Thus,
comment|// all to/from arrays must be brutally casted to char*.
name|char
modifier|*
name|__cto
init|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__to
operator|)
decl_stmt|;
name|char
modifier|*
name|__cfrom
decl_stmt|;
name|size_t
name|__conv
decl_stmt|;
comment|// Some encodings need a byte order marker as the first item
comment|// in the byte stream, to designate endian-ness. The default
comment|// value for the byte order marker is NULL, so if this is
comment|// the case, it's not necessary and we can just go on our
comment|// merry way.
name|int
name|__int_bom
init|=
name|__state
operator|.
name|internal_bom
argument_list|()
decl_stmt|;
if|if
condition|(
name|__int_bom
condition|)
block|{
name|size_t
name|__size
init|=
name|__from_end
operator|-
name|__from
decl_stmt|;
name|intern_type
modifier|*
name|__cfixed
init|=
name|static_cast
operator|<
name|intern_type
operator|*
operator|>
operator|(
name|__builtin_alloca
argument_list|(
sizeof|sizeof
argument_list|(
name|intern_type
argument_list|)
operator|*
operator|(
name|__size
operator|+
literal|1
operator|)
argument_list|)
operator|)
decl_stmt|;
name|__cfixed
index|[
literal|0
index|]
operator|=
name|static_cast
operator|<
name|intern_type
operator|>
operator|(
name|__int_bom
operator|)
expr_stmt|;
name|char_traits
operator|<
name|intern_type
operator|>
operator|::
name|copy
argument_list|(
name|__cfixed
operator|+
literal|1
argument_list|,
name|__from
argument_list|,
name|__size
argument_list|)
expr_stmt|;
name|__cfrom
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__cfixed
operator|)
expr_stmt|;
name|__conv
operator|=
name|__iconv_adaptor
argument_list|(
name|iconv
argument_list|,
name|__desc
argument_list|,
operator|&
name|__cfrom
argument_list|,
operator|&
name|__fbytes
argument_list|,
operator|&
name|__cto
argument_list|,
operator|&
name|__tbytes
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|intern_type
modifier|*
name|__cfixed
init|=
name|const_cast
operator|<
name|intern_type
operator|*
operator|>
operator|(
name|__from
operator|)
decl_stmt|;
name|__cfrom
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__cfixed
operator|)
expr_stmt|;
name|__conv
operator|=
name|__iconv_adaptor
argument_list|(
name|iconv
argument_list|,
name|__desc
argument_list|,
operator|&
name|__cfrom
argument_list|,
operator|&
name|__fbytes
argument_list|,
operator|&
name|__cto
argument_list|,
operator|&
name|__tbytes
argument_list|)
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|__conv
operator|!=
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|__from_next
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|intern_type
operator|*
operator|>
operator|(
name|__cfrom
operator|)
expr_stmt|;
name|__to_next
operator|=
name|reinterpret_cast
operator|<
name|extern_type
operator|*
operator|>
operator|(
name|__cto
operator|)
expr_stmt|;
name|__ret
operator|=
name|codecvt_base
operator|::
name|ok
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|__fbytes
operator|<
name|__fmultiple
operator|*
operator|(
name|__from_end
operator|-
name|__from
operator|)
condition|)
block|{
name|__from_next
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|intern_type
operator|*
operator|>
operator|(
name|__cfrom
operator|)
expr_stmt|;
name|__to_next
operator|=
name|reinterpret_cast
operator|<
name|extern_type
operator|*
operator|>
operator|(
name|__cto
operator|)
expr_stmt|;
name|__ret
operator|=
name|codecvt_base
operator|::
name|partial
expr_stmt|;
block|}
else|else
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|}       return
name|__ret
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|codecvt_base
operator|::
name|result
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_unshift
argument_list|(
argument|state_type& __state
argument_list|,
argument|extern_type* __to
argument_list|,
argument|extern_type* __to_end
argument_list|,
argument|extern_type*& __to_next
argument_list|)
specifier|const
block|{
name|result
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
block|;
if|if
condition|(
name|__state
operator|.
name|good
argument_list|()
condition|)
block|{
specifier|const
name|descriptor_type
modifier|&
name|__desc
init|=
name|__state
operator|.
name|in_descriptor
argument_list|()
decl_stmt|;
specifier|const
name|size_t
name|__tmultiple
init|=
sizeof|sizeof
argument_list|(
name|intern_type
argument_list|)
decl_stmt|;
name|size_t
name|__tlen
init|=
name|__tmultiple
operator|*
operator|(
name|__to_end
operator|-
name|__to
operator|)
decl_stmt|;
comment|// Argument list for iconv specifies a byte sequence. Thus,
comment|// all to/from arrays must be brutally casted to char*.
name|char
modifier|*
name|__cto
init|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__to
operator|)
decl_stmt|;
name|size_t
name|__conv
init|=
name|__iconv_adaptor
argument_list|(
name|iconv
argument_list|,
name|__desc
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|__cto
argument_list|,
operator|&
name|__tlen
argument_list|)
decl_stmt|;
if|if
condition|(
name|__conv
operator|!=
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|__to_next
operator|=
name|reinterpret_cast
operator|<
name|extern_type
operator|*
operator|>
operator|(
name|__cto
operator|)
expr_stmt|;
if|if
condition|(
name|__tlen
operator|==
name|__tmultiple
operator|*
operator|(
name|__to_end
operator|-
name|__to
operator|)
condition|)
name|__ret
operator|=
name|codecvt_base
operator|::
name|noconv
expr_stmt|;
elseif|else
if|if
condition|(
name|__tlen
operator|==
literal|0
condition|)
name|__ret
operator|=
name|codecvt_base
operator|::
name|ok
expr_stmt|;
else|else
name|__ret
operator|=
name|codecvt_base
operator|::
name|partial
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
expr_stmt|;
end_else

begin_expr_stmt
unit|}       return
name|__ret
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}       template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|codecvt_base
operator|::
name|result
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_in
argument_list|(
argument|state_type& __state
argument_list|,
argument|const extern_type* __from
argument_list|,
argument|const extern_type* __from_end
argument_list|,
argument|const extern_type*& __from_next
argument_list|,
argument|intern_type* __to
argument_list|,
argument|intern_type* __to_end
argument_list|,
argument|intern_type*& __to_next
argument_list|)
specifier|const
block|{
name|result
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
block|;
if|if
condition|(
name|__state
operator|.
name|good
argument_list|()
condition|)
block|{
specifier|const
name|descriptor_type
modifier|&
name|__desc
init|=
name|__state
operator|.
name|in_descriptor
argument_list|()
decl_stmt|;
specifier|const
name|size_t
name|__fmultiple
init|=
sizeof|sizeof
argument_list|(
name|extern_type
argument_list|)
decl_stmt|;
name|size_t
name|__flen
init|=
name|__fmultiple
operator|*
operator|(
name|__from_end
operator|-
name|__from
operator|)
decl_stmt|;
specifier|const
name|size_t
name|__tmultiple
init|=
sizeof|sizeof
argument_list|(
name|intern_type
argument_list|)
decl_stmt|;
name|size_t
name|__tlen
init|=
name|__tmultiple
operator|*
operator|(
name|__to_end
operator|-
name|__to
operator|)
decl_stmt|;
comment|// Argument list for iconv specifies a byte sequence. Thus,
comment|// all to/from arrays must be brutally casted to char*.
name|char
modifier|*
name|__cto
init|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__to
operator|)
decl_stmt|;
name|char
modifier|*
name|__cfrom
decl_stmt|;
name|size_t
name|__conv
decl_stmt|;
comment|// Some encodings need a byte order marker as the first item
comment|// in the byte stream, to designate endian-ness. The default
comment|// value for the byte order marker is NULL, so if this is
comment|// the case, it's not necessary and we can just go on our
comment|// merry way.
name|int
name|__ext_bom
init|=
name|__state
operator|.
name|external_bom
argument_list|()
decl_stmt|;
if|if
condition|(
name|__ext_bom
condition|)
block|{
name|size_t
name|__size
init|=
name|__from_end
operator|-
name|__from
decl_stmt|;
name|extern_type
modifier|*
name|__cfixed
init|=
name|static_cast
operator|<
name|extern_type
operator|*
operator|>
operator|(
name|__builtin_alloca
argument_list|(
sizeof|sizeof
argument_list|(
name|extern_type
argument_list|)
operator|*
operator|(
name|__size
operator|+
literal|1
operator|)
argument_list|)
operator|)
decl_stmt|;
name|__cfixed
index|[
literal|0
index|]
operator|=
name|static_cast
operator|<
name|extern_type
operator|>
operator|(
name|__ext_bom
operator|)
expr_stmt|;
name|char_traits
operator|<
name|extern_type
operator|>
operator|::
name|copy
argument_list|(
name|__cfixed
operator|+
literal|1
argument_list|,
name|__from
argument_list|,
name|__size
argument_list|)
expr_stmt|;
name|__cfrom
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__cfixed
operator|)
expr_stmt|;
name|__conv
operator|=
name|__iconv_adaptor
argument_list|(
name|iconv
argument_list|,
name|__desc
argument_list|,
operator|&
name|__cfrom
argument_list|,
operator|&
name|__flen
argument_list|,
operator|&
name|__cto
argument_list|,
operator|&
name|__tlen
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|extern_type
modifier|*
name|__cfixed
init|=
name|const_cast
operator|<
name|extern_type
operator|*
operator|>
operator|(
name|__from
operator|)
decl_stmt|;
name|__cfrom
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__cfixed
operator|)
expr_stmt|;
name|__conv
operator|=
name|__iconv_adaptor
argument_list|(
name|iconv
argument_list|,
name|__desc
argument_list|,
operator|&
name|__cfrom
argument_list|,
operator|&
name|__flen
argument_list|,
operator|&
name|__cto
argument_list|,
operator|&
name|__tlen
argument_list|)
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|__conv
operator|!=
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
name|__from_next
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|extern_type
operator|*
operator|>
operator|(
name|__cfrom
operator|)
expr_stmt|;
name|__to_next
operator|=
name|reinterpret_cast
operator|<
name|intern_type
operator|*
operator|>
operator|(
name|__cto
operator|)
expr_stmt|;
name|__ret
operator|=
name|codecvt_base
operator|::
name|ok
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|__flen
operator|<
name|static_cast
operator|<
name|size_t
operator|>
operator|(
name|__from_end
operator|-
name|__from
operator|)
condition|)
block|{
name|__from_next
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|extern_type
operator|*
operator|>
operator|(
name|__cfrom
operator|)
expr_stmt|;
name|__to_next
operator|=
name|reinterpret_cast
operator|<
name|intern_type
operator|*
operator|>
operator|(
name|__cto
operator|)
expr_stmt|;
name|__ret
operator|=
name|codecvt_base
operator|::
name|partial
expr_stmt|;
block|}
else|else
name|__ret
operator|=
name|codecvt_base
operator|::
name|error
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|}       return
name|__ret
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|int
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_encoding
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
name|int
name|__ret
operator|=
literal|0
block|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|_ExternT
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|_InternT
argument_list|)
condition|)
name|__ret
operator|=
sizeof|sizeof
argument_list|(
name|_InternT
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_ExternT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__ret
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|bool
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_always_noconv
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|int
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_length
argument_list|(
argument|state_type&
argument_list|,
argument|const extern_type* __from
argument_list|,
argument|const extern_type* __end
argument_list|,
argument|size_t __max
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|min
argument_list|(
name|__max
argument_list|,
name|static_cast
operator|<
name|size_t
operator|>
operator|(
name|__end
operator|-
name|__from
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 74.  Garbled text for codecvt::do_max_length
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InternT
operator|,
name|typename
name|_ExternT
operator|>
name|int
name|codecvt
operator|<
name|_InternT
operator|,
name|_ExternT
operator|,
name|encoding_state
operator|>
operator|::
name|do_max_length
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
literal|1
return|;
block|}
end_expr_stmt

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

