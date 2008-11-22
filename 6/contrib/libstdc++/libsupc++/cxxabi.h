begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// new abi support -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2002, 2003, 2004 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of GCC.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// the Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC is distributed in the hope that it will be useful,
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
comment|//
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with GCC; see the file COPYING.  If not, write to
end_comment

begin_comment
comment|// the Free Software Foundation, 59 Temple Place - Suite 330,
end_comment

begin_comment
comment|// Boston, MA 02111-1307, USA.
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
comment|// Written by Nathan Sidwell, Codesourcery LLC,<nathan@codesourcery.com>
end_comment

begin_comment
comment|/* This file declares the new abi entry points into the runtime. It is not    normally necessary for user programs to include this header, or use the    entry points directly. However, this header is available should that be    needed.        Some of the entry points are intended for both C and C++, thus this header    is includable from both C and C++. Though the C++ specific parts are not    available in C, naturally enough.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|_CXXABI_H
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_decl_stmt
name|namespace
name|__cxxabiv1
block|{
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// Allocate array.
name|void
modifier|*
name|__cxa_vec_new
parameter_list|(
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
modifier|*
name|__cxa_vec_new2
parameter_list|(
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|__alloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__dealloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
modifier|*
name|__cxa_vec_new3
parameter_list|(
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|__alloc
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__dealloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
comment|// Construct array.
name|void
name|__cxa_vec_ctor
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|__cxa_vec_cctor
parameter_list|(
name|void
modifier|*
name|dest_array
parameter_list|,
name|void
modifier|*
name|src_array
parameter_list|,
name|size_t
name|element_count
parameter_list|,
name|size_t
name|element_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|constructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|// Destruct array.
name|void
name|__cxa_vec_dtor
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|__cxa_vec_cleanup
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_count
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|// Destruct and release array.
name|void
name|__cxa_vec_delete
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|__cxa_vec_delete2
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__dealloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
name|void
name|__cxa_vec_delete3
parameter_list|(
name|void
modifier|*
name|__array_address
parameter_list|,
name|size_t
name|__element_size
parameter_list|,
name|size_t
name|__padding_size
parameter_list|,
name|void
function_decl|(
modifier|*
name|__destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|__dealloc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
comment|// The ABI requires a 64-bit type.
name|__extension__
typedef|typedef
name|int
name|__guard
name|__attribute__
typedef|((
name|mode
typedef|(
name|__DI__
typedef|)));
name|int
name|__cxa_guard_acquire
parameter_list|(
name|__guard
modifier|*
parameter_list|)
function_decl|;
name|void
name|__cxa_guard_release
parameter_list|(
name|__guard
modifier|*
parameter_list|)
function_decl|;
name|void
name|__cxa_guard_abort
parameter_list|(
name|__guard
modifier|*
parameter_list|)
function_decl|;
comment|// Pure virtual functions.
name|void
name|__cxa_pure_virtual
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Exception handling.
name|void
name|__cxa_bad_cast
parameter_list|()
function_decl|;
name|void
name|__cxa_bad_typeid
parameter_list|()
function_decl|;
comment|// DSO destruction.
name|int
name|__cxa_atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
name|__cxa_finalize
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|// Demangling routines.
name|char
modifier|*
name|__cxa_demangle
parameter_list|(
specifier|const
name|char
modifier|*
name|__mangled_name
parameter_list|,
name|char
modifier|*
name|__output_buffer
parameter_list|,
name|size_t
modifier|*
name|__length
parameter_list|,
name|int
modifier|*
name|__status
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __cxxabiv1
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<typeinfo>
end_include

begin_decl_stmt
name|namespace
name|__cxxabiv1
block|{
comment|// Type information for int, float etc.
name|class
name|__fundamental_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|explicit
name|__fundamental_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|)
operator|:
name|std
operator|::
name|type_info
argument_list|(
argument|__n
argument_list|)
block|{ }
name|virtual
operator|~
name|__fundamental_type_info
argument_list|()
block|;   }
decl_stmt|;
comment|// Type information for array objects.
name|class
name|__array_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|explicit
name|__array_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|)
operator|:
name|std
operator|::
name|type_info
argument_list|(
argument|__n
argument_list|)
block|{ }
name|virtual
operator|~
name|__array_type_info
argument_list|()
block|;   }
decl_stmt|;
comment|// Type information for functions (both member and non-member).
name|class
name|__function_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|explicit
name|__function_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|)
operator|:
name|std
operator|::
name|type_info
argument_list|(
argument|__n
argument_list|)
block|{ }
name|virtual
operator|~
name|__function_type_info
argument_list|()
block|;
name|protected
operator|:
comment|// Implementation defined member function.
name|virtual
name|bool
name|__is_function_p
argument_list|()
specifier|const
block|;   }
decl_stmt|;
comment|// Type information for enumerations.
name|class
name|__enum_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|explicit
name|__enum_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|)
operator|:
name|std
operator|::
name|type_info
argument_list|(
argument|__n
argument_list|)
block|{ }
name|virtual
operator|~
name|__enum_type_info
argument_list|()
block|;   }
decl_stmt|;
comment|// Common type information for simple pointers and pointers to member.
name|class
name|__pbase_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|unsigned
name|int
name|__flags
block|;
comment|// Qualification of the target object.
specifier|const
name|std
operator|::
name|type_info
operator|*
name|__pointee
block|;
comment|// Type of pointed to object.
name|explicit
name|__pbase_type_info
argument_list|(
argument|const char* __n
argument_list|,
argument|int __quals
argument_list|,
argument|const std::type_info* __type
argument_list|)
operator|:
name|std
operator|::
name|type_info
argument_list|(
name|__n
argument_list|)
block|,
name|__flags
argument_list|(
name|__quals
argument_list|)
block|,
name|__pointee
argument_list|(
argument|__type
argument_list|)
block|{ }
name|virtual
operator|~
name|__pbase_type_info
argument_list|()
block|;
comment|// Implementation defined type.
block|enum
name|__masks
block|{
name|__const_mask
operator|=
literal|0x1
block|,
name|__volatile_mask
operator|=
literal|0x2
block|,
name|__restrict_mask
operator|=
literal|0x4
block|,
name|__incomplete_mask
operator|=
literal|0x8
block|,
name|__incomplete_class_mask
operator|=
literal|0x10
block|}
block|;
name|protected
operator|:
name|__pbase_type_info
argument_list|(
specifier|const
name|__pbase_type_info
operator|&
argument_list|)
block|;
name|__pbase_type_info
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__pbase_type_info
operator|&
operator|)
block|;
comment|// Implementation defined member functions.
name|virtual
name|bool
name|__do_catch
argument_list|(
argument|const std::type_info* __thr_type
argument_list|,
argument|void** __thr_obj
argument_list|,
argument|unsigned int __outer
argument_list|)
specifier|const
block|;
specifier|inline
name|virtual
name|bool
name|__pointer_catch
argument_list|(
argument|const __pbase_type_info* __thr_type
argument_list|,
argument|void** __thr_obj
argument_list|,
argument|unsigned __outer
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// Type information for simple pointers.
name|class
name|__pointer_type_info
range|:
name|public
name|__pbase_type_info
block|{
name|public
operator|:
name|explicit
name|__pointer_type_info
argument_list|(
argument|const char* __n
argument_list|,
argument|int __quals
argument_list|,
argument|const std::type_info* __type
argument_list|)
operator|:
name|__pbase_type_info
argument_list|(
argument|__n
argument_list|,
argument|__quals
argument_list|,
argument|__type
argument_list|)
block|{ }
name|virtual
operator|~
name|__pointer_type_info
argument_list|()
block|;
name|protected
operator|:
comment|// Implementation defined member functions.
name|virtual
name|bool
name|__is_pointer_p
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|__pointer_catch
argument_list|(
argument|const __pbase_type_info* __thr_type
argument_list|,
argument|void** __thr_obj
argument_list|,
argument|unsigned __outer
argument_list|)
specifier|const
block|;   }
decl_stmt|;
name|class
name|__class_type_info
decl_stmt|;
comment|// Type information for a pointer to member variable.
name|class
name|__pointer_to_member_type_info
range|:
name|public
name|__pbase_type_info
block|{
name|public
operator|:
name|__class_type_info
operator|*
name|__context
block|;
comment|// Class of the member.
name|explicit
name|__pointer_to_member_type_info
argument_list|(
argument|const char* __n
argument_list|,
argument|int __quals
argument_list|,
argument|const std::type_info* __type
argument_list|,
argument|__class_type_info* __klass
argument_list|)
operator|:
name|__pbase_type_info
argument_list|(
name|__n
argument_list|,
name|__quals
argument_list|,
name|__type
argument_list|)
block|,
name|__context
argument_list|(
argument|__klass
argument_list|)
block|{ }
name|virtual
operator|~
name|__pointer_to_member_type_info
argument_list|()
block|;
name|protected
operator|:
name|__pointer_to_member_type_info
argument_list|(
specifier|const
name|__pointer_to_member_type_info
operator|&
argument_list|)
block|;
name|__pointer_to_member_type_info
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__pointer_to_member_type_info
operator|&
operator|)
block|;
comment|// Implementation defined member function.
name|virtual
name|bool
name|__pointer_catch
argument_list|(
argument|const __pbase_type_info* __thr_type
argument_list|,
argument|void** __thr_obj
argument_list|,
argument|unsigned __outer
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// Helper class for __vmi_class_type.
name|class
name|__base_class_type_info
block|{
name|public
label|:
specifier|const
name|__class_type_info
modifier|*
name|__base_type
decl_stmt|;
comment|// Base class type.
name|long
name|__offset_flags
decl_stmt|;
comment|// Offset and info.
enum|enum
name|__offset_flags_masks
block|{
name|__virtual_mask
init|=
literal|0x1
block|,
name|__public_mask
init|=
literal|0x2
block|,
name|__hwm_bit
init|=
literal|2
block|,
name|__offset_shift
init|=
literal|8
comment|// Bits to shift offset.
block|}
enum|;
comment|// Implementation defined member functions.
name|bool
name|__is_virtual_p
argument_list|()
specifier|const
block|{
return|return
name|__offset_flags
operator|&
name|__virtual_mask
return|;
block|}
name|bool
name|__is_public_p
argument_list|()
specifier|const
block|{
return|return
name|__offset_flags
operator|&
name|__public_mask
return|;
block|}
name|ptrdiff_t
name|__offset
argument_list|()
specifier|const
block|{
comment|// This shift, being of a signed type, is implementation
comment|// defined. GCC implements such shifts as arithmetic, which is
comment|// what we want.
return|return
name|static_cast
operator|<
name|ptrdiff_t
operator|>
operator|(
name|__offset_flags
operator|)
operator|>>
name|__offset_shift
return|;
block|}
block|}
empty_stmt|;
comment|// Type information for a class.
name|class
name|__class_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|public
operator|:
name|explicit
name|__class_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|)
operator|:
name|type_info
argument_list|(
argument|__n
argument_list|)
block|{ }
name|virtual
operator|~
name|__class_type_info
argument_list|()
block|;
comment|// Implementation defined types.
comment|// The type sub_kind tells us about how a base object is contained
comment|// within a derived object. We often do this lazily, hence the
comment|// UNKNOWN value. At other times we may use NOT_CONTAINED to mean
comment|// not publicly contained.
block|enum
name|__sub_kind
block|{
comment|// We have no idea.
name|__unknown
operator|=
literal|0
block|,
comment|// Not contained within us (in some circumstances this might
comment|// mean not contained publicly)
name|__not_contained
block|,
comment|// Contained ambiguously.
name|__contained_ambig
block|,
comment|// Via a virtual path.
name|__contained_virtual_mask
operator|=
name|__base_class_type_info
operator|::
name|__virtual_mask
block|,
comment|// Via a public path.
name|__contained_public_mask
operator|=
name|__base_class_type_info
operator|::
name|__public_mask
block|,
comment|// Contained within us.
name|__contained_mask
operator|=
literal|1
operator|<<
name|__base_class_type_info
operator|::
name|__hwm_bit
block|,
name|__contained_private
operator|=
name|__contained_mask
block|,
name|__contained_public
operator|=
name|__contained_mask
operator||
name|__contained_public_mask
block|}
block|;      struct
name|__upcast_result
block|;     struct
name|__dyncast_result
block|;
name|protected
operator|:
comment|// Implementation defined member functions.
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const __class_type_info* __dst_type
argument_list|,
argument|void**__obj_ptr
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|__do_catch
argument_list|(
argument|const type_info* __thr_type
argument_list|,
argument|void** __thr_obj
argument_list|,
argument|unsigned __outer
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|// Helper for upcast. See if DST is us, or one of our bases.
comment|// Return false if not found, true if found.
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const __class_type_info* __dst
argument_list|,
argument|const void* __obj
argument_list|,
argument|__upcast_result& __restrict __result
argument_list|)
specifier|const
block|;
comment|// Indicate whether SRC_PTR of type SRC_TYPE is contained publicly
comment|// within OBJ_PTR. OBJ_PTR points to a base object of our type,
comment|// which is the destination type. SRC2DST indicates how SRC
comment|// objects might be contained within this type.  If SRC_PTR is one
comment|// of our SRC_TYPE bases, indicate the virtuality. Returns
comment|// not_contained for non containment or private containment.
specifier|inline
name|__sub_kind
name|__find_public_src
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|)
specifier|const
block|;
comment|// Helper for dynamic cast. ACCESS_PATH gives the access from the
comment|// most derived object to this base. DST_TYPE indicates the
comment|// desired type we want. OBJ_PTR points to a base of our type
comment|// within the complete object. SRC_TYPE indicates the static type
comment|// started from and SRC_PTR points to that base within the most
comment|// derived object. Fill in RESULT with what we find. Return true
comment|// if we have located an ambiguous match.
name|virtual
name|bool
name|__do_dyncast
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|__sub_kind __access_path
argument_list|,
argument|const __class_type_info* __dst_type
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|,
argument|__dyncast_result& __result
argument_list|)
specifier|const
block|;
comment|// Helper for find_public_subobj. SRC2DST indicates how SRC_TYPE
comment|// bases are inherited by the type started from -- which is not
comment|// necessarily the current type. The current type will be a base
comment|// of the destination type.  OBJ_PTR points to the current base.
name|virtual
name|__sub_kind
name|__do_find_public_src
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// Type information for a class with a single non-virtual base.
name|class
name|__si_class_type_info
range|:
name|public
name|__class_type_info
block|{
name|public
operator|:
specifier|const
name|__class_type_info
operator|*
name|__base_type
block|;
name|explicit
name|__si_class_type_info
argument_list|(
specifier|const
name|char
operator|*
name|__n
argument_list|,
specifier|const
name|__class_type_info
operator|*
name|__base
argument_list|)
operator|:
name|__class_type_info
argument_list|(
name|__n
argument_list|)
block|,
name|__base_type
argument_list|(
argument|__base
argument_list|)
block|{ }
name|virtual
operator|~
name|__si_class_type_info
argument_list|()
block|;
name|protected
operator|:
name|__si_class_type_info
argument_list|(
specifier|const
name|__si_class_type_info
operator|&
argument_list|)
block|;
name|__si_class_type_info
operator|&
name|operator
operator|=
operator|(
specifier|const
name|__si_class_type_info
operator|&
operator|)
block|;
comment|// Implementation defined member functions.
name|virtual
name|bool
name|__do_dyncast
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|__sub_kind __access_path
argument_list|,
argument|const __class_type_info* __dst_type
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|,
argument|__dyncast_result& __result
argument_list|)
specifier|const
block|;
name|virtual
name|__sub_kind
name|__do_find_public_src
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __sub_ptr
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const __class_type_info*__dst
argument_list|,
argument|const void*__obj
argument_list|,
argument|__upcast_result& __restrict __result
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// Type information for a class with multiple and/or virtual bases.
name|class
name|__vmi_class_type_info
range|:
name|public
name|__class_type_info
block|{
name|public
operator|:
name|unsigned
name|int
name|__flags
block|;
comment|// Details about the class hierarchy.
name|unsigned
name|int
name|__base_count
block|;
comment|// Dumber of direct bases.
comment|// The array of bases uses the trailing array struct hack so this
comment|// class is not constructable with a normal constructor. It is
comment|// internally generated by the compiler.
name|__base_class_type_info
name|__base_info
index|[
literal|1
index|]
block|;
comment|// Array of bases.
name|explicit
name|__vmi_class_type_info
argument_list|(
argument|const char* __n
argument_list|,
argument|int ___flags
argument_list|)
operator|:
name|__class_type_info
argument_list|(
name|__n
argument_list|)
block|,
name|__flags
argument_list|(
name|___flags
argument_list|)
block|,
name|__base_count
argument_list|(
literal|0
argument_list|)
block|{ }
name|virtual
operator|~
name|__vmi_class_type_info
argument_list|()
block|;
comment|// Implementation defined types.
block|enum
name|__flags_masks
block|{
name|__non_diamond_repeat_mask
operator|=
literal|0x1
block|,
comment|// Distinct instance of repeated base.
name|__diamond_shaped_mask
operator|=
literal|0x2
block|,
comment|// Diamond shaped multiple inheritance.
name|__flags_unknown_mask
operator|=
literal|0x10
block|}
block|;
name|protected
operator|:
comment|// Implementation defined member functions.
name|virtual
name|bool
name|__do_dyncast
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|__sub_kind __access_path
argument_list|,
argument|const __class_type_info* __dst_type
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|,
argument|__dyncast_result& __result
argument_list|)
specifier|const
block|;
name|virtual
name|__sub_kind
name|__do_find_public_src
argument_list|(
argument|ptrdiff_t __src2dst
argument_list|,
argument|const void* __obj_ptr
argument_list|,
argument|const __class_type_info* __src_type
argument_list|,
argument|const void* __src_ptr
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const __class_type_info* __dst
argument_list|,
argument|const void* __obj
argument_list|,
argument|__upcast_result& __restrict __result
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|// Dynamic cast runtime.
comment|// src2dst has the following possible values
comment|//>-1: src_type is a unique public non-virtual base of dst_type
comment|//       dst_ptr + src2dst == src_ptr
comment|//   -1: unspecified relationship
comment|//   -2: src_type is not a public base of dst_type
comment|//   -3: src_type is a multiple public non-virtual base of dst_type
extern|extern
literal|"C"
name|void
modifier|*
name|__dynamic_cast
parameter_list|(
specifier|const
name|void
modifier|*
name|__src_ptr
parameter_list|,
comment|// Starting object.
specifier|const
name|__class_type_info
modifier|*
name|__src_type
parameter_list|,
comment|// Static type of object.
specifier|const
name|__class_type_info
modifier|*
name|__dst_type
parameter_list|,
comment|// Desired target type.
name|ptrdiff_t
name|__src2dst
parameter_list|)
function_decl|;
comment|// How src and dst are related.
comment|// Returns the type_info for the currently handled exception [15.3/8], or
comment|// null if there is none.
extern|extern
literal|"C"
name|std
operator|::
name|type_info
operator|*
name|__cxa_current_exception_type
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __cxxabiv1
end_comment

begin_comment
comment|// User programs should use the alias `abi'.
end_comment

begin_decl_stmt
name|namespace
name|abi
init|=
name|__cxxabiv1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __CXXABI_H
end_comment

end_unit

