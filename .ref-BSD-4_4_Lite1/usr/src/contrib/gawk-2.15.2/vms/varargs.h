begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "varargs.h" -- old style variable argument list manipulation (for VAX) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* Use the system's macros with the system's compiler. */
end_comment

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*__GNUC__*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__VAX__
argument_list|)
operator|||
name|defined
argument_list|(
name|__vax__
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX
argument_list|)
operator|||
name|defined
argument_list|(
name|vax
argument_list|)
end_if

begin_comment
comment|/* These macros implement traditional (non-ANSI) varargs for GNU C on VAX */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VA_LIST
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_VA_LIST_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_VA_LIST
end_define

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

begin_define
define|#
directive|define
name|va_alist
value|_varargs
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|AP
parameter_list|)
value|AP = (va_list)&va_alist
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|AP
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_va_rounded_size
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))
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
value|(AP += _va_rounded_size(TYPE),	\ 		*((TYPE *) (AP - _va_rounded_size(TYPE))))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__VMS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__vms__
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|vms
argument_list|)
end_if

begin_comment
comment|/* VAX C compatability macros */
end_comment

begin_define
define|#
directive|define
name|va_count
parameter_list|(
name|CNT
parameter_list|)
value|vaxc$va_count(&CNT)
end_define

begin_comment
comment|/* rtl routine */
end_comment

begin_define
define|#
directive|define
name|va_start_1
parameter_list|(
name|AP
parameter_list|,
name|OFFSET
parameter_list|)
value|AP = (va_list) (&va_alist + (OFFSET))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__GNUC__*/
end_comment

end_unit

