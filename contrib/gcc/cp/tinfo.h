begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RTTI support internals for -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1994, 1995, 1996, 1998 Free Software Foundation
end_comment

begin_include
include|#
directive|include
file|"typeinfo"
end_include

begin_comment
comment|// Class declarations shared between the typeinfo implementation files.
end_comment

begin_comment
comment|// type_info for a class with no base classes (or an enum).
end_comment

begin_decl_stmt
name|struct
name|__user_type_info
range|:
name|public
name|std
operator|::
name|type_info
block|{
name|__user_type_info
argument_list|(
specifier|const
name|char
operator|*
name|n
argument_list|)
operator|:
name|type_info
argument_list|(
argument|n
argument_list|)
block|{}
comment|// If our type can be converted to the desired type,
comment|// return the pointer, adjusted accordingly; else return 0.
name|virtual
name|void
operator|*
name|dcast
argument_list|(
argument|const type_info&
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|const type_info * =
literal|0
argument_list|,
argument|void * =
literal|0
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// type_info for a class with one public, nonvirtual base class.
end_comment

begin_decl_stmt
name|class
name|__si_type_info
range|:
name|public
name|__user_type_info
block|{
specifier|const
name|__user_type_info
operator|&
name|base
block|;
name|public
operator|:
name|__si_type_info
argument_list|(
specifier|const
name|char
operator|*
name|n
argument_list|,
specifier|const
name|__user_type_info
operator|&
name|b
argument_list|)
operator|:
name|__user_type_info
argument_list|(
name|n
argument_list|)
block|,
name|base
argument_list|(
argument|b
argument_list|)
block|{ }
name|virtual
name|void
operator|*
name|dcast
argument_list|(
argument|const type_info&
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|const type_info * =
literal|0
argument_list|,
argument|void * =
literal|0
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// type_info for a general class.
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_decl_stmt
name|struct
name|__class_type_info
range|:
name|public
name|__user_type_info
block|{   enum
name|access
block|{
name|PUBLIC
operator|=
literal|1
block|,
name|PROTECTED
operator|=
literal|2
block|,
name|PRIVATE
operator|=
literal|3
block|}
block|;    struct
name|base_info
block|{
specifier|const
name|__user_type_info
operator|*
name|base
block|;
name|USItype
name|offset
operator|:
literal|29
block|;
name|bool
name|is_virtual
operator|:
literal|1
block|;     enum
name|access
name|access
operator|:
literal|2
block|;   }
block|;
specifier|const
name|base_info
operator|*
name|base_list
block|;
name|size_t
name|n_bases
block|;
name|__class_type_info
argument_list|(
argument|const char *name
argument_list|,
argument|const base_info *bl
argument_list|,
argument|size_t bn
argument_list|)
operator|:
name|__user_type_info
argument_list|(
name|name
argument_list|)
block|,
name|base_list
argument_list|(
name|bl
argument_list|)
block|,
name|n_bases
argument_list|(
argument|bn
argument_list|)
block|{}
comment|// This is a little complex.
name|virtual
name|void
operator|*
name|dcast
argument_list|(
argument|const type_info&
argument_list|,
argument|int
argument_list|,
argument|void *
argument_list|,
argument|const type_info * =
literal|0
argument_list|,
argument|void * =
literal|0
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

end_unit

