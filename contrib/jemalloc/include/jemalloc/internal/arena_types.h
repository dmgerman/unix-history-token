begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ARENA_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ARENA_TYPES_H
end_define

begin_comment
comment|/* Maximum number of regions in one slab. */
end_comment

begin_define
define|#
directive|define
name|LG_SLAB_MAXREGS
value|(LG_PAGE - LG_TINY_MIN)
end_define

begin_define
define|#
directive|define
name|SLAB_MAXREGS
value|(1U<< LG_SLAB_MAXREGS)
end_define

begin_comment
comment|/* Default decay times in milliseconds. */
end_comment

begin_define
define|#
directive|define
name|DIRTY_DECAY_MS_DEFAULT
value|ZD(10 * 1000)
end_define

begin_define
define|#
directive|define
name|MUZZY_DECAY_MS_DEFAULT
value|ZD(10 * 1000)
end_define

begin_comment
comment|/* Number of event ticks between time checks. */
end_comment

begin_define
define|#
directive|define
name|DECAY_NTICKS_PER_UPDATE
value|1000
end_define

begin_typedef
typedef|typedef
name|struct
name|arena_slab_data_s
name|arena_slab_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_bin_info_s
name|arena_bin_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_decay_s
name|arena_decay_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_bin_s
name|arena_bin_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_s
name|arena_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_tdata_s
name|arena_tdata_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|alloc_ctx_s
name|alloc_ctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|percpu_arena_mode_names_base
init|=
literal|0
block|,
comment|/* Used for options processing. */
comment|/* 	 * *_uninit are used only during bootstrapping, and must correspond 	 * to initialized variant plus percpu_arena_mode_enabled_base. 	 */
name|percpu_arena_uninit
init|=
literal|0
block|,
name|per_phycpu_arena_uninit
init|=
literal|1
block|,
comment|/* All non-disabled modes must come after percpu_arena_disabled. */
name|percpu_arena_disabled
init|=
literal|2
block|,
name|percpu_arena_mode_names_limit
init|=
literal|3
block|,
comment|/* Used for options processing. */
name|percpu_arena_mode_enabled_base
init|=
literal|3
block|,
name|percpu_arena
init|=
literal|3
block|,
name|per_phycpu_arena
init|=
literal|4
comment|/* Hyper threads share arena. */
block|}
name|percpu_arena_mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PERCPU_ARENA_ENABLED
parameter_list|(
name|m
parameter_list|)
value|((m)>= percpu_arena_mode_enabled_base)
end_define

begin_define
define|#
directive|define
name|PERCPU_ARENA_DEFAULT
value|percpu_arena_disabled
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ARENA_TYPES_H */
end_comment

end_unit

