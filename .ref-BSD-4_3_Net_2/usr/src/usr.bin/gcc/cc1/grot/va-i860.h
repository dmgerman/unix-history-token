begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_struct
struct|struct
name|__va_struct
block|{
name|int
name|fixed
index|[
literal|12
index|]
decl_stmt|;
name|int
name|floating
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|__va_ctl
block|{
name|struct
name|__va_struct
modifier|*
name|__regs
decl_stmt|;
name|void
modifier|*
name|__stack
decl_stmt|;
name|int
name|__nfixed
decl_stmt|,
name|__nfloating
decl_stmt|;
block|}
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VA_LIST */
end_comment

begin_define
define|#
directive|define
name|va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|pvar
parameter_list|)
define|\
value|(memcpy (&(pvar), (struct __va_ctl *) __builtin_saveregs (), 16))
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
name|va_arg
parameter_list|(
name|pvar
parameter_list|,
name|type
parameter_list|)
define|\
value|({ type __va_temp;						\    *((__builtin_classify_type (__va_temp)< 8			\&& sizeof __va_temp< 8)					\      ? ((pvar).__nfixed< 12					\ 	? (type *)&(pvar).__regs->fixed[(pvar).__nfixed++]	\ 	: ({							\ 	     int temp						\ 	       = ((int) ((pvar).__stack + __alignof__ (type) - 1) \& ~(__alignof__ (type) - 1));			\ 	     (pvar).__stack = (void *) (temp + sizeof (type));	\ 	     (type *) temp; 					\ 	   }))							\      : __builtin_classify_type (__va_temp)< 9			\      ? ((pvar).__nfloating< 8					\ 	? ((pvar).__nfloating					\ 	     = (((pvar).__nfloating + 2 * (sizeof __va_temp / 4) - 1) \& ~(sizeof __va_temp / 4 - 1)),			\ 	   (type *)&(pvar).__regs->floating[(pvar).__nfloating - (sizeof __va_temp / 4)]) \ 	: ({							\ 	     int temp						\ 	       = ((int) ((pvar).__stack + __alignof__ (type) - 1) \& ~(__alignof__ (type) - 1));			\ 	     (pvar).__stack = (void *) (temp + sizeof (type));	\ 	     (type *) temp; 					\ 	   }))							\      : ({							\ 	  int temp						\ 	    = ((int) ((pvar).__stack + __alignof__ (type) - 1)	\& ~(__alignof__ (type) - 1));			\ 	  (pvar).__stack = (void *) (temp + sizeof (type));	\ 	  (type *) temp; 					\ 	})); })
end_define

end_unit

