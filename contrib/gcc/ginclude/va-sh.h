begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The ! __SH3E_VARG case is similar to the default gvarargs.h .  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__SH3E__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SH4_SINGLE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SH4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SH4_SINGLE_ONLY__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__HITACHI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__SH3E_VARG
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|__SH3E_VARG
end_ifdef

begin_typedef
typedef|typedef
name|long
name|__va_greg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__va_freg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__va_greg
modifier|*
name|__va_next_o
decl_stmt|;
comment|/* next available register */
name|__va_greg
modifier|*
name|__va_next_o_limit
decl_stmt|;
comment|/* past last available register */
name|__va_freg
modifier|*
name|__va_next_fp
decl_stmt|;
comment|/* next available fp register */
name|__va_freg
modifier|*
name|__va_next_fp_limit
decl_stmt|;
comment|/* last available fp register */
name|__va_greg
modifier|*
name|__va_next_stack
decl_stmt|;
comment|/* next extended word on stack */
block|}
name|__gnuc_va_list
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SH3E */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|__gnuc_va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SH3E */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC_VA_LIST */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__SH3E_VARG
end_ifdef

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
value|__extension__ \   ({ \      (AP).__va_next_fp = (__va_freg *) __builtin_saveregs (); \      (AP).__va_next_fp_limit = ((AP).__va_next_fp + \ 			      (__builtin_args_info (1)< 8 ? 8 - __builtin_args_info (1) : 0)); \      (AP).__va_next_o = (__va_greg *) (AP).__va_next_fp_limit; \      (AP).__va_next_o_limit = ((AP).__va_next_o + \ 			     (__builtin_args_info (0)< 4 ? 4 - __builtin_args_info (0) : 0)); \      (AP).__va_next_stack = (__va_greg *) __builtin_next_arg (LASTARG); \   })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SH3E */
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
value|((AP) = ((__gnuc_va_list) __builtin_next_arg (LASTARG)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SH3E */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _VARARGS_H */
end_comment

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist;...
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__SH3E_VARG
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|__extension__ \   ({ \      (AP).__va_next_fp = (__va_freg *) __builtin_saveregs (); \      (AP).__va_next_fp_limit = ((AP).__va_next_fp + \ 			      (__builtin_args_info (1)< 8 ? 8 - __builtin_args_info (1) : 0)); \      (AP).__va_next_o = (__va_greg *) (AP).__va_next_fp_limit; \      (AP).__va_next_o_limit = ((AP).__va_next_o + \ 			     (__builtin_args_info (0)< 4 ? 4 - __builtin_args_info (0) : 0)); \      (AP).__va_next_stack \        = ((__va_greg *) __builtin_next_arg (__builtin_va_alist) \ 	  - (__builtin_args_info (0)>= 4 || __builtin_args_info (1)>= 8 \ 	     ? 1 : 0)); \   })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SH3E */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|((AP) = (char *)&__builtin_va_alist)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SH3E */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_end
end_ifndef

begin_function_decl
name|void
name|va_end
parameter_list|(
name|__gnuc_va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in libgcc.a */
end_comment

begin_comment
comment|/* Values returned by __builtin_classify_type.  */
end_comment

begin_enum
enum|enum
name|__va_type_classes
block|{
name|__no_type_class
init|=
operator|-
literal|1
block|,
name|__void_type_class
block|,
name|__integer_type_class
block|,
name|__char_type_class
block|,
name|__enumeral_type_class
block|,
name|__boolean_type_class
block|,
name|__pointer_type_class
block|,
name|__reference_type_class
block|,
name|__offset_type_class
block|,
name|__real_type_class
block|,
name|__complex_type_class
block|,
name|__function_type_class
block|,
name|__method_type_class
block|,
name|__record_type_class
block|,
name|__union_type_class
block|,
name|__array_type_class
block|,
name|__string_type_class
block|,
name|__set_type_class
block|,
name|__file_type_class
block|,
name|__lang_type_class
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|pvar
parameter_list|)
value|((void)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN_P
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN_P
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__SCALAR_TYPE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|((TYPE) == __integer_type_class				\    || (TYPE) == __char_type_class				\    || (TYPE) == __enumeral_type_class)
end_define

begin_comment
comment|/* RECORD_TYPE args passed using the C calling convention are    passed by invisible reference.  ??? RECORD_TYPE args passed    in the stack are made to be word-aligned; for an aggregate that is    not word-aligned, we advance the pointer to the first non-reg slot.  */
end_comment

begin_comment
comment|/* When this is a smaller-than-int integer, using      auto-increment in the promoted (SImode) is fastest;      however, there is no way to express that is C.  Therefore,      we use an asm.      We want the MEM_IN_STRUCT_P bit set in the emitted RTL, therefore we      use unions even when it would otherwise be unnecessary.  */
end_comment

begin_comment
comment|/* gcc has an extension that allows to use a casted lvalue as an lvalue,    But it doesn't work in C++ with -pedantic - even in the presence of    __extension__ .  We work around this problem by using a reference type.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|__VA_REF
value|&
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__VA_REF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__va_arg_sh1
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
value|__extension__ 				\ ({(sizeof (TYPE) == 1							\    ? ({union {TYPE t; char c;} __t;					\        __asm(""								\ 	     : "=r" (__t.c)						\ 	     : "0" ((((union { int i, j; } *__VA_REF) (AP))++)->i));	\        __t.t;})								\    : sizeof (TYPE) == 2							\    ? ({union {TYPE t; short s;} __t;					\        __asm(""								\ 	     : "=r" (__t.s)						\ 	     : "0" ((((union { int i, j; } *__VA_REF) (AP))++)->i));	\        __t.t;})								\    : sizeof (TYPE)>= 4 || __LITTLE_ENDIAN_P				\    ? (((union { TYPE t; int i;} *__VA_REF) (AP))++)->t			\    : ((union {TYPE t;TYPE u;}*) ((char *)++(int *__VA_REF)(AP) - sizeof (TYPE)))->t);})
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__SH3E_VARG
end_ifdef

begin_define
define|#
directive|define
name|__PASS_AS_FLOAT
parameter_list|(
name|TYPE_CLASS
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(TYPE_CLASS == __real_type_class&& SIZE == 4)
end_define

begin_define
define|#
directive|define
name|__TARGET_SH4_P
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SH4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SH4_SINGLE__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|__PASS_AS_FLOAT
end_undef

begin_define
define|#
directive|define
name|__PASS_AS_FLOAT
parameter_list|(
name|TYPE_CLASS
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(TYPE_CLASS == __real_type_class&& SIZE<= 8 \    || TYPE_CLASS == __complex_type_class&& SIZE<= 16)
end_define

begin_undef
undef|#
directive|undef
name|__TARGET_SH4_P
end_undef

begin_define
define|#
directive|define
name|__TARGET_SH4_P
value|1
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
name|pvar
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|__extension__							\ ({int __type = __builtin_classify_type (* (TYPE *) 0);		\   void * __result_p;						\   if (__PASS_AS_FLOAT (__type, sizeof(TYPE)))			\     {								\       if ((pvar).__va_next_fp< (pvar).__va_next_fp_limit)	\ 	{							\ 	  if (((__type == __real_type_class&& sizeof (TYPE)> 4)\ 	       || sizeof (TYPE)> 8)				\&& (((int) (pvar).__va_next_fp ^ (int) (pvar).__va_next_fp_limit)\& 4))						\ 	    (pvar).__va_next_fp++;				\ 	  __result_p =&(pvar).__va_next_fp;			\ 	}							\       else							\ 	__result_p =&(pvar).__va_next_stack;			\     }								\   else								\     {								\       if ((pvar).__va_next_o + ((sizeof (TYPE) + 3) / 4)	\<= (pvar).__va_next_o_limit) 				\ 	__result_p =&(pvar).__va_next_o;			\       else							\ 	{							\ 	  if (sizeof (TYPE)> 4)				\ 	   if (! __TARGET_SH4_P)				\ 	    (pvar).__va_next_o = (pvar).__va_next_o_limit;	\ 								\ 	  __result_p =&(pvar).__va_next_stack;			\ 	}							\     } 								\   __va_arg_sh1(*(void **)__result_p, TYPE);})
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! SH3E */
end_comment

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
value|__va_arg_sh1((AP), TYPE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SH3E */
end_comment

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
value|((dest) = (src))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (_STDARG_H) || defined (_VARARGS_H) */
end_comment

end_unit

