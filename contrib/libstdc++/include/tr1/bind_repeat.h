begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// TR1 code repetition for bind -*- C++ -*-
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
comment|/** @file tr1/bind_repeat.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_BIND_REPEAT_HEADER
end_ifndef

begin_error
error|#
directive|error
error|Internal error: _GLIBCXX_BIND_REPEAT_HEADER must be set
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GLIBCXX_BIND_REPEAT_HEADER */
end_comment

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|0
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5, _U6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5, _U6& __u6
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5, __u6
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5, _U6& __u6, _U7& __u7
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5, __u6, __u7
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5, _U6& __u6, _U7& __u7, _U8& __u8
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5, __u6, __u7, __u8
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8, typename _U9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8, _U9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5, _U6& __u6, _U7& __u7, _U8& __u8, _U9& __u9
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5, __u6, __u7, __u8, __u9
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_NUM_ARGS
value|10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
value|typename _U1, typename _U2, typename _U3, typename _U4, typename _U5, typename _U6, typename _U7, typename _U8, typename _U9, typename _U10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_TEMPLATE_ARGS
value|_U1, _U2, _U3, _U4, _U5, _U6, _U7, _U8, _U9, _U10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_PARAMS
value|_U1& __u1, _U2& __u2, _U3& __u3, _U4& __u4, _U5& __u5, _U6& __u6, _U7& __u7, _U8& __u8, _U9& __u9, _U10& __u10
end_define

begin_define
define|#
directive|define
name|_GLIBCXX_BIND_ARGS
value|__u1, __u2, __u3, __u4, __u5, __u6, __u7, __u8, __u9, __u10
end_define

begin_include
include|#
directive|include
include|_GLIBCXX_BIND_REPEAT_HEADER
end_include

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_ARGS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_TEMPLATE_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_COMMA
end_undef

begin_undef
undef|#
directive|undef
name|_GLIBCXX_BIND_NUM_ARGS
end_undef

end_unit

