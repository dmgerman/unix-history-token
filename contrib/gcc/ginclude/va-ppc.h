begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs support for the PowerPC with V.4 calling sequence */
end_comment

begin_comment
comment|/* Define __gnuc_va_list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_comment
comment|/* Note that the names in this structure are in the user's namespace, but    that the V.4 abi explicitly states that these names should be used.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|gpr
decl_stmt|;
comment|/* index into the array of 8 GPRs stored in the 				   register save area gpr=0 corresponds to r3, 				   gpr=1 to r4, etc. */
name|char
name|fpr
decl_stmt|;
comment|/* index into the array of 8 FPRs stored in the 				   register save area fpr=0 corresponds to f1, 				   fpr=1 to f2, etc. */
name|char
modifier|*
name|overflow_arg_area
decl_stmt|;
comment|/* location on stack that holds the next 				   overflow argument */
name|char
modifier|*
name|reg_save_area
decl_stmt|;
comment|/* where r3:r10 and f1:f8, if saved are stored */
block|}
name|__gnuc_va_list
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __GNUC_VA_LIST */
end_comment

begin_comment
comment|/* If this is for internal libc use, don't define anything but    __gnuc_va_list.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDARG_H
argument_list|)
operator|||
name|defined
argument_list|(
name|_VARARGS_H
argument_list|)
end_if

begin_comment
comment|/* Register save area located below the frame pointer */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|__gp_save
index|[
literal|8
index|]
decl_stmt|;
comment|/* save area for GP registers */
name|double
name|__fp_save
index|[
literal|8
index|]
decl_stmt|;
comment|/* save area for FP registers */
block|}
name|__va_regsave_t
typedef|;
end_typedef

begin_comment
comment|/* Macros to access the register save area */
end_comment

begin_comment
comment|/* We cast to void * and then to TYPE * because this avoids    a warning about increasing the alignment requirement.  */
end_comment

begin_define
define|#
directive|define
name|__VA_FP_REGSAVE
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE *) (void *) (&(((__va_regsave_t *)				\ 			 (AP)->reg_save_area)->__fp_save[(int)(AP)->fpr])))
end_define

begin_define
define|#
directive|define
name|__VA_GP_REGSAVE
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE *) (void *) (&(((__va_regsave_t *)				\ 			 (AP)->reg_save_area)->__gp_save[(int)(AP)->gpr])))
end_define

begin_comment
comment|/* Common code for va_start for both varargs and stdarg.  This depends    on the format of rs6000_args in rs6000.h.  The fields used are:     #0	WORDS			# words used for GP regs/stack values    #1	FREGNO			next available FP register    #2	NARGS_PROTOTYPE		# args left in the current prototype    #3	ORIG_NARGS		original value of NARGS_PROTOTYPE    #4	VARARGS_OFFSET		offset from frame pointer of varargs area */
end_comment

begin_define
define|#
directive|define
name|__va_words
value|__builtin_args_info (0)
end_define

begin_define
define|#
directive|define
name|__va_fregno
value|__builtin_args_info (1)
end_define

begin_define
define|#
directive|define
name|__va_nargs
value|__builtin_args_info (2)
end_define

begin_define
define|#
directive|define
name|__va_orig_nargs
value|__builtin_args_info (3)
end_define

begin_define
define|#
directive|define
name|__va_varargs_offset
value|__builtin_args_info (4)
end_define

begin_define
define|#
directive|define
name|__va_start_common
parameter_list|(
name|AP
parameter_list|,
name|FAKE
parameter_list|)
define|\
value|__extension__ ({							\    register int __words = __va_words - FAKE;				\ 									\    (AP)->gpr = (__words< 8) ? __words : 8;				\    (AP)->fpr = __va_fregno - 33;					\    (AP)->reg_save_area = (((char *) __builtin_frame_address (0))	\ 			  + __va_varargs_offset);			\    (AP)->overflow_arg_area = ((char *)__builtin_saveregs ()		\ 			      + (((__words>= 8) ? __words - 8 : 0)	\ 				 * sizeof (long)));			\    (void)0;								\ })
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* stdarg.h support */
end_comment

begin_comment
comment|/* Calling __builtin_next_arg gives the proper error message if LASTARG is    not indeed the last argument.  */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
define|\
value|(__builtin_next_arg (LASTARG), __va_start_common (AP, 0))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* varargs.h support */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|__va_start_common (AP, 1)
end_define

begin_define
define|#
directive|define
name|va_alist
value|__va_1st_arg
end_define

begin_define
define|#
directive|define
name|va_dcl
value|register int va_alist; ...
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SOFT_FLOAT
end_ifdef

begin_define
define|#
directive|define
name|__va_float_p
parameter_list|(
name|TYPE
parameter_list|)
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_float_p
parameter_list|(
name|TYPE
parameter_list|)
value|(__builtin_classify_type(*(TYPE *)0) == 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__va_aggregate_p
parameter_list|(
name|TYPE
parameter_list|)
value|(__builtin_classify_type(*(TYPE *)0)>= 12)
end_define

begin_define
define|#
directive|define
name|__va_size
parameter_list|(
name|TYPE
parameter_list|)
value|((sizeof(TYPE) + sizeof (long) - 1) / sizeof (long))
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|__extension__ (*({							\   register TYPE *__ptr;							\ 									\   if (__va_float_p (TYPE)&& (AP)->fpr< 8)				\     {									\       __ptr = __VA_FP_REGSAVE (AP, TYPE);				\       (AP)->fpr++;							\     }									\ 									\   else if (__va_aggregate_p (TYPE)&& (AP)->gpr< 8)			\     {									\       __ptr = * __VA_GP_REGSAVE (AP, TYPE *);				\       (AP)->gpr++;							\     }									\ 									\   else if (!__va_float_p (TYPE)&& !__va_aggregate_p (TYPE)		\&& (AP)->gpr + __va_size(TYPE)<= 8)				\     {									\       __ptr = __VA_GP_REGSAVE (AP, TYPE);				\       (AP)->gpr += __va_size (TYPE);					\     }									\ 									\   else if (!__va_float_p (TYPE)&& !__va_aggregate_p (TYPE)		\&& (AP)->gpr< 8)						\     {									\       (AP)->gpr = 8;							\       __ptr = (TYPE *) (void *) ((AP)->overflow_arg_area);		\       (AP)->overflow_arg_area += __va_size (TYPE) * sizeof (long);	\     }									\ 									\   else if (__va_aggregate_p (TYPE))					\     {									\       __ptr = * (TYPE **) (void *) ((AP)->overflow_arg_area);		\       (AP)->overflow_arg_area += sizeof (TYPE *);			\     }									\   else									\     {									\       __ptr = (TYPE *) (void *) ((AP)->overflow_arg_area);		\       (AP)->overflow_arg_area += __va_size (TYPE) * sizeof (long);	\     }									\ 									\   __ptr;								\ }))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

