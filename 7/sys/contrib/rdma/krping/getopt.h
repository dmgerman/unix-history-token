begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lifted from fs/ncpfs/getopt.c  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KRPING_GETOPT_H
end_ifndef

begin_define
define|#
directive|define
name|_KRPING_GETOPT_H
end_define

begin_define
define|#
directive|define
name|OPT_NOPARAM
value|1
end_define

begin_define
define|#
directive|define
name|OPT_INT
value|2
end_define

begin_define
define|#
directive|define
name|OPT_STRING
value|4
end_define

begin_struct
struct|struct
name|krping_option
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|has_arg
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|krping_getopt
parameter_list|(
specifier|const
name|char
modifier|*
name|caller
parameter_list|,
name|char
modifier|*
modifier|*
name|options
parameter_list|,
specifier|const
name|struct
name|krping_option
modifier|*
name|opts
parameter_list|,
name|char
modifier|*
modifier|*
name|optopt
parameter_list|,
name|char
modifier|*
modifier|*
name|optarg
parameter_list|,
name|unsigned
name|long
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KRPING_GETOPT_H */
end_comment

end_unit

