begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mprof.h 2.5 9/14/90 16:01:19	*/
end_comment

begin_comment
comment|/*	Copyright (c) 1987, Benjamin G. Zorn */
end_comment

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|MP_NUM_BINS
value|1025
end_define

begin_define
define|#
directive|define
name|MP_HASH_SIZE
value|8009
end_define

begin_define
define|#
directive|define
name|SHORT_CALLSTACK_SIZE
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|mp_data_struct
block|{
name|int
name|d1
decl_stmt|,
name|d2
decl_stmt|,
name|d3
decl_stmt|,
name|d4
decl_stmt|,
name|d5
decl_stmt|,
name|d6
decl_stmt|,
name|d7
decl_stmt|,
name|d8
decl_stmt|,
name|d9
decl_stmt|,
name|d10
decl_stmt|,
name|d11
decl_stmt|,
name|d12
decl_stmt|;
block|}
name|mpdata_str
operator|,
typedef|*
name|mpdata
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPDATA_SIZE
value|(sizeof(mpdata_str))
end_define

begin_define
define|#
directive|define
name|dt_b_small
parameter_list|(
name|x
parameter_list|)
value|((x)->d1)
end_define

begin_define
define|#
directive|define
name|dt_b_med
parameter_list|(
name|x
parameter_list|)
value|((x)->d2)
end_define

begin_define
define|#
directive|define
name|dt_b_large
parameter_list|(
name|x
parameter_list|)
value|((x)->d3)
end_define

begin_define
define|#
directive|define
name|dt_b_xlarge
parameter_list|(
name|x
parameter_list|)
value|((x)->d4)
end_define

begin_define
define|#
directive|define
name|dt_n_small
parameter_list|(
name|x
parameter_list|)
value|((x)->d5)
end_define

begin_define
define|#
directive|define
name|dt_n_med
parameter_list|(
name|x
parameter_list|)
value|((x)->d6)
end_define

begin_define
define|#
directive|define
name|dt_n_large
parameter_list|(
name|x
parameter_list|)
value|((x)->d7)
end_define

begin_define
define|#
directive|define
name|dt_n_xlarge
parameter_list|(
name|x
parameter_list|)
value|((x)->d8)
end_define

begin_define
define|#
directive|define
name|dt_d_small
parameter_list|(
name|x
parameter_list|)
value|((x)->d9)
end_define

begin_define
define|#
directive|define
name|dt_d_med
parameter_list|(
name|x
parameter_list|)
value|((x)->d10)
end_define

begin_define
define|#
directive|define
name|dt_d_large
parameter_list|(
name|x
parameter_list|)
value|((x)->d11)
end_define

begin_define
define|#
directive|define
name|dt_d_xlarge
parameter_list|(
name|x
parameter_list|)
value|((x)->d12)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mp_cons_struct
block|{
name|int
name|mpcar
decl_stmt|;
name|struct
name|mp_cons_struct
modifier|*
name|mpcdr
decl_stmt|;
block|}
name|mpcell_str
operator|,
typedef|*
name|mpcell
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPCELL_SIZE
value|(sizeof(mpcell_str))
end_define

begin_define
define|#
directive|define
name|MP_NIL
value|-1
end_define

begin_define
define|#
directive|define
name|mp_car
parameter_list|(
name|i
parameter_list|)
value|((i)->mpcar)
end_define

begin_define
define|#
directive|define
name|mp_cdr
parameter_list|(
name|i
parameter_list|)
value|((i)->mpcdr)
end_define

begin_define
define|#
directive|define
name|mp_null
parameter_list|(
name|i
parameter_list|)
value|(((int) i) == MP_NIL)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mp_function_struct
block|{
name|mpdata
name|lcount
decl_stmt|;
name|unsigned
name|addr
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|mpcell
name|parents
decl_stmt|;
block|}
name|mpsym_str
operator|,
typedef|*
name|mpsym
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPSYM_SIZE
value|(sizeof(mpsym_str))
end_define

begin_define
define|#
directive|define
name|fn_addr
parameter_list|(
name|fn
parameter_list|)
value|((fn)->addr)
end_define

begin_define
define|#
directive|define
name|fn_parents
parameter_list|(
name|fn
parameter_list|)
value|((fn)->parents)
end_define

begin_define
define|#
directive|define
name|fn_lcount
parameter_list|(
name|fn
parameter_list|)
value|((fn)->lcount)
end_define

begin_define
define|#
directive|define
name|fn_name
parameter_list|(
name|fn
parameter_list|)
value|((fn)->name)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mp_sstk_struct
block|{
name|unsigned
name|sstack
index|[
name|SHORT_CALLSTACK_SIZE
index|]
decl_stmt|;
name|int
name|allocs
decl_stmt|,
name|bytes_alloced
decl_stmt|;
name|int
name|frees
decl_stmt|,
name|bytes_freed
decl_stmt|;
block|}
name|mpsstk_str
operator|,
typedef|*
name|mpsstk
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPSSTK_SIZE
value|(sizeof(mpsstk_str))
end_define

begin_define
define|#
directive|define
name|sstk_addrs
parameter_list|(
name|fn
parameter_list|)
value|((fn)->sstack)
end_define

begin_define
define|#
directive|define
name|sstk_allocs
parameter_list|(
name|fn
parameter_list|)
value|((fn)->allocs)
end_define

begin_define
define|#
directive|define
name|sstk_bytes_alloced
parameter_list|(
name|fn
parameter_list|)
value|((fn)->bytes_alloced)
end_define

begin_define
define|#
directive|define
name|sstk_frees
parameter_list|(
name|fn
parameter_list|)
value|((fn)->frees)
end_define

begin_define
define|#
directive|define
name|sstk_bytes_freed
parameter_list|(
name|fn
parameter_list|)
value|((fn)->bytes_freed)
end_define

begin_function_decl
specifier|extern
name|void
name|mprof_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpcell
name|mp_cons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpsym
name|mp_new_fn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpdata
name|mp_new_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpdata
name|mp_add_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_sum_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_sum_calls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_sum_kept
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_hash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_puthash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpsym
name|mp_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_note_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpcell
name|mp_note_parent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_note_leaf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_print_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_print_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mp_sprint_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_print_fn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_print_parents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpcell
name|mp_has_parent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mprof_print
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpstruct_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpsym
name|pc_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mpsstk
name|mp_add_leak_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_remove_leak_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_print_leak_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpleak_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sun4
argument_list|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|get_current_fp
parameter_list|(
name|first_local
parameter_list|)
value|((unsigned)&(first_local) + 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<frame.h>
end_include

begin_define
define|#
directive|define
name|prev_fp_from_fp
parameter_list|(
name|fp
parameter_list|)
value|(unsigned)(((struct frame *)(fp))->fr_savfp)
end_define

begin_define
define|#
directive|define
name|ret_addr_from_fp
parameter_list|(
name|fp
parameter_list|)
value|(unsigned)(((struct frame *)(fp))->fr_savpc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for ultrix 0x38, 4.3 bsd 0x3d, other? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|CRT0_ADDRESS
value|0x3d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|CRT0_ADDRESS
value|0x3d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|CRT0_ADDRESS
value|0x204c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|CRT0_ADDRESS
value|0x0
end_define

begin_comment
comment|/* to be filled in later */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

