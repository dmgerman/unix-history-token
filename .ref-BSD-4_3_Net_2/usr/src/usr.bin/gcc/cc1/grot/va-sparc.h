begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is just like the default gvarargs.h    except for differences decribed below.  */
end_comment

begin_comment
comment|/* va_list is a structure instead of a char*.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__va_ctl
block|{
name|char
modifier|*
name|__stack
decl_stmt|;
comment|/* Current pointer for fetching args.  */
name|char
modifier|*
name|__beg
decl_stmt|;
comment|/* Pointer to position of first saved register arg.  */
block|}
name|va_list
typedef|;
end_typedef

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
value|int __builtin_va_alist;
end_define

begin_comment
comment|/* The difference is to store the stack address in both components    instead of in AP itself.  */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
define|\
value|(__builtin_saveregs (),					\  (AP).__beg = (AP).__stack = ((char *)&__builtin_va_alist))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|pvar
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
end_define

begin_comment
comment|/* The difference is that, for an aggregate that is not word-aligned,    we advance (pvar).__stack to the first non-reg slot.  */
end_comment

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
value|({ TYPE __va_temp;						\    ((__builtin_classify_type (__va_temp)< 12			\      || __alignof__ __va_temp>= 4)				\     ? ((pvar).__stack += __va_rounded_size (TYPE),		\        *((TYPE *) ((pvar).__stack - __va_rounded_size (TYPE))))	\     : ((((pvar).__stack - (pvar).__beg< 24)			\ 	? (pvar).__stack = (pvar).__beg + 24 : 0),		\        (pvar).__stack += __va_rounded_size (TYPE),		\        *((TYPE *) ((pvar).__stack - __va_rounded_size (TYPE)))));})
end_define

end_unit

