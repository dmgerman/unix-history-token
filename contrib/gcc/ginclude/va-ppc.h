begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU C varargs support for the PowerPC with either the V.4 or Windows NT calling sequences */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_comment
comment|/* System V.4 support */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VA_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VA_LIST_H
end_define

begin_comment
comment|/* Solaris sys/va_list.h */
end_comment

begin_comment
comment|/* Solaris decided to rename overflow_arg_area to input_arg_area,    so handle it via a macro.  */
end_comment

begin_define
define|#
directive|define
name|__va_overflow
parameter_list|(
name|AP
parameter_list|)
value|(AP)->overflow_arg_area
end_define

begin_comment
comment|/* Note that the names in this structure are in the user's namespace, but    that the V.4 abi explicitly states that these names should be used.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__va_list_tag
block|{
name|unsigned
name|char
name|gpr
decl_stmt|;
comment|/* index into the array of 8 GPRs stored in the 				   register save area gpr=0 corresponds to r3, 				   gpr=1 to r4, etc. */
name|unsigned
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
name|__va_list
index|[
literal|1
index|]
operator|,
name|__gnuc_va_list
index|[
literal|1
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _SYS_VA_LIST */
end_comment

begin_typedef
typedef|typedef
name|__va_list
name|__gnuc_va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__va_overflow
parameter_list|(
name|AP
parameter_list|)
value|(AP)->input_arg_area
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _SYS_VA_LIST */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|__VA_PPC_H__
end_ifndef

begin_define
define|#
directive|define
name|__VA_PPC_H__
end_define

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
name|OFS
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE *) (void *) (&(((__va_regsave_t *)				\ 			 (AP)->reg_save_area)->__fp_save[OFS])))
end_define

begin_define
define|#
directive|define
name|__VA_GP_REGSAVE
parameter_list|(
name|AP
parameter_list|,
name|OFS
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE *) (void *) (&(((__va_regsave_t *)				\ 			 (AP)->reg_save_area)->__gp_save[OFS])))
end_define

begin_comment
comment|/* Common code for va_start for both varargs and stdarg.  We allow all    the work to be done by __builtin_saveregs.  It returns a pointer to    a va_list that was constructed on the stack; we must simply copy it    to the user's variable.  */
end_comment

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
value|__builtin_memcpy ((AP), __builtin_saveregs (), sizeof(__gnuc_va_list))
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

begin_comment
comment|/* This symbol isn't defined.  It is used to flag type promotion violations    at link time.  We can only do this when optimizing.  Use __builtin_trap    instead of abort so that we don't require a prototype for abort.     __builtin_trap stuff is not available on the gcc-2.95 branch, so we just    avoid calling it for now.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|__va_arg_type_violation
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__va_arg_type_violation
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|__extension__ (*({							   \   register TYPE *__ptr;							   \ 									   \   if (__va_float_p (TYPE)&& sizeof (TYPE)< 16)			   \     {									   \       unsigned char __fpr = (AP)->fpr;					   \       if (__fpr< 8)							   \ 	{								   \ 	  __ptr = __VA_FP_REGSAVE (AP, __fpr, TYPE);			   \ 	  (AP)->fpr = __fpr + 1;					   \ 	}								   \       else if (sizeof (TYPE) == 8)					   \ 	{								   \ 	  unsigned long __addr = (unsigned long) (__va_overflow (AP));	   \ 	  __ptr = (TYPE *)((__addr + 7)& -8);				   \ 	  __va_overflow (AP) = (char *)(__ptr + 1);			   \ 	}								   \       else								   \ 	{								   \
comment|/* float is promoted to double.  */
value|\ 	  __va_arg_type_violation ();					   \ 	}								   \     }									   \ 									   \
comment|/* Aggregates and long doubles are passed by reference.  */
value|\   else if (__va_aggregate_p (TYPE) || __va_float_p (TYPE))		   \     {									   \       unsigned char __gpr = (AP)->gpr;					   \       if (__gpr< 8)							   \ 	{								   \ 	  __ptr = * __VA_GP_REGSAVE (AP, __gpr, TYPE *);		   \ 	  (AP)->gpr = __gpr + 1;					   \ 	}								   \       else								   \ 	{								   \ 	  TYPE **__pptr = (TYPE **) (__va_overflow (AP));		   \ 	  __ptr = * __pptr;						   \ 	  __va_overflow (AP) = (char *) (__pptr + 1);			   \ 	}								   \     }									   \ 									   \
comment|/* Only integrals remaining.  */
value|\   else									   \     {									   \
comment|/* longlong is aligned.  */
value|\       if (sizeof (TYPE) == 8)						   \ 	{								   \ 	  unsigned char __gpr = (AP)->gpr;				   \ 	  if (__gpr< 7)						   \ 	    {								   \ 	      __gpr += __gpr& 1;					   \ 	      __ptr = __VA_GP_REGSAVE (AP, __gpr, TYPE);		   \ 	      (AP)->gpr = __gpr + 2;					   \ 	    }								   \ 	  else								   \ 	    {								   \ 	      unsigned long __addr = (unsigned long) (__va_overflow (AP)); \ 	      __ptr = (TYPE *)((__addr + 7)& -8);			   \ 	      (AP)->gpr = 8;						   \ 	      __va_overflow (AP) = (char *)(__ptr + 1);			   \ 	    }								   \ 	}								   \       else if (sizeof (TYPE) == 4)					   \ 	{								   \ 	  unsigned char __gpr = (AP)->gpr;				   \ 	  if (__gpr< 8)						   \ 	    {								   \ 	      __ptr = __VA_GP_REGSAVE (AP, __gpr, TYPE);		   \ 	      (AP)->gpr = __gpr + 1;					   \ 	    }								   \ 	  else								   \ 	    {								   \ 	      __ptr = (TYPE *) __va_overflow (AP);			   \ 	      __va_overflow (AP) = (char *)(__ptr + 1);			   \ 	    }								   \ 	}								   \       else								   \ 	{								   \
comment|/* Everything else was promoted to int.  */
value|\ 	  __va_arg_type_violation ();					   \ 	}								   \     }									   \   __ptr;								   \ }))
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

begin_comment
comment|/* Copy __gnuc_va_list into another variable of this type.  */
end_comment

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|*(dest) = *(src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __VA_PPC_H__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

begin_escape
end_escape

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Windows NT */
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

begin_typedef
typedef|typedef
name|char
modifier|*
name|__gnuc_va_list
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

begin_define
define|#
directive|define
name|__va_start_common
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|,
name|FAKE
parameter_list|)
define|\
value|((__builtin_saveregs ()), ((AP) = ((char *)&LASTARG) + __va_rounded_size (AP)), 0)
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
value|(__builtin_saveregs (),						\    (AP) = __builtin_next_arg (LASTARG),					\    0)
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
define|\
value|(__builtin_saveregs (),						\    (AP) = __builtin_next_arg (__va_1st_arg) - sizeof (int),		\    0)
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
value|register int __va_1st_arg; ...
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
value|((sizeof (TYPE) + 3)& ~3)
end_define

begin_define
define|#
directive|define
name|__va_align
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((((unsigned long)(AP)) + ((sizeof (TYPE)>= 8) ? 7 : 3))		\& ~((sizeof (TYPE)>= 8) ? 7 : 3))
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
value|( *(TYPE *)((AP = (char *) (__va_align(AP, TYPE)			\ 			    + __va_rounded_size(TYPE)))			\ 	    - __va_rounded_size(TYPE)))
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

begin_comment
comment|/* Copy __gnuc_va_list into another variable of this type.  */
end_comment

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(dest) = (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Windows NT */
end_comment

end_unit

