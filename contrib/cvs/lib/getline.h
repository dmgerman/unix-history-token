begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_getline_h_
end_ifndef

begin_define
define|#
directive|define
name|_getline_h_
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|__PROTO
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PROTO
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC.  */
end_comment

begin_define
define|#
directive|define
name|GETLINE_NO_LIMIT
value|-1
end_define

begin_decl_stmt
name|int
name|getline
name|__PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
name|_lineptr
operator|,
name|size_t
operator|*
name|_n
operator|,
name|FILE
operator|*
name|_stream
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getline_safe
name|__PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
name|_lineptr
operator|,
name|size_t
operator|*
name|_n
operator|,
name|FILE
operator|*
name|_stream
operator|,
name|int
name|limit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getstr
name|__PROTO
argument_list|(
operator|(
name|char
operator|*
operator|*
name|_lineptr
operator|,
name|size_t
operator|*
name|_n
operator|,
name|FILE
operator|*
name|_stream
operator|,
name|char
name|_terminator
operator|,
name|int
name|_offset
operator|,
name|int
name|limit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _getline_h_ */
end_comment

end_unit

