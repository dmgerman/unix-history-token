begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TCACHE_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TCACHE_TYPES_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|tcache_bin_info_s
name|tcache_bin_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcache_bin_s
name|tcache_bin_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcache_s
name|tcache_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcaches_s
name|tcaches_t
typedef|;
end_typedef

begin_comment
comment|/* ncached is cast to this type for comparison. */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|low_water_t
typedef|;
end_typedef

begin_comment
comment|/*  * tcache pointers close to NULL are used to encode state information that is  * used for two purposes: preventing thread caching on a per thread basis and  * cleaning up during thread shutdown.  */
end_comment

begin_define
define|#
directive|define
name|TCACHE_STATE_DISABLED
value|((tcache_t *)(uintptr_t)1)
end_define

begin_define
define|#
directive|define
name|TCACHE_STATE_REINCARNATED
value|((tcache_t *)(uintptr_t)2)
end_define

begin_define
define|#
directive|define
name|TCACHE_STATE_PURGATORY
value|((tcache_t *)(uintptr_t)3)
end_define

begin_define
define|#
directive|define
name|TCACHE_STATE_MAX
value|TCACHE_STATE_PURGATORY
end_define

begin_comment
comment|/*  * Absolute minimum number of cache slots for each small bin.  */
end_comment

begin_define
define|#
directive|define
name|TCACHE_NSLOTS_SMALL_MIN
value|20
end_define

begin_comment
comment|/*  * Absolute maximum number of cache slots for each small bin in the thread  * cache.  This is an additional constraint beyond that imposed as: twice the  * number of regions per slab for this size class.  *  * This constant must be an even number.  */
end_comment

begin_define
define|#
directive|define
name|TCACHE_NSLOTS_SMALL_MAX
value|200
end_define

begin_comment
comment|/* Number of cache slots for large size classes. */
end_comment

begin_define
define|#
directive|define
name|TCACHE_NSLOTS_LARGE
value|20
end_define

begin_comment
comment|/* (1U<< opt_lg_tcache_max) is used to compute tcache_maxclass. */
end_comment

begin_define
define|#
directive|define
name|LG_TCACHE_MAXCLASS_DEFAULT
value|15
end_define

begin_comment
comment|/*  * TCACHE_GC_SWEEP is the approximate number of allocation events between  * full GC sweeps.  Integer rounding may cause the actual number to be  * slightly higher, since GC is performed incrementally.  */
end_comment

begin_define
define|#
directive|define
name|TCACHE_GC_SWEEP
value|8192
end_define

begin_comment
comment|/* Number of tcache allocation/deallocation events between incremental GCs. */
end_comment

begin_define
define|#
directive|define
name|TCACHE_GC_INCR
define|\
value|((TCACHE_GC_SWEEP / NBINS) + ((TCACHE_GC_SWEEP / NBINS == 0) ? 0 : 1))
end_define

begin_comment
comment|/* Used in TSD static initializer only. Real init in tcache_data_init(). */
end_comment

begin_define
define|#
directive|define
name|TCACHE_ZERO_INITIALIZER
value|{0}
end_define

begin_comment
comment|/* Used in TSD static initializer only. Will be initialized to opt_tcache. */
end_comment

begin_define
define|#
directive|define
name|TCACHE_ENABLED_ZERO_INITIALIZER
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TCACHE_TYPES_H */
end_comment

end_unit

