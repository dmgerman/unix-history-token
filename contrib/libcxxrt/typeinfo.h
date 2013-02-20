begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright 2010-2011 PathScale, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS  * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"abi_namespace.h"
end_include

begin_decl_stmt
name|namespace
name|ABI_NAMESPACE
block|{
struct_decl|struct
name|__class_type_info
struct_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|std
block|{
comment|/** 	  * Standard type info class.  The layout of this class is specified by the 	  * ABI.  The layout of the vtable is not, but is intended to be 	  * compatible with the GNU ABI. 	  * 	  * Unlike the GNU version, the vtable layout is considered semi-private. 	  */
name|class
name|type_info
block|{
name|public
label|:
comment|/** 		 * Virtual destructor.  This class must have one virtual function to 		 * ensure that it has a vtable. 		 */
name|virtual
operator|~
name|type_info
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|type_info
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|type_info
operator|&
operator|)
specifier|const
expr_stmt|;
name|bool
name|before
argument_list|(
specifier|const
name|type_info
operator|&
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
parameter_list|()
function_decl|const;
name|type_info
argument_list|()
expr_stmt|;
name|private
label|:
name|type_info
argument_list|(
specifier|const
name|type_info
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|type_info
modifier|&
name|operator
init|=
operator|(
specifier|const
name|type_info
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|__type_name
decl_stmt|;
comment|/* 		 * The following functions are in this order to match the 		 * vtable layout of libsupc++.  This allows libcxxrt to be used 		 * with libraries that depend on this. 		 * 		 * These functions are in the public headers for libstdc++, so 		 * we have to assume that someone will probably call them and 		 * expect them to work.  Their names must also match the names used in 		 * libsupc++, so that code linking against this library can subclass 		 * type_info and correctly fill in the values in the vtables. 		 */
name|public
label|:
comment|/** 		 * Returns true if this is some pointer type, false otherwise. 		 */
name|virtual
name|bool
name|__is_pointer_p
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/** 		 * Returns true if this is some function type, false otherwise. 		 */
name|virtual
name|bool
name|__is_function_p
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/** 		 * Catch function.  Allows external libraries to implement 		 * their own basic types.  This is used, for example, in the 		 * GNUstep Objective-C runtime to allow Objective-C types to be 		 * caught in G++ catch blocks. 		 * 		 * The outer parameter indicates the number of outer pointers 		 * in the high bits.  The low bit indicates whether the 		 * pointers are const qualified. 		 */
name|virtual
name|bool
name|__do_catch
argument_list|(
specifier|const
name|type_info
operator|*
name|thrown_type
argument_list|,
name|void
operator|*
operator|*
name|thrown_object
argument_list|,
name|unsigned
name|outer
argument_list|)
decl|const
decl_stmt|;
comment|/** 		 * Performs an upcast.  This is used in exception handling to 		 * cast from subclasses to superclasses.  If the upcast is 		 * possible, it returns true and adjusts the pointer.  If the 		 * upcast is not possible, it returns false and does not adjust 		 * the pointer. 		 */
name|virtual
name|bool
name|__do_upcast
argument_list|(
specifier|const
name|ABI_NAMESPACE
operator|::
name|__class_type_info
operator|*
name|target
argument_list|,
name|void
operator|*
operator|*
name|thrown_object
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|ABI_NAMESPACE
block|{
comment|/** 	 * Primitive type info, for intrinsic types. 	 */
name|struct
name|__fundamental_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__fundamental_type_info
argument_list|()
block|; 	}
decl_stmt|;
comment|/** 	 * Type info for arrays.   	 */
name|struct
name|__array_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__array_type_info
argument_list|()
block|; 	}
decl_stmt|;
comment|/** 	 * Type info for functions. 	 */
name|struct
name|__function_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__function_type_info
argument_list|()
block|;
name|virtual
name|bool
name|__is_function_p
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/** 	 * Type info for enums. 	 */
block|struct
name|__enum_type_info
operator|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__enum_type_info
argument_list|()
block|; 	}
block|;
comment|/** 	 * Base class for class type info.  Used only for tentative definitions. 	 */
block|struct
name|__class_type_info
operator|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__class_type_info
argument_list|()
block|;
comment|/** 		 * Function implementing dynamic casts. 		 */
name|virtual
name|void
operator|*
name|cast_to
argument_list|(
argument|void *obj
argument_list|,
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const __class_type_info *target
argument_list|,
argument|void **thrown_object
argument_list|)
specifier|const
block|{
return|return
name|this
operator|==
name|target
return|;
block|}
expr|}
block|;
comment|/** 	 * Single-inheritance class type info.  This is used for classes containing 	 * a single non-virtual base class at offset 0. 	 */
block|struct
name|__si_class_type_info
operator|:
name|public
name|__class_type_info
block|{
name|virtual
operator|~
name|__si_class_type_info
argument_list|()
block|;
specifier|const
name|__class_type_info
operator|*
name|__base_type
block|;
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const ABI_NAMESPACE::__class_type_info *target
argument_list|,
argument|void **thrown_object
argument_list|)
specifier|const
block|;
name|virtual
name|void
operator|*
name|cast_to
argument_list|(
argument|void *obj
argument_list|,
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|; 	}
block|;
comment|/** 	 * Type info for base classes.  Classes with multiple bases store an array 	 * of these, one for each superclass. 	 */
block|struct
name|__base_class_type_info
block|{
specifier|const
name|__class_type_info
operator|*
name|__base_type
block|;
name|private
operator|:
comment|/** 			 * The high __offset_shift bits of this store the (signed) offset 			 * of the base class.  The low bits store flags from 			 * __offset_flags_masks. 			 */
name|long
name|__offset_flags
block|;
comment|/** 			 * Flags used in the low bits of __offset_flags. 			 */
block|enum
name|__offset_flags_masks
block|{
comment|/** This base class is virtual. */
name|__virtual_mask
operator|=
literal|0x1
block|,
comment|/** This base class is public. */
name|__public_mask
operator|=
literal|0x2
block|,
comment|/** The number of bits reserved for flags. */
name|__offset_shift
operator|=
literal|8
block|}
block|;
name|public
operator|:
comment|/** 			 * Returns the offset of the base class. 			 */
name|long
name|offset
argument_list|()
specifier|const
block|{
return|return
name|__offset_flags
operator|>>
name|__offset_shift
return|;
block|}
comment|/** 			 * Returns the flags. 			 */
name|long
name|flags
argument_list|()
specifier|const
block|{
return|return
name|__offset_flags
operator|&
operator|(
operator|(
literal|1
operator|<<
name|__offset_shift
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/** 			 * Returns whether this is a public base class. 			 */
name|bool
name|isPublic
argument_list|()
specifier|const
block|{
return|return
name|flags
argument_list|()
operator|&
name|__public_mask
return|;
block|}
comment|/** 			 * Returns whether this is a virtual base class. 			 */
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
return|return
name|flags
argument_list|()
operator|&
name|__virtual_mask
return|;
block|}
expr|}
block|;
comment|/** 	 * Type info for classes with virtual bases or multiple superclasses. 	 */
block|struct
name|__vmi_class_type_info
operator|:
name|public
name|__class_type_info
block|{
name|virtual
operator|~
name|__vmi_class_type_info
argument_list|()
block|;
comment|/** Flags describing this class.  Contains values from __flags_masks. */
name|unsigned
name|int
name|__flags
block|;
comment|/** The number of base classes. */
name|unsigned
name|int
name|__base_count
block|;
comment|/**  		 * Array of base classes - this actually has __base_count elements, not 		 * 1. 		 */
name|__base_class_type_info
name|__base_info
index|[
literal|1
index|]
block|;
comment|/** 		 * Flags used in the __flags field. 		 */
block|enum
name|__flags_masks
block|{
comment|/** The class has non-diamond repeated inheritance. */
name|__non_diamond_repeat_mask
operator|=
literal|0x1
block|,
comment|/** The class is diamond shaped. */
name|__diamond_shaped_mask
operator|=
literal|0x2
block|}
block|;
name|virtual
name|bool
name|__do_upcast
argument_list|(
argument|const ABI_NAMESPACE::__class_type_info *target
argument_list|,
argument|void **thrown_object
argument_list|)
specifier|const
block|;
name|virtual
name|void
operator|*
name|cast_to
argument_list|(
argument|void *obj
argument_list|,
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|; 	}
block|;
comment|/** 	 * Base class used for both pointer and pointer-to-member type info. 	 */
block|struct
name|__pbase_type_info
operator|:
name|public
name|std
operator|::
name|type_info
block|{
name|virtual
operator|~
name|__pbase_type_info
argument_list|()
block|;
comment|/** 		 * Flags.  Values from __masks. 		 */
name|unsigned
name|int
name|__flags
block|;
comment|/** 		 * The type info for the pointee. 		 */
specifier|const
name|std
operator|::
name|type_info
operator|*
name|__pointee
block|;
comment|/** 		 * Masks used for qualifiers on the pointer. 		 */
block|enum
name|__masks
block|{
comment|/** Pointer has const qualifier. */
name|__const_mask
operator|=
literal|0x1
block|,
comment|/** Pointer has volatile qualifier. */
name|__volatile_mask
operator|=
literal|0x2
block|,
comment|/** Pointer has restrict qualifier. */
name|__restrict_mask
operator|=
literal|0x4
block|,
comment|/** Pointer points to an incomplete type. */
name|__incomplete_mask
operator|=
literal|0x8
block|,
comment|/** Pointer is a pointer to a member of an incomplete class. */
name|__incomplete_class_mask
operator|=
literal|0x10
block|}
block|;
name|virtual
name|bool
name|__do_catch
argument_list|(
argument|const type_info *thrown_type
argument_list|,
argument|void **thrown_object
argument_list|,
argument|unsigned outer
argument_list|)
specifier|const
block|; 	}
block|;
comment|/** 	 * Pointer type info. 	 */
block|struct
name|__pointer_type_info
operator|:
name|public
name|__pbase_type_info
block|{
name|virtual
operator|~
name|__pointer_type_info
argument_list|()
block|;
name|virtual
name|bool
name|__is_pointer_p
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/** 	 * Pointer to member type info. 	 */
block|struct
name|__pointer_to_member_type_info
operator|:
name|public
name|__pbase_type_info
block|{
name|virtual
operator|~
name|__pointer_to_member_type_info
argument_list|()
block|;
comment|/** 		 * Pointer to the class containing this member. 		 */
specifier|const
name|__class_type_info
operator|*
name|__context
block|; 	}
block|;  }
end_decl_stmt

end_unit

