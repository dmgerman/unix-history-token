begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|_STDARG_H
end_define

begin_comment
comment|/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Amount of space required in an argument list for an arg of type TYPE.    TYPE may alternatively be an expression whose type is used.  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|__sparc__
end_ifndef

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
value|(AP = ((char *) __builtin_next_arg ()))
end_define

begin_else
else|#
directive|else
end_else

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
value|(__builtin_saveregs (),						\   AP = ((char *) __builtin_next_arg ()))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|va_end
parameter_list|(
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in gnulib */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|AP
parameter_list|,
name|mode
parameter_list|)
value|((mode *)(AP = \ 	(char *) (sizeof(mode)> 4 ? ((int)AP + 2*8 - 1)& -8 \ 				   : ((int)AP + 2*4 - 1)& -4)))[-1]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __mips__ */
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
define|\
value|(*((TYPE *) (AP += __va_rounded_size (TYPE),				\ 	      AP - (sizeof (TYPE)< 4 ? sizeof (TYPE)			\ 		    : __va_rounded_size (TYPE)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __mips__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

end_unit

