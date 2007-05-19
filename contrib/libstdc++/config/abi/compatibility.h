begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Compatibility symbols for previous versions -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2005, 2006
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|/** @file compatibility.h  *  This is an internal header file, included by other library sources.  *  You should not attempt to use it directly.  */
end_comment

begin_comment
comment|// Switch for symbol version macro.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_APPLY_SYMVER
end_ifndef

begin_error
error|#
directive|error
error|must define _GLIBCXX_APPLY_SYMVER before including __FILE__
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gcc-3.4.4 _ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv _ZNSt19istreambuf_iteratorIwSt11char_traitsIwEEppEv  */
end_comment

begin_macro
name|namespace
end_macro

begin_block
block|{
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt21istreambuf_iteratorXXIcSt11char_traitsIcEEppEv
argument_list|,
argument|_ZNSt19istreambuf_iteratorIcSt11char_traitsIcEEppEv
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt21istreambuf_iteratorXXIwSt11char_traitsIwEEppEv
argument_list|,
argument|_ZNSt19istreambuf_iteratorIwSt11char_traitsIwEEppEv
argument_list|)
endif|#
directive|endif
block|}
end_block

begin_comment
comment|// anonymous namespace
end_comment

begin_comment
comment|/* gcc-4.0.0 _ZNSs4_Rep26_M_set_length_and_sharableEj _ZNSs7_M_copyEPcPKcj _ZNSs7_M_moveEPcPKcj _ZNSs9_M_assignEPcjc _ZNKSs11_M_disjunctEPKc _ZNKSs15_M_check_lengthEjjPKc _ZNSbIwSt11char_traitsIwESaIwEE4_Rep26_M_set_length_and_sharableEj _ZNSbIwSt11char_traitsIwESaIwEE7_M_copyEPwPKwj _ZNSbIwSt11char_traitsIwESaIwEE7_M_moveEPwPKwj _ZNSbIwSt11char_traitsIwESaIwEE9_M_assignEPwjw _ZNKSbIwSt11char_traitsIwESaIwEE11_M_disjunctEPKw _ZNKSbIwSt11char_traitsIwESaIwEE15_M_check_lengthEjjPKc  _ZNKSt13basic_fstreamIcSt11char_traitsIcEE7is_openEv _ZNKSt13basic_fstreamIwSt11char_traitsIwEE7is_openEv _ZNKSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv _ZNKSt14basic_ifstreamIwSt11char_traitsIwEE7is_openEv _ZNKSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv _ZNKSt14basic_ofstreamIwSt11char_traitsIwEE7is_openEv  _ZNSi6ignoreEi _ZNSi6ignoreEv _ZNSt13basic_istreamIwSt11char_traitsIwEE6ignoreEi _ZNSt13basic_istreamIwSt11char_traitsIwEE6ignoreEv  _ZNSt11char_traitsIcE2eqERKcS2_ _ZNSt11char_traitsIwE2eqERKwS2_  */
end_comment

begin_macro
name|namespace
end_macro

begin_block
block|{
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt11char_traitsIcE4eqXXERKcS2_
argument_list|,
argument|_ZNSt11char_traitsIcE2eqERKcS2_
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs9_M_copyXXEPcPKcj
argument_list|,
argument|_ZNSs7_M_copyEPcPKcj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs9_M_copyXXEPcPKcm
argument_list|,
argument|_ZNSs7_M_copyEPcPKcm
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs9_M_moveXXEPcPKcj
argument_list|,
argument|_ZNSs7_M_moveEPcPKcj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs9_M_moveXXEPcPKcm
argument_list|,
argument|_ZNSs7_M_moveEPcPKcm
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs11_M_assignXXEPcjc
argument_list|,
argument|_ZNSs9_M_assignEPcjc
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs11_M_assignXXEPcmc
argument_list|,
argument|_ZNSs9_M_assignEPcmc
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSs13_M_disjunctXXEPKc
argument_list|,
argument|_ZNKSs11_M_disjunctEPKc
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSs17_M_check_lengthXXEjjPKc
argument_list|,
argument|_ZNKSs15_M_check_lengthEjjPKc
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSs17_M_check_lengthXXEmmPKc
argument_list|,
argument|_ZNKSs15_M_check_lengthEmmPKc
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs4_Rep28_M_set_length_and_sharableXXEj
argument_list|,
argument|_ZNSs4_Rep26_M_set_length_and_sharableEj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSs4_Rep28_M_set_length_and_sharableXXEm
argument_list|,
argument|_ZNSs4_Rep26_M_set_length_and_sharableEm
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSi8ignoreXXEv
argument_list|,
argument|_ZNSi6ignoreEv
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_PTRDIFF_T_IS_INT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSi8ignoreXXEi
argument_list|,
argument|_ZNSi6ignoreEi
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSi8ignoreXXEl
argument_list|,
argument|_ZNSi6ignoreEl
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt15basic_fstreamXXIcSt11char_traitsIcEE7is_openEv
argument_list|,
argument|_ZNKSt13basic_fstreamIcSt11char_traitsIcEE7is_openEv
argument_list|)
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt16basic_ifstreamXXIcSt11char_traitsIcEE7is_openEv
argument_list|,
argument|_ZNKSt14basic_ifstreamIcSt11char_traitsIcEE7is_openEv
argument_list|)
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt16basic_ofstreamXXIcSt11char_traitsIcEE7is_openEv
argument_list|,
argument|_ZNKSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv
argument_list|)
comment|// Support for wchar_t.
ifdef|#
directive|ifdef
name|_GLIBCXX_USE_WCHAR_T
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt11char_traitsIwE4eqXXERKwS2_
argument_list|,
argument|_ZNSt11char_traitsIwE2eqERKwS2_
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_copyXXEPwPKwj
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE7_M_copyEPwPKwj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_copyXXEPwPKwm
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE7_M_copyEPwPKwm
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_moveXXEPwPKwj
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE7_M_moveEPwPKwj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_moveXXEPwPKwm
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE7_M_moveEPwPKwm
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE11_M_assignXXEPwjw
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_assignEPwjw
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE11_M_assignXXEPwmw
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE9_M_assignEPwmw
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSbIwSt11char_traitsIwESaIwEE13_M_disjunctXXEPKw
argument_list|,
argument|_ZNKSbIwSt11char_traitsIwESaIwEE11_M_disjunctEPKw
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSbIwSt11char_traitsIwESaIwEE17_M_check_lengthXXEjjPKc
argument_list|,
argument|_ZNKSbIwSt11char_traitsIwESaIwEE15_M_check_lengthEjjPKc
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSbIwSt11char_traitsIwESaIwEE17_M_check_lengthXXEmmPKc
argument_list|,
argument|_ZNKSbIwSt11char_traitsIwESaIwEE15_M_check_lengthEmmPKc
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_GLIBCXX_SIZE_T_IS_UINT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE4_Rep28_M_set_length_and_sharableXXEj
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE4_Rep26_M_set_length_and_sharableEj
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSbIwSt11char_traitsIwESaIwEE4_Rep28_M_set_length_and_sharableXXEm
argument_list|,
argument|_ZNSbIwSt11char_traitsIwESaIwEE4_Rep26_M_set_length_and_sharableEm
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE8ignoreXXEv
argument_list|,
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE6ignoreEv
argument_list|)
ifdef|#
directive|ifdef
name|_GLIBCXX_PTRDIFF_T_IS_INT
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE8ignoreXXEi
argument_list|,
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE6ignoreEi
argument_list|)
else|#
directive|else
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE8ignoreXXEl
argument_list|,
argument|_ZNSt13basic_istreamIwSt11char_traitsIwEE6ignoreEl
argument_list|)
endif|#
directive|endif
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt15basic_fstreamXXIwSt11char_traitsIwEE7is_openEv
argument_list|,
argument|_ZNKSt13basic_fstreamIwSt11char_traitsIwEE7is_openEv
argument_list|)
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt16basic_ifstreamXXIwSt11char_traitsIwEE7is_openEv
argument_list|,
argument|_ZNKSt14basic_ifstreamIwSt11char_traitsIwEE7is_openEv
argument_list|)
name|_GLIBCXX_APPLY_SYMVER
argument_list|(
argument|_ZNKSt16basic_ofstreamXXIwSt11char_traitsIwEE7is_openEv
argument_list|,
argument|_ZNKSt14basic_ofstreamIwSt11char_traitsIwEE7is_openEv
argument_list|)
endif|#
directive|endif
block|}
end_block

begin_comment
comment|// anonymous namespace
end_comment

end_unit

