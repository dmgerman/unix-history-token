begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|GETSTR_H_
end_ifndef

begin_define
define|#
directive|define
name|GETSTR_H_
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|getstr
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
name|lineptr
operator|,
name|size_t
operator|*
name|n
operator|,
name|FILE
operator|*
name|stream
operator|,
name|int
name|delim1
operator|,
name|int
name|delim2
operator|,
name|size_t
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

