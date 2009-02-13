begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// TR1 code repetition -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2005 Free Software Foundation, Inc.
end_comment

begin_comment
comment|// Written by Douglas Gregor<doug.gregor -at- gmail.com>
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
comment|/** @file tr1/repeat.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_REPEAT_HEADER
end_ifndef

begin_error
error|#
directive|error
error|Internal error: _GLIBCXX_REPEAT_HEADER must be set
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GLIBCXX_REPEAT_HEADER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_PARAMS
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8, typename _T9, typename _T10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_PARAMS_UNNAMED
value|typename, typename, typename, typename, typename, typename, typename, typename, typename, typename
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ALL_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|0
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T1
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T2
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T3
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T4
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T5
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T6
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5, _T6& __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5, __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4, _T5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4, __a5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5; _T6 _M_arg6;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5), _M_arg6(__a6)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple), ::std::tr1::get<5>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T6> _CV(_T6, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T6>()(_M_arg6, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5, typename __add_c_ref<_T6>::type __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5), _M_arg6(__in._M_arg6)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5; _M_arg6 = __in._M_arg6;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass, typename _T6 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type, typename __strip_reference_wrapper<_T6>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5, _U6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5), ref(__a6)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&, _T6&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T7
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5, _T6& __a6, _T7& __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4, _T5, _T6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4, __a5, __a6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5; _T6 _M_arg6; _T7 _M_arg7;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5), _M_arg6(__a6), _M_arg7(__a7)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple), ::std::tr1::get<5>(__tuple), ::std::tr1::get<6>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T6> _CV(_T6, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T7> _CV(_T7, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T6>()(_M_arg6, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T7>()(_M_arg7, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5, typename __add_c_ref<_T6>::type __a6, typename __add_c_ref<_T7>::type __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5), _M_arg6(__in._M_arg6), _M_arg7(__in._M_arg7)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5; _M_arg6 = __in._M_arg6; _M_arg7 = __in._M_arg7;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass, typename _T6 = _NullClass, typename _T7 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type, typename __strip_reference_wrapper<_T6>::__type, typename __strip_reference_wrapper<_T7>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5), ref(__a6), ref(__a7)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&, _T6&, _T7&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T8
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7, _T8 __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5, _T6& __a6, _T7& __a7, _T8& __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5; _T6 _M_arg6; _T7 _M_arg7; _T8 _M_arg8;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5), _M_arg6(__a6), _M_arg7(__a7), _M_arg8(__a8)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple), ::std::tr1::get<5>(__tuple), ::std::tr1::get<6>(__tuple), ::std::tr1::get<7>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T6> _CV(_T6, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T7> _CV(_T7, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T8> _CV(_T8, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T6>()(_M_arg6, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T7>()(_M_arg7, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T8>()(_M_arg8, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5, typename __add_c_ref<_T6>::type __a6, typename __add_c_ref<_T7>::type __a7, typename __add_c_ref<_T8>::type __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5), _M_arg6(__in._M_arg6), _M_arg7(__in._M_arg7), _M_arg8(__in._M_arg8)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5; _M_arg6 = __in._M_arg6; _M_arg7 = __in._M_arg7; _M_arg8 = __in._M_arg8;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass, typename _T6 = _NullClass, typename _T7 = _NullClass, typename _T8 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type, typename __strip_reference_wrapper<_T6>::__type, typename __strip_reference_wrapper<_T7>::__type, typename __strip_reference_wrapper<_T8>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5), ref(__a6), ref(__a7), ref(__a8)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&, _T6&, _T7&, _T8&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T9
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8, typename _T9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7, _T8 __a8, _T9 __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5, _T6& __a6, _T7& __a7, _T8& __a8, _T9& __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8, __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7, _T8 __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5; _T6 _M_arg6; _T7 _M_arg7; _T8 _M_arg8; _T9 _M_arg9;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5), _M_arg6(__a6), _M_arg7(__a7), _M_arg8(__a8), _M_arg9(__a9)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple), ::std::tr1::get<5>(__tuple), ::std::tr1::get<6>(__tuple), ::std::tr1::get<7>(__tuple), ::std::tr1::get<8>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T6> _CV(_T6, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T7> _CV(_T7, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T8> _CV(_T8, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T9> _CV(_T9, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T6>()(_M_arg6, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T7>()(_M_arg7, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T8>()(_M_arg8, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T9>()(_M_arg9, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5, typename __add_c_ref<_T6>::type __a6, typename __add_c_ref<_T7>::type __a7, typename __add_c_ref<_T8>::type __a8, typename __add_c_ref<_T9>::type __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5), _M_arg6(__in._M_arg6), _M_arg7(__in._M_arg7), _M_arg8(__in._M_arg8), _M_arg9(__in._M_arg9)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5; _M_arg6 = __in._M_arg6; _M_arg7 = __in._M_arg7; _M_arg8 = __in._M_arg8; _M_arg9 = __in._M_arg9;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass, typename _T6 = _NullClass, typename _T7 = _NullClass, typename _T8 = _NullClass, typename _T9 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type, typename __strip_reference_wrapper<_T6>::__type, typename __strip_reference_wrapper<_T7>::__type, typename __strip_reference_wrapper<_T8>::__type, typename __strip_reference_wrapper<_T9>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8, typename _U9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8, _U9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5), ref(__a6), ref(__a7), ref(__a8), ref(__a9)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&, _T6&, _T7&, _T8&, _T9&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T10
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_LAST_INCLUDE
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS
value|10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8, typename _T9, typename _T10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7, _T8 __a8, _T9 __a9, _T10 __a10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_PARAMS
value|_T1& __a1, _T2& __a2, _T3& __a3, _T4& __a4, _T5& __a5, _T6& __a6, _T7& __a7, _T8& __a8, _T9& __a9, _T10& __a10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8, __a9, __a10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_COMMA_SHIFTED
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
value|typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8, typename _T9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
value|_T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_PARAMS_SHIFTED
value|_T1 __a1, _T2 __a2, _T3 __a3, _T4 __a4, _T5 __a5, _T6 __a6, _T7 __a7, _T8 __a8, _T9 __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_ARGS_SHIFTED
value|__a1, __a2, __a3, __a4, __a5, __a6, __a7, __a8, __a9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS
value|_T1 _M_arg1; _T2 _M_arg2; _T3 _M_arg3; _T4 _M_arg4; _T5 _M_arg5; _T6 _M_arg6; _T7 _M_arg7; _T8 _M_arg8; _T9 _M_arg9; _T10 _M_arg10;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_MEMBERS_INIT
value|_M_arg1(__a1), _M_arg2(__a2), _M_arg3(__a3), _M_arg4(__a4), _M_arg5(__a5), _M_arg6(__a6), _M_arg7(__a7), _M_arg8(__a8), _M_arg9(__a9), _M_arg10(__a10)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_MU_GET_TUPLE_ARGS
value|::std::tr1::get<0>(__tuple), ::std::tr1::get<1>(__tuple), ::std::tr1::get<2>(__tuple), ::std::tr1::get<3>(__tuple), ::std::tr1::get<4>(__tuple), ::std::tr1::get<5>(__tuple), ::std::tr1::get<6>(__tuple), ::std::tr1::get<7>(__tuple), ::std::tr1::get<8>(__tuple), ::std::tr1::get<9>(__tuple)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
parameter_list|(
name|_CV
parameter_list|)
value|typename result_of<_Mu<_T1> _CV(_T1, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T2> _CV(_T2, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T3> _CV(_T3, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T4> _CV(_T4, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T5> _CV(_T5, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T6> _CV(_T6, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T7> _CV(_T7, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T8> _CV(_T8, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T9> _CV(_T9, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type, typename result_of<_Mu<_T10> _CV(_T10, tuple<_GLIBCXX_BIND_TEMPLATE_ARGS>)>::type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_V_ARGS
value|_Mu<_T1>()(_M_arg1, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T2>()(_M_arg2, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T3>()(_M_arg3, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T4>()(_M_arg4, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T5>()(_M_arg5, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T6>()(_M_arg6, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T7>()(_M_arg7, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T8>()(_M_arg8, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T9>()(_M_arg9, ::std::tr1::tie(_GLIBCXX_BIND_ARGS)), _Mu<_T10>()(_M_arg10, ::std::tr1::tie(_GLIBCXX_BIND_ARGS))
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ADD_CREF
value|typename __add_c_ref<_T1>::type __a1, typename __add_c_ref<_T2>::type __a2, typename __add_c_ref<_T3>::type __a3, typename __add_c_ref<_T4>::type __a4, typename __add_c_ref<_T5>::type __a5, typename __add_c_ref<_T6>::type __a6, typename __add_c_ref<_T7>::type __a7, typename __add_c_ref<_T8>::type __a8, typename __add_c_ref<_T9>::type __a9, typename __add_c_ref<_T10>::type __a10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_COPY_INIT
value|_M_arg1(__in._M_arg1), _M_arg2(__in._M_arg2), _M_arg3(__in._M_arg3), _M_arg4(__in._M_arg4), _M_arg5(__in._M_arg5), _M_arg6(__in._M_arg6), _M_arg7(__in._M_arg7), _M_arg8(__in._M_arg8), _M_arg9(__in._M_arg9), _M_arg10(__in._M_arg10)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TUPLE_ASSIGN
value|_M_arg1 = __in._M_arg1; _M_arg2 = __in._M_arg2; _M_arg3 = __in._M_arg3; _M_arg4 = __in._M_arg4; _M_arg5 = __in._M_arg5; _M_arg6 = __in._M_arg6; _M_arg7 = __in._M_arg7; _M_arg8 = __in._M_arg8; _M_arg9 = __in._M_arg9; _M_arg10 = __in._M_arg10;
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
value|typename _T1 = _NullClass, typename _T2 = _NullClass, typename _T3 = _NullClass, typename _T4 = _NullClass, typename _T5 = _NullClass, typename _T6 = _NullClass, typename _T7 = _NullClass, typename _T8 = _NullClass, typename _T9 = _NullClass, typename _T10 = _NullClass
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
value|typename __strip_reference_wrapper<_T1>::__type, typename __strip_reference_wrapper<_T2>::__type, typename __strip_reference_wrapper<_T3>::__type, typename __strip_reference_wrapper<_T4>::__type, typename __strip_reference_wrapper<_T5>::__type, typename __strip_reference_wrapper<_T6>::__type, typename __strip_reference_wrapper<_T7>::__type, typename __strip_reference_wrapper<_T8>::__type, typename __strip_reference_wrapper<_T9>::__type, typename __strip_reference_wrapper<_T10>::__type
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_PARAMS_U
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8, typename _U9, typename _U10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_TEMPLATE_ARGS_U
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8, _U9, _U10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_WRAP_PARAMS
value|ref(__a1), ref(__a2), ref(__a3), ref(__a4), ref(__a5), ref(__a6), ref(__a7), ref(__a8), ref(__a9), ref(__a10)
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_REF_TEMPLATE_ARGS
value|_T1&, _T2&, _T3&, _T4&, _T5&, _T6&, _T7&, _T8&, _T9&, _T10&
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_NUM_ARGS_PLUS_1
value|11
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
value|_T11
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_T_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS_PLUS_1
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_WRAP_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_U
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_STRIPPED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_NULL_CLASS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_COPY_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TUPLE_ADD_CREF
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_V_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_MU_GET_TUPLE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS_INIT
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_MEMBERS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA_SHIFTED
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_REF_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_NUM_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_LAST_INCLUDE
end_undef

end_unit

