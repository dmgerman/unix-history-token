begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Debugging support implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2005, 2006
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
comment|/** @file debug/macros.h  *  This file is a GNU debug extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEBUG_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_MACROS_H
value|1
end_define

begin_comment
comment|/**  * Macros used by the implementation to verify certain  * properties. These macros may only be used directly by the debug  * wrappers. Note that these are macros (instead of the more obviously  * "correct" choice of making them functions) because we need line and  * file information at the call site, to minimize the distance between  * the user error and where the error is reported.  *  */
end_comment

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_VERIFY
parameter_list|(
name|_Condition
parameter_list|,
name|_ErrorMessage
parameter_list|)
define|\
value|do 									\   {									\     if (! (_Condition))							\       __gnu_debug::_Error_formatter::_M_at(__FILE__, __LINE__)	        \ 	  ._ErrorMessage._M_error();					\   } while (false)
end_define

begin_comment
comment|// Verify that [_First, _Last) forms a valid iterator range.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_valid_range
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_VERIFY(__gnu_debug::__valid_range(_First, _Last),	\ 		      _M_message(__gnu_debug::__msg_valid_range)	\ 		      ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last))
end_define

begin_comment
comment|/** Verify that we can insert into *this with the iterator _Position.  *  Insertion into a container at a specific position requires that  *  the iterator be nonsingular (i.e., either dereferenceable or  *  past-the-end) and that it reference the sequence we are inserting  *  into. Note that this macro is only valid when the container is a  *  _Safe_sequence and the iterator is a _Safe_iterator. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_insert
parameter_list|(
name|_Position
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_VERIFY(!_Position._M_singular(),				\ 		      _M_message(__gnu_debug::__msg_insert_singular) \ 		      ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position));		\ _GLIBCXX_DEBUG_VERIFY(_Position._M_attached_to(this),			\ 		      _M_message(__gnu_debug::__msg_insert_different) \ 		      ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position))
end_define

begin_comment
comment|/** Verify that we can insert the values in the iterator range  *  [_First, _Last) into *this with the iterator _Position.  Insertion  *  into a container at a specific position requires that the iterator  *  be nonsingular (i.e., either dereferenceable or past-the-end),  *  that it reference the sequence we are inserting into, and that the  *  iterator range [_First, Last) is a valid (possibly empty)  *  range. Note that this macro is only valid when the container is a  *  _Safe_sequence and the iterator is a _Safe_iterator.  *  *  @tbd We would like to be able to check for noninterference of  *  _Position and the range [_First, _Last), but that can't (in  *  general) be done. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_insert_range
parameter_list|(
name|_Position
parameter_list|,
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(!_Position._M_singular(),				\ 		      _M_message(__gnu_debug::__msg_insert_singular)    \                       ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position));		\ _GLIBCXX_DEBUG_VERIFY(_Position._M_attached_to(this),			\ 		      _M_message(__gnu_debug::__msg_insert_different)   \ 		      ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position))
end_define

begin_comment
comment|/** Verify that we can erase the element referenced by the iterator  * _Position. We can erase the element if the _Position iterator is  * dereferenceable and references this sequence. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_erase
parameter_list|(
name|_Position
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_VERIFY(_Position._M_dereferenceable(),			\ 		      _M_message(__gnu_debug::__msg_erase_bad)	        \                       ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position));		\ _GLIBCXX_DEBUG_VERIFY(_Position._M_attached_to(this),			\ 		      _M_message(__gnu_debug::__msg_erase_different)    \ 		      ._M_sequence(*this, "this")			\ 		      ._M_iterator(_Position, #_Position))
end_define

begin_comment
comment|/** Verify that we can erase the elements in the iterator range  *  [_First, _Last). We can erase the elements if [_First, _Last) is a  *  valid iterator range within this sequence. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_erase_range
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(_First._M_attached_to(this),			\ 		      _M_message(__gnu_debug::__msg_erase_different)    \                       ._M_sequence(*this, "this")			\ 		      ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last))
end_define

begin_comment
comment|// Verify that the subscript _N is less than the container's size.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_subscript
parameter_list|(
name|_N
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_VERIFY(_N< this->size(),				\ 		      _M_message(__gnu_debug::__msg_subscript_oob)      \                       ._M_sequence(*this, "this")			\ 		      ._M_integer(_N, #_N)				\ 		      ._M_integer(this->size(), "size"))
end_define

begin_comment
comment|// Verify that the container is nonempty
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_nonempty
parameter_list|()
define|\
value|_GLIBCXX_DEBUG_VERIFY(! this->empty(),					\ 		      _M_message(__gnu_debug::__msg_empty)	        \                       ._M_sequence(*this, "this"))
end_define

begin_comment
comment|// Verify that the< operator for elements in the sequence is a
end_comment

begin_comment
comment|// StrictWeakOrdering by checking that it is irreflexive.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_strict_weak_ordering
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_ASSERT(_First == _Last || !(*_First< *_First))
end_define

begin_comment
comment|// Verify that the predicate is StrictWeakOrdering by checking that it
end_comment

begin_comment
comment|// is irreflexive.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_strict_weak_ordering_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_ASSERT(_First == _Last || !_Pred(*_First, *_First))
end_define

begin_comment
comment|// Verify that the iterator range [_First, _Last) is sorted
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_sorted
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ __glibcxx_check_strict_weak_ordering(_First,_Last);			\ _GLIBCXX_DEBUG_VERIFY(__gnu_debug::__check_sorted(_First, _Last),	\ 		      _M_message(__gnu_debug::__msg_unsorted)	        \                       ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last))
end_define

begin_comment
comment|/** Verify that the iterator range [_First, _Last) is sorted by the     predicate _Pred. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_sorted_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ __glibcxx_check_strict_weak_ordering_pred(_First,_Last,_Pred);	        \ _GLIBCXX_DEBUG_VERIFY(__gnu_debug::__check_sorted(_First, _Last, _Pred), \ 		      _M_message(__gnu_debug::__msg_unsorted_pred)      \                       ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last)			\ 		      ._M_string(#_Pred))
end_define

begin_comment
comment|/** Verify that the iterator range [_First, _Last) is partitioned     w.r.t. the value _Value. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_partitioned
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(__gnu_debug::__check_partitioned(_First, _Last,   \ 							    _Value),	\ 		      _M_message(__gnu_debug::__msg_unpartitioned)      \ 		      ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last)			\ 		      ._M_string(#_Value))
end_define

begin_comment
comment|/** Verify that the iterator range [_First, _Last) is partitioned     w.r.t. the value _Value and predicate _Pred. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_partitioned_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Value
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(__gnu_debug::__check_partitioned(_First, _Last,   \ 							 _Value, _Pred), \ 		      _M_message(__gnu_debug::__msg_unpartitioned_pred) \ 		      ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last)			\ 		      ._M_string(#_Pred)				\                       ._M_string(#_Value))
end_define

begin_comment
comment|// Verify that the iterator range [_First, _Last) is a heap
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_heap
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(std::__is_heap(_First, _Last),		        \ 		      _M_message(__gnu_debug::__msg_not_heap)	        \ 		      ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last))
end_define

begin_comment
comment|/** Verify that the iterator range [_First, _Last) is a heap     w.r.t. the predicate _Pred. */
end_comment

begin_define
define|#
directive|define
name|__glibcxx_check_heap_pred
parameter_list|(
name|_First
parameter_list|,
name|_Last
parameter_list|,
name|_Pred
parameter_list|)
define|\
value|__glibcxx_check_valid_range(_First,_Last);				\ _GLIBCXX_DEBUG_VERIFY(std::__is_heap(_First, _Last, _Pred),		\ 		      _M_message(__gnu_debug::__msg_not_heap_pred)      \                       ._M_iterator(_First, #_First)			\ 		      ._M_iterator(_Last, #_Last)			\ 		      ._M_string(#_Pred))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCXX_DEBUG_PEDANTIC
end_ifdef

begin_define
define|#
directive|define
name|__glibcxx_check_string
parameter_list|(
name|_String
parameter_list|)
value|_GLIBCXX_DEBUG_ASSERT(_String != 0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_check_string_len
parameter_list|(
name|_String
parameter_list|,
name|_Len
parameter_list|)
define|\
value|_GLIBCXX_DEBUG_ASSERT(_String != 0 || _Len == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__glibcxx_check_string
parameter_list|(
name|_String
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__glibcxx_check_string_len
parameter_list|(
name|_String
parameter_list|,
name|_Len
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

