begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* malloc.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       malloc.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_MALLOC_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MALLOC_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|MALLOC_DEBUG
value|0
end_define

begin_comment
comment|/* 1 means check caller's use of this module. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MALLOC_typeKS_
block|,
name|MALLOC_typeKSR_
block|,
name|MALLOC_typeKP_
block|,
name|MALLOC_typeKPR_
block|,
name|MALLOC_typeUS_
block|,
name|MALLOC_typeUSR_
block|,
name|MALLOC_type_
block|}
name|mallocType_
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_malloc_area_
modifier|*
name|mallocArea_
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_malloc_pool_
modifier|*
name|mallocPool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|mallocSize
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mallocSize_f
value|"l"
end_define

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_malloc_area_
block|{
name|mallocArea_
name|next
decl_stmt|;
name|mallocArea_
name|previous
decl_stmt|;
name|void
modifier|*
name|where
decl_stmt|;
if|#
directive|if
name|MALLOC_DEBUG
name|mallocSize
name|size
decl_stmt|;
name|mallocType_
name|type
decl_stmt|;
endif|#
directive|endif
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_malloc_pool_
block|{
name|mallocPool
name|next
decl_stmt|;
name|mallocPool
name|previous
decl_stmt|;
name|mallocPool
name|eldest
decl_stmt|;
name|mallocPool
name|youngest
decl_stmt|;
name|mallocArea_
name|first
decl_stmt|;
name|mallocArea_
name|last
decl_stmt|;
name|unsigned
name|long
name|uses
decl_stmt|;
if|#
directive|if
name|MALLOC_DEBUG
name|mallocSize
name|allocated
decl_stmt|;
name|mallocSize
name|freed
decl_stmt|;
name|mallocSize
name|old_sizes
decl_stmt|;
name|mallocSize
name|new_sizes
decl_stmt|;
name|unsigned
name|long
name|allocations
decl_stmt|;
name|unsigned
name|long
name|frees
decl_stmt|;
name|unsigned
name|long
name|resizes
decl_stmt|;
endif|#
directive|endif
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_malloc_root_
block|{
name|struct
name|_malloc_pool_
name|malloc_pool_image_
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_malloc_root_
name|malloc_root_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|malloc_display_
parameter_list|(
name|mallocArea_
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mallocArea_
name|malloc_find_inpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_kill_inpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|mallocType_
name|type
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|mallocSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc_new_
parameter_list|(
name|mallocSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc_new_inpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|mallocType_
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|mallocSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc_new_zinpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|mallocType_
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|mallocSize
name|size
parameter_list|,
name|int
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_pool_display
parameter_list|(
name|mallocPool
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|malloc_pool_find_
parameter_list|(
name|mallocPool
name|p
parameter_list|,
name|mallocPool
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_pool_kill
parameter_list|(
name|mallocPool
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mallocPool
name|malloc_pool_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|mallocPool
name|parent
parameter_list|,
name|unsigned
name|long
name|chunks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mallocPool
name|malloc_pool_use
parameter_list|(
name|mallocPool
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc_resize_
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|mallocSize
name|new_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc_resize_inpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|mallocType_
name|type
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|mallocSize
name|new_size
parameter_list|,
name|mallocSize
name|old_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_verify_inpool_
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|mallocType_
name|type
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|mallocSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|malloc_new_ks
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeKS_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_ksr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeKSR_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_kp
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeKP_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_kpr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeKPR_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_us
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeUS_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_usr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_new_inpool_ (pool,MALLOC_typeUSR_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_new_zks
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeKS_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_new_zksr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeKSR_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_new_zkp
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeKP_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_new_zkpr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeKPR_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_new_zus
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeUS_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_new_zusr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|z
parameter_list|)
define|\
value|malloc_new_zinpool_ (pool,MALLOC_typeUSR_,name,size,z)
end_define

begin_define
define|#
directive|define
name|malloc_kill_ks
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_kill_inpool_ (pool,MALLOC_typeKS_,ptr,size)
end_define

begin_define
define|#
directive|define
name|malloc_kill_ksr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_kill_inpool_ (pool,MALLOC_typeKSR_,ptr,size)
end_define

begin_define
define|#
directive|define
name|malloc_kill_us
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|malloc_kill_inpool_ (pool,MALLOC_typeUS_,ptr,0)
end_define

begin_define
define|#
directive|define
name|malloc_kill_usr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|malloc_kill_inpool_ (pool,MALLOC_typeUSR_,ptr,0)
end_define

begin_define
define|#
directive|define
name|malloc_pool_image
parameter_list|()
value|(&malloc_root_.malloc_pool_image_)
end_define

begin_define
define|#
directive|define
name|malloc_resize_ksr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|new_size
parameter_list|,
name|old_size
parameter_list|)
define|\
value|malloc_resize_inpool_ (pool,MALLOC_typeKSR_,ptr,new_size,old_size)
end_define

begin_define
define|#
directive|define
name|malloc_resize_kpr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|new_size
parameter_list|,
name|old_size
parameter_list|)
define|\
value|malloc_resize_inpool_ (pool,MALLOC_typeKPR_,ptr,new_size,old_size)
end_define

begin_define
define|#
directive|define
name|malloc_resize_usr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|new_size
parameter_list|)
define|\
value|malloc_resize_inpool_ (pool,MALLOC_typeUSR_,ptr,new_size,0)
end_define

begin_define
define|#
directive|define
name|malloc_verify_kp
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeKP_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_verify_kpr
parameter_list|(
name|pool
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeKPR_,name,size)
end_define

begin_define
define|#
directive|define
name|malloc_verify_ks
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeKS_,ptr,size)
end_define

begin_define
define|#
directive|define
name|malloc_verify_ksr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeKSR_,ptr,size)
end_define

begin_define
define|#
directive|define
name|malloc_verify_us
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeUS_,ptr,0)
end_define

begin_define
define|#
directive|define
name|malloc_verify_usr
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|malloc_verify_inpool_ (pool,MALLOC_typeUSR_,ptr,0)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_MALLOC_H */
end_comment

end_unit

