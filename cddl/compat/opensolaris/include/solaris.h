begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SOLARIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SOLARIS_H_
end_define

begin_include
include|#
directive|include
file|<sys/ccompile.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|NOTE
parameter_list|(
name|s
parameter_list|)
end_define

begin_function_decl
name|int
name|mkdirp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SOLARIS_H_ */
end_comment

end_unit

