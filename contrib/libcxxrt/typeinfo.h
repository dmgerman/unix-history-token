begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_include
include|#
directive|include
file|"typeinfo"
end_include

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
block|; 	}
decl_stmt|;
comment|/** 	 * Type info for enums. 	 */
name|struct
name|__enum_type_info
range|:
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
decl_stmt|;
comment|/** 	 * Base class for class type info.  Used only for tentative definitions. 	 */
name|struct
name|__class_type_info
range|:
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
comment|/** 		 * Function returning whether a cast from this type to another type is 		 * possible. 		 */
name|virtual
name|bool
name|can_cast_to
argument_list|(
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|; 	}
decl_stmt|;
comment|/** 	 * Single-inheritance class type info.  This is used for classes containing 	 * a single non-virtual base class at offset 0. 	 */
name|struct
name|__si_class_type_info
range|:
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
name|can_cast_to
argument_list|(
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|; 	}
decl_stmt|;
comment|/** 	 * Type info for base classes.  Classes with multiple bases store an array 	 * of these, one for each superclass. 	 */
struct|struct
name|__base_class_type_info
block|{
specifier|const
name|__class_type_info
modifier|*
name|__base_type
decl_stmt|;
name|private
label|:
comment|/** 			 * The high __offset_shift bits of this store the (signed) offset 			 * of the base class.  The low bits store flags from 			 * __offset_flags_masks. 			 */
name|long
name|__offset_flags
decl_stmt|;
comment|/** 			 * Flags used in the low bits of __offset_flags. 			 */
enum|enum
name|__offset_flags_masks
block|{
comment|/** This base class is virtual. */
name|__virtual_mask
init|=
literal|0x1
block|,
comment|/** This base class is public. */
name|__public_mask
init|=
literal|0x2
block|,
comment|/** The number of bits reserved for flags. */
name|__offset_shift
init|=
literal|8
block|}
enum|;
name|public
label|:
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
block|}
struct|;
comment|/** 	 * Type info for classes with virtual bases or multiple superclasses. 	 */
name|struct
name|__vmi_class_type_info
range|:
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
name|can_cast_to
argument_list|(
argument|const struct __class_type_info *other
argument_list|)
specifier|const
block|; 	}
decl_stmt|;
comment|/** 	 * Base class used for both pointer and pointer-to-member type info. 	 */
name|struct
name|__pbase_type_info
range|:
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
block|; 	}
decl_stmt|;
comment|/** 	 * Pointer type info. 	 */
name|struct
name|__pointer_type_info
range|:
name|public
name|__pbase_type_info
block|{
name|virtual
operator|~
name|__pointer_type_info
argument_list|()
block|; 	}
decl_stmt|;
comment|/** 	 * Pointer to member type info. 	 */
name|struct
name|__pointer_to_member_type_info
range|:
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
decl_stmt|;
block|}
end_decl_stmt

end_unit

