begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_KMEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_KMEM_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|long
name|xfs_pflags_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PFLAGS_TEST_NOIO
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|PFLAGS_TEST_FSTRANS
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|PFLAGS_SET_NOIO
parameter_list|(
name|STATEP
parameter_list|)
value|do {    \ } while (0)
end_define

begin_define
define|#
directive|define
name|PFLAGS_SET_FSTRANS
parameter_list|(
name|STATEP
parameter_list|)
value|do { \ } while (0)
end_define

begin_define
define|#
directive|define
name|PFLAGS_RESTORE
parameter_list|(
name|STATEP
parameter_list|)
value|do {     \ } while (0)
end_define

begin_define
define|#
directive|define
name|PFLAGS_DUP
parameter_list|(
name|OSTATEP
parameter_list|,
name|NSTATEP
parameter_list|)
value|do { \ } while (0)
end_define

begin_comment
comment|/* Restore the PF_FSTRANS state to what was saved in STATEP */
end_comment

begin_define
define|#
directive|define
name|PFLAGS_RESTORE_FSTRANS
parameter_list|(
name|STATEP
parameter_list|)
value|do {     		\ } while (0)
end_define

begin_comment
comment|/*  * memory management routines  */
end_comment

begin_define
define|#
directive|define
name|KM_SLEEP
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|KM_NOSLEEP
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|KM_NOFS
value|M_WAITOK
end_define

begin_define
define|#
directive|define
name|KM_MAYFAIL
value|0
end_define

begin_define
define|#
directive|define
name|kmem_zone
value|uma_zone
end_define

begin_typedef
typedef|typedef
name|struct
name|uma_zone
name|kmem_zone_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|uma_zone
name|xfs_zone_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KM_ZONE_HWALIGN
value|0
end_define

begin_define
define|#
directive|define
name|KM_ZONE_RECLAIM
value|0
end_define

begin_define
define|#
directive|define
name|KM_ZONE_SPREAD
value|0
end_define

begin_define
define|#
directive|define
name|kmem_zone_init
parameter_list|(
name|len
parameter_list|,
name|name
parameter_list|)
define|\
value|uma_zcreate(name, len, NULL, NULL, NULL, NULL, 0, 0)
end_define

begin_function
specifier|static
specifier|inline
name|kmem_zone_t
modifier|*
name|kmem_zone_init_flags
parameter_list|(
name|int
name|size
parameter_list|,
name|char
modifier|*
name|zone_name
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|,
name|void
function_decl|(
modifier|*
name|construct
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|kmem_zone_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
parameter_list|)
block|{
return|return
name|uma_zcreate
argument_list|(
name|zone_name
argument_list|,
name|size
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|kmem_zone_free
parameter_list|(
name|zone
parameter_list|,
name|ptr
parameter_list|)
define|\
value|uma_zfree(zone, ptr)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|kmem_zone_destroy
parameter_list|(
name|kmem_zone_t
modifier|*
name|zone
parameter_list|)
block|{
name|uma_zdestroy
argument_list|(
name|zone
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|kmem_zone_alloc
parameter_list|(
name|zone
parameter_list|,
name|flg
parameter_list|)
define|\
value|uma_zalloc(zone, flg)
end_define

begin_define
define|#
directive|define
name|kmem_zone_zalloc
parameter_list|(
name|zone
parameter_list|,
name|flg
parameter_list|)
define|\
value|uma_zalloc(zone, (flg) | M_ZERO)
end_define

begin_define
define|#
directive|define
name|kmem_alloc
parameter_list|(
name|len
parameter_list|,
name|flg
parameter_list|)
define|\
value|malloc(len, M_XFS, flg)
end_define

begin_define
define|#
directive|define
name|kmem_zalloc
parameter_list|(
name|len
parameter_list|,
name|flg
parameter_list|)
define|\
value|malloc(len, M_XFS, (flg) | M_ZERO)
end_define

begin_define
define|#
directive|define
name|kmem_free
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|free(ptr, M_XFS)
end_define

begin_define
define|#
directive|define
name|kmem_realloc
parameter_list|(
name|ptr
parameter_list|,
name|nsize
parameter_list|,
name|osize
parameter_list|,
name|flg
parameter_list|)
define|\
value|realloc(ptr, nsize, M_XFS, flg)
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_XFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_KMEM_H__ */
end_comment

end_unit

