begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_PROF_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_PROF_TYPES_H
end_define

begin_typedef
typedef|typedef
name|struct
name|prof_bt_s
name|prof_bt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prof_accum_s
name|prof_accum_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prof_cnt_s
name|prof_cnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prof_tctx_s
name|prof_tctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prof_gctx_s
name|prof_gctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|prof_tdata_s
name|prof_tdata_t
typedef|;
end_typedef

begin_comment
comment|/* Option defaults. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_PROF
end_ifdef

begin_define
define|#
directive|define
name|PROF_PREFIX_DEFAULT
value|"jeprof"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROF_PREFIX_DEFAULT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LG_PROF_SAMPLE_DEFAULT
value|19
end_define

begin_define
define|#
directive|define
name|LG_PROF_INTERVAL_DEFAULT
value|-1
end_define

begin_comment
comment|/*  * Hard limit on stack backtrace depth.  The version of prof_backtrace() that  * is based on __builtin_return_address() necessarily has a hard-coded number  * of backtrace frame handlers, and should be kept in sync with this setting.  */
end_comment

begin_define
define|#
directive|define
name|PROF_BT_MAX
value|128
end_define

begin_comment
comment|/* Initial hash table size. */
end_comment

begin_define
define|#
directive|define
name|PROF_CKH_MINITEMS
value|64
end_define

begin_comment
comment|/* Size of memory buffer to use when writing dump files. */
end_comment

begin_define
define|#
directive|define
name|PROF_DUMP_BUFSIZE
value|65536
end_define

begin_comment
comment|/* Size of stack-allocated buffer used by prof_printf(). */
end_comment

begin_define
define|#
directive|define
name|PROF_PRINTF_BUFSIZE
value|128
end_define

begin_comment
comment|/*  * Number of mutexes shared among all gctx's.  No space is allocated for these  * unless profiling is enabled, so it's okay to over-provision.  */
end_comment

begin_define
define|#
directive|define
name|PROF_NCTX_LOCKS
value|1024
end_define

begin_comment
comment|/*  * Number of mutexes shared among all tdata's.  No space is allocated for these  * unless profiling is enabled, so it's okay to over-provision.  */
end_comment

begin_define
define|#
directive|define
name|PROF_NTDATA_LOCKS
value|256
end_define

begin_comment
comment|/*  * prof_tdata pointers close to NULL are used to encode state information that  * is used for cleaning up during thread shutdown.  */
end_comment

begin_define
define|#
directive|define
name|PROF_TDATA_STATE_REINCARNATED
value|((prof_tdata_t *)(uintptr_t)1)
end_define

begin_define
define|#
directive|define
name|PROF_TDATA_STATE_PURGATORY
value|((prof_tdata_t *)(uintptr_t)2)
end_define

begin_define
define|#
directive|define
name|PROF_TDATA_STATE_MAX
value|PROF_TDATA_STATE_PURGATORY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_PROF_TYPES_H */
end_comment

end_unit

